#ifndef __K1C_REGISTERS_MDS_H__
#define __K1C_REGISTERS_MDS_H__
/**
*** (c) Copyright 2010-2018 Kalray SA.
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
**/

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
	{ 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, K1C_NO_EXT_MASK }, \
	{ 0xFFFFFFFF, 0xFFFFFFFF, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, K1C_GRF_EXT_MASK }, \
	{ 0xFFFFFFFF, 0xFFFFFFFF, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, K1C_PRF_EXT_MASK }, \
	{ 0x00000000, 0x00000000, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, K1C_SRF_EXT_MASK }, \
	{ 0x00000000, 0x00000000, 0x10040022, 0x0000610B, 0x000000F0, 0x0000000B, 0x00000010, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, K1C_SRF32_EXT_MASK }, \
	{ 0x00000000, 0x00000000, 0xEFFBFFDD, 0xFFFF9EF4, 0xFFFFFF0F, 0xFFFFFFF4, 0xFFFFFFEF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, K1C_SRF64_EXT_MASK }, \
	{ 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, K1C_ALL_EXT_MASK } \
}

/* A C expression whose value is a register class containing hard
   register regno. In general there is more than one such class;
   choose a class which is minimal, meaning that no smaller class also
   contains the register. */

#define REGNO_REG_CLASS(REGNO) (__extension__ ({\
	enum reg_class res = NO_REGS; \
	if (REGNO >= FIRST_PSEUDO_REGISTER) res = NO_REGS; \
	else if ((TARGET_K1C) && ((REGNO < 64) || (REGNO >= K1C_MDS_REGISTERS && ((1 << (REGNO-K1C_MDS_REGISTERS)) & K1C_GRF_EXT_MASK)))) res = (((REGNO)%2) ? GRF_REGS : PRF_REGS);  \
	else if ((TARGET_32) && (((REGNO >= 64) && (REGNO < 576)) || (REGNO >= K1C_MDS_REGISTERS && ((1 << (REGNO-K1C_MDS_REGISTERS)) & K1C_SRF_EXT_MASK)))) res = SRF_REGS;  \
	else if ((!TARGET_32) && (((REGNO >= 64) && (REGNO < 576) && ((1ULL << (REGNO - 64)) & 0x100000000B000000F00000610B10040022ULL)) || (REGNO >= K1C_MDS_REGISTERS && ((1 << (REGNO-K1C_MDS_REGISTERS)) & K1C_SRF32_EXT_MASK)))) res = SRF32_REGS;  \
	else if ((!TARGET_32) && (((REGNO >= 64) && (REGNO < 576) && ((1ULL << (REGNO - 64)) & 0xFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFEFFFFFFFF4FFFFFF0FFFFF9EF4EFFBFFDDULL)) || (REGNO >= K1C_MDS_REGISTERS && ((1 << (REGNO-K1C_MDS_REGISTERS)) & K1C_SRF64_EXT_MASK)))) res = SRF64_REGS;  \
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
	else if ((1) && ((((REGNO >= 64) && (REGNO < 576)) && ((1ULL << (REGNO - 64)) & 0x100000000B000000F00000610B10040022ULL)) || (REGNO >= K1C_MDS_REGISTERS && ((1 << (REGNO-K1C_MDS_REGISTERS)) & K1C_SRF32_EXT_MASK)))) res = SRF32_REGS;  \
	else if ((1) && ((((REGNO >= 64) && (REGNO < 576)) && ((1ULL << (REGNO - 64)) & 0xFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFEFFFFFFFF4FFFFFF0FFFFF9EF4EFFBFFDDULL)) || (REGNO >= K1C_MDS_REGISTERS && ((1 << (REGNO-K1C_MDS_REGISTERS)) & K1C_SRF64_EXT_MASK)))) res = SRF64_REGS;  \
res; }))

