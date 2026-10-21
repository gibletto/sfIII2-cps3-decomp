/*
 * PLCNT_TBL_B.C  tables read by PLCNTDAT.c: player base data, stun and super-art setup, round resets
 */

#include "types.h"
#include "structs.h"

#pragma section TBL

extern const s16 pl_piyo_tbl[];

const s16 pl_piyo_tbl[16] = {
    72, 72, 64, 64, 72, 64, 72, 64,
    64, 72, 64, 64, 64, 64, 56, 56,
};
