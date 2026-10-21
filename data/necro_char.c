/*
 * NECRO_CHAR.C  Necro's animation scripts and sprite part tables
 *
 * The animation scripts Necro's moves run, one table per kind of script (nmca, dmca, btca, caca,
 * cuca, atca, exca, saca, cbca), each an index of scripts followed by the scripts.
 * set_char_base_data (CHARID) installs the tables as char_table[]; set_char_move_init2 starts
 * script char_table[kind][index] and char_move steps it: a frame line shows sprite `number` for
 * `ctr` frames with its sound, hit boxes (hit_ix into the hit_ix_table), attack (att into the
 * catt_table) and effect; a command line (CM_ codes) jumps, loops, tests and sets. See charscr.h
 * for the line layouts and the kind numbers a command's koc names.
 *
 * olc_ix_table and overlap_char_tbl place the extra sprite parts a frame overlays (cg_olc_ix);
 * rival_catch_tbl positions a caught opponent for each throw frame (cg_rival).
 */

#include "types.h"
#include "structs.h"
#include "charscr.h"

#pragma section TBL

extern const u16 necro_nmca_000[], necro_nmca_001[], necro_nmca_002[], necro_nmca_003[], necro_nmca_004[], necro_nmca_005[], necro_nmca_006[], necro_nmca_007[], necro_nmca_008[], necro_nmca_011[], necro_nmca_012[], necro_nmca_013[], necro_nmca_014[], necro_nmca_015[], necro_nmca_016[], necro_nmca_017[], necro_nmca_020[], necro_nmca_021[], necro_nmca_022[], necro_nmca_023[], necro_nmca_024[], necro_nmca_026[], necro_nmca_027[], necro_nmca_028[], necro_nmca_029[], necro_nmca_030[], necro_nmca_031[], necro_nmca_032[], necro_nmca_033[], necro_nmca_038[], necro_nmca_040[], necro_nmca_041[], necro_nmca_043[], necro_nmca_044[], necro_nmca_045[], necro_nmca_046[];

/* nmca scripts (debug viewer: NORMAL): 47 entries */
const u32 necro_nmca[48] = {
    (u32)necro_nmca_000,  /* 0 KAMAE */
    (u32)necro_nmca_001,  /* 1 HURIMUKI */
    (u32)necro_nmca_002,  /* 2 FRONT WALK */
    (u32)necro_nmca_003,  /* 3 BACK WALK */
    (u32)necro_nmca_004,  /* 4 DASH HUMIKOMI */
    (u32)necro_nmca_005,  /* 5 DASH TOBINOKI */
    (u32)necro_nmca_006,  /* 6 KAGAMU */
    (u32)necro_nmca_007,  /* 7 KAGAMI KAMAE */
    (u32)necro_nmca_008,  /* 8 KAGAMI TURN */
    (u32)necro_nmca_008,  /* 9 KAGAMI F WALK */
    (u32)necro_nmca_008,  /* 10 KAGAMI B WALK */
    (u32)necro_nmca_011,  /* 11 STAND UP */
    (u32)necro_nmca_012,  /* 12 JUMP JUNBI */
    (u32)necro_nmca_013,  /* 13 SP JUMP JUNBI */
    (u32)necro_nmca_014,  /* 14 JUMP FRONT */
    (u32)necro_nmca_015,  /* 15 JUMP VERTICAL */
    (u32)necro_nmca_016,  /* 16 JUMP BACK */
    (u32)necro_nmca_017,  /* 17 S JUMP FRONT */
    (u32)necro_nmca_017,  /* 18 S JUMP V */
    (u32)necro_nmca_017,  /* 19 S JUMP BACK */
    (u32)necro_nmca_020,  /* 20 SP JUMP FRONT */
    (u32)necro_nmca_021,  /* 21 SP JUMP V */
    (u32)necro_nmca_022,  /* 22 SP JUMP BACK */
    (u32)necro_nmca_023,  /* 23 WALK END */
    (u32)necro_nmca_024,  /* 24 PARING HEAD */
    (u32)necro_nmca_024,  /* 25 PARING UP */
    (u32)necro_nmca_026,  /* 26 PARING DOWN */
    (u32)necro_nmca_027,  /* 27 PARING AIR F */
    (u32)necro_nmca_028,  /* 28 PARING AIR B */
    (u32)necro_nmca_029,  /* 29 GUARD HEAD */
    (u32)necro_nmca_030,  /* 30 GUARD UP */
    (u32)necro_nmca_031,  /* 31 GUARD DOWN */
    (u32)necro_nmca_032,  /* 32 GUARD AIR */
    (u32)necro_nmca_033,  /* 33 no name */
    (u32)necro_nmca_033,  /* 34 no name */
    (u32)necro_nmca_033,  /* 35 no name */
    (u32)necro_nmca_033,  /* 36 no name */
    (u32)necro_nmca_033,  /* 37 no name */
    (u32)necro_nmca_038,  /* 38 P BREAK ZUJOU */
    (u32)necro_nmca_038,  /* 39 P BREAK UP */
    (u32)necro_nmca_040,  /* 40 P BREAK DOWN */
    (u32)necro_nmca_041,  /* 41 P BREAK AIR F */
    (u32)necro_nmca_041,  /* 42 P BREAK AIR R */
    (u32)necro_nmca_043,  /* 43 TUKAMIHAZUSI */
    (u32)necro_nmca_044,  /* 44 TUKAMIHAZUSARE */
    (u32)necro_nmca_045,  /* 45 TUKAMIHAZUSI */
    (u32)necro_nmca_046,  /* 46 TUKAMIHAZUSARE */
    0
};

/* script: 0 KAMAE */
const u16 necro_nmca_000_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 necro_nmca_000[180] = {
    L4(4, 0, 0, 0, 0, 0, 0, 0x1E01, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1E02, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1E03, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1E04, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1E05, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1E06, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1E07, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1E08, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1E09, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1E0A, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1E0B, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1E0C, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1E0D, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1E0E, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1E0F, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1E10, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1E11, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1E12, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1E13, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1E14, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 255, 0, 0, 0, 0, 0, 0x1E15, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_END, 0, 0, 1), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 1 HURIMUKI */
const u16 necro_nmca_001_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 necro_nmca_001[76] = {
    L4(3, 0, 0, 0, 0, 0, 0, 0x1E29, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1E2A, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1E2B, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1E2C, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1E2D, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1E2E, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1E3C, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1E3D, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x1E3D, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 2 FRONT WALK */
const u16 necro_nmca_002_head[4] = { HEAD(4, 6, 0, 0, 0, 0, 0) };
const u16 necro_nmca_002[132] = {
    L4(4, 0, 0, 0, 0, 0, 0, 0x1FA0, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1FA1, 0, 1, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x1FA2, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1FA3, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1FA4, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1FA5, 0, 1, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x1FA6, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1FA7, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1FA8, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1FA9, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1FAA, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1FAB, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1FAC, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1FAD, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1FAE, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1FAF, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 3 BACK WALK */
const u16 necro_nmca_003_head[4] = { HEAD(4, 8, 0, 0, 0, 0, 0) };
const u16 necro_nmca_003[116] = {
    L4(5, 0, 0, 0, 0, 0, 0, 0x1FB0, 0, 1, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x1FB1, 0, 1, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x1FB2, 0, 1, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x1FB3, 0, 1, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x1FB4, 0, 1, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x1FB5, 0, 1, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x1FB6, 0, 1, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x1FB7, 0, 1, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x1FB8, 0, 1, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x1FB9, 0, 1, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x1FBA, 0, 1, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x1FBB, 0, 1, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x1FBC, 0, 1, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x1FBD, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 4 DASH HUMIKOMI */
const u16 necro_nmca_004_head[4] = { HEAD(6, 10, 0, 0, 0, 0, 0) };
const u16 necro_nmca_004[136] = {
    CMD(CM_RJA, 0, 4, 5), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(2, 0, 0, 0, 0, 0, 0, 0x1E20, 0, 146, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(6, 1, 277, 0, 0, 0, 0, 0x1E38, 0, 146, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0),
    L6(250, 0, 0, 0, 0, 0, 0, 0x1E3E, 0, 146, 0, 0, 0, 0, 0, 0, 0, 4, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1E39, 0, 146, 0, 0, 0, 0, 0, 0, 0, 6, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x1E3A, 0, 146, 0, 0, 0, 0, 0, 0, 0, 6, 0, 0),
    L6(2, 64, 0, 0, 0, 0, 0, 0x1E21, 0, 146, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1E3B, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1E3C, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1E3D, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x1E3D, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 5 DASH TOBINOKI */
const u16 necro_nmca_005_head[4] = { HEAD(6, 12, 0, 0, 0, 0, 0) };
const u16 necro_nmca_005[136] = {
    CMD(CM_RJA, 0, 5, 5), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(2, 0, 0, 0, 0, 0, 0, 0x1E20, 0, 146, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 1, 277, 0, 0, 0, 0, 0x1E40, 0, 146, 0, 0, 0, 0, 0, 0, 0, 98, 0, 0),
    L6(250, 0, 0, 0, 0, 0, 0, 0x1E41, 0, 146, 0, 0, 0, 0, 0, 0, 0, 100, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1E42, 0, 1, 0, 0, 0, 0, 0, 0, 0, 100, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1E43, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 64, 0, 0, 0, 0, 0, 0x1E21, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1E3B, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1E3C, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1E3D, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x1E3D, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 6 KAGAMU */
const u16 necro_nmca_006_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 necro_nmca_006[52] = {
    L4(2, 0, 0, 0, 0, 0, 0, 0x1E20, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1E21, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1E22, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1E23, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1E24, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x1E24, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 7 KAGAMI KAMAE */
const u16 necro_nmca_007_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 necro_nmca_007[92] = {
    L4(6, 0, 0, 0, 0, 0, 0, 0x1E16, 0, 2, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x1E17, 0, 2, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x1E18, 0, 2, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x1E19, 0, 2, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x1E1A, 0, 2, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x1E1B, 0, 2, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x1E1C, 0, 2, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x1E1D, 0, 2, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x1E1E, 0, 2, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x1E1F, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_END, 0, 0, 1), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 8 KAGAMI TURN, 9 KAGAMI F WALK, 10 KAGAMI B WALK */
const u16 necro_nmca_008_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 necro_nmca_008[76] = {
    L4(4, 0, 0, 0, 0, 0, 0, 0x1E31, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1E32, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1E33, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1E34, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1E35, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1E36, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1E23, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1E24, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x1E24, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 11 STAND UP */
const u16 necro_nmca_011_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 necro_nmca_011[52] = {
    L4(2, 0, 0, 0, 0, 0, 0, 0x1E25, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1E21, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1E26, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1E27, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1E28, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x1E28, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 12 JUMP JUNBI */
const u16 necro_nmca_012_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 necro_nmca_012[28] = {
    L4(2, 1, 281, 0, 0, 0, 0, 0x1E20, 0, 3, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x1E20, 0, 3, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x1E20, 0, 3, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 13 SP JUMP JUNBI */
const u16 necro_nmca_013_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 necro_nmca_013[20] = {
    L4(5, 0, 281, 0, 0, 0, 0, 0x1E24, 0, 3, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x1E24, 0, 3, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 14 JUMP FRONT */
const u16 necro_nmca_014_head[4] = { HEAD(4, 20, 0, 0, 0, 0, 0) };
const u16 necro_nmca_014[156] = {
    CMD(CM_JSR, 8, 1, 1), 0, 0, 0, 0,
    L4(6, 0, 0, 0, 0, 0, 0, 0x1E4D, 0, 3, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1E4E, 0, 3, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1E4F, 0, 3, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1E50, 0, 4, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1E51, 0, 4, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1E52, 0, 4, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1E53, 0, 7, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1E54, 0, 7, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1E55, 0, 7, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1E56, 0, 7, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1E57, 0, 7, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1E58, 0, 7, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1E59, 0, 7, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1E5A, 0, 7, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1E5B, 0, 6, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x1E5C, 0, 6, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x1E5D, 0, 6, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 15 JUMP VERTICAL */
const u16 necro_nmca_015_head[4] = { HEAD(4, 22, 0, 0, 0, 0, 0) };
const u16 necro_nmca_015[108] = {
    CMD(CM_JSR, 8, 1, 1), 0, 0, 0, 0,
    L4(4, 0, 0, 0, 0, 0, 0, 0x1E44, 0, 6, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1E45, 0, 6, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1E46, 0, 7, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1E47, 0, 7, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1E48, 0, 7, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x1E49, 0, 7, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x1E4A, 0, 7, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x1E48, 0, 7, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x1E47, 0, 6, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x1E4B, 0, 6, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x1E4C, 0, 6, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 16 JUMP BACK */
const u16 necro_nmca_016_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 necro_nmca_016[116] = {
    CMD(CM_JSR, 8, 1, 1), 0, 0, 0, 0,
    L4(7, 0, 0, 0, 0, 0, 0, 0x1E5E, 0, 8, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1E5F, 0, 8, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1E60, 0, 8, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1E55, 0, 9, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1E54, 0, 7, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1E53, 0, 7, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1E52, 0, 7, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1E51, 0, 7, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1E50, 0, 7, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x1E5B, 0, 7, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x1E5C, 0, 11, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x1E5D, 0, 11, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 17 S JUMP FRONT, 18 S JUMP V, 19 S JUMP BACK */
const u16 necro_nmca_017_head[4] = { HEAD(4, 14, 0, 0, 0, 0, 0) };
const u16 necro_nmca_017[60] = {
    CMD(CM_JSR, 8, 1, 1), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x1E47, 0, 7, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1E48, 0, 7, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1E49, 0, 7, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1E4A, 0, 7, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1E48, 0, 7, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x1E47, 0, 6, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 20 SP JUMP FRONT */
const u16 necro_nmca_020_head[4] = { HEAD(4, 26, 0, 0, 0, 0, 0) };
const u16 necro_nmca_020[148] = {
    CMD(CM_JSR, 8, 2, 1), 0, 0, 0, 0,
    L4(6, 0, 0, 0, 0, 0, 0, 0x1E4D, 0, 3, 0, 0, 0, 18, 2),
    L4(5, 0, 0, 0, 0, 0, 0, 0x1E4E, 0, 3, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1E4F, 0, 3, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1E50, 0, 4, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1E51, 0, 4, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1E52, 0, 4, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1E53, 0, 5, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1E54, 0, 5, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1E55, 0, 5, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1E56, 0, 5, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1E57, 0, 5, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1E58, 0, 5, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1E59, 0, 5, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x1E5A, 0, 5, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x1E5B, 0, 6, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x1E5C, 0, 6, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 21 SP JUMP V */
const u16 necro_nmca_021_head[4] = { HEAD(4, 28, 0, 0, 0, 0, 0) };
const u16 necro_nmca_021[108] = {
    CMD(CM_JSR, 8, 2, 1), 0, 0, 0, 0,
    L4(12, 0, 0, 0, 0, 0, 0, 0x1E44, 0, 6, 0, 0, 0, 18, 2),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1E45, 0, 6, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1E46, 0, 7, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1E47, 0, 7, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1E48, 0, 7, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x1E49, 0, 7, 0, 0, 0, 0, 0),
    L4(7, 0, 0, 0, 0, 0, 0, 0x1E4A, 0, 7, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x1E48, 0, 7, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x1E47, 0, 6, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x1E4B, 0, 6, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x1E4C, 0, 6, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 22 SP JUMP BACK */
const u16 necro_nmca_022_head[4] = { HEAD(4, 30, 0, 0, 0, 0, 0) };
const u16 necro_nmca_022[108] = {
    CMD(CM_JSR, 8, 2, 1), 0, 0, 0, 0,
    L4(12, 0, 0, 0, 0, 0, 0, 0x1E5E, 0, 8, 0, 0, 0, 18, 2),
    L4(6, 0, 0, 0, 0, 0, 0, 0x1E5F, 0, 8, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x1E60, 0, 8, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x1E55, 0, 9, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x1E54, 0, 10, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x1E53, 0, 10, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x1E52, 0, 10, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x1E51, 0, 10, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x1E50, 0, 10, 0, 0, 0, 0, 0),
    L4(7, 0, 0, 0, 0, 0, 0, 0x1E5B, 0, 11, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x1E5C, 0, 11, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 23 WALK END */
const u16 necro_nmca_023_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 necro_nmca_023[12] = {
    L4(250, 255, 0, 0, 0, 0, 0, 0x1E01, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 24 PARING HEAD, 25 PARING UP */
const u16 necro_nmca_024_head[4] = { HEAD(4, 2, 0, 0, 0, 0, 0) };
const u16 necro_nmca_024[68] = {
    L4(1, 1, 0, 0, 0, 0, 0, 0x20CB, 0, 1, 0, 0, 0, 18, 6),
    L4(2, 1, 498, 0, 0, 0, 0, 0x20CD, 0, 1, 0, 0, 0, 6, 0),
    L4(13, 1, 0, 0, 0, 0, 0, 0x20CC, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x20CB, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 64, 0, 0, 0, 0, 0, 0x1E3B, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1E3C, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1E3D, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x1E3D, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 26 PARING DOWN */
const u16 necro_nmca_026_head[4] = { HEAD(4, 33, 0, 0, 0, 0, 0) };
const u16 necro_nmca_026[68] = {
    L4(1, 1, 0, 0, 0, 0, 0, 0x1E70, 0, 114, 0, 0, 0, 18, 6),
    L4(2, 1, 498, 0, 0, 0, 0, 0x1E71, 0, 114, 0, 0, 0, 6, 1),
    L4(13, 1, 0, 0, 0, 0, 0, 0x1E72, 0, 114, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x1E72, 0, 114, 0, 0, 0, 0, 0),
    L4(2, 64, 0, 0, 0, 0, 0, 0x1E75, 0, 114, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1E76, 0, 114, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1E70, 0, 114, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x1E70, 0, 114, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 27 PARING AIR F */
const u16 necro_nmca_027_head[4] = { HEAD(4, 20, 0, 0, 0, 0, 0) };
const u16 necro_nmca_027[68] = {
    L4(2, 0, 0, 0, 0, 0, 0, 0x1E78, 0, 8, 0, 0, 0, 18, 6),
    L4(2, 0, 498, 0, 0, 0, 0, 0x1E79, 0, 8, 0, 0, 0, 6, 2),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1E7A, 0, 8, 0, 0, 0, 0, 0),
    L4(12, 0, 0, 0, 0, 0, 0, 0x1E7B, 0, 8, 0, 0, 0, 0, 0),
    L4(4, 64, 0, 0, 0, 0, 0, 0x1E7C, 0, 8, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1E7D, 0, 8, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x1E77, 0, 8, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 1), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 28 PARING AIR B */
const u16 necro_nmca_028_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 necro_nmca_028[60] = {
    CMD(CM_JSR, 8, 1, 1), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x1E78, 0, 8, 0, 0, 0, 18, 6),
    L4(3, 0, 498, 0, 0, 0, 0, 0x1E79, 0, 8, 0, 0, 0, 6, 2),
    L4(11, 0, 0, 0, 0, 0, 0, 0x1E7A, 0, 8, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1E7B, 0, 8, 0, 0, 0, 0, 0),
    L4(4, 64, 0, 0, 0, 0, 0, 0x1E5F, 0, 8, 0, 0, 0, 0, 0),
    CMD(CM_JMP, 0, 16, 4), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 29 GUARD HEAD */
const u16 necro_nmca_029_head[4] = { HEAD(4, 2, 0, 0, 0, 0, 0) };
const u16 necro_nmca_029[60] = {
    L4(4, 0, 0, 0, 0, 0, 0, 0x1E61, 0, 113, 0, 0, 0, 0, 0),
    L4(4, 32, 0, 0, 0, 0, 0, 0x1E62, 0, 113, 0, 0, 0, 0, 0),
    L4(4, 32, 0, 0, 0, 0, 0, 0x1E63, 0, 113, 0, 0, 0, 0, 0),
    L4(1, 1, 0, 0, 0, 0, 0, 0x1E63, 0, 113, 0, 0, 0, 0, 0),
    L4(4, 64, 0, 0, 0, 0, 0, 0x1E66, 0, 113, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1E67, 0, 113, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x1E67, 0, 113, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 30 GUARD UP */
const u16 necro_nmca_030_head[4] = { HEAD(4, 2, 0, 0, 0, 0, 0) };
const u16 necro_nmca_030[60] = {
    L4(2, 0, 0, 0, 0, 0, 0, 0x1E67, 0, 113, 0, 0, 0, 0, 0),
    L4(4, 32, 0, 0, 0, 0, 0, 0x1E68, 0, 113, 0, 0, 0, 0, 0),
    L4(4, 32, 0, 0, 0, 0, 0, 0x1E69, 0, 113, 0, 0, 0, 0, 0),
    L4(1, 1, 0, 0, 0, 0, 0, 0x1E69, 0, 113, 0, 0, 0, 0, 0),
    L4(4, 64, 0, 0, 0, 0, 0, 0x1E6C, 0, 113, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1E67, 0, 113, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x1E67, 0, 113, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 31 GUARD DOWN */
const u16 necro_nmca_031_head[4] = { HEAD(4, 33, 0, 0, 0, 0, 0) };
const u16 necro_nmca_031[68] = {
    L4(2, 0, 0, 0, 0, 0, 0, 0x1E70, 0, 114, 0, 0, 0, 0, 0),
    L4(4, 32, 0, 0, 0, 0, 0, 0x1E71, 0, 114, 0, 0, 0, 0, 0),
    L4(4, 32, 0, 0, 0, 0, 0, 0x1E72, 0, 114, 0, 0, 0, 0, 0),
    L4(1, 1, 0, 0, 0, 0, 0, 0x1E72, 0, 114, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1E75, 0, 114, 0, 0, 0, 0, 0),
    L4(4, 64, 0, 0, 0, 0, 0, 0x1E76, 0, 114, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1E70, 0, 114, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x1E70, 0, 114, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 32 GUARD AIR */
const u16 necro_nmca_032_head[4] = { HEAD(4, 33, 0, 0, 0, 0, 0) };
const u16 necro_nmca_032[76] = {
    L4(4, 0, 0, 0, 0, 0, 0, 0x1E77, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1E78, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1E79, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 3, 0, 0, 0, 0, 0, 0x1E7A, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1E7B, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1E7C, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1E7D, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1E77, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x1E77, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 33 no name, 34 no name, 35 no name, 36 no name ... */
const u16 necro_nmca_033_head[4] = { HEAD(4, 33, 0, 0, 0, 0, 0) };
const u16 necro_nmca_033[12] = {
    L4(250, 255, 0, 0, 0, 0, 0, 0x1E69, 0, 16, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 38 P BREAK ZUJOU, 39 P BREAK UP */
const u16 necro_nmca_038_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 necro_nmca_038[76] = {
    CMD(CM_JSR, 8, 24, 1), 0, 0, 0, 0,
    L4(2, 132, 0, 0, 0, 0, 0, 0x1E69, 0, 113, 0, 0, 0, 18, 8),
    L4(250, 0, 0, 0, 0, 0, 0, 0x1E68, 0, 113, 0, 0, 0, 25, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1E40, 0, 146, 0, 0, 0, 0, 0),
    CMD(CM_PA_X, 0, -3072, 0), 0, 0, 0, 0,
    L4(4, 1, 0, 0, 0, 0, 0, 0x1E41, 0, 146, 0, 0, 0, 22, 24),
    CMD(CM_PA_X, 0, -7168, 0), 0, 0, 0, 0,
    L4(250, 0, 0, 0, 0, 0, 0, 0x1E42, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 40 P BREAK DOWN */
const u16 necro_nmca_040_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 necro_nmca_040[76] = {
    CMD(CM_JSR, 8, 24, 1), 0, 0, 0, 0,
    L4(2, 132, 0, 0, 0, 0, 0, 0x1E71, 0, 114, 0, 0, 0, 18, 8),
    L4(250, 0, 0, 0, 0, 0, 0, 0x1E72, 0, 114, 0, 0, 0, 25, 1),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1E76, 0, 1, 0, 0, 0, 22, 0),
    CMD(CM_PA_X, 0, -3072, 0), 0, 0, 0, 0,
    L4(4, 1, 0, 0, 0, 0, 0, 0x2095, 0, 1, 0, 0, 0, 22, 24),
    CMD(CM_PA_X, 0, -7168, 0), 0, 0, 0, 0,
    L4(250, 0, 0, 0, 0, 0, 0, 0x2090, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 41 P BREAK AIR F, 42 P BREAK AIR R */
const u16 necro_nmca_041_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 necro_nmca_041[44] = {
    CMD(CM_JSR, 8, 3, 1), 0, 0, 0, 0,
    L4(2, 132, 0, 0, 0, 0, 0, 0x1E78, 0, 8, 0, 0, 0, 18, 8),
    L4(250, 0, 498, 0, 0, 0, 0, 0x1E79, 0, 8, 0, 0, 0, 25, 2),
    CMD(CM_JPSS, 0, 45, 4), 0, 0, 0, 0,
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 43 TUKAMIHAZUSI */
const u16 necro_nmca_043_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 necro_nmca_043[76] = {
    CMD(CM_JSR, 8, 24, 1), 0, 0, 0, 0,
    L4(2, 132, 0, 0, 0, 0, 0, 0x1E69, 0, 113, 0, 0, 0, 18, 9),
    L4(250, 0, 0, 0, 0, 0, 0, 0x1E68, 0, 113, 0, 0, 0, 25, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1E40, 0, 146, 0, 0, 0, 0, 0),
    CMD(CM_PA_X, 0, -3072, 0), 0, 0, 0, 0,
    L4(4, 1, 0, 0, 0, 0, 0, 0x1E41, 0, 146, 0, 0, 0, 22, 24),
    CMD(CM_PA_X, 0, -7168, 0), 0, 0, 0, 0,
    L4(250, 0, 0, 0, 0, 0, 0, 0x1E42, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 44 TUKAMIHAZUSARE */
const u16 necro_nmca_044_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 necro_nmca_044[108] = {
    L4(3, 133, 0, 0, 0, 0, 0, 0x2097, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x2097, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x2098, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x2099, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 1, 0, 0, 0, 0, 0, 0x209A, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1E85, 0, 1, 0, 0, 0, 0, 0),
    L4(9, 0, 0, 0, 0, 0, 0, 0x1E86, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 64, 0, 0, 0, 0, 0, 0x1E87, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1E88, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1E3B, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1E3C, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1E3D, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x1E3D, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 45 TUKAMIHAZUSI */
const u16 necro_nmca_045_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 necro_nmca_045[116] = {
    CMD(CM_JSR, 8, 1, 1), 0, 0, 0, 0,
    L4(2, 132, 0, 0, 0, 0, 0, 0x1E78, 0, 8, 0, 0, 0, 18, 9),
    L4(250, 0, 498, 0, 0, 0, 0, 0x1E79, 0, 8, 0, 0, 0, 25, 2),
    L4(4, 1, 0, 0, 0, 0, 0, 0x1E60, 0, 8, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1E55, 0, 9, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1E54, 0, 7, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1E53, 0, 7, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1E52, 0, 7, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1E51, 0, 7, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1E50, 0, 7, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x1E5B, 0, 7, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x1E5C, 0, 11, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x1E5D, 0, 11, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 46 TUKAMIHAZUSARE */
const u16 necro_nmca_046_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 necro_nmca_046[432] = {
    CMD(CM_JSR, 8, 1, 1), 0, 0, 0, 0,
    L4(4, 132, 0, 0, 0, 0, 0, 0x1E48, 0, 7, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x1E49, 0, 7, 0, 0, 0, 0, 0),
    L4(6, 1, 0, 0, 0, 0, 0, 0x1E4A, 0, 7, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x1E48, 0, 7, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x1E47, 0, 6, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x1E4B, 0, 6, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x1E4C, 0, 6, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0), 0x0006, 0x0000, 0x0000, 0x0000,
    L4(4, 0, 0, 0, 0, 0, 0, 0x2096, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_DUMMY, 16, 0, 0), 0x0400, 0x0000, 0x0000, 0x2097,
    CMD(CM_DUMMY, 8192, 0, 0), 0x0000, 0x0010, 0x0000, 0x0000,
    L4(4, 0, 0, 0, 0, 0, 0, 0x2098, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_DUMMY, 16, 0, 0), 0x0400, 0x0000, 0x0000, 0x2099,
    CMD(CM_DUMMY, 8192, 0, 0), 0x0000, 0x0010, 0x0000, 0x0000,
    L4(4, 0, 0, 0, 0, 0, 0, 0x209A, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_DUMMY, 16, 0, 0), 0x0400, 0x0000, 0x0000, 0x1E85,
    CMD(CM_DUMMY, 8192, 0, 0), 0x0000, 0x0010, 0x0000, 0x0000,
    L4(4, 0, 0, 0, 0, 0, 0, 0x1E86, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_DUMMY, 16, 0, 0), 0x0400, 0x0000, 0x0000, 0x1E87,
    CMD(CM_DUMMY, 8192, 0, 0), 0x0000, 0x0010, 0x0000, 0x0000,
    L4(4, 0, 0, 0, 0, 0, 0, 0x1E88, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_DUMMY, 16, 0, 0), 0x0400, 0x0000, 0x0000, 0x1E3B,
    CMD(CM_DUMMY, 8192, 0, 0), 0x0000, 0x0010, 0x0000, 0x0000,
    L4(4, 0, 0, 0, 0, 0, 0, 0x1E3C, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_DUMMY, 16, 0, 0), 0x0400, 0x0000, 0x0000, 0x1E3D,
    CMD(CM_DUMMY, 8192, 0, 0), 0x0000, 0x0010, 0x0000, 0x0000,
    L4(250, 255, 0, 0, 0, 0, 0, 0x1E3D, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_DUMMY, 16, 0, 0), 0x0001, 0x0000, 0x0000, 0x0000,
    CMD(CM_JPSS, 6144, 0, 0), 0x0400, 0x0000, 0x0000, 0x1F20,
    CMD(CM_DUMMY, 8192, 0, 0), 0x0400, 0x0000, 0x0000, 0x1F21,
    CMD(CM_DUMMY, 8192, 0, 0), 0x0400, 0x0000, 0x0000, 0x1F22,
    CMD(CM_DUMMY, 8192, 0, 0), 0x0400, 0x0000, 0x0000, 0x1F23,
    CMD(CM_DUMMY, 8192, 0, 0), 0x0400, 0x0000, 0x0000, 0x1F24,
    CMD(CM_DUMMY, 8192, 0, 0), 0x0400, 0x0000, 0x0000, 0x1F25,
    CMD(CM_DUMMY, 8192, 0, 0), 0x0400, 0x0000, 0x0000, 0x1EC0,
    CMD(CM_DUMMY, 8192, 0, 0), 0x0400, 0x0000, 0x0000, 0x1EC1,
    CMD(CM_DUMMY, 8192, 0, 0), 0x0400, 0x0000, 0x0000, 0x1EC2,
    CMD(CM_DUMMY, 8192, 0, 0), 0x0400, 0x0000, 0x0000, 0x1EC3,
    CMD(CM_DUMMY, 8192, 0, 0), 0x0400, 0x0000, 0x0000, 0x1EC4,
    CMD(CM_DUMMY, 8192, 0, 0), 0x0400, 0x0000, 0x0000, 0x1EC5,
    CMD(CM_DUMMY, 8192, 0, 0), 0x0400, 0x0000, 0x0000, 0x1EC6,
    CMD(CM_DUMMY, 8192, 0, 0), 0x0400, 0x0000, 0x0000, 0x1EC7,
    CMD(CM_DUMMY, 8192, 0, 0), 0x0400, 0x0000, 0x0000, 0x1EC8,
    CMD(CM_DUMMY, 8192, 0, 0), 0x0400, 0x0000, 0x0000, 0x1EC9,
    CMD(CM_DUMMY, 8192, 0, 0), 0x0400, 0x0000, 0x0000, 0x1ECA,
    CMD(CM_DUMMY, 8192, 0, 0), 0x0400, 0x0000, 0x0000, 0x1ECB,
    CMD(CM_DUMMY, 8192, 0, 0), 0x0400, 0x0000, 0x0000, 0x1ECC,
    CMD(CM_DUMMY, 8192, 0, 0), 0x0400, 0x0000, 0x0000, 0x1E41,
    CMD(CM_DUMMY, 8192, 0, 0), 0x0400, 0x0000, 0x0000, 0x1E40,
    CMD(CM_DUMMY, 8192, 0, 0), 0x0400, 0x0000, 0x0000, 0x1E3F,
    CMD(CM_DUMMY, 8192, 0, 0), 0xFAFF, 0x0000, 0x0000, 0x1E3F,
    CMD(CM_DUMMY, 8192, 0, 0), 0x0001, 0x0000, 0x0000, 0x0000,
};

extern const u16 necro_dmca_000[], necro_dmca_001[], necro_dmca_002[], necro_dmca_003[], necro_dmca_004[], necro_dmca_006[], necro_dmca_008[], necro_dmca_009[], necro_dmca_010[], necro_dmca_014[], necro_dmca_015[], necro_dmca_018[], necro_dmca_019[], necro_dmca_022[], necro_dmca_024[], necro_dmca_025[], necro_dmca_026[], necro_dmca_028[], necro_dmca_029[], necro_dmca_030[], necro_dmca_034[], necro_dmca_036[], necro_dmca_048[], necro_dmca_049[], necro_dmca_050[], necro_dmca_052[], necro_dmca_060[], necro_dmca_064[], necro_dmca_065[], necro_dmca_066[], necro_dmca_067[], necro_dmca_068[], necro_dmca_069[], necro_dmca_070[], necro_dmca_071[], necro_dmca_072[], necro_dmca_073[], necro_dmca_074[], necro_dmca_075[], necro_dmca_076[], necro_dmca_078[], necro_dmca_079[], necro_dmca_080[], necro_dmca_082[], necro_dmca_083[], necro_dmca_084[], necro_dmca_090[], necro_dmca_091[], necro_dmca_096[], necro_dmca_097[];

/* dmca scripts (debug viewer: DAMAGE): 98 entries */
const u32 necro_dmca[99] = {
    (u32)necro_dmca_000,  /* 0 GUARD HEAD */
    (u32)necro_dmca_001,  /* 1 GUARD UP */
    (u32)necro_dmca_002,  /* 2 GUARD DOWN */
    (u32)necro_dmca_003,  /* 3 GUARD AIR */
    (u32)necro_dmca_004,  /* 4 HUSHIN HEAD */
    (u32)necro_dmca_004,  /* 5 HUSHIN UP */
    (u32)necro_dmca_006,  /* 6 HUSHIN DOWN */
    (u32)necro_dmca_006,  /* 7 HUSHIN AIR */
    (u32)necro_dmca_008,  /* 8 FACE S */
    (u32)necro_dmca_009,  /* 9 FACE M */
    (u32)necro_dmca_010,  /* 10 FACE L */
    (u32)necro_dmca_010,  /* 11 FACE SP */
    (u32)necro_dmca_008,  /* 12 FOOK OKU S */
    (u32)necro_dmca_009,  /* 13 FOOK OKU M */
    (u32)necro_dmca_014,  /* 14 FOOK OKU L */
    (u32)necro_dmca_015,  /* 15 FOOK OKU SP */
    (u32)necro_dmca_008,  /* 16 FOOK TEMAE S */
    (u32)necro_dmca_009,  /* 17 FOOK TEMAE M */
    (u32)necro_dmca_018,  /* 18 FOOK TEMAE L */
    (u32)necro_dmca_019,  /* 19 FOOK TEMAE SP */
    (u32)necro_dmca_008,  /* 20 UPPER S */
    (u32)necro_dmca_009,  /* 21 UPPER M */
    (u32)necro_dmca_022,  /* 22 UPPER L */
    (u32)necro_dmca_022,  /* 23 UPPER SP */
    (u32)necro_dmca_024,  /* 24 NOUTEN S */
    (u32)necro_dmca_025,  /* 25 NOUTEN M */
    (u32)necro_dmca_026,  /* 26 NOUTEN L */
    (u32)necro_dmca_026,  /* 27 NOUTEN SP */
    (u32)necro_dmca_028,  /* 28 BODY BROW S */
    (u32)necro_dmca_029,  /* 29 BODY BROW M */
    (u32)necro_dmca_030,  /* 30 BODY BROW L */
    (u32)necro_dmca_030,  /* 31 BODY BROW SP */
    (u32)necro_dmca_028,  /* 32 BODY UPPER S */
    (u32)necro_dmca_029,  /* 33 BODY UPPER M */
    (u32)necro_dmca_034,  /* 34 BODY UPPER L */
    (u32)necro_dmca_034,  /* 35 BODY UPPER SP */
    (u32)necro_dmca_036,  /* 36 TATAKI S */
    (u32)necro_dmca_036,  /* 37 TATAKI M */
    (u32)necro_dmca_036,  /* 38 TATAKI L */
    (u32)necro_dmca_036,  /* 39 TATAKI SP */
    (u32)necro_dmca_036,  /* 40 TATAKI V. S */
    (u32)necro_dmca_036,  /* 41 TATAKI V. M */
    (u32)necro_dmca_036,  /* 42 TATAKI V. L */
    (u32)necro_dmca_036,  /* 43 TATAKI V. SP */
    (u32)necro_dmca_008,  /* 44 NOBASITA TE S */
    (u32)necro_dmca_009,  /* 45 NOBASITA TE M */
    (u32)necro_dmca_010,  /* 46 NOBASITA TE L */
    (u32)necro_dmca_010,  /* 47 NOBASITA TE SP */
    (u32)necro_dmca_048,  /* 48 KAGAMI S */
    (u32)necro_dmca_049,  /* 49 KAGAMI M */
    (u32)necro_dmca_050,  /* 50 KAGAMI L */
    (u32)necro_dmca_050,  /* 51 KAGAMI SP */
    (u32)necro_dmca_052,  /* 52 KGM TATAKI S */
    (u32)necro_dmca_052,  /* 53 KGM TATAKI M */
    (u32)necro_dmca_052,  /* 54 KGM TATAKI L */
    (u32)necro_dmca_052,  /* 55 KGM TATAKI SP */
    (u32)necro_dmca_052,  /* 56 KGM TTKI V.S */
    (u32)necro_dmca_052,  /* 57 KGM TTKI V.M */
    (u32)necro_dmca_052,  /* 58 KGM TTKI V.L */
    (u32)necro_dmca_052,  /* 59 KGM TTKI V.SP */
    (u32)necro_dmca_060,  /* 60 NEKOROBI S */
    (u32)necro_dmca_060,  /* 61 NEKOROBI M */
    (u32)necro_dmca_060,  /* 62 NEKOROBI L */
    (u32)necro_dmca_060,  /* 63 NEKOROBI SP */
    (u32)necro_dmca_064,  /* 64 OKIAGARI */
    (u32)necro_dmca_065,  /* 65 OKIAGARI F */
    (u32)necro_dmca_066,  /* 66 OKIAGARI B */
    (u32)necro_dmca_067,  /* 67 LOSE NO STAND */
    (u32)necro_dmca_068,  /* 68 LOSE SONABA */
    (u32)necro_dmca_069,  /* 69 LOSE KAGAMI */
    (u32)necro_dmca_070,  /* 70 PIYO */
    (u32)necro_dmca_071,  /* 71 UKEMI MOVE F */
    (u32)necro_dmca_072,  /* 72 UKEMI MOVE R */
    (u32)necro_dmca_073,  /* 73 SHIMEOTASARE */
    (u32)necro_dmca_074,  /* 74 TATI TOUKETU S */
    (u32)necro_dmca_075,  /* 75 TATI TOUKETU M */
    (u32)necro_dmca_076,  /* 76 TATI TOUKETU L */
    (u32)necro_dmca_076,  /* 77 TATI TOUKETU P */
    (u32)necro_dmca_078,  /* 78 KGM TOUKETU S */
    (u32)necro_dmca_079,  /* 79 KGM TOUKETU M */
    (u32)necro_dmca_080,  /* 80 KGM TOUKETU L */
    (u32)necro_dmca_080,  /* 81 KGM TOUKETU P */
    (u32)necro_dmca_082,  /* 82 TATI DENGEKI S */
    (u32)necro_dmca_083,  /* 83 TATI DENGEKI M */
    (u32)necro_dmca_084,  /* 84 TATI DENGEKI L */
    (u32)necro_dmca_084,  /* 85 TATI DENGEKI P */
    (u32)necro_dmca_082,  /* 86 KGM DENGEKI S */
    (u32)necro_dmca_083,  /* 87 KGM DENGEKI M */
    (u32)necro_dmca_084,  /* 88 KGM DENGEKI L */
    (u32)necro_dmca_084,  /* 89 KGM DENGEKI P */
    (u32)necro_dmca_090,  /* 90 OKIAGARI FRONT */
    (u32)necro_dmca_091,  /* 91 OKIAGARI REAR */
    (u32)necro_dmca_008,  /* 92 TATI MOE S */
    (u32)necro_dmca_009,  /* 93 TATI MOE M */
    (u32)necro_dmca_010,  /* 94 TATI MOE L */
    (u32)necro_dmca_010,  /* 95 TATI MOE SP */
    (u32)necro_dmca_096,  /* 96 no name */
    (u32)necro_dmca_097,  /* 97 no name */
    0
};

/* script: 0 GUARD HEAD */
const u16 necro_dmca_000_head[4] = { HEAD(4, 2, 0, 0, 0, 0, 0) };
const u16 necro_dmca_000[52] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x1E63, 0, 113, 0, 0, 0, 0, 0),
    L4(2, 2, 0, 0, 0, 0, 0, 0x1E64, 0, 113, 0, 0, 0, 0, 0),
    L4(250, 132, 0, 0, 0, 0, 0, 0x1E65, 0, 113, 0, 0, 0, 0, 0),
    L4(2, 64, 0, 0, 0, 0, 0, 0x1E66, 0, 113, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1E67, 0, 113, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x1E67, 0, 113, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 1 GUARD UP */
const u16 necro_dmca_001_head[4] = { HEAD(4, 2, 0, 0, 0, 0, 0) };
const u16 necro_dmca_001[52] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x1E69, 0, 113, 0, 0, 0, 0, 0),
    L4(2, 2, 0, 0, 0, 0, 0, 0x1E6A, 0, 113, 0, 0, 0, 0, 0),
    L4(250, 132, 0, 0, 0, 0, 0, 0x1E6B, 0, 113, 0, 0, 0, 0, 0),
    L4(2, 64, 0, 0, 0, 0, 0, 0x1E6C, 0, 113, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1E67, 0, 113, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x1E67, 0, 113, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 2 GUARD DOWN */
const u16 necro_dmca_002_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 necro_dmca_002[60] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x1E72, 0, 114, 0, 0, 0, 0, 0),
    L4(1, 2, 0, 0, 0, 0, 0, 0x1E73, 0, 114, 0, 0, 0, 0, 0),
    L4(250, 132, 0, 0, 0, 0, 0, 0x1E74, 0, 114, 0, 0, 0, 0, 0),
    L4(2, 64, 0, 0, 0, 0, 0, 0x1E75, 0, 114, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1E76, 0, 114, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1E70, 0, 114, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x1E70, 0, 114, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 3 GUARD AIR */
const u16 necro_dmca_003_head[4] = { HEAD(4, 33, 0, 0, 0, 0, 0) };
const u16 necro_dmca_003[124] = {
    L4(1, 131, 0, 0, 0, 0, 0, 0x1E79, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x1E79, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_RJA, 1, 3, 7), 0, 0, 0, 0,
    L4(1, 3, 0, 0, 0, 0, 0, 0x1E7A, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 139, 0, 0, 0, 0, 0, 0x1E7B, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_END, 0, 0, 5), 0, 0, 0, 0,
    L4(250, 136, 0, 0, 0, 0, 0, 0x1E6B, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x1E6C, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1E67, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x1E67, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_JSR, 8, 1, 1), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x1E7C, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1E7D, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x1E77, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_JMP, 0, 15, 13), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 4 HUSHIN HEAD, 5 HUSHIN UP */
const u16 necro_dmca_004_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 necro_dmca_004[68] = {
    CMD(CM_JSR, 8, 6, 1), 0, 0, 0, 0,
    L4(3, 0, 0, 0, 0, 0, 0, 0x2085, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x2086, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x2087, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x2089, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x2088, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x208A, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x208B, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 6 HUSHIN DOWN, 7 HUSHIN AIR */
const u16 necro_dmca_006_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 necro_dmca_006[68] = {
    CMD(CM_JSR, 8, 6, 1), 0, 0, 0, 0,
    L4(3, 0, 0, 0, 0, 0, 0, 0x208D, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x208E, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x208F, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x2089, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x2088, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x208A, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x208B, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 8 FACE S, 12 FOOK OKU S, 16 FOOK TEMAE S, 20 UPPER S ... */
const u16 necro_dmca_008_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 necro_dmca_008[84] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x1FC0, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 134, 494, 0, 0, 0, 0, 0x1FC1, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1FC1, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_WCGT, 16398, 2, -32767), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x1FC2, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x1FC3, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1E3B, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1E3C, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1E3D, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x1E3D, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 9 FACE M, 13 FOOK OKU M, 17 FOOK TEMAE M, 21 UPPER M ... */
const u16 necro_dmca_009_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 necro_dmca_009[108] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x1FC1, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 137, 494, 0, 0, 0, 0, 0x1FC5, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1FC6, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_WCGT, 16398, 6, -32767), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 0, 0, 0x1FC7, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1FC8, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1FC9, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1FCA, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x1FCB, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1E3B, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1E3C, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1E3D, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x1E3D, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 10 FACE L, 11 FACE SP, 46 NOBASITA TE L, 47 NOBASITA TE SP ... */
const u16 necro_dmca_010_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 necro_dmca_010[140] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x1FC6, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 139, 494, 0, 0, 0, 0, 0x1FCD, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1FCE, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1FCF, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1FD0, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1FCF, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1FD0, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1FD1, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1FD2, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_WCGT, 16398, 0, -32767), 0, 0, 0, 0,
    L4(1, 64, 0, 0, 0, 0, 0, 0x1FD7, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1FD8, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1E21, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1E3B, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1E3C, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1E3D, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x1E3D, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 18 FOOK TEMAE L */
const u16 necro_dmca_018_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 necro_dmca_018[132] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x2061, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 138, 494, 0, 0, 0, 0, 0x2061, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x2062, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 10, 0, 0, 0, 0, 0, 0x2063, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 10, 0, 0, 0, 0, 0, 0x2064, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 10, 0, 0, 0, 0, 0, 0x2065, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_WCGT, 16398, 5, -32767), 0, 0, 0, 0,
    L4(3, 10, 0, 0, 0, 0, 0, 0x2066, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 10, 0, 0, 0, 0, 0, 0x209B, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 64, 0, 0, 0, 0, 0, 0x1FD5, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1FD6, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1FD7, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1E3B, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1E3C, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1E3D, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x1E3D, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 19 FOOK TEMAE SP */
const u16 necro_dmca_019_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 necro_dmca_019[132] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x2060, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 138, 494, 0, 0, 0, 0, 0x2061, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 10, 0, 0, 0, 0, 0, 0x2062, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 10, 0, 0, 0, 0, 0, 0x2063, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 10, 0, 0, 0, 0, 0, 0x2064, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 10, 0, 0, 0, 0, 0, 0x2065, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_WCGT, 16398, 3, -32767), 0, 0, 0, 0,
    L4(1, 10, 0, 0, 0, 0, 0, 0x2066, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 10, 0, 0, 0, 0, 0, 0x209B, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 64, 0, 0, 0, 0, 0, 0x1FD5, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1FD6, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1FD7, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1E3B, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1E3C, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1E3D, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x1E3D, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 14 FOOK OKU L */
const u16 necro_dmca_014_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 necro_dmca_014[140] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x1FCC, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 139, 494, 0, 0, 0, 0, 0x1FCF, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 10, 0, 0, 0, 0, 0, 0x1FD1, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 10, 0, 0, 0, 0, 0, 0x2067, 0, 1, 0, 0, 0, 0, 0),
    L4(5, 10, 0, 0, 0, 0, 0, 0x2068, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 10, 0, 0, 0, 0, 0, 0x2069, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 10, 0, 0, 0, 0, 0, 0x2065, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_WCGT, 16398, 3, -32767), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x2066, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x209B, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 64, 0, 0, 0, 0, 0, 0x1FD5, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1FD6, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1FD7, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1E3B, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1E3C, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1E3D, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x1E3D, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 15 FOOK OKU SP */
const u16 necro_dmca_015_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 necro_dmca_015[140] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x1FCC, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 139, 494, 0, 0, 0, 0, 0x1FCF, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1FD1, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 10, 0, 0, 0, 0, 0, 0x2067, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 10, 0, 0, 0, 0, 0, 0x2068, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 10, 0, 0, 0, 0, 0, 0x2069, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 10, 0, 0, 0, 0, 0, 0x2065, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_WCGT, 16398, 4, -32767), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x2066, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x209B, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 64, 0, 0, 0, 0, 0, 0x1FD5, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1FD6, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1FD7, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1E3B, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1E3C, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1E3D, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x1E3D, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 34 BODY UPPER L, 35 BODY UPPER SP */
const u16 necro_dmca_034_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 necro_dmca_034[108] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x2074, 0, 1, 0, 0, 0, 0, 0),
    L4(8, 137, 494, 0, 0, 0, 0, 0x2080, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x2081, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x2082, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_WCGT, 16398, 6, -32767), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x1FE6, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1FE7, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1FE8, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 64, 0, 0, 0, 0, 0, 0x1FE9, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1FEA, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1E27, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1E28, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x1E28, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 22 UPPER L, 23 UPPER SP */
const u16 necro_dmca_022_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 necro_dmca_022[108] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x1FE8, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 137, 494, 0, 0, 0, 0, 0x2081, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x2081, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_WCGT, 16398, 13, -32767), 0, 0, 0, 0,
    L4(6, 0, 0, 0, 0, 0, 0, 0x2082, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1FE6, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1FE7, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1FE8, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 64, 0, 0, 0, 0, 0, 0x1FE9, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1FEA, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1E27, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1E28, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x1E28, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 24 NOUTEN S */
const u16 necro_dmca_024_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 necro_dmca_024[92] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x2074, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 135, 494, 0, 0, 0, 0, 0x2075, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x2076, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_WCGT, 16398, 4, -32767), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x2077, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x2078, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 64, 0, 0, 0, 0, 0, 0x1FE9, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1FEA, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1E27, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1E28, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x1E28, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 25 NOUTEN M */
const u16 necro_dmca_025_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 necro_dmca_025[92] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x2074, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 135, 494, 0, 0, 0, 0, 0x2075, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x2076, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_WCGT, 16398, 4, -32767), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x2077, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x2078, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 64, 0, 0, 0, 0, 0, 0x1FE9, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1FEA, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1E27, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1E28, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x1E28, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 26 NOUTEN L, 27 NOUTEN SP */
const u16 necro_dmca_026_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 necro_dmca_026[92] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x2075, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 135, 494, 0, 0, 0, 0, 0x2075, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x2076, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_WCGT, 16398, 7, -32767), 0, 0, 0, 0,
    L4(4, 0, 0, 0, 0, 0, 0, 0x2077, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x2078, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 64, 0, 0, 0, 0, 0, 0x1FE9, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1FEA, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1E27, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1E28, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x1E28, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 28 BODY BROW S, 32 BODY UPPER S */
const u16 necro_dmca_028_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 necro_dmca_028[84] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x1FD9, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 135, 494, 0, 0, 0, 0, 0x1FDA, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1FDA, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_WCGT, 16398, 4, -32767), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x1FDB, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1FDC, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 64, 0, 0, 0, 0, 0, 0x1E3B, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1E3C, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1E3D, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x1E3D, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 29 BODY BROW M, 33 BODY UPPER M */
const u16 necro_dmca_029_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 necro_dmca_029[100] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x1FDD, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 136, 494, 0, 0, 0, 0, 0x1FDE, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1FDF, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_WCGT, 16398, 4, -32767), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x1FE0, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1FDA, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1FDB, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 64, 0, 0, 0, 0, 0, 0x1FDC, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1E3B, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1E3C, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1E3D, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x1E3D, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 30 BODY BROW L, 31 BODY BROW SP */
const u16 necro_dmca_030_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 necro_dmca_030[124] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x1FE1, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 139, 494, 0, 0, 0, 0, 0x1FE2, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1FE3, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1FE4, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_WCGT, 16398, 6, -32767), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x1FE0, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1FE5, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1FE6, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1FE7, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1FE8, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 64, 0, 0, 0, 0, 0, 0x1FE9, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1FEA, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1E27, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1E28, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x1E28, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 36 TATAKI S, 37 TATAKI M, 38 TATAKI L, 39 TATAKI SP ... */
const u16 necro_dmca_036_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 necro_dmca_036[36] = {
    CMD(CM_RJA, 7, 8, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x2083, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 494, 0, 0, 0, 0, 0x2084, 0, 115, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 48 KAGAMI S */
const u16 necro_dmca_048_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 necro_dmca_048[84] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x1FEB, 0, 2, 0, 0, 0, 0, 0),
    L4(1, 134, 494, 0, 0, 0, 0, 0x1FEC, 0, 2, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1FEC, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_WCGT, 16398, 2, -32767), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x1FED, 0, 2, 0, 0, 0, 0, 0),
    L4(4, 64, 0, 0, 0, 0, 0, 0x1FEE, 0, 2, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1E22, 0, 2, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1E23, 0, 2, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1E24, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x1E24, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 49 KAGAMI M */
const u16 necro_dmca_049_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 necro_dmca_049[100] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x1FF9, 0, 2, 0, 0, 0, 0, 0),
    L4(4, 136, 494, 0, 0, 0, 0, 0x1FF0, 0, 2, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1FF1, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_WCGT, 16398, 5, -32767), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 0, 0, 0x1FF2, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1FF3, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1FF4, 0, 2, 0, 0, 0, 0, 0),
    L4(1, 64, 0, 0, 0, 0, 0, 0x1FF5, 0, 2, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1E22, 0, 2, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1E23, 0, 2, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1E24, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x1E24, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 50 KAGAMI L, 51 KAGAMI SP */
const u16 necro_dmca_050_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 necro_dmca_050[164] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x1FF1, 0, 2, 0, 0, 0, 0, 0),
    L4(4, 143, 494, 0, 0, 0, 0, 0x1FF7, 0, 2, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1FF8, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1FF9, 0, 2, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1FFA, 0, 2, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1FF9, 0, 2, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1FFA, 0, 2, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1FFB, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_WCGT, 16398, 5, -32767), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 0, 0, 0x1FFC, 0, 2, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1FFD, 0, 2, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1FFE, 0, 2, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1FFF, 0, 2, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x2000, 0, 2, 0, 0, 0, 0, 0),
    L4(1, 64, 0, 0, 0, 0, 0, 0x2001, 0, 2, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x2002, 0, 2, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1E22, 0, 2, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1E23, 0, 2, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1E24, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x1E24, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 52 KGM TATAKI S, 53 KGM TATAKI M, 54 KGM TATAKI L, 55 KGM TATAKI SP ... */
const u16 necro_dmca_052_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 necro_dmca_052[36] = {
    CMD(CM_RJA, 7, 8, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x1FEB, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 0, 494, 0, 0, 0, 0, 0x2084, 0, 115, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 60 NEKOROBI S, 61 NEKOROBI M, 62 NEKOROBI L, 63 NEKOROBI SP */
const u16 necro_dmca_060_head[4] = { HEAD(4, 38, 0, 0, 0, 0, 0) };
const u16 necro_dmca_060[92] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x206A, 0, 168, 0, 0, 0, 0, 0),
    L4(3, 2, 494, 0, 0, 0, 0, 0x206B, 0, 168, 0, 0, 0, 0, 0),
    L4(3, 2, 0, 0, 0, 0, 0, 0x206C, 0, 168, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x2027, 0, 168, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x2029, 0, 168, 0, 0, 0, 0, 0),
    L4(3, 5, 0, 0, 0, 0, 0, 0x202A, 0, 168, 0, 0, 0, 0, 0),
    L4(3, 5, 0, 0, 0, 0, 0, 0x202B, 0, 168, 0, 0, 0, 0, 0),
    L4(3, 5, 0, 0, 0, 0, 0, 0x202C, 0, 168, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x202D, 0, 168, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x202E, 0, 168, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x202E, 0, 168, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 64 OKIAGARI */
const u16 necro_dmca_064_head[4] = { HEAD(4, 38, 0, 0, 0, 0, 0) };
const u16 necro_dmca_064[156] = {
    CMD(CM_JSR, 8, 5, 1), 0, 0, 0, 0,
    L4(12, 9, 0, 0, 0, 0, 0, 0x2003, 0, 115, 0, 0, 0, 0, 0),
    L4(1, 11, 0, 0, 0, 0, 0, 0x2003, 0, 115, 0, 0, 0, 0, 0),
    CMD(CM_DUMMY, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_DUMMY, 0, 0, 0), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x2004, 0, 115, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x2005, 0, 115, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x2006, 0, 115, 0, 0, 0, 0, 0),
    L4(4, 12, 0, 0, 0, 0, 0, 0x2007, 0, 115, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x2008, 0, 115, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1FE6, 0, 115, 0, 0, 0, 0, 0),
    L4(1, 64, 0, 0, 0, 0, 0, 0x1FE7, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1FE8, 0, 1, 0, 0, 0, 22, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1FE9, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1FE9, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1FEA, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1E27, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1E28, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x1E28, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 65 OKIAGARI F */
const u16 necro_dmca_065_head[4] = { HEAD(4, 38, 0, 0, 0, 0, 0) };
const u16 necro_dmca_065[148] = {
    CMD(CM_MXYT, 15, 0, 0), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x2010, 0, 115, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x2011, 0, 115, 0, 0, 0, 0, 0),
    L4(2, 1, 498, 0, 0, 0, 0, 0x2012, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x2013, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x2014, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x2015, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x2016, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x2017, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x2018, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 12, 0, 0, 0, 0, 0, 0x2019, 0, 0, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1E25, 0, 115, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1E21, 0, 115, 0, 0, 0, 0, 0),
    L4(1, 64, 0, 0, 0, 0, 0, 0x1E21, 0, 0, 0, 0, 0, 22, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1E26, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1E27, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1E28, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x1E28, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 66 OKIAGARI B */
const u16 necro_dmca_066_head[4] = { HEAD(4, 38, 0, 0, 0, 0, 0) };
const u16 necro_dmca_066[148] = {
    CMD(CM_MXYT, 16, 0, 0), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x2005, 0, 115, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x201A, 0, 115, 0, 0, 0, 0, 0),
    L4(2, 1, 498, 0, 0, 0, 0, 0x2018, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x2017, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x2016, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x2014, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x2013, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x2012, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x2019, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 12, 0, 0, 0, 0, 0, 0x2018, 0, 0, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1E25, 0, 115, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1E21, 0, 115, 0, 0, 0, 0, 0),
    L4(1, 64, 0, 0, 0, 0, 0, 0x1E21, 0, 0, 0, 0, 0, 22, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1E26, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1E27, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1E28, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x1E28, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 67 LOSE NO STAND */
const u16 necro_dmca_067_head[4] = { HEAD(4, 38, 0, 0, 0, 0, 0) };
const u16 necro_dmca_067[28] = {
    L4(8, 0, 0, 0, 0, 0, 0, 0x2003, 0, 0, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x2003, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 1), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 68 LOSE SONABA */
const u16 necro_dmca_068_head[4] = { HEAD(6, 38, 0, 0, 0, 0, 0) };
const u16 necro_dmca_068[148] = {
    L6(250, 130, 0, 0, 0, 0, 0, 0x2051, 0, 1, 0, 0, 0, 0, 0, 0, 0, 264, 0, 0),
    L6(250, 131, 0, 0, 0, 0, 0, 0x2052, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 1, 0, 0, 0, 0, 0, 0x2053, 0, 177, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(16, 0, 0, 0, 0, 0, 0, 0x2054, 0, 177, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(5, 0, 0, 0, 0, 0, 0, 0x2055, 0, 177, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x2056, 0, 177, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x2057, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(5, 0, 0, 0, 0, 0, 0, 0x2058, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 1, 0, 0, 0, 0, 0, 0x2059, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(5, 0, 0, 0, 0, 0, 0, 0x205A, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x205A, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 69 LOSE KAGAMI */
const u16 necro_dmca_069_head[4] = { HEAD(6, 38, 0, 0, 0, 0, 0) };
const u16 necro_dmca_069[148] = {
    L6(250, 130, 0, 0, 0, 0, 0, 0x2051, 0, 1, 0, 0, 0, 0, 0, 0, 0, 264, 0, 0),
    L6(250, 131, 0, 0, 0, 0, 0, 0x2052, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 1, 0, 0, 0, 0, 0, 0x2053, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(16, 0, 0, 0, 0, 0, 0, 0x2054, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(5, 0, 0, 0, 0, 0, 0, 0x2055, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x2056, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x2057, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(5, 0, 0, 0, 0, 0, 0, 0x2058, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 1, 0, 0, 0, 0, 0, 0x2059, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(5, 0, 0, 0, 0, 0, 0, 0x205A, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x205A, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 70 PIYO */
const u16 necro_dmca_070_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 necro_dmca_070[84] = {
    CMD(CM_EXEC, 5, 0, 0), 0, 0, 0, 0,
    L4(7, 0, 0, 0, 0, 0, 0, 0x2124, 0, 1, 0, 0, 0, 0, 0),
    L4(7, 0, 0, 0, 0, 0, 0, 0x2125, 0, 1, 0, 0, 0, 0, 0),
    L4(7, 0, 0, 0, 0, 0, 0, 0x2126, 0, 1, 0, 0, 0, 0, 0),
    L4(7, 0, 0, 0, 0, 0, 0, 0x2127, 0, 1, 0, 0, 0, 0, 0),
    L4(7, 0, 0, 0, 0, 0, 0, 0x2128, 0, 1, 0, 0, 0, 0, 0),
    L4(7, 0, 0, 0, 0, 0, 0, 0x2129, 0, 1, 0, 0, 0, 0, 0),
    L4(7, 0, 0, 0, 0, 0, 0, 0x212A, 0, 164, 0, 0, 0, 0, 0),
    L4(7, 0, 0, 0, 0, 0, 0, 0x212B, 0, 164, 0, 0, 0, 0, 0),
    CMD(CM_END, 0, 0, 2), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 71 UKEMI MOVE F */
const u16 necro_dmca_071_head[4] = { HEAD(4, 38, 0, 0, 0, 0, 0) };
const u16 necro_dmca_071[28] = {
    L4(3, 0, 0, 0, 0, 0, 0, 0x2010, 0, 115, 0, 0, 0, 0, 0),
    CMD(CM_MXYT, 19, 0, 0), 0, 0, 0, 0,
    CMD(CM_JMP, 1, 65, 3), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 72 UKEMI MOVE R */
const u16 necro_dmca_072_head[4] = { HEAD(4, 38, 0, 0, 0, 0, 0) };
const u16 necro_dmca_072[28] = {
    L4(3, 0, 0, 0, 0, 0, 0, 0x2005, 0, 115, 0, 0, 0, 0, 0),
    CMD(CM_MXYT, 20, 0, 0), 0, 0, 0, 0,
    CMD(CM_JMP, 1, 66, 3), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 73 SHIMEOTASARE */
const u16 necro_dmca_073_head[4] = { HEAD(4, 38, 0, 0, 0, 0, 0) };
const u16 necro_dmca_073[100] = {
    L4(3, 0, 0, 0, 0, 0, 0, 0x2051, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x2052, 0, 1, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x2053, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x2054, 0, 1, 0, 0, 0, 0, 0),
    L4(12, 0, 0, 0, 0, 0, 0, 0x2054, 0, 1, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x2055, 0, 0, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x2056, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x2057, 0, 0, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x2058, 0, 0, 0, 0, 0, 0, 0),
    L4(4, 1, 0, 0, 0, 0, 0, 0x2059, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x205A, 0, 0, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x205A, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 74 TATI TOUKETU S */
const u16 necro_dmca_074_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 necro_dmca_074[60] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x1FC0, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 131, 0, 0, 0, 0, 0, 0x1FC0, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x1FC3, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1E3B, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1E3C, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1E3D, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x1E3D, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 75 TATI TOUKETU M */
const u16 necro_dmca_075_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 necro_dmca_075[60] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x1FC4, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 131, 0, 0, 0, 0, 0, 0x1FC4, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x1FCB, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1E3B, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1E3C, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1E3D, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x1E3D, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 76 TATI TOUKETU L, 77 TATI TOUKETU P */
const u16 necro_dmca_076_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 necro_dmca_076[76] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x1FCC, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 131, 0, 0, 0, 0, 0, 0x1FCC, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x1FD7, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1FD8, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1E21, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1E3B, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1E3C, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1E3D, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x1E3D, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 78 KGM TOUKETU S */
const u16 necro_dmca_078_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 necro_dmca_078[60] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x1FEB, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 131, 0, 0, 0, 0, 0, 0x1FEB, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 64, 0, 0, 0, 0, 0, 0x1FEE, 0, 2, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1E22, 0, 2, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1E23, 0, 2, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1E24, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x1E24, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 79 KGM TOUKETU M */
const u16 necro_dmca_079_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 necro_dmca_079[60] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x1FEF, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 131, 0, 0, 0, 0, 0, 0x1FEF, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 64, 0, 0, 0, 0, 0, 0x1FF5, 0, 2, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1E22, 0, 2, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1E23, 0, 2, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1E24, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x1E24, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 80 KGM TOUKETU L, 81 KGM TOUKETU P */
const u16 necro_dmca_080_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 necro_dmca_080[68] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x1FF6, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 131, 0, 0, 0, 0, 0, 0x1FF6, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 64, 0, 0, 0, 0, 0, 0x2001, 0, 2, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x2002, 0, 2, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1E22, 0, 2, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1E23, 0, 2, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1E24, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x1E24, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 82 TATI DENGEKI S, 86 KGM DENGEKI S */
const u16 necro_dmca_082_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 necro_dmca_082[52] = {
    L4(3, 134, 0, 0, 0, 0, 0, 0x2155, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x2156, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x2155, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x2157, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 4), 0, 0, 0, 0,
    CMD(CM_JMP, 1, 8, 2), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 83 TATI DENGEKI M, 87 KGM DENGEKI M */
const u16 necro_dmca_083_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 necro_dmca_083[52] = {
    L4(3, 134, 0, 0, 0, 0, 0, 0x2155, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x2156, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x2155, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x2157, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 4), 0, 0, 0, 0,
    CMD(CM_JMP, 1, 9, 2), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 84 TATI DENGEKI L, 85 TATI DENGEKI P, 88 KGM DENGEKI L, 89 KGM DENGEKI P */
const u16 necro_dmca_084_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 necro_dmca_084[52] = {
    L4(3, 134, 0, 0, 0, 0, 0, 0x2155, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x2156, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x2155, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x2157, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 4), 0, 0, 0, 0,
    CMD(CM_JMP, 1, 10, 2), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 90 OKIAGARI FRONT */
const u16 necro_dmca_090_head[4] = { HEAD(4, 38, 0, 0, 0, 0, 0) };
const u16 necro_dmca_090[212] = {
    CMD(CM_MXYT, 16, 0, 0), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x2010, 0, 115, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x2011, 0, 115, 0, 0, 0, 0, 0),
    L4(1, 1, 0, 0, 0, 0, 0, 0x2012, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 1, 0, 0, 0, 0, 0, 0x2013, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 1, 0, 0, 0, 0, 0, 0x2014, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 1, 0, 0, 0, 0, 0, 0x2015, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 1, 0, 0, 0, 0, 0, 0x2016, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 1, 0, 0, 0, 0, 0, 0x2017, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 1, 0, 0, 0, 0, 0, 0x2018, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 1, 0, 0, 0, 0, 0, 0x2019, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 1, 0, 0, 0, 0, 0, 0x2012, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 1, 0, 0, 0, 0, 0, 0x2013, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 1, 0, 0, 0, 0, 0, 0x2014, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 1, 0, 0, 0, 0, 0, 0x2015, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 1, 0, 0, 0, 0, 0, 0x2016, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 1, 0, 0, 0, 0, 0, 0x2017, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 1, 0, 0, 0, 0, 0, 0x2018, 0, 0, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x2019, 0, 115, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1E25, 0, 115, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1E21, 0, 115, 0, 0, 0, 0, 0),
    CMD(CM_SPS, 0, 0, 0), 0, 0, 0, 0,
    L4(3, 0, 0, 0, 0, 0, 0, 0x1E26, 0, 115, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1E27, 0, 115, 0, 0, 0, 0, 0),
    L4(2, 64, 0, 0, 0, 0, 0, 0x1E28, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x1E28, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 91 OKIAGARI REAR */
const u16 necro_dmca_091_head[4] = { HEAD(4, 38, 0, 0, 0, 0, 0) };
const u16 necro_dmca_091[196] = {
    CMD(CM_MXYT, 15, 0, 0), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x2005, 0, 115, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x201A, 0, 115, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x2018, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x2017, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 1, 0, 0, 0, 0, 0, 0x2016, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 1, 0, 0, 0, 0, 0, 0x2014, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 1, 0, 0, 0, 0, 0, 0x2013, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 1, 0, 0, 0, 0, 0, 0x2012, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 1, 0, 0, 0, 0, 0, 0x2019, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 1, 0, 0, 0, 0, 0, 0x2018, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 1, 0, 0, 0, 0, 0, 0x2017, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 1, 0, 0, 0, 0, 0, 0x2016, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 1, 0, 0, 0, 0, 0, 0x2014, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x2013, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x2012, 0, 0, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x2019, 0, 115, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1E25, 0, 115, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1E21, 0, 115, 0, 0, 0, 0, 0),
    CMD(CM_SPS, 0, 0, 0), 0, 0, 0, 0,
    L4(3, 0, 0, 0, 0, 0, 0, 0x1E26, 0, 115, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1E27, 0, 115, 0, 0, 0, 0, 0),
    L4(2, 64, 0, 0, 0, 0, 0, 0x1E28, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x1E28, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 96 no name */
const u16 necro_dmca_096_head[4] = { HEAD(4, 38, 0, 0, 0, 0, 0) };
const u16 necro_dmca_096[44] = {
    L4(3, 2, 494, 0, 0, 0, 0, 0x202E, 0, 168, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x202E, 0, 168, 0, 0, 0, 0, 0),
    L4(3, 5, 0, 0, 0, 0, 0, 0x202E, 0, 168, 0, 0, 0, 0, 0),
    L4(40, 0, 0, 0, 0, 0, 0, 0x202E, 0, 168, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x202E, 0, 168, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 97 no name */
const u16 necro_dmca_097_head[4] = { HEAD(4, 38, 0, 0, 0, 0, 0) };
const u16 necro_dmca_097[44] = {
    L4(3, 2, 494, 0, 0, 0, 0, 0x202E, 0, 189, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x202E, 0, 189, 0, 0, 0, 0, 0),
    L4(3, 5, 0, 0, 0, 0, 0, 0x202E, 0, 189, 0, 0, 0, 0, 0),
    L4(40, 0, 0, 0, 0, 0, 0, 0x202E, 0, 189, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x202E, 0, 189, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

extern const u16 necro_btca_000[], necro_btca_001[], necro_btca_002[], necro_btca_003[], necro_btca_004[], necro_btca_005[], necro_btca_006[], necro_btca_007[], necro_btca_008[], necro_btca_009[], necro_btca_010[], necro_btca_011[], necro_btca_012[], necro_btca_016[], necro_btca_020[], necro_btca_024[], necro_btca_028[], necro_btca_032[], necro_btca_036[], necro_btca_037[], necro_btca_038[], necro_btca_039[], necro_btca_040[], necro_btca_041[], necro_btca_042[], necro_btca_043[], necro_btca_044[], necro_btca_048[], necro_btca_052[], necro_btca_053[], necro_btca_054[], necro_btca_055[], necro_btca_056[], necro_btca_057[], necro_btca_058[], necro_btca_059[], necro_btca_060[], necro_btca_064[], necro_btca_068[], necro_btca_072[], necro_btca_076[], necro_btca_080[], necro_btca_088[], necro_btca_092[], necro_btca_100[], necro_btca_104[], necro_btca_108[], necro_btca_112[], necro_btca_116[], necro_btca_120[], necro_btca_124[], necro_btca_128[], necro_btca_132[], necro_btca_136[];

/* btca scripts (debug viewer: BUTTOBI): 140 entries */
const u32 necro_btca[141] = {
    (u32)necro_btca_000,  /* 0 AIR S */
    (u32)necro_btca_001,  /* 1 AIR M */
    (u32)necro_btca_002,  /* 2 AIR L */
    (u32)necro_btca_003,  /* 3 AIR SP */
    (u32)necro_btca_004,  /* 4 ASHIBARAI A */
    (u32)necro_btca_005,  /* 5 ASHIBARAI B */
    (u32)necro_btca_006,  /* 6 ASHIBARAI C */
    (u32)necro_btca_007,  /* 7 ASHIBARAI D */
    (u32)necro_btca_008,  /* 8 TUNNOMERI A */
    (u32)necro_btca_009,  /* 9 TUNNOMERI B */
    (u32)necro_btca_010,  /* 10 TUNNOMERI C */
    (u32)necro_btca_011,  /* 11 TUNNOMERI D */
    (u32)necro_btca_012,  /* 12 NOKEZORI A */
    (u32)necro_btca_012,  /* 13 NOKEZORI B */
    (u32)necro_btca_012,  /* 14 NOKEZORI C */
    (u32)necro_btca_012,  /* 15 NOKEZORI D */
    (u32)necro_btca_016,  /* 16 KUNOJI A */
    (u32)necro_btca_016,  /* 17 KUNOJI B */
    (u32)necro_btca_016,  /* 18 KUNOJI C */
    (u32)necro_btca_016,  /* 19 KUNOJI D */
    (u32)necro_btca_020,  /* 20 KIRIMOMI A */
    (u32)necro_btca_020,  /* 21 KIRIMOMI B */
    (u32)necro_btca_020,  /* 22 KIRIMOMI C */
    (u32)necro_btca_020,  /* 23 KIRIMOMI D */
    (u32)necro_btca_024,  /* 24 UPPER A */
    (u32)necro_btca_024,  /* 25 UPPER B */
    (u32)necro_btca_024,  /* 26 UPPER C */
    (u32)necro_btca_024,  /* 27 UPPER D */
    (u32)necro_btca_028,  /* 28 BODY UPPER A */
    (u32)necro_btca_028,  /* 29 BODY UPPER B */
    (u32)necro_btca_028,  /* 30 BODY UPPER C */
    (u32)necro_btca_028,  /* 31 BODY UPPER D */
    (u32)necro_btca_032,  /* 32 NM BUTTOBI A */
    (u32)necro_btca_032,  /* 33 NM BUTTOBI B */
    (u32)necro_btca_032,  /* 34 NM BUTTOBI C */
    (u32)necro_btca_032,  /* 35 NM BUTTOBI D */
    (u32)necro_btca_036,  /* 36 TATAKI AIR A */
    (u32)necro_btca_037,  /* 37 TATAKI AIR B */
    (u32)necro_btca_038,  /* 38 TATAKI AIR C */
    (u32)necro_btca_039,  /* 39 TATAKI AIR D */
    (u32)necro_btca_040,  /* 40 TTKI V. AIR A */
    (u32)necro_btca_041,  /* 41 TTKI V. AIR B */
    (u32)necro_btca_042,  /* 42 TTKI V. AIR C */
    (u32)necro_btca_043,  /* 43 TTKI V. AIR D */
    (u32)necro_btca_044,  /* 44 HUMI ASIB A */
    (u32)necro_btca_044,  /* 45 HUMI ASIB B */
    (u32)necro_btca_044,  /* 46 HUMI ASIB C */
    (u32)necro_btca_044,  /* 47 HUMI ASIB D */
    (u32)necro_btca_048,  /* 48 FACE A */
    (u32)necro_btca_048,  /* 49 FACE B */
    (u32)necro_btca_048,  /* 50 FACE C */
    (u32)necro_btca_048,  /* 51 FACE D */
    (u32)necro_btca_052,  /* 52 ASIBRI MAKE A */
    (u32)necro_btca_053,  /* 53 ASIBRI MAKE B */
    (u32)necro_btca_054,  /* 54 ASIBRI MAKE C */
    (u32)necro_btca_055,  /* 55 ASIBRI MAKE D */
    (u32)necro_btca_056,  /* 56 ASIB TN MAKE A */
    (u32)necro_btca_057,  /* 57 ASIB TN MAKE B */
    (u32)necro_btca_058,  /* 58 ASIB TN MAKE C */
    (u32)necro_btca_059,  /* 59 ASIB TN MAKE D */
    (u32)necro_btca_060,  /* 60 DENKI A */
    (u32)necro_btca_060,  /* 61 DENKI B */
    (u32)necro_btca_060,  /* 62 DENKI C */
    (u32)necro_btca_060,  /* 63 DENKI D */
    (u32)necro_btca_064,  /* 64 KUNOJI NOKE A */
    (u32)necro_btca_064,  /* 65 KUNOJI NOKE B */
    (u32)necro_btca_064,  /* 66 KUNOJI NOKE C */
    (u32)necro_btca_064,  /* 67 KUNOJI NOKE D */
    (u32)necro_btca_068,  /* 68 SINSYOURYU A */
    (u32)necro_btca_068,  /* 69 SINSYOURYU B */
    (u32)necro_btca_068,  /* 70 SINSYOURYU C */
    (u32)necro_btca_068,  /* 71 SINSYOURYU D */
    (u32)necro_btca_072,  /* 72 HANEAGARI A */
    (u32)necro_btca_072,  /* 73 HANEAGARI B */
    (u32)necro_btca_072,  /* 74 HANEAGARI C */
    (u32)necro_btca_072,  /* 75 HANEAGARI D */
    (u32)necro_btca_076,  /* 76 TOUKETSU A */
    (u32)necro_btca_076,  /* 77 TOUKETSU B */
    (u32)necro_btca_076,  /* 78 TOUKETSU C */
    (u32)necro_btca_076,  /* 79 TOUKETSU D */
    (u32)necro_btca_080,  /* 80 BODY SLAM A */
    (u32)necro_btca_080,  /* 81 BODY SLAM B */
    (u32)necro_btca_080,  /* 82 BODY SLAM C */
    (u32)necro_btca_080,  /* 83 BODY SLAM D */
    (u32)necro_btca_080,  /* 84 IPPONZEOI A */
    (u32)necro_btca_080,  /* 85 IPPONZEOI B */
    (u32)necro_btca_080,  /* 86 IPPONZEOI C */
    (u32)necro_btca_080,  /* 87 IPPONZEOI D */
    (u32)necro_btca_088,  /* 88 TOMOE RYU A */
    (u32)necro_btca_088,  /* 89 TOMOE RYU B */
    (u32)necro_btca_088,  /* 90 TOMOE RYU C */
    (u32)necro_btca_088,  /* 91 TOMOE RYU D */
    (u32)necro_btca_092,  /* 92 MONKEY FLIP A */
    (u32)necro_btca_092,  /* 93 MONKEY FLIP B */
    (u32)necro_btca_092,  /* 94 MONKEY FLIP C */
    (u32)necro_btca_092,  /* 95 MONKEY FLIP D */
    (u32)necro_btca_092,  /* 96 TOMOE ORO A */
    (u32)necro_btca_092,  /* 97 TOMOE ORO B */
    (u32)necro_btca_092,  /* 98 TOMOE ORO C */
    (u32)necro_btca_092,  /* 99 TOMOE ORO D */
    (u32)necro_btca_100,  /* 100 SNAKE FANG A */
    (u32)necro_btca_100,  /* 101 SNAKE FANG B */
    (u32)necro_btca_100,  /* 102 SNAKE FANG C */
    (u32)necro_btca_100,  /* 103 SNAKE FANG D */
    (u32)necro_btca_104,  /* 104 FLANKEN.S A */
    (u32)necro_btca_104,  /* 105 FLANKEN.S B */
    (u32)necro_btca_104,  /* 106 FLANKEN.S C */
    (u32)necro_btca_104,  /* 107 FLANKEN.S D */
    (u32)necro_btca_108,  /* 108 KISHINRIKI A */
    (u32)necro_btca_108,  /* 109 KISHINRIKI B */
    (u32)necro_btca_108,  /* 110 KISHINRIKI C */
    (u32)necro_btca_108,  /* 111 KISHINRIKI D */
    (u32)necro_btca_112,  /* 112 SPLASH.M A */
    (u32)necro_btca_112,  /* 113 SPLASH.M B */
    (u32)necro_btca_112,  /* 114 SPLASH.M C */
    (u32)necro_btca_112,  /* 115 SPLASH.M D */
    (u32)necro_btca_116,  /* 116 HARAIGOSHI A */
    (u32)necro_btca_116,  /* 117 HARAIGOSHI B */
    (u32)necro_btca_116,  /* 118 HARAIGOSHI C */
    (u32)necro_btca_116,  /* 119 HARAIGOSHI D */
    (u32)necro_btca_120,  /* 120 ALEX B.D A */
    (u32)necro_btca_120,  /* 121 ALEX B.D B */
    (u32)necro_btca_120,  /* 122 ALEX B.D C */
    (u32)necro_btca_120,  /* 123 ALEX B.D D */
    (u32)necro_btca_124,  /* 124 GILL A */
    (u32)necro_btca_124,  /* 125 GILL B */
    (u32)necro_btca_124,  /* 126 GILL C */
    (u32)necro_btca_124,  /* 127 GILL D */
    (u32)necro_btca_128,  /* 128 no name */
    (u32)necro_btca_128,  /* 129 no name */
    (u32)necro_btca_128,  /* 130 no name */
    (u32)necro_btca_128,  /* 131 no name */
    (u32)necro_btca_132,  /* 132 follow-up of HUGO M S P */
    (u32)necro_btca_132,  /* 133 no name */
    (u32)necro_btca_132,  /* 134 no name */
    (u32)necro_btca_132,  /* 135 no name */
    (u32)necro_btca_136,  /* 136 no name */
    (u32)necro_btca_136,  /* 137 no name */
    (u32)necro_btca_136,  /* 138 no name */
    (u32)necro_btca_136,  /* 139 no name */
    0
};

/* script: 0 AIR S */
const u16 necro_btca_000_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 necro_btca_000[52] = {
    CMD(CM_JSR, 8, 22, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x2080, 0, 147, 0, 0, 0, 0, 0),
    L4(4, 0, 495, 0, 0, 0, 0, 0x2080, 0, 147, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x207B, 0, 158, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x207C, 0, 158, 0, 0, 0, 0, 0),
    CMD(CM_JMP, 7, 0, 1), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 1 AIR M */
const u16 necro_btca_001_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 necro_btca_001[52] = {
    CMD(CM_JSR, 8, 22, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x2080, 0, 147, 0, 0, 0, 0, 0),
    L4(6, 0, 495, 0, 0, 0, 0, 0x2080, 0, 147, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x207B, 0, 158, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x207C, 0, 158, 0, 0, 0, 0, 0),
    CMD(CM_JMP, 7, 0, 1), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 2 AIR L */
const u16 necro_btca_002_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 necro_btca_002[52] = {
    CMD(CM_JSR, 8, 22, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x2080, 0, 147, 0, 0, 0, 0, 0),
    L4(8, 0, 495, 0, 0, 0, 0, 0x2080, 0, 147, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x207B, 0, 158, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x207C, 0, 158, 0, 0, 0, 0, 0),
    CMD(CM_JMP, 7, 0, 1), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 3 AIR SP */
const u16 necro_btca_003_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 necro_btca_003[52] = {
    CMD(CM_JSR, 8, 22, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x2080, 0, 147, 0, 0, 0, 0, 0),
    L4(8, 0, 495, 0, 0, 0, 0, 0x2080, 0, 147, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x207B, 0, 158, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x207C, 0, 158, 0, 0, 0, 0, 0),
    CMD(CM_JMP, 7, 0, 1), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 4 ASHIBARAI A */
const u16 necro_btca_004_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 necro_btca_004[52] = {
    CMD(CM_RJA, 7, 3, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x206D, 0, 147, 0, 0, 0, 0, 0),
    L4(3, 0, 495, 0, 0, 0, 0, 0x206E, 0, 147, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x206F, 0, 147, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x2070, 0, 147, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 5 ASHIBARAI B */
const u16 necro_btca_005_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 necro_btca_005[52] = {
    CMD(CM_RJA, 7, 3, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x206D, 0, 147, 0, 0, 0, 0, 0),
    L4(3, 0, 495, 0, 0, 0, 0, 0x206E, 0, 147, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x206F, 0, 147, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x2070, 0, 147, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 6 ASHIBARAI C */
const u16 necro_btca_006_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 necro_btca_006[52] = {
    CMD(CM_RJA, 7, 3, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x206D, 0, 147, 0, 0, 0, 0, 0),
    L4(3, 0, 495, 0, 0, 0, 0, 0x206E, 0, 147, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x206F, 0, 147, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x2070, 0, 147, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 7 ASHIBARAI D */
const u16 necro_btca_007_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 necro_btca_007[52] = {
    CMD(CM_RJA, 7, 3, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x206D, 0, 147, 0, 0, 0, 0, 0),
    L4(3, 0, 495, 0, 0, 0, 0, 0x206E, 0, 147, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x206F, 0, 147, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x2070, 0, 147, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 8 TUNNOMERI A */
const u16 necro_btca_008_head[4] = { HEAD(4, 20, 0, 0, 0, 0, 0) };
const u16 necro_btca_008[52] = {
    CMD(CM_RJA, 7, 3, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x206D, 0, 147, 0, 0, 0, 0, 0),
    L4(3, 0, 495, 0, 0, 0, 0, 0x206E, 0, 147, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x206F, 0, 147, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x2070, 0, 147, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 9 TUNNOMERI B */
const u16 necro_btca_009_head[4] = { HEAD(4, 20, 0, 0, 0, 0, 0) };
const u16 necro_btca_009[52] = {
    CMD(CM_RJA, 7, 3, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x206D, 0, 147, 0, 0, 0, 0, 0),
    L4(3, 0, 495, 0, 0, 0, 0, 0x206E, 0, 147, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x206F, 0, 147, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x2070, 0, 147, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 10 TUNNOMERI C */
const u16 necro_btca_010_head[4] = { HEAD(4, 20, 0, 0, 0, 0, 0) };
const u16 necro_btca_010[52] = {
    CMD(CM_RJA, 7, 3, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x206D, 0, 147, 0, 0, 0, 0, 0),
    L4(3, 0, 495, 0, 0, 0, 0, 0x206E, 0, 147, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x206F, 0, 147, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x2070, 0, 147, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 11 TUNNOMERI D */
const u16 necro_btca_011_head[4] = { HEAD(4, 20, 0, 0, 0, 0, 0) };
const u16 necro_btca_011[52] = {
    CMD(CM_RJA, 7, 3, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x206D, 0, 147, 0, 0, 0, 0, 0),
    L4(3, 0, 495, 0, 0, 0, 0, 0x206E, 0, 147, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x206F, 0, 147, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x2070, 0, 147, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 12 NOKEZORI A, 13 NOKEZORI B, 14 NOKEZORI C, 15 NOKEZORI D */
const u16 necro_btca_012_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 necro_btca_012[84] = {
    CMD(CM_RJA, 7, 6, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x2030, 0, 147, 0, 0, 0, 0, 0),
    L4(3, 0, 495, 0, 0, 0, 0, 0x2031, 0, 147, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x2032, 0, 147, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x2034, 0, 147, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x2035, 0, 147, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x2036, 0, 147, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x2037, 0, 147, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x2038, 0, 147, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 16 KUNOJI A, 17 KUNOJI B, 18 KUNOJI C, 19 KUNOJI D */
const u16 necro_btca_016_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 necro_btca_016[44] = {
    CMD(CM_RJA, 7, 7, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x1FE2, 0, 147, 0, 0, 0, 0, 0),
    L4(3, 0, 495, 0, 0, 0, 0, 0x1FE3, 0, 147, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x1FE4, 0, 147, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 20 KIRIMOMI A, 21 KIRIMOMI B, 22 KIRIMOMI C, 23 KIRIMOMI D */
const u16 necro_btca_020_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 necro_btca_020[148] = {
    CMD(CM_RJA, 7, 9, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x2040, 0, 147, 0, 0, 0, 0, 0),
    L4(3, 0, 495, 0, 0, 0, 0, 0x2041, 0, 147, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x2042, 0, 147, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x2043, 0, 147, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x2044, 0, 147, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x2045, 0, 147, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x2046, 0, 147, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x2047, 0, 147, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x2048, 0, 147, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x2049, 0, 147, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x204A, 0, 147, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x204B, 0, 147, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x204C, 0, 147, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x204D, 0, 147, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x204E, 0, 147, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x204F, 0, 147, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 24 UPPER A, 25 UPPER B, 26 UPPER C, 27 UPPER D */
const u16 necro_btca_024_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 necro_btca_024[92] = {
    CMD(CM_RJA, 7, 6, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x2080, 0, 147, 0, 0, 0, 0, 0),
    L4(4, 0, 495, 0, 0, 0, 0, 0x2081, 0, 147, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x2082, 0, 147, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x2032, 0, 147, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x2034, 0, 147, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x2035, 0, 147, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x2036, 0, 147, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x2037, 0, 147, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x2038, 0, 147, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 28 BODY UPPER A, 29 BODY UPPER B, 30 BODY UPPER C, 31 BODY UPPER D */
const u16 necro_btca_028_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 necro_btca_028[116] = {
    CMD(CM_RJA, 7, 6, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x2079, 0, 147, 0, 0, 0, 0, 0),
    L4(3, 0, 495, 0, 0, 0, 0, 0x207A, 0, 147, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x207B, 0, 147, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x207C, 0, 147, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x2031, 0, 147, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x2032, 0, 147, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x2033, 0, 147, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x2034, 0, 147, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x2035, 0, 147, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x2036, 0, 147, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x2037, 0, 147, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x2038, 0, 147, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 32 NM BUTTOBI A, 33 NM BUTTOBI B, 34 NM BUTTOBI C, 35 NM BUTTOBI D */
const u16 necro_btca_032_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 necro_btca_032[92] = {
    CMD(CM_RJA, 7, 6, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x2080, 0, 147, 0, 0, 0, 0, 0),
    L4(3, 0, 495, 0, 0, 0, 0, 0x2030, 0, 147, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x2031, 0, 147, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x2032, 0, 147, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x2034, 0, 147, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x2035, 0, 147, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x2036, 0, 147, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x2037, 0, 147, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x2038, 0, 147, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 36 TATAKI AIR A */
const u16 necro_btca_036_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 necro_btca_036[84] = {
    CMD(CM_RJA, 7, 6, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x2030, 0, 147, 0, 0, 0, 0, 0),
    L4(3, 0, 495, 0, 0, 0, 0, 0x2031, 0, 147, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x2032, 0, 147, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x2034, 0, 147, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x2035, 0, 147, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x2036, 0, 147, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x2037, 0, 147, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x2038, 0, 147, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 37 TATAKI AIR B */
const u16 necro_btca_037_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 necro_btca_037[84] = {
    CMD(CM_RJA, 7, 6, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x2030, 0, 147, 0, 0, 0, 0, 0),
    L4(3, 0, 495, 0, 0, 0, 0, 0x2031, 0, 147, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x2032, 0, 147, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x2034, 0, 147, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x2035, 0, 147, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x2036, 0, 147, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x2037, 0, 147, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x2038, 0, 147, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 38 TATAKI AIR C */
const u16 necro_btca_038_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 necro_btca_038[84] = {
    CMD(CM_RJA, 7, 6, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x2030, 0, 147, 0, 0, 0, 0, 0),
    L4(3, 0, 495, 0, 0, 0, 0, 0x2031, 0, 147, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x2032, 0, 147, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x2034, 0, 147, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x2035, 0, 147, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x2036, 0, 147, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x2037, 0, 147, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x2038, 0, 147, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 39 TATAKI AIR D */
const u16 necro_btca_039_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 necro_btca_039[84] = {
    CMD(CM_RJA, 7, 6, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x2030, 0, 147, 0, 0, 0, 0, 0),
    L4(3, 0, 495, 0, 0, 0, 0, 0x2031, 0, 147, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x2032, 0, 147, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x2034, 0, 147, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x2035, 0, 147, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x2036, 0, 147, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x2037, 0, 147, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x2038, 0, 147, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 40 TTKI V. AIR A */
const u16 necro_btca_040_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 necro_btca_040[36] = {
    CMD(CM_RJA, 7, 8, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x2083, 0, 147, 0, 0, 0, 0, 0),
    L4(250, 0, 495, 0, 0, 0, 0, 0x2084, 0, 147, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 41 TTKI V. AIR B */
const u16 necro_btca_041_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 necro_btca_041[36] = {
    CMD(CM_RJA, 7, 8, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x2083, 0, 147, 0, 0, 0, 0, 0),
    L4(250, 0, 495, 0, 0, 0, 0, 0x2084, 0, 147, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 42 TTKI V. AIR C */
const u16 necro_btca_042_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 necro_btca_042[36] = {
    CMD(CM_RJA, 7, 8, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x2083, 0, 147, 0, 0, 0, 0, 0),
    L4(250, 0, 495, 0, 0, 0, 0, 0x2084, 0, 147, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 43 TTKI V. AIR D */
const u16 necro_btca_043_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 necro_btca_043[36] = {
    CMD(CM_RJA, 7, 8, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x2083, 0, 147, 0, 0, 0, 0, 0),
    L4(250, 0, 495, 0, 0, 0, 0, 0x2084, 0, 147, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 44 HUMI ASIB A, 45 HUMI ASIB B, 46 HUMI ASIB C, 47 HUMI ASIB D */
const u16 necro_btca_044_head[4] = { HEAD(4, 20, 0, 0, 0, 0, 0) };
const u16 necro_btca_044[36] = {
    CMD(CM_RJA, 7, 28, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x2072, 0, 147, 0, 0, 0, 0, 0),
    L4(250, 0, 495, 0, 0, 0, 0, 0x2073, 0, 147, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 48 FACE A, 49 FACE B, 50 FACE C, 51 FACE D */
const u16 necro_btca_048_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 necro_btca_048[92] = {
    CMD(CM_RJA, 7, 6, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x1FC4, 0, 147, 0, 0, 0, 0, 0),
    L4(3, 0, 495, 0, 0, 0, 0, 0x2030, 0, 147, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x2031, 0, 147, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x2032, 0, 147, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x2034, 0, 147, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x2035, 0, 147, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x2036, 0, 147, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x2037, 0, 147, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x2038, 0, 147, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 52 ASIBRI MAKE A */
const u16 necro_btca_052_head[4] = { HEAD(2, 24, 0, 0, 0, 0, 0) };
const u16 necro_btca_052[12] = {
    CMD(CM_RJA, 7, 6, 1),
    CMD(CM_JMP, 6, 4, 2),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 53 ASIBRI MAKE B */
const u16 necro_btca_053_head[4] = { HEAD(2, 24, 0, 0, 0, 0, 0) };
const u16 necro_btca_053[12] = {
    CMD(CM_RJA, 7, 6, 1),
    CMD(CM_JMP, 6, 5, 2),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 54 ASIBRI MAKE C */
const u16 necro_btca_054_head[4] = { HEAD(2, 24, 0, 0, 0, 0, 0) };
const u16 necro_btca_054[12] = {
    CMD(CM_RJA, 7, 6, 1),
    CMD(CM_JMP, 6, 6, 2),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 55 ASIBRI MAKE D */
const u16 necro_btca_055_head[4] = { HEAD(2, 24, 0, 0, 0, 0, 0) };
const u16 necro_btca_055[12] = {
    CMD(CM_RJA, 7, 6, 1),
    CMD(CM_JMP, 6, 7, 2),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 56 ASIB TN MAKE A */
const u16 necro_btca_056_head[4] = { HEAD(2, 20, 0, 0, 0, 0, 0) };
const u16 necro_btca_056[12] = {
    CMD(CM_RJA, 7, 6, 1),
    CMD(CM_JMP, 6, 4, 2),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 57 ASIB TN MAKE B */
const u16 necro_btca_057_head[4] = { HEAD(2, 20, 0, 0, 0, 0, 0) };
const u16 necro_btca_057[12] = {
    CMD(CM_RJA, 7, 6, 1),
    CMD(CM_JMP, 6, 5, 2),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 58 ASIB TN MAKE C */
const u16 necro_btca_058_head[4] = { HEAD(2, 20, 0, 0, 0, 0, 0) };
const u16 necro_btca_058[12] = {
    CMD(CM_RJA, 7, 6, 1),
    CMD(CM_JMP, 6, 6, 2),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 59 ASIB TN MAKE D */
const u16 necro_btca_059_head[4] = { HEAD(2, 20, 0, 0, 0, 0, 0) };
const u16 necro_btca_059[12] = {
    CMD(CM_RJA, 7, 6, 1),
    CMD(CM_JMP, 6, 7, 2),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 60 DENKI A, 61 DENKI B, 62 DENKI C, 63 DENKI D */
const u16 necro_btca_060_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 necro_btca_060[76] = {
    CMD(CM_RJA, 7, 6, 1), 0, 0, 0, 0,
    L4(1, 136, 0, 0, 0, 0, 0, 0x2155, 0, 147, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x2155, 0, 147, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x2156, 0, 147, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x2155, 0, 147, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x2157, 0, 147, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 4), 0, 0, 0, 0,
    CMD(CM_SSE, 495, 0, 0), 0, 0, 0, 0,
    CMD(CM_JMP, 6, 32, 3), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 64 KUNOJI NOKE A, 65 KUNOJI NOKE B, 66 KUNOJI NOKE C, 67 KUNOJI NOKE D */
const u16 necro_btca_064_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 necro_btca_064[92] = {
    CMD(CM_RJA, 7, 6, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x1FE2, 0, 147, 0, 0, 0, 0, 0),
    L4(3, 0, 495, 0, 0, 0, 0, 0x1FE3, 0, 147, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1FE4, 0, 147, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x2032, 0, 147, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x2034, 0, 147, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x2035, 0, 147, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x2036, 0, 147, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x2037, 0, 147, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x2038, 0, 147, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 68 SINSYOURYU A, 69 SINSYOURYU B, 70 SINSYOURYU C, 71 SINSYOURYU D */
const u16 necro_btca_068_head[4] = { HEAD(6, 24, 0, 0, 0, 0, 0) };
const u16 necro_btca_068[172] = {
    CMD(CM_RJA, 7, 6, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(250, 131, 0, 0, 0, 0, 0, 0x2079, 0, 147, 0, 0, 0, 0, 0, 12288, 0, 0, 0, 0),
    L6(3, 0, 495, 0, 0, 0, 0, 0x207A, 0, 147, 0, 0, 0, 0, 0, 12288, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x207B, 0, 147, 0, 0, 0, 0, 0, 12288, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x207C, 0, 147, 0, 0, 0, 0, 0, 12288, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x2031, 0, 147, 0, 0, 0, 0, 0, 12288, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x2032, 0, 147, 0, 0, 0, 0, 0, 12288, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x2033, 0, 147, 0, 0, 0, 0, 0, 12288, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x2034, 0, 147, 0, 0, 0, 0, 0, 12288, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x2035, 0, 147, 0, 0, 0, 0, 0, 12288, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x2036, 0, 147, 0, 0, 0, 0, 0, 12288, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x2037, 0, 147, 0, 0, 0, 0, 0, 12288, 0, 0, 0, 0),
    L6(250, 0, 0, 0, 0, 0, 0, 0x2038, 0, 147, 0, 0, 0, 0, 0, 12288, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 72 HANEAGARI A, 73 HANEAGARI B, 74 HANEAGARI C, 75 HANEAGARI D */
const u16 necro_btca_072_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 necro_btca_072[124] = {
    CMD(CM_RJA, 6, 72, 7), 0, 0, 0, 0,
    L4(3, 0, 495, 0, 0, 0, 0, 0x203B, 0, 115, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 8, 0x2038, 0, 115, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 10, 0x2037, 0, 115, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 12, 0x2036, 0, 115, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 15, 0x2035, 0, 115, 0, 0, 0, 0, 0),
    CMD(CM_SPS, 0, 0, 38), 0, 0, 0, 0,
    L4(2, 2, 285, 0, 0, 0, 0, 0x203E, 0, 115, 0, 0, 0, 0, 0),
    L4(2, 2, 0, 0, 0, 0, 0, 0x203F, 0, 115, 0, 0, 0, 0, 0),
    L4(6, 1, 0, 0, 0, 0, 0, 0x202A, 0, 115, 0, 0, 0, 0, 0),
    L4(4, 5, 0, 0, 0, 0, 0, 0x202B, 0, 115, 0, 0, 0, 0, 0),
    L4(3, 5, 0, 0, 0, 0, 0, 0x202C, 0, 115, 0, 0, 0, 0, 0),
    L4(3, 5, 0, 0, 0, 0, 0, 0x202D, 0, 115, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x202E, 0, 115, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x202E, 0, 115, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 76 TOUKETSU A, 77 TOUKETSU B, 78 TOUKETSU C, 79 TOUKETSU D */
const u16 necro_btca_076_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 necro_btca_076[28] = {
    CMD(CM_RJA, 7, 6, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x1FCC, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 0, 495, 0, 0, 0, 0, 0x1FCC, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 80 BODY SLAM A, 81 BODY SLAM B, 82 BODY SLAM C, 83 BODY SLAM D ... */
const u16 necro_btca_080_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 necro_btca_080[20] = {
    L4(3, 0, 0, 0, 0, 0, 0, 0x202A, 0, 147, 0, 0, 0, 0, 0),
    CMD(CM_END, 0, 0, 1), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 88 TOMOE RYU A, 89 TOMOE RYU B, 90 TOMOE RYU C, 91 TOMOE RYU D */
const u16 necro_btca_088_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 necro_btca_088[52] = {
    CMD(CM_RJA, 7, 5, 1), 0, 0, 0, 0,
    L4(12, 0, 0, 0, 3, 0, 0, 0x207C, 0, 147, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x203A, 0, 147, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x203B, 0, 147, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x203B, 0, 147, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 92 MONKEY FLIP A, 93 MONKEY FLIP B, 94 MONKEY FLIP C, 95 MONKEY FLIP D ... */
const u16 necro_btca_092_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 necro_btca_092[60] = {
    CMD(CM_RJA, 7, 5, 1), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 3, 0, 0, 0x2031, 0, 147, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 3, 0, 0, 0x207C, 0, 147, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 3, 0, 0, 0x207B, 0, 147, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 3, 0, 0, 0x20D0, 0, 147, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 3, 0, 0, 0x20D0, 0, 147, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 100 SNAKE FANG A, 101 SNAKE FANG B, 102 SNAKE FANG C, 103 SNAKE FANG D */
const u16 necro_btca_100_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 necro_btca_100[36] = {
    CMD(CM_RJA, 7, 5, 1), 0, 0, 0, 0,
    L4(8, 0, 0, 0, 0, 0, 0, 0x2036, 0, 147, 0, 0, 0, 0, 0),
    L4(8, 0, 0, 0, 0, 0, 0, 0x2037, 0, 147, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x2038, 0, 147, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 104 FLANKEN.S A, 105 FLANKEN.S B, 106 FLANKEN.S C, 107 FLANKEN.S D */
const u16 necro_btca_104_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 necro_btca_104[68] = {
    CMD(CM_RJA, 7, 9, 1), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 3, 0, 0, 0x2031, 0, 147, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 2, 0, 0, 0x2044, 0, 147, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 2, 0, 0, 0x204B, 0, 147, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 2, 0, 0, 0x204C, 0, 147, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 2, 0, 0, 0x204D, 0, 147, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 2, 0, 0, 0x204E, 0, 147, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 2, 0, 0, 0x204E, 0, 147, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 108 KISHINRIKI A, 109 KISHINRIKI B, 110 KISHINRIKI C, 111 KISHINRIKI D */
const u16 necro_btca_108_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 necro_btca_108[60] = {
    CMD(CM_RJA, 7, 6, 1), 0, 0, 0, 0,
    L4(8, 0, 0, 0, 0, 0, 15, 0x2034, 0, 147, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 15, 0x2035, 0, 147, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 15, 0x2036, 0, 147, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 15, 0x2037, 0, 147, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x2038, 0, 147, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 112 SPLASH.M A, 113 SPLASH.M B, 114 SPLASH.M C, 115 SPLASH.M D */
const u16 necro_btca_112_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 necro_btca_112[52] = {
    CMD(CM_RJA, 7, 9, 1), 0, 0, 0, 0,
    L4(4, 0, 0, 0, 0, 0, 0, 0x2036, 0, 115, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x2037, 0, 115, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x2038, 0, 115, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x2038, 0, 115, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 116 HARAIGOSHI A, 117 HARAIGOSHI B, 118 HARAIGOSHI C, 119 HARAIGOSHI D */
const u16 necro_btca_116_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 necro_btca_116[36] = {
    CMD(CM_RJA, 7, 21, 1), 0, 0, 0, 0,
    L4(4, 0, 0, 0, 0, 0, 0, 0x2038, 0, 147, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x2038, 0, 147, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 120 ALEX B.D A, 121 ALEX B.D B, 122 ALEX B.D C, 123 ALEX B.D D */
const u16 necro_btca_120_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 necro_btca_120[116] = {
    CMD(CM_RJA, 7, 6, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x2079, 0, 147, 0, 0, 0, 0, 0),
    L4(3, 0, 495, 0, 0, 0, 0, 0x207A, 0, 147, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x207B, 0, 147, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x207C, 0, 147, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x2031, 0, 147, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 15, 0x2032, 0, 147, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 15, 0x2033, 0, 147, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 15, 0x2034, 0, 147, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 15, 0x2035, 0, 147, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 12, 0x2036, 0, 147, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 10, 0x2037, 0, 147, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 8, 0x2038, 0, 147, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 124 GILL A, 125 GILL B, 126 GILL C, 127 GILL D */
const u16 necro_btca_124_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 necro_btca_124[44] = {
    L4(2, 0, 0, 0, 0, 0, 0, 0x206D, 0, 147, 0, 0, 0, 0, 0),
    L4(3, 0, 495, 0, 0, 0, 0, 0x206E, 0, 147, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x206F, 0, 147, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x2070, 0, 147, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 128 no name, 129 no name, 130 no name, 131 no name */
const u16 necro_btca_128_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 necro_btca_128[36] = {
    CMD(CM_RJA, 7, 6, 1), 0, 0, 0, 0,
    L4(250, 131, 285, 0, 0, 0, 0, 0x2080, 0, 147, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x2030, 0, 147, 0, 0, 0, 24, 0),
    CMD(CM_JMP, 6, 32, 4), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 132 follow-up of HUGO M S P, 133 no name, 134 no name, 135 no name */
const u16 necro_btca_132_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 necro_btca_132[92] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x202B, 0, 115, 0, 0, 0, 0, 0),
    CMD(CM_RJA, 6, 132, 5), 0, 0, 0, 0,
    L4(6, 0, 495, 0, 0, 0, 0, 0x202B, 0, 115, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x202A, 0, 115, 0, 0, 0, 0, 0),
    CMD(CM_SPS, 0, 0, 38), 0, 0, 0, 0,
    L4(2, 2, 285, 0, 0, 0, 0, 0x202A, 0, 115, 0, 0, 0, 0, 0),
    L4(2, 2, 0, 0, 0, 0, 0, 0x202B, 0, 115, 0, 0, 0, 0, 0),
    L4(6, 1, 0, 0, 0, 0, 0, 0x202C, 0, 115, 0, 0, 0, 0, 0),
    L4(4, 5, 0, 0, 0, 0, 0, 0x202D, 0, 115, 0, 0, 0, 0, 0),
    L4(5, 5, 0, 0, 0, 0, 0, 0x202E, 0, 115, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x202E, 0, 115, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 136 no name, 137 no name, 138 no name, 139 no name */
const u16 necro_btca_136_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 necro_btca_136[92] = {
    CMD(CM_RJA, 7, 6, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x2080, 0, 147, 0, 0, 0, 0, 0),
    L4(4, 0, 495, 0, 0, 0, 0, 0x2081, 0, 147, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x2082, 0, 147, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x2032, 0, 147, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x2034, 0, 147, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x2035, 0, 147, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x2036, 0, 147, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x2037, 0, 147, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x2038, 0, 147, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

extern const u16 necro_caca_000[], necro_caca_001[], necro_caca_002[], necro_caca_003[], necro_caca_004[], necro_caca_005[], necro_caca_006[], necro_caca_007[], necro_caca_008[], necro_caca_009[], necro_caca_010[], necro_caca_011[];

/* caca scripts (debug viewer: CATCH): 12 entries */
const u32 necro_caca[13] = {
    (u32)necro_caca_000,  /* 0 CATCH 1 */
    (u32)necro_caca_001,  /* 1 CATCH 2 */
    (u32)necro_caca_002,  /* 2 CATCH 3 */
    (u32)necro_caca_003,  /* 3 CATCH 4 */
    (u32)necro_caca_004,  /* 4 CATCH 5 */
    (u32)necro_caca_005,  /* 5 CATCH 6 */
    (u32)necro_caca_006,  /* 6 CATCH 7 */
    (u32)necro_caca_007,  /* 7 CATCH 8 */
    (u32)necro_caca_008,  /* 8 CATCH 9 */
    (u32)necro_caca_009,  /* 9 CATCH 10 */
    (u32)necro_caca_010,  /* 10 CATCH 11 */
    (u32)necro_caca_011,  /* 11 CATCH 12 */
    0
};

/* script: 0 CATCH 1 */
const u16 necro_caca_000_head[4] = { HEAD(6, 0, 16, 0, 0, 0, 0) };
const u16 necro_caca_000[292] = {
    CMD(CM_NGDA, 1542, 9, 2), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_PS_Y, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(4, 0, 0, 0, 0, 0, 0, 0x2098, 0, 0, 0, 0, 0, 0, 0, 0, 16, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x20A0, 0, 0, 0, 0, 0, 0, 0, 0, 32, 0, 0, 0),
    L6(3, 0, 497, 0, 0, 0, 0, 0x20A1, 0, 0, 0, 0, 0, 0, 0, 0, 48, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x20A2, 0, 0, 0, 0, 0, 0, 0, 0, 64, 0, 0, 0),
    L6(5, 0, 0, 0, 0, 0, 0, 0x20A3, 0, 0, 0, 0, 0, 0, 0, 0, 80, 0, 0, 0),
    L6(5, 2, 270, 0, 0, 0, 0, 0x20A4, 34, 0, 0, 0, 0, 0, 0, 0, 96, 0, 0, 0),
    L6(3, 3, 0, 0, 0, 0, 0, 0x20A5, 0, 0, 0, 0, 0, 0, 0, 0, 112, 0, 0, 0),
    L6(8, 4, 0, 0, 0, 0, 0, 0x20A5, 0, 0, 0, 0, 0, 0, 0, 0, 128, 0, 0, 0),
    L6(2, 9, 0, 0, 0, 0, 0, 0x20A6, 0, 0, 0, 0, 0, 0, 0, 0, 144, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x20A7, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x20A8, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x20A9, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x20AA, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x20AB, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x20AC, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 64, 0, 0, 0, 0, 0, 0x20AD, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x1E3B, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x20AE, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x1E3C, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x20AF, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x1E3D, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x1E3D, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 1 CATCH 2 */
const u16 necro_caca_001_head[4] = { HEAD(6, 0, 25, 0, 0, 0, 0) };
const u16 necro_caca_001[424] = {
    CMD(CM_NGDA, 0, 13, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(4, 0, 0, 0, 0, 0, 0, 0x20B0, 0, 0, 0, 0, 0, 0, 0, 0, 160, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x20B1, 0, 0, 0, 0, 0, 0, 0, 0, 176, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x20B2, 0, 0, 0, 0, 0, 0, 0, 0, 192, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x20B3, 0, 0, 0, 0, 0, 0, 0, 0, 208, 0, 0, 0),
    L6(6, 0, 0, 0, 0, 0, 0, 0x20B4, 0, 0, 0, 0, 0, 0, 0, 0, 224, 0, 0, 0),
    L6(5, 0, 0, 0, 0, 0, 0, 0x20B5, 0, 0, 0, 0, 0, 0, 0, 0, 240, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x20B6, 0, 0, 0, 0, 0, 0, 0, 0, 256, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x20B7, 0, 0, 0, 0, 0, 0, 0, 0, 272, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x20B7, 0, 0, 0, 0, 0, 0, 0, 0, 288, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x20B8, 0, 0, 0, 0, 0, 0, 0, 0, 304, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x20B9, 0, 0, 0, 0, 0, 0, 0, 0, 320, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x20BA, 0, 0, 0, 0, 0, 0, 0, 0, 336, 0, 0, 0),
    L6(3, 2, 0, 0, 0, 0, 0, 0x20BB, 35, 0, 0, 0, 0, 0, 0, 0, 352, 0, 0, 0),
    L6(4, 3, 0, 0, 0, 0, 0, 0x20BC, 0, 0, 0, 0, 0, 0, 0, 0, 368, 0, 0, 0),
    L6(3, 4, 0, 0, 0, 0, 0, 0x20BD, 0, 0, 0, 0, 0, 0, 0, 0, 384, 0, 0, 0),
    L6(2, 4, 0, 0, 0, 0, 0, 0x20BE, 0, 0, 0, 0, 0, 0, 0, 0, 400, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x20BF, 0, 0, 0, 0, 0, 0, 0, 0, 416, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x20C0, 0, 0, 0, 0, 0, 0, 0, 0, 432, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x20C1, 0, 0, 0, 0, 0, 0, 0, 0, 448, 0, 0, 0),
    L6(1, 9, 0, 0, 0, 0, 0, 0x20C2, 0, 0, 0, 0, 0, 0, 0, 0, 464, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x20C3, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x20C4, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x20C5, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x20C6, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x20C7, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x1FE6, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x1FE7, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 64, 0, 0, 0, 0, 0, 0x1FE8, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x1FE9, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x1FEA, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x20C8, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x20C9, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x20CA, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x20CA, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 2 CATCH 3 */
const u16 necro_caca_002_head[4] = { HEAD(6, 0, 17, 0, 0, 0, 0) };
const u16 necro_caca_002[292] = {
    CMD(CM_NGDA, 1542, 21, 2), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(2, 0, 264, 0, 0, 0, 0, 0x20D0, 0, 0, 0, 0, 0, 0, 0, 4096, 688, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x20D1, 0, 0, 0, 0, 0, 0, 0, 4096, 704, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x20D2, 0, 0, 0, 0, 0, 0, 0, 4096, 720, 0, 0, 0),
    L6(1, 0, 497, 0, 0, 0, 0, 0x20D3, 0, 0, 0, 0, 0, 0, 0, 4096, 736, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x20D4, 0, 0, 0, 0, 0, 0, 0, 4096, 752, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x20D5, 0, 0, 0, 0, 0, 0, 0, 4096, 768, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x20D6, 0, 0, 0, 0, 0, 0, 0, 4096, 784, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x20D7, 0, 0, 0, 0, 0, 0, 0, 4096, 800, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x20D8, 0, 0, 0, 0, 0, 0, 0, 4096, 816, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x20D9, 0, 0, 0, 0, 0, 0, 0, 4096, 832, 0, 0, 0),
    L6(6, 0, 0, 0, 0, 0, 0, 0x20DA, 0, 0, 0, 0, 0, 0, 0, 4096, 848, 0, 0, 0),
    CMD(CM_NGME, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(2, 2, 270, 0, 0, 0, 0, 0x20DB, 46, 0, 0, 0, 0, 0, 0, 256, 864, 0, 0, 0),
    L6(1, 9, 0, 0, 0, 0, 0, 0x20DC, 0, 0, 0, 0, 0, 0, 0, 256, 880, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x20DD, 0, 1, 0, 0, 0, 0, 0, 256, 16, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x20DE, 0, 1, 0, 0, 0, 0, 0, 256, 16, 8, 0, 0),
    CMD(CM_PS_Y, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(4, 0, 0, 0, 0, 0, 0, 0x1E22, 0, 1, 0, 0, 0, 0, 0, 256, 0, 0, 0, 0),
    L6(6, 0, 0, 0, 0, 0, 0, 0x1E23, 0, 1, 0, 0, 0, 0, 0, 256, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x1E21, 0, 1, 0, 0, 0, 0, 0, 256, 0, 0, 0, 0),
    L6(4, 64, 0, 0, 0, 0, 0, 0x1E3C, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x1E3D, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x1E3D, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 3 CATCH 4 */
const u16 necro_caca_003_head[4] = { HEAD(6, 0, 25, 0, 0, 0, 0) };
const u16 necro_caca_003[292] = {
    CMD(CM_NGDA, 0, 20, 2), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(3, 0, 0, 0, 0, 0, 0, 0x20E1, 0, 0, 0, 0, 0, 0, 0, 0, 480, 0, 0, 0),
    L6(9, 0, 0, 0, 0, 0, 0, 0x20E2, 0, 0, 0, 0, 0, 0, 0, 0, 496, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x20E3, 0, 0, 0, 0, 0, 0, 0, 0, 512, 200, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x20E4, 0, 0, 0, 0, 0, 0, 0, 0, 528, 202, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x20E5, 0, 0, 0, 0, 0, 0, 0, 0, 544, 204, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x20E6, 0, 0, 0, 0, 0, 0, 0, 0, 560, 206, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x20E7, 0, 0, 0, 0, 0, 0, 0, 0, 576, 208, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x20E8, 0, 0, 0, 0, 0, 0, 0, 0, 592, 210, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x20E9, 0, 0, 0, 0, 0, 0, 0, 0, 608, 212, 0, 0),
    L6(3, 0, 269, 0, 0, 0, 0, 0x20EA, 0, 0, 0, 0, 0, 0, 0, 0, 624, 214, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x20EB, 0, 0, 0, 0, 0, 0, 0, 0, 640, 216, 0, 0),
    L6(3, 2, 0, 0, 0, 0, 0, 0x20EC, -38, 0, 0, 0, 0, 0, 0, 0, 656, 0, 0, 0),
    L6(3, 9, 0, 0, 0, 0, 0, 0x20ED, 0, 0, 0, 0, 0, 0, 0, 0, 672, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x20EE, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x1E94, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x1E67, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x20AD, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x1E3B, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x20AE, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x1E3C, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x20AF, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x1E3D, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x1E3D, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 4 CATCH 5 */
const u16 necro_caca_004_head[4] = { HEAD(6, 0, 25, 0, 0, 0, 0) };
const u16 necro_caca_004[136] = {
    L6(3, 0, 0, 0, 0, 0, 0, 0x20EF, 0, 178, 0, 0, 0, 21, 0, 0, 16, 194, 0, 0),
    L6(9, 0, 0, 0, 0, 0, 0, 0x20F0, 0, 124, 0, 0, 0, 0, 0, 0, 16, 196, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x20F1, 0, 124, 0, 0, 0, 0, 0, 0, 16, 198, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x1F3E, 0, 122, 0, 0, 0, 0, 0, 0, 16, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x1F3F, 0, 122, 0, 0, 0, 0, 0, 0, 16, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x1F40, 0, 2, 0, 0, 0, 0, 0, 0, 16, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x1F41, 0, 2, 0, 0, 0, 0, 0, 0, 16, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x1E22, 0, 2, 0, 0, 0, 0, 0, 0, 16, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x1E23, 0, 2, 0, 0, 0, 0, 0, 0, 16, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x1E24, 0, 2, 0, 0, 0, 0, 0, 0, 16, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x1E24, 0, 2, 0, 0, 0, 0, 0, 0, 16, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 5 CATCH 6 */
const u16 necro_caca_005_head[4] = { HEAD(6, 0, 57, 0, 0, 0, 0) };
const u16 necro_caca_005[1224] = {
    CMD(CM_NGDA, 0, 28, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_IMGS, 1, 3, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(4, 0, 0, 0, 0, 0, 0, 0x20B0, 0, 0, 0, 0, 0, 0, 0, 782, 160, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x20B1, 0, 0, 0, 0, 0, 0, 0, 782, 176, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x20B2, 0, 0, 0, 0, 0, 0, 0, 782, 192, 0, 0, 0),
    L6(4, 0, 497, 0, 0, 0, 0, 0x20B3, 0, 0, 0, 0, 0, 0, 0, 782, 208, 0, 0, 0),
    L6(6, 0, 0, 0, 0, 0, 0, 0x20B4, 0, 0, 0, 0, 0, 0, 0, 0, 224, 0, 0, 0),
    L6(5, 0, 0, 0, 0, 0, 0, 0x20B5, 0, 0, 0, 0, 0, 0, 0, 0, 240, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x20B6, 0, 0, 0, 0, 0, 0, 0, 0, 256, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x20B7, 0, 0, 0, 0, 0, 0, 0, 0, 272, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x20B7, 0, 0, 0, 0, 0, 0, 0, 0, 288, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x20B8, 0, 0, 0, 0, 0, 0, 0, 0, 304, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x20B9, 0, 0, 0, 0, 0, 0, 0, 0, 320, 0, 0, 0),
    L6(1, 0, 270, 0, 0, 0, 0, 0x20BA, 0, 0, 0, 0, 0, 0, 0, 0, 336, 0, 0, 0),
    L6(2, 2, 0, 0, 0, 0, 0, 0x20BB, -51, 0, 0, 0, 0, 0, 0, 0, 352, 0, 0, 0),
    L6(2, 3, 0, 0, 0, 0, 0, 0x20BC, 0, 0, 0, 0, 0, 0, 0, 0, 368, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x20BD, 0, 0, 0, 0, 0, 0, 0, 0, 384, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x20BE, 0, 0, 0, 0, 0, 0, 0, 0, 400, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x20BF, 0, 0, 0, 0, 0, 0, 0, 0, 416, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x20C0, 0, 0, 0, 0, 0, 0, 0, 0, 432, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x20D1, 0, 0, 0, 0, 0, 0, 0, 0, 896, 238, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x20B3, 0, 0, 0, 0, 0, 0, 0, 0, 208, 262, 0, 0),
    L6(6, 0, 0, 0, 0, 0, 0, 0x20B4, 0, 0, 0, 0, 0, 0, 0, 0, 224, 0, 0, 0),
    L6(5, 0, 0, 0, 0, 0, 0, 0x20B5, 0, 0, 0, 0, 0, 0, 0, 0, 240, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x20B6, 0, 0, 0, 0, 0, 0, 0, 0, 256, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x20B7, 0, 0, 0, 0, 0, 0, 0, 0, 272, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x20B7, 0, 0, 0, 0, 0, 0, 0, 0, 288, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x20B8, 0, 0, 0, 0, 0, 0, 0, 0, 304, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x20B9, 0, 0, 0, 0, 0, 0, 0, 0, 320, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x20BA, 0, 0, 0, 0, 0, 0, 0, 0, 336, 0, 0, 0),
    L6(2, 2, 0, 0, 0, 0, 0, 0x20BB, -51, 0, 0, 0, 0, 0, 0, 0, 352, 0, 0, 0),
    L6(2, 3, 0, 0, 0, 0, 0, 0x20BC, 0, 0, 0, 0, 0, 0, 0, 0, 368, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x20BD, 0, 0, 0, 0, 0, 0, 0, 0, 384, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x20BE, 0, 0, 0, 0, 0, 0, 0, 0, 400, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x20BF, 0, 0, 0, 0, 0, 0, 0, 0, 416, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x20C0, 0, 0, 0, 0, 0, 0, 0, 0, 432, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x20D1, 0, 0, 0, 0, 0, 0, 0, 0, 896, 238, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x20D2, 0, 0, 0, 0, 0, 0, 0, 0, 912, 240, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x20D3, 0, 0, 0, 0, 0, 0, 0, 0, 928, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x20D4, 0, 0, 0, 0, 0, 0, 0, 0, 944, 242, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x20D5, 0, 0, 0, 0, 0, 0, 0, 0, 960, 244, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x20D6, 0, 0, 0, 0, 0, 0, 0, 0, 976, 246, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x20D7, 0, 0, 0, 0, 0, 0, 0, 0, 992, 248, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x20D8, 0, 0, 0, 0, 0, 0, 0, 0, 1008, 250, 0, 0),
    L6(3, 0, 501, 0, 0, 0, 0, 0x20D9, 0, 0, 0, 0, 0, 0, 0, 0, 1024, 252, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x20DA, 0, 0, 0, 0, 0, 0, 0, 0, 1040, 254, 0, 0),
    L6(3, 2, 270, 0, 0, 0, 0, 0x20DB, -50, 0, 0, 0, 0, 0, 0, 0, 1056, 256, 0, 0),
    L6(3, 9, 0, 0, 0, 0, 0, 0x20DC, 0, 0, 0, 0, 0, 0, 0, 0, 1072, 258, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x20DD, 0, 1, 0, 0, 0, 0, 0, 0, 1088, 260, 0, 0),
    CMD(CM_PS_Y, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(3, 0, 0, 0, 0, 0, 0, 0x20DE, 0, 1, 0, 0, 0, 0, 0, 0, 16, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x2019, 0, 1, 0, 0, 0, 0, 0, 0, 16, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x2018, 0, 1, 0, 0, 0, 0, 0, 0, 16, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x2017, 0, 1, 0, 0, 0, 0, 0, 0, 16, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x2016, 0, 1, 0, 0, 0, 0, 0, 0, 16, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x2015, 0, 1, 0, 0, 0, 0, 0, 0, 16, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x2014, 0, 1, 0, 0, 0, 0, 0, 0, 16, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x2013, 0, 1, 0, 0, 0, 0, 0, 0, 16, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x2012, 0, 1, 0, 0, 0, 0, 0, 0, 16, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x2012, 0, 1, 0, 0, 0, 0, 0, 0, 16, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0), 0x0006, 0x0038, 0x0000, 0x0000, 0x0069, 0x0000, 0x001C, 0x0001,
    CMD(CM_DUMMY, 0, 0, 0), 0x0000, 0x0000, 0x0000, 0x0000, 0x005A, 0x0000, 0x0000, 0x0000,
    CMD(CM_DUMMY, 0, 0, 0), 0x0000, 0x0000, 0x0000, 0x0000, 0x002B, 0x0014, 0x0001, 0x0000,
    CMD(CM_DUMMY, 0, 0, 0), 0x0000, 0x0000, 0x0000, 0x0000, 0x0400, 0x0000, 0x0000, 0x20B0,
    CMD(CM_DUMMY, 0, 0, 0), 0x0000, 0x00A0, 0x0000, 0x0000, 0x0400, 0x0000, 0x0000, 0x20B1,
    CMD(CM_DUMMY, 0, 0, 0), 0x0000, 0x00B0, 0x0000, 0x0000, 0x0400, 0x0000, 0x0000, 0x20B2,
    CMD(CM_DUMMY, 0, 0, 0), 0x0000, 0x00C0, 0x0000, 0x0000, 0x0400, 0x1F10, 0x0000, 0x20B3,
    CMD(CM_DUMMY, 0, 0, 0), 0x0000, 0x00D0, 0x0000, 0x0000, 0x0600, 0x0000, 0x0000, 0x20B4,
    CMD(CM_DUMMY, 0, 0, 0), 0x0000, 0x00E0, 0x0000, 0x0000, 0x0500, 0x0000, 0x0000, 0x20B5,
    CMD(CM_DUMMY, 0, 0, 0), 0x0000, 0x00F0, 0x0000, 0x0000, 0x0300, 0x0000, 0x0000, 0x20B6,
    CMD(CM_DUMMY, 0, 0, 0), 0x0000, 0x0100, 0x0000, 0x0000, 0x0300, 0x0000, 0x0000, 0x20B7,
    CMD(CM_DUMMY, 0, 0, 0), 0x0000, 0x0110, 0x0000, 0x0000, 0x0300, 0x0000, 0x0000, 0x20B7,
    CMD(CM_DUMMY, 0, 0, 0), 0x0000, 0x0120, 0x0000, 0x0000, 0x0200, 0x0000, 0x0000, 0x20B8,
    CMD(CM_DUMMY, 0, 0, 0), 0x0000, 0x0130, 0x0000, 0x0000, 0x0100, 0x0000, 0x0000, 0x20B9,
    CMD(CM_DUMMY, 0, 0, 0), 0x0000, 0x0140, 0x0000, 0x0000, 0x0100, 0x10E0, 0x0000, 0x20BA,
    CMD(CM_DUMMY, 0, 0, 0), 0x0000, 0x0150, 0x0000, 0x0000, 0x0302, 0x0000, 0x0000, 0x20BB,
    L6(243, 64, 0, 0, 0, 0, 0, 0x0000, 0, 0, 352, 0, 0, 0, 0, 1027, 0, 0, 32, 188),
    CMD(CM_DUMMY, 0, 0, 0), 0x0000, 0x0170, 0x0000, 0x0000, 0x0300, 0x0000, 0x0000, 0x20D1,
    CMD(CM_DUMMY, 0, 0, 0), 0x0000, 0x0380, 0x00EE, 0x0000, 0x0300, 0x0000, 0x0000, 0x20D2,
    CMD(CM_DUMMY, 0, 0, 0), 0x0000, 0x0390, 0x00F0, 0x0000, 0x0300, 0x0000, 0x0000, 0x20D3,
    CMD(CM_DUMMY, 0, 0, 0), 0x0000, 0x03A0, 0x0000, 0x0000, 0x0300, 0x0000, 0x0000, 0x20D4,
    CMD(CM_DUMMY, 0, 0, 0), 0x0000, 0x03B0, 0x00F2, 0x0000, 0x0300, 0x0000, 0x0000, 0x20D5,
    CMD(CM_DUMMY, 0, 0, 0), 0x0000, 0x03C0, 0x00F4, 0x0000, 0x0300, 0x0000, 0x0000, 0x20D6,
    CMD(CM_DUMMY, 0, 0, 0), 0x0000, 0x03D0, 0x00F6, 0x0000, 0x0300, 0x0000, 0x0000, 0x20D7,
    CMD(CM_DUMMY, 0, 0, 0), 0x0000, 0x03E0, 0x00F8, 0x0000, 0x0300, 0x0000, 0x0000, 0x20D8,
    CMD(CM_DUMMY, 0, 0, 0), 0x0000, 0x03F0, 0x00FA, 0x0000, 0x0300, 0x1F50, 0x0000, 0x20D9,
    CMD(CM_DUMMY, 0, 0, 0), 0x0000, 0x0400, 0x00FC, 0x0000, 0x0300, 0x0000, 0x0000, 0x20DA,
    CMD(CM_DUMMY, 0, 0, 0), 0x0000, 0x0410, 0x00FE, 0x0000, 0x0302, 0x10E0, 0x0000, 0x20DB,
    L6(243, 128, 0, 0, 0, 0, 0, 0x0000, 0, 0, 1056, 1, 0, 0, 0, 777, 0, 0, 32, 220),
    CMD(CM_DUMMY, 0, 0, 0), 0x0000, 0x0430, 0x0102, 0x0000, 0x0300, 0x0000, 0x0000, 0x20DD,
    CMD(CM_DUMMY, 8192, 0, 0), 0x0000, 0x0440, 0x0104, 0x0000, 0x0027, 0x0000, 0x0000, 0x0000,
    CMD(CM_DUMMY, 0, 0, 0), 0x0000, 0x0000, 0x0000, 0x0000, 0x0300, 0x0000, 0x0000, 0x20DE,
    CMD(CM_DUMMY, 8192, 0, 0), 0x0000, 0x0010, 0x0000, 0x0000, 0x0300, 0x0000, 0x0000, 0x2019,
    CMD(CM_DUMMY, 8192, 0, 0), 0x0000, 0x0010, 0x0000, 0x0000, 0x0300, 0x0000, 0x0000, 0x2018,
    CMD(CM_DUMMY, 8192, 0, 0), 0x0000, 0x0010, 0x0000, 0x0000, 0x0300, 0x0000, 0x0000, 0x2017,
    CMD(CM_DUMMY, 8192, 0, 0), 0x0000, 0x0010, 0x0000, 0x0000, 0x0300, 0x0000, 0x0000, 0x2016,
    CMD(CM_DUMMY, 8192, 0, 0), 0x0000, 0x0010, 0x0000, 0x0000, 0x0300, 0x0000, 0x0000, 0x2015,
    CMD(CM_DUMMY, 8192, 0, 0), 0x0000, 0x0010, 0x0000, 0x0000, 0x0300, 0x0000, 0x0000, 0x2014,
    CMD(CM_DUMMY, 8192, 0, 0), 0x0000, 0x0010, 0x0000, 0x0000, 0x0300, 0x0000, 0x0000, 0x2013,
    CMD(CM_DUMMY, 8192, 0, 0), 0x0000, 0x0010, 0x0000, 0x0000, 0x0300, 0x0000, 0x0000, 0x2012,
    CMD(CM_DUMMY, 8192, 0, 0), 0x0000, 0x0010, 0x0000, 0x0000, 0xFAFF, 0x0000, 0x0000, 0x2012,
    CMD(CM_DUMMY, 8192, 0, 0), 0x0000, 0x0010, 0x0000, 0x0000, 0x0001, 0x0000, 0x0000, 0x0000,
};

/* script: 6 CATCH 7 */
const u16 necro_caca_006_head[4] = { HEAD(6, 0, 16, 0, 0, 0, 0) };
const u16 necro_caca_006[64] = {
    CMD(CM_NGDA, 1542, 9, 2), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_PS_Y, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(6, 0, 264, 0, 0, 0, 0, 0x2098, 0, 0, 0, 0, 0, 0, 0, 0, 16, 0, 0, 0),
    L6(2, 6, 264, 0, 0, 0, 0, 0x2098, 0, 0, 0, 0, 0, 0, 0, 0, 16, 0, 0, 0),
    CMD(CM_JMP, 2, 0, 3), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 7 CATCH 8 */
const u16 necro_caca_007_head[4] = { HEAD(6, 0, 17, 0, 0, 0, 0) };
const u16 necro_caca_007[52] = {
    CMD(CM_NGDA, 1542, 21, 2), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(6, 0, 264, 0, 0, 0, 0, 0x20D0, 0, 0, 0, 0, 0, 0, 0, 4096, 688, 0, 0, 0),
    L6(4, 6, 0, 0, 0, 0, 0, 0x20D1, 0, 0, 0, 0, 0, 0, 0, 4096, 704, 0, 0, 0),
    CMD(CM_JMP, 2, 2, 3), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 8 CATCH 9 */
const u16 necro_caca_008_head[4] = { HEAD(6, 0, 25, 0, 0, 0, 0) };
const u16 necro_caca_008[292] = {
    CMD(CM_NGDA, 0, 20, 2), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(3, 0, 0, 0, 0, 0, 0, 0x20E1, 0, 0, 0, 0, 0, 0, 0, 0, 480, 0, 0, 0),
    L6(9, 0, 0, 0, 0, 0, 0, 0x20E2, 0, 0, 0, 0, 0, 0, 0, 0, 496, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x20E3, 0, 0, 0, 0, 0, 0, 0, 0, 512, 200, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x20E4, 0, 0, 0, 0, 0, 0, 0, 0, 528, 202, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x20E5, 0, 0, 0, 0, 0, 0, 0, 0, 544, 204, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x20E6, 0, 0, 0, 0, 0, 0, 0, 0, 560, 206, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x20E7, 0, 0, 0, 0, 0, 0, 0, 0, 576, 208, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x20E8, 0, 0, 0, 0, 0, 0, 0, 0, 592, 210, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x20E9, 0, 0, 0, 0, 0, 0, 0, 0, 608, 212, 0, 0),
    L6(3, 0, 269, 0, 0, 0, 0, 0x20EA, 0, 0, 0, 0, 0, 0, 0, 0, 624, 214, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x20EB, 0, 0, 0, 0, 0, 0, 0, 0, 640, 216, 0, 0),
    L6(3, 2, 0, 0, 0, 0, 0, 0x20EC, -68, 0, 0, 0, 0, 0, 0, 0, 656, 0, 0, 0),
    L6(3, 9, 0, 0, 0, 0, 0, 0x20ED, 0, 0, 0, 0, 0, 0, 0, 0, 672, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x20EE, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x1E94, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x1E67, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x20AD, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x1E3B, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x20AE, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x1E3C, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x20AF, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x1E3D, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x1E3D, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 9 CATCH 10 */
const u16 necro_caca_009_head[4] = { HEAD(6, 0, 25, 0, 0, 0, 0) };
const u16 necro_caca_009[292] = {
    CMD(CM_NGDA, 0, 20, 2), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(3, 0, 0, 0, 0, 0, 0, 0x20E1, 0, 0, 0, 0, 0, 0, 0, 0, 480, 0, 0, 0),
    L6(9, 0, 0, 0, 0, 0, 0, 0x20E2, 0, 0, 0, 0, 0, 0, 0, 0, 496, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x20E3, 0, 0, 0, 0, 0, 0, 0, 0, 512, 200, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x20E4, 0, 0, 0, 0, 0, 0, 0, 0, 528, 202, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x20E5, 0, 0, 0, 0, 0, 0, 0, 0, 544, 204, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x20E6, 0, 0, 0, 0, 0, 0, 0, 0, 560, 206, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x20E7, 0, 0, 0, 0, 0, 0, 0, 0, 576, 208, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x20E8, 0, 0, 0, 0, 0, 0, 0, 0, 592, 210, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x20E9, 0, 0, 0, 0, 0, 0, 0, 0, 608, 212, 0, 0),
    L6(3, 0, 269, 0, 0, 0, 0, 0x20EA, 0, 0, 0, 0, 0, 0, 0, 0, 624, 214, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x20EB, 0, 0, 0, 0, 0, 0, 0, 0, 640, 216, 0, 0),
    L6(3, 2, 0, 0, 0, 0, 0, 0x20EC, -69, 0, 0, 0, 0, 0, 0, 0, 656, 0, 0, 0),
    L6(3, 9, 0, 0, 0, 0, 0, 0x20ED, 0, 0, 0, 0, 0, 0, 0, 0, 672, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x20EE, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x1E94, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x1E67, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x20AD, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x1E3B, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x20AE, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x1E3C, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x20AF, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x1E3D, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x1E3D, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 10 CATCH 11 */
const u16 necro_caca_010_head[4] = { HEAD(6, 0, 25, 0, 0, 0, 0) };
const u16 necro_caca_010[184] = {
    CMD(CM_NGDA, 0, 13, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(4, 0, 0, 0, 0, 0, 0, 0x20B0, 0, 0, 0, 0, 0, 0, 0, 0, 160, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x20B1, 0, 0, 0, 0, 0, 0, 0, 0, 176, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x20B2, 0, 0, 0, 0, 0, 0, 0, 0, 192, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x20B3, 0, 0, 0, 0, 0, 0, 0, 0, 208, 0, 0, 0),
    L6(6, 0, 0, 0, 0, 0, 0, 0x20B4, 0, 0, 0, 0, 0, 0, 0, 0, 224, 0, 0, 0),
    L6(5, 0, 0, 0, 0, 0, 0, 0x20B5, 0, 0, 0, 0, 0, 0, 0, 0, 240, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x20B6, 0, 0, 0, 0, 0, 0, 0, 0, 256, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x20B7, 0, 0, 0, 0, 0, 0, 0, 0, 272, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x20B7, 0, 0, 0, 0, 0, 0, 0, 0, 288, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x20B8, 0, 0, 0, 0, 0, 0, 0, 0, 304, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x20B9, 0, 0, 0, 0, 0, 0, 0, 0, 320, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x20BA, 0, 0, 0, 0, 0, 0, 0, 0, 336, 0, 0, 0),
    L6(3, 2, 0, 0, 0, 0, 0, 0x20BB, 74, 0, 0, 0, 0, 0, 0, 0, 352, 0, 0, 0),
    CMD(CM_JMP, 2, 1, 15), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 11 CATCH 12 */
const u16 necro_caca_011_head[4] = { HEAD(6, 0, 25, 0, 0, 0, 0) };
const u16 necro_caca_011[184] = {
    CMD(CM_NGDA, 0, 13, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(4, 0, 0, 0, 0, 0, 0, 0x20B0, 0, 0, 0, 0, 0, 0, 0, 0, 160, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x20B1, 0, 0, 0, 0, 0, 0, 0, 0, 176, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x20B2, 0, 0, 0, 0, 0, 0, 0, 0, 192, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x20B3, 0, 0, 0, 0, 0, 0, 0, 0, 208, 0, 0, 0),
    L6(6, 0, 0, 0, 0, 0, 0, 0x20B4, 0, 0, 0, 0, 0, 0, 0, 0, 224, 0, 0, 0),
    L6(5, 0, 0, 0, 0, 0, 0, 0x20B5, 0, 0, 0, 0, 0, 0, 0, 0, 240, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x20B6, 0, 0, 0, 0, 0, 0, 0, 0, 256, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x20B7, 0, 0, 0, 0, 0, 0, 0, 0, 272, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x20B7, 0, 0, 0, 0, 0, 0, 0, 0, 288, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x20B8, 0, 0, 0, 0, 0, 0, 0, 0, 304, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x20B9, 0, 0, 0, 0, 0, 0, 0, 0, 320, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x20BA, 0, 0, 0, 0, 0, 0, 0, 0, 336, 0, 0, 0),
    L6(3, 2, 0, 0, 0, 0, 0, 0x20BB, 75, 0, 0, 0, 0, 0, 0, 0, 352, 0, 0, 0),
    CMD(CM_JMP, 2, 1, 15), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

extern const u16 necro_cuca_000[], necro_cuca_001[], necro_cuca_002[], necro_cuca_003[], necro_cuca_004[], necro_cuca_005[], necro_cuca_006[], necro_cuca_007[], necro_cuca_008[], necro_cuca_009[], necro_cuca_010[], necro_cuca_011[], necro_cuca_012[], necro_cuca_013[], necro_cuca_014[], necro_cuca_015[], necro_cuca_016[], necro_cuca_017[], necro_cuca_018[], necro_cuca_019[], necro_cuca_020[], necro_cuca_021[], necro_cuca_022[], necro_cuca_023[], necro_cuca_024[], necro_cuca_025[], necro_cuca_026[], necro_cuca_027[], necro_cuca_028[], necro_cuca_029[], necro_cuca_030[], necro_cuca_031[], necro_cuca_032[], necro_cuca_033[], necro_cuca_034[], necro_cuca_035[], necro_cuca_037[], necro_cuca_038[], necro_cuca_039[], necro_cuca_040[], necro_cuca_041[], necro_cuca_042[], necro_cuca_043[], necro_cuca_044[], necro_cuca_045[], necro_cuca_046[], necro_cuca_047[];

/* cuca scripts (debug viewer: CAUGHT): 48 entries */
const u32 necro_cuca[49] = {
    (u32)necro_cuca_000,  /* 0 ALEX ZUTUKI */
    (u32)necro_cuca_001,  /* 1 ALEX BODY S */
    (u32)necro_cuca_002,  /* 2 ALEX BACK D */
    (u32)necro_cuca_003,  /* 3 ALEX POWER B */
    (u32)necro_cuca_004,  /* 4 ALEX SLEEPER */
    (u32)necro_cuca_005,  /* 5 RYU SEOINAGE */
    (u32)necro_cuca_006,  /* 6 IBUKI */
    (u32)necro_cuca_007,  /* 7 DADLEY L B */
    (u32)necro_cuca_008,  /* 8 IBUKI KUBIORI */
    (u32)necro_cuca_009,  /* 9 NECRO S T */
    (u32)necro_cuca_010,  /* 10 RYU TOMOENAGE */
    (u32)necro_cuca_011,  /* 11 YUN HIZAGERI */
    (u32)necro_cuca_012,  /* 12 ORO KUBISIME */
    (u32)necro_cuca_013,  /* 13 NECRO G S */
    (u32)necro_cuca_014,  /* 14 DUDDLEY D S */
    (u32)necro_cuca_015,  /* 15 YUN MONKEY F */
    (u32)necro_cuca_016,  /* 16 ORO TOMOENAGE */
    (u32)necro_cuca_017,  /* 17 ORO NIOURIKI */
    (u32)necro_cuca_018,  /* 18 ORO GIGOKU G */
    (u32)necro_cuca_019,  /* 19 YUN */
    (u32)necro_cuca_020,  /* 20 NECRO SNAKE F */
    (u32)necro_cuca_021,  /* 21 NECRO F S */
    (u32)necro_cuca_022,  /* 22 IBUKI HARAIG */
    (u32)necro_cuca_023,  /* 23 GILL SPLASH M */
    (u32)necro_cuca_024,  /* 24 KEN HIZAGERI */
    (u32)necro_cuca_025,  /* 25 ORO KISINRIKI */
    (u32)necro_cuca_026,  /* 26 SEAN TACKLE */
    (u32)necro_cuca_027,  /* 27 ALEX HYPER B */
    (u32)necro_cuca_028,  /* 28 NECRO SLAM D */
    (u32)necro_cuca_029,  /* 29 ELENA ASINAGE */
    (u32)necro_cuca_030,  /* 30 GILL IMPACT C */
    (u32)necro_cuca_031,  /* 31 ALEX S H B */
    (u32)necro_cuca_032,  /* 32 ALEX F N D */
    (u32)necro_cuca_033,  /* 33 no name */
    (u32)necro_cuca_034,  /* 34 IBUKI */
    (u32)necro_cuca_035,  /* 35 IBUKI YOROI D */
    (u32)necro_cuca_035,  /* 36 no name */
    (u32)necro_cuca_037,  /* 37 MAWARIKOMI M F */
    (u32)necro_cuca_038,  /* 38 HUGO BODY S */
    (u32)necro_cuca_039,  /* 39 HUGO N G T */
    (u32)necro_cuca_040,  /* 40 HUGO M S P */
    (u32)necro_cuca_041,  /* 41 HUGO S D B B */
    (u32)necro_cuca_042,  /* 42 no name */
    (u32)necro_cuca_043,  /* 43 no name */
    (u32)necro_cuca_044,  /* 44 no name */
    (u32)necro_cuca_045,  /* 45 no name */
    (u32)necro_cuca_046,  /* 46 no name */
    (u32)necro_cuca_047,  /* 47 no name */
    0
};

/* script: 0 ALEX ZUTUKI */
const u16 necro_cuca_000_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 necro_cuca_000[56] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x206D),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FCB),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FEA),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FEA),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FEA),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2074),
    CMD(CM_RMJA, 3, 0, 12),
    L2(250, 9, 0, 0, 0, 0, 0, 0x2075),
    CMD(CM_MDAT, 1, 12, 1),
    CMD(CM_JMP, 1, 25, 1),
    CMD(CM_DUMMY, 0, 0, 0),
    CMD(CM_MDAT, 1, 24, 2),
    CMD(CM_JMP, 1, 73, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 1 ALEX BODY S */
const u16 necro_cuca_001_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 necro_cuca_001[60] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FEA),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2080),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2080),
    L2(250, 0, 0, 0, 3, 0, 0, 0x2037),
    L2(250, 0, 0, 0, 3, 0, 0, 0x2034),
    L2(250, 0, 0, 0, 3, 0, 0, 0x2032),
    L2(250, 0, 0, 0, 3, 0, 0, 0x2031),
    L2(250, 0, 0, 0, 3, 0, 0, 0x2030),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2038),
    CMD(CM_RMJA, 3, 1, 12),
    L2(250, 9, 0, 0, 0, 0, 0, 0x2038),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_RJA, 7, 9, 1),
    CMD(CM_JMP, 6, 80, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 2 ALEX BACK D */
const u16 necro_cuca_002_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 necro_cuca_002[80] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x2067),
    L2(250, 0, 0, 0, 1, 0, 0, 0x1ED1),
    L2(250, 0, 0, 0, 1, 0, 0, 0x1ED1),
    L2(250, 0, 0, 0, 1, 0, 0, 0x1ED2),
    L2(250, 0, 0, 0, 1, 0, 0, 0x1ED3),
    L2(250, 0, 0, 0, 1, 0, 0, 0x1ED6),
    L2(250, 0, 0, 0, 1, 0, 0, 0x207A),
    L2(250, 0, 0, 0, 1, 0, 0, 0x207A),
    L2(250, 0, 0, 0, 1, 0, 0, 0x20D3),
    L2(250, 0, 0, 0, 1, 0, 0, 0x20D4),
    L2(250, 0, 0, 0, 1, 0, 0, 0x206B),
    L2(250, 0, 0, 0, 1, 0, 0, 0x2036),
    L2(250, 0, 0, 0, 1, 0, 0, 0x2038),
    CMD(CM_RMJA, 3, 2, 18),
    L2(250, 9, 0, 0, 1, 0, 0, 0x2038),
    CMD(CM_MDAT, 1, 14, 2),
    CMD(CM_JMP, 7, 5, 1),
    CMD(CM_MDAT, 1, 14, 2),
    CMD(CM_JMP, 7, 5, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 3 ALEX POWER B */
const u16 necro_cuca_003_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 necro_cuca_003[84] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FEA),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FEA),
    L2(250, 0, 0, 0, 1, 0, 0, 0x2067),
    L2(250, 0, 0, 0, 1, 0, 0, 0x2065),
    L2(250, 0, 0, 0, 3, 0, 0, 0x206F),
    L2(250, 0, 0, 0, 3, 0, 0, 0x206F),
    L2(250, 0, 0, 0, 3, 0, 0, 0x206F),
    L2(250, 0, 0, 0, 0, 0, 0, 0x203A),
    L2(250, 0, 0, 0, 0, 0, 0, 0x203C),
    L2(250, 0, 0, 0, 0, 0, 0, 0x206E),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2035),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2036),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2004),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2038),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2039),
    L2(250, 0, 0, 0, 0, 0, 0, 0x203A),
    CMD(CM_RMJA, 3, 3, 19),
    L2(250, 9, 0, 0, 0, 0, 0, 0x2039),
    CMD(CM_MDAT, 1, 28, 1),
    CMD(CM_JMP, 6, 72, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 4 ALEX SLEEPER */
const u16 necro_cuca_004_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 necro_cuca_004[56] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x2067),
    L2(250, 0, 0, 0, 1, 0, 0, 0x1FED),
    L2(250, 0, 0, 0, 1, 0, 0, 0x1FED),
    L2(250, 0, 0, 0, 1, 0, 0, 0x1FC2),
    L2(250, 0, 0, 0, 1, 0, 0, 0x1FC4),
    L2(250, 0, 0, 0, 1, 0, 0, 0x1FC4),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2067),
    CMD(CM_RMJA, 3, 4, 12),
    L2(250, 9, 0, 0, 0, 0, 0, 0x2067),
    CMD(CM_MDAT, 1, 12, 1),
    CMD(CM_JMP, 1, 26, 1),
    CMD(CM_MDAT, 1, 24, 2),
    CMD(CM_JMP, 1, 73, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 5 RYU SEOINAGE */
const u16 necro_cuca_005_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 necro_cuca_005[64] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x1E01),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FC0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FC4),
    L2(250, 0, 0, 0, 1, 0, 0, 0x1FD1),
    L2(250, 0, 0, 0, 1, 0, 0, 0x1FCF),
    L2(250, 0, 0, 0, 1, 0, 0, 0x1FAE),
    L2(250, 0, 0, 0, 1, 0, 0, 0x1EB1),
    L2(250, 0, 0, 0, 2, 0, 0, 0x20C4),
    L2(250, 0, 0, 0, 1, 0, 0, 0x2038),
    L2(250, 0, 0, 0, 1, 0, 0, 0x2036),
    CMD(CM_RMJA, 3, 5, 13),
    L2(250, 9, 0, 0, 0, 0, 0, 0x202A),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_RJA, 1, 60, 2),
    CMD(CM_JMP, 6, 80, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 6 IBUKI */
const u16 necro_cuca_006_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 necro_cuca_006[68] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x1E6C),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1E80),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1E26),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FDA),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FDB),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FDC),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1E88),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1EC2),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1E8B),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1ECE),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1ECE),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FE2),
    CMD(CM_RMJA, 3, 6, 15),
    L2(250, 9, 0, 0, 0, 0, 0, 0x1FE2),
    CMD(CM_MDAT, 1, 18, 2),
    CMD(CM_JMP, 6, 16, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 7 DADLEY L B */
const u16 necro_cuca_007_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 necro_cuca_007[40] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FC3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FC3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FDB),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2079),
    CMD(CM_RMJA, 3, 7, 7),
    L2(250, 9, 0, 0, 0, 0, 0, 0x1FC3),
    CMD(CM_MDAT, 1, 18, 2),
    CMD(CM_RJA, 7, 6, 1),
    CMD(CM_JMP, 6, 29, 3),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 8 IBUKI KUBIORI */
const u16 necro_cuca_008_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 necro_cuca_008[48] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FC3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FC2),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FC1),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FC3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FC2),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FC4),
    CMD(CM_RMJA, 3, 8, 9),
    L2(250, 9, 0, 0, 0, 0, 0, 0x2044),
    CMD(CM_MDAT, 1, 18, 2),
    CMD(CM_RJA, 7, 9, 1),
    CMD(CM_JMP, 6, 23, 3),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 9 NECRO S T */
const u16 necro_cuca_009_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 necro_cuca_009[60] = {
    CMD(CM_PS_Y, 0, 0, 0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FD7),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FD7),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FD6),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FD7),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FD6),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FD6),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FC4),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FCD),
    CMD(CM_RMJA, 3, 9, 12),
    L2(250, 9, 0, 0, 0, 0, 0, 0x2030),
    CMD(CM_MDAT, 1, 18, 2),
    CMD(CM_RJA, 7, 6, 1),
    CMD(CM_JMP, 6, 48, 3),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 10 RYU TOMOENAGE */
const u16 necro_cuca_010_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 necro_cuca_010[48] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x1E01),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1E64),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FE8),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FE9),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FC3),
    L2(250, 0, 0, 0, 3, 0, 0, 0x206A),
    L2(250, 0, 0, 0, 0, 0, 0, 0x20DD),
    CMD(CM_RMJA, 3, 10, 10),
    L2(250, 9, 0, 0, 3, 0, 0, 0x207C),
    CMD(CM_MDAT, 1, 18, 2),
    CMD(CM_JMP, 6, 88, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 11 YUN HIZAGERI */
const u16 necro_cuca_011_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 necro_cuca_011[68] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FD7),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FD7),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FD7),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FD7),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FCB),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FCB),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FCA),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FE0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FDD),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FD9),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FD9),
    CMD(CM_RMJA, 3, 11, 14),
    L2(250, 9, 0, 0, 0, 0, 0, 0x1EE0),
    CMD(CM_MDAT, 1, 18, 2),
    CMD(CM_RJA, 7, 6, 1),
    CMD(CM_JMP, 6, 15, 3),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 12 ORO KUBISIME */
const u16 necro_cuca_012_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 necro_cuca_012[52] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x1E01),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1E20),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FD4),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FC8),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FC7),
    CMD(CM_RMJA, 3, 12, 11),
    L2(250, 9, 0, 0, 1, 0, 0, 0x2030),
    CMD(CM_MDAT, 1, 18, 2),
    CMD(CM_RJA, 7, 6, 1),
    CMD(CM_JMP, 6, 12, 3),
    CMD(CM_MDAT, 1, 24, 2),
    CMD(CM_JMP, 1, 73, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 13 NECRO G S */
const u16 necro_cuca_013_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 necro_cuca_013[104] = {
    L2(250, 0, 0, 0, 1, 0, 0, 0x2127),
    L2(250, 0, 0, 0, 1, 0, 0, 0x2128),
    L2(250, 0, 0, 0, 1, 0, 0, 0x2129),
    L2(250, 0, 0, 0, 1, 0, 0, 0x2129),
    L2(250, 0, 0, 0, 1, 0, 0, 0x212A),
    L2(250, 0, 0, 0, 1, 0, 0, 0x212B),
    L2(250, 0, 0, 0, 1, 0, 0, 0x207B),
    L2(250, 0, 0, 0, 1, 0, 0, 0x2031),
    L2(250, 0, 0, 0, 1, 0, 0, 0x2032),
    L2(250, 0, 0, 0, 1, 0, 0, 0x203D),
    L2(250, 0, 0, 0, 1, 0, 0, 0x2038),
    L2(250, 0, 0, 0, 1, 0, 0, 0x2038),
    L2(250, 0, 0, 0, 1, 0, 0, 0x2038),
    L2(250, 0, 0, 0, 1, 0, 0, 0x2039),
    L2(250, 0, 0, 0, 1, 0, 0, 0x203A),
    L2(250, 0, 0, 0, 1, 0, 0, 0x203A),
    L2(250, 0, 0, 0, 1, 0, 0, 0x2039),
    L2(250, 0, 0, 0, 1, 0, 0, 0x2039),
    L2(250, 0, 0, 0, 1, 0, 0, 0x2039),
    CMD(CM_RMJA, 3, 13, 24),
    L2(250, 9, 0, 0, 1, 0, 0, 0x2039),
    CMD(CM_MDAT, 1, 14, 2),
    CMD(CM_JMP, 7, 5, 1),
    CMD(CM_MDAT, 1, 14, 2),
    CMD(CM_JMP, 7, 5, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 14 DUDDLEY D S */
const u16 necro_cuca_014_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 necro_cuca_014[48] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FCE),
    L2(250, 0, 0, 0, 1, 0, 0, 0x1FE8),
    L2(250, 0, 0, 0, 1, 0, 0, 0x1FE9),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2066),
    L2(250, 0, 0, 0, 1, 0, 0, 0x1FDE),
    L2(250, 0, 0, 0, 1, 0, 0, 0x1FE3),
    CMD(CM_RMJA, 3, 14, 9),
    L2(250, 9, 0, 0, 1, 0, 0, 0x1FE4),
    CMD(CM_MDAT, 1, 18, 2),
    CMD(CM_RJA, 7, 7, 1),
    CMD(CM_JMP, 6, 17, 3),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 15 YUN MONKEY F */
const u16 necro_cuca_015_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 necro_cuca_015[64] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FC9),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FD7),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FD7),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FD7),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1E26),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1E27),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1E28),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FD7),
    L2(250, 0, 0, 0, 1, 0, 0, 0x2064),
    L2(250, 0, 0, 0, 3, 0, 0, 0x2035),
    L2(250, 0, 0, 0, 3, 0, 0, 0x2031),
    CMD(CM_RMJA, 3, 15, 14),
    L2(250, 9, 0, 0, 0, 0, 0, 0x203C),
    CMD(CM_MDAT, 1, 18, 2),
    CMD(CM_JMP, 6, 92, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 16 ORO TOMOENAGE */
const u16 necro_cuca_016_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 necro_cuca_016[56] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x1EE0),
    L2(250, 0, 0, 0, 3, 0, 0, 0x2037),
    L2(250, 0, 0, 0, 3, 0, 0, 0x2036),
    L2(250, 0, 0, 0, 3, 0, 0, 0x2035),
    L2(250, 0, 0, 0, 3, 0, 0, 0x206B),
    L2(250, 0, 0, 0, 3, 0, 0, 0x2030),
    L2(250, 0, 0, 0, 3, 0, 0, 0x207C),
    L2(250, 0, 0, 0, 3, 0, 0, 0x206F),
    L2(250, 0, 0, 0, 3, 0, 0, 0x206F),
    CMD(CM_RMJA, 3, 16, 12),
    L2(250, 9, 0, 0, 0, 0, 0, 0x203A),
    CMD(CM_MDAT, 1, 18, 2),
    CMD(CM_JMP, 6, 92, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 17 ORO NIOURIKI */
const u16 necro_cuca_017_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 necro_cuca_017[108] = {
    L2(250, 0, 0, 0, 1, 0, 0, 0x1FD0),
    L2(250, 0, 0, 0, 1, 0, 0, 0x1FCF),
    L2(250, 0, 0, 0, 1, 0, 0, 0x2030),
    L2(250, 0, 0, 0, 1, 0, 0, 0x2032),
    L2(250, 0, 0, 0, 1, 0, 0, 0x2038),
    L2(250, 0, 0, 0, 1, 0, 0, 0x2039),
    L2(250, 0, 0, 0, 1, 0, 0, 0x203A),
    L2(250, 0, 0, 0, 0, 0, 0, 0x207C),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2030),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2031),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2036),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2038),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2039),
    L2(250, 0, 0, 0, 1, 0, 0, 0x207C),
    L2(250, 0, 0, 0, 1, 0, 0, 0x2030),
    L2(250, 0, 0, 0, 1, 0, 0, 0x2032),
    L2(250, 0, 0, 0, 1, 0, 0, 0x2038),
    L2(250, 0, 0, 0, 1, 0, 0, 0x2039),
    L2(250, 0, 0, 0, 0, 0, 0, 0x203A),
    CMD(CM_RMJA, 3, 17, 24),
    L2(250, 9, 0, 0, 0, 0, 0, 0x203A),
    CMD(CM_MDAT, 1, 14, 2),
    CMD(CM_JMP, 7, 5, 4),
    CMD(CM_MDAT, 1, 14, 2),
    CMD(CM_RJA, 7, 5, 10),
    CMD(CM_JMP, 7, 5, 4),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 18 ORO GIGOKU G */
const u16 necro_cuca_018_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 necro_cuca_018[68] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x2019),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2012),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2013),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2014),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2015),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2016),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2017),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2018),
    L2(250, 0, 0, 0, 0, 0, 0, 0x202A),
    L2(250, 3, 0, 0, 0, 0, 0, 0x2035),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2035),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2035),
    CMD(CM_RMJA, 3, 18, 15),
    L2(250, 9, 0, 0, 0, 0, 0, 0x2035),
    CMD(CM_MDAT, 1, 27, 2),
    CMD(CM_JMP, 1, 60, 2),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 19 YUN */
const u16 necro_cuca_019_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 necro_cuca_019[100] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x1E01),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1E01),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FDC),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FDC),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FDC),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FDB),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FDB),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FDB),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FDA),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FDA),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FDA),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FDA),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FDA),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FDB),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FDB),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FDB),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FDB),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FCC),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FCD),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FCE),
    CMD(CM_RMJA, 3, 19, 23),
    L2(250, 9, 0, 0, 0, 0, 0, 0x1E01),
    CMD(CM_MDAT, 1, 12, 1),
    CMD(CM_JMP, 1, 10, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 20 NECRO SNAKE F */
const u16 necro_cuca_020_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 necro_cuca_020[68] = {
    L2(250, 0, 0, 0, 1, 0, 0, 0x1E67),
    L2(250, 0, 0, 0, 1, 0, 0, 0x1E66),
    L2(250, 0, 0, 0, 1, 0, 0, 0x1E65),
    L2(250, 0, 0, 0, 1, 0, 0, 0x1E64),
    L2(250, 0, 0, 0, 1, 0, 0, 0x1E65),
    L2(250, 0, 0, 0, 1, 0, 0, 0x1E66),
    L2(250, 0, 0, 0, 1, 0, 0, 0x1E3A),
    L2(250, 0, 0, 0, 1, 0, 0, 0x1E38),
    L2(250, 0, 0, 0, 1, 0, 0, 0x2030),
    L2(250, 0, 0, 0, 1, 0, 0, 0x2031),
    L2(250, 0, 0, 0, 1, 0, 0, 0x2032),
    L2(250, 0, 0, 0, 1, 0, 0, 0x2034),
    CMD(CM_RMJA, 3, 20, 15),
    L2(250, 9, 0, 0, 1, 0, 0, 0x2036),
    CMD(CM_MDAT, 1, 18, 2),
    CMD(CM_JMP, 6, 100, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 21 NECRO F S */
const u16 necro_cuca_021_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 necro_cuca_021[68] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x1E67),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1E67),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FDC),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FDB),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FDB),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FDA),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FDA),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FDA),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FDA),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FDB),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FDB),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FEA),
    CMD(CM_RMJA, 3, 21, 15),
    L2(250, 9, 0, 0, 0, 0, 0, 0x1FEA),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_JMP, 6, 104, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 22 IBUKI HARAIG */
const u16 necro_cuca_022_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 necro_cuca_022[56] = {
    L2(250, 0, 0, 0, 1, 0, 0, 0x1FCF),
    L2(250, 0, 0, 0, 1, 0, 0, 0x2030),
    L2(250, 0, 0, 0, 1, 0, 0, 0x2031),
    L2(250, 0, 0, 0, 1, 0, 0, 0x2032),
    L2(250, 0, 0, 0, 1, 0, 0, 0x2033),
    L2(250, 0, 0, 0, 1, 0, 0, 0x2034),
    L2(250, 0, 0, 0, 1, 0, 0, 0x2036),
    L2(250, 0, 0, 0, 1, 0, 0, 0x2037),
    CMD(CM_RMJA, 3, 22, 11),
    L2(250, 9, 0, 0, 1, 0, 0, 0x2038),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_RJA, 7, 5, 1),
    CMD(CM_JMP, 6, 116, 2),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 23 GILL SPLASH M */
const u16 necro_cuca_023_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 necro_cuca_023[96] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FD7),
    L2(250, 0, 0, 0, 1, 0, 0, 0x2065),
    L2(250, 0, 0, 0, 1, 0, 0, 0x2064),
    L2(250, 0, 0, 0, 3, 0, 0, 0x206F),
    L2(250, 0, 0, 0, 3, 0, 0, 0x2070),
    L2(250, 0, 0, 0, 2, 0, 0, 0x203A),
    L2(250, 0, 0, 0, 3, 0, 0, 0x207A),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2035),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2034),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2033),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2032),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2031),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2033),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2027),
    L2(250, 0, 0, 0, 0, 0, 0, 0x206B),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2039),
    L2(250, 0, 0, 0, 0, 0, 0, 0x203A),
    CMD(CM_RMJA, 3, 23, 22),
    L2(250, 9, 0, 0, 0, 0, 0, 0x203B),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_JMP, 6, 112, 1),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_JMP, 6, 112, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 24 KEN HIZAGERI */
const u16 necro_cuca_024_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 necro_cuca_024[64] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FC0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FCF),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FD3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FEA),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FDC),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FE0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FDF),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FDE),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FDF),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FE0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FD7),
    CMD(CM_RMJA, 3, 24, 14),
    L2(250, 9, 0, 0, 0, 0, 0, 0x1FDE),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_JMP, 6, 15, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 25 ORO KISINRIKI */
const u16 necro_cuca_025_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 necro_cuca_025[112] = {
    L2(250, 0, 0, 0, 1, 0, 0, 0x1FD0),
    L2(250, 0, 0, 0, 1, 0, 0, 0x1FCF),
    L2(250, 0, 0, 0, 1, 0, 0, 0x2030),
    L2(250, 0, 0, 0, 1, 0, 0, 0x2032),
    L2(250, 0, 0, 0, 1, 0, 0, 0x2038),
    L2(250, 0, 0, 0, 1, 0, 0, 0x2039),
    L2(250, 0, 0, 0, 1, 0, 0, 0x203A),
    L2(250, 0, 0, 0, 0, 0, 0, 0x207C),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2030),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2031),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2036),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2038),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2039),
    L2(250, 0, 0, 0, 1, 0, 0, 0x207C),
    L2(250, 0, 0, 0, 1, 0, 0, 0x2030),
    L2(250, 0, 0, 0, 1, 0, 0, 0x2032),
    L2(250, 0, 0, 0, 1, 0, 0, 0x2038),
    L2(250, 0, 0, 0, 1, 0, 0, 0x2039),
    L2(250, 0, 0, 0, 0, 0, 0, 0x203A),
    L2(250, 0, 0, 0, 0, 0, 0, 0x203A),
    L2(250, 0, 0, 0, 0, 0, 0, 0x207B),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2031),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2033),
    CMD(CM_RMJA, 3, 25, 26),
    L2(250, 9, 0, 0, 0, 0, 0, 0x2034),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_RJA, 7, 5, 1),
    CMD(CM_JMP, 6, 15, 3),
};

/* script: 26 SEAN TACKLE */
const u16 necro_cuca_026_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 necro_cuca_026[72] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x2040),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FE5),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2032),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2034),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2035),
    L2(250, 3, 0, 0, 0, 0, 0, 0x2036),
    L2(250, 0, 0, 0, 0, 0, 0, 0x21B5),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2028),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2029),
    L2(250, 0, 0, 0, 0, 0, 0, 0x202A),
    L2(250, 0, 0, 0, 0, 0, 0, 0x202B),
    L2(250, 0, 0, 0, 0, 0, 0, 0x202C),
    L2(250, 3, 0, 0, 0, 0, 0, 0x202A),
    CMD(CM_RMJA, 3, 26, 16),
    L2(250, 9, 0, 0, 0, 0, 0, 0x202C),
    CMD(CM_MDAT, 1, 27, 2),
    CMD(CM_JMP, 1, 60, 2),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 27 ALEX HYPER B */
const u16 necro_cuca_027_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 necro_cuca_027[148] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x2067),
    L2(250, 0, 0, 0, 1, 0, 0, 0x1ED1),
    L2(250, 0, 0, 0, 1, 0, 0, 0x1ED1),
    L2(250, 0, 0, 0, 1, 0, 0, 0x1ED2),
    L2(250, 0, 0, 0, 1, 0, 0, 0x1ED3),
    L2(250, 0, 0, 0, 1, 0, 0, 0x1ED6),
    L2(250, 0, 0, 0, 1, 0, 0, 0x207A),
    L2(250, 0, 0, 0, 1, 0, 0, 0x207A),
    L2(250, 0, 0, 0, 1, 0, 0, 0x20D3),
    L2(250, 0, 0, 0, 1, 0, 0, 0x20D4),
    L2(250, 0, 0, 0, 1, 0, 0, 0x206B),
    L2(250, 0, 0, 0, 1, 0, 0, 0x2036),
    L2(250, 0, 0, 0, 1, 0, 0, 0x203A),
    L2(250, 0, 0, 0, 1, 0, 0, 0x203B),
    L2(250, 0, 0, 0, 2, 0, 0, 0x207B),
    L2(250, 0, 0, 0, 2, 0, 0, 0x207C),
    L2(250, 0, 0, 0, 2, 0, 0, 0x206B),
    L2(250, 0, 0, 0, 0, 0, 0, 0x203B),
    L2(250, 0, 0, 0, 0, 0, 0, 0x217B),
    L2(250, 0, 0, 0, 3, 0, 0, 0x2178),
    L2(250, 0, 0, 0, 3, 0, 0, 0x206F),
    L2(250, 0, 0, 0, 3, 0, 0, 0x206F),
    L2(250, 0, 0, 0, 3, 0, 0, 0x2070),
    L2(250, 0, 0, 0, 0, 0, 0, 0x203B),
    L2(250, 0, 0, 0, 0, 0, 0, 0x206F),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2035),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2036),
    L2(250, 0, 0, 0, 0, 0, 0, 0x206F),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2038),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2039),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2039),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2039),
    CMD(CM_RMJA, 3, 27, 35),
    L2(250, 9, 0, 0, 0, 0, 0, 0x2039),
    CMD(CM_MDAT, 1, 28, 1),
    CMD(CM_JMP, 6, 72, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 28 NECRO SLAM D */
const u16 necro_cuca_028_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 necro_cuca_028[128] = {
    L2(250, 0, 0, 0, 1, 0, 0, 0x2127),
    L2(250, 0, 0, 0, 1, 0, 0, 0x2128),
    L2(250, 0, 0, 0, 1, 0, 0, 0x2129),
    L2(250, 0, 0, 0, 1, 0, 0, 0x2129),
    L2(250, 0, 0, 0, 1, 0, 0, 0x212A),
    L2(250, 0, 0, 0, 1, 0, 0, 0x212B),
    L2(250, 0, 0, 0, 1, 0, 0, 0x207B),
    L2(250, 0, 0, 0, 1, 0, 0, 0x2031),
    L2(250, 0, 0, 0, 1, 0, 0, 0x2032),
    L2(250, 0, 0, 0, 1, 0, 0, 0x203D),
    L2(250, 0, 0, 0, 1, 0, 0, 0x2038),
    L2(250, 0, 0, 0, 1, 0, 0, 0x2038),
    L2(250, 0, 0, 0, 1, 0, 0, 0x2038),
    L2(250, 0, 0, 0, 1, 0, 0, 0x2039),
    L2(250, 0, 0, 0, 2, 0, 0, 0x2003),
    L2(250, 0, 0, 0, 2, 0, 0, 0x2005),
    L2(250, 0, 0, 0, 2, 0, 0, 0x2004),
    L2(250, 0, 0, 0, 2, 0, 0, 0x2004),
    L2(250, 0, 0, 0, 2, 0, 0, 0x2050),
    L2(250, 0, 0, 0, 2, 0, 0, 0x2035),
    L2(250, 0, 0, 0, 2, 0, 0, 0x2036),
    L2(250, 0, 0, 0, 2, 0, 0, 0x2036),
    L2(250, 0, 0, 0, 2, 0, 0, 0x2036),
    L2(250, 0, 0, 0, 2, 0, 0, 0x2037),
    L2(250, 0, 0, 0, 2, 0, 0, 0x2038),
    L2(250, 0, 0, 0, 1, 0, 0, 0x2034),
    CMD(CM_RMJA, 3, 28, 29),
    L2(250, 9, 0, 0, 1, 0, 0, 0x2034),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_RJA, 7, 6, 1),
    CMD(CM_JMP, 6, 108, 2),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 29 ELENA ASINAGE */
const u16 necro_cuca_029_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 necro_cuca_029[52] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FD7),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FDC),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FDB),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FDA),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FC0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x207A),
    L2(250, 0, 0, 0, 3, 0, 0, 0x2036),
    L2(250, 0, 0, 0, 3, 0, 0, 0x207B),
    CMD(CM_RMJA, 3, 29, 11),
    L2(250, 9, 0, 0, 3, 0, 0, 0x207C),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_JMP, 6, 88, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 30 GILL IMPACT C */
const u16 necro_cuca_030_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 necro_cuca_030[88] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x1E08),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FC0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2040),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2041),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2044),
    L2(250, 0, 0, 0, 1, 0, 0, 0x1F89),
    L2(250, 0, 0, 0, 1, 0, 0, 0x1E5C),
    L2(250, 0, 0, 0, 1, 0, 0, 0x1F6C),
    L2(250, 0, 0, 0, 1, 0, 0, 0x207A),
    L2(250, 0, 0, 0, 1, 0, 0, 0x2079),
    L2(250, 0, 0, 0, 1, 0, 0, 0x207A),
    L2(250, 0, 0, 0, 1, 0, 0, 0x207A),
    L2(250, 0, 0, 0, 1, 0, 0, 0x207A),
    CMD(CM_RMJA, 3, 30, 19),
    L2(250, 9, 0, 0, 1, 0, 0, 0x207A),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_RJA, 7, 32, 1),
    CMD(CM_JMP, 6, 124, 1),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_RJA, 7, 33, 1),
    CMD(CM_JMP, 6, 124, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 31 ALEX S H B */
const u16 necro_cuca_031_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 necro_cuca_031[64] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x206D),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FCB),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FEA),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FEA),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FEA),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2074),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2075),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2075),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2075),
    CMD(CM_RMJA, 3, 31, 14),
    L2(250, 9, 0, 0, 0, 0, 0, 0x2075),
    CMD(CM_MDAT, 1, 12, 1),
    CMD(CM_JMP, 1, 25, 2),
    CMD(CM_MDAT, 1, 24, 2),
    CMD(CM_JMP, 1, 73, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 32 ALEX F N D */
const u16 necro_cuca_032_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 necro_cuca_032[48] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FE2),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FE3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FE4),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FE4),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2035),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2036),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2038),
    L2(250, 0, 0, 0, 0, 0, 0, 0x202A),
    CMD(CM_RMJA, 3, 32, 11),
    L2(250, 9, 0, 0, 0, 0, 0, 0x202A),
    CMD(CM_MDAT, 1, 27, 2),
    CMD(CM_JMP, 1, 60, 2),
};

/* script: 33 no name */
const u16 necro_cuca_033_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 necro_cuca_033[84] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x2067),
    L2(250, 0, 0, 0, 1, 0, 0, 0x1ED1),
    L2(250, 0, 0, 0, 1, 0, 0, 0x1ED1),
    L2(250, 0, 0, 0, 1, 0, 0, 0x1ED2),
    L2(250, 0, 0, 0, 1, 0, 0, 0x1ED3),
    L2(250, 0, 0, 0, 1, 0, 0, 0x1ED6),
    L2(250, 0, 0, 0, 1, 0, 0, 0x207A),
    L2(250, 0, 0, 0, 1, 0, 0, 0x207A),
    L2(250, 0, 0, 0, 1, 0, 0, 0x20D3),
    L2(250, 0, 0, 0, 1, 0, 0, 0x20D4),
    L2(250, 0, 0, 0, 1, 0, 0, 0x206B),
    L2(250, 0, 0, 0, 1, 0, 0, 0x2036),
    CMD(CM_RMJA, 3, 33, 18),
    L2(250, 9, 0, 0, 1, 0, 0, 0x2038),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_RJA, 7, 6, 1),
    CMD(CM_JMP, 6, 120, 8),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_RJA, 7, 6, 1),
    CMD(CM_JMP, 6, 120, 8),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 34 IBUKI */
const u16 necro_cuca_034_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 necro_cuca_034[56] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x1E44),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2072),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FE2),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FE3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FE4),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FE5),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2081),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2082),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2081),
    CMD(CM_RMJA, 3, 34, 12),
    L2(250, 9, 0, 0, 0, 0, 0, 0x2081),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_JMP, 6, 108, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 35 IBUKI YOROI D, 36 no name */
const u16 necro_cuca_035_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 necro_cuca_035[68] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x1E6C),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1E80),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1E26),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FDA),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FDB),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FDC),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1E88),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1EC2),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1E8B),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1ECE),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1ECE),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FE2),
    CMD(CM_RMJA, 3, 35, 15),
    L2(250, 9, 0, 0, 0, 0, 0, 0x1FE2),
    CMD(CM_MDAT, 1, 18, 2),
    CMD(CM_JMP, 6, 16, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 37 MAWARIKOMI M F */
const u16 necro_cuca_037_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 necro_cuca_037[132] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x1E01),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1E01),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FDC),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FDC),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FDC),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FDB),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FDB),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FDB),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FDA),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FDA),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FDA),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FDA),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FDA),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FDB),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FDB),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FDB),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FDB),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FCC),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FCD),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FD7),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FD7),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1E26),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1E27),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FD8),
    L2(250, 0, 0, 0, 3, 0, 0, 0x2035),
    L2(250, 0, 0, 0, 3, 0, 0, 0x2033),
    L2(250, 0, 0, 0, 2, 0, 0, 0x2035),
    L2(250, 0, 0, 0, 2, 0, 0, 0x2036),
    CMD(CM_RMJA, 3, 15, 14),
    L2(250, 9, 0, 0, 0, 0, 0, 0x203C),
    CMD(CM_MDAT, 1, 18, 2),
    CMD(CM_JMP, 6, 88, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 38 HUGO BODY S */
const u16 necro_cuca_038_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 necro_cuca_038[84] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x1E2D),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FCB),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FD6),
    L2(250, 0, 0, 0, 3, 0, 0, 0x2036),
    L2(250, 0, 0, 0, 3, 0, 0, 0x2035),
    L2(250, 0, 0, 0, 3, 0, 0, 0x2032),
    L2(250, 0, 0, 0, 3, 0, 0, 0x2030),
    L2(250, 0, 0, 0, 2, 0, 0, 0x2035),
    L2(250, 0, 0, 0, 2, 0, 0, 0x2034),
    L2(250, 0, 0, 0, 2, 0, 0, 0x2033),
    L2(250, 0, 0, 0, 2, 0, 0, 0x2033),
    L2(250, 0, 0, 0, 2, 0, 0, 0x20C4),
    L2(250, 0, 0, 0, 2, 0, 0, 0x202E),
    L2(250, 0, 0, 0, 2, 0, 0, 0x207B),
    L2(250, 0, 0, 0, 2, 0, 0, 0x207A),
    CMD(CM_RMJA, 3, 1, 12),
    L2(250, 9, 0, 0, 2, 0, 0, 0x2084),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_RJA, 7, 9, 1),
    CMD(CM_JMP, 6, 80, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 39 HUGO N G T */
const u16 necro_cuca_039_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 necro_cuca_039[60] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FC0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FEA),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FE9),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2080),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2040),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2080),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FC2),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FC7),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FC9),
    L2(250, 0, 0, 0, 3, 0, 0, 0x2038),
    CMD(CM_RMJA, 3, 39, 13),
    L2(250, 9, 0, 0, 0, 0, 0, 0x2030),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_JMP, 6, 15, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 40 HUGO M S P */
const u16 necro_cuca_040_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 necro_cuca_040[148] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FC6),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FC1),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FCF),
    L2(250, 0, 0, 0, 1, 0, 0, 0x1FC7),
    L2(250, 0, 0, 0, 1, 0, 0, 0x1FC6),
    L2(250, 0, 0, 0, 1, 0, 0, 0x2030),
    L2(250, 0, 0, 0, 1, 0, 0, 0x1FC0),
    L2(250, 0, 0, 0, 1, 0, 0, 0x1F03),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1F02),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FC6),
    L2(250, 0, 0, 0, 1, 0, 0, 0x1FC6),
    L2(250, 0, 0, 0, 1, 0, 0, 0x1FC7),
    L2(250, 0, 0, 0, 1, 0, 0, 0x2042),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1F02),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FC7),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2040),
    L2(250, 0, 0, 0, 3, 0, 0, 0x203E),
    L2(250, 0, 0, 0, 3, 0, 0, 0x2035),
    L2(250, 0, 0, 0, 3, 0, 0, 0x2033),
    L2(250, 0, 0, 0, 3, 0, 0, 0x2049),
    L2(250, 0, 0, 0, 3, 0, 0, 0x1FE8),
    L2(250, 0, 0, 0, 0, 0, 0, 0x203D),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2004),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2003),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2028),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2029),
    L2(250, 0, 0, 0, 0, 0, 0, 0x202B),
    L2(250, 0, 0, 0, 0, 0, 0, 0x206E),
    L2(250, 0, 0, 0, 0, 0, 0, 0x202C),
    L2(250, 0, 0, 0, 0, 0, 0, 0x202D),
    L2(250, 0, 0, 0, 0, 0, 0, 0x202D),
    L2(250, 0, 0, 0, 0, 0, 0, 0x202E),
    CMD(CM_RMJA, 3, 40, 35),
    L2(250, 9, 0, 0, 0, 0, 0, 0x202E),
    CMD(CM_MDAT, 1, 28, 1),
    CMD(CM_JMP, 6, 132, 2),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 41 HUGO S D B B */
const u16 necro_cuca_041_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 necro_cuca_041[88] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FC0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2040),
    L2(250, 0, 0, 0, 0, 0, 0, 0x207C),
    L2(250, 0, 0, 0, 0, 0, 0, 0x206B),
    L2(250, 0, 0, 0, 0, 0, 0, 0x202A),
    L2(250, 0, 0, 0, 0, 0, 0, 0x202D),
    L2(250, 0, 0, 0, 0, 0, 0, 0x202B),
    L2(250, 0, 0, 0, 0, 0, 0, 0x202B),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2027),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2028),
    L2(250, 0, 0, 0, 0, 0, 0, 0x202B),
    L2(250, 0, 0, 0, 0, 0, 0, 0x202B),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2033),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2032),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2034),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2033),
    CMD(CM_RMJA, 3, 41, 19),
    L2(250, 9, 0, 0, 0, 0, 0, 0x2036),
    CMD(CM_MDAT, 1, 18, 2),
    CMD(CM_RJA, 1, 60, 2),
    CMD(CM_JMP, 6, 13, 5),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 42 no name */
const u16 necro_cuca_042_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 necro_cuca_042[48] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FCF),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2030),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FC6),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2040),
    L2(250, 0, 0, 0, 0, 0, 0, 0x207B),
    L2(250, 0, 0, 0, 0, 0, 0, 0x207C),
    CMD(CM_RMJA, 3, 42, 9),
    L2(250, 9, 0, 0, 0, 0, 0, 0x1FE4),
    CMD(CM_MDAT, 1, 30, 2),
    CMD(CM_RJA, 7, 7, 1),
    CMD(CM_JMP, 6, 16, 3),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 43 no name */
const u16 necro_cuca_043_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 necro_cuca_043[32] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FE8),
    L2(250, 0, 0, 0, 0, 0, 0, 0x202D),
    CMD(CM_RMJA, 3, 43, 5),
    L2(250, 9, 0, 0, 0, 0, 0, 0x202D),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_RJA, 1, 96, 1),
    CMD(CM_JMP, 6, 84, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 44 no name */
const u16 necro_cuca_044_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 necro_cuca_044[212] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FC6),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FC1),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FCF),
    L2(250, 0, 0, 0, 1, 0, 0, 0x1FC7),
    L2(250, 0, 0, 0, 1, 0, 0, 0x1FC6),
    L2(250, 0, 0, 0, 1, 0, 0, 0x2030),
    L2(250, 0, 0, 0, 1, 0, 0, 0x1FC0),
    L2(250, 0, 0, 0, 1, 0, 0, 0x1F03),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1F02),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FC6),
    L2(250, 0, 0, 0, 1, 0, 0, 0x1FC6),
    L2(250, 0, 0, 0, 1, 0, 0, 0x1FC7),
    L2(250, 0, 0, 0, 1, 0, 0, 0x2042),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1F02),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FC7),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2040),
    L2(250, 0, 0, 0, 3, 0, 0, 0x203E),
    L2(250, 0, 0, 0, 3, 0, 0, 0x2035),
    L2(250, 0, 0, 0, 3, 0, 0, 0x2033),
    L2(250, 0, 0, 0, 3, 0, 0, 0x2049),
    L2(250, 0, 0, 0, 3, 0, 0, 0x1FE8),
    L2(250, 0, 0, 0, 0, 0, 0, 0x203D),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2004),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2003),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2028),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2029),
    L2(250, 0, 0, 0, 0, 0, 0, 0x202B),
    L2(250, 0, 0, 0, 0, 0, 0, 0x206E),
    L2(250, 0, 0, 0, 0, 0, 0, 0x202C),
    L2(250, 0, 0, 0, 0, 0, 0, 0x202D),
    L2(250, 0, 0, 0, 0, 0, 0, 0x202D),
    L2(250, 0, 0, 0, 0, 0, 0, 0x202E),
    L2(250, 0, 0, 0, 0, 0, 0, 0x207C),
    L2(250, 0, 0, 0, 0, 0, 0, 0x206B),
    L2(250, 0, 0, 0, 0, 0, 0, 0x202A),
    L2(250, 0, 0, 0, 0, 0, 0, 0x202D),
    L2(250, 0, 0, 0, 0, 0, 0, 0x202B),
    L2(250, 0, 0, 0, 0, 0, 0, 0x202B),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2027),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2028),
    L2(250, 0, 0, 0, 0, 0, 0, 0x202B),
    L2(250, 0, 0, 0, 0, 0, 0, 0x202B),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2033),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2032),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2034),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2033),
    L2(250, 0, 0, 0, 3, 0, 0, 0x206F),
    L2(250, 0, 0, 0, 3, 0, 0, 0x2036),
    CMD(CM_RMJA, 3, 44, 51),
    L2(250, 9, 0, 0, 0, 0, 0, 0x202E),
    CMD(CM_MDAT, 1, 28, 1),
    CMD(CM_JMP, 6, 132, 2),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 45 no name */
const u16 necro_cuca_045_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 necro_cuca_045[36] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FDC),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FE0),
    CMD(CM_RMJA, 3, 45, 7),
    L2(250, 9, 0, 0, 0, 0, 0, 0x1FE0),
    CMD(CM_MDAT, 1, 12, 1),
    CMD(CM_JMP, 1, 26, 1),
    CMD(CM_MDAT, 1, 24, 2),
    CMD(CM_JMP, 1, 73, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 46 no name */
const u16 necro_cuca_046_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 necro_cuca_046[84] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FC7),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2040),
    L2(250, 0, 0, 0, 3, 0, 0, 0x203E),
    L2(250, 0, 0, 0, 3, 0, 0, 0x2035),
    L2(250, 0, 0, 0, 3, 0, 0, 0x2033),
    L2(250, 0, 0, 0, 3, 0, 0, 0x2049),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2035),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2033),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2049),
    L2(250, 0, 0, 0, 0, 0, 0, 0x1FE8),
    L2(250, 0, 0, 0, 3, 0, 0, 0x203D),
    L2(250, 0, 0, 0, 3, 0, 0, 0x1FE8),
    L2(250, 0, 0, 0, 0, 0, 0, 0x203D),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2004),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2003),
    CMD(CM_RMJA, 3, 46, 18),
    L2(250, 9, 0, 0, 0, 0, 0, 0x2028),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_RJA, 1, 97, 1),
    CMD(CM_JMP, 6, 84, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 47 no name */
const u16 necro_cuca_047_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 necro_cuca_047[124] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x2067),
    L2(250, 0, 0, 0, 1, 0, 0, 0x1ED1),
    L2(250, 0, 0, 0, 1, 0, 0, 0x1ED1),
    L2(250, 0, 0, 0, 1, 0, 0, 0x1ED2),
    L2(250, 0, 0, 0, 1, 0, 0, 0x1ED3),
    L2(250, 0, 0, 0, 1, 0, 0, 0x1ED6),
    L2(250, 0, 0, 0, 1, 0, 0, 0x207A),
    L2(250, 0, 0, 0, 1, 0, 0, 0x207A),
    L2(250, 0, 0, 0, 1, 0, 0, 0x20D3),
    L2(250, 0, 0, 0, 1, 0, 0, 0x20D4),
    L2(250, 0, 0, 0, 1, 0, 0, 0x206B),
    L2(250, 0, 0, 0, 1, 0, 0, 0x2036),
    L2(250, 0, 0, 0, 1, 0, 0, 0x203A),
    L2(250, 0, 0, 0, 1, 0, 0, 0x203B),
    L2(250, 0, 0, 0, 2, 0, 0, 0x207B),
    L2(250, 0, 0, 0, 2, 0, 0, 0x207C),
    L2(250, 0, 0, 0, 2, 0, 0, 0x206B),
    L2(250, 0, 0, 0, 0, 0, 0, 0x203B),
    L2(250, 0, 0, 0, 0, 0, 0, 0x217B),
    L2(250, 0, 0, 0, 3, 0, 0, 0x2178),
    L2(250, 0, 0, 0, 3, 0, 0, 0x206F),
    L2(250, 0, 0, 0, 3, 0, 0, 0x206F),
    L2(250, 0, 0, 0, 1, 0, 0, 0x2036),
    L2(250, 0, 0, 0, 1, 0, 0, 0x2038),
    CMD(CM_RMJA, 3, 47, 29),
    L2(250, 9, 0, 0, 1, 0, 0, 0x2038),
    CMD(CM_MDAT, 1, 14, 2),
    CMD(CM_JMP, 7, 5, 1),
    CMD(CM_MDAT, 1, 14, 2),
    CMD(CM_JMP, 7, 5, 1),
    CMD(CM_ROA, 0, 0, 0),
};

extern const u16 necro_atca_000[], necro_atca_002[], necro_atca_003[], necro_atca_005[], necro_atca_006[], necro_atca_009[], necro_atca_011[], necro_atca_012[], necro_atca_014[], necro_atca_015[], necro_atca_017[], necro_atca_018[], necro_atca_021[], necro_atca_024[], necro_atca_026[], necro_atca_027[], necro_atca_030[], necro_atca_033[], necro_atca_036[], necro_atca_038[], necro_atca_040[], necro_atca_042[], necro_atca_043[], necro_atca_044[], necro_atca_046[], necro_atca_048[], necro_atca_050[], necro_atca_052[], necro_atca_054[], necro_atca_055[], necro_atca_056[], necro_atca_058[], necro_atca_060[], necro_atca_062[], necro_atca_064[], necro_atca_066[], necro_atca_067[], necro_atca_068[], necro_atca_070[], necro_atca_072[], necro_atca_074[], necro_atca_076[], necro_atca_078[], necro_atca_079[], necro_atca_080[], necro_atca_082[], necro_atca_084[], necro_atca_086[], necro_atca_088[], necro_atca_090[], necro_atca_091[], necro_atca_092[], necro_atca_094[], necro_atca_096[], necro_atca_098[], necro_atca_100[], necro_atca_102[], necro_atca_103[], necro_atca_104[], necro_atca_106[], necro_atca_108[], necro_atca_110[], necro_atca_112[], necro_atca_114[], necro_atca_116[], necro_atca_118[], necro_atca_144[], necro_atca_145[], necro_atca_156[], necro_atca_157[];

/* atca scripts (debug viewer: ATTACK): 158 entries */
const u32 necro_atca[159] = {
    (u32)necro_atca_000,  /* 0 S PUNCH A */
    (u32)necro_atca_000,  /* 1 S PUNCH B */
    (u32)necro_atca_002,  /* 2 S PUNCH C */
    (u32)necro_atca_003,  /* 3 M PUNCH A */
    (u32)necro_atca_003,  /* 4 M PUNCH B */
    (u32)necro_atca_005,  /* 5 M PUNCH C */
    (u32)necro_atca_006,  /* 6 L PUNCH A */
    (u32)necro_atca_006,  /* 7 L PUNCH B */
    (u32)necro_atca_006,  /* 8 L PUNCH C */
    (u32)necro_atca_009,  /* 9 S KICK A */
    (u32)necro_atca_009,  /* 10 S KICK B */
    (u32)necro_atca_011,  /* 11 S KICK C */
    (u32)necro_atca_012,  /* 12 M KICK A */
    (u32)necro_atca_012,  /* 13 M KICK B */
    (u32)necro_atca_014,  /* 14 M KICK C */
    (u32)necro_atca_015,  /* 15 L KICK A */
    (u32)necro_atca_015,  /* 16 L KICK B */
    (u32)necro_atca_017,  /* 17 L KICK C */
    (u32)necro_atca_018,  /* 18 KAGAMI P A */
    (u32)necro_atca_018,  /* 19 KAGAMI P B */
    (u32)necro_atca_018,  /* 20 KAGAMI P C */
    (u32)necro_atca_021,  /* 21 KAGAMI P A */
    (u32)necro_atca_021,  /* 22 KAGAMI P B */
    (u32)necro_atca_021,  /* 23 KAGAMI P C */
    (u32)necro_atca_024,  /* 24 KAGAMI P A */
    (u32)necro_atca_024,  /* 25 KAGAMI P B */
    (u32)necro_atca_026,  /* 26 KAGAMI P C */
    (u32)necro_atca_027,  /* 27 KAGAMI K A */
    (u32)necro_atca_027,  /* 28 KAGAMI K B */
    (u32)necro_atca_027,  /* 29 KAGAMI K C */
    (u32)necro_atca_030,  /* 30 KAGAMI K A */
    (u32)necro_atca_030,  /* 31 KAGAMI K B */
    (u32)necro_atca_030,  /* 32 KAGAMI K C */
    (u32)necro_atca_033,  /* 33 KAGAMI K A */
    (u32)necro_atca_033,  /* 34 KAGAMI K B */
    (u32)necro_atca_033,  /* 35 KAGAMI K C */
    (u32)necro_atca_036,  /* 36 V JUMP P S A */
    (u32)necro_atca_036,  /* 37 V JUMP P S B */
    (u32)necro_atca_038,  /* 38 V JUMP P M A */
    (u32)necro_atca_038,  /* 39 V JUMP P M B */
    (u32)necro_atca_040,  /* 40 V JUMP P L A */
    (u32)necro_atca_040,  /* 41 V JUMP P L B */
    (u32)necro_atca_042,  /* 42 V JUMP K S A */
    (u32)necro_atca_043,  /* 43 V JUMP K S B */
    (u32)necro_atca_044,  /* 44 V JUMP K M A */
    (u32)necro_atca_044,  /* 45 V JUMP K M B */
    (u32)necro_atca_046,  /* 46 V JUMP K L A */
    (u32)necro_atca_046,  /* 47 V JUMP K L B */
    (u32)necro_atca_048,  /* 48 F JUMP P S A */
    (u32)necro_atca_048,  /* 49 F JUMP P S B */
    (u32)necro_atca_050,  /* 50 F JUMP P M A */
    (u32)necro_atca_050,  /* 51 F JUMP P M B */
    (u32)necro_atca_052,  /* 52 F JUMP P L A */
    (u32)necro_atca_052,  /* 53 F JUMP P L B */
    (u32)necro_atca_054,  /* 54 F JUMP K S A */
    (u32)necro_atca_055,  /* 55 F JUMP K S B */
    (u32)necro_atca_056,  /* 56 F JUMP K M A */
    (u32)necro_atca_056,  /* 57 F JUMP K M B */
    (u32)necro_atca_058,  /* 58 F JUMP K L A */
    (u32)necro_atca_058,  /* 59 F JUMP K L B */
    (u32)necro_atca_060,  /* 60 B JUMP P S A */
    (u32)necro_atca_060,  /* 61 B JUMP P S B */
    (u32)necro_atca_062,  /* 62 B JUMP P M A */
    (u32)necro_atca_062,  /* 63 B JUMP P M B */
    (u32)necro_atca_064,  /* 64 B JUMP P L A */
    (u32)necro_atca_064,  /* 65 B JUMP P L B */
    (u32)necro_atca_066,  /* 66 B JUMP K S A */
    (u32)necro_atca_067,  /* 67 B JUMP K S B */
    (u32)necro_atca_068,  /* 68 B JUMP K M A */
    (u32)necro_atca_068,  /* 69 B JUMP K M B */
    (u32)necro_atca_070,  /* 70 B JUMP K L A */
    (u32)necro_atca_070,  /* 71 B JUMP K L B */
    (u32)necro_atca_072,  /* 72 SP V JP S P A */
    (u32)necro_atca_072,  /* 73 SP V JP S P B */
    (u32)necro_atca_074,  /* 74 SP V JP M P A */
    (u32)necro_atca_074,  /* 75 SP V JP M P B */
    (u32)necro_atca_076,  /* 76 SP V JP L P A */
    (u32)necro_atca_076,  /* 77 SP V JP L P B */
    (u32)necro_atca_078,  /* 78 SP V JP S K A */
    (u32)necro_atca_079,  /* 79 SP V JP S K B */
    (u32)necro_atca_080,  /* 80 SP V JP M K A */
    (u32)necro_atca_080,  /* 81 SP V JP M K B */
    (u32)necro_atca_082,  /* 82 SP V JP L K A */
    (u32)necro_atca_082,  /* 83 SP V JP L K B */
    (u32)necro_atca_084,  /* 84 SP F JP S P A */
    (u32)necro_atca_084,  /* 85 SP F JP S P B */
    (u32)necro_atca_086,  /* 86 SP F JP M P A */
    (u32)necro_atca_086,  /* 87 SP F JP M P B */
    (u32)necro_atca_088,  /* 88 SP F JP L P A */
    (u32)necro_atca_088,  /* 89 SP F JP L P B */
    (u32)necro_atca_090,  /* 90 SP F JP S K A */
    (u32)necro_atca_091,  /* 91 SP F JP S K B */
    (u32)necro_atca_092,  /* 92 SP F JP M K A */
    (u32)necro_atca_092,  /* 93 SP F JP M K B */
    (u32)necro_atca_094,  /* 94 SP F JP L K A */
    (u32)necro_atca_094,  /* 95 SP F JP L K B */
    (u32)necro_atca_096,  /* 96 SP B JP S P A */
    (u32)necro_atca_096,  /* 97 SP B JP S P B */
    (u32)necro_atca_098,  /* 98 SP B JP M P A */
    (u32)necro_atca_098,  /* 99 SP B JP M P B */
    (u32)necro_atca_100,  /* 100 SP B JP L P A */
    (u32)necro_atca_100,  /* 101 SP B JP L P B */
    (u32)necro_atca_102,  /* 102 SP B JP S K A */
    (u32)necro_atca_103,  /* 103 SP B JP S K B */
    (u32)necro_atca_104,  /* 104 SP B JP M K A */
    (u32)necro_atca_104,  /* 105 SP B JP M K B */
    (u32)necro_atca_106,  /* 106 SP B JP L K A */
    (u32)necro_atca_106,  /* 107 SP B JP L K B */
    (u32)necro_atca_108,  /* 108 S V JP S P A */
    (u32)necro_atca_108,  /* 109 S V JP S P B */
    (u32)necro_atca_110,  /* 110 S V JP M P A */
    (u32)necro_atca_110,  /* 111 S V JP M P B */
    (u32)necro_atca_112,  /* 112 S V JP L P A */
    (u32)necro_atca_112,  /* 113 S V JP L P B */
    (u32)necro_atca_114,  /* 114 S V JP S K A */
    (u32)necro_atca_114,  /* 115 S V JP S K B */
    (u32)necro_atca_116,  /* 116 S V JP M K A */
    (u32)necro_atca_116,  /* 117 S V JP M K B */
    (u32)necro_atca_118,  /* 118 S V JP L K A */
    (u32)necro_atca_118,  /* 119 S V JP L K B */
    (u32)necro_atca_108,  /* 120 S F JP S P A */
    (u32)necro_atca_108,  /* 121 S F JP S P B */
    (u32)necro_atca_110,  /* 122 S F JP M P A */
    (u32)necro_atca_110,  /* 123 S F JP M P B */
    (u32)necro_atca_112,  /* 124 S F JP L P A */
    (u32)necro_atca_112,  /* 125 S F JP L P B */
    (u32)necro_atca_114,  /* 126 S F JP S K A */
    (u32)necro_atca_114,  /* 127 S F JP S K B */
    (u32)necro_atca_116,  /* 128 S F JP M K A */
    (u32)necro_atca_116,  /* 129 S F JP M K B */
    (u32)necro_atca_118,  /* 130 S F JP L K A */
    (u32)necro_atca_118,  /* 131 S F JP L K B */
    (u32)necro_atca_108,  /* 132 S B JP S P A */
    (u32)necro_atca_108,  /* 133 S B JP S P B */
    (u32)necro_atca_110,  /* 134 S B JP M P A */
    (u32)necro_atca_110,  /* 135 S B JP M P B */
    (u32)necro_atca_112,  /* 136 S B JP L P A */
    (u32)necro_atca_112,  /* 137 S B JP L P B */
    (u32)necro_atca_114,  /* 138 S B JP S K A */
    (u32)necro_atca_114,  /* 139 S B JP S K B */
    (u32)necro_atca_116,  /* 140 S B JP M K A */
    (u32)necro_atca_116,  /* 141 S B JP M K B */
    (u32)necro_atca_118,  /* 142 S B JP L K A */
    (u32)necro_atca_118,  /* 143 S B JP L K B */
    (u32)necro_atca_144,  /* 144 TUKAMIKAKARI A */
    (u32)necro_atca_145,  /* 145 TUKAMIKAKARI B */
    (u32)necro_atca_144,  /* 146 TUKAMIKAKARI C */
    (u32)necro_atca_144,  /* 147 TUKAMIKAKARI D */
    (u32)necro_atca_145,  /* 148 TUKAMIKAKARI E */
    (u32)necro_atca_144,  /* 149 TUKAMIKAKARI F */
    (u32)necro_atca_048,  /* 150 TUKAMI AIR A */
    (u32)necro_atca_048,  /* 151 TUKAMI AIR B */
    (u32)necro_atca_048,  /* 152 TUKAMI AIR C */
    (u32)necro_atca_048,  /* 153 TUKAMI AIR D */
    (u32)necro_atca_048,  /* 154 TUKAMI AIR E */
    (u32)necro_atca_048,  /* 155 TUKAMI AIR F */
    (u32)necro_atca_156,  /* 156 follow-up of S KICK A / S KICK C */
    (u32)necro_atca_157,  /* 157 follow-up of follow-up of S KICK A / S KICK C */
    0
};

/* script: 0 S PUNCH A, 1 S PUNCH B */
const u16 necro_atca_000_head[4] = { HEAD(6, 0, 0, 16, 0, 1, 0) };
const u16 necro_atca_000[172] = {
    L6(1, 0, 0, 0, 0, 0, 0, 0x1E80, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 268, 0, 0, 0, 0, 0x1E81, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1E82, 0, 18, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1E82, -2, 17, 0, 0, 96, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x1E83, 0, 18, 0, 0, 96, 21, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1E84, 0, 131, 0, 0, 64, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1E85, 0, 131, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 64, 0, 0, 0, 0, 0, 0x1E86, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1E87, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1E88, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1E3B, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1E3C, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1E3D, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x1E3D, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 2 S PUNCH C */
const u16 necro_atca_002_head[4] = { HEAD(6, 0, 0, 11, 0, 1, 0) };
const u16 necro_atca_002[208] = {
    L6(1, 0, 0, 0, 0, 0, 0, 0x1EA7, 0, 12, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 268, 0, 0, 0, 0, 0x1EA8, 0, 12, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1EAA, 0, 14, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1EAA, -1, 13, 0, 0, 96, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x1EAA, 0, 14, 0, 0, 96, 21, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1EAB, 0, 15, 0, 0, 64, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 64, 0, 0, 0, 0, 0, 0x1EAC, 0, 15, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1EAD, 0, 12, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1EAE, 0, 12, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1EAF, 0, 16, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1EB0, 0, 16, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1EB1, 0, 16, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1E88, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1E3B, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1E3C, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1E3D, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x1E3D, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 3 M PUNCH A, 4 M PUNCH B */
const u16 necro_atca_003_head[4] = { HEAD(6, 0, 2, 14, 0, 1, 0) };
const u16 necro_atca_003[244] = {
    CMD(CM_RJA7, 4, 3, 4), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_JSR, 8, 10, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(1, 0, 0, 0, 0, 0, 0, 0x1E80, -33, 121, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x1E89, 0, 1, 0, 0, 0, 0, 0, 0, 0, 24, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1E8A, 0, 19, 0, 0, 0, 0, 0, 0, 0, 26, 0, 0),
    L6(1, 0, 269, 0, 0, 0, 0, 0x1E8B, 0, 19, 0, 0, 32, 0, 0, 0, 0, 26, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1E8C, 0, 165, 0, 0, 0, 0, 0, 0, 0, 28, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1E8D, -3, 20, 0, 0, 96, 0, 0, 0, 0, 30, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1E8D, 0, 165, 0, 0, 96, 21, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x1ECE, 0, 21, 0, 0, 64, 0, 0, 0, 0, 32, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1E8F, 0, 19, 0, 0, 0, 0, 0, 0, 0, 32, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1E90, 0, 19, 0, 0, 0, 0, 0, 0, 0, 34, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1E91, 0, 19, 0, 0, 0, 0, 0, 0, 0, 34, 0, 0),
    L6(2, 64, 0, 0, 0, 0, 0, 0x1E92, 0, 19, 0, 0, 0, 0, 0, 0, 0, 36, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1E93, 0, 1, 0, 0, 0, 0, 0, 0, 0, 38, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1E94, 0, 1, 0, 0, 0, 0, 0, 0, 0, 38, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1E3B, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1E3C, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1E3D, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x1E3D, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 5 M PUNCH C */
const u16 necro_atca_005_head[4] = { HEAD(6, 0, 2, 13, 0, 1, 0) };
const u16 necro_atca_005[232] = {
    CMD(CM_RJA7, 4, 5, 4), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_JSR, 8, 10, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(1, 0, 0, 0, 0, 0, 0, 0x1EA7, -33, 121, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 269, 0, 0, 0, 0, 0x1EA8, 0, 126, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1EA9, 0, 128, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1EA9, -54, 127, 0, 0, 96, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x1EAA, 0, 128, 0, 0, 96, 21, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1EAB, 0, 129, 0, 0, 64, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1EAC, 3, 129, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 64, 0, 0, 0, 0, 0, 0x1EAD, 0, 126, 0, 0, 96, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1EAE, 0, 126, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1EAF, 0, 130, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1EB0, 0, 130, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1EB1, 0, 130, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1E88, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1E3B, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1E3C, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1E3D, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x1E3D, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 6 L PUNCH A, 7 L PUNCH B, 8 L PUNCH C */
const u16 necro_atca_006_head[4] = { HEAD(6, 0, 4, 19, 0, 1, 0) };
const u16 necro_atca_006[304] = {
    CMD(CM_RJA7, 4, 7, 4), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_JSR, 8, 10, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(1, 0, 0, 0, 0, 0, 0, 0x1E95, -33, 157, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x1E96, 0, 30, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x1E97, 0, 30, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 496, 0, 0, 0, 0, 0x1E98, 0, 30, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1E99, 0, 30, 0, 0, 0, 0, 0, 0, 0, 60, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1E9A, 0, 31, 0, 0, 0, 0, 0, 0, 0, 62, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1E9B, 0, 32, 0, 0, 0, 0, 0, 0, 0, 62, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1E9C, 0, 32, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 270, 0, 0, 0, 0, 0x1E9D, 0, 32, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1E9E, 0, 35, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1E9E, -5, 34, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x1E9F, 0, 35, 0, 0, 0, 21, 0, 0, 0, 64, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1EA0, 0, 35, 0, 0, 0, 0, 0, 0, 0, 64, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1EA0, 0, 35, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1EA1, 0, 35, 0, 0, 0, 0, 0, 0, 0, 64, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1EA2, 0, 33, 0, 0, 0, 0, 0, 0, 0, 64, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1EA3, 0, 33, 0, 0, 0, 0, 0, 0, 0, 64, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1EA4, 0, 32, 0, 0, 0, 0, 0, 0, 0, 64, 0, 0),
    L6(2, 64, 0, 0, 0, 0, 0, 0x1EA5, 0, 1, 0, 0, 0, 0, 0, 0, 0, 64, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1EA6, 0, 1, 0, 0, 0, 0, 0, 0, 0, 64, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1E3C, 0, 1, 0, 0, 0, 0, 0, 0, 0, 64, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1E3D, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x1E3D, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 9 S KICK A, 10 S KICK B */
const u16 necro_atca_009_head[4] = { HEAD(4, 0, 1, 12, 0, 1, 0) };
const u16 necro_atca_009[108] = {
    CMD(CM_RMJA, 4, 156, 1), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 0, 0, 0x1ED1, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1ED2, 0, 38, 0, 0, 0, 0, 0),
    L4(1, 0, 268, 0, 0, 0, 0, 0x1ED3, 0, 38, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1ED4, 0, 40, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1ED4, -7, 39, 0, 135, 96, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1ED5, 0, 40, 2213, 0, 104, 21, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1ED6, 0, 38, 2213, 0, 72, 0, 0),
    L4(2, 64, 0, 0, 0, 0, 0, 0x1ED1, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1E3B, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1E3C, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1E3D, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x1E3D, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 11 S KICK C */
const u16 necro_atca_011_head[4] = { HEAD(4, 0, 1, 10, 0, 1, 0) };
const u16 necro_atca_011[108] = {
    CMD(CM_RMJA, 4, 156, 1), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x21C0, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 268, 0, 0, 0, 0, 0x21C1, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x21C2, -6, 36, 0, 128, 96, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x21C3, 0, 37, 2213, 0, 104, 21, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x21C4, 0, 1, 2213, 0, 120, 0, 2),
    L4(2, 0, 0, 0, 0, 0, 0, 0x21C5, 0, 1, 0, 0, 16, 0, 2),
    L4(1, 0, 0, 0, 0, 0, 0, 0x21C6, 0, 1, 0, 0, 16, 0, 2),
    L4(2, 64, 0, 0, 0, 0, 0, 0x21C7, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1E3B, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1E3C, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1E3D, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x1E3D, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 12 M KICK A, 13 M KICK B */
const u16 necro_atca_012_head[4] = { HEAD(6, 0, 3, 17, 0, 1, 0) };
const u16 necro_atca_012[172] = {
    CMD(CM_RJA7, 4, 12, 4), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_JSR, 8, 11, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(1, 0, 0, 0, 0, 0, 0, 0x1ED7, -47, 121, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x1ED8, 0, 187, 0, 0, 0, 0, 0, 0, 0, 72, 0, 0),
    L6(2, 0, 269, 0, 0, 0, 0, 0x1ED9, 0, 187, 0, 0, 0, 0, 0, 0, 0, 72, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1EDA, 0, 45, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1EDA, -9, 44, 0, 128, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x1EDB, 0, 45, 0, 0, 0, 21, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x1EDC, 0, 45, 0, 0, 0, 0, 0, 0, 0, 74, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1EDD, 0, 45, 0, 0, 0, 0, 0, 0, 0, 74, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1EDE, 0, 1, 0, 0, 0, 0, 0, 0, 0, 76, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1E3B, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 64, 0, 0, 0, 0, 0, 0x1E3D, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x1E3D, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 14 M KICK C */
const u16 necro_atca_014_head[4] = { HEAD(6, 0, 3, 10, 0, 1, 0) };
const u16 necro_atca_014[208] = {
    CMD(CM_RJA7, 4, 14, 4), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_JSR, 8, 11, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(1, 0, 0, 0, 0, 0, 0, 0x1EF9, -47, 121, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1EFA, 0, 1, 0, 0, 0, 0, 0, 0, 0, 66, 0, 0),
    L6(1, 0, 269, 0, 0, 0, 0, 0x1EFB, 0, 41, 0, 0, 0, 0, 0, 0, 0, 66, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1EFC, 0, 43, 0, 0, 0, 0, 0, 0, 0, 68, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1EFC, -8, 42, 0, 136, 96, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x1EFD, 0, 43, 0, 0, 96, 21, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1EFE, 0, 43, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1EFF, 0, 41, 0, 0, 0, 0, 0, 0, 0, 70, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1F00, 0, 41, 0, 0, 96, 0, 0, 0, 0, 70, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1F01, 0, 1, 0, 0, 0, 0, 0, 0, 0, 70, 0, 0),
    L6(1, 64, 0, 0, 0, 0, 0, 0x1E88, 0, 1, 0, 0, 0, 0, 0, 0, 0, 70, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1E3B, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1E3C, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1E3D, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x1E3D, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 15 L KICK A, 16 L KICK B */
const u16 necro_atca_015_head[4] = { HEAD(6, 0, 5, 17, 0, 1, 0) };
const u16 necro_atca_015[340] = {
    CMD(CM_RJA7, 4, 16, 4), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_JSR, 8, 11, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(1, 0, 0, 0, 0, 0, 0, 0x1EDF, -47, 157, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1EE0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1EE1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1EE2, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1EE3, 0, 50, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1EE4, 0, 50, 0, 0, 0, 0, 0, 0, 0, 84, 0, 0),
    L6(1, 0, 498, 0, 0, 0, 0, 0x1EE5, 0, 50, 0, 0, 0, 0, 0, 0, 0, 84, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1EE6, 0, 50, 0, 0, 0, 0, 0, 0, 0, 84, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1EE7, 0, 50, 0, 0, 0, 0, 0, 0, 0, 84, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1EE8, 0, 51, 0, 0, 0, 0, 0, 0, 0, 84, 0, 0),
    L6(1, 0, 270, 0, 0, 0, 0, 0x1EE9, 0, 52, 0, 143, 0, 0, 0, 0, 0, 86, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1EEA, 0, 54, 0, 0, 0, 0, 0, 0, 0, 88, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1EEA, -11, 53, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x1EEA, 0, 54, 0, 0, 0, 21, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x1EEB, 0, 54, 0, 0, 0, 0, 0, 0, 0, 90, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x1EEC, 0, 54, 0, 0, 0, 0, 0, 0, 0, 92, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1EED, 0, 55, 0, 0, 0, 0, 0, 0, 0, 94, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1EEE, 0, 55, 0, 0, 0, 0, 0, 0, 0, 92, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1EEF, 0, 55, 0, 0, 0, 0, 0, 0, 0, 92, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1EF0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 96, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1EF1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 96, 0, 0),
    L6(1, 64, 0, 0, 0, 0, 0, 0x1E88, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1E3B, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1E3C, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1E3D, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x1E3D, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 17 L KICK C */
const u16 necro_atca_017_head[4] = { HEAD(6, 0, 5, 10, 0, 1, 0) };
const u16 necro_atca_017[280] = {
    CMD(CM_RJA7, 4, 17, 4), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_JSR, 8, 11, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(1, 0, 0, 0, 0, 0, 0, 0x1F02, -47, 157, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1F03, 0, 1, 0, 0, 0, 21, 0, 0, 0, 78, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1F04, 0, 46, 0, 0, 0, 0, 0, 0, 0, 80, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1F05, 0, 46, 0, 0, 0, 0, 0, 0, 0, 80, 0, 0),
    L6(1, 0, 496, 0, 0, 0, 0, 0x1F06, 0, 46, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1F07, 0, 46, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1F08, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1F09, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1F0A, 0, 47, 0, 0, 0, 33, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 270, 0, 0, 0, 0, 0x1F0B, 0, 47, 0, 0, 0, 0, 0, 0, 0, 82, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1F0C, 0, 49, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1F0C, -10, 48, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x1F0C, 0, 49, 0, 0, 0, 21, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x1F0E, 0, 49, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1F0F, 0, 49, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1F11, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1F12, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1F13, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1E3B, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1E3D, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x1E3D, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 18 KAGAMI P A, 19 KAGAMI P B, 20 KAGAMI P C */
const u16 necro_atca_018_head[4] = { HEAD(4, 32, 0, 15, 0, 1, 0) };
const u16 necro_atca_018[100] = {
    L4(2, 0, 0, 0, 0, 0, 0, 0x1F17, 0, 2, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1F18, 0, 56, 0, 0, 0, 0, 0),
    L4(1, 0, 268, 0, 0, 0, 0, 0x1F19, 0, 56, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1F1A, 0, 58, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1F1A, -12, 57, 0, 0, 96, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1F1B, 0, 58, 0, 0, 64, 21, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1F1C, 0, 132, 0, 0, 96, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1F1D, 0, 132, 0, 0, 0, 0, 0),
    L4(1, 64, 0, 0, 0, 0, 0, 0x1E22, 0, 2, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1E23, 0, 2, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1E24, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x1E24, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 21 KAGAMI P A, 22 KAGAMI P B, 23 KAGAMI P C */
const u16 necro_atca_021_head[4] = { HEAD(4, 32, 2, 15, 0, 1, 0) };
const u16 necro_atca_021[172] = {
    L4(1, 0, 0, 0, 0, 0, 0, 0x1F17, 0, 2, 0, 0, 0, 21, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1F21, 0, 2, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1F22, 0, 56, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1F23, 0, 56, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1F24, 0, 56, 0, 0, 0, 0, 0),
    L4(1, 0, 269, 0, 0, 0, 0, 0x1F25, 0, 56, 0, 0, 0, 33, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1F26, 0, 60, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1F27, -13, 59, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1F27, 0, 60, 0, 0, 0, 21, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1F28, 0, 60, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1F29, 0, 60, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1F2A, 0, 60, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1F2B, 0, 60, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1F2C, 0, 61, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1F2D, 0, 61, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1F2E, 0, 61, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1F2F, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 64, 0, 0, 0, 0, 0, 0x1F30, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1E23, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1E24, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x1E24, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 24 KAGAMI P A, 25 KAGAMI P B */
const u16 necro_atca_024_head[4] = { HEAD(4, 32, 4, 16, 0, 1, 0) };
const u16 necro_atca_024[180] = {
    L4(1, 0, 0, 0, 0, 0, 0, 0x1F31, 0, 2, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1F32, 0, 62, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1F33, 0, 62, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1F34, 0, 63, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1F35, 0, 63, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1F36, 0, 64, 0, 0, 0, 0, 0),
    L4(1, 0, 270, 0, 0, 0, 0, 0x1F37, 0, 65, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1F38, 0, 67, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1F38, -14, 66, 0, 138, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x1F39, 0, 67, 0, 0, 0, 21, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1F3A, 0, 139, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1F3B, 0, 68, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1F3C, 0, 68, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1F3D, 0, 68, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1F3E, 0, 2, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1F3F, 0, 2, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1F40, 0, 2, 0, 0, 0, 0, 0),
    L4(1, 64, 0, 0, 0, 0, 0, 0x1F41, 0, 2, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1E22, 0, 2, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1E23, 0, 2, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1E24, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x1E24, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 26 KAGAMI P C */
const u16 necro_atca_026_head[4] = { HEAD(6, 0, 4, 8, 0, 1, 0) };
const u16 necro_atca_026[304] = {
    L6(1, 0, 0, 0, 0, 0, 0, 0x1EB2, 0, 22, 0, 0, 0, 0, 0, 0, 0, 40, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1EB3, 0, 22, 0, 0, 0, 0, 0, 0, 0, 42, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1EB4, 0, 23, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1EB5, 0, 23, 0, 0, 0, 0, 0, 0, 0, 44, 0, 0),
    L6(2, 0, 498, 0, 0, 0, 0, 0x1EB6, 0, 24, 0, 0, 0, 0, 0, 0, 0, 46, 0, 0),
    L6(2, 0, 270, 0, 0, 0, 0, 0x1EB7, 0, 25, 0, 0, 0, 0, 0, 0, 0, 48, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1EB8, 0, 25, 0, 0, 0, 0, 0, 0, 0, 50, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1EB8, -4, 83, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1EB9, 0, 186, 0, 128, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1EBA, 0, 160, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(5, 0, 0, 0, 0, 0, 0, 0x1EBA, 0, 156, 0, 0, 0, 21, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x1EBB, 0, 156, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x1EBC, 0, 27, 0, 0, 0, 0, 0, 0, 0, 52, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x1EBD, 0, 28, 0, 0, 0, 0, 0, 0, 0, 52, 0, 0),
    L6(2, 64, 0, 0, 0, 0, 0, 0x1EBE, 0, 28, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1EBF, 0, 29, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1ECF, 0, 29, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1EC0, 0, 29, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1EC1, 0, 29, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1EC2, 0, 29, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1E88, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1E3B, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1E3C, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1E3D, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x1E3D, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 27 KAGAMI K A, 28 KAGAMI K B, 29 KAGAMI K C */
const u16 necro_atca_027_head[4] = { HEAD(4, 32, 1, 14, 0, 1, 0) };
const u16 necro_atca_027[132] = {
    L4(2, 0, 0, 0, 0, 0, 0, 0x1F42, 0, 2, 0, 0, 96, 0, 0),
    L4(2, 0, 268, 0, 0, 0, 0, 0x1F43, 0, 2, 0, 0, 96, 0, 0),
    CMD(CM_IXFW, 0, 0, 2), 0, 0, 0, 0,
    L4(3, 0, 268, 0, 0, 0, 0, 0x1F43, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1F44, 0, 70, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1F44, -15, 69, 0, 135, 96, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1F45, 0, 70, 0, 0, 96, 21, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1F46, 0, 133, 0, 0, 64, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1F47, 0, 2, 0, 0, 96, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1F48, 0, 2, 0, 0, 112, 0, 4),
    L4(1, 64, 0, 0, 0, 0, 0, 0x1F49, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1F4A, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1E22, 0, 2, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1E23, 0, 2, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1E24, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x1E24, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 30 KAGAMI K A, 31 KAGAMI K B, 32 KAGAMI K C */
const u16 necro_atca_030_head[4] = { HEAD(6, 32, 3, 19, 0, 1, 0) };
const u16 necro_atca_030[196] = {
    L6(1, 0, 0, 0, 0, 0, 0, 0x21C8, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 269, 0, 0, 0, 0, 0x21C9, 0, 134, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(5, 0, 0, 0, 0, 0, 0, 0x21CA, 0, 134, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x21CB, 0, 134, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x21CD, 0, 135, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x21CD, -53, 136, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(5, 0, 0, 0, 0, 0, 0, 0x21CE, 0, 135, 0, 0, 0, 21, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x21CF, 0, 134, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x21D0, 0, 134, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x21D1, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x21D3, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 64, 0, 0, 0, 0, 0, 0x1E25, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1E22, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1E23, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1E24, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x1E24, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 33 KAGAMI K A, 34 KAGAMI K B, 35 KAGAMI K C */
const u16 necro_atca_033_head[4] = { HEAD(4, 32, 5, 15, 0, 1, 0) };
const u16 necro_atca_033[204] = {
    L4(1, 0, 0, 1, 0, 0, 0, 0x1F4B, 0, 71, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 1, 0, 0, 0, 0x1F4C, 0, 71, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 1, 0, 0, 0, 0x1F4D, 0, 72, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 1, 0, 0, 0, 0x1F4E, 0, 72, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 1, 0, 0, 0, 0x1F4F, 0, 73, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 1, 0, 0, 0, 0x1F50, 0, 74, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 1, 0, 0, 0, 0x1F51, 0, 75, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 1, 0, 0, 0, 0x1F52, 0, 76, 0, 0, 0, 0, 0),
    L4(1, 0, 270, 1, 0, 0, 0, 0x1F53, 0, 77, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 1, 0, 0, 0, 0x1F54, 0, 159, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1F55, -17, 79, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1F56, 0, 80, 0, 0, 0, 21, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1F57, 0, 81, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1F58, 0, 82, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1F59, 0, 82, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1F5A, 0, 82, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1F5B, 0, 82, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1F5C, 0, 82, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1F5D, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1F5E, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1F17, 0, 2, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1E22, 0, 2, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1E23, 0, 2, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1E24, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x1E24, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 36 V JUMP P S A, 37 V JUMP P S B */
const u16 necro_atca_036_head[4] = { HEAD(4, 22, 0, 17, 0, 1, 0) };
const u16 necro_atca_036[108] = {
    CMD(CM_JSR, 8, 3, 1), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 0, 0, 0x1F66, 0, 88, 0, 0, 0, 0, 0),
    L4(2, 0, 268, 0, 0, 0, 0, 0x1F67, 0, 88, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1F68, 0, 90, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1F68, -19, 89, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1F69, 0, 89, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1F6A, 0, 90, 0, 0, 0, 21, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x1F6B, 0, 90, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1F6C, 0, 88, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1F6D, 0, 6, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1E5C, 0, 6, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x1E5D, 0, 6, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 38 V JUMP P M A, 39 V JUMP P M B */
const u16 necro_atca_038_head[4] = { HEAD(4, 22, 2, 17, 0, 1, 0) };
const u16 necro_atca_038[108] = {
    CMD(CM_JSR, 8, 3, 1), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x1F66, 0, 88, 0, 0, 0, 0, 0),
    L4(3, 0, 269, 0, 0, 0, 0, 0x1F67, 0, 88, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1F68, 0, 92, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1F68, -20, 91, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x1F69, 0, 91, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1F6A, 0, 92, 0, 0, 0, 21, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x1F6B, 0, 92, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1F6C, 0, 88, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1F6D, 0, 6, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1E5C, 0, 6, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x1E5D, 0, 6, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 40 V JUMP P L A, 41 V JUMP P L B */
const u16 necro_atca_040_head[4] = { HEAD(4, 22, 4, 18, 0, 1, 0) };
const u16 necro_atca_040[212] = {
    CMD(CM_JSR, 8, 3, 1), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x1F6F, 0, 88, 0, 0, 0, 21, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1F70, 0, 100, 0, 0, 0, 0, 0),
    L4(3, 0, 496, 0, 0, 0, 0, 0x1F71, 0, 100, 0, 0, 0, 0, 0),
    L4(3, 0, 270, 0, 0, 0, 0, 0x1F8A, 0, 100, 0, 0, 0, 33, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1F72, 0, 94, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1F73, -21, 93, 0, 148, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1F72, 0, 94, 0, 149, 0, 21, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1F73, 0, 94, 0, 150, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1F74, 0, 94, 0, 151, 0, 0, 0),
    L4(7, 0, 0, 0, 0, 0, 0, 0x1F75, 0, 94, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1ECA, 0, 100, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1ECB, 0, 100, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1ECC, 0, 88, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1F76, 0, 6, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1E5C, 0, 6, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x1E5D, 0, 6, 0, 0, 0, 0, 0),
    CMD(CM_END, 0, 0, 17), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x1F73, 0, 94, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1F74, 0, 94, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1F73, 0, 94, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1F74, 0, 94, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1F73, 0, 94, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1F74, 0, 94, 0, 0, 0, 0, 0),
    CMD(CM_JMP, 4, 40, 11), 0, 0, 0, 0,
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 42 V JUMP K S A */
const u16 necro_atca_042_head[4] = { HEAD(4, 22, 1, 7, 0, 1, 0) };
const u16 necro_atca_042[68] = {
    CMD(CM_JSR, 8, 3, 1), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 0, 0, 0x1F77, 0, 95, 0, 0, 0, 0, 0),
    L4(1, 0, 268, 0, 0, 0, 0, 0x1F78, 0, 95, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1F79, -22, 96, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1F7A, 0, 96, 0, 0, 0, 0, 0),
    L4(12, 0, 0, 0, 0, 0, 0, 0x1F7B, 0, 96, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x1F7C, 0, 88, 0, 0, 0, 21, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 43 V JUMP K S B */
const u16 necro_atca_043_head[4] = { HEAD(4, 20, 1, 12, 0, 3, 42) };
const u16 necro_atca_043[292] = {
    CMD(CM_JSR, 8, 3, 1), 0, 0, 0, 0,
    L4(3, 20, 0, 0, 0, 0, 10, 0x21F0, 0, 105, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 10, 0x21F1, 0, 105, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 10, 0x21F2, 0, 105, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 10, 0x21F3, -79, 184, 0, 81, 0, 0, 0),
    L4(2, 0, 268, 0, 0, 0, 10, 0x21F4, 0, 184, 0, 81, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 10, 0x21F5, 0, 184, 0, 87, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 10, 0x21F6, 0, 184, 0, 87, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 10, 0x21F7, 0, 184, 0, 87, 0, 0, 0),
    L4(2, 0, 268, 0, 0, 0, 10, 0x21F8, 0, 184, 0, 87, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 10, 0x21F9, 0, 184, 0, 81, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 10, 0x21FA, 0, 184, 0, 81, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 10, 0x21FB, 0, 184, 0, 81, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 8), 0, 0, 0, 0,
    L4(2, 0, 268, 0, 0, 0, 10, 0x21F4, -80, 184, 0, 81, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 9), 0, 0, 0, 0,
    CMD(CM_WCGT, 16392, 2, 16396), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 10, 0x21F5, 0, 185, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 10, 0x21F6, 0, 185, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 10, 0x21F7, 0, 185, 0, 0, 0, 0, 0),
    L4(2, 0, 268, 0, 0, 0, 10, 0x21F8, -80, 184, 0, 87, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 11), 0, 0, 0, 0,
    CMD(CM_WCGT, 16392, 2, 16394), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 10, 0x21F9, 0, 185, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 10, 0x21FA, 0, 185, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 10, 0x21FB, 0, 185, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 12), 0, 0, 0, 0,
    L4(2, 0, 268, 0, 0, 0, 10, 0x21F4, 0, 185, 0, 0, 0, 21, 0),
    L4(2, 0, 0, 0, 0, 0, 10, 0x21F5, 0, 185, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 10, 0x21F6, 0, 185, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 10, 0x21F7, 0, 185, 0, 0, 0, 0, 0),
    L4(2, 0, 268, 0, 0, 0, 10, 0x21F8, 0, 185, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 10, 0x21F9, 0, 185, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 10, 0x21FA, 0, 185, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 10, 0x21FB, 0, 185, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 8), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 44 V JUMP K M A, 45 V JUMP K M B */
const u16 necro_atca_044_head[4] = { HEAD(4, 22, 3, 19, 0, 1, 0) };
const u16 necro_atca_044[156] = {
    CMD(CM_JSR, 8, 3, 1), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 0, 12, 0x21E4, 0, 6, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 12, 0x21E5, 0, 6, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 12, 0x21E6, 0, 137, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 12, 0x21E7, 0, 137, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 12, 0x21E8, 0, 179, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 12, 0x21E9, -23, 180, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 12, 0x21E9, 0, 181, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 12, 0x21EA, 0, 182, 0, 0, 0, 21, 0),
    L4(2, 0, 0, 0, 0, 0, 12, 0x21EB, 0, 182, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 12, 0x21EC, 0, 182, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 12, 0x21ED, 0, 137, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 12, 0x21EE, 0, 137, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 12, 0x21EF, 0, 137, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 11, 0x1E47, 0, 6, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1E4B, 0, 6, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1E5C, 0, 6, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x1E5D, 0, 6, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 46 V JUMP K L A, 47 V JUMP K L B */
const u16 necro_atca_046_head[4] = { HEAD(4, 22, 5, 18, 0, 1, 0) };
const u16 necro_atca_046[188] = {
    CMD(CM_JSR, 8, 3, 1), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 0, 9, 0x1F8C, 0, 95, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 9, 0x1F8D, 0, 95, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 9, 0x1F8E, 0, 95, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 5, 0x1F8F, 0, 95, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 5, 0x1F90, 0, 95, 0, 0, 0, 0, 0),
    L4(1, 0, 498, 0, 0, 0, 5, 0x1F91, 0, 95, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 5, 0x1F92, 0, 97, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 5, 0x1F93, 0, 97, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 5, 0x1F94, 0, 97, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 7, 0x1F95, 0, 97, 0, 0, 0, 0, 0),
    L4(3, 0, 270, 0, 0, 0, 8, 0x1F96, 0, 97, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 8, 0x1F97, 0, 138, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 8, 0x1F97, -24, 98, 0, 143, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 11, 0x1F98, 0, 99, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 11, 0x1F99, 0, 138, 0, 0, 0, 21, 0),
    L4(3, 0, 0, 0, 0, 0, 11, 0x1F9A, 0, 137, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 11, 0x1F9B, 0, 137, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 11, 0x1F9C, 0, 137, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 11, 0x1F9D, 0, 95, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1E5C, 0, 6, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x1E5D, 0, 6, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 48 F JUMP P S A, 49 F JUMP P S B, 150 TUKAMI AIR A, 151 TUKAMI AIR B ... */
const u16 necro_atca_048_head[4] = { HEAD(4, 20, 0, 11, 0, 1, 0) };
const u16 necro_atca_048[84] = {
    CMD(CM_JSR, 8, 3, 1), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x1F60, 0, 95, 0, 0, 0, 0, 0),
    L4(2, 0, 268, 0, 0, 0, 0, 0x1F61, 0, 95, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1F62, -25, 101, 0, 0, 0, 0, 0),
    L4(12, 0, 0, 0, 0, 0, 0, 0x1F63, 0, 101, 0, 0, 0, 0, 0),
    L4(7, 0, 0, 0, 0, 0, 0, 0x1F64, 0, 102, 0, 0, 0, 21, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x1F65, 0, 95, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1E5C, 0, 95, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x1E5D, 0, 95, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 50 F JUMP P M A, 51 F JUMP P M B */
const u16 necro_atca_050_head[4] = { HEAD(4, 20, 2, 11, 0, 1, 0) };
const u16 necro_atca_050[84] = {
    CMD(CM_JSR, 8, 3, 1), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x1F60, 0, 95, 0, 0, 0, 0, 0),
    L4(3, 0, 269, 0, 0, 0, 0, 0x1F61, 0, 95, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1F62, -26, 103, 0, 0, 0, 0, 0),
    L4(8, 0, 0, 0, 0, 0, 0, 0x1F63, 0, 103, 0, 0, 0, 0, 0),
    L4(8, 0, 0, 0, 0, 0, 0, 0x1F64, 0, 104, 0, 0, 0, 21, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x1F65, 0, 95, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1E5C, 0, 95, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x1E5D, 0, 95, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 52 F JUMP P L A, 53 F JUMP P L B */
const u16 necro_atca_052_head[4] = { HEAD(4, 20, 4, 19, 0, 1, 0) };
const u16 necro_atca_052[204] = {
    CMD(CM_JSR, 8, 3, 1), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x1F6F, 0, 88, 0, 0, 0, 21, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1F70, 0, 100, 0, 0, 0, 0, 0),
    L4(3, 0, 496, 0, 0, 0, 0, 0x1F71, 0, 100, 0, 0, 0, 0, 0),
    L4(3, 0, 270, 0, 0, 0, 0, 0x1F8A, 0, 100, 0, 0, 0, 33, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1F72, 0, 94, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1F73, -21, 93, 0, 148, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1F72, 0, 94, 0, 149, 0, 21, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1F73, 0, 94, 0, 150, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1F74, 0, 94, 0, 151, 0, 0, 0),
    L4(7, 0, 0, 0, 0, 0, 0, 0x1F75, 0, 94, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1ECA, 0, 100, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1ECB, 0, 100, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1F76, 0, 6, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1E5C, 0, 6, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x1E5D, 0, 6, 0, 0, 0, 0, 0),
    CMD(CM_END, 0, 0, 17), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x1F73, 0, 94, 0, 0, 0, 21, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1F74, 0, 94, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1F73, 0, 94, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1F74, 0, 94, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1F73, 0, 94, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1F74, 0, 94, 0, 0, 0, 0, 0),
    CMD(CM_JMP, 4, 52, 11), 0, 0, 0, 0,
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 54 F JUMP K S A */
const u16 necro_atca_054_head[4] = { HEAD(4, 20, 1, 8, 0, 1, 0) };
const u16 necro_atca_054[68] = {
    CMD(CM_JSR, 8, 3, 1), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 0, 0, 0x1F77, 0, 95, 0, 0, 0, 0, 0),
    L4(1, 0, 268, 0, 0, 0, 0, 0x1F78, 0, 95, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1F79, -22, 96, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1F7A, 22, 96, 0, 0, 0, 0, 0),
    L4(12, 0, 0, 0, 0, 0, 0, 0x1F7B, 22, 96, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x1F7C, 0, 88, 0, 0, 0, 21, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 55 F JUMP K S B */
const u16 necro_atca_055_head[4] = { HEAD(2, 20, 1, 12, 0, 3, 42) };
const u16 necro_atca_055[8] = {
    CMD(CM_JPSS, 4, 43, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 56 F JUMP K M A, 57 F JUMP K M B */
const u16 necro_atca_056_head[4] = { HEAD(4, 20, 3, 9, 0, 3, 42) };
const u16 necro_atca_056[292] = {
    CMD(CM_JSR, 8, 3, 1), 0, 0, 0, 0,
    L4(3, 20, 0, 0, 0, 0, 0, 0x1F7D, 0, 105, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x1F7E, 0, 105, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1F7F, 0, 105, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1F80, -27, 106, 0, 81, 0, 0, 0),
    L4(2, 0, 269, 0, 0, 0, 0, 0x1F81, 0, 106, 0, 81, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1F82, 0, 106, 0, 87, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1F83, 0, 107, 0, 87, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1F84, 0, 107, 0, 87, 0, 0, 0),
    L4(2, 0, 269, 0, 0, 0, 0, 0x1F85, 0, 107, 0, 87, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1F86, 0, 107, 0, 81, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1F87, 0, 107, 0, 81, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1F88, 0, 106, 0, 81, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 8), 0, 0, 0, 0,
    L4(2, 0, 269, 0, 0, 0, 0, 0x1F81, -28, 106, 0, 81, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 9), 0, 0, 0, 0,
    CMD(CM_WCGT, 16392, 2, 16396), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x1F82, 0, 108, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1F83, 0, 108, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1F84, 0, 108, 0, 0, 0, 0, 0),
    L4(2, 0, 269, 0, 0, 0, 0, 0x1F85, -28, 107, 0, 87, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 11), 0, 0, 0, 0,
    CMD(CM_WCGT, 16392, 2, 16394), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x1F86, 0, 108, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1F87, 0, 108, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1F88, 0, 108, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 12), 0, 0, 0, 0,
    L4(2, 0, 269, 0, 0, 0, 0, 0x1F81, 0, 108, 0, 0, 0, 21, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1F82, 0, 108, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1F83, 0, 108, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1F84, 0, 108, 0, 0, 0, 0, 0),
    L4(2, 0, 269, 0, 0, 0, 0, 0x1F85, 0, 108, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1F86, 0, 108, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1F87, 0, 108, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1F88, 0, 108, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 8), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 58 F JUMP K L A, 59 F JUMP K L B */
const u16 necro_atca_058_head[4] = { HEAD(4, 20, 5, 9, 0, 3, 42) };
const u16 necro_atca_058[292] = {
    CMD(CM_JSR, 8, 3, 1), 0, 0, 0, 0,
    L4(3, 20, 0, 0, 0, 0, 3, 0x21FD, 0, 105, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 3, 0x21FE, 0, 105, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 3, 0x21FF, 0, 105, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 3, 0x2200, -29, 110, 0, 81, 0, 0, 0),
    L4(2, 0, 270, 0, 0, 0, 3, 0x2201, 0, 111, 0, 81, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 3, 0x2202, 0, 111, 0, 87, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 3, 0x2203, 0, 111, 0, 87, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 3, 0x2204, 0, 111, 0, 87, 0, 0, 0),
    L4(2, 0, 270, 0, 0, 0, 3, 0x2205, 0, 111, 0, 87, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 3, 0x2206, 0, 111, 0, 81, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 3, 0x2207, 0, 111, 0, 81, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 3, 0x2208, 0, 111, 0, 81, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 8), 0, 0, 0, 0,
    L4(2, 0, 270, 0, 0, 0, 3, 0x2201, -30, 111, 0, 81, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 9), 0, 0, 0, 0,
    CMD(CM_WCGT, 16392, 2, 16396), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 3, 0x2202, 0, 112, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 3, 0x2203, 0, 112, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 3, 0x2204, 0, 112, 0, 0, 0, 0, 0),
    L4(2, 0, 270, 0, 0, 0, 3, 0x2205, -30, 111, 0, 87, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 11), 0, 0, 0, 0,
    CMD(CM_WCGT, 16392, 2, 16394), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 3, 0x2206, 0, 112, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 3, 0x2207, 0, 112, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 3, 0x2208, 0, 112, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 12), 0, 0, 0, 0,
    L4(2, 0, 270, 0, 0, 0, 3, 0x2201, 0, 112, 0, 0, 0, 21, 0),
    L4(2, 0, 0, 0, 0, 0, 3, 0x2202, 0, 112, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 3, 0x2203, 0, 112, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 3, 0x2204, 0, 112, 0, 0, 0, 0, 0),
    L4(2, 0, 270, 0, 0, 0, 3, 0x2205, 0, 112, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 3, 0x2206, 0, 112, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 3, 0x2207, 0, 112, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 3, 0x2208, 0, 112, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 8), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 60 B JUMP P S A, 61 B JUMP P S B */
const u16 necro_atca_060_head[4] = { HEAD(2, 24, 0, 10, 0, 1, 0) };
const u16 necro_atca_060[8] = {
    CMD(CM_JPSS, 4, 48, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 62 B JUMP P M A, 63 B JUMP P M B */
const u16 necro_atca_062_head[4] = { HEAD(2, 24, 2, 10, 0, 1, 0) };
const u16 necro_atca_062[8] = {
    CMD(CM_JPSS, 4, 50, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 64 B JUMP P L A, 65 B JUMP P L B */
const u16 necro_atca_064_head[4] = { HEAD(2, 24, 4, 18, 0, 1, 0) };
const u16 necro_atca_064[8] = {
    CMD(CM_JPSS, 4, 52, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 66 B JUMP K S A */
const u16 necro_atca_066_head[4] = { HEAD(2, 24, 1, 7, 0, 1, 0) };
const u16 necro_atca_066[8] = {
    CMD(CM_JPSS, 4, 54, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 67 B JUMP K S B */
const u16 necro_atca_067_head[4] = { HEAD(2, 24, 1, 12, 0, 3, 42) };
const u16 necro_atca_067[8] = {
    CMD(CM_JPSS, 4, 43, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 68 B JUMP K M A, 69 B JUMP K M B */
const u16 necro_atca_068_head[4] = { HEAD(2, 24, 3, 8, 0, 3, 42) };
const u16 necro_atca_068[8] = {
    CMD(CM_JPSS, 4, 56, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 70 B JUMP K L A, 71 B JUMP K L B */
const u16 necro_atca_070_head[4] = { HEAD(2, 24, 5, 8, 0, 3, 42) };
const u16 necro_atca_070[8] = {
    CMD(CM_JPSS, 4, 58, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 72 SP V JP S P A, 73 SP V JP S P B */
const u16 necro_atca_072_head[4] = { HEAD(2, 28, 0, 17, 0, 1, 0) };
const u16 necro_atca_072[8] = {
    CMD(CM_JPSS, 4, 36, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 74 SP V JP M P A, 75 SP V JP M P B */
const u16 necro_atca_074_head[4] = { HEAD(2, 28, 2, 17, 0, 1, 0) };
const u16 necro_atca_074[8] = {
    CMD(CM_JPSS, 4, 38, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 76 SP V JP L P A, 77 SP V JP L P B */
const u16 necro_atca_076_head[4] = { HEAD(2, 28, 4, 18, 0, 1, 0) };
const u16 necro_atca_076[8] = {
    CMD(CM_JPSS, 4, 40, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 78 SP V JP S K A */
const u16 necro_atca_078_head[4] = { HEAD(2, 28, 1, 7, 0, 1, 0) };
const u16 necro_atca_078[8] = {
    CMD(CM_JPSS, 4, 42, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 79 SP V JP S K B */
const u16 necro_atca_079_head[4] = { HEAD(2, 28, 1, 12, 0, 3, 42) };
const u16 necro_atca_079[8] = {
    CMD(CM_JPSS, 4, 43, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 80 SP V JP M K A, 81 SP V JP M K B */
const u16 necro_atca_080_head[4] = { HEAD(2, 28, 3, 19, 0, 1, 0) };
const u16 necro_atca_080[8] = {
    CMD(CM_JPSS, 4, 44, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 82 SP V JP L K A, 83 SP V JP L K B */
const u16 necro_atca_082_head[4] = { HEAD(2, 28, 5, 18, 0, 1, 0) };
const u16 necro_atca_082[8] = {
    CMD(CM_JPSS, 4, 46, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 84 SP F JP S P A, 85 SP F JP S P B */
const u16 necro_atca_084_head[4] = { HEAD(2, 26, 0, 11, 0, 1, 0) };
const u16 necro_atca_084[8] = {
    CMD(CM_JPSS, 4, 48, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 86 SP F JP M P A, 87 SP F JP M P B */
const u16 necro_atca_086_head[4] = { HEAD(2, 26, 2, 11, 0, 1, 0) };
const u16 necro_atca_086[8] = {
    CMD(CM_JPSS, 4, 50, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 88 SP F JP L P A, 89 SP F JP L P B */
const u16 necro_atca_088_head[4] = { HEAD(2, 26, 4, 19, 0, 1, 0) };
const u16 necro_atca_088[8] = {
    CMD(CM_JPSS, 4, 52, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 90 SP F JP S K A */
const u16 necro_atca_090_head[4] = { HEAD(2, 26, 1, 8, 0, 1, 0) };
const u16 necro_atca_090[8] = {
    CMD(CM_JPSS, 4, 54, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 91 SP F JP S K B */
const u16 necro_atca_091_head[4] = { HEAD(2, 26, 1, 12, 0, 3, 42) };
const u16 necro_atca_091[8] = {
    CMD(CM_JPSS, 4, 43, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 92 SP F JP M K A, 93 SP F JP M K B */
const u16 necro_atca_092_head[4] = { HEAD(2, 26, 3, 9, 0, 3, 42) };
const u16 necro_atca_092[8] = {
    CMD(CM_JPSS, 4, 56, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 94 SP F JP L K A, 95 SP F JP L K B */
const u16 necro_atca_094_head[4] = { HEAD(2, 26, 5, 9, 0, 3, 42) };
const u16 necro_atca_094[8] = {
    CMD(CM_JPSS, 4, 58, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 96 SP B JP S P A, 97 SP B JP S P B */
const u16 necro_atca_096_head[4] = { HEAD(2, 30, 0, 10, 0, 1, 0) };
const u16 necro_atca_096[8] = {
    CMD(CM_JPSS, 4, 84, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 98 SP B JP M P A, 99 SP B JP M P B */
const u16 necro_atca_098_head[4] = { HEAD(2, 30, 2, 10, 0, 1, 0) };
const u16 necro_atca_098[8] = {
    CMD(CM_JPSS, 4, 86, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 100 SP B JP L P A, 101 SP B JP L P B */
const u16 necro_atca_100_head[4] = { HEAD(2, 30, 4, 18, 0, 1, 0) };
const u16 necro_atca_100[8] = {
    CMD(CM_JPSS, 4, 88, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 102 SP B JP S K A */
const u16 necro_atca_102_head[4] = { HEAD(2, 30, 1, 7, 0, 1, 0) };
const u16 necro_atca_102[8] = {
    CMD(CM_JPSS, 4, 90, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 103 SP B JP S K B */
const u16 necro_atca_103_head[4] = { HEAD(2, 30, 1, 12, 0, 3, 42) };
const u16 necro_atca_103[8] = {
    CMD(CM_JPSS, 4, 43, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 104 SP B JP M K A, 105 SP B JP M K B */
const u16 necro_atca_104_head[4] = { HEAD(2, 30, 3, 8, 0, 3, 42) };
const u16 necro_atca_104[8] = {
    CMD(CM_JPSS, 4, 92, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 106 SP B JP L K A, 107 SP B JP L K B */
const u16 necro_atca_106_head[4] = { HEAD(2, 30, 5, 8, 0, 3, 42) };
const u16 necro_atca_106[8] = {
    CMD(CM_JPSS, 4, 94, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 108 S V JP S P A, 109 S V JP S P B, 120 S F JP S P A, 121 S F JP S P B ... */
const u16 necro_atca_108_head[4] = { HEAD(2, 16, 0, 0, 0, 0, 0) };
const u16 necro_atca_108[8] = {
    CMD(CM_JPSS, 4, 48, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 110 S V JP M P A, 111 S V JP M P B, 122 S F JP M P A, 123 S F JP M P B ... */
const u16 necro_atca_110_head[4] = { HEAD(2, 16, 2, 0, 0, 0, 0) };
const u16 necro_atca_110[8] = {
    CMD(CM_JPSS, 4, 50, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 112 S V JP L P A, 113 S V JP L P B, 124 S F JP L P A, 125 S F JP L P B ... */
const u16 necro_atca_112_head[4] = { HEAD(2, 16, 4, 0, 0, 0, 0) };
const u16 necro_atca_112[8] = {
    CMD(CM_JPSS, 4, 50, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 114 S V JP S K A, 115 S V JP S K B, 126 S F JP S K A, 127 S F JP S K B ... */
const u16 necro_atca_114_head[4] = { HEAD(2, 16, 1, 0, 0, 0, 0) };
const u16 necro_atca_114[8] = {
    CMD(CM_JPSS, 4, 42, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 116 S V JP M K A, 117 S V JP M K B, 128 S F JP M K A, 129 S F JP M K B ... */
const u16 necro_atca_116_head[4] = { HEAD(2, 16, 3, 0, 0, 0, 0) };
const u16 necro_atca_116[8] = {
    CMD(CM_JPSS, 4, 56, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 118 S V JP L K A, 119 S V JP L K B, 130 S F JP L K A, 131 S F JP L K B ... */
const u16 necro_atca_118_head[4] = { HEAD(2, 16, 5, 0, 0, 0, 0) };
const u16 necro_atca_118[152] = {
    CMD(CM_JPSS, 4, 56, 1),
    CMD(CM_ROA, 0, 0, 0),
    CMD(CM_END, 3584, 0, 0),
    CMD(CM_JPSS, 4, 48, 1),
    CMD(CM_ROA, 0, 0, 0),
    CMD(CM_END, 3586, 0, 0),
    CMD(CM_JPSS, 4, 50, 1),
    CMD(CM_ROA, 0, 0, 0),
    CMD(CM_END, 3588, 0, 0),
    CMD(CM_JPSS, 4, 52, 1),
    CMD(CM_ROA, 0, 0, 0),
    CMD(CM_END, 3585, 0, 0),
    CMD(CM_JPSS, 4, 54, 1),
    CMD(CM_ROA, 0, 0, 0),
    CMD(CM_END, 3587, 0, 0),
    CMD(CM_JPSS, 4, 56, 1),
    CMD(CM_ROA, 0, 0, 0),
    CMD(CM_END, 3589, 0, 0),
    CMD(CM_JPSS, 4, 58, 1),
    CMD(CM_ROA, 0, 0, 0),
    CMD(CM_END, 4608, 0, 0),
    CMD(CM_JPSS, 4, 60, 1),
    CMD(CM_ROA, 0, 0, 0),
    CMD(CM_END, 4610, 0, 0),
    CMD(CM_JPSS, 4, 62, 1),
    CMD(CM_ROA, 0, 0, 0),
    CMD(CM_END, 4612, 0, 0),
    CMD(CM_JPSS, 4, 64, 1),
    CMD(CM_ROA, 0, 0, 0),
    CMD(CM_END, 4609, 0, 0),
    CMD(CM_JPSS, 4, 66, 1),
    CMD(CM_ROA, 0, 0, 0),
    CMD(CM_END, 4611, 0, 0),
    CMD(CM_JPSS, 4, 68, 1),
    CMD(CM_ROA, 0, 0, 0),
    CMD(CM_END, 4613, 0, 0),
    CMD(CM_JPSS, 4, 70, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 144 TUKAMIKAKARI A, 146 TUKAMIKAKARI C, 147 TUKAMIKAKARI D, 149 TUKAMIKAKARI F */
const u16 necro_atca_144_head[4] = { HEAD(4, 0, 16, 0, 0, 0, 0) };
const u16 necro_atca_144[44] = {
    CMD(CM_CAFR, 2, 1, 0), 0, 0, 0, 0,
    CMD(CM_CARE, 2, 1, 0), 0, 0, 0, 0,
    L4(3, 0, 0, 0, 0, 0, 0, 0x2096, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x2097, -33, 121, 0, 0, 0, 0, 0),
    CMD(CM_JMP, 4, 0, 2), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 145 TUKAMIKAKARI B, 148 TUKAMIKAKARI E */
const u16 necro_atca_145_head[4] = { HEAD(4, 0, 18, 0, 0, 0, 0) };
const u16 necro_atca_145[44] = {
    CMD(CM_CAFR, 2, 1, 2), 0, 0, 0, 0,
    CMD(CM_CARE, 2, 1, 2), 0, 0, 0, 0,
    L4(3, 0, 0, 0, 0, 0, 0, 0x2096, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x2097, -47, 121, 0, 0, 0, 0, 0),
    CMD(CM_JMP, 4, 0, 2), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 156 follow-up of S KICK A / S KICK C */
const u16 necro_atca_156_head[4] = { HEAD(6, 0, 2, 14, 0, 1, 0) };
const u16 necro_atca_156[208] = {
    CMD(CM_RMJA, 4, 157, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(1, 0, 0, 0, 0, 0, 0, 0x1E89, 0, 1, 0, 0, 96, 0, 0, 0, 0, 24, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1E8A, 0, 19, 0, 0, 96, 0, 0, 0, 0, 26, 0, 0),
    L6(1, 0, 269, 0, 0, 0, 0, 0x1E8B, 0, 19, 0, 0, 96, 0, 0, 0, 0, 26, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1E8C, 0, 165, 0, 0, 96, 0, 0, 0, 0, 28, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x1E8D, -76, 20, 0, 0, 96, 0, 0, 0, 0, 30, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1ECE, 0, 21, 0, 0, 64, 21, 0, 0, 0, 32, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1E8F, 0, 19, 0, 0, 0, 0, 0, 0, 0, 32, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1E90, 0, 19, 0, 0, 0, 0, 0, 0, 0, 34, 0, 0),
    L6(1, 64, 0, 0, 0, 0, 0, 0x1E91, 0, 19, 0, 0, 0, 0, 0, 0, 0, 34, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1E92, 0, 19, 0, 0, 0, 0, 0, 0, 0, 36, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1E93, 0, 1, 0, 0, 0, 0, 0, 0, 0, 38, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1E94, 0, 1, 0, 0, 0, 0, 0, 0, 0, 38, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1E3B, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1E3C, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1E3D, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x1E3D, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 157 follow-up of follow-up of S KICK A / S KICK C */
const u16 necro_atca_157_head[4] = { HEAD(6, 0, 4, 20, 0, 13, 0) };
const u16 necro_atca_157[220] = {
    L6(1, 0, 0, 0, 0, 0, 0, 0x1E9A, 0, 31, 0, 0, 96, 0, 0, 0, 0, 62, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1E9B, 0, 32, 0, 0, 96, 0, 0, 0, 0, 62, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1E9C, 0, 30, 0, 0, 96, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 270, 0, 0, 0, 0, 0x1E9D, 0, 30, 0, 0, 64, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1E9E, 0, 35, 0, 0, 64, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x1E9E, -77, 34, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1E9F, 0, 34, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1EA0, 0, 35, 0, 0, 0, 21, 0, 0, 0, 64, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1EA0, 0, 35, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1EA1, 0, 35, 0, 0, 0, 0, 0, 0, 0, 64, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1EA2, 0, 33, 0, 0, 0, 0, 0, 0, 0, 64, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1EA3, 0, 33, 0, 0, 0, 0, 0, 0, 0, 64, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1EA4, 0, 1, 0, 0, 0, 0, 0, 0, 0, 64, 0, 0),
    L6(2, 64, 0, 0, 0, 0, 0, 0x1EA5, 0, 1, 0, 0, 0, 0, 0, 0, 0, 64, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1EA6, 0, 1, 0, 0, 0, 0, 0, 0, 0, 64, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1E3C, 0, 1, 0, 0, 0, 0, 0, 0, 0, 64, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1E3D, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x1E3D, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

const OLC_IX necro_olc_ix_table[10] = {
    { { 0, 0, 0, 0 } },  /* 0 */
    { { 0, 1, 0, 0 } },  /* 1 */
    { { 0, 13, 0, 0 } },  /* 2 */
    { { 0, 0, 21, 0 } },  /* 3 */
    { { 0, 0, 33, 0 } },  /* 4 */
    { { 41, 0, 0, 0 } },  /* 5 */
    { { 42, 0, 0, 0 } },  /* 6 */
    { { 43, 0, 0, 0 } },  /* 7 */
    { { 44, 0, 0, 0 } },  /* 8 */
    { { 45, 0, 0, 0 } },  /* 9 */
};

const OVERLAP_PARTS necro_overlap_char_tbl[46] = {
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 0, 0 },  /* 0 */
    { 0, 0, 0, 0, 2, 0, 2, 0, 0, 0, 8544 },  /* 1 */
    { 0, 0, 0, 0, 2, 0, 2, 0, 0, 0, 8545 },  /* 2 */
    { 0, 0, 0, 0, 2, 0, 2, 0, 0, 0, 8546 },  /* 3 */
    { 0, 0, 0, 0, 2, 0, 2, 0, 0, 0, 8547 },  /* 4 */
    { 0, 0, 0, 0, 2, 0, 2, 0, 0, 0, 8548 },  /* 5 */
    { 0, 0, 0, 0, 2, 0, 2, 0, 0, 0, 8549 },  /* 6 */
    { 0, 0, 0, 0, 2, 0, 2, 0, 0, 0, 8550 },  /* 7 */
    { 0, 0, 0, 0, 2, 0, 2, 0, 0, 0, 8551 },  /* 8 */
    { 0, 0, 0, 0, 2, 0, 2, 0, 0, 0, 8552 },  /* 9 */
    { 0, 0, 0, 0, 2, 0, 2, 0, 0, 0, 8553 },  /* 10 */
    { 0, 0, 0, 0, 2, 0, 2, 0, 0, 0, 8554 },  /* 11 */
    { 0, 0, 0, 0, 2, 0, 2, 0, 0, 1, 8555 },  /* 12 */
    { 0, 0, 0, 0, 2, 0, 2, 0, 0, 0, 8575 },  /* 13 */
    { 0, 0, 0, 0, 2, 0, 2, 0, 0, 0, 8576 },  /* 14 */
    { 0, 0, 0, 0, 2, 0, 2, 0, 0, 0, 8577 },  /* 15 */
    { 0, 0, 0, 0, 2, 0, 2, 0, 0, 0, 8578 },  /* 16 */
    { 0, 0, 0, 0, 2, 0, 2, 0, 0, 0, 8579 },  /* 17 */
    { 0, 0, 0, 0, 2, 0, 2, 0, 0, 0, 8580 },  /* 18 */
    { 0, 0, 0, 0, 2, 0, 2, 0, 0, 0, 8581 },  /* 19 */
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 20, 0 },  /* 20 */
    { 0, 0, 0, 0, 2, 0, 2, 0, 0, 0, 8556 },  /* 21 */
    { 0, 0, 0, 0, 2, 0, 2, 0, 0, 0, 8557 },  /* 22 */
    { 0, 0, 0, 0, 2, 0, 2, 0, 0, 0, 8558 },  /* 23 */
    { 0, 0, 0, 0, 2, 0, 2, 0, 0, 0, 8559 },  /* 24 */
    { 0, 0, 0, 0, 2, 0, 2, 0, 0, 0, 8560 },  /* 25 */
    { 0, 0, 0, 0, 2, 0, 2, 0, 0, 0, 8561 },  /* 26 */
    { 0, 0, 0, 0, 2, 0, 2, 0, 0, 0, 8562 },  /* 27 */
    { 0, 0, 0, 0, 2, 0, 2, 0, 0, 0, 8563 },  /* 28 */
    { 0, 0, 0, 0, 2, 0, 2, 0, 0, 0, 8564 },  /* 29 */
    { 0, 0, 0, 0, 2, 0, 2, 0, 0, 0, 8565 },  /* 30 */
    { 0, 0, 0, 0, 2, 0, 2, 0, 0, 0, 8566 },  /* 31 */
    { 0, 0, 0, 0, 2, 0, 2, 0, 0, 21, 8567 },  /* 32 */
    { 0, 0, 0, 0, 2, 0, 2, 0, 0, 0, 8582 },  /* 33 */
    { 0, 0, 0, 0, 2, 0, 2, 0, 0, 0, 8583 },  /* 34 */
    { 0, 0, 0, 0, 2, 0, 2, 0, 0, 0, 8584 },  /* 35 */
    { 0, 0, 0, 0, 2, 0, 2, 0, 0, 0, 8585 },  /* 36 */
    { 0, 0, 0, 0, 2, 0, 2, 0, 0, 0, 8586 },  /* 37 */
    { 0, 0, 0, 0, 2, 0, 2, 0, 0, 0, 8587 },  /* 38 */
    { 0, 0, 0, 0, 2, 0, 2, 0, 0, 0, 8588 },  /* 39 */
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 40, 0 },  /* 40 */
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 41, 8608 },  /* 41 */
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 42, 8609 },  /* 42 */
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 43, 8610 },  /* 43 */
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 44, 8611 },  /* 44 */
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 45, 8612 },  /* 45 */
};

const CatchTable necro_rival_catch_tbl[1088] = {
    { -68, 0, 1, 1, 1 },  /* 0 */
    { -68, 0, 1, 1, 1 },  /* 1 */
    { -68, 0, 1, 1, 1 },  /* 2 */
    { -68, 0, 1, 1, 1 },  /* 3 */
    { -74, 0, 1, 1, 2 },  /* 4 */
    { -78, 0, 1, 1, 2 },  /* 5 */
    { -72, 0, 1, 1, 1 },  /* 6 */
    { -75, 0, 1, 1, 1 },  /* 7 */
    { -84, 0, 1, 1, 1 },  /* 8 */
    { -20, 0, 1, 1, 1 },  /* 9 */
    { -68, 0, 1, 1, 1 },  /* 10 */
    { -68, 0, 1, 1, 1 },  /* 11 */
    { -68, 0, 1, 1, 1 },  /* 12 */
    { -68, 0, 1, 1, 1 },  /* 13 */
    { -68, 0, 1, 1, 1 },  /* 14 */
    { -68, 0, 1, 1, 1 },  /* 15 */
    { -64, 0, 1, 1, 2 },  /* 16 */
    { -68, 0, 1, 1, 2 },  /* 17 */
    { -68, 0, 1, 1, 2 },  /* 18 */
    { -58, 0, 1, 1, 2 },  /* 19 */
    { -68, 0, 1, 1, 3 },  /* 20 */
    { -76, 0, 1, 1, 3 },  /* 21 */
    { -72, 0, 1, 1, 2 },  /* 22 */
    { -72, 0, 1, 1, 2 },  /* 23 */
    { -80, 0, 1, 1, 2 },  /* 24 */
    { -100, 0, 1, 1, 2 },  /* 25 */
    { -58, 0, 1, 1, 2 },  /* 26 */
    { -68, 0, 1, 1, 2 },  /* 27 */
    { -68, 0, 1, 1, 2 },  /* 28 */
    { -64, 0, 1, 1, 2 },  /* 29 */
    { -68, 0, 1, 1, 2 },  /* 30 */
    { -68, 0, 1, 1, 2 },  /* 31 */
    { -48, 0, 1, 1, 3 },  /* 32 */
    { -66, 0, 1, 1, 3 },  /* 33 */
    { -66, 0, 1, 1, 3 },  /* 34 */
    { -56, 0, 1, 1, 3 },  /* 35 */
    { -64, 0, 1, 1, 4 },  /* 36 */
    { -64, 0, 1, 1, 4 },  /* 37 */
    { -66, 0, 1, 1, 3 },  /* 38 */
    { -70, 0, 1, 1, 3 },  /* 39 */
    { -80, 0, 1, 1, 3 },  /* 40 */
    { -89, 0, 1, 1, 3 },  /* 41 */
    { -56, 0, 1, 1, 3 },  /* 42 */
    { -66, 0, 1, 1, 3 },  /* 43 */
    { -66, 0, 1, 1, 3 },  /* 44 */
    { -48, 0, 1, 1, 3 },  /* 45 */
    { -66, 0, 1, 1, 3 },  /* 46 */
    { -66, 0, 1, 1, 3 },  /* 47 */
    { -64, 0, 1, 1, 4 },  /* 48 */
    { -64, 0, 1, 1, 4 },  /* 49 */
    { -52, 0, 1, 1, 4 },  /* 50 */
    { -52, 0, 1, 1, 4 },  /* 51 */
    { -56, 0, 1, 1, 5 },  /* 52 */
    { -62, 0, 1, 1, 5 },  /* 53 */
    { -82, 0, 1, 1, 4 },  /* 54 */
    { -68, 0, 1, 1, 4 },  /* 55 */
    { -78, 0, 1, 1, 4 },  /* 56 */
    { -88, 0, 1, 1, 4 },  /* 57 */
    { -52, 0, 1, 1, 4 },  /* 58 */
    { -52, 0, 1, 1, 4 },  /* 59 */
    { -52, 0, 1, 1, 4 },  /* 60 */
    { -64, 0, 1, 1, 4 },  /* 61 */
    { -52, 0, 1, 1, 4 },  /* 62 */
    { -52, 0, 1, 1, 4 },  /* 63 */
    { -60, 0, 1, 1, 5 },  /* 64 */
    { -62, 0, 1, 1, 5 },  /* 65 */
    { -52, 0, 1, 1, 5 },  /* 66 */
    { -50, 0, 1, 1, 5 },  /* 67 */
    { -51, 0, 1, 1, 6 },  /* 68 */
    { -56, 0, 1, 1, 6 },  /* 69 */
    { -82, 0, 1, 1, 5 },  /* 70 */
    { -55, 0, 1, 1, 5 },  /* 71 */
    { -74, 0, 1, 1, 5 },  /* 72 */
    { -77, 0, 1, 1, 5 },  /* 73 */
    { -50, 0, 1, 1, 5 },  /* 74 */
    { -52, 0, 1, 1, 5 },  /* 75 */
    { -52, 0, 1, 1, 5 },  /* 76 */
    { -60, 0, 1, 1, 5 },  /* 77 */
    { -52, 0, 1, 1, 5 },  /* 78 */
    { -52, 0, 1, 1, 5 },  /* 79 */
    { -62, 0, 1, 1, 6 },  /* 80 */
    { -60, 0, 1, 1, 6 },  /* 81 */
    { -44, 0, 1, 1, 6 },  /* 82 */
    { -48, 0, 1, 1, 6 },  /* 83 */
    { -46, 0, 1, 1, 7 },  /* 84 */
    { -54, 0, 1, 1, 7 },  /* 85 */
    { -82, 0, 1, 1, 6 },  /* 86 */
    { -57, 0, 1, 1, 6 },  /* 87 */
    { -72, 0, 1, 1, 6 },  /* 88 */
    { -76, 0, 1, 1, 6 },  /* 89 */
    { -48, 0, 1, 1, 6 },  /* 90 */
    { -44, 0, 1, 1, 6 },  /* 91 */
    { -44, 0, 1, 1, 6 },  /* 92 */
    { -62, 0, 1, 1, 6 },  /* 93 */
    { -44, 0, 1, 1, 6 },  /* 94 */
    { -44, 0, 1, 1, 6 },  /* 95 */
    { -72, 0, 1, 1, 7 },  /* 96 */
    { -72, 0, 1, 1, 7 },  /* 97 */
    { -80, 0, 1, 1, 7 },  /* 98 */
    { -75, 0, 1, 1, 7 },  /* 99 */
    { -86, 0, 1, 1, 8 },  /* 100 */
    { -94, 0, 1, 1, 8 },  /* 101 */
    { -104, 0, 1, 1, 7 },  /* 102 */
    { -86, 0, 1, 1, 7 },  /* 103 */
    { -82, 0, 1, 1, 7 },  /* 104 */
    { -86, 0, 1, 1, 7 },  /* 105 */
    { -75, 0, 1, 1, 7 },  /* 106 */
    { -80, 0, 1, 1, 7 },  /* 107 */
    { -80, 0, 1, 1, 7 },  /* 108 */
    { -72, 0, 1, 1, 7 },  /* 109 */
    { -80, 0, 1, 1, 7 },  /* 110 */
    { -80, 0, 1, 1, 7 },  /* 111 */
    { -68, 0, 1, 1, 8 },  /* 112 */
    { -64, 0, 1, 1, 8 },  /* 113 */
    { -80, 0, 1, 1, 8 },  /* 114 */
    { -75, 0, 1, 1, 8 },  /* 115 */
    { -86, 0, 1, 1, 9 },  /* 116 */
    { -88, 0, 1, 1, 9 },  /* 117 */
    { -104, 0, 1, 1, 8 },  /* 118 */
    { -86, 0, 1, 1, 8 },  /* 119 */
    { -86, 0, 1, 1, 8 },  /* 120 */
    { -83, 0, 1, 1, 8 },  /* 121 */
    { -75, 0, 1, 1, 8 },  /* 122 */
    { -80, 0, 1, 1, 8 },  /* 123 */
    { -80, 0, 1, 1, 8 },  /* 124 */
    { -68, 0, 1, 1, 8 },  /* 125 */
    { -80, 0, 1, 1, 8 },  /* 126 */
    { -80, 0, 1, 1, 8 },  /* 127 */
    { -112, 0, 1, 1, 9 },  /* 128 */
    { -112, 0, 1, 1, 9 },  /* 129 */
    { -112, 0, 1, 1, 9 },  /* 130 */
    { -112, 0, 1, 1, 9 },  /* 131 */
    { -112, 0, 1, 1, 10 },  /* 132 */
    { -112, 0, 1, 1, 10 },  /* 133 */
    { -137, 0, 1, 1, 9 },  /* 134 */
    { -112, 0, 1, 1, 9 },  /* 135 */
    { -86, 0, 1, 1, 9 },  /* 136 */
    { -112, 0, 1, 1, 9 },  /* 137 */
    { -112, 0, 1, 1, 9 },  /* 138 */
    { -112, 0, 1, 1, 9 },  /* 139 */
    { -112, 0, 1, 1, 9 },  /* 140 */
    { -112, 0, 1, 1, 9 },  /* 141 */
    { -112, 0, 1, 1, 9 },  /* 142 */
    { -112, 0, 1, 1, 9 },  /* 143 */
    { -90, 0, 1, 1, 1 },  /* 144 */
    { -90, 0, 1, 1, 1 },  /* 145 */
    { -85, 1, 1, 1, 1 },  /* 146 */
    { -94, 0, 1, 1, 1 },  /* 147 */
    { -94, -3, 1, 1, 1 },  /* 148 */
    { -96, 0, 1, 1, 1 },  /* 149 */
    { -85, 1, 1, 1, 1 },  /* 150 */
    { -94, 0, 1, 1, 1 },  /* 151 */
    { -106, 0, 1, 1, 1 },  /* 152 */
    { -69, 0, 1, 1, 1 },  /* 153 */
    { -94, 0, 1, 1, 1 },  /* 154 */
    { -85, 1, 1, 1, 1 },  /* 155 */
    { -85, 1, 1, 1, 1 },  /* 156 */
    { -90, 0, 1, 1, 1 },  /* 157 */
    { -85, 1, 1, 1, 1 },  /* 158 */
    { -85, 1, 1, 1, 1 },  /* 159 */
    { -85, 0, 1, 1, 2 },  /* 160 */
    { -84, -1, 1, 1, 2 },  /* 161 */
    { -84, 2, 1, 1, 2 },  /* 162 */
    { -94, 0, 1, 1, 2 },  /* 163 */
    { -98, -3, 1, 1, 2 },  /* 164 */
    { -96, 0, 1, 1, 2 },  /* 165 */
    { -79, 0, 1, 1, 2 },  /* 166 */
    { -95, -1, 1, 1, 2 },  /* 167 */
    { -94, 0, 1, 1, 2 },  /* 168 */
    { -69, 0, 1, 1, 2 },  /* 169 */
    { -94, 0, 1, 1, 2 },  /* 170 */
    { -84, 2, 1, 1, 2 },  /* 171 */
    { -84, 2, 1, 1, 2 },  /* 172 */
    { -85, 0, 1, 1, 2 },  /* 173 */
    { -84, 2, 1, 1, 2 },  /* 174 */
    { -84, 2, 1, 1, 2 },  /* 175 */
    { -90, 0, 1, 1, 3 },  /* 176 */
    { -90, 0, 1, 1, 3 },  /* 177 */
    { -84, 1, 1, 1, 3 },  /* 178 */
    { -94, 0, 1, 1, 3 },  /* 179 */
    { -100, 0, 1, 1, 3 },  /* 180 */
    { -96, 0, 1, 1, 3 },  /* 181 */
    { -79, 0, 1, 1, 3 },  /* 182 */
    { -91, 0, 1, 1, 3 },  /* 183 */
    { -96, 0, 1, 1, 3 },  /* 184 */
    { -69, 0, 1, 1, 3 },  /* 185 */
    { -94, 0, 1, 1, 3 },  /* 186 */
    { -84, 1, 1, 1, 3 },  /* 187 */
    { -84, 1, 1, 1, 3 },  /* 188 */
    { -90, 0, 1, 1, 3 },  /* 189 */
    { -84, 1, 1, 1, 3 },  /* 190 */
    { -84, 1, 1, 1, 3 },  /* 191 */
    { -83, 0, 1, 1, 4 },  /* 192 */
    { -90, 0, 1, 1, 4 },  /* 193 */
    { -84, 2, 1, 1, 4 },  /* 194 */
    { -94, -1, 1, 1, 4 },  /* 195 */
    { -99, -1, 1, 1, 4 },  /* 196 */
    { -96, 0, 1, 1, 4 },  /* 197 */
    { -79, 0, 1, 1, 4 },  /* 198 */
    { -90, 0, 1, 1, 4 },  /* 199 */
    { -102, 0, 1, 1, 4 },  /* 200 */
    { -71, -2, 1, 1, 4 },  /* 201 */
    { -94, -1, 1, 1, 4 },  /* 202 */
    { -84, 2, 1, 1, 4 },  /* 203 */
    { -84, 2, 1, 1, 4 },  /* 204 */
    { -83, 0, 1, 1, 4 },  /* 205 */
    { -84, 2, 1, 1, 4 },  /* 206 */
    { -84, 2, 1, 1, 4 },  /* 207 */
    { -83, 0, 1, 1, 5 },  /* 208 */
    { -90, 0, 1, 1, 5 },  /* 209 */
    { -84, 2, 1, 1, 5 },  /* 210 */
    { -94, -2, 1, 1, 5 },  /* 211 */
    { -91, 0, 1, 1, 5 },  /* 212 */
    { -96, 0, 1, 1, 5 },  /* 213 */
    { -80, 0, 1, 1, 5 },  /* 214 */
    { -91, 0, 1, 1, 5 },  /* 215 */
    { -102, 0, 1, 1, 5 },  /* 216 */
    { -71, -2, 1, 1, 5 },  /* 217 */
    { -94, -2, 1, 1, 5 },  /* 218 */
    { -84, 2, 1, 1, 5 },  /* 219 */
    { -84, 2, 1, 1, 5 },  /* 220 */
    { -83, 0, 1, 1, 5 },  /* 221 */
    { -84, 2, 1, 1, 5 },  /* 222 */
    { -84, 2, 1, 1, 5 },  /* 223 */
    { -83, 0, 1, 1, 6 },  /* 224 */
    { -90, 0, 1, 1, 6 },  /* 225 */
    { -83, 2, 1, 1, 6 },  /* 226 */
    { -94, -7, 1, 1, 6 },  /* 227 */
    { -90, -1, 1, 1, 6 },  /* 228 */
    { -96, 0, 1, 1, 6 },  /* 229 */
    { -86, 2, 1, 1, 6 },  /* 230 */
    { -89, 1, 1, 1, 6 },  /* 231 */
    { -96, 2, 1, 1, 6 },  /* 232 */
    { -115, 4, 1, 1, 6 },  /* 233 */
    { -94, -7, 1, 1, 6 },  /* 234 */
    { -83, 2, 1, 1, 6 },  /* 235 */
    { -83, 2, 1, 1, 6 },  /* 236 */
    { -83, 0, 1, 1, 6 },  /* 237 */
    { -83, 2, 1, 1, 6 },  /* 238 */
    { -83, 2, 1, 1, 6 },  /* 239 */
    { -83, 0, 1, 1, 7 },  /* 240 */
    { -44, -6, 1, 1, 7 },  /* 241 */
    { -61, 28, 1, 1, 7 },  /* 242 */
    { -69, 29, 1, 1, 7 },  /* 243 */
    { -81, 16, 1, 1, 7 },  /* 244 */
    { -92, 17, 1, 1, 7 },  /* 245 */
    { -79, -1, 1, 1, 7 },  /* 246 */
    { -78, 36, 1, 1, 7 },  /* 247 */
    { -78, 26, 1, 1, 7 },  /* 248 */
    { -69, 39, 1, 1, 7 },  /* 249 */
    { -69, 29, 1, 1, 7 },  /* 250 */
    { -61, 28, 1, 1, 7 },  /* 251 */
    { -61, 28, 1, 1, 7 },  /* 252 */
    { -83, 0, 1, 1, 7 },  /* 253 */
    { -61, 28, 1, 1, 7 },  /* 254 */
    { -61, 28, 1, 1, 7 },  /* 255 */
    { -18, 63, 1, 1, 8 },  /* 256 */
    { -31, 65, 1, 1, 8 },  /* 257 */
    { -19, 74, 1, 1, 8 },  /* 258 */
    { -24, 82, 1, 1, 8 },  /* 259 */
    { -18, 66, 1, 1, 8 },  /* 260 */
    { -18, 55, 1, 1, 8 },  /* 261 */
    { -20, 72, 1, 1, 8 },  /* 262 */
    { -34, 57, 1, 1, 8 },  /* 263 */
    { -42, 106, 1, 1, 8 },  /* 264 */
    { -7, 84, 1, 1, 8 },  /* 265 */
    { -24, 82, 1, 1, 8 },  /* 266 */
    { -19, 74, 1, 1, 8 },  /* 267 */
    { -19, 74, 1, 1, 8 },  /* 268 */
    { -18, 63, 1, 1, 8 },  /* 269 */
    { -19, 74, 1, 1, 8 },  /* 270 */
    { -19, 74, 1, 1, 8 },  /* 271 */
    { -11, 60, 1, 1, 9 },  /* 272 */
    { -13, 80, 1, 1, 9 },  /* 273 */
    { -17, 75, 1, 1, 9 },  /* 274 */
    { -11, 85, 1, 1, 9 },  /* 275 */
    { -18, 62, 1, 1, 9 },  /* 276 */
    { -16, 64, 1, 1, 9 },  /* 277 */
    { -12, 69, 1, 1, 9 },  /* 278 */
    { -31, 63, 1, 1, 9 },  /* 279 */
    { -32, 122, 1, 1, 9 },  /* 280 */
    { 0, 84, 1, 1, 9 },  /* 281 */
    { -11, 85, 1, 1, 9 },  /* 282 */
    { -17, 75, 1, 1, 9 },  /* 283 */
    { -17, 75, 1, 1, 9 },  /* 284 */
    { -11, 60, 1, 1, 9 },  /* 285 */
    { -17, 75, 1, 1, 9 },  /* 286 */
    { -17, 75, 1, 1, 9 },  /* 287 */
    { 43, 64, 1, 1, 10 },  /* 288 */
    { 42, 103, 1, 1, 10 },  /* 289 */
    { 33, 88, 1, 1, 10 },  /* 290 */
    { 24, 102, 1, 1, 10 },  /* 291 */
    { 33, 80, 1, 1, 10 },  /* 292 */
    { 46, 108, 1, 1, 10 },  /* 293 */
    { 43, 61, 1, 1, 10 },  /* 294 */
    { 24, 86, 1, 1, 10 },  /* 295 */
    { 30, 120, 1, 1, 10 },  /* 296 */
    { 40, 95, 1, 1, 10 },  /* 297 */
    { 24, 102, 1, 1, 10 },  /* 298 */
    { 33, 88, 1, 1, 10 },  /* 299 */
    { 33, 88, 1, 1, 10 },  /* 300 */
    { 43, 64, 1, 1, 10 },  /* 301 */
    { 33, 88, 1, 1, 10 },  /* 302 */
    { 33, 88, 1, 1, 10 },  /* 303 */
    { 75, 72, 1, 1, 11 },  /* 304 */
    { 70, 109, 1, 1, 11 },  /* 305 */
    { 63, 111, 1, 1, 11 },  /* 306 */
    { 58, 122, 1, 1, 11 },  /* 307 */
    { 64, 116, 1, 1, 11 },  /* 308 */
    { 84, 96, 1, 1, 11 },  /* 309 */
    { 75, 71, 1, 1, 11 },  /* 310 */
    { 55, 120, 1, 1, 11 },  /* 311 */
    { 80, 108, 1, 1, 11 },  /* 312 */
    { 62, 117, 1, 1, 11 },  /* 313 */
    { 58, 122, 1, 1, 11 },  /* 314 */
    { 63, 111, 1, 1, 11 },  /* 315 */
    { 63, 111, 1, 1, 11 },  /* 316 */
    { 75, 72, 1, 1, 11 },  /* 317 */
    { 63, 111, 1, 1, 11 },  /* 318 */
    { 63, 111, 1, 1, 11 },  /* 319 */
    { 78, 72, 1, 1, 12 },  /* 320 */
    { 72, 105, 1, 1, 12 },  /* 321 */
    { 62, 108, 1, 1, 12 },  /* 322 */
    { 100, 117, 1, 1, 12 },  /* 323 */
    { 66, 114, 1, 1, 12 },  /* 324 */
    { 85, 91, 1, 1, 12 },  /* 325 */
    { 69, 73, 1, 1, 12 },  /* 326 */
    { 63, 113, 1, 1, 12 },  /* 327 */
    { 114, 134, 1, 1, 12 },  /* 328 */
    { 66, 116, 1, 1, 12 },  /* 329 */
    { 100, 117, 1, 1, 12 },  /* 330 */
    { 62, 108, 1, 1, 12 },  /* 331 */
    { 62, 108, 1, 1, 12 },  /* 332 */
    { 78, 72, 1, 1, 12 },  /* 333 */
    { 62, 108, 1, 1, 12 },  /* 334 */
    { 62, 108, 1, 1, 12 },  /* 335 */
    { 69, 32, 1, 1, 13 },  /* 336 */
    { 56, 68, 1, 1, 13 },  /* 337 */
    { 49, 67, 1, 1, 13 },  /* 338 */
    { 87, 76, 1, 1, 13 },  /* 339 */
    { 52, 72, 1, 1, 13 },  /* 340 */
    { 73, 52, 1, 1, 13 },  /* 341 */
    { 58, 30, 1, 1, 13 },  /* 342 */
    { 46, 76, 1, 1, 13 },  /* 343 */
    { 100, 90, 1, 1, 13 },  /* 344 */
    { 54, 69, 1, 1, 13 },  /* 345 */
    { 87, 76, 1, 1, 13 },  /* 346 */
    { 49, 67, 1, 1, 13 },  /* 347 */
    { 49, 67, 1, 1, 13 },  /* 348 */
    { 69, 32, 1, 1, 13 },  /* 349 */
    { 49, 67, 1, 1, 13 },  /* 350 */
    { 49, 67, 1, 1, 13 },  /* 351 */
    { 81, -13, 1, 1, 14 },  /* 352 */
    { 65, -11, 1, 1, 14 },  /* 353 */
    { 49, -4, 1, 1, 14 },  /* 354 */
    { 54, -5, 1, 1, 14 },  /* 355 */
    { 49, -3, 1, 1, 14 },  /* 356 */
    { 84, -6, 1, 1, 14 },  /* 357 */
    { 67, -13, 1, 1, 14 },  /* 358 */
    { 57, -19, 1, 1, 14 },  /* 359 */
    { 100, -22, 1, 1, 14 },  /* 360 */
    { 53, -11, 1, 1, 14 },  /* 361 */
    { 54, -5, 1, 1, 14 },  /* 362 */
    { 49, -4, 1, 1, 14 },  /* 363 */
    { 49, -4, 1, 1, 14 },  /* 364 */
    { 81, -13, 1, 1, 14 },  /* 365 */
    { 49, -4, 1, 1, 14 },  /* 366 */
    { 49, -4, 1, 1, 14 },  /* 367 */
    { 71, -8, 1, 1, 15 },  /* 368 */
    { 65, -11, 1, 1, 15 },  /* 369 */
    { 49, -4, 1, 1, 15 },  /* 370 */
    { 54, -5, 1, 1, 15 },  /* 371 */
    { 49, -2, 1, 1, 15 },  /* 372 */
    { 84, -3, 1, 1, 15 },  /* 373 */
    { 63, -8, 1, 1, 15 },  /* 374 */
    { 57, -5, 1, 1, 15 },  /* 375 */
    { 98, -12, 1, 1, 15 },  /* 376 */
    { 53, -6, 1, 1, 15 },  /* 377 */
    { 54, -5, 1, 1, 15 },  /* 378 */
    { 49, -4, 1, 1, 15 },  /* 379 */
    { 49, -4, 1, 1, 15 },  /* 380 */
    { 71, -8, 1, 1, 15 },  /* 381 */
    { 49, -4, 1, 1, 15 },  /* 382 */
    { 49, -4, 1, 1, 15 },  /* 383 */
    { 65, 0, 1, 1, 16 },  /* 384 */
    { 65, 0, 1, 1, 16 },  /* 385 */
    { 49, -4, 1, 1, 16 },  /* 386 */
    { 54, -5, 1, 1, 16 },  /* 387 */
    { 49, -1, 1, 1, 16 },  /* 388 */
    { 84, -3, 1, 1, 16 },  /* 389 */
    { 61, -6, 1, 1, 16 },  /* 390 */
    { 57, -4, 1, 1, 16 },  /* 391 */
    { 94, -16, 1, 1, 16 },  /* 392 */
    { 53, -6, 1, 1, 16 },  /* 393 */
    { 54, -5, 1, 1, 16 },  /* 394 */
    { 49, -4, 1, 1, 16 },  /* 395 */
    { 49, -4, 1, 1, 16 },  /* 396 */
    { 65, 0, 1, 1, 16 },  /* 397 */
    { 49, -4, 1, 1, 16 },  /* 398 */
    { 49, -4, 1, 1, 16 },  /* 399 */
    { 72, 0, 1, 1, 17 },  /* 400 */
    { 65, 0, 1, 1, 17 },  /* 401 */
    { 49, -3, 1, 1, 17 },  /* 402 */
    { 54, -4, 1, 1, 17 },  /* 403 */
    { 49, 0, 1, 1, 17 },  /* 404 */
    { 84, -2, 1, 1, 17 },  /* 405 */
    { 56, -6, 1, 1, 17 },  /* 406 */
    { 57, -4, 1, 1, 17 },  /* 407 */
    { 60, 2, 1, 1, 17 },  /* 408 */
    { 53, -5, 1, 1, 17 },  /* 409 */
    { 54, -4, 1, 1, 17 },  /* 410 */
    { 49, -3, 1, 1, 17 },  /* 411 */
    { 49, -3, 1, 1, 17 },  /* 412 */
    { 72, 0, 1, 1, 17 },  /* 413 */
    { 49, -3, 1, 1, 17 },  /* 414 */
    { 49, -3, 1, 1, 17 },  /* 415 */
    { 72, 0, 1, 1, 18 },  /* 416 */
    { 65, 0, 1, 1, 18 },  /* 417 */
    { 49, -2, 1, 1, 18 },  /* 418 */
    { 35, -2, 1, 1, 18 },  /* 419 */
    { 49, 0, 1, 1, 18 },  /* 420 */
    { 84, -2, 1, 1, 18 },  /* 421 */
    { 67, 0, 1, 1, 18 },  /* 422 */
    { 57, -4, 1, 1, 18 },  /* 423 */
    { 70, 8, 1, 1, 18 },  /* 424 */
    { 53, -4, 1, 1, 18 },  /* 425 */
    { 35, -2, 1, 1, 18 },  /* 426 */
    { 49, -2, 1, 1, 18 },  /* 427 */
    { 49, -2, 1, 1, 18 },  /* 428 */
    { 72, 0, 1, 1, 18 },  /* 429 */
    { 49, -2, 1, 1, 18 },  /* 430 */
    { 49, -2, 1, 1, 18 },  /* 431 */
    { 72, 0, 1, 1, 19 },  /* 432 */
    { 65, 0, 1, 1, 19 },  /* 433 */
    { 49, -2, 1, 1, 19 },  /* 434 */
    { 35, -5, 1, 1, 19 },  /* 435 */
    { 49, 0, 1, 1, 19 },  /* 436 */
    { 84, -2, 1, 1, 19 },  /* 437 */
    { 66, 0, 1, 1, 19 },  /* 438 */
    { 57, -4, 1, 1, 19 },  /* 439 */
    { 72, 14, 1, 1, 19 },  /* 440 */
    { 53, -4, 1, 1, 19 },  /* 441 */
    { 35, -5, 1, 1, 19 },  /* 442 */
    { 49, -2, 1, 1, 19 },  /* 443 */
    { 49, -2, 1, 1, 19 },  /* 444 */
    { 72, 0, 1, 1, 19 },  /* 445 */
    { 49, -2, 1, 1, 19 },  /* 446 */
    { 49, -2, 1, 1, 19 },  /* 447 */
    { 72, 0, 1, 0, 20 },  /* 448 */
    { 65, 0, 1, 0, 20 },  /* 449 */
    { 49, -2, 1, 0, 20 },  /* 450 */
    { 35, 0, 1, 0, 20 },  /* 451 */
    { 49, 0, 1, 0, 20 },  /* 452 */
    { 84, -2, 1, 0, 20 },  /* 453 */
    { 70, 0, 1, 0, 20 },  /* 454 */
    { 57, -4, 1, 0, 20 },  /* 455 */
    { 74, 0, 1, 0, 20 },  /* 456 */
    { 53, -4, 1, 0, 20 },  /* 457 */
    { 35, 0, 1, 0, 20 },  /* 458 */
    { 49, -2, 1, 0, 20 },  /* 459 */
    { 49, -2, 1, 0, 20 },  /* 460 */
    { 72, 0, 1, 0, 20 },  /* 461 */
    { 49, -2, 1, 0, 20 },  /* 462 */
    { 49, -2, 1, 0, 20 },  /* 463 */
    { -130, 0, 1, 0, 1 },  /* 464 */
    { -152, 0, 1, 0, 1 },  /* 465 */
    { -136, 0, 1, 0, 1 },  /* 466 */
    { -132, 0, 1, 0, 1 },  /* 467 */
    { -128, 0, 1, 0, 1 },  /* 468 */
    { -106, 0, 1, 0, 1 },  /* 469 */
    { -133, 0, 1, 0, 1 },  /* 470 */
    { -130, 0, 1, 0, 1 },  /* 471 */
    { -112, 0, 1, 0, 1 },  /* 472 */
    { -130, 0, 1, 0, 1 },  /* 473 */
    { -132, 0, 1, 0, 1 },  /* 474 */
    { -136, 0, 1, 0, 1 },  /* 475 */
    { -136, 0, 1, 0, 1 },  /* 476 */
    { -130, 0, 1, 0, 1 },  /* 477 */
    { -136, 0, 1, 0, 1 },  /* 478 */
    { -136, 0, 1, 0, 1 },  /* 479 */
    { -132, 0, 1, 0, 2 },  /* 480 */
    { -136, 0, 1, 0, 2 },  /* 481 */
    { -118, 0, 1, 0, 2 },  /* 482 */
    { -110, 0, 1, 0, 2 },  /* 483 */
    { -119, 0, 1, 0, 2 },  /* 484 */
    { -107, 0, 1, 0, 2 },  /* 485 */
    { -126, 0, 1, 0, 2 },  /* 486 */
    { -118, 0, 1, 0, 2 },  /* 487 */
    { -90, 0, 1, 0, 2 },  /* 488 */
    { -119, 0, 1, 0, 2 },  /* 489 */
    { -110, 0, 1, 0, 2 },  /* 490 */
    { -118, 0, 1, 0, 2 },  /* 491 */
    { -118, 0, 1, 0, 2 },  /* 492 */
    { -132, 0, 1, 0, 2 },  /* 493 */
    { -118, 0, 1, 0, 2 },  /* 494 */
    { -118, 0, 1, 0, 2 },  /* 495 */
    { -134, 0, 1, 0, 3 },  /* 496 */
    { -134, 0, 1, 0, 3 },  /* 497 */
    { -118, 0, 1, 0, 3 },  /* 498 */
    { -108, 0, 1, 0, 3 },  /* 499 */
    { -123, 0, 1, 0, 3 },  /* 500 */
    { -112, 0, 1, 0, 3 },  /* 501 */
    { -129, 0, 1, 0, 3 },  /* 502 */
    { -106, 0, 1, 0, 3 },  /* 503 */
    { -96, 0, 1, 0, 3 },  /* 504 */
    { -116, 0, 1, 0, 3 },  /* 505 */
    { -108, 0, 1, 0, 3 },  /* 506 */
    { -118, 0, 1, 0, 3 },  /* 507 */
    { -118, 0, 1, 0, 3 },  /* 508 */
    { -134, 0, 1, 0, 3 },  /* 509 */
    { -118, 0, 1, 0, 3 },  /* 510 */
    { -118, 0, 1, 0, 3 },  /* 511 */
    { -130, 0, 1, 0, 4 },  /* 512 */
    { -134, 0, 1, 0, 4 },  /* 513 */
    { -116, 0, 1, 0, 4 },  /* 514 */
    { -117, 0, 1, 0, 4 },  /* 515 */
    { -124, 0, 1, 0, 4 },  /* 516 */
    { -114, 0, 1, 0, 4 },  /* 517 */
    { -133, 0, 1, 0, 4 },  /* 518 */
    { -114, 0, 1, 0, 4 },  /* 519 */
    { -92, 0, 1, 0, 4 },  /* 520 */
    { -113, 0, 1, 0, 4 },  /* 521 */
    { -117, 0, 1, 0, 4 },  /* 522 */
    { -116, 0, 1, 0, 4 },  /* 523 */
    { -116, 0, 1, 0, 4 },  /* 524 */
    { -130, 0, 1, 0, 4 },  /* 525 */
    { -116, 0, 1, 0, 4 },  /* 526 */
    { -116, 0, 1, 0, 4 },  /* 527 */
    { -126, 0, 1, 0, 5 },  /* 528 */
    { -129, 0, 1, 0, 5 },  /* 529 */
    { -115, 0, 1, 0, 5 },  /* 530 */
    { -116, 0, 1, 0, 5 },  /* 531 */
    { -120, 0, 1, 0, 5 },  /* 532 */
    { -115, 0, 1, 0, 5 },  /* 533 */
    { -130, 0, 1, 0, 5 },  /* 534 */
    { -117, 0, 1, 0, 5 },  /* 535 */
    { -92, 0, 1, 0, 5 },  /* 536 */
    { -103, 0, 1, 0, 5 },  /* 537 */
    { -116, 0, 1, 0, 5 },  /* 538 */
    { -115, 0, 1, 0, 5 },  /* 539 */
    { -115, 0, 1, 0, 5 },  /* 540 */
    { -126, 0, 1, 0, 5 },  /* 541 */
    { -115, 0, 1, 0, 5 },  /* 542 */
    { -115, 0, 1, 0, 5 },  /* 543 */
    { -124, 0, 1, 0, 6 },  /* 544 */
    { -124, 0, 1, 0, 6 },  /* 545 */
    { -110, 0, 1, 0, 6 },  /* 546 */
    { -128, 0, 1, 0, 6 },  /* 547 */
    { -111, 0, 1, 0, 6 },  /* 548 */
    { -111, 0, 1, 0, 6 },  /* 549 */
    { -133, 2, 1, 0, 6 },  /* 550 */
    { -100, 0, 1, 0, 6 },  /* 551 */
    { -86, 0, 1, 0, 6 },  /* 552 */
    { -100, 0, 1, 0, 6 },  /* 553 */
    { -128, 0, 1, 0, 6 },  /* 554 */
    { -110, 0, 1, 0, 6 },  /* 555 */
    { -110, 0, 1, 0, 6 },  /* 556 */
    { -124, 0, 1, 0, 6 },  /* 557 */
    { -110, 0, 1, 0, 6 },  /* 558 */
    { -110, 0, 1, 0, 6 },  /* 559 */
    { -136, 0, 1, 0, 7 },  /* 560 */
    { -130, 0, 1, 0, 7 },  /* 561 */
    { -99, 0, 1, 0, 7 },  /* 562 */
    { -127, 0, 1, 0, 7 },  /* 563 */
    { -108, 0, 1, 0, 7 },  /* 564 */
    { -108, 0, 1, 0, 7 },  /* 565 */
    { -127, 0, 1, 0, 7 },  /* 566 */
    { -95, 0, 1, 0, 7 },  /* 567 */
    { -92, 0, 1, 0, 7 },  /* 568 */
    { -122, 0, 1, 0, 7 },  /* 569 */
    { -127, 0, 1, 0, 7 },  /* 570 */
    { -99, 0, 1, 0, 7 },  /* 571 */
    { -99, 0, 1, 0, 7 },  /* 572 */
    { -136, 0, 1, 0, 7 },  /* 573 */
    { -99, 0, 1, 0, 7 },  /* 574 */
    { -99, 0, 1, 0, 7 },  /* 575 */
    { -140, -29, 1, 0, 8 },  /* 576 */
    { -139, -11, 1, 0, 8 },  /* 577 */
    { -93, 0, 1, 0, 8 },  /* 578 */
    { -116, 0, 1, 0, 8 },  /* 579 */
    { -99, -3, 1, 0, 8 },  /* 580 */
    { -106, -3, 1, 0, 8 },  /* 581 */
    { -139, -16, 1, 0, 8 },  /* 582 */
    { -83, -3, 1, 0, 8 },  /* 583 */
    { -90, 0, 1, 0, 8 },  /* 584 */
    { -110, 4, 1, 0, 8 },  /* 585 */
    { -116, 0, 1, 0, 8 },  /* 586 */
    { -93, 0, 1, 0, 8 },  /* 587 */
    { -93, 0, 1, 0, 8 },  /* 588 */
    { -140, -29, 1, 0, 8 },  /* 589 */
    { -93, 0, 1, 0, 8 },  /* 590 */
    { -93, 0, 1, 0, 8 },  /* 591 */
    { -130, -31, 1, 0, 9 },  /* 592 */
    { -119, -16, 1, 0, 9 },  /* 593 */
    { -109, 16, 1, 0, 9 },  /* 594 */
    { -109, 10, 1, 0, 9 },  /* 595 */
    { -108, 1, 1, 0, 9 },  /* 596 */
    { -76, 20, 1, 0, 9 },  /* 597 */
    { -130, 2, 1, 0, 9 },  /* 598 */
    { -92, 8, 1, 0, 9 },  /* 599 */
    { -88, 16, 1, 0, 9 },  /* 600 */
    { -104, -4, 1, 0, 9 },  /* 601 */
    { -109, 10, 1, 0, 9 },  /* 602 */
    { -109, 16, 1, 0, 9 },  /* 603 */
    { -109, 16, 1, 0, 9 },  /* 604 */
    { -130, -31, 1, 0, 9 },  /* 605 */
    { -109, 16, 1, 0, 9 },  /* 606 */
    { -109, 16, 1, 0, 9 },  /* 607 */
    { -106, -11, 1, 0, 10 },  /* 608 */
    { -104, 12, 1, 0, 10 },  /* 609 */
    { -95, 5, 1, 0, 10 },  /* 610 */
    { -97, 24, 1, 0, 10 },  /* 611 */
    { -99, 3, 1, 0, 10 },  /* 612 */
    { -88, 7, 1, 0, 10 },  /* 613 */
    { -117, 25, 1, 0, 10 },  /* 614 */
    { -75, -1, 1, 0, 10 },  /* 615 */
    { -56, 32, 1, 0, 10 },  /* 616 */
    { -97, 20, 1, 0, 10 },  /* 617 */
    { -97, 24, 1, 0, 10 },  /* 618 */
    { -95, 5, 1, 0, 10 },  /* 619 */
    { -95, 5, 1, 0, 10 },  /* 620 */
    { -106, -11, 1, 0, 10 },  /* 621 */
    { -95, 5, 1, 0, 10 },  /* 622 */
    { -95, 5, 1, 0, 10 },  /* 623 */
    { -62, 38, 1, 0, 11 },  /* 624 */
    { -62, 67, 1, 0, 11 },  /* 625 */
    { -52, 42, 1, 0, 11 },  /* 626 */
    { -60, 51, 1, 0, 11 },  /* 627 */
    { -69, 29, 1, 0, 11 },  /* 628 */
    { -51, 46, 1, 0, 11 },  /* 629 */
    { -97, 18, 1, 0, 11 },  /* 630 */
    { -38, 34, 1, 0, 11 },  /* 631 */
    { -72, 76, 1, 0, 11 },  /* 632 */
    { -60, 50, 1, 0, 11 },  /* 633 */
    { -60, 51, 1, 0, 11 },  /* 634 */
    { -52, 42, 1, 0, 11 },  /* 635 */
    { -52, 42, 1, 0, 11 },  /* 636 */
    { -62, 38, 1, 0, 11 },  /* 637 */
    { -52, 42, 1, 0, 11 },  /* 638 */
    { -52, 42, 1, 0, 11 },  /* 639 */
    { -3, 80, 1, 0, 12 },  /* 640 */
    { -3, 80, 1, 0, 12 },  /* 641 */
    { 10, 71, 1, 0, 12 },  /* 642 */
    { 18, 81, 1, 0, 12 },  /* 643 */
    { -6, 56, 1, 0, 12 },  /* 644 */
    { -2, 64, 1, 0, 12 },  /* 645 */
    { -21, 81, 1, 0, 12 },  /* 646 */
    { 8, 67, 1, 0, 12 },  /* 647 */
    { 6, 92, 1, 0, 12 },  /* 648 */
    { -9, 73, 1, 0, 12 },  /* 649 */
    { 18, 81, 1, 0, 12 },  /* 650 */
    { 10, 71, 1, 0, 12 },  /* 651 */
    { 10, 71, 1, 0, 12 },  /* 652 */
    { -3, 80, 1, 0, 12 },  /* 653 */
    { 10, 71, 1, 0, 12 },  /* 654 */
    { 10, 71, 1, 0, 12 },  /* 655 */
    { 41, 115, 1, 1, 13 },  /* 656 */
    { 41, 115, 1, 1, 13 },  /* 657 */
    { 48, 115, 1, 1, 13 },  /* 658 */
    { 48, 112, 1, 1, 13 },  /* 659 */
    { 32, 98, 1, 1, 13 },  /* 660 */
    { 36, 106, 1, 1, 13 },  /* 661 */
    { 113, 42, 1, 1, 13 },  /* 662 */
    { 47, 106, 1, 1, 13 },  /* 663 */
    { 52, 118, 1, 1, 13 },  /* 664 */
    { 37, 117, 1, 1, 13 },  /* 665 */
    { 48, 112, 1, 1, 13 },  /* 666 */
    { 48, 115, 1, 1, 13 },  /* 667 */
    { 48, 115, 1, 1, 13 },  /* 668 */
    { 41, 115, 1, 1, 13 },  /* 669 */
    { 48, 115, 1, 1, 13 },  /* 670 */
    { 48, 115, 1, 1, 13 },  /* 671 */
    { -19, -73, 1, 1, 1 },  /* 672 */
    { -10, -56, 1, 1, 1 },  /* 673 */
    { -18, -48, 1, 1, 1 },  /* 674 */
    { -6, -33, 1, 1, 1 },  /* 675 */
    { -13, -54, 1, 1, 1 },  /* 676 */
    { -19, -36, 1, 1, 1 },  /* 677 */
    { -20, -76, 1, 1, 1 },  /* 678 */
    { -33, -39, 1, 1, 1 },  /* 679 */
    { -32, -42, 1, 1, 1 },  /* 680 */
    { -21, -30, 1, 1, 1 },  /* 681 */
    { -6, -33, 1, 1, 1 },  /* 682 */
    { -18, -48, 1, 1, 1 },  /* 683 */
    { -18, -48, 1, 1, 1 },  /* 684 */
    { -19, -73, 1, 1, 1 },  /* 685 */
    { -18, -48, 1, 1, 1 },  /* 686 */
    { -18, -48, 1, 1, 1 },  /* 687 */
    { -22, -61, 1, 1, 2 },  /* 688 */
    { -21, -51, 1, 1, 2 },  /* 689 */
    { -23, -47, 1, 1, 2 },  /* 690 */
    { -13, -32, 1, 1, 2 },  /* 691 */
    { -11, -54, 1, 1, 2 },  /* 692 */
    { -26, -36, 1, 1, 2 },  /* 693 */
    { -27, -80, 1, 1, 2 },  /* 694 */
    { -33, -38, 1, 1, 2 },  /* 695 */
    { -33, -38, 1, 1, 2 },  /* 696 */
    { -16, -30, 1, 1, 2 },  /* 697 */
    { -13, -32, 1, 1, 2 },  /* 698 */
    { -23, -47, 1, 1, 2 },  /* 699 */
    { -23, -47, 1, 1, 2 },  /* 700 */
    { -22, -61, 1, 1, 2 },  /* 701 */
    { -23, -47, 1, 1, 2 },  /* 702 */
    { -23, -47, 1, 1, 2 },  /* 703 */
    { -59, -58, 1, 1, 3 },  /* 704 */
    { -23, -57, 1, 1, 3 },  /* 705 */
    { -27, -47, 1, 1, 3 },  /* 706 */
    { -10, -44, 1, 1, 3 },  /* 707 */
    { -21, -68, 1, 1, 3 },  /* 708 */
    { -44, -44, 1, 1, 3 },  /* 709 */
    { -30, -91, 1, 1, 3 },  /* 710 */
    { -22, -51, 1, 1, 3 },  /* 711 */
    { -30, -57, 1, 1, 3 },  /* 712 */
    { -16, -48, 1, 1, 3 },  /* 713 */
    { -10, -44, 1, 1, 3 },  /* 714 */
    { -27, -47, 1, 1, 3 },  /* 715 */
    { -27, -47, 1, 1, 3 },  /* 716 */
    { -59, -58, 1, 1, 3 },  /* 717 */
    { -27, -47, 1, 1, 3 },  /* 718 */
    { -27, -47, 1, 1, 3 },  /* 719 */
    { -53, -49, 1, 1, 4 },  /* 720 */
    { -14, -49, 1, 1, 4 },  /* 721 */
    { -24, -49, 1, 1, 4 },  /* 722 */
    { -10, -43, 1, 1, 4 },  /* 723 */
    { -16, -58, 1, 1, 4 },  /* 724 */
    { -37, -45, 1, 1, 4 },  /* 725 */
    { -23, -88, 1, 1, 4 },  /* 726 */
    { -19, -49, 1, 1, 4 },  /* 727 */
    { -29, -58, 1, 1, 4 },  /* 728 */
    { -15, -50, 1, 1, 4 },  /* 729 */
    { -10, -43, 1, 1, 4 },  /* 730 */
    { -24, -49, 1, 1, 4 },  /* 731 */
    { -24, -49, 1, 1, 4 },  /* 732 */
    { -53, -49, 1, 1, 4 },  /* 733 */
    { -24, -49, 1, 1, 4 },  /* 734 */
    { -24, -49, 1, 1, 4 },  /* 735 */
    { -45, -50, 1, 1, 5 },  /* 736 */
    { -13, -50, 1, 1, 5 },  /* 737 */
    { -20, -50, 1, 1, 5 },  /* 738 */
    { -9, -44, 1, 1, 5 },  /* 739 */
    { -13, -60, 1, 1, 5 },  /* 740 */
    { -36, -46, 1, 1, 5 },  /* 741 */
    { -25, -96, 1, 1, 5 },  /* 742 */
    { -19, -54, 1, 1, 5 },  /* 743 */
    { -27, -62, 1, 1, 5 },  /* 744 */
    { -14, -51, 1, 1, 5 },  /* 745 */
    { -9, -44, 1, 1, 5 },  /* 746 */
    { -20, -50, 1, 1, 5 },  /* 747 */
    { -20, -50, 1, 1, 5 },  /* 748 */
    { -45, -50, 1, 1, 5 },  /* 749 */
    { -20, -50, 1, 1, 5 },  /* 750 */
    { -20, -50, 1, 1, 5 },  /* 751 */
    { -51, -44, 1, 1, 6 },  /* 752 */
    { -22, -46, 1, 1, 6 },  /* 753 */
    { -27, -48, 1, 1, 6 },  /* 754 */
    { -17, -40, 1, 1, 6 },  /* 755 */
    { -26, -57, 1, 1, 6 },  /* 756 */
    { -42, -39, 1, 1, 6 },  /* 757 */
    { -18, -90, 1, 1, 6 },  /* 758 */
    { -31, -56, 1, 1, 6 },  /* 759 */
    { -32, -57, 1, 1, 6 },  /* 760 */
    { -23, -42, 1, 1, 6 },  /* 761 */
    { -17, -40, 1, 1, 6 },  /* 762 */
    { -27, -48, 1, 1, 6 },  /* 763 */
    { -27, -48, 1, 1, 6 },  /* 764 */
    { -51, -44, 1, 1, 6 },  /* 765 */
    { -27, -48, 1, 1, 6 },  /* 766 */
    { -27, -48, 1, 1, 6 },  /* 767 */
    { -66, -20, 1, 1, 7 },  /* 768 */
    { -43, -34, 1, 1, 7 },  /* 769 */
    { -43, -34, 1, 1, 7 },  /* 770 */
    { -37, -29, 1, 1, 7 },  /* 771 */
    { -46, -47, 1, 1, 7 },  /* 772 */
    { -62, -27, 1, 1, 7 },  /* 773 */
    { -46, -75, 1, 1, 7 },  /* 774 */
    { -54, -36, 1, 1, 7 },  /* 775 */
    { -56, -41, 1, 1, 7 },  /* 776 */
    { -43, -24, 1, 1, 7 },  /* 777 */
    { -37, -29, 1, 1, 7 },  /* 778 */
    { -43, -34, 1, 1, 7 },  /* 779 */
    { -43, -34, 1, 1, 7 },  /* 780 */
    { -66, -20, 1, 1, 7 },  /* 781 */
    { -43, -34, 1, 1, 7 },  /* 782 */
    { -43, -34, 1, 1, 7 },  /* 783 */
    { -68, -34, 1, 1, 8 },  /* 784 */
    { -43, -34, 1, 1, 8 },  /* 785 */
    { -47, -38, 1, 1, 8 },  /* 786 */
    { -40, -32, 1, 1, 8 },  /* 787 */
    { -45, -48, 1, 1, 8 },  /* 788 */
    { -63, -29, 1, 1, 8 },  /* 789 */
    { -24, -82, 1, 1, 8 },  /* 790 */
    { -57, -41, 1, 1, 8 },  /* 791 */
    { -57, -38, 1, 1, 8 },  /* 792 */
    { -60, -29, 1, 1, 8 },  /* 793 */
    { -40, -32, 1, 1, 8 },  /* 794 */
    { -47, -38, 1, 1, 8 },  /* 795 */
    { -47, -38, 1, 1, 8 },  /* 796 */
    { -68, -34, 1, 1, 8 },  /* 797 */
    { -47, -38, 1, 1, 8 },  /* 798 */
    { -47, -38, 1, 1, 8 },  /* 799 */
    { -76, -21, 1, 1, 9 },  /* 800 */
    { -54, -21, 1, 1, 9 },  /* 801 */
    { -55, -28, 1, 1, 9 },  /* 802 */
    { -47, -18, 1, 1, 9 },  /* 803 */
    { -55, -37, 1, 1, 9 },  /* 804 */
    { -68, -15, 1, 1, 9 },  /* 805 */
    { -39, -68, 1, 1, 9 },  /* 806 */
    { -63, -23, 1, 1, 9 },  /* 807 */
    { -63, -21, 1, 1, 9 },  /* 808 */
    { -64, -15, 1, 1, 9 },  /* 809 */
    { -47, -18, 1, 1, 9 },  /* 810 */
    { -55, -28, 1, 1, 9 },  /* 811 */
    { -55, -28, 1, 1, 9 },  /* 812 */
    { -76, -21, 1, 1, 9 },  /* 813 */
    { -55, -28, 1, 1, 9 },  /* 814 */
    { -55, -28, 1, 1, 9 },  /* 815 */
    { -64, -29, 1, 1, 10 },  /* 816 */
    { -56, -11, 1, 1, 10 },  /* 817 */
    { -55, -20, 1, 1, 10 },  /* 818 */
    { -48, -11, 1, 1, 10 },  /* 819 */
    { -56, -28, 1, 1, 10 },  /* 820 */
    { -72, -6, 1, 1, 10 },  /* 821 */
    { -56, -57, 1, 1, 10 },  /* 822 */
    { -66, -6, 1, 1, 10 },  /* 823 */
    { -65, -16, 1, 1, 10 },  /* 824 */
    { -63, -9, 1, 1, 10 },  /* 825 */
    { -48, -11, 1, 1, 10 },  /* 826 */
    { -55, -20, 1, 1, 10 },  /* 827 */
    { -55, -20, 1, 1, 10 },  /* 828 */
    { -64, -29, 1, 1, 10 },  /* 829 */
    { -55, -20, 1, 1, 10 },  /* 830 */
    { -55, -20, 1, 1, 10 },  /* 831 */
    { -66, -17, 1, 1, 11 },  /* 832 */
    { -56, -3, 1, 1, 11 },  /* 833 */
    { -51, -4, 1, 1, 11 },  /* 834 */
    { -51, 2, 1, 1, 11 },  /* 835 */
    { -63, -17, 1, 1, 11 },  /* 836 */
    { -73, 7, 1, 1, 11 },  /* 837 */
    { -75, -40, 1, 1, 11 },  /* 838 */
    { -69, 6, 1, 1, 11 },  /* 839 */
    { -75, -4, 1, 1, 11 },  /* 840 */
    { -76, 1, 1, 1, 11 },  /* 841 */
    { -51, 2, 1, 1, 11 },  /* 842 */
    { -51, -4, 1, 1, 11 },  /* 843 */
    { -51, -4, 1, 1, 11 },  /* 844 */
    { -66, -17, 1, 1, 11 },  /* 845 */
    { -51, -4, 1, 1, 11 },  /* 846 */
    { -51, -4, 1, 1, 11 },  /* 847 */
    { -70, -2, 1, 1, 12 },  /* 848 */
    { -65, -5, 1, 1, 12 },  /* 849 */
    { -50, 10, 1, 1, 12 },  /* 850 */
    { -77, 13, 1, 1, 12 },  /* 851 */
    { -62, 0, 1, 1, 12 },  /* 852 */
    { -71, 8, 1, 1, 12 },  /* 853 */
    { -80, -15, 1, 1, 12 },  /* 854 */
    { -69, 18, 1, 1, 12 },  /* 855 */
    { -69, 13, 1, 1, 12 },  /* 856 */
    { -69, 20, 1, 1, 12 },  /* 857 */
    { -77, 13, 1, 1, 12 },  /* 858 */
    { -50, 10, 1, 1, 12 },  /* 859 */
    { -50, 10, 1, 1, 12 },  /* 860 */
    { -70, -2, 1, 1, 12 },  /* 861 */
    { -50, 10, 1, 1, 12 },  /* 862 */
    { -50, 10, 1, 1, 12 },  /* 863 */
    { 48, 88, 1, 1, 13 },  /* 864 */
    { 48, 88, 1, 1, 13 },  /* 865 */
    { 71, 103, 1, 1, 13 },  /* 866 */
    { 48, 104, 1, 1, 13 },  /* 867 */
    { 56, 108, 1, 1, 13 },  /* 868 */
    { 48, 96, 1, 1, 13 },  /* 869 */
    { 93, 53, 1, 1, 13 },  /* 870 */
    { 48, 104, 1, 1, 13 },  /* 871 */
    { 41, 108, 1, 1, 13 },  /* 872 */
    { 40, 88, 1, 1, 13 },  /* 873 */
    { 48, 104, 1, 1, 13 },  /* 874 */
    { 71, 103, 1, 1, 13 },  /* 875 */
    { 71, 103, 1, 1, 13 },  /* 876 */
    { 48, 88, 1, 1, 13 },  /* 877 */
    { 71, 103, 1, 1, 13 },  /* 878 */
    { 71, 103, 1, 1, 13 },  /* 879 */
    { -10, -22, 1, 1, 15 },  /* 880 */
    { 10, -7, 1, 1, 15 },  /* 881 */
    { 3, -9, 1, 1, 15 },  /* 882 */
    { 5, 29, 1, 1, 15 },  /* 883 */
    { -10, -14, 1, 1, 15 },  /* 884 */
    { -3, -1, 1, 1, 15 },  /* 885 */
    { -9, 0, 1, 1, 15 },  /* 886 */
    { -24, -6, 1, 1, 15 },  /* 887 */
    { 12, -1, 1, 1, 15 },  /* 888 */
    { 7, 0, 1, 1, 15 },  /* 889 */
    { 5, 29, 1, 1, 15 },  /* 890 */
    { 3, -9, 1, 1, 15 },  /* 891 */
    { 3, -9, 1, 1, 15 },  /* 892 */
    { -10, -22, 1, 1, 15 },  /* 893 */
    { 3, -9, 1, 1, 15 },  /* 894 */
    { 3, -9, 1, 1, 15 },  /* 895 */
    { -36, -4, 1, 1, 16 },  /* 896 */
    { -16, -7, 1, 1, 16 },  /* 897 */
    { -18, -11, 1, 1, 16 },  /* 898 */
    { -29, 29, 1, 1, 16 },  /* 899 */
    { -35, -22, 1, 1, 16 },  /* 900 */
    { -23, 0, 1, 1, 16 },  /* 901 */
    { -32, 3, 1, 1, 16 },  /* 902 */
    { -35, -5, 1, 1, 16 },  /* 903 */
    { -19, -8, 1, 1, 16 },  /* 904 */
    { -30, 0, 1, 1, 16 },  /* 905 */
    { -29, 29, 1, 1, 16 },  /* 906 */
    { -18, -11, 1, 1, 16 },  /* 907 */
    { -18, -11, 1, 1, 16 },  /* 908 */
    { -36, -4, 1, 1, 16 },  /* 909 */
    { -18, -11, 1, 1, 16 },  /* 910 */
    { -18, -11, 1, 1, 16 },  /* 911 */
    { -36, 4, 1, 1, 17 },  /* 912 */
    { -18, -1, 1, 1, 17 },  /* 913 */
    { -18, -9, 1, 1, 17 },  /* 914 */
    { -19, -3, 1, 1, 17 },  /* 915 */
    { -21, 17, 1, 1, 17 },  /* 916 */
    { -30, 5, 1, 1, 17 },  /* 917 */
    { -34, 2, 1, 1, 17 },  /* 918 */
    { -20, 11, 1, 1, 17 },  /* 919 */
    { -8, -4, 1, 1, 17 },  /* 920 */
    { -28, 1, 1, 1, 17 },  /* 921 */
    { -19, -3, 1, 1, 17 },  /* 922 */
    { -18, 9, 1, 1, 17 },  /* 923 */
    { -18, 9, 1, 1, 17 },  /* 924 */
    { -36, 4, 1, 1, 17 },  /* 925 */
    { -18, -9, 1, 1, 17 },  /* 926 */
    { -18, -9, 1, 1, 17 },  /* 927 */
    { -30, 4, 1, 1, 18 },  /* 928 */
    { -20, -5, 1, 1, 18 },  /* 929 */
    { -15, -9, 1, 1, 18 },  /* 930 */
    { -16, -5, 1, 1, 18 },  /* 931 */
    { -21, 12, 1, 1, 18 },  /* 932 */
    { -18, 13, 1, 1, 18 },  /* 933 */
    { -17, -20, 1, 1, 18 },  /* 934 */
    { -18, -16, 1, 1, 18 },  /* 935 */
    { -13, 16, 1, 1, 18 },  /* 936 */
    { -13, -4, 1, 1, 18 },  /* 937 */
    { -16, -5, 1, 1, 18 },  /* 938 */
    { 71, 103, 1, 1, 18 },  /* 939 */
    { -15, 9, 1, 1, 18 },  /* 940 */
    { -30, 4, 1, 1, 18 },  /* 941 */
    { -15, -9, 1, 1, 18 },  /* 942 */
    { -15, -9, 1, 1, 18 },  /* 943 */
    { -16, -4, 1, 1, 19 },  /* 944 */
    { -23, -23, 1, 1, 19 },  /* 945 */
    { -14, -7, 1, 1, 19 },  /* 946 */
    { -4, -24, 1, 1, 19 },  /* 947 */
    { -11, -8, 1, 1, 19 },  /* 948 */
    { -26, -29, 1, 1, 19 },  /* 949 */
    { -41, -30, 1, 1, 19 },  /* 950 */
    { -14, -13, 1, 1, 19 },  /* 951 */
    { -19, -22, 1, 1, 19 },  /* 952 */
    { -23, -23, 1, 1, 19 },  /* 953 */
    { -4, -24, 1, 1, 19 },  /* 954 */
    { -14, -7, 1, 1, 19 },  /* 955 */
    { -14, -7, 1, 1, 19 },  /* 956 */
    { -16, -4, 1, 1, 19 },  /* 957 */
    { -14, -7, 1, 1, 19 },  /* 958 */
    { -14, -7, 1, 1, 19 },  /* 959 */
    { -38, 4, 1, 1, 20 },  /* 960 */
    { -38, -24, 1, 1, 20 },  /* 961 */
    { -34, -3, 1, 1, 20 },  /* 962 */
    { -31, -9, 1, 1, 20 },  /* 963 */
    { -39, -14, 1, 1, 20 },  /* 964 */
    { -45, -20, 1, 1, 20 },  /* 965 */
    { -50, -33, 1, 1, 20 },  /* 966 */
    { -49, -14, 1, 1, 20 },  /* 967 */
    { -37, 1, 1, 1, 20 },  /* 968 */
    { -43, -12, 1, 1, 20 },  /* 969 */
    { -31, -9, 1, 1, 20 },  /* 970 */
    { -34, -3, 1, 1, 20 },  /* 971 */
    { -34, -3, 1, 1, 20 },  /* 972 */
    { -38, 4, 1, 1, 20 },  /* 973 */
    { -34, -3, 1, 1, 20 },  /* 974 */
    { -34, -3, 1, 1, 20 },  /* 975 */
    { -36, -32, 1, 1, 21 },  /* 976 */
    { -37, -42, 1, 1, 21 },  /* 977 */
    { -31, -7, 1, 1, 21 },  /* 978 */
    { -21, -18, 1, 1, 21 },  /* 979 */
    { -39, -7, 1, 1, 21 },  /* 980 */
    { -45, -28, 1, 1, 21 },  /* 981 */
    { -62, -39, 1, 1, 21 },  /* 982 */
    { -50, -24, 1, 1, 21 },  /* 983 */
    { -36, -6, 1, 1, 21 },  /* 984 */
    { -38, -27, 1, 1, 21 },  /* 985 */
    { -21, -18, 1, 1, 21 },  /* 986 */
    { -31, -7, 1, 1, 21 },  /* 987 */
    { -31, -7, 1, 1, 21 },  /* 988 */
    { -36, -32, 1, 1, 21 },  /* 989 */
    { -31, -7, 1, 1, 21 },  /* 990 */
    { -31, -7, 1, 1, 21 },  /* 991 */
    { -48, -28, 1, 1, 22 },  /* 992 */
    { -51, -24, 1, 1, 22 },  /* 993 */
    { -46, 11, 1, 1, 22 },  /* 994 */
    { -31, -2, 1, 1, 22 },  /* 995 */
    { -58, -3, 1, 1, 22 },  /* 996 */
    { -57, -15, 1, 1, 22 },  /* 997 */
    { -80, -8, 1, 1, 22 },  /* 998 */
    { -56, -9, 1, 1, 22 },  /* 999 */
    { -47, 7, 1, 1, 22 },  /* 1000 */
    { -54, -6, 1, 1, 22 },  /* 1001 */
    { -31, -2, 1, 1, 22 },  /* 1002 */
    { -46, 11, 1, 1, 22 },  /* 1003 */
    { -46, 11, 1, 1, 22 },  /* 1004 */
    { -48, -28, 1, 1, 22 },  /* 1005 */
    { -46, 11, 1, 1, 22 },  /* 1006 */
    { -46, 11, 1, 1, 22 },  /* 1007 */
    { -46, -28, 1, 1, 23 },  /* 1008 */
    { -53, -26, 1, 1, 23 },  /* 1009 */
    { -48, 19, 1, 1, 23 },  /* 1010 */
    { -39, 9, 1, 1, 23 },  /* 1011 */
    { -60, 17, 1, 1, 23 },  /* 1012 */
    { -64, -9, 1, 1, 23 },  /* 1013 */
    { -73, -4, 1, 1, 23 },  /* 1014 */
    { -57, -3, 1, 1, 23 },  /* 1015 */
    { -65, 20, 1, 1, 23 },  /* 1016 */
    { -41, 31, 1, 1, 23 },  /* 1017 */
    { -48, 19, 1, 1, 23 },  /* 1018 */
    { -48, 19, 1, 1, 23 },  /* 1019 */
    { -48, 19, 1, 1, 23 },  /* 1020 */
    { -46, -28, 1, 1, 23 },  /* 1021 */
    { -48, 19, 1, 1, 23 },  /* 1022 */
    { -48, 19, 1, 1, 23 },  /* 1023 */
    { -46, -8, 1, 1, 24 },  /* 1024 */
    { -51, -10, 1, 1, 24 },  /* 1025 */
    { -43, 27, 1, 1, 24 },  /* 1026 */
    { -43, 20, 1, 1, 24 },  /* 1027 */
    { -78, -1, 1, 1, 24 },  /* 1028 */
    { -59, 11, 1, 1, 24 },  /* 1029 */
    { -78, 11, 1, 1, 24 },  /* 1030 */
    { -77, 8, 1, 1, 24 },  /* 1031 */
    { -67, 32, 1, 1, 24 },  /* 1032 */
    { -38, 42, 1, 1, 24 },  /* 1033 */
    { -43, 20, 1, 1, 24 },  /* 1034 */
    { -43, 27, 1, 1, 24 },  /* 1035 */
    { -43, 27, 1, 1, 24 },  /* 1036 */
    { -46, -8, 1, 1, 24 },  /* 1037 */
    { -43, 27, 1, 1, 24 },  /* 1038 */
    { -43, 27, 1, 1, 24 },  /* 1039 */
    { -40, -2, 1, 1, 25 },  /* 1040 */
    { -79, 33, 1, 1, 25 },  /* 1041 */
    { -56, 52, 1, 1, 25 },  /* 1042 */
    { -75, 31, 1, 1, 25 },  /* 1043 */
    { -58, 27, 1, 1, 25 },  /* 1044 */
    { -44, 30, 1, 1, 25 },  /* 1045 */
    { -66, 34, 1, 1, 25 },  /* 1046 */
    { -56, 29, 1, 1, 25 },  /* 1047 */
    { -75, 32, 1, 1, 25 },  /* 1048 */
    { -54, 64, 1, 1, 25 },  /* 1049 */
    { -75, 31, 1, 1, 25 },  /* 1050 */
    { -56, 52, 1, 1, 25 },  /* 1051 */
    { -56, 52, 1, 1, 25 },  /* 1052 */
    { -40, -2, 1, 1, 25 },  /* 1053 */
    { -56, 52, 1, 1, 25 },  /* 1054 */
    { -56, 52, 1, 1, 25 },  /* 1055 */
    { 72, 24, 1, 1, 26 },  /* 1056 */
    { 67, 23, 1, 1, 26 },  /* 1057 */
    { 68, 44, 1, 1, 26 },  /* 1058 */
    { 57, 56, 1, 1, 26 },  /* 1059 */
    { 72, 27, 1, 1, 26 },  /* 1060 */
    { 76, 40, 1, 1, 26 },  /* 1061 */
    { 74, 34, 1, 1, 26 },  /* 1062 */
    { 49, 29, 1, 1, 26 },  /* 1063 */
    { 66, 82, 1, 1, 26 },  /* 1064 */
    { 75, 57, 1, 1, 26 },  /* 1065 */
    { 57, 56, 1, 1, 26 },  /* 1066 */
    { 68, 44, 1, 1, 26 },  /* 1067 */
    { 68, 44, 1, 1, 26 },  /* 1068 */
    { 72, 24, 1, 1, 26 },  /* 1069 */
    { 68, 44, 1, 1, 26 },  /* 1070 */
    { 68, 44, 1, 1, 26 },  /* 1071 */
    { 96, 24, 1, 0, 27 },  /* 1072 */
    { 67, 39, 1, 0, 27 },  /* 1073 */
    { 68, 44, 1, 0, 27 },  /* 1074 */
    { 57, 56, 1, 0, 27 },  /* 1075 */
    { 72, 27, 1, 0, 27 },  /* 1076 */
    { 76, 40, 1, 0, 27 },  /* 1077 */
    { 100, 34, 1, 0, 27 },  /* 1078 */
    { 49, 29, 1, 0, 27 },  /* 1079 */
    { 66, 82, 1, 0, 27 },  /* 1080 */
    { 75, 57, 1, 0, 27 },  /* 1081 */
    { 57, 56, 1, 0, 27 },  /* 1082 */
    { 68, 44, 1, 0, 27 },  /* 1083 */
    { 68, 44, 1, 0, 27 },  /* 1084 */
    { 96, 24, 1, 0, 27 },  /* 1085 */
    { 68, 44, 1, 0, 27 },  /* 1086 */
    { 68, 44, 1, 0, 27 },  /* 1087 */
};

extern const u16 necro_exca_000[], necro_exca_001[], necro_exca_002[], necro_exca_003[], necro_exca_004[], necro_exca_005[], necro_exca_006[], necro_exca_007[], necro_exca_008[], necro_exca_009[], necro_exca_010[], necro_exca_011[], necro_exca_012[], necro_exca_013[], necro_exca_014[], necro_exca_017[], necro_exca_021[], necro_exca_023[], necro_exca_024[], necro_exca_026[], necro_exca_027[], necro_exca_028[], necro_exca_029[], necro_exca_030[], necro_exca_031[], necro_exca_032[], necro_exca_033[], necro_exca_034[], necro_exca_035[], necro_exca_036[], necro_exca_037[], necro_exca_040[], necro_exca_041[];

/* exca scripts (debug viewer: UNION): 42 entries */
const u32 necro_exca[43] = {
    (u32)necro_exca_000,  /* 0 follow-up of AIR S / AIR M +2 */
    (u32)necro_exca_001,  /* 1 follow-up of APPEAR JUNBI 2 */
    (u32)necro_exca_002,  /* 2 follow-up of APPEAR JUNBI 3 */
    (u32)necro_exca_003,  /* 3 follow-up of ASHIBARAI A / ASHIBARAI B +6 */
    (u32)necro_exca_004,  /* 4 follow-up of APPEAR JUNBI 4 */
    (u32)necro_exca_005,  /* 5 follow-up of ALEX BACK D / NECRO G S +6 */
    (u32)necro_exca_006,  /* 6 follow-up of DADLEY L B / NECRO S T +26 */
    (u32)necro_exca_007,  /* 7 follow-up of DUDDLEY D S / KUNOJI A */
    (u32)necro_exca_008,  /* 8 follow-up of TATAKI S / KGM TATAKI S +4 */
    (u32)necro_exca_009,  /* 9 follow-up of ALEX BODY S / IBUKI KUBIORI +4 */
    (u32)necro_exca_010,  /* 10 follow-up of APPEAR JUNBI 2 */
    (u32)necro_exca_011,  /* 11 follow-up of APPEAR JUNBI 3 */
    (u32)necro_exca_012,  /* 12 follow-up of APPEAR JUNBI 4 */
    (u32)necro_exca_013,  /* 13 follow-up of APPEAR JUNBI 5 */
    (u32)necro_exca_014,  /* 14 no name */
    (u32)necro_exca_014,  /* 15 no name */
    (u32)necro_exca_014,  /* 16 no name */
    (u32)necro_exca_017,  /* 17 no name */
    (u32)necro_exca_014,  /* 18 no name */
    (u32)necro_exca_014,  /* 19 no name */
    (u32)necro_exca_014,  /* 20 no name */
    (u32)necro_exca_021,  /* 21 follow-up of HARAIGOSHI A */
    (u32)necro_exca_014,  /* 22 no name */
    (u32)necro_exca_023,  /* 23 follow-up of APPEAR JUNBI 7 */
    (u32)necro_exca_024,  /* 24 follow-up of APPEAR JUNBI 7 */
    (u32)necro_exca_014,  /* 25 no name */
    (u32)necro_exca_026,  /* 26 follow-up of APPEAR 2 */
    (u32)necro_exca_027,  /* 27 follow-up of APPEAR 2 */
    (u32)necro_exca_028,  /* 28 follow-up of HUMI ASIB A */
    (u32)necro_exca_029,  /* 29 follow-up of APPEAR JUNBI 5 */
    (u32)necro_exca_030,  /* 30 follow-up of SP APPEAR 6 */
    (u32)necro_exca_031,  /* 31 follow-up of SP APPEAR 6 */
    (u32)necro_exca_032,  /* 32 follow-up of GILL IMPACT C */
    (u32)necro_exca_033,  /* 33 follow-up of GILL IMPACT C */
    (u32)necro_exca_034,  /* 34 follow-up of SP APPEAR 7 */
    (u32)necro_exca_035,  /* 35 follow-up of SP APPEAR 7 */
    (u32)necro_exca_036,  /* 36 follow-up of ZANNEN 1 */
    (u32)necro_exca_037,  /* 37 follow-up of ZANNEN 1 */
    (u32)necro_exca_036,  /* 38 follow-up of ZANNEN 2 */
    (u32)necro_exca_037,  /* 39 follow-up of ZANNEN 2 */
    (u32)necro_exca_040,  /* 40 follow-up of ZANNEN 3 */
    (u32)necro_exca_041,  /* 41 follow-up of ZANNEN 3 */
    0
};

/* script: 0 follow-up of AIR S / AIR M +2 */
const u16 necro_exca_000_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 necro_exca_000[100] = {
    L4(2, 0, 0, 0, 0, 0, 0, 0x2178, 0, 158, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x2179, 0, 158, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x217A, 0, 158, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x217B, 0, 158, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x217C, 0, 158, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x217D, 0, 158, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x217E, 0, 158, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x217E, 0, 158, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x1E5B, 0, 158, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x1E5C, 0, 158, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x1E5D, 0, 158, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 1 follow-up of APPEAR JUNBI 2 */
const u16 necro_exca_001_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 necro_exca_001[60] = {
    L4(2, 2, 273, 0, 0, 0, 0, 0x1E21, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 3, 0, 0, 0, 0, 0, 0x1E22, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 3, 0, 0, 0, 0, 0, 0x1E23, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 3, 0, 0, 0, 0, 0, 0x1E21, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x1E3C, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1E3D, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x1E3D, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 2 follow-up of APPEAR JUNBI 3 */
const u16 necro_exca_002_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 necro_exca_002[36] = {
    L4(1, 2, 273, 0, 0, 0, 0, 0x1E1F, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 2, 0, 0, 0, 0, 0, 0x1E21, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 2, 0, 0, 0, 0, 0, 0x1E11, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_JPSS, 7, 1, 5), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 3 follow-up of ASHIBARAI A / ASHIBARAI B +6 */
const u16 necro_exca_003_head[4] = { HEAD(4, 38, 0, 0, 0, 0, 0) };
const u16 necro_exca_003[108] = {
    L4(2, 2, 0, 0, 0, 0, 0, 0x2071, 0, 115, 0, 0, 0, 0, 0),
    L4(3, 2, 0, 0, 0, 0, 0, 0x206B, 0, 115, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x2027, 0, 115, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x2028, 0, 115, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x2029, 0, 115, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x202A, 0, 115, 0, 0, 0, 0, 0),
    L4(2, 5, 0, 0, 0, 0, 0, 0x202B, 0, 115, 0, 0, 0, 0, 0),
    L4(2, 5, 0, 0, 0, 0, 0, 0x202C, 0, 115, 0, 0, 0, 0, 0),
    L4(2, 5, 0, 0, 0, 0, 0, 0x202D, 0, 115, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x202E, 0, 115, 0, 0, 0, 0, 0),
    L4(2, 9, 0, 0, 0, 0, 0, 0x202E, 0, 115, 0, 0, 0, 0, 0),
    L4(1, 9, 0, 0, 0, 0, 0, 0x2004, 0, 115, 0, 0, 0, 0, 0),
    CMD(CM_JMP, 1, 64, 6), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 4 follow-up of APPEAR JUNBI 4 */
const u16 necro_exca_004_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 necro_exca_004[68] = {
    L4(1, 0, 273, 0, 0, 0, 0, 0x1E21, 0, 1, 0, 0, 0, 21, 0),
    L4(1, 2, 0, 0, 0, 0, 0, 0x1E21, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 3, 0, 0, 0, 0, 0, 0x1E22, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 3, 0, 0, 0, 0, 0, 0x1E23, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 3, 0, 0, 0, 0, 0, 0x1E21, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x1E3C, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1E3D, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x1E3D, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 5 follow-up of ALEX BACK D / NECRO G S +6 */
const u16 necro_exca_005_head[4] = { HEAD(4, 38, 0, 0, 0, 0, 0) };
const u16 necro_exca_005[108] = {
    L4(2, 2, 0, 0, 0, 0, 0, 0x2039, 0, 115, 0, 0, 0, 0, 0),
    L4(3, 2, 0, 0, 0, 0, 0, 0x203A, 0, 115, 0, 0, 0, 0, 0),
    L4(3, 2, 0, 0, 0, 0, 0, 0x203B, 0, 115, 0, 0, 0, 0, 0),
    L4(3, 2, 0, 0, 0, 0, 0, 0x203C, 0, 115, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x203D, 0, 115, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x203E, 0, 115, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x203F, 0, 115, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x202A, 0, 115, 0, 0, 0, 0, 0),
    L4(2, 5, 0, 0, 0, 0, 0, 0x202B, 0, 115, 0, 0, 0, 0, 0),
    L4(2, 5, 0, 0, 0, 0, 0, 0x202C, 0, 115, 0, 0, 0, 0, 0),
    L4(2, 5, 0, 0, 0, 0, 0, 0x202D, 0, 115, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x202E, 0, 115, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x202E, 0, 115, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 6 follow-up of DADLEY L B / NECRO S T +26 */
const u16 necro_exca_006_head[4] = { HEAD(4, 38, 0, 0, 0, 0, 0) };
const u16 necro_exca_006[108] = {
    L4(2, 2, 0, 0, 0, 0, 0, 0x2039, 0, 115, 0, 0, 0, 0, 0),
    L4(3, 2, 0, 0, 0, 0, 0, 0x203A, 0, 115, 0, 0, 0, 0, 0),
    L4(3, 2, 0, 0, 0, 0, 0, 0x203B, 0, 115, 0, 0, 0, 0, 0),
    L4(3, 2, 0, 0, 0, 0, 0, 0x203C, 0, 115, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x203D, 0, 115, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x203E, 0, 115, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x203F, 0, 115, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x202A, 0, 115, 0, 0, 0, 0, 0),
    L4(2, 5, 0, 0, 0, 0, 0, 0x202B, 0, 115, 0, 0, 0, 0, 0),
    L4(2, 5, 0, 0, 0, 0, 0, 0x202C, 0, 115, 0, 0, 0, 0, 0),
    L4(2, 5, 0, 0, 0, 0, 0, 0x202D, 0, 115, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x202E, 0, 115, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x202E, 0, 115, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 7 follow-up of DUDDLEY D S / KUNOJI A */
const u16 necro_exca_007_head[4] = { HEAD(4, 38, 0, 0, 0, 0, 0) };
const u16 necro_exca_007[100] = {
    L4(2, 2, 0, 0, 0, 0, 0, 0x2025, 0, 115, 0, 0, 0, 0, 0),
    L4(3, 2, 0, 0, 0, 0, 0, 0x2026, 0, 115, 0, 0, 0, 0, 0),
    L4(3, 2, 0, 0, 0, 0, 0, 0x2010, 0, 115, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x2027, 0, 115, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x2028, 0, 115, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x2029, 0, 115, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x202A, 0, 115, 0, 0, 0, 0, 0),
    L4(2, 5, 0, 0, 0, 0, 0, 0x202B, 0, 115, 0, 0, 0, 0, 0),
    L4(2, 5, 0, 0, 0, 0, 0, 0x202C, 0, 115, 0, 0, 0, 0, 0),
    L4(2, 5, 0, 0, 0, 0, 0, 0x202D, 0, 115, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x202E, 0, 115, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x202E, 0, 115, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 8 follow-up of TATAKI S / KGM TATAKI S +4 */
const u16 necro_exca_008_head[4] = { HEAD(4, 38, 0, 0, 0, 0, 0) };
const u16 necro_exca_008[100] = {
    L4(2, 2, 0, 0, 0, 0, 0, 0x2025, 0, 115, 0, 0, 0, 0, 0),
    L4(3, 2, 0, 0, 0, 0, 0, 0x2026, 0, 115, 0, 0, 0, 0, 0),
    L4(3, 2, 0, 0, 0, 0, 0, 0x2010, 0, 115, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x2027, 0, 115, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x2028, 0, 115, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x2029, 0, 115, 0, 0, 0, 0, 0),
    L4(2, 5, 0, 0, 0, 0, 0, 0x202A, 0, 115, 0, 0, 0, 0, 0),
    L4(2, 5, 0, 0, 0, 0, 0, 0x202B, 0, 115, 0, 0, 0, 0, 0),
    L4(2, 5, 0, 0, 0, 0, 0, 0x202C, 0, 115, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x202D, 0, 115, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x202E, 0, 115, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x202E, 0, 115, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 9 follow-up of ALEX BODY S / IBUKI KUBIORI +4 */
const u16 necro_exca_009_head[4] = { HEAD(4, 38, 0, 0, 0, 0, 0) };
const u16 necro_exca_009[84] = {
    L4(2, 2, 0, 0, 0, 0, 0, 0x2050, 0, 115, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x2027, 0, 115, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x2028, 0, 115, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x2029, 0, 115, 0, 0, 0, 0, 0),
    L4(2, 5, 0, 0, 0, 0, 0, 0x202A, 0, 115, 0, 0, 0, 0, 0),
    L4(2, 5, 0, 0, 0, 0, 0, 0x202B, 0, 115, 0, 0, 0, 0, 0),
    L4(2, 5, 0, 0, 0, 0, 0, 0x202C, 0, 115, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x202D, 0, 115, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x202E, 0, 115, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x202E, 0, 115, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 10 follow-up of APPEAR JUNBI 2 */
const u16 necro_exca_010_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 necro_exca_010[44] = {
    L4(2, 2, 273, 0, 0, 0, 0, 0x1E21, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 3, 0, 0, 0, 0, 0, 0x1E22, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 3, 0, 0, 0, 0, 0, 0x1E23, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x1E24, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x1E24, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 11 follow-up of APPEAR JUNBI 3 */
const u16 necro_exca_011_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 necro_exca_011[36] = {
    L4(1, 2, 273, 0, 0, 0, 0, 0x1E21, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 2, 0, 0, 0, 0, 0, 0x1E22, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 3, 0, 0, 0, 0, 0, 0x1E23, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_JPSS, 7, 10, 4), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 12 follow-up of APPEAR JUNBI 4 */
const u16 necro_exca_012_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 necro_exca_012[52] = {
    L4(1, 0, 273, 0, 0, 0, 0, 0x1E21, 0, 2, 0, 0, 0, 21, 0),
    L4(1, 2, 0, 0, 0, 0, 0, 0x1E21, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 3, 0, 0, 0, 0, 0, 0x1E22, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 3, 0, 0, 0, 0, 0, 0x1E23, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x1E24, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x1E24, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 13 follow-up of APPEAR JUNBI 5 */
const u16 necro_exca_013_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 necro_exca_013[36] = {
    L4(3, 0, 273, 0, 0, 0, 0, 0x1E3B, 0, 1, 0, 0, 0, 21, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1E3C, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1E3D, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x1E3D, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 14 no name, 15 no name, 16 no name, 18 no name ... */
const u16 necro_exca_014_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 necro_exca_014[20] = {
    L4(250, 255, 0, 0, 0, 0, 0, 0x1E01, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_END, 0, 0, 1), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 17 no name */
const u16 necro_exca_017_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 necro_exca_017[60] = {
    CMD(CM_RJA, 7, 5, 1), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 2, 0, 0, 0x2031, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 2, 0, 0, 0x207C, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 2, 0, 0, 0x207B, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 2, 0, 0, 0x20D0, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 2, 0, 0, 0x20D0, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 21 follow-up of HARAIGOSHI A */
const u16 necro_exca_021_head[4] = { HEAD(4, 38, 0, 0, 0, 0, 0) };
const u16 necro_exca_021[108] = {
    L4(2, 1, 0, 0, 1, 0, 0, 0x2039, 0, 115, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 1, 0, 0, 0x203A, 0, 115, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 1, 0, 0, 0x203B, 0, 115, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 1, 0, 0, 0x203C, 0, 115, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 1, 0, 0, 0x203D, 0, 115, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 1, 0, 0, 0x203E, 0, 115, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 1, 0, 0, 0x203F, 0, 115, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 1, 0, 0, 0x202A, 0, 115, 0, 0, 0, 0, 0),
    L4(2, 5, 0, 0, 1, 0, 0, 0x202B, 0, 115, 0, 0, 0, 0, 0),
    L4(2, 5, 0, 0, 1, 0, 0, 0x202C, 0, 115, 0, 0, 0, 0, 0),
    L4(2, 5, 0, 0, 1, 0, 0, 0x202D, 0, 115, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 1, 0, 0, 0x202E, 0, 115, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 1, 0, 0, 0x202E, 0, 115, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 23 follow-up of APPEAR JUNBI 7 */
const u16 necro_exca_023_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 necro_exca_023[84] = {
    L4(3, 2, 0, 0, 0, 0, 0, 0x208C, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 3, 0, 0, 0, 0, 0, 0x1FD5, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 3, 0, 0, 0, 0, 0, 0x1FD6, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 3, 0, 0, 0, 0, 0, 0x1FD7, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 3, 0, 0, 0, 0, 0, 0x1FD8, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 3, 0, 0, 0, 0, 0, 0x1E21, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 3, 0, 0, 0, 0, 0, 0x1E3B, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 3, 0, 0, 0, 0, 0, 0x1E3C, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 3, 0, 0, 0, 0, 0, 0x1E3D, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x1E3D, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 24 follow-up of APPEAR JUNBI 7 */
const u16 necro_exca_024_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 necro_exca_024[84] = {
    L4(3, 2, 0, 0, 0, 0, 0, 0x208C, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 3, 0, 0, 0, 0, 0, 0x1FD5, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 3, 0, 0, 0, 0, 0, 0x1FD6, 0, 2, 0, 0, 0, 0, 0),
    L4(1, 3, 0, 0, 0, 0, 0, 0x1FD7, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 3, 0, 0, 0, 0, 0, 0x1FD8, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 3, 0, 0, 0, 0, 0, 0x1E21, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 3, 0, 0, 0, 0, 0, 0x1E22, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 3, 0, 0, 0, 0, 0, 0x1E23, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 3, 0, 0, 0, 0, 0, 0x1E24, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x1E24, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 26 follow-up of APPEAR 2 */
const u16 necro_exca_026_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 necro_exca_026[84] = {
    L4(3, 2, 0, 0, 0, 0, 0, 0x208C, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 3, 0, 0, 0, 0, 0, 0x1FD5, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 3, 0, 0, 0, 0, 0, 0x1FD6, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 3, 0, 0, 0, 0, 0, 0x1FD7, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 3, 0, 0, 0, 0, 0, 0x1FD8, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 3, 0, 0, 0, 0, 0, 0x1E21, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 3, 0, 0, 0, 0, 0, 0x1E3B, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 3, 0, 0, 0, 0, 0, 0x1E3C, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 3, 0, 0, 0, 0, 0, 0x1E3D, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x1E3D, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 27 follow-up of APPEAR 2 */
const u16 necro_exca_027_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 necro_exca_027[84] = {
    L4(3, 2, 0, 0, 0, 0, 0, 0x208C, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1FD5, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1FD6, 0, 2, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1FD7, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1FD8, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1E21, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1E22, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1E23, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1E24, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x1E24, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 28 follow-up of HUMI ASIB A */
const u16 necro_exca_028_head[4] = { HEAD(4, 38, 0, 0, 0, 0, 0) };
const u16 necro_exca_028[100] = {
    CMD(CM_PA_X, 0, 8192, 0), 0, 0, 0, 0,
    L4(3, 2, 0, 0, 0, 0, 0, 0x203B, 0, 115, 0, 0, 0, 0, 0),
    L4(3, 2, 0, 0, 0, 0, 0, 0x203C, 0, 115, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x203D, 0, 115, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x203E, 0, 115, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x203F, 0, 115, 0, 0, 0, 0, 0),
    L4(2, 5, 0, 0, 0, 0, 0, 0x202A, 0, 115, 0, 0, 0, 0, 0),
    L4(2, 5, 0, 0, 0, 0, 0, 0x202B, 0, 115, 0, 0, 0, 0, 0),
    L4(2, 5, 0, 0, 0, 0, 0, 0x202C, 0, 115, 0, 0, 0, 0, 0),
    L4(2, 5, 0, 0, 0, 0, 0, 0x202D, 0, 115, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x202E, 0, 115, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x202E, 0, 115, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 29 follow-up of APPEAR JUNBI 5 */
const u16 necro_exca_029_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 necro_exca_029[44] = {
    L4(3, 0, 273, 0, 0, 0, 0, 0x1E21, 0, 2, 0, 0, 0, 21, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1E22, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1E23, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x1E24, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x1E24, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 30 follow-up of SP APPEAR 6 */
const u16 necro_exca_030_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 necro_exca_030[68] = {
    L4(1, 0, 273, 0, 0, 0, 0, 0x1E21, 0, 174, 0, 0, 0, 21, 0),
    L4(1, 2, 0, 0, 0, 0, 0, 0x1E21, 0, 174, 0, 0, 0, 0, 0),
    L4(2, 3, 0, 0, 0, 0, 0, 0x1E22, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 3, 0, 0, 0, 0, 0, 0x1E23, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 3, 0, 0, 0, 0, 0, 0x1E21, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x1E3C, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1E3D, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x1E3D, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 31 follow-up of SP APPEAR 6 */
const u16 necro_exca_031_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 necro_exca_031[52] = {
    L4(1, 0, 273, 0, 0, 0, 0, 0x1E21, 0, 175, 0, 0, 0, 21, 0),
    L4(1, 2, 0, 0, 0, 0, 0, 0x1E21, 0, 175, 0, 0, 0, 0, 0),
    L4(3, 3, 0, 0, 0, 0, 0, 0x1E22, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 3, 0, 0, 0, 0, 0, 0x1E23, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x1E24, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x1E24, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 32 follow-up of GILL IMPACT C */
const u16 necro_exca_032_head[4] = { HEAD(4, 38, 0, 0, 0, 0, 0) };
const u16 necro_exca_032[108] = {
    L4(2, 2, 0, 0, 0, 0, 0, 0x2071, 0, 115, 0, 0, 0, 0, 0),
    L4(3, 2, 0, 0, 0, 0, 0, 0x206B, 0, 115, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x2027, 0, 115, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x2028, 0, 115, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x2029, 0, 115, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x202A, 0, 115, 0, 0, 0, 0, 0),
    L4(2, 5, 0, 0, 0, 0, 0, 0x202B, 0, 115, 0, 0, 0, 0, 0),
    L4(2, 5, 0, 0, 0, 0, 0, 0x202C, 0, 115, 0, 0, 0, 0, 0),
    L4(2, 5, 0, 0, 0, 0, 0, 0x202D, 0, 115, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x202E, 0, 115, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x202E, 0, 115, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x2004, 0, 115, 0, 0, 0, 0, 0),
    CMD(CM_JMP, 1, 64, 6), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 33 follow-up of GILL IMPACT C */
const u16 necro_exca_033_head[4] = { HEAD(4, 38, 0, 0, 0, 0, 0) };
const u16 necro_exca_033[100] = {
    L4(2, 2, 0, 0, 0, 0, 0, 0x2071, 0, 115, 0, 0, 0, 0, 0),
    L4(3, 2, 0, 0, 0, 0, 0, 0x206B, 0, 115, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x2027, 0, 115, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x2028, 0, 115, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x2029, 0, 115, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x202A, 0, 115, 0, 0, 0, 0, 0),
    L4(2, 5, 0, 0, 0, 0, 0, 0x202B, 0, 115, 0, 0, 0, 0, 0),
    L4(2, 5, 0, 0, 0, 0, 0, 0x202C, 0, 115, 0, 0, 0, 0, 0),
    L4(2, 5, 0, 0, 0, 0, 0, 0x202D, 0, 115, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x202E, 0, 115, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x202E, 0, 115, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x2004, 0, 115, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 34 follow-up of SP APPEAR 7 */
const u16 necro_exca_034_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 necro_exca_034[60] = {
    L4(2, 3, 273, 0, 0, 0, 0, 0x1E21, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 3, 0, 0, 0, 0, 0, 0x1E22, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 3, 0, 0, 0, 0, 0, 0x1E23, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 3, 0, 0, 0, 0, 0, 0x1E21, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x1E3C, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1E3D, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x1E3D, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 35 follow-up of SP APPEAR 7 */
const u16 necro_exca_035_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 necro_exca_035[44] = {
    L4(2, 3, 273, 0, 0, 0, 0, 0x1E21, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 3, 0, 0, 0, 0, 0, 0x1E22, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 3, 0, 0, 0, 0, 0, 0x1E23, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x1E24, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x1E24, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 36 follow-up of ZANNEN 1, 38 follow-up of ZANNEN 2 */
const u16 necro_exca_036_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 necro_exca_036[52] = {
    L4(3, 2, 0, 0, 0, 0, 0, 0x1E43, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 2, 0, 0, 0, 0, 0, 0x1E21, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 64, 0, 0, 0, 0, 0, 0x1E3B, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1E3C, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1E3D, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x1E3D, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 37 follow-up of ZANNEN 1, 39 follow-up of ZANNEN 2 */
const u16 necro_exca_037_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 necro_exca_037[52] = {
    L4(3, 2, 0, 0, 0, 0, 0, 0x1E43, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 2, 0, 0, 0, 0, 0, 0x1E21, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 64, 0, 0, 0, 0, 0, 0x1E22, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1E23, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1E24, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x1E24, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 40 follow-up of ZANNEN 3 */
const u16 necro_exca_040_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 necro_exca_040[52] = {
    L4(3, 2, 0, 0, 0, 0, 0, 0x1E43, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 2, 0, 0, 0, 0, 0, 0x1E21, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 64, 0, 0, 0, 0, 0, 0x1E3B, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1E3C, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1E3D, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x1E3D, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 41 follow-up of ZANNEN 3 */
const u16 necro_exca_041_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 necro_exca_041[52] = {
    L4(3, 2, 0, 0, 0, 0, 0, 0x1E43, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 2, 0, 0, 0, 0, 0, 0x1E21, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 64, 0, 0, 0, 0, 0, 0x1E22, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1E23, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1E24, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x1E24, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

extern const u16 necro_saca_000[], necro_saca_003[], necro_saca_006[], necro_saca_009[], necro_saca_012[], necro_saca_018[], necro_saca_024[], necro_saca_028[], necro_saca_029[], necro_saca_030[], necro_saca_031[], necro_saca_032[], necro_saca_033[], necro_saca_034[], necro_saca_036[], necro_saca_040[], necro_saca_041[], necro_saca_042[], necro_saca_044[], necro_saca_045[], necro_saca_046[], necro_saca_047[], necro_saca_048[], necro_saca_054[], necro_saca_058[], necro_saca_059[], necro_saca_060[], necro_saca_061[], necro_saca_062[], necro_saca_063[], necro_saca_066[];

/* saca scripts (debug viewer: SP AT): 67 entries */
const u32 necro_saca[68] = {
    (u32)necro_saca_000,  /* 0 UP P GUARD P S */
    (u32)necro_saca_000,  /* 1 UP P GUARD P M */
    (u32)necro_saca_000,  /* 2 UP P GUARD P L */
    (u32)necro_saca_003,  /* 3 UP P GUARD K S */
    (u32)necro_saca_003,  /* 4 UP P GUARD K M */
    (u32)necro_saca_003,  /* 5 UP P GUARD K L */
    (u32)necro_saca_006,  /* 6 D P GUARD P S */
    (u32)necro_saca_006,  /* 7 D P GUARD P M */
    (u32)necro_saca_006,  /* 8 D P GUARD P L */
    (u32)necro_saca_009,  /* 9 D P GUARD K S */
    (u32)necro_saca_009,  /* 10 D P GUARD K M */
    (u32)necro_saca_009,  /* 11 D P GUARD K L */
    (u32)necro_saca_012,  /* 12 FUSHIN P S */
    (u32)necro_saca_012,  /* 13 FUSHIN P M */
    (u32)necro_saca_012,  /* 14 FUSHIN P L */
    (u32)necro_saca_012,  /* 15 FUSHIN K S */
    (u32)necro_saca_012,  /* 16 FUSHIN K M */
    (u32)necro_saca_012,  /* 17 FUSHIN K L */
    (u32)necro_saca_018,  /* 18 OKIAGARI P S */
    (u32)necro_saca_018,  /* 19 OKIAGARI P M */
    (u32)necro_saca_018,  /* 20 OKIAGARI P L */
    (u32)necro_saca_018,  /* 21 OKIAGARI K S */
    (u32)necro_saca_018,  /* 22 OKIAGARI K M */
    (u32)necro_saca_018,  /* 23 OKIAGARI K L */
    (u32)necro_saca_024,  /* 24 ATTACK 1 S: not started by a command */
    (u32)necro_saca_024,  /* 25 ATTACK 1 M: not started by a command */
    (u32)necro_saca_024,  /* 26 ATTACK 1 L: not started by a command */
    (u32)necro_saca_024,  /* 27 ATTACK 1 SP: not started by a command */
    (u32)necro_saca_028,  /* 28 ATTACK 2 S: not started by a command */
    (u32)necro_saca_029,  /* 29 ATTACK 2 M: not started by a command */
    (u32)necro_saca_030,  /* 30 ATTACK 2 L: not started by a command */
    (u32)necro_saca_031,  /* 31 ATTACK 2 SP: not started by a command */
    (u32)necro_saca_032,  /* 32 ATTACK 3 S: not started by a command */
    (u32)necro_saca_033,  /* 33 ATTACK 3 M: not started by a command */
    (u32)necro_saca_034,  /* 34 ATTACK 3 L: not started by a command */
    (u32)necro_saca_034,  /* 35 ATTACK 3 SP: not started by a command */
    (u32)necro_saca_036,  /* 36 ATTACK 4 S: not started by a command */
    (u32)necro_saca_036,  /* 37 ATTACK 4 M: not started by a command */
    (u32)necro_saca_036,  /* 38 ATTACK 4 L: not started by a command */
    (u32)necro_saca_036,  /* 39 ATTACK 4 SP: not started by a command */
    (u32)necro_saca_040,  /* 40 ATTACK 5 S: not started by a command */
    (u32)necro_saca_041,  /* 41 ATTACK 5 M: not started by a command */
    (u32)necro_saca_042,  /* 42 ATTACK 5 L: not started by a command */
    (u32)necro_saca_042,  /* 43 ATTACK 5 SP: not started by a command */
    (u32)necro_saca_044,  /* 44 ATTACK 6 S: not started by a command */
    (u32)necro_saca_045,  /* 45 ATTACK 6 M: not started by a command */
    (u32)necro_saca_046,  /* 46 ATTACK 6 L: not started by a command */
    (u32)necro_saca_047,  /* 47 ATTACK 6 SP: not started by a command */
    (u32)necro_saca_048,  /* 48 ATTACK 7 S: not started by a command */
    (u32)necro_saca_048,  /* 49 ATTACK 7 M: not started by a command */
    (u32)necro_saca_000,  /* 50 ATTACK 7 L: not started by a command */
    (u32)necro_saca_000,  /* 51 ATTACK 7 SP: not started by a command */
    (u32)necro_saca_000,  /* 52 ATTACK 8 S: not started by a command */
    (u32)necro_saca_000,  /* 53 ATTACK 8 M: not started by a command */
    (u32)necro_saca_054,  /* 54 ATTACK 8 L: not started by a command */
    (u32)necro_saca_054,  /* 55 ATTACK 8 SP: not started by a command */
    (u32)necro_saca_054,  /* 56 ATTACK 9 S: not started by a command */
    (u32)necro_saca_054,  /* 57 ATTACK 9 M: not started by a command */
    (u32)necro_saca_058,  /* 58 ATTACK 9 L: not started by a command */
    (u32)necro_saca_059,  /* 59 ATTACK 9 SP: not started by a command */
    (u32)necro_saca_060,  /* 60 ATTACK 10 S: not started by a command */
    (u32)necro_saca_061,  /* 61 ATTACK 10 M: not started by a command */
    (u32)necro_saca_062,  /* 62 ATTACK 10 L: not started by a command */
    (u32)necro_saca_063,  /* 63 ATTACK 10 SP: not started by a command */
    (u32)necro_saca_063,  /* 64 ATTACK 11 S: not started by a command */
    (u32)necro_saca_063,  /* 65 ATTACK 11 M: not started by a command */
    (u32)necro_saca_066,  /* 66 ATTACK 11 L: not started by a command */
    0
};

/* script: 0 UP P GUARD P S, 1 UP P GUARD P M, 2 UP P GUARD P L, 50 ATTACK 7 L: not started by a command ... */
const u16 necro_saca_000_head[4] = { HEAD(6, 0, 2, 13, 0, 3, 0) };
const u16 necro_saca_000[172] = {
    L6(1, 0, 269, 0, 0, 0, 0, 0x1E8B, 0, 19, 0, 0, 0, 0, 0, 0, 0, 26, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1E8C, -3, 20, 0, 0, 0, 0, 0, 0, 0, 28, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1E8D, 4, 20, 0, 0, 0, 21, 0, 0, 0, 30, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1ECE, 0, 21, 0, 0, 0, 0, 0, 0, 0, 32, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1E8F, 0, 19, 0, 0, 0, 0, 0, 0, 0, 32, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1E90, 0, 19, 0, 0, 0, 0, 0, 0, 0, 34, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1E91, 0, 19, 0, 0, 0, 0, 0, 0, 0, 34, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1E92, 0, 19, 0, 0, 0, 0, 0, 0, 0, 36, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1E93, 0, 1, 0, 0, 0, 0, 0, 0, 0, 38, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1E94, 0, 1, 0, 0, 0, 0, 0, 0, 0, 38, 0, 0),
    L6(2, 64, 0, 0, 0, 0, 0, 0x1E3B, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1E3C, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1E3D, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x1E3D, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 3 UP P GUARD K S, 4 UP P GUARD K M, 5 UP P GUARD K L */
const u16 necro_saca_003_head[4] = { HEAD(6, 0, 3, 18, 0, 5, 0) };
const u16 necro_saca_003[324] = {
    L6(1, 0, 0, 0, 0, 0, 0, 0x1ED7, 0, 1, 0, 0, 0, 0, 0, 0, 0, 72, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x1ED8, 0, 1, 0, 0, 0, 0, 0, 0, 0, 72, 0, 0),
    L6(1, 0, 269, 0, 0, 0, 0, 0x1ED9, 0, 1, 0, 0, 0, 0, 0, 0, 0, 72, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1EDA, -9, 44, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(5, 0, 0, 0, 0, 0, 0, 0x1EDB, 0, 45, 0, 0, 0, 21, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1EDC, 0, 1, 0, 0, 0, 0, 0, 0, 0, 74, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1EDD, 0, 1, 0, 0, 0, 0, 0, 0, 0, 74, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1EDE, 0, 1, 0, 0, 0, 0, 0, 0, 0, 76, 0, 0),
    L6(2, 64, 0, 0, 0, 0, 0, 0x1E3B, 0, 1, 0, 0, 0, 0, 0, 0, 0, 76, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1E3D, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x1E3D, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0), 0x0006, 0x0003, 0x1200, 0x0500, 0x0300, 0x0000, 0x0000, 0x20F2,
    CMD(CM_DUMMY, 8192, 0, 0), 0x0000, 0x0000, 0x006E, 0x0000, 0x0400, 0x0000, 0x0000, 0x20F3,
    CMD(CM_DUMMY, 8192, 0, 0), 0x0000, 0x0000, 0x0070, 0x0000, 0x0400, 0x0000, 0x0000, 0x20F4,
    CMD(CM_RJA2, -24576, 0, 0), 0x0000, 0x0000, 0x0072, 0x00A0, 0x0400, 0x0000, 0x0000, 0x20F6,
    L6(242, 82, 3072, 0, 0, 0, 0, 0x0000, 0, 0, 0, 0, 116, 0, 0, 768, 0, 0, 32, 246),
    L6(242, 82, 3072, 0, 0, 0, 0, 0x0000, 0, 0, 0, 0, 0, 0, 0, 1024, 0, 0, 32, 246),
    L6(242, 82, 3072, 0, 0, 0, 0, 0x0014, 0, 0, 0, 0, 0, 0, 0, 1024, 0, 0, 32, 247),
    CMD(CM_RJA2, -24576, 0, 0), 0x0000, 0x0000, 0x0076, 0x0000, 0x0400, 0x0000, 0x0000, 0x20FB,
    CMD(CM_RJA2, -24576, 0, 0), 0x0000, 0x0000, 0x0088, 0x0000, 0x0400, 0x0000, 0x0000, 0x20FC,
    CMD(CM_RJA2, -24576, 0, 0), 0x0000, 0x0000, 0x0000, 0x0000, 0x0400, 0x0000, 0x0000, 0x20FD,
    CMD(CM_RJA2, -24576, 0, 0), 0x0000, 0x0000, 0x008A, 0x0080, 0x0440, 0x0000, 0x0000, 0x1E21,
    CMD(CM_DUMMY, 8192, 0, 0), 0x0000, 0x0000, 0x008C, 0x0000, 0x0400, 0x0000, 0x0000, 0x1E3B,
    CMD(CM_DUMMY, 8192, 0, 0), 0x0000, 0x0000, 0x008E, 0x0000, 0x0400, 0x0000, 0x0000, 0x1E3C,
    CMD(CM_DUMMY, 8192, 0, 0), 0x0000, 0x0000, 0x0000, 0x0000, 0x0400, 0x0000, 0x0000, 0x1E3D,
    CMD(CM_DUMMY, 8192, 0, 0), 0x0000, 0x0000, 0x0000, 0x0000, 0xFAFF, 0x0000, 0x0000, 0x1E3D,
    CMD(CM_DUMMY, 8192, 0, 0), 0x0000, 0x0000, 0x0000, 0x0000, 0x0001, 0x0000, 0x0000, 0x0000,
};

/* script: 6 D P GUARD P S, 7 D P GUARD P M, 8 D P GUARD P L */
const u16 necro_saca_006_head[4] = { HEAD(6, 32, 2, 13, 0, 3, 0) };
const u16 necro_saca_006[172] = {
    L6(1, 0, 269, 0, 0, 0, 0, 0x1E8B, 0, 19, 0, 0, 0, 0, 0, 0, 0, 26, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1E8C, -3, 20, 0, 0, 0, 0, 0, 0, 0, 28, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1E8D, 4, 20, 0, 0, 0, 0, 0, 0, 0, 30, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1ECE, 0, 21, 0, 0, 0, 21, 0, 0, 0, 32, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1E8F, 0, 19, 0, 0, 0, 0, 0, 0, 0, 32, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1E90, 0, 19, 0, 0, 0, 0, 0, 0, 0, 34, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1E91, 0, 19, 0, 0, 0, 0, 0, 0, 0, 34, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1E92, 0, 19, 0, 0, 0, 0, 0, 0, 0, 36, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1E93, 0, 1, 0, 0, 0, 0, 0, 0, 0, 38, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1E94, 0, 1, 0, 0, 0, 0, 0, 0, 0, 38, 0, 0),
    L6(2, 64, 0, 0, 0, 0, 0, 0x1E3B, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1E3C, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1E3D, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x1E3D, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 9 D P GUARD K S, 10 D P GUARD K M, 11 D P GUARD K L */
const u16 necro_saca_009_head[4] = { HEAD(6, 32, 3, 18, 0, 5, 0) };
const u16 necro_saca_009[324] = {
    L6(1, 0, 0, 0, 0, 0, 0, 0x1ED7, 0, 1, 0, 0, 0, 0, 0, 0, 0, 72, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x1ED8, 0, 1, 0, 0, 0, 0, 0, 0, 0, 72, 0, 0),
    L6(1, 0, 269, 0, 0, 0, 0, 0x1ED9, 0, 1, 0, 0, 0, 0, 0, 0, 0, 72, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1EDA, -9, 44, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(5, 0, 0, 0, 0, 0, 0, 0x1EDB, 0, 45, 0, 0, 0, 21, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1EDC, 0, 1, 0, 0, 0, 0, 0, 0, 0, 74, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1EDD, 0, 1, 0, 0, 0, 0, 0, 0, 0, 74, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1EDE, 0, 1, 0, 0, 0, 0, 0, 0, 0, 76, 0, 0),
    L6(2, 64, 0, 0, 0, 0, 0, 0x1E3B, 0, 1, 0, 0, 0, 0, 0, 0, 0, 76, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1E3D, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x1E3D, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0), 0x0006, 0x2003, 0x1200, 0x0500, 0x0300, 0x0000, 0x0000, 0x20F2,
    CMD(CM_DUMMY, 8192, 0, 0), 0x0000, 0x0000, 0x006E, 0x0000, 0x0400, 0x0000, 0x0000, 0x20F3,
    CMD(CM_DUMMY, 8192, 0, 0), 0x0000, 0x0000, 0x0070, 0x0000, 0x0400, 0x0000, 0x0000, 0x20F4,
    CMD(CM_RJA2, -24576, 0, 0), 0x0000, 0x0000, 0x0072, 0x00A0, 0x0400, 0x0000, 0x0000, 0x20F6,
    L6(242, 82, 3072, 0, 0, 0, 0, 0x0000, 0, 0, 0, 0, 116, 0, 0, 768, 0, 0, 32, 246),
    L6(242, 82, 3072, 0, 0, 0, 0, 0x0000, 0, 0, 0, 0, 0, 0, 0, 1024, 0, 0, 32, 246),
    L6(242, 82, 3072, 0, 0, 0, 0, 0x0014, 0, 0, 0, 0, 0, 0, 0, 1024, 0, 0, 32, 247),
    CMD(CM_RJA2, -24576, 0, 0), 0x0000, 0x0000, 0x0076, 0x0000, 0x0400, 0x0000, 0x0000, 0x20FB,
    CMD(CM_RJA2, -24576, 0, 0), 0x0000, 0x0000, 0x0088, 0x0000, 0x0400, 0x0000, 0x0000, 0x20FC,
    CMD(CM_RJA2, -24576, 0, 0), 0x0000, 0x0000, 0x0000, 0x0000, 0x0400, 0x0000, 0x0000, 0x20FD,
    CMD(CM_RJA2, -24576, 0, 0), 0x0000, 0x0000, 0x008A, 0x0080, 0x0440, 0x0000, 0x0000, 0x1E21,
    CMD(CM_DUMMY, 8192, 0, 0), 0x0000, 0x0000, 0x008C, 0x0000, 0x0400, 0x0000, 0x0000, 0x1E3B,
    CMD(CM_DUMMY, 8192, 0, 0), 0x0000, 0x0000, 0x008E, 0x0000, 0x0400, 0x0000, 0x0000, 0x1E3C,
    CMD(CM_DUMMY, 8192, 0, 0), 0x0000, 0x0000, 0x0000, 0x0000, 0x0400, 0x0000, 0x0000, 0x1E3D,
    CMD(CM_DUMMY, 8192, 0, 0), 0x0000, 0x0000, 0x0000, 0x0000, 0xFAFF, 0x0000, 0x0000, 0x1E3D,
    CMD(CM_DUMMY, 8192, 0, 0), 0x0000, 0x0000, 0x0000, 0x0000, 0x0001, 0x0000, 0x0000, 0x0000,
};

/* script: 12 FUSHIN P S, 13 FUSHIN P M, 14 FUSHIN P L, 15 FUSHIN K S ... */
const u16 necro_saca_012_head[4] = { HEAD(4, 0, 2, 10, 0, 6, 0) };
const u16 necro_saca_012[84] = {
    CMD(CM_JSR, 8, 26, 1), 0, 0, 0, 0,
    L4(1, 131, 269, 0, 0, 0, 0, 0x2090, 0, 117, 0, 0, 0, 0, 0),
    L4(2, 1, 269, 0, 0, 0, 0, 0x2090, 0, 117, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x2091, -31, 118, 0, 133, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x2092, 0, 118, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x2093, 0, 117, 0, 0, 0, 21, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x2094, 0, 117, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x2095, 0, 117, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x208B, 0, 117, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 18 OKIAGARI P S, 19 OKIAGARI P M, 20 OKIAGARI P L, 21 OKIAGARI K S ... */
const u16 necro_saca_018_head[4] = { HEAD(4, 0, 2, 11, 0, 12, 0) };
const u16 necro_saca_018[188] = {
    L4(3, 0, 0, 0, 0, 0, 0, 0x2003, 0, 152, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x2005, 0, 152, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x201B, 0, 153, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x201C, 0, 153, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x201D, 0, 153, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x201E, 0, 173, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x201F, 0, 117, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x2020, 0, 117, 0, 0, 0, 0, 0),
    L4(1, 0, 269, 0, 0, 0, 0, 0x2021, 0, 117, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x2022, -32, 119, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x2023, -32, 120, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x2024, 0, 2, 0, 0, 0, 21, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1FD8, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_IF_L, 2, 16389, 0), 0, 0, 0, 0,
    L4(4, 64, 0, 0, 0, 0, 0, 0x1E3B, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1E3C, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1E3D, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x1E3D, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_SPS, 0, 0, 32), 0, 0, 0, 0,
    L4(4, 64, 0, 0, 0, 0, 0, 0x1E22, 0, 2, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1E23, 0, 2, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1E24, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x1E24, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 24 ATTACK 1 S: not started by a command, 25 ATTACK 1 M: not started by a command, 26 ATTACK 1 L: not started by a command, 27 ATTACK 1 SP: not started by a command */
const u16 necro_saca_024_head[4] = { HEAD(6, 0, 32, 0, 0, 3, 41) };
const u16 necro_saca_024[244] = {
    CMD(CM_JSR, 8, 12, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(2, 0, 0, 0, 0, 5, 0, 0x20F2, 0, 154, 0, 0, 0, 0, 0, 0, 0, 110, 0, 0),
    L6(2, 0, 0, 0, 0, 6, 0, 0x20F3, 0, 154, 0, 0, 0, 13, 9, 0, 0, 112, 0, 0),
    L6(38, 0, 0, 0, 0, 7, 0, 0x20F4, 0, 154, 0, 0, 0, 0, 0, 0, 0, 114, 0, 160),
    L6(1, 0, 0, 0, 0, 0, 0, 0x20F5, 0, 154, 0, 0, 0, 0, 0, 0, 0, 116, 0, 0),
    L6(3, 0, 327, 0, 0, 8, 0, 0x20F5, 0, 154, 0, 0, 0, 2, 20, 0, 0, 0, 0, 0),
    L6(5, 0, 0, 0, 0, 9, 0, 0x20F6, 0, 161, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(5, 0, 0, 0, 0, 0, 0, 0x20F6, 0, 161, 0, 0, 0, 2, 20, 0, 0, 0, 0, 0),
    L6(5, 0, 0, 0, 0, 0, 0, 0x20F7, 0, 161, 0, 0, 0, 0, 0, 0, 0, 118, 0, 0),
    L6(5, 0, 0, 0, 0, 0, 0, 0x20F8, 0, 161, 0, 0, 0, 2, 21, 0, 0, 120, 0, 0),
    L6(5, 0, 0, 0, 0, 0, 0, 0x20F9, 0, 161, 0, 0, 0, 0, 0, 0, 0, 122, 0, 0),
    L6(5, 0, 0, 0, 0, 0, 0, 0x20FA, 0, 161, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x20FB, 0, 161, 0, 0, 0, 0, 0, 0, 0, 136, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x20FC, 0, 161, 0, 0, 0, 21, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x20FD, 0, 161, 0, 0, 0, 0, 0, 0, 0, 138, 0, 128),
    L6(4, 0, 0, 0, 0, 0, 0, 0x1E21, 0, 1, 0, 0, 0, 0, 0, 0, 0, 140, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x1E3B, 0, 1, 0, 0, 0, 0, 0, 0, 0, 142, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x1E3C, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 64, 0, 0, 0, 0, 0, 0x1E3D, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x1E3D, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 28 ATTACK 2 S: not started by a command */
const u16 necro_saca_028_head[4] = { HEAD(6, 0, 8, 12, 0, 2, 38) };
const u16 necro_saca_028[508] = {
    L6(2, 0, 0, 0, 0, 0, 0, 0x2100, 0, 163, 0, 0, 0, 0, 0, 0, 0, 144, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x2101, 0, 163, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x2102, 0, 163, 0, 0, 0, 30, 18, 0, 0, 0, 0, 0),
    L6(1, 0, 270, 0, 0, 0, 0, 0x2103, 0, 163, 0, 0, 0, 0, 0, 0, 0, 146, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x2105, -39, 140, 0, 160, 0, 0, 0, 0, 0, 150, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x2106, 0, 140, 0, 161, 0, 0, 0, 0, 0, 152, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x2107, 0, 163, 0, 0, 0, 0, 0, 0, 0, 154, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x2108, 0, 163, 0, 0, 0, 0, 0, 0, 0, 156, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x2109, 0, 163, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x210A, 0, 163, 0, 0, 0, 0, 0, 0, 0, 158, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x210B, 0, 163, 0, 0, 0, 0, 0, 0, 0, 160, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x210C, 0, 163, 0, 0, 0, 0, 0, 0, 0, 162, 0, 0),
    L6(1, 0, 270, 0, 0, 0, 0, 0x210D, 0, 163, 0, 0, 0, 0, 0, 0, 0, 164, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x210F, -40, 141, 0, 128, 64, 0, 0, 0, 0, 168, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x2110, 0, 141, 0, 0, 64, 0, 0, 0, 0, 170, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x2111, 0, 163, 0, 0, 0, 21, 0, 0, 0, 172, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x2112, 0, 163, 0, 0, 0, 0, 0, 0, 0, 174, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x2113, 0, 163, 0, 0, 0, 0, 0, 0, 0, 176, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x2114, 0, 163, 0, 0, 0, 0, 0, 0, 0, 178, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x2115, 0, 163, 0, 0, 0, 0, 0, 0, 0, 180, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x2116, 0, 163, 0, 0, 0, 0, 0, 0, 0, 182, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x2117, 0, 163, 0, 0, 0, 0, 0, 0, 0, 184, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x2118, 0, 163, 0, 0, 0, 0, 0, 0, 0, 186, 0, 0),
    L6(2, 64, 0, 0, 0, 0, 0, 0x2119, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x211A, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x2119, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x2118, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x211B, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1E3C, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1E3D, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x1E3D, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x2106, 39, 140, 0, 0, 0, 0, 0, 0, 0, 152, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x2107, 0, 163, 0, 0, 0, 0, 0, 0, 0, 154, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x2108, 0, 163, 0, 0, 0, 0, 0, 0, 0, 156, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x2109, 0, 163, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x210A, 0, 163, 0, 0, 0, 0, 0, 0, 0, 158, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x210B, 0, 163, 0, 0, 0, 0, 0, 0, 0, 160, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x210C, 0, 163, 0, 0, 0, 0, 0, 0, 0, 162, 0, 0),
    L6(1, 0, 270, 0, 0, 0, 0, 0x210D, 0, 163, 0, 0, 0, 0, 0, 0, 0, 164, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x210F, -41, 141, 0, 128, 64, 0, 0, 0, 0, 168, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x2110, 0, 141, 0, 0, 64, 0, 0, 0, 0, 170, 0, 0),
    CMD(CM_END, 0, 0, 16), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 29 ATTACK 2 M: not started by a command */
const u16 necro_saca_029_head[4] = { HEAD(6, 0, 8, 12, 0, 2, 38) };
const u16 necro_saca_029[544] = {
    L6(2, 0, 0, 0, 0, 0, 0, 0x2100, 0, 163, 0, 0, 0, 0, 0, 0, 0, 144, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x2101, 0, 163, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x2102, 0, 163, 0, 0, 0, 30, 18, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x2103, 0, 163, 0, 0, 0, 0, 0, 0, 0, 146, 0, 0),
    L6(2, 20, 270, 0, 0, 0, 0, 0x2104, 0, 163, 0, 0, 0, 0, 0, 0, 0, 148, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x2105, -57, 140, 0, 162, 0, 0, 0, 0, 0, 150, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x2106, 0, 140, 0, 163, 0, 0, 0, 0, 0, 152, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x2107, 0, 163, 0, 0, 0, 0, 0, 0, 0, 154, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x2108, 0, 163, 0, 0, 0, 0, 0, 0, 0, 156, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x2109, 0, 163, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x210A, 0, 163, 0, 0, 0, 0, 0, 0, 0, 158, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x210B, 0, 163, 0, 0, 0, 0, 0, 0, 0, 160, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x210C, 0, 163, 0, 0, 0, 0, 0, 0, 0, 162, 0, 0),
    L6(1, 20, 0, 0, 0, 0, 0, 0x210D, 0, 163, 0, 0, 0, 0, 0, 0, 0, 164, 0, 0),
    L6(1, 0, 270, 0, 0, 0, 0, 0x210E, 0, 163, 0, 0, 0, 0, 0, 0, 0, 166, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x210F, -58, 141, 0, 145, 64, 0, 0, 0, 0, 168, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x2110, 0, 141, 0, 0, 64, 0, 0, 0, 0, 170, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x2111, 0, 163, 0, 0, 0, 21, 0, 0, 0, 172, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x2112, 0, 163, 0, 0, 0, 0, 0, 0, 0, 174, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x2113, 0, 163, 0, 0, 0, 0, 0, 0, 0, 176, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x2114, 0, 163, 0, 0, 0, 0, 0, 0, 0, 178, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x2115, 0, 163, 0, 0, 0, 0, 0, 0, 0, 180, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x2116, 0, 163, 0, 0, 0, 0, 0, 0, 0, 182, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x2117, 0, 163, 0, 0, 0, 0, 0, 0, 0, 184, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x2118, 0, 163, 0, 0, 0, 0, 0, 0, 0, 186, 0, 0),
    L6(2, 64, 0, 0, 0, 0, 0, 0x2119, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x211A, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x2119, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x2118, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x211B, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1E3C, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1E3D, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x1E3D, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x2106, 57, 140, 0, 0, 0, 0, 0, 0, 0, 152, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x2107, 0, 163, 0, 0, 0, 0, 0, 0, 0, 154, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x2108, 0, 163, 0, 0, 0, 0, 0, 0, 0, 156, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x2109, 0, 163, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x210A, 0, 163, 0, 0, 0, 0, 0, 0, 0, 158, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x210B, 0, 163, 0, 0, 0, 0, 0, 0, 0, 160, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x210C, 0, 163, 0, 0, 0, 0, 0, 0, 0, 162, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x210D, 0, 163, 0, 0, 0, 0, 0, 0, 0, 164, 0, 0),
    L6(1, 0, 270, 0, 0, 0, 0, 0x210E, 0, 163, 0, 0, 0, 0, 0, 0, 0, 166, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x210F, -59, 141, 0, 172, 64, 0, 0, 0, 0, 168, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x2110, 0, 141, 0, 0, 64, 0, 0, 0, 0, 170, 0, 0),
    CMD(CM_END, 0, 0, 18), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 30 ATTACK 2 L: not started by a command */
const u16 necro_saca_030_head[4] = { HEAD(6, 0, 8, 12, 0, 3, 38) };
const u16 necro_saca_030[616] = {
    CMD(CM_JSR, 8, 23, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(6, 0, 0, 0, 0, 0, 0, 0x2100, 0, 163, 0, 0, 0, 21, 0, 0, 0, 144, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x2101, 0, 163, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x2102, 0, 163, 0, 0, 0, 30, 18, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x2103, 0, 163, 0, 0, 0, 0, 0, 0, 0, 146, 0, 0),
    L6(2, 20, 270, 0, 0, 0, 0, 0x2104, 0, 163, 0, 0, 0, 33, 0, 0, 0, 148, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x2105, -60, 140, 0, 136, 0, 0, 0, 0, 0, 150, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x2106, 0, 140, 0, 0, 0, 0, 0, 0, 0, 152, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x2107, 0, 163, 0, 0, 0, 0, 0, 0, 0, 154, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x2108, 0, 163, 0, 0, 0, 0, 0, 0, 0, 156, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x2109, 0, 163, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x210A, 0, 163, 0, 0, 0, 0, 0, 0, 0, 158, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x210B, 0, 163, 0, 0, 0, 0, 0, 0, 0, 160, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x210C, 0, 163, 0, 0, 0, 0, 0, 0, 0, 162, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x2101, 0, 163, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x2102, 0, 163, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x2103, 0, 163, 0, 0, 0, 0, 0, 0, 0, 146, 0, 0),
    L6(1, 20, 270, 0, 0, 0, 0, 0x2104, 0, 163, 0, 0, 0, 0, 0, 0, 0, 148, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x2105, -65, 140, 0, 128, 0, 0, 0, 0, 0, 150, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x2106, 0, 140, 0, 0, 0, 0, 0, 0, 0, 152, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x2107, 0, 163, 0, 0, 0, 0, 0, 0, 0, 154, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x2108, 0, 163, 0, 0, 0, 0, 0, 0, 0, 156, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x2109, 0, 163, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x210A, 0, 163, 0, 0, 0, 0, 0, 0, 0, 158, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x210B, 0, 163, 0, 0, 0, 0, 0, 0, 0, 160, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x210C, 0, 163, 0, 0, 0, 0, 0, 0, 0, 162, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x210D, 0, 163, 0, 0, 0, 0, 0, 0, 0, 164, 0, 0),
    L6(1, 0, 270, 0, 0, 0, 0, 0x210E, 0, 163, 0, 0, 0, 0, 0, 0, 0, 166, 0, 0),
    CMD(CM_HJMP, 16388, 16388, 16388), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(2, 0, 0, 0, 0, 0, 0, 0x210F, -61, 141, 0, 128, 0, 0, 0, 0, 0, 168, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x2110, 0, 141, 0, 0, 64, 0, 0, 0, 0, 170, 0, 0),
    CMD(CM_IXFW, 0, 0, 3), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(2, 0, 0, 0, 0, 0, 0, 0x210F, -62, 141, 0, 128, 0, 0, 0, 0, 0, 168, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x2110, 0, 141, 0, 0, 64, 0, 0, 0, 0, 170, 0, 0),
    CMD(CM_HJMP, 0, 5, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(3, 0, 0, 0, 0, 0, 0, 0x2111, 0, 163, 0, 0, 0, 21, 0, 0, 0, 172, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x2112, 0, 163, 0, 0, 0, 0, 0, 0, 0, 174, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x2113, 0, 163, 0, 0, 0, 0, 0, 0, 0, 176, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x2114, 0, 163, 0, 0, 0, 0, 0, 0, 0, 178, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x2115, 0, 163, 0, 0, 0, 0, 0, 0, 0, 180, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x2116, 0, 163, 0, 0, 0, 0, 0, 0, 0, 182, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x2117, 0, 163, 0, 0, 0, 0, 0, 0, 0, 184, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x2118, 0, 163, 0, 0, 0, 0, 0, 0, 0, 186, 0, 0),
    L6(2, 64, 0, 0, 0, 0, 0, 0x2119, 0, 163, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x211A, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x2119, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x2118, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x211B, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1E3C, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1E3D, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x1E3D, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 31 ATTACK 2 SP: not started by a command */
const u16 necro_saca_031_head[4] = { HEAD(6, 0, 14, 12, 0, 5, 38) };
const u16 necro_saca_031[736] = {
    CMD(CM_JSR, 8, 23, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_JSR, 8, 27, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(6, 0, 0, 0, 0, 0, 0, 0x2100, 0, 163, 0, 0, 0, 21, 0, 0, 0, 144, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x2101, 0, 163, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x2102, 0, 163, 0, 0, 0, 30, 18, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x2103, 0, 163, 0, 0, 0, 0, 0, 0, 0, 146, 0, 0),
    L6(2, 20, 270, 0, 0, 0, 0, 0x2104, 0, 163, 0, 0, 0, 33, 0, 0, 0, 148, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x2105, -86, 194, 0, 128, 0, 0, 0, 0, 0, 150, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x2106, 0, 140, 0, 0, 0, 0, 0, 0, 0, 152, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x2107, 0, 163, 0, 0, 0, 0, 0, 0, 0, 154, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x2108, 0, 163, 0, 0, 0, 0, 0, 0, 0, 156, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x2109, 0, 163, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x210A, 0, 163, 0, 0, 0, 0, 0, 0, 0, 158, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x210B, 0, 163, 0, 0, 0, 0, 0, 0, 0, 160, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x210C, 0, 163, 0, 0, 0, 0, 0, 0, 0, 162, 0, 0),
    L6(1, 20, 270, 0, 0, 0, 0, 0x2102, 0, 163, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x2105, -87, 140, 0, 128, 0, 0, 0, 0, 0, 150, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x2106, 0, 140, 0, 0, 0, 0, 0, 0, 0, 152, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x2107, 0, 163, 0, 0, 0, 0, 0, 0, 0, 154, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x2108, 0, 163, 0, 0, 0, 0, 0, 0, 0, 156, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x210A, 0, 163, 0, 0, 0, 0, 0, 0, 0, 158, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x210B, 0, 163, 0, 0, 0, 0, 0, 0, 0, 160, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x210C, 0, 163, 0, 0, 0, 0, 0, 0, 0, 162, 0, 0),
    CMD(CM_MVIX, 49, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(1, 20, 270, 0, 0, 0, 0, 0x2102, 0, 163, 0, 0, 0, 30, 18, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x2105, -87, 140, 0, 128, 0, 0, 0, 0, 0, 150, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x2106, 0, 140, 0, 0, 0, 0, 0, 0, 0, 152, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x2107, 0, 163, 0, 0, 0, 0, 0, 0, 0, 154, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x2108, 0, 163, 0, 0, 0, 0, 0, 0, 0, 156, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x210A, 0, 163, 0, 0, 0, 0, 0, 0, 0, 158, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x210B, 0, 163, 0, 0, 0, 0, 0, 0, 0, 160, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x210C, 0, 163, 0, 0, 0, 0, 0, 0, 0, 162, 0, 0),
    L6(1, 20, 270, 0, 0, 0, 0, 0x2102, 0, 163, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x2105, -88, 140, 0, 128, 0, 0, 0, 0, 0, 150, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x2106, 0, 140, 0, 0, 0, 0, 0, 0, 0, 152, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x2107, 0, 163, 0, 0, 0, 0, 0, 0, 0, 154, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x2108, 0, 163, 0, 0, 0, 0, 0, 0, 0, 156, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x210A, 0, 163, 0, 0, 0, 0, 0, 0, 0, 158, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x210B, 0, 163, 0, 0, 0, 0, 0, 0, 0, 160, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x210C, 0, 163, 0, 0, 0, 0, 0, 0, 0, 162, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x210D, 0, 163, 0, 0, 0, 0, 0, 0, 0, 164, 0, 0),
    L6(1, 0, 270, 0, 0, 0, 0, 0x210E, 0, 163, 0, 0, 0, 0, 0, 0, 0, 166, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x210F, -89, 141, 0, 128, 0, 0, 0, 0, 0, 168, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x2110, 0, 141, 0, 0, 64, 0, 0, 0, 0, 170, 0, 0),
    CMD(CM_HJMP, 0, 5, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(3, 0, 0, 0, 0, 0, 0, 0x2111, 0, 163, 0, 0, 0, 21, 0, 0, 0, 172, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x2112, 0, 163, 0, 0, 0, 0, 0, 0, 0, 174, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x2113, 0, 163, 0, 0, 0, 0, 0, 0, 0, 176, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x2114, 0, 163, 0, 0, 0, 0, 0, 0, 0, 178, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x2115, 0, 163, 0, 0, 0, 0, 0, 0, 0, 180, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x2116, 0, 163, 0, 0, 0, 0, 0, 0, 0, 182, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x2117, 0, 163, 0, 0, 0, 0, 0, 0, 0, 184, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x2118, 0, 163, 0, 0, 0, 0, 0, 0, 0, 186, 0, 0),
    L6(2, 64, 0, 0, 0, 0, 0, 0x2119, 0, 163, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x211A, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x2119, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x2118, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x211B, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1E3C, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1E3D, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x1E3D, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 32 ATTACK 3 S: not started by a command */
const u16 necro_saca_032_head[4] = { HEAD(4, 0, 8, 6, 0, 3, 0) };
const u16 necro_saca_032[260] = {
    L4(1, 0, 0, 0, 0, 0, 0, 0x1E67, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x211C, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x211D, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x211E, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ASXY, 124, 0, 0), 0, 0, 0, 0,
    L4(1, 0, 499, 0, 0, 0, 0, 0x211F, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ASXY, 126, 0, 0), 0, 0, 0, 0,
    L4(1, 0, 328, 0, 0, 1, 0, 0x2120, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ASXY, 128, 0, 0), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 1, 0, 0x2121, -42, 169, 0, 0, 64, 0, 0),
    CMD(CM_FOR, 0, 0, 10), 0, 0, 0, 0,
    L4(3, 0, 0, 0, 0, 1, 0, 0x2122, 0, 176, 0, 0, 64, 0, 0),
    L4(2, 0, 0, 0, 0, 1, 0, 0x2123, -43, 169, 0, 0, 64, 0, 0),
    L4(3, 0, 328, 0, 0, 1, 0, 0x2122, 0, 176, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 1, 0, 0x2123, -43, 169, 0, 0, 0, 0, 0),
    CMD(CM_RAPP, 5, 32, 18), 0, 0, 0, 0,
    CMD(CM_IXFW, 0, 0, 2), 0, 0, 0, 0,
    CMD(CM_NEX, 0, 0, 0), 0, 0, 0, 0,
    L4(8, 0, 0, 0, 0, 2, 0, 0x2122, 0, 1, 0, 0, 0, 21, 0),
    CMD(CM_ASXY, 130, 0, 0), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x2120, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ASXY, 132, 0, 0), 0, 0, 0, 0,
    L4(2, 0, 304, 0, 0, 0, 0, 0x211F, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ASXY, 134, 0, 0), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x211E, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x211D, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x211C, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x1E67, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1E3B, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1E3C, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1E3D, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x1E3D, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 33 ATTACK 3 M: not started by a command */
const u16 necro_saca_033_head[4] = { HEAD(6, 0, 8, 7, 0, 3, 0) };
const u16 necro_saca_033[388] = {
    CMD(CM_RJA, 5, 33, 10), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_WSET, 16384, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(1, 0, 0, 0, 0, 0, 0, 0x1E67, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x211C, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x211D, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x211E, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 499, 0, 0, 0, 0, 0x211F, 0, 1, 0, 0, 0, 0, 0, 0, 0, 124, 0, 0),
    L6(1, 0, 328, 0, 0, 1, 0, 0x2120, 0, 1, 0, 0, 0, 0, 0, 0, 0, 126, 0, 0),
    L6(2, 0, 0, 0, 0, 1, 0, 0x2121, -42, 171, 0, 0, 64, 0, 0, 0, 0, 128, 11, 0),
    L6(2, 0, 0, 0, 0, 1, 0, 0x2122, 0, 1, 0, 0, 64, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_WCLT, 16399, 1, 16386), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(2, 0, 0, 0, 0, 1, 0, 0x2123, -67, 171, 0, 0, 64, 0, 0, 0, 0, 0, 14, 0),
    L6(2, 0, 0, 0, 0, 1, 0, 0x2123, -43, 171, 0, 0, 64, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 328, 0, 0, 1, 0, 0x2122, 0, 176, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_WCLT, 16399, 1, 16386), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(2, 0, 0, 0, 0, 1, 0, 0x2123, -67, 171, 0, 0, 0, 0, 0, 0, 0, 0, 18, 0),
    L6(2, 0, 0, 0, 0, 1, 0, 0x2123, -43, 171, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_RAPP, 5, 33, 20), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_IXFW, 0, 0, 3), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_WADD, 16384, 1, 32767), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_WCLT, 16384, 10, 2), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(14, 0, 0, 0, 0, 2, 0, 0x2122, 0, 1, 0, 0, 0, 21, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x2120, 0, 1, 0, 0, 0, 0, 0, 0, 0, 130, 0, 0),
    L6(3, 0, 304, 0, 0, 0, 0, 0x211F, 0, 1, 0, 0, 0, 0, 0, 0, 0, 132, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x211E, 0, 1, 0, 0, 0, 0, 0, 0, 0, 134, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x211D, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(6, 0, 0, 0, 0, 0, 0, 0x211C, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 64, 0, 0, 0, 0, 0, 0x1E67, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x1E3B, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x1E3C, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x1E3D, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x1E3D, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 34 ATTACK 3 L: not started by a command, 35 ATTACK 3 SP: not started by a command */
const u16 necro_saca_034_head[4] = { HEAD(6, 0, 8, 7, 0, 3, 0) };
const u16 necro_saca_034[436] = {
    CMD(CM_RJA, 5, 34, 10), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_WSET, 16384, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(1, 0, 0, 0, 0, 0, 0, 0x1E67, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x211C, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x211D, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x211E, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 499, 0, 0, 0, 0, 0x211F, 0, 1, 0, 0, 0, 0, 0, 0, 0, 124, 0, 0),
    L6(1, 0, 328, 0, 0, 1, 0, 0x2120, 0, 1, 0, 0, 0, 0, 0, 0, 0, 126, 0, 0),
    L6(2, 0, 0, 0, 0, 1, 0, 0x2121, -42, 142, 0, 0, 64, 0, 0, 0, 0, 128, 0, 0),
    CMD(CM_WCLT, 16399, 2, 16386), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(2, 0, 0, 0, 0, 1, 0, 0x2122, -67, 143, 0, 0, 64, 0, 0, 0, 0, 0, 13, 0),
    L6(2, 0, 0, 0, 0, 1, 0, 0x2122, -43, 143, 0, 0, 64, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_WCLT, 16399, 2, 16386), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(2, 0, 0, 0, 0, 1, 0, 0x2123, -67, 142, 0, 0, 64, 0, 0, 0, 0, 0, 16, 0),
    L6(2, 0, 0, 0, 0, 1, 0, 0x2123, -43, 142, 0, 0, 64, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_WCLT, 16399, 2, 16386), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(2, 0, 328, 0, 0, 1, 0, 0x2122, -67, 143, 0, 0, 0, 0, 0, 0, 0, 0, 19, 0),
    L6(2, 0, 328, 0, 0, 1, 0, 0x2122, -43, 143, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_WCLT, 16399, 2, 16386), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(2, 0, 0, 0, 0, 1, 0, 0x2123, -67, 142, 0, 0, 0, 0, 0, 0, 0, 0, 22, 0),
    L6(2, 0, 0, 0, 0, 1, 0, 0x2123, -43, 142, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_RAPP, 5, 34, 24), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_IXFW, 0, 0, 3), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_WADD, 16384, 1, 32767), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_WCLT, 16384, 10, 2), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(14, 0, 0, 0, 0, 2, 0, 0x2122, 0, 1, 0, 0, 0, 21, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x2120, 0, 1, 0, 0, 0, 0, 0, 0, 0, 130, 0, 0),
    L6(3, 0, 304, 0, 0, 0, 0, 0x211F, 0, 1, 0, 0, 0, 0, 0, 0, 0, 132, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x211E, 0, 1, 0, 0, 0, 0, 0, 0, 0, 134, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x211D, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(7, 0, 0, 0, 0, 0, 0, 0x211C, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 64, 0, 0, 0, 0, 0, 0x1E67, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x1E3B, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x1E3C, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x1E3D, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x1E3D, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 36 ATTACK 4 S: not started by a command, 37 ATTACK 4 M: not started by a command, 38 ATTACK 4 L: not started by a command, 39 ATTACK 4 SP: not started by a command */
const u16 necro_saca_036_head[4] = { HEAD(6, 0, 32, 11, 0, 14, 0) };
const u16 necro_saca_036[496] = {
    CMD(CM_JSR, 8, 13, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(1, 0, 0, 0, 0, 0, 0, 0x1E67, 0, 154, 0, 0, 0, 13, 6, 788, 0, 0, 0, 0),
    L6(39, 0, 0, 0, 0, 0, 0, 0x211C, 0, 154, 0, 0, 0, 0, 0, 788, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x211D, 0, 154, 0, 0, 0, 14, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x211E, 0, 154, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 502, 0, 0, 0, 0, 0x211F, 0, 154, 0, 0, 0, 0, 0, 0, 0, 124, 0, 0),
    L6(2, 0, 0, 0, 0, 3, 0, 0x2120, 0, 154, 0, 0, 0, 0, 0, 0, 0, 126, 0, 0),
    L6(2, 0, 0, 0, 0, 3, 0, 0x2159, -56, 144, 0, 128, 0, 0, 0, 0, 0, 128, 0, 0),
    L6(2, 0, 329, 0, 0, 3, 0, 0x2122, 0, 145, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 3, 0, 0x215B, -73, 144, 0, 128, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 3, 0, 0x215C, 0, 145, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 3, 0, 0x215B, -45, 144, 0, 128, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 329, 0, 0, 3, 0, 0x2122, 0, 145, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 3, 0, 0x215D, 0, 144, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_FOR, 0, 0, 4), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_RAPP, 5, 36, 18), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_JMP, 5, 36, 31), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_WCLT, 16399, 4, 16386), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(1, 0, 0, 0, 0, 3, 0, 0x215B, -44, 144, 0, 128, 0, 0, 0, 0, 0, 0, 21, 0),
    L6(1, 0, 0, 0, 0, 3, 0, 0x215B, -73, 144, 0, 128, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 3, 0, 0x215C, 0, 145, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_WCLT, 16399, 4, 16386), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(1, 0, 0, 0, 0, 3, 0, 0x215B, -44, 144, 0, 128, 0, 0, 0, 0, 0, 0, 25, 0),
    L6(1, 0, 0, 0, 0, 3, 0, 0x215B, -45, 144, 0, 128, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 329, 0, 0, 3, 0, 0x2122, 0, 145, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_WCLT, 16399, 4, 16386), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(1, 0, 0, 0, 0, 3, 0, 0x215D, -44, 144, 0, 128, 0, 0, 0, 0, 0, 0, 29, 0),
    L6(1, 0, 0, 0, 0, 3, 0, 0x215D, -73, 144, 0, 128, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 329, 0, 0, 3, 0, 0x215B, 0, 145, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_NEX, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(8, 0, 0, 0, 0, 4, 0, 0x2122, -78, 144, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(6, 0, 0, 0, 0, 0, 0, 0x2120, 0, 1, 0, 0, 0, 21, 0, 0, 0, 130, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x211F, 0, 1, 0, 0, 0, 0, 0, 0, 0, 132, 0, 0),
    L6(3, 0, 304, 0, 0, 0, 0, 0x211E, 0, 1, 0, 0, 0, 0, 0, 0, 0, 134, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x211D, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(6, 0, 0, 0, 0, 0, 0, 0x211C, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 64, 0, 0, 0, 0, 0, 0x1E67, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x1E3B, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x1E3C, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x1E3D, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x1E3D, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 40 ATTACK 5 S: not started by a command */
const u16 necro_saca_040_head[4] = { HEAD(6, 0, 25, 17, 0, 1, 24) };
const u16 necro_saca_040[136] = {
    CMD(CM_CAFR, 2, 1, 3), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_CARE, 2, 1, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(1, 0, 0, 0, 0, 0, 0, 0x1F31, 0, 122, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1F32, 0, 123, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1F33, 0, 123, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 498, 0, 0, 0, 0, 0x20DF, 0, 124, 0, 0, 0, 0, 0, 0, 0, 188, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x20E0, 0, 124, 0, 0, 0, 0, 0, 0, 0, 190, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x20E1, 0, 178, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x20E1, -37, 125, 0, 0, 0, 0, 0, 0, 0, 192, 0, 0),
    L6(5, 0, 0, 0, 0, 0, 0, 0x20E1, 0, 178, 0, 0, 0, 21, 0, 0, 0, 0, 0, 0),
    CMD(CM_JMP, 2, 4, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 41 ATTACK 5 M: not started by a command */
const u16 necro_saca_041_head[4] = { HEAD(6, 0, 25, 17, 0, 0, 24) };
const u16 necro_saca_041[136] = {
    CMD(CM_CAFR, 2, 1, 8), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_CARE, 2, 1, 10), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(1, 0, 0, 0, 0, 0, 0, 0x1F31, 0, 122, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1F32, 0, 123, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1F33, 0, 123, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 498, 0, 0, 0, 0, 0x20DF, 0, 124, 0, 0, 0, 0, 0, 0, 0, 188, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x20E0, 0, 124, 0, 0, 0, 0, 0, 0, 0, 190, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x20E1, 0, 178, 0, 0, 0, 0, 0, 0, 0, 192, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x20E1, -37, 125, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x20E1, 0, 178, 0, 0, 0, 21, 0, 0, 0, 192, 0, 0),
    CMD(CM_JMP, 2, 4, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 42 ATTACK 5 L: not started by a command, 43 ATTACK 5 SP: not started by a command */
const u16 necro_saca_042_head[4] = { HEAD(6, 0, 25, 16, 0, 0, 24) };
const u16 necro_saca_042[124] = {
    CMD(CM_CAFR, 2, 1, 9), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_CARE, 2, 1, 11), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(1, 0, 0, 0, 0, 0, 0, 0x1F31, 0, 122, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x1F32, 0, 123, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1F33, 0, 123, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 498, 0, 0, 0, 0, 0x20DF, 0, 124, 0, 0, 0, 0, 0, 0, 0, 188, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x20E0, 0, 124, 0, 0, 0, 0, 0, 0, 0, 190, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x20E1, 0, 178, 0, 0, 0, 0, 0, 0, 0, 192, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x20E1, -37, 125, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_JMP, 2, 4, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 44 ATTACK 6 S: not started by a command */
const u16 necro_saca_044_head[4] = { HEAD(4, 22, 8, 13, 0, 1, 40) };
const u16 necro_saca_044[124] = {
    CMD(CM_JSR, 8, 4, 1), 0, 0, 0, 0,
    L4(6, 0, 281, 0, 0, 0, 0, 0x1E24, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1EC3, 0, 84, 0, 0, 0, 1, 42),
    L4(6, 20, 0, 0, 0, 0, 0, 0x1EC3, 0, 84, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1EC4, 0, 84, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1EC5, 0, 84, 0, 0, 0, 0, 0),
    L4(3, 0, 496, 0, 0, 0, 0, 0x1EC6, 0, 84, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 7, 0x1EC7, 0, 85, 0, 0, 0, 0, 0),
    L4(4, 0, 269, 0, 0, 0, 7, 0x1EC8, -18, 86, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 7, 0x1EC9, 0, 86, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 11, 0x1ECA, 0, 87, 0, 0, 0, 21, 0),
    L4(3, 0, 0, 0, 0, 0, 11, 0x1ECB, 0, 85, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1ECC, 0, 85, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x1ECD, 0, 85, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 45 ATTACK 6 M: not started by a command */
const u16 necro_saca_045_head[4] = { HEAD(4, 22, 10, 13, 0, 1, 40) };
const u16 necro_saca_045[124] = {
    CMD(CM_JSR, 8, 4, 1), 0, 0, 0, 0,
    L4(6, 0, 281, 0, 0, 0, 0, 0x1E24, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1EC3, 0, 84, 0, 0, 0, 1, 42),
    L4(6, 20, 0, 0, 0, 0, 0, 0x1EC3, 0, 84, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1EC4, 0, 84, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1EC5, 0, 84, 0, 0, 0, 0, 0),
    L4(3, 0, 496, 0, 0, 0, 0, 0x1EC6, 0, 84, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 7, 0x1EC7, 0, 85, 0, 0, 0, 0, 0),
    L4(5, 0, 269, 0, 0, 0, 7, 0x1EC8, -63, 86, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 7, 0x1EC9, 0, 86, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 11, 0x1ECA, 0, 87, 0, 0, 0, 21, 0),
    L4(3, 0, 0, 0, 0, 0, 11, 0x1ECB, 0, 85, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1ECC, 0, 85, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x1ECD, 0, 85, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 46 ATTACK 6 L: not started by a command */
const u16 necro_saca_046_head[4] = { HEAD(4, 22, 12, 13, 0, 1, 40) };
const u16 necro_saca_046[124] = {
    CMD(CM_JSR, 8, 4, 1), 0, 0, 0, 0,
    L4(6, 0, 281, 0, 0, 0, 0, 0x1E24, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1EC3, 0, 84, 0, 0, 0, 1, 42),
    L4(6, 20, 0, 0, 0, 0, 0, 0x1EC3, 0, 84, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x1EC4, 0, 84, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1EC5, 0, 84, 0, 0, 0, 0, 0),
    L4(3, 0, 496, 0, 0, 0, 0, 0x1EC6, 0, 84, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 7, 0x1EC7, 0, 85, 0, 0, 0, 0, 0),
    L4(6, 0, 269, 0, 0, 0, 7, 0x1EC8, -64, 86, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 7, 0x1EC9, 0, 86, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 11, 0x1ECA, 0, 87, 0, 0, 0, 21, 0),
    L4(3, 0, 0, 0, 0, 0, 11, 0x1ECB, 0, 85, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1ECC, 0, 85, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x1ECD, 0, 85, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 47 ATTACK 6 SP: not started by a command */
const u16 necro_saca_047_head[4] = { HEAD(4, 22, 14, 13, 0, 2, 40) };
const u16 necro_saca_047[204] = {
    CMD(CM_JSR, 8, 4, 1), 0, 0, 0, 0,
    CMD(CM_JSR, 8, 28, 1), 0, 0, 0, 0,
    L4(6, 0, 281, 0, 0, 0, 0, 0x1E24, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1EC3, 0, 84, 0, 0, 0, 1, 42),
    L4(6, 20, 0, 0, 0, 0, 0, 0x1EC3, 0, 84, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1EC4, 0, 84, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1EC5, 0, 84, 0, 0, 0, 0, 0),
    L4(2, 0, 496, 0, 0, 0, 0, 0x1EC6, 0, 84, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 7, 0x1EC7, 0, 85, 0, 0, 0, 0, 0),
    L4(3, 1, 269, 0, 0, 0, 7, 0x1EC8, -81, 191, 0, 0, 0, 0, 0),
    CMD(CM_HJMP, 16387, 16387, 16387), 0, 0, 0, 0,
    L4(1, 1, 0, 0, 0, 0, 7, 0x1EC9, 0, 86, 0, 0, 0, 0, 0),
    CMD(CM_IXFW, 0, 0, 8), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 0, 7, 0x1EC9, 0, 86, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 11, 0x1ECA, 0, 87, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 11, 0x1ECB, 0, 85, 0, 0, 0, 0, 0),
    L4(1, 0, 496, 0, 0, 0, 0, 0x1EC6, 0, 84, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 7, 0x1EC7, 0, 85, 0, 0, 0, 0, 0),
    L4(6, 1, 269, 0, 0, 0, 7, 0x1EC8, -82, 86, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 7, 0x1EC9, 0, 86, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 11, 0x1ECA, 0, 87, 0, 0, 0, 21, 0),
    L4(3, 0, 0, 0, 0, 0, 11, 0x1ECB, 0, 85, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1ECC, 0, 85, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x1ECD, 0, 85, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 48 ATTACK 7 S: not started by a command, 49 ATTACK 7 M: not started by a command */
const u16 necro_saca_048_head[4] = { HEAD(6, 0, 57, 12, 0, 0, 0) };
const u16 necro_saca_048[364] = {
    CMD(CM_CAFR, 2, 1, 5), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_CARE, 2, 1, 5), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_JSR, 8, 14, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(40, 0, 0, 0, 0, 0, 0, 0x2096, 0, 154, 0, 0, 0, 13, 20, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x2097, 0, 154, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(6, 0, 0, 0, 0, 0, 0, 0x2098, -52, 148, 0, 0, 0, 0, 0, 0, 0, 192, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1E85, 0, 131, 0, 0, 0, 21, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x1E86, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1E87, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 64, 0, 0, 0, 0, 0, 0x1E88, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1E3B, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1E3C, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1E3D, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x1E3D, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0), 0x0004, 0x0002, 0x0B00, 0x0C00, 0x0300, 0x0000, 0x0000, 0x2003,
    CMD(CM_UJA2, 0, 0, 0), 0x0300, 0x0000, 0x0000, 0x2005, 0x0013, 0x0000, 0x0000, 0x0000,
    L6(3, 0, 0, 0, 0, 0, 0, 0x201B, 0, 153, 0, 0, 0, 0, 0, 768, 0, 0, 32, 28),
    CMD(CM_UJA2, 8192, 0, 0), 0x0300, 0x0000, 0x0000, 0x201D, 0x0013, 0x2000, 0x0000, 0x0000,
    L6(4, 0, 0, 0, 0, 0, 0, 0x201E, 0, 173, 0, 0, 0, 0, 0, 512, 0, 0, 32, 31),
    CMD(CM_FOR2, -24576, 0, 0), 0x0200, 0x0000, 0x0000, 0x2020, 0x000E, 0xA000, 0x0000, 0x0000,
    L6(1, 0, 269, 0, 0, 0, 0, 0x2021, 0, 117, 0, 0, 0, 0, 0, 512, 0, 0, 32, 34),
    L6(248, 14, 3584, 0, 0, 0, 0, 0x0000, 8, 0, 0, 0, 0, 32, 35, 63503, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x2024, 0, 2, 0, 0, 0, 21, 0, 1024, 0, 0, 31, 216),
    CMD(CM_DUMMY, 16384, 0, 0), 0x000A, 0x0002, 0x4005, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
    L6(4, 64, 0, 0, 0, 0, 0, 0x1E3B, 0, 1, 0, 0, 0, 0, 0, 1024, 0, 0, 30, 60),
    CMD(CM_DUMMY, 8192, 0, 0), 0x0400, 0x0000, 0x0000, 0x1E3D, 0x0000, 0x2000, 0x0000, 0x0000,
    L6(250, 255, 0, 0, 0, 0, 0, 0x1E3D, 0, 1, 0, 0, 0, 0, 0, 7, 0, 0, 0, 32),
    CMD(CM_DUMMY, 0, 0, 0), 0x0440, 0x0000, 0x0000, 0x1E22, 0x0000, 0x4000, 0x0000, 0x0000,
    L6(4, 0, 0, 0, 0, 0, 0, 0x1E23, 0, 2, 0, 0, 0, 0, 0, 1024, 0, 0, 30, 36),
    CMD(CM_DUMMY, 16384, 0, 0), 0xFAFF, 0x0000, 0x0000, 0x1E24, 0x0000, 0x4000, 0x0000, 0x0000,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 54 ATTACK 8 L: not started by a command, 55 ATTACK 8 SP: not started by a command, 56 ATTACK 9 S: not started by a command, 57 ATTACK 9 M: not started by a command */
const u16 necro_saca_054_head[4] = { HEAD(4, 0, 2, 11, 0, 1, 33) };
const u16 necro_saca_054[76] = {
    CMD(CM_JSR, 8, 21, 1), 0, 0, 0, 0,
    L4(2, 1, 0, 0, 0, 0, 0, 0x1E47, 0, 7, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1E48, 0, 7, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1E49, 0, 7, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1F60, 0, 95, 0, 0, 0, 0, 0),
    L4(1, 0, 268, 0, 0, 0, 0, 0x1F61, 0, 95, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1F62, -25, 162, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x1F63, 0, 162, 0, 0, 0, 21, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 58 ATTACK 9 L: not started by a command */
const u16 necro_saca_058_head[4] = { HEAD(4, 0, 9, 13, 0, 1, 0) };
const u16 necro_saca_058[196] = {
    L4(1, 0, 0, 0, 0, 0, 0, 0x1E22, 0, 2, 0, 0, 0, 21, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1E23, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x201B, 0, 153, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x201C, 0, 153, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x201D, 0, 153, 0, 0, 0, 0, 0),
    L4(8, 0, 0, 0, 0, 0, 0, 0x201E, 0, 173, 0, 0, 0, 33, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x201F, 0, 190, 0, 0, 0, 30, 39),
    L4(1, 0, 0, 0, 0, 0, 0, 0x201F, 0, 190, 0, 0, 0, 30, 40),
    L4(1, 0, 0, 0, 0, 0, 0, 0x2020, 0, 117, 0, 0, 0, 0, 0),
    L4(1, 0, 269, 0, 0, 0, 0, 0x2021, 0, 117, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x2022, -70, 119, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x2023, 0, 120, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x2024, 0, 2, 0, 0, 0, 21, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1FD8, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_IF_L, 2, 16389, 0), 0, 0, 0, 0,
    L4(4, 0, 0, 0, 0, 0, 0, 0x1E3B, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1E3C, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 64, 0, 0, 0, 0, 0, 0x1E3D, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x1E3D, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_SPS, 0, 0, 32), 0, 0, 0, 0,
    L4(4, 0, 0, 0, 0, 0, 0, 0x1E22, 0, 2, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1E23, 0, 2, 0, 0, 0, 0, 0),
    L4(4, 64, 0, 0, 0, 0, 0, 0x1E24, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x1E24, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 59 ATTACK 9 SP: not started by a command */
const u16 necro_saca_059_head[4] = { HEAD(4, 0, 11, 13, 0, 1, 0) };
const u16 necro_saca_059[196] = {
    L4(1, 0, 0, 0, 0, 0, 0, 0x1E22, 0, 2, 0, 0, 0, 21, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1E23, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x201B, 0, 153, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x201C, 0, 153, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x201D, 0, 153, 0, 0, 0, 0, 0),
    L4(8, 0, 0, 0, 0, 0, 0, 0x201E, 0, 173, 0, 0, 0, 33, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x201F, 0, 190, 0, 0, 0, 30, 39),
    L4(1, 0, 0, 0, 0, 0, 0, 0x201F, 0, 190, 0, 0, 0, 30, 40),
    L4(2, 0, 0, 0, 0, 0, 0, 0x2020, 0, 117, 0, 0, 0, 0, 0),
    L4(2, 0, 269, 0, 0, 0, 0, 0x2021, 0, 117, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x2022, -71, 119, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x2023, 0, 120, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x2024, 0, 2, 0, 0, 0, 21, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1FD8, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_IF_L, 2, 16389, 0), 0, 0, 0, 0,
    L4(4, 0, 0, 0, 0, 0, 0, 0x1E3B, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1E3C, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 64, 0, 0, 0, 0, 0, 0x1E3D, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x1E3D, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_SPS, 0, 0, 32), 0, 0, 0, 0,
    L4(4, 0, 0, 0, 0, 0, 0, 0x1E22, 0, 2, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1E23, 0, 2, 0, 0, 0, 0, 0),
    L4(4, 64, 0, 0, 0, 0, 0, 0x1E24, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x1E24, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 60 ATTACK 10 S: not started by a command */
const u16 necro_saca_060_head[4] = { HEAD(4, 0, 13, 13, 0, 1, 0) };
const u16 necro_saca_060[196] = {
    L4(1, 0, 0, 0, 0, 0, 0, 0x1E22, 0, 2, 0, 0, 0, 21, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1E23, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x201B, 0, 153, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x201C, 0, 153, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x201D, 0, 153, 0, 0, 0, 0, 0),
    L4(9, 0, 0, 0, 0, 0, 0, 0x201E, 0, 173, 0, 0, 0, 33, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x201F, 0, 190, 0, 0, 0, 30, 39),
    L4(2, 0, 0, 0, 0, 0, 0, 0x201F, 0, 190, 0, 0, 0, 30, 40),
    L4(2, 0, 0, 0, 0, 0, 0, 0x2020, 0, 117, 0, 0, 0, 0, 0),
    L4(2, 0, 269, 0, 0, 0, 0, 0x2021, 0, 117, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x2022, -72, 119, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x2023, 0, 120, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x2024, 0, 2, 0, 0, 0, 21, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1FD8, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_IF_L, 2, 16389, 0), 0, 0, 0, 0,
    L4(4, 0, 0, 0, 0, 0, 0, 0x1E3B, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1E3C, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 64, 0, 0, 0, 0, 0, 0x1E3D, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x1E3D, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_SPS, 0, 0, 32), 0, 0, 0, 0,
    L4(4, 0, 0, 0, 0, 0, 0, 0x1E22, 0, 2, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1E23, 0, 2, 0, 0, 0, 0, 0),
    L4(4, 64, 0, 0, 0, 0, 0, 0x1E24, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x1E24, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 61 ATTACK 10 M: not started by a command */
const u16 necro_saca_061_head[4] = { HEAD(4, 0, 15, 13, 0, 2, 0) };
const u16 necro_saca_061[204] = {
    CMD(CM_JSR, 8, 29, 1), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 0, 0, 0x1E22, 0, 2, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x1E23, 0, 2, 0, 0, 0, 21, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x201B, 0, 153, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x201C, 0, 153, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x201D, 0, 153, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x201E, 0, 173, 0, 0, 0, 33, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x201F, 0, 190, 0, 0, 0, 30, 39),
    L4(2, 0, 0, 0, 0, 0, 0, 0x201F, 0, 190, 0, 0, 0, 30, 40),
    L4(2, 30, 0, 0, 0, 0, 0, 0x2020, 0, 117, 0, 0, 0, 0, 0),
    L4(3, 0, 269, 0, 0, 0, 0, 0x2021, 0, 117, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x2022, -83, 192, 0, 0, 0, 0, 0),
    L4(2, 21, 0, 0, 0, 0, 0, 0x2023, -84, 193, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x2024, 0, 2, 0, 0, 0, 21, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1FD8, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_IF_L, 2, 16389, 0), 0, 0, 0, 0,
    L4(4, 0, 0, 0, 0, 0, 0, 0x1E3B, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1E3C, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 64, 0, 0, 0, 0, 0, 0x1E3D, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x1E3D, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_SPS, 0, 0, 32), 0, 0, 0, 0,
    L4(4, 0, 0, 0, 0, 0, 0, 0x1E22, 0, 2, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1E23, 0, 2, 0, 0, 0, 0, 0),
    L4(4, 64, 0, 0, 0, 0, 0, 0x1E24, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x1E24, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 62 ATTACK 10 L: not started by a command */
const u16 necro_saca_062_head[4] = { HEAD(6, 0, 8, 12, 0, 0, 38) };
const u16 necro_saca_062[196] = {
    L6(4, 0, 0, 0, 0, 0, 0, 0x2111, 0, 163, 0, 0, 0, 21, 0, 0, 0, 172, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x2112, 0, 163, 0, 0, 0, 0, 0, 0, 0, 174, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x2113, 0, 163, 0, 0, 0, 0, 0, 0, 0, 176, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x2114, 0, 163, 0, 0, 0, 0, 0, 0, 0, 178, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x2115, 0, 163, 0, 0, 0, 0, 0, 0, 0, 180, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x2116, 0, 163, 0, 0, 0, 0, 0, 0, 0, 182, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x2117, 0, 163, 0, 0, 0, 0, 0, 0, 0, 184, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x2118, 0, 163, 0, 0, 0, 0, 0, 0, 0, 186, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x2119, 0, 163, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 64, 0, 0, 0, 0, 0, 0x211A, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x2119, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x2118, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x211B, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1E3C, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x1E3D, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x1E3D, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 63 ATTACK 10 SP: not started by a command, 64 ATTACK 11 S: not started by a command, 65 ATTACK 11 M: not started by a command */
const u16 necro_saca_063_head[4] = { HEAD(4, 0, 0, 13, 0, 3, 0) };
const u16 necro_saca_063[188] = {
    L4(2, 0, 0, 0, 0, 0, 0, 0x225C, 0, 1, 0, 0, 0, 21, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x225D, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x225E, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x225F, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x2260, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 40, 504, 0, 0, 0, 0, 0x2261, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x2262, 0, 26, 0, 0, 0, 0, 0),
    L4(2, 0, 268, 0, 0, 0, 0, 0x2263, 0, 26, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x2264, -31, 188, 0, 0, 0, 21, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x2265, 0, 188, 0, 0, 0, 0, 0),
    L4(2, 0, 268, 0, 0, 0, 0, 0x2266, -31, 188, 0, 0, 0, 21, 0),
    CMD(CM_IF_S, 1088, -32763, 0), 0, 0, 0, 0,
    L4(3, 0, 0, 0, 0, 0, 0, 0x2267, 0, 26, 0, 0, 0, 0, 0),
    L4(4, 20, 0, 0, 0, 0, 0, 0x2268, 0, 26, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x2269, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x226A, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x20AD, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1E3B, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x20AE, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 64, 0, 0, 0, 0, 0, 0x1E3C, 0, 1, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x20AF, 0, 1, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x1E3D, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x1E3D, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 66 ATTACK 11 L: not started by a command */
const u16 necro_saca_066_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 necro_saca_066[92] = {
    L4(2, 0, 0, 0, 0, 0, 0, 0x20AF, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1E3D, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x20AE, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1E3C, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x20AD, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1E3B, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x20AE, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1E3C, 0, 1, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x20AF, 0, 1, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x1E3D, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x1E3D, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

extern const u16 necro_cbca_000[], necro_cbca_001[], necro_cbca_002[], necro_cbca_003[], necro_cbca_004[], necro_cbca_005[], necro_cbca_006[], necro_cbca_007[], necro_cbca_008[], necro_cbca_009[], necro_cbca_010[], necro_cbca_011[], necro_cbca_012[], necro_cbca_013[], necro_cbca_014[], necro_cbca_015[], necro_cbca_016[], necro_cbca_017[], necro_cbca_018[], necro_cbca_019[], necro_cbca_020[], necro_cbca_021[], necro_cbca_022[], necro_cbca_023[], necro_cbca_024[], necro_cbca_025[], necro_cbca_026[], necro_cbca_027[], necro_cbca_028[], necro_cbca_029[];

/* cbca scripts (debug viewer: ETC): 30 entries */
const u32 necro_cbca[31] = {
    (u32)necro_cbca_000,  /* 0 APPEAR JUNBI 1 */
    (u32)necro_cbca_001,  /* 1 APPEAR JUNBI 2 */
    (u32)necro_cbca_002,  /* 2 APPEAR JUNBI 3 */
    (u32)necro_cbca_003,  /* 3 APPEAR JUNBI 4 */
    (u32)necro_cbca_004,  /* 4 APPEAR JUNBI 5 */
    (u32)necro_cbca_005,  /* 5 APPEAR JUNBI 6 */
    (u32)necro_cbca_006,  /* 6 APPEAR JUNBI 7 */
    (u32)necro_cbca_007,  /* 7 APPEAR JUNBI 8 */
    (u32)necro_cbca_008,  /* 8 APPEAR 1 */
    (u32)necro_cbca_009,  /* 9 APPEAR 2 */
    (u32)necro_cbca_010,  /* 10 APPEAR 3 */
    (u32)necro_cbca_011,  /* 11 APPEAR 4 */
    (u32)necro_cbca_012,  /* 12 APPEAR 5 */
    (u32)necro_cbca_013,  /* 13 APPEAR 6 */
    (u32)necro_cbca_014,  /* 14 APPEAR 7 */
    (u32)necro_cbca_015,  /* 15 APPEAR 8 */
    (u32)necro_cbca_016,  /* 16 SP APPEAR 1 */
    (u32)necro_cbca_017,  /* 17 SP APPEAR 2 */
    (u32)necro_cbca_018,  /* 18 SP APPEAR 3 */
    (u32)necro_cbca_019,  /* 19 SP APPEAR 4 */
    (u32)necro_cbca_020,  /* 20 SP APPEAR 5 */
    (u32)necro_cbca_021,  /* 21 SP APPEAR 6 */
    (u32)necro_cbca_022,  /* 22 SP APPEAR 7 */
    (u32)necro_cbca_023,  /* 23 SP APPEAR 8 */
    (u32)necro_cbca_024,  /* 24 ZANNEN 1 */
    (u32)necro_cbca_025,  /* 25 ZANNEN 2 */
    (u32)necro_cbca_026,  /* 26 ZANNEN 3 */
    (u32)necro_cbca_027,  /* 27 ZANNEN 4 */
    (u32)necro_cbca_028,  /* 28 ZANNEN 5 */
    (u32)necro_cbca_029,  /* 29 ZANNEN 6 */
    0
};

/* script: 0 APPEAR JUNBI 1 */
const u16 necro_cbca_000_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 necro_cbca_000[4] = {
    CMD(CM_IF_L, 2, 4, 3),
};

/* script: 1 APPEAR JUNBI 2 */
const u16 necro_cbca_001_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 necro_cbca_001[16] = {
    CMD(CM_RJA, 8, 0, 1),
    CMD(CM_RJA2, 7, 1, 1),
    CMD(CM_RJA3, 7, 10, 1),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 2 APPEAR JUNBI 3 */
const u16 necro_cbca_002_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 necro_cbca_002[16] = {
    CMD(CM_RJA, 8, 0, 1),
    CMD(CM_RJA2, 7, 2, 1),
    CMD(CM_RJA3, 7, 11, 1),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 3 APPEAR JUNBI 4 */
const u16 necro_cbca_003_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 necro_cbca_003[16] = {
    CMD(CM_RJA, 8, 0, 1),
    CMD(CM_RJA2, 7, 4, 1),
    CMD(CM_RJA3, 7, 12, 1),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 4 APPEAR JUNBI 5 */
const u16 necro_cbca_004_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 necro_cbca_004[16] = {
    CMD(CM_RJA, 8, 0, 1),
    CMD(CM_RJA2, 7, 13, 1),
    CMD(CM_RJA3, 7, 29, 1),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 5 APPEAR JUNBI 6 */
const u16 necro_cbca_005_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 necro_cbca_005[16] = {
    CMD(CM_RJA, 1, 64, 6),
    CMD(CM_RJA2, 1, 65, 1),
    CMD(CM_RJA3, 1, 66, 1),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 6 APPEAR JUNBI 7 */
const u16 necro_cbca_006_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 necro_cbca_006[16] = {
    CMD(CM_RJA, 8, 0, 1),
    CMD(CM_RJA2, 7, 23, 1),
    CMD(CM_RJA3, 7, 24, 1),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 7 APPEAR JUNBI 8 */
const u16 necro_cbca_007_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 necro_cbca_007[16] = {
    CMD(CM_CAFR, 2, 1, 0),
    CMD(CM_CARE, 2, 1, 0),
    CMD(CM_RJA7, 4, 8, 3),
    CMD(CM_DJMP, 10, 8, 8),
};

/* script: 8 APPEAR 1 */
const u16 necro_cbca_008_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 necro_cbca_008[16] = {
    CMD(CM_CAFR, 2, 1, 2),
    CMD(CM_CARE, 2, 1, 2),
    CMD(CM_RJA7, 4, 17, 3),
    CMD(CM_DJMP, 10, 8, 8),
};

/* script: 9 APPEAR 2 */
const u16 necro_cbca_009_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 necro_cbca_009[16] = {
    CMD(CM_RJA, 8, 0, 1),
    CMD(CM_RJA2, 7, 26, 1),
    CMD(CM_RJA3, 7, 27, 1),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 10 APPEAR 3 */
const u16 necro_cbca_010_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 necro_cbca_010[28] = {
    CMD(CM_DJMP, 8, 0, 16388),
    CMD(CM_CAFR, 2, 1, 0),
    CMD(CM_CARE, 2, 1, 0),
    CMD(CM_RET, 0, 0, 0),
    CMD(CM_CAFR, 2, 1, 6),
    CMD(CM_CARE, 2, 1, 6),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 11 APPEAR 4 */
const u16 necro_cbca_011_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 necro_cbca_011[28] = {
    CMD(CM_DJMP, 8, 0, 16388),
    CMD(CM_CAFR, 2, 1, 7),
    CMD(CM_CARE, 2, 1, 7),
    CMD(CM_RET, 0, 0, 0),
    CMD(CM_CAFR, 2, 1, 2),
    CMD(CM_CARE, 2, 1, 2),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 12 APPEAR 5 */
const u16 necro_cbca_012_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 necro_cbca_012[16] = {
    CMD(CM_IMGS, 0, 6, 0),
    CMD(CM_EXEC, 20, 22, 0),
    CMD(CM_STOP, -40, 40, 1),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 13 APPEAR 6 */
const u16 necro_cbca_013_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 necro_cbca_013[16] = {
    CMD(CM_IMGS, 0, 6, 0),
    CMD(CM_EXEC, 20, 20, 0),
    CMD(CM_STOP, -40, 48, 1),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 14 APPEAR 7 */
const u16 necro_cbca_014_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 necro_cbca_014[16] = {
    CMD(CM_IMGS, 0, 2, 0),
    CMD(CM_EXEC, 20, 21, 0),
    CMD(CM_STOP, -40, 40, 1),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 15 APPEAR 8 */
const u16 necro_cbca_015_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 necro_cbca_015[16] = {
    CMD(CM_CAFR, 2, 1, 0),
    CMD(CM_CARE, 2, 1, 0),
    CMD(CM_RJA7, 4, 5, 3),
    CMD(CM_DJMP, 10, 8, 8),
};

/* script: 16 SP APPEAR 1 */
const u16 necro_cbca_016_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 necro_cbca_016[16] = {
    CMD(CM_CAFR, 2, 1, 0),
    CMD(CM_CARE, 2, 1, 0),
    CMD(CM_RJA7, 4, 3, 3),
    CMD(CM_DJMP, 10, 8, 8),
};

/* script: 17 SP APPEAR 2 */
const u16 necro_cbca_017_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 necro_cbca_017[16] = {
    CMD(CM_CAFR, 2, 1, 2),
    CMD(CM_CARE, 2, 1, 2),
    CMD(CM_RJA7, 4, 14, 3),
    CMD(CM_DJMP, 10, 8, 8),
};

/* script: 18 SP APPEAR 3 */
const u16 necro_cbca_018_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 necro_cbca_018[16] = {
    CMD(CM_CAFR, 2, 1, 2),
    CMD(CM_CARE, 2, 1, 2),
    CMD(CM_RJA7, 4, 12, 3),
    CMD(CM_DJMP, 10, 8, 8),
};

/* script: 19 SP APPEAR 4 */
const u16 necro_cbca_019_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 necro_cbca_019[16] = {
    CMD(CM_CAFR, 2, 1, 0),
    CMD(CM_CARE, 2, 1, 0),
    CMD(CM_RJA7, 4, 7, 3),
    CMD(CM_DJMP, 10, 8, 8),
};

/* script: 20 SP APPEAR 5 */
const u16 necro_cbca_020_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 necro_cbca_020[16] = {
    CMD(CM_CAFR, 2, 1, 2),
    CMD(CM_CARE, 2, 1, 2),
    CMD(CM_RJA7, 4, 16, 3),
    CMD(CM_DJMP, 10, 8, 8),
};

/* script: 21 SP APPEAR 6 */
const u16 necro_cbca_021_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 necro_cbca_021[16] = {
    CMD(CM_RJA, 8, 0, 1),
    CMD(CM_RJA2, 7, 30, 1),
    CMD(CM_RJA3, 7, 31, 1),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 22 SP APPEAR 7 */
const u16 necro_cbca_022_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 necro_cbca_022[16] = {
    CMD(CM_RJA, 8, 0, 1),
    CMD(CM_RJA2, 7, 34, 1),
    CMD(CM_RJA3, 7, 35, 1),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 23 SP APPEAR 8 */
const u16 necro_cbca_023_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 necro_cbca_023[8] = {
    CMD(CM_RJA4, 5, 62, 1),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 24 ZANNEN 1 */
const u16 necro_cbca_024_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 necro_cbca_024[16] = {
    CMD(CM_RJA, 8, 0, 1),
    CMD(CM_RJA2, 7, 36, 1),
    CMD(CM_RJA3, 7, 37, 1),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 25 ZANNEN 2 */
const u16 necro_cbca_025_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 necro_cbca_025[16] = {
    CMD(CM_RJA, 8, 0, 1),
    CMD(CM_RJA2, 7, 38, 1),
    CMD(CM_RJA3, 7, 39, 1),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 26 ZANNEN 3 */
const u16 necro_cbca_026_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 necro_cbca_026[16] = {
    CMD(CM_RJA, 8, 0, 1),
    CMD(CM_RJA2, 7, 40, 1),
    CMD(CM_RJA3, 7, 41, 1),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 27 ZANNEN 4 */
const u16 necro_cbca_027_head[4] = { HEAD(2, 0, 14, 0, 0, 0, 0) };
const u16 necro_cbca_027[16] = {
    CMD(CM_EXEC, 49, 25, 0),
    CMD(CM_IMGS, 0, 12, 0),
    CMD(CM_EXEC, 16, 5, 0),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 28 ZANNEN 5 */
const u16 necro_cbca_028_head[4] = { HEAD(2, 0, 14, 0, 0, 0, 0) };
const u16 necro_cbca_028[16] = {
    CMD(CM_EXEC, 49, 26, 0),
    CMD(CM_IMGS, 0, 12, 0),
    CMD(CM_EXEC, 16, 5, 0),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 29 ZANNEN 6 */
const u16 necro_cbca_029_head[4] = { HEAD(2, 0, 15, 0, 0, 0, 0) };
const u16 necro_cbca_029[16] = {
    CMD(CM_EXEC, 49, 27, 0),
    CMD(CM_IMGS, 0, 12, 0),
    CMD(CM_EXEC, 16, 5, 0),
    CMD(CM_RET, 0, 0, 0),
};
