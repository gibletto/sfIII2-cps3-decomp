/*
 * KEN_YUCA.C  Ken's animation scripts
 *
 * The animation scripts Ken's moves run, one table per kind of script (yuca), each an index of
 * scripts followed by the scripts. set_char_base_data (CHARID) installs the tables as char_table[];
 * set_char_move_init2 starts script char_table[kind][index] and char_move steps it: a frame line
 * shows sprite `number` for `ctr` frames with its sound, hit boxes (hit_ix into the hit_ix_table),
 * attack (att into the catt_table) and effect; a command line (CM_ codes) jumps, loops, tests and
 * sets. See charscr.h for the line layouts and the kind numbers a command's koc names.
 */

#include "types.h"
#include "structs.h"
#include "charscr.h"

#pragma section TBL

extern const u16 ken_yuca_000[], ken_yuca_001[], ken_yuca_008[], ken_yuca_009[], ken_yuca_016[], ken_yuca_024[], ken_yuca_032[], ken_yuca_036[], ken_yuca_040[], ken_yuca_048[], ken_yuca_060[], ken_yuca_061[], ken_yuca_062[], ken_yuca_063[];

/* yuca scripts (debug viewer: ETC): 68 entries */
const u32 ken_yuca[69] = {
    (u32)ken_yuca_000,  /* 0 APPEAR JUNBI 1 */
    (u32)ken_yuca_001,  /* 1 APPEAR JUNBI 2 */
    (u32)ken_yuca_000,  /* 2 APPEAR JUNBI 3 */
    (u32)ken_yuca_001,  /* 3 APPEAR JUNBI 4 */
    (u32)ken_yuca_000,  /* 4 APPEAR JUNBI 5 */
    (u32)ken_yuca_001,  /* 5 APPEAR JUNBI 6 */
    (u32)ken_yuca_000,  /* 6 APPEAR JUNBI 7 */
    (u32)ken_yuca_001,  /* 7 APPEAR JUNBI 8 */
    (u32)ken_yuca_008,  /* 8 APPEAR 1 */
    (u32)ken_yuca_009,  /* 9 APPEAR 2 */
    (u32)ken_yuca_008,  /* 10 APPEAR 3 */
    (u32)ken_yuca_009,  /* 11 APPEAR 4 */
    (u32)ken_yuca_008,  /* 12 APPEAR 5 */
    (u32)ken_yuca_009,  /* 13 APPEAR 6 */
    (u32)ken_yuca_008,  /* 14 APPEAR 7 */
    (u32)ken_yuca_009,  /* 15 APPEAR 8 */
    (u32)ken_yuca_016,  /* 16 SP APPEAR 1 */
    (u32)ken_yuca_016,  /* 17 SP APPEAR 2 */
    (u32)ken_yuca_016,  /* 18 SP APPEAR 3 */
    (u32)ken_yuca_016,  /* 19 SP APPEAR 4 */
    (u32)ken_yuca_016,  /* 20 SP APPEAR 5 */
    (u32)ken_yuca_016,  /* 21 SP APPEAR 6 */
    (u32)ken_yuca_016,  /* 22 SP APPEAR 7 */
    (u32)ken_yuca_016,  /* 23 SP APPEAR 8 */
    (u32)ken_yuca_024,  /* 24 ZANNEN 1 */
    (u32)ken_yuca_024,  /* 25 ZANNEN 2 */
    (u32)ken_yuca_024,  /* 26 ZANNEN 3 */
    (u32)ken_yuca_024,  /* 27 ZANNEN 4 */
    (u32)ken_yuca_024,  /* 28 ZANNEN 5 */
    (u32)ken_yuca_024,  /* 29 ZANNEN 6 */
    (u32)ken_yuca_024,  /* 30 ZANNEN 7 */
    (u32)ken_yuca_024,  /* 31 ZANNEN 8 */
    (u32)ken_yuca_032,  /* 32 WIN 1 */
    (u32)ken_yuca_032,  /* 33 WIN 2 */
    (u32)ken_yuca_032,  /* 34 WIN 3 */
    (u32)ken_yuca_032,  /* 35 WIN 4 */
    (u32)ken_yuca_036,  /* 36 WIN 5 */
    (u32)ken_yuca_036,  /* 37 WIN 6 */
    (u32)ken_yuca_036,  /* 38 WIN 7 */
    (u32)ken_yuca_036,  /* 39 WIN 8 */
    (u32)ken_yuca_040,  /* 40 SP WIN 1 */
    (u32)ken_yuca_040,  /* 41 SP WIN 2 */
    (u32)ken_yuca_040,  /* 42 SP WIN 3 */
    (u32)ken_yuca_040,  /* 43 SP WIN 4 */
    (u32)ken_yuca_040,  /* 44 SP WIN 5 */
    (u32)ken_yuca_040,  /* 45 SP WIN 6 */
    (u32)ken_yuca_040,  /* 46 SP WIN 7 */
    (u32)ken_yuca_040,  /* 47 SP WIN 8 */
    (u32)ken_yuca_048,  /* 48 JUDGMENT WAIT */
    (u32)ken_yuca_048,  /* 49 JUDGMENT WAIT */
    (u32)ken_yuca_048,  /* 50 JUDGMENT WAIT */
    (u32)ken_yuca_048,  /* 51 JUDGMENT WAIT */
    (u32)ken_yuca_032,  /* 52 JUDGMENT WIN */
    (u32)ken_yuca_032,  /* 53 JUDGMENT WIN */
    (u32)ken_yuca_032,  /* 54 JUDGMENT WIN */
    (u32)ken_yuca_032,  /* 55 JUDGMENT WIN */
    (u32)ken_yuca_024,  /* 56 JUDGMENT LOSE */
    (u32)ken_yuca_024,  /* 57 JUDGMENT LOSE */
    (u32)ken_yuca_024,  /* 58 JUDGMENT LOSE */
    (u32)ken_yuca_024,  /* 59 JUDGMENT LOSE */
    (u32)ken_yuca_060,  /* 60 WAIT */
    (u32)ken_yuca_061,  /* 61 AFRICA JUMP */
    (u32)ken_yuca_062,  /* 62 AFRICA LAND */
    (u32)ken_yuca_063,  /* 63 SEAN BALL HIT */
    (u32)ken_yuca_063,  /* 64 no name */
    (u32)ken_yuca_036,  /* 65 BONUS WIN 1 */
    (u32)ken_yuca_032,  /* 66 BONUS WIN 2 */
    (u32)ken_yuca_024,  /* 67 BONUS WIN 3 */
    0
};

