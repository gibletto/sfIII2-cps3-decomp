/*
 * EFFG9_TBL.C  trail particle offsets, bonus level display and ending fly-in objects
 *
 * g9_pos_hos is the 16 random offsets added to a G9 particle's x and y when it appears; a y
 * offset above 1 also puts it behind the characters. Read by EFFG9.C. effh0_nando_tbl is the
 * six-cell bonus-stage level display, by screen mode and facing (EFFH0.C). effh1_data_tbl and
 * effh1_speed_tbl give the settings and speeds of the four ending objects that fly in when the
 * scroll arrives (EFFH1.C).
 */

#include "types.h"
#include "structs.h"

#pragma section TBL

extern const s16 g9_pos_hos[];
extern const CONN effh0_nando_tbl[][6];
extern const s16 effh1_data_tbl[][4];
extern const s32 effh1_speed_tbl[][4];

const s16 g9_pos_hos[16] = {
    0, 1, -1, 2, -2, 0, 3, -3,
    1, -1, 2, -2, 4, 3, 0, 3,
};

const CONN effh0_nando_tbl[4][6] = {
    { { 176, -16, 0, 0xB2E0 }, { 132, -16, 0, 0xB2DF }, { 0, 0, 0, 0 }, { 0, 0, 0, 0 }, { 0, 0, 0, 0 }, { 0, 0, 0, 0 } },
    { { -104, -16, 0, 0xB2E0 }, { -148, -16, 0, 0xB2DF }, { 0, 0, 0, 0 }, { 0, 0, 0, 0 }, { 0, 0, 0, 0 }, { 0, 0, 0, 0 } },
    { { 224, -16, 0, 0xB2E0 }, { 180, -16, 0, 0xB2DF }, { 0, 0, 0, 0 }, { 0, 0, 0, 0 }, { 0, 0, 0, 0 }, { 0, 0, 0, 0 } },
    { { -160, -16, 0, 0xB2E0 }, { -204, -16, 0, 0xB2DF }, { 0, 0, 0, 0 }, { 0, 0, 0, 0 }, { 0, 0, 0, 0 }, { 0, 0, 0, 0 } },
};

const s16 effh1_data_tbl[4][4] = {
    { 1, 296, 160, 72 },
    { 2, 312, 144, 70 },
    { 3, 328, 116, 68 },
    { 4, 360, 80, 66 },
};

const s32 effh1_speed_tbl[4][4] = {
    { 98304, 1024, -65536, 10240 },
    { 163840, 1024, -65536, 10240 },
    { 229376, 2048, -65536, 10752 },
    { 294912, 2048, -65536, 12288 },
};
