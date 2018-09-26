#ifndef __K1C_REGISTERS_MDS_H__
#define __K1C_REGISTERS_MDS_H__
/**
*** (c) Copyright 1999-2005 STMicroelectronics.
*** (c) Copyright 2010-2015 Kalray SA.
***
*** This program is free software; you can redistribute it and/or
*** modify it under the terms of the GNU General Public License
*** as published by the Free Software Foundation; either version
*** 2 of the License, or (at your option) any later version.
***
*** This program is distributed in the hope that it will be useful,
*** but WITHOUT ANY WARRANTY; without even the implied warranty of
*** MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
*** General Public License for more details.
***
*** You should have received a copy of the GNU General Public License
*** along with this program; if not, write to the Free Software
*** Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
***
*** --------------------------------------------------
***                *** DO NOT EDIT ***
***  This file was automatically generated by the
***  Machine Description System (MDS).
*** --------------------------------------------------
**/

/*
 * THIS FILE HAS BEEN MODIFIED OR ADDED BY Kalray, Inc. 2010-2014
 */

enum reg_class {
	NO_REGS,
	GRF_REGS,
	PRF_REGS,
	SRF_REGS,
	SRF32_REGS,
	SRF64_REGS,
	ALL_REGS,
	LIM_REG_CLASSES
};

#define REG_CLASS_NAMES { \
	"NO_REGS", \
	"GRF_REGS", \
	"PRF_REGS", \
	"SRF_REGS", \
	"SRF32_REGS", \
	"SRF64_REGS", \
	"ALL_REGS", \
	"LIM_REG_CLASSES", \
}

enum k1c_abi {
  K1C_ABI_K1C_REGULAR
};
extern enum k1c_abi k1c_cur_abi;
#define REG_CLASS_CONTENTS { \
	{ 0x00000000, 0x00000000, 0x00000000, 0x00000000, K1C_NO_EXT_MASK }, \
	{ 0xFFFFFFFF, 0xFFFFFFFF, 0x00000000, 0x00000000, K1C_GRF_EXT_MASK }, \
	{ 0xFFFFFFFF, 0xFFFFFFFF, 0x00000000, 0x00000000, K1C_PRF_EXT_MASK }, \
	{ 0x00000000, 0x00000000, 0xFFFFFFFF, 0x003FFFFF, K1C_SRF_EXT_MASK }, \
	{ 0x00000000, 0x00000000, 0x0000042A, 0x00340410, K1C_SRF32_EXT_MASK }, \
	{ 0x00000000, 0x00000000, 0xFFFFFBD5, 0x000BFBEF, K1C_SRF64_EXT_MASK }, \
	{ 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, K1C_ALL_EXT_MASK } \
}

/* A C expression whose value is a register class containing hard
   register regno. In general there is more than one such class;
   choose a class which is minimal, meaning that no smaller class also
   contains the register. */

#define REGNO_REG_CLASS(REGNO) (__extension__ ({\
	enum reg_class res = NO_REGS; \
	if (REGNO >= FIRST_PSEUDO_REGISTER) res = NO_REGS; \
	else if ((TARGET_K1C) && ((REGNO < 64) || (REGNO >= K1C_MDS_REGISTERS && ((1 << (REGNO-K1C_MDS_REGISTERS)) & K1C_GRF_EXT_MASK)))) res = (((REGNO)%2) ? GRF_REGS : PRF_REGS);  \
	else if ((TARGET_32) && (((REGNO >= 64) && (REGNO < 118)) || (REGNO >= K1C_MDS_REGISTERS && ((1 << (REGNO-K1C_MDS_REGISTERS)) & K1C_SRF_EXT_MASK)))) res = SRF_REGS;  \
	else if ((!TARGET_32) && (((REGNO >= 64) && (REGNO < 118) && ((1ULL << (REGNO - 64)) & 0x3404100000042AULL)) || (REGNO >= K1C_MDS_REGISTERS && ((1 << (REGNO-K1C_MDS_REGISTERS)) & K1C_SRF32_EXT_MASK)))) res = SRF32_REGS;  \
	else if ((!TARGET_32) && (((REGNO >= 64) && (REGNO < 118) && ((1ULL << (REGNO - 64)) & 0xBFBEFFFFFFBD5ULL)) || (REGNO >= K1C_MDS_REGISTERS && ((1 << (REGNO-K1C_MDS_REGISTERS)) & K1C_SRF64_EXT_MASK)))) res = SRF64_REGS;  \
res; }))

/*
 * Same as above, but returns the real size of registers, not the size
 * that should be used wrt to current target : $ra should always be
 * used as 32bits when not targeting 64bits but hardware allows the
 * use of 64bits.
 */

