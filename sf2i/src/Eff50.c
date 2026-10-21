/*
 * EFF50.C  Effect 50: super art selection plate part
 *
 * Effect 50 is created by effect_50_init from sel_pl as part of the super art selection display.
 * effect_50_move appears when the art selection opens, animates in step with the plate held in
 * Synchro_Address, and when Moving_Plate selects its plate steps to the next animation and shifts
 * its offset; it follows Plate_X / Plate_Y for the player and hides and releases itself when
 * Sel_Arts_Complete is set.
 * 2i: no plate synchronisation; the part shows once Select_Arts clears, animates until
 * Sel_Arts_Complete and holds 5 frames; effect_50_init places it at fixed positions.
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



/* 2i 060CEB28, inferred: sf3 src/Eff50.c:23 effect_50_move; 2i: shown after Select_Arts clears, held 5 frames after Sel_Arts_Complete */
void effect_50_move(WORK_Other* ewk) {
    switch (ewk->wu.routine_no[0]) {
    case 0:
        if (Select_Arts[ewk->master_id] == 0) {
            ewk->wu.routine_no[0]++;
            ewk->wu.disp_flag = 1;
        }
        break;
    case 1:
        char_move(&ewk->wu);
        if (Sel_Arts_Complete[ewk->master_id]) {
            ewk->wu.routine_no[0]++;
            ewk->wu.dir_timer = 5;
        }
        break;
    case 2:
        char_move(&ewk->wu);
        if (--ewk->wu.dir_timer == 0) {
            ewk->wu.disp_flag = 0;
            ewk->wu.routine_no[0]++;
            return;
        }
        break;
    case 3:
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



/* 2i 060CEBFA (no table row; the census calls 3s effect_50_init absent): sf3 src/Eff50.c effect_50_init; 2i: two arguments, fixed positions */
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
    *ewk->wu.char_table = sel_pl_char_table;
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
