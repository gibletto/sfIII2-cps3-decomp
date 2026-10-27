/*
 * EFFE5_TBL.C  after-image setup table
 *
 * illusion_setup_table gives { who, parameter set } pairs for setup_after_images (0 this
 * player, 1 the opponent, other both); the parameter sets are in after_image_data. Read by
 * EFFE5.C, the after-image controller.
 */

#include "types.h"
#include "structs.h"

#pragma section TBL

extern const s16 illusion_setup_table[][2];

const s16 illusion_setup_table[13][2] = {
    { 0, 0 },
    { 2, 0 },
    { 0, 4 },
    { 0, 5 },
    { 0, 2 },
    { 1, 3 },
    { 0, 11 },
    { 0, 12 },
    { 0, 13 },
    { 0, 14 },
    { 0, 15 },
    { 0, 17 },
    { 0, 18 },
};
