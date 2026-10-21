/*
 * EFF33.C  Effect 33: appearance companion that reacts to the result
 *
 * effect_33_init (from PLCNTAPP) places a companion beside a player during the appearance.
 * It animates with a shadow until the judgement is complete, then plays the win or lose
 * animation from WinLoseID for its master and ends when the master is killed.
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
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
#include "EFF33.h"



/* 2i 060CB334, 3s-near: sf3 src/EFF33.c:27 effect_33_move */
void effect_33_move(WORK_Other* ewk) {
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
        break;
    case 1:
        suzi_sync_pos_set(ewk);
        sort_push_request(&ewk->wu);
        if (!EXE_flag && !Game_pause) {
            if (pcon_rno[2] == 1 && Event_Judge_Gals == -1) {
                if (Complete_Judgement) {
                    ewk->wu.routine_no[0]++;
                }
            }
        }
        break;
    case 2:
        if (!EXE_flag && !Game_pause) {
            ewk->wu.routine_no[0]++;
            ewk->wu.char_index = WinLoseID[ewk->master_id][Winner_id] + 10;
            set_char_move_init(&ewk->wu, 0, ewk->wu.char_index);
        }
        suzi_sync_pos_set(ewk);
        sort_push_request(&ewk->wu);
        break;
    case 3:
        if (!EXE_flag && !Game_pause) {
            if (ewk->wu.dead_f == 1 || Suicide != 0) {
                ewk->wu.disp_flag = 0;
                ewk->wu.routine_no[0]++;
                break;
            }
            char_move(&ewk->wu);
        }
        suzi_sync_pos_set(ewk);
        sort_push_request(&ewk->wu);
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



/* 2i 060CB4DE, 3s-near: sf3 src/EFF33.c:85 effect_33_init */
s32 effect_33_init(WORK* wk) {
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
    ewk->wu.id = 33;
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
    ewk->wu.xyz[0].disp.pos += wk->rl_flag ? -48 : 48;
    ewk->wu.xyz[1].disp.pos = wk->xyz[1].disp.pos - 12;
    ewk->wu.my_priority = wk->my_priority - 12;
    ewk->wu.position_z = ewk->wu.my_priority - 12;
    ewk->wu.char_table[0] = etc3_char_table;
    ewk->wu.char_index = 7;
    ewk->wu.sync_suzi = 0;
    suzi_offset_set(&ewk->wu);
    return 0;
}
