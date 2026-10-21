/*
 * EFF15.C  Effect 15: appearance smoke and small stones
 *
 * effect_15_init is called from the appearance scripts (appear.c). Type 0 (eff15_kemuri) is
 * the smoke slot and does nothing; type 1 (eff15_koishi) is a small stone that is thrown
 * across the scene under gravity, lands and plays its landing animation before ending.
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
#include "bg_sub.h"
#include "bg_sub_2.h"
#include "bg_sub_3.h"
#include "bg_sub_4.h"
#include "bg_sub_5.h"
#include "EFF15.h"

void eff15_kemuri(WORK_Other* ewk);

void eff15_koishi(WORK_Other* ewk);



/* 2i 060C7144, 3s-exact: sf3 src/EFF15.c:32 effect_15_move */
void effect_15_move(WORK_Other* ewk) {
    if (ewk->wu.type) {
        eff15_koishi(ewk);
    } else {
        eff15_kemuri(ewk);
    }
}



void eff15_kemuri(WORK_Other* ewk) {
    WORK* oya_ptr;
}



/* 2i 060C7152, 3s-near: sf3 src/EFF15.c:48 eff15_koishi */
void eff15_koishi(WORK_Other* ewk) {
    WORK* oya_ptr = (WORK*)ewk->my_master;
    switch (ewk->wu.routine_no[0]) {
    case 0:
        ewk->wu.routine_no[0]++;
        ewk->wu.disp_flag = 1;
        set_char_move_init(&ewk->wu, 0, ewk->wu.char_index);
        if (ewk->wu.type == 1) {
            ewk->wu.mvxy.a[0].sp = 0x8000;
            ewk->wu.mvxy.d[0].sp = 0;
            ewk->wu.mvxy.a[1].sp = -0x28000;
            ewk->wu.mvxy.d[1].sp = -0x6000;
            ewk->wu.xyz[0].disp.pos = 640;
            ewk->wu.old_rno[2] = 64;
            break;
        }
        ewk->wu.mvxy.a[0].sp = -0x8000;
        ewk->wu.mvxy.d[0].sp = 0;
        ewk->wu.mvxy.a[1].sp = 0;
        ewk->wu.mvxy.d[1].sp = -0x4000;
        ewk->wu.xyz[0].disp.pos = 576;
        ewk->wu.old_rno[2] = 72;
        break;
    case 1:
        if (!EXE_flag && !Game_pause) {
            char_move(&ewk->wu);
            add_x_sub(ewk);
            add_y_sub(ewk);
            if (ewk->wu.xyz[1].disp.pos < ewk->wu.old_rno[2]) {
                ewk->wu.routine_no[0]++;
                set_char_move_init(&ewk->wu, 0, 41);
            }
        }
        suzi_sync_pos_set(ewk);
        sort_push_request(&ewk->wu);
        break;
    case 2:
        if (!EXE_flag && !Game_pause) {
            char_move(&ewk->wu);
            if (ewk->wu.cg_type) {
                ewk->wu.routine_no[0]++;
                ewk->wu.disp_flag = 0;
            }
        }
        suzi_sync_pos_set(ewk);
        sort_push_request(&ewk->wu);
        break;
    case 3:
        ewk->wu.routine_no[0]++;
        break;
    default:
        all_cgps_put_back(&ewk->wu);
        push_effect_work(&ewk->wu);
        break;
    }
}



/* 2i 060C72C4, 3s-near: sf3 src/EFF15.c:107 effect_15_init */
s32 effect_15_init(WORK* wk, u8 data) {
    WORK_Other* ewk;
    s16 ix;
    if ((ix = pull_effect_work(4)) == -1) {
        return -1;
    }
    ewk = (WORK_Other*)frw[ix];
    ewk->wu.be_flag = 1;
    ewk->wu.id = 0xF;
    ewk->master_id = wk->id;
    ewk->wu.cgromtype = 1;
    ewk->wu.type = data;
    ewk->wu.my_col_mode = 0x4200;
    ewk->wu.my_col_code = 0x2020;
    ewk->wu.my_family = wk->my_family;
    ewk->my_master = (u32*)wk;
    ewk->wu.rl_flag = 0;
    ewk->wu.xyz[0].disp.pos = 629;
    ewk->wu.xyz[1].disp.pos = 340;
    ewk->wu.my_priority = 76;
    ewk->wu.position_z = 76;
    ewk->wu.char_table[0] = etc2_char_table;
    if (data) {
        ewk->wu.char_index = 40;
    } else {
        ewk->wu.char_index = 39;
    }
    ewk->wu.sync_suzi = 0;
    suzi_offset_set(&ewk->wu);
    return 0;
}
