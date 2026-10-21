/*
 * PLPAT09.C  Player 09 (Oro) special attack routines
 *
 * Character-specific attack routines for player number 9, dispatched by pl09_extra_attack
 * through pl09_exatt_table.
 * set_tenguiwa (an effect-init routine) summons three rocks from the stage's set for the round
 * and places them from tenguiwa_pos_hosei; Att_JINNCHUUWATARI_EX is the jumping special, with
 * mvxy_table_reader stepping the move data.
 * Att_PL09_TOKUSHUKOUDOU is the personal action: each repeat builds tk_success (up to 13) and
 * cuts the stun gauge timer by the rate in pl09_tk_table.
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
#include "EFF13_KOTP.h"
#include "EFFECT.h"
#include "effect_2.h"
#include "Grade.h"
#include "PLPAT.h"
#include "PLS01.h"
#include "PLPAT09.h"

static void mvxy_table_reader(PLW* wk);



void pl09_extra_attack(PLW* wk) {
    pl09_exatt_table[wk->wu.routine_no[2] - 16](wk);
}




void set_tenguiwa(PLW* wk, u8 data) {
    s16 i;
    s16 j;
    s16 num;
    const u8* tengu;
    WORK* tmw;
    tengu = tenguiwa_stand_by[tenguiwa_stage_data[bg_w.stage][Round_num & 3]];
    for (i = 0; i < 3; i++) {
        effect_13_init((WORK*)wk, tengu[random_16_com() & 7]);
    }
    for (j = 0, i = 0; i < 8; i++) {
        if (!get_my_shell_ix((WORK*)wk, i, &tmw)) {
            continue;
        }
        num = tmw->type - 24;
        if (!tenguiwa_type_flag[num]) {
            continue;
        }
        tmw->old_pos[0] = tenguiwa_pos_hosei[j][0];
        tmw->old_pos[1] = tenguiwa_pos_hosei[j][1];
        tmw->old_pos[2] = tenguiwa_pos_hosei[j][2];
        tmw->scr_mv_x = tenguiwa_pos_hosei[j][3];
        tmw->scr_mv_y = tenguiwa_pos_hosei[j][4];
        tmw->direction = tenguiwa_pos_hosei[j][5];
        j++;
        if (j > 2) {
            break;
        }
    }
}



void Att_PL09_TOKUSHUKOUDOU(PLW* wk) {
    wk->scr_pos_set_flag = 0;
    switch (wk->wu.routine_no[3]) {
    case 0:
        wk->wu.routine_no[3]++;
        wk->tk_success = 0;
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
            if (++wk->tk_success > 13) {
                wk->tk_success = 13;
            }
        }
        if (wk->wu.cg_type == 30) {
            wk->wu.routine_no[3]++;
            wk->wu.cg_type = 0;
            break;
        }
        wk->py->now.timer -= wk->py->recover * pl09_tk_table[wk->tk_success] / 100;
        if (wk->py->now.quantity.h <= 0) {
            wk->py->now.timer = 0;
        }
        break;
    default:
        char_move((WORK*)wk);
        break;
    }
}



void Att_JINNCHUUWATARI_EX(PLW* wk) {
    switch (wk->wu.routine_no[3]) {
    case 0:
        wk->wu.routine_no[3]++;
        wk->wu.rl_flag = wk->wu.rl_waza;
        wk->wu.xyz[1].disp.pos = 0;
        set_char_move_init((WORK*)wk, 5, wk->as->char_ix);
        wk->wu.kow = wk->as->r_no;
        wk->wu.mvxy.index = wk->as->data_ix;
        break;
    case 1:
        char_move((WORK*)wk);
        mvxy_table_reader(wk);
        break;
    case 2:
        mvxy_table_reader(wk);
        jumping_union_process((WORK*)wk, 3);
        break;
    case 3:
        if (wk->wu.cg_type == 1) {
            wk->wu.cg_type = 0;
            wk->wu.routine_no[3] = (wk->wu.routine_no[1] == 0) ? 2 : 4;
            break;
        }
        jumping_union_process((WORK*)wk, 4);
        break;
    case 4:
        char_move((WORK*)wk);
        if (wk->wu.cg_type == 1) {
            wk->wu.cg_type = 0;
            wk->wu.routine_no[3] = (wk->wu.routine_no[1] == 0) ? 2 : 3;
        }
        break;
    }
}



static void mvxy_table_reader(PLW* wk) {
    PLW* twk = (PLW*)wk->wu.target_adrs;
    const s16* curr_kop = &homing_kop[wk->wu.kow][0];
    s16 ex;
    s16 ey;
    if (wk->wu.cg_type == 30) {
        setup_mvxy_data(&wk->wu, wk->wu.mvxy.index);
        wk->wu.mvxy.index++;
        switch (curr_kop[0]) {
        case 0:
            if (wk->wu.xyz[0].disp.pos < twk->wu.xyz[0].disp.pos) {
                ex = twk->wu.xyz[0].disp.pos - homing_hos[wk->wu.kow][twk->player_number][0];
                if (!wk->wu.rl_flag) {
                    ex = wk->wu.xyz[0].disp.pos - (ex - wk->wu.xyz[0].disp.pos);
                }
            } else {
                ex = twk->wu.xyz[0].disp.pos + homing_hos[wk->wu.kow][twk->player_number][0];
                if (wk->wu.rl_flag) {
                    ex = wk->wu.xyz[0].disp.pos + (wk->wu.xyz[0].disp.pos - ex);
                }
            }
            ey = homing_hos[wk->wu.kow][twk->player_number][1];
            wk->wu.mvxy.a[0].sp = 0;
            cal_initial_speed(&wk->wu, curr_kop[1], ex, ey);
            wk->wu.kow = wk->wu.kow + 1;
            break;
        case 1:
            ex = wk->wu.xyz[0].disp.pos;
            if (wk->wu.xyz[0].disp.pos < twk->wu.xyz[0].disp.pos) {
                ex += (twk->wu.xyz[0].disp.pos - wk->wu.xyz[0].disp.pos) / 2;
            } else {
                ex -= (wk->wu.xyz[0].disp.pos - twk->wu.xyz[0].disp.pos) / 2;
            }
            ey = homing_hos[wk->wu.kow][twk->player_number][1];
            wk->wu.mvxy.a[0].sp = 0;
            cal_initial_speed(&wk->wu, curr_kop[1], ex, ey);
            wk->wu.kow++;
        default:
            break;
        }
        if (wk->wu.rl_flag == 0) {
            wk->wu.mvxy.a[0].sp = -wk->wu.mvxy.a[0].sp;
            wk->wu.mvxy.d[0].sp = -wk->wu.mvxy.d[0].sp;
        }
        wk->wu.routine_no[3]++;
        wk->wu.cg_type = 0;
        add_mvxy_speed(&wk->wu);
    }
    if (wk->wu.cg_type == 20) {
        setup_mvxy_data(&wk->wu, wk->wu.mvxy.index);
        wk->wu.mvxy.index++;
        wk->wu.routine_no[3]++;
        wk->wu.cg_type = 0;
        add_mvxy_speed(&wk->wu);
    }
}

