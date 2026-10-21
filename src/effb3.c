/*
 * EFFB3.C  Effect B3: round / FIGHT display
 *
 * Effect B3 is the display child of the round-call effect B2 (EFFB2.C). In 2nd Impact it is one work
 * per letter: effect_B3_init makes the ROUND letters (6 works, then effect B9 for the round
 * number) or the FINAL ROUND letters (10 works), each with its own start and goal position.
 * effect_B3_move follows the parent's state each frame:
 *   round_move_init    (state 1) runs round_letter_move or final_letter_move
 *   round_letter_move  zooms a ROUND letter in from 127 while it flies to its goal
 *   final_letter_move  grows a FINAL ROUND letter, one letter after another (b2_curr_no)
 *   round_vanish       (state 4) shrinks the letter away
 *   fight_move         (state 5) grows the FIGHT letters in
 *   fight_vanish       (state 7) zooms the FIGHT letters out and lets them fall
 * Each routine counts rf_b2_flag up (or sets it) when its part is done.
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
void char_move(WORK* wk);
void set_char_move_init2();
#include "charmove_2.h"
#include "ta_sub.h"
#include "aboutspr.h"
#include "effb9.h"
#include "EFFECT.h"
#include "effect_2.h"
#include "PLS02.h"
#include "SE.h"
#include "se_2.h"
#include "se_3.h"
#include "bg_sub.h"
#include "bg_sub_2.h"
#include "bg_sub_3.h"
#include "bg_sub_4.h"
#include "bg_sub_5.h"
#include "CALDIR.h"
#include "effb2.h"
#include "effb3.h"



WORK_Other * oya_adrs;  

extern const s16 effb3_round_tbl[5][4];
extern const s16 effb3_final_tbl[10][3];
extern const s16 effb3_fight_tbl[6][5];
extern const s32 effb3_fight_speed_tbl[5][2];


void effect_B3_move(WORK_Other* ewk) {
    oya_adrs = (WORK_Other*)ewk->my_master;
    b3_Break_Into_check(ewk);
    switch (oya_adrs->wu.routine_no[0]) {
    case 0:
        ewk->wu.routine_no[0] = ewk->wu.routine_no[1] = ewk->wu.routine_no[2] = 0;
        ewk->wu.disp_flag;
        break;
    case 1:
        round_move_init(ewk);
        break;
    case 2:
    case 3:
    case 6:
        disp_pos_trans_entry(ewk);
        break;
    case 4:
        round_vanish(ewk);
        break;
    case 5:
        fight_move(ewk);
        break;
    case 7:
        fight_vanish(ewk);
        break;
    case 8:
    case 9:
    case 99:
        ewk->wu.disp_flag = 0;
        break;
    default:
        all_cgps_put_back(ewk);
        push_effect_work(&ewk->wu);
        break;
    }
}



void round_move_init(WORK_Other* ewk) {
    if (ewk->wu.vital_new == 5 && !ewk->wu.hit_quake) {
        return;
    }
    if (oya_adrs->wu.type) {
        final_letter_move(ewk);
    } else {
        round_letter_move(ewk);
    }
}



/* provisional name */
void round_letter_move(WORK_Other* ewk) {
    switch (ewk->wu.routine_no[1]) {
    case 0:
        ewk->wu.routine_no[1]++;
        if (!ewk->wu.vital_new) {
            Sound_SE(Round_num + 0x80);
        }
        ewk->wu.xyz[1].disp.pos = 176;
        ewk->wu.disp_flag = 1;
        ewk->wu.my_mr.size.x = 127;
        ewk->wu.my_mr.size.y = 127;
        ewk->wu.my_mr_flag = 1;
        set_char_move_init2(&ewk->wu, 0, ewk->wu.char_index, ewk->wu.old_rno[0], 0);
        ewk->wu.xyz[0].disp.pos += bg_w.bgw[1].pos_x_work;
        ewk->wu.hit_stop = 8;
        cal_all_speed_data(ewk, ewk->wu.hit_stop, ewk->wu.scr_mv_x, ewk->wu.scr_mv_y, 1, 1);
        break;
    case 1:
        ewk->wu.my_mr.size.x -= 8;
        ewk->wu.my_mr.size.y -= 8;
        if (ewk->wu.my_mr.size.x <= 63) {
            ewk->wu.my_mr.size.x = 63;
            ewk->wu.my_mr.size.y = 63;
        }
        if (ewk->wu.hit_stop > 1) {
            ewk->wu.hit_stop--;
            add_x_sub(ewk);
            add_y_sub(ewk);
        } else {
            ewk->wu.hit_stop = 0;
        }
        if (ewk->wu.my_mr.size.x == 63 && ewk->wu.hit_stop == 0) {
            ewk->wu.routine_no[1]++;
            rf_b2_flag++;
            ewk->wu.xyz[0].disp.pos = ewk->wu.scr_mv_x;
            ewk->wu.xyz[1].disp.pos = ewk->wu.scr_mv_y;
        }
        disp_pos_trans_entry5(ewk);
        break;
    case 2:
        break;
    }
}



