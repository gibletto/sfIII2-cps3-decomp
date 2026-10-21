/*
 * END_8_TBL.C  tables read by end_7.c, end_8.c and end_9.c
 */

#include "types.h"
#include "structs.h"

#pragma section TBL

extern const u16 end_7_anm_tbl[];
extern const PANEL end_800_panel0[];
extern const PANEL end_800_panel1[];
extern const u16 timer_8_tbl[];
extern const u16 end_8_pos[];
extern const u32 end_900_bg0_cell_tbl[];

/* provisional name */
const u16 end_7_anm_tbl[8] = {
    0x4A, 0x4B, 0x4C, 0x4D, 0x4E, 0x4F, 0x50, 0x51,
};

/* provisional name */
const PANEL end_800_panel0[8] = {
    { 4096, 86 },
    { 4160, 87 },
    { 8192, 92 },
    { 8256, 93 },
    { 8320, 96 },
    { 8384, 97 },
    { 12416, 30 },
    { 12480, 31 },
};

/* provisional name */
const PANEL end_800_panel1[8] = {
    { 4096, 94 },
    { 4160, 95 },
    { 8192, 90 },
    { 8256, 91 },
    { 8320, 94 },
    { 8384, 95 },
    { 12416, 98 },
    { 12480, 99 },
};

/* provisional name */
const u16 timer_8_tbl[4] = {
    0x30C, 0x12C, 0x1E0, 0x1E0,
};

/* provisional name */
const u16 end_8_pos[8] = {
    0x100, 0x100, 0x300, 0x100, 0x100, 0x200, 0x300, 0,
};

/* provisional name */
const u32 end_900_bg0_cell_tbl[12] = {
    0x2000, 1, 0x2040, 2,
    0x2080, 3, 0x3000, 4,
    0x3040, 5, 0x3080, 6,
};
