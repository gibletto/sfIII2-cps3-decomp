/*
 * EFFI4MV.C  Effect I4 (184): the stage 00 crowd
 *
 * effect_I4_init makes four objects from effi4_data_tbl (x, y, priority, pattern); old_rno[0] is
 * the object's type. Each one plays its pattern until the match is decided (Round_num or the
 * winner's PL_Wins against Game_setting.Battle_Number), then cheers when the winner is player
 * number 0 or stops. Type 1 also turns towards a player (effi4_turn).
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "CHARMOVE.h"
#include "charmove_2.h"
#include "ta_sub.h"
#include "EFFECT.h"
#include "effect_2.h"
#include "aboutspr.h"
#include "EFFI4MV.h"
#include "fighter.h"
#include "eff05.h"

/* routine_no[0], effi4_move_0 */
#define R0_INIT         0       /* start the pattern */
#define R0_WATCH        1       /* watch until the match is decided */
#define R0_CHEER        2       /* cheer for the winner */
#define R0_STOP         3       /* stand still */

extern const s16 effi4_turn_tbl[16];
extern const s16 effi4_data_tbl[4][4];



void effect_I4_move(WORK_Other* ewk) {
    if (obr_no_disp_check()) {
        return;
    }
    switch (ewk->wu.old_rno[0]) {
    case 0:
        effi4_move_0(ewk);
        break;
    case 1:
        effi4_move_1(ewk);
        break;
    default:
        effi4_move_2(ewk);
        break;
    }
}



/* provisional name */
void effi4_move_0(WORK_Other* ewk) {
    switch (ewk->wu.routine_no[0]) {
    case R0_INIT:
        ewk->wu.routine_no[0]++;
        ewk->wu.disp_flag = 1;
        set_char_move_init(&ewk->wu, 0, 11);
        break;
    case R0_WATCH:
        char_move(&ewk->wu);
        if (Round_num >= Game_setting.Battle_Number << 1 || PL_Wins[Winner_id] >= Game_setting.Battle_Number + 1) {
            if (plw[Winner_id].player_number == PL_GILL) {
                ewk->wu.routine_no[0]++;
                set_char_move_init(&ewk->wu, 0, 3);
            } else {
                ewk->wu.routine_no[0] = R0_STOP;
            }
        }
        disp_pos_trans_entry_r(ewk);
        break;
    case R0_CHEER:
        if (!EXE_flag && !Game_pause && !EXE_obroll) {
            char_move(&ewk->wu);
        }
        /* fall through */
    case R0_STOP:
        disp_pos_trans_entry_r(ewk);
        break;
    default:
        all_cgps_put_back(&ewk->wu);
        push_effect_work(&ewk->wu);
        break;
    }
}



/* provisional name */
void effi4_move_1(WORK_Other* ewk) {
    switch (ewk->wu.routine_no[0]) {
    case R0_INIT:
        ewk->wu.routine_no[0]++;
        ewk->wu.disp_flag = 1;
        ewk->wu.old_rno[3] = 99;
        effi4_turn(ewk);
        if (plw[0].player_number == PL_GILL) {
            ewk->wu.old_rno[1] = 0;
        } else {
            ewk->wu.old_rno[1] = 1;
        }
        break;
    case R0_WATCH:
        if (Round_num >= Game_setting.Battle_Number << 1 || PL_Wins[Winner_id] >= Game_setting.Battle_Number + 1) {
            if (plw[Winner_id].player_number == PL_GILL) {
                ewk->wu.routine_no[0]++;
                set_char_move_init(&ewk->wu, 0, 4);
            } else {
                ewk->wu.routine_no[0] = R0_STOP;
            }
        } else {
            effi4_turn(ewk);
        }
        disp_pos_trans_entry_r(ewk);
        break;
    case R0_CHEER:
        if (!EXE_flag && !Game_pause && !EXE_obroll) {
            char_move(&ewk->wu);
        }
        /* fall through */
    case R0_STOP:
        disp_pos_trans_entry_r(ewk);
        break;
    default:
        all_cgps_put_back(&ewk->wu);
        push_effect_work(&ewk->wu);
        break;
    }
}



/* faces the player old_rno[1] by its x position */
/* provisional name */
void effi4_turn(WORK_Other* ewk) {
    s16 ix;
    ix = plw[ewk->wu.old_rno[1]].wu.xyz[0].disp.pos >> 6;
    ix &= 0xF;
    ewk->wu.old_rno[2] = effi4_turn_tbl[ix];
    if (ewk->wu.old_rno[2] != ewk->wu.old_rno[3]) {
        set_char_move_init2(&ewk->wu, 0, 12, ewk->wu.old_rno[2] + 1, 0);
        ewk->wu.old_rno[3] = ewk->wu.old_rno[2];
    }
}



/* provisional name */
void effi4_move_2(WORK_Other* ewk) {
    switch (ewk->wu.routine_no[0]) {
    case R0_INIT:
        ewk->wu.routine_no[0]++;
        ewk->wu.disp_flag = 1;
        set_char_move_init(&ewk->wu, 0, ewk->wu.char_index);
        break;
    case R0_WATCH:
        if (Round_num >= Game_setting.Battle_Number << 1 || PL_Wins[Winner_id] >= Game_setting.Battle_Number + 1) {
            if (plw[Winner_id].player_number == PL_GILL) {
                ewk->wu.routine_no[0]++;
            } else {
                ewk->wu.routine_no[0] = R0_STOP;
            }
        }
        disp_pos_trans_entry_r(ewk);
        break;
    case R0_CHEER:
        if (!EXE_flag && !Game_pause && !EXE_obroll) {
            char_move(&ewk->wu);
        }
        /* fall through */
    case R0_STOP:
        disp_pos_trans_entry_r(ewk);
        break;
    default:
        all_cgps_put_back(&ewk->wu);
        push_effect_work(&ewk->wu);
        break;
    }
}



s32 effect_I4_init(void) {
    WORK_Other* ewk;
    s16 ix;
    s16 i;
    const s16* data_ptr = effi4_data_tbl[0];
    for (i = 0; i < 4; i++) {
        if ((ix = pull_effect_work(4)) == -1) {
            return -1;
        }
        ewk = (WORK_Other*)frw[ix];
        ewk->wu.be_flag = 1;
        ewk->wu.id = 184;
        ewk->wu.work_id = 16;
        ewk->wu.cgromtype = 1;
        ewk->wu.rl_flag = 0;
        ewk->wu.my_col_mode = 0x4200;
        ewk->wu.old_rno[0] = i;
        ewk->wu.dead_f = 0;
        ewk->wu.my_family = 2;
        ewk->wu.my_col_code = 0x2040;
        ewk->wu.char_table[0] = stg00_char_table;
        ewk->wu.xyz[0].disp.pos = *data_ptr++;
        ewk->wu.xyz[1].disp.pos = *data_ptr++;
        ewk->wu.my_priority = ewk->wu.position_z = *data_ptr++;
        ewk->wu.char_index = *data_ptr++;
    }
    return 0;
}



const s16 effi4_turn_tbl[16] = { 0, 0, 0, 0, 0, 0, 1, 1, 2, 2, 3, 3, 4, 4, 5, 5 };
const s16 effi4_data_tbl[4][4] = {
    { 320, 64, 82, 11 }, { 576, 72, 82, 12 }, { 208, 136, 82, 5 }, { 720, 96, 82, 6 },
};
