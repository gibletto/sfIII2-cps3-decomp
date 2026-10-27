/*
 * EFFE9_TBL.C  frame bar sprite table (effect E9)
 *
 * effE9_data rows hold the x, y and animation number of the frame bar sprites: the top and
 * bottom pair, and a second pair added in the wide screen mode. Read by effect_E9_init in
 * EFFE9.C.
 */

#include "types.h"
#include "structs.h"

#pragma section TBL

extern const s16 effE9_data[][3];

const s16 effE9_data[4][3] = {
    { 512, 0, 0 },
    { 512, 208, 1 },
    { 292, 136, 2 },
    { 728, 136, 2 },
};
