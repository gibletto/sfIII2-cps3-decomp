/*
 * EFF47_TBL.C  scattering piece and opening scene object tables
 *
 * eff47_data_tbl gives the offset from the character and the life time of each of the four
 * pieces, and eff47_sp_tbl their speeds and accelerations; read by EFF47.C, the four
 * scattering pieces. eff48_data_tbl holds the rows of each type of opening scene object, read
 * by EFF48.C.
 */

#include "types.h"
#include "structs.h"

#pragma section TBL

extern const s32 eff47_sp_tbl[][4];
extern const s16 eff47_data_tbl[];
extern const s16 eff48_data_tbl[][5][6];

const s32 eff47_sp_tbl[4][4] = {
    { 0x40000, -0x1000, 0x30000, -0x4000 },
    { -0x20000, 0x800, 0x30000, -0x4000 },
    { 0x10000, 0, 0x20000, -0x4000 },
    { -0x50000, 0x1000, 0x40000, -0x4000 },
};

const s16 eff47_data_tbl[12] = {
    16, 144, 50, -68, 122, 50, 24, 48,
    30, -37, 70, 30,
};

const s16 eff48_data_tbl[6][5][6] = {
    { { 1, 76, 1, 16, 30, 0 }, { 1, 76, 2, 18, 30, 0 }, { 1, 76, 3, 20, 30, 0 }, { 1, 76, 4, 22, 30, 0 }, { 1, 76, 5, 24, 30, 0 } },
    { { 1, 77, 1, 0, 30, 2 }, { 1, 77, 2, 2, 30, 2 }, { 1, 77, 3, 4, 30, 2 }, { 1, 77, 4, 6, 30, 2 }, { 1, 77, 5, 8, 30, 2 } },
    { { 1, 78, 1, 0, 16, 4 }, { 1, 78, 2, 2, 30, 4 }, { 1, 78, 3, 4, 30, 4 }, { 1, 78, 4, 6, 30, 4 }, { 1, 78, 5, 8, 30, 4 } },
    { { 1, 79, 1, 0, 30, 6 }, { 1, 79, 2, 2, 30, 6 }, { 1, 79, 3, 4, 30, 6 }, { 1, 79, 4, 6, 30, 6 }, { 1, 79, 5, 8, 30, 6 } },
    { { 1, 97, 1, 0, 30, 6 }, { 1, 97, 2, 2, 30, 6 }, { 1, 97, 3, 4, 30, 6 }, { 1, 97, 4, 6, 30, 6 }, { 1, 97, 5, 8, 30, 6 } },
    { { 1, 98, 1, 0, 30, 6 }, { 1, 98, 2, 2, 30, 6 }, { 1, 98, 3, 4, 30, 6 }, { 1, 98, 4, 6, 30, 6 }, { 1, 98, 5, 8, 30, 6 } },
};
