/*
 * PLPATUNI_TBL.C  leaping move control rows
 *
 * ahj_kop gives the control row of each leaping move, stepped by att_ahj_table_reader with the
 * target points of ahj_empos_hos. Read by PLPATUNI.C, the shared special-move routines.
 */

#include "types.h"
#include "structs.h"

#pragma section TBL

extern const s16 ahj_kop[][4];

const s16 ahj_kop[5][4] = {
    { 0, 28, 2, 2 },
    { 0, 22, 0, 2 },
    { 0, 23, 0, 2 },
    { 0, 24, 0, 2 },
    { 0, 27, 0, 2 },
};