#define REGNO_REG_CLASS_INSENSITIVE(REGNO) (__extension__ ({\
	enum reg_class res = NO_REGS; \
	if (REGNO >= FIRST_PSEUDO_REGISTER) res = NO_REGS; \
	else if ((( TARGET_K1C )) && (((REGNO < 64)) || (REGNO >= K1C_MDS_REGISTERS && ((1 << (REGNO-K1C_MDS_REGISTERS)) & K1C_GRF_EXT_MASK)))) res = (((REGNO)%2) ? GRF_REGS : PRF_REGS);  \
	else if ((1) && ((((REGNO >= 64) && (REGNO < 118)) && ((1ULL << (REGNO - 64)) & 0x3404100000042AULL)) || (REGNO >= K1C_MDS_REGISTERS && ((1 << (REGNO-K1C_MDS_REGISTERS)) & K1C_SRF32_EXT_MASK)))) res = SRF32_REGS;  \
	else if ((1) && ((((REGNO >= 64) && (REGNO < 118)) && ((1ULL << (REGNO - 64)) & 0xBFBEFFFFFFBD5ULL)) || (REGNO >= K1C_MDS_REGISTERS && ((1 << (REGNO-K1C_MDS_REGISTERS)) & K1C_SRF64_EXT_MASK)))) res = SRF64_REGS;  \
res; }))

#define K1C_GRF_FIRST_REGNO (0)
#define K1C_GRF_LAST_REGNO (64 - 1)
#define K1C_SRF_FIRST_REGNO (64)
#define K1C_SRF_LAST_REGNO (118 - 1)
#define K1C_SRF32_FIRST_REGNO (64)
#define K1C_SRF32_LAST_REGNO (118 - 1)
#define K1C_SRF64_FIRST_REGNO (64)
#define K1C_SRF64_LAST_REGNO (118 - 1)


#define K1C_MDS_REGISTERS 128
#define K1C_REGISTER_NAMES \
    "r0",    "r1",    "r2",    "r3",    "r4",    "r5",    "r6",    "r7", \
    "r8",    "r9",   "r10",   "r11",   "r12",   "r13",   "r14",   "r15", \
   "r16",   "r17",   "r18",   "r19",   "r20",   "r21",   "r22",   "r23", \
   "r24",   "r25",   "r26",   "r27",   "r28",   "r29",   "r30",   "r31", \
   "r32",   "r33",   "r34",   "r35",   "r36",   "r37",   "r38",   "r39", \
   "r40",   "r41",   "r42",   "r43",   "r44",   "r45",   "r46",   "r47", \
   "r48",   "r49",   "r50",   "r51",   "r52",   "r53",   "r54",   "r55", \
   "r56",   "r57",   "r58",   "r59",   "r60",   "r61",   "r62",   "r63", \
    "pc",    "ps",   "spc",   "sps",  "sspc",  "ssps",   "sr3",   "sr4", \
    "cs",    "ra",   "pcr",    "ls",    "le",    "lc",    "ea",    "ev", \
  "res0",  "res1",  "res2",  "res3",   "ev4",   "men",  "pmsa", "aespc", \
   "pm0",   "pm1",   "pm2",   "pm3",   "pmc",   "sr0",   "sr1",   "sr2", \
   "t0v",   "t1v",   "t0r",   "t1r",   "tcr",   "wdc",   "wdr",   "ile", \
   "ill",   "ilh",   "mmc",   "tel",   "teh",    "dv",  "oce0",  "oce1", \
  "ocec",  "ocea",    "es",   "ilr",   "mes",    "ws",   "???",   "???", \
   "???",   "???",   "???",   "???",   "???",   "???",   "???",   "???", \

#define K1C_K1C_GRF_REGISTER_NAMES \
  "r0",  "r1",  "r2",  "r3",  "r4",  "r5",  "r6",  "r7", \
  "r8",  "r9", "r10", "r11", "r12", "r13", "r14", "r15", \
 "r16", "r17", "r18", "r19", "r20", "r21", "r22", "r23", \
 "r24", "r25", "r26", "r27", "r28", "r29", "r30", "r31", \
 "r32", "r33", "r34", "r35", "r36", "r37", "r38", "r39", \
 "r40", "r41", "r42", "r43", "r44", "r45", "r46", "r47", \
 "r48", "r49", "r50", "r51", "r52", "r53", "r54", "r55", \
 "r56", "r57", "r58", "r59", "r60", "r61", "r62", "r63", \