/* provisional name */
void final_letter_move(WORK_Other* ewk) {
    if (b2_curr_no < ewk->wu.vital_new) {
        return;
    }
    switch (ewk->wu.routine_no[1]) {
    case 0:
        ewk->wu.routine_no[1]++;
        if (!ewk->wu.vital_new) {
            Sound_SE(0x8C);
        }
        ewk->wu.disp_flag = 1;
        ewk->wu.my_mr.size.x = 0;
        ewk->wu.my_mr.size.y = 0;
        ewk->wu.my_mr_flag = 1;
        set_char_move_init2(&ewk->wu, 0, ewk->wu.char_index, ewk->wu.old_rno[0], 0);
        ewk->wu.hit_stop = 4;
        cal_all_speed_data(ewk, ewk->wu.hit_stop, ewk->wu.scr_mv_x, ewk->wu.scr_mv_y, 1, 1);
        break;
    case 1:
        ewk->wu.my_mr.size.x += 10;
        ewk->wu.my_mr.size.y += 10;
        ewk->wu.hit_stop--;
        if (ewk->wu.hit_stop < 0) {
            ewk->wu.routine_no[1]++;
            rf_b2_flag++;
            ewk->wu.my_mr.size.x = 63;
            ewk->wu.my_mr.size.y = 63;
        } else {
            add_x_sub(ewk);
            add_y_sub(ewk);
            if (ewk->wu.hit_stop == 3) {
                b2_curr_no++;
            }
        }
    case 2:
    default:
        disp_pos_trans_entry5(ewk);
        break;
    }
}



/* provisional name */
void round_vanish(WORK_Other* ewk) {
    if (ewk->wu.vital_new == 5 && !ewk->wu.hit_quake) {
        return;
    }
    switch (ewk->wu.routine_no[3]) {
    case 0:
        ewk->wu.disp_flag = 1;
        ewk->wu.my_mr.size.y -= 12;
        if (ewk->wu.my_mr.size.y < 0) {
            ewk->wu.disp_flag = 0;
            ewk->wu.hit_stop = 16;
            ewk->wu.routine_no[3]++;
        }
        disp_pos_trans_entry5(ewk);
        break;
    case 1:
        ewk->wu.hit_stop--;
        if (ewk->wu.hit_stop < 0) {
            rf_b2_flag++;
        }
        break;
    }
}



void fight_move(WORK_Other* ewk) {
    switch (ewk->wu.routine_no[2]) {
    case 0:
        if (ewk->wu.vital_new > 4) {
            ewk->wu.routine_no[2] = 98;
            break;
        }
        ewk->wu.routine_no[2]++;
        ewk->wu.disp_flag = 1;
        ewk->wu.my_mr.size.x = 63;
        ewk->wu.my_mr.size.y = 0;
        ewk->wu.my_mr_flag = 1;
        ewk->wu.xyz[1].cal = 0x780000;
        ewk->wu.old_rno[0] = effb3_fight_tbl[ewk->wu.vital_new][0];
        ewk->wu.xyz[0].disp.pos = effb3_fight_tbl[ewk->wu.vital_new][3];
        ewk->wu.xyz[0].disp.pos += bg_w.bgw[1].pos_x_work;
        ewk->wu.xyz[0].disp.low = 0;
        set_char_move_init2(&ewk->wu, 0, 4, ewk->wu.old_rno[0], 0);
        break;
    case 1:
        ewk->wu.my_mr.size.y += 10;
        if (ewk->wu.my_mr.size.y >= 63) {
            ewk->wu.my_mr.size.x = 63;
            ewk->wu.my_mr.size.y = 63;
            if (!ewk->wu.vital_new) {
                Sound_SE(0x89);
            }
            if (ewk->wu.vital_new == 4) {
                rf_b2_flag = 1;
            }
        }
    case 2:
        disp_pos_trans_entry5(ewk);
        break;
    case 98:
        ewk->wu.routine_no[2]++;
        break;
    default:
        all_cgps_put_back(ewk);
        push_effect_work(&ewk->wu);
        break;
    }
}



