/*
 * EFFD4_TBL.C  tables read by effects D4 and D5
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
const s32 dm_sp_sel_tbl[4] = {
    14, 65552, 131090, 196628,
};

const s32 range_time_table[8] = {
    2097186, 2359334, 2621482, 2883630,
    3145778, 3407926, 3670074, 3932222,
};
