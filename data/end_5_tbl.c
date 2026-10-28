/*
 * END_5_TBL.C  Necro's ending cell list (ending 5)
 *
 * end_500_bg0_cell_tbl lists the BG0 cells (map offset, cell number) written at the start of
 * Necro's ending. Read by END_5.C.
 */

#include "types.h"
#include "structs.h"

#pragma section TBL

extern const PANEL end_500_bg0_cell_tbl[];

/* provisional name */
const PANEL end_500_bg0_cell_tbl[4] = {
    { 0, 9 }, { 0x40, 10 }, { 0x80, 13 }, { 0xC0, 14 },
};
