/*
 * EFF08.C  Animated background layer (effect 08)
 *
 * Animates the BG1 scroll layer by flipping its character page between the layer's own
 * map and a second copy built in a SIMM RAM slot, and by moving its Y scroll per frame.
 * effect_08_init records the two page addresses (the second allocated with
 * simmram_big_page_alloc_40); effect_08_build_tile_grid writes the 2x16 cell grid into it.
 * effect_08_move steps through eff08_anm_tbl, and at the end of each 8-frame cycle picks a
 * random number of extra loops through eff08_anm2_tbl; the slot is freed on exit.
 * Started from the BG030 base-layer init (bg0301_init00).
 * 2i: effect 08 is an object that effect_07_init starts with the effect 07 object as its
 * master: it animates while the master shows pattern 2 and restarts when the master does.
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
#include "EFFECT.h"
#include "effect_2.h"
#include "PLS02.h"
#include "sys_config.h"
#include "sys_config_2.h"
#include "sys_config_3.h"
#include "aboutspr.h"
#include "CHARMOVE.h"
#include "ta_sub.h"
#include "eff08.h"

extern const u32 eff08_char_table[];   /* provisional name */



/* 2i 060C2A54, 3s-near: sf3 src/eff08.c:35 effect_08_move; 2i: follows its master (3s: the animated BG1 layer) */
void effect_08_move(WORK_Other* ewk) {
    WORK_Other* oya;
    if (obr_no_disp_check()) {
        return;
    }
    oya = (WORK_Other*)ewk->my_master;
    switch (ewk->wu.routine_no[0]) {
    case 0:
        ewk->wu.routine_no[0]++;
        ewk->wu.disp_flag = 1;
        set_char_move_init(&ewk->wu, 0, ewk->wu.char_index);
        /* fall through */
    case 1:
        if (!EXE_flag && !Game_pause && !EXE_obroll) {
            if (!oya->wu.routine_no[0]) {
                if (oya->wu.char_index == 2) {
                    ewk->wu.char_index = 0;
                    ewk->wu.routine_no[0] = 0;
                }
            } else if (oya->wu.char_index == 2) {
                char_move(&ewk->wu);
            }
        }
        sort_push_request4(&ewk->wu);
        break;
    default:
        all_cgps_put_back(&ewk->wu);
        push_effect_work(&ewk->wu);
        break;
    }
}



/* 2i 060C2B00 (effect_08_init row): sf3 src/eff08.c:137 effect_08_init; 2i: one object for the master */
s32 effect_08_init(WORK_Other* oya) {
    WORK_Other* ewk;
    s16 ix;
    if ((ix = pull_effect_work(4)) == -1) {
        return -1;
    }
    ewk = (WORK_Other*)frw[ix];
    ewk->my_master = (u32*)oya;
    ewk->wu.be_flag = 1;
    ewk->wu.id = 8;
    ewk->wu.work_id = 16;
    ewk->wu.my_priority = 64;
    ewk->wu.cgromtype = 1;
    ewk->wu.rl_flag = 0;
    ewk->wu.my_col_mode = 0x4200;
    ewk->wu.my_family = 2;
    ewk->wu.my_col_code = 0x2040;
    ewk->wu.position_x = 432;
    ewk->wu.position_y = 118;
    ewk->wu.position_z = 70;
    ewk->wu.char_table[0] = eff08_char_table;
    ewk->wu.char_index = 0;
    return 0;
}
