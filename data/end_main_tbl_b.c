/*
 * END_MAIN_TBL_B.C  ending type table
 *
 * end_type_tbl gives, by the ending's character number, one of three ending types, which picks
 * the colour load and the fades into and out of the staff roll. Read by END_MAIN_C.C.
 */

#include "types.h"
#include "structs.h"

#pragma section TBL

extern const s8 end_type_tbl[];

/* provisional name */
const s8 end_type_tbl[16] = {
    0, 1, 1, 2, 0, 1, 2, 0, 0, 1, 2, 0, 1, 2, 2, 2,
};
