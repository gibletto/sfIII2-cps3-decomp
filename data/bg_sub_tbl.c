/*
 * BG_SUB_TBL.C  background test, zoom and scroll area tables
 *
 * bg_test_stage_tbl is the stage and area of each entry the debug background test steps
 * through; read by TATE00.C. bg_zoom_rate_tbl is the zoom rate for each step of the screen
 * zoom (zoom_ud_check), akebono_scrn_pos_tbl the x and y of the finish screen pages
 * (akebono_scrn_move), and pos_area_tbl maps a player's screen x in the normal mode to an area
 * code for the background scroll choice; read by BG000.C.
 */

#include "types.h"
#include "structs.h"

#pragma section TBL

extern const s8 bg_test_stage_tbl[][2];
extern const u16 bg_zoom_rate_tbl[];
extern const s16 akebono_scrn_pos_tbl[][2];
extern const s16 pos_area_tbl[];

const s8 bg_test_stage_tbl[18][2] = {
    { 0, 0 },
    { 1, 0 },
    { 2, 0 },
    { 2, 1 },
    { 3, 0 },
    { 3, 1 },
    { 4, 0 },
    { 4, 1 },
    { 5, 0 },
    { 6, 0 },
    { 7, 0 },
    { 7, 1 },
    { 7, 2 },
    { 8, 0 },
    { 8, 1 },
    { 9, 0 },
    { 12, 0 },
    { -1, -1 },
};

/* provisional name */
const u16 bg_zoom_rate_tbl[112] = {
    1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 2, 0, 1, 1, 1,
    1, 1, 1, 1, 2, 0, 1, 1,
    1, 1, 1, 0, 2, 1, 1, 1,
    1, 1, 1, 1, 0, 2, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1,
};

/* provisional name */
const s16 akebono_scrn_pos_tbl[4][2] = {
    { 0x100, 0x100 }, { 0x300, 0x100 }, { 0x100, 0 }, { 0x300, 0 },
};

/* provisional name */
const s16 pos_area_tbl[384] = {
    1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    2, 2, 2, 2, 2, 2, 2, 2,
    2, 2, 2, 2, 2, 2, 2, 2,
    2, 2, 2, 2, 2, 2, 2, 2,
    2, 2, 2, 2, 2, 2, 2, 2,
    2, 2, 2, 2, 2, 2, 2, 2,
    2, 2, 2, 2, 2, 2, 2, 2,
    2, 2, 2, 2, 2, 2, 2, 2,
    2, 2, 2, 2, 2, 2, 2, 2,
};
