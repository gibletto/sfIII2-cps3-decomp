/*
 * EFFC0_TBL.C  tables read by effects C0 and C2
 */

#include "types.h"
#include "structs.h"

#pragma section TBL

extern const s16 hok_table_ef[];
extern const s16 plhos_data[][3];
extern const s16 effc2_data_tbl[][4];

const s16 hok_table_ef[8] = {
    1, 1, 2, 2, 3, 3, 3, 3,
};

const s16 plhos_data[16][3] = {
    { 2, 136, 4 },
    { 40, 92, 3 },
    { -4, 104, 2 },
    { 2, 92, 5 },
    { 40, 88, 5 },
    { 8, 94, 2 },
    { 8, 106, 2 },
    { 20, 78, 2 },
    { 30, 96, 2 },
    { 10, 88, 3 },
    { 2, 92, 5 },
    { -4, 104, 2 },
    { -4, 104, 5 },
    { 2, 136, 4 },
    { -4, 104, 2 },
    { -4, 104, 2 },
};

/* provisional name */
const s16 effc2_data_tbl[4][4] = {
    { 784, 32, 20, 8 },
    { 720, 64, 77, 9 },
    { 240, 32, 20, 10 },
    { 304, 64, 77, 11 },
};
