/* Routines for emitting trees to a file stream.

   Copyright (C) 2011-2017 Free Software Foundation, Inc.
   Contributed by Diego Novillo <dnovillo@google.com>

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
#include "backend.h"
#include "target.h"
#include "tree.h"
#include "gimple.h"
#include "tree-streamer.h"
#include "cgraph.h"
#include "alias.h"
#include "stor-layout.h"
#include "gomp-constants.h"


/* Output the STRING constant to the string
   table in OB.  Then put the index onto the INDEX_STREAM.  */

void
streamer_write_string_cst (struct output_block *ob,
			   struct lto_output_stream *index_stream,
			   tree string)
{
  streamer_write_string_with_length (ob, index_stream,
				     string ? TREE_STRING_POINTER (string)
					    : NULL,
				     string ? TREE_STRING_LENGTH (string) : 0,
				     true);
}


/* Output the identifier ID to the string
   table in OB.  Then put the index onto the INDEX_STREAM.  */

static void
write_identifier (struct output_block *ob,
		   struct lto_output_stream *index_stream,
		   tree id)
{
  streamer_write_string_with_length (ob, index_stream,
				     IDENTIFIER_POINTER (id),
				     IDENTIFIER_LENGTH (id),
				     true);
}


/* Pack all the non-pointer fields of the TS_BASE structure of
   expression EXPR into bitpack BP.  */

static inline void
pack_ts_base_value_fields (struct bitpack_d *bp, tree expr)
{
  bp_pack_value (bp, TREE_CODE (expr), 16);
  if (!TYPE_P (expr))
    {
      bp_pack_value (bp, TREE_SIDE_EFFECTS (expr), 1);
      bp_pack_value (bp, TREE_CONSTANT (expr), 1);
      bp_pack_value (bp, TREE_READONLY (expr), 1);

      /* TREE_PUBLIC is used on types to indicate that the type
	 has a TYPE_CACHED_VALUES vector.  This is not streamed out,
	 so we skip it here.  */
      bp_pack_value (bp, TREE_PUBLIC (expr), 1);
    }
  else
    bp_pack_value (bp, 0, 4);
  bp_pack_value (bp, TREE_ADDRESSABLE (expr), 1);
  bp_pack_value (bp, TREE_THIS_VOLATILE (expr), 1);
  if (DECL_P (expr))
    {
      bp_pack_value (bp, DECL_UNSIGNED (expr), 1);
      bp_pack_value (bp, DECL_NAMELESS (expr), 1);
    }
  else if (TYPE_P (expr))
    bp_pack_value (bp, TYPE_UNSIGNED (expr), 1);
  else
    bp_pack_value (bp, 0, 1);
  /* We write debug info two times, do not confuse the second one.
     The only relevant TREE_ASM_WRITTEN use is on SSA names.  */
  bp_pack_value (bp, (TREE_CODE (expr) != SSA_NAME
		      ? 0 : TREE_ASM_WRITTEN (expr)), 1);
  if (TYPE_P (expr))
    bp_pack_value (bp, TYPE_ARTIFICIAL (expr), 1);
  else
    bp_pack_value (bp, TREE_NO_WARNING (expr), 1);
  bp_pack_value (bp, TREE_NOTHROW (expr), 1);
  bp_pack_value (bp, TREE_STATIC (expr), 1);
  if (TREE_CODE (expr) != TREE_BINFO)
    bp_pack_value (bp, TREE_PRIVATE (expr), 1);
  else
    bp_pack_value (bp, 0, 1);
  bp_pack_value (bp, TREE_PROTECTED (expr), 1);
  bp_pack_value (bp, TREE_DEPRECATED (expr), 1);
  if (TYPE_P (expr))
    {
      if (AGGREGATE_TYPE_P (expr))
	bp_pack_value (bp, TYPE_REVERSE_STORAGE_ORDER (expr), 1);
      else
	bp_pack_value (bp, TYPE_SATURATING (expr), 1);
      bp_pack_value (bp, TYPE_ADDR_SPACE (expr), 8);
    }
  else if (TREE_CODE (expr) == BIT_FIELD_REF || TREE_CODE (expr) == MEM_REF)
    {
      bp_pack_value (bp, REF_REVERSE_STORAGE_ORDER (expr), 1);
      bp_pack_value (bp, 0, 8);
    }
  else if (TREE_CODE (expr) == SSA_NAME)
    {
      bp_pack_value (bp, SSA_NAME_IS_DEFAULT_DEF (expr), 1);
      bp_pack_value (bp, 0, 8);
    }
  else
    bp_pack_value (bp, 0, 9);
}


/* Pack all the non-pointer fields of the TS_INTEGER_CST structure of
   expression EXPR into bitpack BP.  */

static void
pack_ts_int_cst_value_fields (struct bitpack_d *bp, tree expr)
{
  int i;
  /* Note that the number of elements has already been written out in
     streamer_write_tree_header.  */
  for (i = 0; i < TREE_INT_CST_EXT_NUNITS (expr); i++)
    bp_pack_var_len_int (bp, TREE_INT_CST_ELT (expr, i));
}


/* Pack all the non-pointer fields of the TS_REAL_CST structure of
   expression EXPR into bitpack BP.  */

