/*
 * CMD_MAIN_CTBL.C  debug screen filler strings
 *
 * dbg_minus_str ("-") and dbg_space2_str (two spaces) are printed beside the values on the
 * debug screens. Read by CMD_MAIN.C, the debug menu.
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
