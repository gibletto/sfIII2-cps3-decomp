/*
 * EFF82.C  Effect 82: win-pose companion that runs in to the winner (first variant)
 *
 * Effect 82 is spawned by Win_07000 (win_pl.c) for character 7's final-round win pose when the
 * win pattern chosen is 0-3. effect_82_init places the object off-screen on the side the winner
 * faces (256 dots out, or just past the BG1 screen edge) and aims it 56 dots from the winner.
 * effect_82_move runs it in with a shadow over 50 frames, requests a voice when it comes within
 * 112 dots, then plays its landing pattern and sets cmwk[1] = 9 in the winner's work so the
 * winner's pose can continue. Uses etc2_char_table index 33 and the winner's palette + 6.
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
#include "SE.h"
#include "se_2.h"
#include "se_3.h"
#include "bg_sub.h"
#include "bg_sub_2.h"
#include "bg_sub_3.h"
#include "bg_sub_4.h"
#include "bg_sub_5.h"
#include "EFF82.h"
#include "EFFECT.h"
#include "effect_2.h"

/* routine_no[0] */
#define R0_INIT         0       /* set up the run with a shadow */
#define R0_RUN          1       /* run in until 112 dots away */
#define R0_CLOSE        2       /* run the rest of the way */
#define R0_POSE         3       /* play the landing pattern */

/* voice master_id * 512 + 350, case 3 follows the master pattern with char_move_index */
void effect_82_move(WORK_Other* ewk) {
    WORK* oya_ptr = (WORK*)ewk->my_master;
    s16 work;
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
        ewk->wu.old_rno[0] = 50;
        cal_all_speed_data(&ewk->wu, ewk->wu.old_rno[0], ewk->wu.old_rno[1], ewk->wu.xyz[1].disp.pos, 2, 2);
        break;
    case R0_RUN:
        if (!EXE_flag && !Game_pause) {
            ewk->wu.old_rno[0]--;
            add_x_sub(ewk);
            add_y_sub(ewk);
            work = ewk->wu.xyz[0].disp.pos - oya_ptr->xyz[0].disp.pos;
            if (work < 0) {
                work = -work;
            }
            if (work <= 112) {
                ewk->wu.routine_no[0]++;
                Sound_SE((ewk->master_id * 512) + 350);
                char_move_z(&ewk->wu);
            }
        }
        suzi_sync_pos_set(ewk);
        sort_push_request(&ewk->wu);
        break;
    case R0_CLOSE:
        if (!EXE_flag && !Game_pause) {
            char_move(&ewk->wu);
            add_x_sub(ewk);
            add_y_sub(ewk);
            ewk->wu.old_rno[0]--;
            if (ewk->wu.old_rno[0] <= 0) {
                ewk->wu.routine_no[0]++;
                oya_ptr->cmwk[1] = 9;
                set_char_move_init(&ewk->wu, 0, 42);
            }
        }
        suzi_sync_pos_set(ewk);
        sort_push_request(&ewk->wu);
        break;
    case R0_POSE:
        if (!EXE_flag && !Game_pause) {
            char_move_index(&ewk->wu, oya_ptr->cg_ix / oya_ptr->cgd_type + 1);
        }
        suzi_sync_pos_set(ewk);
        sort_push_request(&ewk->wu);
        break;
    }
}

s32 effect_82_init(WORK* wk) {
    WORK_Other* ewk;
    s16 ix;
    ix = pull_effect_work(4);
    if (ix == -1) {
        return -1;
    }
    ewk = (WORK_Other*)frw[ix];
    ewk->wu.be_flag = 1;
    ewk->wu.id = 82;
    ewk->master_id = wk->id;
    ewk->wu.cgromtype = 1;
    ewk->wu.my_col_mode = wk->my_col_mode;
    ewk->wu.my_col_code = wk->my_col_code + 6;
    ewk->wu.my_family = wk->my_family;
    ewk->my_master = (u32*)wk;
    ewk->wu.rl_flag = wk->rl_flag;
    if (wk->rl_flag) {
        if (wk->xyz[0].disp.pos > bg_w.bgw[1].wxy[0].disp.pos) {
            ewk->wu.xyz[0].disp.pos = wk->xyz[0].disp.pos + 256;
        } else {
            s16 pos = bg_w.pos_offset;
            pos += bg_w.bgw[1].wxy[0].disp.pos;
            pos += 32;
            ewk->wu.xyz[0].disp.pos = pos;
        }
        ewk->wu.old_rno[1] = wk->xyz[0].disp.pos + 56;
    } else {
        if (wk->xyz[0].disp.pos < bg_w.bgw[1].wxy[0].disp.pos) {
            ewk->wu.xyz[0].disp.pos = wk->xyz[0].disp.pos - 256;
        } else {
            ewk->wu.xyz[0].disp.pos = bg_w.bgw[1].wxy[0].disp.pos - bg_w.pos_offset - 32;
        }
        ewk->wu.old_rno[1] = wk->xyz[0].disp.pos - 56;
    }
    ewk->wu.xyz[1].disp.pos = wk->xyz[1].disp.pos - 12;
    ewk->wu.my_priority = wk->my_priority - 12;
    ewk->wu.position_z = ewk->wu.my_priority - 12;
    *ewk->wu.char_table = etc2_char_table;
    ewk->wu.char_index = 33;
    ewk->wu.sync_suzi = 0;
    suzi_offset_set(&ewk->wu);
    return 0;
}
