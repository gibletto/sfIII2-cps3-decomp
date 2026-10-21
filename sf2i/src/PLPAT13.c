/*
 * PLPAT13.C  Player 13 (Urien) special attack routines
 *
 * Character-specific attack routines for player number 13, dispatched by pl13_extra_attack
 * through pl13_exatt_table.
 * Att_MOONSALT_KNEE_DROP2 is a jumping knee-drop special run through mvxy data.
 * Att_RESURRECTION2 is a resurrection move not reached from the table: it refills vitality each
 * frame at the rate get_life_add_point2 picks from the animation's cg_type, then drops and lands.
 * Att_PL13_TOKUSHUKOUDOU is the personal action: super gauge on cg_type 40 and a strike power
 * boost of 10 (capped 10) on cg_type 20.
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "PLS02.h"
#include "PLSGAUGE.h"
#include "CALDIR.h"
#include "CHARMOVE.h"
#include "charmove_2.h"
#include "Grade.h"
#include "PLPAT.h"
#include "PLS01.h"
#include "PLPAT13.h"


/* 2i 0601614C, 3s-exact: sf3 src/PLPAT13.c:28 pl13_extra_attack */
void pl13_extra_attack(PLW* wk) {
    pl13_exatt_table[wk->wu.routine_no[2] - 16](wk);
}



/* 2i 06016162, 3s-near: sf3 src/PLPAT13.c:34 Att_MOONSALT_KNEE_DROP2 */
void Att_MOONSALT_KNEE_DROP2(PLW* wk) {
    PLW* twk;
    s16 ex;
    s16 ey;
    switch (wk->wu.routine_no[3]) {
    case 0:
        wk->wu.routine_no[3]++;
        wk->wu.rl_flag = wk->wu.rl_waza;
        set_char_move_init(&wk->wu, 5, wk->as->char_ix);
        setup_mvxy_data(&wk->wu, wk->as->data_ix);
        twk = (PLW*)wk->wu.target_adrs;
        if (wk->wu.rl_flag) {
            ex = twk->wu.position_x - mnd_em_tall2[twk->player_number][0];
        } else {
            ex = twk->wu.position_x + mnd_em_tall2[twk->player_number][0];
        }
        ey = mnd_em_tall2[twk->player_number][1];
        wk->wu.mvxy.a[0].sp = 0;
        cal_delta_speed(&wk->wu, wk->as->r_no, ex, ey, 2, 2);
        if (wk->wu.rl_flag == 0) {
            wk->wu.mvxy.a[0].sp = -wk->wu.mvxy.a[0].sp;
            wk->wu.mvxy.d[0].sp = -wk->wu.mvxy.d[0].sp;
        }
        break;
    case 1:
        char_move(&wk->wu);
        if (wk->wu.cg_type == 20) {
            wk->wu.routine_no[3]++;
            wk->wu.cg_type = 0;
            add_mvxy_speed(&wk->wu);
        }
        break;
    case 2:
        jumping_union_process(&wk->wu, 3);
        break;
    case 3:
        char_move(&wk->wu);
        break;
    }
}



/* provisional name */
/* 2i 060162A0, 3s-exact: sf3 src/PLPAT13.c:78 Att_RESURRECTION2 */
void Att_RESURRECTION2(PLW* wk) {
    wk->scr_pos_set_flag = 0;
    switch (wk->wu.routine_no[3]) {
    case 0:
        wk->wu.routine_no[3]++;
        wk->wu.direction = 0;
        reset_mvxy_data(&wk->wu);
        set_char_move_init(&wk->wu, 5, wk->as->char_ix);
        round_slow_flag = 0;
        break;
    case 1:
        char_move(&wk->wu);
        if (wk->wu.cg_type) {
            wk->wu.direction = get_life_add_point2(wk->wu.cg_type, wk->wu.direction);
            wk->wu.cg_type = 0;
        }
        wk->wu.vital_new += wk->wu.direction;
        if (wk->wu.vital_new < wk->wu.vitality) {
            return;
        } else {
            wk->wu.vital_new = wk->wu.vitality;
        }
        wk->wu.mvxy.d[1].sp = -0x8000;
        wk->wu.direction = 0;
        wk->wu.routine_no[3]++;
        if (wk->wu.vital_new < 0) {
            wk->wu.vital_new = 0;
        }
        char_move_cmja(&wk->wu);
        break;
    case 2:
        jumping_union_process(&wk->wu, 3);
        break;
    default:
        char_move(&wk->wu);
        break;
    }
}



/* provisional name */
/* 2i 0601637C, 3s-exact: sf3 src/PLPAT13.c:120 get_life_add_point2 */
s32 get_life_add_point2(cg_type, rate)
    u8 cg_type;
    s16 rate;
{
    u16 ix = cg_type - 20;
    if (ix < 9) {
        rate = glap_table2[ix >> 1];
    }
    return rate;
}



/* 2i 06016398, 3s-near: sf3 src/PLPAT13.c:133 Att_PL13_TOKUSHUKOUDOU */
void Att_PL13_TOKUSHUKOUDOU(PLW* wk) {
    wk->scr_pos_set_flag = 0;
    switch (wk->wu.routine_no[3]) {
    case 0:
        wk->wu.routine_no[3]++;
        wk->wu.rl_flag = wk->wu.rl_waza;
        set_char_move_init((WORK*)wk, 5, wk->as->char_ix);
        break;
    case 1:
        char_move((WORK*)wk);
        if (wk->wu.cg_type == 40) {
            wk->wu.cg_type = 0;
            add_sp_arts_gauge_tokushu(wk);
        }
        if (wk->wu.cg_type == 20) {
            wk->wu.cg_type = 0;
            wk->tk_dageki += 10;
            if (wk->tk_dageki > 10) {
                wk->tk_dageki = 10;
            }
        }
        break;
    }
}
