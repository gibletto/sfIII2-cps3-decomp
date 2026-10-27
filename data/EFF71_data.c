/*
 * EFF71_DATA.C  fighter-watching stage object character table
 *
 * eff71_char_tbl gives a weight for each character number; effect 71 compares the two
 * fighters' weights to choose which one it watches, and follows the stage scroll when they are
 * equal. Read by EFF71.C, a stage object that watches the fighters.
 */

#include "types.h"
#include "structs.h"

#pragma section TBL

extern const u16 eff71_char_tbl[];

const u16 eff71_char_tbl[16] = {
    0, 0, 0, 0, 0, 0, 0, 1,
    1, 2, 0, 0, 0, 0, 0, 0,
};
