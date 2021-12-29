/* Definitions of target machine for GNU compiler KVX cores.
   Copyright (C) 1991-2014 Free Software Foundation, Inc.
   Copyright (C) 2017 Kalray

   This file is part of GCC.

   GCC is free software; you can redistribute it and/or modify it
   under the terms of the GNU General Public License as published
   by the Free Software Foundation; either version 3, or (at your
   option) any later version.

   GCC is distributed in the hope that it will be useful, but WITHOUT
   ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
   or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public
   License for more details.

   Under Section 7 of GPL version 3, you are granted additional
   permissions described in the GCC Runtime Library Exception, version
   3.1, as published by the Free Software Foundation.

   You should have received a copy of the GNU General Public License and
   a copy of the GCC Runtime Library Exception along with this program;
   see the files COPYING3 and COPYING.RUNTIME respectively.  If not, see
   <http://www.gnu.org/licenses/>.  */

#define IN_TARGET_CODE 1

#include "config.h"
#define INCLUDE_STRING
#include "system.h"
#include "coretypes.h"
#include "backend.h"
#include "target.h"
#include "rtl.h"
#include "rtl-iter.h"
#include "tree.h"
#include "memmodel.h"
#include "gimple.h"
#include "cfghooks.h"
#include "cfgloop.h"
#include "df.h"
#include "tm_p.h"
#include "stringpool.h"
#include "optabs.h"
#include "regs.h"
#include "emit-rtl.h"
#include "recog.h"
#include "attribs.h"
#include "diagnostic.h"
#include "insn-attr.h"
#include "alias.h"
#include "fold-const.h"
#include "stor-layout.h"
#include "calls.h"
#include "varasm.h"
#include "output.h"
#include "flags.h"
#include "explow.h"
#include "expr.h"
#include "reload.h"
#include "langhooks.h"
#include "opts.h"
#include "params.h"
#include "gimplify.h"
#include "dwarf2.h"
#include "gimple-iterator.h"
#include "tree-vectorizer.h"
#include "cfgrtl.h"

#include "dumpfile.h"
#include "builtins.h"
#include "tm-constrs.h"
#include "sched-int.h"
#include "target-globals.h"
#include "common/common-target.h"
#include "selftest.h"
#include "selftest-rtl.h"

#include "config.h"
#include "system.h"
#include "coretypes.h"
#include "tm.h"

#include "calls.h"
#include "function.h"
#include "cfgloop.h"
#include "cppdefault.h"
#include "cpplib.h"
#include "diagnostic.h"
#include "incpath.h"

#include "basic-block.h"
#include "bitmap.h"
#include "hard-reg-set.h"
#include "df.h"
#include "tree.h"
#include "rtl.h"
#include "expr.h"
#include "function.h"
#include "ggc.h"
#include "insn-attr.h"
#include "insn-codes.h"
#include "insn-modes.h"
#include "langhooks.h"
#include "libfuncs.h"
#include "output.h"
#include "hw-doloop.h"
#include "opts.h"
#include "params.h"
#include "emit-rtl.h"
//#include "recog.h"
#include "regs.h"

#include "sel-sched.h"
#include "toplev.h"
#include "stor-layout.h"
#include "varasm.h"

#include "tm_p.h"
#include "target.h"
#include "target-def.h"
#include "ira.h"
#include "ddg.h"

#include "kvx-protos.h"
#include "kvx-opts.h"

#include <stdlib.h>
#include <unistd.h>
#include <libgen.h>

#undef TARGET_HAVE_TLS
#define TARGET_HAVE_TLS (true)

static bool scheduling = false;

rtx kvx_link_reg_rtx;

rtx kvx_divmod_zero;

/* Which arch are we scheduling for */
enum attr_arch kvx_arch_schedule;

/* Information about a function's frame layout.  */
struct GTY (()) kvx_frame_info
{
  /* The total frame size, used for moving $sp in prologue */
  poly_int64 frame_size;

  /* Offsets of save area from frame bottom */
  poly_int64 saved_reg_sp_offset;

  /* Relative offsets within register save area  */
  HOST_WIDE_INT reg_rel_offset[FIRST_PSEUDO_REGISTER];
  /* Register save area size */
  HOST_WIDE_INT saved_regs_size;
  HARD_REG_SET saved_regs;

  /* Offset of virtual frame pointer from new stack pointer/frame bottom */
  poly_int64 virt_frame_pointer_offset;

  /* Offset of hard frame pointer from new stack pointer/frame bottom */
  poly_int64 hard_frame_pointer_offset;

  /* The offset of arg_pointer_rtx from the new stack pointer/frame bottom.  */
  poly_int64 arg_pointer_offset;

  /* Offset to the static chain pointer, if needed */
  poly_int64 static_chain_offset;

  /* Padding size between local area and incoming/varargs */
  HOST_WIDE_INT padding1;

  /* Padding between local area and register save */
  HOST_WIDE_INT padding2;

  /* Padding size between register save and outgoing args */
  HOST_WIDE_INT padding3;

  bool laid_out;
};

struct GTY (()) machine_function
{
  char save_reg[FIRST_PSEUDO_REGISTER];

  kvx_frame_info frame;

  /* If true, the current function has a STATIC_CHAIN.  */
  int static_chain_on_stack;

  rtx stack_check_block_label;
  rtx stack_check_block_seq, stack_check_block_last;
};

/*
				~               ~
				|  ..........   |
				|               |    ^
				|               |    |
				| Incomming     |    | Caller frame
				| Args          | <--/ <- incoming $sp [256-bits aligned]
				+---------------+
				| Varargs       |
				|               |
				|               |
				+---------------+
				|               |
				| padding1      |
				|               |
				+---------------+
 Argument Pointer / Virt. FP--->| [Static chain]| [256-bits aligned]
				+---------------+
				| Local         |
				| Variable      |
				|               |
				+---------------+
				|               |
				| padding2      |
				|               |
				+---------------+
				|               |
				| Register      |
				| Save          |
				|               |
				| $ra           | (if frame_pointer_needed)
				| caller FP     | (<- $fp if frame_pointer_needed) [64-bits aligned]
				+---------------+
				|               |
				| padding3      |
				|               |
				+---------------+
				|               |
				| Outgoing      |
				| Args          |
				|               | <- $sp [256-bits aligned]
				+---------------+

*/

enum spill_action
{
  SPILL_COMPUTE_SIZE,
  SPILL_SAVE,
  SPILL_RESTORE
};

static bool should_be_saved_in_prologue (int regno);


static void
kvx_compute_frame_info (void)
{
  struct kvx_frame_info *frame;

  poly_int64 inc_sp_offset = 0;

  if (reload_completed && cfun->machine->frame.laid_out)
    return;

  frame = &cfun->machine->frame;
  memset (frame, 0, sizeof (*frame));
  CLEAR_HARD_REG_SET (frame->saved_regs);

  inc_sp_offset += crtl->args.pretend_args_size;

  /* If any anonymous arg may be in register, push them on the stack */
  if (cfun->stdarg && crtl->args.info.next_arg_reg < KV3_ARG_REG_SLOTS)
    inc_sp_offset
      += UNITS_PER_WORD * (KV3_ARG_REG_SLOTS - crtl->args.info.next_arg_reg);

  /* FIXME AUTO: trampoline are broken T6775 */
  if (cfun->machine->static_chain_on_stack)
    inc_sp_offset += UNITS_PER_WORD;

  HOST_WIDE_INT local_vars_sz = get_frame_size ();
  frame->padding1 = 0;

  if (local_vars_sz > 0)
    {
      frame->padding1 = ROUND_UP (inc_sp_offset, STACK_BOUNDARY / BITS_PER_UNIT)
			- inc_sp_offset;
      inc_sp_offset = ROUND_UP (inc_sp_offset, STACK_BOUNDARY / BITS_PER_UNIT);

      /* Next are automatic variables. */
      inc_sp_offset += local_vars_sz;
    }
#define SLOT_NOT_REQUIRED (-2)
#define SLOT_REQUIRED (-1)

  frame->padding2 = ROUND_UP (inc_sp_offset, UNITS_PER_WORD) - inc_sp_offset;
  inc_sp_offset = ROUND_UP (inc_sp_offset, UNITS_PER_WORD);

  HOST_WIDE_INT reg_offset = 0;

  /* Mark which register should be saved... */
  for (int regno = 0; regno < FIRST_PSEUDO_REGISTER; regno++)
    if (should_be_saved_in_prologue (regno))
      {
	SET_HARD_REG_BIT (frame->saved_regs, regno);
	cfun->machine->frame.reg_rel_offset[regno] = SLOT_REQUIRED;
      }
    else
      cfun->machine->frame.reg_rel_offset[regno] = SLOT_NOT_REQUIRED;

  if (frame_pointer_needed)
    {
      SET_HARD_REG_BIT (frame->saved_regs, HARD_FRAME_POINTER_REGNUM);
      SET_HARD_REG_BIT (frame->saved_regs, KV3_RETURN_POINTER_REGNO);

      cfun->machine->frame.reg_rel_offset[HARD_FRAME_POINTER_REGNUM] = 0;
      cfun->machine->frame.reg_rel_offset[KV3_RETURN_POINTER_REGNO]
	= UNITS_PER_WORD;
      reg_offset = UNITS_PER_WORD * 2;
    }

  /* ... assign stack slots */
  for (int regno = 0; regno < FIRST_PSEUDO_REGISTER; regno++)
    if (cfun->machine->frame.reg_rel_offset[regno] == SLOT_REQUIRED)
      {
	cfun->machine->frame.reg_rel_offset[regno] = reg_offset;
	reg_offset += UNITS_PER_WORD;
      }

  frame->saved_regs_size = reg_offset;

  inc_sp_offset += reg_offset;

  /* At the bottom of the frame are any outgoing stack arguments. */
  inc_sp_offset += crtl->outgoing_args_size;
  frame->padding3
    = ROUND_UP (inc_sp_offset, STACK_BOUNDARY / BITS_PER_UNIT) - inc_sp_offset;

  inc_sp_offset = ROUND_UP (inc_sp_offset, STACK_BOUNDARY / BITS_PER_UNIT);

  frame->hard_frame_pointer_offset = frame->saved_reg_sp_offset
    = crtl->outgoing_args_size + frame->padding3;

  frame->static_chain_offset = frame->virt_frame_pointer_offset
    = frame->saved_reg_sp_offset + frame->saved_regs_size + frame->padding2
      + get_frame_size ();

  frame->arg_pointer_offset
    = frame->virt_frame_pointer_offset + frame->padding1
      + (cfun->machine->static_chain_on_stack ? UNITS_PER_WORD : 0);

  frame->frame_size = inc_sp_offset;
  frame->laid_out = true;
}

static void
kvx_debug_frame_info (struct kvx_frame_info *fi)
{
  if (!dump_file)
    return;
  fprintf (dump_file, "\nKVX Frame info:\n");

  fprintf (dump_file,
	   " |XXXXXXXXXXXXXXXXXXXXXXXXXXXXXX| %d/0 (caller frame) <- $sp "
	   "(incoming) %s \n",
	   fi->frame_size,
	   cfun->stdarg && crtl->args.info.next_arg_reg < KV3_ARG_REG_SLOTS
	     ? ""
	     : "and virt frame pointer");

#define DFI_SEP fprintf (dump_file, " +------------------------------+    \n")

#define DFI_FIELD(f, size, bottom, decorate_up, decorate_down)                   \
  fprintf (dump_file,                                                            \
	   " |                              | %d/%d %s  \n"                      \
	   " |%30s|                              \n"                             \
	   " |size: %24d| %d/%d  %s\n",                                          \
	   (bottom) + (size) -UNITS_PER_WORD,                                    \
	   fi->frame_size - ((bottom) + (size) -UNITS_PER_WORD), decorate_up, f, \
	   (size), (bottom), fi->frame_size - (bottom), decorate_down)

  DFI_SEP;
  if (cfun->stdarg && crtl->args.info.next_arg_reg < KV3_ARG_REG_SLOTS)
    {
      DFI_FIELD ("varargs", fi->frame_size - fi->arg_pointer_offset,
		 fi->arg_pointer_offset, "", " <- arg pointer");
      DFI_SEP;
    }

  if (fi->padding1 > 0)
    {
      DFI_FIELD (
	"padding1", fi->padding1,
	fi->virt_frame_pointer_offset
	  + (cfun->machine->static_chain_on_stack ? UNITS_PER_WORD : 0),
	"",
	cfun->machine->static_chain_on_stack ? "" : "<- virt frame pointer");
      DFI_SEP;
    }
  if (cfun->machine->static_chain_on_stack)
    {
      DFI_FIELD ("static chain", UNITS_PER_WORD, fi->virt_frame_pointer_offset,
		 "", "<- virt frame pointer");
      DFI_SEP;
    }

  if (get_frame_size () > 0)
    {
      DFI_FIELD ("locals", get_frame_size (),
		 fi->virt_frame_pointer_offset - get_frame_size (), "", "");
      DFI_SEP;
    }
  if (fi->padding2 > 0)
    {
      DFI_FIELD ("padding2", fi->padding2,
		 fi->hard_frame_pointer_offset + fi->saved_regs_size, "", "");
      DFI_SEP;
    }

  if (fi->saved_regs_size > 0)
    {
      unsigned regno;
      hard_reg_set_iterator rsi;
      /* 64 should be already oversized as there are 64 GPRS + possibly $fp and
       * $ra */
      unsigned stacked_regs[64] = {0};

      EXECUTE_IF_SET_IN_HARD_REG_SET (fi->saved_regs, 0, regno, rsi)
      stacked_regs[fi->reg_rel_offset[regno] / UNITS_PER_WORD] = regno;

      for (unsigned int i = (fi->saved_regs_size / UNITS_PER_WORD) - 1; i != 0;
	   i--)
	fprintf (dump_file, " |%30s| %d/-\n", reg_names[stacked_regs[i]],
		 fi->hard_frame_pointer_offset
		   + fi->reg_rel_offset[stacked_regs[i]]);

      fprintf (dump_file, " |%21s (%d)%4s| %d/- %s\n", "saved regs",
	       fi->saved_regs_size, reg_names[stacked_regs[0]],
	       fi->hard_frame_pointer_offset,
	       frame_pointer_needed ? "<- hard frame pointer ($fp)" : "");

      DFI_SEP;
    }
  if (fi->padding3 > 0)
    {
      if (crtl->outgoing_args_size > 0)
	{
	  DFI_FIELD ("padding3", fi->padding3,
		     crtl->outgoing_args_size + fi->padding3, "", "");
	  DFI_SEP;
	}
      else
	{
	  DFI_FIELD ("padding3", fi->padding3, 0, "", "<- $sp (callee)");
	  DFI_SEP;
	}
    }
  if (crtl->outgoing_args_size > 0)
    {
      DFI_FIELD ("outgoing", crtl->outgoing_args_size, 0, "",
		 "<- $sp (callee)");
      DFI_SEP;
    }

  fprintf (dump_file, "Saved regs: ");
  unsigned regno;
  hard_reg_set_iterator rsi;
  EXECUTE_IF_SET_IN_HARD_REG_SET (fi->saved_regs, 0, regno, rsi)
  fprintf (dump_file, " $%s [%d]", reg_names[regno], fi->reg_rel_offset[regno]);

  fprintf (dump_file, "\n");

  fprintf (dump_file, "KVX Frame info valid :%s\n",
	   fi->laid_out ? "yes" : "no");
}

static HOST_WIDE_INT
kvx_starting_frame_offset (void)
{
  return 0;
}

HOST_WIDE_INT
kvx_first_parm_offset (tree decl ATTRIBUTE_UNUSED)
{
  struct kvx_frame_info *frame;
  kvx_compute_frame_info ();
  frame = &cfun->machine->frame;

  return frame->arg_pointer_offset - frame->virt_frame_pointer_offset;
}

static rtx
kvx_static_chain (const_tree fndecl, bool incoming_p ATTRIBUTE_UNUSED)
{
  if (!DECL_STATIC_CHAIN (fndecl))
    return NULL;

  cfun->machine->static_chain_on_stack = 1;

  return gen_frame_mem (Pmode, frame_pointer_rtx);
}

static const char *pgr_reg_names[] = {KV3_PGR_REGISTER_NAMES};
static const char *qgr_reg_names[] = {KV3_QGR_REGISTER_NAMES};

/* Splits X as a base + offset. Returns true if split successful,
   false if not. BASE_OUT and OFFSET_OUT contain the corresponding
   split. If STRICT is false, base is not always a register.
 */
bool
kvx_split_mem (rtx x, rtx *base_out, rtx *offset_out, bool strict)
{
  if (GET_CODE (x) != PLUS && !REG_P (x))
    return false;

  if (strict
      && !((GET_CODE (x) == PLUS && CONST_INT_P (XEXP (x, 1))
	    && REG_P (XEXP (x, 0)))
	   || REG_P (x)))
    return false;

  if (GET_CODE (x) == PLUS && CONST_INT_P (XEXP (x, 1)))
    {
      *base_out = XEXP (x, 0);
      *offset_out = XEXP (x, 1);
      return true;
    }

  *base_out = x;
  *offset_out = const0_rtx;
  return true;
}

#define KVX_MAX_PACKED_LSU (4)
/* Used during peephole to merge consecutive loads/stores.
   Returns TRUE if the merge was successful, FALSE if not.
   NOPS is the number of load/store to consider in OPERANDS array.
 */

/* OPERANDS contains NOPS (set ...) (2 or 4) that must be all load or
   all store.  The sets are checked for correctness wrt packing.
   On success, the function emits the packed instruction and returns
   TRUE. If the packing could not be done, returns FALSE.
 */
bool
kvx_pack_load_store (rtx operands[], unsigned int nops)
{
  rtx set_dests[KVX_MAX_PACKED_LSU];
  rtx set_srcs[KVX_MAX_PACKED_LSU];
  rtx sorted_operands[2 * KVX_MAX_PACKED_LSU];

  /* Only:
     ld + ld => lq
     ld + ld + ld + ld => lo

     sd + sd => sq
     sd + sd + sd + sd => so
  */

  if (nops != 2 && nops != 4)
    return false;

  for (unsigned i = 0; i < nops; i++)
    {
      set_dests[i] = operands[2 * i];
      set_srcs[i] = operands[2 * i + 1];
      sorted_operands[2 * i] = sorted_operands[2 * i + 1] = NULL_RTX;
    }

  /* Only for register size accesses */
  for (unsigned i = 0; i < nops; i++)
    if (GET_MODE (set_dests[i]) != DImode)
      return false;

  bool is_load = false;
  bool is_store = false;
  for (unsigned i = 0; i < nops; i++)
    if (MEM_P (set_srcs[i]) && REG_P (set_dests[i]))
      is_load = true;
    else if (MEM_P (set_dests[i]) && REG_P (set_srcs[i]))
      is_store = true;

  if ((is_store && is_load) || !(is_load || is_store))
    return false;

  /* Used to pick correct operands in both cases (load and store) */
  int op_offset = is_load ? 0 : 1;

  unsigned int min_regno = REGNO (operands[op_offset]);

  /* Find first regno for destination (load)/source (store) */
  for (unsigned int i = 1; i < nops; i++)
    if (REGNO (operands[i * 2 + op_offset]) < min_regno)
      min_regno = REGNO (operands[i * 2 + op_offset]);

  /* Sort operands based on regno */
  for (unsigned int i = 0; i < nops; i++)
    {
      const unsigned int regno = REGNO (operands[i * 2 + op_offset]);
      const unsigned int idx = 2 * (regno - min_regno);

      /* Registers are not consecutive */
      if (idx >= (2 * nops))
	return false;

      /* Register used twice in operands */
      if (sorted_operands[idx] != NULL_RTX)
	return false;

      sorted_operands[idx] = operands[2 * i];
      sorted_operands[idx + 1] = operands[2 * i + 1];
    }

  /* Check mem addresses are consecutive */
  rtx base_reg, base_offset;
  if (!kvx_split_mem (XEXP (sorted_operands[1 - op_offset], 0), &base_reg,
		      &base_offset, true))
    return false;

  const unsigned int base_regno = REGNO (base_reg);

  /* Base register is modified by one load */
  if (is_load && base_regno >= REGNO (sorted_operands[op_offset])
      && base_regno <= REGNO (sorted_operands[(nops - 1) * 2 + op_offset]))
    {
      bool mod_before_last = false;
      /* Check the base register is modified in the last load */
      for (unsigned int i = 0; i < (nops - 1); i++)
	{
	  if (REGNO (operands[2 * i + op_offset]) == base_regno)
	    {
	      mod_before_last = true;
	      break;
	    }
	}
      if (mod_before_last)
	return false;
    }

  unsigned int next_offset = INTVAL (base_offset) + UNITS_PER_WORD;
  for (unsigned int i = 1; i < nops; i++)
    {
      rtx elem = XEXP (sorted_operands[2 * i + 1 - op_offset], 0);

      /* Not addressing next memory word */
      const bool is_plus_bad_offset
	= GET_CODE (elem) == PLUS
	  && (!REG_P (XEXP (elem, 0)) || REGNO (XEXP (elem, 0)) != base_regno
	      || !CONST_INT_P (XEXP (elem, 1))
	      || INTVAL (XEXP (elem, 1)) != next_offset);

      const bool is_reg_bad
	= REG_P (elem) && (REGNO (elem) != base_regno || next_offset != 0);

      if (is_reg_bad || is_plus_bad_offset)
	return false;

      next_offset += UNITS_PER_WORD;
    }

  rtx multi_insn;
  if (is_load)
    multi_insn = gen_load_multiple (sorted_operands[0], sorted_operands[1],
				    GEN_INT (nops));
  else
    multi_insn = gen_store_multiple (sorted_operands[0], sorted_operands[1],
				     GEN_INT (nops));
  if (multi_insn == NULL_RTX)
    return false;

  emit_insn (multi_insn);
  return true;
}

/* Implement HARD_REGNO_RENAME_OK.  */
int
kvx_hard_regno_rename_ok (unsigned int from, unsigned int to)
{
  if (IN_RANGE (from, KV3_GPR_FIRST_REGNO, KV3_GPR_LAST_REGNO)
      && IN_RANGE (to, KV3_GPR_FIRST_REGNO, KV3_GPR_LAST_REGNO))
    {
      /* Retain quad alignement */
      if ((from % 4) == 0)
	return ((to % 4) == 0);

      /* Retain pair alignement */
      if ((from % 2) == 0)
	return ((to % 2) == 0);
    }

  return 1;
}

static unsigned int
kvx_hard_regno_nregs (unsigned int regno, machine_mode mode)
{
  return (GET_MODE_SIZE (mode) + UNITS_PER_WORD - 1) / UNITS_PER_WORD;
}

/* Implement HARD_REGNO_MODE_OK.  */
static bool
kvx_hard_regno_mode_ok (unsigned regno, enum machine_mode mode)
{
  // SI/DI -> KV3_GPR_FIRST_REGNO - KV3_GPR_LAST_REGNO => OK
  // SI/DI -> KV3_SRF_FIRST_REGNO - KV3_SRF_LAST_REGNO => OK
  // TI    -> KV3_GPR_FIRST_REGNO - KV3_GPR_LAST_REGNO && even => OK
  // OI    -> KV3_GPR_FIRST_REGNO - KV3_GPR_LAST_REGNO && 0mod4 => OK
  if (GET_MODE_SIZE (mode) <= UNITS_PER_WORD)
    return 1;
  if (IN_RANGE (regno, KV3_GPR_FIRST_REGNO, KV3_GPR_LAST_REGNO))
    {
      if (GET_MODE_SIZE (mode) == 2 * UNITS_PER_WORD)
	return (regno % 2 == 0);
      if (GET_MODE_SIZE (mode) == 4 * UNITS_PER_WORD)
	return (regno % 4 == 0);
    }
  return 0;
}

static unsigned char
kvx_class_max_nregs (reg_class_t regclass ATTRIBUTE_UNUSED,
		     enum machine_mode mode)
{
  return kvx_hard_regno_nregs (0, mode);
}

static tree kvx_handle_fndecl_attribute (tree *node, tree name,
					 tree args ATTRIBUTE_UNUSED,
					 int flags ATTRIBUTE_UNUSED,
					 bool *no_add_attrs);

static bool function_symbol_referenced_p (rtx x);

static bool symbolic_reference_mentioned_p (rtx op);

static bool kvx_output_addr_const_extra (FILE *, rtx);

static bool kvx_legitimate_address_p (enum machine_mode mode, rtx x,
				      bool strict);

bool kvx_legitimate_pic_symbolic_ref_p (rtx op);

static bool kvx_legitimate_constant_p (enum machine_mode mode ATTRIBUTE_UNUSED,
				       rtx x);

/* Table of machine attributes.  */
static const struct attribute_spec kvx_attribute_table[] = {
  /* { name, min_len, max_len, decl_req, type_req, fn_type_req, handler,
     affects_type } */
  {"no_save_regs", 0, 0, true, false, false, false, kvx_handle_fndecl_attribute,
   NULL},
  {"farcall", 0, 0, true, false, false, false, kvx_handle_fndecl_attribute, NULL},
  {NULL, 0, 0, false, false, false, false, NULL, NULL}};

/* Returns 0 if there is no TLS ref, != 0 if there is.

  Beware that UNSPEC_TLS are not symbol ref, they are offset within
  TLS.
 */
int
kvx_has_tls_reference (rtx x)
{
  if (!TARGET_HAVE_TLS)
    return false;

  subrtx_iterator::array_type array;
  FOR_EACH_SUBRTX (iter, array, x, ALL)
    {
      const_rtx x = *iter;
      if (GET_CODE (x) == SYMBOL_REF && SYMBOL_REF_TLS_MODEL (x) != 0)
	return true;
      /* Don't recurse into UNSPEC_TLS looking for TLS symbols; these are
	 TLS offsets, not real symbol references.  */
      if (GET_CODE (x) == UNSPEC
	  && (XINT (x, 1) == UNSPEC_TLS_GD || XINT (x, 1) == UNSPEC_TLS_LD
	      || XINT (x, 1) == UNSPEC_TLS_DTPOFF
	      || XINT (x, 1) == UNSPEC_TLS_LE || XINT (x, 1) == UNSPEC_TLS_IE))
	iter.skip_subrtxes ();
    }
  return false;
}

static int
kvx_has_unspec_reference_1 (rtx *x)
{
  return (GET_CODE (*x) == UNSPEC
	  && (XINT (*x, 1) == UNSPEC_GOT || XINT (*x, 1) == UNSPEC_GOTOFF
	      || XINT (*x, 1) == UNSPEC_PCREL || XINT (*x, 1) == UNSPEC_TLS_GD
	      || XINT (*x, 1) == UNSPEC_TLS_LD || XINT (*x, 1) == UNSPEC_TLS_LE
	      || XINT (*x, 1) == UNSPEC_TLS_IE));
}

static int
kvx_has_unspec_reference (rtx x)
{
  subrtx_ptr_iterator::array_type array;
  FOR_EACH_SUBRTX_PTR (iter, array, &x, ALL)
    {
      rtx *x = *iter;
      switch (kvx_has_unspec_reference_1 (x))
	{
	case -1:
	  iter.skip_subrtxes ();
	  break;
	case 0:
	  break;
	default:
	  return 1;
	}
    }
  return 0;
  //   return for_each_rtx (&x, &kvx_has_unspec_reference_1, NULL);
}

static bool
kvx_legitimate_address_register_p (rtx reg, bool strict)
{
  return (REG_P (reg) && IS_GENERAL_REGNO (REGNO (reg), strict)
	  && GET_MODE (reg) == Pmode);
}

static bool
kvx_legitimate_address_offset_register_p (rtx reg, bool strict)
{
  machine_mode mode = GET_MODE (reg);

  if (GET_CODE (reg) == SUBREG)
    reg = SUBREG_REG (reg);

  return (REG_P (reg) && IS_GENERAL_REGNO (REGNO (reg), strict)
	  && mode == Pmode);
}

/**
 * Legitimate address :
 * - (reg)
 * - (plus (reg) (constant))
 * - (plus (reg) (reg))
 * - (plus (mult (reg) (constant)) (reg))
 */
static bool
kvx_legitimate_address_p (machine_mode mode, rtx x, bool strict)
{
  /*
   * ld reg = 0[reg]
   */
  if (kvx_legitimate_address_register_p (x, strict))
    return true;

  /*
   * ld reg = @got[reg]
   * ld reg = @gotoff[reg]
   */
  if (GET_CODE (x) == PLUS
      && kvx_legitimate_address_register_p (XEXP (x, 0), strict)
      && (GET_CODE (XEXP (x, 1)) == UNSPEC
	  && (XINT (XEXP (x, 1), 1) == UNSPEC_GOT
	      || XINT (XEXP (x, 1), 1) == UNSPEC_GOTOFF)))
    return true;

  /*
   * ld reg = const[reg]
   * ld reg = symbol[reg]
   * ld reg = @pcrel(symbol)[reg]
   */
  if (GET_CODE (x) == PLUS
      && kvx_legitimate_address_register_p (XEXP (x, 0), strict)
      && ((CONSTANT_P (XEXP (x, 1))
	   && kvx_legitimate_constant_p (VOIDmode, XEXP (x, 1)))
	  || GET_CODE (XEXP (x, 1)) == CONST_INT)
      && immediate_operand (XEXP (x, 1), DImode)
      && (!current_pass || current_pass->tv_id != TV_CPROP))
    return true;

  /*
   * ld reg = reg[reg]
   */
  if (GET_CODE (x) == PLUS
      && kvx_legitimate_address_register_p (XEXP (x, 0), strict)
      && kvx_legitimate_address_offset_register_p (XEXP (x, 1), strict))
    return true;

  /*
   * ld.xs reg = reg[reg]
   */
  if (GET_CODE (x) == PLUS
      && kvx_legitimate_address_register_p (XEXP (x, 1), strict)
      && GET_CODE (XEXP (x, 0)) == MULT
      && GET_CODE (XEXP (XEXP (x, 0), 1)) == CONST_INT
      && INTVAL (XEXP (XEXP (x, 0), 1)) == GET_MODE_SIZE (mode)
      && kvx_legitimate_address_offset_register_p (XEXP (XEXP (x, 0), 0),
						   strict))
    // The .xs addressing mode applies to object sizes 2, 4, 8, 16, 32.
    return GET_MODE_SIZE (mode) > 1 && GET_MODE_SIZE (mode) <= 32;

  return false;
}

static void
kvx_conditional_register_usage (void)
{
  kvx_link_reg_rtx = gen_rtx_REG (Pmode, KV3_RETURN_POINTER_REGNO);
}

rtx
kvx_return_addr_rtx (int count, rtx frameaddr ATTRIBUTE_UNUSED)
{
  return count == 0 ? get_hard_reg_initial_val (Pmode, KV3_RETURN_POINTER_REGNO)
		    : NULL_RTX;
}

/* Implements the macro INIT_CUMULATIVE_ARGS defined in kvx.h. */

void
kvx_init_cumulative_args (CUMULATIVE_ARGS *cum,
			  const_tree fntype ATTRIBUTE_UNUSED,
			  rtx libname ATTRIBUTE_UNUSED,
			  tree fndecl ATTRIBUTE_UNUSED,
			  int n_named_args ATTRIBUTE_UNUSED)
{
  cum->next_arg_reg = 0;
  cum->anonymous_arg_offset = 0;
  cum->anonymous_arg_offset_valid = false;
}

/* Information about a single argument.  */
struct kvx_arg_info
{
  /* first register to be used for this arg */
  unsigned int first_reg;

  /* number of registers used */
  int num_regs;

  /* number of words pushed on the stack (in excess of registers) */
  int num_stack;
};

/* Analyzes a single argument and fills INFO struct. Does not modify
   CUM_V. Returns a reg rtx pointing at first argument register to be
   used for given argument or NULL_RTX if argument must be stacked
   because there is no argument slot in registers free/correctly
   aligned. */

