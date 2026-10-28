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
    { 567, 288, 80 }, { 396, 320, 79 },
    { 502, 337, 79 }, { 535, 313, 79 },
};

const s32 eff74_move_tbl[8][6] = {
    { 0, 33, 0, 0, 0, 0 },
    { 1, 32, 294912, 512, 0xFFFF8000, -256 },
    { 2, 36, 0xFFFB8000, -256, 0, -256 },
    { 2, 36, 0xFFF98000, -512, 0, -256 },
    { 1, 32, 491520, 0, 256, 0 },
    { 0, 37, 0, 0, 0, 0 },
    { 1, 32, 491520, 0xFFFD8000, 0, 8192 },
    { 2, 36, 0xFFF88000, 0xFFFB8000, -1024, 12288 },
};
