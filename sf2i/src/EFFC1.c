/*
 * EFFC1.C  Effect C1: companion that runs in to the loser after the final round
 *
 * effect_C1_init is called by Lose_20000 (lose_pl.c) when the match is decided. It starts the
 * object just past the BG1 screen edge on the loser's facing side (etc2_char_table pattern 36,
 * the loser's palette + 6). effect_C1_move runs it toward the loser with a shadow over 64
 * frames (to the loser's x when the loser shows pattern 67, else 74 dots in front), requests a
 * voice when it comes within 0x90 dots, then switches to pattern 37 or 38 and keeps animating.
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
#include "SE.h"
#include "se_2.h"
#include "se_3.h"
#include "bg_sub.h"
#include "bg_sub_2.h"
#include "bg_sub_3.h"
#include "bg_sub_4.h"
#include "bg_sub_5.h"
#include "EFFC1.h"



/* 2i 060DCA4C, 3s-near: sf3 src/EFFC1.c:34 effect_C1_move; 2i: voice master_id * 0x200 + 0x15E */
void effect_C1_move(WORK_Other* ewk) {
    WORK* oya_ptr = (WORK*)ewk->my_master;
    s16 work;
    switch (ewk->wu.routine_no[0]) {
    case 0:
        ewk->wu.routine_no[0]++;
        ewk->wu.disp_flag = 1;
        ewk->wu.kage_flag = 1;
        ewk->wu.kage_hx = 0;
        ewk->wu.kage_prio = 71;
        ewk->wu.kage_char = 16;
        set_char_move_init(&ewk->wu, 0, ewk->wu.char_index);
        ewk->wu.old_rno[0] = 64;
        if (oya_ptr->char_index == 67) {
            work = oya_ptr->xyz[0].disp.pos;
        } else if (oya_ptr->rl_flag) {
            work = oya_ptr->xyz[0].disp.pos + 74;
        } else {
            work = oya_ptr->xyz[0].disp.pos - 74;
        }
        cal_all_speed_data(&ewk->wu, ewk->wu.old_rno[0], work, ewk->wu.xyz[1].disp.pos, 2, 2);
        break;
    case 1:
        if (!EXE_flag && !Game_pause) {
            ewk->wu.old_rno[0]--;
            add_x_sub(ewk);
            add_y_sub(ewk);
            work = ewk->wu.xyz[0].disp.pos - oya_ptr->xyz[0].disp.pos;
            if (work < 0) {
                work = -work;
            }
            if (work <= 0x90) {
                ewk->wu.routine_no[0]++;
                Sound_SE((ewk->master_id * 0x200) + 0x15E);
                char_move_z(&ewk->wu);
            }
        }
        suzi_sync_pos_set(ewk);
        sort_push_request(&ewk->wu);
        break;
    case 2:
        if (!EXE_flag && !Game_pause) {
            char_move(&ewk->wu);
            add_x_sub(ewk);
            add_y_sub(ewk);
            ewk->wu.old_rno[0]--;
            if (ewk->wu.old_rno[0] <= 0) {
                ewk->wu.routine_no[0]++;
                if (oya_ptr->char_index == 67) {
                    set_char_move_init(&ewk->wu, 0, 37);
                } else {
                    set_char_move_init(&ewk->wu, 0, 38);
                }
            }
        }
        suzi_sync_pos_set(ewk);
        sort_push_request(&ewk->wu);
        break;
    case 3:
        if (!EXE_flag && !Game_pause) {
            char_move(&ewk->wu);
        }
        suzi_sync_pos_set(ewk);
        sort_push_request(&ewk->wu);
        break;
    }
}



/* 2i 060DCC14, 3s-near: sf3 src/EFFC1.c:104 effect_C1_init */
s32 effect_C1_init(WORK* wk) {
    WORK_Other* ewk;
    s16 ix;
    if ((ix = pull_effect_work(4)) == -1) {
        return -1;
    }
    ewk = (WORK_Other*)frw[ix];
    ewk->wu.be_flag = 1;
    ewk->wu.id = 121;
    ewk->master_id = wk->id;
    ewk->wu.cgromtype = 1;
    ewk->wu.my_col_mode = wk->my_col_mode;
    ewk->wu.my_col_code = wk->my_col_code + 6;
    ewk->wu.my_family = wk->my_family;
    ewk->my_master = (u32*)wk;
    ewk->wu.rl_flag = wk->rl_flag;
    if (wk->rl_flag) {
        ewk->wu.xyz[0].disp.pos = bg_w.bgw[1].wxy[0].disp.pos + (bg_w.pos_offset + 16);
    } else {
        ewk->wu.xyz[0].disp.pos = bg_w.bgw[1].wxy[0].disp.pos - (bg_w.pos_offset + 16);
    }
    ewk->wu.xyz[1].disp.pos = wk->xyz[1].disp.pos - 16;
    ewk->wu.kage_hy = -8;
    ewk->wu.my_priority = wk->my_priority - 12;
    ewk->wu.position_z = ewk->wu.my_priority - 12;
    *ewk->wu.char_table = etc2_char_table;
    ewk->wu.char_index = 36;
    ewk->wu.sync_suzi = 0;
    suzi_offset_set(&ewk->wu);
    return 0;
}
