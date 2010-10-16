/* Subroutines for gcc2 for pdp11.
   Copyright (C) 1994, 1995, 1996, 1997, 1998, 1999, 2001, 2004, 2005,
   2006, 2007, 2008, 2009, 2010 Free Software Foundation, Inc.
   Contributed by Michael K. Gschwind (mike@vlsivie.tuwien.ac.at).

This file is part of GCC.

GCC is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation; either version 3, or (at your option)
any later version.

GCC is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with GCC; see the file COPYING3.  If not see
<http://www.gnu.org/licenses/>.  */

#include "config.h"
#include "system.h"
#include "coretypes.h"
#include "tm.h"
#include "rtl.h"
#include "regs.h"
#include "hard-reg-set.h"
#include "insn-config.h"
#include "conditions.h"
#include "function.h"
#include "output.h"
#include "insn-attr.h"
#include "flags.h"
#include "recog.h"
#include "tree.h"
#include "expr.h"
#include "diagnostic-core.h"
#include "toplev.h"
#include "tm_p.h"
#include "target.h"
#include "target-def.h"
#include "df.h"

/*
#define FPU_REG_P(X)	((X)>=8 && (X)<14)
#define CPU_REG_P(X)	((X)>=0 && (X)<8)
*/

/* this is the current value returned by the macro FIRST_PARM_OFFSET 
   defined in tm.h */
int current_first_parm_offset;

/* Routines to encode/decode pdp11 floats */
static void encode_pdp11_f (const struct real_format *fmt,
			    long *, const REAL_VALUE_TYPE *);
static void decode_pdp11_f (const struct real_format *,
			    REAL_VALUE_TYPE *, const long *);
static void encode_pdp11_d (const struct real_format *fmt,
			    long *, const REAL_VALUE_TYPE *);
static void decode_pdp11_d (const struct real_format *,
			    REAL_VALUE_TYPE *, const long *);

/* These two are taken from the corresponding vax descriptors
   in real.c, changing only the encode/decode routine pointers.  */
const struct real_format pdp11_f_format =
  {
    encode_pdp11_f,
    decode_pdp11_f,
    2,
    1,
    24,
    24,
    -127,
    127,
    15,
    false,
    false,
    false,
    false,
    false,
    false,
    false,
    false
  };

const struct real_format pdp11_d_format =
  {
    encode_pdp11_d,
    decode_pdp11_d,
    2,
    1,
    56,
    56,
    -127,
    127,
    15,
    false,
    false,
    false,
    false,
    false,
    false,
    false,
    false
  };

static void
encode_pdp11_f (const struct real_format *fmt ATTRIBUTE_UNUSED, long *buf,
		const REAL_VALUE_TYPE *r)
{
  (*vax_f_format.encode) (fmt, buf, r);
  buf[0] = ((buf[0] >> 16) & 0xffff) | ((buf[0] & 0xffff) << 16);
}

static void
decode_pdp11_f (const struct real_format *fmt ATTRIBUTE_UNUSED,
		REAL_VALUE_TYPE *r, const long *buf)
{
  long tbuf;
  tbuf = ((buf[0] >> 16) & 0xffff) | ((buf[0] & 0xffff) << 16);
  (*vax_f_format.decode) (fmt, r, &tbuf);
}

static void
encode_pdp11_d (const struct real_format *fmt ATTRIBUTE_UNUSED, long *buf,
		const REAL_VALUE_TYPE *r)
{
  (*vax_d_format.encode) (fmt, buf, r);
  buf[0] = ((buf[0] >> 16) & 0xffff) | ((buf[0] & 0xffff) << 16);
  buf[1] = ((buf[1] >> 16) & 0xffff) | ((buf[1] & 0xffff) << 16);
}

static void
decode_pdp11_d (const struct real_format *fmt ATTRIBUTE_UNUSED,
		REAL_VALUE_TYPE *r, const long *buf)
{
  long tbuf[2];
  tbuf[0] = ((buf[0] >> 16) & 0xffff) | ((buf[0] & 0xffff) << 16);
  tbuf[1] = ((buf[1] >> 16) & 0xffff) | ((buf[1] & 0xffff) << 16);
  (*vax_d_format.decode) (fmt, r, tbuf);
}

/* This is where the condition code register lives.  */
/* rtx cc0_reg_rtx; - no longer needed? */

static bool pdp11_handle_option (size_t, const char *, int);
static void pdp11_option_optimization (int, int);
static void pdp11_option_init_struct (struct gcc_options *);
static rtx find_addr_reg (rtx); 
static const char *singlemove_string (rtx *);
static bool pdp11_assemble_integer (rtx, unsigned int, int);
static void pdp11_output_function_prologue (FILE *, HOST_WIDE_INT);
static void pdp11_output_function_epilogue (FILE *, HOST_WIDE_INT);
static bool pdp11_rtx_costs (rtx, int, int, int *, bool);
static bool pdp11_return_in_memory (const_tree, const_tree);
static rtx pdp11_function_value (const_tree, const_tree, bool);
static rtx pdp11_libcall_value (enum machine_mode, const_rtx);
static bool pdp11_function_value_regno_p (const unsigned int);
static void pdp11_trampoline_init (rtx, tree, rtx);
static rtx pdp11_function_arg (CUMULATIVE_ARGS *, enum machine_mode,
			       const_tree, bool);
static void pdp11_function_arg_advance (CUMULATIVE_ARGS *,
					enum machine_mode, const_tree, bool);

/* Initialize the GCC target structure.  */
#undef TARGET_ASM_BYTE_OP
#define TARGET_ASM_BYTE_OP NULL
#undef TARGET_ASM_ALIGNED_HI_OP
#define TARGET_ASM_ALIGNED_HI_OP NULL
#undef TARGET_ASM_ALIGNED_SI_OP
#define TARGET_ASM_ALIGNED_SI_OP NULL
#undef TARGET_ASM_INTEGER
#define TARGET_ASM_INTEGER pdp11_assemble_integer

#undef TARGET_ASM_FUNCTION_PROLOGUE
#define TARGET_ASM_FUNCTION_PROLOGUE pdp11_output_function_prologue
#undef TARGET_ASM_FUNCTION_EPILOGUE
#define TARGET_ASM_FUNCTION_EPILOGUE pdp11_output_function_epilogue

#undef TARGET_ASM_OPEN_PAREN
#define TARGET_ASM_OPEN_PAREN "["
#undef TARGET_ASM_CLOSE_PAREN
#define TARGET_ASM_CLOSE_PAREN "]"

#undef TARGET_DEFAULT_TARGET_FLAGS
#define TARGET_DEFAULT_TARGET_FLAGS \
  (MASK_FPU | MASK_45 | MASK_ABSHI_BUILTIN | TARGET_UNIX_ASM_DEFAULT)
#undef TARGET_HANDLE_OPTION
#define TARGET_HANDLE_OPTION pdp11_handle_option
#undef TARGET_OPTION_OPTIMIZATION
#define TARGET_OPTION_OPTIMIZATION pdp11_option_optimization
#undef TARGET_OPTION_INIT_STRUCT
#define TARGET_OPTION_INIT_STRUCT pdp11_option_init_struct

#undef TARGET_RTX_COSTS
#define TARGET_RTX_COSTS pdp11_rtx_costs

#undef TARGET_FUNCTION_ARG
#define TARGET_FUNCTION_ARG pdp11_function_arg
#undef TARGET_FUNCTION_ARG_ADVANCE
#define TARGET_FUNCTION_ARG_ADVANCE pdp11_function_arg_advance

#undef TARGET_RETURN_IN_MEMORY
#define TARGET_RETURN_IN_MEMORY pdp11_return_in_memory

