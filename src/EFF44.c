/*
 * EFF44.C  Effect 44 (animated stage objects)
 *
 * Effect 44 creates the animated objects of scr_obj_data44 for a stage and animates them
 * until killed; it is used by the stage 02-06, 10, 11, 13 and 16 backgrounds.
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "CHARMOVE.h"
#include "charmove_2.h"
#include "ta_sub.h"
#include "aboutspr.h"
#include "EFFECT.h"
#include "effect_2.h"
#include "bg_sub.h"
#include "bg_sub_2.h"
#include "bg_sub_3.h"
#include "bg_sub_4.h"
#include "bg_sub_5.h"
#include "SYS_sub.h"
#include "EFF44.h"



const s16* scr_obj_data44[9] = {
    (const s16*)&scr_obj_num44[9],
    (const s16*)&scr_obj_num44[57],
    (const s16*)&scr_obj_num44[73],
    (const s16*)&scr_obj_num44[81],
    (const s16*)&scr_obj_num44[161],
    (const s16*)&scr_obj_num44[185],
    (const s16*)&scr_obj_num44[193],
    (const s16*)&scr_obj_num44[257],
    (const s16*)&scr_obj_num44[265],
};


/* provisional name */
void effect_44_move(WORK_Other* ewk) {
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
        disp_pos_trans_entry_rs(ewk);
        break;
    default:
        all_cgps_put_back(ewk);
        push_effect_work((WORK*)ewk);
        break;
    }
}



s32 effect_44_init(s16 type) {
    WORK_Other* ewk;
    s16 ix;
    s16 lp_cnt = scr_obj_num44[type];
    s16 i;
    const s16* data_ptr;
    if (lp_cnt == 0) {
        return;
    }
    data_ptr = scr_obj_data44[type];
    for (i = 0; i < lp_cnt; i++) {
        if ((ix = pull_effect_work(4)) == -1) {
            return -1;
        }
        ewk = (WORK_Other*)frw[ix];
        ewk->wu.be_flag = 1;
        ewk->wu.id = 44;
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
