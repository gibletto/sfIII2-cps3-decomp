/*
 * RYU_YUCA.C  Ryu's animation scripts
 *
 * The animation scripts Ryu's moves run, one table per kind of script (yuca), each an index of
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

extern const u16 ryu_yuca_000[], ryu_yuca_008[], ryu_yuca_016[], ryu_yuca_024[], ryu_yuca_032[], ryu_yuca_036[], ryu_yuca_040[], ryu_yuca_048[], ryu_yuca_060[], ryu_yuca_061[], ryu_yuca_062[], ryu_yuca_063[];

/* yuca scripts (debug viewer: ETC): 68 entries */
const u32 ryu_yuca[69] = {
    (u32)ryu_yuca_000,  /* 0 APPEAR JUNBI 1 */
    (u32)ryu_yuca_000,  /* 1 APPEAR JUNBI 2 */
    (u32)ryu_yuca_000,  /* 2 APPEAR JUNBI 3 */
    (u32)ryu_yuca_000,  /* 3 APPEAR JUNBI 4 */
    (u32)ryu_yuca_000,  /* 4 APPEAR JUNBI 5 */
    (u32)ryu_yuca_000,  /* 5 APPEAR JUNBI 6 */
    (u32)ryu_yuca_000,  /* 6 APPEAR JUNBI 7 */
    (u32)ryu_yuca_000,  /* 7 APPEAR JUNBI 8 */
    (u32)ryu_yuca_008,  /* 8 APPEAR 1 */
    (u32)ryu_yuca_008,  /* 9 APPEAR 2 */
    (u32)ryu_yuca_008,  /* 10 APPEAR 3 */
    (u32)ryu_yuca_008,  /* 11 APPEAR 4 */
    (u32)ryu_yuca_008,  /* 12 APPEAR 5 */
    (u32)ryu_yuca_008,  /* 13 APPEAR 6 */
    (u32)ryu_yuca_008,  /* 14 APPEAR 7 */
    (u32)ryu_yuca_008,  /* 15 APPEAR 8 */
    (u32)ryu_yuca_016,  /* 16 SP APPEAR 1 */
    (u32)ryu_yuca_016,  /* 17 SP APPEAR 2 */
    (u32)ryu_yuca_016,  /* 18 SP APPEAR 3 */
    (u32)ryu_yuca_016,  /* 19 SP APPEAR 4 */
    (u32)ryu_yuca_016,  /* 20 SP APPEAR 5 */
    (u32)ryu_yuca_016,  /* 21 SP APPEAR 6 */
    (u32)ryu_yuca_016,  /* 22 SP APPEAR 7 */
    (u32)ryu_yuca_016,  /* 23 SP APPEAR 8 */
    (u32)ryu_yuca_024,  /* 24 ZANNEN 1 */
    (u32)ryu_yuca_024,  /* 25 ZANNEN 2 */
    (u32)ryu_yuca_024,  /* 26 ZANNEN 3 */
    (u32)ryu_yuca_024,  /* 27 ZANNEN 4 */
    (u32)ryu_yuca_024,  /* 28 ZANNEN 5 */
    (u32)ryu_yuca_024,  /* 29 ZANNEN 6 */
    (u32)ryu_yuca_024,  /* 30 ZANNEN 7 */
    (u32)ryu_yuca_024,  /* 31 ZANNEN 8 */
    (u32)ryu_yuca_032,  /* 32 WIN 1 */
    (u32)ryu_yuca_032,  /* 33 WIN 2 */
    (u32)ryu_yuca_032,  /* 34 WIN 3 */
    (u32)ryu_yuca_032,  /* 35 WIN 4 */
    (u32)ryu_yuca_036,  /* 36 WIN 5 */
    (u32)ryu_yuca_036,  /* 37 WIN 6 */
    (u32)ryu_yuca_036,  /* 38 WIN 7 */
    (u32)ryu_yuca_036,  /* 39 WIN 8 */
    (u32)ryu_yuca_040,  /* 40 SP WIN 1 */
    (u32)ryu_yuca_040,  /* 41 SP WIN 2 */
    (u32)ryu_yuca_040,  /* 42 SP WIN 3 */
    (u32)ryu_yuca_040,  /* 43 SP WIN 4 */
    (u32)ryu_yuca_040,  /* 44 SP WIN 5 */
    (u32)ryu_yuca_040,  /* 45 SP WIN 6 */
    (u32)ryu_yuca_040,  /* 46 SP WIN 7 */
    (u32)ryu_yuca_040,  /* 47 SP WIN 8 */
    (u32)ryu_yuca_048,  /* 48 JUDGMENT WAIT */
    (u32)ryu_yuca_048,  /* 49 JUDGMENT WAIT */
    (u32)ryu_yuca_048,  /* 50 JUDGMENT WAIT */
    (u32)ryu_yuca_048,  /* 51 JUDGMENT WAIT */
    (u32)ryu_yuca_032,  /* 52 JUDGMENT WIN */
    (u32)ryu_yuca_032,  /* 53 JUDGMENT WIN */
    (u32)ryu_yuca_032,  /* 54 JUDGMENT WIN */
    (u32)ryu_yuca_032,  /* 55 JUDGMENT WIN */
    (u32)ryu_yuca_024,  /* 56 JUDGMENT LOSE */
    (u32)ryu_yuca_024,  /* 57 JUDGMENT LOSE */
    (u32)ryu_yuca_024,  /* 58 JUDGMENT LOSE */
    (u32)ryu_yuca_024,  /* 59 JUDGMENT LOSE */
    (u32)ryu_yuca_060,  /* 60 WAIT */
    (u32)ryu_yuca_061,  /* 61 AFRICA JUMP */
    (u32)ryu_yuca_062,  /* 62 AFRICA LAND */
    (u32)ryu_yuca_063,  /* 63 SEAN BALL HIT */
    (u32)ryu_yuca_063,  /* 64 no name */
    (u32)ryu_yuca_036,  /* 65 BONUS WIN 1 */
    (u32)ryu_yuca_032,  /* 66 BONUS WIN 2 */
    (u32)ryu_yuca_024,  /* 67 BONUS WIN 3 */
    0
};

