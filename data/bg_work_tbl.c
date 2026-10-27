/*
 * BG_WORK_TBL.C  background layer 0 cell list
 *
 * end_1100_bg0_cell_tbl is a cell list (map offset, cell number) for background layer 0,
 * reached through bg_rewrite_cell_tbl in BG_WORK.C and written by bg_scr_write in BG000.C.
 */

#include "types.h"
#include "structs.h"

#pragma section TBL

extern const PANEL end_1100_bg0_cell_tbl[];

const PANEL end_1100_bg0_cell_tbl[8] = {
    { 8192, 1 },
    { 8256, 2 },
    { 8320, 3 },
    { 8384, 4 },
    { 12288, 5 },
    { 12352, 6 },
    { 12416, 7 },
    { 12480, 8 },
};