#undef TARGET_FUNCTION_VALUE
#define TARGET_FUNCTION_VALUE pdp11_function_value
#undef TARGET_LIBCALL_VALUE
#define TARGET_LIBCALL_VALUE pdp11_libcall_value
#undef TARGET_FUNCTION_VALUE_REGNO_P
#define TARGET_FUNCTION_VALUE_REGNO_P pdp11_function_value_regno_p

#undef TARGET_TRAMPOLINE_INIT
#define TARGET_TRAMPOLINE_INIT pdp11_trampoline_init

struct gcc_target targetm = TARGET_INITIALIZER;

/* Implement TARGET_HANDLE_OPTION.  */

static bool
pdp11_handle_option (size_t code, const char *arg ATTRIBUTE_UNUSED,
		     int value ATTRIBUTE_UNUSED)
{
  switch (code)
    {
    case OPT_m10:
      target_flags &= ~(MASK_40 | MASK_45);
      return true;

    default:
      return true;
    }
}

/* Implement TARGET_OPTION_OPTIMIZATION.  */

static void
pdp11_option_optimization (int level, int size ATTRIBUTE_UNUSED)
{
  if (level >= 3)
    {
      flag_omit_frame_pointer = 1;
      /* flag_unroll_loops = 1; */
    }
}

/* Implement TARGET_OPTION_INIT_STRUCT.  */

static void
pdp11_option_init_struct (struct gcc_options *opts)
{
  opts->x_flag_finite_math_only = 0;
  opts->x_flag_trapping_math = 0;
  opts->x_flag_signaling_nans = 0;
}

/* Nonzero if OP is a valid second operand for an arithmetic insn.  */

int
arith_operand (rtx op, enum machine_mode mode)
{
  return (register_operand (op, mode) || GET_CODE (op) == CONST_INT);
}

int
const_immediate_operand (rtx op, enum machine_mode mode ATTRIBUTE_UNUSED)
{
  return (GET_CODE (op) == CONST_INT);
}

int 
immediate15_operand (rtx op, enum machine_mode mode ATTRIBUTE_UNUSED)
{
    return (GET_CODE (op) == CONST_INT && ((INTVAL (op) & 0x8000) == 0x0000));
}

int
expand_shift_operand (rtx op, enum machine_mode mode ATTRIBUTE_UNUSED)
{
    return (GET_CODE (op) == CONST_INT 
	    && abs (INTVAL(op)) > 1 
	    && abs (INTVAL(op)) <= 4);
}

/*
   stream is a stdio stream to output the code to.
   size is an int: how many units of temporary storage to allocate.
   Refer to the array `regs_ever_live' to determine which registers
   to save; `regs_ever_live[I]' is nonzero if register number I
   is ever used in the function.  This macro is responsible for
   knowing which registers should not be saved even if used.  
*/

static void
pdp11_output_function_prologue (FILE *stream, HOST_WIDE_INT size)
{							       
    HOST_WIDE_INT fsize = ((size) + 1) & ~1;
    int regno;
    int via_ac = -1;

    fprintf (stream,
	     "\n\t;	/* function prologue %s*/\n",
	     current_function_name ());

    /* if we are outputting code for main, 
       the switch FPU to right mode if TARGET_FPU */
    if (MAIN_NAME_P (DECL_NAME (current_function_decl)) && TARGET_FPU)
    {
	fprintf(stream,
		"\t;/* switch cpu to double float, single integer */\n");
	fprintf(stream, "\tsetd\n");
	fprintf(stream, "\tseti\n\n");
    }
    
    if (frame_pointer_needed) 					
    {								
	fprintf(stream, "\tmov r5, -(sp)\n");			
	fprintf(stream, "\tmov sp, r5\n");				
    }								
    else 								
    {								
	/* DON'T SAVE FP */
    }								

    /* make frame */
    if (fsize)							
	asm_fprintf (stream, "\tsub $%#wo, sp\n", fsize);

    /* save CPU registers  */
    for (regno = 0; regno < 8; regno++)				
      if (df_regs_ever_live_p (regno) && ! call_used_regs[regno])	
	    if (! ((regno == FRAME_POINTER_REGNUM)			
		   && frame_pointer_needed))				
		fprintf (stream, "\tmov %s, -(sp)\n", reg_names[regno]);	
    /* fpu regs saving */
    
    /* via_ac specifies the ac to use for saving ac4, ac5 */
    via_ac = -1;
    
    for (regno = 8; regno < FIRST_PSEUDO_REGISTER ; regno++) 
    {
	/* ac0 - ac3 */						
	if (LOAD_FPU_REG_P(regno)
	    && df_regs_ever_live_p (regno) 
	    && ! call_used_regs[regno])
	{
	    fprintf (stream, "\tstd %s, -(sp)\n", reg_names[regno]);
	    via_ac = regno;
	}
	
	/* maybe make ac4, ac5 call used regs?? */
	/* ac4 - ac5 */
	if (NO_LOAD_FPU_REG_P(regno)
	    && df_regs_ever_live_p (regno)
	    && ! call_used_regs[regno])
	{
	  gcc_assert (via_ac != -1);
	  fprintf (stream, "\tldd %s, %s\n",
		   reg_names[regno], reg_names[via_ac]);
	  fprintf (stream, "\tstd %s, -(sp)\n", reg_names[via_ac]);
	}
    }

    fprintf (stream, "\t;/* end of prologue */\n\n");		
}

/*
   The function epilogue should not depend on the current stack pointer!
   It should use the frame pointer only.  This is mandatory because
   of alloca; we also take advantage of it to omit stack adjustments
   before returning.  */

/* maybe we can make leaf functions faster by switching to the
   second register file - this way we don't have to save regs!
   leaf functions are ~ 50% of all functions (dynamically!) 

   set/clear bit 11 (dec. 2048) of status word for switching register files - 
   but how can we do this? the pdp11/45 manual says bit may only 
   be set (p.24), but not cleared!

   switching to kernel is probably more expensive, so we'll leave it 
   like this and not use the second set of registers... 

   maybe as option if you want to generate code for kernel mode? */