/* script: 0 APPEAR JUNBI 1, 2 APPEAR JUNBI 3, 4 APPEAR JUNBI 5, 6 APPEAR JUNBI 7 */
const u16 ken_yuca_000_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 ken_yuca_000[28] = {
    CMD(CM_PA_X, 0, -1024, 0), 0, 0, 0, 0,
    L4(32, 9, 0, 0, 0, 0, 0, 0x44D0, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 1), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 1 APPEAR JUNBI 2, 3 APPEAR JUNBI 4, 5 APPEAR JUNBI 6, 7 APPEAR JUNBI 8 */
const u16 ken_yuca_001_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 ken_yuca_001[20] = {
    L4(30, 9, 0, 0, 0, 0, 0, 0x4577, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 1), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 8 APPEAR 1, 10 APPEAR 3, 12 APPEAR 5, 14 APPEAR 7 */
const u16 ken_yuca_008_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 ken_yuca_008[148] = {
    L4(32, 0, 0, 0, 0, 0, 0, 0x44D0, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 608, 0, 0, 0, 0, 0x44D1, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x44D2, 0, 1, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x44D3, 0, 1, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x44D9, 0, 1, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x44DA, 0, 1, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x44DB, 0, 1, 0, 0, 0, 0, 0),
    L4(24, 0, 0, 0, 0, 0, 0, 0x44DC, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x44D4, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x44D5, 0, 1, 0, 0, 0, 0, 0),
    L4(14, 0, 0, 0, 0, 0, 0, 0x44D6, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x44D7, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_PA_X, 0, 256, 0), 0, 0, 0, 0,
    L4(4, 0, 0, 0, 0, 0, 0, 0x44D8, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_PA_X, 0, 256, 0), 0, 0, 0, 0,
    L4(4, 0, 0, 0, 0, 0, 0, 0x4293, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_PA_X, 0, 256, 0), 0, 0, 0, 0,
    L4(250, 255, 0, 0, 0, 0, 0, 0x4293, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 9 APPEAR 2, 11 APPEAR 4, 13 APPEAR 6, 15 APPEAR 8 */
const u16 ken_yuca_009_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 ken_yuca_009[108] = {
    L4(40, 0, 0, 0, 0, 0, 0, 0x4577, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x4578, 0, 1, 0, 0, 0, 0, 0),
    L4(15, 0, 0, 0, 0, 0, 0, 0x4579, 0, 1, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x457A, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x457B, 0, 1, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x457C, 0, 1, 0, 0, 0, 0, 0),
    L4(8, 0, 0, 0, 0, 0, 0, 0x457D, 0, 1, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x457E, 0, 1, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x457F, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x4580, 0, 1, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x422E, 0, 1, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x422F, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x422F, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 16 SP APPEAR 1, 17 SP APPEAR 2, 18 SP APPEAR 3, 19 SP APPEAR 4 ... */
const u16 ken_yuca_016_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 ken_yuca_016[12] = {
    L4(4, 255, 0, 0, 0, 0, 0, 0x4201, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 24 ZANNEN 1, 25 ZANNEN 2, 26 ZANNEN 3, 27 ZANNEN 4 ... */
const u16 ken_yuca_024_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ken_yuca_024[20] = {
    L2(6, 0, 0, 0, 0, 0, 0, 0x4311),
    L2(6, 0, 0, 0, 0, 0, 0, 0x4312),
    L2(250, 255, 0, 0, 0, 0, 0, 0x4312),
    CMD(CM_END, 0, 0, 3),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 32 WIN 1, 33 WIN 2, 34 WIN 3, 35 WIN 4 ... */
const u16 ken_yuca_032_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ken_yuca_032[36] = {
    L2(4, 0, 0, 0, 0, 0, 0, 0x44F0),
    L2(2, 0, 0, 0, 0, 0, 0, 0x44F1),
    L2(3, 0, 0, 0, 0, 0, 0, 0x44F2),
    L2(3, 0, 0, 0, 0, 0, 0, 0x44F3),
    L2(4, 0, 0, 0, 0, 0, 0, 0x44F4),
    L2(12, 0, 0, 0, 0, 0, 0, 0x44F5),
    L2(250, 255, 0, 0, 0, 0, 0, 0x44F5),
    CMD(CM_END, 0, 0, 7),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 36 WIN 5, 37 WIN 6, 38 WIN 7, 39 WIN 8 ... */
const u16 ken_yuca_036_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ken_yuca_036[28] = {
    L2(8, 0, 0, 0, 0, 0, 0, 0x44F6),
    L2(6, 0, 268, 0, 0, 0, 0, 0x44F7),
    L2(4, 0, 0, 0, 0, 0, 0, 0x44F8),
    L2(5, 0, 612, 0, 0, 0, 0, 0x44F9),
    L2(250, 255, 0, 0, 0, 0, 0, 0x44F9),
    CMD(CM_END, 0, 0, 5),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 40 SP WIN 1, 41 SP WIN 2, 42 SP WIN 3, 43 SP WIN 4 ... */
const u16 ken_yuca_040_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 ken_yuca_040[8] = {
    L4(8, 0, 0, 0, 0, 0, 0, 0x4201, 0, 8, 0, 0, 0, 0, 0),
};

/* script: 48 JUDGMENT WAIT, 49 JUDGMENT WAIT, 50 JUDGMENT WAIT, 51 JUDGMENT WAIT */
const u16 ken_yuca_048_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ken_yuca_048[44] = {
    L2(3, 0, 0, 0, 0, 0, 0, 0x4201),
    L2(4, 0, 0, 0, 0, 0, 0, 0x4202),
    L2(3, 0, 0, 0, 0, 0, 0, 0x4203),
    L2(3, 0, 0, 0, 0, 0, 0, 0x4204),
    L2(3, 0, 0, 0, 0, 0, 0, 0x4205),
    L2(3, 0, 0, 0, 0, 0, 0, 0x4206),
    L2(3, 0, 0, 0, 0, 0, 0, 0x4207),
    L2(2, 0, 0, 0, 0, 0, 0, 0x4208),
    L2(2, 0, 0, 0, 0, 0, 0, 0x4209),
    L2(3, 255, 0, 0, 0, 0, 0, 0x420A),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 60 WAIT */
const u16 ken_yuca_060_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 ken_yuca_060[84] = {
    L4(3, 0, 0, 0, 0, 0, 0, 0x4201, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x4202, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x4203, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x4204, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x4205, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x4206, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x4207, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x4208, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x4209, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 255, 0, 0, 0, 0, 0, 0x420A, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 61 AFRICA JUMP */
const u16 ken_yuca_061_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ken_yuca_061[76] = {
    L2(5, 0, 0, 0, 0, 0, 0, 0x4229),
    L2(1, 0, 0, 0, 0, 0, 0, 0x4240),
    L2(1, 0, 0, 0, 0, 0, 0, 0x4241),
    L2(1, 0, 0, 0, 0, 0, 0, 0x426A),
    L2(1, 0, 0, 0, 0, 0, 0, 0x4240),
    L2(1, 0, 0, 0, 0, 0, 0, 0x4241),
    L2(1, 0, 0, 0, 0, 0, 0, 0x426A),
    L2(3, 0, 0, 0, 0, 0, 0, 0x4242),
    L2(3, 0, 0, 0, 0, 0, 0, 0x4243),
    L2(3, 0, 0, 0, 0, 0, 0, 0x4244),
    L2(3, 0, 0, 0, 0, 0, 0, 0x4245),
    L2(3, 0, 0, 0, 0, 0, 0, 0x4246),
    L2(3, 0, 0, 0, 0, 0, 0, 0x4247),
    L2(3, 0, 0, 0, 0, 0, 0, 0x4248),
    L2(3, 0, 0, 0, 0, 0, 0, 0x4249),
    L2(3, 0, 0, 0, 0, 0, 0, 0x424A),
    L2(3, 0, 0, 0, 0, 0, 0, 0x426B),
    CMD(CM_END, 0, 0, 15),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 62 AFRICA LAND */
const u16 ken_yuca_062_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ken_yuca_062[20] = {
    L2(3, 0, 0, 0, 0, 0, 0, 0x422A),
    L2(3, 0, 0, 0, 0, 0, 0, 0x424B),
    L2(3, 0, 0, 0, 0, 0, 0, 0x422F),
    L2(3, 255, 0, 0, 0, 0, 0, 0x422F),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 63 SEAN BALL HIT, 64 no name */
const u16 ken_yuca_063_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ken_yuca_063[40] = {
    L2(4, 0, 0, 0, 0, 0, 0, 0x42B3),
    L2(2, 0, 0, 0, 0, 0, 0, 0x42B4),
    L2(3, 0, 0, 0, 0, 0, 0, 0x42B5),
    L2(3, 0, 0, 0, 0, 0, 0, 0x42B5),
    L2(2, 0, 0, 0, 0, 0, 0, 0x42B6),
    L2(4, 0, 0, 0, 0, 0, 0, 0x42B7),
    L2(4, 0, 0, 0, 0, 0, 0, 0x4399),
    L2(4, 0, 0, 0, 0, 0, 0, 0x439A),
    L2(250, 255, 0, 0, 0, 0, 0, 0x439A),
    CMD(CM_ROA, 0, 0, 0),
};