#define K1C_K1C_PRF_REGISTER_NAMES \
   "r0r1",     "NA",   "r2r3",     "NA",   "r4r5",     "NA", \
   "r6r7",     "NA",   "r8r9",     "NA", "r10r11",     "NA", \
 "r12r13",     "NA", "r14r15",     "NA", "r16r17",     "NA", \
 "r18r19",     "NA", "r20r21",     "NA", "r22r23",     "NA", \
 "r24r25",     "NA", "r26r27",     "NA", "r28r29",     "NA", \
 "r30r31",     "NA", "r32r33",     "NA", "r34r35",     "NA", \
 "r36r37",     "NA", "r38r39",     "NA", "r40r41",     "NA", \
 "r42r43",     "NA", "r44r45",     "NA", "r46r47",     "NA", \
 "r48r49",     "NA", "r50r51",     "NA", "r52r53",     "NA", \
 "r54r55",     "NA", "r56r57",     "NA", "r58r59",     "NA", \
 "r60r61",     "NA", "r62r63",     "NA", \

#define K1C_K1C_SRF_REGISTER_NAMES \
    "pc",    "ps",   "spc",   "sps",  "sspc",  "ssps",   "sr3",   "sr4", \
    "cs",    "ra",   "pcr",    "ls",    "le",    "lc",    "ea",    "ev", \
  "res0",  "res1",  "res2",  "res3",   "ev4",   "men",  "pmsa", "aespc", \
   "pm0",   "pm1",   "pm2",   "pm3",   "pmc",   "sr0",   "sr1",   "sr2", \
   "t0v",   "t1v",   "t0r",   "t1r",   "tcr",   "wdc",   "wdr",   "ile", \
   "ill",   "ilh",   "mmc",   "tel",   "teh",    "dv",  "oce0",  "oce1", \
  "ocec",  "ocea",    "es",   "ilr",   "mes",    "ws", \

#define K1C_ADJUST_REGISTER_NAMES \
	if (TARGET_K1C) { \
	} \


#define K1C_PROGRAM_POINTER_REGNO 64
#define K1C_STACK_POINTER_REGNO 12
#define K1C_FRAME_POINTER_REGNO 14
#define K1C_LOCAL_POINTER_REGNO 13
#define K1C_STRUCT_POINTER_REGNO 15
#define K1C_RETURN_POINTER_REGNO 73
#define K1C_ARGUMENT_POINTER_REGNO 0
#define K1C_ARG_REG_SLOTS 12

#define K1C_FIXED_REGISTERS \
        2,        2,        2,        2,        2,        2, \
        2,        2,        2,        2,        2,        2, \
        2,        2,        2,        2,        2,        2, \
        2,        2,        2,        2,        2,        2, \
        2,        2,        2,        2,        2,        2, \
        2,        2,        2,        2,        2,        2, \
        2,        2,        2,        2,        2,        2, \
        2,        2,        2,        2,        2,        2, \
        2,        2,        2,        2,        2,        2, \
        2,        2,        2,        2,        2,        2, \
        2,        2,        2,        2,        2,        2, \
        2,        2,        2,        2,        2,        2, \
        2,        2,        2,        2,        2,        2, \
        2,        2,        2,        2,        2,        2, \
        2,        2,        2,        2,        2,        2, \
        2,        2,        2,        2,        2,        2, \
        2,        2,        2,        2,        2,        2, \
        2,        2,        2,        2,        2,        2, \
        2,        2,        2,        2,        2,        2, \
        2,        2,        2,        2,        2,        2, \
        2,        2,        2,        2,        2,        2, \
        2,        2, \

#define K1C_CALL_USED_REGISTERS \
        2,        2,        2,        2,        2,        2, \
        2,        2,        2,        2,        2,        2, \
        2,        2,        2,        2,        2,        2, \
        2,        2,        2,        2,        2,        2, \
        2,        2,        2,        2,        2,        2, \
        2,        2,        2,        2,        2,        2, \
        2,        2,        2,        2,        2,        2, \
        2,        2,        2,        2,        2,        2, \
        2,        2,        2,        2,        2,        2, \
        2,        2,        2,        2,        2,        2, \
        2,        2,        2,        2,        2,        2, \
        2,        2,        2,        2,        2,        2, \
        2,        2,        2,        2,        2,        2, \
        2,        2,        2,        2,        2,        2, \
        2,        2,        2,        2,        2,        2, \
        2,        2,        2,        2,        2,        2, \
        2,        2,        2,        2,        2,        2, \
        2,        2,        2,        2,        2,        2, \
        2,        2,        2,        2,        2,        2, \
        2,        2,        2,        2,        2,        2, \
        2,        2,        2,        2,        2,        2, \
        2,        2, \

