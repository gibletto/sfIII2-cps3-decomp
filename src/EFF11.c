/*
 * EFF11.C  Effect 11: stage objects that fly off at the start (bg000)
 *
 * effect_11_init (from bg000, not during the opening roll) creates four objects from eff11_data_tbl
 * (position, priority, pattern, delay) and eff11_speed_tbl. Each waits out its delay, shows itself
 * and moves with its speeds until it drops below height 64.
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "ta_sub.h"
#include "CALDIR.h"
#include "CHARMOVE.h"
#include "charmove_2.h"
#include "EFFECT.h"
#include "effect_2.h"
#include "PLS02.h"
#include "aboutspr.h"
#include "bg_sub.h"
#include "bg_sub_2.h"
#include "bg_sub_3.h"
#include "bg_sub_4.h"
#include "bg_sub_5.h"
#include "EFF11.h"
#include "eff05.h"

/* routine_no[0] */
#define R0_WAIT         0       /* wait out the delay, then appear */
#define R0_MOVE         1       /* fly until below height 64 */
#define R0_END          2       /* hidden for a frame */
#define R0_KILL         3       /* (default) put the work back */



void effect_11_move(WORK_Other* ewk) {
    switch (ewk->wu.routine_no[0]) {
    case R0_WAIT:
        if (!EXE_flag && !Game_pause) {
            ewk->wu.direction--;
            if (ewk->wu.direction > 0) {
                break;
            }
            ewk->wu.routine_no[0]++;
            ewk->wu.disp_flag = 1;
            set_char_move_init(&ewk->wu, 0, ewk->wu.char_index);
        }
        break;
    case R0_MOVE:
        if (!EXE_flag && !Game_pause && !EXE_obroll) {
            add_x_sub(ewk);
            add_y_sub(ewk);
            char_move(&ewk->wu);
            if (ewk->wu.xyz[1].disp.pos < 64) {
                ewk->wu.routine_no[0]++;
                ewk->wu.disp_flag = 0;
            }
        }
        disp_pos_trans_entry_s(ewk);
        break;
    case R0_END:
        ewk->wu.routine_no[0]++;
        break;
    default:
        all_cgps_put_back(&ewk->wu);
        push_effect_work(&ewk->wu);
        break;
    }
}



s32 effect_11_init(void) {
    WORK_Other* ewk;
    s16 ix;
    s16 i;
    const s16* data_ptr;
    const s32* speed_ptr;
    if (EXE_obroll) {
        return;
    }
    data_ptr = &eff11_data_tbl[0][0];
    speed_ptr = &eff11_speed_tbl[0][0];
    for (i = 0; i < 4; i++) {
        if ((ix = pull_effect_work(4)) == -1) {
            return -1;
        }
        ewk = (WORK_Other*)frw[ix];
        ewk->wu.be_flag = 1;
        ewk->wu.id = 11;
        ewk->wu.work_id = 16;
        ewk->wu.cgromtype = 1;
        ewk->wu.rl_flag = 0;
        ewk->wu.my_col_mode = 0x4200;
        ewk->wu.sync_suzi = 0;
        ewk->wu.char_table[0] = stg00_char_table;
        ewk->wu.my_family = 2;
        ewk->wu.my_col_code = 0x2040;
        ewk->wu.position_x = ewk->wu.xyz[0].disp.pos = *data_ptr++;
        ewk->wu.position_y = ewk->wu.xyz[1].disp.pos = *data_ptr++;
        ewk->wu.position_z = ewk->wu.my_priority = *data_ptr++;
        ewk->wu.char_index = *data_ptr++;
        ewk->wu.direction = *data_ptr++;
        ewk->wu.mvxy.a[0].sp = *speed_ptr++;
        ewk->wu.mvxy.d[0].sp = *speed_ptr++;
        ewk->wu.mvxy.a[1].sp = *speed_ptr++;
        ewk->wu.mvxy.d[1].sp = *speed_ptr++;
        suzi_offset_set(&ewk->wu);
    }
    return 0;
}
