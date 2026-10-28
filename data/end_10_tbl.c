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
extern const s16 timer_10_tbl[];
extern const s16 end_10_pos[][2];
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
    { 0, 62 },
    { 0x40, 63 },
    { 0x80, 50 },
    { 0xC0, 51 },
    { 0x1000, 66 },
    { 0x1040, 67 },
    { 0x1080, 64 },
    { 0x10C0, 65 },
    { 0x2000, 68 },
    { 0x2040, 69 },
    { 0x2080, 72 },
    { 0x20C0, 73 },
    { 0x3000, 70 },
    { 0x3040, 71 },
    { 0x3080, 74 },
    { 0x30C0, 75 },
};

/* provisional name */
const PANEL end_10_panel_tbl_1[16] = {
    { 0, 48 },
    { 0x40, 49 },
    { 0x80, 48 },
    { 0xC0, 49 },
    { 0x1000, 52 },
    { 0x1040, 53 },
    { 0x1080, 54 },
    { 0x10C0, 55 },
    { 0x2000, 56 },
    { 0x2040, 57 },
    { 0x2080, 60 },
    { 0x20C0, 61 },
    { 0x3000, 58 },
    { 0x3040, 59 },
    { 0x3080, 48 },
    { 0x30C0, 49 },
};

/* provisional name */
const s16 timer_10_tbl[7] = {
    300, 180, 240, 240, 540, 300, 360,
};

/* provisional name */
const s16 end_10_pos[7][2] = {
    { 256, 768 }, { 768, 768 }, { 256, 512 }, { 720, 512 },
    { 256, 256 }, { 720, 256 }, { 768, 0 },
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