static rtx
kvx_get_arg_info (struct kvx_arg_info *info, cumulative_args_t cum_v,
		  machine_mode mode, const_tree type,
		  bool named ATTRIBUTE_UNUSED)
{
  CUMULATIVE_ARGS *cum = get_cumulative_args (cum_v);
  HOST_WIDE_INT n_bytes
    = type ? int_size_in_bytes (type) : GET_MODE_SIZE (mode);
  HOST_WIDE_INT n_words = (n_bytes + UNITS_PER_WORD - 1) / UNITS_PER_WORD;

  info->first_reg = cum->next_arg_reg;

  /* If all register argument slots are used, then it must go on the
     stack. */
  if (cum->next_arg_reg >= KV3_ARG_REG_SLOTS)
    {
      info->num_stack = n_words;
      info->num_regs = 0;
      return NULL_RTX;
    }

  info->num_regs = KV3_ARG_REG_SLOTS - info->first_reg;

  if (info->num_regs >= n_words)
    {
      /* All arg fits in remaining registers */
      info->num_regs = n_words;
      info->num_stack = 0;
    }
  else
    {
      /* At least one word on stack */
      info->num_stack = n_words - info->num_regs;
    }

  return gen_rtx_REG (mode, KV3_ARGUMENT_POINTER_REGNO + info->first_reg);
}

/* Implements TARGET_PROMOTE_FUNCTION_MODE.  */
static machine_mode
kvx_promote_function_mode (const_tree type ATTRIBUTE_UNUSED, machine_mode mode,
			   int *punsignedp, const_tree, int for_return)
{
  if (for_return)
    if (GET_MODE_CLASS (mode) == MODE_INT
	&& GET_MODE_SIZE (mode) < UNITS_PER_WORD)
      {
	mode = word_mode;
	*punsignedp = 1;
      }

  return mode;
}

/* Implements TARGET_FUNCTION_ARG.
   Returns a reg rtx pointing at first argument register to be
   used for given argument or NULL_RTX if argument must be stacked
   because there is no argument slot in registers free. */

static rtx
kvx_function_arg (cumulative_args_t cum_v, machine_mode mode,
		  const_tree type, bool named)
{
  struct kvx_arg_info info;
  return kvx_get_arg_info (&info, cum_v, mode, type, named);
}

/* Implements TARGET_ARG_PARTIAL_BYTES.
   Return the number of bytes, at the beginning of an argument,
   that must be put in registers */

static int
kvx_arg_partial_bytes (cumulative_args_t cum_v, machine_mode mode,
		       tree type, bool named ATTRIBUTE_UNUSED)
{
  struct kvx_arg_info info = {0};
  rtx reg = kvx_get_arg_info (&info, cum_v, mode, type, named);
  if (reg != NULL_RTX && info.num_regs > 0 && info.num_stack > 0)
    {
      return info.num_regs * UNITS_PER_WORD;
    }
  return 0;
}

static void
kvx_function_arg_advance (cumulative_args_t cum_v, enum machine_mode mode,
			  const_tree type, bool named)
{
  CUMULATIVE_ARGS *cum = get_cumulative_args (cum_v);
  struct kvx_arg_info info = {0};
  kvx_get_arg_info (&info, cum_v, mode, type, named);

  if (info.num_regs > 0)
    {
      cum->next_arg_reg = info.first_reg + info.num_regs;
    }
  else if (named)
    {
      cum->anonymous_arg_offset += info.num_stack * UNITS_PER_WORD;
    }
  else if (!cum->anonymous_arg_offset_valid)
    {
      /* First !named arg is in fact the last named arg */
      cum->anonymous_arg_offset += info.num_stack * UNITS_PER_WORD;
      cum->anonymous_arg_offset_valid = true;
    }
}

/* Implements TARGET_FUNCTION_VALUE.  */
static rtx
kvx_function_value (const_tree ret_type, const_tree func, bool outgoing)
{
  int unsignedp = TYPE_UNSIGNED (ret_type);
  enum machine_mode mode = TYPE_MODE (ret_type);
  HOST_WIDE_INT size = int_size_in_bytes (ret_type);

  mode = promote_function_mode (ret_type, mode, &unsignedp, func, 1);

  if (mode == BLKmode && (size * BITS_PER_UNIT > LONG_LONG_TYPE_SIZE))
    {
      int nexps = (size + UNITS_PER_WORD - 1) / UNITS_PER_WORD;
      rtx ret = gen_rtx_PARALLEL (BLKmode, rtvec_alloc (nexps));

      for (int i = 0; i < nexps; i++)
	XVECEXP (ret, 0, i)
	  = gen_rtx_EXPR_LIST (VOIDmode,
			       gen_rtx_REG (DImode,
					    KV3_ARGUMENT_POINTER_REGNO + i),
			       GEN_INT (i * UNITS_PER_WORD));
      return ret;
    }

  return gen_rtx_REG (mode, KV3_ARGUMENT_POINTER_REGNO);
}

/* Implements TARGET_RETURN_IN_MSB.  */
static bool
kvx_return_in_msb (const_tree type ATTRIBUTE_UNUSED)
{
  return false;
}

/* Implements TARGET_RETURN_IN_MEMORY.  */
static bool
kvx_return_in_memory (const_tree type, const_tree fntype ATTRIBUTE_UNUSED)
{
  HOST_WIDE_INT size = int_size_in_bytes (type);

  /* Return value can use up to 4 registers (256bits). Larger values
   * or variable sized type must be returned in memory. */
  return (size > (4 * UNITS_PER_WORD) || size < 0);
}

/* Implements TARGET_STRUCT_VALUE_RTX.  */
static rtx
kvx_struct_value_rtx (tree fndecl ATTRIBUTE_UNUSED,
		      int incoming ATTRIBUTE_UNUSED)
{
  return gen_rtx_REG (Pmode, KV3_STRUCT_POINTER_REGNO);
}

static void
kvx_asm_output_mi_thunk (FILE *file ATTRIBUTE_UNUSED,
			 tree thunk_fndecl ATTRIBUTE_UNUSED,
			 HOST_WIDE_INT delta ATTRIBUTE_UNUSED,
			 HOST_WIDE_INT vcall_offset ATTRIBUTE_UNUSED,
			 tree function ATTRIBUTE_UNUSED)
{
  rtx xops[1];
  if (!TARGET_32)
    {
      if (delta)
	/* FIXME AUTO: this is fixed for build, not checked for correctness ! */
	fprintf (file, "\taddd $r0 = $r0, %i\n", (int) delta);

      if (vcall_offset)
	{
	  /* FIXME AUTO: this is fixed for build, not checked for correctness !
	   */
	  fprintf (file, "\tld $r32 = %i[$r0]\n\t;;\n", (int) delta);
	  fprintf (file, "\tld $r32 = %i[$r32]\n\t;;\n", (int) vcall_offset);
	  fprintf (file, "\taddd $r0 = $r0, $r32\n");
	}
    }
  else
    {
      if (delta)
	fprintf (file, "\taddw $r0 = $r0, %i\n", (int) delta);

      if (vcall_offset)
	{
	  fprintf (file, "\tlwz $r32 = %i[$r0]\n\t;;\n", (int) delta);
	  fprintf (file, "\tlwz $r32 = %i[$r32]\n\t;;\n", (int) vcall_offset);
	  fprintf (file, "\taddw $r0 = $r0, $r32\n");
	}
    }
  xops[0] = XEXP (DECL_RTL (function), 0);
  output_asm_insn ("goto\t%0\n\t;;", xops);
}

static bool
kvx_asm_can_output_mi_thunk (const_tree thunk_fndecl ATTRIBUTE_UNUSED,
			     HOST_WIDE_INT delta ATTRIBUTE_UNUSED,
			     HOST_WIDE_INT vcall_offset ATTRIBUTE_UNUSED,
			     const_tree function ATTRIBUTE_UNUSED)
{
  return true;
}

static rtx
kvx_expand_builtin_saveregs (void)
{
  int regno;
  int slot = 0;
  struct kvx_frame_info *frame;

  kvx_compute_frame_info ();
  frame = &cfun->machine->frame;
  HOST_WIDE_INT arg_fp_offset
    = frame->arg_pointer_offset - frame->virt_frame_pointer_offset;
  rtx area = gen_rtx_PLUS (Pmode, frame_pointer_rtx, GEN_INT (arg_fp_offset));

  /* All argument register slots used for named args, nothing to push */
  if (crtl->args.info.next_arg_reg >= KV3_ARG_REG_SLOTS)
    return const0_rtx;

  /* use arg_pointer since saved register slots are not known at that time */
  regno = crtl->args.info.next_arg_reg;

  if (regno & 1)
    {
      rtx insn = emit_move_insn (gen_rtx_MEM (DImode, area),
				 gen_rtx_REG (DImode, KV3_ARGUMENT_POINTER_REGNO
							+ regno));
      RTX_FRAME_RELATED_P (insn) = 1;
      /* Do not attach a NOTE here as the frame has not been laid out yet.
       Let the kvx_fix_debug_for_bundles function during reorg pass handle these
     */

      regno++;
      slot++;
    }

  for (; regno < KV3_ARG_REG_SLOTS; regno += 2, slot += 2)
    {
      rtx addr
	= gen_rtx_MEM (TImode, gen_rtx_PLUS (Pmode, frame_pointer_rtx,
					     GEN_INT (slot * UNITS_PER_WORD
						      + arg_fp_offset)));
      rtx src = gen_rtx_REG (TImode, KV3_ARGUMENT_POINTER_REGNO + regno);

      rtx insn = emit_move_insn (addr, src);
      RTX_FRAME_RELATED_P (insn) = 1;
      /* Do not attach a NOTE here as the frame has not been laid out yet.
       Let the kvx_fix_debug_for_bundles function during reorg pass handle these
     */
    }

  return area;
}

static void
kvx_expand_va_start (tree valist, rtx nextarg ATTRIBUTE_UNUSED)
{
  rtx va_start_addr = expand_builtin_saveregs ();
  rtx va_r = expand_expr (valist, NULL_RTX, VOIDmode, EXPAND_WRITE);

  struct kvx_frame_info *frame;

  frame = &cfun->machine->frame;
  HOST_WIDE_INT arg_fp_offset
    = frame->arg_pointer_offset - frame->virt_frame_pointer_offset;

  gcc_assert (frame->laid_out);

  /* All arg registers must be used by named parameter, va_start
     must point to caller frame for first anonymous parameter ... */
  if (va_start_addr == const0_rtx && crtl->args.info.anonymous_arg_offset_valid)
    {
      /* ... and there are some more arguments. */
      va_start_addr
	= gen_rtx_PLUS (Pmode, frame_pointer_rtx,
			GEN_INT (crtl->args.info.anonymous_arg_offset
				 + arg_fp_offset));
    }
  else
    {
      /* ... and there are no more argument. */
      va_start_addr
	= gen_rtx_PLUS (Pmode, frame_pointer_rtx, GEN_INT (arg_fp_offset));
    }

  emit_move_insn (va_r, va_start_addr);
}

static bool
kvx_cannot_force_const_mem (enum machine_mode mode ATTRIBUTE_UNUSED,
			    rtx x ATTRIBUTE_UNUSED)
{
  return true;
}

static bool
kvx_fixed_point_supported_p (void)
{
  return false;
}

static bool
kvx_scalar_mode_supported_p (scalar_mode mode)
{
  if (mode == HFmode)
    return true;

  int precision = GET_MODE_PRECISION (mode);

  switch (GET_MODE_CLASS (mode))
    {
    case MODE_PARTIAL_INT:
    case MODE_INT:
      if (precision == SHORT_TYPE_SIZE)
	return true;
      break;

    default:
      break;
    }

  return default_scalar_mode_supported_p (mode);
}

static bool
kvx_libgcc_floating_mode_supported_p (scalar_float_mode mode)
{
  return (mode == HFmode
	  ? true
	  : default_libgcc_floating_mode_supported_p (mode));
}

static const char *
kvx_mangle_type (const_tree type)
{
  /* Half-precision float.  */
  if (TREE_CODE (type) == REAL_TYPE && TYPE_PRECISION (type) == 16)
    return "Dh";

  return NULL;
}

static enum flt_eval_method
kvx_excess_precision (enum excess_precision_type type)
{
  switch (type)
    {
    case EXCESS_PRECISION_TYPE_FAST:
    case EXCESS_PRECISION_TYPE_STANDARD:
    case EXCESS_PRECISION_TYPE_IMPLICIT:
      return FLT_EVAL_METHOD_PROMOTE_TO_FLOAT16;
    default:
      gcc_unreachable ();
    }
  return FLT_EVAL_METHOD_UNPREDICTABLE;
}

static bool
kvx_vector_mode_supported_p (enum machine_mode mode)
{
  switch (mode)
    {
    // 64-bit modes
    case E_V8QImode:
    case E_V4HImode:
    case E_V2SImode:
    case E_V4HFmode:
    case E_V2SFmode:
    // 128-bit modes
    case E_V16QImode:
    case E_V8HImode:
    case E_V4SImode:
    case E_V2DImode:
    case E_V8HFmode:
    case E_V4SFmode:
    case E_V2DFmode:
    // 256-bit modes
    case E_V32QImode:
    case E_V16HImode:
    case E_V8SImode:
    case E_V4DImode:
    case E_V16HFmode:
    case E_V8SFmode:
    case E_V4DFmode:
      return true;
    default:
      break;
    }
  return false;
}

static bool
kvx_support_vector_misalignment (enum machine_mode mode ATTRIBUTE_UNUSED,
				 const_tree type ATTRIBUTE_UNUSED,
				 int misalignment ATTRIBUTE_UNUSED,
				 bool is_packed ATTRIBUTE_UNUSED)
{
  return !TARGET_STRICT_ALIGN;
}

static machine_mode
kvx_vectorize_preferred_simd_mode (scalar_mode mode)
{
  switch (mode)
    {
    case E_HImode:
      return V8HImode;
    case E_SImode:
      return V4SImode;
    case E_DImode:
      return V2DImode;
    case E_HFmode:
      return V8HFmode;
    case E_SFmode:
      return V4SFmode;
    case E_DFmode:
      return V2DFmode;
    default:
      break;
    }
  return word_mode;
}

static bool
kvx_pass_by_reference (cumulative_args_t cum ATTRIBUTE_UNUSED,
		       enum machine_mode mode, const_tree type,
		       bool named ATTRIBUTE_UNUSED)
{
  HOST_WIDE_INT size;

  /* GET_MODE_SIZE (BLKmode) is useless since it is 0.  */
  size = (mode == BLKmode && type) ? int_size_in_bytes (type)
				   : (int) GET_MODE_SIZE (mode);

  /* Aggregates are passed by reference based on their size.  */
  if (type && AGGREGATE_TYPE_P (type))
    size = int_size_in_bytes (type);

  /* Variable sized arguments are always returned by reference.  */
  if (size < 0)
    return true;

  /* Arguments which are variable sized or larger than 4 registers are
     passed by reference */
  return (size > (4 * UNITS_PER_WORD)) && mode == BLKmode;
}

static reg_class_t
kvx_secondary_reload (bool in_p ATTRIBUTE_UNUSED, rtx x ATTRIBUTE_UNUSED,
		      reg_class_t reload_class ATTRIBUTE_UNUSED,
		      enum machine_mode reload_mode ATTRIBUTE_UNUSED,
		      secondary_reload_info *sri ATTRIBUTE_UNUSED)
{
  if (!flag_pic)
    return NO_REGS;

  if (in_p && GET_CODE (x) == SYMBOL_REF && SYMBOL_REF_LOCAL_P (x)
      && !SYMBOL_REF_EXTERNAL_P (x))
    {
      if (sri->prev_sri == NULL)
	{
	  return GPR_REGS;
	}
      else
	{
	  sri->icode = GET_MODE (x) == SImode ? CODE_FOR_reload_in_gotoff_si
					      : CODE_FOR_reload_in_gotoff_di;
	  return NO_REGS;
	}
    }
  else if (SYMBOLIC_CONST (x) && !kvx_legitimate_constant_p (VOIDmode, x))
    {
      gcc_unreachable ();
    }
  return NO_REGS;
}

static const char *kvx_unspec_tls_asm_op[]
  = {"@tlsgd", "@tlsld", "@tlsle", "@dtpoff", "@tlsie"};

/* Helper function to produce manifest _Float16 constants, where the float
 * value represented as integer comes from REAL_VALUE_TO_TARGET_SINGLE.
 * Adapted from http://openkb.fr/Half-precision_floating-point_in_Java */
static unsigned
kvx_float_to_half_as_int (unsigned fbits)
{
  unsigned sign = fbits >> 16 & 0x8000;		// sign only
  unsigned val = (fbits & 0x7fffffff) + 0x1000; // rounded value
  if (val >= 0x47800000)			// might be or become NaN/Inf
    {						// avoid Inf due to rounding
      if ((fbits & 0x7fffffff) >= 0x47800000)
	{				     // is or must become NaN/Inf
	  if (val < 0x7f800000)		     // was value but too large
	    return sign | 0x7c00;	     // make it +/-Inf
	  return sign | 0x7c00 |	     // remains +/-Inf or NaN
		 (fbits & 0x007fffff) >> 13; // keep NaN (and Inf) bits
	}
      return sign | 0x7bff; // unrounded not quite Inf
    }
  if (val >= 0x38800000)		  // remains normalized value
    return sign | val - 0x38000000 >> 13; // exp - 127 + 15
  if (val < 0x33000000)			  // too small for subnormal
    return sign;			  // becomes +/-0
  val = (fbits & 0x7fffffff) >> 23;	  // tmp exp for subnormal calc
  return sign
	 | ((fbits & 0x7fffff | 0x800000) // add subnormal bit
	      + (0x800000 >> val - 102)	  // round depending on cut off
	    >> 126 - val); // div by 2^(1-(exp-127+15)) and >> 13 | exp=0
}

void
kvx_print_operand (FILE *file, rtx x, int code)
{
  rtx operand = x;
  bool select_qreg = 0;
  bool select_preg = 0;
  bool select_treg = 0;
  bool select_zreg = 0;
  bool select_yreg = 0;
  bool select_xreg = 0;
  bool addressing_mode = false;
  bool as_address = false;
  bool is_float = false;
  bool must_be_reversed = false;
  int addr_space = 0;

  switch (code)
    {
    case 0:
      /* No code, print as usual.  */
      break;

    case 'a':
      as_address = true;
      break;

    case 'o':
      select_qreg = true;
      break;

    case 'q':
      select_preg = true;
      break;

    case 't':
      select_treg = true;
      break;

    case 'z':
      select_zreg = true;
      break;

    case 'y':
      select_yreg = true;
      break;

    case 'x':
      select_xreg = true;
      break;

    case 'f':
      is_float = true;
      break;

    case 'R':
      must_be_reversed = true;
      break;

    case 'T':
      fprintf (file, "@pcrel(");
      output_addr_const (file, operand);
      fprintf (file, ")");
      return;

    case 'm':
      addressing_mode = true;
      break;

    case 'C': /* Print an additional '.u' or '.us' in the case of uncached load
	       */
      addr_space = kvx_is_uncached_mem_op_p (x);
      if (addr_space == KVX_ADDR_SPACE_BYPASS)
	fprintf (file, ".u");
      if (addr_space == KVX_ADDR_SPACE_PRELOAD)
	fprintf (file, ".us");
      return;

    default:
      output_operand_lossage ("invalid operand code '%c'", code);
    }

  if ((as_address || addressing_mode) && GET_CODE (x) != MEM)
    {
      x = gen_rtx_MEM (Pmode, x);
      operand = x;
    }

  if (COMPARISON_P (x))
    {
      if (!is_float)
	{
	  if (must_be_reversed)
	    fprintf (file, "%s",
		     GET_RTX_NAME (reverse_condition (GET_CODE (x))));
	  else
	    fprintf (file, "%s", GET_RTX_NAME (GET_CODE (x)));
	}
      else
	{
	  const char *name;
	  switch (GET_CODE (x))
	    {
	    case NE:
	      name = "une";
	      break;
	    case EQ:
	      name = "oeq";
	      break;
	    case GE:
	      name = "oge";
	      break;
	    case LT:
	      name = "olt";
	      break;
	    case UNEQ:
	      name = "ueq";
	      break;
	    case UNGE:
	      name = "uge";
	      break;
	    case UNLT:
	      name = "ult";
	      break;
	    case LTGT:
	      name = "one";
	      break;
	    default:
	      gcc_unreachable ();
	    }
	  fprintf (file, "%s", name);
	}
      return;
    }

  switch (GET_CODE (operand))
    {
    case REG:
      if (REGNO (operand) >= FIRST_PSEUDO_REGISTER)
	error ("internal error: bad register: %d", REGNO (operand));
      if (system_register_operand (operand, VOIDmode))
	gcc_assert (GET_MODE_SIZE (GET_MODE (x)) <= UNITS_PER_WORD);
      if (select_qreg)
	{
	  fprintf (file, "$%s", qgr_reg_names[REGNO (operand)]);
	}
      else if (select_preg)
	{
	  fprintf (file, "$%s", pgr_reg_names[REGNO (operand)]);
	}
      else if (select_treg)
	{
	  if (GET_MODE_SIZE (GET_MODE (x)) < UNITS_PER_WORD * 4)
	    error ("using %%t format with operand smaller than 4 registers");
	  fprintf (file, "$%s", reg_names[REGNO (operand) + 3]);
	}
      else if (select_zreg)
	{
	  if (GET_MODE_SIZE (GET_MODE (x)) < UNITS_PER_WORD * 4)
	    error ("using %%z format with operand smaller than 4 registers");
	  fprintf (file, "$%s", reg_names[REGNO (operand) + 2]);
	}
      else if (select_yreg)
	{
	  if (GET_MODE_SIZE (GET_MODE (x)) < UNITS_PER_WORD * 2)
	    error ("using %%y format with operand smaller than 2 registers");
	  fprintf (file, "$%s", reg_names[REGNO (operand) + 1]);
	}
      else if (select_xreg)
	{
	  if (GET_MODE_SIZE (GET_MODE (x)) < UNITS_PER_WORD * 2)
	    error ("using %%x format with operand smaller than 2 registers");
	  fprintf (file, "$%s", reg_names[REGNO (operand)]);
	}
      else if (GET_MODE_SIZE (GET_MODE (x)) == UNITS_PER_WORD * 4)
	{
	  fprintf (file, "$%s", qgr_reg_names[REGNO (operand)]);
	}
      else if (GET_MODE_SIZE (GET_MODE (x)) == UNITS_PER_WORD * 2)
	{
	  fprintf (file, "$%s", pgr_reg_names[REGNO (operand)]);
	}
      else
	fprintf (file, "$%s", reg_names[REGNO (operand)]);
      return;

    case MEM:
      if (addressing_mode)
	{
	  x = XEXP (x, 0);
	  if (GET_CODE (x) == PLUS && GET_CODE (XEXP (x, 0)) == MULT
	      && GET_CODE (XEXP (XEXP (x, 0), 1)) == CONST_INT
	      && INTVAL (XEXP (XEXP (x, 0), 1)) > HOST_WIDE_INT_1)
	    fprintf (file, ".xs");
	}
      else
	{
	  x = XEXP (x, 0);
	  if (GET_CODE (x) == UNSPEC)
	    kvx_print_operand (file, x, 0);
	  else
	    output_address (GET_MODE (XEXP (operand, 0)), XEXP (operand, 0));
	}
      return;

    case CONST_DOUBLE: {
	long l[2];
	REAL_VALUE_TYPE r = *CONST_DOUBLE_REAL_VALUE (operand);
	if (GET_MODE (x) == HFmode)
	  {
	    REAL_VALUE_TO_TARGET_SINGLE (r, l[0]);
	    l[0] = kvx_float_to_half_as_int (l[0]);
	    fprintf (file, "0x%04x", (unsigned int) l[0]);
	    return;
	  }
	else if (GET_MODE (x) == SFmode)
	  {
	    REAL_VALUE_TO_TARGET_SINGLE (r, l[0]);
	    fprintf (file, "0x%08x", (unsigned int) l[0]);
	    return;
	  }
	else if (GET_MODE (x) == DFmode)
	  {
	    /* this is a double that should fit on less than 64bits */
	    REAL_VALUE_TO_TARGET_DOUBLE (r, l);
	    fprintf (file, "0x%08x%08x", (unsigned int) l[1],
		     (unsigned int) l[0]);
	    return;
	  }
      }
      gcc_unreachable ();
      return;

    case CONST_INT:
      {
	HOST_WIDE_INT value = INTVAL (x);
	int signed10 = value >= -512 && value < 512;
	const char *format = signed10? HOST_WIDE_INT_PRINT_DEC:
				       "0x" HOST_WIDE_INT_PRINT_PADDED_HEX;
	fprintf (file, format, INTVAL (x));
      }
      return;

      case CONST_VECTOR: {
	int slice = 1 * select_yreg + 2 * select_zreg + 3 * select_treg;
	fprintf (file, "0x" HOST_WIDE_INT_PRINT_PADDED_HEX,
		 kvx_const_vector_value (x, slice));
      }
      return;

    case CONST_STRING:
      /* Case for modifier strings */
      fputs (XSTR (operand, 0), file);
      return;

      default: {
	int is_unspec = 0, unspec;

	if (GET_CODE (operand) == CONST)
	  operand = XEXP (operand, 0);

	if (GET_CODE (operand) == UNSPEC)
	  {
	    is_unspec = 1;
	    unspec = XINT (operand, 1);
	    operand = XVECEXP (operand, 0, 0);
	  }

	if (is_unspec)
	  {
	    switch (unspec)
	      {
	      case UNSPEC_TLS_GD:
	      case UNSPEC_TLS_LD:
	      case UNSPEC_TLS_DTPOFF:
	      case UNSPEC_TLS_LE:
	      case UNSPEC_TLS_IE:
		fputs (kvx_unspec_tls_asm_op[unspec - UNSPEC_TLS_GD], (file));
		fputs ("(", (file));
		break;
	      case UNSPEC_GOT:
		fprintf (file, "@got(");
		break;
	      case UNSPEC_GOTOFF:
		fprintf (file, "@gotoff(");
		break;
	      case UNSPEC_PCREL:
		fprintf (file, "@pcrel(");
		break;
	      default:
		gcc_unreachable ();
	      }
	  }

	/* No need to handle all strange variants, let output_addr_const
	   do it for us.  */
	output_addr_const (file, operand);
	if (is_unspec)
	  fprintf (file, ")");
      }
    }
}

static const char *
kvx_regname (rtx x)
{
  machine_mode mode = GET_MODE (x);

  switch (GET_CODE (x))
    {
    case REG:
      if (GET_MODE_SIZE (mode) <= UNITS_PER_WORD)
	return reg_names[REGNO (x)];
      else if (GET_MODE_SIZE (mode) <= 2 * UNITS_PER_WORD)
	return pgr_reg_names[REGNO (x)];
      else if (GET_MODE_SIZE (mode) <= 4 * UNITS_PER_WORD)
	return qgr_reg_names[REGNO (x)];
      gcc_unreachable ();
    case SUBREG:
      // Addressing mode with register offset
      gcc_assert (TARGET_32);
      gcc_assert (SUBREG_BYTE (x) == 0);
      return kvx_regname (SUBREG_REG (x));
    default:
      gcc_unreachable ();
    }
}

void
kvx_print_operand_address (FILE *file, rtx x)
{
  switch (GET_CODE (x))
    {
    case REG:
    case SUBREG:
      fprintf (file, "0[$%s]", kvx_regname (x));
      break;

    case PLUS:
      switch (GET_CODE (XEXP (x, 1)))
	{
	case CONST_INT:
	  fprintf (file, HOST_WIDE_INT_PRINT_DEC, INTVAL (XEXP (x, 1)));
	  break;
	case LABEL_REF:
	case SYMBOL_REF:
	case CONST:
	case UNSPEC:
	  output_addr_const (file, XEXP (x, 1));
	  break;
	case REG:
	case SUBREG:
	  if (GET_CODE (XEXP (x, 0)) == MULT)
	    fprintf (file, "$%s", kvx_regname (XEXP (XEXP (x, 0), 0)));
	  else
	    fprintf (file, "$%s", kvx_regname (XEXP (x, 1)));
	  break;
	default:
	  abort ();
	}
      if (GET_CODE (XEXP (x, 0)) == MULT)
	fprintf (file, "[$%s]", kvx_regname (XEXP (x, 1)));
      else
	fprintf (file, "[$%s]", kvx_regname (XEXP (x, 0)));
      return;

    default:
      output_addr_const (file, x);
      break;
    }
}

/* Functions to save and restore machine-specific function data.  */
static struct machine_function *
kvx_init_machine_status (void)
{
  struct machine_function *machine;
  machine = ggc_cleared_alloc<machine_function> ();

  return machine;
}

/* Do anything needed before RTL is emitted for each function.  */
void
kvx_init_expanders (void)
{
  /* Arrange to initialize and mark the machine per-function status.  */
  init_machine_status = kvx_init_machine_status;

  if (TARGET_DIVMOD0_TRAP)
    kvx_divmod_zero = const0_rtx;
  else
    kvx_divmod_zero = const1_rtx;
}

bool
kvx_print_punct_valid_p (unsigned char code)
{
  return code == ';';
}

/* Handle an attribute requiring a FUNCTION_DECL;
   arguments as in struct attribute_spec.handler.  */
static tree
kvx_handle_fndecl_attribute (tree *node, tree name, tree args ATTRIBUTE_UNUSED,
			     int flags ATTRIBUTE_UNUSED, bool *no_add_attrs)
{
  if (TREE_CODE (*node) != FUNCTION_DECL)
    {
      warning (OPT_Wattributes, "%qE attribute only applies to functions",
	       name);
      *no_add_attrs = true;
    }

  return NULL_TREE;
}

void
kvx_expand_tablejump (rtx op0, rtx op1)
{
  if (flag_pic)
    {
      rtx tmp_reg = gen_reg_rtx (Pmode);
      emit_move_insn (tmp_reg, gen_rtx_LABEL_REF (VOIDmode, op1));

      /* Relative addrs are stored as 32bits value. */
      if (GET_MODE (op0) != Pmode)
	{
	  rtx dreg = gen_reg_rtx (Pmode);
	  emit_insn (gen_extend_insn (dreg, op0, Pmode, GET_MODE (op0), 0));
	  op0 = dreg;
	}
      emit_insn (gen_add2_insn (op0, tmp_reg));
    }

  if (!TARGET_32)
    {
      emit_jump_insn (gen_tablejump_real_di (op0, op1));
    }
  else
    {
      emit_jump_insn (gen_tablejump_real_si (op0, op1));
    }
}

/* Return TRUE if REGNO should be saved in the prologue of current function */
static bool
should_be_saved_in_prologue (int regno)
{
  return (df_regs_ever_live_p (regno)	   // reg is used
	  && !call_really_used_regs[regno] // reg is callee-saved
	  && (regno == KV3_RETURN_POINTER_REGNO || !fixed_regs[regno]));
}

static bool
kvx_register_saved_on_entry (int regno)
{
  return cfun->machine->frame.reg_rel_offset[regno] >= 0;
}

/* Returns a REG rtx with the nth hard reg that is safe to use in prologue
   (caller-saved and non fixed reg). Returns NULL_RTX and emits an
   error if no such register can be found. */
static rtx
kvx_get_callersaved_nonfixed_reg (machine_mode mode, unsigned int n)
{
  int regno;
  unsigned int i;
  // start at R16 as as everything before that may be used.
  // We should be able to use the veneer regs if not fixed.
  for (i = 0, regno = 16; regno < FIRST_PSEUDO_REGISTER; regno++)
    {
      bool candidate = call_really_used_regs[regno] && !fixed_regs[regno];
#ifdef GCC_KVX_MPPA_LINUX
      candidate &= !((regno == PROFILE_REGNO) && (crtl->profile));
#endif

      if (!candidate)
        continue;

      if (i == n)
        return gen_rtx_REG (mode, regno);
      else
        i++;
    }

  error ("No scratch register available in function prologue.");
  return NULL_RTX;
}

static void
kvx_emit_single_spill (rtx mem, rtx reg, bool is_load)
{
  rtx set = gen_rtx_SET (is_load ? reg : mem, is_load ? mem : reg);
  rtx insn = emit_insn (set);
  if (!is_load)
    {
      RTX_FRAME_RELATED_P (insn) = 1;
      add_reg_note (insn, REG_CFA_OFFSET, copy_rtx (set));
    }
}

