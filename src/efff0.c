/*
 * EFFF0.C  Alternate background controller (effect F0)
 *
 * Switches the stage display to a special full-screen background while either player's
 * another_bg request is set. effect_F0_move turns the stage layers off, chooses the BG3
 * source page from ake_scrl_w by request type, lowers sound register 0 while active,
 * tracks which player's request has priority, and on release restores the layers
 * (effF0_scroll_reset). effF0_scroll_set positions BG3 and family 4 from the scroll records
 * and BG1. seraph_flag tells other effects it is active; it yields to the finish screen.
 * effect_F0_init creates it together with two effect B6 objects.
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "sys_test.h"
#include "sys_test_2.h"
#include "sys_test_2b.h"
#include "sys_test_2c.h"
#include "sys_test_3.h"
#include "sys_test_4.h"
#include "sys_test_5.h"
#include "EFFB6.h"
#include "fifo.h"
#include "EFFECT.h"
#include "effect_2.h"
#include "aboutspr.h"
#include "textsound.h"
#include "textsound_2.h"
#include "textsound_3.h"
#include "efff0.h"

/* routine_no[0] */
#define R0_INIT         0       /* point BG 3 at the first page */
#define R0_NORMAL       1       /* turn the stage layers back on */
#define R0_WAIT         2       /* wait for an another-BG request */
#define R0_ON           3       /* turn the stage layers off */
#define R0_MOVE         4       /* show the BG of the player in charge */
#define R0_OFF          5       /* put the stage scroll back */



void effect_F0_move(WORK_Other* ewk) {
    s16 i;
    if (akebono_flag) {
        seraph_flag = 0;
    } else {
        switch (ewk->wu.routine_no[0]) {
        case R0_INIT:
            ewk->wu.routine_no[0]++;
            scrn_map_set_now(3, ake_scrl_w[0].adrs);
        case R0_NORMAL:
            seraph_flag = 0;
            if (!akebono_flag && !sa_pa_flag) {
                for (i = 0; i < bg_w.scno; i++) {
                    Bg_On_W(1 << i);
                }
                Bg_Off_W(8);
            }
            ewk->wu.routine_no[0]++;
            ewk->wu.dir_old = 0;
        case R0_WAIT:
            if (!another_bg[0] && !another_bg[1]) {
                break;
            }
            ewk->wu.routine_no[0]++;
            if (another_bg[0] && another_bg[1]) {
                ewk->wu.type = 0;
            } else {
                if (another_bg[0]) {
                    ewk->wu.type = 0;
                } else {
                    ewk->wu.type = 1;
                }
            }
            seraph_flag = 1;
            break;
        case R0_ON:
            ewk->wu.routine_no[0]++;
            for (i = 0; i < bg_w.scno; i++) {
                Bg_Off_W(1 << i);
            }
            Bg_Off_W(8);
            switch (another_bg[ewk->wu.type]) {
            case 1:
            case 4:
                ewk->wu.dir_old = 1;
                break;
            default:
                ewk->wu.dir_old = 0;
                break;
            }
            sound_reg_level_set(0, 0xF0);
        case R0_MOVE:
            if (ewk->wu.type) {
                if (another_bg[0] && another_bg_old[0] == 0) {
                    ewk->wu.type = 0;
                }
            } else if (another_bg[1] && another_bg_old[1] == 0) {
                ewk->wu.type = 1;
            }
            if (ewk->wu.type) {
                if (another_bg[1] == 0 && another_bg[0]) {
                    ewk->wu.type = 0;
                }
            } else if (another_bg[0] == 0 && another_bg[1]) {
                ewk->wu.type = 1;
            }
            Bg_Off_W(8);
            switch (another_bg[ewk->wu.type]) {
            case 2:
            case 3:
                scrn_map_set(3, ake_scrl_w[3].adrs);
                break;
            case 4:
                if (!ewk->wu.dir_old) {
                    ewk->wu.dir_old = 1;
                }
                scrn_map_set(3, ake_scrl_w[4].adrs);
                break;
            default:
                if (!ewk->wu.dir_old) {
                    ewk->wu.dir_old = 1;
                }
                scrn_map_set(3, ake_scrl_w[0].adrs);
                break;
            }
            if (another_bg[0] || another_bg[1]) {
                seraph_flag = 1;
                effF0_scroll_set(ewk);
            } else {
                ewk->wu.routine_no[0] = R0_OFF;
                sound_reg_level_set(0, 0);
                another_bg_old[0] = another_bg_old[1] = 0;
                effF0_scroll_set(ewk);
                seraph_flag = 0;
            }
            break;
        case R0_OFF:
            ewk->wu.routine_no[0] = R0_NORMAL;
            another_bg_old[0] = another_bg_old[1] = 0;
            effF0_scroll_reset(ewk);
            effF0_scroll_set(ewk);
            break;
        default:
            all_cgps_put_back(&ewk->wu);
            push_effect_work(&ewk->wu);
            break;
        }
    }
    another_bg_old[0] = another_bg[0];
    another_bg_old[1] = another_bg[1];
}



