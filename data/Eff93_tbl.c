/*
 * EFF93_TBL.C  tables read by effects 88 and 90
 */

#include "types.h"
#include "structs.h"

#pragma section TBL

extern const s16 scr_obj_data87_0_06179F44[];
extern const s16 eff88_loop_tbl[][4];
extern const s16 scr_obj_data88_0[];
extern const u16 eff90_pos_y_tbl[];

/* provisional name */
const s16 scr_obj_data87_0_06179F44[2] = {
    1, 0,
};

const s16 eff88_loop_tbl[20][4] = {
    { 3, 3, 3, 3 },
    { 1, 0, 1, 1 },
    { 1, 2, 8288, 265 },
    { 89, 80, 6, 0 },
    { 0, 1, 2, 8288 },
    { 327, 88, 81, 8 },
    { 0, 0, 1, 2 },
    { 8288, 272, 80, 72 },
    { 9, 0, 0, 1 },
    { 2, 8288, 352, 56 },
    { 71, 16, 1, 0 },
    { 1, 2, 8288, 265 },
    { 89, 80, 6, 0 },
    { 0, 1, 2, 8288 },
    { 327, 88, 81, 8 },
    { 0, 0, 1, 2 },
    { 8288, 319, 65, 71 },
    { 11, 1, 0, 1 },
    { 2, 8288, 319, 65 },
    { 71, 11, 1, 0 },
};

/* provisional name */
const s16 scr_obj_data88_0[36] = {
    0, 2, 64, 79, 129, 82, 0, 0,
    1, 0, 2, 64, 208, 65, 82, 6,
    0, 1, 0, 2, 64, -96, 112, 82,
    7, 0, 1, 1, 2, 8256, 256, 53,
    79, 10, 0, -1,
};

const u16 eff90_pos_y_tbl[10] = {
    0, 0x20, 0x40, 0x60, 0x80, 0xA0, 0xC0, 0xE0,
    0x100, 0xFFFF,
};