static void
kvx_emit_multiple_spill (rtx mem, rtx reg, unsigned nr, bool is_load)
{
  gcc_assert (nr == 2 || nr == 4);

  rtx operands[4] = {is_load ? reg : mem, is_load ? mem : reg, GEN_INT (nr)};

  if (is_load)
    kvx_expand_load_multiple (operands);
  else
    kvx_expand_store_multiple (operands);
  rtx insn = emit_insn (operands[3]);

  if (!is_load)
    {
      RTX_FRAME_RELATED_P (insn) = 1;
      gcc_assert (XVECLEN (PATTERN (insn), 0) == nr);

      for (unsigned int i = 0; i < nr; i++)
	{
	  add_reg_note (insn, REG_CFA_OFFSET,
			copy_rtx (XVECEXP (PATTERN (insn), 0, i)));
	}
    }
}

/* Save/Restore register at offsets previously computed in frame information
 * layout. The routine uses $sp as base register, so it must be set to its
 * initial value in case of dynamic stack allocation.
 */
static void
kvx_save_or_restore_callee_save_registers (bool restore)
{
  struct kvx_frame_info *frame = &cfun->machine->frame;
  rtx insn;
  rtx (*gen_mem_ref) (enum machine_mode, rtx) = gen_rtx_MEM;

  unsigned regno;

  unsigned int pack_prev_regs[4];
  unsigned int pack_prev_regs_idx = 0;

  enum
  {
    NO_PACK_YET = 0,
    DOUBLE_REG,
    QUAD_REG
  } pack_type
    = NO_PACK_YET;

  hard_reg_set_iterator rsi;

  EXECUTE_IF_SET_IN_HARD_REG_SET (frame->saved_regs, 0, regno, rsi)
  {
    if (kvx_register_saved_on_entry (regno))
      {
	rtx mem
	  = gen_mem_ref (DImode,
			 plus_constant (Pmode, stack_pointer_rtx,
					frame->saved_reg_sp_offset
					  + frame->reg_rel_offset[regno]));

	rtx saved_reg = gen_rtx_REG (DImode, regno);
	rtx orig_save_reg = saved_reg;

	if (regno == KV3_RETURN_POINTER_REGNO)
	  {
	    saved_reg = kvx_get_callersaved_nonfixed_reg (DImode, 0);
	    gcc_assert (saved_reg != NULL_RTX);

	    if (restore == false)
	      {
		rtx src_reg = gen_rtx_REG (DImode, regno);
		insn = emit_move_insn (saved_reg, src_reg);
		RTX_FRAME_RELATED_P (insn) = 1;

		add_reg_note (insn, REG_CFA_REGISTER,
			      gen_rtx_SET (saved_reg, src_reg));
	      }
	  }

	if (regno == KV3_RETURN_POINTER_REGNO)
	  {
	    if (restore)
	      {
		insn = emit_move_insn (saved_reg, mem);
		insn = emit_move_insn (gen_rtx_REG (DImode, regno), saved_reg);
	      }
	    else
	      {
		insn = emit_move_insn (mem, saved_reg);
		RTX_FRAME_RELATED_P (insn) = 1;
		add_reg_note (insn, REG_CFA_OFFSET,
			      gen_rtx_SET (mem, orig_save_reg));
	      }
	  }
	else
	  {
	  process_current_reg:
	    switch (pack_type)
	      {
	      case NO_PACK_YET:
		if (regno & 1)
		  {
		    kvx_emit_single_spill (mem, saved_reg, restore);
		  }
		else
		  {
		    pack_type = (regno % 4 == 0) ? QUAD_REG : DOUBLE_REG;
		    pack_prev_regs[0] = regno;
		    pack_prev_regs_idx = 1;
		  }
		break;

	      case DOUBLE_REG:
		if (pack_prev_regs[0] == (regno - 1)
		    && frame->reg_rel_offset[pack_prev_regs[0]]
			 == (frame->reg_rel_offset[regno] - UNITS_PER_WORD))
		  {
		    kvx_emit_multiple_spill (
		      gen_mem_ref (
			DImode,
			plus_constant (
			  Pmode, stack_pointer_rtx,
			  frame->saved_reg_sp_offset
			    + frame->reg_rel_offset[pack_prev_regs[0]])),
		      gen_rtx_REG (DImode, pack_prev_regs[0]), 2, restore);
		    pack_type = NO_PACK_YET;
		    pack_prev_regs_idx = 0;
		  }
		else
		  {
		    /* Emit previous candidate */
		    kvx_emit_single_spill (
		      gen_mem_ref (
			DImode,
			plus_constant (
			  Pmode, stack_pointer_rtx,
			  frame->saved_reg_sp_offset
			    + frame->reg_rel_offset[pack_prev_regs[0]])),
		      gen_rtx_REG (DImode, pack_prev_regs[0]), restore);

		    pack_type = NO_PACK_YET;
		    goto process_current_reg;
		  }
		break;

	      case QUAD_REG:
		if (pack_prev_regs[pack_prev_regs_idx - 1] == (regno - 1)
		    && frame->reg_rel_offset[pack_prev_regs[pack_prev_regs_idx
							    - 1]]
			 == (frame->reg_rel_offset[regno] - UNITS_PER_WORD))
		  {
		    if (pack_prev_regs_idx == 3)
		      {
			/* Emit a quad register load/store */
			kvx_emit_multiple_spill (
			  gen_mem_ref (
			    DImode,
			    plus_constant (
			      Pmode, stack_pointer_rtx,
			      frame->saved_reg_sp_offset
				+ frame->reg_rel_offset[pack_prev_regs[0]])),
			  gen_rtx_REG (DImode, pack_prev_regs[0]), 4, restore);
			pack_type = NO_PACK_YET;
			pack_prev_regs_idx = 0;
		      }
		    else
		      {
			pack_prev_regs[pack_prev_regs_idx++] = regno;
		      }
		  }
		else if (pack_prev_regs_idx == 3)
		  {
		    /* Emit a double followed by a single register load/store */
		    kvx_emit_multiple_spill (
		      gen_mem_ref (
			DImode,
			plus_constant (
			  Pmode, stack_pointer_rtx,
			  frame->saved_reg_sp_offset
			    + frame->reg_rel_offset[pack_prev_regs[0]])),
		      gen_rtx_REG (DImode, pack_prev_regs[0]), 2, restore);
		    kvx_emit_single_spill (
		      gen_mem_ref (
			DImode,
			plus_constant (
			  Pmode, stack_pointer_rtx,
			  frame->saved_reg_sp_offset
			    + frame->reg_rel_offset[pack_prev_regs[2]])),
		      gen_rtx_REG (DImode, pack_prev_regs[2]), restore);

		    pack_type = NO_PACK_YET;
		    pack_prev_regs_idx = 0;
		    goto process_current_reg;
		  }
		else if (pack_prev_regs_idx == 2)
		  {
		    /* Emit a double register load/store and try to pack the
		       next one */
		    kvx_emit_multiple_spill (
		      gen_mem_ref (
			DImode,
			plus_constant (
			  Pmode, stack_pointer_rtx,
			  frame->saved_reg_sp_offset
			    + frame->reg_rel_offset[pack_prev_regs[0]])),
		      gen_rtx_REG (DImode, pack_prev_regs[0]), 2, restore);

		    pack_type = NO_PACK_YET;
		    pack_prev_regs_idx = 0;
		    goto process_current_reg;
		  }
		else
		  {
		    /* Emit a single single register load/store and try to pack
		       the next one */
		    kvx_emit_single_spill (
		      gen_mem_ref (
			DImode,
			plus_constant (
			  Pmode, stack_pointer_rtx,
			  frame->saved_reg_sp_offset
			    + frame->reg_rel_offset[pack_prev_regs[0]])),
		      gen_rtx_REG (DImode, pack_prev_regs[0]), restore);

		    pack_type = NO_PACK_YET;
		    pack_prev_regs_idx = 0;
		    goto process_current_reg;
		  }
	      }
	  }
      }
  }

  /* Purge remaining register load/store that could not be packed */
  if (pack_type == DOUBLE_REG)
    {
      kvx_emit_single_spill (
	gen_mem_ref (
	  DImode, plus_constant (Pmode, stack_pointer_rtx,
				 frame->saved_reg_sp_offset
				   + frame->reg_rel_offset[pack_prev_regs[0]])),
	gen_rtx_REG (DImode, pack_prev_regs[0]), restore);
    }
  else if (pack_type == QUAD_REG)
    {
      if (pack_prev_regs_idx == 1)
	{
	  kvx_emit_single_spill (
	    gen_mem_ref (
	      DImode,
	      plus_constant (Pmode, stack_pointer_rtx,
			     frame->saved_reg_sp_offset
			       + frame->reg_rel_offset[pack_prev_regs[0]])),
	    gen_rtx_REG (DImode, pack_prev_regs[0]), restore);
	}
      else if (pack_prev_regs_idx == 2)
	{
	  kvx_emit_multiple_spill (
	    gen_mem_ref (
	      DImode,
	      plus_constant (Pmode, stack_pointer_rtx,
			     frame->saved_reg_sp_offset
			       + frame->reg_rel_offset[pack_prev_regs[0]])),
	    gen_rtx_REG (DImode, pack_prev_regs[0]), 2, restore);
	}
      else
	{
	  kvx_emit_multiple_spill (
	    gen_mem_ref (
	      DImode,
	      plus_constant (Pmode, stack_pointer_rtx,
			     frame->saved_reg_sp_offset
			       + frame->reg_rel_offset[pack_prev_regs[0]])),
	    gen_rtx_REG (DImode, pack_prev_regs[0]), 2, restore);

	  kvx_emit_single_spill (
	    gen_mem_ref (
	      DImode,
	      plus_constant (Pmode, stack_pointer_rtx,
			     frame->saved_reg_sp_offset
			       + frame->reg_rel_offset[pack_prev_regs[2]])),
	    gen_rtx_REG (DImode, pack_prev_regs[2]), restore);
	}
    }
}

/* Implement INITIAL_ELIMINATION_OFFSET.  FROM is either the frame pointer
   or argument pointer.  TO is either the stack pointer or frame
   pointer.  */

poly_int64
kvx_initial_elimination_offset (int from, int to)
{
  kvx_compute_frame_info ();
  struct kvx_frame_info *frame = &cfun->machine->frame;

  /* Should never have anything else FRAME_POINTER_REGNUM -> HFP/SP */
  if (from != FRAME_POINTER_REGNUM
      || (to != STACK_POINTER_REGNUM && to != HARD_FRAME_POINTER_REGNUM))
    gcc_unreachable ();

  if (from == FRAME_POINTER_REGNUM && to == STACK_POINTER_REGNUM)
    return frame->virt_frame_pointer_offset;
  else if (from == FRAME_POINTER_REGNUM && to == HARD_FRAME_POINTER_REGNUM)
    return (frame->virt_frame_pointer_offset
	    - frame->hard_frame_pointer_offset);

  gcc_unreachable ();
}

/* Return TRUE if target supports -fstack-limit-register */

bool
kvx_have_stack_checking (void)
{
#ifdef GCC_KVX_MPPA_COS
  return true;
#else
  return false;
#endif
}

void
kvx_expand_prologue (void)
{
  kvx_compute_frame_info ();
  struct kvx_frame_info *frame = &cfun->machine->frame;
  HOST_WIDE_INT size = frame->frame_size;
  rtx insn;

  if (flag_stack_usage_info)
    current_function_static_stack_size = size;

  kvx_debug_frame_info (frame);

  if (size > 0)
    {

      if (crtl->limit_stack)
	{
	  if (kvx_have_stack_checking ())
	    {
	      rtx new_stack_pointer_rtx
		= kvx_get_callersaved_nonfixed_reg (Pmode, 0);
	      rtx stack_limit_reg = kvx_get_callersaved_nonfixed_reg (Pmode, 1);

	      emit_move_insn (stack_limit_reg, stack_limit_rtx);
	      emit_insn (gen_add3_insn (new_stack_pointer_rtx,
					stack_pointer_rtx, GEN_INT (-size)));
	      emit_insn (gen_sub3_insn (new_stack_pointer_rtx, stack_limit_reg,
					new_stack_pointer_rtx));
	      emit_insn (
		gen_ctrapsi4 (gen_rtx_GT (VOIDmode, new_stack_pointer_rtx,
					  const0_rtx),
			      new_stack_pointer_rtx, const0_rtx, GEN_INT (0)));
	    }
	  else
	    {
	      error ("-fstack-limit-* is not supported.");
	    }
	}

      insn = emit_insn (gen_add2_insn (stack_pointer_rtx, GEN_INT (-size)));
      RTX_FRAME_RELATED_P (insn) = 1;

      add_reg_note (insn, REG_CFA_ADJUST_CFA, copy_rtx (PATTERN (insn)));
    }

  /* Save registers */
  kvx_save_or_restore_callee_save_registers (0);

  if (frame_pointer_needed)
    {
      gcc_assert (frame->reg_rel_offset[HARD_FRAME_POINTER_REGNUM] == 0);
      insn = emit_insn (
	gen_add3_insn (hard_frame_pointer_rtx, stack_pointer_rtx,
		       GEN_INT (frame->hard_frame_pointer_offset)));

      RTX_FRAME_RELATED_P (insn) = 1;
      add_reg_note (
	insn, REG_CFA_DEF_CFA,
	gen_rtx_PLUS (
	  Pmode, hard_frame_pointer_rtx,
				  GEN_INT (
				    size - frame->hard_frame_pointer_offset)));
    }
}

void
kvx_expand_epilogue (void)
{
  struct kvx_frame_info *frame = &cfun->machine->frame;
  HOST_WIDE_INT frame_size = frame->frame_size;
  rtx insn;

  if (frame_pointer_needed)
    {
      /* Restore $sp from $fp */
      insn = emit_insn (
	gen_add3_insn (stack_pointer_rtx, hard_frame_pointer_rtx,
		       GEN_INT (-frame->hard_frame_pointer_offset)));

      /* Revert CFA reg to use SP with its initial offset */
      RTX_FRAME_RELATED_P (insn) = 1;
      add_reg_note (insn, REG_CFA_DEF_CFA,
		    gen_rtx_PLUS (DImode, stack_pointer_rtx,
				  GEN_INT (frame->frame_size)));
    }

  /* $sp is now correct and can be used by save_or_restore */
  kvx_save_or_restore_callee_save_registers (1);

  if (frame_size != 0)
    {
      insn = GEN_INT (frame_size);
      insn = emit_insn (gen_add2_insn (stack_pointer_rtx, insn));
      RTX_FRAME_RELATED_P (insn) = 1;
      add_reg_note (insn, REG_CFA_ADJUST_CFA, copy_rtx (PATTERN (insn)));
    }
}

/* Return the TLS model to use for ADDR.  */

static enum tls_model
tls_symbolic_operand_type (rtx addr)
{
  enum tls_model tls_kind = TLS_MODEL_NONE;

  if (GET_CODE (addr) == CONST)
    {
      if (GET_CODE (XEXP (addr, 0)) == PLUS
	  && GET_CODE (XEXP (XEXP (addr, 0), 0)) == SYMBOL_REF)
	tls_kind = SYMBOL_REF_TLS_MODEL (XEXP (XEXP (addr, 0), 0));
    }
  else if (GET_CODE (addr) == SYMBOL_REF)
    tls_kind = SYMBOL_REF_TLS_MODEL (addr);

    /* General TLS model only supported on Linux. ClusterOS and bare
       only supports local exec. */

#ifndef GCC_KVX_MPPA_LINUX
  if (tls_kind != TLS_MODEL_NONE)
    tls_kind = TLS_MODEL_LOCAL_EXEC;
#endif
  return tls_kind;
}

/* Return true if SYMBOL_REF X is thread local */
static bool
kvx_tls_symbol_p (rtx x)
{
  if (!TARGET_HAVE_TLS)
    return false;

  if (GET_CODE (x) != SYMBOL_REF)
    return false;

  return SYMBOL_REF_TLS_MODEL (x) != 0;
}

static rtx
gen_set_gotp_insn (rtx target)
{
  if (TARGET_32)
    return gen_set_gotp_si (target);
  else
    return gen_set_gotp_di (target);
}

static enum kvx_symbol_type
kvx_classify_tls_symbol (rtx x)
{
  enum tls_model tls_kind = tls_symbolic_operand_type (x);
  switch (tls_kind)
    {
    case TLS_MODEL_LOCAL_EXEC:
      return SYMBOL_TLSLE;

      /* General TLS model only supported on Linux. ClusterOS and bare
	 only supports local exec. */
#ifdef GCC_KVX_MPPA_LINUX
    case TLS_MODEL_LOCAL_DYNAMIC:
      return SYMBOL_TLSLD;

    case TLS_MODEL_GLOBAL_DYNAMIC:
      return SYMBOL_TLSGD;

    case TLS_MODEL_INITIAL_EXEC:
      return SYMBOL_TLSIE;
#else
    case TLS_MODEL_LOCAL_DYNAMIC:
    case TLS_MODEL_GLOBAL_DYNAMIC:
    case TLS_MODEL_INITIAL_EXEC:
#endif
    case TLS_MODEL_EMULATED:
    case TLS_MODEL_NONE:
      error ("TLS model not supported.");
      break;

    default:
      gcc_unreachable ();
    }
}

static enum kvx_symbol_type
kvx_classify_symbol (rtx x)
{
  if (kvx_tls_symbol_p (x))
    return kvx_classify_tls_symbol (x);

  /* We keep both way of materializing the absolute address of a label
     because the use of pcrel insn has greater constraints on bundling
     (ALU_FULL) versus a simple make (ALU_TINY) */
  if (GET_CODE (x) == LABEL_REF)
    return flag_pic ? LABEL_PCREL_ABSOLUTE : LABEL_ABSOLUTE;

  if (GET_CODE (x) == SYMBOL_REF)
    {
      if (!flag_pic)
	return SYMBOL_ABSOLUTE;

      if (SYMBOL_REF_LOCAL_P (x) && !SYMBOL_REF_EXTERNAL_P (x))
	return SYMBOL_GOTOFF;
      else
	return SYMBOL_GOT;
    }
  return SYMBOL_ABSOLUTE;
}

static GTY (()) rtx kvx_tls_symbol;

/* Return an instruction sequence that calls __tls_get_addr.  SYM is
   the TLS symbol we are referencing and TYPE is the symbol type to use
   (either global dynamic or local dynamic).  RESULT is an RTX for the
   return value location.  */

static rtx_insn *
kvx_call_tls_get_addr (rtx sym, rtx result, int unspec)
{
  rtx a0 = gen_rtx_REG (Pmode, KV3_ARGUMENT_POINTER_REGNO), func;
  rtx_insn *insn;

  if (!kvx_tls_symbol)
    kvx_tls_symbol = init_one_libfunc ("__tls_get_addr");
  func = gen_rtx_MEM (FUNCTION_MODE, kvx_tls_symbol);

  start_sequence ();

  /* sequence for getting TLS desc address from GOT slot:
   */
  rtx pic_reg = gen_reg_rtx (Pmode);
  emit_insn (gen_set_gotp_insn (pic_reg));

  rtx new_rtx
    = gen_rtx_CONST (Pmode, gen_rtx_UNSPEC (Pmode, gen_rtvec (1, sym), unspec));
  emit_insn (gen_add3_insn (a0, pic_reg, new_rtx));

  insn = emit_call_insn (gen_call_value (result, func, const0_rtx));
  RTL_CONST_CALL_P (insn) = 1;
  use_reg (&CALL_INSN_FUNCTION_USAGE (insn), a0);
  insn = get_insns ();

  end_sequence ();

  return insn;
}

static rtx
kvx_legitimize_tls_reference (rtx x)
{
  rtx addr, pic_reg, eqv;
  rtx dest, tmp;

  if (reload_completed || reload_in_progress)
    return x;

  enum kvx_symbol_type sty = kvx_classify_symbol (x);

  switch (sty)
    {
    case SYMBOL_TLSLE:
      /* address is @tlsle(symbol)[$tp]
       */
      addr
	= gen_rtx_PLUS (Pmode, gen_rtx_REG (Pmode, KV3_LOCAL_POINTER_REGNO),
			gen_rtx_CONST (Pmode,
				       gen_rtx_UNSPEC (Pmode, gen_rtvec (1, x),
						       UNSPEC_TLS_LE)));
      return addr;

    case SYMBOL_TLSGD:
      /* Sequence is:
       * $r0 = @tlsgd(sym) + $got
       * addr = __tls_get_addr()
       */
      tmp = gen_rtx_REG (Pmode, KV3_ARGUMENT_POINTER_REGNO);
      dest = gen_reg_rtx (Pmode);
      emit_libcall_block (kvx_call_tls_get_addr (x, tmp, UNSPEC_TLS_GD),
			  dest /* target */, tmp /* result */, x /* equiv */);
      return dest;

    case SYMBOL_TLSIE:
      pic_reg = gen_reg_rtx (Pmode);
      dest = gen_reg_rtx (Pmode);

      emit_insn (gen_set_gotp_insn (pic_reg));

      addr
	= gen_rtx_PLUS (Pmode, pic_reg,
			gen_rtx_CONST (Pmode,
				       gen_rtx_UNSPEC (Pmode, gen_rtvec (1, x),
						       UNSPEC_TLS_IE)));
      emit_move_insn (dest, gen_rtx_MEM (Pmode, addr));

      return gen_rtx_PLUS (Pmode, gen_rtx_REG (Pmode, KV3_LOCAL_POINTER_REGNO),
			   dest);

    case SYMBOL_TLSLD:
      tmp = gen_rtx_REG (Pmode, KV3_ARGUMENT_POINTER_REGNO);
      dest = gen_reg_rtx (Pmode);

      /* Attach a unique REG_EQUIV, to allow the RTL optimizers to
	 share the LD result with other LD model accesses.  */
      eqv
	= gen_rtx_UNSPEC (Pmode, gen_rtvec (1, const0_rtx), UNSPEC_TLS_LD_CALL);

      emit_libcall_block (kvx_call_tls_get_addr (x, tmp, UNSPEC_TLS_LD),
			  dest /* target */, tmp /* result */, eqv /* equiv */);

      addr
	= gen_rtx_PLUS (Pmode, dest,
			gen_rtx_CONST (Pmode,
				       gen_rtx_UNSPEC (Pmode, gen_rtvec (1, x),
						       UNSPEC_TLS_DTPOFF)));

      return addr;

    default:
      gcc_unreachable ();
    }
}

static bool
function_symbol_referenced_p (rtx x)
{
  const char *format;
  int length;
  int j;

  if (GET_CODE (x) == SYMBOL_REF)
    return SYMBOL_REF_FUNCTION_P (x);

  length = GET_RTX_LENGTH (GET_CODE (x));
  format = GET_RTX_FORMAT (GET_CODE (x));

  for (j = 0; j < length; ++j)
    {
      switch (format[j])
	{
	case 'e':
	  if (function_symbol_referenced_p (XEXP (x, j)))
	    return TRUE;
	  break;

	case 'V':
	case 'E':
	  if (XVEC (x, j) != 0)
	    {
	      int k;
	      for (k = 0; k < XVECLEN (x, j); ++k)
		if (function_symbol_referenced_p (XVECEXP (x, j, k)))
		  return TRUE;
	    }
	  break;

	default:
	  /* Nothing to do.  */
	  break;
	}
    }

  return FALSE;
}

/* Returns TRUE if OP contains a symbol reference or a label reference */
bool
symbolic_reference_mentioned_p (rtx op)
{
  const char *fmt;
  int i;

  if (GET_CODE (op) == SYMBOL_REF || GET_CODE (op) == LABEL_REF)
    return TRUE;

  /* UNSPEC_TLS entries for a symbol include a LABEL_REF for the
     referencing instruction, but they are constant offsets, not
     symbols.  */
  if (GET_CODE (op) == UNSPEC
      && (XINT (op, 1) == UNSPEC_TLS_LE || XINT (op, 1) == UNSPEC_TLS_LD
	  || XINT (op, 1) == UNSPEC_TLS_DTPOFF || XINT (op, 1) == UNSPEC_TLS_GD
	  || XINT (op, 1) == UNSPEC_TLS_IE))
    return false;

  fmt = GET_RTX_FORMAT (GET_CODE (op));
  for (i = GET_RTX_LENGTH (GET_CODE (op)) - 1; i >= 0; i--)
    {
      if (fmt[i] == 'E')
	{
	  int j;

	  for (j = XVECLEN (op, i) - 1; j >= 0; j--)
	    if (symbolic_reference_mentioned_p (XVECEXP (op, i, j)))
	      return TRUE;
	}

      else if (fmt[i] == 'e' && symbolic_reference_mentioned_p (XEXP (op, i)))
	return TRUE;
    }

  return FALSE;
}

/* Returns TRUE if OP is (const (unspec ([] UNSPEC_*))) or
   (unspec ([] UNSPEC_*)) with unspec type compatible with PIC
   code
*/
bool
kvx_legitimate_pic_symbolic_ref_p (rtx op)
{
  /* Unwrap CONST */
  if (GET_CODE (op) == CONST)
    op = XEXP (op, 0);

  /* Valid ref are wrapped in UNSPEC */
  if (GET_CODE (op) != UNSPEC)
    return false;

  int unspec = XINT ((op), 1);
  return (unspec == UNSPEC_GOT || unspec == UNSPEC_GOTOFF
	  || unspec == UNSPEC_TLS_DTPOFF || unspec == UNSPEC_TLS_GD
	  || unspec == UNSPEC_TLS_LD || unspec == UNSPEC_TLS_LE
	  || unspec == UNSPEC_TLS_IE || unspec == UNSPEC_PCREL);
}

/* Returns TRUE if X can be used as an operand in PIC code.
 * LABELs are rejected as they should be handled by mov expand
 */

bool
kvx_legitimate_pic_operand_p (rtx x)
{
  if (GET_CODE (x) == SYMBOL_REF || GET_CODE (x) == LABEL_REF
      || (GET_CODE (x) == CONST && GET_CODE (XEXP (x, 0)) == PLUS
	  && (GET_CODE (XEXP (XEXP (x, 0), 0)) == SYMBOL_REF
	      || GET_CODE (XEXP (XEXP (x, 0), 0)) == LABEL_REF)))
    return false;

  return true;
}

static rtx
gen_add2_pcrel_insn (rtx dest, rtx pcrel_offset)
{
  if (TARGET_32)
    return gen_add_pcrel_si (dest, pcrel_offset);
  else
    return gen_add_pcrel_di (dest, pcrel_offset);
}

/* Expands a mov which second operand is a constant. */
void
kvx_expand_mov_constant (rtx operands[])
{
  rtx dest = operands[0];
  rtx src = operands[1];
  rtx new_rtx;

  if (GET_CODE (src) == SYMBOL_REF || GET_CODE (src) == LABEL_REF
      || GET_CODE (src) == CONST)
    {
      rtx base, offset;
      enum kvx_symbol_type sty;
      rtx pic_reg;

      /* If we have (const (plus symbol offset)), separate out the offset
	 before we start classifying the symbol.  */
      split_const (src, &base, &offset);

      sty = kvx_classify_symbol (base);
      switch (sty)
	{
	case SYMBOL_ABSOLUTE:
	case LABEL_ABSOLUTE:
	  /* Emit: dest = sym */
	  emit_insn (gen_rtx_SET (dest, src));
	  break;

	case LABEL_PCREL_ABSOLUTE:
	  /* Emit dest = pc + @pcrel(label) */
	  emit_insn (gen_add2_pcrel_insn (dest, src));
	  break;

	case SYMBOL_GOT:
	  /*
	   * Emit dest = *(@got(sym) + $pic)
	   */
	  pic_reg = gen_reg_rtx (Pmode);
	  emit_insn (gen_set_gotp_insn (pic_reg));

	  new_rtx
	    = gen_rtx_CONST (Pmode, gen_rtx_UNSPEC (Pmode, gen_rtvec (1, base),
						    UNSPEC_GOT));

	  emit_move_insn (dest, pic_reg);

	  emit_move_insn (dest, gen_rtx_MEM (Pmode, gen_rtx_PLUS (Pmode, dest,
								  new_rtx)));
	  if (INTVAL (offset) != 0)
	    emit_insn (gen_add2_insn (dest, offset));

	  crtl->uses_pic_offset_table = true;
	  break;

	case SYMBOL_GOTOFF:
	  /*
	   * Emit dest = @gotoff(sym)[$pic]
	   */
	  pic_reg = gen_reg_rtx (Pmode);
	  emit_insn (gen_set_gotp_insn (pic_reg));

	  new_rtx
	    = gen_rtx_CONST (Pmode, gen_rtx_UNSPEC (Pmode, gen_rtvec (1, base),
						    UNSPEC_GOTOFF));

	  emit_move_insn (dest, pic_reg);

	  emit_move_insn (dest, gen_rtx_PLUS (Pmode, dest, new_rtx));

	  if (INTVAL (offset) != 0)
	    emit_insn (gen_add2_insn (dest, offset));

	  crtl->uses_pic_offset_table = true;
	  break;

	case SYMBOL_TLSIE:
	case SYMBOL_TLSLD:
	case SYMBOL_TLSGD:
	case SYMBOL_TLSLE:
	  operands[1] = kvx_legitimize_tls_reference (base);
	  gcc_assert (operands[1] != src);

	  emit_insn (gen_rtx_SET (dest, operands[1]));

	  if (INTVAL (offset) != 0)
	    emit_insn (gen_add2_insn (dest, offset));

	  break;

	default:
	  gcc_unreachable ();
	}
      return;
    }

  emit_insn (gen_rtx_SET (dest, src));

  /* if (kvx_has_tls_reference (operands[1])) */
  /*   { */
  /*     rtx src = operands[1]; */
  /*     operands[1] = kvx_legitimize_tls_reference (src); */
  /*     gcc_assert (operands[1] != src); */
  /*   } else if (flag_pic) */
  /*   { */
  /*     if (SYMBOLIC_CONST(operands[1])) */
  /* 	operands[1] = kvx_legitimize_pic_address (operands[1],
   * operands[0]); */
  /*   } */
  return;
}

/* Canonicalize a comparison from one we don't have to one we do have.  */
static void
kvx_canonicalize_comparison (int *code, rtx *op0, rtx *op1,
			     bool op0_preserve_value)
{
  machine_mode mode = GET_MODE (*op0);
  bool float_compare_p = (GET_MODE_CLASS (mode) == MODE_FLOAT);
  static struct rtx_def rtx_; PUT_CODE (&rtx_, (enum rtx_code)*code);

  if (!op0_preserve_value && float_compare_p
      && !float_comparison_operator (&rtx_, VOIDmode))
    {
      rtx temp = *op1;
      *op1 = *op0;
      *op0 = temp;
      *code = (int)swap_condition ((enum rtx_code)*code);
    }
}

/* Return the mode of a predicate resulting from comparing MODE. */
static enum machine_mode
kvx_get_predicate_mode (enum machine_mode mode)
{
  switch (mode)
    {
    // 64-bit modes
    case E_V4HFmode:
      return V4HImode;
    case E_V2SFmode:
      return V2SImode;
    // 128-bit modes
    case E_V8HFmode:
      return V8HImode;
    case E_V4SFmode:
      return V4SImode;
    case E_V2DFmode:
      return V2DImode;
    // 256-bit modes
    case E_V16HFmode:
      return V16HImode;
    case E_V8SFmode:
      return V8SImode;
    case E_V4DFmode:
      return V4DImode;
    // Scalar modes
    case E_HFmode:
    case E_SFmode:
    case E_DFmode:
      return DImode;
    // Other modes
    default:
      break;
    }
  return mode;
}

