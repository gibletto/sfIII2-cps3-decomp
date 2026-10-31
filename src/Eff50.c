/*
 * EFF50.C  Effect 50: super art selection plate part
 *
 * Effect 50 is created by effect_50_init from sel_pl as part of the super art selection display, at a
 * fixed position. effect_50_move shows the part once Select_Arts clears and animates it until
 * Sel_Arts_Complete is set; it holds 5 more frames, then hides and releases itself.
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "charmove_2.h"
#include "aboutspr.h"
#include "EFFECT.h"
#include "effect_2.h"
#include "Eff50.h"

/* routine_no[0] */
#define R0_WAIT         0       /* wait for the art select to open */
#define R0_MOVE         1       /* animate until the art is chosen */
#define R0_HOLD         2       /* hold a few frames, then hide */
#define R0_END          3       /* one more frame */
#define R0_KILL         4       /* (default) put the work back */



/* Shown after Select_Arts clears, and held 5 frames after Sel_Arts_Complete. */
void effect_50_move(WORK_Other* ewk) {
    switch (ewk->wu.routine_no[0]) {
    case R0_WAIT:
        if (Select_Arts[ewk->master_id] == 0) {
            ewk->wu.routine_no[0]++;
            ewk->wu.disp_flag = 1;
        }
        break;
    case R0_MOVE:
        char_move(&ewk->wu);
        if (Sel_Arts_Complete[ewk->master_id]) {
            ewk->wu.routine_no[0]++;
            ewk->wu.dir_timer = 5;
        }
        break;
    case R0_HOLD:
        char_move(&ewk->wu);
        if (--ewk->wu.dir_timer == 0) {
            ewk->wu.disp_flag = 0;
            ewk->wu.routine_no[0]++;
            return;
        }
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
    sort_push_request4(&ewk->wu);
}



/* Two arguments; the positions are fixed. */
s32 effect_50_init(s16 PL_id, s16 Direction) {
    WORK_Other* ewk;
    s16 ix;
    if ((ix = pull_effect_work(4)) == -1) {
        return -1;
    }
    ewk = (WORK_Other*)frw[ix];
    ewk->wu.be_flag = 1;
    ewk->wu.id = 50;
    ewk->wu.work_id = 16;
    ewk->wu.cgromtype = 1;
    ewk->wu.my_col_mode = 0x4200;
    ewk->wu.my_col_code = 0x2040;
    ewk->wu.my_family = 3;
    ewk->master_id = PL_id;
    ewk->wu.char_index = Direction + 74;
    ewk->wu.char_table[0] = sel_pl_char_table;
    if (Direction == 1) {
        ewk->wu.xyz[1].disp.pos = 178;
    } else {
        ewk->wu.xyz[1].disp.pos = 126;
    }
    if (PL_id) {
        ewk->wu.xyz[0].disp.pos = DE_X[10] + DE_X[10] + 736;
    } else {
        ewk->wu.xyz[0].disp.pos = 672;
    }
    ewk->wu.position_z = 30;
    set_char_move_init(&ewk->wu, 0, ewk->wu.char_index);
    return 0;
}
