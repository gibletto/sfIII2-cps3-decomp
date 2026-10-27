/*
 * PLCNT_TBL_B.C  stun limits
 *
 * pl_piyo_tbl gives each character's stun limit. Read by PLCNTDAT.C, the player base data and
 * stun setup.
 */

#include "types.h"
#include "structs.h"

#pragma section TBL

extern const s16 pl_piyo_tbl[];

const s16 pl_piyo_tbl[16] = {
    72, 72, 64, 64, 72, 64, 72, 64,
    64, 72, 64, 64, 64, 64, 56, 56,
};