static void
pack_ts_real_cst_value_fields (struct bitpack_d *bp, tree expr)
{
  unsigned i;
  REAL_VALUE_TYPE r;

  r = TREE_REAL_CST (expr);
  bp_pack_value (bp, r.cl, 2);
  bp_pack_value (bp, r.decimal, 1);
  bp_pack_value (bp, r.sign, 1);
  bp_pack_value (bp, r.signalling, 1);
  bp_pack_value (bp, r.canonical, 1);
  bp_pack_value (bp, r.uexp, EXP_BITS);
  for (i = 0; i < SIGSZ; i++)
    bp_pack_value (bp, r.sig[i], HOST_BITS_PER_LONG);
}


/* Pack all the non-pointer fields of the TS_FIXED_CST structure of
   expression EXPR into bitpack BP.  */

static void
pack_ts_fixed_cst_value_fields (struct bitpack_d *bp, tree expr)
{
  struct fixed_value fv = TREE_FIXED_CST (expr);
  bp_pack_machine_mode (bp, fv.mode);
  bp_pack_var_len_int (bp, fv.data.low);
  bp_pack_var_len_int (bp, fv.data.high);
}

/* Pack all the non-pointer fields of the TS_DECL_COMMON structure
   of expression EXPR into bitpack BP.  */

static void
pack_ts_decl_common_value_fields (struct bitpack_d *bp, tree expr)
{
  bp_pack_machine_mode (bp, DECL_MODE (expr));
  bp_pack_value (bp, DECL_NONLOCAL (expr), 1);
  bp_pack_value (bp, DECL_VIRTUAL_P (expr), 1);
  bp_pack_value (bp, DECL_IGNORED_P (expr), 1);
  bp_pack_value (bp, DECL_ABSTRACT_P (expr), 1);
  bp_pack_value (bp, DECL_ARTIFICIAL (expr), 1);
  bp_pack_value (bp, DECL_USER_ALIGN (expr), 1);
  bp_pack_value (bp, DECL_PRESERVE_P (expr), 1);
  bp_pack_value (bp, DECL_EXTERNAL (expr), 1);
  bp_pack_value (bp, DECL_GIMPLE_REG_P (expr), 1);
  bp_pack_var_len_unsigned (bp, DECL_ALIGN (expr));

  if (TREE_CODE (expr) == LABEL_DECL)
    {
      /* Note that we do not write LABEL_DECL_UID.  The reader will
	 always assume an initial value of -1 so that the
	 label_to_block_map is recreated by gimple_set_bb.  */
      bp_pack_var_len_unsigned (bp, EH_LANDING_PAD_NR (expr));
    }

  if (TREE_CODE (expr) == FIELD_DECL)
    {
      bp_pack_value (bp, DECL_PACKED (expr), 1);
      bp_pack_value (bp, DECL_NONADDRESSABLE_P (expr), 1);
      bp_pack_value (bp, expr->decl_common.off_align, 8);
    }

  if (VAR_P (expr))
    {
      bp_pack_value (bp, DECL_HAS_DEBUG_EXPR_P (expr), 1);
      bp_pack_value (bp, DECL_NONLOCAL_FRAME (expr), 1);
    }

  if (TREE_CODE (expr) == RESULT_DECL
      || TREE_CODE (expr) == PARM_DECL
      || VAR_P (expr))
    {
      bp_pack_value (bp, DECL_BY_REFERENCE (expr), 1);
      if (VAR_P (expr) || TREE_CODE (expr) == PARM_DECL)
	bp_pack_value (bp, DECL_HAS_VALUE_EXPR_P (expr), 1);
    }
}


/* Pack all the non-pointer fields of the TS_DECL_WRTL structure
   of expression EXPR into bitpack BP.  */

static void
pack_ts_decl_wrtl_value_fields (struct bitpack_d *bp, tree expr)
{
  bp_pack_value (bp, DECL_REGISTER (expr), 1);
}


/* Pack all the non-pointer fields of the TS_DECL_WITH_VIS structure
   of expression EXPR into bitpack BP.  */

static void
pack_ts_decl_with_vis_value_fields (struct bitpack_d *bp, tree expr)
{
  bp_pack_value (bp, DECL_COMMON (expr), 1);
  bp_pack_value (bp, DECL_DLLIMPORT_P (expr), 1);
  bp_pack_value (bp, DECL_WEAK (expr), 1);
  bp_pack_value (bp, DECL_SEEN_IN_BIND_EXPR_P (expr),  1);
  bp_pack_value (bp, DECL_COMDAT (expr),  1);
  bp_pack_value (bp, DECL_VISIBILITY (expr),  2);
  bp_pack_value (bp, DECL_VISIBILITY_SPECIFIED (expr),  1);

  if (VAR_P (expr))
    {
      bp_pack_value (bp, DECL_HARD_REGISTER (expr), 1);
      /* DECL_IN_TEXT_SECTION is set during final asm output only. */
      bp_pack_value (bp, DECL_IN_CONSTANT_POOL (expr), 1);
    }

  if (TREE_CODE (expr) == FUNCTION_DECL)
    {
      bp_pack_value (bp, DECL_FINAL_P (expr), 1);
      bp_pack_value (bp, DECL_CXX_CONSTRUCTOR_P (expr), 1);
      bp_pack_value (bp, DECL_CXX_DESTRUCTOR_P (expr), 1);
    }
}


/* Pack all the non-pointer fields of the TS_FUNCTION_DECL structure
   of expression EXPR into bitpack BP.  */

