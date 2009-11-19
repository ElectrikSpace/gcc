/* Write and read any fix-up information generated by the WPA mode.

   Copyright 2009 Free Software Foundation, Inc.
   Contributed by Doug Kwan <dougkwan@google.com>

This file is part of GCC.

GCC is free software; you can redistribute it and/or modify it under
the terms of the GNU General Public License as published by the Free
Software Foundation; either version 3, or (at your option) any later
version.

GCC is distributed in the hope that it will be useful, but WITHOUT ANY
WARRANTY; without even the implied warranty of MERCHANTABILITY or
FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
for more details.

You should have received a copy of the GNU General Public License
along with GCC; see the file COPYING3.  If not see
<http://www.gnu.org/licenses/>.  */

#include "config.h"
#include "system.h"
#include "coretypes.h"
#include "tm.h"
#include "toplev.h"
#include "tree.h"
#include "expr.h"
#include "flags.h"
#include "cgraph.h"
#include "function.h"
#include "diagnostic.h"
#include "vec.h"
#include "bitmap.h"
#include "timevar.h"
#include "tree-flow.h"
#include "tree-pass.h"
#include "lto-streamer.h"

/* LTO fix-up.

   In WPA mode, LTO cannot access function bodies.  Some modifications in
   IR require additional updates in function bodies,  which are not possible
   in WPA mode.  So we write out information about these modifications for
   LTRANS to fix up the function bodies accordingly.  */

/* The vectors records function DECLs having multiple copies with different
   exception throwing attributes.  We do not mark a DECL if all copies of it
   have the same exception throwing attribute. */
static bitmap lto_nothrow_fndecls;

/* We need to fix up GIMPLE bodies due to changes in exception setting.
   Consider this example:

   a.h:
   class a {
   public:
     a();
     ~a();
   };

   main.cc:
   #include "a.h"

   int
   main (int argc, char **argv)
   {
     a x;
     return 0;
   }

   a.cc:
   #include "a.h"
   a::a() {}
   a::~a() {}
   
   When main.cc is compiled, gcc only sees the constructor declaration, so
   the constructor and hence the call to it are marked as exception throwing.
   When a.cc is compiled, the body of the constructor is available and is
   obviously not exception throwing. Thus DECL of a::a in a.o has the NOTHROW
   attribute.  When LTO runs, two DECLs of a::a with different exception
   attributes are merged.  We want the merged DECL to be not exception
   throwing for better generated code.  To do that, we need to fix up any
   function calls that have been marked as exception throwing.  */

/* Fix up all the call statements whose target fndecls might have changed
   to NOTHROW.   Note that this problem is not WPA specific.  We can also
   run into this problem in normal LTO with multiple input files.  */

void
lto_fixup_nothrow_decls (void)
{
  struct cgraph_node *node;
  struct cgraph_edge *edge;
  struct function *caller_function;
  gimple call_stmt;

  /* Quit if we are in WPA mode or have not marked any DECLs.  */
  if (flag_wpa || !lto_nothrow_fndecls)
    return;

  /* For each node that has been marked, go over all call edges to it.  */
  for (node = cgraph_nodes; node; node = node->next)
    if (bitmap_bit_p (lto_nothrow_fndecls, DECL_UID (node->decl)))
      {
	gcc_assert (TREE_NOTHROW (node->decl));
	for (edge = node->callers; edge; edge = edge->next_caller)
	  {
	    caller_function = DECL_STRUCT_FUNCTION (edge->caller->decl);
	    call_stmt = edge->call_stmt;
	    gcc_assert (call_stmt);
	    if (lookup_stmt_eh_lp_fn (caller_function, call_stmt) != 0)
	      remove_stmt_from_eh_lp_fn (caller_function, call_stmt);
	  } 
      }
}

/* Mark FNDECL as becoming not exception throwing.  */

void
lto_mark_nothrow_fndecl (tree fndecl)
{
  gcc_assert (TREE_CODE (fndecl) == FUNCTION_DECL);
  if (!lto_nothrow_fndecls)
    lto_nothrow_fndecls = lto_bitmap_alloc ();
    
  bitmap_set_bit (lto_nothrow_fndecls, DECL_UID (fndecl));
}

/* Write out fix-up information.  Currently the only WPA fix-up
   information is the list of DECLs marked as not exception throwing. SET
   is a cgraph node set whose fix-up information is to be written.  */

