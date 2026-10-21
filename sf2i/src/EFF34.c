/*
 * EFF34.C  Effect 34: character companion object
 *
 * Effect 34 is placed beside a character and coloured from its palette. It moves toward the
 * character over 60 frames, waits until the background has scrolled into place, plays its
 * animation (signalling the master through cmwk[1]), turns round and walks away.
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
#include "EFF34.h"



/* 2i 060CB5F4, 3s-near: sf3 src/EFF34.c:29 effect_34_move */
void effect_34_move(WORK_Other* ewk) {
    WORK* oya_ptr = (WORK*)ewk->my_master;
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
        ewk->wu.old_rno[0] = 60;
        cal_initial_speed(&ewk->wu, ewk->wu.old_rno[0], ewk->wu.old_rno[1], ewk->wu.xyz[1].disp.pos);
        break;
    case 1:
        if (EXE_flag || Game_pause || bg_w.bgw[1].xy[1].disp.pos >= 104) {
            suzi_sync_pos_set(ewk);
            sort_push_request(&ewk->wu);
            break;
        }
        char_move(&ewk->wu);
        suzi_sync_pos_set(ewk);
        sort_push_request(&ewk->wu);
        if (ewk->wu.cg_type != 1) {
            break;
        }
        ewk->wu.routine_no[0]++;
        ewk->wu.cg_type = 0;
        oya_ptr->cmwk[1] = 9;
        break;
    case 2:
        if (EXE_flag || Game_pause) {
            suzi_sync_pos_set(ewk);
            sort_push_request(&ewk->wu);
            break;
        }
        char_move(&ewk->wu);
        suzi_sync_pos_set(ewk);
        sort_push_request(&ewk->wu);
        if (ewk->wu.cg_type != 0xFF) {
            break;
        }
        ewk->wu.routine_no[0]++;
        ewk->wu.rl_flag = ewk->wu.rl_flag ? 0 : 1;
        set_char_move_init(&ewk->wu, 0, 0);
        break;
    case 3:
        if (EXE_flag || Game_pause) {
            suzi_sync_pos_set(ewk);
            sort_push_request(&ewk->wu);
            break;
        }
        if (ewk->wu.old_rno[0]--) {
            char_move(&ewk->wu);
            add_x_sub(ewk);
            suzi_sync_pos_set(ewk);
            sort_push_request(&ewk->wu);
            break;
        }
        ewk->wu.routine_no[0]++;
        ewk->wu.disp_flag = 0;
        break;
    case 4:
        ewk->wu.routine_no[0]++;
        break;
    case 5:
    default:
        all_cgps_put_back(&ewk->wu);
        push_effect_work(&ewk->wu);
        break;
    }
}



/* 2i 060CB7F4, 3s-near: sf3 src/EFF34.c:105 effect_34_init; 2i: none when Version_Type is 3 */
s32 effect_34_init(WORK* wk, s32 _p1) {
    WORK_Other* ewk;
    s16 ix;
    if (Version_Type == 3) {
        return -1;
    }
    if ((ix = pull_effect_work(4)) == -1) {
        return -1;
    }
    ewk = (WORK_Other*)frw[ix];
    ewk->wu.be_flag = 1;
    ewk->wu.id = 34;
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
    ewk->wu.rl_flag = wk->rl_flag;
    ewk->wu.xyz[0].disp.pos = wk->xyz[0].disp.pos;
    ewk->wu.xyz[0].disp.pos += (wk->rl_flag ? -48 : 48);
    ewk->wu.xyz[1].disp.pos = wk->xyz[1].disp.pos - 12;
    ewk->wu.my_priority = wk->my_priority - 12;
    ewk->wu.position_z = ewk->wu.my_priority - 12;
    ewk->wu.char_table[0] = etc3_char_table;
    ewk->wu.sync_suzi = 0;
    ewk->wu.char_index = bg_w.stage == 6 ? 4 : 8;
    if (wk->rl_flag) {
        ewk->wu.old_rno[1] = bg_w.bgw[1].wxy[0].disp.pos - (bg_w.pos_offset + 32);
    } else {
        ewk->wu.old_rno[1] = bg_w.bgw[1].wxy[0].disp.pos + (bg_w.pos_offset + 32);
    }
    suzi_offset_set(&ewk->wu);
    return 0;
}