/* Emulate V<n>QI comparisons by expanding them to V4HI comparisons. */
static rtx
kvx_emulate_vxqi_comparison(rtx pred, enum rtx_code cmp_code, rtx left, rtx right)
{
  machine_mode cmp_mode = GET_MODE (left);
  unsigned mode_size = GET_MODE_SIZE (cmp_mode);
  for (unsigned offset = 0; offset < mode_size; offset += UNITS_PER_WORD)
    {
      rtx rightc = simplify_gen_subreg (V4HImode, right, cmp_mode, offset);
      rtx leftc = simplify_gen_subreg (V4HImode, left, cmp_mode, offset);
      rtx predc = simplify_gen_subreg (V4HImode, pred, cmp_mode, offset);
      rtx righto = CONST0_RTX (V4HImode), righte = CONST0_RTX (V4HImode);
      if (!const_zero_operand (right, cmp_mode))
	{
	  righto = gen_reg_rtx (V4HImode), righte = gen_reg_rtx (V4HImode);
	  emit_insn (gen_rtx_SET (righto, gen_rtx_UNSPEC (V4HImode, gen_rtvec (1, rightc), UNSPEC_QXOBHQ)));
	  emit_insn (gen_rtx_SET (righte, gen_rtx_UNSPEC (V4HImode, gen_rtvec (1, rightc), UNSPEC_QXEBHQ)));
	}
      rtx lefto = gen_reg_rtx (V4HImode), lefte = gen_reg_rtx (V4HImode);
      emit_insn (gen_rtx_SET (lefto, gen_rtx_UNSPEC (V4HImode, gen_rtvec (1, leftc), UNSPEC_QXOBHQ)));
      emit_insn (gen_rtx_SET (lefte, gen_rtx_UNSPEC (V4HImode, gen_rtvec (1, leftc), UNSPEC_QXEBHQ)));
      rtx predo = gen_reg_rtx (V4HImode), prede = gen_reg_rtx (V4HImode);
      kvx_lower_comparison (predo, cmp_code, lefto, righto);
      kvx_lower_comparison (prede, cmp_code, lefte, righte);
      emit_insn (gen_rtx_SET (predo, gen_rtx_UNSPEC (V4HImode, gen_rtvec (1, predo), UNSPEC_QXOBHQ)));
      emit_insn (gen_rtx_SET (prede, gen_rtx_UNSPEC (V4HImode, gen_rtvec (1, prede), UNSPEC_ZXOBHQ)));
      emit_insn (gen_rtx_SET (predc, gen_rtx_UNSPEC (V4HImode, gen_rtvec (2, predo, prede), UNSPEC_OROEBO)));
    }
  return pred;
}

/* Emit the compare insn and return the predicate register if lowering occurred.
 * Lowering occurs if the comparison is not between scalar integer and zero.
 * In case of floating-point lowering, the left and right operand may be swapped.
 * The predicate register is created if lowering and if NULL_RTX is passed.  */
rtx
kvx_lower_comparison (rtx pred, enum rtx_code cmp_code, rtx left, rtx right)
{
  machine_mode cmp_mode = GET_MODE (left);
  enum mode_class cmp_class = GET_MODE_CLASS (cmp_mode);
  bool float_compare_p
    = (cmp_class == MODE_FLOAT || cmp_class == MODE_VECTOR_FLOAT);

  if (cmp_class == MODE_INT && const_zero_operand (right, cmp_mode))
    return NULL_RTX;

  if (pred == NULL_RTX)
    pred = gen_reg_rtx (kvx_get_predicate_mode (cmp_mode));

  if (VECTOR_MODE_P (cmp_mode) && GET_MODE_INNER (cmp_mode) == QImode)
    return kvx_emulate_vxqi_comparison (pred, cmp_code, left,right);

  machine_mode pred_mode = GET_MODE (pred);
  rtx cmp = gen_rtx_fmt_ee (cmp_code, pred_mode, left, right);

  if (float_compare_p)
    {
      if (!float_comparison_operator (cmp, VOIDmode))
	{
	  enum rtx_code swapped = swap_condition (cmp_code);

	  if (swapped == cmp_code)
	    {
	      rtx tmp = gen_reg_rtx (pred_mode);
	      rtx tmp2 = gen_reg_rtx (pred_mode);
	      rtx cmp2 = copy_rtx (cmp);
	      enum rtx_code cond_code;

	      if (cmp_code == UNORDERED)
		{
		  PUT_CODE (cmp, UNGE);
		  PUT_CODE (cmp2, UNLT);
		  cond_code = AND;
		}
	      else if (cmp_code == ORDERED)
		{
		  PUT_CODE (cmp, GE);
		  PUT_CODE (cmp2, LT);
		  cond_code = IOR;
		}
	      else
		{
		  gcc_unreachable ();
		}

	      emit_insn (gen_rtx_SET (tmp, cmp));
	      emit_insn (gen_rtx_SET (tmp2, cmp2));
	      cmp = gen_rtx_fmt_ee (cond_code, pred_mode, tmp, tmp2);
	    }
	  else
	    {
	      PUT_CODE (cmp, swapped);
	      XEXP (cmp, 0) = right;
	      XEXP (cmp, 1) = left;
	    }
	  gcc_assert (swapped == cmp_code
		      || float_comparison_operator (cmp, VOIDmode));
	}

      XEXP (cmp, 0) = force_reg (cmp_mode, XEXP (cmp, 0));
      XEXP (cmp, 1) = force_reg (cmp_mode, XEXP (cmp, 1));
    }
  else if (VECTOR_MODE_P (cmp_mode))
    {
      XEXP (cmp, 0) = force_reg (cmp_mode, XEXP (cmp, 0));
      XEXP (cmp, 1) = force_reg (cmp_mode, XEXP (cmp, 1));
    }

  emit_insn (gen_rtx_SET (pred, cmp));
  return pred;
}

/* Emulate V<n>QI cond moves by expanding them to V4HI cond moves. */
static void
kvx_emulate_vxqi_simplecond_move(rtx pred, enum rtx_code cmp_code, rtx src, rtx dst)
{
  machine_mode mode = GET_MODE (dst);
  rtx const0_v4hi_rtx = CONST0_RTX (V4HImode);
  unsigned mode_size = GET_MODE_SIZE (mode);
  for (unsigned offset = 0; offset < mode_size; offset += UNITS_PER_WORD)
    {
      rtx srcc = simplify_gen_subreg (V4HImode, src, mode, offset);
      rtx dstc = simplify_gen_subreg (V4HImode, dst, mode, offset);
      rtx predc = simplify_gen_subreg (V4HImode, pred, mode, offset);

      rtx srco = gen_reg_rtx (V4HImode), srce = gen_reg_rtx (V4HImode);
      emit_insn (gen_rtx_SET (srco, gen_rtx_UNSPEC (V4HImode, gen_rtvec (1, srcc), UNSPEC_QXOBHQ)));
      emit_insn (gen_rtx_SET (srce, gen_rtx_UNSPEC (V4HImode, gen_rtvec (1, srcc), UNSPEC_QXEBHQ)));

      rtx predo = gen_reg_rtx (V4HImode), prede = gen_reg_rtx (V4HImode);
      emit_insn (gen_rtx_SET (predo, gen_rtx_UNSPEC (V4HImode, gen_rtvec (1, predc), UNSPEC_QXOBHQ)));
      emit_insn (gen_rtx_SET (prede, gen_rtx_UNSPEC (V4HImode, gen_rtvec (1, predc), UNSPEC_QXEBHQ)));

      rtx cmpo = gen_rtx_fmt_ee (cmp_code, VOIDmode, predo, const0_v4hi_rtx);
      rtx cmpe = gen_rtx_fmt_ee (cmp_code, VOIDmode, prede, const0_v4hi_rtx);

      rtx dsto = gen_reg_rtx (V4HImode), dste = gen_reg_rtx (V4HImode);
      emit_insn (gen_rtx_SET (dsto, gen_rtx_UNSPEC (V4HImode, gen_rtvec (1, dstc), UNSPEC_QXOBHQ)));
      emit_insn (gen_rtx_SET (dste, gen_rtx_UNSPEC (V4HImode, gen_rtvec (1, dstc), UNSPEC_QXEBHQ)));

      emit_insn (gen_rtx_SET (dsto, gen_rtx_IF_THEN_ELSE (V4HImode, cmpo, srco, dsto)));
      emit_insn (gen_rtx_SET (dste, gen_rtx_IF_THEN_ELSE (V4HImode, cmpe, srce, dste)));

      emit_insn (gen_rtx_SET (dsto, gen_rtx_UNSPEC (V4HImode, gen_rtvec (1, dsto), UNSPEC_QXOBHQ)));
      emit_insn (gen_rtx_SET (dste, gen_rtx_UNSPEC (V4HImode, gen_rtvec (1, dste), UNSPEC_ZXOBHQ)));
      emit_insn (gen_rtx_SET (dstc, gen_rtx_UNSPEC (V4HImode, gen_rtvec (2, dsto, dste), UNSPEC_OROEBO)));
    }
}

void
kvx_expand_conditional_move (rtx target, rtx select1, rtx select2,
			     rtx cmp, rtx left, rtx right)
{
  machine_mode mode = GET_MODE (target);
  enum rtx_code cmp_code = GET_CODE (cmp);
  machine_mode cmp_mode = GET_MODE (left);
  rtx src = NULL_RTX, dst = NULL_RTX;
  bool vector_true_false = false;

  if (VECTOR_MODE_P (mode))
    {
      rtx const0_mode_rtx = CONST0_RTX (mode);
      rtx constm1_mode_rtx = CONSTM1_RTX (mode);
      vector_true_false = (select1 == constm1_mode_rtx)
			  && (select2 == const0_mode_rtx);
    }

  if (vector_true_false)
    {
      dst = target;
    }
  else if (!rtx_equal_p (select1, target) && !rtx_equal_p (select2, target))
    {
      if (reg_overlap_mentioned_p (target, cmp))
	dst = gen_reg_rtx (mode);
      else
	dst = target;

      src = force_reg (mode, select1);
      emit_move_insn (dst, select2);
    }
  else if (rtx_equal_p (select1, target))
    {
      src = force_reg (mode, select2);
      dst = target;

      enum mode_class cmp_class = GET_MODE_CLASS (cmp_mode);
      if (cmp_class == MODE_FLOAT || cmp_class == MODE_VECTOR_FLOAT)
	cmp_code = reverse_condition_maybe_unordered (cmp_code);
      else
	cmp_code = reverse_condition (cmp_code);
    }
  else
    {
      src = force_reg (mode, select1);
      dst = target;
    }

  machine_mode pred_mode = kvx_get_predicate_mode (cmp_mode);
  rtx pred = gen_reg_rtx (pred_mode);

  if (kvx_lower_comparison (pred, cmp_code, left, right))
    cmp_code = NE;
  else
    emit_move_insn (pred, left);

  if (vector_true_false)
    {
      emit_insn (gen_rtx_SET (dst, pred));
    }
  else if (VECTOR_MODE_P (cmp_mode) && GET_MODE_INNER (cmp_mode) == QImode)
    {
      kvx_emulate_vxqi_simplecond_move(pred, cmp_code, src, dst);
    }
  else
    {
      rtx const0_pred_mode_rtx = CONST0_RTX (pred_mode);
      rtx cmp0 = gen_rtx_fmt_ee (cmp_code, VOIDmode, pred, const0_pred_mode_rtx);
      emit_insn (gen_rtx_SET (dst, gen_rtx_IF_THEN_ELSE (mode, cmp0, src, dst)));
    }

  if (dst != target)
    emit_move_insn (target, dst);
}

void
kvx_expand_masked_move (rtx target, rtx select1, rtx select2, rtx mask)
{
  machine_mode mode = GET_MODE (target);
  enum rtx_code cmp_code = NE;
  rtx src = NULL_RTX, dst = NULL_RTX;
  bool vector_true_false = false;

  if (VECTOR_MODE_P (mode))
    {
      rtx const0_mode_rtx = CONST0_RTX (mode);
      rtx constm1_mode_rtx = CONSTM1_RTX (mode);
      vector_true_false = (select1 == constm1_mode_rtx)
			  && (select2 == const0_mode_rtx);
    }

  if (vector_true_false)
    {
      dst = target;
    }
  else if (!rtx_equal_p (select1, target) && !rtx_equal_p (select2, target))
    {
      if (reg_overlap_mentioned_p (target, mask))
	dst = gen_reg_rtx (mode);
      else
	dst = target;

      src = force_reg (mode, select1);
      emit_move_insn (dst, select2);
    }
  else if (rtx_equal_p (select1, target))
    {
      src = force_reg (mode, select2);
      dst = target;
      cmp_code = EQ;
    }
  else
    {
      src = force_reg (mode, select1);
      dst = target;
    }

  if (vector_true_false)
    {
      emit_insn (gen_rtx_SET (dst, mask));
    }
  else if (VECTOR_MODE_P (mode) && GET_MODE_INNER (mode) == QImode)
    {
      kvx_emulate_vxqi_simplecond_move(mask, cmp_code, src, dst);
    }
  else
    {
      machine_mode mask_mode = GET_MODE (mask);
      rtx const0_mask_mode_rtx = CONST0_RTX (mask_mode);
      rtx cmp0 = gen_rtx_fmt_ee (cmp_code, VOIDmode, mask, const0_mask_mode_rtx);
      emit_insn (gen_rtx_SET (dst, gen_rtx_IF_THEN_ELSE (mode, cmp0, src, dst)));
    }

  if (dst != target)
    emit_move_insn (target, dst);
}

/* Return the mode of a 64-bit chunk from a vector mode, else the mode. */
static enum machine_mode
kvx_get_chunk_mode (enum machine_mode mode)
{
  switch (mode)
    {
    // 128-bit modes
    case E_V16QImode:
      return V8QImode;
    case E_V8HImode:
      return V4HImode;
    case E_V4SImode:
      return V2SImode;
    case E_V2DImode:
      return DImode;
    case E_V8HFmode:
      return V4HFmode;
    case E_V4SFmode:
      return V2SFmode;
    case E_V2DFmode:
      return DFmode;
    // 256-bit modes
    case E_V32QImode:
      return V8QImode;
    case E_V16HImode:
      return V4HImode;
    case E_V8SImode:
      return V2SImode;
    case E_V4DImode:
      return DImode;
    case E_V16HFmode:
      return V4HFmode;
    case E_V8SFmode:
      return V2SFmode;
    case E_V4DFmode:
      return DFmode;
    // Other modes
    default:
      break;
    }
  return mode;
}

void
kvx_expand_vector_insert (rtx target, rtx source, rtx where)
{
  machine_mode vector_mode = GET_MODE (target);
  machine_mode inner_mode = GET_MODE_INNER (vector_mode);
  int width = GET_MODE_SIZE (inner_mode);

  if (CONST_INT_P (where))
    {
      int index = INTVAL (where);
      int major = (index*width) / UNITS_PER_WORD;
      int minor = (index*width) % UNITS_PER_WORD;

      if (GET_MODE_SIZE (inner_mode) == UNITS_PER_WORD)
	{
	  rtx op0 = simplify_gen_subreg (inner_mode, target, vector_mode, major*UNITS_PER_WORD);
	  rtx op1 = source;
	  emit_move_insn (op0, op1);
	}
      else
	{
	  machine_mode chunk_mode = kvx_get_chunk_mode (vector_mode);
	  rtx op0 = simplify_gen_subreg (chunk_mode, target, vector_mode, major*UNITS_PER_WORD);
	  rtx op1 = source;
	  rtx op2 = GEN_INT (width*8);
	  rtx op3 = GEN_INT (minor*8);
	  rtx insert = gen_rtx_UNSPEC (chunk_mode, gen_rtvec (4, op1, op2, op3, op0), UNSPEC_INSF);
	  emit_insn (gen_rtx_SET (op0, insert));
	}

      return;
    }

  gcc_unreachable ();
}

void
kvx_expand_vector_extract (rtx target, rtx source, rtx where)
{
  machine_mode vector_mode = GET_MODE (source);
  machine_mode inner_mode = GET_MODE_INNER (vector_mode);
  int width = GET_MODE_SIZE (inner_mode);

  if (CONST_INT_P (where))
    {
      int index = INTVAL (where);
      int major = (index*width) / UNITS_PER_WORD;
      int minor = (index*width) % UNITS_PER_WORD;

      if (GET_MODE_SIZE (inner_mode) == UNITS_PER_WORD)
	{
	  rtx op0 = target;
	  rtx op1 = simplify_gen_subreg(inner_mode, source, vector_mode, major*UNITS_PER_WORD);
	  emit_move_insn (op0, op1);
	}
      else
	{
	  machine_mode chunk_mode = kvx_get_chunk_mode (vector_mode);
	  rtx op0 = target;
	  rtx op1 = simplify_gen_subreg(chunk_mode, source, vector_mode, major*UNITS_PER_WORD);
	  rtx op2 = GEN_INT (width*8);
	  rtx op3 = GEN_INT (minor*8);
	  rtx extract = gen_rtx_UNSPEC (inner_mode, gen_rtvec (3, op1, op2, op3), UNSPEC_EXTFZ);
	  emit_insn (gen_rtx_SET (op0, extract));
	}

      return;
    }

  gcc_unreachable ();
}

/* Splat a value of mode smaller than a word into a word size vector chunk.
 * This is used both for initializing a vector from a scalar, and for the
 * vector arithmetic patterns that operate a vector with a scalar.  */
rtx
kvx_expand_chunk_splat (rtx target, rtx source, machine_mode inner_mode)
{
  HOST_WIDE_INT constant = 0;
  machine_mode chunk_mode = GET_MODE (target);
  unsigned inner_size = GET_MODE_SIZE (inner_mode);

  if (inner_size == UNITS_PER_WORD)
    return source;

  if (!REG_P (source) && !SUBREG_P (source))
    source = force_reg (inner_mode, source);

  switch (inner_size)
    {
    case 1:
      constant = 0x0101010101010101LL;
      break;
    case 2:
      constant = 0x0201020102010201LL;
      break;
    case 4:
      constant = 0x0804020108040201LL;
      break;
    default:
      gcc_unreachable ();
    }
  rtx op2 = force_reg (DImode, GEN_INT (constant));
  rtx op1 = gen_lowpart (inner_mode, source);
  rtx sbmm8 = gen_rtx_UNSPEC (chunk_mode, gen_rtvec (2, op1, op2), UNSPEC_SBMM8);
  emit_insn (gen_rtx_SET (target, sbmm8));
  return target;
}

/* Helper function for kvx_expand_vector_init () in case inner mode size < 64 bits.
 * The init source has been partioned into 64-bit chunks, which are inserted into
 * the corresponding 64-bit chunks of the target.
 */
static rtx
kvx_expand_chunk_insert(rtx target, rtx source, int index, machine_mode inner_mode)
{
  machine_mode chunk_mode = GET_MODE (target);
  unsigned inner_size = GET_MODE_SIZE (inner_mode);

  switch (inner_size)
    {
    case 4:
      {
	rtx op1 = copy_to_mode_reg (inner_mode, XVECEXP (source, 0, index++));
	rtx op2 = copy_to_mode_reg (inner_mode, XVECEXP (source, 0, index++));
	emit_insn (gen_rtx_SET (target, gen_rtx_VEC_CONCAT (chunk_mode, op1, op2)));
      }
      break;
    case 2:
      {
	rtx op1 = copy_to_mode_reg (inner_mode, XVECEXP (source, 0, index++));
	rtx op2 = copy_to_mode_reg (inner_mode, XVECEXP (source, 0, index++));
	rtx op3 = copy_to_mode_reg (inner_mode, XVECEXP (source, 0, index++));
	rtx op4 = copy_to_mode_reg (inner_mode, XVECEXP (source, 0, index++));
	rtx initx4a = gen_rtx_UNSPEC (chunk_mode, gen_rtvec (1, op1), UNSPEC_INITX4A);
	rtx initx4b = gen_rtx_UNSPEC (chunk_mode, gen_rtvec (2, op2, target), UNSPEC_INITX4B);
	rtx initx4c = gen_rtx_UNSPEC (chunk_mode, gen_rtvec (2, op3, target), UNSPEC_INITX4C);
	rtx initx4d = gen_rtx_UNSPEC (chunk_mode, gen_rtvec (2, op4, target), UNSPEC_INITX4D);
	emit_insn (gen_rtx_SET (target, initx4a));
	emit_insn (gen_rtx_SET (target, initx4b));
	emit_insn (gen_rtx_SET (target, initx4c));
	emit_insn (gen_rtx_SET (target, initx4d));
      }
      break;
    case 1:
      {
	rtx op1 = copy_to_mode_reg (inner_mode, XVECEXP (source, 0, index++));
	rtx op2 = copy_to_mode_reg (inner_mode, XVECEXP (source, 0, index++));
	rtx op3 = copy_to_mode_reg (inner_mode, XVECEXP (source, 0, index++));
	rtx op4 = copy_to_mode_reg (inner_mode, XVECEXP (source, 0, index++));
	rtx op5 = copy_to_mode_reg (inner_mode, XVECEXP (source, 0, index++));
	rtx op6 = copy_to_mode_reg (inner_mode, XVECEXP (source, 0, index++));
	rtx op7 = copy_to_mode_reg (inner_mode, XVECEXP (source, 0, index++));
	rtx op8 = copy_to_mode_reg (inner_mode, XVECEXP (source, 0, index++));
	rtx initx8a = gen_rtx_UNSPEC (chunk_mode, gen_rtvec (1, op1), UNSPEC_INITX8A);
	rtx initx8b = gen_rtx_UNSPEC (chunk_mode, gen_rtvec (2, op2, target), UNSPEC_INITX8B);
	rtx initx8c = gen_rtx_UNSPEC (chunk_mode, gen_rtvec (2, op3, target), UNSPEC_INITX8C);
	rtx initx8d = gen_rtx_UNSPEC (chunk_mode, gen_rtvec (2, op4, target), UNSPEC_INITX8D);
	rtx initx8e = gen_rtx_UNSPEC (chunk_mode, gen_rtvec (2, op5, target), UNSPEC_INITX8E);
	rtx initx8f = gen_rtx_UNSPEC (chunk_mode, gen_rtvec (2, op6, target), UNSPEC_INITX8F);
	rtx initx8g = gen_rtx_UNSPEC (chunk_mode, gen_rtvec (2, op7, target), UNSPEC_INITX8G);
	rtx initx8h = gen_rtx_UNSPEC (chunk_mode, gen_rtvec (2, op8, target), UNSPEC_INITX8H);
	emit_insn (gen_rtx_SET (target, initx8a));
	emit_insn (gen_rtx_SET (target, initx8b));
	emit_insn (gen_rtx_SET (target, initx8c));
	emit_insn (gen_rtx_SET (target, initx8d));
	emit_insn (gen_rtx_SET (target, initx8e));
	emit_insn (gen_rtx_SET (target, initx8f));
	emit_insn (gen_rtx_SET (target, initx8g));
	emit_insn (gen_rtx_SET (target, initx8h));
      }
      break;
    default:
      gcc_unreachable ();
    }
  return target;
}

/* Called by kvx_expand_vector_init(). */
void
kvx_expand_vector_duplicate (rtx target, rtx source)
{
  machine_mode vector_mode = GET_MODE (target);
  machine_mode inner_mode = GET_MODE_INNER (vector_mode);
  machine_mode chunk_mode = kvx_get_chunk_mode (vector_mode);

  rtx chunk = gen_reg_rtx (chunk_mode);
  chunk = kvx_expand_chunk_splat (chunk, source, inner_mode);

  unsigned vector_size = GET_MODE_SIZE (vector_mode);
  if (vector_size > UNITS_PER_WORD)
    {
      rtx splat = NULL_RTX;
      if (vector_size == 2*UNITS_PER_WORD)
	splat = gen_rtx_UNSPEC (vector_mode, gen_rtvec (1, chunk), UNSPEC_DUP128);
      else if (vector_size == 4*UNITS_PER_WORD)
	splat = gen_rtx_UNSPEC (vector_mode, gen_rtvec (1, chunk), UNSPEC_DUP256);
      else
	gcc_unreachable ();
      emit_insn (gen_rtx_SET (target, splat));
    }
  else
    emit_insn (gen_rtx_SET (target, chunk));

  return;
}

/* Called by the vec_init<mode> standard pattern. */
void
kvx_expand_vector_init (rtx target, rtx source)
{
  machine_mode vector_mode = GET_MODE (target);
  unsigned vector_size = GET_MODE_SIZE (vector_mode);
  machine_mode inner_mode = GET_MODE_INNER (vector_mode);
  unsigned inner_size = GET_MODE_SIZE (inner_mode);
  int nunits = GET_MODE_NUNITS (vector_mode);

  /* Special-case for the duplicate of a value. */
  bool duplicate = true;
  rtx x0 = XVECEXP (source, 0, 0);

  for (int i = 1; i < nunits; ++i)
    {
      rtx x = XVECEXP (source, 0, i);
      duplicate &= rtx_equal_p (x, x0);
    }
  if (duplicate)
    {
      kvx_expand_vector_duplicate (target, x0);
      return;
    }

  /* Inner mode size not smaller than word size, delegate to move pattern. */
  if (inner_size >= UNITS_PER_WORD)
    {
      for (int i = 0; i < nunits; i++)
	{
	  rtx op1 = XVECEXP (source, 0, i);
	  rtx op0 = simplify_gen_subreg (inner_mode, target, vector_mode, i*inner_size);
	  emit_move_insn (op0, op1);
	}
      return;
    }

  /* Process vector init chunk by chunk */
  int nwords = vector_size / UNITS_PER_WORD;
  int chunk_nunits = UNITS_PER_WORD / inner_size;
  machine_mode chunk_mode = kvx_get_chunk_mode (vector_mode);

  for (int i = 0; i < nwords; i++)
    {
      int nvars = 0;
      rtx splat = XVECEXP (source, 0, i * chunk_nunits);
      rtx op0 = simplify_gen_subreg (chunk_mode, target, vector_mode, i*UNITS_PER_WORD);

      /* Count the number of variable elements and compute splat. */
      for (int j = 0; j < chunk_nunits; j++)
	{
	  rtx x = XVECEXP (source, 0, i * chunk_nunits + j);
	  nvars += !(CONST_INT_P (x) || CONST_DOUBLE_P (x));
	  splat = rtx_equal_p (splat, x)? splat: 0;
	}

      /* No variable elements, delegate to move chunk const vector. */
      if (nvars == 0)
	{
	  rtvec v = rtvec_alloc (chunk_nunits);
	  for (int j = 0; j < chunk_nunits; j++)
	    RTVEC_ELT (v, j) = XVECEXP (source, 0, i * chunk_nunits + j);
	  rtx constants = gen_rtx_CONST_VECTOR (chunk_mode, v);
	  emit_move_insn (op0, constants);
	  continue;
	}

      /* Splat first element to all words in chunk. */
      if (splat)
	{
	  kvx_expand_chunk_splat (op0, splat, inner_mode);
	  continue;
	}

      /* Insert the variable lanes in chunk. */
      kvx_expand_chunk_insert (op0, source, i * chunk_nunits, inner_mode);
    }
}

/* Collect the SBMM8 immdiate values to implement a swizzle or a shuffle.
   As the largest vector type is 32 bytes and the word is 8 bytes, there
   are at most 4 words to operate in the destination vector. This corresponds
   to the [4] rows in values. A shuffle has up to two vector inputs,
   this corresponds to the [8] columns in values.  */
struct {
  unsigned char from[32];
  union {
    unsigned char bytes[UNITS_PER_WORD];
    unsigned long long dword;
  } values[8][4];
} kvx_expand_vec_perm;

void
kvx_expand_vec_perm_print (FILE *file, machine_mode vector_mode)
{
  int nwords = GET_MODE_SIZE (vector_mode) / UNITS_PER_WORD;
  machine_mode inner_mode = GET_MODE_INNER (vector_mode);
  int nunits = GET_MODE_NUNITS (vector_mode);
  int ibytes = GET_MODE_SIZE (inner_mode);

  for (int i = 0; i < nunits*ibytes; i++)
    fprintf(file, "[%2d]", kvx_expand_vec_perm.from[i]);
  fprintf(file, " from[]\n");

  for (int orig = 0; orig < 2*nwords; orig++) {
    for (int dest = 0; dest < nwords; dest++) {
      for (int lane = 0; lane < UNITS_PER_WORD; lane++)
	fprintf(file, "%03d ", kvx_expand_vec_perm.values[orig][dest].bytes[lane]);
    }
    fprintf(file, "orig[%d]\n", orig);
  }
  for (int dest = 0; dest < nwords; dest++) {
    fprintf(file, "            dest[%d]            |", dest);
  }
  fprintf(file, "\n");
}

/* Special case of kvx_expand_vec_perm_const_emit with a single MOVE. */
rtx
kvx_expand_vec_perm_const_emit_move (rtx target, rtx source1, rtx source2,
				     int dest, int orig)
{
  machine_mode vector_mode = GET_MODE (target);
  machine_mode chunk_mode = kvx_get_chunk_mode (vector_mode);
  int nwords = GET_MODE_SIZE (vector_mode) / UNITS_PER_WORD;
  rtx op0 = simplify_gen_subreg (chunk_mode, target, vector_mode, dest*UNITS_PER_WORD);
  rtx source = orig >= nwords? source2: source1;
  int offset = orig >= nwords? orig - nwords: orig;
  rtx op1 = simplify_gen_subreg (chunk_mode, source, vector_mode, offset*UNITS_PER_WORD);
  emit_move_insn (op0, op1);
  return op0;
}

/* Special case of kvx_expand_vec_perm_const_emit with INSF and MOVE.
   Logic based on the SBMM8 constants that have at most 1 bit set per byte. */
rtx
kvx_expand_vec_perm_const_emit_insf (rtx target, rtx source1, rtx source2,
				     int dest, int orig1, int orig2)
{
  machine_mode vector_mode = GET_MODE (target);
  int nwords = GET_MODE_SIZE (vector_mode) / UNITS_PER_WORD;
  HOST_WIDE_INT constant1 = kvx_expand_vec_perm.values[orig1][dest].dword;
  HOST_WIDE_INT constant2 = kvx_expand_vec_perm.values[orig2][dest].dword;
  HOST_WIDE_INT constant0 = 0x8040201008040201ULL, constanti = 0;
  int origm = -1, origi = -1;

  // The move constant is the one with a subset of bits of constant0.
  if ((constant1 & constant0) == constant1)
    {
      origm = orig1, origi = orig2;
      constanti = constant2;
    }
  else if ((constant2 & constant0) == constant2)
    {
      origm = orig2, origi = orig1;
      constanti = constant1;
    }

  if (!constanti)
    return NULL_RTX;

  // The insert constant must be constant0 shifted left and truncated.
  int shift = __builtin_ctzll (constanti);
  int count = __builtin_popcountll (constanti);
  HOST_WIDE_INT maski = (-1ULL >> __builtin_clzll (constanti)) & (constant0 << shift);

  // For speed we prevent the generation of extract as SBMM8 is faster.
  //if (optimize_insn_for_speed_p () && (shift & 7))
    //return NULL_RTX;

  if (maski == constanti && origm >= 0 && origi >= 0)
    {
      machine_mode inner_mode = GET_MODE_INNER (vector_mode);
      machine_mode chunk_mode = kvx_get_chunk_mode (vector_mode);
      rtx op0 = kvx_expand_vec_perm_const_emit_move (target, source1, source2,
						     dest, origm);
      rtx sourcei = origi >= nwords? source2: source1;
      int offseti = origi >= nwords? origi - nwords: origi;
      rtx op2 = GEN_INT (count*8);
      rtx op1 = NULL_RTX;

      // If shift is not a multiple of 8, extract is needed.
      if ((shift & 7))
	{
	  op1 = gen_reg_rtx (inner_mode);
	  rtx op3 = GEN_INT ((shift & 7)*8);
	  rtx opi = simplify_gen_subreg (chunk_mode, sourcei, vector_mode, offseti*UNITS_PER_WORD);
	  rtx extract = gen_rtx_UNSPEC (inner_mode, gen_rtvec (3, opi, op2, op3), UNSPEC_EXTFZ);
	  emit_insn (gen_rtx_SET (op1, extract));
	}
      else
	{
	  op1 = simplify_gen_subreg (inner_mode, sourcei, vector_mode, offseti*UNITS_PER_WORD);
	}

      rtx op3 = GEN_INT (shift & -8);
      rtx insert = gen_rtx_UNSPEC (chunk_mode, gen_rtvec (4, op1, op2, op3, op0), UNSPEC_INSF);
      emit_insn (gen_rtx_SET (op0, insert));
      return op0;
    }

  return NULL_RTX;
}