static void
pack_ts_function_decl_value_fields (struct bitpack_d *bp, tree expr)
{
  bp_pack_enum (bp, built_in_class, BUILT_IN_LAST,
		DECL_BUILT_IN_CLASS (expr));
  bp_pack_value (bp, DECL_STATIC_CONSTRUCTOR (expr), 1);
  bp_pack_value (bp, DECL_STATIC_DESTRUCTOR (expr), 1);
  bp_pack_value (bp, DECL_UNINLINABLE (expr), 1);
  bp_pack_value (bp, DECL_POSSIBLY_INLINED (expr), 1);
  bp_pack_value (bp, DECL_IS_NOVOPS (expr), 1);
  bp_pack_value (bp, DECL_IS_RETURNS_TWICE (expr), 1);
  bp_pack_value (bp, DECL_IS_MALLOC (expr), 1);
  bp_pack_value (bp, DECL_IS_OPERATOR_NEW (expr), 1);
  bp_pack_value (bp, DECL_DECLARED_INLINE_P (expr), 1);
  bp_pack_value (bp, DECL_STATIC_CHAIN (expr), 1);
  bp_pack_value (bp, DECL_NO_INLINE_WARNING_P (expr), 1);
  bp_pack_value (bp, DECL_NO_INSTRUMENT_FUNCTION_ENTRY_EXIT (expr), 1);
  bp_pack_value (bp, DECL_NO_LIMIT_STACK (expr), 1);
  bp_pack_value (bp, DECL_DISREGARD_INLINE_LIMITS (expr), 1);
  bp_pack_value (bp, DECL_PURE_P (expr), 1);
  bp_pack_value (bp, DECL_LOOPING_CONST_OR_PURE_P (expr), 1);
  if (DECL_BUILT_IN_CLASS (expr) != NOT_BUILT_IN)
    bp_pack_value (bp, DECL_FUNCTION_CODE (expr), 12);
}


/* Pack all the non-pointer fields of the TS_TYPE_COMMON structure
   of expression EXPR into bitpack BP.  */

static void
pack_ts_type_common_value_fields (struct bitpack_d *bp, tree expr)
{
  /* for VECTOR_TYPE, TYPE_MODE reevaluates the mode using target_flags
     not necessary valid in a global context.
     Use the raw value previously set by layout_type.  */
  bp_pack_machine_mode (bp, TYPE_MODE_RAW (expr));
  bp_pack_value (bp, TYPE_STRING_FLAG (expr), 1);
  /* TYPE_NO_FORCE_BLK is private to stor-layout and need
     no streaming.  */
  bp_pack_value (bp, TYPE_NEEDS_CONSTRUCTING (expr), 1);
  bp_pack_value (bp, TYPE_PACKED (expr), 1);
  bp_pack_value (bp, TYPE_RESTRICT (expr), 1);
  bp_pack_value (bp, TYPE_USER_ALIGN (expr), 1);
  bp_pack_value (bp, TYPE_READONLY (expr), 1);
  /* We used to stream TYPE_ALIAS_SET == 0 information to let frontends mark
     types that are opaque for TBAA.  This however did not work as intended,
     because TYPE_ALIAS_SET == 0 was regularly lost in type merging.  */
  if (RECORD_OR_UNION_TYPE_P (expr))
    {
      bp_pack_value (bp, TYPE_TRANSPARENT_AGGR (expr), 1);
      bp_pack_value (bp, TYPE_FINAL_P (expr), 1);
    }
  else if (TREE_CODE (expr) == ARRAY_TYPE)
    bp_pack_value (bp, TYPE_NONALIASED_COMPONENT (expr), 1);
  if (AGGREGATE_TYPE_P (expr))
    bp_pack_value (bp, TYPE_TYPELESS_STORAGE (expr), 1);
  bp_pack_var_len_unsigned (bp, TYPE_PRECISION (expr));
  bp_pack_var_len_unsigned (bp, TYPE_ALIGN (expr));
}


/* Pack all the non-pointer fields of the TS_BLOCK structure
   of expression EXPR into bitpack BP.  */

static void
pack_ts_block_value_fields (struct output_block *ob,
			    struct bitpack_d *bp, tree expr)
{
  bp_pack_value (bp, BLOCK_ABSTRACT (expr), 1);
  /* BLOCK_NUMBER is recomputed.  */
  /* Stream BLOCK_SOURCE_LOCATION for the limited cases we can handle - those
     that represent inlined function scopes.
     For the rest them on the floor instead of ICEing in dwarf2out.c.  */
  if (inlined_function_outer_scope_p (expr))
    stream_output_location (ob, bp, BLOCK_SOURCE_LOCATION (expr));
  else
    stream_output_location (ob, bp, UNKNOWN_LOCATION);
}

/* Pack all the non-pointer fields of the TS_TRANSLATION_UNIT_DECL structure
   of expression EXPR into bitpack BP.  */

static void
pack_ts_translation_unit_decl_value_fields (struct output_block *ob,
					    struct bitpack_d *bp, tree expr)
{
  bp_pack_string (ob, bp, TRANSLATION_UNIT_LANGUAGE (expr), true);
}


/* Pack all the non-pointer fields of the TS_OMP_CLAUSE structure
   of expression EXPR into bitpack BP.  */

