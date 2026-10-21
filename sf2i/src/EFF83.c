/*
 * EFF83.C  Effect 83: win-pose companion that runs in to the winner (second variant)
 *
 * The twin of effect 82, spawned by Win_07000 (win_pl.c) for character 7's final-round win pose
 * when the win pattern chosen is above 3. effect_83_init starts the object off-screen on the
 * winner's facing side; effect_83_move runs it toward the winner with a shadow, requests a voice
 * when it is within 112 dots, then switches to pattern 35 and sets cmwk[1] = 9 in the winner's
 * work to release the winner's pose. Uses etc2_char_table index 34.
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
#include "EFF83.h"



/* 2i 060D5434, 3s-near: sf3 src/EFF83.c:34 effect_83_move */
void effect_83_move(WORK_Other* ewk) {
    WORK* oya_ptr = (WORK*)ewk->my_master;
    s16 work;
    switch (ewk->wu.routine_no[0]) {
    case 0:
        ewk->wu.routine_no[0]++;
        ewk->wu.disp_flag = 1;
        ewk->wu.kage_flag = 1;
        ewk->wu.kage_hx = 0;
        ewk->wu.kage_hy = -10;
        ewk->wu.kage_prio = 71;
        ewk->wu.kage_char = 16;
        set_char_move_init(&ewk->wu, 0, ewk->wu.char_index);
        ewk->wu.old_rno[0] = 50;
        cal_all_speed_data(&ewk->wu, ewk->wu.old_rno[0], oya_ptr->xyz[0].disp.pos, ewk->wu.xyz[1].disp.pos, 2, 2);
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
            if (work <= 112) {
                ewk->wu.routine_no[0]++;
                Sound_SE((ewk->master_id * 512) + 350);
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
                oya_ptr->cmwk[1] = 9;
                set_char_move_init(&ewk->wu, 0, 35);
            }
        }
        suzi_sync_pos_set(ewk);
        sort_push_request(&ewk->wu);
        break;
    case 3:
        if (!EXE_flag && !Game_pause) {
            char_move_index(&ewk->wu, oya_ptr->cg_ix / oya_ptr->cgd_type + 1);
        }
        suzi_sync_pos_set(ewk);
        sort_push_request(&ewk->wu);
        break;
    }
}



s32 effect_83_init(WORK* wk) {
    s16 s;
    WORK_Other* o;
    s = pull_effect_work(4);
    if (s == -1) {
        return -1;
    }
    o = (WORK_Other*)frw[s];
    o->wu.be_flag = 1;
    o->wu.id = 83;
    o->master_id = wk->id;
    o->wu.cgromtype = 1;
    o->wu.my_col_mode = wk->my_col_mode;
    o->wu.my_col_code = wk->my_col_code + 6;
    o->wu.my_family = wk->my_family;
    o->my_master = (u32*)wk;
    o->wu.rl_flag = wk->rl_flag;
    if (wk->rl_flag) {
        if (wk->xyz[0].disp.pos > bg_w.bgw[1].wxy[0].disp.pos) {
            o->wu.xyz[0].disp.pos = wk->xyz[0].disp.pos + 256;
        } else {
            s16 v = bg_w.pos_offset;
            v += bg_w.bgw[1].wxy[0].disp.pos;
            v += 32;
            o->wu.xyz[0].disp.pos = v;
        }
        o->wu.old_rno[2] = wk->xyz[0].disp.pos + 56;
    } else {
        if (wk->xyz[0].disp.pos < bg_w.bgw[1].wxy[0].disp.pos) {
            o->wu.xyz[0].disp.pos = wk->xyz[0].disp.pos - 256;
        } else {
            o->wu.xyz[0].disp.pos = bg_w.bgw[1].wxy[0].disp.pos - bg_w.pos_offset - 32;
        }
        o->wu.old_rno[2] = wk->xyz[0].disp.pos - 56;
    }
    o->wu.xyz[1].disp.pos = wk->xyz[1].disp.pos - 12;
    o->wu.my_priority = wk->my_priority - 12;
    o->wu.position_z = o->wu.my_priority - 12;
    o->wu.char_table[0] = etc2_char_table;
    o->wu.char_index = 34;
    o->wu.sync_suzi = 0;
    suzi_offset_set(&o->wu);
    return 0;
}
