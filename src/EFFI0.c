/*
 * EFFI0.C  Effect H9 (balls-left counter) and effect I0: small stone debris
 *
 * Effect H9 is the bonus stage's remaining-ball counter: effect_H9_init (BBBSCOM.c) builds three
 * connected sprites from bbbs_ball, by facing and by Game_setting.mode (bbbs_ball has four
 * rows), and effect_H9_move counts the two-digit number up to Bonus_Game_Work, then keeps it
 * equal to Bonus_Game_Work (nokori_ball_effH9).
 * Each I0 work is one piece of stone kicked up from the floor. effect_I0_init spawns the pieces
 * (effI0_piece_set) from the koishi tables; effect_I0_move picks one of eight stone patterns
 * (char_of_koishi) at random, flies the piece up under gravity, and when it falls back to its
 * landing height plays the landing part of its pattern and frees itself when the pattern ends.
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "PLS02.h"
#include "CHARMOVE.h"
#include "charmove_2.h"
#include "aboutspr.h"
#include "EFFECT.h"
#include "effect_2.h"
#include "EFFI0.h"
#include "end_sub.h"
#include "end_sub_2.h"
#include "end_sub_3.h"
#include "end_sub_4.h"
#include "end_sub_5.h"
#include "end_sub_6.h"
#include "end_sub_7.h"
#include "color3rd.h"
#include "end_sub_8.h"
#include "EFF03.h"
#include "EFFH9.h"


void effect_H9_move(WORK_Other_CONN* ewk) {
    switch (ewk->wu.routine_no[0]) {
    case 0:
        switch (ewk->wu.routine_no[1]) {
        case 0:
            ewk->wu.routine_no[1]++;
            ewk->wu.disp_flag = 1;
            ewk->wu.old_cgnum = 0;
            ewk->wu.position_z = ewk->wu.my_priority = 27;
            ewk->wu.direction = 0;
            ewk->wu.dir_timer = 0;
            nokori_ball_effH9(ewk, ewk->wu.direction);
            break;
        case 1:
            if (--ewk->wu.dir_timer > 0) {
                break;
            }
            ewk->wu.dir_timer = 3;
            ewk->wu.direction++;
            nokori_ball_effH9(ewk, ewk->wu.direction);
            if (ewk->wu.direction < Bonus_Game_Work) {
                break;
            }
            ewk->wu.routine_no[0] = 1;
            ewk->wu.routine_no[1] = 0;
            break;
        }
        effH9_trans(&ewk->wu);
        break;
    case 1:
        if (ewk->wu.dead_f == 1) {
            ewk->wu.disp_flag = 0;
            ewk->wu.type = 0;
            ewk->wu.routine_no[0] = 2;
            break;
        }
        nokori_ball_effH9(ewk, Bonus_Game_Work);
        effH9_trans(&ewk->wu);
        break;
    case 2:
        ewk->wu.routine_no[0] = 3;
        break;
    default:
        all_cgps_put_back(&ewk->wu);
        push_effect_work(&ewk->wu);
        break;
    }
}


void effH9_trans(WORK* ewk) {
    ewk->cg_number = (ewk->cg_number + 1) & 0x7FFF;
    if (ewk->cg_number == 0) {
        ewk->cg_number = 1;
    }
    ewk->position_x = bg_w.bgw[1].wxy[0].disp.pos;
    ewk->position_y = bg_w.bgw[1].wxy[1].disp.pos;
    sort_push_request3(ewk);
}


void nokori_ball_effH9(WORK_Other_CONN* ewk, s16 num) {
    ewk->conn[0].chr = (num % 10) + 0xB2C3;
    ewk->conn[1].chr = (num / 10) + 0xB2C3;
}


s32 effect_H9_init(PLW* wk) {
    WORK_Other_CONN* ewk;
    s16 ix;
    s16 i;
    if ((ix = pull_effect_work(4)) == -1) {
        return -1;
    }
    ewk = (WORK_Other_CONN*)frw[ix];
    ewk->wu.be_flag = 1;
    ewk->wu.id = 179;
    ewk->wu.work_id = 16;
    ewk->wu.my_family = 2;
    ewk->wu.cgromtype = 1;
    ewk->wu.type = wk->wu.rl_flag;
    ewk->wu.my_col_mode = 0x4200;
    ewk->wu.my_col_code = 0x80;
    ewk->num_of_conn = 3;
    ix = (Game_setting.mode != 0);
    ix *= 2;
    if (wk->wu.rl_flag != 0) {
        ix = ix + 1;
    }
    for (i = 0; i < 3; i++) {
        ewk->conn[i] = bbbs_ball[ix][i];
    }
    return 0;
}


void effect_I0_move(WORK_Other* ewk) {
    switch (ewk->wu.routine_no[0]) {
    case 0:
        ewk->wu.routine_no[0]++;
        ewk->wu.disp_flag = 1;
        ewk->wu.my_col_mode = 0x4200;
        ewk->wu.my_col_code = 0x2020;
        set_char_move_init(&ewk->wu, 0, char_of_koishi[random_16_com() & 7]);
    case 1:
        if (ewk->wu.dead_f == 1) {
            ewk->wu.disp_flag = 0;
            ewk->wu.routine_no[0]++;
            break;
        }
        if (EXE_flag == 0 && Game_pause == 0) {
            switch (ewk->wu.routine_no[1]) {
            case 0:
                add_mvxy_speed(&ewk->wu);
                cal_mvxy_speed(&ewk->wu);
                if (ewk->wu.mvxy.a[1].sp <= 0) {
                    ewk->wu.routine_no[1]++;
                }
                char_move(&ewk->wu);
                break;
            case 1:
                add_mvxy_speed(&ewk->wu);
                cal_mvxy_speed(&ewk->wu);
                if (ewk->wu.xyz[1].disp.pos <= ewk->wu.next_y) {
                    ewk->wu.routine_no[1]++;
                    char_move_wca(&ewk->wu);
                    break;
                }
            default:
                char_move(&ewk->wu);
                if (ewk->wu.cg_type == 0xFF) {
                    ewk->wu.disp_flag = 0;
                    ewk->wu.routine_no[0]++;
                }
                break;
            }
        }
        ewk->wu.position_x = ewk->wu.xyz[0].disp.pos;
        ewk->wu.position_y = ewk->wu.xyz[1].disp.pos;
        sort_push_request(&ewk->wu);
        break;
    case 2:
        ewk->wu.routine_no[0] = 3;
        break;
    default:
        all_cgps_put_back(&ewk->wu);
        push_effect_work(&ewk->wu);
        break;
    }
}


s32 effI0_piece_set(wk, hsx, hsy, spx, spy, nxy)
WORK* wk;
s16 hsx;
s16 hsy;
s16 spx;
s16 spy;
s16 nxy;
{
    WORK_Other* ewk;
    s16 ix;
    if ((ix = pull_effect_work(3)) == -1) {
        return -1;
    }
    ewk = (WORK_Other*)frw[ix];
    ewk->wu.be_flag = 1;
    ewk->wu.id = 0xB4;
    ewk->wu.work_id = 0x10;
    ewk->wu.rl_flag = wk->rl_flag;
    ewk->wu.my_family = wk->my_family;
    ewk->wu.cgromtype = 1;
    ewk->wu.next_y = nxy;
    ewk->wu.mvxy.a[0].sp = spx << 8;
    ewk->wu.mvxy.d[0].sp = 0;
    ewk->wu.mvxy.a[1].sp = spy << 8;
    ewk->wu.mvxy.d[1].sp = -0x8000U;
    if (ewk->wu.rl_flag) {
        ewk->wu.xyz[0].disp.pos = wk->position_x - hsx;
    } else {
        ewk->wu.xyz[0].disp.pos = wk->position_x + hsx;
    }
    ewk->wu.xyz[1].disp.pos = wk->position_y + hsy;
    ewk->wu.position_z = wk->position_z + 1;
    ewk->wu.char_table[0] = plef_char_table;
    return 0;
}


void effect_I0_init(WORK* wk, u8 num) {
    s16* dix;
    s16 i;
    s16 hsx;
    s16 hsy;
    s16 spx;
    s16 spy;
    s16 nxy;
    dix = &koishi_app_area[random_16_com() & 7][0];
    for (i = 0; i < num_of_koishi[num]; i++) {
        hsx = (koishi_area_hosei[dix[i]] + (random_16_com() - 7));
        hsy = -(random_16_com() & 3);
        nxy = (hsy - (random_16_com() & 3));
        spx = koishi_speed_x[dix[i]][random_16_com() & 7];
        spy = koishi_speed_y[dix[i]][random_16_com() & 7];
        effI0_piece_set(wk, hsx, hsy, spx, spy, nxy);
    }
}


