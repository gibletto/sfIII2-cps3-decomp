/*
 * ABOUTSPR_TBL_B.C  shadow width table
 *
 * kage_width_tbl is the width of a character's shadow by height above the ground (in steps of
 * four dots), returned by get_kage_width in ABOUTSPR.C.
 */

#include "types.h"
#include "structs.h"

#pragma section TBL

extern const s16 kage_width_tbl[];

const s16 kage_width_tbl[60] = {
    0, 1, 2, 3, 4, 4, 5, 5,
    5, 6, 6, 6, 7, 7, 7, 7,
    8, 8, 8, 8, 9, 9, 9, 9,
    10, 10, 10, 10, 10, 11, 11, 11,
    11, 11, 11, 12, 12, 12, 12, 12,
    12, 12, 13, 13, 13, 13, 13, 13,
    13, 14, 14, 14, 14, 14, 14, 14,
    15, 15, 15, 15,
};
