/*
 * EFFI6.C  Effect I6: round-call line
 *
 * 3s: Effect I6 is a child of the round-call effect (effect_I6_init, called from effb2.c) placed at
 * screen centre on BG4. It follows its parent's state: it starts pattern 3 at zero size
 * (effi6_line_move), copies the parent's zoom, hides with it and is freed with it.
 * 2i: effect I6 (id 0xBA) is a stage object set: effect_I6_init creates the objects listed for
 * the stage (scr_obj_numI6 / scr_obj_dataI6 by bg_index) and effect_I6_move animates them.
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



extern const s16 scr_obj_numI6[];   /* provisional name */

/* 2i 0200848C: pointers into scr_obj_numI6, by bg_index (provisional name) */
const s16* scr_obj_dataI6[18] = {
    (const s16*)&scr_obj_numI6[18],
    (const s16*)&scr_obj_numI6[19],
    (const s16*)&scr_obj_numI6[37],
    (const s16*)&scr_obj_numI6[67],
    (const s16*)&scr_obj_numI6[109],
    (const s16*)&scr_obj_numI6[115],
    (const s16*)&scr_obj_numI6[121],
    (const s16*)&scr_obj_numI6[151],
    (const s16*)&scr_obj_numI6[152],
    (const s16*)&scr_obj_numI6[158],
    (const s16*)&scr_obj_numI6[170],
    (const s16*)&scr_obj_numI6[91],
    (const s16*)&scr_obj_numI6[176],
    (const s16*)&scr_obj_numI6[200],
    (const s16*)&scr_obj_numI6[218],
    (const s16*)&scr_obj_numI6[19],
    (const s16*)&scr_obj_numI6[19],
    (const s16*)&scr_obj_numI6[121],
};



/* 2i 060EBC94, inferred: sf3 src/effi6.c:32 effect_I6_move; 2i: a stage object (3s: the round-call line) */
void effect_I6_move(WORK_Other* ewk) {
    switch (ewk->wu.routine_no[0]) {
    case 0:
        ewk->wu.routine_no[0]++;
        ewk->wu.disp_flag = 1;
        set_char_move_init(&ewk->wu, 0, ewk->wu.char_index);
        break;
    case 1:
        disp_pos_trans_entry(ewk);
        break;
    default:
        all_cgps_put_back(&ewk->wu);
        push_effect_work(&ewk->wu);
        break;
    }
}



/* 2i 060EBCE4 (no table row; the census places no 3s routine here): sf3 src/effi6.c effect_I6_init; 2i: the stage's object list */
s32 effect_I6_init(void) {
    WORK_Other* ewk;
    s16 ix;
    s16 lp_cnt = scr_obj_numI6[bg_w.bg_index];
    s16 i;
    const s16* data_ptr;
    if (lp_cnt == 0) {
        return;
    }
    data_ptr = scr_obj_dataI6[bg_w.bg_index];
    for (i = 0; i < lp_cnt; i++) {
        if ((ix = pull_effect_work(4)) == -1) {
            return -1;
        }
        ewk = (WORK_Other*)frw[ix];
        ewk->wu.be_flag = 1;
        ewk->wu.id = 0xBA;
        ewk->wu.work_id = 16;
        ewk->wu.cgromtype = 1;
        ewk->wu.rl_flag = 0;
        ewk->wu.my_col_mode = 0x4200;
        ewk->wu.type = i;
        ewk->wu.my_family = *data_ptr++;
        ewk->wu.my_col_code = *data_ptr++;
        ewk->wu.xyz[0].disp.pos = *data_ptr++;
        ewk->wu.xyz[1].disp.pos = *data_ptr++;
        ewk->wu.my_priority = ewk->wu.position_z = *data_ptr++;
        ewk->wu.char_index = *data_ptr++;
        ewk->wu.sync_suzi = 0;
        ewk->wu.char_table[0] = char_add[bg_w.stage][bg_w.area];
    }
    return 0;
}
