/*
 * EFFB4_TBL.C  tables read by effect B4
 */

#include "types.h"
#include "structs.h"

#pragma section TBL

extern const s16 s_mark_tbl[];

const s16 s_mark_tbl[32] = {
    0, 1, 0, 1, 0, 3, 0, 0,
    0, 2, 4, 0, 0, 1, 0, 2,
    6, 3, 0, 2, 0, 0, 6, 3,
    0, 4, 0, 0, 6, 0, 0, 4,
};
