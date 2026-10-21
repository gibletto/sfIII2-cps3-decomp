/*
 * SEAN_YUCA.C  Sean's animation scripts
 *
 * The animation scripts Sean's moves run, one table per kind of script (yuca), each an index of
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

extern const u16 sean_yuca_000[], sean_yuca_008[], sean_yuca_016[], sean_yuca_017[], sean_yuca_024[], sean_yuca_032[], sean_yuca_034[], sean_yuca_036[], sean_yuca_040[], sean_yuca_048[], sean_yuca_052[], sean_yuca_060[], sean_yuca_061[], sean_yuca_062[], sean_yuca_063[];

/* yuca scripts (debug viewer: ETC): 68 entries */
const u32 sean_yuca[69] = {
    (u32)sean_yuca_000,  /* 0 APPEAR JUNBI 1 */
    (u32)sean_yuca_000,  /* 1 APPEAR JUNBI 2 */
    (u32)sean_yuca_000,  /* 2 APPEAR JUNBI 3 */
    (u32)sean_yuca_000,  /* 3 APPEAR JUNBI 4 */
    (u32)sean_yuca_000,  /* 4 APPEAR JUNBI 5 */
    (u32)sean_yuca_000,  /* 5 APPEAR JUNBI 6 */
    (u32)sean_yuca_000,  /* 6 APPEAR JUNBI 7 */
    (u32)sean_yuca_000,  /* 7 APPEAR JUNBI 8 */
    (u32)sean_yuca_008,  /* 8 APPEAR 1 */
    (u32)sean_yuca_008,  /* 9 APPEAR 2 */
    (u32)sean_yuca_008,  /* 10 APPEAR 3 */
    (u32)sean_yuca_008,  /* 11 APPEAR 4 */
    (u32)sean_yuca_008,  /* 12 APPEAR 5 */
    (u32)sean_yuca_008,  /* 13 APPEAR 6 */
    (u32)sean_yuca_008,  /* 14 APPEAR 7 */
    (u32)sean_yuca_008,  /* 15 APPEAR 8 */
    (u32)sean_yuca_016,  /* 16 SP APPEAR 1 */
    (u32)sean_yuca_017,  /* 17 SP APPEAR 2 */
    (u32)sean_yuca_017,  /* 18 SP APPEAR 3 */
    (u32)sean_yuca_017,  /* 19 SP APPEAR 4 */
    (u32)sean_yuca_017,  /* 20 SP APPEAR 5 */
    (u32)sean_yuca_017,  /* 21 SP APPEAR 6 */
    (u32)sean_yuca_017,  /* 22 SP APPEAR 7 */
    (u32)sean_yuca_017,  /* 23 SP APPEAR 8 */
    (u32)sean_yuca_024,  /* 24 ZANNEN 1 */
    (u32)sean_yuca_024,  /* 25 ZANNEN 2 */
    (u32)sean_yuca_024,  /* 26 ZANNEN 3 */
    (u32)sean_yuca_024,  /* 27 ZANNEN 4 */
    (u32)sean_yuca_024,  /* 28 ZANNEN 5 */
    (u32)sean_yuca_024,  /* 29 ZANNEN 6 */
    (u32)sean_yuca_024,  /* 30 ZANNEN 7 */
    (u32)sean_yuca_024,  /* 31 ZANNEN 8 */
    (u32)sean_yuca_032,  /* 32 WIN 1 */
    (u32)sean_yuca_032,  /* 33 WIN 2 */
    (u32)sean_yuca_034,  /* 34 WIN 3 */
    (u32)sean_yuca_034,  /* 35 WIN 4 */
    (u32)sean_yuca_036,  /* 36 WIN 5 */
    (u32)sean_yuca_036,  /* 37 WIN 6 */
    (u32)sean_yuca_036,  /* 38 WIN 7 */
    (u32)sean_yuca_036,  /* 39 WIN 8 */
    (u32)sean_yuca_040,  /* 40 SP WIN 1 */
    (u32)sean_yuca_040,  /* 41 SP WIN 2 */
    (u32)sean_yuca_040,  /* 42 SP WIN 3 */
    (u32)sean_yuca_040,  /* 43 SP WIN 4 */
    (u32)sean_yuca_040,  /* 44 SP WIN 5 */
    (u32)sean_yuca_040,  /* 45 SP WIN 6 */
    (u32)sean_yuca_040,  /* 46 SP WIN 7 */
    (u32)sean_yuca_040,  /* 47 SP WIN 8 */
    (u32)sean_yuca_048,  /* 48 JUDGMENT WAIT */
    (u32)sean_yuca_048,  /* 49 JUDGMENT WAIT */
    (u32)sean_yuca_048,  /* 50 JUDGMENT WAIT */
    (u32)sean_yuca_048,  /* 51 JUDGMENT WAIT */
    (u32)sean_yuca_052,  /* 52 JUDGMENT WIN */
    (u32)sean_yuca_052,  /* 53 JUDGMENT WIN */
    (u32)sean_yuca_052,  /* 54 JUDGMENT WIN */
    (u32)sean_yuca_052,  /* 55 JUDGMENT WIN */
    (u32)sean_yuca_024,  /* 56 JUDGMENT LOSE */
    (u32)sean_yuca_024,  /* 57 JUDGMENT LOSE */
    (u32)sean_yuca_024,  /* 58 JUDGMENT LOSE */
    (u32)sean_yuca_024,  /* 59 JUDGMENT LOSE */
    (u32)sean_yuca_060,  /* 60 WAIT */
    (u32)sean_yuca_061,  /* 61 AFRICA JUMP */
    (u32)sean_yuca_062,  /* 62 AFRICA LAND */
    (u32)sean_yuca_063,  /* 63 SEAN BALL HIT */
    (u32)sean_yuca_063,  /* 64 no name */
    (u32)sean_yuca_034,  /* 65 BONUS WIN 1 */
    (u32)sean_yuca_032,  /* 66 BONUS WIN 2 */
    (u32)sean_yuca_024,  /* 67 BONUS WIN 3 */
    0
};