static void
pdp11_output_function_epilogue (FILE *stream, HOST_WIDE_INT size)
{								
    HOST_WIDE_INT fsize = ((size) + 1) & ~1;
    int i, j, k;

    int via_ac;
    
    fprintf (stream, "\n\t;	/*function epilogue */\n");		

    if (frame_pointer_needed)					
    {								
	/* hope this is safe - m68k does it also .... */		
        df_set_regs_ever_live (FRAME_POINTER_REGNUM, false);
								
	for (i =7, j = 0 ; i >= 0 ; i--)				
	  if (df_regs_ever_live_p (i) && ! call_used_regs[i])		
		j++;
	
	/* remember # of pushed bytes for CPU regs */
	k = 2*j;
	
	/* change fp -> r5 due to the compile error on libgcc2.c */
	for (i =7 ; i >= 0 ; i--)					
	  if (df_regs_ever_live_p (i) && ! call_used_regs[i])		
		fprintf(stream, "\tmov %#" HOST_WIDE_INT_PRINT "o(r5), %s\n",
			(-fsize-2*j--)&0xffff, reg_names[i]);

	/* get ACs */						
	via_ac = FIRST_PSEUDO_REGISTER -1;
	
	for (i = FIRST_PSEUDO_REGISTER; i > 7; i--)
	  if (df_regs_ever_live_p (i) && ! call_used_regs[i])
	    {
		via_ac = i;
		k += 8;
	    }
	
	for (i = FIRST_PSEUDO_REGISTER; i > 7; i--)
	{
	    if (LOAD_FPU_REG_P(i)
		&& df_regs_ever_live_p (i)
		&& ! call_used_regs[i])
	    {
		fprintf(stream, "\tldd %#" HOST_WIDE_INT_PRINT "o(r5), %s\n",
			(-fsize-k)&0xffff, reg_names[i]);
		k -= 8;
	    }
	    
	    if (NO_LOAD_FPU_REG_P(i)
		&& df_regs_ever_live_p (i)
		&& ! call_used_regs[i])
	    {
	        gcc_assert (LOAD_FPU_REG_P(via_ac));
		    
		fprintf(stream, "\tldd %#" HOST_WIDE_INT_PRINT "o(r5), %s\n",
			(-fsize-k)&0xffff, reg_names[via_ac]);
		fprintf(stream, "\tstd %s, %s\n", reg_names[via_ac], reg_names[i]);
		k -= 8;
	    }
	}
	
	fprintf(stream, "\tmov r5, sp\n");				
	fprintf (stream, "\tmov (sp)+, r5\n");     			
    }								
    else								
    {		   
	via_ac = FIRST_PSEUDO_REGISTER -1;
	
	/* get ACs */
	for (i = FIRST_PSEUDO_REGISTER; i > 7; i--)
	  if (df_regs_ever_live_p (i) && call_used_regs[i])
		via_ac = i;
	
	for (i = FIRST_PSEUDO_REGISTER; i > 7; i--)
	{
	    if (LOAD_FPU_REG_P(i)
		&& df_regs_ever_live_p (i)
		&& ! call_used_regs[i])
	      fprintf(stream, "\tldd (sp)+, %s\n", reg_names[i]);
	    
	    if (NO_LOAD_FPU_REG_P(i)
		&& df_regs_ever_live_p (i)
		&& ! call_used_regs[i])
	    {
	        gcc_assert (LOAD_FPU_REG_P(via_ac));
		    
		fprintf(stream, "\tldd (sp)+, %s\n", reg_names[via_ac]);
		fprintf(stream, "\tstd %s, %s\n", reg_names[via_ac], reg_names[i]);
	    }
	}

	for (i=7; i >= 0; i--)					
	  if (df_regs_ever_live_p (i) && !call_used_regs[i])		
		fprintf(stream, "\tmov (sp)+, %s\n", reg_names[i]);	
								
	if (fsize)						
	    fprintf((stream), "\tadd $%#" HOST_WIDE_INT_PRINT "o, sp\n",
		    (fsize)&0xffff);      		
    }			
					
    fprintf (stream, "\trts pc\n");					
    fprintf (stream, "\t;/* end of epilogue*/\n\n\n");		
}

/* Return the best assembler insn template
   for moving operands[1] into operands[0] as a fullword.  */
static const char *
singlemove_string (rtx *operands)
{
  if (operands[1] != const0_rtx)
    return "mov %1,%0";

  return "clr %0";
}


/* Output assembler code to perform a doubleword move insn
   with operands OPERANDS.  */

const char *
output_move_double (rtx *operands)
{
  enum { REGOP, OFFSOP, MEMOP, PUSHOP, POPOP, CNSTOP, RNDOP } optype0, optype1;
  rtx latehalf[2];
  rtx addreg0 = 0, addreg1 = 0;

  /* First classify both operands.  */

  if (REG_P (operands[0]))
    optype0 = REGOP;
  else if (offsettable_memref_p (operands[0]))
    optype0 = OFFSOP;
  else if (GET_CODE (XEXP (operands[0], 0)) == POST_INC)
    optype0 = POPOP;
  else if (GET_CODE (XEXP (operands[0], 0)) == PRE_DEC)
    optype0 = PUSHOP;
  else if (GET_CODE (operands[0]) == MEM)
    optype0 = MEMOP;
  else
    optype0 = RNDOP;

  if (REG_P (operands[1]))
    optype1 = REGOP;
  else if (CONSTANT_P (operands[1])
#if 0
	   || GET_CODE (operands[1]) == CONST_DOUBLE
#endif
	   )
    optype1 = CNSTOP;
  else if (offsettable_memref_p (operands[1]))
    optype1 = OFFSOP;
  else if (GET_CODE (XEXP (operands[1], 0)) == POST_INC)
    optype1 = POPOP;
  else if (GET_CODE (XEXP (operands[1], 0)) == PRE_DEC)
    optype1 = PUSHOP;
  else if (GET_CODE (operands[1]) == MEM)
    optype1 = MEMOP;
  else
    optype1 = RNDOP;

  /* Check for the cases that the operand constraints are not
     supposed to allow to happen.  Abort if we get one,
     because generating code for these cases is painful.  */

  gcc_assert (optype0 != RNDOP && optype1 != RNDOP);

  /* If one operand is decrementing and one is incrementing
     decrement the former register explicitly
     and change that operand into ordinary indexing.  */

  if (optype0 == PUSHOP && optype1 == POPOP)
    {
      operands[0] = XEXP (XEXP (operands[0], 0), 0);
      output_asm_insn ("sub $4,%0", operands);
      operands[0] = gen_rtx_MEM (SImode, operands[0]);
      optype0 = OFFSOP;
    }
  if (optype0 == POPOP && optype1 == PUSHOP)
    {
      operands[1] = XEXP (XEXP (operands[1], 0), 0);
      output_asm_insn ("sub $4,%1", operands);
      operands[1] = gen_rtx_MEM (SImode, operands[1]);
      optype1 = OFFSOP;
    }

  /* If an operand is an unoffsettable memory ref, find a register
     we can increment temporarily to make it refer to the second word.  */

  if (optype0 == MEMOP)
    addreg0 = find_addr_reg (XEXP (operands[0], 0));

  if (optype1 == MEMOP)
    addreg1 = find_addr_reg (XEXP (operands[1], 0));

  /* Ok, we can do one word at a time.
     Normally we do the low-numbered word first,
     but if either operand is autodecrementing then we
     do the high-numbered word first.

     In either case, set up in LATEHALF the operands to use
     for the high-numbered word and in some cases alter the
     operands in OPERANDS to be suitable for the low-numbered word.  */

  if (optype0 == REGOP)
    latehalf[0] = gen_rtx_REG (HImode, REGNO (operands[0]) + 1);
  else if (optype0 == OFFSOP)
    latehalf[0] = adjust_address (operands[0], HImode, 2);
  else
    latehalf[0] = operands[0];

  if (optype1 == REGOP)
    latehalf[1] = gen_rtx_REG (HImode, REGNO (operands[1]) + 1);
  else if (optype1 == OFFSOP)
    latehalf[1] = adjust_address (operands[1], HImode, 2);
  else if (optype1 == CNSTOP)
    {
	if (CONSTANT_P (operands[1]))
	{
	    /* now the mess begins, high word is in lower word??? 

	       that's what ashc makes me think, but I don't remember :-( */
	    latehalf[1] = GEN_INT (INTVAL(operands[1]) >> 16);
	    operands[1] = GEN_INT (INTVAL(operands[1]) & 0xff);
	}
	else
	  /* immediate 32-bit values not allowed */
	  gcc_assert (GET_CODE (operands[1]) != CONST_DOUBLE);
    }
  else
    latehalf[1] = operands[1];

  /* If insn is effectively movd N(sp),-(sp) then we will do the
     high word first.  We should use the adjusted operand 1 (which is N+4(sp))
     for the low word as well, to compensate for the first decrement of sp.  */
  if (optype0 == PUSHOP
      && REGNO (XEXP (XEXP (operands[0], 0), 0)) == STACK_POINTER_REGNUM
      && reg_overlap_mentioned_p (stack_pointer_rtx, operands[1]))
    operands[1] = latehalf[1];

  /* If one or both operands autodecrementing,
     do the two words, high-numbered first.  */

  /* Likewise,  the first move would clobber the source of the second one,
     do them in the other order.  This happens only for registers;
     such overlap can't happen in memory unless the user explicitly
     sets it up, and that is an undefined circumstance.  */

  if (optype0 == PUSHOP || optype1 == PUSHOP
      || (optype0 == REGOP && optype1 == REGOP
	  && REGNO (operands[0]) == REGNO (latehalf[1])))
    {
      /* Make any unoffsettable addresses point at high-numbered word.  */
      if (addreg0)
	output_asm_insn ("add $2,%0", &addreg0);
      if (addreg1)
	output_asm_insn ("add $2,%0", &addreg1);

      /* Do that word.  */
      output_asm_insn (singlemove_string (latehalf), latehalf);

      /* Undo the adds we just did.  */
      if (addreg0)
	output_asm_insn ("sub $2,%0", &addreg0);
      if (addreg1)
	output_asm_insn ("sub $2,%0", &addreg1);

      /* Do low-numbered word.  */
      return singlemove_string (operands);
    }

  /* Normal case: do the two words, low-numbered first.  */

  output_asm_insn (singlemove_string (operands), operands);

  /* Make any unoffsettable addresses point at high-numbered word.  */
  if (addreg0)
    output_asm_insn ("add $2,%0", &addreg0);
  if (addreg1)
    output_asm_insn ("add $2,%0", &addreg1);

  /* Do that word.  */
  output_asm_insn (singlemove_string (latehalf), latehalf);

  /* Undo the adds we just did.  */
  if (addreg0)
    output_asm_insn ("sub $2,%0", &addreg0);
  if (addreg1)
    output_asm_insn ("sub $2,%0", &addreg1);

  return "";
}
/* Output assembler code to perform a quadword move insn
   with operands OPERANDS.  */