static void
pack_ts_omp_clause_value_fields (struct output_block *ob,
				 struct bitpack_d *bp, tree expr)
{
  stream_output_location (ob, bp, OMP_CLAUSE_LOCATION (expr));
  switch (OMP_CLAUSE_CODE (expr))
    {
    case OMP_CLAUSE_DEFAULT:
      bp_pack_enum (bp, omp_clause_default_kind, OMP_CLAUSE_DEFAULT_LAST,
		    OMP_CLAUSE_DEFAULT_KIND (expr));
      break;
    case OMP_CLAUSE_SCHEDULE:
      bp_pack_enum (bp, omp_clause_schedule_kind, OMP_CLAUSE_SCHEDULE_LAST,
		    OMP_CLAUSE_SCHEDULE_KIND (expr));
      break;
    case OMP_CLAUSE_DEPEND:
      bp_pack_enum (bp, omp_clause_depend_kind, OMP_CLAUSE_DEPEND_LAST,
		    OMP_CLAUSE_DEPEND_KIND (expr));
      break;
    case OMP_CLAUSE_MAP:
      bp_pack_enum (bp, gomp_map_kind, GOMP_MAP_LAST,
		    OMP_CLAUSE_MAP_KIND (expr));
      break;
    case OMP_CLAUSE_PROC_BIND:
      bp_pack_enum (bp, omp_clause_proc_bind_kind, OMP_CLAUSE_PROC_BIND_LAST,
		    OMP_CLAUSE_PROC_BIND_KIND (expr));
      break;
    case OMP_CLAUSE_REDUCTION:
      bp_pack_enum (bp, tree_code, MAX_TREE_CODES,
		    OMP_CLAUSE_REDUCTION_CODE (expr));
      break;
    default:
      break;
    }
}


/* Pack all the bitfields in EXPR into a bit pack.  */

void
streamer_write_tree_bitfields (struct output_block *ob, tree expr)
{
  bitpack_d bp = bitpack_create (ob->main_stream);
  enum tree_code code;

  code = TREE_CODE (expr);

  /* Note that all these functions are highly sensitive to changes in
     the types and sizes of each of the fields being packed.  */
  pack_ts_base_value_fields (&bp, expr);

  if (CODE_CONTAINS_STRUCT (code, TS_INT_CST))
    pack_ts_int_cst_value_fields (&bp, expr);

  if (CODE_CONTAINS_STRUCT (code, TS_REAL_CST))
    pack_ts_real_cst_value_fields (&bp, expr);

  if (CODE_CONTAINS_STRUCT (code, TS_FIXED_CST))
    pack_ts_fixed_cst_value_fields (&bp, expr);

  if (CODE_CONTAINS_STRUCT (code, TS_DECL_MINIMAL))
    stream_output_location (ob, &bp, DECL_SOURCE_LOCATION (expr));

  if (CODE_CONTAINS_STRUCT (code, TS_DECL_COMMON))
    pack_ts_decl_common_value_fields (&bp, expr);

  if (CODE_CONTAINS_STRUCT (code, TS_DECL_WRTL))
    pack_ts_decl_wrtl_value_fields (&bp, expr);

  if (CODE_CONTAINS_STRUCT (code, TS_DECL_WITH_VIS))
    pack_ts_decl_with_vis_value_fields (&bp, expr);

  if (CODE_CONTAINS_STRUCT (code, TS_FUNCTION_DECL))
    pack_ts_function_decl_value_fields (&bp, expr);

  if (CODE_CONTAINS_STRUCT (code, TS_TYPE_COMMON))
    pack_ts_type_common_value_fields (&bp, expr);

  if (CODE_CONTAINS_STRUCT (code, TS_EXP))
    {
      stream_output_location (ob, &bp, EXPR_LOCATION (expr));
      if (code == MEM_REF
	  || code == TARGET_MEM_REF)
	{
	  bp_pack_value (&bp, MR_DEPENDENCE_CLIQUE (expr), sizeof (short) * 8);
	  if (MR_DEPENDENCE_CLIQUE (expr) != 0)
	    bp_pack_value (&bp, MR_DEPENDENCE_BASE (expr), sizeof (short) * 8);
	}
    }

  if (CODE_CONTAINS_STRUCT (code, TS_BLOCK))
    pack_ts_block_value_fields (ob, &bp, expr);

  if (CODE_CONTAINS_STRUCT (code, TS_TRANSLATION_UNIT_DECL))
    pack_ts_translation_unit_decl_value_fields (ob, &bp, expr);

  if (CODE_CONTAINS_STRUCT (code, TS_OPTIMIZATION))
    cl_optimization_stream_out (&bp, TREE_OPTIMIZATION (expr));

  if (CODE_CONTAINS_STRUCT (code, TS_BINFO))
    bp_pack_var_len_unsigned (&bp, vec_safe_length (BINFO_BASE_ACCESSES (expr)));

  if (CODE_CONTAINS_STRUCT (code, TS_CONSTRUCTOR))
    bp_pack_var_len_unsigned (&bp, CONSTRUCTOR_NELTS (expr));

  if (CODE_CONTAINS_STRUCT (code, TS_TARGET_OPTION)
      /* Don't stream these when passing things to a different target.  */
      && !lto_stream_offload_p)
    cl_target_option_stream_out (ob, &bp, TREE_TARGET_OPTION (expr));

  if (code == OMP_CLAUSE)
    pack_ts_omp_clause_value_fields (ob, &bp, expr);

  streamer_write_bitpack (&bp);
}


/* Emit the chain of tree nodes starting at T.  OB is the output block
   to write to.  REF_P is true if chain elements should be emitted
   as references.  */

