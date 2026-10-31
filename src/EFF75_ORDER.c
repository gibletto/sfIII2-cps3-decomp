/*
 * EFF75_ORDER.C  Effect 75: move routine, order-driven states and init
 *
 * Effect 75 is a select-screen object: effect_75_init places pattern ID + 27 of
 * sel_pl_char_table high above the screen; effect_75_move waits dir_timer frames, drops it to
 * height 155, waits for Explosion and then flies it off with the speeds of its current
 * pattern (eff75_speed_tbl). Suicide hides it at once.
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "EFFECT.h"
#include "effect_2.h"
#include "aboutspr.h"
#include "CHARMOVE.h"
#include "charmove_2.h"
#include "SYS_sub.h"
#include "EFF75_ORDER.h"

/* routine_no[0] */
#define R0_WAIT         0       /* count the start delay down */
#define R0_DROP         1       /* drop to its height */
#define R0_HOLD         2       /* wait for the explosion */
#define R0_FLY          3       /* fly off until off screen */
#define R0_END          4       /* hidden for a frame */
#define R0_KILL         5       /* (default) put the work back */

extern const s32 eff75_speed_tbl[][4];



void effect_75_move(WORK_Other* ewk) {
    if (Suicide) {
        ewk->wu.disp_flag = 0;
        ewk->wu.routine_no[0] = R0_END;
        return;
    }
    switch (ewk->wu.routine_no[0]) {
    case R0_WAIT:
        if (--ewk->wu.dir_timer != 0) {
            return;
        }
        ewk->wu.routine_no[0]++;
        ewk->wu.disp_flag = 1;
        set_char_move_init(&ewk->wu, 0, ewk->wu.char_index);
        break;
    case R0_DROP:
        ewk->wu.xyz[1].cal += ewk->wu.mvxy.a[1].sp;
        ewk->wu.mvxy.a[1].sp += ewk->wu.mvxy.d[1].sp;
        if (ewk->wu.direction <= ewk->wu.xyz[1].disp.pos) {
            ewk->wu.routine_no[0]++;
            ewk->wu.dir_timer = 1;
            ewk->wu.xyz[1].disp.pos = ewk->wu.direction;
        }
        break;
    case R0_HOLD:
        if (Explosion) {
            ewk->wu.routine_no[0]++;
            ewk->wu.mvxy.a[0].sp = eff75_speed_tbl[ewk->wu.cg_type][0];
            ewk->wu.mvxy.d[0].sp = eff75_speed_tbl[ewk->wu.cg_type][1];
            ewk->wu.mvxy.a[1].sp = eff75_speed_tbl[ewk->wu.cg_type][2];
            ewk->wu.mvxy.d[1].sp = eff75_speed_tbl[ewk->wu.cg_type][3];
        }
        break;
    case R0_FLY:
        ewk->wu.xyz[0].cal += ewk->wu.mvxy.a[0].sp;
        ewk->wu.mvxy.a[0].sp += ewk->wu.mvxy.d[0].sp;
        ewk->wu.xyz[1].cal += ewk->wu.mvxy.a[1].sp;
        ewk->wu.mvxy.a[1].sp += ewk->wu.mvxy.d[1].sp;
        if (Ck_Range_Out_S(ewk, 2, 0x80) || Ck_Range_Out_Y(ewk, 2, 48)) {
            ewk->wu.routine_no[0]++;
            ewk->wu.disp_flag = 0;
            return;
        }
        break;
    case R0_END:
        ewk->wu.routine_no[0]++;
        return;
    default:
        ewk->wu.disp_flag = 0;
        all_cgps_put_back(&ewk->wu);
        push_effect_work(&ewk->wu);
        return;
    }
    char_move(&ewk->wu);
    ewk->wu.position_x = ewk->wu.xyz[0].disp.pos & 0x3FF;
    ewk->wu.position_y = ewk->wu.xyz[1].disp.pos & 0x3FF;
    ewk->wu.position_z = ewk->wu.xyz[2].disp.pos & 0x3FF;
    sort_push_request4(&ewk->wu);
}



s32 effect_75_init(s16 Vital, s16 ID, s16 Wait) {
    WORK_Other* ewk;
    s16 ix;
    if ((ix = pull_effect_work(4)) == -1) {
        return -1;
    }
    ewk = (WORK_Other*)frw[ix];
    ewk->wu.be_flag = 1;
    ewk->wu.id = 75;
    ewk->wu.work_id = 16;
    ewk->wu.cgromtype = 1;
    ewk->wu.my_col_mode = 0x4200;
    ewk->wu.my_col_code = 0x2040;
    ewk->wu.my_family = 3;
    ewk->wu.dir_timer = Wait;
    ewk->wu.char_table[0] = sel_pl_char_table;
    ewk->wu.char_index = ID + 27;
    ewk->wu.dm_vital = Vital;
    ewk->wu.xyz[0].disp.pos = DE_X[10] + 0x2C0;
    ewk->wu.xyz[1].disp.pos = -96;
    ewk->wu.xyz[2].disp.pos = 9;
    ewk->wu.mvxy.a[1].sp = 0x80000;
    ewk->wu.mvxy.d[1].sp = 0x8000;
    ewk->wu.direction = 155;
    return 0;
}
