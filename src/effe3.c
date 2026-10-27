/*
 * EFFE3.C  Super art flash background (effect E3)
 *
 * While a player's Flash_MT is set this effect swaps the stage for a single BG3 picture.
 * effect_E3_move waits for either player's flash request, turns every stage layer off and
 * BG3 on (unless an alternate background is already up), holds it for the time given in
 * effE3_data while effE3_scroll_set positions BG3 and family 4, then restores the stage
 * layers and clears the request. It yields to the finish screen (akebono_flag) and to the
 * alternate-background effect (seraph_flag), and flags its own state in sa_pa_flag.
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
#include "fifo.h"
#include "EFFECT.h"
#include "effect_2.h"
#include "aboutspr.h"
#include "effe3.h"

/* routine_no[0] */
#define R0_WAIT         0       /* wait for a flash request */
#define R0_START        1       /* switch to the flash picture */
#define R0_HOLD         2       /* hold for the flash time */
#define R0_RESTORE      3       /* restore the stage layers */

/* effE3_data columns */
#define E3_BG_X         0       /* BG3 x position */
#define E3_BG_Y         1       /* BG3 y position */
#define E3_TIME         2       /* frames the picture is held */




void effect_E3_move(WORK_Other* ewk) {
    s16 i;
    if (akebono_flag) {
        sa_pa_flag = 0;
        return;
    }
    switch (ewk->wu.routine_no[0]) {
    case R0_WAIT:
        if (!Flash_MT[0] && !Flash_MT[1]) {
            break;
        }
        ewk->wu.routine_no[0]++;
        break;
    case R0_START:
        ewk->wu.routine_no[0]++;
        if (another_bg[0] || another_bg[1]) {
            sa_pa_flag = 0;
            if (Flash_MT[0]) {
                Flash_MT[0] = 0;
            } else {
                Flash_MT[1] = 0;
            }
            ewk->wu.routine_no[0] = R0_WAIT;
            return;
        }
        sa_pa_flag = 1;
        for (i = 0; i < bg_w.scno; i++) {
            Bg_Off_W(1 << i);
        }
        Bg_On_W(8);
        if (Flash_MT[0]) {
            ewk->wu.old_rno[0] = effE3_data[Flash_MT[0]][E3_TIME];
            ewk->master_id = 0;
        } else {
            ewk->wu.old_rno[0] = effE3_data[Flash_MT[1]][E3_TIME];
            ewk->master_id = 1;
        }
        effE3_scroll_set(ewk);
        return;
        break;
    case R0_HOLD:
        ewk->wu.old_rno[0]--;
        if (ewk->wu.old_rno[0] <= 0) {
            ewk->wu.routine_no[0]++;
            break;
        } else {
            effE3_scroll_set(ewk);
        }
        break;
    case R0_RESTORE:
        ewk->wu.routine_no[0] = R0_WAIT;
        Flash_MT[ewk->master_id] = 0;
        sa_pa_flag = 0;
        if (akebono_flag) {
            return;
        }
        if (seraph_flag) {
            return;
        }
        for (i = 0; i < bg_w.scno; i++) {
            Bg_On_W(1 << i);
        }
        Bg_Off_W(8);
        return;
        break;
    default:
        all_cgps_put_back(ewk);
        push_effect_work(&ewk->wu);
        return;
    }
}


/* provisional name */
void effE3_scroll_set(WORK_Other* ewk) {
    s32 x = effE3_data[Flash_MT[ewk->master_id]][E3_BG_X] - bg_w.pos_offset;
    s32 y = effE3_data[Flash_MT[ewk->master_id]][E3_BG_Y];
    scrn_map_set(3, ake_scrl_w[2].adrs);
    Scrn_Move_Set(3, x, y);
    x = -x & 0x3FF;
    y = (0x300 - (y & 0x3FF)) & 0x3FF;
    Family_Set_W(4, x, y);
}


/* provisional name */
void effect_E3_dummy_1(void) {}


/* provisional name */
void effect_E3_dummy_2(void) {}
