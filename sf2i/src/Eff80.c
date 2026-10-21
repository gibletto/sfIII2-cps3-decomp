/*
 * EFF80.C  Effect 80: a select-screen mark that follows its parent (2nd Impact)
 *
 * effect_80_init creates the mark under its parent work, its pattern by character (My_char), the
 * player slot and the Country; Kind is kept in routine_no[7]. effect_80_move keeps it on the parent,
 * waits until the player's Stop_Cursor is clear and frees it once it has left the screen; a Kind 7
 * mark is taken away at once by a Suicide request.
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
#include "Eff80.h"



void effect_80_move(WORK_Other* ewk) {
    WORK* mwk = (WORK*)ewk->my_master;
    if (ewk->wu.routine_no[7] == 7 && Suicide) {
        ewk->wu.disp_flag = 0;
        ewk->wu.routine_no[0] = 3;
        return;
    }
    switch (ewk->wu.routine_no[0]) {
    case 0:
        ewk->wu.routine_no[0]++;
        ewk->wu.disp_flag = 1;
        set_char_move_init2(&ewk->wu, 0, ewk->wu.char_index, ewk->wu.vital_new + 1, 0);
        break;
    case 1:
        if (Stop_Cursor[ewk->master_id] == 0) {
            ewk->wu.routine_no[0]++;
        }
        break;
    case 2:
        if (Ck_Range_Out_S(ewk, 2, 96)) {
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
    ewk->wu.position_x = ewk->wu.xyz[0].disp.pos = mwk->position_x;
    ewk->wu.position_y = ewk->wu.xyz[1].disp.pos = mwk->position_y + mwk->cg_type;
    ewk->wu.position_z = ewk->wu.xyz[2].disp.pos = mwk->position_z - 1;
    sort_push_request4(&ewk->wu);
}



s32 effect_80_init(WORK_Other* oya, s16 PL_id, s16 Master_Player, s16 Priority, s16 Kind) {
    WORK_Other* ewk;
    s16 ix;
    s16 k;
    if ((ix = pull_effect_work(4)) == -1) {
        return -1;
    }
    ewk = (WORK_Other*)frw[ix];
    ewk->wu.be_flag = 1;
    ewk->wu.id = 80;
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
    ewk->wu.routine_no[7] = Kind;
    if (Country == 1) {
        k = 0;
    } else {
        k = 1;
    }
    ewk->wu.char_index = 7;
    ewk->wu.vital_new = My_char[PL_id] * 3 + k * 48 + Master_Player;
    return 0;
}
