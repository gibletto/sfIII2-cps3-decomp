/*
 * EEPROM_TBL.C  tables read by eeprom.c: EEPROM access and bookkeeping counters
 */

#include "types.h"
#include "structs.h"

#pragma section TBL

extern const s8 eeprom_error_str[];

const s8 eeprom_error_str[16] = {
    69, 69, 80, 82, 79, 77, 32, 32, 69, 82, 82, 79, 82, 0, -1, -1,
};
