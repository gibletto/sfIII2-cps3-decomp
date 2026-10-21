/*
 * EFF33_TBL.C  tables read by effects 33 and 35
 */

#include "types.h"
#include "structs.h"

#pragma section TBL

extern const s16 WinLoseID[][2];
extern const s16 eff35_data_tbl[][7];

const s16 WinLoseID[2][2] = {
    { 1, 0 },
    { 0, 1 },
};

const s16 eff35_data_tbl[5][7] = {
    { 512, 0, 28, 51, 1, 1, 60 },
    { 512, 0, 28, 51, 2, 1, 60 },
    { 576, 28, 30, 50, 10, 0, 60 },
    { 512, 0, 28, 51, 3, 2, 60 },
    { 512, 0, 28, 51, 4, 2, 60 },
};