void
streamer_write_chain (struct output_block *ob, tree t, bool ref_p)
{
  while (t)
    {
      /* We avoid outputting external vars or functions by reference
	 to the global decls section as we do not want to have them
	 enter decl merging.  This is, of course, only for the call
	 for streaming BLOCK_VARS, but other callers are safe.
	 See also lto-streamer-out.c:DFS_write_tree_body.  */
      if (VAR_OR_FUNCTION_DECL_P (t)
	  && DECL_EXTERNAL (t))
	stream_write_tree_shallow_non_ref (ob, t, ref_p);
      else
	stream_write_tree (ob, t, ref_p);

      t = TREE_CHAIN (t);
    }

  /* Write a sentinel to terminate the chain.  */
  stream_write_tree (ob, NULL_TREE, ref_p);
}


/* Write all pointer fields in the TS_COMMON structure of EXPR to output
   block OB.  If REF_P is true, write a reference to EXPR's pointer
   fields.  */

static void
write_ts_common_tree_pointers (struct output_block *ob, tree expr, bool ref_p)
{
  if (TREE_CODE (expr) != IDENTIFIER_NODE)
    stream_write_tree (ob, TREE_TYPE (expr), ref_p);
}


/* Write all pointer fields in the TS_VECTOR structure of EXPR to output
   block OB.  If REF_P is true, write a reference to EXPR's pointer
   fields.  */

static void
write_ts_vector_tree_pointers (struct output_block *ob, tree expr, bool ref_p)
{
  unsigned i;
  /* Note that the number of elements for EXPR has already been emitted
     in EXPR's header (see streamer_write_tree_header).  */
  for (i = 0; i < VECTOR_CST_NELTS (expr); ++i)
    stream_write_tree (ob, VECTOR_CST_ELT (expr, i), ref_p);
}


/* Write all pointer fields in the TS_COMPLEX structure of EXPR to output
   block OB.  If REF_P is true, write a reference to EXPR's pointer
   fields.  */

static void
write_ts_complex_tree_pointers (struct output_block *ob, tree expr, bool ref_p)
{
  stream_write_tree (ob, TREE_REALPART (expr), ref_p);
  stream_write_tree (ob, TREE_IMAGPART (expr), ref_p);
}


/* Write all pointer fields in the TS_DECL_MINIMAL structure of EXPR
   to output block OB.  If REF_P is true, write a reference to EXPR's
   pointer fields.  */

static void
write_ts_decl_minimal_tree_pointers (struct output_block *ob, tree expr,
				     bool ref_p)
{
  /* Drop names that were created for anonymous entities.  */
  if (DECL_NAME (expr)
      && TREE_CODE (DECL_NAME (expr)) == IDENTIFIER_NODE
      && anon_aggrname_p (DECL_NAME (expr)))
    stream_write_tree (ob, NULL_TREE, ref_p);
  else
    stream_write_tree (ob, DECL_NAME (expr), ref_p);
  if (TREE_CODE (expr) != TRANSLATION_UNIT_DECL
      && ! DECL_CONTEXT (expr))
    stream_write_tree (ob, (*all_translation_units)[0], ref_p);
  else
    stream_write_tree (ob, DECL_CONTEXT (expr), ref_p);
}


/* Write all pointer fields in the TS_DECL_COMMON structure of EXPR to
   output block OB.  If REF_P is true, write a reference to EXPR's
   pointer fields.  */

static void
write_ts_decl_common_tree_pointers (struct output_block *ob, tree expr,
				    bool ref_p)
{
  stream_write_tree (ob, DECL_SIZE (expr), ref_p);
  stream_write_tree (ob, DECL_SIZE_UNIT (expr), ref_p);

  /* Note, DECL_INITIAL is not handled here.  Since DECL_INITIAL needs
     special handling in LTO, it must be handled by streamer hooks.  */

  stream_write_tree (ob, DECL_ATTRIBUTES (expr), ref_p);
  stream_write_tree (ob, DECL_ABSTRACT_ORIGIN (expr), ref_p);

  if ((VAR_P (expr) || TREE_CODE (expr) == PARM_DECL)
      && DECL_HAS_VALUE_EXPR_P (expr))
    stream_write_tree (ob, DECL_VALUE_EXPR (expr), ref_p);

  if (VAR_P (expr))
    stream_write_tree (ob, DECL_DEBUG_EXPR (expr), ref_p);
}


/* Write all pointer fields in the TS_DECL_NON_COMMON structure of
   EXPR to output block OB.  If REF_P is true, write a reference to EXPR's
   pointer fields.  */

static void
write_ts_decl_non_common_tree_pointers (struct output_block *ob, tree expr,
				        bool ref_p)
{
  if (TREE_CODE (expr) == TYPE_DECL)
    stream_write_tree (ob, DECL_ORIGINAL_TYPE (expr), ref_p);
}


/* Write all pointer fields in the TS_DECL_WITH_VIS structure of EXPR
   to output block OB.  If REF_P is true, write a reference to EXPR's
   pointer fields.  */

static void
write_ts_decl_with_vis_tree_pointers (struct output_block *ob, tree expr,
			              bool ref_p)
{
  /* Make sure we don't inadvertently set the assembler name.  */
  if (DECL_ASSEMBLER_NAME_SET_P (expr))
    stream_write_tree (ob, DECL_ASSEMBLER_NAME (expr), ref_p);
  else
    stream_write_tree (ob, NULL_TREE, false);
}


/* Write all pointer fields in the TS_FIELD_DECL structure of EXPR to
   output block OB.  If REF_P is true, write a reference to EXPR's
   pointer fields.  */