const char *
output_move_quad (rtx *operands)
{
  enum { REGOP, OFFSOP, MEMOP, PUSHOP, POPOP, CNSTOP, RNDOP } optype0, optype1;
  rtx latehalf[2];
  rtx addreg0 = 0, addreg1 = 0;

  output_asm_insn(";/* movdi/df: %1 -> %0 */", operands);
  
  if (REG_P (operands[0]))
    optype0 = REGOP;
  else if (offsettable_memref_p (operands[0]))
    optype0 = OFFSOP;
  else if (GET_CODE (XEXP (operands[0], 0)) == POST_INC)
    optype0 = POPOP;
  else if (GET_CODE (XEXP (operands[0], 0)) == PRE_DEC)
    optype0 = PUSHOP;
  else if (GET_CODE (operands[0]) == MEM)
    optype0 = MEMOP;
  else
    optype0 = RNDOP;

  if (REG_P (operands[1]))
    optype1 = REGOP;
  else if (CONSTANT_P (operands[1])
	   || GET_CODE (operands[1]) == CONST_DOUBLE)
    optype1 = CNSTOP;
  else if (offsettable_memref_p (operands[1]))
    optype1 = OFFSOP;
  else if (GET_CODE (XEXP (operands[1], 0)) == POST_INC)
    optype1 = POPOP;
  else if (GET_CODE (XEXP (operands[1], 0)) == PRE_DEC)
    optype1 = PUSHOP;
  else if (GET_CODE (operands[1]) == MEM)
    optype1 = MEMOP;
  else
    optype1 = RNDOP;

  /* Check for the cases that the operand constraints are not
     supposed to allow to happen.  Abort if we get one,
     because generating code for these cases is painful.  */

  gcc_assert (optype0 != RNDOP && optype1 != RNDOP);
  
  /* check if we move a CPU reg to an FPU reg, or vice versa! */
  if (optype0 == REGOP && optype1 == REGOP)
      /* bogus - 64 bit cannot reside in CPU! */
      gcc_assert (!CPU_REG_P(REGNO(operands[0]))
		  && !CPU_REG_P (REGNO(operands[1])));
  
  if (optype0 == REGOP || optype1 == REGOP)
  {
      /* check for use of clrd???? 
         if you ever allow ac4 and ac5 (now we require secondary load) 
	 you must check whether 
	 you want to load into them or store from them - 
	 then dump ac0 into $help$ movce ac4/5 to ac0, do the 
	 store from ac0, and restore ac0 - if you can find 
	 an unused ac[0-3], use that and you save a store and a load!*/

      if (FPU_REG_P(REGNO(operands[0])))
      {
	  if (GET_CODE(operands[1]) == CONST_DOUBLE)
	  {
	      REAL_VALUE_TYPE r;
	      REAL_VALUE_FROM_CONST_DOUBLE (r, operands[1]);

	      if (REAL_VALUES_EQUAL (r, dconst0))
		  return "{clrd|clrf} %0";
	  }
	      
	  return "{ldd|movf} %1, %0";
      }
      
      if (FPU_REG_P(REGNO(operands[1])))
	  return "{std|movf} %1, %0";
  }
      
  /* If one operand is decrementing and one is incrementing
     decrement the former register explicitly
     and change that operand into ordinary indexing.  */

  if (optype0 == PUSHOP && optype1 == POPOP)
    {
      operands[0] = XEXP (XEXP (operands[0], 0), 0);
      output_asm_insn ("sub $8,%0", operands);
      operands[0] = gen_rtx_MEM (DImode, operands[0]);
      optype0 = OFFSOP;
    }
  if (optype0 == POPOP && optype1 == PUSHOP)
    {
      operands[1] = XEXP (XEXP (operands[1], 0), 0);
      output_asm_insn ("sub $8,%1", operands);
      operands[1] = gen_rtx_MEM (SImode, operands[1]);
      optype1 = OFFSOP;
    }

  /* If an operand is an unoffsettable memory ref, find a register
     we can increment temporarily to make it refer to the second word.  */

  if (optype0 == MEMOP)
    addreg0 = find_addr_reg (XEXP (operands[0], 0));

  if (optype1 == MEMOP)
    addreg1 = find_addr_reg (XEXP (operands[1], 0));

  /* Ok, we can do one word at a time.
     Normally we do the low-numbered word first,
     but if either operand is autodecrementing then we
     do the high-numbered word first.

     In either case, set up in LATEHALF the operands to use
     for the high-numbered word and in some cases alter the
     operands in OPERANDS to be suitable for the low-numbered word.  */

  if (optype0 == REGOP)
    latehalf[0] = gen_rtx_REG (SImode, REGNO (operands[0]) + 2);
  else if (optype0 == OFFSOP)
    latehalf[0] = adjust_address (operands[0], SImode, 4);
  else
    latehalf[0] = operands[0];

  if (optype1 == REGOP)
    latehalf[1] = gen_rtx_REG (SImode, REGNO (operands[1]) + 2);
  else if (optype1 == OFFSOP)
    latehalf[1] = adjust_address (operands[1], SImode, 4);
  else if (optype1 == CNSTOP)
    {
      if (GET_CODE (operands[1]) == CONST_DOUBLE)
	{
	  REAL_VALUE_TYPE r;
	  long dval[2];
	  REAL_VALUE_FROM_CONST_DOUBLE (r, operands[1]);
	  REAL_VALUE_TO_TARGET_DOUBLE (r, dval);
	  latehalf[1] = GEN_INT (dval[1]);
	  operands[1] = GEN_INT	(dval[0]);
	}
      else if (GET_CODE(operands[1]) == CONST_INT)
	{
	  latehalf[1] = const0_rtx;
	}
      else
	gcc_unreachable ();
    }
  else
    latehalf[1] = operands[1];

  /* If insn is effectively movd N(sp),-(sp) then we will do the
     high word first.  We should use the adjusted operand 1 (which is N+4(sp))
     for the low word as well, to compensate for the first decrement of sp.  */
  if (optype0 == PUSHOP
      && REGNO (XEXP (XEXP (operands[0], 0), 0)) == STACK_POINTER_REGNUM
      && reg_overlap_mentioned_p (stack_pointer_rtx, operands[1]))
    operands[1] = latehalf[1];

  /* If one or both operands autodecrementing,
     do the two words, high-numbered first.  */

  /* Likewise,  the first move would clobber the source of the second one,
     do them in the other order.  This happens only for registers;
     such overlap can't happen in memory unless the user explicitly
     sets it up, and that is an undefined circumstance.  */

  if (optype0 == PUSHOP || optype1 == PUSHOP
      || (optype0 == REGOP && optype1 == REGOP
	  && REGNO (operands[0]) == REGNO (latehalf[1])))
    {
      /* Make any unoffsettable addresses point at high-numbered word.  */
      if (addreg0)
	output_asm_insn ("add $4,%0", &addreg0);
      if (addreg1)
	output_asm_insn ("add $4,%0", &addreg1);

      /* Do that word.  */
      output_asm_insn(output_move_double(latehalf), latehalf);

      /* Undo the adds we just did.  */
      if (addreg0)
	output_asm_insn ("sub $4,%0", &addreg0);
      if (addreg1)
	output_asm_insn ("sub $4,%0", &addreg1);

      /* Do low-numbered word.  */
      return output_move_double (operands);
    }

  /* Normal case: do the two words, low-numbered first.  */

  output_asm_insn (output_move_double (operands), operands);

  /* Make any unoffsettable addresses point at high-numbered word.  */
  if (addreg0)
    output_asm_insn ("add $4,%0", &addreg0);
  if (addreg1)
    output_asm_insn ("add $4,%0", &addreg1);

  /* Do that word.  */
  output_asm_insn (output_move_double (latehalf), latehalf);

  /* Undo the adds we just did.  */
  if (addreg0)
    output_asm_insn ("sub $4,%0", &addreg0);
  if (addreg1)
    output_asm_insn ("sub $4,%0", &addreg1);

  return "";
}


