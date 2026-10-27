/*
 * EFF10_TBL.C  character scene objects and bg000 flying objects
 *
 * scr_obj_num10 starts with the number of objects of each of the four types, followed by the
 * rows of each type (x offset from the owner, y position, animation number), reached through
 * scr_obj_data10; read by EFF10.C, the character scene objects. eff11_data_tbl gives the
 * position, priority, pattern and delay of each of the four objects that fly off at the start
 * on bg000, and eff11_speed_tbl their speeds; read by EFF11.C.
 */

#include "types.h"
#include "structs.h"

#pragma section TBL

extern const s16 scr_obj_num10[];
extern const s16 eff11_data_tbl[][5];
extern const s32 eff11_speed_tbl[][4];

const s16 scr_obj_num10[30] = {
    4, 3, 1, 0, -64, 100, 8, -71,
    42, 9, 26, 96, 10, 70, 26, 11,
    16, 100, 10, -80, 48, 9, 70, 26,
    11, -61, 50, 12, 0, -1,
};

const s16 eff11_data_tbl[4][5] = {
    { 896, 576, 85, 0, 10 },
    { 928, 384, 86, 1, 20 },
    { 848, 544, 86, 2, 32 },
    { 896, 448, 88, 2, 48 },
};

const s32 eff11_speed_tbl[4][4] = {
    { -557056, 0, -393216, -3072 },
    { -294912, 0, -196608, -2560 },
    { -524288, 0, -196608, -3072 },
    { -393216, 0, -98304, -3840 },
};