static void
write_ts_field_decl_tree_pointers (struct output_block *ob, tree expr,
				   bool ref_p)
{
  stream_write_tree (ob, DECL_FIELD_OFFSET (expr), ref_p);
  stream_write_tree (ob, DECL_BIT_FIELD_TYPE (expr), ref_p);
  stream_write_tree (ob, DECL_BIT_FIELD_REPRESENTATIVE (expr), ref_p);
  stream_write_tree (ob, DECL_FIELD_BIT_OFFSET (expr), ref_p);
  stream_write_tree (ob, DECL_FCONTEXT (expr), ref_p);
}


/* Write all pointer fields in the TS_FUNCTION_DECL structure of EXPR
   to output block OB.  If REF_P is true, write a reference to EXPR's
   pointer fields.  */

static void
write_ts_function_decl_tree_pointers (struct output_block *ob, tree expr,
				      bool ref_p)
{
  stream_write_tree (ob, DECL_VINDEX (expr), ref_p);
  /* DECL_STRUCT_FUNCTION is handled by lto_output_function.  */
  stream_write_tree (ob, DECL_FUNCTION_PERSONALITY (expr), ref_p);
  /* Don't stream these when passing things to a different target.  */
  if (!lto_stream_offload_p)
    stream_write_tree (ob, DECL_FUNCTION_SPECIFIC_TARGET (expr), ref_p);
  stream_write_tree (ob, DECL_FUNCTION_SPECIFIC_OPTIMIZATION (expr), ref_p);
}


/* Write all pointer fields in the TS_TYPE_COMMON structure of EXPR to
   output block OB.  If REF_P is true, write a reference to EXPR's
   pointer fields.  */

static void
write_ts_type_common_tree_pointers (struct output_block *ob, tree expr,
				    bool ref_p)
{
  stream_write_tree (ob, TYPE_SIZE (expr), ref_p);
  stream_write_tree (ob, TYPE_SIZE_UNIT (expr), ref_p);
  stream_write_tree (ob, TYPE_ATTRIBUTES (expr), ref_p);
  stream_write_tree (ob, TYPE_NAME (expr), ref_p);
  /* Do not stream TYPE_POINTER_TO or TYPE_REFERENCE_TO.  They will be
     reconstructed during fixup.  */
  /* Do not stream TYPE_NEXT_VARIANT, we reconstruct the variant lists
     during fixup.  */
  stream_write_tree (ob, TYPE_MAIN_VARIANT (expr), ref_p);
  stream_write_tree (ob, TYPE_CONTEXT (expr), ref_p);
  /* TYPE_CANONICAL is re-computed during type merging, so no need
     to stream it here.  */
  stream_write_tree (ob, TYPE_STUB_DECL (expr), ref_p);
}

/* Write all pointer fields in the TS_TYPE_NON_COMMON structure of EXPR
   to output block OB.  If REF_P is true, write a reference to EXPR's
   pointer fields.  */

static void
write_ts_type_non_common_tree_pointers (struct output_block *ob, tree expr,
					bool ref_p)
{
  if (TREE_CODE (expr) == ENUMERAL_TYPE)
    stream_write_tree (ob, TYPE_VALUES (expr), ref_p);
  else if (TREE_CODE (expr) == ARRAY_TYPE)
    stream_write_tree (ob, TYPE_DOMAIN (expr), ref_p);
  else if (RECORD_OR_UNION_TYPE_P (expr))
    streamer_write_chain (ob, TYPE_FIELDS (expr), ref_p);
  else if (TREE_CODE (expr) == FUNCTION_TYPE
	   || TREE_CODE (expr) == METHOD_TYPE)
    stream_write_tree (ob, TYPE_ARG_TYPES (expr), ref_p);

  if (!POINTER_TYPE_P (expr))
    stream_write_tree (ob, TYPE_MIN_VALUE_RAW (expr), ref_p);
  stream_write_tree (ob, TYPE_MAX_VALUE_RAW (expr), ref_p);
}


/* Write all pointer fields in the TS_LIST structure of EXPR to output
   block OB.  If REF_P is true, write a reference to EXPR's pointer
   fields.  */

static void
write_ts_list_tree_pointers (struct output_block *ob, tree expr, bool ref_p)
{
  stream_write_tree (ob, TREE_PURPOSE (expr), ref_p);
  stream_write_tree (ob, TREE_VALUE (expr), ref_p);
  stream_write_tree (ob, TREE_CHAIN (expr), ref_p);
}


/* Write all pointer fields in the TS_VEC structure of EXPR to output
   block OB.  If REF_P is true, write a reference to EXPR's pointer
   fields.  */

static void
write_ts_vec_tree_pointers (struct output_block *ob, tree expr, bool ref_p)
{
  int i;

  /* Note that the number of slots for EXPR has already been emitted
     in EXPR's header (see streamer_write_tree_header).  */
  for (i = 0; i < TREE_VEC_LENGTH (expr); i++)
    stream_write_tree (ob, TREE_VEC_ELT (expr, i), ref_p);
}


/* Write all pointer fields in the TS_EXP structure of EXPR to output
   block OB.  If REF_P is true, write a reference to EXPR's pointer
   fields.  */

static void
write_ts_exp_tree_pointers (struct output_block *ob, tree expr, bool ref_p)
{
  int i;

  for (i = 0; i < TREE_OPERAND_LENGTH (expr); i++)
    stream_write_tree (ob, TREE_OPERAND (expr, i), ref_p);
  stream_write_tree (ob, TREE_BLOCK (expr), ref_p);
}


