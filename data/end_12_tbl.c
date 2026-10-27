/*
 * END_12_TBL.C  Urien's ending cell list (ending 12)
 *
 * end_1200_panel0 lists the BG0 cells (map offset, cell number) written at the start of
 * Urien's ending. Read by END_12.C.
 */

#include "types.h"
#include "structs.h"

#pragma section TBL

extern const u32 end_1200_panel0[];

/* provisional name */
const u32 end_1200_panel0[16] = {
    0x2000, 1, 0x2040, 2,
    0x2080, 5, 0x20C0, 6,
    0x3000, 9, 0x3040, 0xA,
    0x3080, 0xB, 0x30C0, 0xC,
};
