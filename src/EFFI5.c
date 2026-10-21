/*
 * EFFI5.C  Effect I5: ending object synchronised by end_obj_sync
 *
 * Effect I5: effect_I5_init creates an etc2_char_table object at x Gill_Pos_X, y 24, priority
 * 70, and clears end_obj_sync. effect_I5_move shows pattern 54 and waits for end_obj_sync; three
 * seconds later it fades palette 144 in through effI5_fade_tbl, restores it, animates until
 * frame type 9 (setting end_obj_sync to 2) and then drifts down until it is near the floor.
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
#include "CHARMOVE.h"
#include "charmove_2.h"
#include "ta_sub.h"
#include "EFFECT.h"
#include "effect_2.h"
#include "aboutspr.h"
#include "effi6.h"
#include "EFFI5.h"



void effect_I5_move(WORK_Other* ewk) {
    s16 work;
    switch (ewk->wu.routine_no[0]) {
    case 0:
        ewk->wu.routine_no[0]++;
        ewk->wu.disp_flag = 1;
        set_char_move_init(&ewk->wu, 0, 54);
        ewk->wu.old_rno[0] = 0;
        disp_pos_trans_entry(ewk);
        break;
    case 1:
        if (end_obj_sync) {
            ewk->wu.routine_no[0]++;
            ewk->wu.old_rno[1] = 180;
        }
        disp_pos_trans_entry(ewk);
        break;
    case 2:
        ewk->wu.old_rno[1]--;
        if (ewk->wu.old_rno[1] <= 0) {
            ewk->wu.routine_no[0]++;
        }
        disp_pos_trans_entry(ewk);
        break;
    case 3:
        work = effI5_fade_tbl[ewk->wu.old_rno[0]];
        load_any_color_fade(144, work, work, work);
        ewk->wu.old_rno[0]++;
        if (ewk->wu.old_rno[0] > 14) {
            ewk->wu.routine_no[0]++;
        }
        disp_pos_trans_entry(ewk);
        break;
    case 4:
        ewk->wu.routine_no[0]++;
        load_any_color(144);
    case 5:
        char_move(&ewk->wu);
        if (ewk->wu.cg_type == 9) {
            ewk->wu.routine_no[0]++;
            end_obj_sync = 2;
        }
        disp_pos_trans_entry(ewk);
        break;
    case 6:
        char_move(&ewk->wu);
        ewk->wu.xyz[1].cal -= 0x4000;
        if (ewk->wu.xyz[1].disp.pos < 20) {
            ewk->wu.routine_no[0]++;
        }
        disp_pos_trans_entry(ewk);
        return;
    case 7:
        disp_pos_trans_entry(ewk);
        break;
    default:
        all_cgps_put_back(ewk);
        push_effect_work((WORK*)ewk);
        return;
    }
}



s32 effect_I5_init(void) {
    WORK_Other* ewk;
    s16 ix;
    if ((ix = pull_effect_work(4)) == -1) {
        return -1;
    }
    ewk = (WORK_Other*)frw[ix];
    ewk->wu.be_flag = 1;
    ewk->wu.id = 185;
    ewk->master_id = 0;
    ewk->wu.be_flag = 1;
    ewk->wu.work_id = 16;
    ewk->wu.cgromtype = 1;
    ewk->wu.rl_flag = 0;
    ewk->wu.kage_flag = 0;
    ewk->wu.my_col_mode = 0x4200;
    ewk->wu.dead_f = 0;
    ewk->wu.my_family = 2;
    ewk->wu.my_col_code = 0x2120;
    ewk->wu.char_table[0] = etc2_char_table;
    ewk->wu.xyz[0].disp.pos = Gill_Pos_X;
    ewk->wu.xyz[1].disp.pos = 24;
    ewk->wu.my_priority = ewk->wu.position_z = 70;
    ewk->wu.char_index = 10;
    end_obj_sync = 0;
    return 0;
}


