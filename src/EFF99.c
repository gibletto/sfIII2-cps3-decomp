/*
 * EFF99.C  Effect 99: PERFECT mark
 *
 * effect_99_init (from Disp_Perfect_Mark in manage_2.c: index 77, then 78 with the winner's perfect
 * count) shows a select-screen sprite (sel_pl_char_table) after a delay, drawn relative to BG1;
 * effect_99_move frees it when Disp_PERFECT is cleared.
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
#include "EFF99.h"



void effect_99_move(WORK_Other* ewk) {
    switch (ewk->wu.routine_no[0]) {
    case 0:
        if (--ewk->wu.dir_timer != 0) {
            return;
        }
        ewk->wu.routine_no[0]++;
        ewk->wu.disp_flag = 1;
        break;
    case 1:
        if (Disp_PERFECT == 0) {
            ewk->wu.disp_flag = 0;
            ewk->wu.routine_no[0] = 99;
            return;
        }
        break;
    default:
        all_cgps_put_back(ewk);
        push_effect_work((WORK*)ewk);
        return;
    }
    ewk->wu.position_x = bg_w.bgw[1].xy[0].disp.pos + ewk->wu.dm_vital;
    ewk->wu.position_y = bg_w.bgw[1].xy[1].disp.pos + base_y_pos + 136;
    sort_push_request4(&ewk->wu);
}



s32 effect_99_init(s16 index, s16 timer, s16 ip) {
    WORK_Other* ewk;
    s16 ix;
    if ((ix = pull_effect_work(4)) == -1) {
        return -1;
    }
    ewk = (WORK_Other*)frw[ix];
    ewk->wu.be_flag = 1;
    ewk->wu.id = 99;
    ewk->wu.work_id = 16;
    ewk->wu.cgromtype = 1;
    ewk->wu.my_col_mode = 0x4200;
    ewk->wu.my_col_code = 0x2039;
    ewk->wu.my_family = 2;
    ewk->wu.char_index = index;
    ewk->wu.char_table[0] = sel_pl_char_table;
    ewk->wu.dir_timer = timer;
    ewk->wu.position_z = 10;
    if (index == 77) {
        ewk->wu.dm_vital = -8;
        set_char_move_init(&ewk->wu, 0, ewk->wu.char_index);
    } else {
        ewk->wu.dm_vital = 46;
        set_char_move_init2(&ewk->wu, 0, ewk->wu.char_index, ip, 0);
    }
    return 0;
}



