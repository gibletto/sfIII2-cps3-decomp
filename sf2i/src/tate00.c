/*
 * TATE00.C  Stage background control task
 *
 * TATE00 is the per-frame stage BG entry used during fights (and by the debug fight setups):
 * ta0_init00 sets a random compel_flag and runs bg_initialize; ta0_move then calls the stage's
 * own handler (2i: a local table of the 17 stage handlers, no ta0_init01/ta0_init02 and no global
 * ta_move_tbl) every frame and counts down the screen quake timers. The file ends with debug
 * helpers that step through the stages, scroll the layers and switch them off, and free the
 * stage work blocks.
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "bg000.h"
#include "PLS02.h"
#include "tate00.h"
#include "Com_Pl.h"
#include "SYS_sub.h"
#include "fifo.h"
#include "sys_test.h"
#include "sys_test_2.h"
#include "sys_test_2b.h"
#include "sys_test_2c.h"
#include "sys_test_3.h"
#include "sys_test_4.h"
#include "sys_test_5.h"
#include "ta_sub2.h"
#include "ta_sub.h"
#include "sys_config.h"
#include "sys_config_2.h"
#include "sys_config_3.h"
#include "bg_sub_2.h"
#include "bg_sub_3.h"
#include "bg_sub_5.h"
#include "bg_sub.h"
#include "bg040.h"
#include "BG050.h"
#include "bg090.h"
#include "BG100.h"
#include "bg120.h"
#include "bg130.h"
#include "bg140.h"
#include "bg150.h"
#include "bg160.h"
#include "bg190.h"
#include "bonus_bg.h"
#include "bns_bg2.h"



/* 2i 060A0480, 3s-near: sf3 src/tate00.c:81 TATE00 */
void TATE00(void) {
    void (*jump_tbl[2])() = { ta0_init00, ta0_move };
    jump_tbl[bg_w.bg_routine]();
}



/* 2i 060A04A6, 3s-near: sf3 src/tate00.c:88 ta0_init00 */
void ta0_init00(void) {
    bg_w.bg_routine++;
    bg_w.compel_flag = random_16_com();
    bg_w.compel_flag &= 3;
    bg_initialize();
    effect_F0_init();
    effect_E3_dummy_1();
}



/* 2i 060A04D0, 3s-near: sf3 src/tate00.c:113 ta0_move (2i: the handler table is local; the BGnn0 names are
   the table slots, the stage numbers) */
void ta0_move(void) {
    void (*move_tbl[17])() = {
        BG000,
        BG010,
        BG020,
        BG030,
        BG040,
        BG050,
        BG060,
        BG070,
        BG080,
        BG090,
        BG100,
        BG110,
        BG120,
        BG130,
        BG140,
        BG150,
        BG160,
    };
    move_tbl[bg_w.bg_index]();
    if (bg_w.quake_x_index > 0) {
        bg_w.quake_x_index--;
    }
    if (bg_w.quake_y_index > 0) {
        bg_w.quake_y_index--;
    }
}



/* provisional name */
/* 2i 060A053C, 3s-near: sf3 src/tate00.c:126 bg_debug_stage_change */
s32 bg_debug_stage_change(void) {
    u16 sw1 = ~p1sw_1 & p1sw_0;
    u16 sw2 = ~p2sw_1 & p2sw_0;
    u16 ret = 0;
    if (exsw_1 & 0x80) {
        if ((sw1 & 0x80) || (sw2 & 0x80)) {
            bg_w.stage++;
            ret = 1;
            if (bg_w.stage > 16) {
                bg_w.stage = 0;
            }
        }
        if ((sw1 & 0x100) || (sw2 & 0x100)) {
            bg_w.stage--;
            ret = 1;
            if (bg_w.stage < 0) {
                bg_w.stage = 16;
            }
        }
        if ((sw1 & 0x200) || (sw2 & 0x200)) {
            bg_w.area++;
            ret = 1;
            if (bg_w.area > 2) {
                bg_w.area = 0;
            }
        }
    }
    return ret;
}



