/*
 * SYS_TEST_4.C  System library: scroll registers, test mode pages, CD/SCSI, coin chutes (part 4)
 *
 * Routines: rewrite_menu_init, rewrite_menu_select, rewrite_cd_not_ready, rewrite_page,
 * coin_chutes_update, service_coin_check.
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
#include "sys_test_3.h"
#include "sys_test_4.h"
#include "cps3.h"



s16 rewrite_no = 0;  /* 02007CDC */
s16 rewrite_cursor = 0;  /* 02007CDE */


/* provisional name */
void rewrite_menu_init(void) {
    s32 col;
    rewrite_cursor = 0;
    if (screen_mode == 7) {
        col = 4;
    } else {
        col = 0;
    }
    while (scsi_prevent_allow_medium_removal(0, 1)) {
    }
    tilemap_fill_all(0, 32);
    tilemap_print_string(col, 0, 0xFFFF, rewrite_menu_scr);
    tilemap_print_string(col, 0, 0xFFFF, rewrite_guide_scr);
    tilemap_put_block(col + 15, 9, 2, 62);
    rewrite_no++;
}



/* provisional name */
void rewrite_menu_select(void) {
    s32 col;
    s32 unused;
    if (screen_mode == 7) {
        col = 4;
    } else {
        col = 0;
    }
    if ((p1sw_0 & 1) == 1 && (p1sw_1 & 1) != 1) {
        tilemap_put_block(col + 15, rewrite_cursor * 2 + 9, 2, 32);
        if (--rewrite_cursor < 0) {
            rewrite_cursor = 2;
        }
        if (rewrite_cursor == 2) {
            tilemap_print_string(col, 0, 0xFFFF, rewrite_exit_guide_scr);
        } else {
            tilemap_print_string(col, 0, 0xFFFF, rewrite_guide_scr);
        }
        tilemap_put_block(col + 15, rewrite_cursor * 2 + 9, 2, 62);
    } else if ((p1sw_0 & 2) == 2 && (p1sw_1 & 2) != 2) {
        tilemap_put_block(col + 15, rewrite_cursor * 2 + 9, 2, 32);
        if (++rewrite_cursor > 2) {
            rewrite_cursor = 0;
        }
        if (rewrite_cursor == 2) {
            tilemap_print_string(col, 0, 0xFFFF, rewrite_exit_guide_scr);
        } else {
            tilemap_print_string(col, 0, 0xFFFF, rewrite_guide_scr);
        }
        tilemap_put_block(col + 15, rewrite_cursor * 2 + 9, 2, 62);
    }
    if ((p1sw_0 & 0x10) == 0x10 && (p1sw_1 & 0x10) != 0x10) {
        if (rewrite_cursor == 2) {
            rewrite_no++;
        }
    } else if ((p1sw_0 & 0x1000) == 0x1000 && (p1sw_0 & 0x10) == 0x10) {
        tilemap_fill_all(0, 32);
        task_sleep(1);
        if (rewrite_cursor == 0) {
            bios_vector_restart(0x200, 0);
        } else {
            bios_vector_restart(0x208, 0);
        }
    }
}



/* provisional name */
void rewrite_cd_not_ready(void) {
    s32 col;
    if (screen_mode == 7) {
        col = 4;
    } else {
        col = 0;
    }
    tilemap_fill_all(0, 32);
    tilemap_print_string(col, 0, 0xFFFF, rewrite_not_ready_str);
    task_sleep(180);
    rewrite_no = 0;
}



/* provisional name */
s32 rewrite_page(void) {
    register s32 rc;
    if (no_cd_flag) {
        return -1;
    }
    rc = 0;
    switch (rewrite_no) {
    case 0:
        rewrite_menu_init();
        break;
    case 1:
        rewrite_menu_select();
        break;
    case 2:
        if (cd_check_drive_inquiry() == 0) {
            if (cd_check_disc_id() == 0) {
                while (scsi_prevent_allow_medium_removal(1, 1)) {
                }
                rc = -1;
                rewrite_no = 0;
            } else {
                rewrite_no++;
            }
        } else {
            rewrite_no++;
        }
        break;
    case 3:
        rewrite_cd_not_ready();
        break;
    }
    return rc;
}



