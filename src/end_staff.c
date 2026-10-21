/*
 * END_STAFF.C  Staff roll scene
 *
 * end_staff_main runs the staff roll (staff_roll_main) while BG layer 1 scrolls toward Gill's position, then
 * starts the end object (end_obj_sync), zooms in on the centre that end_staff_scrn_set computes and ends the
 * ending after effect A8.
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "sys_test.h"
#include "sys_test_2.h"
#include "sys_test_2b.h"
#include "sys_test_2c.h"
#include "sys_test_3.h"
#include "sys_test_4.h"
#include "sys_test_5.h"
#include "SYS_sub.h"
#include "efff7.h"
#include "efff8_code.h"
#include "EFFF9.h"
#include "SE.h"
#include "se_2.h"
#include "se_3.h"
#include "bg_sub.h"
#include "bg_sub_2.h"
#include "bg_sub_3.h"
#include "bg_sub_4.h"
#include "bg_sub_5.h"
#include "end_main.h"
#include "effe6.h"
#include "aboutspr.h"
#include "end_staff.h"



extern s8 end_staff_done;
extern s8 end_scroll_dir;
extern s16 end_cnt;
extern s16 end_cnt2;
extern s32 staff_roll_main();
s32 Frame_Up();



void end_staff_main(void) {
    switch (end_w.r_no_1) {
    case 0:
        end_w.r_no_1++;
        end_no_cut = 1;
        break;
    case 1:
        end_w.r_no_1++;
        end_no_cut = 0;
        break;
    case 2:
        Forbid_Break = 0;
        end_w.r_no_1++;
        bgm_request(27);
        end_staff_done = 0;
        break;
    case 3:
        Forbid_Break = 0;
        if (!end_staff_done) {
            end_staff_done = staff_roll_main(0);
        }
        if (end_scroll_dir) {
            if (bg_w.bgw[1].wxy[0].disp.pos > Gill_Pos_X && bg_w.bgw[1].wxy[0].disp.pos > bg_w.bgw[1].l_limit2) {
                bg_w.bgw[1].wxy[0].cal -= 0x4000;
                bg_w.bgw[1].xy[0].cal -= 0x4000;
            } else {
                end_w.r_no_1++;
            }
        } else {
            if (bg_w.bgw[1].wxy[0].disp.pos < Gill_Pos_X && bg_w.bgw[1].wxy[0].disp.pos < bg_w.bgw[1].r_limit2) {
                bg_w.bgw[1].wxy[0].cal += 0x4000;
                bg_w.bgw[1].xy[0].cal += 0x4000;
            } else {
                end_w.r_no_1++;
            }
        }
        break;
    case 4:
        Forbid_Break = 0;
        if (!end_staff_done) {
            end_staff_done = staff_roll_main(0);
            break;
        }
        end_w.r_no_1++;
        end_cnt = 30;
        break;
    case 5:
        end_cnt--;
        if (end_cnt >= 0) {
            break;
        }
        end_w.r_no_1++;
        end_obj_sync = 1;
        end_cnt2 = 80;
        bg_w.bgw[5].xy[0].disp.pos = 0x300;
        bg_w.bgw[5].position_x = 0x300 - bg_w.pos_offset;
        Family_Set_W(6, (s16)-bg_w.bgw[5].position_x & 0x3FF, 0x300);
        Forbid_Break = -1;
        break;
    case 6:
        Forbid_Break = -1;
        if (end_obj_sync >= 2) {
            end_w.r_no_1++;
            end_staff_scrn_set();
        }
        break;
    case 7:
        Forbid_Break = -1;
        end_cnt2--;
        if (end_cnt2 >= 0) {
            Frame_Up(bg_w.center_x, bg_w.center_y, 1, 1);
        } else {
            end_w.r_no_1++;
            end_cnt = 4;
        }
        break;
    case 8:
        Forbid_Break = -1;
        end_cnt--;
        if (end_cnt < 0) {
            end_w.r_no_1++;
            effect_A8_init();
            end_cnt = 60;
        }
        break;
    case 9:
        Forbid_Break = -1;
        end_cnt--;
        if (end_cnt < 0) {
            end_w.r_no_1++;
            end_w.end_flag = 1;
        }
        break;
    case 10:
        Forbid_Break = -1;
        return;
    }
}



void end_staff_scrn_set(void) {
    s16 x;
    if (Gill_Pos_X != bg_w.bgw[1].wxy[0].disp.pos) {
        x = Gill_Pos_X - bg_w.bgw[1].wxy[0].disp.pos;
        if (Game_setting.mode) {
            x += 0xF8;
        } else {
            x += 0xC0;
        }
    } else if (Game_setting.mode) {
        x = 0xF8;
    } else {
        x = 0xC0;
    }
    if (Monitor_Flip) {
        bg_w.center_x = bg_w.pos_offset * 2 - x;
    } else {
        bg_w.center_x = x;
    }
    bg_w.center_y = 48;
}
