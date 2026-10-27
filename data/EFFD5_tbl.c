/*
 * EFFD5_TBL.C  thrown rose launch heights
 *
 * range_isp_table gives the initial height speed of the rose by distance to the opponent. Read
 * by EFFD5.C, the thrown rose.
 */

#include "types.h"
#include "structs.h"

#pragma section TBL

extern const s16 range_isp_table[];

const s16 range_isp_table[16] = {
    2, 2, 3, 3, 3, 3, 4, 4,
    4, 4, 4, 5, 5, 5, 5, 5,
};
