/*
 * plpat15.c  Character 15 (Shin Gouki) special attack routines
 *
 * The routines are plpat14's (Gouki) with their own table (pl15_exatt_table); only the personal action differs:
 * it adds 16 to tk_dageki
 * and caps it at 16 where Gouki's adds and caps 14.
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
#include "plpat15.h"

/* routine_no[3], Att_PL15_AT1 */
#define AT1_MOVE        1       /* move and run the animation */

/* routine_no[3], Att_PL15_AT2 */
#define AT2_MOVE        1       /* move and run the animation */
#define AT2_AIR         2       /* in the air until it lands */
#define AT2_LAND        3       /* the landing */

/* routine_no[3], Att_PL15_TOKUSHUKOUDOU */
#define TOKUSHUKOUDOU_ACTION 1  /* the personal action, filling the super art gauge */





void pl15_extra_attack(PLW* wk) {
    pl15_exatt_table[wk->wu.routine_no[2] - ATTACK_SPECIAL](wk);
}



void Att_PL15_AT1(PLW* wk) {
    switch (wk->wu.routine_no[3]) {
    case RN3_START:
        wk->wu.routine_no[3]++;
        wk->wu.xyz[1].cal = 0;
        wk->wu.rl_flag = wk->wu.rl_waza;
        wk->rl_save = wk->wu.rl_flag;
        reset_mvxy_data(&wk->wu);
        wk->wu.mvxy.index = wk->as->r_no;
        set_char_move_init(&wk->wu, 5, wk->as->char_ix);
        break;
    case AT1_MOVE:
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



void Att_PL15_AT2(PLW* wk) {
    switch (wk->wu.routine_no[3]) {
    case RN3_START:
        wk->wu.routine_no[3]++;
        set_char_move_init(&wk->wu, 5, wk->as->char_ix);
        wk->wu.mvxy.index = wk->as->r_no;
        break;
    case AT2_MOVE:
        char_move(&wk->wu);
        switch (wk->wu.cg_type) {
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
    case AT2_AIR:
        jumping_union_process(&wk->wu, 3);
        if (wk->wu.cg_type == 40) {
            wk->wu.routine_no[3] = AT2_MOVE;
            wk->wu.cg_type = 0;
        }
        break;
    case AT2_LAND:
        char_move(&wk->wu);
        break;
    }
}




void Att_PL15_TOKUSHUKOUDOU(PLW* wk) {
    wk->scr_pos_set_flag = 0;
    switch (wk->wu.routine_no[3]) {
    case RN3_START:
        wk->wu.routine_no[3]++;
        wk->wu.rl_flag = wk->wu.rl_waza;
        set_char_move_init(&wk->wu, 5, wk->as->char_ix);
        break;
    case TOKUSHUKOUDOU_ACTION:
        char_move(&wk->wu);
        if (wk->wu.cg_type == 40) {
            wk->wu.cg_type = 0;
            add_sp_arts_gauge_tokushu(wk);
        }
        if (wk->wu.cg_type == 64) {
            wk->wu.cg_type = 0;
            wk->tk_dageki += 16;
            wk->tk_kizetsu += 9;
            if (wk->tk_dageki > 16) {
                wk->tk_dageki = 16;
            }
            if (wk->tk_kizetsu > 9) {
                wk->tk_kizetsu = 9;
            }
        }
        break;
    }
}
