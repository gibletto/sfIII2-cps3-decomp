/*
 * EFFB6.C  Effect B6: another-BG overlay parts
 *
 * Effect B6 draws a set of background overlay cells for the another-BG switch: effect_B6_init is
 * called twice (types 0 and 1) from efff0.c. effect_B6_move copies the cell positions from
 * effB6_pos_tbl_0 / _1 and, while another_bg[] is set, shows the parts of its type and slides
 * them by the offsets for the switch direction (1-4), drawing with disp_car_parts_cells.
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "ta_sub.h"
#include "aboutspr.h"
#include "EFFECT.h"
#include "effect_2.h"
#include "CHARMOVE.h"
#include "charmove_2.h"
#include "bg_sub.h"
#include "bg_sub_2.h"
#include "bg_sub_3.h"
#include "bg_sub_4.h"
#include "bg_sub_5.h"
#include "PLS02.h"
#include "EFFB6.h"

/* routine_no[0] */
#define R0_INIT         0       /* copy the cell positions */
#define R0_MOVE         1       /* show and slide the parts */
#define R0_KILL         2       /* put the work back */

/* routine_no[1] */
#define R1_WAIT         0       /* wait for the another-BG switch */
#define R1_SLIDE        1       /* slide the parts while it runs */

void effect_B6_move(WORK_Other_CONN* ewk_conn) {
    WORK_B6* ewk = (WORK_B6*)ewk_conn;
    WORK* oya = ewk->my_master;
    s16 i;
    switch (ewk->wu.routine_no[0]) {
    case R0_INIT:
        ewk->wu.routine_no[0]++;
        ewk->wu.disp_flag = 0;
        ewk->num = effB6_num_tbl[ewk->wu.type];
        if (ewk->wu.type) {
            effB6_pos_data_set(ewk, effB6_pos_tbl_1, ewk->num);
        } else {
            effB6_pos_data_set(ewk, effB6_pos_tbl_0, ewk->num);
        }
        return;
    case R0_MOVE:
        if (ewk->wu.dead_f == 1) {
            ewk->wu.disp_flag = 0;
            ewk->wu.routine_no[0]++;
            break;
        }
        if (akebono_flag != 0) {
            break;
        }
        switch (ewk->wu.routine_no[1]) {
        case R1_WAIT:
            if (!(another_bg[0] | another_bg[1])) {
                break;
            }
            ewk->wu.routine_no[1]++;
            break;
        case R1_SLIDE:
            if (another_bg[0] | another_bg[1]) {
                ewk->wu.disp_flag = 0;
                switch (another_bg[oya->type]) {
                case 1:
                    if (ewk->wu.type == 0) {
                        for (i = 0; i < ewk->num; i++) {
                            ewk->pos[i][1] += ewk->src[i].d[3];
                            ewk->pos[i][2] = ewk->src[i].d[4];
                        }
                        ewk->wu.disp_flag = 1;
                    }
                    break;
                case 2:
                    if (ewk->wu.type != 0) {
                        for (i = 0; i < ewk->num; i++) {
                            ewk->pos[i][0] += ewk->src[i].d[1];
                            ewk->pos[i][2] = ewk->src[i].d[5];
                        }
                        ewk->wu.disp_flag = 1;
                    }
                    break;
                case 3:
                    if (ewk->wu.type == 0) {
                        break;
                    }
                    for (i = 0; i < ewk->num; i++) {
                        ewk->pos[i][0] -= ewk->src[i].d[1];
                        ewk->pos[i][2] = ewk->src[i].d[4];
                    }
                    ewk->wu.disp_flag = 1;
                    break;
                case 4:
                    if (ewk->wu.type != 0) {
                        break;
                    }
                    for (i = 0; i < ewk->num; i++) {
                        ewk->pos[i][1] -= ewk->src[i].d[3];
                        ewk->pos[i][2] = ewk->src[i].d[5];
                    }
                    ewk->wu.disp_flag = 1;
                }
            } else {
                ewk->wu.disp_flag = 0;
                ewk->wu.routine_no[1] = R1_WAIT;
            }
            break;
        }
        disp_car_parts_cells(&ewk->wu);
        break;
    case R0_KILL:
    default:
        push_effect_work(&ewk->wu);
        return;
    }
}

/* provisional name */
void effB6_pos_data_set(ewk, tbl, num)
WORK_B6* ewk;
const B6_SRC* tbl;
s16 num;
{
    s16 i;
    for (i = 0; i < num; i++) {
        ewk->src[i] = tbl[i];
        ewk->pos[i][0] = ewk->src[i].d[0];
        ewk->pos[i][1] = ewk->src[i].d[2];
        ewk->pos[i][2] = ewk->src[i].d[4];
        ewk->pos[i][0] += bg_w.bgw[1].pos_x_work;
    }
}



/* my_col_code 0x20C5 */
s32 effect_B6_init(WORK_Other* oya, u8 type) {
    WORK_Other* ewk;
    s16 ix;
    if ((ix = pull_effect_work(5)) == -1) {
        return -1;
    }
    ewk = (WORK_Other*)frw[ix];
    ewk->wu.be_flag = 1;
    ewk->wu.id = 116;
    ewk->wu.work_id = 16;
    ewk->wu.type = type;
    ewk->wu.cgromtype = 1;
    ewk->wu.my_col_mode = 0x4200;
    ewk->wu.my_col_code = 0x20C5;
    ewk->wu.my_family = 2;
    ewk->wu.my_priority = ewk->wu.position_z = 69;
    ewk->my_master = (u32*)oya;
    ewk->wu.sync_suzi = 0;
    suzi_offset_set(&ewk->wu);
    return 0;
}
