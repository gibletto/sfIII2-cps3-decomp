/*
 * EFFI7.C  Effect I7: sign shown beside a player during an attack
 *
 * effect_I7_init creates the sign for a player (skipped when test_flag is set) with an entry
 * number in ex_sign_data (x offset, y offset, pattern, follow flag; plef_char_table).
 * effect_I7_move places it beside the player (effI7_pos_hosei, mirrored for facing), just in
 * front of the player's depth, plays its pattern (honouring hit stop) and, when the entry asks,
 * keeps following the player. It is hidden and freed when the pattern ends or the player leaves
 * the attack state (routine_no[1] != 4).
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "CHARMOVE.h"
#include "charmove_2.h"
#include "aboutspr.h"
#include "EFFECT.h"
#include "effect_2.h"
#include "EFFI7.h"



/* 2i 060EBDEC, 3s-near: sf3 src/EFFI7.c:25 effect_I7_move */
void effect_I7_move(WORK_Other* ewk) {
    PLW* mwk = (PLW*)ewk->my_master;
    switch (ewk->wu.routine_no[0]) {
    case 0:
        ewk->wu.routine_no[0]++;
        ewk->wu.disp_flag = 1;
        ewk->wu.my_col_mode = 0x4200;
        ewk->wu.my_col_code = 0x2020;
        effI7_pos_hosei(ewk, &mwk->wu);
        ewk->wu.position_z = mwk->wu.position_z - 4;
        set_char_move_init(&ewk->wu, 0, ex_sign_data[ewk->wu.type][2]);
        sort_push_request(&ewk->wu);
        break;
    case 1:
        if (ewk->wu.dead_f == 1 || mwk->wu.routine_no[1] != 4) {
            ewk->wu.routine_no[0]++;
            ewk->wu.disp_flag = 0;
            break;
        }
        if (EXE_flag == 0 && Game_pause == 0) {
            if (ewk->wu.hit_stop) {
                ewk->wu.hit_stop--;
            } else {
                char_move(&ewk->wu);
            }
        }
        if (ewk->wu.cg_type == 0xFF) {
            ewk->wu.routine_no[0]++;
            ewk->wu.disp_flag = 0;
            break;
        }
        if (ex_sign_data[ewk->wu.type][3]) {
            effI7_pos_hosei(ewk, &mwk->wu);
        }
        ewk->wu.position_z = mwk->wu.position_z - 4;
        sort_push_request(&ewk->wu);
        break;
    case 2:
        ewk->wu.routine_no[0] = 3;
        break;
    default:
        all_cgps_put_back(&ewk->wu);
        push_effect_work(&ewk->wu);
        break;
    }
}



/* 2i 060EBF32, 3s-exact: sf3 src/EFFI7.c:74 effI7_pos_hosei */
void effI7_pos_hosei(WORK_Other* ewk, WORK* mwk) {
    ewk->wu.position_x = mwk->position_x;
    if (mwk->rl_flag) {
        ewk->wu.position_x -= ex_sign_data[ewk->wu.type][0];
    } else {
        ewk->wu.position_x += ex_sign_data[ewk->wu.type][0];
    }
    ewk->wu.position_y = mwk->position_y + ex_sign_data[ewk->wu.type][1];
}



/* 2i 060EBF8E, 3s-near: sf3 src/EFFI7.c:86 effect_I7_init */
s32 effect_I7_init(PLW* wk, u8 data) {
    WORK_Other* ewk;
    s16 ix;
    if (!test_flag) {
        if ((ix = pull_effect_work(3)) == -1) {
            return -1;
        }
        ewk = (WORK_Other*)frw[ix];
        ewk->wu.be_flag = 1;
        ewk->wu.type = data;
        ewk->wu.id = 187;
        ewk->wu.work_id = 16;
        ewk->wu.my_family = wk->wu.my_family;
        ewk->wu.cgromtype = 1;
        ewk->my_master = (u32*)wk;
        ewk->master_work_id = wk->wu.work_id;
        ewk->master_id = wk->wu.id;
        *ewk->wu.char_table = plef_char_table;
        return 0;
    }
}
