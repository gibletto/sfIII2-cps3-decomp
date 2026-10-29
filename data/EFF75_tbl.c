/*
 * EFF75_TBL.C  select-screen object fly-off speeds and full-screen background positions
 *
 * eff75_speed_tbl gives the x and y speeds and accelerations with which the select-screen
 * object flies off, by its current pattern; read by EFF75_ORDER.C. eff77_data_tbl gives the
 * time and the BG layer 3 position of each temporary full-screen background; read by EFF77.C.
 */

#include "types.h"
#include "structs.h"

#pragma section TBL

extern const s32 eff75_speed_tbl[][4];
extern const s16 eff77_data_tbl[][3];

const s32 eff75_speed_tbl[6][4] = {
    { -0x280000, 0x28000, 0x80000, -0x8000 },
    { 0x20000, 0, 0x1A0000, -0x1A000 },
    { 0x280000, -0x28000, 0x80000, -0x8000 },
    { -0x280000, 0x28000, -0x80000, 0x8000 },
    { -0x20000, 0, -0x1A0000, 0x1A000 },
    { 0x280000, -0x28000, -0x80000, 0x8000 },
};

const s16 eff77_data_tbl[3][3] = {
    { 64, 256, 256 },
    { 2, 768, 256 },
    { 1, 256, 0 },
};
