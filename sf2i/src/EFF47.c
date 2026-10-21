/*
 * EFF47.C  Effect 47: four scattering pieces
 *
 * effect_47_init creates four pieces around a character, each with its own offset, life
 * time and speed from eff47_data_tbl / eff47_sp_tbl. effect_47_move moves them under their
 * speeds and hides them when their time runs out.
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "ta_sub.h"
#include "CHARMOVE.h"
#include "charmove_2.h"
#include "aboutspr.h"
#include "EFFECT.h"
#include "effect_2.h"
#include "EFF47.h"



/* 2i 060CDE9C, 3s-near: sf3 src/EFF47.c:23 effect_47_move; 2i: case 1 not gated by EXE_flag/Game_pause, no draw on the last frame */
void effect_47_move(WORK_Other* ewk) {
    switch (ewk->wu.routine_no[0]) {
    case 0:
        ewk->wu.routine_no[0]++;
        ewk->wu.disp_flag = 1;
        ewk->wu.kage_flag = 0;
        set_char_move_init(&ewk->wu, 0, ewk->wu.char_index);
        break;
    case 1:
        ewk->wu.old_rno[0]--;
        if (ewk->wu.old_rno[0] < 0) {
            ewk->wu.routine_no[0]++;
            ewk->wu.disp_flag = 0;
            break;
        }
        char_move(&ewk->wu);
        add_x_sub(ewk);
        add_y_sub(ewk);
        ewk->wu.position_x = ewk->wu.xyz[0].disp.pos & 0x3FF;
        ewk->wu.position_y = ewk->wu.xyz[1].disp.pos & 0x3FF;
        sort_push_request(&ewk->wu);
        break;
    case 2:
        ewk->wu.routine_no[0]++;
        break;
    default:
        all_cgps_put_back(&ewk->wu);
        push_effect_work(&ewk->wu);
        break;
    }
}



/* 2i 060CDF56, 3s-near: sf3 src/EFF47.c:59 effect_47_init */
s32 effect_47_init(WORK* wk, s32 _p1) {
    WORK_Other* ewk;
    s16 ix;
    s16 i;
    const s16* data_ptr = eff47_data_tbl;
    for (i = 0; i < 4; i++) {
        if ((ix = pull_effect_work(4)) == -1) {
            return -1;
        }
        ewk = (WORK_Other*)frw[ix];
        ewk->wu.be_flag = 1;
        ewk->wu.id = 47;
        ewk->wu.work_id = 16;
        ewk->wu.cgromtype = 1;
        ewk->wu.rl_flag = 0;
        *ewk->wu.char_table = etc_char_table;
        ewk->wu.type = i;
        ewk->wu.my_family = 2;
        ewk->wu.char_index = i + 0x43;
        ewk->wu.my_col_mode = wk->my_col_mode;
        ewk->wu.my_col_code = wk->my_col_code;
        ewk->wu.my_family = wk->my_family;
        ewk->wu.position_z = ewk->wu.my_priority = wk->my_priority - 2;
        ewk->wu.xyz[0].disp.pos = wk->xyz[0].disp.pos;
        ewk->wu.xyz[1].disp.pos = wk->xyz[1].disp.pos;
        ewk->wu.xyz[0].disp.pos += *(s16*)data_ptr++;
        ewk->wu.xyz[1].disp.pos += *(s16*)data_ptr++;
        ewk->wu.old_rno[0] = *data_ptr++;
        ewk->wu.mvxy.a[0].sp = eff47_sp_tbl[i][0];
        ewk->wu.mvxy.d[0].sp = eff47_sp_tbl[i][1];
        ewk->wu.mvxy.a[1].sp = eff47_sp_tbl[i][2];
        ewk->wu.mvxy.d[1].sp = eff47_sp_tbl[i][3];
    }
    return 0;
}