/* script: 0 APPEAR JUNBI 1, 1 APPEAR JUNBI 2, 2 APPEAR JUNBI 3, 3 APPEAR JUNBI 4 ... */
const u16 ryu_yuca_000_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ryu_yuca_000[8] = {
    L2(4, 9, 0, 0, 0, 0, 0, 0x0ED0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 8 APPEAR 1, 9 APPEAR 2, 10 APPEAR 3, 11 APPEAR 4 ... */
const u16 ryu_yuca_008_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 ryu_yuca_008[76] = {
    L4(32, 0, 0, 0, 0, 0, 0, 0x0ED0, 0, 1, 0, 0, 0, 0, 0),
    L4(7, 0, 511, 0, 0, 0, 0, 0x0ED1, 0, 1, 0, 0, 0, 0, 0),
    L4(7, 0, 0, 0, 0, 0, 0, 0x0ED2, 0, 1, 0, 0, 0, 0, 0),
    L4(7, 0, 0, 0, 0, 0, 0, 0x0ED3, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_EXEC, 12, 0, 0), 0x0000, 0x2000, 0x0000, 0x0000,
    L4(7, 0, 0, 0, 0, 0, 0, 0x0C2E, 0, 1, 0, 0, 0, 0, 0),
    L4(7, 0, 0, 0, 0, 0, 0, 0x0C2F, 0, 1, 0, 0, 0, 0, 0),
    L4(7, 0, 0, 0, 0, 0, 0, 0x0C93, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x0C93, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 16 SP APPEAR 1, 17 SP APPEAR 2, 18 SP APPEAR 3, 19 SP APPEAR 4 ... */
const u16 ryu_yuca_016_head[4] = { HEAD(2, 24, 0, 0, 0, 0, 0) };
const u16 ryu_yuca_016[8] = {
    L2(4, 0, 0, 0, 0, 0, 0, 0x0C01),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 24 ZANNEN 1, 25 ZANNEN 2, 26 ZANNEN 3, 27 ZANNEN 4 ... */
const u16 ryu_yuca_024_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ryu_yuca_024[32] = {
    L2(6, 0, 0, 0, 0, 0, 0, 0x0F3E),
    L2(6, 0, 0, 0, 0, 0, 0, 0x0F3F),
    L2(6, 0, 0, 0, 0, 0, 0, 0x0F40),
    L2(6, 0, 0, 0, 0, 0, 0, 0x0F41),
    L2(6, 0, 0, 0, 0, 0, 0, 0x0F42),
    L2(6, 255, 0, 0, 0, 0, 0, 0x0F42),
    CMD(CM_END, 0, 0, 6),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 32 WIN 1, 33 WIN 2, 34 WIN 3, 35 WIN 4 ... */
const u16 ryu_yuca_032_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ryu_yuca_032[48] = {
    L2(4, 0, 0, 0, 0, 0, 0, 0x0EF0),
    CMD(CM_PA_X, 0, -256, 0),
    L2(2, 0, 0, 0, 0, 0, 0, 0x0EF1),
    CMD(CM_PA_X, 0, -256, 0),
    L2(3, 0, 0, 0, 0, 0, 0, 0x0EF2),
    L2(3, 0, 0, 0, 0, 0, 0, 0x0EF3),
    CMD(CM_PA_X, 0, -256, 0),
    L2(4, 0, 0, 0, 0, 0, 0, 0x0EF4),
    L2(12, 0, 0, 0, 0, 0, 0, 0x0EF5),
    L2(250, 255, 0, 0, 0, 0, 0, 0x0EF5),
    CMD(CM_END, 0, 0, 10),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 36 WIN 5, 37 WIN 6, 38 WIN 7, 39 WIN 8 ... */
const u16 ryu_yuca_036_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ryu_yuca_036[120] = {
    L2(4, 0, 0, 0, 0, 0, 0, 0x0EF6),
    CMD(CM_PA_X, 0, 512, 0),
    L2(4, 0, 0, 0, 0, 0, 0, 0x0EF7),
    CMD(CM_PA_X, 0, 512, 0),
    L2(4, 0, 0, 0, 0, 0, 0, 0x0EF8),
    CMD(CM_PA_X, 0, 512, 0),
    L2(4, 0, 0, 0, 0, 0, 0, 0x0EF9),
    L2(7, 0, 0, 0, 0, 0, 0, 0x0EFA),
    L2(7, 0, 0, 0, 0, 0, 0, 0x0EFB),
    L2(7, 0, 0, 0, 0, 0, 0, 0x0EFC),
    L2(7, 0, 0, 0, 0, 0, 0, 0x0EFD),
    L2(7, 0, 0, 0, 0, 0, 0, 0x0EFE),
    L2(7, 0, 0, 0, 0, 0, 0, 0x0EFF),
    L2(7, 0, 0, 0, 0, 0, 0, 0x0F01),
    L2(7, 0, 0, 0, 0, 0, 0, 0x0F02),
    L2(7, 255, 0, 0, 0, 0, 0, 0x0F03),
    L2(7, 0, 0, 0, 0, 0, 0, 0x0F04),
    L2(7, 0, 0, 0, 0, 0, 0, 0x0F05),
    L2(7, 0, 0, 0, 0, 0, 0, 0x0F06),
    L2(7, 0, 0, 0, 0, 0, 0, 0x0F07),
    L2(7, 0, 0, 0, 0, 0, 0, 0x0F08),
    L2(7, 0, 0, 0, 0, 0, 0, 0x0F09),
    L2(7, 0, 0, 0, 0, 0, 0, 0x0F0A),
    L2(7, 0, 0, 0, 0, 0, 0, 0x0F0B),
    L2(7, 0, 0, 0, 0, 0, 0, 0x0F0C),
    L2(7, 0, 0, 0, 0, 0, 0, 0x0F0D),
    L2(7, 0, 0, 0, 0, 0, 0, 0x0EFA),
    L2(250, 255, 0, 0, 0, 0, 0, 0x0EFA),
    CMD(CM_END, 0, 0, 28),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 40 SP WIN 1, 41 SP WIN 2, 42 SP WIN 3, 43 SP WIN 4 ... */
const u16 ryu_yuca_040_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ryu_yuca_040[8] = {
    L2(7, 255, 0, 0, 0, 0, 0, 0x0C01),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 48 JUDGMENT WAIT, 49 JUDGMENT WAIT, 50 JUDGMENT WAIT, 51 JUDGMENT WAIT */
const u16 ryu_yuca_048_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ryu_yuca_048[44] = {
    L2(3, 0, 0, 0, 0, 0, 0, 0x0C01),
    L2(4, 0, 0, 0, 0, 0, 0, 0x0C02),
    L2(3, 0, 0, 0, 0, 0, 0, 0x0C03),
    L2(3, 0, 0, 0, 0, 0, 0, 0x0C04),
    L2(3, 0, 0, 0, 0, 0, 0, 0x0C05),
    L2(3, 0, 0, 0, 0, 0, 0, 0x0C06),
    L2(4, 0, 0, 0, 0, 0, 0, 0x0C07),
    L2(3, 0, 0, 0, 0, 0, 0, 0x0C08),
    L2(3, 0, 0, 0, 0, 0, 0, 0x0C09),
    L2(2, 255, 0, 0, 0, 0, 0, 0x0C0A),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 60 WAIT */
const u16 ryu_yuca_060_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 ryu_yuca_060[84] = {
    L4(4, 0, 0, 0, 0, 0, 0, 0x0C01, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x0C02, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x0C03, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x0C04, 0, 1, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x0C05, 0, 1, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x0C06, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x0C07, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0C08, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0C09, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 255, 0, 0, 0, 0, 0, 0x0C0A, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 61 AFRICA JUMP */
const u16 ryu_yuca_061_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ryu_yuca_061[76] = {
    L2(4, 0, 0, 0, 0, 0, 0, 0x0C29),
    L2(1, 0, 281, 0, 0, 0, 0, 0x0C40),
    L2(1, 0, 0, 0, 0, 0, 0, 0x0C41),
    L2(1, 0, 0, 0, 0, 0, 0, 0x0C6A),
    L2(1, 0, 0, 0, 0, 0, 0, 0x0C40),
    L2(1, 0, 0, 0, 0, 0, 0, 0x0C41),
    L2(1, 0, 0, 0, 0, 0, 0, 0x0C6A),
    L2(3, 0, 0, 0, 0, 0, 0, 0x0C42),
    L2(3, 0, 0, 0, 0, 0, 0, 0x0C43),
    L2(3, 0, 0, 0, 0, 0, 0, 0x0C44),
    L2(3, 0, 0, 0, 0, 0, 0, 0x0C45),
    L2(3, 0, 0, 0, 0, 0, 0, 0x0C46),
    L2(3, 0, 0, 0, 0, 0, 0, 0x0C47),
    L2(3, 0, 0, 0, 0, 0, 0, 0x0C48),
    L2(3, 0, 0, 0, 0, 0, 0, 0x0C49),
    L2(3, 0, 0, 0, 0, 0, 0, 0x0C4A),
    L2(3, 0, 0, 0, 0, 0, 0, 0x0C6B),
    CMD(CM_END, 0, 0, 15),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 62 AFRICA LAND */
const u16 ryu_yuca_062_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ryu_yuca_062[20] = {
    L2(4, 0, 0, 0, 0, 0, 0, 0x0C2A),
    L2(3, 0, 0, 0, 0, 0, 0, 0x0C4B),
    L2(3, 0, 0, 0, 0, 0, 0, 0x0C2F),
    L2(3, 255, 0, 0, 0, 0, 0, 0x0C2F),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 63 SEAN BALL HIT, 64 no name */
const u16 ryu_yuca_063_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ryu_yuca_063[36] = {
    L2(4, 0, 0, 0, 0, 0, 0, 0x0CB3),
    L2(2, 0, 0, 0, 0, 0, 0, 0x0CB4),
    L2(3, 0, 0, 0, 0, 0, 0, 0x0CB5),
    L2(4, 0, 0, 0, 0, 0, 0, 0x0CB6),
    L2(4, 0, 0, 0, 0, 0, 0, 0x0CB7),
    L2(4, 0, 0, 0, 0, 0, 0, 0x0D99),
    L2(4, 0, 0, 0, 0, 0, 0, 0x0D9A),
    L2(250, 255, 0, 0, 0, 0, 0, 0x0D9A),
    CMD(CM_ROA, 0, 0, 0),
};
