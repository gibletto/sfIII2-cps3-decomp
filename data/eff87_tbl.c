/*
 * EFF87_TBL.C  tables read by effect 87
 */

#include "types.h"
#include "structs.h"

#pragma section TBL

extern const s16 eff87_loop_tbl[][4];
extern const s16 scr_obj_data87_0[];

const s16 eff87_loop_tbl[4][4] = {
    { 0, 0, 0, 0 },
    { 0, 0, 0, 0 },
    { 1, 1, 1, 1 },
    { 1, 1, 0, 0 },
};

const s16 scr_obj_data87_0[36] = {
    0, 0, 0, 2, 8277, 416, 72, 80,
    28, 0, 0, 0, 2, 8292, 512, 56,
    74, 0, 1, 0, 1, 2, 8288, 389,
    183, 81, 7, 0, 0, 1, 2, 8288,
    704, 49, 81, 15,
};
