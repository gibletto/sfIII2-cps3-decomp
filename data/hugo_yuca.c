/*
 * HUGO_YUCA.C  Hugo's animation scripts
 *
 * The animation scripts Hugo's moves run, one table per kind of script (yuca), each an index of
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

extern const u16 hugo_yuca_000[], hugo_yuca_004[], hugo_yuca_008[], hugo_yuca_012[], hugo_yuca_016[], hugo_yuca_024[], hugo_yuca_032[], hugo_yuca_033[], hugo_yuca_036[], hugo_yuca_040[], hugo_yuca_048[], hugo_yuca_060[], hugo_yuca_061[], hugo_yuca_062[], hugo_yuca_063[];

/* yuca scripts (debug viewer: ETC): 68 entries */
const u32 hugo_yuca[69] = {
    (u32)hugo_yuca_000,  /* 0 APPEAR JUNBI 1 */
    (u32)hugo_yuca_000,  /* 1 APPEAR JUNBI 2 */
    (u32)hugo_yuca_000,  /* 2 APPEAR JUNBI 3 */
    (u32)hugo_yuca_000,  /* 3 APPEAR JUNBI 4 */
    (u32)hugo_yuca_004,  /* 4 APPEAR JUNBI 5 */
    (u32)hugo_yuca_004,  /* 5 APPEAR JUNBI 6 */
    (u32)hugo_yuca_004,  /* 6 APPEAR JUNBI 7 */
    (u32)hugo_yuca_004,  /* 7 APPEAR JUNBI 8 */
    (u32)hugo_yuca_008,  /* 8 APPEAR 1 */
    (u32)hugo_yuca_008,  /* 9 APPEAR 2 */
    (u32)hugo_yuca_008,  /* 10 APPEAR 3 */
    (u32)hugo_yuca_008,  /* 11 APPEAR 4 */
    (u32)hugo_yuca_012,  /* 12 APPEAR 5 */
    (u32)hugo_yuca_012,  /* 13 APPEAR 6 */
    (u32)hugo_yuca_012,  /* 14 APPEAR 7 */
    (u32)hugo_yuca_012,  /* 15 APPEAR 8 */
    (u32)hugo_yuca_016,  /* 16 SP APPEAR 1 */
    (u32)hugo_yuca_016,  /* 17 SP APPEAR 2 */
    (u32)hugo_yuca_016,  /* 18 SP APPEAR 3 */
    (u32)hugo_yuca_016,  /* 19 SP APPEAR 4 */
    (u32)hugo_yuca_016,  /* 20 SP APPEAR 5 */
    (u32)hugo_yuca_016,  /* 21 SP APPEAR 6 */
    (u32)hugo_yuca_016,  /* 22 SP APPEAR 7 */
    (u32)hugo_yuca_016,  /* 23 SP APPEAR 8 */
    (u32)hugo_yuca_024,  /* 24 ZANNEN 1 */
    (u32)hugo_yuca_024,  /* 25 ZANNEN 2 */
    (u32)hugo_yuca_024,  /* 26 ZANNEN 3 */
    (u32)hugo_yuca_024,  /* 27 ZANNEN 4 */
    (u32)hugo_yuca_024,  /* 28 ZANNEN 5 */
    (u32)hugo_yuca_024,  /* 29 ZANNEN 6 */
    (u32)hugo_yuca_024,  /* 30 ZANNEN 7 */
    (u32)hugo_yuca_024,  /* 31 ZANNEN 8 */
    (u32)hugo_yuca_032,  /* 32 WIN 1 */
    (u32)hugo_yuca_033,  /* 33 WIN 2 */
    (u32)hugo_yuca_032,  /* 34 WIN 3 */
    (u32)hugo_yuca_033,  /* 35 WIN 4 */
    (u32)hugo_yuca_036,  /* 36 WIN 5 */
    (u32)hugo_yuca_036,  /* 37 WIN 6 */
    (u32)hugo_yuca_036,  /* 38 WIN 7 */
    (u32)hugo_yuca_036,  /* 39 WIN 8 */
    (u32)hugo_yuca_040,  /* 40 SP WIN 1 */
    (u32)hugo_yuca_040,  /* 41 SP WIN 2 */
    (u32)hugo_yuca_040,  /* 42 SP WIN 3 */
    (u32)hugo_yuca_040,  /* 43 SP WIN 4 */
    (u32)hugo_yuca_040,  /* 44 SP WIN 5 */
    (u32)hugo_yuca_040,  /* 45 SP WIN 6 */
    (u32)hugo_yuca_040,  /* 46 SP WIN 7 */
    (u32)hugo_yuca_040,  /* 47 SP WIN 8 */
    (u32)hugo_yuca_048,  /* 48 JUDGMENT WAIT */
    (u32)hugo_yuca_048,  /* 49 JUDGMENT WAIT */
    (u32)hugo_yuca_048,  /* 50 JUDGMENT WAIT */
    (u32)hugo_yuca_048,  /* 51 JUDGMENT WAIT */
    (u32)hugo_yuca_033,  /* 52 JUDGMENT WIN */
    (u32)hugo_yuca_033,  /* 53 JUDGMENT WIN */
    (u32)hugo_yuca_033,  /* 54 JUDGMENT WIN */
    (u32)hugo_yuca_033,  /* 55 JUDGMENT WIN */
    (u32)hugo_yuca_024,  /* 56 JUDGMENT LOSE */
    (u32)hugo_yuca_024,  /* 57 JUDGMENT LOSE */
    (u32)hugo_yuca_024,  /* 58 JUDGMENT LOSE */
    (u32)hugo_yuca_024,  /* 59 JUDGMENT LOSE */
    (u32)hugo_yuca_060,  /* 60 WAIT */
    (u32)hugo_yuca_061,  /* 61 AFRICA JUMP */
    (u32)hugo_yuca_062,  /* 62 AFRICA LAND */
    (u32)hugo_yuca_063,  /* 63 SEAN BALL HIT */
    (u32)hugo_yuca_063,  /* 64 no name */
    (u32)hugo_yuca_036,  /* 65 BONUS WIN 1 */
    (u32)hugo_yuca_033,  /* 66 BONUS WIN 2 */
    (u32)hugo_yuca_024,  /* 67 BONUS WIN 3 */
    0
};

