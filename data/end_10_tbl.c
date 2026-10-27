/*
 * END_10_TBL.C  Ken's ending tables (ending 10) and Sean's ending cells
 *
 * end_10_panel_tbl_0 and end_10_panel_tbl_1 are BG cell lists (map offset, cell number),
 * reached through end_10_panel_p in OP_END_WORK.C; timer_10_tbl is the length in frames of
 * each scene, end_10_pos the BG x and y of each scene and end_10_anm_tbl the steps of a
 * layer's cell animation; all are read by END_10.C. end_1100_cell0 - 7 are the cell pairs of
 * Sean's ending (ending 11), reached through end_11_cell_ptr0 and end_11_cell_ptr1 in
 * OP_END_WORK.C and written by END_11.C.
 */

#include "types.h"
#include "structs.h"

#pragma section TBL

extern const PANEL end_10_panel_tbl_0[];
extern const PANEL end_10_panel_tbl_1[];
extern const u16 timer_10_tbl[];
extern const u16 end_10_pos[];
extern const u16 end_10_anm_tbl[];
extern const s32 end_1100_cell0[];
extern const s32 end_1100_cell1[];
extern const s32 end_1100_cell2[];
extern const s32 end_1100_cell3[];
extern const s32 end_1100_cell4[];
extern const s32 end_1100_cell5[];
extern const s32 end_1100_cell6[];
extern const s32 end_1100_cell7[];

/* provisional name */
const PANEL end_10_panel_tbl_0[16] = {
    { 0, 0x3E },
    { 0x40, 0x3F },
    { 0x80, 0x32 },
    { 0xC0, 0x33 },
    { 0x1000, 0x42 },
    { 0x1040, 0x43 },
    { 0x1080, 0x40 },
    { 0x10C0, 0x41 },
    { 0x2000, 0x44 },
    { 0x2040, 0x45 },
    { 0x2080, 0x48 },
    { 0x20C0, 0x49 },
    { 0x3000, 0x46 },
    { 0x3040, 0x47 },
    { 0x3080, 0x4A },
    { 0x30C0, 0x4B },
};

/* provisional name */
const PANEL end_10_panel_tbl_1[16] = {
    { 0, 0x30 },
    { 0x40, 0x31 },
    { 0x80, 0x30 },
    { 0xC0, 0x31 },
    { 0x1000, 0x34 },
    { 0x1040, 0x35 },
    { 0x1080, 0x36 },
    { 0x10C0, 0x37 },
    { 0x2000, 0x38 },
    { 0x2040, 0x39 },
    { 0x2080, 0x3C },
    { 0x20C0, 0x3D },
    { 0x3000, 0x3A },
    { 0x3040, 0x3B },
    { 0x3080, 0x30 },
    { 0x30C0, 0x31 },
};

/* provisional name */
const u16 timer_10_tbl[7] = {
    0x12C, 0xB4, 0xF0, 0xF0, 0x21C, 0x12C, 0x168,
};

/* provisional name */
const u16 end_10_pos[14] = {
    0x100, 0x300, 0x300, 0x300, 0x100, 0x200, 0x2D0, 0x200,
    0x100, 0x100, 0x2D0, 0x100, 0x300, 0,
};

/* provisional name */
const u16 end_10_anm_tbl[5] = {
    2, 3, 4, 5, 0xFFFF,
};

/* provisional name */
const s32 end_1100_cell0[4] = {
    12352, 5, 12416, 6,
};

/* provisional name */
const s32 end_1100_cell1[4] = {
    12352, 13, 12416, 14,
};

/* provisional name */
const s32 end_1100_cell2[4] = {
    12352, 11, 12416, 12,
};

/* provisional name */
const s32 end_1100_cell3[4] = {
    12352, 7, 12416, 8,
};

/* provisional name */
const s32 end_1100_cell4[4] = {
    12352, 1, 12416, 2,
};

/* provisional name */
const s32 end_1100_cell5[4] = {
    12352, 9, 12416, 10,
};

/* provisional name */
const s32 end_1100_cell6[4] = {
    12352, 5, 12416, 6,
};

/* provisional name */
const s32 end_1100_cell7[4] = {
    12352, 1, 12416, 2,
};
