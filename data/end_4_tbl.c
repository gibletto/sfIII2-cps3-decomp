/*
 * END_4_TBL.C  tables read by end_4.c: ending 4
 */

#include "types.h"
#include "structs.h"

#pragma section TBL

extern const PANEL end_400_panel0[];
extern const PANEL end_400_panel1[];
extern const u16 timer_4_tbl[];
extern const u16 end_4_pos[];

/* provisional name */
const PANEL end_400_panel0[10] = {
    { 0, 82 },
    { 64, 83 },
    { 128, 84 },
    { 192, 85 },
    { 4096, 80 },
    { 4160, 81 },
    { 4224, 0 },
    { 4288, 0 },
    { 8192, 78 },
    { 8256, 79 },
};

/* provisional name */
const PANEL end_400_panel1[10] = {
    { 0, 76 },
    { 64, 77 },
    { 128, 52 },
    { 192, 53 },
    { 4096, 52 },
    { 4160, 53 },
    { 4224, 0 },
    { 4288, 0 },
    { 8192, 0 },
    { 8256, 0 },
};

/* provisional name */
const u16 timer_4_tbl[5] = {
    0x21C, 0x168, 0xB4, 0x258, 0x1E0,
};

/* provisional name */
const u16 end_4_pos[11] = {
    0x100, 0x300, 0x100, 0x200, 0x300, 0x300, 0x100, 0x100,
    0x100, 0x100, 0xFFFF,
};
