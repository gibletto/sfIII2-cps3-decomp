/*
 * EFF93_DATA.C  win screen character colours, Akuma palette swap and an ending record
 *
 * eff95_col_tbl_win and eff95_col_tbl_lose give the colour of each character on the win screen
 * as winner and loser, and eff95_ofs_tbl its offsets; read by EFF95.C, the win and ranking
 * screen characters. effA0_swap_tbl picks Akuma's palette from the opponent's colour so that
 * the two differ (EFFA0.C, Akuma's entrance). effb0_scr_record_data is the BG3 sprite list
 * record set up by an ending's scene changes (EFFB0.C).
 */

#include "types.h"
#include "structs.h"

#pragma section TBL

extern const s8 eff95_col_tbl_win[];
extern const s8 eff95_col_tbl_lose[];
extern const s16 eff95_ofs_tbl[][2];
extern const s8 effA0_swap_tbl[];
extern const s16 effb0_scr_record_data[];

/* provisional name */
const s8 eff95_col_tbl_win[16] = {
    1, 1, 1, 2, 2, 1, 2, 1, 2, 1, 1, 1, 2, 2, 2, 2,
};

/* provisional name */
const s8 eff95_col_tbl_lose[16] = {
    3, 2, 3, 3, 3, 2, 3, 2, 2, 1, 2, 2, 3, 3, 3, 3,
};

/* provisional name */
/* One row per fighter: x offset of the picture when the fighter won, and when it lost. */
const s16 eff95_ofs_tbl[16][2] = {
    { 0, 0 },  /* Gill */
    { 0, 0 },  /* Alex */
    { 0, 0 },  /* Ryu */
    { 0, 0 },  /* Yun */
    { 32, 0 },  /* Dudley */
    { 0, 0 },  /* Necro */
    { 0, 0 },  /* Hugo */
    { 0, 0 },  /* Ibuki */
    { 0, 0 },  /* Elena */
    { 0, 0 },  /* Oro */
    { 32, 0 },  /* Yang */
    { 0, 0 },  /* Ken */
    { 0, 0 },  /* Sean */
    { 0, 0 },  /* Urien */
    { 0, 0 },  /* Gouki */
    { 0, 0 },  /* Shin Gouki */
};

const s8 effA0_swap_tbl[8] = {
    3, 4, 5, 0, 1, 2, 0, -1,
};

/* provisional name */
const s16 effb0_scr_record_data[14] = {
    4, 88, 127, 32512, 60, 255, 32512, 60,
    383, 32512, 60, -1, -1, -1,
};
