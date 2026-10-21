/*
 * EFF35.C  Bonus-stage objects (effect 35)
 *
 * Sprites for the bonus games' presentation: title pieces, props that slide or zoom in,
 * and result signs, all drawn from bns_char_table.
 * effect_35_init(wait, c_type) picks an entry of eff35_data_tbl (for some types the choice
 * depends on Country or on Bonus_Game_result); after the wait timer effect_35_move runs
 * one of seven behaviours eff35_0000-0006: static display, horizontal zoom-in, repeating
 * sliding pieces, a reaction to the bonus result, and pieces pinned to BG1. Several of
 * them set Next_Step when done and most exit early on Break_Into.
 * Created from Game_Main, Manage and the second bonus-stage BG init (bns11_init00).
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "ta_sub.h"
#include "CHARMOVE.h"
#include "charmove_2.h"
#include "eff56.h"
#include "eff57.h"
#include "EFF58.h"
#include "EFFECT.h"
#include "effect_2.h"
#include "aboutspr.h"
#include "eff35.h"


/* 2i 060CB950, 3s-near: sf3 src/eff35.c:30 effect_35_move */
void effect_35_move(WORK_Other* ewk) {
    void (*eff35_jp[3])(WORK_Other*) = { eff35_0000, eff35_0001, eff35_0002 };
    eff35_jp[ewk->wu.routine_no[0]](ewk);
}



/* 2i 060CB986, 3s-near: sf3 src/eff35.c:37 eff35_0000 */
void eff35_0000(WORK_Other* ewk) {
    switch (ewk->wu.routine_no[1]) {
    case 0:
        ewk->wu.old_rno[1]--;
        if (ewk->wu.old_rno[1] > 0) {
            break;
        }
        ewk->wu.routine_no[1]++;
        ewk->wu.disp_flag = 1;
        if (plw[0].wu.operator) {
            if (Game_setting.mode) {
                ewk->wu.xyz[0].disp.pos = 0x260;
            } else {
                ewk->wu.xyz[0].disp.pos = 0x238;
            }
        } else if (Game_setting.mode) {
            ewk->wu.xyz[0].disp.pos = 0x1A0;
        } else {
            ewk->wu.xyz[0].disp.pos = 0x1C8;
        }
        set_char_move_init2(&ewk->wu, 0, ewk->wu.char_index, ewk->wu.old_rno[3], 0);
        break;
    case 1:
        disp_pos_trans_entry(ewk);
        break;
    default:
        all_cgps_put_back(&ewk->wu);
        push_effect_work(&ewk->wu);
    }
}



/* 2i 060CBA4C, 3s-near: sf3 src/eff35.c:59 eff35_0001 */
void eff35_0001(WORK_Other* ewk) {
    switch (ewk->wu.routine_no[1]) {
    case 0:
        if (Break_Into) {
            ewk->wu.routine_no[1] = 4;
            break;
        }
        ewk->wu.old_rno[1]--;
        if (ewk->wu.old_rno[1] > 0) {
            break;
        }
        ewk->wu.routine_no[1]++;
        ewk->wu.disp_flag = 1;
        ewk->wu.my_mr_flag = 1;
        ewk->wu.my_mr.size.x = 0x7F;
        ewk->wu.my_mr.size.y = 0x3F;
        set_char_move_init2(&ewk->wu, 0, ewk->wu.char_index, ewk->wu.old_rno[3], 0);
        break;
    case 1:
        if (Break_Into) {
            ewk->wu.routine_no[1] = 4;
            break;
        }
        ewk->wu.my_mr.size.x -= 12;
        if (ewk->wu.my_mr.size.x <= 0) {
            ewk->wu.routine_no[1]++;
            ewk->wu.my_mr.size.x = 0;
        }
        disp_pos_trans_entry5(ewk);
        break;
    case 2:
        if (Break_Into) {
            ewk->wu.routine_no[1] = 4;
            break;
        }
        ewk->wu.my_mr.size.x += 12;
        if (ewk->wu.my_mr.size.x >= 0x3F) {
            ewk->wu.routine_no[1]++;
            ewk->wu.my_mr.size.x = 0x3F;
        }
        disp_pos_trans_entry5(ewk);
        break;
    case 3:
        if (Break_Into) {
            ewk->wu.routine_no[1] = 4;
            break;
        }
        ewk->wu.old_rno[4]--;
        if (ewk->wu.old_rno[4] <= 0) {
            ewk->wu.routine_no[1]++;
            ewk->wu.disp_flag = 0;
            Next_Step = 1;
        }
        disp_pos_trans_entry5(ewk);
        break;
    case 4:
        ewk->wu.routine_no[1]++;
        break;
    default:
        all_cgps_put_back(&ewk->wu);
        push_effect_work(&ewk->wu);
    }
}



/* 2i 060CBB7A, 3s-near: sf3 src/eff35.c:125 eff35_0002 */
void eff35_0002(WORK_Other* ewk) {
    switch (ewk->wu.routine_no[1]) {
    case 0:
        if (Break_Into) {
            ewk->wu.routine_no[1] = 4;
            break;
        }
        ewk->wu.old_rno[1]--;
        if (ewk->wu.old_rno[1] > 0) {
            break;
        }
        ewk->wu.routine_no[1]++;
        ewk->wu.disp_flag = 1;
        set_char_move_init2(&ewk->wu, 0, ewk->wu.char_index, ewk->wu.old_rno[3], 0);
        effect_58_init(6, 4, 0xA8);
        break;
    case 1:
        if (Break_Into) {
            ewk->wu.routine_no[1] = 4;
            break;
        }
        ewk->wu.old_rno[4]--;
        if (ewk->wu.old_rno[4] <= 0) {
            ewk->wu.routine_no[1]++;
            ewk->wu.disp_flag = 0;
        }
        disp_pos_trans_entry(ewk);
        break;
    case 2:
        ewk->wu.routine_no[1]++;
        break;
    default:
        all_cgps_put_back(&ewk->wu);
        push_effect_work(&ewk->wu);
    }
}



s32 effect_35_init(s16 wait_timer, s16 c_type) {
    WORK_Other* ewk;
    s16 ix;
    const s16* data_ptr;
    u8 char_num;
    if ((ix = pull_effect_work(4)) == -1) {
        return -1;
    }
    switch (c_type) {
    case 0:
        if (Country == 1) {
            char_num = 0;
        } else {
            char_num = 1;
        }
        break;
    case 2:
        char_num = 2;
        break;
    case 3:
        char_num = 3;
        break;
    }
    data_ptr = eff35_data_tbl[char_num];
    set_work:;
    ewk = (WORK_Other*)frw[ix];
    ewk->wu.id = 35;
    ewk->wu.be_flag = 1;
    ewk->wu.old_rno[1] = wait_timer;
    ewk->wu.type = char_num;
    ewk->wu.work_id = 16;
    ewk->wu.cgromtype = 1;
    ewk->wu.my_col_mode = 0x4200;
    *ewk->wu.char_table = etc2_char_table;
    ewk->wu.my_col_code = 0x80;
    ewk->wu.my_family = 2;
    ewk->wu.xyz[0].disp.pos = *data_ptr++;
    ewk->wu.xyz[1].disp.pos = *data_ptr++;
    ewk->wu.my_priority = ewk->wu.position_z = *data_ptr++;
    ewk->wu.char_index = *data_ptr++;
    ewk->wu.old_rno[3] = *data_ptr++;
    ewk->wu.routine_no[0] = *data_ptr++;
    ewk->wu.old_rno[4] = *data_ptr;
    return 0;
}