#define K1C_GRF_FIRST_REGNO (0)
#define K1C_GRF_LAST_REGNO (64 - 1)
#define K1C_SRF_FIRST_REGNO (64)
#define K1C_SRF_LAST_REGNO (576 - 1)
#define K1C_SRF32_FIRST_REGNO (64)
#define K1C_SRF32_LAST_REGNO (576 - 1)
#define K1C_SRF64_FIRST_REGNO (64)
#define K1C_SRF64_LAST_REGNO (576 - 1)


#define K1C_MDS_REGISTERS 576
#define K1C_REGISTER_NAMES \
      "r0",      "r1",      "r2",      "r3",      "r4",      "r5", \
      "r6",      "r7",      "r8",      "r9",     "r10",     "r11", \
     "r12",     "r13",     "r14",     "r15",     "r16",     "r17", \
     "r18",     "r19",     "r20",     "r21",     "r22",     "r23", \
     "r24",     "r25",     "r26",     "r27",     "r28",     "r29", \
     "r30",     "r31",     "r32",     "r33",     "r34",     "r35", \
     "r36",     "r37",     "r38",     "r39",     "r40",     "r41", \
     "r42",     "r43",     "r44",     "r45",     "r46",     "r47", \
     "r48",     "r49",     "r50",     "r51",     "r52",     "r53", \
     "r54",     "r55",     "r56",     "r57",     "r58",     "r59", \
     "r60",     "r61",     "r62",     "r63",      "pc",      "ps", \
     "pcr",      "ra",      "cs",    "csit",   "aespc",      "ls", \
      "le",      "lc",     "ipe",     "men",     "pmc",     "pm0", \
     "pm1",     "pm2",     "pm3",    "pmsa",     "tcr",     "t0v", \
     "t1v",     "t0r",     "t1r",     "wdv",     "wdr",     "ile", \
     "ill",     "ilr",     "mmc",     "tel",     "teh",   "res31", \
     "syo",     "hto",     "ito",      "do",      "mo",     "pso", \
   "res38",   "res39",      "dc",    "dba0",    "dba1",    "dwa0", \
    "dwa1",     "mes",      "ws",   "res47",   "res48",   "res49", \
   "res50",   "res51",   "res52",   "res53",   "res54",   "res55", \
   "res56",   "res57",   "res58",   "res59",   "res60",   "res61", \
   "res62",   "res63", "spc_pl0", "spc_pl1", "spc_pl2", "spc_pl3", \
 "sps_pl0", "sps_pl1", "sps_pl2", "sps_pl3",  "ea_pl0",  "ea_pl1", \
  "ea_pl2",  "ea_pl3",  "ev_pl0",  "ev_pl1",  "ev_pl2",  "ev_pl3", \
  "sr_pl0",  "sr_pl1",  "sr_pl2",  "sr_pl3",  "es_pl0",  "es_pl1", \
  "es_pl2",  "es_pl3",   "res88",   "res89",   "res90",   "res91", \
   "res92",   "res93",   "res94",   "res95",    "syow",    "htow", \
    "itow",     "dow",     "mow",    "psow",  "res102",  "res103", \
  "res104",  "res105",  "res106",  "res107",  "res108",  "res109", \
  "res110",  "res111",  "res112",  "res113",  "res114",  "res115", \
  "res116",  "res117",  "res118",  "res119",  "res120",  "res121", \
  "res122",  "res123",  "res124",  "res125",  "res126",  "res127", \
     "spc",  "res129",  "res130",  "res131",     "sps",  "res133", \
  "res134",  "res135",      "ea",  "res137",  "res138",  "res139", \
      "ev",  "res141",  "res142",  "res143",      "sr",  "res145", \
  "res146",  "res147",      "es",  "res149",  "res150",  "res151", \
  "res152",  "res153",  "res154",  "res155",  "res156",  "res157", \
  "res158",  "res159",  "res160",  "res161",  "res162",  "res163", \
  "res164",  "res165",  "res166",  "res167",  "res168",  "res169", \
  "res170",  "res171",  "res172",  "res173",  "res174",  "res175", \
  "res176",  "res177",  "res178",  "res179",  "res180",  "res181", \
  "res182",  "res183",  "res184",  "res185",  "res186",  "res187", \
  "res188",  "res189",  "res190",  "res191",  "res192",  "res193", \
  "res194",  "res195",  "res196",  "res197",  "res198",  "res199", \
  "res200",  "res201",  "res202",  "res203",  "res204",  "res205", \
  "res206",  "res207",  "res208",  "res209",  "res210",  "res211", \
  "res212",  "res213",  "res214",  "res215",  "res216",  "res217", \
  "res218",  "res219",  "res220",  "res221",  "res222",  "res223", \
  "res224",  "res225",  "res226",  "res227",  "res228",  "res229", \
  "res230",  "res231",  "res232",  "res233",  "res234",  "res235", \
  "res236",  "res237",  "res238",  "res239",  "res240",  "res241", \
  "res242",  "res243",  "res244",  "res245",  "res246",  "res247", \
  "res248",  "res249",  "res250",  "res251",  "res252",  "res253", \
  "res254",  "res255",   "vsfr0",   "vsfr1",   "vsfr2",   "vsfr3", \
   "vsfr4",   "vsfr5",   "vsfr6",   "vsfr7",   "vsfr8",   "vsfr9", \
  "vsfr10",  "vsfr11",  "vsfr12",  "vsfr13",  "vsfr14",  "vsfr15", \
  "vsfr16",  "vsfr17",  "vsfr18",  "vsfr19",  "vsfr20",  "vsfr21", \
  "vsfr22",  "vsfr23",  "vsfr24",  "vsfr25",  "vsfr26",  "vsfr27", \
  "vsfr28",  "vsfr29",  "vsfr30",  "vsfr31",  "vsfr32",  "vsfr33", \
  "vsfr34",  "vsfr35",  "vsfr36",  "vsfr37",  "vsfr38",  "vsfr39", \
  "vsfr40",  "vsfr41",  "vsfr42",  "vsfr43",  "vsfr44",  "vsfr45", \
  "vsfr46",  "vsfr47",  "vsfr48",  "vsfr49",  "vsfr50",  "vsfr51", \
  "vsfr52",  "vsfr53",  "vsfr54",  "vsfr55",  "vsfr56",  "vsfr57", \
  "vsfr58",  "vsfr59",  "vsfr60",  "vsfr61",  "vsfr62",  "vsfr63", \
  "vsfr64",  "vsfr65",  "vsfr66",  "vsfr67",  "vsfr68",  "vsfr69", \
  "vsfr70",  "vsfr71",  "vsfr72",  "vsfr73",  "vsfr74",  "vsfr75", \
  "vsfr76",  "vsfr77",  "vsfr78",  "vsfr79",  "vsfr80",  "vsfr81", \
  "vsfr82",  "vsfr83",  "vsfr84",  "vsfr85",  "vsfr86",  "vsfr87", \
  "vsfr88",  "vsfr89",  "vsfr90",  "vsfr91",  "vsfr92",  "vsfr93", \
  "vsfr94",  "vsfr95",  "vsfr96",  "vsfr97",  "vsfr98",  "vsfr99", \
 "vsfr100", "vsfr101", "vsfr102", "vsfr103", "vsfr104", "vsfr105", \
 "vsfr106", "vsfr107", "vsfr108", "vsfr109", "vsfr110", "vsfr111", \
 "vsfr112", "vsfr113", "vsfr114", "vsfr115", "vsfr116", "vsfr117", \
 "vsfr118", "vsfr119", "vsfr120", "vsfr121", "vsfr122", "vsfr123", \
 "vsfr124", "vsfr125", "vsfr126", "vsfr127", "vsfr128", "vsfr129", \
 "vsfr130", "vsfr131", "vsfr132", "vsfr133", "vsfr134", "vsfr135", \
 "vsfr136", "vsfr137", "vsfr138", "vsfr139", "vsfr140", "vsfr141", \
 "vsfr142", "vsfr143", "vsfr144", "vsfr145", "vsfr146", "vsfr147", \
 "vsfr148", "vsfr149", "vsfr150", "vsfr151", "vsfr152", "vsfr153", \
 "vsfr154", "vsfr155", "vsfr156", "vsfr157", "vsfr158", "vsfr159", \
 "vsfr160", "vsfr161", "vsfr162", "vsfr163", "vsfr164", "vsfr165", \
 "vsfr166", "vsfr167", "vsfr168", "vsfr169", "vsfr170", "vsfr171", \
 "vsfr172", "vsfr173", "vsfr174", "vsfr175", "vsfr176", "vsfr177", \
 "vsfr178", "vsfr179", "vsfr180", "vsfr181", "vsfr182", "vsfr183", \
 "vsfr184", "vsfr185", "vsfr186", "vsfr187", "vsfr188", "vsfr189", \
 "vsfr190", "vsfr191", "vsfr192", "vsfr193", "vsfr194", "vsfr195", \
 "vsfr196", "vsfr197", "vsfr198", "vsfr199", "vsfr200", "vsfr201", \
 "vsfr202", "vsfr203", "vsfr204", "vsfr205", "vsfr206", "vsfr207", \
 "vsfr208", "vsfr209", "vsfr210", "vsfr211", "vsfr212", "vsfr213", \
 "vsfr214", "vsfr215", "vsfr216", "vsfr217", "vsfr218", "vsfr219", \
 "vsfr220", "vsfr221", "vsfr222", "vsfr223", "vsfr224", "vsfr225", \
 "vsfr226", "vsfr227", "vsfr228", "vsfr229", "vsfr230", "vsfr231", \
 "vsfr232", "vsfr233", "vsfr234", "vsfr235", "vsfr236", "vsfr237", \
 "vsfr238", "vsfr239", "vsfr240", "vsfr241", "vsfr242", "vsfr243", \
 "vsfr244", "vsfr245", "vsfr246", "vsfr247", "vsfr248", "vsfr249", \
 "vsfr250", "vsfr251", "vsfr252", "vsfr253", "vsfr254", "vsfr255", \

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
      "pc",      "ps",     "pcr",      "ra",      "cs",    "csit", \
   "aespc",      "ls",      "le",      "lc",     "ipe",     "men", \
     "pmc",     "pm0",     "pm1",     "pm2",     "pm3",    "pmsa", \
     "tcr",     "t0v",     "t1v",     "t0r",     "t1r",     "wdv", \
     "wdr",     "ile",     "ill",     "ilr",     "mmc",     "tel", \
     "teh",   "res31",     "syo",     "hto",     "ito",      "do", \
      "mo",     "pso",   "res38",   "res39",      "dc",    "dba0", \
    "dba1",    "dwa0",    "dwa1",     "mes",      "ws",   "res47", \
   "res48",   "res49",   "res50",   "res51",   "res52",   "res53", \
   "res54",   "res55",   "res56",   "res57",   "res58",   "res59", \
   "res60",   "res61",   "res62",   "res63", "spc_pl0", "spc_pl1", \
 "spc_pl2", "spc_pl3", "sps_pl0", "sps_pl1", "sps_pl2", "sps_pl3", \
  "ea_pl0",  "ea_pl1",  "ea_pl2",  "ea_pl3",  "ev_pl0",  "ev_pl1", \
  "ev_pl2",  "ev_pl3",  "sr_pl0",  "sr_pl1",  "sr_pl2",  "sr_pl3", \
  "es_pl0",  "es_pl1",  "es_pl2",  "es_pl3",   "res88",   "res89", \
   "res90",   "res91",   "res92",   "res93",   "res94",   "res95", \
    "syow",    "htow",    "itow",     "dow",     "mow",    "psow", \
  "res102",  "res103",  "res104",  "res105",  "res106",  "res107", \
  "res108",  "res109",  "res110",  "res111",  "res112",  "res113", \
  "res114",  "res115",  "res116",  "res117",  "res118",  "res119", \
  "res120",  "res121",  "res122",  "res123",  "res124",  "res125", \
  "res126",  "res127",     "spc",  "res129",  "res130",  "res131", \
     "sps",  "res133",  "res134",  "res135",      "ea",  "res137", \
  "res138",  "res139",      "ev",  "res141",  "res142",  "res143", \
      "sr",  "res145",  "res146",  "res147",      "es",  "res149", \
  "res150",  "res151",  "res152",  "res153",  "res154",  "res155", \
  "res156",  "res157",  "res158",  "res159",  "res160",  "res161", \
  "res162",  "res163",  "res164",  "res165",  "res166",  "res167", \
  "res168",  "res169",  "res170",  "res171",  "res172",  "res173", \
  "res174",  "res175",  "res176",  "res177",  "res178",  "res179", \
  "res180",  "res181",  "res182",  "res183",  "res184",  "res185", \
  "res186",  "res187",  "res188",  "res189",  "res190",  "res191", \
  "res192",  "res193",  "res194",  "res195",  "res196",  "res197", \
  "res198",  "res199",  "res200",  "res201",  "res202",  "res203", \
  "res204",  "res205",  "res206",  "res207",  "res208",  "res209", \
  "res210",  "res211",  "res212",  "res213",  "res214",  "res215", \
  "res216",  "res217",  "res218",  "res219",  "res220",  "res221", \
  "res222",  "res223",  "res224",  "res225",  "res226",  "res227", \
  "res228",  "res229",  "res230",  "res231",  "res232",  "res233", \
  "res234",  "res235",  "res236",  "res237",  "res238",  "res239", \
  "res240",  "res241",  "res242",  "res243",  "res244",  "res245", \
  "res246",  "res247",  "res248",  "res249",  "res250",  "res251", \
  "res252",  "res253",  "res254",  "res255",   "vsfr0",   "vsfr1", \
   "vsfr2",   "vsfr3",   "vsfr4",   "vsfr5",   "vsfr6",   "vsfr7", \
   "vsfr8",   "vsfr9",  "vsfr10",  "vsfr11",  "vsfr12",  "vsfr13", \
  "vsfr14",  "vsfr15",  "vsfr16",  "vsfr17",  "vsfr18",  "vsfr19", \
  "vsfr20",  "vsfr21",  "vsfr22",  "vsfr23",  "vsfr24",  "vsfr25", \
  "vsfr26",  "vsfr27",  "vsfr28",  "vsfr29",  "vsfr30",  "vsfr31", \
  "vsfr32",  "vsfr33",  "vsfr34",  "vsfr35",  "vsfr36",  "vsfr37", \
  "vsfr38",  "vsfr39",  "vsfr40",  "vsfr41",  "vsfr42",  "vsfr43", \
  "vsfr44",  "vsfr45",  "vsfr46",  "vsfr47",  "vsfr48",  "vsfr49", \
  "vsfr50",  "vsfr51",  "vsfr52",  "vsfr53",  "vsfr54",  "vsfr55", \
  "vsfr56",  "vsfr57",  "vsfr58",  "vsfr59",  "vsfr60",  "vsfr61", \
  "vsfr62",  "vsfr63",  "vsfr64",  "vsfr65",  "vsfr66",  "vsfr67", \
  "vsfr68",  "vsfr69",  "vsfr70",  "vsfr71",  "vsfr72",  "vsfr73", \
  "vsfr74",  "vsfr75",  "vsfr76",  "vsfr77",  "vsfr78",  "vsfr79", \
  "vsfr80",  "vsfr81",  "vsfr82",  "vsfr83",  "vsfr84",  "vsfr85", \
  "vsfr86",  "vsfr87",  "vsfr88",  "vsfr89",  "vsfr90",  "vsfr91", \
  "vsfr92",  "vsfr93",  "vsfr94",  "vsfr95",  "vsfr96",  "vsfr97", \
  "vsfr98",  "vsfr99", "vsfr100", "vsfr101", "vsfr102", "vsfr103", \
 "vsfr104", "vsfr105", "vsfr106", "vsfr107", "vsfr108", "vsfr109", \
 "vsfr110", "vsfr111", "vsfr112", "vsfr113", "vsfr114", "vsfr115", \
 "vsfr116", "vsfr117", "vsfr118", "vsfr119", "vsfr120", "vsfr121", \
 "vsfr122", "vsfr123", "vsfr124", "vsfr125", "vsfr126", "vsfr127", \
 "vsfr128", "vsfr129", "vsfr130", "vsfr131", "vsfr132", "vsfr133", \
 "vsfr134", "vsfr135", "vsfr136", "vsfr137", "vsfr138", "vsfr139", \
 "vsfr140", "vsfr141", "vsfr142", "vsfr143", "vsfr144", "vsfr145", \
 "vsfr146", "vsfr147", "vsfr148", "vsfr149", "vsfr150", "vsfr151", \
 "vsfr152", "vsfr153", "vsfr154", "vsfr155", "vsfr156", "vsfr157", \
 "vsfr158", "vsfr159", "vsfr160", "vsfr161", "vsfr162", "vsfr163", \
 "vsfr164", "vsfr165", "vsfr166", "vsfr167", "vsfr168", "vsfr169", \
 "vsfr170", "vsfr171", "vsfr172", "vsfr173", "vsfr174", "vsfr175", \
 "vsfr176", "vsfr177", "vsfr178", "vsfr179", "vsfr180", "vsfr181", \
 "vsfr182", "vsfr183", "vsfr184", "vsfr185", "vsfr186", "vsfr187", \
 "vsfr188", "vsfr189", "vsfr190", "vsfr191", "vsfr192", "vsfr193", \
 "vsfr194", "vsfr195", "vsfr196", "vsfr197", "vsfr198", "vsfr199", \
 "vsfr200", "vsfr201", "vsfr202", "vsfr203", "vsfr204", "vsfr205", \
 "vsfr206", "vsfr207", "vsfr208", "vsfr209", "vsfr210", "vsfr211", \
 "vsfr212", "vsfr213", "vsfr214", "vsfr215", "vsfr216", "vsfr217", \
 "vsfr218", "vsfr219", "vsfr220", "vsfr221", "vsfr222", "vsfr223", \
 "vsfr224", "vsfr225", "vsfr226", "vsfr227", "vsfr228", "vsfr229", \
 "vsfr230", "vsfr231", "vsfr232", "vsfr233", "vsfr234", "vsfr235", \
 "vsfr236", "vsfr237", "vsfr238", "vsfr239", "vsfr240", "vsfr241", \
 "vsfr242", "vsfr243", "vsfr244", "vsfr245", "vsfr246", "vsfr247", \
 "vsfr248", "vsfr249", "vsfr250", "vsfr251", "vsfr252", "vsfr253", \
 "vsfr254", "vsfr255", \

#define K1C_ADJUST_REGISTER_NAMES \
	if (TARGET_K1C) { \
	} \


#define K1C_PROGRAM_POINTER_REGNO 64
#define K1C_STACK_POINTER_REGNO 12
#define K1C_FRAME_POINTER_REGNO 14
#define K1C_LOCAL_POINTER_REGNO 13
#define K1C_STRUCT_POINTER_REGNO 15
#define K1C_RETURN_POINTER_REGNO 67
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
 1, 1, 1, 0, 1, 1, 1, 1, \
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
 1, 1, 1, 1, 1, 1, 1, 1, \
 1, 1, 1, 1, 1, 1, 1, 1, \
 1, 1, 1, 1, 1, 1, 1, 1, \

#endif /* __K1C_REGISTERS_MDS_H__ */