#define K1C_CALL_REALLY_USED_REGISTERS \
        2,        2,        2,        2,        2,        2, \
        2,        2,        2,        2,        2,        2, \
        2,        2,        2,        2,        2,        2, \
        2,        2,        2,        2,        2,        2, \
        2,        2,        2,        2,        2,        2, \
        2,        2,        2,        2,        2,        2, \
        2,        2,        2,        2,        2,        2, \
        2,        2,        2,        2,        2,        2, \
        2,        2,        2,        2,        2,        2, \
        2,        2,        2,        2,        2,        2, \
        2,        2,        2,        2,        2,        2, \
        2,        2,        2,        2,        2,        2, \
        2,        2,        2,        2,        2,        2, \
        2,        2,        2,        2,        2,        2, \
        2,        2,        2,        2,        2,        2, \
        2,        2,        2,        2,        2,        2, \
        2,        2,        2,        2,        2,        2, \
        2,        2,        2,        2,        2,        2, \
        2,        2,        2,        2,        2,        2, \
        2,        2,        2,        2,        2,        2, \
        2,        2,        2,        2,        2,        2, \
        2,        2, \

#define K1C_ABI_K1C_REGULAR_FIXED_REGISTERS \
 0, 0, 0, 0, 0, 0, 0, 0, \
 0, 0, 0, 0, 1, 1, 1, 0, \
 0, 0, 0, 0, 0, 0, 0, 0, \
 0, 0, 0, 0, 0, 0, 0, 0, \
 0, 0, 0, 0, 0, 0, 0, 0, \
 0, 0, 0, 0, 0, 0, 0, 0, \
 0, 0, 0, 0, 0, 0, 0, 0, \
 0, 0, 0, 0, 0, 0, 0, 0, \
 1, 1, 1, 1, 1, 1, 1, 1, \
 1, 1, 1, 1, 1, 1, 1, 1, \
 1, 1, 1, 1, 1, 1, 1, 1, \
 1, 1, 1, 1, 1, 1, 1, 1, \
 1, 1, 1, 1, 1, 1, 1, 1, \
 1, 1, 1, 1, 1, 1, 1, 1, \
 1, 1, 1, 1, 1, 1, 1, 1, \
 1, 1, 1, 1, 1, 1, 1, 1, \

#define K1C_ABI_K1C_REGULAR_CALL_USED_REGISTERS \
 1, 1, 1, 1, 1, 1, 1, 1, \
 1, 1, 1, 1, 1, 1, 1, 1, \
 1, 1, 0, 0, 0, 0, 0, 0, \
 0, 0, 0, 0, 0, 0, 0, 0, \
 1, 1, 1, 1, 1, 1, 1, 1, \
 1, 1, 1, 1, 1, 1, 1, 1, \
 1, 1, 1, 1, 1, 1, 1, 1, \
 1, 1, 1, 1, 1, 1, 1, 1, \
 1, 1, 1, 1, 1, 1, 1, 1, \
 1, 1, 1, 1, 1, 1, 1, 1, \
 1, 1, 1, 1, 1, 1, 1, 1, \
 1, 1, 1, 1, 1, 1, 1, 1, \
 1, 1, 1, 1, 1, 1, 1, 1, \
 1, 1, 1, 1, 1, 1, 1, 1, \
 1, 1, 1, 1, 1, 1, 1, 1, \
 1, 1, 1, 1, 1, 1, 1, 1, \

#define K1C_ABI_K1C_REGULAR_CALL_REALLY_USED_REGISTERS \
 1, 1, 1, 1, 1, 1, 1, 1, \
 1, 1, 1, 1, 1, 1, 1, 1, \
 1, 1, 0, 0, 0, 0, 0, 0, \
 0, 0, 0, 0, 0, 0, 0, 0, \
 1, 1, 1, 1, 1, 1, 1, 1, \
 1, 1, 1, 1, 1, 1, 1, 1, \
 1, 1, 1, 1, 1, 1, 1, 1, \
 1, 1, 1, 1, 1, 1, 1, 1, \
 1, 1, 1, 1, 1, 1, 1, 1, \
 1, 0, 1, 1, 1, 1, 1, 1, \
 1, 1, 1, 1, 1, 1, 1, 1, \
 1, 1, 1, 1, 1, 1, 1, 1, \
 1, 1, 1, 1, 1, 1, 1, 1, \
 1, 1, 1, 1, 1, 1, 1, 1, \
 1, 1, 1, 1, 1, 1, 1, 1, \
 1, 1, 1, 1, 1, 1, 1, 1, \

#endif /* __K1C_REGISTERS_MDS_H__ */