/* Write all pointer fields in the TS_BLOCK structure of EXPR to output
   block OB.  If REF_P is true, write a reference to EXPR's pointer
   fields.  */

static void
write_ts_block_tree_pointers (struct output_block *ob, tree expr, bool ref_p)
{
  streamer_write_chain (ob, BLOCK_VARS (expr), ref_p);

  stream_write_tree (ob, BLOCK_SUPERCONTEXT (expr), ref_p);

  /* Stream BLOCK_ABSTRACT_ORIGIN for the limited cases we can handle - those
     that represent inlined function scopes.
     For the rest them on the floor instead of ICEing in dwarf2out.c, but
     keep the notion of whether the block is an inlined block by refering
     to itself for the sake of tree_nonartificial_location.  */
  if (inlined_function_outer_scope_p (expr))
    {
      tree ultimate_origin = block_ultimate_origin (expr);
      stream_write_tree (ob, ultimate_origin, ref_p);
    }
  else
    stream_write_tree (ob, (BLOCK_ABSTRACT_ORIGIN (expr)
			    ? expr : NULL_TREE), ref_p);
  /* Do not stream BLOCK_NONLOCALIZED_VARS.  We cannot handle debug information
     for early inlined BLOCKs so drop it on the floor instead of ICEing in
     dwarf2out.c.  */

  /* BLOCK_FRAGMENT_ORIGIN and BLOCK_FRAGMENT_CHAIN is not live at LTO
     streaming time.  */

  /* Do not output BLOCK_SUBBLOCKS.  Instead on streaming-in this
     list is re-constructed from BLOCK_SUPERCONTEXT.  */
}


/* Write all pointer fields in the TS_BINFO structure of EXPR to output
   block OB.  If REF_P is true, write a reference to EXPR's pointer
   fields.  */

static void
write_ts_binfo_tree_pointers (struct output_block *ob, tree expr, bool ref_p)
{
  unsigned i;
  tree t;

  /* Note that the number of BINFO slots has already been emitted in
     EXPR's header (see streamer_write_tree_header) because this length
     is needed to build the empty BINFO node on the reader side.  */
  FOR_EACH_VEC_ELT (*BINFO_BASE_BINFOS (expr), i, t)
    stream_write_tree (ob, t, ref_p);
  stream_write_tree (ob, NULL_TREE, false);

  stream_write_tree (ob, BINFO_OFFSET (expr), ref_p);
  stream_write_tree (ob, BINFO_VTABLE (expr), ref_p);
  stream_write_tree (ob, BINFO_VPTR_FIELD (expr), ref_p);

  /* The number of BINFO_BASE_ACCESSES has already been emitted in
     EXPR's bitfield section.  */
  FOR_EACH_VEC_SAFE_ELT (BINFO_BASE_ACCESSES (expr), i, t)
    stream_write_tree (ob, t, ref_p);

  /* Do not walk BINFO_INHERITANCE_CHAIN, BINFO_SUBVTT_INDEX
     and BINFO_VPTR_INDEX; these are used by C++ FE only.  */
}


/* Write all pointer fields in the TS_CONSTRUCTOR structure of EXPR to
   output block OB.  If REF_P is true, write a reference to EXPR's
   pointer fields.  */

static void
write_ts_constructor_tree_pointers (struct output_block *ob, tree expr,
				    bool ref_p)
{
  unsigned i;
  tree index, value;

  FOR_EACH_CONSTRUCTOR_ELT (CONSTRUCTOR_ELTS (expr), i, index, value)
    {
      stream_write_tree (ob, index, ref_p);
      stream_write_tree (ob, value, ref_p);
    }
}


/* Write all pointer fields in the TS_OMP_CLAUSE structure of EXPR
   to output block OB.  If REF_P is true, write a reference to EXPR's
   pointer fields.  */

static void
write_ts_omp_clause_tree_pointers (struct output_block *ob, tree expr,
				   bool ref_p)
{
  int i;
  for (i = 0; i < omp_clause_num_ops[OMP_CLAUSE_CODE (expr)]; i++)
    stream_write_tree (ob, OMP_CLAUSE_OPERAND (expr, i), ref_p);
  if (OMP_CLAUSE_CODE (expr) == OMP_CLAUSE_REDUCTION)
    {
      /* We don't stream these right now, handle it if streaming
	 of them is needed.  */
      gcc_assert (OMP_CLAUSE_REDUCTION_GIMPLE_INIT (expr) == NULL);
      gcc_assert (OMP_CLAUSE_REDUCTION_GIMPLE_MERGE (expr) == NULL);
    }
  stream_write_tree (ob, OMP_CLAUSE_CHAIN (expr), ref_p);
}


/* Write all pointer fields in EXPR to output block OB.  If REF_P is true,
   the leaves of EXPR are emitted as references.  */