void fight_vanish(WORK_Other* ewk) {
    switch (ewk->wu.routine_no[4]) {
    case 0:
        ewk->wu.routine_no[4]++;
        ewk->wu.disp_flag = 1;
        ewk->wu.my_mr.size.x = 63;
        ewk->wu.my_mr.size.y = 63;
        ewk->wu.mvxy.a[0].sp = effb3_fight_speed_tbl[ewk->wu.vital_new][0];
        ewk->wu.mvxy.d[0].sp = effb3_fight_speed_tbl[ewk->wu.vital_new][1];
        ewk->wu.mvxy.a[1].sp = -0x48000;
        ewk->wu.mvxy.d[1].sp = -0x18000;
        disp_pos_trans_entry5(ewk);
        break;
    case 1:
        ewk->wu.my_mr.size.x += 8;
        ewk->wu.my_mr.size.y += 8;
        if (ewk->wu.my_mr.size.x >= 127) {
            ewk->wu.my_mr.size.x = 127;
            ewk->wu.my_mr.size.y = 127;
        }
        add_x_sub(ewk);
        add_y_sub(ewk);
        if (ewk->wu.xyz[1].disp.pos < -32) {
            ewk->wu.disp_flag = 0;
            ewk->wu.routine_no[4]++;
            ewk->wu.disp_flag = 0;
            if (ewk->wu.vital_new == 4) {
                rf_b2_flag = 1;
            }
        }
    case 2:
        disp_pos_trans_entry5(ewk);
        break;
    }
}



s32 effect_B3_init(WORK_Other* wk) {
    WORK_Other* ewk;
    s16 ix;
    s16 i;
    s16 num;
    const s16* ptr;
    if (wk->wu.type) {
        ptr = &effb3_final_tbl[0][0];
        num = 10;
    } else {
        ptr = &effb3_round_tbl[0][0];
        num = 6;
    }
    for (i = 0; i < num; i++) {
        if ((ix = pull_effect_work(3)) == -1) {
            return -1;
        }
        ewk = (WORK_Other*)frw[ix];
        ewk->wu.be_flag = 1;
        ewk->wu.id = 113;
        ewk->wu.work_id = 16;
        ewk->wu.vital_new = i;
        ewk->wu.cgromtype = 1;
        ewk->my_master = (u32*)wk;
        ewk->wu.rl_flag = 0;
        ewk->wu.my_family = 2;
        ewk->wu.my_col_mode = 0x4200;
        ewk->wu.my_col_code = 57;
        ewk->wu.my_priority = ewk->wu.position_z = 10;
        ewk->wu.xyz[1].cal = 0x780000;
        ewk->wu.position_x = ewk->wu.xyz[0].disp.pos = bg_w.bgw[1].pos_x_work;
        ewk->wu.xyz[0].disp.low = 0;
        ewk->wu.char_table[0] = etc_char_table;
        if (wk->wu.type) {
            ewk->wu.hit_quake = 1;
            ewk->wu.old_rno[0] = *ptr++;
            ewk->wu.scr_mv_x = *ptr++;
            ewk->wu.position_y = ewk->wu.scr_mv_y = *ptr++;
            ewk->wu.char_index = 5;
        } else {
            ewk->wu.hit_quake = 0;
            ewk->wu.old_rno[0] = *ptr++;
            ewk->wu.xyz[0].disp.pos = *ptr++;
            ewk->wu.scr_mv_x = *ptr++;
            ewk->wu.position_y = ewk->wu.scr_mv_y = *ptr++;
            ewk->wu.char_index = 2;
        }
        ewk->wu.scr_mv_x += bg_w.bgw[1].pos_x_work;
    }
    if (wk->wu.type == 0) {
        effect_B9_init(wk);
    }
    return 0;
}