/* Implement swizzle (NULL source2) or shuffle based on kvx_expand_vec_perm.
   Before implementing a generic SBMM8-XORD scheme, we special-case the target
   words that can be computed using a MOVE alone or followed by EXTFZ, INSF. */
void
kvx_expand_vec_perm_const_emit (rtx target, rtx source1, rtx source2)
{
  machine_mode vector_mode = GET_MODE (target);
  int nwords = GET_MODE_SIZE (vector_mode) / UNITS_PER_WORD;
  int range = source2? 2*nwords: nwords;

  for (int dest = 0; dest < nwords; dest++)
    {
      HOST_WIDE_INT constant0 = 0x8040201008040201ULL;
      int orig0 = -1, orig1 = -1, orig2 = -1, nconst = 0;

      for (int orig = 0; orig < range; orig++)
	{
	  HOST_WIDE_INT constant = kvx_expand_vec_perm.values[orig][dest].dword;
	  if (constant)
	    {
	      if (constant == constant0)
		orig0 = orig;
	      else if (orig1 < 0)
		orig1 = orig;
	      else if (orig2 < 0)
		orig2 = orig;
	      nconst++;
	    }
	}

      if (orig0 >= 0
	  && kvx_expand_vec_perm_const_emit_move (target, source1, source2,
						  dest, orig0))
	continue;

      if (nconst == 2
	  && kvx_expand_vec_perm_const_emit_insf (target, source1, source2,
						  dest, orig1, orig2))
	continue;

      rtx op0 = simplify_gen_subreg (DImode, target, vector_mode, dest*UNITS_PER_WORD);
      rtx acc = force_reg (DImode, GEN_INT (0));
      for (int orig = 0; orig < range; orig++)
	{
	  HOST_WIDE_INT constant = kvx_expand_vec_perm.values[orig][dest].dword;
	  if (constant)
	    {
	      rtx tmp = gen_reg_rtx (DImode);
	      rtx source = force_reg (vector_mode, orig >= nwords ? source2 : source1);
	      int offset = orig >= nwords? orig - nwords: orig;
	      rtx op1 = simplify_gen_subreg (DImode, source, vector_mode, offset*UNITS_PER_WORD);
	      rtx op2 = force_reg (DImode, GEN_INT (constant));
	      emit_insn (gen_kvx_sbmm8 (tmp, op1, op2));
	      emit_insn (gen_xordi3 (acc, acc, tmp));
	    }
	}

      emit_move_insn (op0, acc);
    }
}


/* Called by the vec_perm_const<mode> standard pattern.
   First step identifies whether this is a swizzle (one source) or a shuffle.
   Second step fills the kvx_expand_vec_perm structure with SBMM8 immediates.
   Third step emits the permutation with (kvx_expand_vec_perm_const_emit).  */
bool
kvx_expand_vec_perm_const (rtx target, rtx source1, rtx source2, rtx selector)
{
  // used during testing
  if (!target)
    return true;

  machine_mode vector_mode = GET_MODE (target);
  machine_mode inner_mode = GET_MODE_INNER (vector_mode);
  int nwords = GET_MODE_SIZE (vector_mode) / UNITS_PER_WORD;
  int nunits = GET_MODE_NUNITS (vector_mode);
  int ibytes = GET_MODE_SIZE (inner_mode);
  unsigned idx_mask = 2*nunits - 1, which = 0;

  gcc_assert (nwords <= 4);
  gcc_assert (nunits*ibytes <= 32);
  memset (&kvx_expand_vec_perm, 0, sizeof (kvx_expand_vec_perm));

  // Fill the kvx_expand_vec_perm.from[] array, where each byte of the
  // destination records the index of the source byte in [source1,source2].
  for (int i = 0; i < nunits; i++)
    {
      rtx elt = XVECEXP (selector, 0, i);
      int index = INTVAL (elt) & idx_mask;
      which |= 1 << (index >= nunits);
      for (int j = 0; j < ibytes; j++)
	kvx_expand_vec_perm.from[i*ibytes + j] = index*ibytes + j;
    }

  // In case the two sources are equal, only index into the first source.
  if (rtx_equal_p (source1, source2) && which == 2)
    {
      for (int i = 0; i < nunits*ibytes; i++)
	kvx_expand_vec_perm.from[i] &= nunits*ibytes - 1;
      which = 1;
    }

  // Use the kvx_expand_vec_perm.from[] array to compute the SBMM8 constants.
  // There is one SBMM8 constant per origin word and per destination word.
  for (int i = 0; i < nwords; i++)
    {
      for (int j = 0; j < nunits*ibytes; j++)
	{
	  int k = kvx_expand_vec_perm.from[j];
	  int dest = j / UNITS_PER_WORD;
	  int lane = j % UNITS_PER_WORD;
	  int orig = k / UNITS_PER_WORD;
	  int shift = k % UNITS_PER_WORD;
	  gcc_assert (orig < 2*nwords && dest < nwords);
	  kvx_expand_vec_perm.values[orig][dest].bytes[lane] = 1 << shift;
	}
    }

#if 0
  kvx_expand_vec_perm_print (stderr, vector_mode);
#endif

  if (which == 1)
    kvx_expand_vec_perm_const_emit (target, source1, NULL_RTX);
  else
    kvx_expand_vec_perm_const_emit (target, source1, source2);

  return true;
}

static bool
kvx_vectorize_vec_perm_const (machine_mode vmode, rtx target, rtx op0,
			      rtx op1, const vec_perm_indices &sel)
{
  opt_machine_mode smode = mode_for_int_vector (vmode);
  rtx sel_rtx = vec_perm_indices_to_rtx (smode.else_void (), sel);
  kvx_expand_vec_perm_const(target, op0, op1, sel_rtx);
}

/* Helper to implement vector cross-element right shift. Two source chunks are
 * provided, with a NULL source2 in case the vacated bits must be cleared. */
rtx
kvx_expand_chunk_shift (rtx target, rtx source1, rtx source2, int shift)
{
  machine_mode mode = GET_MODE (target);
  gcc_assert ((unsigned)shift < 64U);
  if (shift == 0)
    emit_move_insn (target, source1);
  else
    {
      rtx op0 = simplify_gen_subreg (DImode, target, mode, 0);
      rtx op1 = simplify_gen_subreg (DImode, source1, mode, 0);
      if (source2 == NULL_RTX)
	{
	  emit_insn (gen_lshrdi3 (op0, op1, GEN_INT (shift)));
	}
      else
	{
	  rtx temp0 = gen_reg_rtx (DImode);
	  rtx temp1 = gen_reg_rtx (DImode);
	  rtx op2 = simplify_gen_subreg (DImode, source2, mode, 0);
	  emit_insn (gen_ashldi3 (temp1, op2, GEN_INT (64 - shift)));
	  emit_insn (gen_lshrdi3 (temp0, op1, GEN_INT (shift)));
	  emit_insn (gen_iordi3 (op0, temp0, temp1));
	}
    }
  return target;
}

/* Emit a barrier, that is appropriate for memory model MODEL, at the
   start of a sequence implementing an atomic operation. We always use
   a very conservative memory model since the KV3 has a relaxed memory
   consistency model, meaning that all loads and stores are scheduled
   out-of-order at different memory addresses. Only simple load/store
   operations are performed with more usual memory constraints (if
   MOVE is true). */

void
kvx_emit_pre_barrier (rtx model, bool move)
{
  const enum memmodel mm = memmodel_from_int (INTVAL (model));
  switch (mm & MEMMODEL_BASE_MASK) // treat sync operations as atomic ones
    {
    case MEMMODEL_RELAXED:
    case MEMMODEL_CONSUME:
    case MEMMODEL_ACQUIRE:
    case MEMMODEL_ACQ_REL:
      // no barrier is required for RELAXED, CONSUME, ACQUIRE, and
      // ACQ_REL memory models with MOVE operations (loads/stores). Be
      // conservative for any other cases, emit a fence.
      if (move)
	break;
    case MEMMODEL_RELEASE:
    case MEMMODEL_SEQ_CST:
      emit_insn (gen_mem_thread_fence (model));
      break;
    default:
      gcc_unreachable ();
    }
}

/* Emit a barrier, that is appropriate for memory model MODEL, at the
   end of a sequence implementing an atomic operation. See
   kvx_emit_pre_barrier () for MOVE. */

void
kvx_emit_post_barrier (rtx model, bool move)
{
  const enum memmodel mm = memmodel_from_int (INTVAL (model));
  switch (mm & MEMMODEL_BASE_MASK) // treat sync operations as atomic ones
    {
    case MEMMODEL_RELAXED:
    case MEMMODEL_RELEASE:
    case MEMMODEL_ACQ_REL:
      // no barrier is required for RELAXED, RELEASE, and ACQ_REL
      // memory models with MOVE operations (loads/stores). Be
      // conservative for any other cases, emit a fence.
      if (move)
	break;
    case MEMMODEL_ACQUIRE:
    case MEMMODEL_CONSUME:
    case MEMMODEL_SEQ_CST:
      emit_insn (gen_mem_thread_fence (model));
      break;
    default:
      gcc_unreachable ();
    }
}

/* Expand a compare and swap pattern. We do not support weak operation
   (operands[5], operands[6] and operands[7] can be ignored).  */

void
kvx_expand_compare_and_swap (rtx operands[])
{
  rtx mem, oldval, newval, currval;
  rtx cas_retry = gen_label_rtx ();
  rtx cas_return = gen_label_rtx ();
  rtx (*gen) (rtx, rtx, rtx);
  machine_mode mode = GET_MODE (operands[2]);

  gcc_assert ((mode == SImode || mode == DImode));

  mem = operands[2];
  oldval = operands[3];
  newval = operands[4];

  rtx tmp = gen_reg_rtx (TImode);
  rtx low = gen_lowpart (DImode, tmp);
  rtx high = gen_highpart (DImode, tmp);

  // We don't care of operands[6] and operands[7] (memory models to
  // use after the operation). We just need to ensure that memory is
  // consistent before the compare-and-swap.
  emit_insn (gen_mem_thread_fence (GEN_INT (MEMMODEL_SEQ_CST)));

  // Packing data to swap for acswap[wd] insns.
  emit_move_insn (gen_lowpart (mode, high), oldval);
  emit_label (cas_retry);
  emit_move_insn (gen_lowpart (mode, low), newval);

  emit_insn (mode == SImode ? gen_acswapw (tmp, mem) : gen_acswapd (tmp, mem));

  // If acswap succeeds (LOW is equal to 0x1), then return.
  emit_cmp_and_jump_insns (gen_lowpart (mode, low), const1_rtx, EQ, NULL_RTX,
			   mode, true, cas_return);

  // Else, the acswap has failed, reload MEM (atomically) to ensure
  // that the value wasn't updated to the expected one since.
  currval = gen_reg_rtx (mode);
  gen = mode == SImode ? gen_atomic_loadsi : gen_atomic_loaddi;
  emit_insn (
    gen (gen_lowpart (mode, currval), mem, GEN_INT (MEMMODEL_RELAXED)));

  // If the reloaded MEM is equal to the expected one (HIGH), retry
  // the acswap.
  emit_cmp_and_jump_insns (currval, gen_lowpart (mode, high), EQ, NULL_RTX,
			   mode, true, cas_retry);
  // Else, update HIGH with the current value of MEM, then return.
  emit_move_insn (gen_lowpart (mode, high), currval);

  // LOW contains the boolean to return.
  // HIGH contains the value present in memory before the operation.
  emit_label (cas_return);
  // operands[0] is an output operand which is set to true of false
  // based on whether the operation succeeded.
  emit_move_insn (operands[0], gen_lowpart (SImode, low));
  // operands[1] is an output operand which is set to the contents of
  // the memory before the operation was attempted.
  emit_move_insn (operands[1], gen_lowpart (mode, high));
}

/* Expand an atomic operation pattern (CODE). Only for SImode and
   DImode (CAS loop is too difficult to handle for HI, QI, and TI
   modes). Others modes will be expanded by libatomic if enabled
   anyway. MEM is the memory location where to perform the atomic
   operation with value in VAL. If AFTER is true then store the value
   from MEM into TARGET holds after the operation, if AFTER is false
   then store the value from MEM into TARGET holds before the
   operation. If TARGET is NULL_RTX then discard that value, else
   store the result to TARGET. */

void
kvx_expand_atomic_op (enum rtx_code code, rtx target, bool after, rtx mem,
		      rtx val, rtx model)
{
  machine_mode mode = GET_MODE (mem);
  rtx csloop = gen_label_rtx ();
  rtx tmp = gen_reg_rtx (TImode);
  rtx ret = gen_reg_rtx (mode);
  rtx new_mem_val = gen_lowpart (DImode, tmp);
  rtx curr_mem_val = gen_highpart (DImode, tmp);
  rtx (*gen) (rtx, rtx, rtx);
  rtx op_res, op_res_copy;

  if (target && after)
    op_res_copy = gen_reg_rtx (mode);

  gcc_assert ((mode == SImode || mode == DImode));

  kvx_emit_pre_barrier (model, false);

  emit_label (csloop); /* cas loop entry point */
  /* copy memory content to perform op on it (atomic uncached load) */
  gen = mode == SImode ? gen_atomic_loadsi : gen_atomic_loaddi;
  emit_insn (
    gen (gen_lowpart (mode, curr_mem_val), mem, GEN_INT (MEMMODEL_RELAXED)));

  /* Perform operation in a cas loop, we do not need to convert
  CURR_MEM_VAL, NEW_MEM_VAL (DImode) and VAL (SImode or
  DImode). expand_simple_binop () is smart enough to select the right
  insn depending on MODE. */
  switch (code)
    {
    case PLUS:
    case IOR:
    case XOR:
    case MINUS:
    case AND:
      op_res = expand_simple_binop (mode, code, curr_mem_val, val, new_mem_val,
				    1, OPTAB_LIB_WIDEN);
      break;
      case MULT: /* NAND */
      {
	rtx x = expand_simple_binop (mode, AND, curr_mem_val, val, NULL_RTX, 1,
				     OPTAB_LIB_WIDEN);
	op_res = expand_simple_unop (mode, NOT, x, new_mem_val, 1);
	break;
      }
    case SET:
      op_res = gen_reg_rtx (mode);
      emit_move_insn (op_res, val);
      break;
    default:
      gcc_unreachable ();
    }

  if (op_res != gen_lowpart (mode, new_mem_val))
    emit_move_insn (gen_lowpart (mode, new_mem_val), op_res);

  /* Save OP_RES when returning it (the result of the operation),
     because ACSWAP will erase it. */
  if (target && after)
    emit_move_insn (op_res_copy, op_res);

  /* Update memory with op result iff memory hasn't been modifyed
  since, i.e: if CURR_MEM_VAL == MEM; then update MEM with
  NEW_MEM_VAL; else try again */
  emit_insn (mode == SImode ? gen_acswapw (tmp, mem) : gen_acswapd (tmp, mem));
  /* ACSWAP insn returns 0x0 (fail) or 0x1 (success) in the low part
     of TMP:
     - if successful: MEM is updated, do not loop
     - if failing: MEM has changed, try again */
  emit_cmp_and_jump_insns (gen_lowpart (mode, new_mem_val), const1_rtx, NE,
			   NULL_RTX, mode, true, csloop);

  /* In addition to modifying MEM, return a value if needed */
  if (target)
    {
      ret = (after
	       /* returning op result */
	       ? op_res_copy
	       /* returning mem content before op */
	       : gen_lowpart (mode, curr_mem_val));
      emit_move_insn (target, ret);
    }

  kvx_emit_post_barrier (model, false);
}

/* Expand the atomic test-and-set on byte atomic operation using the
   acswapw insn. */

void
kvx_expand_atomic_test_and_set (rtx operands[])
{
  rtx mem = operands[1];   /* memory to be modified */
  rtx model = operands[2]; /* memory model */

  rtx retry = gen_label_rtx ();
  rtx fini = gen_label_rtx ();
  rtx pos = gen_reg_rtx (Pmode);
  rtx offset = gen_reg_rtx (Pmode);
  rtx memsi;
  rtx tmp = gen_reg_rtx (TImode);
  rtx val = gen_lowpart (SImode, (gen_highpart (DImode, tmp)));
  rtx newval = gen_lowpart (SImode, (gen_lowpart (DImode, tmp)));
  rtx byte = gen_reg_rtx (SImode);
  rtx mask = gen_reg_rtx (SImode);
  rtx (*gen3) (rtx, rtx, rtx);
  rtx (*gen2) (rtx, rtx);

  kvx_emit_pre_barrier (model, false);

  emit_move_insn (pos, XEXP (mem, 0)); /* copy MEM pointer */
  /* find the place of the byte to test-and-set within the memory
     word-aligned it belongs to (POS is 0, 1, 2, or 3) */
  gen3 = Pmode == SImode ? gen_andsi3 : gen_anddi3;
  emit_insn (gen3 (pos, pos, GEN_INT (0x3)));
  /* the address of word containing the byte is MEM+OFFSET, with
     OFFSET <- -POS */
  gen2 = Pmode == SImode ? gen_negsi2 : gen_negdi2;
  emit_insn (gen2 (offset, pos));
  /* if MEM already has an offset, update OFFSET */
  gen3 = Pmode == SImode ? gen_addsi3 : gen_adddi3;
  if (GET_CODE (XEXP (mem, 0)) == PLUS)
    emit_insn (gen3 (offset, offset, XEXP (XEXP (mem, 0), 1)));

  /* load the word containing the byte to test-and-set
    - if MEM is already of the form offset[addr]: load OFFSET[addr]
    - else: load OFFSET[MEM] */
  if (GET_CODE (XEXP (mem, 0)) == PLUS)
    memsi = gen_rtx_MEM (SImode,
			 gen_rtx_PLUS (Pmode, XEXP (XEXP (mem, 0), 0), offset));
  else
    memsi = gen_rtx_MEM (SImode, gen_rtx_PLUS (Pmode, XEXP (mem, 0), offset));

  /* POS = (POS*BITS_PER_UNIT) */
  gen3 = Pmode == SImode ? gen_mulsi3 : gen_muldi3;
  emit_insn (gen3 (pos, pos, GEN_INT (BITS_PER_UNIT)));

  emit_label (retry); /* cas loop entry point */
  emit_insn (gen_atomic_loadsi (val, memsi, GEN_INT (MEMMODEL_RELAXED)));

  /* keep only the byte to test-and-set: BYTE <- VAL >> POS & 0xFF */
  emit_insn (gen_lshrsi3 (byte, val, gen_lowpart (SImode, pos)));
  emit_insn (gen_andsi3 (byte, byte, GEN_INT (0xFF)));

  /* if BYTE is false, try a compare-and-swap with the byte set to
     TRUE, else return true (i.e. BYTE) because the lock is already
     acquired */
  emit_cmp_and_jump_insns (byte, const0_rtx, NE, NULL_RTX, SImode, true, fini);
  /* NEWVAL <- VAL | TRUE << (POS*BITS_PER_UNIT) */
  emit_move_insn (mask, const1_rtx);
  emit_insn (gen_ashlsi3 (mask, mask, gen_lowpart (SImode, pos)));
  emit_insn (gen_iorsi3 (newval, val, mask));
  emit_insn (gen_acswapw (tmp, memsi));

  /* ACSWAP insn returns 0x0 (fail) or 0x1 (success) in the low part of TMP:
     - if successful: MEM is updated, do not loop,
		      lock is acquired, return false (i.e. BYTE)
     - if failing: MEM has changed, try again */
  emit_cmp_and_jump_insns (newval, const1_rtx, NE, NULL_RTX, SImode, true,
			   retry);

  emit_label (fini);
  emit_move_insn (operands[0], gen_lowpart (QImode, byte));

  kvx_emit_post_barrier (model, false);
}

int
kv3_mau_lsu_double_port_bypass_p (rtx_insn *producer, rtx_insn *consumer)
{
  rtx produced = SET_DEST (single_set (producer));
  rtx consumed = PATTERN (consumer);

  if (GET_CODE (consumed) == PARALLEL)
    consumed = XVECEXP (consumed, 0, 0);
  consumed = SET_DEST (consumed);

  return reg_overlap_mentioned_p (produced, consumed);
}

static int kvx_sched2_max_uid;
static int kvx_sched2_prev_uid;
static short *kvx_sched2_insn_cycle;
static unsigned char *kvx_sched2_insn_flags;
#define KVX_SCHED2_INSN_HEAD 1
#define KVX_SCHED2_INSN_START 2
#define KVX_SCHED2_INSN_STOP 4
#define KVX_SCHED2_INSN_TAIL 8
#define KVX_SCHED2_INSN_STALL 16
static int kvx_sched2_verbose;

static void
kvx_dependencies_fprint (FILE *file, rtx_insn *insn)
{
  dep_t dep;
  sd_iterator_def sd_it;
  fprintf (file, "forward dependences(# %d)\n", INSN_UID (insn));
  FOR_EACH_DEP (insn, SD_LIST_FORW, sd_it, dep)
    {
      enum reg_note dep_type = DEP_TYPE (dep);
      const char *dtype = "<none>";
      if (dep_type == REG_DEP_TRUE)
	dtype = "true";
      if (dep_type == REG_DEP_ANTI)
	dtype = "anti";
      if (dep_type == REG_DEP_OUTPUT)
	dtype = "output";
      if (dep_type == REG_DEP_CONTROL)
	dtype = "control";
      fprintf (file, "\t%s -> (# %d)\n", dtype, INSN_UID (DEP_CON (dep)));
    }
  fprintf (file, "backward dependences(# %d)\n", INSN_UID (insn));
  FOR_EACH_DEP (insn, SD_LIST_BACK, sd_it, dep)
    {
      enum reg_note dep_type = DEP_TYPE (dep);
      const char *dtype = "<none>";
      if (dep_type == REG_DEP_TRUE)
	dtype = "true";
      if (dep_type == REG_DEP_ANTI)
	dtype = "anti";
      if (dep_type == REG_DEP_OUTPUT)
	dtype = "output";
      if (dep_type == REG_DEP_CONTROL)
	dtype = "control";
      fprintf (file, "\t%s <- (# %d)\n", dtype, INSN_UID (DEP_PRO (dep)));
    }
}

static int
kvx_sched_issue_rate (void)
{
  return 5;
}

static int
kvx_sched_variable_issue (FILE *file ATTRIBUTE_UNUSED,
			  int verbose ATTRIBUTE_UNUSED, rtx_insn *insn,
			  int more)
{
  rtx x = PATTERN (insn);
  if (GET_CODE (x) == CLOBBER || GET_CODE (x) == USE)
    return more;
  // Cannot issue further insns at the same cycle as JUMP or CALL.
  if (JUMP_P (insn) || CALL_P (insn))
    return 0;
  return more - 1;
}

static int
kvx_sched_adjust_cost (rtx_insn *insn, int dep_type, rtx_insn *dep_insn,
		       int cost, unsigned int dw ATTRIBUTE_UNUSED)
{
  if (dep_type == REG_DEP_TRUE)
    {
      // Use (set_of) instead of (reg_overlap_mentioned_p) to catch cases in
      // SCHED2 of producing a register pair and consuming a single register.
      if (JUMP_P (insn))
	// Reduce cost except for the dependence carrying the tested value.
	// Case of carrying is when DEP_INSN modifies a REG used by INSN.
	{
	  rtx x = PATTERN (insn);
	  if (GET_CODE (x) == PARALLEL)
	    x = XVECEXP (x, 0, 0);
	  if (GET_CODE (x) == SET)
	    {
	      x = SET_SRC (x);
	    if (GET_CODE (x) == IF_THEN_ELSE)
	      x = XEXP (XEXP (x, 0), 0);
	    if (GET_CODE (x) == ZERO_EXTRACT)
	      x = XEXP (x, 0);
	    if (!REG_P (x) || !set_of (x, dep_insn))
	      cost = 0;
	    }
	  else if (ANY_RETURN_P (x))
	    {
	      rtx y = PATTERN (dep_insn);
	      if (GET_CODE (y) == PARALLEL)
		y = XVECEXP (y, 0, 0);
	      if (GET_CODE (y) == SET)
		y = SET_DEST (y);
	      if (!REG_P (y) || REGNO (y) != KV3_RA_REGNO)
		cost = 0;
	    }
	}
      else if (CALL_P (insn))
	// Reduce cost except for the dependence carrying the call target.
	// Case of carrying is when DEP_INSN modifies a REG used by INSN.
	{
	  rtx x = PATTERN (insn);
	  if (GET_CODE (x) == PARALLEL)
	    x = XVECEXP (x, 0, 0);
	  if (GET_CODE (x) == SET)
	    x = SET_SRC (x);
	  if (GET_CODE (x) == CALL)
	    x = XEXP (XEXP (x, 0), 0);
	  if (!REG_P (x) || !set_of (x, dep_insn))
	    cost = 0;
	}
      else if (recog_memoized (dep_insn) >= 0)
	// If the producer is a MAU that sets HF inner mode, decrement cost.
	{
	  enum attr_type type = get_attr_type (dep_insn);
	  if (type >= TYPE_MAU && type < TYPE_BCU)
	    {
	      rtx x = SET_DEST (single_set (dep_insn));
	      machine_mode inner_mode = GET_MODE_INNER (GET_MODE (x));
	      if (inner_mode == HFmode)
		cost--;
	    }
	}
    }
  else if (dep_type == REG_DEP_ANTI)
    {
      cost = 0;
      if (JUMP_P (dep_insn) || CALL_P (dep_insn))
	// Consumer INSN must issue after a JUMP or CALL producer.
	{
	  cost = 1;
	}
      else if (GET_CODE (PATTERN (dep_insn)) == CLOBBER)
	// Delay consumer INSN of CLOBBER for non-zero number of clock cycles.
	// This corrects the rewriting of dependencies by chain_to_prev_insn().
	// Problem appears in cases the CLOBBER of an INSF is located after the
	// producer for the INSF. So we find this producer and apply its cost.
	{
	  cost = 1;
	  dep_t dep;
	  sd_iterator_def sd_it;
	  FOR_EACH_DEP (dep_insn, SD_LIST_BACK, sd_it, dep)
	    {
	      if (DEP_TYPE (dep) == REG_DEP_TRUE)
		{
		  rtx_insn *pro_insn = DEP_PRO (dep);
		  // FIXME GCC9: added 'true' arg here.
		  int pro_cost = insn_cost (pro_insn, true);
		  if (cost < pro_cost)
		    cost = pro_cost;
		}
	    }
	}
    }
  else if (dep_type == REG_DEP_OUTPUT)
    {
      cost = 1;
      if (JUMP_P (insn) || CALL_P (insn))
	// Consumer is JUMP or CALL, producer can issue at same clock cycle.
	{
	  cost = 0;
	}
    }

  return cost;
}

static int
kvx_sched_adjust_priority (rtx_insn *insn, int priority)
{
  rtx x = PATTERN (insn);
  // CLOBBER insns better remain first in scheduling group after SCHED1.
  if (GET_CODE (x) == CLOBBER)
    priority += 10;
  return priority;
}

static void
kvx_sched_dependencies_evaluation_hook (rtx_insn *head, rtx_insn *tail)
{
  rtx_insn *next_tail = NEXT_INSN (tail);
  for (rtx_insn *insn = head; insn != next_tail; insn = NEXT_INSN (insn))
    {
      // Place holder, do nothing for now.
    }
}

static void
kvx_sched_init (FILE *file ATTRIBUTE_UNUSED, int verbose ATTRIBUTE_UNUSED,
		int max_ready ATTRIBUTE_UNUSED)
{
  if (reload_completed)
    {
      if ((unsigned) kvx_sched2_prev_uid < kvx_sched2_max_uid)
	{
	  kvx_sched2_insn_flags[kvx_sched2_prev_uid]
	    |= KVX_SCHED2_INSN_STOP | KVX_SCHED2_INSN_TAIL;
	}
      kvx_sched2_prev_uid = -1;
    }
}

static void
kvx_sched_finish (FILE *file ATTRIBUTE_UNUSED, int verbose ATTRIBUTE_UNUSED)
{
  if (reload_completed)
    {
      if ((unsigned) kvx_sched2_prev_uid < kvx_sched2_max_uid)
	{
	  kvx_sched2_insn_flags[kvx_sched2_prev_uid]
	    |= KVX_SCHED2_INSN_STOP | KVX_SCHED2_INSN_TAIL;
	}
    }
}

static void
kvx_sched_init_global (FILE *file ATTRIBUTE_UNUSED,
		       int verbose ATTRIBUTE_UNUSED, int old_max_uid)
{
  scheduling = true;
  if (reload_completed)
    {
      /* Allocate here, deallocate in kvx_function_epilogue(). */
      kvx_sched2_max_uid = old_max_uid;
      kvx_sched2_prev_uid = -1;
      kvx_sched2_insn_cycle = XNEWVEC (short, kvx_sched2_max_uid);
      memset (kvx_sched2_insn_cycle, -1, sizeof (short) * kvx_sched2_max_uid);
      kvx_sched2_insn_flags = XCNEWVEC (unsigned char, kvx_sched2_max_uid);
      kvx_sched2_verbose = verbose;
    }
}

static void
kvx_sched_finish_global (FILE *file ATTRIBUTE_UNUSED,
			 int verbose ATTRIBUTE_UNUSED)
{
}

static int
kvx_sched_dfa_new_cycle (FILE *dump ATTRIBUTE_UNUSED,
			 int verbose ATTRIBUTE_UNUSED, rtx_insn *insn,
			 int last_clock ATTRIBUTE_UNUSED, int clock,
			 int *sort_p ATTRIBUTE_UNUSED)
{
  // Use this hook to record the cycle and flags of INSN in SCHED2.
  int uid = INSN_UID (insn);
  if ((unsigned) uid < kvx_sched2_max_uid && GET_CODE (PATTERN (insn)) != USE
      && GET_CODE (PATTERN (insn)) != CLOBBER)
    {
      int prev_uid = kvx_sched2_prev_uid;
      if (prev_uid < 0)
	{
	  // Head of the scheduling region, start a new bundle.
	  kvx_sched2_insn_flags[uid]
	    = KVX_SCHED2_INSN_HEAD | KVX_SCHED2_INSN_START;
	}
      else if (clock > kvx_sched2_insn_cycle[prev_uid])
	{
	  // Advanced clock, stop previous bundle and start a new one.
	  kvx_sched2_insn_flags[prev_uid] |= KVX_SCHED2_INSN_STOP;
	  kvx_sched2_insn_flags[uid] = KVX_SCHED2_INSN_START;
	}
      else if (kvx_sched2_insn_flags[prev_uid] & KVX_SCHED2_INSN_STOP)
	{
	  // Previous bundle was stopped for some reason, start a new one.
	  kvx_sched2_insn_flags[uid] |= KVX_SCHED2_INSN_START;
	}

      if (JUMP_P (insn) || CALL_P (insn))
	{
	  // JUMP or CALL, stop the current bundle regardless of clock.
	  kvx_sched2_insn_flags[uid] |= KVX_SCHED2_INSN_STOP;
	}

      kvx_sched2_insn_cycle[uid] = clock;
      kvx_sched2_prev_uid = uid;
    }
  return 0;
}

static void
kvx_sched_set_sched_flags (struct spec_info_def *spec_info)
{
  unsigned int *flags = &(current_sched_info->flags);
  // Speculative scheduling is enabled by non-zero spec_info->mask.
  spec_info->mask = 0;
}

// Always return true, as long-running instructions are fully pipelined.
static bool
kvx_sched_can_speculate_insn (rtx_insn *insn)
{
  return true;
}

