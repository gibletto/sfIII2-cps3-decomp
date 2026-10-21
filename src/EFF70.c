/*
 * EFF70.C  Effect 70: select-screen face plate (2nd Impact)
 *
 * effect_70_init places plate id at its Face_Pos_Data spot (from DE_X[10]); effect_70_init2 places
 * the plate for slot 16. Both use Setup_Eff70. effect_70_move waits until eff70_ready allows it,
 * then shows the plate's pattern until a Suicide request removes it. eff70_sel_id reports which
 * player's selection decides the plate.
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
#include "EFF70.h"

s32 eff70_ready();



void effect_70_move(WORK_Other* ewk) {
    switch (ewk->wu.routine_no[0]) {
    case 0:
        if (!eff70_ready()) {
            return;
        }
        ewk->wu.routine_no[0]++;
        ewk->wu.disp_flag = 1;
        /* fall through */
    case 1:
        if (Suicide == 1) {
            ewk->wu.routine_no[0]++;
            ewk->wu.disp_flag = 0;
        } else {
            ewk->wu.position_z = 62;
            set_char_move_init2(&ewk->wu, 0, ewk->wu.char_index, ewk->wu.dir_timer + 1, 0);
            ewk->wu.position_x = ewk->wu.xyz[0].disp.pos & 0x3FF;
            ewk->wu.position_y = ewk->wu.xyz[1].disp.pos & 0x3FF;
            ewk->wu.position_z = ewk->wu.xyz[2].disp.pos & 0x3FF;
            sort_push_request4(&ewk->wu);
        }
        break;
    case 2:
        ewk->wu.routine_no[0]++;
        return;
    default:
        all_cgps_put_back(&ewk->wu);
        push_effect_work(&ewk->wu);
        break;
    }
}



/* provisional name */
s16 eff70_sel_id(void) {
    if (Sel_PL_Complete[0] != 0 && Sel_PL_Complete[1] != 0) {
        return Last_Selected_ID;
    }
    if (Sel_PL_Complete[0] == 0) {
        return 0;
    }
    if (Sel_PL_Complete[1] == 0) {
        return 1;
    }
}



s32 effect_70_init(s16 id) {
    WORK_Other* ewk;
    s16 ix;
    s16 x;
    if ((ix = pull_effect_work(4)) == -1) {
        return -1;
    }
    ewk = (WORK_Other*)frw[ix];
    Setup_Eff70(&ewk->wu);
    x = DE_X[10] + 0x101;
    ewk->wu.xyz[0].disp.pos = x + Face_Pos_Data[id][0] + 0xC0;
    ewk->wu.xyz[1].disp.pos = Face_Pos_Data[id][1];
    ewk->wu.xyz[2].disp.pos = 62;
    ewk->wu.dir_timer = id;
}



/* provisional name */
s32 effect_70_init2(void) {
    WORK_Other* ewk;
    s16 ix;
    if ((ix = pull_effect_work(4)) == -1) {
        return -1;
    }
    ewk = (WORK_Other*)frw[ix];
    Setup_Eff70(&ewk->wu);
    ewk->wu.xyz[0].disp.pos = DE_X[10] + 0x1C1;
    ewk->wu.xyz[1].disp.pos = 87;
    ewk->wu.xyz[2].disp.pos = 64;
    ewk->wu.my_col_code = 64;
    ewk->wu.char_index = 0;
    ewk->wu.dir_timer = 16;
    ewk->wu.char_table[0] = sel_pl_char_table;
}



void Setup_Eff70(WORK* wk) {
    wk->be_flag = 1;
    wk->id = 70;
    wk->work_id = 16;
    wk->cgromtype = 1;
    wk->my_col_mode = 0x4200;
    wk->my_col_code = 0x2040;
    wk->my_family = 2;
    wk->char_index = 0;
    wk->char_table[0] = sel_pl_char_table;
}



/* provisional name */
s32 eff70_ready(WORK_Other* ewk) {
    if (ewk->wu.dir_timer != 14) {
        return 1;
    }
    return Gouki_Select_Open;
}