/* provisional name */
/* 2i 060A05E2, 3s-reloc: sf3 src/tate00.c:159 bg_free_work_blocks */
void bg_free_work_blocks(void) {
    s16 i;
    simmram_block_free_10(scr_cg_c_no);
    for (i = 0; i < bg_w.scno; i++) {
        simmram_block_free_40(bg_w.bgw[i].bg_adrs_c_no);
        sprite_list_clear(i);
        if (bg_w.bgw[i].zuubun != 0) {
            simmram_block_free_40(bg_w.bgw[i].suzi_c_no);
        }
    }
}



/* provisional name */
/* 2i 060A0680, 3s-near: sf3 src/tate00.c:165 bg_debug_scroll_layers (2i: layers 0-5, then bg_pos_hosei2 and
   Bg_Family_Set once) */
void bg_debug_scroll_layers(void) {
    BGW* bgw;
    s32 dx;
    s32 dy;
    s16 i;
    for (i = 0; i < 6; i++) {
        bgw = &bg_w.bgw[i];
        if (p1sw_0 & 0x10) {
            dx = bgw->speed_x * 2;
            dy = bgw->speed_y * 2;
        } else {
            dx = bgw->speed_x;
            dy = bgw->speed_y;
        }
        if (p1sw_0 & 4) {
            Bg_mv_tw_appoint(i, -dx, 0);
            bgw->hos_xy[0].cal = bgw->xy[0].cal;
        }
        if (p1sw_0 & 8) {
            Bg_mv_tw_appoint(i, dx, 0);
            bgw->hos_xy[0].cal = bgw->xy[0].cal;
        }
        if (p1sw_0 & 1) {
            Bg_mv_tw_appoint(i, 0, dy);
            bgw->hos_xy[0].cal = bgw->xy[0].cal;
        }
        if (p1sw_0 & 2) {
            Bg_mv_tw_appoint(i, 0, -dy);
            bgw->hos_xy[0].cal = bgw->xy[0].cal;
        }
    }
    bg_pos_hosei2();
    Bg_Family_Set();
}



/* provisional name */
/* 2i 060A0A30, 3s-exact: sf3 src/tate00.c:213 bg_test_stage_select */
void bg_test_stage_select(void) {
    u16 sw;
    s16 changed;
    s8 save_27;
    s8 save_entry;
    changed = 0;
    sw = ~p1sw_1 & p1sw_0;
    if (sw & 0x80) {
        bg_select_no++;
        if (bg_select_no > 16) {
            bg_select_no = 0;
        }
        bg_w.stage = bg_test_stage_tbl[bg_select_no][0];
        bg_w.area = bg_test_stage_tbl[bg_select_no][1];
        changed = 1;
    }
    if (sw & 0x100) {
        bg_select_no--;
        if (bg_select_no < 0) {
            bg_select_no = 16;
        }
        bg_w.stage = bg_test_stage_tbl[bg_select_no][0];
        bg_w.area = bg_test_stage_tbl[bg_select_no][1];
        changed = 1;
    }
    if (changed) {
        System_all_clear_Wait();
        pcon_rno[0] = pcon_rno[1] = pcon_rno[2] = pcon_rno[3] = 0;
        save_27 = bg_test_flag;
        save_entry = bg_select_no;
        bg_work_clear();
        bg_select_no = save_entry;
        bg_test_flag = save_27;
    }
}



/* provisional name */
/* 2i 060A0AE4, 3s-reloc: sf3 src/tate00.c:252 bg_layers_off */
void bg_layers_off(void) {
    s16 i;

    for (i = 0; i < bg_w.scno; i++) {
        if ((scrn_reg_w[i].ctrl & 0x8000) == 0) {
            continue;
        }
        Bg_Off_W(1 << i);
    }
    if ((scrn_reg_w[3].ctrl & 0x8000) != 0) {
        Bg_Off_W(8);
    }
}