/* Return a REG that occurs in ADDR with coefficient 1.
   ADDR can be effectively incremented by incrementing REG.  */

static rtx
find_addr_reg (rtx addr)
{
  while (GET_CODE (addr) == PLUS)
    {
      if (GET_CODE (XEXP (addr, 0)) == REG)
	addr = XEXP (addr, 0);
      if (GET_CODE (XEXP (addr, 1)) == REG)
	addr = XEXP (addr, 1);
      if (CONSTANT_P (XEXP (addr, 0)))
	addr = XEXP (addr, 1);
      if (CONSTANT_P (XEXP (addr, 1)))
	addr = XEXP (addr, 0);
    }
  if (GET_CODE (addr) == REG)
    return addr;
  return 0;
}

/* Output an ascii string.  */
void
output_ascii (FILE *file, const char *p, int size)
{
  int i;

  /* This used to output .byte "string", which doesn't work with the UNIX
     assembler and I think not with DEC ones either.  */
  fprintf (file, "\t.byte ");

  for (i = 0; i < size; i++)
    {
      register int c = p[i];
      if (c < 0)
	c += 256;
      fprintf (file, "%#o", c);
      if (i < size - 1)
	putc (',', file);
    }
  putc ('\n', file);
}


/* --- stole from out-vax, needs changes */

void
print_operand_address (FILE *file, register rtx addr)
{
  register rtx reg1, reg2, breg, ireg;
  rtx offset;

 retry:

  switch (GET_CODE (addr))
    {
    case MEM:
      if (TARGET_UNIX_ASM)
	fprintf (file, "*");
      else
	fprintf (file, "@");
      addr = XEXP (addr, 0);
      goto retry;

    case REG:
      fprintf (file, "(%s)", reg_names[REGNO (addr)]);
      break;

    case PRE_MODIFY:
    case PRE_DEC:
      fprintf (file, "-(%s)", reg_names[REGNO (XEXP (addr, 0))]);
      break;

    case POST_MODIFY:
    case POST_INC:
      fprintf (file, "(%s)+", reg_names[REGNO (XEXP (addr, 0))]);
      break;

    case PLUS:
      reg1 = 0;	reg2 = 0;
      ireg = 0;	breg = 0;
      offset = 0;
      if (CONSTANT_ADDRESS_P (XEXP (addr, 0))
	  || GET_CODE (XEXP (addr, 0)) == MEM)
	{
	  offset = XEXP (addr, 0);
	  addr = XEXP (addr, 1);
	}
      else if (CONSTANT_ADDRESS_P (XEXP (addr, 1))
	       || GET_CODE (XEXP (addr, 1)) == MEM)
	{
	  offset = XEXP (addr, 1);
	  addr = XEXP (addr, 0);
	}
      if (GET_CODE (addr) != PLUS)
	;
      else if (GET_CODE (XEXP (addr, 0)) == MULT)
	{
	  reg1 = XEXP (addr, 0);
	  addr = XEXP (addr, 1);
	}
      else if (GET_CODE (XEXP (addr, 1)) == MULT)
	{
	  reg1 = XEXP (addr, 1);
	  addr = XEXP (addr, 0);
	}
      else if (GET_CODE (XEXP (addr, 0)) == REG)
	{
	  reg1 = XEXP (addr, 0);
	  addr = XEXP (addr, 1);
	}
      else if (GET_CODE (XEXP (addr, 1)) == REG)
	{
	  reg1 = XEXP (addr, 1);
	  addr = XEXP (addr, 0);
	}
      if (GET_CODE (addr) == REG || GET_CODE (addr) == MULT)
	{
	  if (reg1 == 0)
	    reg1 = addr;
	  else
	    reg2 = addr;
	  addr = 0;
	}
      if (offset != 0)
	{
	  gcc_assert (addr == 0);
	  addr = offset;
	}
      if (reg1 != 0 && GET_CODE (reg1) == MULT)
	{
	  breg = reg2;
	  ireg = reg1;
	}
      else if (reg2 != 0 && GET_CODE (reg2) == MULT)
	{
	  breg = reg1;
	  ireg = reg2;
	}
      else if (reg2 != 0 || GET_CODE (addr) == MEM)
	{
	  breg = reg2;
	  ireg = reg1;
	}
      else
	{
	  breg = reg1;
	  ireg = reg2;
	}
      if (addr != 0)
	output_address (addr);
      if (breg != 0)
	{
	  gcc_assert (GET_CODE (breg) == REG);
	  fprintf (file, "(%s)", reg_names[REGNO (breg)]);
	}
      if (ireg != 0)
	{
	  if (GET_CODE (ireg) == MULT)
	    ireg = XEXP (ireg, 0);
	  gcc_assert (GET_CODE (ireg) == REG);
	  gcc_unreachable(); /* ??? */
	  fprintf (file, "[%s]", reg_names[REGNO (ireg)]);
	}
      break;

    default:
      output_addr_const_pdp11 (file, addr);
    }
}

/* Target hook to assemble integer objects.  We need to use the
   pdp-specific version of output_addr_const.  */

static bool
pdp11_assemble_integer (rtx x, unsigned int size, int aligned_p)
{
  if (aligned_p)
    switch (size)
      {
      case 1:
	fprintf (asm_out_file, "\t.byte\t");
	output_addr_const_pdp11 (asm_out_file, x);
	fprintf (asm_out_file, " /* char */\n");
	return true;

      case 2:
	fprintf (asm_out_file, TARGET_UNIX_ASM ? "\t" : "\t.word\t");
	output_addr_const_pdp11 (asm_out_file, x);
	fprintf (asm_out_file, " /* short */\n");
	return true;
      }
  return default_assemble_integer (x, size, aligned_p);
}


/* register move costs, indexed by regs */

static const int move_costs[N_REG_CLASSES][N_REG_CLASSES] = 
{
             /* NO  MUL  GEN  LFPU  NLFPU FPU ALL */

/* NO */     {  0,   0,   0,    0,    0,    0,   0},
/* MUL */    {  0,   2,   2,   10,   22,   22,  22},
/* GEN */    {  0,   2,   2,   10,   22,   22,  22},
/* LFPU */   {  0,  10,  10,    2,    2,    2,  10},
/* NLFPU */  {  0,  22,  22,    2,    2,    2,  22},
/* FPU */    {  0,  22,  22,    2,    2,    2,  22},
/* ALL */    {  0,  22,  22,   10,   22,   22,  22}
}  ;


