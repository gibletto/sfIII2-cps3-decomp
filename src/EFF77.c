/*
 * EFF77.C  Effect 77: temporary full-screen background
 *
 * Effect 77 hides the players and all BG layers, shows BG layer 3 scrolled to the position
 * in eff77_data_tbl and holds it for a set time with sa_pa_flag set, then restores the
 * layers and players. It also clears the another-BG and flash state while it runs.
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
#include "EFF77.h"

/* routine_no[0] */
#define R0_INIT         0       /* hide the players */
#define R0_BG_ON        1       /* show only bg 3, set the time */
#define R0_BG_AGAIN     2       /* show only bg 3 again */
#define R0_HOLD         3       /* hold for the set time */
#define R0_RESTORE      4       /* bring the layers back */
#define R0_KILL         99      /* (default) put the work back */



s16 chk77_flag;  /* 02068C08 */


void effect_77_move(WORK_Other* ewk) {
    s16 i;
    another_bg[0] = another_bg[1] = 0;
    Flash_MT[0] = Flash_MT[1] = 0;
    if (akebono_flag) {
        ewk->wu.routine_no[0] = R0_KILL;
    }
    switch (ewk->wu.routine_no[0]) {
    case R0_INIT:
        if (Game_pause || EXE_flag) {
            break;
        }
        ewk->wu.routine_no[0]++;
        plw[0].wu.disp_flag = 0;
        plw[1].wu.disp_flag = 0;
        if (ewk->wu.type == 0) {
            Extra_Break = 1;
        }
    case R0_BG_ON:
        if (Game_pause || EXE_flag) {
            break;
        }
        ewk->wu.routine_no[0]++;
        sa_pa_flag = 1;
        for (i = 0; i < bg_w.scno; i++) {
            Bg_Off_W(1 << i);
        }
        Bg_On_W(8);
        ewk->wu.old_rno[0] = eff77_data_tbl[ewk->wu.type][0];
        eff77_scroll_set(ewk);
        return;
        break;
    case R0_BG_AGAIN:
        if (Game_pause || EXE_flag) {
            break;
        }
        ewk->wu.routine_no[0]++;
        for (i = 0; i < bg_w.scno; i++) {
            Bg_Off_W(1 << i);
        }
        Bg_On_W(8);
        sa_pa_flag = 1;
    case R0_HOLD:
        if (Game_pause || EXE_flag) {
        } else {
            ewk->wu.old_rno[0]--;
            if (ewk->wu.old_rno[0] <= 0) {
                sa_pa_flag = 0;
                ewk->wu.routine_no[0]++;
                plw[0].wu.disp_flag = 1;
                plw[1].wu.disp_flag = 1;
                break;
            }
            sa_pa_flag = 1;
        }
        eff77_scroll_set(ewk);
        return;
        break;
    case R0_RESTORE:
        if (Game_pause || EXE_flag) {
            break;
        }
        ewk->wu.routine_no[0]++;
        if (ewk->wu.type == 0) {
            Extra_Break = 0;
        }
        for (i = 0; i < bg_w.scno; i++) {
            Bg_On_W(1 << i);
        }
        Bg_Off_W(8);
        break;
    default:
        if (Game_pause || EXE_flag) {
        } else {
            sa_pa_flag = 0;
            all_cgps_put_back(ewk);
            push_effect_work(&ewk->wu);
        }
        break;
    }
}



/* provisional name */
void eff77_scroll_set(WORK_Other* ewk) {
    s32 x;
    s32 y;
    x = *(s16*)((u8*)eff77_data_tbl + 2 + (s8)(ewk->wu.type * 6)) - bg_w.pos_offset;
    y = *(s16*)((u8*)eff77_data_tbl + 4 + (s8)(ewk->wu.type * 6));
    scrn_map_set(3, ake_scrl_w[2].adrs);
    Scrn_Move_Set(3, x, y);
    x = -x & 0x3FF;
    y = (0x300 - (y & 0x3FF)) & 0x3FF;
    Family_Set_W(4, x, y);
}



s32 effect_77_init(u8 _p0, u8 data) {
    WORK_Other* ewk;
    s16 ix;
    chk77_flag = 0;
    if ((ix = pull_effect_work(4)) == -1) {
        return -1;
    }
    ewk = (WORK_Other*)frw[ix];
    ewk->wu.be_flag = 1;
    ewk->wu.id = 77;
    ewk->wu.type = data;
    another_bg[0] = another_bg[1] = 0;
    Flash_MT[0] = Flash_MT[1] = 0;
    sa_pa_flag = 1;
    return 0;
}
