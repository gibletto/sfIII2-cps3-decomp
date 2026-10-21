/*
 * WIN_PL_TBL.C  tables read by win_pl.c: round winner poses
 */

#include "types.h"
#include "structs.h"

#pragma section TBL

extern const s16 win_type_tbl[];

const s16 win_type_tbl[20] = {
    6, 0, 0, 6, 2, 7, 9, 3,
    4, 1, 0, 0, 5, 6, 8, 8,
    0, 0, 0, -1,
};
