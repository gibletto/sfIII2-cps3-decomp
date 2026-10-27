/*
 * EFFD4_TBL.C  suction pull speeds and thrown rose tables
 *
 * swallow_speeds gives the pull speed of each speed number, read by EFFD4.C, the suction pull
 * of an attack. range_time_table gives the flight time of the rose by distance to the
 * opponent, and dm_sp_sel_tbl the petal set and petal acceleration by the strength of the
 * attack that hits it; read by EFFD5.C, the thrown rose.
 */

#include "types.h"
#include "structs.h"

#pragma section TBL

extern const s32 swallow_speeds[];
extern const s16 dm_sp_sel_tbl[][2];
extern const s16 range_time_table[][1];

const s32 swallow_speeds[16] = {
    0, 32768, 65536, 98304,
    131072, 163840, 196608, 229376,
    262144, 294912, 327680, 360448,
    393216, 425984, 458752, 491520,
};

/* provisional name */
/*
 * Read as two s16 entries per attack strength (dm_kind_of_waza): petal set (num_of_hana) and
 * petal acceleration.
 */
const s16 dm_sp_sel_tbl[4][2] = {
    { 0, 14 }, { 1, 16 }, { 2, 18 }, { 3, 20 },
};

const s16 range_time_table[16][1] = {
    { 32 }, { 34 }, { 36 }, { 38 }, { 40 }, { 42 }, { 44 }, { 46 },
    { 48 }, { 50 }, { 52 }, { 54 }, { 56 }, { 58 }, { 60 }, { 62 },
};