/* provisional name */
void effF0_scroll_reset(WORK_Other* ewk) {
    s16 i;
    seraph_flag = 0;
    if (!sa_pa_flag) {
        Bg_Off_W(8);
        for (i = 0; i < bg_w.scno; i++) {
            Bg_On_W(1 << i);
        }
    }
    ake_scrl_w[0].xy[0].cal = 0x2000000;
    ake_scrl_w[0].xy[1].cal = 0;
    ake_scrl_w[3].xy[0].cal = 0x2000000;
    ake_scrl_w[3].xy[1].cal = 0;
    ake_scrl_w[4].xy[0].cal = 0x2000000;
    ake_scrl_w[4].xy[1].cal = 0;
    ake_scrl_w[0].pos_x = ake_scrl_w[0].xy[0].disp.pos;
    ake_scrl_w[0].pos_y = ake_scrl_w[0].xy[1].disp.pos;
    ake_scrl_w[3].pos_x = ake_scrl_w[3].xy[0].disp.pos;
    ake_scrl_w[3].pos_y = ake_scrl_w[3].xy[1].disp.pos;
    ake_scrl_w[4].pos_x = ake_scrl_w[4].xy[0].disp.pos;
    ake_scrl_w[4].pos_y = ake_scrl_w[4].xy[1].disp.pos;
}



/* provisional name */
void effF0_scroll_set(WORK_Other* ewk) {
    s32 x;
    s32 y;
    switch (another_bg[ewk->wu.type]) {
    case 2:
        ake_scrl_w[3].pos_x = ake_scrl_w[3].xy[0].disp.pos & 0x3FF;
        ake_scrl_w[3].pos_x -= bg_w.pos_offset;
        ake_scrl_w[3].pos_y = bg_w.bgw[1].wxy[1].disp.pos;
        x = ake_scrl_w[3].pos_x;
        y = ake_scrl_w[3].pos_y;
        break;
    case 3:
        ake_scrl_w[3].pos_x = ake_scrl_w[3].xy[0].disp.pos & 0x3FF;
        ake_scrl_w[3].pos_x -= bg_w.pos_offset;
        ake_scrl_w[3].pos_y = bg_w.bgw[1].wxy[1].disp.pos;
        x = ake_scrl_w[3].pos_x;
        y = ake_scrl_w[3].pos_y;
        y += 0x200;
        break;
    case 4:
        ake_scrl_w[4].pos_x = bg_w.bgw[1].wxy[0].disp.pos;
        ake_scrl_w[4].pos_x -= bg_w.pos_offset;
        ake_scrl_w[4].pos_y = ake_scrl_w[4].xy[1].disp.pos & 0x3FF;
        x = ake_scrl_w[4].pos_x;
        y = ake_scrl_w[4].pos_y;
        break;
    default:
        ake_scrl_w[0].pos_x = bg_w.bgw[1].wxy[0].disp.pos;
        ake_scrl_w[0].pos_x -= bg_w.pos_offset;
        ake_scrl_w[0].pos_y = ake_scrl_w[0].xy[1].disp.pos & 0x3FF;
        x = ake_scrl_w[0].pos_x;
        y = ake_scrl_w[0].pos_y;
        break;
    }
    Scrn_Move_Set(3, x, y);
    x = -x & 0x3FF;
    y = (0x300 - (y & 0x3FF)) & 0x3FF;
    Family_Set_W(4, x, y);
}



/* none in the combo demo, loads char gfx 0x9A40 */
s32 effect_F0_init(WORK* wk) {
    s16 ix;
    WORK_Other* ewk;

    if (Combo_Demo_Flag) {
        return;
    }
    ix = pull_effect_work(4);
    if (ix == -1) {
        return -1;
    }
    ewk = (WORK_Other*)frw[ix];
    ewk->wu.id = 150;
    another_bg[1] = another_bg[0] = another_bg[1] = 0;
    another_bg_old[0] = 0;
    load_char_gfx(0x9A40, 1);
    effect_B6_init(ewk, 0);
    return effect_B6_init(ewk, 1);
}
