/*
 * EFF74_TBL.C  stage bird tables
 *
 * eff74_data_tbl gives the placement of the four birds on their perches, and eff74_move_tbl
 * the eight flight paths a bird takes off along when a player comes near. Read by EFF74.C, the
 * birds on the stage.
 */

#include "types.h"
#include "structs.h"

#pragma section TBL

extern const s16 eff74_data_tbl[][3];
extern const s32 eff74_move_tbl[][6];

const s16 eff74_data_tbl[4][3] = {
    { 0x237, 0x120, 0x50 }, { 0x18C, 0x140, 0x4F },
    { 0x1F6, 0x151, 0x4F }, { 0x217, 0x139, 0x4F },
};

const s32 eff74_move_tbl[8][6] = {
    { 0, 0x21, 0, 0, 0, 0 },
    { 1, 0x20, 0x48000, 0x200, 0xFFFF8000, -256 },
    { 2, 0x24, 0xFFFB8000, -256, 0, -256 },
    { 2, 0x24, 0xFFF98000, -512, 0, -256 },
    { 1, 0x20, 0x78000, 0, 0x100, 0 },
    { 0, 0x25, 0, 0, 0, 0 },
    { 1, 0x20, 0x78000, 0xFFFD8000, 0, 0x2000 },
    { 2, 0x24, 0xFFF88000, 0xFFFB8000, -1024, 0x3000 },
};
