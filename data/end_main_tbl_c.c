/*
 * END_MAIN_TBL_C.C  opening scene timer table
 *
 * op_timer_tbl is the length in frames of the scenes of the opening. Read by END_MAIN.C.
 */

#include "types.h"
#include "structs.h"

#pragma section TBL

extern const s16 op_timer_tbl[];

/* provisional name */
const s16 op_timer_tbl[14] = {
    304, 240, 176, 240, 192, 256, 48, 60,
    108, 18, 38, 90, 64, 80,
};
