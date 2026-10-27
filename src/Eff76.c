/*
 * EFF76.C  Effect 76: a select-screen plate that slides in
 *
 * effect_76_init(Side, Time, Rl, Char_Ix) places sel_pl_char_table pattern 79 + Char_Ix off screen on
 * the side given by Side; after Time frames it slides in until it reaches hit_quake. A Suicide
 * request hides and frees it.
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "SYS_sub.h"
#include "CHARMOVE.h"
#include "charmove_2.h"
#include "EFFECT.h"
#include "effect_2.h"
#include "aboutspr.h"
#include "Eff76.h"

/* routine_no[0] */
#define R0_WAIT         0       /* count the start delay down */
#define R0_SLIDE        1       /* slide in to its place */
#define R0_STAY         2       /* stay in place */
#define R0_END          3       /* hidden for a frame */
#define R0_KILL         4       /* (default) put the work back */



void effect_76_move(WORK_Other* ewk) {
    if (Suicide) {
        ewk->wu.disp_flag = 0;
        ewk->wu.routine_no[0] = R0_END;
        return;
    }
    Cut_Cut_Sub(3);
    switch (ewk->wu.routine_no[0]) {
    case R0_WAIT:
        if (--ewk->wu.dir_timer) {
            return;
        }
        ewk->wu.routine_no[0]++;
        ewk->wu.disp_flag = 1;
        set_char_move_init2(&ewk->wu, 0, ewk->wu.char_index, ewk->wu.vital_new + 1, 0);
        break;
    case R0_SLIDE:
        ewk->wu.xyz[0].cal += ewk->wu.mvxy.a[0].sp * 3;
        ewk->wu.mvxy.a[0].sp += ewk->wu.mvxy.d[0].sp;
        if (ewk->wu.mvxy.a[0].sp > 0) {
            if (ewk->wu.hit_quake < ewk->wu.xyz[0].disp.pos) {
                ewk->wu.routine_no[0]++;
            }
        } else if (ewk->wu.hit_quake > ewk->wu.xyz[0].disp.pos) {
            ewk->wu.routine_no[0]++;
        }
        break;
    case R0_STAY:
        break;
    case R0_END:
        ewk->wu.routine_no[0]++;
        return;
    default:
        all_cgps_put_back(&ewk->wu);
        push_effect_work(&ewk->wu);
        return;
    }
    ewk->wu.position_x = ewk->wu.xyz[0].disp.pos & 0x3FF;
    ewk->wu.position_y = ewk->wu.xyz[1].disp.pos & 0x3FF;
    ewk->wu.position_z = ewk->wu.xyz[2].disp.pos & 0x3FF;
    sort_push_request4(&ewk->wu);
}



s32 effect_76_init(s16 Side, s16 Time, s16 Rl, s16 Char_Ix) {
    WORK_Other* ewk;
    s16 ix;
    if ((ix = pull_effect_work(4)) == -1) {
        return -1;
    }
    ewk = (WORK_Other*)frw[ix];
    ewk->wu.be_flag = 1;
    ewk->wu.id = 76;
    ewk->wu.work_id = 16;
    ewk->wu.cgromtype = 1;
    ewk->wu.my_col_mode = 0x4200;
    ewk->wu.my_col_code = 0x2040;
    ewk->wu.my_family = 3;
    ewk->wu.dir_timer = Time;
    *ewk->wu.char_table = sel_pl_char_table;
    ewk->wu.char_index = Char_Ix + 79;
    ewk->wu.rl_flag = Rl;
    if ((ewk->wu.vital_new = Side)) {
        ewk->wu.hit_quake = DE_X[10] + DE_X[10] + 0x330;
        ewk->wu.xyz[0].disp.pos = DE_X[5] + 0x3D0;
        ewk->wu.mvxy.a[0].sp = -0xA0000;
        ewk->wu.mvxy.d[0].sp = -0x8000;
    } else {
        ewk->wu.hit_quake = 0x250;
        ewk->wu.xyz[0].disp.pos = 0x1B0;
        ewk->wu.mvxy.a[0].sp = 0xA0000;
        ewk->wu.mvxy.d[0].sp = 0x8000;
    }
    ewk->wu.xyz[1].disp.pos = 77;
    ewk->wu.xyz[2].disp.pos = 8;
    return 0;
}