static int
kvx_sched_sms_res_mii (struct ddg *g)
{
  int insn_count = 0;
  int tiny_count = 0;
  int lite_count = 0;
  int full_count = 0;
  int auxr_count = 0;
  int alu_count = 0;
  int lsu_count = 0;
  int mau_count = 0;
  int bcu_count = 0;
  int issue_rate = kvx_sched_issue_rate ();
  for (int i = 0; i < g->num_nodes; i++)
    {
      rtx_insn *insn = g->nodes[i].insn;
      if (NONDEBUG_INSN_P (insn))
	{
	  insn_count++;
	  // Keep the TYPE tests in sync with the order of the types.md file.
	  enum attr_type type = get_attr_type (insn);
	  if (type == TYPE_ALL)
	    {
	      insn_count += issue_rate;
	      lsu_count++, mau_count++;
	      bcu_count++;
	    }
	  else if (type >= TYPE_ALU_TINY && type < TYPE_LSU)
	    {
	      if (type < TYPE_ALU_TINY_X2)
		tiny_count++;
	      else if (type < TYPE_ALU_TINY_X4)
		tiny_count += 2;
	      else if (type < TYPE_ALU_LITE)
		tiny_count += 4;
	      else if (type < TYPE_ALU_LITE_X2)
		lite_count++;
	      else if (type < TYPE_ALU_FULL)
		lite_count += 2;
	      else
		full_count++;
	    }
	  else if (type >= TYPE_LSU && type < TYPE_MAU)
	    lsu_count++;
	    if (type >= TYPE_LSU_AUXR_STORE
		&& type < TYPE_LSU_CRRP_STORE)
	      auxr_count++;
	  else if (type >= TYPE_MAU && type < TYPE_BCU)
	    mau_count++;
	    if (type >= TYPE_MAU_AUXR)
	      auxr_count++;
	  else if (type >= TYPE_BCU && type < TYPE_TCA)
	    bcu_count++;
	}
    }
  int res_mii = (insn_count + issue_rate - 1) / issue_rate;
  if (res_mii < (tiny_count + 3)/4)
    res_mii = (tiny_count + 3)/4;
  if (res_mii < (lite_count + 1)/2)
    res_mii = (lite_count + 1)/2;
  if (res_mii < full_count)
    res_mii = full_count;
  if (res_mii < auxr_count)
    res_mii = auxr_count;
  if (res_mii < lsu_count)
    res_mii = lsu_count;
  if (res_mii < mau_count)
    res_mii = mau_count;
  if (res_mii < bcu_count)
    res_mii = bcu_count;
  return res_mii;
}

/* FIXME AUTO: This must be fixed for coolidge */
/* See T7749 */
static int
kvx_sched_reassociation_width (unsigned int opc, enum machine_mode mode)
{
  int res = 1;

  /* see tree.c:associative_tree_code () for possible values of opc. */

  switch (opc)
    {
    case BIT_IOR_EXPR:
    case BIT_AND_EXPR:
    case BIT_XOR_EXPR:
      if (mode == SImode || mode == HImode || mode == QImode || mode == DImode)
	res = 4;
      else if (mode == TImode)
	res = 2;
      break;
    case PLUS_EXPR:
    case MIN_EXPR:
    case MAX_EXPR:
      if (mode == SImode || mode == HImode || mode == QImode || mode == DImode)
	res = 4;
      break;
    case MULT_EXPR:
      break;
    }

  return res;
}

/* Test if X is of the form reg[reg] or .xs reg = reg[reg] or signed10bits[reg]
 */
bool
kvx_has_10bit_imm_or_register_p (rtx x)
{
  if (MEM_P (x))
    x = XEXP (x, 0);

  if (REG_P (x))
    return true;

  /*
   * ld reg = reg[reg]
   */
  if (GET_CODE (x) == PLUS && REG_P (XEXP (x, 0)) && REG_P (XEXP (x, 1)))
    return true;

  /*
   * ld.xs reg = reg[reg]
   */
  if (GET_CODE (x) == PLUS && GET_CODE (XEXP (x, 0)) == MULT
      && GET_CODE (XEXP (XEXP (x, 0), 1)) == CONST_INT
      && INTVAL (XEXP (XEXP (x, 0), 1)) > HOST_WIDE_INT_1)
    return true;

  return kvx_has_10bit_immediate_p (x);
}

bool
kvx_has_10bit_immediate_p (rtx x)
{
  if (MEM_P (x))
    x = XEXP (x, 0);

  if (GET_CODE (x) == PLUS && GET_CODE (XEXP (x, 1)) == CONST_INT
      && REG_P (XEXP (x, 0)))
    return IN_RANGE (INTVAL (XEXP (x, 1)), -512, 511);

  return false;
}

bool
kvx_has_37bit_immediate_p (rtx x)
{
  if (MEM_P (x))
    x = XEXP (x, 0);

  if (GET_CODE (x) == PLUS && GET_CODE (XEXP (x, 1)) == CONST_INT
      && REG_P (XEXP (x, 0)))
    return !IN_RANGE (INTVAL (XEXP (x, 1)), -512, 511)
	   && IN_RANGE (INTVAL (XEXP (x, 1)), -(1LL << 36), (1LL << 36) - 1);

  return false;
}

bool
kvx_has_64bit_immediate_p (rtx x)
{
  if (MEM_P (x))
    x = XEXP (x, 0);

  if (GET_CODE (x) == PLUS && GET_CODE (XEXP (x, 1)) == CONST_INT
      && REG_P (XEXP (x, 0)))
    return !IN_RANGE (INTVAL (XEXP (x, 1)), -(1LL << 36), (1LL << 36) - 1);

  if (GET_CODE (x) == PLUS && GET_CODE (XEXP (x, 1)) != CONST_INT
      && REG_P (XEXP (x, 0)))
    return true;

  return false;
}

/* Test whether the memory operand X should be accessed cached or
   uncached (bypass or preload) regarding it's name address space.
   If non-zero, the return value is the MEM_ADDR_SPACE. */
int
kvx_is_uncached_mem_op_p (rtx x)
{
  gcc_assert (MEM_P (x));
  if (!MEM_P (x))
    return false;

  /* __convert[_no_sync] addr space should not come here. */
  gcc_assert (MEM_ADDR_SPACE (x) < KVX_ADDR_SPACE_CONVERT);

  return MEM_ADDR_SPACE (x);
}

HOST_WIDE_INT
kvx_const_vector_value (rtx x, int slice)
{
  HOST_WIDE_INT value = 0;
  if (GET_CODE (x) == CONST_VECTOR)
    {
      machine_mode mode = GET_MODE (x);
      machine_mode inner_mode = GET_MODE_INNER (mode);
      int index = slice * (8 / GET_MODE_SIZE (inner_mode));
      if (inner_mode == QImode)
	{
	  HOST_WIDE_INT val_0 = INTVAL (CONST_VECTOR_ELT (x, index + 0));
	  HOST_WIDE_INT val_1 = INTVAL (CONST_VECTOR_ELT (x, index + 1));
	  HOST_WIDE_INT val_2 = INTVAL (CONST_VECTOR_ELT (x, index + 2));
	  HOST_WIDE_INT val_3 = INTVAL (CONST_VECTOR_ELT (x, index + 3));
	  HOST_WIDE_INT val_4 = INTVAL (CONST_VECTOR_ELT (x, index + 4));
	  HOST_WIDE_INT val_5 = INTVAL (CONST_VECTOR_ELT (x, index + 5));
	  HOST_WIDE_INT val_6 = INTVAL (CONST_VECTOR_ELT (x, index + 6));
	  HOST_WIDE_INT val_7 = INTVAL (CONST_VECTOR_ELT (x, index + 7));
	  value = (val_0 & 0xFF) | (val_1 & 0xFF) << 8 | (val_2 & 0xFF) << 16
		  | (val_3 & 0xFF) << 24 | (val_4 & 0xFF) << 32
		  | (val_5 & 0xFF) << 40 | (val_6 & 0xFF) << 48
		  | (val_7 & 0xFF) << 56;
	}
      else if (inner_mode == HImode)
	{
	  HOST_WIDE_INT val_0 = INTVAL (CONST_VECTOR_ELT (x, index + 0));
	  HOST_WIDE_INT val_1 = INTVAL (CONST_VECTOR_ELT (x, index + 1));
	  HOST_WIDE_INT val_2 = INTVAL (CONST_VECTOR_ELT (x, index + 2));
	  HOST_WIDE_INT val_3 = INTVAL (CONST_VECTOR_ELT (x, index + 3));
	  value = (val_0 & 0xFFFF) | (val_1 & 0xFFFF) << 16
		  | (val_2 & 0xFFFF) << 32 | (val_3 & 0xFFFF) << 48;
	}
      else if (inner_mode == SImode)
	{
	  HOST_WIDE_INT val_0 = INTVAL (CONST_VECTOR_ELT (x, index + 0));
	  HOST_WIDE_INT val_1 = INTVAL (CONST_VECTOR_ELT (x, index + 1));
	  value = (val_0 & 0xFFFFFFFF) | (val_1 & 0xFFFFFFFF) << 32;
	}
      else if (inner_mode == DImode)
	{
	  value = INTVAL (CONST_VECTOR_ELT (x, index + 0));
	}
      else if (inner_mode == HFmode)
	{
	  long val_0 = 0, val_1 = 0, val_2 = 0, val_3 = 0;
	  rtx elt_0 = CONST_VECTOR_ELT (x, index + 0);
	  rtx elt_1 = CONST_VECTOR_ELT (x, index + 1);
	  rtx elt_2 = CONST_VECTOR_ELT (x, index + 2);
	  rtx elt_3 = CONST_VECTOR_ELT (x, index + 3);
	  REAL_VALUE_TO_TARGET_SINGLE (*CONST_DOUBLE_REAL_VALUE (elt_0), val_0);
	  REAL_VALUE_TO_TARGET_SINGLE (*CONST_DOUBLE_REAL_VALUE (elt_1), val_1);
	  REAL_VALUE_TO_TARGET_SINGLE (*CONST_DOUBLE_REAL_VALUE (elt_2), val_2);
	  REAL_VALUE_TO_TARGET_SINGLE (*CONST_DOUBLE_REAL_VALUE (elt_3), val_3);
	  val_0 = kvx_float_to_half_as_int (val_0);
	  val_1 = kvx_float_to_half_as_int (val_1);
	  val_2 = kvx_float_to_half_as_int (val_2);
	  val_3 = kvx_float_to_half_as_int (val_3);
	  value = (val_0 & 0xFFFF) | (val_1 & 0xFFFF) << 16
		  | (val_2 & 0xFFFF) << 32 | (val_3 & 0xFFFF) << 48;
	}
      else if (inner_mode == SFmode)
	{
	  long val_0 = 0, val_1 = 0;
	  rtx elt_0 = CONST_VECTOR_ELT (x, index + 0);
	  rtx elt_1 = CONST_VECTOR_ELT (x, index + 1);
	  REAL_VALUE_TO_TARGET_SINGLE (*CONST_DOUBLE_REAL_VALUE (elt_0), val_0);
	  REAL_VALUE_TO_TARGET_SINGLE (*CONST_DOUBLE_REAL_VALUE (elt_1), val_1);
	  value = ((HOST_WIDE_INT) val_0 & 0xFFFFFFFF)
		  | ((HOST_WIDE_INT) val_1 & 0xFFFFFFFF) << 32;
	}
      else if (inner_mode == DFmode)
	{
	  long val[2] = {0, 0};
	  rtx elt_0 = CONST_VECTOR_ELT (x, index + 0);
	  REAL_VALUE_TO_TARGET_DOUBLE (*CONST_DOUBLE_REAL_VALUE (elt_0), val);
	  value = ((HOST_WIDE_INT) val[0] & 0xFFFFFFFF)
		  | ((HOST_WIDE_INT) val[1] & 0xFFFFFFFF) << 32;
	}
      else
	gcc_unreachable ();
      return value;
    }
  else
    gcc_unreachable ();
  return value;
}

bool
kvx_has_10bit_vector_const_p (rtx x)
{
  HOST_WIDE_INT value = kvx_const_vector_value (x, 0);
  return SIGNED_INT_FITS_N_BITS (value, 10);
}

bool
kvx_has_16bit_vector_const_p (rtx x)
{
  HOST_WIDE_INT value = kvx_const_vector_value (x, 0);
  return SIGNED_INT_FITS_N_BITS (value, 16);
}

bool
kvx_has_32bit_vector_const_p (rtx x)
{
  HOST_WIDE_INT value = kvx_const_vector_value (x, 0);
  return SIGNED_INT_FITS_N_BITS (value, 32);
}

bool
kvx_has_37bit_vector_const_p (rtx x)
{
  HOST_WIDE_INT value = kvx_const_vector_value (x, 0);
  return SIGNED_INT_FITS_N_BITS (value, 37);
}

bool
kvx_has_43bit_vector_const_p (rtx x)
{
  HOST_WIDE_INT value = kvx_const_vector_value (x, 0);
  return SIGNED_INT_FITS_N_BITS (value, 43);
}

bool
kvx_has_32x2bit_vector_const_p (rtx x)
{
  HOST_WIDE_INT value = kvx_const_vector_value (x, 0);
  // Need the dual immediate syntax to be fixed in assembler.
  // return (value&0xFFFFFFFF) == ((value>>32)&0xFFFFFFFF);
  return false;
}

/* Helper function for kvx_expand_load_multiple and
   kvx_expand_store_multiple */
static bool
kvx_expand_load_store_multiple (rtx operands[], bool is_load)
{
  int regno;
  int count;
  int i;

  const int reg_op_idx = is_load ? 0 : 1;
  const int mem_op_idx = is_load ? 1 : 0;

  count = INTVAL (operands[2]);
  regno = REGNO (operands[reg_op_idx]);

  if (GET_CODE (operands[2]) != CONST_INT
      || GET_MODE (operands[reg_op_idx]) != DImode || (count != 2 && count != 4)
      || ((count == 2) && (regno & 1)) || ((count == 4) && (regno & 3))
      || !MEM_P (operands[mem_op_idx]) || !REG_P (operands[reg_op_idx])
      || (TARGET_STRICT_ALIGN
	  && MEM_ALIGN (operands[mem_op_idx]) < (count * UNITS_PER_WORD))
      || MEM_VOLATILE_P (operands[mem_op_idx])
      || REGNO (operands[reg_op_idx]) > KV3_GPR_LAST_REGNO)
    return false;

  operands[3] = gen_rtx_PARALLEL (VOIDmode, rtvec_alloc (count));

  rtx base, offset;
  if (!kvx_split_mem (XEXP (operands[mem_op_idx], 0), &base, &offset, false))
    return false;

  if (!REG_P (base))
    base = force_reg (Pmode, base);

  /* Add a PLUS so that we have a simpler match in load multiple patterns */
  XEXP (operands[mem_op_idx], 0) = gen_rtx_PLUS (Pmode, base, offset);

  for (i = 0; i < count; i++)
    {
      rtx addr
	= adjust_address_nv (operands[mem_op_idx], DImode, i * UNITS_PER_WORD);

      /* Force a PLUS even for offset 0 so that we have a simpler
	 match in load multiple patterns */
      if (REG_P (XEXP (addr, 0)))
	XEXP (addr, 0) = gen_rtx_PLUS (Pmode, XEXP (addr, 0), const0_rtx);

      if (is_load)
	XVECEXP (operands[3], 0, i)
	  = gen_rtx_SET (gen_rtx_REG (DImode, regno + i), addr);
      else
	XVECEXP (operands[3], 0, i)
	  = gen_rtx_SET (addr, gen_rtx_REG (DImode, regno + i));
    }

  return true;
}

/* Expands a store multiple with operand 0 being the first destination
   address, operand 1 the first source register and operand 2 the
   number of consecutive stores to pack. */
bool
kvx_expand_store_multiple (rtx operands[])
{
  return kvx_expand_load_store_multiple (operands, false);
}

/* Expands a load multiple with operand 0 being the first destination
   register, operand 1 the first source address and operand 2 the
   number of consecutive loads to pack. */
bool
kvx_expand_load_multiple (rtx operands[])
{
  return kvx_expand_load_store_multiple (operands, true);
}

/*
 * When IS_LOAD is TRUE, returns TRUE if OP is a load multiple
 * operation and all mems are cached/uncached depending on
 * IS_UNCACHED.
 * When IS_LOAD is FALSE, returns TRUE if OP is a store multiple
 * operation.
 * Returns FALSE otherwise.
 */
static bool
kvx_load_store_multiple_operation_p (rtx op, bool is_uncached, bool is_load)
{
  int count = XVECLEN (op, 0);
  unsigned int dest_regno;
  int i;

  /* Perform a quick check so we don't blow up below.  */
  if (count != 2 && count != 4)
    return 0;

  for (i = 0; i < count; i++)
    {
      rtx set = XVECEXP (op, 0, i);
      if (GET_CODE (set) != SET)
	return false;

      rtx reg_part = is_load ? SET_DEST (set) : SET_SRC (set);
      rtx mem_part = is_load ? SET_SRC (set) : SET_DEST (set);

      if (!REG_P (reg_part) || !MEM_P (mem_part) || MEM_VOLATILE_P (mem_part))
	return false;

      if (is_load && is_uncached != !!kvx_is_uncached_mem_op_p (mem_part))
	return false;
    }

  rtx first_mem
    = is_load ? SET_SRC (XVECEXP (op, 0, 0)) : SET_DEST (XVECEXP (op, 0, 0));
  rtx first_reg
    = is_load ? SET_DEST (XVECEXP (op, 0, 0)) : SET_SRC (XVECEXP (op, 0, 0));

  if (TARGET_STRICT_ALIGN && MEM_ALIGN (first_mem) < (count * UNITS_PER_WORD))
    return false;

  dest_regno = REGNO (first_reg);

  /* register number must be correctly aligned */
  if (dest_regno < FIRST_PSEUDO_REGISTER && (dest_regno % count != 0))
    return false;

  HOST_WIDE_INT expected_offset = 0;
  rtx base;

  for (i = 0; i < count; i++)
    {
      rtx elt = XVECEXP (op, 0, i);
      rtx base_cur, offset_cur;
      rtx mem_elt = is_load ? SET_SRC (elt) : SET_DEST (elt);
      rtx reg_elt = is_load ? SET_DEST (elt) : SET_SRC (elt);

      if (!kvx_split_mem (XEXP (mem_elt, 0), &base_cur, &offset_cur, false))
	return false;

      if (i == 0)
	{
	  expected_offset = INTVAL (offset_cur);
	  base = base_cur;
	}
      else
	{
	  expected_offset += UNITS_PER_WORD;
	}

      if (GET_MODE (reg_elt) != DImode || REGNO (reg_elt) != dest_regno + i
	  || GET_MODE (mem_elt) != DImode || !rtx_equal_p (base_cur, base)
	  || expected_offset != INTVAL (offset_cur))

	return false;
    }

  return true;
}

/*
 * Returns TRUE if OP is a load multiple operation and all mems are
 * cached/uncached depending on IS_UNCACHED.
 */
bool
kvx_load_multiple_operation_p (rtx op, bool is_uncached)
{
  return kvx_load_store_multiple_operation_p (op, is_uncached, true);
}

/*
 * Returns TRUE if OP is a store multiple operation.
 */
bool
kvx_store_multiple_operation_p (rtx op)
{
  return kvx_load_store_multiple_operation_p (op, false, false);
}

/* Following funtions are used for bundling insn before ASM emission */

struct bundle_state
{
  /* Unique bundle state number to identify them in the debugging
     output */
  int unique_num;

  /* First insn in the bundle */
  rtx_insn *insn;

  /* Last insn in the bundle */
  rtx_insn *last_insn;

  /* Number of insn in the bundle */
  int insns_num;

  /* Registers being defined within the bundle */
  HARD_REG_SET reg_defs;

  /* All bundle states are in the following chain.  */
  struct bundle_state *allocated_states_chain;

  struct bundle_state *next;
  state_t dfa_state;
};

/* Bundles list for current function */
static struct bundle_state *cur_bundle_list;

/* The unique number of next bundle state.  */
static int bundle_states_num;

/* All allocated bundle states are in the following chain.  */
static struct bundle_state *allocated_bundle_states_chain;

/* All allocated but not used bundle states are in the following
   chain.  */
static struct bundle_state *free_bundle_state_chain;

struct bundle_regs
{
  int set_dest;
  rtx scanned_insn;
  HARD_REG_SET uses;
  HARD_REG_SET defs;
};

static void kvx_scan_insn_registers_wrap (rtx *x, void *data);

static int
kvx_scan_insn_registers_1 (rtx *x, void *data)
{
  struct bundle_regs *regs = (struct bundle_regs *) data;

  if (!*x)
    return 0;

  if (GET_CODE (*x) == USE && CALL_P (regs->scanned_insn))
    return -1;

  if (GET_CODE (*x) == SET)
    {
      regs->set_dest = 1;
      /* for_each_rtx (&SET_DEST (*x), kvx_scan_insn_registers_1, regs); */
      kvx_scan_insn_registers_wrap (&SET_DEST (*x), regs);
      regs->set_dest = 0;
      /* for_each_rtx (&SET_SRC (*x), kvx_scan_insn_registers_1, regs); */
      kvx_scan_insn_registers_wrap (&SET_SRC (*x), regs);
      return -1;
    }

  if (MEM_P (*x))
    {
      regs->set_dest = 0;
      /* for_each_rtx (&XEXP (*x, 0), kvx_scan_insn_registers_1, regs); */
      kvx_scan_insn_registers_wrap (&XEXP (*x, 0), regs);
      return -1;
    }

  if (GET_CODE (*x) == CLOBBER)
    {
      if (REG_P (XEXP (*x, 0)))
	SET_HARD_REG_BIT (regs->defs, REGNO (XEXP (*x, 0)));

      /* double/quadruple/octuple register */
      /* Also mark the implicitely defined registers */
      if (GET_MODE_SIZE (GET_MODE (*x)) > UNITS_PER_WORD)
	{
	  unsigned word;
	  for (word = 1; word < GET_MODE_SIZE (GET_MODE (*x)) / UNITS_PER_WORD;
	       word++)
	    {
	      SET_HARD_REG_BIT (regs->defs, REGNO (XEXP (*x, 0)) + word);
	    }
	}
      return -1;
    }

  if (GET_CODE (*x) == EXPR_LIST
      && (enum reg_note) GET_MODE (*x) != REG_DEP_TRUE)
    {
      return -1;
    }

  if (REG_P (*x))
    {
      /* Must be a real hard registers */
      gcc_assert (REGNO (*x) < KV3_MDS_REGISTERS);

      if (regs->set_dest)
	SET_HARD_REG_BIT (regs->defs, REGNO (*x));
      else
	SET_HARD_REG_BIT (regs->uses, REGNO (*x));

      if (GET_MODE_SIZE (GET_MODE (*x)) > UNITS_PER_WORD)
	{
	  unsigned word;
	  for (word = 1; word < GET_MODE_SIZE (GET_MODE (*x)) / UNITS_PER_WORD;
	       word++)
	    {
	      SET_HARD_REG_BIT (regs->set_dest ? regs->defs : regs->uses,
				REGNO (*x) + word);
	    }
	}
    }

  return 0;
}

static void
kvx_scan_insn_registers_wrap (rtx *x, void *data)
{
  subrtx_ptr_iterator::array_type array;
  FOR_EACH_SUBRTX_PTR (iter, array, x, ALL)
    {
      rtx *x = *iter;
      if (kvx_scan_insn_registers_1 (x, data) == -1)
	{
	  iter.skip_subrtxes ();
	}
    }
}

static void
kvx_scan_insn_registers (rtx insn, struct bundle_regs *regs)
{
  if (GET_CODE (insn) == CLOBBER || GET_CODE (insn) == USE || !INSN_P (insn))
    return;

  regs->set_dest = 0;
  regs->scanned_insn = insn;
  CLEAR_HARD_REG_SET (regs->uses);
  CLEAR_HARD_REG_SET (regs->defs);
  /* for_each_rtx (&insn, kvx_scan_insn_registers_1, regs); */
  kvx_scan_insn_registers_wrap (&insn, regs);
}

/* Skip over irrelevant NOTEs and such and look for the next insn we
   would consider bundling.  */
static rtx_insn *
next_insn_to_bundle (rtx_insn *r, rtx_insn *end)
{
  for (; r != end; r = NEXT_INSN (r))
    {
      if (NONDEBUG_INSN_P (r) && GET_CODE (PATTERN (r)) != USE
	  && GET_CODE (PATTERN (r)) != CLOBBER)
	return r;
    }

  return NULL;
}
/* Finish work with abstract data `bundle states'.  */

static void
finish_bundle_states (void)
{
  struct bundle_state *curr_state, *next_state;

  for (curr_state = allocated_bundle_states_chain; curr_state != NULL;
       curr_state = next_state)
    {
      next_state = curr_state->allocated_states_chain;
      free (curr_state->dfa_state);
      free (curr_state);
    }
}

/* Start work with abstract data `bundle states'.  */

static void
initiate_bundle_states (void)
{
  if (cur_bundle_list != NULL)
    finish_bundle_states ();

  bundle_states_num = 0;
  cur_bundle_list = NULL;
  free_bundle_state_chain = NULL;
  allocated_bundle_states_chain = NULL;
}

static struct bundle_state *
get_free_bundle_state (void)
{
  struct bundle_state *result;

  if (free_bundle_state_chain != NULL)
    {
      result = free_bundle_state_chain;
      free_bundle_state_chain = result->next;
    }
  else
    {
      result = XNEW (struct bundle_state);
      result->allocated_states_chain = allocated_bundle_states_chain;
      allocated_bundle_states_chain = result;
      result->dfa_state = xmalloc (dfa_state_size);
    }

  result->next = NULL;
  result->insn = NULL;
  result->last_insn = NULL;
  result->insns_num = 0;

  CLEAR_HARD_REG_SET (result->reg_defs);
  state_reset (result->dfa_state);

  result->unique_num = bundle_states_num;
  bundle_states_num++;

  return result;
}

/* The following function frees given bundle state.  */
static void free_bundle_state (struct bundle_state *state) ATTRIBUTE_UNUSED;

static void
free_bundle_state (struct bundle_state *state)
{
  state->next = free_bundle_state_chain;
  free_bundle_state_chain = state;
}

static int
kvx_insn_is_bundle_end_p (rtx insn)
{
  bundle_state *i;
  for (i = cur_bundle_list; i; i = i->next)
    {
      gcc_assert (i->insn != NULL_RTX);
      gcc_assert (i->last_insn != NULL_RTX);
      if (i->last_insn == insn)
	return 1;
    }
  return 0;
}

static void kvx_dump_bundles (void);

static void
kvx_gen_bundles (void)
{
  bundle_state *cur_bstate = NULL;

  dfa_start ();

  basic_block bb;
  FOR_EACH_BB_FN (bb, cfun)
    {
      rtx_insn *next, *prev;
      rtx_insn *end = NEXT_INSN (BB_END (bb));

      if (next_insn_to_bundle (BB_HEAD (bb), end) == NULL)
	continue;

      /* BB has no insn to bundle */
      if (next_insn_to_bundle (BB_HEAD (bb), end) == NULL_RTX)
	continue;

      if (cur_bstate == NULL)
	{
	  /* First bundle for function */
	  cur_bstate = get_free_bundle_state ();
	  cur_bundle_list = cur_bstate;
	}
      else if (cur_bstate->insns_num != 0) /* can reuse preallocated
					      bundle if previous BB
					      ended-up empty of
					      insns */
	{
	  cur_bstate->next = get_free_bundle_state ();
	  cur_bstate = cur_bstate->next;
	}

      prev = NULL;
      for (rtx_insn *insn = next_insn_to_bundle (BB_HEAD (bb), end); insn;
	   prev = insn, insn = next)
	{
	  next = next_insn_to_bundle (NEXT_INSN (insn), end);

	  struct bundle_regs cur_insn_regs = {0};

	  /* First, check if the insn fits in the bundle:
	   * - bundle size
	   * - exu resources
	   */
	  int can_issue = state_transition (cur_bstate->dfa_state, insn) < 0;

	  /* Scan insn for registers definitions and usage. */
	  kvx_scan_insn_registers (insn, &cur_insn_regs);

	  const int insn_raw = hard_reg_set_intersect_p (cur_insn_regs.uses,
							 cur_bstate->reg_defs);
	  const int insn_waw = hard_reg_set_intersect_p (cur_insn_regs.defs,
							 cur_bstate->reg_defs);
	  const int insn_jump = JUMP_P (insn) || CALL_P (insn);
	  const int next_is_label = (next != NULL) && LABEL_P (next);

	  /* Current insn can't be bundled with other insn, create a new one. */
	  if (!can_issue || insn_raw || insn_waw)
	    {
	      gcc_assert (cur_bstate->insn != NULL);

	      gcc_assert (prev != NULL);

	      cur_bstate->next = get_free_bundle_state ();
	      cur_bstate = cur_bstate->next;

	      state_transition (cur_bstate->dfa_state, insn);
	    }

	  if (cur_bstate->insn == NULL)
	    {
	      /* First insn in bundle */
	      cur_bstate->insn = insn;
	      cur_bstate->insns_num = 1;
	    }
	  else
	    {
	      cur_bstate->insns_num++;
	    }
	  cur_bstate->last_insn = insn;

	  IOR_HARD_REG_SET (cur_bstate->reg_defs, cur_insn_regs.defs);

	  /* Current insn is a jump, don't bundle following insns. */
	  /* If there is a label in the middle of a possible bundle,
	     split it */
	  if ((insn_jump && next != NULL) || next_is_label)
	    {
	      gcc_assert (cur_bstate->insn != NULL);
	      cur_bstate->next = get_free_bundle_state ();
	      cur_bstate = cur_bstate->next;
	    }
	}
    }

  dfa_finish ();
}

static void kvx_dump_bundles (void) ATTRIBUTE_UNUSED;

static void
kvx_dump_bundles (void)
{
  bundle_state *i;
  for (i = cur_bundle_list; i; i = i->next)
    {

      rtx_insn *binsn = i->insn;
      fprintf (stderr, "BUNDLE START %d\n", i->unique_num);

      if (i->insn == NULL_RTX)
	fprintf (stderr, " invalid bundle %d: insn is NULL\n", i->unique_num);

      if (i->last_insn == NULL_RTX)
	fprintf (stderr, " invalid bundle %d: last_insn is NULL\n",
		 i->unique_num);

      int bundle_stop = 0;
      do
	{
	  bundle_stop = (binsn == i->last_insn);
	  debug (binsn);
	  binsn = NEXT_INSN (binsn);
	}
      while (!bundle_stop);
      fprintf (stderr, "BUNDLE STOP %d\n", i->unique_num);
    }
}

/* Used during CFA note fixups.  When a FRAME_RELATED_P insn is being
   moved around a CFA-defining insn, its CFA NOTE must be changed
   accordingly to use correct register instead of OLD_BASE.
*/
static void
kvx_swap_fp_sp_in_note (rtx note, rtx old_base)
{
  XEXP (note, 0) = copy_rtx (XEXP (note, 0));
  rtx note_pat = XEXP (note, 0);

  rtx new_base_reg = (REGNO (old_base) == REGNO (hard_frame_pointer_rtx))
		       ? stack_pointer_rtx
		       : hard_frame_pointer_rtx;
  rtx mem_dest = SET_DEST (note_pat);
  struct kvx_frame_info *frame = &cfun->machine->frame;

  if (frame->hard_frame_pointer_offset == 0)
    {
      if (GET_CODE (XEXP (mem_dest, 0)) == PLUS)
	XEXP (XEXP (mem_dest, 0), 0) = new_base_reg;
      else
	XEXP (mem_dest, 0) = new_base_reg;
    }
  else
    {
      HOST_WIDE_INT new_offset
	= (new_base_reg == hard_frame_pointer_rtx)
				   ? -frame->hard_frame_pointer_offset
				   : frame->hard_frame_pointer_offset;
      if (GET_CODE (XEXP (mem_dest, 0)) == PLUS)
	{
	  rtx plus = XEXP (mem_dest, 0);
	  HOST_WIDE_INT old_offset = INTVAL (XEXP (plus, 1));
	  new_offset += old_offset;
	}
      XEXP (mem_dest, 0) = gen_rtx_PLUS (Pmode, new_base_reg,
					 gen_rtx_CONST_INT (Pmode, new_offset));
    }
}

