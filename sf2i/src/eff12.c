/*
 * EFF12.C  Animated stage props (object set 12)
 *
 * Stage background props that play a character animation in place.
 * effect_12_init(type) creates one object per entry of scr_obj_data12[type] with its family,
 * colour, position, priority and animation; effect_12_move runs char_move each frame
 * (stopped during EXE_flag/Game_pause), draws the prop with disp_pos_trans_entry and frees
 * it when compel_dead_check says the stage is being torn down.
 * Used by the BG040, BG120, BG140, BG190 and second bonus-stage init routines.
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "CHARMOVE.h"
#include "charmove_2.h"
#include "ta_sub.h"
#include "EFFECT.h"
#include "effect_2.h"
#include "aboutspr.h"
#include "eff12.h"
#include "bg_sub_5.h"



/* 2i 02007BC0 */
const s16* scr_obj_data12[6] = {
    (const s16*)&scr_obj_num12[11],
    (const s16*)&scr_obj_num12[27],
    (const s16*)&scr_obj_num12[51],
    (const s16*)&scr_obj_num12[91],
    (const s16*)&scr_obj_num12[107],
    (const s16*)&scr_obj_num12[123],
};


void effect_12_move(WORK_Other* ewk) {
    if (obr_no_disp_check()) {
        return;
    }
    switch (ewk->wu.routine_no[0]) {
    case 0:
        ewk->wu.routine_no[0]++;
        ewk->wu.disp_flag = 1;
        set_char_move_init(&ewk->wu, 0, ewk->wu.char_index);
        break;
    case 1:
        if (compel_dead_check(ewk)) {
            ewk->wu.routine_no[0]++;
            ewk->wu.disp_flag = 0;
            break;
        }
        if (!EXE_flag && !Game_pause && !EXE_obroll) {
            char_move(&ewk->wu);
        }
        disp_pos_trans_entry_s(ewk);
        break;
    default:
        all_cgps_put_back(&ewk->wu);
        push_effect_work(&ewk->wu);
        break;
    }
}



/* 2i 060C4D7A, 3s-near: sf3 src/eff12.c:67 effect_12_init */
s32 effect_12_init(s16 type) {
    WORK_Other* ewk;
    s16 ix;
    s16 lp_cnt = scr_obj_num12[type];
    s16 i;
    const s16* data_ptr;
    if (lp_cnt == 0) {
        return;
    }
    data_ptr = scr_obj_data12[type];
    for (i = 0; i < lp_cnt; i++) {
        if ((ix = pull_effect_work(4)) == -1) {
            return -1;
        }
        ewk = (WORK_Other*)frw[ix];
        ewk->wu.be_flag = 1;
        ewk->wu.id = 12;
        ewk->wu.work_id = 16;
        ewk->wu.cgromtype = 1;
        ewk->wu.rl_flag = 0;
        ewk->wu.my_col_mode = 0x4200;
        ewk->wu.type = i;
        ewk->wu.dead_f = *data_ptr++;
        ewk->wu.my_family = *data_ptr++;
        ewk->wu.my_col_code = *data_ptr++;
        ewk->wu.xyz[0].disp.pos = *data_ptr++;
        ewk->wu.xyz[1].disp.pos = *data_ptr++;
        ewk->wu.my_priority = ewk->wu.position_z = *data_ptr++;
        ewk->wu.char_index = *data_ptr++;
        ewk->wu.sync_suzi = *data_ptr++;
        ewk->wu.char_table[0] = char_add[bg_w.stage][bg_w.area];
        suzi_offset_set(&ewk->wu);
    }
    return 0;
}
