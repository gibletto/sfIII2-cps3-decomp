/*
 * EFF43.C  Effect 43: an object that slides in on the VS screen (2nd Impact only)
 *
 * effect_43_init(Side, Time) places it off-screen on the left or right after Time frames;
 * effect_43_move slides it in with a decelerating speed to its stop point (hit_quake, from DE_X),
 * plays its pattern and sets Next_Step. In 3rd Strike effect 43 shared EFF44.C; in 2nd Impact it is its own file.
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
#include "EFF43.h"



/* provisional name */
/* slides in to its stop point */
void effect_43_move(WORK_Other* ewk) {
    Cut_Cut_Sub(3);
    switch (ewk->wu.routine_no[0]) {
    case 0:
        if (--ewk->wu.dir_timer != 0) {
            return;
        }
        ewk->wu.routine_no[0]++;
        ewk->wu.disp_flag = 1;
        set_char_move_init2(&ewk->wu, 0, ewk->wu.char_index, ewk->wu.dir_step + 1, 0);
        break;
    case 1:
        ewk->wu.xyz[0].cal += ewk->wu.mvxy.a[0].sp * 3;
        ewk->wu.mvxy.a[0].sp += ewk->wu.mvxy.d[0].sp;
        if (ewk->wu.mvxy.a[0].sp > 0) {
            if (ewk->wu.hit_quake < ewk->wu.xyz[0].disp.pos) {
                ewk->wu.routine_no[0] = 99;
                ewk->wu.disp_flag = 0;
                ewk->wu.xyz[0].disp.pos = ewk->wu.hit_quake;
            }
        } else if (ewk->wu.hit_quake > ewk->wu.xyz[0].disp.pos) {
            ewk->wu.routine_no[0]++;
            ewk->wu.xyz[0].disp.pos = ewk->wu.hit_quake;
            char_move(&ewk->wu);
        }
        break;
    case 2:
        if (ewk->wu.cg_type) {
            Next_Step = 1;
            ewk->wu.routine_no[0]++;
        } else {
            char_move(&ewk->wu);
        }
        break;
    case 3:
        break;
    default:
        all_cgps_put_back(ewk);
        push_effect_work((WORK*)ewk);
        return;
    }
    ewk->wu.position_x = ewk->wu.xyz[0].disp.pos & 0x3FF;
    ewk->wu.position_y = ewk->wu.xyz[1].disp.pos & 0x3FF;
    ewk->wu.position_z = ewk->wu.xyz[2].disp.pos & 0x3FF;
    sort_push_request4(&ewk->wu);
}



/* from the left or right side */
s32 effect_43_init(s16 Side, s16 Time) {
    WORK_Other* ewk;
    s16 ix;
    if ((ix = pull_effect_work(4)) == -1) {
        return -1;
    }
    ewk = (WORK_Other*)frw[ix];
    ewk->wu.be_flag = 1;
    ewk->wu.id = 43;
    ewk->wu.work_id = 16;
    ewk->wu.cgromtype = 1;
    ewk->wu.rl_flag = 0;
    ewk->wu.my_col_mode = 0x4200;
    ewk->wu.my_col_code = 0x2040;
    ewk->wu.my_family = 3;
    ewk->wu.xyz[1].disp.pos = 0x80;
    ewk->wu.xyz[2].disp.pos = 8;
    ewk->wu.char_index = 10;
    ewk->wu.char_table[0] = sel_pl_char_table;
    ewk->wu.dir_timer = Time;
    ewk->wu.hit_quake = DE_X[10] + 0x2C0;
    if ((ewk->wu.dir_step = Side)) {
        ewk->wu.xyz[0].disp.pos = DE_X[5] + 0x3D0;
        ewk->wu.mvxy.a[0].sp = -0x48000;
        ewk->wu.mvxy.d[1].sp = ewk->wu.mvxy.a[0].sp / 16;
    } else {
        ewk->wu.xyz[0].disp.pos = 0x1B0;
        ewk->wu.mvxy.a[0].sp = 0x48000;
        ewk->wu.mvxy.d[1].sp = ewk->wu.mvxy.a[0].sp / 16;
    }
    return 0;
}
