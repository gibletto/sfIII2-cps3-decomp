/*
 * SC_DATA2.C  a table nothing reads, kept for the layout
 */

#include "types.h"
#include "structs.h"

#pragma section TBL

extern const u16 spgauge_postbl_unref[];

/* a table of spgauge_postbl_0's form (VITAL_tbl.c); nothing in the program refers to it (provisional name) */
const u16 spgauge_postbl_unref[22] = {
    0x15, 0x14, 0x13, 0x12, 0x11, 0x10, 0xF, 0xE,
    0xD, 0xC, 0xB, 0xA, 9, 8, 7, 6,
    5, 4, 3, 2, 1, 0xFFFF,
};
