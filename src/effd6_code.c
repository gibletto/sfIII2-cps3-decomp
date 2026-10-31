/*
 * EFFD6_CODE.C  Effect D6: rose petals
 *
 * Effect D6 is one petal: setup_hana_extra spawns num_of_hana[] petals with random directions and
 * speeds (hana_dir_hosei, hana_speed_hosei, hana_delta_hosei); effect_D6_move slows each petal
 * to a stop with add_pos_dir_064, lets it hang for 24 frames, blinks it for 12 and frees it.
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "EFFECT.h"
#include "effect_2.h"
#include "EFFI8.h"
#include "PLS02.h"
#include "CALDIR.h"
#include "CHARMOVE.h"
#include "charmove_2.h"
#include "aboutspr.h"
#include "EFF03.h"
#include "bg_sub.h"
#include "bg_sub_2.h"
#include "bg_sub_3.h"
#include "bg_sub_4.h"
#include "bg_sub_5.h"
#include "HITCHECK.h"
#include "PLS01.h"
#include "CHARID.h"
#include "effd6_code.h"

/* routine_no[0] */
#define R0_INIT         0       /* set off */
#define R0_MOVE         1       /* drift, hang and blink */
#define R0_END          2       /* one more frame */
#define R0_KILL         3       /* (default) put the work back */

/* routine_no[1] */
#define R1_DRIFT        0       /* slow to a stop */
#define R1_HANG         1       /* hang for 24 frames */
#define R1_BLINK        2       /* (default) blink for 12 frames, then end */



void effect_D6_move(WORK_Other* ewk) {
    switch (ewk->wu.routine_no[0]) {
    case R0_INIT:
        ewk->wu.routine_no[0]++;
        ewk->wu.disp_flag = 1;
        add_pos_dir_064(&ewk->wu, ewk->wu.dir_old << 1);
        set_char_move_init(&ewk->wu, 0, 0x7D);
    case R0_MOVE:
        if (ewk->wu.dead_f == 1 || Suicide != 0) {
            ewk->wu.disp_flag = 0;
            ewk->wu.routine_no[0]++;
            break;
        }
        if (sa_stop_check()) {
        } else {
            if (EXE_flag == 0 && Game_pause == 0) {
                switch (ewk->wu.routine_no[1]) {
                case R1_DRIFT:
                    ewk->wu.dir_old += ewk->wu.dir_step;
                    if (ewk->wu.dir_old < 0) {
                        ewk->wu.dir_old = 0;
                        ewk->wu.routine_no[1]++;
                        ewk->wu.dir_timer = 24;
                    }
                    add_pos_dir_064(&ewk->wu, ewk->wu.dir_old);
                    char_move(&ewk->wu);
                    break;
                case R1_HANG:
                    char_move(&ewk->wu);
                    if (--ewk->wu.dir_timer <= 0) {
                        ewk->wu.routine_no[1]++;
                        ewk->wu.disp_flag = 2;
                        ewk->wu.dir_timer = 12;
                    }
                    break;
                default:
                    char_move(&ewk->wu);
                    if (--ewk->wu.dir_timer <= 0) {
                        ewk->wu.routine_no[0]++;
                        ewk->wu.disp_flag = 0;
                    }
                    break;
                }
            }
            ewk->wu.position_x = ewk->wu.xyz[0].disp.pos;
            ewk->wu.position_y = ewk->wu.xyz[1].disp.pos;
        }
        sort_push_request(&ewk->wu);
        break;
    case R0_END:
        ewk->wu.routine_no[0] = R0_KILL;
        break;
    default:
        all_cgps_put_back(&ewk->wu);
        push_effect_work(&ewk->wu);
        return;
    }
}



s32 effect_D6_init(wk, dr, sp, dl, acc)
WORK_Other* wk;
s16 dr;
s16 sp;
s16 dl;
s16 acc;
{
    WORK_Other* ewk;
    s16 ix;
    if ((ix = pull_effect_work(3)) == -1) {
        return -1;
    }
    ewk = (WORK_Other*)frw[ix];
    ewk->wu.be_flag = 1;
    ewk->wu.id = 136;
    ewk->wu.work_id = 16;
    ewk->wu.rl_flag = wk->wu.rl_flag;
    ewk->wu.my_family = wk->wu.my_family;
    ewk->wu.my_col_mode = wk->wu.my_col_mode;
    ewk->wu.my_col_code = wk->wu.my_col_code;
    ewk->wu.cgromtype = 1;
    ewk->wu.direction = dr;
    ewk->wu.dir_old = (sp * acc) / 16;
    ewk->wu.dir_step = (dl * acc) / 16;
    ewk->master_id = ewk->wu.blink_timing = wk->master_id;
    ewk->wu.xyz[0].disp.pos = wk->wu.position_x;
    ewk->wu.xyz[1].disp.pos = wk->wu.position_y;
    ewk->wu.position_z = wk->wu.position_z + 1;
    ewk->wu.char_table[0] = plef_char_table;
    return 0;
}



void setup_hana_extra(WORK* wk, s16 num, s16 acc) {
    s16 i;
    s16 way = wk->direction * 4;
    s16 rnd_00 = random_16_com() & 3;
    s16 rnd_01;
    for (i = 0; i < num_of_hana[num]; i++) {
        rnd_01 = random_16_com() & 3;
        effect_D6_init((WORK_Other*)wk,
                       way + hana_dir_hosei[rnd_00][i] & 0x3F,
                       hana_speed_hosei[rnd_01][i],
                       hana_delta_hosei[rnd_01][i],
                       acc);
    }
}



