/*
 * EFFI6.C  Effect I6: stage objects
 *
 * Effect I6 (id 0xBA) is a stage object set: effect_I6_init creates the objects listed for
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

/* routine_no[0] */
#define R0_INIT         0       /* start the pattern */
#define R0_MOVE         1       /* draw */



extern const s16 scr_obj_numI6[];   /* provisional name */
extern const s16 scr_obj_dataI6_0[];
extern const s16 scr_obj_dataI6_1[];
extern const s16 scr_obj_dataI6_2[];
extern const s16 scr_obj_dataI6_3[];
extern const s16 scr_obj_dataI6_11[];
extern const s16 scr_obj_dataI6_4[];
extern const s16 scr_obj_dataI6_5[];
extern const s16 scr_obj_dataI6_6[];
extern const s16 scr_obj_dataI6_7[];
extern const s16 scr_obj_dataI6_8[];
extern const s16 scr_obj_dataI6_9[];
extern const s16 scr_obj_dataI6_10[];
extern const s16 scr_obj_dataI6_12[];
extern const s16 scr_obj_dataI6_13[];
extern const s16 scr_obj_dataI6_14[];

/* provisional name: the object list of each bg_index */
const s16* scr_obj_dataI6[18] = {
    scr_obj_dataI6_0,
    scr_obj_dataI6_1,
    scr_obj_dataI6_2,
    scr_obj_dataI6_3,
    scr_obj_dataI6_4,
    scr_obj_dataI6_5,
    scr_obj_dataI6_6,
    scr_obj_dataI6_7,
    scr_obj_dataI6_8,
    scr_obj_dataI6_9,
    scr_obj_dataI6_10,
    scr_obj_dataI6_11,
    scr_obj_dataI6_12,
    scr_obj_dataI6_13,
    scr_obj_dataI6_14,
    scr_obj_dataI6_1,
    scr_obj_dataI6_1,
    scr_obj_dataI6_6,
};



/* a stage object */
void effect_I6_move(WORK_Other* ewk) {
    switch (ewk->wu.routine_no[0]) {
    case R0_INIT:
        ewk->wu.routine_no[0]++;
        ewk->wu.disp_flag = 1;
        set_char_move_init(&ewk->wu, 0, ewk->wu.char_index);
        break;
    case R0_MOVE:
        disp_pos_trans_entry(ewk);
        break;
    default:
        all_cgps_put_back(&ewk->wu);
        push_effect_work(&ewk->wu);
        break;
    }
}



/* the stage's object list */
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
