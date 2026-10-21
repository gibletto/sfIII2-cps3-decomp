/*
 * GOUKI1_YUCA.C  Akuma's animation scripts
 *
 * The animation scripts Akuma's moves run, one table per kind of script (yuca), each an index of
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

extern const u16 gouki1_yuca_000[], gouki1_yuca_008[], gouki1_yuca_016[], gouki1_yuca_017[], gouki1_yuca_018[], gouki1_yuca_019[], gouki1_yuca_020[], gouki1_yuca_021[], gouki1_yuca_022[], gouki1_yuca_023[], gouki1_yuca_024[], gouki1_yuca_032[], gouki1_yuca_034[], gouki1_yuca_036[], gouki1_yuca_038[], gouki1_yuca_040[], gouki1_yuca_048[], gouki1_yuca_060[], gouki1_yuca_061[], gouki1_yuca_062[], gouki1_yuca_063[], gouki1_yuca_064[], gouki1_yuca_068[];

/* yuca scripts (debug viewer: ETC): 69 entries */
const u32 gouki1_yuca[70] = {
    (u32)gouki1_yuca_000,  /* 0 APPEAR JUNBI 1 */
    (u32)gouki1_yuca_000,  /* 1 APPEAR JUNBI 2 */
    (u32)gouki1_yuca_000,  /* 2 APPEAR JUNBI 3 */
    (u32)gouki1_yuca_000,  /* 3 APPEAR JUNBI 4 */
    (u32)gouki1_yuca_000,  /* 4 APPEAR JUNBI 5 */
    (u32)gouki1_yuca_000,  /* 5 APPEAR JUNBI 6 */
    (u32)gouki1_yuca_000,  /* 6 APPEAR JUNBI 7 */
    (u32)gouki1_yuca_000,  /* 7 APPEAR JUNBI 8 */
    (u32)gouki1_yuca_008,  /* 8 APPEAR 1 */
    (u32)gouki1_yuca_008,  /* 9 APPEAR 2 */
    (u32)gouki1_yuca_008,  /* 10 APPEAR 3 */
    (u32)gouki1_yuca_008,  /* 11 APPEAR 4 */
    (u32)gouki1_yuca_008,  /* 12 APPEAR 5 */
    (u32)gouki1_yuca_008,  /* 13 APPEAR 6 */
    (u32)gouki1_yuca_008,  /* 14 APPEAR 7 */
    (u32)gouki1_yuca_008,  /* 15 APPEAR 8 */
    (u32)gouki1_yuca_016,  /* 16 SP APPEAR 1 */
    (u32)gouki1_yuca_017,  /* 17 SP APPEAR 2 */
    (u32)gouki1_yuca_018,  /* 18 SP APPEAR 3 */
    (u32)gouki1_yuca_019,  /* 19 SP APPEAR 4 */
    (u32)gouki1_yuca_020,  /* 20 SP APPEAR 5 */
    (u32)gouki1_yuca_021,  /* 21 SP APPEAR 6 */
    (u32)gouki1_yuca_022,  /* 22 SP APPEAR 7 */
    (u32)gouki1_yuca_023,  /* 23 SP APPEAR 8 */
    (u32)gouki1_yuca_024,  /* 24 ZANNEN 1 */
    (u32)gouki1_yuca_024,  /* 25 ZANNEN 2 */
    (u32)gouki1_yuca_024,  /* 26 ZANNEN 3 */
    (u32)gouki1_yuca_024,  /* 27 ZANNEN 4 */
    (u32)gouki1_yuca_024,  /* 28 ZANNEN 5 */
    (u32)gouki1_yuca_024,  /* 29 ZANNEN 6 */
    (u32)gouki1_yuca_024,  /* 30 ZANNEN 7 */
    (u32)gouki1_yuca_024,  /* 31 ZANNEN 8 */
    (u32)gouki1_yuca_032,  /* 32 WIN 1 */
    (u32)gouki1_yuca_032,  /* 33 WIN 2 */
    (u32)gouki1_yuca_034,  /* 34 WIN 3 */
    (u32)gouki1_yuca_034,  /* 35 WIN 4 */
    (u32)gouki1_yuca_036,  /* 36 WIN 5 */
    (u32)gouki1_yuca_036,  /* 37 WIN 6 */
    (u32)gouki1_yuca_038,  /* 38 WIN 7 */
    (u32)gouki1_yuca_038,  /* 39 WIN 8 */
    (u32)gouki1_yuca_040,  /* 40 SP WIN 1 */
    (u32)gouki1_yuca_040,  /* 41 SP WIN 2 */
    (u32)gouki1_yuca_040,  /* 42 SP WIN 3 */
    (u32)gouki1_yuca_040,  /* 43 SP WIN 4 */
    (u32)gouki1_yuca_040,  /* 44 SP WIN 5 */
    (u32)gouki1_yuca_040,  /* 45 SP WIN 6 */
    (u32)gouki1_yuca_040,  /* 46 SP WIN 7 */
    (u32)gouki1_yuca_040,  /* 47 SP WIN 8 */
    (u32)gouki1_yuca_048,  /* 48 JUDGMENT WAIT */
    (u32)gouki1_yuca_048,  /* 49 JUDGMENT WAIT */
    (u32)gouki1_yuca_048,  /* 50 JUDGMENT WAIT */
    (u32)gouki1_yuca_048,  /* 51 JUDGMENT WAIT */
    (u32)gouki1_yuca_034,  /* 52 JUDGMENT WIN */
    (u32)gouki1_yuca_034,  /* 53 JUDGMENT WIN */
    (u32)gouki1_yuca_034,  /* 54 JUDGMENT WIN */
    (u32)gouki1_yuca_034,  /* 55 JUDGMENT WIN */
    (u32)gouki1_yuca_024,  /* 56 JUDGMENT LOSE */
    (u32)gouki1_yuca_024,  /* 57 JUDGMENT LOSE */
    (u32)gouki1_yuca_024,  /* 58 JUDGMENT LOSE */
    (u32)gouki1_yuca_024,  /* 59 JUDGMENT LOSE */
    (u32)gouki1_yuca_060,  /* 60 WAIT */
    (u32)gouki1_yuca_061,  /* 61 AFRICA JUMP */
    (u32)gouki1_yuca_062,  /* 62 AFRICA LAND */
    (u32)gouki1_yuca_063,  /* 63 SEAN BALL HIT */
    (u32)gouki1_yuca_064,  /* 64 no name */
    (u32)gouki1_yuca_038,  /* 65 BONUS WIN 1 */
    (u32)gouki1_yuca_032,  /* 66 BONUS WIN 2 */
    (u32)gouki1_yuca_024,  /* 67 BONUS WIN 3 */
    (u32)gouki1_yuca_068,  /* 68 no name */
    0
};

