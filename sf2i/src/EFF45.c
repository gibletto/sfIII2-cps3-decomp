/*
 * EFF45.C  Effect 45: stage objects at random places (2nd Impact)
 *
 * effect_45_init creates three pairs of objects. Each takes a random number: its X position comes
 * from eff45_pos_x_tbl by that number, its Y position from eff45_pos_y_tbl (first pair) or
 * eff45_pos_y_tbl2 (others) by its low four bits, and its pattern from its low two bits (15-18,
 * 19-22, 23-26). effect_45_move starts the pattern and plays it while the game runs.
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
#include "bg_sub_5.h"
#include "PLS02.h"
#include "EFF45.h"

extern const s16 eff45_pos_x_tbl[];       /* provisional names (06179360, 061793A0, 061793C0) */
extern const s16 eff45_pos_y_tbl[16];
extern const s16 eff45_pos_y_tbl2[16];
extern const u32 eff45_char_table[];      /* provisional name (06353FBC) */



void effect_45_move(WORK_Other* ewk) {
    if (obr_no_disp_check()) {
        return;
    }
    switch (ewk->wu.routine_no[0]) {
    case 0:
        ewk->wu.routine_no[0]++;
        ewk->wu.disp_flag = 1;
        set_char_move_init(&ewk->wu, 0, ewk->wu.char_index);
        break;
    case 1:
        if (!EXE_flag && !Game_pause && !EXE_obroll) {
            char_move(&ewk->wu);
        }
        disp_pos_trans_entry_s(ewk);
        break;
    default:
        all_cgps_put_back(&ewk->wu);
        push_effect_work(&ewk->wu);
        break;
    }
}



s32 effect_45_init(void) {
    WORK_Other* ewk;
    s16 ix;
    s16 i;
    s16 r;
    for (i = 0; i < 2; i++) {
        if ((ix = pull_effect_work(4)) == -1) {
            return -1;
        }
        ewk = (WORK_Other*)frw[ix];
        r = random_32_ex_com();
        ewk->wu.be_flag = 1;
        ewk->wu.id = 45;
        ewk->wu.work_id = 16;
        ewk->wu.cgromtype = 1;
        ewk->wu.rl_flag = 0;
        ewk->wu.my_col_mode = 0x4200;
        ewk->wu.my_family = 1;
        ewk->wu.my_col_code = 0x2040;
        ewk->wu.position_x = ewk->wu.xyz[0].disp.pos = eff45_pos_x_tbl[r];
        ewk->wu.position_y = ewk->wu.xyz[1].disp.pos = eff45_pos_y_tbl[r & 15];
        ewk->wu.position_z = ewk->wu.my_priority = 80;
        ewk->wu.char_index = (r & 3) + 15;
        ewk->wu.sync_suzi = 0;
        ewk->wu.char_table[0] = eff45_char_table;
        suzi_offset_set(&ewk->wu);
    }
    for (i = 0; i < 2; i++) {
        if ((ix = pull_effect_work(4)) == -1) {
            return -1;
        }
        ewk = (WORK_Other*)frw[ix];
        r = random_32_ex_com();
        ewk->wu.be_flag = 1;
        ewk->wu.id = 45;
        ewk->wu.work_id = 16;
        ewk->wu.cgromtype = 1;
        ewk->wu.rl_flag = 0;
        ewk->wu.my_col_mode = 0x4200;
        ewk->wu.my_family = 1;
        ewk->wu.my_col_code = 0x2040;
        ewk->wu.position_x = ewk->wu.xyz[0].disp.pos = eff45_pos_x_tbl[r];
        ewk->wu.position_y = ewk->wu.xyz[1].disp.pos = eff45_pos_y_tbl2[r & 15];
        ewk->wu.position_z = ewk->wu.my_priority = 80;
        ewk->wu.char_index = (r & 3) + 19;
        ewk->wu.sync_suzi = 0;
        ewk->wu.char_table[0] = eff45_char_table;
        suzi_offset_set(&ewk->wu);
    }
    for (i = 0; i < 2; i++) {
        if ((ix = pull_effect_work(4)) == -1) {
            return -1;
        }
        ewk = (WORK_Other*)frw[ix];
        r = random_32_ex_com();
        ewk->wu.be_flag = 1;
        ewk->wu.id = 45;
        ewk->wu.work_id = 16;
        ewk->wu.cgromtype = 1;
        ewk->wu.rl_flag = 0;
        ewk->wu.my_col_mode = 0x4200;
        ewk->wu.my_family = 1;
        ewk->wu.my_col_code = 0x2040;
        ewk->wu.position_x = ewk->wu.xyz[0].disp.pos = eff45_pos_x_tbl[r];
        ewk->wu.position_y = ewk->wu.xyz[1].disp.pos = eff45_pos_y_tbl2[r & 15];
        ewk->wu.position_z = ewk->wu.my_priority = 80;
        ewk->wu.char_index = (r & 3) + 23;
        ewk->wu.sync_suzi = 0;
        ewk->wu.char_table[0] = eff45_char_table;
        suzi_offset_set(&ewk->wu);
    }
    return 0;
}
