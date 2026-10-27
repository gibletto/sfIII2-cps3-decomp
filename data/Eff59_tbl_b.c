/*
 * EFF59_TBL_B.C  flashing stage object records of effect 60
 *
 * flash_obj_data61_0 and flash_obj_data61_1 are the records of the two flashing stage objects
 * of effect 60, reached through flash_obj_data61. Read by EFF59.C.
 */

#include "types.h"
#include "structs.h"

#pragma section TBL

extern const s16 flash_obj_data61_0[];
extern const s16 flash_obj_data61_1[];

const s16 flash_obj_data61_0[9] = {
    1, 2, 8256, 272, 96, 86, 61, 1,
    0,
};

const s16 flash_obj_data61_1[9] = {
    1, 2, 8256, 304, 48, 76, 32, 1,
    0,
};