/* -- note that some moves are tremendously expensive, 
   because they require lots of tricks! do we have to 
   charge the costs incurred by secondary reload class 
   -- as we do here with 22 -- or not ? */

int 
pdp11_register_move_cost (enum reg_class c1, enum reg_class c2)
{
    return move_costs[(int)c1][(int)c2];
}

static bool
pdp11_rtx_costs (rtx x, int code, int outer_code ATTRIBUTE_UNUSED, int *total,
		 bool speed ATTRIBUTE_UNUSED)
{
  switch (code)
    {
    case CONST_INT:
      if (INTVAL (x) == 0 || INTVAL (x) == -1 || INTVAL (x) == 1)
	{
	  *total = 0;
	  return true;
	}
      /* FALLTHRU */

    case CONST:
    case LABEL_REF:
    case SYMBOL_REF:
      /* Twice as expensive as REG.  */
      *total = 2;
      return true;

    case CONST_DOUBLE:
      /* Twice (or 4 times) as expensive as 16 bit.  */
      *total = 4;
      return true;

    case MULT:
      /* ??? There is something wrong in MULT because MULT is not 
         as cheap as total = 2 even if we can shift!  */
      /* If optimizing for size make mult etc cheap, but not 1, so when 
         in doubt the faster insn is chosen.  */
      if (optimize_size)
        *total = COSTS_N_INSNS (2);
      else
        *total = COSTS_N_INSNS (11);
      return false;

    case DIV:
      if (optimize_size)
        *total = COSTS_N_INSNS (2);
      else
        *total = COSTS_N_INSNS (25);
      return false;

    case MOD:
      if (optimize_size)
        *total = COSTS_N_INSNS (2);
      else
        *total = COSTS_N_INSNS (26);
      return false;

    case ABS:
      /* Equivalent to length, so same for optimize_size.  */
      *total = COSTS_N_INSNS (3);
      return false;

    case ZERO_EXTEND:
      /* Only used for qi->hi.  */
      *total = COSTS_N_INSNS (1);
      return false;

    case SIGN_EXTEND:
      if (GET_MODE (x) == HImode)
      	*total = COSTS_N_INSNS (1);
      else if (GET_MODE (x) == SImode)
	*total = COSTS_N_INSNS (6);
      else
	*total = COSTS_N_INSNS (2);
      return false;

    case ASHIFT:
    case LSHIFTRT:
    case ASHIFTRT:
      if (optimize_size)
        *total = COSTS_N_INSNS (1);
      else if (GET_MODE (x) ==  QImode)
        {
          if (GET_CODE (XEXP (x, 1)) != CONST_INT)
   	    *total = COSTS_N_INSNS (8); /* worst case */
          else
	    *total = COSTS_N_INSNS (INTVAL (XEXP (x, 1)));
        }
      else if (GET_MODE (x) == HImode)
        {
          if (GET_CODE (XEXP (x, 1)) == CONST_INT)
            {
	      if (abs (INTVAL (XEXP (x, 1))) == 1)
                *total = COSTS_N_INSNS (1);
              else
	        *total = COSTS_N_INSNS (2.5 + 0.5 * INTVAL (XEXP (x, 1)));
            }
          else
            *total = COSTS_N_INSNS (10); /* worst case */
        }
      else if (GET_MODE (x) == SImode)
        {
          if (GET_CODE (XEXP (x, 1)) == CONST_INT)
	    *total = COSTS_N_INSNS (2.5 + 0.5 * INTVAL (XEXP (x, 1)));
          else /* worst case */
            *total = COSTS_N_INSNS (18);
        }
      return false;

    default:
      return false;
    }
}

const char *
output_jump (enum rtx_code code, int inv, int length)
{
    static int x = 0;
    
    static char buf[1000];
    const char *pos, *neg;

    switch (code)
      {
      case EQ: pos = "beq", neg = "bne"; break;
      case NE: pos = "bne", neg = "beq"; break;
      case GT: pos = "bgt", neg = "ble"; break;
      case GTU: pos = "bhi", neg = "blos"; break;
      case LT: pos = "blt", neg = "bge"; break;
      case LTU: pos = "blo", neg = "bhis"; break;
      case GE: pos = "bge", neg = "blt"; break;
      case GEU: pos = "bhis", neg = "blo"; break;
      case LE: pos = "ble", neg = "bgt"; break;
      case LEU: pos = "blos", neg = "bhi"; break;
      default: gcc_unreachable ();
      }

#if 0
/* currently we don't need this, because the tstdf and cmpdf 
   copy the condition code immediately, and other float operations are not 
   yet recognized as changing the FCC - if so, then the length-cost of all
   jump insns increases by one, because we have to potentially copy the 
   FCC! */
    if (cc_status.flags & CC_IN_FPU)
	output_asm_insn("cfcc", NULL);
#endif
	
    switch (length)
    {
      case 1:
	
	sprintf(buf, "%s %%l1", inv ? neg : pos);
	
	return buf;
	
      case 3:
	
	sprintf(buf, "%s JMP_%d\n\tjmp %%l1\nJMP_%d:", inv ? pos : neg, x, x);
	
	x++;
	
	return buf;
	
      default:
	
	gcc_unreachable ();
    }
    
}

void
notice_update_cc_on_set(rtx exp, rtx insn ATTRIBUTE_UNUSED)
{
    if (GET_CODE (SET_DEST (exp)) == CC0)
    { 
	cc_status.flags = 0;					
	cc_status.value1 = SET_DEST (exp);			
	cc_status.value2 = SET_SRC (exp);			

/*
	if (GET_MODE(SET_SRC(exp)) == DFmode)
	    cc_status.flags |= CC_IN_FPU;
*/	
    }							
    else if ((GET_CODE (SET_DEST (exp)) == REG		
	      || GET_CODE (SET_DEST (exp)) == MEM)		
	     && GET_CODE (SET_SRC (exp)) != PC		
	     && (GET_MODE (SET_DEST(exp)) == HImode		
		 || GET_MODE (SET_DEST(exp)) == QImode)	
		&& (GET_CODE (SET_SRC(exp)) == PLUS		
		    || GET_CODE (SET_SRC(exp)) == MINUS	
		    || GET_CODE (SET_SRC(exp)) == AND	
		    || GET_CODE (SET_SRC(exp)) == IOR	
		    || GET_CODE (SET_SRC(exp)) == XOR	
		    || GET_CODE (SET_SRC(exp)) == NOT	
		    || GET_CODE (SET_SRC(exp)) == NEG	
			|| GET_CODE (SET_SRC(exp)) == REG	
		    || GET_CODE (SET_SRC(exp)) == MEM))	
    { 
	cc_status.flags = 0;					
	cc_status.value1 = SET_SRC (exp);   			
	cc_status.value2 = SET_DEST (exp);			
	
	if (cc_status.value1 && GET_CODE (cc_status.value1) == REG	
	    && cc_status.value2					
	    && reg_overlap_mentioned_p (cc_status.value1, cc_status.value2))
    	    cc_status.value2 = 0;					
	if (cc_status.value1 && GET_CODE (cc_status.value1) == MEM	
	    && cc_status.value2					
	    && GET_CODE (cc_status.value2) == MEM)			
	    cc_status.value2 = 0; 					
    }							
    else if (GET_CODE (SET_SRC (exp)) == CALL)		
    { 
	CC_STATUS_INIT; 
    }
    else if (GET_CODE (SET_DEST (exp)) == REG)       		
	/* what's this ? */					
    { 
	if ((cc_status.value1					
	     && reg_overlap_mentioned_p (SET_DEST (exp), cc_status.value1)))
	    cc_status.value1 = 0;				
	if ((cc_status.value2					
	     && reg_overlap_mentioned_p (SET_DEST (exp), cc_status.value2)))
	    cc_status.value2 = 0;				
    }							
    else if (SET_DEST(exp) == pc_rtx)
    { 
	/* jump */
    }
    else /* if (GET_CODE (SET_DEST (exp)) == MEM)	*/	
    {  
	/* the last else is a bit paranoiac, but since nearly all instructions 
	   play with condition codes, it's reasonable! */

	CC_STATUS_INIT; /* paranoia*/ 
    }		        
}