/* script: 0 APPEAR JUNBI 1, 1 APPEAR JUNBI 2, 2 APPEAR JUNBI 3, 3 APPEAR JUNBI 4 */
const u16 hugo_yuca_000_head[4] = { HEAD(2, 6, 0, 0, 0, 0, 0) };
const u16 hugo_yuca_000[28] = {
    CMD(CM_EXEC, 12, 15, 0),
    CMD(CM_EXEC, 12, 16, 0),
    CMD(CM_EXEC, 12, 17, 0),
    CMD(CM_EXEC, 10, 0, 0),
    L2(5, 9, 0, 0, 0, 0, 0, 0x26C1),
    CMD(CM_IXBW, 0, 0, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 4 APPEAR JUNBI 5, 5 APPEAR JUNBI 6, 6 APPEAR JUNBI 7, 7 APPEAR JUNBI 8 */
const u16 hugo_yuca_004_head[4] = { HEAD(2, 6, 0, 0, 0, 0, 0) };
const u16 hugo_yuca_004[40] = {
    CMD(CM_EXEC, 10, 0, 0),
    L2(5, 0, 0, 0, 0, 0, 0, 0x26B0),
    L2(6, 0, 0, 0, 0, 0, 0, 0x26B1),
    L2(3, 0, 269, 0, 0, 0, 0, 0x26B2),
    L2(4, 0, 0, 0, 0, 0, 0, 0x26B3),
    L2(5, 0, 0, 0, 0, 0, 0, 0x26B4),
    L2(5, 0, 0, 0, 0, 0, 0, 0x26B5),
    L2(5, 9, 0, 0, 0, 0, 0, 0x26B6),
    CMD(CM_IXBW, 0, 0, 7),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 8 APPEAR 1, 9 APPEAR 2, 10 APPEAR 3, 11 APPEAR 4 */
const u16 hugo_yuca_008_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 hugo_yuca_008[68] = {
    L4(40, 0, 0, 0, 0, 0, 0, 0x26C1, 0, 1, 0, 0, 0, 0, 0),
    L4(10, 99, 0, 0, 0, 0, 0, 0x26C1, 0, 1, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x26C2, 0, 1, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x26C3, 0, 1, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x26C4, 0, 1, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x26C5, 0, 1, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x26C6, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x26C6, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 12 APPEAR 5, 13 APPEAR 6, 14 APPEAR 7, 15 APPEAR 8 */
const u16 hugo_yuca_012_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 hugo_yuca_012[180] = {
    L4(5, 0, 0, 0, 0, 0, 0, 0x26B0, 0, 1, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x26B1, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 269, 0, 0, 0, 0, 0x26B2, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x26B3, 0, 1, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x26B4, 0, 1, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x26B5, 0, 1, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x26B6, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x26B7, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 2048, 0, 0, 0, 0, 0x26B9, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x26BA, 0, 1, 0, 0, 0, 0, 0),
    L4(8, 0, 0, 0, 0, 0, 0, 0x26BB, 0, 1, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x26B8, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x26BD, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x26BE, 0, 1, 0, 0, 0, 0, 0),
    L4(16, 0, 0, 0, 0, 0, 0, 0x26BF, 0, 1, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x26BE, 0, 1, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x26BD, 0, 1, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x26BC, 0, 1, 0, 0, 0, 0, 0),
    L4(7, 0, 0, 0, 0, 0, 0, 0x26C0, 0, 1, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x25FC, 0, 1, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x25FD, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x25FD, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 16 SP APPEAR 1, 17 SP APPEAR 2, 18 SP APPEAR 3, 19 SP APPEAR 4 ... */
const u16 hugo_yuca_016_head[4] = { HEAD(2, 24, 0, 0, 0, 0, 0) };
const u16 hugo_yuca_016[104] = {
    L2(20, 0, 0, 0, 0, 0, 0, 0x2703),
    L2(2, 0, 0, 0, 0, 0, 0, 0x2704),
    L2(2, 0, 0, 0, 0, 0, 0, 0x2705),
    L2(2, 0, 0, 0, 0, 0, 0, 0x2704),
    L2(2, 0, 0, 0, 0, 0, 0, 0x2705),
    L2(2, 0, 0, 0, 0, 0, 0, 0x2704),
    L2(2, 0, 0, 0, 0, 0, 0, 0x2705),
    L2(2, 0, 0, 0, 0, 0, 0, 0x2704),
    L2(2, 0, 0, 0, 0, 0, 0, 0x2705),
    L2(2, 0, 0, 0, 0, 0, 0, 0x2704),
    L2(2, 0, 0, 0, 0, 0, 0, 0x2703),
    L2(2, 0, 0, 0, 0, 0, 0, 0x2709),
    L2(2, 0, 0, 0, 0, 0, 0, 0x2708),
    L2(2, 0, 0, 0, 0, 0, 0, 0x2707),
    L2(2, 0, 0, 0, 0, 0, 0, 0x2706),
    CMD(CM_FLIP, 0, 0, 0),
    L2(2, 0, 0, 0, 0, 0, 0, 0x270A),
    L2(2, 0, 0, 0, 0, 0, 0, 0x270B),
    L2(2, 0, 0, 0, 0, 0, 0, 0x270C),
    L2(2, 0, 0, 0, 0, 0, 0, 0x270D),
    L2(2, 0, 0, 0, 0, 0, 0, 0x270E),
    L2(2, 0, 0, 0, 0, 0, 0, 0x270F),
    L2(2, 0, 0, 0, 0, 0, 0, 0x2710),
    L2(2, 255, 0, 0, 0, 0, 0, 0x2711),
    CMD(CM_IXBW, 0, 0, 7),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 24 ZANNEN 1, 25 ZANNEN 2, 26 ZANNEN 3, 27 ZANNEN 4 ... */
const u16 hugo_yuca_024_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 hugo_yuca_024[76] = {
    L4(6, 0, 0, 0, 0, 0, 0, 0x2434, 0, 0, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x2435, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x2436, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 0, 289, 0, 0, 39, 0, 0x26F3, 0, 0, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 39, 0, 0x26F3, 0, 0, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 39, 0, 0x26F4, 0, 0, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 39, 0, 0x26F5, 0, 0, 0, 0, 0, 0, 0),
    L4(6, 255, 0, 0, 0, 39, 0, 0x26F4, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 4), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 32 WIN 1, 34 WIN 3 */
const u16 hugo_yuca_032_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 hugo_yuca_032[64] = {
    L2(8, 0, 0, 0, 0, 0, 0, 0x26B0),
    L2(6, 0, 0, 0, 0, 0, 0, 0x26B1),
    L2(6, 0, 270, 0, 0, 0, 0, 0x26D0),
    L2(6, 0, 0, 0, 0, 0, 0, 0x26D1),
    L2(8, 0, 0, 0, 0, 0, 0, 0x26D2),
    L2(8, 0, 0, 0, 0, 0, 0, 0x26D3),
    L2(5, 0, 0, 0, 0, 0, 0, 0x26D4),
    L2(5, 0, 0, 0, 0, 0, 0, 0x26D5),
    L2(5, 0, 568, 0, 0, 0, 0, 0x26D6),
    L2(5, 0, 0, 0, 0, 0, 0, 0x26D7),
    L2(5, 0, 0, 0, 0, 0, 0, 0x26D8),
    L2(5, 0, 0, 0, 0, 0, 0, 0x26D9),
    L2(5, 0, 0, 0, 0, 0, 0, 0x26DA),
    L2(250, 255, 0, 0, 0, 0, 0, 0x26DA),
    CMD(CM_END, 0, 0, 14),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 33 WIN 2, 35 WIN 4, 52 JUDGMENT WIN, 53 JUDGMENT WIN ... */
const u16 hugo_yuca_033_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 hugo_yuca_033[64] = {
    L2(8, 0, 0, 0, 0, 0, 0, 0x26B0),
    L2(6, 0, 0, 0, 0, 0, 0, 0x26B1),
    L2(6, 0, 553, 0, 0, 0, 0, 0x26D0),
    L2(6, 0, 0, 0, 0, 0, 0, 0x26D1),
    L2(8, 0, 0, 0, 0, 0, 0, 0x26D2),
    L2(8, 0, 0, 0, 0, 0, 0, 0x26D3),
    L2(5, 0, 0, 0, 0, 0, 0, 0x26D4),
    L2(5, 0, 0, 0, 0, 0, 0, 0x26D5),
    L2(5, 0, 548, 0, 0, 0, 0, 0x26D6),
    L2(5, 0, 0, 0, 0, 0, 0, 0x26D7),
    L2(5, 0, 0, 0, 0, 0, 0, 0x26D8),
    L2(5, 0, 0, 0, 0, 0, 0, 0x26D9),
    L2(5, 0, 0, 0, 0, 0, 0, 0x26DA),
    L2(250, 255, 0, 0, 0, 0, 0, 0x26DA),
    CMD(CM_END, 0, 0, 14),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 36 WIN 5, 37 WIN 6, 38 WIN 7, 39 WIN 8 ... */
const u16 hugo_yuca_036_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 hugo_yuca_036[104] = {
    CMD(CM_PA_X, 0, 4096, 0),
    L2(5, 0, 0, 0, 0, 0, 0, 0x26DB),
    L2(5, 0, 0, 0, 0, 0, 0, 0x26DC),
    L2(5, 0, 0, 0, 0, 0, 0, 0x26DD),
    L2(5, 0, 554, 0, 0, 0, 0, 0x26DE),
    L2(5, 0, 0, 0, 0, 0, 0, 0x26DF),
    L2(5, 0, 0, 0, 0, 0, 0, 0x26E0),
    L2(5, 0, 0, 0, 0, 0, 0, 0x26E1),
    L2(5, 0, 0, 0, 0, 0, 0, 0x26E2),
    L2(12, 0, 0, 0, 0, 0, 0, 0x26E3),
    L2(5, 0, 0, 0, 0, 0, 0, 0x26E4),
    L2(5, 0, 0, 0, 0, 0, 0, 0x26E5),
    L2(5, 0, 0, 0, 0, 0, 0, 0x26E6),
    L2(5, 0, 0, 0, 0, 0, 0, 0x26E7),
    L2(5, 0, 0, 0, 0, 0, 0, 0x26E8),
    L2(5, 0, 0, 0, 0, 0, 0, 0x26E9),
    L2(5, 0, 0, 0, 0, 0, 0, 0x26EA),
    L2(5, 0, 0, 0, 0, 0, 0, 0x26EB),
    L2(5, 0, 0, 0, 0, 0, 0, 0x26EC),
    L2(12, 0, 0, 0, 0, 0, 0, 0x26ED),
    L2(5, 255, 0, 0, 0, 0, 0, 0x26EE),
    L2(5, 0, 0, 0, 0, 0, 0, 0x26DC),
    L2(5, 0, 0, 0, 0, 0, 0, 0x26DD),
    L2(5, 0, 0, 0, 0, 0, 0, 0x26DE),
    CMD(CM_END, 0, 0, 6),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 40 SP WIN 1, 41 SP WIN 2, 42 SP WIN 3, 43 SP WIN 4 ... */
const u16 hugo_yuca_040_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 hugo_yuca_040[8] = {
    L2(250, 255, 0, 0, 0, 0, 0, 0x2401),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 48 JUDGMENT WAIT, 49 JUDGMENT WAIT, 50 JUDGMENT WAIT, 51 JUDGMENT WAIT */
const u16 hugo_yuca_048_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 hugo_yuca_048[88] = {
    L2(3, 0, 0, 0, 0, 0, 0, 0x2411),
    L2(4, 0, 0, 0, 0, 0, 0, 0x2412),
    L2(5, 0, 0, 0, 0, 0, 0, 0x2413),
    L2(6, 0, 0, 0, 0, 0, 0, 0x2414),
    L2(7, 0, 0, 0, 0, 0, 0, 0x2415),
    L2(7, 0, 0, 0, 0, 0, 0, 0x2416),
    L2(6, 0, 0, 0, 0, 0, 0, 0x2401),
    L2(6, 0, 0, 0, 0, 0, 0, 0x2402),
    L2(6, 0, 0, 0, 0, 0, 0, 0x2403),
    L2(6, 0, 0, 0, 0, 0, 0, 0x2404),
    L2(6, 0, 0, 0, 0, 0, 0, 0x2405),
    L2(6, 0, 0, 0, 0, 0, 0, 0x2406),
    L2(6, 0, 0, 0, 0, 0, 0, 0x2407),
    L2(6, 0, 0, 0, 0, 0, 0, 0x2401),
    L2(6, 0, 0, 0, 0, 0, 0, 0x2408),
    L2(6, 0, 0, 0, 0, 0, 0, 0x2409),
    L2(6, 0, 0, 0, 0, 0, 0, 0x240A),
    L2(6, 0, 0, 0, 0, 0, 0, 0x240B),
    L2(6, 0, 0, 0, 0, 0, 0, 0x240C),
    L2(6, 255, 0, 0, 0, 0, 0, 0x240D),
    CMD(CM_END, 0, 0, 7),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 60 WAIT */
const u16 hugo_yuca_060_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 hugo_yuca_060[172] = {
    L4(3, 0, 0, 0, 0, 0, 0, 0x2411, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x2412, 0, 1, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x2413, 0, 1, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x2414, 0, 1, 0, 0, 0, 0, 0),
    L4(7, 0, 0, 0, 0, 0, 0, 0x2415, 0, 1, 0, 0, 0, 0, 0),
    L4(7, 0, 0, 0, 0, 0, 0, 0x2416, 0, 1, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x2401, 0, 1, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x2402, 0, 1, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x2403, 0, 1, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x2404, 0, 1, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x2405, 0, 1, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x2406, 0, 1, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x2407, 0, 1, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x2401, 0, 1, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x2408, 0, 1, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x2409, 0, 1, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x240A, 0, 1, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x240B, 0, 1, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x240C, 0, 1, 0, 0, 0, 0, 0),
    L4(6, 255, 0, 0, 0, 0, 0, 0x240D, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_END, 0, 0, 7), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 61 AFRICA JUMP */
const u16 hugo_yuca_061_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 hugo_yuca_061[64] = {
    L2(2, 0, 0, 0, 0, 0, 0, 0x2434),
    L2(4, 0, 0, 0, 0, 0, 0, 0x2449),
    L2(4, 0, 0, 0, 0, 0, 0, 0x244A),
    L2(3, 0, 0, 0, 0, 0, 0, 0x244B),
    L2(3, 0, 0, 0, 0, 0, 0, 0x244C),
    L2(3, 0, 0, 0, 0, 0, 0, 0x244D),
    L2(2, 0, 0, 0, 0, 0, 0, 0x244E),
    L2(2, 0, 0, 0, 0, 0, 0, 0x244F),
    L2(1, 0, 0, 0, 0, 0, 0, 0x2450),
    L2(2, 0, 0, 0, 0, 0, 0, 0x2451),
    L2(3, 0, 0, 0, 0, 0, 0, 0x2452),
    L2(4, 0, 0, 0, 0, 0, 0, 0x2453),
    L2(4, 0, 0, 0, 0, 0, 0, 0x2454),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2455),
    CMD(CM_END, 0, 0, 14),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 62 AFRICA LAND */
const u16 hugo_yuca_062_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 hugo_yuca_062[28] = {
    L2(3, 0, 0, 0, 0, 0, 0, 0x2434),
    L2(4, 0, 0, 0, 0, 0, 0, 0x2435),
    L2(6, 0, 0, 0, 0, 0, 0, 0x2438),
    L2(9, 0, 0, 0, 0, 0, 0, 0x2439),
    L2(3, 0, 0, 0, 0, 0, 0, 0x243A),
    L2(3, 255, 0, 0, 0, 0, 0, 0x243A),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 63 SEAN BALL HIT, 64 no name */
const u16 hugo_yuca_063_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 hugo_yuca_063[12] = {
    L2(20, 0, 0, 0, 0, 0, 0, 0x2480),
    L2(250, 255, 0, 0, 0, 0, 0, 0x2482),
    CMD(CM_ROA, 0, 0, 0),
};