/* script: 0 APPEAR JUNBI 1, 1 APPEAR JUNBI 2, 2 APPEAR JUNBI 3, 3 APPEAR JUNBI 4 ... */
const u16 sean_yuca_000_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 sean_yuca_000[44] = {
    L2(4, 0, 0, 0, 0, 0, 0, 0x4801),
    L2(4, 0, 0, 0, 0, 0, 0, 0x4802),
    L2(4, 0, 0, 0, 0, 0, 0, 0x4803),
    L2(4, 0, 0, 0, 0, 0, 0, 0x4804),
    L2(4, 0, 0, 0, 0, 0, 0, 0x4805),
    L2(4, 0, 0, 0, 0, 0, 0, 0x4806),
    L2(4, 0, 0, 0, 0, 0, 0, 0x4807),
    L2(4, 0, 0, 0, 0, 0, 0, 0x4808),
    L2(4, 0, 0, 0, 0, 0, 0, 0x4809),
    L2(4, 9, 0, 0, 0, 0, 0, 0x480A),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 8 APPEAR 1, 9 APPEAR 2, 10 APPEAR 3, 11 APPEAR 4 ... */
const u16 sean_yuca_008_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 sean_yuca_008[92] = {
    L4(4, 0, 0, 0, 0, 0, 0, 0x4801, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x4802, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x4803, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x4804, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x4805, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x4806, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x4807, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x4808, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x4809, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 9, 0, 0, 0, 0, 0, 0x480A, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x480A, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 16 SP APPEAR 1 */
const u16 sean_yuca_016_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 sean_yuca_016[12] = {
    L4(5, 9, 0, 0, 0, 0, 0, 0x4AD0, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 17 SP APPEAR 2, 18 SP APPEAR 3, 19 SP APPEAR 4, 20 SP APPEAR 5 ... */
const u16 sean_yuca_017_head[4] = { HEAD(6, 0, 0, 0, 0, 0, 0) };
const u16 sean_yuca_017[232] = {
    L6(5, 0, 0, 0, 0, 0, 0, 0x4AD0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(6, 0, 0, 0, 0, 0, 0, 0x4AD1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(8, 0, 0, 0, 0, 0, 0, 0x4AD2, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x4AD3, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 282, 0, 0, 0, 0, 0x4AD4, 0, 1, 0, 0, 0, 0, 0, 0, 0, 148, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x4AD5, 0, 1, 0, 0, 0, 0, 0, 0, 0, 150, 0, 0),
    L6(6, 0, 0, 0, 0, 0, 0, 0x4AD6, 0, 1, 0, 0, 0, 0, 0, 0, 0, 152, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x4AD7, 0, 1, 0, 0, 0, 0, 0, 0, 0, 154, 0, 0),
    L6(3, 0, 332, 0, 0, 0, 0, 0x4AD7, 0, 1, 0, 0, 0, 0, 0, 0, 0, 156, 0, 0),
    CMD(CM_EXEC, 12, 1, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(1, 0, 517, 0, 0, 0, 0, 0x4AD8, 0, 1, 0, 0, 0, 0, 0, 0, 0, 158, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x4AD8, 0, 1, 0, 0, 0, 0, 0, 0, 0, 160, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x4AD9, 0, 1, 0, 0, 0, 0, 0, 0, 0, 162, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x4ADA, 0, 1, 0, 0, 0, 0, 0, 0, 0, 164, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x4856, 0, 1, 0, 0, 0, 0, 0, 0, 0, 166, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x4857, 0, 1, 0, 0, 0, 0, 0, 0, 0, 168, 0, 0),
    L6(4, 0, 274, 0, 0, 0, 0, 0x484B, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x482F, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x482F, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 24 ZANNEN 1, 25 ZANNEN 2, 26 ZANNEN 3, 27 ZANNEN 4 ... */
const u16 sean_yuca_024_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 sean_yuca_024[36] = {
    L2(4, 0, 0, 0, 0, 0, 0, 0x48B7),
    CMD(CM_PA_X, 0, -512, 0),
    L2(4, 0, 0, 0, 0, 0, 0, 0x48B6),
    CMD(CM_PA_X, 0, -512, 0),
    L2(4, 0, 0, 0, 0, 0, 0, 0x48B5),
    L2(4, 0, 0, 0, 0, 0, 0, 0x48B4),
    L2(250, 255, 0, 0, 0, 0, 0, 0x48B4),
    CMD(CM_END, 0, 0, 7),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 32 WIN 1, 33 WIN 2, 66 BONUS WIN 2 */
const u16 sean_yuca_032_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 sean_yuca_032[36] = {
    L2(4, 0, 0, 0, 0, 0, 0, 0x4AF0),
    L2(2, 0, 0, 0, 0, 0, 0, 0x4AF1),
    L2(3, 0, 519, 0, 0, 0, 0, 0x4AF2),
    L2(3, 0, 0, 0, 0, 0, 0, 0x4AF3),
    L2(4, 0, 0, 0, 0, 0, 0, 0x4AF4),
    L2(12, 0, 0, 0, 0, 0, 0, 0x4AF5),
    L2(250, 255, 0, 0, 0, 0, 0, 0x4AF5),
    CMD(CM_END, 0, 0, 7),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 34 WIN 3, 35 WIN 4, 65 BONUS WIN 1 */
const u16 sean_yuca_034_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 sean_yuca_034[72] = {
    L2(4, 0, 0, 0, 0, 0, 0, 0x4B20),
    L2(4, 0, 0, 0, 0, 0, 0, 0x4B21),
    L2(4, 0, 0, 0, 0, 0, 0, 0x4B22),
    L2(4, 0, 0, 0, 0, 0, 0, 0x4B23),
    L2(4, 0, 0, 0, 0, 0, 0, 0x4B24),
    L2(4, 0, 0, 0, 0, 0, 0, 0x4B25),
    L2(4, 0, 0, 0, 0, 0, 0, 0x4B26),
    L2(4, 0, 0, 0, 0, 0, 0, 0x4B27),
    L2(4, 0, 0, 0, 0, 0, 0, 0x4B28),
    L2(4, 0, 0, 0, 0, 0, 0, 0x4B29),
    L2(4, 0, 0, 0, 0, 0, 0, 0x4B2A),
    L2(4, 0, 520, 0, 0, 0, 0, 0x4B2B),
    L2(4, 0, 0, 0, 0, 0, 0, 0x4B2E),
    L2(4, 0, 0, 0, 0, 0, 0, 0x4B2F),
    L2(4, 0, 0, 0, 0, 0, 0, 0x4B30),
    L2(4, 0, 0, 0, 0, 0, 0, 0x4B31),
    CMD(CM_END, 0, 0, 16),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 36 WIN 5, 37 WIN 6, 38 WIN 7, 39 WIN 8 */
const u16 sean_yuca_036_head[4] = { HEAD(6, 0, 0, 0, 0, 0, 0) };
const u16 sean_yuca_036[328] = {
    L6(1, 0, 0, 0, 0, 0, 0, 0x4828, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x4829, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 9, 0, 0, 0, 0, 0, 0x4B00, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x4B01, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x4B02, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 445, 0, 0, 0, 0, 0x4B03, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x4B04, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(6, 0, 0, 0, 0, 0, 0, 0x4B05, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(8, 0, 0, 0, 0, 0, 0, 0x4B06, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x4B06, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x4B06, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x4870, 0, 1, 0, 0, 0, 0, 0, 0, 0, 274, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x4871, 0, 1, 0, 0, 0, 21, 0, 0, 0, 0, 0, 0),
    L6(250, 0, 0, 0, 0, 0, 0, 0x4872, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x4873, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x4874, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x484B, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x482F, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x482E, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x4AF0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x4AF1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 519, 0, 0, 0, 0, 0x4AF2, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x4AF3, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x4AF4, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(12, 0, 0, 0, 0, 0, 0, 0x4AF5, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x4AF5, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_END, 0, 0, 26), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 40 SP WIN 1, 41 SP WIN 2, 42 SP WIN 3, 43 SP WIN 4 ... */
const u16 sean_yuca_040_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 sean_yuca_040[8] = {
    L2(250, 255, 0, 0, 0, 0, 0, 0x4801),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 48 JUDGMENT WAIT, 49 JUDGMENT WAIT, 50 JUDGMENT WAIT, 51 JUDGMENT WAIT */
const u16 sean_yuca_048_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 sean_yuca_048[44] = {
    L2(4, 0, 0, 0, 0, 0, 0, 0x4801),
    L2(4, 0, 0, 0, 0, 0, 0, 0x4802),
    L2(4, 0, 0, 0, 0, 0, 0, 0x4803),
    L2(4, 0, 0, 0, 0, 0, 0, 0x4804),
    L2(4, 0, 0, 0, 0, 0, 0, 0x4805),
    L2(4, 0, 0, 0, 0, 0, 0, 0x4806),
    L2(4, 0, 0, 0, 0, 0, 0, 0x4807),
    L2(4, 0, 0, 0, 0, 0, 0, 0x4808),
    L2(4, 0, 0, 0, 0, 0, 0, 0x4809),
    L2(4, 255, 0, 0, 0, 0, 0, 0x480A),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 52 JUDGMENT WIN, 53 JUDGMENT WIN, 54 JUDGMENT WIN, 55 JUDGMENT WIN */
const u16 sean_yuca_052_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 sean_yuca_052[64] = {
    L2(4, 0, 0, 0, 0, 0, 0, 0x4B20),
    L2(4, 0, 0, 0, 0, 0, 0, 0x4B21),
    L2(4, 0, 0, 0, 0, 0, 0, 0x4B22),
    L2(4, 0, 0, 0, 0, 0, 0, 0x4B23),
    L2(4, 0, 0, 0, 0, 0, 0, 0x4B24),
    L2(4, 0, 0, 0, 0, 0, 0, 0x4B25),
    L2(4, 0, 0, 0, 0, 0, 0, 0x4B26),
    L2(4, 0, 0, 0, 0, 0, 0, 0x4B27),
    L2(4, 0, 0, 0, 0, 0, 0, 0x4B28),
    L2(4, 0, 0, 0, 0, 0, 0, 0x4B29),
    L2(4, 0, 0, 0, 0, 0, 0, 0x4B2A),
    L2(4, 0, 0, 0, 0, 0, 0, 0x4B2B),
    L2(4, 0, 0, 0, 0, 0, 0, 0x4B2C),
    L2(4, 0, 0, 0, 0, 0, 0, 0x4B2D),
    CMD(CM_END, 0, 0, 14),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 60 WAIT */
const u16 sean_yuca_060_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 sean_yuca_060[84] = {
    L4(2, 0, 0, 0, 0, 0, 0, 0x4801, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x4802, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x4803, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x4804, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x4805, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x4806, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x4807, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x4808, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x4809, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 255, 0, 0, 0, 0, 0, 0x480A, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 61 AFRICA JUMP */
const u16 sean_yuca_061_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 sean_yuca_061[76] = {
    L2(5, 0, 0, 0, 0, 0, 0, 0x4829),
    L2(1, 0, 0, 0, 0, 0, 0, 0x4840),
    L2(1, 0, 0, 0, 0, 0, 0, 0x4841),
    L2(1, 0, 0, 0, 0, 0, 0, 0x486A),
    L2(1, 0, 0, 0, 0, 0, 0, 0x4840),
    L2(1, 0, 0, 0, 0, 0, 0, 0x4841),
    L2(1, 0, 0, 0, 0, 0, 0, 0x486A),
    L2(3, 0, 0, 0, 0, 0, 0, 0x4842),
    L2(3, 0, 0, 0, 0, 0, 0, 0x4843),
    L2(3, 0, 0, 0, 0, 0, 0, 0x4844),
    L2(3, 0, 0, 0, 0, 0, 0, 0x4845),
    L2(3, 0, 0, 0, 0, 0, 0, 0x4846),
    L2(3, 0, 0, 0, 0, 0, 0, 0x4847),
    L2(3, 0, 0, 0, 0, 0, 0, 0x4848),
    L2(3, 0, 0, 0, 0, 0, 0, 0x4849),
    L2(3, 0, 0, 0, 0, 0, 0, 0x484A),
    L2(3, 0, 0, 0, 0, 0, 0, 0x486B),
    CMD(CM_END, 0, 0, 15),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 62 AFRICA LAND */
const u16 sean_yuca_062_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 sean_yuca_062[20] = {
    L2(3, 0, 0, 0, 0, 0, 0, 0x482A),
    L2(3, 0, 0, 0, 0, 0, 0, 0x484B),
    L2(3, 0, 0, 0, 0, 0, 0, 0x482F),
    L2(3, 255, 0, 0, 0, 0, 0, 0x482F),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 63 SEAN BALL HIT, 64 no name */
const u16 sean_yuca_063_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 sean_yuca_063[36] = {
    L2(4, 0, 0, 0, 0, 0, 0, 0x48B3),
    L2(2, 0, 0, 0, 0, 0, 0, 0x48B4),
    L2(3, 0, 0, 0, 0, 0, 0, 0x48B5),
    L2(4, 0, 0, 0, 0, 0, 0, 0x48B6),
    L2(4, 0, 0, 0, 0, 0, 0, 0x48B7),
    L2(4, 0, 0, 0, 0, 0, 0, 0x4999),
    L2(4, 0, 0, 0, 0, 0, 0, 0x499A),
    L2(250, 255, 0, 0, 0, 0, 0, 0x499A),
    CMD(CM_ROA, 0, 0, 0),
};
