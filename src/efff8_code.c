/*
 * EFFF8_CODE.C  Effect F8: second parry mark
 *
 * Effect F8 is a second parry mark: like effect C7 it is placed from its own offset table for the
 * parry type and character and plays pattern 3 of ef01_char_table until it ends.
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
#include "CMD_MAIN.h"
#include "cmd_main_2.h"
#include "ta_sub.h"
#include "aboutspr.h"
#include "EFFECT.h"
#include "effect_2.h"
#include "textsound.h"
#include "textsound_2.h"
#include "textsound_3.h"
#include "efff8_code.h"

/* routine_no[0] */
#define R0_INIT         0       /* place the mark */
#define R0_MOVE         1       /* play the mark until it ends */
#define R0_END          2       /* hidden for a frame */
#define R0_KILL         3       /* (default) put the work back */



void effect_F8_move(WORK_Other* ewk)
{
    WORK* mwk = (WORK*)ewk->my_master;

    switch (ewk->wu.routine_no[0]) {
    case R0_INIT:
        ewk->wu.routine_no[0]++;
        ewk->wu.disp_flag = 1;
        ewk->wu.xyz[2].disp.pos = 26;
        ewk->wu.next_z = mwk->position_z;
        if (mwk->rl_flag) {
            ewk->wu.position_x = mwk->position_x + paring_b_mark_data[ewk->wu.direction][ewk->master_player][0];
        } else {
            ewk->wu.position_x = mwk->position_x - paring_b_mark_data[ewk->wu.direction][ewk->master_player][0];
        }
        ewk->wu.position_y = mwk->position_y + paring_b_mark_data[ewk->wu.direction][ewk->master_player][1];
        if (ewk->wu.position_z == ewk->wu.xyz[2].disp.pos) {
            ewk->wu.position_z = ewk->wu.next_z;
        } else {
            ewk->wu.position_z = ewk->wu.xyz[2].disp.pos;
        }
        set_char_move_init(&ewk->wu, 0, 3);
        sort_push_request(&ewk->wu);
        break;
    case R0_MOVE:
        if (ewk->wu.dead_f == 1 || Suicide != 0) {
            ewk->wu.disp_flag = 0;
            ewk->wu.routine_no[0]++;
            break;
        }
        if (EXE_flag == 0 && !Game_pause) {
            char_move(&ewk->wu);
            if (ewk->wu.cg_type == 0xFF) {
                ewk->wu.disp_flag = 0;
                ewk->wu.routine_no[0]++;
                break;
            }
        }
        sort_push_request(&ewk->wu);
        break;
    case R0_END:
        ewk->wu.routine_no[0] = R0_KILL;
        break;
    default:
        all_cgps_put_back(&ewk->wu);
        push_effect_work(&ewk->wu);
        break;
    }
}



s32 effect_F8_init(PLW* wk, u8 data) {
    WORK_Other* ewk;
    s16 ix;
    if ((ix = pull_effect_work(2)) == -1) {
        return -1;
    }
    ewk = (WORK_Other*)frw[ix];
    ewk->wu.be_flag = 1;
    ewk->wu.id = 158;
    ewk->wu.work_id = 64;
    ewk->wu.rl_flag = wk->wu.rl_flag;
    ewk->wu.direction = data;
    ewk->wu.cgromtype = 1;
    ewk->wu.my_col_mode = 0x4200;
    ewk->wu.my_col_code = 0x2020;
    ewk->wu.my_family = wk->wu.my_family;
    ewk->my_master = (u32*)wk;
    ewk->master_id = wk->wu.id;
    ewk->master_work_id = wk->wu.work_id;
    ewk->master_player = wk->player_number;
    ewk->wu.char_table[0] = ef01_char_table;
    return 0;
}
