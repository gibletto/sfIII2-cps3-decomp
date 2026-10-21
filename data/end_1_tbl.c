/*
 * END_1_TBL.C  tables read by end_1.c: ending 1 (end_01000), 2nd Impact version
 */

#include "types.h"
#include "structs.h"

#pragma section TBL

extern const PANEL end_100_panel0[];
extern const PANEL end_100_panel1[];
extern const u16 timer_1_tbl[];
extern const u16 end_1_tbl_06165250[];
extern const u16 end_1_tbl_0616525A[];
extern const u16 end_1_pos[];
extern const u16 end_1_tbl_06165278[];

const PANEL end_100_panel0[8] = {
    { 8192, 1 },
    { 8256, 2 },
    { 8320, 5 },
    { 8384, 6 },
    { 12288, 7 },
    { 12352, 8 },
    { 12416, 11 },
    { 12480, 12 },
};

const PANEL end_100_panel1[4] = {
    { 8320, 3 },
    { 8384, 4 },
    { 12416, 9 },
    { 12480, 10 },
};

/* provisional name */
const u16 timer_1_tbl[2] = {
    0x474, 0xF0,
};

/* provisional name */
const u16 end_1_tbl_06165250[5] = {
    0xF0, 0xF0, 0xF0, 0x1E0, 0x1E0,
};

/* provisional name */
const u16 end_1_tbl_0616525A[1] = {
    0x258,
};

/* provisional name */
const u16 end_1_pos[14] = {
    0x100, 0x100, 0x150, 0x100, 0x100, 0x100, 0x300, 0x100,
    0x300, 0x100, 0x300, 0x100, 0x100, 0,
};

/* provisional name */
const u16 end_1_tbl_06165278[2] = {
    0x300, 0,
};