/* script: 0 APPEAR JUNBI 1, 1 APPEAR JUNBI 2, 2 APPEAR JUNBI 3, 3 APPEAR JUNBI 4 ... */
const u16 gouki1_yuca_000_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 gouki1_yuca_000[8] = {
    L2(4, 9, 0, 0, 0, 0, 0, 0x56F5),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 8 APPEAR 1, 9 APPEAR 2, 10 APPEAR 3, 11 APPEAR 4 ... */
const u16 gouki1_yuca_008_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 gouki1_yuca_008[180] = {
    L4(20, 0, 0, 0, 0, 0, 0, 0x56F5, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_PA_X, 0, -9728, 0), 0, 0, 0, 0,
    L4(6, 0, 0, 0, 0, 0, 0, 0x56FA, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_PA_X, 0, -4352, 0), 0, 0, 0, 0,
    L4(4, 0, 0, 0, 0, 0, 0, 0x56FB, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_PA_X, 0, -4096, 0), 0, 0, 0, 0,
    L4(4, 0, 634, 0, 0, 0, 0, 0x56FC, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 351, 0, 0, 0, 0, 0x5730, 0, 1, 0, 0, 0, 39, 20),
    CMD(CM_FOR, 0, 0, 2), 0, 0, 0, 0,
    L4(3, 0, 0, 0, 0, 0, 0, 0x5730, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5731, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5732, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5733, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5734, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5735, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5736, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5737, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_NEX, 0, 0, 0), 0, 0, 0, 0,
    L4(5, 0, 643, 0, 0, 0, 0, 0x5549, 0, 1, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x554A, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5401, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x5401, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 16 SP APPEAR 1 */
const u16 gouki1_yuca_016_head[4] = { HEAD(2, 38, 0, 0, 0, 0, 0) };
const u16 gouki1_yuca_016[12] = {
    L2(60, 0, 0, 0, 0, 0, 0, 0x54F8),
    L2(60, 9, 0, 0, 0, 0, 0, 0x54F8),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 17 SP APPEAR 2 */
const u16 gouki1_yuca_017_head[4] = { HEAD(2, 38, 5, 0, 0, 0, 0) };
const u16 gouki1_yuca_017[116] = {
    CMD(CM_EXEC, 16, 6, 0),
    L2(6, 0, 0, 0, 0, 0, 0, 0x54F9),
    CMD(CM_PA_X, 0, 2048, 0),
    L2(7, 0, 0, 0, 0, 0, 0, 0x561B),
    CMD(CM_PA_X, 0, 3072, 0),
    L2(9, 0, 0, 0, 0, 0, 0, 0x5623),
    CMD(CM_PA_X, 0, -6656, 0),
    L2(12, 0, 641, 0, 0, 0, 0, 0x54AC),
    L2(10, 0, 0, 0, 0, 0, 0, 0x54AD),
    CMD(CM_PA_X, 0, 1536, 0),
    L2(4, 0, 0, 0, 0, 0, 0, 0x55C8),
    CMD(CM_PA_X, 0, 6144, 0),
    L2(5, 0, 0, 0, 0, 0, 0, 0x56FA),
    CMD(CM_PA_X, 0, -4608, 0),
    L2(12, 0, 0, 0, 0, 0, 0, 0x56FB),
    CMD(CM_PA_X, 0, -3584, 0),
    L2(3, 0, 0, 0, 0, 0, 0, 0x56FC),
    CMD(CM_QUAY, 20, 0, 0),
    L2(1, 0, 351, 0, 0, 0, 0, 0x56FD),
    CMD(CM_FOR, 0, 0, 5),
    L2(3, 0, 0, 0, 0, 0, 0, 0x56FE),
    L2(3, 0, 0, 0, 0, 0, 0, 0x56FF),
    CMD(CM_NEX, 0, 0, 0),
    CMD(CM_FOR, 0, 0, 5),
    L2(3, 255, 0, 0, 0, 0, 0, 0x56FE),
    L2(3, 0, 0, 0, 0, 0, 0, 0x56FF),
    CMD(CM_NEX, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 4),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 18 SP APPEAR 3 */
const u16 gouki1_yuca_018_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 gouki1_yuca_018[8] = {
    L2(6, 255, 0, 0, 0, 0, 0, 0x5401),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 19 SP APPEAR 4 */
const u16 gouki1_yuca_019_head[4] = { HEAD(2, 38, 5, 0, 0, 0, 0) };
const u16 gouki1_yuca_019[124] = {
    CMD(CM_EXEC, 16, 6, 0),
    L2(6, 0, 0, 0, 0, 0, 0, 0x54F9),
    CMD(CM_PA_X, 0, 2048, 0),
    L2(7, 0, 0, 0, 0, 0, 0, 0x561B),
    CMD(CM_PA_X, 0, 3072, 0),
    L2(9, 0, 0, 0, 0, 0, 0, 0x5623),
    CMD(CM_PA_X, 0, -6656, 0),
    L2(12, 0, 641, 0, 0, 0, 0, 0x54AC),
    L2(10, 0, 0, 0, 0, 0, 0, 0x54AD),
    L2(6, 0, 0, 0, 1, 0, 0, 0x540B),
    L2(6, 0, 0, 0, 1, 0, 0, 0x540C),
    CMD(CM_PA_X, 0, -1024, 0),
    L2(10, 0, 0, 0, 1, 0, 0, 0x540D),
    CMD(CM_PA_X, 0, -6400, 0),
    L2(4, 0, 0, 0, 1, 0, 0, 0x56FA),
    CMD(CM_PA_X, 0, 3840, 0),
    L2(12, 0, 0, 0, 1, 0, 0, 0x56FB),
    CMD(CM_PA_X, 0, 3840, 0),
    L2(3, 0, 0, 0, 1, 0, 0, 0x56FC),
    CMD(CM_QUAY, 20, 0, 0),
    L2(1, 0, 351, 0, 1, 0, 0, 0x56FD),
    CMD(CM_FOR, 0, 0, 5),
    L2(3, 0, 0, 0, 1, 0, 0, 0x56FE),
    L2(3, 0, 0, 0, 1, 0, 0, 0x56FF),
    CMD(CM_NEX, 0, 0, 0),
    CMD(CM_FOR, 0, 0, 5),
    L2(3, 255, 0, 0, 1, 0, 0, 0x56FE),
    L2(3, 0, 0, 0, 1, 0, 0, 0x56FF),
    CMD(CM_NEX, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 4),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 20 SP APPEAR 5 */
const u16 gouki1_yuca_020_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 gouki1_yuca_020[8] = {
    L2(6, 255, 0, 0, 1, 0, 0, 0x5401),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 21 SP APPEAR 6 */
const u16 gouki1_yuca_021_head[4] = { HEAD(2, 38, 0, 0, 0, 0, 0) };
const u16 gouki1_yuca_021[12] = {
    L2(60, 0, 0, 0, 0, 0, 0, 0x553F),
    L2(60, 9, 0, 0, 0, 0, 0, 0x553F),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 22 SP APPEAR 7 */
const u16 gouki1_yuca_022_head[4] = { HEAD(2, 38, 5, 0, 0, 0, 0) };
const u16 gouki1_yuca_022[116] = {
    CMD(CM_EXEC, 16, 6, 0),
    L2(6, 0, 0, 0, 1, 0, 0, 0x54F9),
    CMD(CM_PA_X, 0, 2048, 0),
    L2(7, 0, 0, 0, 1, 0, 0, 0x561B),
    CMD(CM_PA_X, 0, 3072, 0),
    L2(9, 0, 0, 0, 1, 0, 0, 0x5623),
    CMD(CM_PA_X, 0, 6656, 0),
    L2(12, 0, 641, 0, 1, 0, 0, 0x54AC),
    L2(10, 0, 0, 0, 1, 0, 0, 0x54AD),
    CMD(CM_PA_X, 0, -1536, 0),
    L2(4, 0, 0, 0, 1, 0, 0, 0x55C8),
    CMD(CM_PA_X, 0, -6144, 0),
    L2(5, 0, 0, 0, 1, 0, 0, 0x56FA),
    CMD(CM_PA_X, 0, 4608, 0),
    L2(12, 0, 0, 0, 1, 0, 0, 0x56FB),
    CMD(CM_PA_X, 0, 3584, 0),
    L2(3, 0, 0, 0, 1, 0, 0, 0x56FC),
    CMD(CM_QUAY, 20, 0, 0),
    L2(1, 0, 351, 0, 1, 0, 0, 0x56FD),
    CMD(CM_FOR, 0, 0, 5),
    L2(3, 0, 0, 0, 1, 0, 0, 0x56FE),
    L2(3, 0, 0, 0, 1, 0, 0, 0x56FF),
    CMD(CM_NEX, 0, 0, 0),
    CMD(CM_FOR, 0, 0, 5),
    L2(3, 255, 0, 0, 1, 0, 0, 0x56FE),
    L2(3, 0, 0, 0, 1, 0, 0, 0x56FF),
    CMD(CM_NEX, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 4),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 23 SP APPEAR 8 */
const u16 gouki1_yuca_023_head[4] = { HEAD(2, 38, 5, 0, 0, 0, 0) };
const u16 gouki1_yuca_023[124] = {
    CMD(CM_EXEC, 16, 6, 0),
    L2(6, 0, 0, 0, 1, 0, 0, 0x54F9),
    CMD(CM_PA_X, 0, 2048, 0),
    L2(7, 0, 0, 0, 1, 0, 0, 0x561B),
    CMD(CM_PA_X, 0, 3072, 0),
    L2(9, 0, 0, 0, 1, 0, 0, 0x5623),
    CMD(CM_PA_X, 0, -6656, 0),
    L2(12, 0, 641, 0, 1, 0, 0, 0x54AC),
    L2(10, 0, 0, 0, 1, 0, 0, 0x54AD),
    L2(6, 0, 0, 0, 0, 0, 0, 0x540B),
    L2(6, 0, 0, 0, 0, 0, 0, 0x540C),
    CMD(CM_PA_X, 0, 1024, 0),
    L2(10, 0, 0, 0, 0, 0, 0, 0x540D),
    CMD(CM_PA_X, 0, 6400, 0),
    L2(4, 0, 0, 0, 0, 0, 0, 0x56FA),
    CMD(CM_PA_X, 0, -3840, 0),
    L2(12, 0, 0, 0, 0, 0, 0, 0x56FB),
    CMD(CM_PA_X, 0, -3840, 0),
    L2(3, 0, 0, 0, 0, 0, 0, 0x56FC),
    CMD(CM_QUAY, 20, 0, 0),
    L2(1, 0, 351, 0, 0, 0, 0, 0x56FD),
    CMD(CM_FOR, 0, 0, 5),
    L2(3, 0, 0, 0, 0, 0, 0, 0x56FE),
    L2(3, 0, 0, 0, 0, 0, 0, 0x56FF),
    CMD(CM_NEX, 0, 0, 0),
    CMD(CM_FOR, 0, 0, 5),
    L2(3, 255, 0, 0, 0, 0, 0, 0x56FE),
    L2(3, 0, 0, 0, 0, 0, 0, 0x56FF),
    CMD(CM_NEX, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 4),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 24 ZANNEN 1, 25 ZANNEN 2, 26 ZANNEN 3, 27 ZANNEN 4 ... */
const u16 gouki1_yuca_024_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 gouki1_yuca_024[32] = {
    L2(6, 0, 0, 0, 0, 0, 0, 0x5530),
    L2(6, 0, 0, 0, 0, 0, 0, 0x5531),
    L2(6, 0, 0, 0, 0, 0, 0, 0x5532),
    L2(6, 0, 0, 0, 0, 0, 0, 0x5533),
    L2(6, 0, 0, 0, 0, 0, 0, 0x5534),
    L2(6, 255, 0, 0, 0, 0, 0, 0x5534),
    CMD(CM_END, 0, 0, 6),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 32 WIN 1, 33 WIN 2, 66 BONUS WIN 2 */
const u16 gouki1_yuca_032_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 gouki1_yuca_032[64] = {
    L2(4, 0, 0, 0, 0, 0, 0, 0x55C0),
    CMD(CM_PA_X, 0, -512, 0),
    L2(4, 0, 0, 0, 0, 0, 0, 0x55C8),
    CMD(CM_PA_X, 0, 7936, 0),
    L2(5, 0, 0, 0, 0, 0, 0, 0x56FA),
    CMD(CM_PA_X, 0, -4352, 0),
    L2(5, 0, 0, 0, 0, 0, 0, 0x56FB),
    CMD(CM_PA_X, 0, -3584, 0),
    L2(3, 0, 0, 0, 0, 0, 0, 0x56FC),
    CMD(CM_QUAY, 20, 0, 0),
    L2(1, 0, 351, 0, 0, 0, 0, 0x56FD),
    L2(3, 0, 628, 0, 0, 0, 0, 0x56FD),
    L2(2, 255, 0, 0, 0, 0, 0, 0x56FE),
    L2(2, 255, 0, 0, 0, 0, 0, 0x56FF),
    CMD(CM_IXBW, 0, 0, 2),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 34 WIN 3, 35 WIN 4, 52 JUDGMENT WIN, 53 JUDGMENT WIN ... */
const u16 gouki1_yuca_034_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 gouki1_yuca_034[64] = {
    L2(4, 0, 0, 0, 0, 0, 0, 0x55C0),
    CMD(CM_PA_X, 0, -512, 0),
    L2(4, 0, 0, 0, 0, 0, 0, 0x55C8),
    CMD(CM_PA_X, 0, 7936, 0),
    L2(5, 0, 0, 0, 0, 0, 0, 0x56FA),
    CMD(CM_PA_X, 0, -4352, 0),
    L2(5, 0, 0, 0, 0, 0, 0, 0x56FB),
    CMD(CM_PA_X, 0, -3584, 0),
    L2(3, 0, 0, 0, 0, 0, 0, 0x56FC),
    CMD(CM_QUAY, 20, 0, 0),
    L2(1, 0, 351, 0, 0, 0, 0, 0x56FD),
    L2(3, 0, 633, 0, 0, 0, 0, 0x56FD),
    L2(2, 255, 0, 0, 0, 0, 0, 0x56FE),
    L2(2, 255, 0, 0, 0, 0, 0, 0x56FF),
    CMD(CM_IXBW, 0, 0, 2),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 36 WIN 5, 37 WIN 6 */
const u16 gouki1_yuca_036_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 gouki1_yuca_036[48] = {
    CMD(CM_PA_X, 0, 6144, 0),
    L2(6, 0, 0, 0, 0, 0, 0, 0x56F1),
    CMD(CM_PA_X, 0, 4096, 0),
    L2(6, 0, 0, 0, 0, 0, 0, 0x56F2),
    CMD(CM_PA_X, 0, 2048, 0),
    L2(6, 0, 640, 0, 0, 0, 0, 0x56F3),
    L2(6, 0, 0, 0, 0, 0, 0, 0x56F4),
    L2(6, 0, 0, 0, 0, 0, 0, 0x56F5),
    CMD(CM_EXEC, 12, 10, 0),
    L2(6, 255, 0, 0, 0, 0, 0, 0x56F5),
    CMD(CM_END, 0, 0, 10),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 38 WIN 7, 39 WIN 8, 65 BONUS WIN 1 */
const u16 gouki1_yuca_038_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 gouki1_yuca_038[48] = {
    CMD(CM_PA_X, 0, 6144, 0),
    L2(6, 0, 0, 0, 0, 0, 0, 0x56F1),
    CMD(CM_PA_X, 0, 4096, 0),
    L2(6, 0, 0, 0, 0, 0, 0, 0x56F2),
    CMD(CM_PA_X, 0, 2048, 0),
    L2(6, 0, 639, 0, 0, 0, 0, 0x56F3),
    L2(6, 0, 0, 0, 0, 0, 0, 0x56F4),
    L2(6, 0, 0, 0, 0, 0, 0, 0x56F5),
    CMD(CM_EXEC, 12, 10, 0),
    L2(6, 255, 0, 0, 0, 0, 0, 0x56F5),
    CMD(CM_END, 0, 0, 10),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 40 SP WIN 1, 41 SP WIN 2, 42 SP WIN 3, 43 SP WIN 4 ... */
const u16 gouki1_yuca_040_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 gouki1_yuca_040[40] = {
    CMD(CM_RLJMP, 0, 0, 16389),
    L2(4, 0, 0, 0, 0, 7, 0, 0x56F3),
    L2(4, 255, 0, 0, 0, 7, 0, 0x56F4),
    L2(4, 255, 0, 0, 0, 7, 0, 0x56F5),
    CMD(CM_IXBW, 0, 0, 2),
    L2(4, 0, 0, 0, 0, 8, 0, 0x56F3),
    L2(4, 255, 0, 0, 0, 8, 0, 0x56F4),
    L2(4, 255, 0, 0, 0, 8, 0, 0x56F5),
    CMD(CM_IXBW, 0, 0, 2),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 48 JUDGMENT WAIT, 49 JUDGMENT WAIT, 50 JUDGMENT WAIT, 51 JUDGMENT WAIT */
const u16 gouki1_yuca_048_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 gouki1_yuca_048[44] = {
    L2(5, 0, 0, 0, 0, 0, 0, 0x5401),
    L2(5, 0, 0, 0, 0, 0, 0, 0x5402),
    L2(5, 0, 0, 0, 0, 0, 0, 0x5403),
    L2(5, 0, 0, 0, 0, 0, 0, 0x5404),
    L2(6, 0, 0, 0, 0, 0, 0, 0x5405),
    L2(6, 0, 0, 0, 0, 0, 0, 0x5406),
    L2(5, 0, 0, 0, 0, 0, 0, 0x5407),
    L2(4, 0, 0, 0, 0, 0, 0, 0x5408),
    L2(4, 0, 0, 0, 0, 0, 0, 0x5409),
    L2(4, 255, 0, 0, 0, 0, 0, 0x540A),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 60 WAIT */
const u16 gouki1_yuca_060_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 gouki1_yuca_060[84] = {
    L4(5, 0, 0, 0, 0, 0, 0, 0x5401, 0, 1, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x5402, 0, 1, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x5403, 0, 1, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x5404, 0, 1, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x5405, 0, 1, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x5406, 0, 1, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x5407, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x5408, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x5409, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 255, 0, 0, 0, 0, 0, 0x540A, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 61 AFRICA JUMP */
const u16 gouki1_yuca_061_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 gouki1_yuca_061[52] = {
    L2(2, 0, 0, 0, 0, 0, 0, 0x542A),
    L2(2, 0, 0, 0, 0, 0, 0, 0x5441),
    L2(2, 0, 0, 0, 0, 0, 0, 0x5442),
    L2(2, 0, 0, 0, 0, 0, 0, 0x5443),
    L2(3, 0, 0, 0, 0, 0, 0, 0x5444),
    L2(3, 0, 0, 0, 0, 0, 0, 0x5445),
    L2(3, 0, 0, 0, 0, 0, 0, 0x5446),
    L2(3, 0, 0, 0, 0, 0, 0, 0x5447),
    L2(3, 0, 0, 0, 0, 0, 0, 0x5448),
    L2(3, 0, 0, 0, 0, 0, 0, 0x5449),
    L2(3, 0, 0, 0, 0, 0, 0, 0x544A),
    CMD(CM_END, 0, 0, 10),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 62 AFRICA LAND */
const u16 gouki1_yuca_062_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 gouki1_yuca_062[16] = {
    L2(2, 0, 0, 0, 0, 0, 0, 0x5549),
    L2(2, 0, 0, 0, 0, 0, 0, 0x554A),
    L2(3, 255, 0, 0, 0, 0, 0, 0x554A),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 63 SEAN BALL HIT */
const u16 gouki1_yuca_063_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 gouki1_yuca_063[28] = {
    L2(4, 0, 0, 0, 0, 0, 0, 0x5494),
    L2(4, 0, 0, 0, 0, 0, 0, 0x5493),
    L2(6, 0, 0, 0, 0, 0, 0, 0x5491),
    L2(4, 0, 0, 0, 0, 0, 0, 0x5493),
    L2(4, 0, 0, 0, 0, 0, 0, 0x5494),
    L2(250, 255, 0, 0, 0, 0, 0, 0x5494),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 64 no name */
const u16 gouki1_yuca_064_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 gouki1_yuca_064[84] = {
    L2(6, 0, 0, 0, 0, 0, 0, 0x54F9),
    L2(7, 0, 0, 0, 0, 0, 0, 0x561B),
    L2(9, 0, 0, 0, 0, 0, 0, 0x5623),
    L2(12, 0, 641, 0, 0, 0, 0, 0x54AC),
    L2(10, 0, 0, 0, 0, 0, 0, 0x54AD),
    L2(4, 0, 0, 0, 0, 0, 0, 0x55C8),
    L2(5, 0, 0, 0, 0, 0, 0, 0x56FA),
    L2(12, 0, 0, 0, 0, 0, 0, 0x56FB),
    L2(3, 0, 0, 0, 0, 0, 0, 0x56FC),
    CMD(CM_QUAY, 20, 0, 0),
    L2(1, 0, 0, 0, 0, 0, 0, 0x56FD),
    CMD(CM_FOR, 0, 0, 5),
    L2(3, 0, 0, 0, 0, 0, 0, 0x56FE),
    L2(3, 0, 0, 0, 0, 0, 0, 0x56FF),
    CMD(CM_NEX, 0, 0, 0),
    CMD(CM_FOR, 0, 0, 5),
    L2(3, 255, 0, 0, 0, 0, 0, 0x56FE),
    L2(3, 0, 0, 0, 0, 0, 0, 0x56FF),
    CMD(CM_NEX, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 4),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 68 no name */
const u16 gouki1_yuca_068_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 gouki1_yuca_068[128] = {
    CMD(CM_EXEC, 16, 6, 0),
    L2(12, 0, 0, 0, 0, 0, 0, 0x54F8),
    L2(6, 0, 0, 0, 0, 0, 0, 0x54F9),
    CMD(CM_PAXY, 0, 512, -256),
    L2(6, 0, 0, 0, 0, 0, 0, 0x561B),
    CMD(CM_PA_X, 0, 256, 0),
    L2(4, 0, 0, 0, 0, 0, 0, 0x5624),
    CMD(CM_PA_X, 0, -3328, 0),
    L2(6, 0, 0, 0, 0, 0, 0, 0x5625),
    CMD(CM_PAXY, 0, -1024, 256),
    L2(4, 0, 0, 0, 0, 0, 0, 0x542F),
    CMD(CM_PA_X, 0, 256, 0),
    L2(4, 0, 641, 0, 0, 0, 0, 0x5405),
    L2(5, 0, 0, 0, 0, 0, 0, 0x5406),
    L2(6, 0, 0, 0, 0, 0, 0, 0x5407),
    CMD(CM_PA_X, 0, 256, 0),
    L2(4, 0, 0, 0, 0, 0, 0, 0x55C0),
    L2(6, 0, 0, 0, 0, 0, 0, 0x55C8),
    CMD(CM_PA_X, 0, 8192, 0),
    L2(8, 0, 0, 0, 0, 0, 0, 0x56FA),
    CMD(CM_PA_X, 0, -4864, 0),
    L2(8, 0, 0, 0, 0, 0, 0, 0x56FB),
    CMD(CM_PA_X, 0, -3840, 0),
    L2(4, 0, 0, 0, 0, 0, 0, 0x56FC),
    CMD(CM_PA_X, 0, -512, 0),
    L2(2, 0, 0, 0, 0, 0, 0, 0x56FD),
    CMD(CM_QUAY, 18, 0, 0),
    L2(2, 0, 0, 0, 0, 0, 0, 0x56FD),
    L2(4, 0, 0, 0, 0, 0, 0, 0x56FE),
    L2(12, 0, 0, 0, 0, 0, 0, 0x56FF),
    L2(250, 255, 0, 0, 0, 0, 0, 0x56FF),
    CMD(CM_ROA, 0, 0, 0),
};