int
simple_memory_operand(rtx op, enum machine_mode mode ATTRIBUTE_UNUSED)
{
    rtx addr;

    /* Eliminate non-memory operations */
    if (GET_CODE (op) != MEM)
	return FALSE;

#if 0
    /* dword operations really put out 2 instructions, so eliminate them.  */
    if (GET_MODE_SIZE (GET_MODE (op)) > (HAVE_64BIT_P () ? 8 : 4))
	return FALSE;
#endif

    /* Decode the address now.  */

  indirection:
    
    addr = XEXP (op, 0);

    switch (GET_CODE (addr))
    {
      case REG:
	/* (R0) - no extra cost */
	return 1;
	
      case PRE_DEC:
      case POST_INC:
	/* -(R0), (R0)+ - cheap! */
	return 0;
	
      case MEM:
	/* cheap - is encoded in addressing mode info! 

	   -- except for @(R0), which has to be @0(R0) !!! */

	if (GET_CODE (XEXP (addr, 0)) == REG)
	    return 0;
	
	op=addr;
	goto indirection;
	
      case CONST_INT:
      case LABEL_REF:	       
      case CONST:
      case SYMBOL_REF:
	/* @#address - extra cost */
	return 0;

      case PLUS:
	/* X(R0) - extra cost */
	return 0;

      default:
	break;
    }
    
    return FALSE;
}


/*
 * output a block move:
 *
 * operands[0]	... to
 * operands[1]  ... from
 * operands[2]  ... length
 * operands[3]  ... alignment
 * operands[4]  ... scratch register
 */

 
const char *
output_block_move(rtx *operands)
{
    static int count = 0;
    char buf[200];
    
    if (GET_CODE(operands[2]) == CONST_INT
	&& ! optimize_size)
    {
	if (INTVAL(operands[2]) < 16
	    && INTVAL(operands[3]) == 1)
	{
	    register int i;
	    
	    for (i = 1; i <= INTVAL(operands[2]); i++)
		output_asm_insn("movb (%1)+, (%0)+", operands);

	    return "";
	}
	else if (INTVAL(operands[2]) < 32)
	{
	    register int i;
	    
	    for (i = 1; i <= INTVAL(operands[2])/2; i++)
		output_asm_insn("mov (%1)+, (%0)+", operands);
	    
	    /* may I assume that moved quantity is 
	       multiple of alignment ???

	       I HOPE SO !
	    */

	    return "";
	}
	

	/* can do other clever things, maybe... */
    }

    if (CONSTANT_P(operands[2]) )
    {
	/* just move count to scratch */
	output_asm_insn("mov %2, %4", operands);
    }
    else
    {
	/* just clobber the register */
	operands[4] = operands[2];
    }
    

    /* switch over alignment */
    switch (INTVAL(operands[3]))
    {
      case 1:
	
	/* 
	  x:
	  movb (%1)+, (%0)+
	  
	  if (TARGET_45)
	     sob %4,x
	  else
	     dec %4
	     bgt x

	*/

	sprintf(buf, "\nmovestrhi%d:", count);
	output_asm_insn(buf, NULL);
	
	output_asm_insn("movb (%1)+, (%0)+", operands);
	
	if (TARGET_45)
	{
	    sprintf(buf, "sob %%4, movestrhi%d", count);
	    output_asm_insn(buf, operands);
	}
	else
	{
	    output_asm_insn("dec %4", operands);
	    
	    sprintf(buf, "bgt movestrhi%d", count);
	    output_asm_insn(buf, NULL);
	}
	
	count ++;
	break;
	
      case 2:
	
	/* 
	   asr %4

	   x:

	   mov (%1)+, (%0)+

	   if (TARGET_45)
	     sob %4, x
	   else
	     dec %4
	     bgt x
	*/

      generate_compact_code:

	output_asm_insn("asr %4", operands);

	sprintf(buf, "\nmovestrhi%d:", count);
	output_asm_insn(buf, NULL);
	
	output_asm_insn("mov (%1)+, (%0)+", operands);
	
	if (TARGET_45)
	{
	    sprintf(buf, "sob %%4, movestrhi%d", count);
	    output_asm_insn(buf, operands);
	}
	else
	{
	    output_asm_insn("dec %4", operands);
	    
	    sprintf(buf, "bgt movestrhi%d", count);
	    output_asm_insn(buf, NULL);
	}
	
	count ++;
	break;

      case 4:
	
	/*

	   asr %4
	   asr %4

	   x:

	   mov (%1)+, (%0)+
	   mov (%1)+, (%0)+

	   if (TARGET_45)
	     sob %4, x
	   else
	     dec %4
	     bgt x
	*/

	if (optimize_size)
	    goto generate_compact_code;
	
	output_asm_insn("asr %4", operands);
	output_asm_insn("asr %4", operands);

	sprintf(buf, "\nmovestrhi%d:", count);
	output_asm_insn(buf, NULL);
	
	output_asm_insn("mov (%1)+, (%0)+", operands);
	output_asm_insn("mov (%1)+, (%0)+", operands);
	
	if (TARGET_45)
	{
	    sprintf(buf, "sob %%4, movestrhi%d", count);
	    output_asm_insn(buf, operands);
	}
	else
	{
	    output_asm_insn("dec %4", operands);
	    
	    sprintf(buf, "bgt movestrhi%d", count);
	    output_asm_insn(buf, NULL);
	}
	
	count ++;
	break;
       
      default:
	
	/*
	   
	   asr %4
	   asr %4
	   asr %4

	   x:

	   mov (%1)+, (%0)+
	   mov (%1)+, (%0)+
	   mov (%1)+, (%0)+
	   mov (%1)+, (%0)+
	   
	   if (TARGET_45)
	     sob %4, x
	   else
	     dec %4
	     bgt x
	*/


	if (optimize_size)
	    goto generate_compact_code;
	
	output_asm_insn("asr %4", operands);
	output_asm_insn("asr %4", operands);
	output_asm_insn("asr %4", operands);

	sprintf(buf, "\nmovestrhi%d:", count);
	output_asm_insn(buf, NULL);
	
	output_asm_insn("mov (%1)+, (%0)+", operands);
	output_asm_insn("mov (%1)+, (%0)+", operands);
	output_asm_insn("mov (%1)+, (%0)+", operands);
	output_asm_insn("mov (%1)+, (%0)+", operands);
	
	if (TARGET_45)
	{
	    sprintf(buf, "sob %%4, movestrhi%d", count);
	    output_asm_insn(buf, operands);
	}
	else
	{
	    output_asm_insn("dec %4", operands);
	    
	    sprintf(buf, "bgt movestrhi%d", count);
	    output_asm_insn(buf, NULL);
	}
	
	count ++;
	break;
	
	;
	
    }
    
    return "";
}

/* This function checks whether a real value can be encoded as
   a literal, i.e., addressing mode 27.  In that mode, real values
   are one word values, so the remaining 48 bits have to be zero.  */
int
legitimate_const_double_p (rtx address)
{
  REAL_VALUE_TYPE r;
  long sval[2];
  REAL_VALUE_FROM_CONST_DOUBLE (r, address);
  REAL_VALUE_TO_TARGET_DOUBLE (r, sval);
  if ((sval[0] & 0xffff) == 0 && sval[1] == 0)
    return 1;
  return 0;
}

