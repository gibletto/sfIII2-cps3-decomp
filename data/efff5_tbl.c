/*
 * EFFF5_TBL.C  opening demo picture object table (effect F5)
 *
 * efff5_data_tbl has one row per object type: move routine, x, y, priority, animation number
 * and a flag, copied into the object by effect_F5_init. Read by EFFF5.C.
 */

#include "types.h"
#include "structs.h"

#pragma section TBL

extern const s16 efff5_data_tbl[][6];

const s16 efff5_data_tbl[22][6] = {
    { 0, 512, 48, 50, 52, 1 },
    { 0, 512, 48, 50, 54, 1 },
    { 1, 512, 40, 52, 62, 1 },
    { 0, 512, 48, 50, 57, 1 },
    { 2, 512, 64, 78, 58, 1 },
    { 2, 512, 0, 78, 58, 1 },
    { 0, 512, 48, 50, 63, 1 },
    { 0, 512, 48, 50, 64, 1 },
    { 3, 512, 53, 52, 58, 0 },
    { 4, 684, 85, 52, 66, 0 },
    { 5, 512, 48, 50, 52, 1 },
    { 5, 512, 48, 50, 54, 1 },
    { 5, 512, 48, 50, 63, 1 },
    { 5, 512, 48, 50, 64, 1 },
    { 6, 512, 0, 83, 74, 0 },
    { 7, 512, 48, 84, 86, 0 },
    { 8, 512, 72, 40, 93, 0 },
    { 8, 608, 168, 54, 91, 0 },
    { 8, 608, 120, 54, 92, 0 },
    { 9, 224, 72, 54, 93, 0 },
    { 10, 608, 408, 54, 91, 0 },
    { 11, 864, 120, 54, 92, 0 },
};
