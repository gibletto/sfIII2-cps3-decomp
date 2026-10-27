/*
 * EFF81.C  Effect 81: a select-screen mark that follows its parent
 *
 * effect_81_init creates the mark for a player's selection under its parent work; its pattern
 * depends on the character (My_char), the side and the Country. effect_81_move keeps it on the
 * parent (shown while the parent's cg_type is 8), waits until the player's Stop_Cursor is clear
 * and frees it once it has left the screen.
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
#include "Eff81.h"

/* routine_no[0] */
#define R0_INIT         0       /* start the animation */
#define R0_WAIT         1       /* wait until the cursor is released */
#define R0_MOVE         2       /* follow the parent until off screen */
#define R0_END          3       /* hidden for a frame */
#define R0_KILL         4       /* (default) put the work back */



void effect_81_move(WORK_Other* ewk) {
    WORK* mwk = (WORK*)ewk->my_master;
    if (mwk->cg_type == 8) {
        ewk->wu.disp_flag = 1;
    } else {
        ewk->wu.disp_flag = 0;
    }
    switch (ewk->wu.routine_no[0]) {
    case R0_INIT:
        ewk->wu.routine_no[0]++;
        set_char_move_init2(&ewk->wu, 0, ewk->wu.char_index, ewk->wu.vital_new + 1, 0);
        break;
    case R0_WAIT:
        if (Stop_Cursor[ewk->master_id] == 0) {
            ewk->wu.routine_no[0]++;
        }
        break;
    case R0_MOVE:
        if (Ck_Range_Out_S(ewk, 2, 96)) {
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
        break;
    }
    ewk->wu.position_x = ewk->wu.xyz[0].disp.pos = mwk->position_x;
    ewk->wu.position_y = ewk->wu.xyz[1].disp.pos = mwk->position_y - mwk->cg_type;
    ewk->wu.position_z = ewk->wu.xyz[2].disp.pos = mwk->position_z - 1;
    sort_push_request4(&ewk->wu);
}



s32 effect_81_init(WORK_Other* oya, s16 PL_id, s16 Master_Player, s16 Priority) {
    WORK_Other* ewk;
    s16 ix;
    s16 k;
    if ((ix = pull_effect_work(4)) == -1) {
        return -1;
    }
    ewk = (WORK_Other*)frw[ix];
    ewk->wu.be_flag = 1;
    ewk->wu.id = 81;
    ewk->wu.work_id = 16;
    ewk->wu.cgromtype = 1;
    ewk->wu.my_col_mode = 0x4200;
    ewk->wu.my_col_code = 0x2040;
    ewk->wu.my_family = 3;
    ewk->wu.char_table[0] = sel_pl_char_table;
    ewk->master_id = PL_id;
    ewk->master_player = Master_Player;
    ewk->master_priority = Priority;
    ewk->my_master = (u32*)oya;
    if (Country == 1) {
        k = 0;
    } else {
        k = 2;
    }
    if (PL_id == 1) {
        k++;
    }
    ewk->wu.char_index = 8;
    ewk->wu.vital_new = My_char[PL_id] * 3 + k * 48 + Master_Player;
    return 0;
}
