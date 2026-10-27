/*
 * END_6_TBL_D.C  Hugo's ending scene tables (ending 6)
 *
 * timer_6_tbl is the length in frames of each scene of Hugo's ending and end_6_pos the BG x
 * and y of each scene; read by END_6.C. end_200_panel1 is not referred to.
 */

#include "types.h"
#include "structs.h"

#pragma section TBL

extern const PANEL end_200_panel1[];
extern const s16 timer_6_tbl[];
extern const s16 end_6_pos[][2];

const PANEL end_200_panel1[2] = {
    { 8320, 5 },
    { 8384, 6 },
};

/* provisional name */
const s16 timer_6_tbl[4] = {
    0x1A4, 0x30C, 0x294, 0x2D0,
};

/* provisional name */
const s16 end_6_pos[4][2] = {
    { 0x100, 0x100 }, { 0x300, 0x100 }, { 0x100, 0 }, { 0x300, 0 },
};
