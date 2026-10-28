/*
 * END_12_TBL_B.C  Urien's ending tables (ending 12)
 *
 * end_1200_panel1 is the second cell list written at the start of the ending, timer_12_tbl the
 * length in frames of each scene and end_12_pos the BG x and y of each scene. Read by
 * END_12.C.
 */

#include "types.h"
#include "structs.h"

#pragma section TBL

extern const PANEL end_1200_panel1[];
extern const s16 timer_12_tbl[];
extern const s16 end_12_pos[][2];

const PANEL end_1200_panel1[8] = {
    { 0x2000, 0 },
    { 0x2040, 0 },
    { 0x2080, 3 },
    { 0x20C0, 4 },
    { 0x3000, 7 },
    { 0x3040, 8 },
    { 0x3080, 0 },
    { 0x30C0, 0 },
};

const s16 timer_12_tbl[4] = {
    600, 420, 900, 1020,
};

/* provisional name */
const s16 end_12_pos[4][2] = {
    { 0x100, 0x100 }, { 0x300, 0x100 }, { 0x100, 0 }, { 0x300, 0 },
};