static void
kvx_fix_debug_for_bundle_1 (rtx_insn *start_insn, rtx_insn *stop_insn)
{
  /* Start from the end so that NOTEs will be added in the correct order. */
  rtx_insn *binsn = stop_insn;
  bool last_do = false;
  do
    {
      last_do = (binsn == start_insn);
      if (INSN_P (binsn) && RTX_FRAME_RELATED_P (binsn))
	{
	  bool handled = false;
	  for (rtx note = REG_NOTES (binsn); note; note = XEXP (note, 1))
	    {
	      switch (REG_NOTE_KIND (note))
		{
		case REG_CFA_DEF_CFA:
		case REG_CFA_ADJUST_CFA:
		case REG_CFA_REGISTER:
		case REG_CFA_RESTORE:
		case REG_CFA_OFFSET:
		  handled = true;
		  if (binsn != stop_insn)
		    {
		      /* Move note to last insn in bundle */
		      add_shallow_copy_of_reg_note (stop_insn, note);
		      remove_note (binsn, note);
		    }
		  break;

		case REG_CFA_EXPRESSION:
		case REG_CFA_SET_VDRAP:
		case REG_CFA_WINDOW_SAVE:
		case REG_CFA_FLUSH_QUEUE:
		  error ("Unexpected CFA notes found.");
		  break;

		default:
		  break;
		}
	    }

	  if (!handled)
	    {
	      /* This *must* be some mem write emitted by builtin_save_regs,
	       * or a bug */
	      add_reg_note (stop_insn, REG_CFA_OFFSET,
			    copy_rtx (PATTERN (binsn)));
	    }

	  RTX_FRAME_RELATED_P (binsn) = 0;
	  RTX_FRAME_RELATED_P (stop_insn) = 1;
	}

      binsn = PREV_INSN (binsn);
    }
  while (!last_do);
}

static unsigned
kvx_fix_debug_for_bundle_2 (rtx_insn *start_insn, rtx_insn *stop_insn,
			    unsigned cur_cfa_reg)
{
  rtx_insn *binsn = start_insn;
  bool last_do = false;
  do
    {
      last_do = (binsn == stop_insn);
      if (INSN_P (binsn) && RTX_FRAME_RELATED_P (binsn))
	{
	  for (rtx note = REG_NOTES (binsn); note; note = XEXP (note, 1))
	    {

	      switch (REG_NOTE_KIND (note))
		{
		  case REG_CFA_DEF_CFA: {
		    rtx pat = XEXP (note, 0);

		    /* (PLUS ( CFA_REG, OFFSET)) */
		    gcc_assert (GET_CODE (pat) == PLUS);
		    cur_cfa_reg = REGNO (XEXP (pat, 0));
		    break;
		  }
		  /* We only need to fixup register spill */
		  case REG_CFA_OFFSET: {
		    rtx pat = XEXP (note, 0);

		    gcc_assert (GET_CODE (pat) == SET);

		    rtx mem_dest = SET_DEST (pat);
		    rtx base_reg;
		    if (GET_CODE (XEXP (mem_dest, 0)) == PLUS)
		      {
			base_reg = XEXP (XEXP (mem_dest, 0), 0);
		      }
		    else
		      {
			base_reg = XEXP (mem_dest, 0);
		      }
		    gcc_assert (REG_P (base_reg));

		    if (REGNO (base_reg) != cur_cfa_reg)
		      {
			/* Most likely an insn was moved around and
			   its note has not been modified accordingly.
			   We need to rebuild an offset based on
			   current CFA.
			*/
			kvx_swap_fp_sp_in_note (note, base_reg);
		      }
		  }
		  break;

		default:
		  break;
		}
	    }
	}
      binsn = NEXT_INSN (binsn);
    }
  while (!last_do);
  return cur_cfa_reg;
}

/* Visit all bundles and force all debug insns after the last insn in
   the bundle. */
static void
kvx_fix_debug_for_bundles (void)
{
  unsigned cur_cfa_reg = REGNO (stack_pointer_rtx);
  if (!TARGET_BUNDLING)
    {
      rtx_insn *start_insn = 0, *stop_insn = 0;
      basic_block bb;
      FOR_EACH_BB_FN (bb, cfun)
	{
	  rtx_insn *insn;
	  FOR_BB_INSNS (bb, insn)
	    {
	      if (NONDEBUG_INSN_P (insn) && GET_CODE (PATTERN (insn)) != USE
		  && GET_CODE (PATTERN (insn)) != CLOBBER)
		{
		  int uid = INSN_UID (insn);
		  if ((unsigned) uid >= kvx_sched2_max_uid
		      || kvx_sched2_insn_cycle[uid] < 0)
		    {
		      if (!start_insn)
			start_insn = stop_insn = insn;
		    }
		  else
		    {
		      unsigned flags = kvx_sched2_insn_flags[uid];
		      if (flags & KVX_SCHED2_INSN_HEAD)
			cur_cfa_reg = REGNO (stack_pointer_rtx);
		      if (flags & KVX_SCHED2_INSN_START)
			start_insn = insn;
		      if (flags & KVX_SCHED2_INSN_STOP)
			stop_insn = insn;
		    }
		  if (start_insn && stop_insn)
		    {
		      kvx_fix_debug_for_bundle_1 (start_insn, stop_insn);
		      cur_cfa_reg
			= kvx_fix_debug_for_bundle_2 (start_insn, stop_insn,
						      cur_cfa_reg);
		      start_insn = stop_insn = 0;
		    }
		}
	    }
	}
      if (start_insn || stop_insn)
	gcc_assert (!start_insn && !stop_insn);
    }
  else
    {
      for (bundle_state *i = cur_bundle_list; i; i = i->next)
	{
	  rtx_insn *start_insn = i->insn;
	  rtx_insn *stop_insn = i->last_insn;
	  kvx_fix_debug_for_bundle_1 (start_insn, stop_insn);
	  cur_cfa_reg
	    = kvx_fix_debug_for_bundle_2 (start_insn, stop_insn, cur_cfa_reg);
	}
    }
}

/* Adjust for the stall effects of AUXR RAW on issue cycle. */
static void
kvx_sched2_insn_issue (rtx_insn *insn, rtx *opvec, int noperands)
{
  int uid = INSN_UID (insn);

  static struct
  {
    int delay;
    short write[KV3_MDS_REGISTERS];
  } scoreboard;
  if (kvx_sched2_insn_flags[uid] & KVX_SCHED2_INSN_HEAD)
    {
      scoreboard.delay = 0;
      memset (scoreboard.write, -1, sizeof (scoreboard.write));
    }

  if (NONDEBUG_INSN_P (insn))
    {
      int stall = 0;
      int cycle = kvx_sched2_insn_cycle[uid] + scoreboard.delay;
      // Keep TYPE tests in sync with the order of the types.md file.
      enum attr_type type = get_attr_type (insn);
      if (type >= TYPE_MAU_AUXR && type <= TYPE_MAU_AUXR_FPU && noperands > 3
	  && REG_P (opvec[3]))
	{
	  int regno = REGNO (opvec[3]);
	  int regno_quad = (regno & -4);
	  machine_mode mode = GET_MODE (opvec[3]);
	  unsigned mode_size = GET_MODE_SIZE (mode);
	  if (mode_size <= UNITS_PER_WORD)
	    {
	      for (int i = 0; i < 4; i += 2)
		{
		  int j = (regno + i) & 3;
		  int write = scoreboard.write[regno_quad + j];
		  int delta = write - cycle;
		  if (stall < delta)
		    stall = delta;
		}
	    }
	  else if (mode_size >= 2 * UNITS_PER_WORD)
	    {
	      for (int i = 0; i < 4; i++)
		{
		  int write = scoreboard.write[regno_quad + i];
		  int delta = write - cycle;
		  if (stall < delta)
		    stall = delta;
		}
	    }
	}
      if (type >= TYPE_MAU && type < TYPE_BCU && noperands > 0
	  && REG_P (opvec[0]))
	{
	  int regno = REGNO (opvec[0]);
	  machine_mode mode = GET_MODE (opvec[0]);
	  int cost = FLOAT_MODE_P (mode) ? 4 : (INTEGRAL_MODE_P (mode) ? 3 : 1);
	  int i = hard_regno_nregs (regno, mode);
	  while (--i >= 0)
	    {
	      scoreboard.write[regno + i] = cycle + cost + stall;
	    }
	}

      if (stall)
	kvx_sched2_insn_flags[uid] |= KVX_SCHED2_INSN_STALL;
      kvx_sched2_insn_cycle[uid] = cycle + stall;
      scoreboard.delay += stall;
    }
}

static void
kvx_asm_final_postscan_insn (FILE *file, rtx_insn *insn,
			     rtx *opvec ATTRIBUTE_UNUSED,
			     int noperands ATTRIBUTE_UNUSED)
{
  if (!TARGET_BUNDLING && kvx_sched2_insn_cycle)
    {
      int uid = INSN_UID (insn);
      if ((unsigned) uid >= kvx_sched2_max_uid
	  || kvx_sched2_insn_cycle[uid] < 0)
	{
	  if (TARGET_SCHED2_DATES)
	    fprintf (file, "\t;;\t# (unscheduled)\n");
	  else
	    fprintf (file, "\t;;\n");
	  return;
	}
      kvx_sched2_insn_issue (insn, opvec, noperands);
      if (kvx_sched2_insn_flags[uid] & KVX_SCHED2_INSN_STOP)
	{
	  if (TARGET_SCHED2_DATES)
	    {
	      if (recog_memoized (insn) != CODE_FOR_doloop_end_si
		  && recog_memoized (insn) != CODE_FOR_doloop_end_di)
		{
		  const char *stalled = "";
		  if (kvx_sched2_insn_flags[uid] & KVX_SCHED2_INSN_STALL)
		    stalled = "(stalled)";
		  int cycle = kvx_sched2_insn_cycle[uid];
		  fprintf (file, "\t;;\t# (end cycle %d)%s\n", cycle, stalled);
		}
	    }
	  else
	    fprintf (file, "\t;;\n");
	  return;
	}
    }
  if (!TARGET_BUNDLING && !kvx_sched2_insn_cycle)
    {
      fprintf (file, "\t;;\n");
      return;
    }
  if (!scheduling || kvx_insn_is_bundle_end_p (insn))
    {
      fprintf (file, "\t;;\n");
      return;
    }
}

static int
kvx_type_all_cost (int nunits, int penalty)
{
  return COSTS_N_INSNS (6 * nunits + penalty);
}

static int
kvx_type_tiny_cost (int nunits, int penalty)
{
  return COSTS_N_INSNS (1 * nunits + penalty);
}

static int
kvx_type_lite_cost (int nunits, int penalty)
{
  return COSTS_N_INSNS (2 * nunits + penalty);
}

static int
kvx_type_full_cost (int nunits, int penalty)
{
  return COSTS_N_INSNS (4 * nunits + penalty);
}

static int
kvx_type_lsu_cost (int nunits, int penalty)
{
  return COSTS_N_INSNS (4 * nunits + penalty);
}

static int
kvx_type_mau_cost (int nunits, int penalty)
{
  return COSTS_N_INSNS (4 * nunits + penalty);
}

static int
kvx_type_bcu_cost (int nunits, int penalty)
{
  return COSTS_N_INSNS (4 * nunits + penalty);
}

static int
kvx_type_tca_cost (int nunits, int penalty)
{
  return COSTS_N_INSNS (4 * nunits + penalty);
}

/* Compute a (partial) cost for rtx X.  Return true if the complete
   cost has been computed, and false if subexpressions should be
   scanned.  In either case, *TOTAL contains the cost result.
   The initial value of *TOTAL is the default value computed by
   (rtx_cost).  It may be left unmodified.  OUTER_CODE contains the
   code of the superexpression of x.
   Used by instruction selection and subreg splitting, can be approximate.  */
static bool
kvx_rtx_costs (rtx x, machine_mode mode, int outer_code,
	       int opno ATTRIBUTE_UNUSED, int *total, bool speed)
{
  bool float_mode_p = FLOAT_MODE_P (mode);
  int nwords = (GET_MODE_SIZE (mode) + UNITS_PER_WORD - 1) / UNITS_PER_WORD;
  int latency = 1;

  if (DUMP_COSTS)
    {
      fprintf (stderr, "kvx_rtx_costs(mode=%s, code=%s, speed=%d)\n",
	       GET_MODE_NAME (mode), GET_RTX_NAME (outer_code), speed);
      debug_rtx (x);
    }

  switch (GET_CODE (x))
    {
    // RTX_CONST_OBJ:
    case CONST_INT:
      // Assume 10-bit immediates are always available.
      if (INTVAL (x) >= -512 && INTVAL (x) <= 511)
	*total = COSTS_N_INSNS (0);
      else if (INTVAL (x) >= -32768 && INTVAL (x) <= 32767)
	*total = COSTS_N_INSNS (1);
      else
	*total = COSTS_N_INSNS (2);
      goto return_true;

    case CONST_WIDE_INT:
    case CONST_DOUBLE:
    case CONST_VECTOR:
    case CONST:
    case LABEL_REF:
    case SYMBOL_REF:
      *total = COSTS_N_INSNS (2);
      goto return_true;

    // RTX_OBJ:
    case REG:
    case SCRATCH:
      break;

    case MEM:
      latency = 3;
      *total = kvx_type_lsu_cost (1, (latency - 1) * speed);
      goto return_false;

    // RTX_COMPARE:
    // RTX_COMM_COMPARE:
    case GE:
    case GT:
    case LE:
    case LT:
    case GEU:
    case GTU:
    case LEU:
    case LTU:
    case UNGE:
    case UNGT:
    case UNLE:
    case UNLT:
    case NE:
    case EQ:
    case UNORDERED:
    case ORDERED:
    case UNEQ:
    case LTGT:
      latency = 2;
      *total = float_mode_p
		 ? kvx_type_lite_cost (nwords, (latency - 1) * speed)
		 : kvx_type_tiny_cost (nwords, (latency - 1) * speed);
      goto return_false;

    // RTX_UNARY:
    case NEG:
    case NOT:
      *total = kvx_type_tiny_cost (nwords, 0);
      goto return_false;

    case SIGN_EXTEND:
    case ZERO_EXTEND:
      if (MEM_P (XEXP (x, 0)))
	*total = 0;
      else
	*total = kvx_type_tiny_cost (nwords, 0);
      goto return_false;

    case TRUNCATE:
    case FLOAT_EXTEND:
    case FLOAT_TRUNCATE:
    case FLOAT:
    case UNSIGNED_FLOAT:
    case ABS:
    case SQRT:
    case BSWAP:
    case FFS:
    case CLRSB:
    case CLZ:
    case CTZ:
    case POPCOUNT:
    case PARITY:
    case VEC_DUPLICATE:
    case SS_NEG:
    case US_NEG:
    case SS_ABS:
    case SS_TRUNCATE:
    case US_TRUNCATE:
      *total = float_mode_p ? kvx_type_lite_cost (nwords, 0)
			    : kvx_type_tiny_cost (nwords, 0);
      goto return_false;

    // RTX_COMM_ARITH:
    // RTX_BIN_ARITH:
    case PLUS:
    case MINUS:
      latency = 2 + float_mode_p * 2;
      *total = float_mode_p ? kvx_type_mau_cost (nwords, (latency - 1) * speed)
			    : kvx_type_tiny_cost (nwords, 0);
      goto return_false;

    case MULT:
    case SS_MULT:
    case US_MULT:
      latency = 2 + float_mode_p * 2;
      *total = kvx_type_mau_cost (nwords, (latency - 1) * speed);
      goto return_false;

    case AND:
    case IOR:
    case XOR:
    case SMIN:
    case SMAX:
    case UMIN:
    case UMAX:
    case SS_PLUS:
    case US_PLUS:
      *total = float_mode_p ? kvx_type_lite_cost (nwords, 0)
			    : kvx_type_tiny_cost (nwords, 0);
      goto return_false;

    case COMPARE:
      *total = kvx_type_tiny_cost (nwords, 0);
      goto return_false;

    case DIV:
    case SS_DIV:
    case US_DIV:
      if (CONST_INT_P (XEXP (x, 1))
	  && __builtin_popcount (INTVAL (XEXP (x, 1))) == 1)
	{
	  // Integer divide by a power of 2.
	  *total = kvx_type_tiny_cost (nwords, 0);
	  goto return_true;
	}

    case MOD:
    case UDIV:
    case UMOD:
      *total = kvx_type_all_cost (4, 0);
      goto return_true;

    case ASHIFT:
    case ROTATE:
    case ASHIFTRT:
    case LSHIFTRT:
    case ROTATERT:
      *total = kvx_type_tiny_cost (nwords, 0);
      goto return_false;

    case VEC_SELECT:
    case VEC_CONCAT:
    case VEC_SERIES:
    case SS_MINUS:
    case SS_ASHIFT:
    case US_ASHIFT:
    case US_MINUS:
      *total = kvx_type_lite_cost (nwords, 0);
      goto return_false;

    // RTX_TERNARY:
    case IF_THEN_ELSE:
    case VEC_MERGE:
      break;

    case FMA:
      latency = 2 + float_mode_p * 2;
      *total = kvx_type_mau_cost (nwords, (latency - 1) * speed);
      goto return_false;

    // RTX_BITFIELD_OPS:
    case SIGN_EXTRACT:
    case ZERO_EXTRACT:
      goto return_false;

    // RTX_EXTRA:
    case SET:
      goto return_false;

    case UNSPEC:
      switch (XINT (x, 1))
	{
	case UNSPEC_SRS32:
	case UNSPEC_SRS64:
	case UNSPEC_SRS128:
	case UNSPEC_SRS256:
	  *total = kvx_type_tiny_cost (nwords, 0);
	  goto return_false;
	default:
	  *total = kvx_type_lite_cost (nwords, 0);
	  break;
	}
      goto return_false;

    case UNSPEC_VOLATILE:
      *total = kvx_type_all_cost (nwords, 0);
      goto return_true;

    default:
      break;
    }

return_false:
  if (DUMP_COSTS)
    fprintf (stderr, "\tcost=%d (inner)\n\n", *total);
  return false;

return_true:
  if (DUMP_COSTS)
    fprintf (stderr, "\tcost=%d (leaf)\n\n", *total);
  return true;
}

/* Compute the cost of an addressing mode that contains X.  */
static int
kvx_address_cost (rtx x, machine_mode mode ATTRIBUTE_UNUSED,
		  addr_space_t space ATTRIBUTE_UNUSED,
		  bool speed ATTRIBUTE_UNUSED)
{
  int cost = kvx_type_tiny_cost (1, 0);

  // Case of .xs reg[reg] addressing mode.
  if (GET_CODE (x) == PLUS && GET_CODE (XEXP (x, 0)) == MULT
      && GET_CODE (XEXP (XEXP (x, 0), 1)) == CONST_INT
      && INTVAL (XEXP (XEXP (x, 0), 1)) > HOST_WIDE_INT_1)
    cost = 1;

  // Case of reg[reg] addressing mode.
  else if (GET_CODE (x) == PLUS && REG_P (XEXP (x, 0)) && REG_P (XEXP (x, 1)))
    cost = 2;

  // Case of const[reg] addressing mode.
  else if (GET_CODE (x) == PLUS && REG_P (XEXP (x, 0)))
    cost = 3;

  // Case of [reg] addressing mode.
  else if (REG_P (x))
    cost = 4;

  if (DUMP_COSTS)
    {
      fprintf (stderr, "kvx_address_cost(mode=%s, space=%d, speed=%d)\n",
	       GET_MODE_NAME (mode), space, speed);
      debug_rtx (x);
      fprintf (stderr, "\tcost=%d\n\n", cost);
    }

  return cost;
}

/* Describes the relative cost of RTL instructions.
   Used by instruction combining, better than kvx_rtx_costs (PATTERN (insn)).
   /!\ Synchronize with the types.md type and latencies.  */
static int
kvx_insn_cost (rtx_insn *insn, bool speed)
{
  if (recog_memoized (insn) < 0)
    {
      if (DUMP_COSTS)
	{
	  fprintf (stderr, "kvx_insn_cost(uid=%d, speed=%d)\n", INSN_UID (insn),
		   speed);
	  debug_rtx (PATTERN (insn));
	  fprintf (stderr, "\tcost=0 (not memoized)\n\n");
	}
      return 0;
    }

  enum attr_type type = get_attr_type (insn);
  int cost = get_attr_length (insn) - 4;
  gcc_assert (cost >= 0);

  if (!speed)
    {
      cost = get_attr_length (insn);
    }
  else if (type == TYPE_ALL)
    {
      cost += kvx_type_all_cost (1, 0);
    }
  else if (type >= TYPE_ALU_TINY && type < TYPE_ALU_LITE)
    {
      int nunits = 1;
      if (type >= TYPE_ALU_TINY_X2 && type <= TYPE_ALU_TINY_X2_Y)
	nunits = 2;
      if (type >= TYPE_ALU_TINY_X4 && type <= TYPE_ALU_TINY_X4_X)
	nunits = 4;
      cost += kvx_type_tiny_cost (nunits, 0);
    }
  else if (type >= TYPE_ALU_LITE && type < TYPE_ALU_FULL)
    {
      int nunits = 1;
      if (type >= TYPE_ALU_LITE_X2 && type <= TYPE_ALU_LITE_X2_X)
	nunits = 2;
      cost += kvx_type_lite_cost (nunits, 0);
    }
  else if (type >= TYPE_ALU_FULL && type < TYPE_LSU)
    {
      int penalty = (type == TYPE_ALU_FULL_COPRO) * (15 - 1);
      cost += kvx_type_full_cost (1, penalty);
    }
  else if (type >= TYPE_LSU && type < TYPE_MAU)
    {
      int penalty = 0;
      if (type >= TYPE_LSU_AUXW_LOAD && type <= TYPE_LSU_AUXW_LOAD_Y)
	penalty = (3 - 1);
      if ((type >= TYPE_LSU_AUXW_LOAD_UNCACHED
	   && type <= TYPE_LSU_LOAD_UNCACHED_Y)
	  || (type >= TYPE_LSU_AUXW_ATOMIC
	      && type <= TYPE_LSU_AUXR_AUXW_ATOMIC_Y))
	penalty = (24 - 1);
      cost += kvx_type_lsu_cost (1, penalty);
    }
  else if (type >= TYPE_MAU && type < TYPE_BCU)
    {
      int penalty = (2 - 1);
      if (type == TYPE_MAU_FPU || type == TYPE_MAU_AUXR_FPU)
	penalty = (4 - 1); // FIXME (3 - 1) in case of FP16.
      cost += kvx_type_mau_cost (1, penalty);
    }
  else if (type >= TYPE_MAU && type < TYPE_BCU)
    {
      cost += kvx_type_bcu_cost (1, 0);
    }
  else if (type >= TYPE_BCU && type < TYPE_TCA)
    {
      cost += kvx_type_tca_cost (1, 3);
    }

  if (DUMP_COSTS)
    {
      fprintf (stderr, "kvx_insn_cost(uid=%d, speed=%d)\n", INSN_UID (insn),
	       speed);
      debug_rtx (PATTERN (insn));
      fprintf (stderr, "\tcost=%d\n\n", cost);
    }

  return cost;
}

/* Used by register allocation.  */
static int
kvx_register_move_cost (machine_mode mode, reg_class_t from ATTRIBUTE_UNUSED,
			reg_class_t to ATTRIBUTE_UNUSED)
{
  int n_copyd = (GET_MODE_SIZE (mode) + UNITS_PER_WORD - 1) / UNITS_PER_WORD;
  // Default MOVE cost is 2 per word.
  int cost = n_copyd * 2;

  if (DUMP_COSTS)
    {
      fprintf (stderr, "kvx_register_move_cost(mode=%s, from=%s, to=%s)\n",
	       GET_MODE_NAME (mode), reg_class_names[from],
	       reg_class_names[to]);
      fprintf (stderr, "\tcost=%d\n\n", cost);
    }

  return cost;
}

/* Used by register allocation.  */
static int
kvx_memory_move_cost (machine_mode mode, reg_class_t rclass ATTRIBUTE_UNUSED,
		      bool in)
{
  // In-cache laod altency is 3 cycles.
  int penalty = in ? (3 - 1) : 0;
  int cost = kvx_type_lsu_cost (1, penalty);

  if (DUMP_COSTS)
    {
      fprintf (stderr, "kvx_memory_move_cost(mode=%s, rclass=%s, in=%d)\n",
	       GET_MODE_NAME (mode), reg_class_names[rclass], in);
      fprintf (stderr, "\tcost=%d\n\n", cost);
    }

  return cost;
}

static bool
kvx_function_ok_for_sibcall (tree decl, tree exp ATTRIBUTE_UNUSED)
{
  /* Sometimes GCC allocates a call_used_register to hold the sibcall
     destination... This of course  won't work because we can't restore that
     register to the right value and do the call (In fact we could by bundling
     the igoto and the restore together).
     FIXME: I think we can avoid this by defining sibcall and
     sibcall_value expanders that will use scratch registers
     instead of any GPR. */

  if (!decl)
    return false;

  /* Do not tail-call to farcall, there are cases where our prologue
   * overwrite the target register
   */
  tree attrs = TYPE_ATTRIBUTES (TREE_TYPE (decl));
  if (KVX_FARCALL || lookup_attribute ("farcall", attrs))
    return false;

  /* Do not tail-call calls to weak symbol
   * Same reason as for farcall
   */
  if (DECL_WEAK (decl))
    {
      return false;
    }

  return true;
}

static bool
kvx_legitimate_constant_p (enum machine_mode mode ATTRIBUTE_UNUSED, rtx x)
{
  if (kvx_has_tls_reference (x))
    return false;

  if (kvx_has_unspec_reference (x))
    {
      if (GET_CODE (x) == CONST)
	x = XEXP (x, 0);

      if (GET_CODE (x) == UNSPEC)
	return true;

      if (GET_CODE (x) == PLUS || GET_CODE (x) == MINUS)
	return GET_CODE (XEXP (x, 0)) == UNSPEC && CONST_INT_P (XEXP (x, 1));

      return false;
    }

  return true;
}

static rtx
kvx_legitimize_address (rtx x, rtx oldx ATTRIBUTE_UNUSED,
			enum machine_mode mode)
{
  if (kvx_has_tls_reference (x))
    return kvx_legitimize_tls_reference (x);
  else if (GET_CODE (x) == PLUS
	   && (GET_CODE (XEXP (x, 0)) == MULT
	       || GET_CODE (XEXP (x, 0)) == ZERO_EXTEND))
    {
      rtx reg = gen_reg_rtx (Pmode);
      rtx cst = XEXP (x, 1);

      XEXP (x, 1) = reg;
      if (kvx_legitimate_address_p (mode, x, false))
	{
	  emit_move_insn (reg, cst);
	  return copy_rtx (x);
	}
      else
	{
	  XEXP (x, 1) = cst;
	  return x;
	}
    }
  return x;
}

/* Implements TARGET_ADDR_SPACE_POINTER_MODE.  */
static scalar_int_mode
kvx_addr_space_pointer_mode (addr_space_t address_space ATTRIBUTE_UNUSED)
{
  return ptr_mode;
}

/* Implements TARGET_ADDR_SPACE_ADDRESS_MODE.  */
static scalar_int_mode
kvx_addr_space_address_mode (addr_space_t address_space ATTRIBUTE_UNUSED)
{
  return Pmode;
}

/* Implements TARGET_ADDR_SPACE_LEGITIMATE_ADDRESS_P.  */
static bool
kvx_addr_space_legitimate_address_p (machine_mode mode, rtx exp, bool strict,
				     addr_space_t as ATTRIBUTE_UNUSED)
{
  switch (as)
    {
    default:
      gcc_unreachable ();

    case ADDR_SPACE_GENERIC:
    case KVX_ADDR_SPACE_BYPASS:
    case KVX_ADDR_SPACE_PRELOAD:
      return kvx_legitimate_address_p (mode, exp, strict);

    case KVX_ADDR_SPACE_CONVERT:
      return false;
    }
}

/* Implements TARGET_ADDR_SPACE_LEGITIMIZE_ADDRESS.  */
static rtx
kvx_addr_space_legitimize_address (rtx x, rtx oldx, machine_mode mode,
				   addr_space_t as)
{
  if (as == KVX_ADDR_SPACE_CONVERT)
    error ("__convert should be used only in explicit pointer casting");

  return kvx_legitimize_address (x, oldx, mode);
}

/* Implements TARGET_ADDR_SPACE_SUBSET_P.  */
static bool
kvx_addr_space_subset_p (addr_space_t subset ATTRIBUTE_UNUSED,
			 addr_space_t superset ATTRIBUTE_UNUSED)
{
  // Address spaces (GENERIC or __UNCACHED) refer to the same space
  return true;
}

/* Implements TARGET_ADDR_SPACE_CONVERT.  */
static rtx
kvx_addr_space_convert (rtx op, tree from_type, tree to_type ATTRIBUTE_UNUSED)
{
  if (KVX_WARN_ADDRESS_SPACE_CONVERSION
      && TYPE_ADDR_SPACE (TREE_TYPE (from_type)) != KVX_ADDR_SPACE_CONVERT
      && TYPE_ADDR_SPACE (TREE_TYPE (to_type)) != KVX_ADDR_SPACE_CONVERT)
    {

      warning (0,
	       TYPE_ADDR_SPACE (TREE_TYPE (from_type)) > ADDR_SPACE_GENERIC
		 ? "Implicit conversion from uncached pointer to cached one"
		 : "Implicit conversion from cached pointer to uncached one");
      inform (input_location,
	      "Use (__convert <type> *) to acknowledge this conversion");
    }
  return op;
}

static void
kvx_function_prologue (FILE *file ATTRIBUTE_UNUSED)
{
  dfa_start ();
}

static void
kvx_function_epilogue (FILE *file ATTRIBUTE_UNUSED)
{
  kvx_sched2_max_uid = 0;
  kvx_sched2_prev_uid = -1;
  XDELETEVEC (kvx_sched2_insn_cycle);
  XDELETEVEC (kvx_sched2_insn_flags);
  kvx_sched2_insn_cycle = 0;
  kvx_sched2_insn_flags = 0;
  dfa_finish ();
}

/* NULL if INSN insn is valid within a low-overhead loop.
   Otherwise return why doloop cannot be applied.  */

static const char *
kvx_invalid_within_doloop (const rtx_insn *insn)
{
  if (CALL_P (insn))
    return "Function call in the loop.";

  if (JUMP_TABLE_DATA_P (insn))
    return "Computed branch in the loop.";

  if (!INSN_P (insn))
    return NULL;

  rtx body = PATTERN (insn);
  rtx asm_ops = extract_asm_operands (body);

  if (asm_ops && GET_CODE (body) == PARALLEL)
    {
      int i, regno, nparallel = XVECLEN (body, 0);

      for (i = 0; i < nparallel; i++)
	{
	  rtx clobber = XVECEXP (body, 0, i);
	  if (GET_CODE (clobber) == CLOBBER && REG_P (XEXP (clobber, 0))
	      && (regno = REGNO (XEXP (clobber, 0)))
	      && (regno == KV3_LC_REGNO || regno == KV3_LS_REGNO
		  || regno == KV3_LE_REGNO))
	    return "HW Loop register clobbered by asm.";
	}
    }

  return NULL;
}

/* A callback for the hw-doloop pass.  Called when a candidate doloop turns out
   not to be optimizable. The doloop_end pattern must be split into a decrement
   of the loop counter and looping branch if not zero, assuming without reload.
   In case of loop counter reload the doloop_end pattern was already split.  */

static void
hwloop_fail (hwloop_info loop)
{
  if (recog_memoized (loop->loop_end) != CODE_FOR_doloop_end_si
      && recog_memoized (loop->loop_end) != CODE_FOR_doloop_end_di)
    return;

  rtx (*gen_add) (rtx, rtx, rtx);
  rtx (*gen_cbranch) (rtx, rtx, rtx, rtx);
  machine_mode mode = GET_MODE (loop->iter_reg);
  gen_add = (mode == SImode) ? gen_addsi3 : gen_adddi3;
  gen_cbranch = (mode == SImode) ? gen_cbranchsi4 : gen_cbranchdi4;

  rtx decr = gen_add (loop->iter_reg, loop->iter_reg, constm1_rtx);
  emit_insn_before (decr, loop->loop_end);

  rtx test = gen_rtx_NE (VOIDmode, NULL_RTX, NULL_RTX);
  rtx cbranch
    = gen_cbranch (test, loop->iter_reg, const0_rtx, loop->start_label);
  rtx_insn *jump_insn = emit_jump_insn_before (cbranch, loop->loop_end);

  JUMP_LABEL (jump_insn) = loop->start_label;
  LABEL_NUSES (loop->start_label)++;

  delete_insn (loop->loop_end);
}

