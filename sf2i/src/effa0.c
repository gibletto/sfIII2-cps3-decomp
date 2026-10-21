/*
 * EFFA0.C  Effect A0: Akuma entrance
 *
 * Effect A0 is Akuma's (Gouki) intrusion entrance: effect_A0_init picks a palette that differs
 * from the opponent's colour (effA0_swap_tbl), places the object off-screen and spawns two A1
 * after-images.
 * effect_A0_move runs in with a shadow, plays its appearance pattern, sets gouki_app, wakes
 * the other player (cmwk[0]), and finally sets Next_Step to hand control back to the game flow.
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "end_sub.h"
#include "end_sub_2.h"
#include "end_sub_3.h"
#include "end_sub_4.h"
#include "end_sub_5.h"
#include "end_sub_6.h"
#include "end_sub_7.h"
#include "color3rd.h"
#include "end_sub_8.h"
#include "EFFA1.h"
#include "ta_sub.h"
#include "CALDIR.h"
#include "CHARMOVE.h"
#include "charmove_2.h"
#include "aboutspr.h"
#include "EFFECT.h"
#include "effect_2.h"
#include "effa0.h"



/* 2i 060D8540, 3s-near: sf3 src/effa0.c:36 effect_A0_move */
void effect_A0_move(WORK_Other* ewk) {
    switch (ewk->wu.routine_no[0]) {
    case 0:
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
    case 1:
        add_x_sub(ewk);
        add_y_sub(ewk);
        ewk->wu.old_rno[0]--;
        if (ewk->wu.old_rno[0] <= 0) {
            ewk->wu.routine_no[0]++;
            char_move_z(&ewk->wu);
        }
        ewk->wu.position_x = ewk->wu.xyz[0].disp.pos;
        ewk->wu.position_y = ewk->wu.xyz[1].disp.pos;
        if (!obr_no_disp_check()) {
            sort_push_request(&ewk->wu);
        }
        break;
    case 2:
        char_move_z(&ewk->wu);
        ewk->wu.disp_flag = 0;
        ewk->wu.kage_flag = 0;
        ewk->wu.routine_no[0]++;
        ewk->wu.position_x = ewk->wu.xyz[0].disp.pos;
        ewk->wu.position_y = ewk->wu.xyz[1].disp.pos;
        if (!obr_no_disp_check()) {
            sort_push_request(&ewk->wu);
        }
        break;
    case 3:
        char_move(&ewk->wu);
        if (ewk->wu.cg_type == 40) {
            gouki_app = 1;
            plw[ewk->master_id ^ 1].wu.cmwk[0] = (ewk->master_id ^ 1) + 1;
            ewk->wu.my_priority = 58;
            ewk->wu.position_z = 58;
            ewk->wu.cg_type = 0;
        }
        if (ewk->wu.cg_type == 50) {
            ewk->wu.routine_no[0]++;
            ewk->wu.disp_flag = 1;
            ewk->wu.kage_flag = 1;
            ewk->wu.cg_type = 0;
        }
        ewk->wu.position_x = ewk->wu.xyz[0].disp.pos;
        ewk->wu.position_y = ewk->wu.xyz[1].disp.pos;
        if (!obr_no_disp_check()) {
            sort_push_request(&ewk->wu);
        }
        break;
    case 4:
        char_move(&ewk->wu);
        if (ewk->wu.cg_type == 0xFF) {
            ewk->wu.routine_no[0]++;
        }
        ewk->wu.position_x = ewk->wu.xyz[0].disp.pos;
        ewk->wu.position_y = ewk->wu.xyz[1].disp.pos;
        if (!obr_no_disp_check()) {
            sort_push_request(&ewk->wu);
        }
        break;
    case 5:
        Next_Step = 1;
        ewk->wu.routine_no[0]++;
        ewk->wu.position_x = ewk->wu.xyz[0].disp.pos;
        ewk->wu.position_y = ewk->wu.xyz[1].disp.pos;
        if (!obr_no_disp_check()) {
            sort_push_request(&ewk->wu);
        }
        break;
    case 6:
        ewk->wu.position_x = ewk->wu.xyz[0].disp.pos;
        ewk->wu.position_y = ewk->wu.xyz[1].disp.pos;
        if (!obr_no_disp_check()) {
            sort_push_request(&ewk->wu);
        }
        break;
    case 7:
        ewk->wu.disp_flag = 0;
        ewk->wu.kage_flag = 0;
        ewk->wu.routine_no[0]++;
        break;
    case 8:
        ewk->wu.routine_no[0]++;
        break;
    default:
        push_effect_work(&ewk->wu);
        return;
    }
}



