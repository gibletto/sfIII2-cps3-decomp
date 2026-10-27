/*
 * EFFI3_TBL.C  stage colour cycle of effect I2
 *
 * effI2_col_tbl and effI2_timer_tbl are the ten colours and step times that effect I2 cycles
 * through. Read by EFFI3.C.
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