/* A callback for the hw-doloop pass.  This function examines INSN; if
   it is a doloop_end pattern we recognize, return the reg rtx for the
   loop counter.  Otherwise, return NULL_RTX.  */

static rtx
hwloop_pattern_reg (rtx_insn *insn)
{
  if (!JUMP_P (insn)
      || (recog_memoized (insn) != CODE_FOR_doloop_end_si
	  && recog_memoized (insn) != CODE_FOR_doloop_end_di))
    return NULL_RTX;

  rtx reg = SET_DEST (XVECEXP (PATTERN (insn), 0, 1));
  if (!REG_P (reg))
    return NULL_RTX;

  return reg;
}

static bool
hwloop_optimize (hwloop_info loop)
{
  int i;
  edge entry_edge;
  rtx iter_reg;
  rtx_insn *insn;
  rtx_insn *seq, *entry_after;

  if (loop->jumps_within)
    {
      if (dump_file)
	fprintf (dump_file, ";; loop %d jumps within\n", loop->loop_no);
      return false;
    }

  if (loop->jumps_outof)
    {
      if (dump_file)
	fprintf (dump_file, ";; loop %d has early exit\n", loop->loop_no);
      return false;
    }

  if (!loop->incoming_dest)
    {
      if (dump_file)
	fprintf (dump_file, ";; loop %d has more than one entry\n",
		 loop->loop_no);
      return false;
    }

  if (loop->incoming_dest != loop->head)
    {
      if (dump_file)
	fprintf (dump_file, ";; loop %d is not entered from head\n",
		 loop->loop_no);
      return false;
    }

  if (loop->blocks.length () > 1)
    {
      if (dump_file)
	fprintf (dump_file, ";; loop %d has more than one basic block\n",
		 loop->loop_no);
      return false;
    }

  if (loop->iter_reg_used || loop->iter_reg_used_outside)
    {
      if (dump_file)
	fprintf (dump_file, ";; loop %d uses iterator register\n",
		 loop->loop_no);
      return false;
    }

  /* Check if start_label appears before doloop_end.  */
  insn = loop->start_label;
  while (insn && insn != loop->loop_end)
    insn = NEXT_INSN (insn);

  if (!insn)
    {
      if (dump_file)
	fprintf (dump_file, ";; loop %d start_label not before loop_end\n",
		 loop->loop_no);
      return false;
    }

  /* Get the loop iteration register.  */
  iter_reg = loop->iter_reg;

  gcc_assert (REG_P (iter_reg));

  entry_edge = NULL;

  FOR_EACH_VEC_SAFE_ELT (loop->incoming, i, entry_edge)
    if (entry_edge->flags & EDGE_FALLTHRU)
      break;

  if (entry_edge == NULL)
    return false;

  loop->end_label = block_label (loop->successor);

  start_sequence ();
  insn = emit_insn (gen_kvx_loopdo (loop->iter_reg, loop->end_label));
  seq = get_insns ();

  /* Place the zero_cost_loop_start instruction before the loop.  */
  basic_block entry_bb = entry_edge->src;
  if (!single_succ_p (entry_bb) || vec_safe_length (loop->incoming) > 1)
    {
      basic_block new_bb;
      edge e;
      edge_iterator ei;

      emit_insn_before (seq, BB_HEAD (loop->head));
      seq = emit_label_before (gen_label_rtx (), seq);
      new_bb = create_basic_block (seq, insn, entry_bb);
      FOR_EACH_EDGE (e, ei, loop->incoming)
	{
	  if (!(e->flags & EDGE_FALLTHRU))
	    redirect_edge_and_branch_force (e, new_bb);
	  else
	    redirect_edge_succ (e, new_bb);
	}

      make_edge (new_bb, loop->head, 0);
    }
  else if (entry_bb != ENTRY_BLOCK_PTR_FOR_FN (cfun))
    {
      entry_after = BB_END (entry_bb);
      emit_insn_after (seq, entry_after);
    }
  else
    {
      // Loop is at the very beginning of function
      insert_insn_on_edge (seq,
			   single_succ_edge (ENTRY_BLOCK_PTR_FOR_FN (cfun)));
      commit_one_edge_insertion (
	single_succ_edge (ENTRY_BLOCK_PTR_FOR_FN (cfun)));
    }

  end_sequence ();

  return true;
}

static struct hw_doloop_hooks kvx_doloop_hooks
  = {hwloop_pattern_reg, hwloop_optimize, hwloop_fail};

/* Implement the TARGET_MACHINE_DEPENDENT_REORG pass.  */

static void
kvx_reorg (void)
{
  compute_bb_for_insn ();

  /* If optimizing, we'll have split before scheduling.  */
  if (optimize == 0)
    split_all_insns ();

  /* Doloop optimization. */
  if (optimize)
    reorg_loops (true, &kvx_doloop_hooks);

  df_analyze ();

  if (optimize && flag_schedule_insns_after_reload)
    {
      timevar_push (TV_SCHED2);

      if (flag_selective_scheduling2 && !maybe_skip_selective_scheduling ())
	run_selective_scheduling ();
      else
	schedule_ebbs ();

      timevar_pop (TV_SCHED2);
    }

  if (scheduling && !TARGET_BUNDLING)
    {
      kvx_fix_debug_for_bundles ();
    }

  /* Do it even if ! TARGET_BUNDLING because it also takes care of
   cleaning previous data */
  initiate_bundle_states ();

  if (scheduling && TARGET_BUNDLING)
    {
      kvx_gen_bundles ();
      kvx_fix_debug_for_bundles ();
    }

  /* This is needed. Else final pass will crash on debug_insn-s */
  if (flag_var_tracking)
    {
      compute_bb_for_insn ();
      timevar_push (TV_VAR_TRACKING);
      variable_tracking_main ();
      timevar_pop (TV_VAR_TRACKING);
      free_bb_for_insn ();
    }

  df_finish_pass (false);
}

static bool
kvx_handle_fixed_reg_option (const char *arg)
{
  const char *dash;
  int first_reg = -1, last_reg = -1, i;

  if (*arg++ != '=')
    return false;

  dash = strchr (arg, '-');

  for (i = 0; i < FIRST_PSEUDO_REGISTER; ++i)
    if (strncmp (reg_names[i], arg, dash - arg) == 0)
      {
	first_reg = i;
	break;
      }

  if (first_reg < 0)
    {
      error ("Unknown register %s passed to -ffixed-reg.", arg);
      return false;
    }

  if (dash)
    {
      for (i = 0; i < FIRST_PSEUDO_REGISTER; ++i)
	if (strcmp (reg_names[i], dash + 1) == 0)
	  {
	    last_reg = i;
	    break;
	  }
      if (last_reg < 0)
	{
	  error ("Unknown register %s passed to -ffixed-reg.", dash + 1);
	  return false;
	}
    }
  else
    {
      last_reg = first_reg;
    }

  if (first_reg > last_reg)
    {
      error ("Invalid range passed to -ffixed-reg.");
      return false;
    }

  for (i = first_reg; i <= last_reg; ++i)
    {
      fix_register (reg_names[i], 1, 1);
    }

  return true;
}

/* Implement TARGET_OPTION_OVERRIDE.  */

static void
kvx_option_override (void)
{
  unsigned int i;
  cl_deferred_option *opt;
  vec<cl_deferred_option> *v = (vec<cl_deferred_option> *) kvx_deferred_options;

  if (v)
    FOR_EACH_VEC_ELT (*v, i, opt)
      {
	switch (opt->opt_index)
	  {
	  case OPT_ffixed_reg:
	    kvx_handle_fixed_reg_option (opt->arg);
	    break;
	  default:
	    gcc_unreachable ();
	  }
      }

  kvx_arch_schedule = ARCH_COOLIDGE;
}

/* Recognize machine-specific patterns that may appear within
   constants.  Used for PIC-specific UNSPECs.
   Previously a macro. */
static bool
kvx_output_addr_const_extra (FILE *fp, rtx x)
{
  if (GET_CODE (x) == UNSPEC)
    {
      int unspec_code = XINT ((x), 1);
      switch (unspec_code)
	{
	case UNSPEC_PIC:
	  /* GLOBAL_OFFSET_TABLE or local symbols, no suffix.  */
	  output_addr_const ((fp), XVECEXP ((x), 0, 0));
	  return true;

	case UNSPEC_GOT:
	  fputs ("@got", (fp));
	  fputs ("(", (fp));
	  output_addr_const ((fp), XVECEXP ((x), 0, 0));
	  fputs (")", (fp));
	  return true;

	case UNSPEC_PCREL:
	  fputs ("@pcrel(", (fp));
	  output_addr_const ((fp), XVECEXP ((x), 0, 0));
	  fputs (")", (fp));
	  return true;

	case UNSPEC_GOTOFF:
	  fputs ("@gotoff", (fp));
	  fputs ("(", (fp));
	  output_addr_const ((fp), XVECEXP ((x), 0, 0));
	  fputs (")", (fp));
	  return true;

	case UNSPEC_TLS_GD:
	case UNSPEC_TLS_LD:
	case UNSPEC_TLS_DTPOFF:
	case UNSPEC_TLS_LE:
	case UNSPEC_TLS_IE:
	  fputs (kvx_unspec_tls_asm_op[unspec_code - UNSPEC_TLS_GD], (fp));
	  fputs ("(", (fp));
	  output_addr_const ((fp), XVECEXP ((x), 0, 0));
	  fputs (")", (fp));
	  return true;

	default:
	  return false;
	}
    }
  return false;
}

/* FIXME AUTO: This must be fixed for coolidge */
/* See T7749 */
static int
kvx_reassociation_width (unsigned int opc, machine_mode mode)
{
  int res = 1;

  /* see tree.c:associative_tree_code () for possible values of opc. */

  switch (opc)
    {
    case BIT_IOR_EXPR:
    case BIT_AND_EXPR:
    case BIT_XOR_EXPR:
      if (mode == SImode || mode == HImode || mode == QImode || mode == DImode)
	res = 4;
      else if (mode == TImode)
	res = 2;
      break;
    case PLUS_EXPR:
    case MIN_EXPR:
    case MAX_EXPR:
      if (mode == SImode || mode == HImode || mode == QImode || mode == DImode)
	res = 4;
      break;
    case MULT_EXPR:
      break;
    }

  return res;
}

/* Return true for the .xs addressing modes, else false. */
static bool
kvx_mode_dependent_address_p (const_rtx addr,
			      addr_space_t space ATTRIBUTE_UNUSED)
{
  const_rtx x = addr;

  // Same logic as .xs addressing mode in kvx_print_operand
  if (GET_CODE (x) == PLUS && GET_CODE (XEXP (x, 0)) == MULT
      && GET_CODE (XEXP (XEXP (x, 0), 1)) == CONST_INT
      && INTVAL (XEXP (XEXP (x, 0), 1)) > HOST_WIDE_INT_1)
    return true;

  return false;
}

bool
kvx_float_fits_bits (const REAL_VALUE_TYPE *r, unsigned bitsz,
		     enum machine_mode mode)
{
  if (bitsz >= 64)
    return true;

  long l[2];
  unsigned long long value = 0;
  if (mode == HFmode)
    {
      REAL_VALUE_TO_TARGET_SINGLE (*r, l[0]);
      value = kvx_float_to_half_as_int (l[0]);
    }
  else if (mode == SFmode)
    {
      REAL_VALUE_TO_TARGET_SINGLE (*r, l[0]);
      value = l[0] & 0xFFFFFFFFULL;
    }
  else if (mode == DFmode)
    {
      REAL_VALUE_TO_TARGET_DOUBLE (*r, l);
      value = (l[0] & 0xFFFFFFFFULL) | ((unsigned long long) l[1] << 32);
    }
  else
    gcc_unreachable ();

  return SIGNED_INT_FITS_N_BITS (value, bitsz);
}

/* Returns a pattern suitable for copyq asm insn with the paired
   register SRCREG correctly split in 2 separate register reference:
   $r0r1 => "copyq %0 = $r0, $r1" if optimising for size.  Returns "#"
   if it is not the case to force the insn to be split in 2 copyd
   insns at the cost of an extra instruction.
 */
const char *
kvx_asm_pat_copyq (rtx srcreg)
{
  static char templ[128];

  /* The single-word copyq will be split in 2 copyd */
  if (!optimize_size)
    return "#";

  snprintf (templ, sizeof (templ), "copyq %%0 = $r%d, $r%d", REGNO (srcreg),
	    REGNO (srcreg) + 1);
  return templ;
}

/* Returns the pattern for copyo when optimizing for code size or
   forces a split by returning #
 */
const char *
kvx_asm_pat_copyo (void)
{
  if (!optimize_size)
    return "#";
  return "copyo %0 = %1";
}

/* Returns TRUE if OP is a REG (directly or through a SUBREG) */
bool
kvx_is_reg_subreg_p (rtx op)
{
  return REG_P (op) || (SUBREG_P (op) && REG_P (SUBREG_REG (op)));
}

/* Returns the regno associated with the REG or SUBREG in OP */
unsigned int
kvx_regno_subregno (rtx op)
{
  if (REG_P (op))
    return REGNO (op);
  else
    return REGNO (SUBREG_REG (op));
}

/* Returns TRUE if OP is a pseudo REG (directly or through a SUBREG)
 */
static bool
kvx_is_pseudo_reg_subreg_p (rtx op)
{
  return ((REG_P (op) && !HARD_REGISTER_P (op))
	  || (SUBREG_P (op) && REG_P (SUBREG_REG (op))
	      && !HARD_REGISTER_P (SUBREG_REG (op))));
}

/* Returns TRUE if OP is a hard (sub)register aligned on ALIGN or a
 * pseudo (sub)register, FALSE for all other cases. */
static bool
kvx_check_align_reg (rtx op, int align)
{
  if (!kvx_is_reg_subreg_p (op))
    return false;
  if (kvx_is_pseudo_reg_subreg_p (op))
    return true;

  const bool aligned_reg = REG_P (op) && REGNO (op) % align == 0;

  const bool aligned_subreg
    = SUBREG_P (op) && REG_P (SUBREG_REG (op))
      && (REGNO (SUBREG_REG (op)) + SUBREG_BYTE (op) / UNITS_PER_WORD) % align
	   == 0;

  return aligned_reg || aligned_subreg;
}

/* Returns TRUE if OP is an even hard (sub)register or a pseudo
 * (sub)register, FALSE for all other cases. It is used to check
 * correct alignement for some SIMD insn or 128bits load/store */
bool
kvx_ok_for_paired_reg_p (rtx op)
{
  return kvx_check_align_reg (op, 2);
}

/* Returns TRUE if OP is a hard (sub)register quad aligned or a pseudo
 * (sub)register, FALSE for all other cases. It is used to check
 * correct alignement for some SIMD insn or 256bits load/store */
bool
kvx_ok_for_quad_reg_p (rtx op)
{
  return kvx_check_align_reg (op, 4);
}

/* Split a 128bit move op in mode MODE from SRC to DST in 2 smaller
   64bit moves */
void
kvx_split_128bits_move (rtx dst, rtx src, enum machine_mode mode)
{
  gcc_assert (!(side_effects_p (src) || side_effects_p (dst)));
  gcc_assert (mode == GET_MODE (src) || GET_MODE (src) == VOIDmode);

  rtx dst_lo = gen_lowpart (word_mode, dst);
  rtx dst_hi = gen_highpart (word_mode, dst);

  rtx src_lo = gen_lowpart (word_mode, src);
  rtx src_hi = gen_highpart_mode (word_mode, mode, src);

  if (reg_overlap_mentioned_p (dst_lo, src_hi))
    {
      gcc_assert (!reg_overlap_mentioned_p (dst_hi, src_lo));

      emit_insn (gen_movdi (dst_hi, src_hi));
      emit_insn (gen_movdi (dst_lo, src_lo));
    }
  else
    {
      emit_insn (gen_movdi (dst_lo, src_lo));
      emit_insn (gen_movdi (dst_hi, src_hi));
    }
}

/* Returns TRUE of OP is a SUBREG of a CONST_VECTOR */
bool
kvx_subreg_const_vector_p (rtx op)
{
  return SUBREG_P (op) && (GET_CODE (XEXP (op, 0)) == CONST_VECTOR);
}

/* Split a 256bit move op in mode MODE from SRC to DST in 2 smaller
   128bit moves */
void
kvx_split_256bits_move (rtx dst, rtx src, enum machine_mode mode)
{
  rtx dst_lo = simplify_gen_subreg (TImode, dst, mode, 0);
  rtx dst_hi = simplify_gen_subreg (TImode, dst, mode, 16);

  rtx src_lo = simplify_gen_subreg (TImode, src, mode, 0);
  rtx src_hi = simplify_gen_subreg (TImode, src, mode, 16);

  if (reg_overlap_mentioned_p (dst_lo, src_hi))
    {
      gcc_assert (!reg_overlap_mentioned_p (dst_hi, src_lo));

      emit_insn (gen_movdi (dst_hi, src_hi));
      emit_insn (gen_movdi (dst_lo, src_lo));
    }
  else
    {
      emit_insn (gen_movdi (dst_lo, src_lo));
      emit_insn (gen_movdi (dst_hi, src_hi));
    }
}

/* Returns TRUE if OP is a symbol and has the farcall attribute or if
   -mfarcall is in use. */
bool
kvx_is_farcall_p (rtx op)
{
  bool farcall = KVX_FARCALL;
  if (!farcall
      && (GET_CODE (XEXP (op, 0)) == SYMBOL_REF
	  && SYMBOL_REF_FUNCTION_P (XEXP (op, 0))
	  && SYMBOL_REF_DECL (XEXP (op, 0)) != NULL_TREE))
    farcall
      = lookup_attribute ("farcall",
			  DECL_ATTRIBUTES (SYMBOL_REF_DECL (XEXP (op, 0))))
	!= NULL;
  return farcall;
}

#ifdef GCC_KVX_MPPA_LINUX
void
kvx_output_function_profiler (FILE *file)
{
  int temp_reg = REGNO (kvx_get_callersaved_nonfixed_reg (Pmode, 2));
  fprintf (file, "\n\tget $r%d = $ra", PROFILE_REGNO);
  if (KVX_FARCALL)
    {
      fprintf (file, "\n\tmake $r%d = __mcount\n\t;;\n\t", temp_reg);
      fprintf (file, "\n\ticall $r%d\n\t;;\n\t", temp_reg);
    }
  else
    {
      fputs ("\n\t;;\n\tcall __mcount\n\t;;\n\t", file);
    }
}
#else
void
kvx_profile_hook (void)
{
  rtx ra_arg = get_hard_reg_initial_val (Pmode, KV3_RETURN_POINTER_REGNO);
  rtx fun = gen_rtx_SYMBOL_REF (Pmode, "__mcount");
  emit_library_call (fun, LCT_NORMAL, VOIDmode, ra_arg, Pmode);
}
#endif

static HOST_WIDE_INT
kvx_constant_alignment (const_tree exp, HOST_WIDE_INT align)
{
  return ((TREE_CODE (exp) == STRING_CST
	   && !optimize_size
	   && (align) < BITS_PER_WORD )
	  ? BITS_PER_WORD : (align));
}

/* Returns asm template for ctrapsi4 */
char *
kvx_ctrapsi4 (void)
{
  static char asm_template[] = "cb.@%R0z %1? 1f\n\t"
			       ";;\n\t"
			       "get $r0 = $pc\n\t"
			       "copyd $r1 = $r12\n\t"
			       ";;\n\t"
			       "call __stack_overflow_detected\n\t"
			       ";;\n\t"
			       "1:\n\t";
  char *width = strchr (asm_template, '@');

  if (width)
    *width = TARGET_32 ? 'w' : 'd';
  return asm_template;
}


/* Initialize the GCC target structure.  */

#undef TARGET_CLASS_MAX_NREGS
#define TARGET_CLASS_MAX_NREGS kvx_class_max_nregs

#undef TARGET_OPTION_OVERRIDE
#define TARGET_OPTION_OVERRIDE kvx_option_override

#undef TARGET_FUNCTION_VALUE
#define TARGET_FUNCTION_VALUE kvx_function_value

#undef TARGET_OMIT_STRUCT_RETURN_REG
#define TARGET_OMIT_STRUCT_RETURN_REG true

#undef TARGET_RETURN_IN_MSB
#define TARGET_RETURN_IN_MSB kvx_return_in_msb

#undef TARGET_RETURN_IN_MEMORY
#define TARGET_RETURN_IN_MEMORY kvx_return_in_memory

#undef TARGET_STRUCT_VALUE_RTX
#define TARGET_STRUCT_VALUE_RTX kvx_struct_value_rtx

#undef TARGET_ASM_OUTPUT_MI_THUNK
#define TARGET_ASM_OUTPUT_MI_THUNK kvx_asm_output_mi_thunk

#undef TARGET_ASM_CAN_OUTPUT_MI_THUNK
#define TARGET_ASM_CAN_OUTPUT_MI_THUNK kvx_asm_can_output_mi_thunk

#undef TARGET_ASM_ALIGNED_DI_OP
#define TARGET_ASM_ALIGNED_DI_OP "\t.8byte\t"

#undef TARGET_EXPAND_BUILTIN_SAVEREGS
#define TARGET_EXPAND_BUILTIN_SAVEREGS kvx_expand_builtin_saveregs

#undef TARGET_EXPAND_BUILTIN_VA_START
#define TARGET_EXPAND_BUILTIN_VA_START kvx_expand_va_start

#undef TARGET_LEGITIMATE_ADDRESS_P
#define TARGET_LEGITIMATE_ADDRESS_P kvx_legitimate_address_p

#undef TARGET_FIXED_POINT_SUPPORTED_P
#define TARGET_FIXED_POINT_SUPPORTED_P kvx_fixed_point_supported_p

#undef TARGET_SCALAR_MODE_SUPPORTED_P
#define TARGET_SCALAR_MODE_SUPPORTED_P kvx_scalar_mode_supported_p

#undef TARGET_VECTOR_MODE_SUPPORTED_P
#define TARGET_VECTOR_MODE_SUPPORTED_P kvx_vector_mode_supported_p

#undef TARGET_LIBGCC_FLOATING_MODE_SUPPORTED_P
#define TARGET_LIBGCC_FLOATING_MODE_SUPPORTED_P                                \
  kvx_libgcc_floating_mode_supported_p

#undef TARGET_MANGLE_TYPE
#define TARGET_MANGLE_TYPE kvx_mangle_type

#undef TARGET_C_EXCESS_PRECISION
#define TARGET_C_EXCESS_PRECISION kvx_excess_precision

#undef TARGET_VECTORIZE_SUPPORT_VECTOR_MISALIGNMENT
#define TARGET_VECTORIZE_SUPPORT_VECTOR_MISALIGNMENT                           \
  kvx_support_vector_misalignment

#undef TARGET_VECTORIZE_PREFERRED_SIMD_MODE
#define TARGET_VECTORIZE_PREFERRED_SIMD_MODE kvx_vectorize_preferred_simd_mode

#undef TARGET_PROMOTE_FUNCTION_MODE
#define TARGET_PROMOTE_FUNCTION_MODE kvx_promote_function_mode

#undef TARGET_PROMOTE_PROTOTYPES
#define TARGET_PROMOTE_PROTOTYPES hook_bool_const_tree_true

#undef TARGET_ARG_PARTIAL_BYTES
#define TARGET_ARG_PARTIAL_BYTES kvx_arg_partial_bytes

#undef TARGET_MUST_PASS_IN_STACK
#define TARGET_MUST_PASS_IN_STACK must_pass_in_stack_var_size

#undef TARGET_PASS_BY_REFERENCE
#define TARGET_PASS_BY_REFERENCE kvx_pass_by_reference

#undef TARGET_SECONDARY_RELOAD
#define TARGET_SECONDARY_RELOAD kvx_secondary_reload

#undef TARGET_INIT_BUILTINS
#define TARGET_INIT_BUILTINS kvx_init_builtins

#undef TARGET_EXPAND_BUILTIN
#define TARGET_EXPAND_BUILTIN kvx_expand_builtin

#undef TARGET_CANNOT_FORCE_CONST_MEM
#define TARGET_CANNOT_FORCE_CONST_MEM kvx_cannot_force_const_mem

#undef TARGET_RTX_COSTS
#define TARGET_RTX_COSTS kvx_rtx_costs

#undef TARGET_ADDRESS_COST
#define TARGET_ADDRESS_COST kvx_address_cost

#undef TARGET_INSN_COST
#define TARGET_INSN_COST kvx_insn_cost

#undef TARGET_REGISTER_MOVE_COST
#define TARGET_REGISTER_MOVE_COST kvx_register_move_cost

#undef TARGET_MEMORY_MOVE_COST
#define TARGET_MEMORY_MOVE_COST kvx_memory_move_cost

#undef TARGET_SCHED_ISSUE_RATE
#define TARGET_SCHED_ISSUE_RATE kvx_sched_issue_rate

#undef TARGET_SCHED_VARIABLE_ISSUE
#define TARGET_SCHED_VARIABLE_ISSUE kvx_sched_variable_issue

#undef TARGET_SCHED_ADJUST_COST
#define TARGET_SCHED_ADJUST_COST kvx_sched_adjust_cost

#undef TARGET_SCHED_ADJUST_PRIORITY
#define TARGET_SCHED_ADJUST_PRIORITY kvx_sched_adjust_priority

#undef TARGET_SCHED_DEPENDENCIES_EVALUATION_HOOK
#define TARGET_SCHED_DEPENDENCIES_EVALUATION_HOOK                              \
  kvx_sched_dependencies_evaluation_hook

#undef TARGET_SCHED_INIT
#define TARGET_SCHED_INIT kvx_sched_init

#undef TARGET_SCHED_FINISH
#define TARGET_SCHED_FINISH kvx_sched_finish

#undef TARGET_SCHED_INIT_GLOBAL
#define TARGET_SCHED_INIT_GLOBAL kvx_sched_init_global

#undef TARGET_SCHED_FINISH_GLOBAL
#define TARGET_SCHED_FINISH_GLOBAL kvx_sched_finish_global

#undef TARGET_SCHED_DFA_NEW_CYCLE
#define TARGET_SCHED_DFA_NEW_CYCLE kvx_sched_dfa_new_cycle

#undef TARGET_SCHED_SET_SCHED_FLAGS
#define TARGET_SCHED_SET_SCHED_FLAGS kvx_sched_set_sched_flags

#undef TARGET_SCHED_CAN_SPECULATE_INSN
#define TARGET_SCHED_CAN_SPECULATE_INSN kvx_sched_can_speculate_insn

#undef TARGET_SCHED_SMS_RES_MII
#define TARGET_SCHED_SMS_RES_MII kvx_sched_sms_res_mii

#undef TARGET_SCHED_EXPOSED_PIPELINE
#define TARGET_SCHED_EXPOSED_PIPELINE true

#undef TARGET_SCHED_REASSOCIATION_WIDTH
#define TARGET_SCHED_REASSOCIATION_WIDTH kvx_sched_reassociation_width

#undef TARGET_FUNCTION_OK_FOR_SIBCALL
#define TARGET_FUNCTION_OK_FOR_SIBCALL kvx_function_ok_for_sibcall

#undef TARGET_BUILTIN_DECL
#define TARGET_BUILTIN_DECL kvx_builtin_decl

#undef TARGET_LEGITIMIZE_ADDRESS
#define TARGET_LEGITIMIZE_ADDRESS kvx_legitimize_address

#undef TARGET_CONST_ANCHOR
#define TARGET_CONST_ANCHOR 0x200

#undef TARGET_ASM_FUNCTION_PROLOGUE
#define TARGET_ASM_FUNCTION_PROLOGUE kvx_function_prologue

#undef TARGET_ASM_FUNCTION_EPILOGUE
#define TARGET_ASM_FUNCTION_EPILOGUE kvx_function_epilogue

#undef TARGET_ASM_FINAL_POSTSCAN_INSN
#define TARGET_ASM_FINAL_POSTSCAN_INSN kvx_asm_final_postscan_insn

#undef TARGET_MACHINE_DEPENDENT_REORG
#define TARGET_MACHINE_DEPENDENT_REORG kvx_reorg

#undef TARGET_ATTRIBUTE_TABLE
#define TARGET_ATTRIBUTE_TABLE kvx_attribute_table

#undef TARGET_FUNCTION_ARG
#define TARGET_FUNCTION_ARG kvx_function_arg

#undef TARGET_FUNCTION_ARG_ADVANCE
#define TARGET_FUNCTION_ARG_ADVANCE kvx_function_arg_advance

#undef TARGET_LEGITIMATE_CONSTANT_P
#define TARGET_LEGITIMATE_CONSTANT_P kvx_legitimate_constant_p

#undef TARGET_CONDITIONAL_REGISTER_USAGE
#define TARGET_CONDITIONAL_REGISTER_USAGE kvx_conditional_register_usage

#undef TARGET_CANONICALIZE_COMPARISON
#define TARGET_CANONICALIZE_COMPARISON kvx_canonicalize_comparison

#undef TARGET_ASM_OUTPUT_ADDR_CONST_EXTRA
#define TARGET_ASM_OUTPUT_ADDR_CONST_EXTRA kvx_output_addr_const_extra

#undef TARGET_INVALID_WITHIN_DOLOOP
#define TARGET_INVALID_WITHIN_DOLOOP kvx_invalid_within_doloop

#undef TARGET_MODE_DEPENDENT_ADDRESS_P
#define TARGET_MODE_DEPENDENT_ADDRESS_P kvx_mode_dependent_address_p

#undef TARGET_CAN_USE_DOLOOP_P
#define TARGET_CAN_USE_DOLOOP_P can_use_doloop_if_innermost

#undef TARGET_ADDR_SPACE_POINTER_MODE
#define TARGET_ADDR_SPACE_POINTER_MODE kvx_addr_space_pointer_mode

#undef TARGET_ADDR_SPACE_ADDRESS_MODE
#define TARGET_ADDR_SPACE_ADDRESS_MODE kvx_addr_space_address_mode
#undef TARGET_ADDR_SPACE_LEGITIMATE_ADDRESS_P
#define TARGET_ADDR_SPACE_LEGITIMATE_ADDRESS_P                                 \
  kvx_addr_space_legitimate_address_p

#undef TARGET_ADDR_SPACE_LEGITIMIZE_ADDRESS
#define TARGET_ADDR_SPACE_LEGITIMIZE_ADDRESS kvx_addr_space_legitimize_address

#undef TARGET_ADDR_SPACE_SUBSET_P
#define TARGET_ADDR_SPACE_SUBSET_P kvx_addr_space_subset_p

#undef TARGET_ADDR_SPACE_CONVERT
#define TARGET_ADDR_SPACE_CONVERT kvx_addr_space_convert

#undef TARGET_CONSTANT_ALIGNMENT
#define TARGET_CONSTANT_ALIGNMENT kvx_constant_alignment

#undef TARGET_HARD_REGNO_NREGS
#define TARGET_HARD_REGNO_NREGS kvx_hard_regno_nregs

#undef TARGET_HARD_REGNO_MODE_OK
#define TARGET_HARD_REGNO_MODE_OK kvx_hard_regno_mode_ok

#undef TARGET_STARTING_FRAME_OFFSET
#define TARGET_STARTING_FRAME_OFFSET kvx_starting_frame_offset

/* FIXME AUTO: trampoline are broken T6775 */
#undef TARGET_STATIC_CHAIN
#define TARGET_STATIC_CHAIN kvx_static_chain

#undef TARGET_DELAY_SCHED2
#define TARGET_DELAY_SCHED2 (!TARGET_BUNDLING)

#undef TARGET_DELAY_VARTRACK
#define TARGET_DELAY_VARTRACK (!TARGET_BUNDLING)

#undef TARGET_VECTORIZE_VEC_PERM_CONST
#define TARGET_VECTORIZE_VEC_PERM_CONST		\
  kvx_vectorize_vec_perm_const

void kvx_init_builtins (void);
tree kvx_builtin_decl (unsigned code, bool initialize_p);
rtx kvx_expand_builtin (tree exp, rtx target, rtx subtarget,
			enum machine_mode mode, int ignore);

struct gcc_target targetm = TARGET_INITIALIZER;

#include "gt-kvx.h"
