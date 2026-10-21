/*
 * EFFJ4.C  Effects J3 and J4: background pieces
 *
 * effect_J3 plays a one-shot animation at its owner's position and submits a 2D polygon quad.
 * effect_J4 places background pieces from effJ4_data_tbl that scroll with BG1, either for a
 * limited life or permanently (effJ4_piece_set / effJ4_piece_set_stay, effect_J4_init2).
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "bg000.h"
#include "sys_test.h"
#include "sys_test_2.h"
#include "sys_test_2b.h"
#include "sys_test_2c.h"
#include "sys_test_3.h"
#include "sys_test_4.h"
#include "sys_test_5.h"
#include "CHARMOVE.h"
#include "charmove_2.h"
#include "ta_sub.h"
#include "aboutspr.h"
#include "EFF27.h"
#include "EFFECT.h"
#include "effect_2.h"
#include "sys_config.h"
#include "sys_config_2.h"
#include "sys_config_3.h"
#include "effj4.h"
/* 2i 060ED094, 3s-exact: sf3 src/effj4.c:32 effect_J3_move */
void effect_J3_move(WORK_Other* ewk) {
    switch (ewk->wu.routine_no[0]) {
    case 0:
        ewk->wu.routine_no[0]++;
        ewk->wu.disp_flag = 1;
        set_char_move_init(&ewk->wu, 0, ewk->wu.char_index);
        disp_pos_trans_entry(ewk);
        break;
    case 1:
        char_move(&ewk->wu);
        if (ewk->wu.cg_type == 0xFF) {
            ewk->wu.routine_no[0]++;
            break;
        }
        disp_pos_trans_entry(ewk);
        break;
    default:
        all_cgps_put_back(ewk);
        push_effect_work((WORK*)ewk);
        break;
    }
}



/* 2i 060ED110, 3s-near: sf3 src/effj4.c:57 effect_J3_init; 2i: palette source 0x0279B800 */
s32 effect_J3_init(WORK* wk, u8 type) {
    WORK_Other* ewk;
    s16 ix;
    if ((ix = pull_effect_work(4)) == -1) {
        return -1;
    }
    ewk = (WORK_Other*)frw[ix];
    ewk->wu.be_flag = 1;
    ewk->wu.id = 193;
    ewk->wu.work_id = 16;
    ewk->wu.cgromtype = 1;
    ewk->wu.rl_flag = 0;
    ewk->my_master = (u32*)wk;
    ewk->wu.type = type;
    ewk->wu.my_col_mode = 0x4200;
    ewk->wu.dead_f = 0;
    ewk->wu.my_family = 2;
    ewk->wu.my_col_code = 0x2120;
    ewk->wu.char_table[0] = etc2_char_table;
    if (type) {
        ewk->wu.char_index = 57;
        ewk->wu.my_priority = ewk->wu.position_z = 71;
    } else {
        ewk->wu.char_index = 56;
        ewk->wu.my_priority = ewk->wu.position_z = 69;
    }
    ewk->wu.xyz[0].disp.pos = wk->xyz[0].disp.pos;
    ewk->wu.xyz[1].disp.pos = wk->xyz[1].disp.pos;
    polygon2d_submit_quad(0x0279B800, 0x9280, 0x100, 0, 0, 0);
    return 0;
}




