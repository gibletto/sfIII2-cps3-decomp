/*
 * plpat14.c  Character 14 (Gouki) special attack routines
 *
 * The entry routine pl14_extra_attack runs the routine for attack numbers 16 and up
 * (routine_no[2]) through pl14_exatt_table; each routine is a small state machine on
 * routine_no[3] that starts the animation and then follows its cg_type markers to apply motion
 * data, effects and gauge changes.
 * Att_PL14_AT1 and AT2 are moves driven by step-by-step motion data (setup_mvxy_data at each
 * marker), and Att_PL14_TOKUSHUKOUDOU is the personal action.
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "PLS02.h"
#include "PLSGAUGE.h"
#include "CHARMOVE.h"
#include "charmove_2.h"
#include "Grade.h"
#include "PLPAT.h"
#include "PLS01.h"
#include "plpat14.h"





void pl14_extra_attack(PLW* wk) {
    pl14_exatt_table[wk->wu.routine_no[2] - 16](wk);
}



void Att_PL14_AT1(PLW* wk) {
    switch (wk->wu.routine_no[3]) {
    case 0:
        wk->wu.routine_no[3]++;
        wk->wu.xyz[1].cal = 0;
        wk->wu.rl_flag = wk->wu.rl_waza;
        wk->rl_save = wk->wu.rl_flag;
        reset_mvxy_data(&wk->wu);
        wk->wu.mvxy.index = wk->as->r_no;
        set_char_move_init(&wk->wu, 5, wk->as->char_ix);
        break;
    case 1:
        char_move(&wk->wu);
        cal_mvxy_speed(&wk->wu);
        if (wk->rl_save) {
            wk->wu.xyz[0].cal += wk->wu.mvxy.a[0].sp;
        } else {
            wk->wu.xyz[0].cal -= wk->wu.mvxy.a[0].sp;
        }
        wk->wu.xyz[1].cal += wk->wu.mvxy.a[1].sp;
        switch (wk->wu.cg_type) {
        case 10:
            wk->wu.routine_no[3]++;
        case 20:
            setup_mvxy_data(&wk->wu, wk->wu.mvxy.index);
            wk->wu.mvxy.index++;
            wk->wu.cg_type = 0;
            break;
        case 21:
            reset_mvxy_data(&wk->wu);
            wk->wu.cg_type = 0;
        }
        return;
    default:
        char_move(&wk->wu);
        cal_mvxy_speed(&wk->wu);
        if (wk->rl_save) {
            wk->wu.xyz[0].cal += wk->wu.mvxy.a[0].sp;
        } else {
            wk->wu.xyz[0].cal -= wk->wu.mvxy.a[0].sp;
        }
        wk->wu.xyz[1].cal += wk->wu.mvxy.a[1].sp;
        wk->wu.rl_flag = wk->wu.rl_waza;
        if ((wk->wu.mvxy.a[0].sp != 0)) {
            if (wk->old_pos_data[0] == wk->old_pos_data[1]) {
                char_move_z(&wk->wu);
            }
        }
        switch (wk->wu.cg_type) {
        case 20:
            setup_mvxy_data(&wk->wu, wk->wu.mvxy.index);
            wk->wu.mvxy.index++;
            wk->wu.cg_type = 0;
            break;
        case 21:
            reset_mvxy_data(&wk->wu);
            wk->wu.cg_type = 0;
        default:
            break;
        }
    }
}



void Att_PL14_AT2(PLW* wk) {
    switch (wk->wu.routine_no[3]) {
    case 0:
        wk->wu.routine_no[3]++;
        set_char_move_init(&wk->wu, 5, wk->as->char_ix);
        wk->wu.mvxy.index = wk->as->r_no;
        break;
    case 1:
        char_move(&wk->wu);
        switch ((u8)wk->wu.cg_type) {
        case 10:
            wk->wu.routine_no[3]++;
            wk->wu.cg_type = 0;
            break;
        case 20:
            setup_mvxy_data(&wk->wu, wk->wu.mvxy.index);
            wk->wu.mvxy.index++;
            wk->wu.cg_type = 0;
            break;
        case 30:
            add_to_mvxy_data(&wk->wu, wk->wu.mvxy.index);
            wk->wu.mvxy.index++;
            wk->wu.cg_type = 0;
            break;
        }
        return;
    case 2:
        jumping_union_process(&wk->wu, 3);
        if ((u8)wk->wu.cg_type == 40) {
            wk->wu.routine_no[3] = 1;
            wk->wu.cg_type = 0;
        }
        break;
    case 3:
        char_move(&wk->wu);
        break;
    }
}




void Att_PL14_TOKUSHUKOUDOU(PLW* wk) {
    wk->scr_pos_set_flag = 0;
    switch (wk->wu.routine_no[3]) {
    case 0:
        wk->wu.routine_no[3]++;
        wk->wu.rl_flag = wk->wu.rl_waza;
        set_char_move_init(&wk->wu, 5, wk->as->char_ix);
        break;
    case 1:
        char_move(&wk->wu);
        if (wk->wu.cg_type == 40) {
            wk->wu.cg_type = 0;
            add_sp_arts_gauge_tokushu(wk);
        }
        if (wk->wu.cg_type == 64) {
            wk->wu.cg_type = 0;
            wk->tk_dageki += 14;
            wk->tk_kizetsu += 9;
            if (wk->tk_dageki > 14) {
                wk->tk_dageki = 14;
            }
            if (wk->tk_kizetsu > 9) {
                wk->tk_kizetsu = 9;
            }
        }
        break;
    }
}
