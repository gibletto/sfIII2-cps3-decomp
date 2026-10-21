/*
 * EFF62.C  Effect 62: parts of the alternate background
 *
 * effect_62_init creates 24 parts for a parent from eff62_data_tbl. While the alternate
 * background is active (seraph_flag, another_bg) each part scrolls up or down at its own
 * speed; they are removed when that mode ends. (3rd Strike has effect 61 in this file too; 2nd Impact has it
 * in EFF61.C.)
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "ta_sub.h"
#include "EFFECT.h"
#include "effect_2.h"
#include "aboutspr.h"
#include "CHARMOVE.h"
#include "charmove_2.h"
#include "EFF62.h"
#include "bg_sub.h"
#include "bg_sub_2.h"
#include "bg_sub_3.h"
#include "bg_sub_4.h"
#include "bg_sub_5.h"
#include "EFF61.h"

void effect_62_move(WORK_Other* ewk) {
    WORK_Other* mwk = (WORK_Other*)ewk->my_master;
    if (akebono_flag || !seraph_flag) {
        ewk->wu.routine_no[0] = 99;
    }
    switch (ewk->wu.routine_no[0]) {
    case 0:
        ewk->wu.routine_no[0]++;
        ewk->wu.be_flag = 1;
        ewk->wu.disp_flag = 1;
        set_char_move_init2(&ewk->wu, 0, ewk->wu.char_index, ewk->wu.dir_old + 1, 0);
    case 1:
        switch (another_bg[mwk->wu.type]) {
        case 4:
            ewk->wu.xyz[1].cal -= ewk->wu.mvxy.a[1].sp;
            ewk->wu.disp_flag = 1;
            ewk->wu.cg_flip = 2;
            disp_pos_trans_entry_seraph(ewk);
            break;
        case 1:
            ewk->wu.xyz[1].cal += ewk->wu.mvxy.a[1].sp;
            ewk->wu.disp_flag = 1;
            ewk->wu.cg_flip = 0;
            disp_pos_trans_entry_seraph(ewk);
            break;
        default:
            ewk->wu.disp_flag = 0;
            break;
        }
        break;
    default:
        all_cgps_put_back(ewk);
        push_effect_work(&ewk->wu);
        break;
    }
}

s32 effect_62_init(WORK_Other* oya) {
    WORK_Other* ewk;
    s16 ix;
    s16 i;
    const s16* data_ptr = eff62_data_tbl[0];
    for (i = 0; i < 24; i++) {
        if ((ix = pull_effect_work(4)) == -1) {
            return -1;
        }
        ewk = (WORK_Other*)frw[ix];
        ewk->my_master = (u32*)oya;
        ewk->wu.be_flag = 1;
        ewk->wu.id = 62;
        ewk->wu.work_id = 16;
        ewk->wu.cgromtype = 1;
        ewk->wu.rl_flag = 0;
        ewk->wu.my_col_mode = 0x4200;
        ewk->wu.my_family = 2;
        ewk->wu.my_col_code = 0xC0;
        ewk->wu.my_priority = ewk->wu.position_z = 68;
        ewk->wu.char_table[0] = etc2_char_table;
        ewk->wu.xyz[0].disp.pos = bg_w.bgw[1].pos_x_work;
        ewk->wu.xyz[0].disp.pos += *data_ptr++;
        ewk->wu.xyz[1].disp.pos = *data_ptr++;
        ewk->wu.dir_old = *data_ptr++;
        ewk->wu.char_index = 31;
        ewk->wu.mvxy.a[1].sp = eff62_speed_tbl[ewk->wu.dir_old];
        ewk->wu.mvxy.d[1].sp = 0;
        ewk->wu.sync_suzi = 0;
        suzi_offset_set(&ewk->wu);
    }
    return 0;
}
