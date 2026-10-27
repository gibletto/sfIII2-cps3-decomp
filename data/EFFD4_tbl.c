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
extern const s32 dm_sp_sel_tbl[];
extern const s32 range_time_table[];

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
const s32 dm_sp_sel_tbl[4] = {
    14, 65552, 131090, 196628,
};

const s32 range_time_table[8] = {
    2097186, 2359334, 2621482, 2883630,
    3145778, 3407926, 3670074, 3932222,
};
