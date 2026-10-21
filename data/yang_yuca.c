/*
 * YANG_YUCA.C  Yang's animation scripts
 *
 * The animation scripts Yang's moves run, one table per kind of script (yuca), each an index of
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

extern const u16 yang_yuca_000[], yang_yuca_008[], yang_yuca_016[], yang_yuca_018[], yang_yuca_019[], yang_yuca_020[], yang_yuca_021[], yang_yuca_024[], yang_yuca_032[], yang_yuca_036[], yang_yuca_038[], yang_yuca_040[], yang_yuca_048[], yang_yuca_052[], yang_yuca_060[], yang_yuca_061[], yang_yuca_062[], yang_yuca_063[];

/* yuca scripts (debug viewer: ETC): 68 entries */
const u32 yang_yuca[69] = {
    (u32)yang_yuca_000,  /* 0 APPEAR JUNBI 1 */
    (u32)yang_yuca_000,  /* 1 APPEAR JUNBI 2 */
    (u32)yang_yuca_000,  /* 2 APPEAR JUNBI 3 */
    (u32)yang_yuca_000,  /* 3 APPEAR JUNBI 4 */
    (u32)yang_yuca_000,  /* 4 APPEAR JUNBI 5 */
    (u32)yang_yuca_000,  /* 5 APPEAR JUNBI 6 */
    (u32)yang_yuca_000,  /* 6 APPEAR JUNBI 7 */
    (u32)yang_yuca_000,  /* 7 APPEAR JUNBI 8 */
    (u32)yang_yuca_008,  /* 8 APPEAR 1 */
    (u32)yang_yuca_008,  /* 9 APPEAR 2 */
    (u32)yang_yuca_008,  /* 10 APPEAR 3 */
    (u32)yang_yuca_008,  /* 11 APPEAR 4 */
    (u32)yang_yuca_008,  /* 12 APPEAR 5 */
    (u32)yang_yuca_008,  /* 13 APPEAR 6 */
    (u32)yang_yuca_008,  /* 14 APPEAR 7 */
    (u32)yang_yuca_008,  /* 15 APPEAR 8 */
    (u32)yang_yuca_016,  /* 16 SP APPEAR 1 */
    (u32)yang_yuca_016,  /* 17 SP APPEAR 2 */
    (u32)yang_yuca_018,  /* 18 SP APPEAR 3 */
    (u32)yang_yuca_019,  /* 19 SP APPEAR 4 */
    (u32)yang_yuca_020,  /* 20 SP APPEAR 5 */
    (u32)yang_yuca_021,  /* 21 SP APPEAR 6 */
    (u32)yang_yuca_021,  /* 22 SP APPEAR 7 */
    (u32)yang_yuca_021,  /* 23 SP APPEAR 8 */
    (u32)yang_yuca_024,  /* 24 ZANNEN 1 */
    (u32)yang_yuca_024,  /* 25 ZANNEN 2 */
    (u32)yang_yuca_024,  /* 26 ZANNEN 3 */
    (u32)yang_yuca_024,  /* 27 ZANNEN 4 */
    (u32)yang_yuca_024,  /* 28 ZANNEN 5 */
    (u32)yang_yuca_024,  /* 29 ZANNEN 6 */
    (u32)yang_yuca_024,  /* 30 ZANNEN 7 */
    (u32)yang_yuca_024,  /* 31 ZANNEN 8 */
    (u32)yang_yuca_032,  /* 32 WIN 1 */
    (u32)yang_yuca_032,  /* 33 WIN 2 */
    (u32)yang_yuca_032,  /* 34 WIN 3 */
    (u32)yang_yuca_032,  /* 35 WIN 4 */
    (u32)yang_yuca_036,  /* 36 WIN 5 */
    (u32)yang_yuca_036,  /* 37 WIN 6 */
    (u32)yang_yuca_038,  /* 38 WIN 7 */
    (u32)yang_yuca_038,  /* 39 WIN 8 */
    (u32)yang_yuca_040,  /* 40 SP WIN 1 */
    (u32)yang_yuca_040,  /* 41 SP WIN 2 */
    (u32)yang_yuca_040,  /* 42 SP WIN 3 */
    (u32)yang_yuca_040,  /* 43 SP WIN 4 */
    (u32)yang_yuca_040,  /* 44 SP WIN 5 */
    (u32)yang_yuca_040,  /* 45 SP WIN 6 */
    (u32)yang_yuca_040,  /* 46 SP WIN 7 */
    (u32)yang_yuca_040,  /* 47 SP WIN 8 */
    (u32)yang_yuca_048,  /* 48 JUDGMENT WAIT */
    (u32)yang_yuca_048,  /* 49 JUDGMENT WAIT */
    (u32)yang_yuca_048,  /* 50 JUDGMENT WAIT */
    (u32)yang_yuca_048,  /* 51 JUDGMENT WAIT */
    (u32)yang_yuca_052,  /* 52 JUDGMENT WIN */
    (u32)yang_yuca_052,  /* 53 JUDGMENT WIN */
    (u32)yang_yuca_052,  /* 54 JUDGMENT WIN */
    (u32)yang_yuca_052,  /* 55 JUDGMENT WIN */
    (u32)yang_yuca_024,  /* 56 JUDGMENT LOSE */
    (u32)yang_yuca_024,  /* 57 JUDGMENT LOSE */
    (u32)yang_yuca_024,  /* 58 JUDGMENT LOSE */
    (u32)yang_yuca_024,  /* 59 JUDGMENT LOSE */
    (u32)yang_yuca_060,  /* 60 WAIT */
    (u32)yang_yuca_061,  /* 61 AFRICA JUMP */
    (u32)yang_yuca_062,  /* 62 AFRICA LAND */
    (u32)yang_yuca_063,  /* 63 SEAN BALL HIT */
    (u32)yang_yuca_063,  /* 64 no name */
    (u32)yang_yuca_036,  /* 65 BONUS WIN 1 */
    (u32)yang_yuca_032,  /* 66 BONUS WIN 2 */
    (u32)yang_yuca_052,  /* 67 BONUS WIN 3 */
    0
};

