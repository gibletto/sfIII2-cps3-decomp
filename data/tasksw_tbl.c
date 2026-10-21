/*
 * TASKSW_TBL.C  game tables
 */

#include "types.h"
#include "structs.h"

#pragma section TBL

extern const s16 boot_setting_defaults[];
extern const s16 region_area_tbl[];

const s16 boot_setting_defaults[2] = {
    256, 255,
};

const s16 region_area_tbl[16] = {
    0, 0, 0, 0, 0, 2, 0, 5,
    0, 1, 0, 3, 0, 4, 0, 1,
};
