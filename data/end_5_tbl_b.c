/*
 * END_5_TBL_B.C  tables read by end_5.c: ending 5 (end_05000), 2nd Impact version
 */

#include "types.h"
#include "structs.h"

#pragma section TBL

extern const PANEL end_2000_bg0_cell_tbl[];
extern const PANEL end_2000_ake_cell_tbl[];
extern const u32 end_500_bg1_cell_tbl[];
extern const u16 timer_5_tbl[];
extern const u16 end_5_tbl_06165574[];
extern const u16 end_5_pos[];

const PANEL end_2000_bg0_cell_tbl[4] = {
    { 4224, 1 },
    { 4288, 2 },
    { 8192, 3 },
    { 8256, 4 },
};

const PANEL end_2000_ake_cell_tbl[4] = {
    { 12288, 5 },
    { 12352, 6 },
    { 12416, 5 },
    { 12480, 6 },
};

/* provisional name */
const u32 end_500_bg1_cell_tbl[16] = {
    0x80, 0xB, 0xC0, 0xC,
    0x1000, 0xF, 0x1040, 0x10,
    0x2000, 1, 0x2040, 2,
    0x3000, 7, 0x3040, 8,
};

/* provisional name */
const u16 timer_5_tbl[4] = {
    0x12C, 0x258, 0x168, 0x30C,
};

/* provisional name */
const u16 end_5_tbl_06165574[2] = {
    0x96, 0x3FC,
};

/* provisional name */
const u16 end_5_pos[12] = {
    0x100, 0x300, 0x300, 0x300, 0x100, 0x200, 0x300, 0x200,
    0x100, 0x100, 0x100, 0,
};
