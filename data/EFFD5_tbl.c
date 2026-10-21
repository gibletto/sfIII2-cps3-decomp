/*
 * EFFD5_TBL.C  tables read by effect D5
 */

#include "types.h"
#include "structs.h"

#pragma section TBL

extern const s16 range_isp_table[];

const s16 range_isp_table[16] = {
    2, 2, 3, 3, 3, 3, 4, 4,
    4, 4, 4, 5, 5, 5, 5, 5,
};
