/*
 * EFF52.C  Effect 52: a select-screen object
 *
 * effect_52_init places sel_pl_char_table pattern 15 at DE_X[10] + 0x2BF, height 200; effect_52_move
 * shows it until a Suicide request removes it.
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "CHARMOVE.h"
#include "charmove_2.h"
#include "EFFECT.h"
#include "effect_2.h"
#include "aboutspr.h"
#include "Eff52.h"

/* routine_no[0] */
#define R0_INIT         0       /* show */
#define R0_MOVE         1       /* stay until told to go */
#define R0_KILL         2       /* (default) put the work back */



void effect_52_move(WORK_Other* ewk) {
    switch (ewk->wu.routine_no[0]) {
    case R0_INIT:
        ewk->wu.routine_no[0]++;
        ewk->wu.disp_flag = 1;
        break;
    case R0_MOVE:
        if (Suicide) {
            ewk->wu.routine_no[0]++;
            ewk->wu.disp_flag = 0;
        }
        break;
    default:
        all_cgps_put_back(&ewk->wu);
        push_effect_work(&ewk->wu);
        return;
    }
    ewk->wu.position_x = ewk->wu.xyz[0].disp.pos & 0x3FF;
    ewk->wu.position_y = ewk->wu.xyz[1].disp.pos & 0x3FF;
    sort_push_request4(&ewk->wu);
}



s32 effect_52_init(void) {
    WORK_Other* ewk;
    s16 ix;
    if ((ix = pull_effect_work(4)) == -1) {
        return -1;
    }
    ewk = (WORK_Other*)frw[ix];
    ewk->wu.be_flag = 1;
    ewk->wu.id = 52;
    ewk->wu.work_id = 16;
    ewk->wu.cgromtype = 1;
    ewk->wu.my_col_mode = 0x4200;
    ewk->wu.my_col_code = 0x2040;
    ewk->wu.my_family = 3;
    ewk->wu.char_index = 15;
    ewk->wu.char_table[0] = sel_pl_char_table;
    ewk->wu.xyz[0].disp.pos = DE_X[10] + 0x2BF;
    ewk->wu.xyz[1].disp.pos = 200;
    ewk->wu.position_z = 80;
    set_char_move_init(&ewk->wu, 0, ewk->wu.char_index);
    return 0;
}
