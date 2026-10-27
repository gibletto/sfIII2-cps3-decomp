/*
 * EFF87_TBL.C  stage background object table (effect 87)
 *
 * eff87_loop_tbl gives the number of objects by type and compel flag, and scr_obj_data87_0
 * holds the object rows that scr_obj_data87 in EFF87.C points into. Read by EFF87.C, whose
 * objects are started by the stage 03 and 06 backgrounds.
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

const s16 scr_obj_data87_0[38] = {
    0, 0, 0, 2, 8277, 416, 72, 80,
    28, 0, 0, 0, 2, 8292, 512, 56,
    74, 0, 1, 0, 1, 2, 8288, 389,
    183, 81, 7, 0, 0, 1, 2, 8288,
    704, 49, 81, 15, 1, 0,
};
