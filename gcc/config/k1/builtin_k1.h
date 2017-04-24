/*
 *      Copyright 2010, Kalray.
 *      All rights reserved.
 *
 * Kalray, INCORPORATED PROPRIETARY INFORMATION
 * This software is supplied under the terms of a license agreement
 * or nondisclosure agreement with Kalray and may not be
 * copied or disclosed except in accordance with the terms of that
 * agreement.
 */

/* Note on dedicated registers: as these registers are not allocated by the
 * compiler, it is necessary to pass the index of such register. When it is
 * passed as builtin operand, an immediate of the form 'u[0..n]' is expected in
 * place of dedicated register. 'n' is the size of the register file minus one.
 * When dedicated register is the result, one additional operand of the same
 * form 'u[0..n]' is placed as first parameter to select the result register
 * index.
 *
 * Note on immediates: some builtins may accept constant value as parameter.
 * Programmer must respect the immediate range given by the bits number and
 * signess. Immediates are given under the form '[su][0-9]+'
 * - [su] for signed and unsigned respectively.
 * - [0-9]+ the bits number associated to the immediate.
 */

/* Register classes used:
 * GPR: 64 General Purpose Regisers
 * PR: 32 Paired General Purpose Registers
 */

/* Builtins for class k1 */
#ifdef __K1__

#ifndef _BUILTIN_K1_H_
#define _BUILTIN_K1_H_

