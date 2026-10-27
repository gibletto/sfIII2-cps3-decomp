/*
 * SC_TRANS_TBL2.C  text layer win mark, stun mark and combo message tables
 *
 * vmark_tbl gives the cell positions of each player's round win marks (win_mark_put,
 * win_mark_find_put); smark_pos_tbl and smark_kind_tbl give the stun mark's position by
 * character, side and screen mode and its size by character (stun_mark_put); combo_mtbl holds
 * the frame cells and size of each combo message, combo_mpos_tbl, combo_mclr_pos_tbl and
 * combo_hitpos_tbl its columns, clearing column and hit count column by message kind and side,
 * and combo_erase_pos_tbl and combo_erase_len_tbl the area cleared by combo_window_erase;
 * sa_color_data_tbl is the colours of the super art stock number (sa_stock_trans). Read by
 * SC_TRANS.C.
 */

#include "types.h"
#include "structs.h"

#pragma section TBL

extern const s16 vmark_tbl[];
extern const s16 smark_pos_tbl[][2][2];
extern const u16 smark_kind_tbl[];
extern const CMB_FRAME combo_mtbl[];
extern const s16 combo_mpos_tbl[][2];
extern const s16 combo_mclr_pos_tbl[][2];
extern const s16 combo_hitpos_tbl[][2];
extern const u16 combo_erase_pos_tbl[][8][2];
extern const u16 combo_erase_len_tbl[];
extern const u16 sa_color_data_tbl[];

const s16 vmark_tbl[48] = {
    19, 4, 16, 20, 4, 17, 17, 4,
    18, 18, 4, 19, 15, 4, 20, 16,
    4, 21, 13, 4, 22, 14, 4, 23,
    27, 4, 24, 28, 4, 25, 29, 4,
    26, 30, 4, 27, 31, 4, 28, 32,
    4, 29, 33, 4, 30, 34, 4, 31,
};

const s16 smark_pos_tbl[16][2][2] = {
    { { 14, 21 }, { 29, 36 } },  /* Gill */
    { { 14, 21 }, { 29, 36 } },  /* Alex */
    { { 15, 22 }, { 29, 36 } },  /* Ryu */
    { { 15, 22 }, { 29, 36 } },  /* Yun */
    { { 14, 21 }, { 29, 36 } },  /* Dudley */
    { { 15, 22 }, { 29, 36 } },  /* Necro */
    { { 14, 21 }, { 29, 36 } },  /* Hugo */
    { { 15, 22 }, { 29, 36 } },  /* Ibuki */
    { { 15, 22 }, { 29, 36 } },  /* Elena */
    { { 14, 21 }, { 29, 36 } },  /* Oro */
    { { 15, 22 }, { 29, 36 } },  /* Yang */
    { { 15, 22 }, { 29, 36 } },  /* Ken */
    { { 15, 22 }, { 29, 36 } },  /* Sean */
    { { 15, 22 }, { 29, 36 } },  /* Urien */
    { { 15, 22 }, { 28, 35 } },  /* Gouki */
    { { 15, 22 }, { 28, 35 } },  /* Shin Gouki */
};

const u16 smark_kind_tbl[16] = {
    1, 1, 0, 0, 1, 0, 1, 0,
    0, 1, 0, 0, 0, 0, 1, 1,
};

const CMB_FRAME combo_mtbl[7] = {
    { { 2822, 8, 2 } }, { { 2848, 12, 2 } },
    { { 2880, 16, 2 } }, { { 2912, 15, 2 } },
    { { 2944, 11, 2 } }, { { 2976, 9, 2 } },
    { { 3008, 11, 2 } },
};

const s16 combo_mpos_tbl[7][2] = {
    { 3, 12 }, { 3, 8 }, { 3, 4 }, { 0, 5 },
    { 0, 9 }, { 0, 11 }, { 0, 9 },
};

const s16 combo_mclr_pos_tbl[7][2] = {
    { 11, 8 }, { 15, 4 }, { 19, 0 }, { 15, 4 },
    { 11, 8 }, { 9, 10 }, { 11, 8 },
};

const s16 combo_hitpos_tbl[3][2] = {
    { 0, 9 }, { 0, 5 }, { 0, 1 },
};

const u16 combo_erase_pos_tbl[2][8][2] = {
    { { 36, 1 }, { 31, 1 }, { 28, 1 }, { 32, 1 }, { 36, 1 }, { 38, 1 }, { 36, 1 }, { 36, 1 } },
    { { 50, 1 }, { 45, 1 }, { 42, 1 }, { 46, 1 }, { 50, 1 }, { 52, 1 }, { 50, 1 }, { 48, 1 } },
};

const u16 combo_erase_len_tbl[11] = {
    11, 16, 19, 15, 11, 9, 11, 11,
    34, 34, 36,
};

const u16 sa_color_data_tbl[4] = {
    10, 8, 60, 0xFFFF,
};
