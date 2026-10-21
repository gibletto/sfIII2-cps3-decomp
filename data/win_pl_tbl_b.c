/*
 * WIN_PL_TBL_B.C  tables read by lose_pl.c and win_pl.c
 */

#include "types.h"
#include "structs.h"

#pragma section TBL

extern const s16 win_10000_tbl[][8];
extern const s16 win_2000_tbl[];
extern const s16 Win_3000_tbl[];
extern const s8 Win_3001_tbl[];
extern const s16 win_pl_unref_words[];
extern const s16 lose_type_tbl[];

const s16 win_10000_tbl[2][8] = {
    { 32, 33, 34, 32, 36, 37, 38, 33 },
    { 35, 39, 34, 35, 36, 37, 38, 39 },
};

const s16 win_2000_tbl[18] = {
    1, 1, 1, 1, 1, 0, 0, 1,
    1, 1, 0, 0, 1, 1, 1, 1,
    1, 1,
};

const s16 Win_3000_tbl[8] = {
    32, 34, 33, 35, 32, 34, 32, 35,
};

const s8 Win_3001_tbl[8] = {
    36, 37, 36, 39, 36, 38, 39, 37,
};

const s16 win_pl_unref_words[4] = {
    532, 373, 530, 531,
};

const s16 lose_type_tbl[20] = {
    0, 0, 0, 0, 0, 2, 0, 0,
    1, 0, 0, 0, 0, 3, 0, 0,
    0, 0, 0, -1,
};
