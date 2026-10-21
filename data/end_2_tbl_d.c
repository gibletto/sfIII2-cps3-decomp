/*
 * END_2_TBL_D.C  tables read by end_7.c, end_8.c and end_9.c
 */

#include "types.h"
#include "structs.h"

#pragma section TBL

extern const u16 end_7_anm_tbl[];
extern const u16 timer_8_tbl[];
extern const u16 end_2_tbl_06165896[];
extern const u16 end_8_pos[];
extern const u32 end_900_bg0_cell_tbl[];

/* provisional name */
const u16 end_7_anm_tbl[72] = {
    0x4A, 0x4B, 0x4C, 0x4D, 0x4E, 0x4F, 0x50, 0x51,
    0, 0x1000, 0, 0x56, 0, 0x1040, 0, 0x57,
    0, 0x2000, 0, 0x5C, 0, 0x2040, 0, 0x5D,
    0, 0x2080, 0, 0x60, 0, 0x20C0, 0, 0x61,
    0, 0x3080, 0, 0x1E, 0, 0x30C0, 0, 0x1F,
    0, 0x1000, 0, 0x5E, 0, 0x1040, 0, 0x5F,
    0, 0x2000, 0, 0x5A, 0, 0x2040, 0, 0x5B,
    0, 0x2080, 0, 0x5E, 0, 0x20C0, 0, 0x5F,
    0, 0x3080, 0, 0x62, 0, 0x30C0, 0, 0x63,
};

/* provisional name */
const u16 timer_8_tbl[3] = {
    0x30C, 0x12C, 0x1E0,
};

/* provisional name */
const u16 end_2_tbl_06165896[1] = {
    0x1E0,
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