/* provisional name */
void coin_chutes_update(s32 keep) {
    switch (Chute_Mode) {
    case 0:
    case 3:
    case 7:
        if (coin_chute_check(0, keep)) {
            coin_credit_add(0, 0);
        }
        coin_counter_drive(0);
        break;
    case 1:
        if (coin_chute_check(0, keep)) {
            coin_credit_add(0, 0);
        }
        if (coin_chute_check(1, keep)) {
            coin_credit_add(0, 0);
        }
        coin_counter_drive(0);
        break;
    case 2:
        if (coin_chute_check(0, keep)) {
            coin_credit_add(0, 0);
        }
        if (coin_chute_check(1, keep)) {
            coin_credit_add(1, 0);
        }
        coin_counter_drive(0);
        break;
    case 4:
    case 8:
        if (coin_chute_check(0, keep)) {
            coin_credit_add(0, 0);
        }
        if (coin_chute_check(2, keep)) {
            coin_credit_add(0, 0);
        }
        coin_counter_drive(0);
        break;
    case 5:
        if (coin_chute_check(0, keep)) {
            coin_credit_add(0, 0);
        }
        if (coin_chute_check(1, keep)) {
            coin_credit_add(0, 0);
        }
        if (coin_chute_check(2, keep)) {
            coin_credit_add(0, 0);
        }
        coin_counter_drive(0);
        break;
    case 6:
        if (coin_chute_check(0, keep)) {
            coin_credit_add(0, 0);
        }
        if (coin_chute_check(1, keep)) {
            coin_credit_add(1, 0);
        }
        if (coin_chute_check(2, keep)) {
            coin_credit_add(2, 0);
        }
        coin_counter_drive(0);
        break;
    case 9:
        if (coin_chute_check(0, keep)) {
            coin_credit_add(0, 0);
        }
        if (coin_chute_check(2, keep)) {
            coin_credit_add(2, 0);
        }
        coin_counter_drive(0);
        break;
    case 10:
        if (coin_chute_check(0, keep)) {
            coin_credit_add(0, 0);
        }
        if (coin_chute_check(1, keep)) {
            coin_credit_add(0, 0);
        }
        if (coin_chute_check(2, keep)) {
            coin_credit_add(0, 0);
        }
        if (coin_chute_check(3, keep)) {
            coin_credit_add(0, 0);
        }
        coin_counter_drive(0);
        break;
    case 11:
        if (coin_chute_check(0, keep)) {
            coin_credit_add(0, 0);
        }
        if (coin_chute_check(1, keep)) {
            coin_credit_add(1, 0);
        }
        if (coin_chute_check(2, keep)) {
            coin_credit_add(2, 0);
        }
        if (coin_chute_check(3, keep)) {
            coin_credit_add(3, 0);
        }
        coin_counter_drive(0);
        break;
    }
}



/* provisional name */
void service_coin_check(void) {
    if ((syssw_0 & 1) && !(syssw_1 & 1)) {
        bookkeep_service_count();
        coin_in_flag = 1;
        switch (Chute_Mode) {
        case 0:
        case 1:
        case 3:
        case 4:
        case 5:
        case 7:
        case 8:
        case 10:
            credit_1p++;
            coin_chute1_w.dropped = 1;
            if (credit_1p > 9) {
                credit_1p = 9;
            }
            break;
        case 2:
        case 9:
            credit_1p++;
            coin_chute1_w.dropped = 1;
            if (credit_1p > 9) {
                credit_1p = 9;
            }
            credit_2p++;
            coin_chute2_w.dropped = 1;
            if (credit_2p > 9) {
                credit_2p = 9;
            }
            break;
        case 6:
            credit_1p++;
            coin_chute1_w.dropped = 1;
            if (credit_1p > 9) {
                credit_1p = 9;
            }
            credit_2p++;
            coin_chute2_w.dropped = 1;
            if (credit_2p > 9) {
                credit_2p = 9;
            }
            credit_3p++;
            coin_chute3_w.dropped = 1;
            if (credit_3p > 9) {
                credit_3p = 9;
            }
            break;
        case 11:
            credit_1p++;
            coin_chute1_w.dropped = 1;
            if (credit_1p > 9) {
                credit_1p = 9;
            }
            credit_2p++;
            coin_chute2_w.dropped = 1;
            if (credit_2p > 9) {
                credit_2p = 9;
            }
            credit_3p++;
            coin_chute3_w.dropped = 1;
            if (credit_3p > 9) {
                credit_3p = 9;
            }
            credit_4p++;
            coin_chute4_w.dropped = 1;
            if (credit_4p > 9) {
                credit_4p = 9;
            }
            break;
        }
    }
}
