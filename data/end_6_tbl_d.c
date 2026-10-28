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
    { 0x2080, 5 },
    { 0x20C0, 6 },
};

/* provisional name */
const s16 timer_6_tbl[4] = {
    420, 780, 660, 720,
};

/* provisional name */
const s16 end_6_pos[4][2] = {
    { 256, 256 }, { 768, 256 }, { 256, 0 }, { 768, 0 },
};