static void
lto_output_wpa_fixup (cgraph_node_set set)
{
  struct lto_simple_output_block *ob;
  cgraph_node_set_iterator csi;
  tree fndecl;
  bitmap seen_decls;
  VEC(tree, heap) *decls = NULL;
  unsigned HOST_WIDE_INT i, count;

  ob = lto_create_simple_output_block (LTO_section_wpa_fixup);

  /* Accumulate the DECLs to be written out.  Since we do not want
     duplicates, we need to use a bitmap and a vector to save the
     DECLs we want.  Note that we need to check if lto_nothrow_fndecls
     is NULL.  This happens when no DECL has been marked.  */
  seen_decls = lto_bitmap_alloc ();
  if (lto_nothrow_fndecls)
    for (csi = csi_start (set); !csi_end_p (csi); csi_next (&csi))
      {
	struct cgraph_edge *e;
	struct cgraph_node *n;
	
	n = csi_node (csi);
	fndecl = n->decl;

	/* Check if the N's function is in the set of nothrow functions.  */
	if (!bitmap_bit_p (seen_decls, DECL_UID (fndecl)))
	  {
	    bitmap_set_bit (seen_decls, (DECL_UID (fndecl)));
	    if (bitmap_bit_p (lto_nothrow_fndecls, DECL_UID (fndecl)))
	      VEC_safe_push (tree, heap, decls, fndecl);
	  }

	/* Now check the callees and also add them if they are nothrow.  This
	   is needed because node N may end up in a different partition than
	   its callees.  In which case, when the file holding N is compiled,
	   the calls it makes to nothrow functions will not be fixed up,
	   causing verification issues.  */
	for (e = n->callees; e; e = e->next_callee)
	  {
	    fndecl = e->callee->decl;
	    if (!bitmap_bit_p (seen_decls, DECL_UID (fndecl)))
	      {
		bitmap_set_bit (seen_decls, (DECL_UID (fndecl)));
		if (bitmap_bit_p (lto_nothrow_fndecls, DECL_UID (fndecl)))
		  VEC_safe_push (tree, heap, decls, fndecl);
	      }
	  }
      }

  /* Write out number of DECLs, followed by the DECLs.  */
  count = VEC_length (tree, decls); 
  lto_output_uleb128_stream (ob->main_stream, count);
  for (i = 0; i < count; i++)
    {
      fndecl = VEC_index (tree, decls, i);
      lto_output_fn_decl_index (ob->decl_state, ob->main_stream, fndecl);
    }

  /* Release resources.  */
  lto_destroy_simple_output_block (ob);
  VEC_free(tree, heap, decls);
  lto_bitmap_free (seen_decls);
}

/* Read in WPA fix-up information from one file. FILE_DATA points to
   DECL information of the file where as IB is the input block for the
   WPA fix-up section.  */

static void
lto_input_wpa_fixup_1 (struct lto_file_decl_data *file_data,
		   struct lto_input_block *ib)
{
  unsigned HOST_WIDE_INT i, count, decl_index;
  tree fndecl;

  count = lto_input_uleb128 (ib);
  for (i = 0; i < count; i++)
    {
      decl_index = lto_input_uleb128 (ib);
      fndecl = lto_file_decl_data_get_fn_decl (file_data, decl_index);
      lto_mark_nothrow_fndecl (fndecl);
    }
}

/* Read in WPA fix-up information. */

static void
lto_input_wpa_fixup (void)
{
  struct lto_file_decl_data ** file_data_vec
    = lto_get_file_decl_data ();
  struct lto_file_decl_data * file_data;
  int i = 0;

  /* Fix up information is only used in LTRANS mode.  */
  if (!flag_ltrans)
    return;

  while ((file_data = file_data_vec[i++]))
    {
      const char *data;
      size_t len;
      struct lto_input_block *ib
	= lto_create_simple_input_block (file_data, LTO_section_wpa_fixup,
					 &data, &len);

      lto_input_wpa_fixup_1 (file_data, ib);
      lto_destroy_simple_input_block (file_data, LTO_section_wpa_fixup, ib,
				      data, len);
    }
}

/* Gate function for all lto streaming passes.  */

static bool
gate_wpa_fixup (void)
{
  return (flag_wpa || flag_ltrans) && gate_lto_out ();
}

struct ipa_opt_pass_d pass_ipa_lto_wpa_fixup =
{
 {
  IPA_PASS,
  "lto_wpa_fixup",			/* name */
  gate_wpa_fixup,		        /* gate */
  NULL,		                        /* execute */
  NULL,					/* sub */
  NULL,					/* next */
  0,					/* static_pass_number */
  TV_WHOPR_WPA_FIXUP,		        /* tv_id */
  0,	                                /* properties_required */
  0,					/* properties_provided */
  0,					/* properties_destroyed */
  0,            			/* todo_flags_start */
  TODO_dump_func                        /* todo_flags_finish */
 },
 NULL,		                        /* generate_summary */
 lto_output_wpa_fixup,			/* write_summary */
 lto_input_wpa_fixup,			/* read_summary */
 NULL,					/* function_read_summary */
 NULL,					/* stmt_fixup */
 0,					/* TODOs */
 NULL,			                /* function_transform */
 NULL					/* variable_transform */
};

