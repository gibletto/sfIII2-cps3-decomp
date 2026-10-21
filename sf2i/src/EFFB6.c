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

/* 2i 060DB81C, 3s-near: sf3 src/EFFB6.c:28 effect_B6_move */
void effect_B6_move(WORK_Other_CONN* ewk_conn) {
    WORK_B6* ewk = (WORK_B6*)ewk_conn;
    WORK* oya = ewk->my_master;
    s16 i;
    switch (ewk->wu.routine_no[0]) {
    case 0:
        ewk->wu.routine_no[0]++;
        ewk->wu.disp_flag = 0;
        ewk->num = effB6_num_tbl[ewk->wu.type];
        if (ewk->wu.type) {
            effB6_pos_data_set(ewk, effB6_pos_tbl_1, ewk->num);
        } else {
            effB6_pos_data_set(ewk, effB6_pos_tbl_0, ewk->num);
        }
        return;
    case 1:
        if (ewk->wu.dead_f == 1) {
            ewk->wu.disp_flag = 0;
            ewk->wu.routine_no[0]++;
            break;
        }
        if (akebono_flag != 0) {
            break;
        }
        switch (ewk->wu.routine_no[1]) {
        case 0:
            if (!(another_bg[0] | another_bg[1])) {
                break;
            }
            ewk->wu.routine_no[1]++;
            break;
        case 1:
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
                ewk->wu.routine_no[1] = 0;
            }
            break;
        }
        disp_car_parts_cells(&ewk->wu);
        break;
    case 2:
    default:
        push_effect_work(&ewk->wu);
        return;
    }
}

/* provisional name */
/* 2i 060DBAB0, 3s-exact: sf3 src/EFFB6.c:117 effB6_pos_data_set */
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



/* 2i 060DBB56, 3s-near: sf3 src/EFFB6.c:134 effect_B6_init; 2i: my_col_code 0x20C5 */
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
