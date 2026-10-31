/*
 * COIN_SW_2.C  Dispenser control
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "meta_col.h"
#include "meta_col_mem.h"
#include "meta_col_strcpy.h"
#include "meta_col_lib.h"
#include "meta_col_bcd.h"
#include "eeprom.h"
#include "sys_config.h"
#include "sys_config_2.h"
#include "sys_config_3.h"
#include "textsound.h"
#include "textsound_2.h"
#include "textsound_3.h"
#include "sys_test.h"
#include "sys_test_2.h"
#include "sys_test_2b.h"
#include "sys_test_2c.h"
#include "sys_test_3.h"
#include "sys_test_4.h"
#include "sys_test_5.h"
#include "cps3.h"



s16 card_out_req;  /* 02064F68 */
u16 card_out_busy;  /* 02064F6A */
u8 card_out_busy_tail[128];  /* after card_out_busy; nothing refers to it by name or address */


s32 card_empty_flag = 0;  /* 02008584 */


/* provisional name */
void dispenser_init(void) {
    card_out_req = 0;
    if (Card_Dispenser != 0) {
        card_out_busy = 0;
        coin_out_latch &= ~4;
        if (card_sw_0 & 4) {
            card_out_busy = 4;
            coin_out_latch |= 4;
        }
    }
}



/* provisional name */
void dispenser_control(void) {
    if (Card_Dispenser == 0) {
        return;
    }
    if ((card_sw_0 & 0x20) == 0) {
        card_empty_flag = -1;
    } else {
        card_empty_flag = 0;
    }
    if (card_out_busy == 4) {
        if ((~card_sw_1 & card_sw_0) & 0x40) {
            if (!test_flag) {
                bookkeep_card_count();
            }
            card_out_busy = 0;
            coin_out_latch &= ~4;
        }
    } else {
        if (card_empty_flag == -1) {
            return;
        }
        if (card_out_req == 0) {
            return;
        }
        if (card_sw_0 & 1) {
            return;
        }
        card_out_req--;
        card_out_busy = 4;
        coin_out_latch |= 4;
    }
}
