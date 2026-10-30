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
extern const s16 scr_obj_data87_1_0[];
extern const s16 scr_obj_data87_2_0[];
extern const s16 scr_obj_data87_3_0[];
extern const s16 scr_obj_data87_4_0[];

const s16 eff87_loop_tbl[4][4] = {
    { 0, 0, 0, 0 },
    { 0, 0, 0, 0 },
    { 1, 1, 1, 1 },
    { 1, 1, 0, 0 },
};

/* type/compel flag 0/0, 0/1, 0/2, 0/3 with no objects; provisional name */
const s16 scr_obj_data87_0[1] = {
    0,
};

/* type/compel flag 1/0, 1/1, 1/2, 1/3 with no objects; provisional name */
const s16 scr_obj_data87_1_0[1] = {
    0,
};

/* type/compel flag 2/0, 2/1, 2/2, 2/3; provisional name */
const s16 scr_obj_data87_2_0[9] = {
    0, 2, 8277, 416, 72, 80, 28, 0, 0,
};

/* type/compel flag 3/0, 3/1; 3/2, 3/3 with no objects; provisional name */
const s16 scr_obj_data87_3_0[9] = {
    0, 2, 8292, 512, 56, 74, 0, 1, 0,
};

/* type 4, which eff87_loop_tbl has no counts for; provisional name */
const s16 scr_obj_data87_4_0[18] = {
    1, 2, 8288, 389, 183, 81, 7, 0, 0,
    1, 2, 8288, 704, 49, 81, 15, 1, 0,
};
