/*
 * EFFB1_INIT.C  Effect B1 init: bonus-stage result marks
 *
 * effect_B1_init is called by the bonus-stage controller (bbbs_com_execute in BBBSCOM.c) when
 * the blocking bonus stage starts. It creates a connected-sprite work of 20 marks copied from
 * bbbs_blocking (layout chosen by Game_setting), clears the 20 per-mark state entries with
 * bbbs_clear, and mirrors the marks when the player faces left. See EFFB1.C for the movement.
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "EFFECT.h"
#include "effect_2.h"
#include "EFFB1_INIT.h"



/* my_col_code 0x2081 */
s32 effect_B1_init(PLW* wk) {
    WORK_Other_CONN* ewk;
    s16 ix;
    s16 i;
    s16 type;
    if ((ix = pull_effect_work(4)) == -1) {
        return -1;
    }
    ewk = (WORK_Other_CONN*)frw[ix];
    ewk->wu.be_flag = 1;
    ewk->wu.id = 111;
    ewk->wu.work_id = 16;
    ewk->wu.my_family = 2;
    ewk->wu.cgromtype = 1;
    ewk->wu.my_col_mode = 0x4200;
    ewk->wu.my_col_code = 0x2081;
    ewk->num_of_conn = 20;
    type = (Game_setting.mode != 0);
    for (i = 0; i < 20; i++) {
        ewk->conn[i] = bbbs_blocking[type][i];
    }
    for (i = 0; i < 20; i++) {
        ewk->conn[i + 20] = *bbbs_clear;
    }
    if (wk->wu.rl_flag) {
        for (i = 0; i < 20; i++) {
            ewk->conn[i].nx = -ewk->conn[i].nx;
        }
    }
    return 0;
}
