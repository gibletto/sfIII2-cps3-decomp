/*
 * EFF93_TBL.C  stage background object counts and BG1 display positions
 *
 * eff88_loop_tbl gives the number of effect 88 background objects to spawn by type and compel
 * flag, and scr_obj_data88_0 their records, reached through scr_obj_data88; read by EFF88.C.
 * eff90_pos_y_tbl gives the y positions of the nine parts of the BG1 display object; read by
 * EFF90.C.
 */

#include "types.h"
#include "structs.h"

#pragma section TBL

extern const s16 eff88_loop_tbl[][4];
extern const s16 scr_obj_data88_0[];
extern const u16 eff90_pos_y_tbl[];

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
    0, 32, 64, 96, 128, 160, 192, 224,
    256, 0xFFFF,
};
