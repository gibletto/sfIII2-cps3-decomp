/*
 * END_6_TBL.C  Hugo's ending BG0 cell list (ending 6)
 *
 * end_600_bg0_cell_tbl lists the BG0 cells (map offset, cell number) written at the start of
 * Hugo's ending. Read by END_6.C.
 */

#include "types.h"
#include "structs.h"

#pragma section TBL

extern const PANEL end_600_bg0_cell_tbl[];

const PANEL end_600_bg0_cell_tbl[8] = {
    { 8192, 7 },
    { 8256, 8 },
    { 8320, 9 },
    { 8384, 10 },
    { 12288, 1 },
    { 12352, 2 },
    { 12416, 3 },
    { 12480, 4 },
};
