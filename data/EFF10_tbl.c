/*
 * EFF10_TBL.C  character scene objects and bg000 flying objects
 *
 * scr_obj_num10 gives the number of objects of each of the four types, and scr_obj_data10_N the
 * rows of type N (x offset from the owner, y position, animation number), named by
 * scr_obj_data10; read by EFF10.C, the character scene objects. eff11_data_tbl gives the
 * position, priority, pattern and delay of each of the four objects that fly off at the start
 * on bg000, and eff11_speed_tbl their speeds; read by EFF11.C.
 */

#include "types.h"
#include "structs.h"

#pragma section TBL

extern const s16 scr_obj_num10[];
extern const s16 scr_obj_data10_0[];
extern const s16 scr_obj_data10_1[];
extern const s16 scr_obj_data10_2[];
extern const s16 scr_obj_data10_3[];
extern const s16 eff11_data_tbl[][5];
extern const s32 eff11_speed_tbl[][4];

const s16 scr_obj_num10[4] = {
    4, 3, 1, 0,
};

/* type 0; provisional name */
const s16 scr_obj_data10_0[12] = {
    -64, 100, 8,
    -71, 42, 9,
    26, 96, 10,
    70, 26, 11,
};

/* type 1; provisional name */
const s16 scr_obj_data10_1[9] = {
    16, 100, 10,
    -80, 48, 9,
    70, 26, 11,
};

/* type 2; provisional name */
const s16 scr_obj_data10_2[3] = {
    -61, 50, 12,
};

/* type 3 with no objects; provisional name */
const s16 scr_obj_data10_3[2] = {
    0, -1,
};

const s16 eff11_data_tbl[4][5] = {
    { 896, 576, 85, 0, 10 },
    { 928, 384, 86, 1, 20 },
    { 848, 544, 86, 2, 32 },
    { 896, 448, 88, 2, 48 },
};

const s32 eff11_speed_tbl[4][4] = {
    { -0x88000, 0, -0x60000, -0xC00 },
    { -0x48000, 0, -0x30000, -0xA00 },
    { -0x80000, 0, -0x30000, -0xC00 },
    { -0x60000, 0, -0x18000, -0xF00 },
};
