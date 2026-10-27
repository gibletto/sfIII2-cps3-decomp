/*
 * EFFB4_TBL.C  ball hit spark patterns
 *
 * s_mark_tbl gives the pattern added to the spark's animation, picked at random. Read by
 * EFFB4.C, the ball hit spark.
 */

#include "types.h"
#include "structs.h"

#pragma section TBL

extern const s16 s_mark_tbl[];

const s16 s_mark_tbl[32] = {
    0, 1, 0, 1, 0, 3, 0, 0,
    0, 2, 4, 0, 0, 1, 0, 2,
    6, 3, 0, 2, 0, 0, 6, 3,
    0, 4, 0, 0, 6, 0, 0, 4,
};
