/*
 * EFFA1.C  Effect A1: after-image copies of the Akuma entrance object
 *
 * effect_A1_init is called twice by effect_A0_init (EFFA0.C) with n = 1 and 2. Each copy takes
 * its master's position, target x, facing, character table and pattern, uses palette 50 + n
 * and sits n priority steps behind, and waits n * 2 frames before starting.
 * effect_A1_move then runs the copy toward the same target over 40 frames with a shadow, so the
 * two copies trail the master as after-images, and finally hides and frees itself.
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "ta_sub.h"
#include "CALDIR.h"
#include "aboutspr.h"
#include "EFFECT.h"
#include "effect_2.h"
#include "CHARMOVE.h"
#include "bg_sub.h"
#include "bg_sub_2.h"
#include "bg_sub_3.h"
#include "bg_sub_4.h"
#include "bg_sub_5.h"
#include "EFFA1.h"

/* routine_no[0] */
#define R0_WAIT         0       /* wait n * 2 frames */
#define R0_INIT         1       /* show with a shadow, aim at the target */
#define R0_MOVE         2       /* run toward the target for 40 frames */
#define R0_HIDE         3       /* hide the copy and its shadow */
#define R0_END          4       /* one more frame */
#define R0_KILL         5       /* (default) put the work back */



void effect_A1_move(WORK_Other* ewk) {
    switch (ewk->wu.routine_no[0]) {
    case R0_WAIT:
        if (--ewk->wu.old_rno[0] > 0) {
            return;
        }
        ewk->wu.routine_no[0]++;
        break;
    case R0_INIT:
        ewk->wu.routine_no[0]++;
        ewk->wu.disp_flag = 1;
        ewk->wu.kage_flag = 1;
        ewk->wu.kage_hx = 0;
        ewk->wu.kage_hy = -2;
        ewk->wu.kage_prio = 71;
        ewk->wu.kage_char = 18;
        set_char_move_init(&ewk->wu, 0, ewk->wu.char_index);
        ewk->wu.old_rno[0] = 40;
        cal_all_speed_data(&ewk->wu, ewk->wu.old_rno[0], ewk->wu.old_rno[1], ewk->wu.xyz[1].disp.pos, 2, 2);
        break;
    case R0_MOVE:
        add_x_sub(ewk);
        add_y_sub(ewk);
        if (--ewk->wu.old_rno[0] <= 0) {
            ewk->wu.routine_no[0]++;
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



s32 effect_A1_init(WORK* wk, s16 n) {
    WORK_Other* ewk;
    s16 ix;
    if ((ix = pull_effect_work(4)) == -1) {
        return -1;
    }
    ewk = (WORK_Other*)frw[ix];
    ewk->wu.be_flag = 1;
    ewk->wu.id = 101;
    ewk->master_id = wk->id;
    ewk->wu.cgromtype = 1;
    ewk->wu.my_col_mode = wk->my_col_mode;
    ewk->wu.my_col_code = n + 50;
    ewk->wu.my_family = wk->my_family;
    ewk->my_master = (u32*)wk;
    ewk->wu.rl_flag = wk->rl_flag;
    ewk->wu.old_rno[0] = n * 2;
    ewk->wu.xyz[0].disp.pos = wk->xyz[0].disp.pos;
    ewk->wu.xyz[1].disp.pos = wk->xyz[1].disp.pos;
    ewk->wu.old_rno[1] = wk->old_rno[1];
    ewk->wu.my_priority = wk->my_priority + n;
    ewk->wu.position_z = wk->my_priority + n;
    ewk->wu.char_table[0] = wk->char_table[0];
    ewk->wu.char_index = wk->char_index;
    ewk->wu.sync_suzi = 0;
    suzi_offset_set(&ewk->wu);
    return 0;
}