#ifdef __cplusplus__
extern "C" {
#endif

#if defined(__native__)
#include "builtins_k1_native.h"

#else /* include for k1-compilation */

/*
 * BCU Instructions
 */

/* AWAIT */
/* BARRIER */
extern void __builtin_k1_barrier (void);
/* BREAK */
/* CALL */
/* CB */
/* CDB */
/* CLEAR1 */
extern void __builtin_k1_clear1 (unsigned int event);
/* DOZE */
/* GET */
extern unsigned int __builtin_k1_get (int);
/* GOTO */
/* HFXB */
extern void __builtin_k1_hfxb (unsigned char, int);
/* HFXT */
extern void __builtin_k1_hfxt (unsigned char, int);
/* ICALL */
/* IGET */
/* IGOTO */
/* IGOTOD */
/* INVALDTLB */
extern void __builtin_k1_invaldtlb (void);
/* INVALITLB */
extern void __builtin_k1_invalitlb (void);
/* LOOPDO */
/* LOOPGTZ */
/* LOOPNEZ */
/* NOTIFY1 */
extern void __builtin_k1_notify1 (unsigned int);
/* PROBETLB */
extern void __builtin_k1_probetlb (void);
/* READTLB */
extern void __builtin_k1_readtlb (void);
/* RET */
/* RFE */
/* SCALL */
/* SET */
/* SLEEP */
/* STOP */
/* SYNCGROUP */
extern void __builtin_k1_syncgroup (unsigned int);
/* TRAPA */
/* TRAPO */
/* WAITANY */
extern unsigned int __builtin_k1_waitany (unsigned int, unsigned char);
/* WAITCLR1 */
extern void
__builtin_k1_waitclr1 (unsigned int /* event = event_reg * 32 + event_index */);
/* WANTANY */
extern unsigned int __builtin_k1_wantany (unsigned int, unsigned char);
/* WRITETLB */
extern void __builtin_k1_writetlb (void);

/*
 * LSU Instrutions
 */

/* ACWS */
extern unsigned long long __builtin_k1_acws (void *address,
					     unsigned int new_value,
					     unsigned int old_value);
/* ACWSU */
extern unsigned long long __builtin_k1_acwsu (void *address,
					      unsigned int new_value,
					      unsigned int old_value);
/* AFDA */
extern unsigned long long __builtin_k1_afda (void *address, long long addend);
/* AFDAU */
extern unsigned long long __builtin_k1_afdau (void *address, long long addend);
/* ALDC */
extern unsigned long long __builtin_k1_aldc (void *addr);
/* ALDCU */
extern unsigned long long __builtin_k1_aldcu (void *addr);
/* DINVAL */
extern void __builtin_k1_dinval (void);
/* DINVALL */
extern void __builtin_k1_dinvall (const void *addr);
static __inline__ __attribute__ ((deprecated)) void
__builtin_k1_dinvall_s10 (short a, unsigned int b)
{
  __builtin_k1_dinvall ((const void *) (a + b));
}
/* DTOUCHL */
extern void __builtin_k1_dtouchl (const void *addr);
static __inline__ __attribute__ ((deprecated)) void
__builtin_k1_dtouchl_s10 (short a, unsigned int b)
{
  __builtin_k1_dtouchl ((const void *) (a + b));
}
/* DZEROL */
extern void __builtin_k1_dzerol (void *addr);
static __inline__ __attribute__ ((deprecated)) void
__builtin_k1_dzerol_s10 (short a, unsigned int b)
{
  __builtin_k1_dzerol ((void *) (a + b));
}
/* DZEROLU */
/* FENCE */
extern void __builtin_k1_fence (void);
/* IINVAL */
extern void __builtin_k1_iinval (void);
/* IINVALS */
extern void __builtin_k1_iinvals (const void *addr);
/* LBQS */
extern unsigned long long __builtin_k1_lbqs (const void *addr);
/* LBQSN */
/* LBQSU */
extern unsigned long long __builtin_k1_lbqsu (const void *addr);
/* LBQSUN */
/* LBQZ */
extern unsigned long long __builtin_k1_lbqz (const void *addr);
static __inline__ __attribute__ ((deprecated)) long long
__builtin_k1_lbqz_s32_p (int a, int b)
{
  return __builtin_k1_lbqz ((const void *) (a + b));
}
/* LBQZN */
/* LBQZU */
extern unsigned long long __builtin_k1_lbqzu (const void *addr);
/* LBQZUN */
/* LBS */
/* LBSN */
/* LBSU */
extern signed char __builtin_k1_lbsu (const void *addr);
/* LBSUN */
/* LBZ */
/* LBZN */
/* LBZU */
extern unsigned char __builtin_k1_lbzu (const void *addr);
/* LBZUN */
/* LD */
/* LDN */
/* LDU */
extern unsigned long long __builtin_k1_ldu (const void *addr);
static __inline__ __attribute__ ((deprecated)) unsigned long long
__builtin_k1_ldu_s10_p (int s10, unsigned int addr)
{
  return __builtin_k1_ldu ((const void *) (addr + s10));
}
/* LDUN */
/* LHPS */
/* LHPSN */
/* LHPSU */
/* LHPSUN */
/* LHPZ */
/* LHPZN */
/* LHPZU */
/* LHPZUN */
/* LHS */
/* LHSN */
/* LHSU */
extern short __builtin_k1_lhsu (const void *addr);
/* LHSUN */
/* LHZ */
/* LHZN */
/* LHZU */
extern unsigned short __builtin_k1_lhzu (const void *addr);
/* LHZUN */
/* LW */
/* LWN */
/* LWU */
extern unsigned int __builtin_k1_lwu (const void *addr);
/* LWUN */
/* SB */
/* SBQ */
/* SBQU */
/* SD */
/* SH */
/* SHP */
/* SHPU */
/* SW */

/*
 * ALU Instruction (non-FPU)
 */

/* ABD */
/* ABDD */
/* ABDHP */
extern int __builtin_k1_abdhp (int op0_hp, int op1_hp);
/* ABDHQ */
/* ABDWP */
/* ABS */
/* ABSD */
/* ABSHP */
/* ABSHQ */
/* ABSWP */
/* ADD */
/* ADDC */
/* ADDCD */
/* ADDCI */
/* ADDCID */
/* ADDD */
/* ADDHP */
extern int __builtin_k1_addhp (int op0_hp, int op1_hp);
/* ADDHQ */
/* ADDHR */
/* ADDHRWP */
/* ADDS */
extern int __builtin_k1_adds (int op0, int op1);
/* ADDSD */
/* ADDSHP */
/* ADDSHQ */
/* ADDSWP */
/* ADDUHR */
/* ADDUHRWP */
/* ADDUWD */
/* ADDWD */
/* ADDWP */
/* ADDX2 */
/* ADDX2D */
/* ADDX2HP */
/* ADDX2HQ */
/* ADDX2UWD */
/* ADDX2WD */
/* ADDX2WP */
/* ADDX4 */
/* ADDX4D */
/* ADDX4HP */
/* ADDX4HQ */
/* ADDX4UWD */
/* ADDX4WD */
/* ADDX4WP */
/* ADDX8 */
/* ADDX8D */
/* ADDX8HP */
/* ADDX8HQ */
/* ADDX8UWD */
/* ADDX8WD */
/* ADDX8WP */
/* AND */
/* ANDD */
/* ANDHR */
/* ANDHRWP */
/* ANDN */
/* ANDND */
/* AVG */
/* AVGD */
/* AVGHP */
/* AVGHQ */
/* AVGR */
/* AVGRD */
/* AVGRHP */
/* AVGRHQ */
/* AVGRU */
/* AVGRUD */
/* AVGRUHP */
/* AVGRUHQ */
/* AVGRUWP */
/* AVGRWP */
/* AVGU */
/* AVGUD */
/* AVGUHP */
/* AVGUHQ */
/* AVGUWP */
/* AVGWP */
/* BWLU */
extern unsigned int __builtin_k1_bwlu (unsigned op0_a, unsigned op1_b,
				       unsigned op2_c, unsigned op3_d,
				       unsigned short op4_lut);
/* BWLUHP */
extern unsigned int __builtin_k1_bwluhp (unsigned int op0_hp_ab,
					 unsigned int op1_hp_cd,
					 unsigned int op2_hp_lut);
/* BWLUWP */
extern unsigned long long __builtin_k1_bwluwp (unsigned long long op0_wp_ab,
					       unsigned long long op1_wp_cd,
					       unsigned int op2_hp_lut);
/* CBS */
extern int __builtin_k1_cbs (unsigned int op0);
/* CBSDL */
extern int __builtin_k1_cbsdl (unsigned long long op0);
/* CBSWP */
/* CDMOVED */
/* CLS */
/* CLSDL */
/* CLSWP */
/* CLZ */
extern int __builtin_k1_clz (unsigned int op0);
/* CLZDL */
extern int __builtin_k1_clzdl (unsigned long long op0);
/* CLZWP */
/* CMOVE */
extern int __builtin_k1_cmove (int condition, int new_value, int curent_value);
/* CMOVED */
/* CMOVEHP */
/* CMOVEHQ */
/* CMOVEWP */
/* COMP */
/* COMPDL */
/* COMPHP */
/* COMPHQ */
/* COMPUWDL */
/* COMPWDL */
/* COMPWP */
/* CTZ */
extern int __builtin_k1_ctz (unsigned int op0);
/* CTZDL */
extern int __builtin_k1_ctzdl (unsigned long long op0);
/* CTZWP */
/* EXTFDS */
/* EXTFDZ */
extern unsigned int __builtin_k1_extfz (unsigned int op0,
					unsigned int op1_highbit,
					unsigned int op2_lowbit);
/* EXTFS */
/* EXTFZ */
/* INSF */
/* LAND */
/* LANDDL */
/* LANDHP */
extern int __builtin_k1_landhp (int, int);
/* LANDHQ */
/* LANDWP */
/* LNAND */
/* LNANDDL */
/* LNANDHP */
/* LNANDHQ */
/* LNANDWP */
/* LNOR */
/* LNORDL */
/* LNORHP */
/* LNORHQ */
/* LNORWP */
/* LOR */
/* LORDL */
/* LORHP */
/* LORHQ */
/* LORWP */
/* MAKE */
/* MAKED */
/* MAX */
/* MAXD */
/* MAXHP */
/* MAXHPS */
/* MAXHQ */
/* MAXHR */
/* MAXHRWP */
/* MAXS */
/* MAXU */
/* MAXUD */
/* MAXUHP */
/* MAXUHPS */
/* MAXUHQ */
/* MAXUHR */
/* MAXUHRWP */
/* MAXUS */
/* MAXUWP */
/* MAXWP */
/* MIN */
/* MIND */
/* MINHP */
/* MINHPS */
/* MINHQ */
/* MINHR */
/* MINHRWP */
/* MINS */
/* MINU */
/* MINUD */
/* MINUHP */
/* MINUHPS */
/* MINUHQ */
/* MINUHR */
/* MINUHRWP */
/* MINUS */
/* MINUWP */
/* MINWP */
/* NAND */
/* NANDD */
/* NEG */
/* NEGD */
/* NEGHP */
/* NEGHQ */
/* NEGWP */
/* NOR */
/* NORD */
/* NXOR */
/* NXORD */
/* OR */
/* ORD */
/* ORN */
/* ORND */
/* ROL */
/* ROLWPS */
/* ROR */
/* RORWPS */
/* SAT */
extern int __builtin_k1_sat (int, unsigned char);
/* SATD */
extern long long int __builtin_k1_satd (long long int, unsigned char);
/* SATDL */
/* SATU */
/* SATUD */
/* SATUDL */
/* SBF */
/* SBFC */
/* SBFCD */
/* SBFCI */
/* SBFCID */
/* SBFD */
/* SBFHP */
extern int __builtin_k1_sbfhp (int, int);
/* SBFHQ */
/* SBFS */
/* SBFSD */
/* SBFSHP */
/* SBFSHQ */
/* SBFSWP */
/* SBFUWD */
/* SBFWD */
/* SBFWP */
/* SBFX2 */
/* SBFX2D */
/* SBFX2HP */
/* SBFX2HQ */
/* SBFX2UWD */
/* SBFX2WD */
/* SBFX2WP */
/* SBFX4 */
/* SBFX4D */
/* SBFX4HP */
/* SBFX4HQ */
/* SBFX4UWD */
/* SBFX4WD */
/* SBFX4WP */
/* SBFX8 */
/* SBFX8D */
/* SBFX8HP */
/* SBFX8HQ */
/* SBFX8UWD */
/* SBFX8WD */
/* SBFX8WP */
/* SBMM8 */
extern unsigned long long __builtin_k1_sbmm8 (unsigned long long a,
					      unsigned long long b);
/* SBMM8L */
extern unsigned int __builtin_k1_sbmm8l (unsigned long long a,
					 unsigned long long b);
/* SBMMT8 */
extern unsigned long long __builtin_k1_sbmmt8 (unsigned long long a,
					       unsigned long long b);
/* SBMMT8L */
/* SLL */
/* SLLD */
/* SLLDM */
/* SLLHPS */
extern unsigned int __builtin_k1_sllhps (unsigned int, unsigned int);
/* SLLHQS */
/* SLLWPS */
/* SLS */
/* SLSD */
/* SLSHPS */
/* SLSHQS */
/* SLSWPS */
/* SRA */
/* SRAD */
/* SRADL */
/* SRAHPS */
extern unsigned int __builtin_k1_srahps (unsigned int, unsigned int);
/* SRAHQS */
/* SRAWPS */
/* SRL */
/* SRLD */
/* SRLDL */
/* SRLHPS */
/* SRLHQS */
/* SRLWPS */
/* SRS */
/* SRSD */
/* SRSHPS */
/* SRSHQS */
/* SRSWPS */
/* STSU */
extern unsigned int __builtin_k1_stsu (unsigned int, unsigned int);
/* STSUD */
extern unsigned long long __builtin_k1_stsud (unsigned long long,
					      unsigned long long);
/* SXBP */
/* SXBPWP */
/* SXBQ */
/* UPX10L0 */
/* UPX10L1 */
/* UPX10L2 */
/* UPX12L0 */
/* UPX12L1 */
/* XOR */
/* XORD */
/* XORHR */
/* XORHRWP */
/* ZXBP */
/* ZXBPWP */
/* ZXBQ */

/*
 * MAU Instructions (non-FPU)
 */

/* CMAHD */
/* CMAQHD */
/* CMASUHD */
/* CMAUUHD */
/* CMSHD */
/* CMSQHD */
/* CMSSUHD */
/* CMSUUHD */
/* DMAHD */
/* DMAQHD */
/* DMASUHD */
/* DMAUUHD */
/* DMSHD */
/* DMSQHD */
/* DMSSUHD */
/* DMSUUHD */
/* MADHWP */
/* MADQBWPRD */
/* MADQTWPRD */
/* MADQWPRD */
/* MADSUCIWD */
/* MADSUCWD */
/* MADSUHWP */
/* MADSUWD */
/* MADUUCIWD */
extern unsigned long long __builtin_k1_maduuciwd (unsigned long long,
						  unsigned int, unsigned int);
/* MADUUCWD */
/* MADUUHWP */
/* MADUUWD */
/* MADWD */
/* MSBHWP */
/* MSBQBWPRD */
/* MSBQTWPRD */
/* MSBQWPRD */
/* MSBSUHWP */
/* MSBSUWD */
/* MSBUUHWP */
/* MSBUUWD */
/* MSBWD */
/* MULBWDL */
/* MULHPSWP */
/* MULHWP */
/* MULQBBS */
/* MULQBTS */
/* MULQBWPRD */
/* MULQBWPRS */
/* MULQHPSPRSWP */
/* MULQHSWP */
/* MULQPRS */
/* MULQTBS */
/* MULQTTS */
/* MULQTWPRD */
/* MULQTWPRS */
/* MULQWPRD */
/* MULSUBWDL */
/* MULSUHPSWP */
/* MULSUHWP */
/* MULSUTWDL */
/* MULSUWD */
/* MULSUWDM */
/* MULTWDL */
/* MULUUBWDL */
/* MULUUHPSWP */
/* MULUUHWP */
/* MULUUTWDL */
/* MULUUWD */
/* MULUUWDM */
/* MULWD */
/* MULWDL */
/* MULWDM */

/*
 * FPU Instructions (ALU ans MAU)
 */

/* FABS */
/* FABSD */
/* FABSWP */
/* FADD */
/* FADDD */
/* FADDRN */
extern float __builtin_k1_faddrn (float op0, float op1);
/* FADDRND */
extern double __builtin_k1_faddrnd (double op0, double op1);
/* FADDRNWP */
/* FADDWP */
/* FCDIV */
extern float __builtin_k1_fcdiv (float dividend, float divisor);
/* FCDIVD */
/* FCDIVWP */
/* FCMA */
extern float __builtin_k1_fcma (float mult1_op0, float mult0_op0,
				float mult0_op1, float mult1_op1);
/* FCMAWD */
extern double __builtin_k1_fcmawd (float mult1_op0, float mult0_op0,
				   float mult0_op1, float mult1_op1);
/* FCMS */
extern float __builtin_k1_fcms (float mult1_op0, float mult0_op0,
				float mult0_op1, float mult1_op1);
/* FCMSWD */
extern double __builtin_k1_fcmswd (float mult1_op0, float mult0_op0,
				   float mult0_op1, float mult1_op1);
/* FCOMP */
/* FCOMPDL */
/* FCOMPWP */
/* FDMA */
extern float __builtin_k1_fdma (float mult0_op0, float mult1_op0,
				float mult0_op1, float mult1_op1);
/* FDMAWD */
extern double __builtin_k1_fdmawd (float mult0_op0, float mult1_op0,
				   float mult0_op1, float mult1_op1);
/* FDMS */
extern float __builtin_k1_fdms (float mult0_op0, float mult1_op0,
				float mult0_op1, float mult1_op1);
/* FDMSWD */
extern double __builtin_k1_fdmswd (float mult0_op0, float mult1_op0,
				   float mult0_op1, float mult1_op1);
/* FFMA */
extern float __builtin_k1_ffma (float addend, float mult_op0, float mult_op1);
/* FFMAD */
/* FFMAN */
extern float __builtin_k1_ffman (float addend, float mult_op0, float mult_op1);
/* FFMAND */
/* FFMANRN */
extern float __builtin_k1_ffmanrn (float addend, float mult_op0,
				   float mult_op1);
/* FFMANRND */
/* FFMANRNWD */
/* FFMANRNWP */
/* FFMANWD */
/* FFMANWP */
/* FFMARN */
extern float __builtin_k1_ffmarn (float addend, float mult_op0, float mult_op1);
/* FFMARND */
/* FFMARNWD */
/* FFMARNWP */
/* FFMAWD */
/* FFMAWP */
/* FFMS */
extern float __builtin_k1_ffms (float addend, float mult_op0, float mult_op1);
/* FFMSD */
/* FFMSN */
extern float __builtin_k1_ffmsn (float addend, float mult_op0, float mult_op1);
/* FFMSND */
/* FFMSNRN */
extern float __builtin_k1_ffmsnrn (float addend, float mult_op0,
				   float mult_op1);
/* FFMSNRND */
/* FFMSNRNWD */
/* FFMSNRNWP */
/* FFMSNWD */
/* FFMSNWP */
/* FFMSRN */
extern float __builtin_k1_ffmsrn (float addend, float mult_op0, float mult_op1);
/* FFMSRND */
/* FFMSRNWD */
/* FFMSRNWP */
/* FFMSWD */
/* FFMSWP */
/* FIXED */
extern int __builtin_k1_fixed (unsigned char rounding, float fp_32b_num,
			       unsigned char u6_coef);
/* FIXEDD */
extern long long __builtin_k1_fixedd (unsigned char rounding, double fp_64b_num,
				      unsigned char u6_coef);
/* FIXEDDN */
/* FIXEDN */
/* FIXEDU */
extern unsigned __builtin_k1_fixedu (unsigned char rounding, float fp_32b_num,
				     unsigned char u6_coef);
/* FIXEDUD */
extern unsigned long long __builtin_k1_fixedud (unsigned char rounding,
						double fp_64b_num,
						unsigned char u6_coef);
/* FIXEDUDN */
/* FIXEDUN */
/* FIXEDUWP */
/* FIXEDUWPN */
/* FIXEDWP */
/* FIXEDWPN */
/* FLOAT */
extern float __builtin_k1_float (unsigned char rounding, int fixed_32b_num,
				 unsigned char u6_coef);
/* FLOATD */
extern double __builtin_k1_floatd (unsigned char rounding,
				   long long fixed_64b_num,
				   unsigned char u6_coef);
/* FLOATDN */
/* FLOATN */
/* FLOATU */
extern float __builtin_k1_floatu (unsigned char rounding,
				  unsigned int fixed_unsigned_32b_num,
				  unsigned char u6_coef);
/* FLOATUD */
extern double __builtin_k1_floatud (unsigned char rounding,
				    unsigned long long fixed_unsigned_64b_num,
				    unsigned char u6_coef);
/* FLOATUDN */
/* FLOATUN */
/* FLOATUWP */
/* FLOATUWPN */
/* FLOATWP */
/* FLOATWPN */
/* FMAX */
/* FMAXD */
/* FMAXS */
/* FMAXWP */
/* FMIN */
/* FMIND */
/* FMINS */
/* FMINWP */
/* FMUL */
/* FMULD */
/* FMULN */
/* FMULND */
/* FMULNRN */
extern float __builtin_k1_fmulnrn (float op0, float op1);
/* FMULNRND */
/* FMULNRNWD */
/* FMULNRNWP */
/* FMULNWD */
/* FMULNWP */
/* FMULRN */
extern float __builtin_k1_fmulrn (float op0, float op1);
/* FMULRND */
/* FMULRNWD */
/* FMULRNWP */
/* FMULWD */
/* FMULWP */
/* FNARROW */
/* FNARROWH */
/* FNARROWHWP */
/* FNEG */
/* FNEGD */
/* FNEGWP */
/* FSBF */
/* FSBFD */
/* FSBFRN */
extern float __builtin_k1_fsbfrn (float op0, float op1);
/* FSBFRND */
/* FSBFRNWP */
/* FSBFWP */
/* FSDIV */
extern float __builtin_k1_fsdiv (float, float);
/* FSDIVD */
extern double __builtin_k1_fsdivd (double, double);
/* FSDIVWP */
/* FSINV */
extern float __builtin_k1_fsinv (float);
/* FSINVD */
extern double __builtin_k1_fsinvd (double);
/* FSINVN */
extern float __builtin_k1_fsinvn (float);
/* FSINVND */
extern double __builtin_k1_fsinvnd (double);
/* FSINVNWP */
/* FSINVWP */
/* FSISR */
extern float __builtin_k1_fsisr (float);
/* FSISRD */
extern double __builtin_k1_fsisrd (double);
/* FSISRWP */
/* FWIDENB */
extern float __builtin_k1_fwidenb (unsigned int);
/* FWIDENBWP */
/* FWIDEND */
/* FWIDENT */
extern float __builtin_k1_fwident (unsigned int);
/* FWIDENTWP */

/*
 * Other Builtin Functions
 */

/* CWS is an alias for ACWSU */
extern unsigned long long __builtin_k1_cws (void *address,
					    unsigned int new_value,
					    unsigned int old_value);
static __inline__ __attribute__ ((deprecated)) long long
__builtin_k1_cws_s10 (short a, unsigned int b, long long c)
{
  return __builtin_k1_cws ((void *) (a + b), (c & 0xFFFFFFFF),
			   ((c >> 32) & 0xFFFFFFFF));
}
/* LDC is an alias for ALDCU */
extern unsigned long long __builtin_k1_ldc (void *addr);
static __inline__ __attribute__ ((deprecated)) long long
__builtin_k1_ldc_s32_p (int a, int b)
{
  return __builtin_k1_ldc ((void *) (a + b));
}
/* IINVALL is an alias for IINVALS */
extern void __builtin_k1_iinvall (const void *addr);
static __inline__ __attribute__ ((deprecated)) void
__builtin_k1_iinvall_s10 (short a, unsigned int b)
{
  __builtin_k1_iinvall ((const void *) (a + b));
}

/* DFLUSHL is K1A only */
extern void __builtin_k1_dflush (void);
/* DFLUSHLL is K1A only */
extern void __builtin_k1_dflushl (const void *addr);
static __inline__ __attribute__ ((deprecated)) void
__builtin_k1_dflushl_s10 (short a, int b)
{
  __builtin_k1_dflushl ((const void *) (a + b));
}
/* DPURGE is K1A only */
extern void __builtin_k1_dpurge (void);
/* DPURGEL is K1A only */
extern void __builtin_k1_dpurgel (const void *addr);
static __inline__ __attribute__ ((deprecated)) void
__builtin_k1_dpurgel_s10 (short a, unsigned int b)
{
  __builtin_k1_dpurgel ((const void *) (a + b));
}

/* get GPR = GPR
 * GPR get( GPR);
 */
extern unsigned int __builtin_k1_get_r (int);

/* get GPR = GPR
 * GPR get( GPR);
 */
extern unsigned long long __builtin_k1_getd_r (int);

#if defined(__open64__) || defined(__clang__)
#define __builtin_error(MSG)                                                   \
  do                                                                           \
    {                                                                          \
    }                                                                          \
  while (0);
#else
#define __builtin_error(MSG)                                                   \
  {                                                                            \
    extern int __attribute__ ((error (#MSG))) __builtin_compile_time_check (); \
    __builtin_compile_time_check ();                                           \
  }
#endif /* defined(__open64__) || defined(__clang__) */

#define __builtin_k1_hfx(arg1, arg2, arg3, arg4)                               \
  {                                                                            \
    switch (arg1)                                                              \
      {                                                                        \
      case 0:                                                                  \
	__builtin_k1_hfxb (arg2,                                               \
			   ((int) (arg3) << 16) | ((int) (arg4) &0xffff));     \
	break;                                                                 \
      case 1:                                                                  \
	__builtin_k1_hfxt (arg2,                                               \
			   ((int) (arg3) << 16) | ((int) (arg4) &0xffff));     \
	break;                                                                 \
      default:                                                                 \
	__builtin_error (                                                      \
	  "__builtin_k1_hfx expects a 1 bits immediate first argument.");      \
      }                                                                        \
  }

/* xord
 *
 */
extern void __builtin_k1_r_xord (unsigned char, unsigned long long,
				 unsigned short);

/* set nopcpsreg = GPR
 *  set( u[0..63], GPR);
 */
extern void __builtin_k1_set (int, unsigned int);

/* set onlypsreg = GPR
 *  set( u[0..63], GPR);
 */
extern void __builtin_k1_set_ps (int, unsigned int);

#ifdef __cplusplus__
}
#endif

#endif

#endif /* _BUILTIN_K1_H_ */
#endif /* __K1__ */
