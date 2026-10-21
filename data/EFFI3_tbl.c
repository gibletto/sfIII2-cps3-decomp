/*
 * EFFI3_TBL.C  tables read by effect I3: the colours and timers of effect I2
 */

#include "types.h"
#include "structs.h"

#pragma section TBL

extern const u8 effI2_col_tbl[];
extern const u8 effI2_timer_tbl[];

const u8 effI2_col_tbl[10] = {
    8, 0xD, 0xE, 0xF, 0x10, 0x11, 0x10, 0xF, 0xE, 0xD,
};

const u8 effI2_timer_tbl[10] = {
    9, 8, 7, 6, 5, 4, 5, 6, 7, 8,
};