/* script: 0 APPEAR JUNBI 1, 1 APPEAR JUNBI 2, 2 APPEAR JUNBI 3, 3 APPEAR JUNBI 4 ... */
const u16 yang_yuca_000_head[4] = { HEAD(2, 6, 0, 0, 0, 0, 0) };
const u16 yang_yuca_000[8] = {
    L2(8, 9, 0, 0, 0, 0, 0, 0x3F80),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 8 APPEAR 1, 9 APPEAR 2, 10 APPEAR 3, 11 APPEAR 4 ... */
const u16 yang_yuca_008_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 yang_yuca_008[324] = {
    L4(8, 0, 0, 0, 0, 0, 0, 0x3F80, 0, 1, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x3F81, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x3F82, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x3F83, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3F84, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3F85, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3F86, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3F87, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3F88, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3F87, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3F86, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3F85, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3F84, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3F85, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3F86, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3F87, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3F88, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_PA_X, 0, -256, 0), 0, 0, 0, 0,
    L4(4, 0, 0, 0, 0, 0, 0, 0x3F89, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_PA_X, 0, -256, 0), 0, 0, 0, 0,
    L4(4, 0, 0, 0, 0, 0, 0, 0x3F8A, 0, 1, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x3F8B, 0, 1, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x3F66, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_PA_X, 0, 256, 0), 0, 0, 0, 0,
    L4(4, 0, 0, 0, 0, 0, 0, 0x3F67, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_PA_X, 0, 256, 0), 0, 0, 0, 0,
    L4(10, 0, 0, 0, 0, 0, 0, 0x3F68, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_PA_X, 0, -256, 0), 0, 0, 0, 0,
    L4(4, 0, 0, 0, 0, 0, 0, 0x3F67, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_PA_X, 0, -256, 0), 0, 0, 0, 0,
    L4(5, 0, 0, 0, 0, 0, 0, 0x3F66, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x3F64, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_PA_X, 0, -256, 0), 0, 0, 0, 0,
    L4(4, 0, 0, 0, 0, 0, 0, 0x3F63, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_PA_X, 0, -256, 0), 0, 0, 0, 0,
    L4(4, 0, 0, 0, 0, 0, 0, 0x3F62, 0, 1, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x3C41, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x3C40, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x3C3F, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x3C3F, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 16 SP APPEAR 1, 17 SP APPEAR 2 */
const u16 yang_yuca_016_head[4] = { HEAD(4, 6, 0, 0, 0, 0, 0) };
const u16 yang_yuca_016[20] = {
    L4(2, 0, 0, 0, 0, 0, 0, 0x3C7B, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3C7C, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 18 SP APPEAR 3 */
const u16 yang_yuca_018_head[4] = { HEAD(4, 6, 0, 0, 0, 0, 0) };
const u16 yang_yuca_018[44] = {
    L4(1, 0, 0, 0, 0, 0, 0, 0x3C7D, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3C7E, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x3C7F, 0, 1, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x3C41, 0, 1, 0, 0, 0, 0, 0),
    L4(8, 1, 0, 0, 0, 0, 0, 0x3C41, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 19 SP APPEAR 4 */
const u16 yang_yuca_019_head[4] = { HEAD(4, 6, 0, 0, 0, 0, 0) };
const u16 yang_yuca_019[164] = {
    L4(6, 0, 0, 0, 0, 0, 0, 0x3F62, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x3F63, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x3F64, 0, 1, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x3F65, 0, 1, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x3F66, 0, 1, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x3F67, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_PA_X, 0, 512, 0), 0, 0, 0, 0,
    L4(12, 0, 0, 0, 0, 0, 0, 0x3F68, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x3F67, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x3F66, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_PA_X, 0, -256, 0), 0, 0, 0, 0,
    L4(4, 0, 0, 0, 0, 0, 0, 0x3F64, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_PA_X, 0, -256, 0), 0, 0, 0, 0,
    L4(4, 0, 0, 0, 0, 0, 0, 0x3F63, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_PA_X, 0, -256, 0), 0, 0, 0, 0,
    L4(4, 0, 0, 0, 0, 0, 0, 0x3F62, 0, 1, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x3C41, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x3C40, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x3C3F, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x3C3F, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 20 SP APPEAR 5 */
const u16 yang_yuca_020_head[4] = { HEAD(2, 6, 0, 0, 0, 0, 0) };
const u16 yang_yuca_020[8] = {
    L2(250, 255, 0, 0, 0, 0, 0, 0x3F8C),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 21 SP APPEAR 6, 22 SP APPEAR 7, 23 SP APPEAR 8 */
const u16 yang_yuca_021_head[4] = { HEAD(2, 6, 0, 0, 0, 0, 0) };
const u16 yang_yuca_021[184] = {
    CMD(CM_FOR, 0, 0, 2),
    CMD(CM_PA_X, 0, -2304, 0),
    L2(2, 0, 0, 0, 0, 0, 0, 0x3CB9),
    CMD(CM_PA_X, 0, -2304, 0),
    L2(2, 0, 0, 0, 0, 0, 0, 0x3CBA),
    CMD(CM_PA_X, 0, -2304, 0),
    L2(2, 0, 0, 0, 0, 0, 0, 0x3CBB),
    CMD(CM_PA_X, 0, -2304, 0),
    L2(2, 0, 0, 0, 0, 0, 0, 0x3CBC),
    CMD(CM_PA_X, 0, -2304, 0),
    L2(2, 0, 0, 0, 0, 0, 0, 0x3CBD),
    CMD(CM_PA_X, 0, -2304, 0),
    L2(2, 0, 0, 0, 0, 0, 0, 0x3CBE),
    CMD(CM_PA_X, 0, -2304, 0),
    L2(2, 0, 0, 0, 0, 0, 0, 0x3CBF),
    CMD(CM_PA_X, 0, -2304, 0),
    L2(2, 0, 0, 0, 0, 0, 0, 0x3CC0),
    CMD(CM_PA_X, 0, -2304, 0),
    L2(2, 0, 0, 0, 0, 0, 0, 0x3CC1),
    CMD(CM_PA_X, 0, -2304, 0),
    L2(2, 0, 0, 0, 0, 0, 0, 0x3CC2),
    CMD(CM_PA_X, 0, -2304, 0),
    L2(2, 0, 0, 0, 0, 0, 0, 0x3CC3),
    CMD(CM_PA_X, 0, -2304, 0),
    L2(2, 0, 0, 0, 0, 0, 0, 0x3CC4),
    CMD(CM_PA_X, 0, -2304, 0),
    L2(2, 0, 0, 0, 0, 0, 0, 0x3CC5),
    CMD(CM_PA_X, 0, -2304, 0),
    L2(2, 0, 0, 0, 0, 0, 0, 0x3CC6),
    CMD(CM_PA_X, 0, -2304, 0),
    L2(2, 0, 0, 0, 0, 0, 0, 0x3CC7),
    CMD(CM_PA_X, 0, -2304, 0),
    L2(2, 0, 0, 0, 0, 0, 0, 0x3CC8),
    CMD(CM_PA_X, 0, -2304, 0),
    L2(2, 0, 0, 0, 0, 0, 0, 0x3CC9),
    CMD(CM_PA_X, 0, -2304, 0),
    L2(2, 0, 0, 0, 0, 0, 0, 0x3CCA),
    CMD(CM_PA_X, 0, -2304, 0),
    L2(2, 0, 0, 0, 0, 0, 0, 0x3CCB),
    CMD(CM_NEX, 0, 0, 0),
    L2(4, 0, 0, 0, 0, 0, 0, 0x3CCC),
    L2(6, 0, 0, 0, 0, 0, 0, 0x3C41),
    L2(6, 0, 0, 0, 0, 0, 0, 0x3C40),
    L2(6, 0, 0, 0, 0, 0, 0, 0x3C3F),
    L2(250, 255, 0, 0, 0, 0, 0, 0x3C3F),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 24 ZANNEN 1, 25 ZANNEN 2, 26 ZANNEN 3, 27 ZANNEN 4 ... */
const u16 yang_yuca_024_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 yang_yuca_024[20] = {
    L2(4, 0, 0, 0, 0, 0, 0, 0x3F56),
    L2(4, 0, 0, 0, 0, 0, 0, 0x3F57),
    L2(4, 255, 0, 0, 0, 0, 0, 0x3F58),
    CMD(CM_END, 0, 0, 2),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 32 WIN 1, 33 WIN 2, 34 WIN 3, 35 WIN 4 ... */
const u16 yang_yuca_032_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 yang_yuca_032[84] = {
    L2(4, 0, 0, 0, 0, 0, 0, 0x3C01),
    L2(4, 0, 0, 0, 0, 0, 0, 0x3F62),
    L2(4, 0, 0, 0, 0, 0, 0, 0x3F63),
    L2(4, 0, 0, 0, 0, 0, 0, 0x3F64),
    L2(4, 0, 0, 0, 0, 0, 0, 0x3F69),
    L2(4, 0, 0, 0, 0, 0, 0, 0x3F6A),
    CMD(CM_PA_X, 0, 512, 0),
    L2(4, 0, 0, 0, 0, 0, 0, 0x3F6B),
    L2(4, 0, 0, 0, 0, 0, 0, 0x3F6C),
    CMD(CM_PA_X, 0, -512, 0),
    L2(4, 0, 0, 0, 0, 0, 0, 0x3F6B),
    L2(4, 0, 0, 0, 0, 0, 0, 0x3F6A),
    L2(4, 0, 0, 0, 0, 0, 0, 0x3F6D),
    L2(4, 0, 0, 0, 0, 0, 0, 0x3F6E),
    L2(4, 0, 0, 0, 0, 0, 0, 0x3F6F),
    L2(4, 0, 0, 0, 0, 0, 0, 0x3F70),
    L2(4, 0, 0, 0, 0, 0, 0, 0x3F6F),
    L2(4, 0, 0, 0, 0, 0, 0, 0x3F6E),
    L2(250, 255, 0, 0, 0, 0, 0, 0x3F6E),
    CMD(CM_END, 0, 0, 18),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 36 WIN 5, 37 WIN 6, 65 BONUS WIN 1 */
const u16 yang_yuca_036_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 yang_yuca_036[64] = {
    L2(4, 0, 0, 0, 0, 0, 0, 0x3C01),
    L2(4, 0, 0, 0, 0, 0, 0, 0x3F71),
    L2(4, 0, 0, 0, 0, 0, 0, 0x3F72),
    L2(4, 0, 0, 0, 0, 0, 0, 0x3F73),
    L2(4, 0, 0, 0, 0, 0, 0, 0x3F74),
    L2(4, 0, 0, 0, 0, 0, 0, 0x3F75),
    L2(4, 0, 0, 0, 0, 0, 0, 0x3F76),
    L2(4, 0, 0, 0, 0, 0, 0, 0x3F77),
    L2(4, 0, 0, 0, 0, 0, 0, 0x3F78),
    L2(4, 0, 0, 0, 0, 0, 0, 0x3F79),
    L2(4, 0, 421, 0, 0, 0, 0, 0x3F7A),
    L2(4, 0, 0, 0, 0, 0, 0, 0x3F7B),
    L2(4, 0, 0, 0, 0, 0, 0, 0x3F7C),
    L2(250, 255, 0, 0, 0, 0, 0, 0x3F7C),
    CMD(CM_END, 0, 0, 13),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 38 WIN 7, 39 WIN 8 */
const u16 yang_yuca_038_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 yang_yuca_038[64] = {
    L2(4, 0, 0, 0, 0, 0, 0, 0x3C01),
    L2(4, 0, 0, 0, 0, 0, 0, 0x3F71),
    L2(4, 0, 0, 0, 0, 0, 0, 0x3F72),
    L2(4, 0, 0, 0, 0, 0, 0, 0x3F73),
    L2(4, 0, 0, 0, 0, 0, 0, 0x3F74),
    L2(4, 0, 0, 0, 0, 0, 0, 0x3F75),
    L2(4, 0, 0, 0, 0, 0, 0, 0x3F76),
    L2(4, 0, 0, 0, 0, 0, 0, 0x3F77),
    L2(4, 0, 423, 0, 0, 0, 0, 0x3F78),
    L2(4, 0, 0, 0, 0, 0, 0, 0x3F79),
    L2(4, 0, 0, 0, 0, 0, 0, 0x3F7A),
    L2(4, 0, 0, 0, 0, 0, 0, 0x3F7B),
    L2(4, 0, 0, 0, 0, 0, 0, 0x3F7C),
    L2(250, 255, 0, 0, 0, 0, 0, 0x3F7C),
    CMD(CM_END, 0, 0, 13),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 40 SP WIN 1, 41 SP WIN 2, 42 SP WIN 3, 43 SP WIN 4 ... */
const u16 yang_yuca_040_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 yang_yuca_040[8] = {
    L2(250, 255, 0, 0, 0, 0, 0, 0x3C01),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 48 JUDGMENT WAIT, 49 JUDGMENT WAIT, 50 JUDGMENT WAIT, 51 JUDGMENT WAIT */
const u16 yang_yuca_048_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 yang_yuca_048[52] = {
    L2(8, 0, 0, 0, 0, 0, 0, 0x3C01),
    L2(8, 0, 0, 0, 0, 0, 0, 0x3C02),
    L2(8, 0, 0, 0, 0, 0, 0, 0x3C03),
    L2(8, 0, 0, 0, 0, 0, 0, 0x3C04),
    L2(8, 0, 0, 0, 0, 0, 0, 0x3C05),
    L2(8, 0, 0, 0, 0, 0, 0, 0x3C06),
    L2(8, 0, 0, 0, 0, 0, 0, 0x3C07),
    L2(8, 0, 0, 0, 0, 0, 0, 0x3C08),
    L2(8, 0, 0, 0, 0, 0, 0, 0x3C09),
    L2(8, 0, 0, 0, 0, 0, 0, 0x3C0A),
    L2(8, 0, 0, 0, 0, 0, 0, 0x3C0B),
    L2(8, 255, 0, 0, 0, 0, 0, 0x3C0C),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 52 JUDGMENT WIN, 53 JUDGMENT WIN, 54 JUDGMENT WIN, 55 JUDGMENT WIN ... */
const u16 yang_yuca_052_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 yang_yuca_052[32] = {
    L2(4, 0, 0, 0, 0, 0, 0, 0x3F59),
    L2(4, 0, 0, 0, 0, 0, 0, 0x3F5A),
    L2(4, 0, 0, 0, 0, 0, 0, 0x3F5B),
    L2(4, 0, 0, 0, 0, 0, 0, 0x3F5C),
    L2(4, 0, 0, 0, 0, 0, 0, 0x3F5D),
    L2(250, 0, 0, 0, 0, 0, 0, 0x3F5E),
    CMD(CM_END, 0, 0, 6),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 60 WAIT */
const u16 yang_yuca_060_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 yang_yuca_060[116] = {
    L4(5, 0, 0, 0, 0, 0, 0, 0x3FCA, 0, 1, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x3FCB, 0, 1, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x3FCC, 0, 1, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x3FCD, 0, 1, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x3FCE, 0, 1, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x3FCF, 0, 1, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x3FD0, 0, 1, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x3FD1, 0, 1, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x3FD2, 0, 1, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x3FD3, 0, 1, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x3FD4, 0, 1, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x3FD5, 0, 1, 0, 0, 0, 0, 0),
    L4(5, 255, 0, 0, 0, 0, 0, 0x3FD6, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_END, 0, 0, 1), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 61 AFRICA JUMP */
const u16 yang_yuca_061_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 yang_yuca_061[60] = {
    L2(5, 0, 0, 0, 0, 0, 0, 0x3C60),
    L2(4, 0, 0, 0, 0, 0, 0, 0x3C61),
    L2(3, 0, 0, 0, 0, 0, 0, 0x3C62),
    L2(3, 0, 0, 0, 0, 0, 0, 0x3C63),
    L2(3, 0, 0, 0, 0, 0, 0, 0x3C64),
    L2(2, 0, 0, 0, 0, 0, 0, 0x3C65),
    L2(2, 0, 0, 0, 0, 0, 0, 0x3C66),
    L2(2, 0, 0, 0, 0, 0, 0, 0x3C67),
    L2(3, 0, 0, 0, 0, 0, 0, 0x3C68),
    L2(3, 0, 0, 0, 0, 0, 0, 0x3C69),
    L2(3, 0, 0, 0, 0, 0, 0, 0x3C6A),
    L2(4, 0, 0, 0, 0, 0, 0, 0x3C6B),
    L2(4, 0, 0, 0, 0, 0, 0, 0x3C6C),
    CMD(CM_END, 0, 0, 12),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 62 AFRICA LAND */
const u16 yang_yuca_062_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 yang_yuca_062[32] = {
    L2(3, 0, 0, 0, 0, 0, 0, 0x3C6D),
    L2(2, 0, 0, 0, 0, 0, 0, 0x3C6E),
    L2(1, 0, 0, 0, 0, 0, 0, 0x3C6F),
    L2(4, 0, 0, 0, 0, 0, 0, 0x3C41),
    L2(4, 0, 0, 0, 0, 0, 0, 0x3C40),
    L2(4, 0, 0, 0, 0, 0, 0, 0x3C3F),
    L2(4, 255, 0, 0, 0, 0, 0, 0x3C3F),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 63 SEAN BALL HIT, 64 no name */
const u16 yang_yuca_063_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 yang_yuca_063[28] = {
    L2(4, 0, 0, 0, 0, 0, 0, 0x3D00),
    L2(2, 0, 0, 0, 0, 0, 0, 0x3D01),
    L2(2, 0, 0, 0, 0, 0, 0, 0x3D02),
    L2(4, 0, 0, 0, 0, 0, 0, 0x3D03),
    L2(4, 0, 0, 0, 0, 0, 0, 0x3D04),
    L2(250, 255, 0, 0, 0, 0, 0, 0x3D04),
    CMD(CM_ROA, 0, 0, 0),
};