/* A copy of output_addr_const modified for pdp11 expression syntax.
   output_addr_const also gets called for %cDIGIT and %nDIGIT, which we don't
   use, and for debugging output, which we don't support with this port either.
   So this copy should get called whenever needed.
*/
void
output_addr_const_pdp11 (FILE *file, rtx x)
{
  char buf[256];

 restart:
  switch (GET_CODE (x))
    {
    case PC:
      gcc_assert (flag_pic);
      putc ('.', file);
      break;

    case SYMBOL_REF:
      assemble_name (file, XSTR (x, 0));
      break;

    case LABEL_REF:
      ASM_GENERATE_INTERNAL_LABEL (buf, "L", CODE_LABEL_NUMBER (XEXP (x, 0)));
      assemble_name (file, buf);
      break;

    case CODE_LABEL:
      ASM_GENERATE_INTERNAL_LABEL (buf, "L", CODE_LABEL_NUMBER (x));
      assemble_name (file, buf);
      break;

    case CONST_INT:
      /* Should we check for constants which are too big?  Maybe cutting
	 them off to 16 bits is OK?  */
      fprintf (file, "%#ho", (unsigned short) INTVAL (x));
      break;

    case CONST:
      /* This used to output parentheses around the expression,
	 but that does not work on the 386 (either ATT or BSD assembler).  */
      output_addr_const_pdp11 (file, XEXP (x, 0));
      break;

    case CONST_DOUBLE:
      if (GET_MODE (x) == VOIDmode)
	{
	  /* We can use %o if the number is one word and positive.  */
	  gcc_assert (!CONST_DOUBLE_HIGH (x));
	  fprintf (file, "%#ho", (unsigned short) CONST_DOUBLE_LOW (x));
	}
      else
	/* We can't handle floating point constants;
	   PRINT_OPERAND must handle them.  */
	output_operand_lossage ("floating constant misused");
      break;

    case PLUS:
      /* Some assemblers need integer constants to appear last (e.g. masm).  */
      if (GET_CODE (XEXP (x, 0)) == CONST_INT)
	{
	  output_addr_const_pdp11 (file, XEXP (x, 1));
	  if (INTVAL (XEXP (x, 0)) >= 0)
	    fprintf (file, "+");
	  output_addr_const_pdp11 (file, XEXP (x, 0));
	}
      else
	{
	  output_addr_const_pdp11 (file, XEXP (x, 0));
	  if (INTVAL (XEXP (x, 1)) >= 0)
	    fprintf (file, "+");
	  output_addr_const_pdp11 (file, XEXP (x, 1));
	}
      break;

    case MINUS:
      /* Avoid outputting things like x-x or x+5-x,
	 since some assemblers can't handle that.  */
      x = simplify_subtraction (x);
      if (GET_CODE (x) != MINUS)
	goto restart;

      output_addr_const_pdp11 (file, XEXP (x, 0));
      fprintf (file, "-");
      if (GET_CODE (XEXP (x, 1)) == CONST_INT
	  && INTVAL (XEXP (x, 1)) < 0)
	{
	  fprintf (file, targetm.asm_out.open_paren);
	  output_addr_const_pdp11 (file, XEXP (x, 1));
	  fprintf (file, targetm.asm_out.close_paren);
	}
      else
	output_addr_const_pdp11 (file, XEXP (x, 1));
      break;

    case ZERO_EXTEND:
    case SIGN_EXTEND:
      output_addr_const_pdp11 (file, XEXP (x, 0));
      break;

    default:
      output_operand_lossage ("invalid expression as operand");
    }
}

/* Worker function for TARGET_RETURN_IN_MEMORY.  */

static bool
pdp11_return_in_memory (const_tree type, const_tree fntype ATTRIBUTE_UNUSED)
{
  /* Should probably return DImode and DFmode in memory, lest
     we fill up all regs!

     have to, else we crash - exception: maybe return result in 
     ac0 if DFmode and FPU present - compatibility problem with
     libraries for non-floating point....  */
  return (TYPE_MODE (type) == DImode
	  || (TYPE_MODE (type) == DFmode && ! TARGET_AC0));
}

/* Worker function for TARGET_FUNCTION_VALUE.

   On the pdp11 the value is found in R0 (or ac0??? not without FPU!!!! )  */

static rtx
pdp11_function_value (const_tree valtype, 
 		      const_tree fntype_or_decl ATTRIBUTE_UNUSED,
 		      bool outgoing ATTRIBUTE_UNUSED)
{
  return gen_rtx_REG (TYPE_MODE (valtype),
		      BASE_RETURN_VALUE_REG(TYPE_MODE(valtype)));
}

/* Worker function for TARGET_LIBCALL_VALUE.  */

static rtx
pdp11_libcall_value (enum machine_mode mode,
                     const_rtx fun ATTRIBUTE_UNUSED)
{
  return  gen_rtx_REG (mode, BASE_RETURN_VALUE_REG(mode));
}

/* Worker function for TARGET_FUNCTION_VALUE_REGNO_P.

   On the pdp, the first "output" reg is the only register thus used.

   maybe ac0 ? - as option someday!  */

static bool
pdp11_function_value_regno_p (const unsigned int regno)
{
  return (regno == 0) || (TARGET_AC0 && (regno == 8));
}

/* Worker function for TARGET_TRAMPOLINE_INIT.

   trampoline - how should i do it in separate i+d ? 
   have some allocate_trampoline magic??? 

   the following should work for shared I/D:

   MV	#STATIC, $4	0x940Y	0x0000 <- STATIC; Y = STATIC_CHAIN_REGNUM
   JMP	FUNCTION	0x0058  0x0000 <- FUNCTION
*/

static void
pdp11_trampoline_init (rtx m_tramp, tree fndecl, rtx chain_value)
{
  rtx fnaddr = XEXP (DECL_RTL (fndecl), 0);
  rtx mem;

  gcc_assert (!TARGET_SPLIT);

  mem = adjust_address (m_tramp, HImode, 0);
  emit_move_insn (mem, GEN_INT (0x9400+STATIC_CHAIN_REGNUM));
  mem = adjust_address (m_tramp, HImode, 2);
  emit_move_insn (mem, chain_value);
  mem = adjust_address (m_tramp, HImode, 4);
  emit_move_insn (mem, GEN_INT (0x0058));
  emit_move_insn (mem, fnaddr);
}

/* Worker function for TARGET_FUNCTION_ARG.

   Determine where to put an argument to a function.
   Value is zero to push the argument on the stack,
   or a hard register in which to store the argument.

   MODE is the argument's machine mode.
   TYPE is the data type of the argument (as a tree).
    This is null for libcalls where that information may
    not be available.
   CUM is a variable of type CUMULATIVE_ARGS which gives info about
    the preceding args and about the function being called.
   NAMED is nonzero if this argument is a named parameter
    (otherwise it is an extra parameter matching an ellipsis).  */

static rtx
pdp11_function_arg (CUMULATIVE_ARGS *cum ATTRIBUTE_UNUSED,
		    enum machine_mode mode ATTRIBUTE_UNUSED,
		    const_tree type ATTRIBUTE_UNUSED,
		    bool named ATTRIBUTE_UNUSED)
{
  return NULL_RTX;
}

/* Worker function for TARGET_FUNCTION_ARG_ADVANCE.

   Update the data in CUM to advance over an argument of mode MODE and
   data type TYPE.  (TYPE is null for libcalls where that information
   may not be available.)  */

static void
pdp11_function_arg_advance (CUMULATIVE_ARGS *cum, enum machine_mode mode,
			    const_tree type, bool named ATTRIBUTE_UNUSED)
{
  *cum += (mode != BLKmode
	   ? GET_MODE_SIZE (mode)
	   : int_size_in_bytes (type));
}
