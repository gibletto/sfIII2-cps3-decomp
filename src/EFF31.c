/*
 * EFF31.C  Effect 31: win-pose companion
 *
 * Like effect 30: effect_31_init creates a companion for a win pose (from win_pl) placed off
 * to one side of the player; effect_31_move brings it in over 120 frames with a shadow and
 * plays its following animations, moving the shadow with the animation.
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "ta_sub.h"
#include "CALDIR.h"
#include "CHARMOVE.h"
#include "charmove_2.h"
#include "aboutspr.h"
#include "EFFECT.h"
#include "effect_2.h"
#include "bg_sub.h"
#include "bg_sub_2.h"
#include "bg_sub_3.h"
#include "bg_sub_4.h"
#include "bg_sub_5.h"
#include "EFF31.h"

/* routine_no[0] */
#define R0_INIT         0       /* show with a shadow, aim at the player */
#define R0_ENTER        1       /* walk in beside the player */
#define R0_ARRIVE       2       /* play the arrival pattern */
#define R0_POSE         3       /* pose, moving the shadow with it */
#define R0_HIDE         4       /* hide it and its shadow */
#define R0_END          5       /* one more frame */
#define R0_KILL         6       /* (default) put the work back */



void effect_31_move(WORK_Other* ewk) {
    switch (ewk->wu.routine_no[0]) {
    case R0_INIT:
        ewk->wu.routine_no[0]++;
        ewk->wu.disp_flag = 1;
        ewk->wu.kage_flag = 1;
        ewk->wu.kage_hx = 0;
        ewk->wu.kage_hy = -10;
        ewk->wu.kage_prio = 71;
        ewk->wu.kage_char = 16;
        set_char_move_init(&ewk->wu, 0, ewk->wu.char_index);
        ewk->wu.old_rno[0] = 120;
        cal_initial_speed(&ewk->wu, ewk->wu.old_rno[0], ewk->wu.old_rno[1], ewk->wu.xyz[1].disp.pos);
        break;
    case R0_ENTER:
        if (!EXE_flag && !Game_pause) {
            char_move(&ewk->wu);
            add_x_sub(ewk);
            add_y_sub(ewk);
            ewk->wu.old_rno[0]--;
            if (ewk->wu.old_rno[0] <= 0) {
                ewk->wu.routine_no[0]++;
                set_char_move_init(&ewk->wu, 0, 1);
            }
        }
        suzi_sync_pos_set(ewk);
        sort_push_request(&ewk->wu);
        break;
    case R0_ARRIVE:
        if (!EXE_flag && !Game_pause) {
            char_move(&ewk->wu);
            if (ewk->wu.cg_type == 0xFF) {
                ewk->wu.routine_no[0]++;
                set_char_move_init(&ewk->wu, 0, 3);
            }
        }
        suzi_sync_pos_set(ewk);
        sort_push_request(&ewk->wu);
        break;
    case R0_POSE:
        if (!EXE_flag && !Game_pause) {
            char_move(&ewk->wu);
            if (ewk->wu.cg_type == 10) {
                ewk->wu.cg_type = 0;
                ewk->wu.kage_hx += 4;
            }
        }
        suzi_sync_pos_set(ewk);
        sort_push_request(&ewk->wu);
        break;
    case R0_HIDE:
        ewk->wu.disp_flag = 0;
        ewk->wu.kage_flag = 0;
        ewk->wu.routine_no[0]++;
        break;
    case R0_END:
        ewk->wu.routine_no[0]++;
        break;
    default:
        push_effect_work(&ewk->wu);
        break;
    }
}



/* none when Version_Type is 3 */
s32 effect_31_init(WORK* wk) {
    s16 ix;
    WORK_Other* ewk;
    if (Version_Type == 3) {
        return -1;
    }
    ix = pull_effect_work(4);
    if (ix == -1) {
        return -1;
    }
    ewk = (WORK_Other*)frw[ix];
    ewk->wu.be_flag = 1;
    ewk->wu.id = 31;
    ewk->master_id = wk->id;
    ewk->wu.cgromtype = 1;
    ewk->wu.my_col_mode = wk->my_col_mode;
    ewk->wu.my_col_code = wk->my_col_code + 1;
    if (wk->id) {
        ewk->wu.my_col_code = wk->my_col_code + 2;
    }
    if (Player_Color[wk->id] == 6) {
        ewk->wu.my_col_code = wk->my_col_code + 3;
    }
    ewk->wu.my_family = wk->my_family;
    ewk->my_master = (u32*)wk;
    ewk->wu.target_adrs = wk->target_adrs;
    ewk->wu.rl_flag = wk->rl_flag;
    if (wk->rl_flag) {
        if (wk->xyz[0].disp.pos < bg_w.bgw[1].wxy[0].disp.pos) {
            ewk->wu.xyz[0].disp.pos = wk->xyz[0].disp.pos - 256;
        } else {
            ewk->wu.xyz[0].disp.pos = bg_w.bgw[1].wxy[0].disp.pos - bg_w.pos_offset - 32;
        }
        ewk->wu.old_rno[1] = wk->xyz[0].disp.pos + 80;
    } else {
        if (wk->xyz[0].disp.pos > bg_w.bgw[1].wxy[0].disp.pos) {
            ewk->wu.xyz[0].disp.pos = wk->xyz[0].disp.pos + 256;
        } else {
            s16 xx = bg_w.pos_offset;
            xx += bg_w.bgw[1].wxy[0].disp.pos;
            xx += 32;
            ewk->wu.xyz[0].disp.pos = xx;
        }
        ewk->wu.old_rno[1] = wk->xyz[0].disp.pos - 80;
    }
    ewk->wu.xyz[1].disp.pos = wk->xyz[1].disp.pos - 12;
    ewk->wu.my_priority = 28;
    ewk->wu.position_z = 28;
    ewk->wu.char_table[0] = etc3_char_table;
    ewk->wu.char_index = 0;
    ewk->wu.sync_suzi = 0;
    suzi_offset_set(&ewk->wu);
    return 0;
}