void
streamer_write_tree_body (struct output_block *ob, tree expr, bool ref_p)
{
  enum tree_code code;

  lto_stats.num_tree_bodies_output++;

  code = TREE_CODE (expr);

  if (CODE_CONTAINS_STRUCT (code, TS_TYPED))
    write_ts_common_tree_pointers (ob, expr, ref_p);

  if (CODE_CONTAINS_STRUCT (code, TS_VECTOR))
    write_ts_vector_tree_pointers (ob, expr, ref_p);

  if (CODE_CONTAINS_STRUCT (code, TS_COMPLEX))
    write_ts_complex_tree_pointers (ob, expr, ref_p);

  if (CODE_CONTAINS_STRUCT (code, TS_DECL_MINIMAL))
    write_ts_decl_minimal_tree_pointers (ob, expr, ref_p);

  if (CODE_CONTAINS_STRUCT (code, TS_DECL_COMMON))
    write_ts_decl_common_tree_pointers (ob, expr, ref_p);

  if (CODE_CONTAINS_STRUCT (code, TS_DECL_NON_COMMON))
    write_ts_decl_non_common_tree_pointers (ob, expr, ref_p);

  if (CODE_CONTAINS_STRUCT (code, TS_DECL_WITH_VIS))
    write_ts_decl_with_vis_tree_pointers (ob, expr, ref_p);

  if (CODE_CONTAINS_STRUCT (code, TS_FIELD_DECL))
    write_ts_field_decl_tree_pointers (ob, expr, ref_p);

  if (CODE_CONTAINS_STRUCT (code, TS_FUNCTION_DECL))
    write_ts_function_decl_tree_pointers (ob, expr, ref_p);

  if (CODE_CONTAINS_STRUCT (code, TS_TYPE_COMMON))
    write_ts_type_common_tree_pointers (ob, expr, ref_p);

  if (CODE_CONTAINS_STRUCT (code, TS_TYPE_NON_COMMON))
    write_ts_type_non_common_tree_pointers (ob, expr, ref_p);

  if (CODE_CONTAINS_STRUCT (code, TS_LIST))
    write_ts_list_tree_pointers (ob, expr, ref_p);

  if (CODE_CONTAINS_STRUCT (code, TS_VEC))
    write_ts_vec_tree_pointers (ob, expr, ref_p);

  if (CODE_CONTAINS_STRUCT (code, TS_EXP))
    write_ts_exp_tree_pointers (ob, expr, ref_p);

  if (CODE_CONTAINS_STRUCT (code, TS_BLOCK))
    write_ts_block_tree_pointers (ob, expr, ref_p);

  if (CODE_CONTAINS_STRUCT (code, TS_BINFO))
    write_ts_binfo_tree_pointers (ob, expr, ref_p);

  if (CODE_CONTAINS_STRUCT (code, TS_CONSTRUCTOR))
    write_ts_constructor_tree_pointers (ob, expr, ref_p);

  if (code == OMP_CLAUSE)
    write_ts_omp_clause_tree_pointers (ob, expr, ref_p);
}


/* Emit header information for tree EXPR to output block OB.  The header
   contains everything needed to instantiate an empty skeleton for
   EXPR on the reading side.  IX is the index into the streamer cache
   where EXPR is stored.  */

void
streamer_write_tree_header (struct output_block *ob, tree expr)
{
  enum LTO_tags tag;
  enum tree_code code;

  /* We should not see any tree nodes not handled by the streamer.  */
  code = TREE_CODE (expr);

  /* The header of a tree node consists of its tag, the size of
     the node, and any other information needed to instantiate
     EXPR on the reading side (such as the number of slots in
     variable sized nodes).  */
  tag = lto_tree_code_to_tag (code);
  streamer_write_record_start (ob, tag);

  /* The text in strings and identifiers are completely emitted in
     the header.  */
  if (CODE_CONTAINS_STRUCT (code, TS_STRING))
    streamer_write_string_cst (ob, ob->main_stream, expr);
  else if (CODE_CONTAINS_STRUCT (code, TS_IDENTIFIER))
    write_identifier (ob, ob->main_stream, expr);
  else if (CODE_CONTAINS_STRUCT (code, TS_VECTOR))
    streamer_write_hwi (ob, VECTOR_CST_NELTS (expr));
  else if (CODE_CONTAINS_STRUCT (code, TS_VEC))
    streamer_write_hwi (ob, TREE_VEC_LENGTH (expr));
  else if (CODE_CONTAINS_STRUCT (code, TS_BINFO))
    streamer_write_uhwi (ob, BINFO_N_BASE_BINFOS (expr));
  else if (TREE_CODE (expr) == CALL_EXPR)
    streamer_write_uhwi (ob, call_expr_nargs (expr));
  else if (TREE_CODE (expr) == OMP_CLAUSE)
    streamer_write_uhwi (ob, OMP_CLAUSE_CODE (expr));
  else if (CODE_CONTAINS_STRUCT (code, TS_INT_CST))
    {
      gcc_checking_assert (TREE_INT_CST_NUNITS (expr));
      streamer_write_uhwi (ob, TREE_INT_CST_NUNITS (expr));
      streamer_write_uhwi (ob, TREE_INT_CST_EXT_NUNITS (expr));
    }
}


/* Emit the integer constant CST to output block OB.  If REF_P is true,
   CST's type will be emitted as a reference.  */

void
streamer_write_integer_cst (struct output_block *ob, tree cst, bool ref_p)
{
  int i;
  int len = TREE_INT_CST_NUNITS (cst);
  gcc_assert (!TREE_OVERFLOW (cst));
  streamer_write_record_start (ob, LTO_integer_cst);
  stream_write_tree (ob, TREE_TYPE (cst), ref_p);
  /* We're effectively streaming a non-sign-extended wide_int here,
     so there's no need to stream TREE_INT_CST_EXT_NUNITS or any
     array members beyond LEN.  We'll recreate the tree from the
     wide_int and the type.  */
  streamer_write_uhwi (ob, len);
  for (i = 0; i < len; i++)
    streamer_write_hwi (ob, TREE_INT_CST_ELT (cst, i));
}
