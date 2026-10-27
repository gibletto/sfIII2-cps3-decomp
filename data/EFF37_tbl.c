/*
 * EFF37_TBL.C  face panel offsets and select-screen face depths
 *
 * panel_pos_hosei gives the offset of the face panel from its master for each character set
 * and display frame type; read by EFF37.C, the face panel shown with a character. eff38_z_tbl
 * gives the depth of the player's face on the character select screen; read by EFF38.C.
 */

#include "types.h"
#include "structs.h"

#pragma section TBL

extern const s16 panel_pos_hosei[][4][2];
extern const s16 eff38_z_tbl[][2][16];

const s16 panel_pos_hosei[8][4][2] = {
    { { 25, 100 }, { 25, 101 }, { 0, 0 }, { 25, 101 } },
    { { 43, 104 }, { 42, 107 }, { 0, 0 }, { 42, 107 } },
    { { 18, 116 }, { 0, 0 }, { 0, 0 }, { 18, 116 } },
    { { 18, 116 }, { 0, 0 }, { 0, 0 }, { 18, 116 } },
    { { 18, 116 }, { 0, 0 }, { 0, 0 }, { 18, 116 } },
    { { 30, 91 }, { 30, 90 }, { 0, 0 }, { 30, 90 } },
    { { -23, 112 }, { 0, 0 }, { 0, 0 }, { -23, 112 } },
    { { -86, 63 }, { 0, 0 }, { 0, 0 }, { -86, 63 } },
};

/* provisional name */
const s16 eff38_z_tbl[1][2][16] = {
    { { 77, 77, 77, 77, 77, 77, 77, 77, 77, 77, 77, 77, 77, 73, 75, 75 }, { 77, 77, 77, 77, 77, 77, 77, 77, 77, 77, 77, 77, 77, 74, 76, 76 } },
};
