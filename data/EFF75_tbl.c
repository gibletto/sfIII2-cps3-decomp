/*
 * EFF75_TBL.C  tables read by effects 75 and 77
 */

#include "types.h"
#include "structs.h"

#pragma section TBL

extern const s32 eff75_speed_tbl[][4];
extern const s16 eff77_data_tbl[][3];

const s32 eff75_speed_tbl[6][4] = {
    { -2621440, 163840, 524288, -32768 },
    { 131072, 0, 1703936, -106496 },
    { 2621440, -163840, 524288, -32768 },
    { -2621440, 163840, -524288, 32768 },
    { -131072, 0, -1703936, 106496 },
    { 2621440, -163840, -524288, 32768 },
};

const s16 eff77_data_tbl[3][3] = {
    { 64, 256, 256 },
    { 2, 768, 256 },
    { 1, 256, 0 },
};
