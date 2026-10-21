/*
 * EFF93_DATA.C  tables read by effects 95, A0 and B0
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
const s16 eff95_ofs_tbl[16][2] = {
    { 0, 0 },
    { 0, 0 },
    { 0, 0 },
    { 0, 0 },
    { 32, 0 },
    { 0, 0 },
    { 0, 0 },
    { 0, 0 },
    { 0, 0 },
    { 0, 0 },
    { 32, 0 },
    { 0, 0 },
    { 0, 0 },
    { 0, 0 },
    { 0, 0 },
    { 0, 0 },
};

const s8 effA0_swap_tbl[8] = {
    3, 4, 5, 0, 1, 2, 0, -1,
};

/* provisional name */
const s16 effb0_scr_record_data[14] = {
    4, 88, 127, 32512, 60, 255, 32512, 60,
    383, 32512, 60, -1, -1, -1,
};
