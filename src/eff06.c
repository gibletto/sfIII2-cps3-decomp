/*
 * EFF06.C  Stage scenery objects, set 06
 *
 * Second set of per-stage decorative sprites, identical in structure to EFF05 but driven
 * from the scr_obj_num6/scr_obj_data6 tables and drawn with disp_pos_trans_entry_rs.
 * effect_06_init creates one object per table entry for the current stage and area (bg_w.stage and
 * bg_w.area);
 * effect_06_move animates it until compel_dead_check retires it, then frees it.
 * Called from every stage BG init routine alongside effect_05_init.
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
#include "bg_sub.h"
#include "bg_sub_2.h"
#include "bg_sub_3.h"
#include "bg_sub_4.h"
#include "bg_sub_5.h"
#include "eff06.h"



/* by stage and area */
const s16* scr_obj_data6[17][3] = {
    { (const s16*)scr_obj_num6 + 51, (const s16*)scr_obj_num6 + 51, (const s16*)scr_obj_num6 + 51 },
    { (const s16*)scr_obj_num6 + 52, (const s16*)scr_obj_num6 + 52, (const s16*)scr_obj_num6 + 52 },
    { (const s16*)scr_obj_num6 + 53, (const s16*)scr_obj_num6 + 53, (const s16*)scr_obj_num6 + 53 },
    { (const s16*)scr_obj_num6 + 77, (const s16*)scr_obj_num6 + 77, (const s16*)scr_obj_num6 + 77 },
    { (const s16*)scr_obj_num6 + 141, (const s16*)scr_obj_num6 + 141, (const s16*)scr_obj_num6 + 141 },
    { (const s16*)scr_obj_num6 + 157, (const s16*)scr_obj_num6 + 157, (const s16*)scr_obj_num6 + 157 },
    { (const s16*)scr_obj_num6 + 173, (const s16*)scr_obj_num6 + 205, (const s16*)scr_obj_num6 + 205 },
    { (const s16*)scr_obj_num6 + 237, (const s16*)scr_obj_num6 + 237, (const s16*)scr_obj_num6 + 237 },
    { (const s16*)scr_obj_num6 + 238, (const s16*)scr_obj_num6 + 310, (const s16*)scr_obj_num6 + 310 },
    { (const s16*)scr_obj_num6 + 318, (const s16*)scr_obj_num6 + 318, (const s16*)scr_obj_num6 + 318 },
    { (const s16*)scr_obj_num6 + 117, (const s16*)scr_obj_num6 + 117, (const s16*)scr_obj_num6 + 117 },
    { (const s16*)scr_obj_num6 + 53, (const s16*)scr_obj_num6 + 53, (const s16*)scr_obj_num6 + 53 },
    { (const s16*)scr_obj_num6 + 326, (const s16*)scr_obj_num6 + 326, (const s16*)scr_obj_num6 + 326 },
    { (const s16*)scr_obj_num6 + 52, (const s16*)scr_obj_num6 + 52, (const s16*)scr_obj_num6 + 52 },
    { (const s16*)scr_obj_num6 + 52, (const s16*)scr_obj_num6 + 52, (const s16*)scr_obj_num6 + 52 },
    { (const s16*)scr_obj_num6 + 52, (const s16*)scr_obj_num6 + 52, (const s16*)scr_obj_num6 + 52 },
    { (const s16*)scr_obj_num6 + 350, (const s16*)scr_obj_num6 + 382, (const s16*)scr_obj_num6 + 382 },
};



void effect_06_move(WORK_Other* ewk) {
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
            break;
        }
        disp_pos_trans_entry_rs(ewk);
        break;
    default:
        all_cgps_put_back(&ewk->wu);
        push_effect_work(&ewk->wu);
        break;
    }
}



/* tables by stage and area */
s32 effect_06_init(void) {
    WORK_Other* ewk;
    s16 ix;
    s16 lp_cnt = scr_obj_num6[bg_w.stage][bg_w.area];
    s16 i;
    const s16* data_ptr;
    if (lp_cnt == 0) {
        return;
    }
    data_ptr = scr_obj_data6[bg_w.stage][bg_w.area];
    for (i = 0; i < lp_cnt; i++) {
        if ((ix = pull_effect_work(4)) == -1) {
            return -1;
        }
        ewk = (WORK_Other*)frw[ix];
        ewk->wu.be_flag = 1;
        ewk->wu.id = 6;
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
