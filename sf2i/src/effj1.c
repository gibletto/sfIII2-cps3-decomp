/*
 * EFFJ1.C  Effect J1 (2nd Impact)
 *
 * In 3s effect J1 is an empty routine. In 2i it is an ending object: effect_J1_init places
 * pattern 55 of etc2_char_table and draws three polygon quads; effect_J1_move waits for
 * end_obj_sync, then moves BG layer 5 to 768 and sets its family, waits 180 frames and cycles
 * its extra colour through effj1_col_tbl (timer, colour) for ever.
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "aboutspr.h"
#include "EFFECT.h"
#include "effect_2.h"
#include "CHARMOVE.h"
#include "charmove_2.h"
#include "ta_sub.h"
#include "fifo.h"
#include "sys_config.h"
#include "effj1.h"

extern const s16 effj1_col_tbl[4][2];



/* 2i 060ECC18 */
void effect_J1_move(WORK_Other* ewk) {
    switch (ewk->wu.routine_no[0]) {
    case 0:
        ewk->wu.routine_no[0]++;
        ewk->wu.disp_flag = 1;
        set_char_move_init(&ewk->wu, 0, 55);
        disp_pos_trans_entry(ewk);
        break;
    case 1:
        if (end_obj_sync) {
            ewk->wu.routine_no[0]++;
            ewk->wu.old_rno[3] = 180;
            bg_w.bgw[5].xy[0].disp.pos = 768;
            bg_w.bgw[5].position_x = 768 - bg_w.pos_offset;
            Family_Set_W(6, -bg_w.bgw[5].position_x & 0x3FF, 768);
        }
        disp_pos_trans_entry(ewk);
        break;
    case 2:
        ewk->wu.old_rno[3]--;
        if (ewk->wu.old_rno[3] <= 0) {
            ewk->wu.routine_no[0]++;
            ewk->wu.old_rno[1] = 0;
            ewk->wu.old_rno[0] = effj1_col_tbl[ewk->wu.old_rno[1]][0];
        }
        disp_pos_trans_entry(ewk);
        break;
    case 3:
        ewk->wu.old_rno[0]--;
        if (ewk->wu.old_rno[0] < 0) {
            ewk->wu.extra_col = effj1_col_tbl[ewk->wu.old_rno[1]][1];
            ewk->wu.old_rno[1]++;
            ewk->wu.old_rno[1] &= 3;
            ewk->wu.old_rno[0] = effj1_col_tbl[ewk->wu.old_rno[1]][0];
        }
        disp_pos_trans_entry(ewk);
        break;
    default:
        all_cgps_put_back(ewk);
        push_effect_work(&ewk->wu);
        break;
    }
}



/* 2i 060ECD7C */
s32 effect_J1_init(void) {
    WORK_Other* ewk;
    s16 ix;
    if ((ix = pull_effect_work(4)) == -1) {
        return -1;
    }
    ewk = (WORK_Other*)frw[ix];
    ewk->wu.be_flag = 1;
    ewk->wu.id = 191;
    ewk->wu.work_id = 16;
    ewk->wu.cgromtype = 1;
    ewk->wu.rl_flag = 0;
    ewk->wu.my_col_mode = 0x4200;
    ewk->wu.dead_f = 0;
    ewk->wu.my_family = 2;
    ewk->wu.my_col_code = 0x2120;
    *ewk->wu.char_table = etc2_char_table;
    ewk->wu.xyz[0].disp.pos = 0x200;
    ewk->wu.xyz[1].disp.pos = 36;
    ewk->wu.my_priority = ewk->wu.position_z = 70;
    ewk->wu.char_index = 55;
    end_obj_sync = 0;
    polygon2d_submit_quad(0x0279B480, 0x9000, 0x80, 79, 79, 79);
    polygon2d_submit_quad(0x027D4D00, 0x9080, 0x80, 79, 79, 79);
    polygon2d_submit_quad(0x027D4E80, 0x9100, 0x80, 79, 79, 79);
    return 0;
}
