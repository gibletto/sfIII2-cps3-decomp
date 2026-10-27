/*
 * APPEAR_TBL_B.C  entrance smoke table
 *
 * smoke_check marks, per background (bg_index), the stages where the Appear_16000 entrance
 * starts with its alternative animation. Read by APPEAR.C.
 */

#include "types.h"
#include "structs.h"

#pragma section TBL

extern const s16 smoke_check[];

const s16 smoke_check[20] = {
    1, 1, 0, 0, 0, 0, 0, 0,
    0, 1, 0, 1, 0, 0, 1, 0,
    0, 0, 0, 0,
};
