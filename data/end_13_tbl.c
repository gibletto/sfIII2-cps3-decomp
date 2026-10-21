/*
 * END_13_TBL.C  tables read by end_13.c: ending 13, 2nd Impact version
 */

#include "types.h"
#include "structs.h"

#pragma section TBL

extern const u32 end_1300_panel0[];
extern const u32 end_1300_panel1[];
extern const u16 timer_13_tbl[];
extern const u16 end_13_tbl_06165D16[];
extern const u16 end_13_pos[];

/* provisional name */
const u32 end_1300_panel0[16] = {
    0x2000, 1, 0x2040, 2,
    0x2080, 3, 0x20C0, 4,
    0x3000, 7, 0x3040, 8,
    0x3080, 5, 0x30C0, 6,
};

/* provisional name */
const u32 end_1300_panel1[16] = {
    0x2000, 0, 0x2040, 0,
    0x2080, 0, 0x20C0, 0,
    0x3000, 9, 0x3040, 0xA,
    0x3080, 0, 0x30C0, 0,
};

/* provisional name */
const u16 timer_13_tbl[7] = {
    0x168, 0x1A4, 0xF0, 0xB4, 0x78, 0x3C, 0x3C,
};

/* provisional name */
const u16 end_13_tbl_06165D16[2] = {
    0x1A4, 0x258,
};

/* provisional name */
const u16 end_13_pos[19] = {
    0x100, 0x100, 0x300, 0x100, 0x100, 0, 0x300, 0,
    0x100, 0x100, 0x100, 0x100, 0x100, 0x100, 0x100, 0x100,
    0x300, 0x100, 0xFFFF,
};
