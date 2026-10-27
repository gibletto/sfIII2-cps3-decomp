/*
 * END_1_TBL.C  Alex's ending tables (ending 1)
 *
 * end_100_panel0 and end_100_panel1 list the BG cells (map offset, cell number) written by
 * end_100_cell_set at the start of the ending, timer_1_tbl is the length in frames of each of
 * its eight scenes and end_1_pos the BG x and y of each scene. Read by END_1.C.
 */

#include "types.h"
#include "structs.h"

#pragma section TBL

extern const PANEL end_100_panel0[];
extern const PANEL end_100_panel1[];
extern const u16 timer_1_tbl[];
extern const u16 end_1_pos[];

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
const u16 timer_1_tbl[8] = {
    0x474, 0xF0, 0xF0, 0xF0, 0xF0, 0x1E0, 0x1E0, 0x258,
};

/* provisional name */
const u16 end_1_pos[16] = {
    0x100, 0x100, 0x150, 0x100, 0x100, 0x100, 0x300, 0x100,
    0x300, 0x100, 0x300, 0x100, 0x100, 0, 0x300, 0,
};

