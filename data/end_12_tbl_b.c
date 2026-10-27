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
    { 8192, 0 },
    { 8256, 0 },
    { 8320, 3 },
    { 8384, 4 },
    { 12288, 7 },
    { 12352, 8 },
    { 12416, 0 },
    { 12480, 0 },
};

const s16 timer_12_tbl[4] = {
    600, 420, 900, 1020,
};

/* provisional name */
const s16 end_12_pos[4][2] = {
    { 0x100, 0x100 }, { 0x300, 0x100 }, { 0x100, 0 }, { 0x300, 0 },
};
