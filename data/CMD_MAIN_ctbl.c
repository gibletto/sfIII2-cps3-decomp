/*
 * CMD_MAIN_CTBL.C  tables read by CMD_MAIN.c: debug menu and command input
 */

#include "types.h"
#include "structs.h"

#pragma section TBL

extern const char dbg_minus_str[];
extern const char dbg_space2_str[];

const char dbg_minus_str[4] = {
    0x2D, 0, 0xFF, 0xFF,
};

const char dbg_space2_str[4] = {
    0x20, 0x20, 0, 0xFF,
};