/* 2i 060D8812, 3s-near: sf3 src/effa0.c:139 effect_A0_init */
s32 effect_A0_init(s16 pl) {
    WORK_Other* ewk;
    PLW* mwk;
    WORK* twk;
    s16 ix;
    s16 offset;
    if ((ix = pull_effect_work(4)) == -1) {
        return -1;
    }
    ewk = (WORK_Other*)frw[ix];
    mwk = &plw[pl];
    twk = (WORK*)mwk->wu.target_adrs;
    ewk->wu.be_flag = 1;
    ewk->wu.id = 100;
    ewk->master_id = mwk->wu.id;
    ewk->wu.cgromtype = 1;
    ewk->wu.my_col_mode = mwk->wu.my_col_mode;
    ewk->wu.my_col_code = 50;
    ewk->wu.my_family = mwk->wu.my_family;
    ewk->my_master = (u32*)mwk;
    ewk->wu.rl_flag = mwk->wu.rl_flag;
    ewk->wu.old_rno[2] = Player_Color[twk->id];
    if (ewk->wu.old_rno[2] == Player_Color[mwk->wu.id]) {
        if (Player_Color[mwk->wu.id] < 7) {
            ewk->wu.old_rno[2] = effA0_swap_tbl[Player_Color[mwk->wu.id]];
        } else {
            ewk->wu.old_rno[2] = 0;
        }
        Player_Color[twk->id] = ewk->wu.old_rno[2];
    }
    if (mwk->wu.rl_flag) {
        if (mwk->wu.xyz[0].disp.pos < bg_w.bgw[1].wxy[0].disp.pos) {
            ewk->wu.xyz[0].disp.pos = mwk->wu.xyz[0].disp.pos - 0x100;
        } else {
            ewk->wu.xyz[0].disp.pos = bg_w.bgw[1].wxy[0].disp.pos - bg_w.pos_offset - 32;
        }
        ewk->wu.old_rno[1] = twk->xyz[0].disp.pos - 16;
    } else {
        if (mwk->wu.xyz[0].disp.pos > bg_w.bgw[1].wxy[0].disp.pos) {
            ewk->wu.xyz[0].disp.pos = mwk->wu.xyz[0].disp.pos + 0x100;
        } else {
            ewk->wu.xyz[0].disp.pos = bg_w.pos_offset + bg_w.bgw[1].wxy[0].disp.pos + 32;
        }
        ewk->wu.old_rno[1] = twk->xyz[0].disp.pos + 16;
    }
    ewk->wu.xyz[1].disp.pos = mwk->wu.xyz[1].disp.pos - 4;
    ewk->wu.my_priority = mwk->wu.my_priority - 12;
    ewk->wu.position_z = mwk->wu.my_priority - 12;
    ewk->wu.char_table[0] = etc3_char_table;
    ewk->wu.char_index = 9;
    ewk->wu.sync_suzi = 0;
    load_any_color(ewk->wu.old_rno[2] + 0xAB);
    load_any_color(0xB2);
    effect_A1_init(&ewk->wu, 1);
    effect_A1_init(&ewk->wu, 2);
    return 0;
}
