/*
 * BGST110.C  Stage 11 background (2i)
 *
 * BG110 runs stage 11's two layers (1 and 0) with the same drop-in as stage 03 (bg110_demo), keyed
 * on character 10 instead of 3; the dispatchers have two one-frame steps that pick the drop-in or
 * the normal scroll, and layer 1's steps also load the stage palette.
 */
#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "bg_sub.h"
#include "bg_sub_2.h"
#include "bg_sub_3.h"
#include "bg_sub_4.h"
#include "bg_sub_5.h"
#include "SYS_sub.h"
#include "aboutspr.h"
#include "sys_config.h"
#include "sys_test.h"
#include "meta_col_mem.h"
#include "color3rd.h"
#include "eff05.h"
#include "eff06.h"
#include "eff88.h"

s32 Check_Shin_Gouki_Next(void);
void load_any_color();
extern const u8 bg_fade_level_tbl[];
extern s16 Appear_end;
s32 effect_12_init();
s32 effect_25_init();
s32 effect_29_init();
s32 effect_44_init();
void bg1101(void);
void bg1102(void);
void bg1101_init00(void);
void bg1101_next4(void);
void bg1101_next3(void);
void bg1102_init00(void);
void bg1102_color4(void);
void bg1102_color3(void);
void bg110_demo(void);
s32 bg110_appear_check(void);
static void bg_move_common(void);
static void bg_base_move_common(void);
#pragma inline(bg1101, bg1102)


/* 2i 060A6084, 3s-near: sf3 src/bg120.c:34 BG110 (2i: layers 1 and 0 with the drop-in step) */
void BG110(void) {
    bgw_ptr = &bg_w.bgw[1];
    bg1102();
    bgw_ptr = &bg_w.bgw[0];
    bg1101();
    zoom_ud_check();
    bg_pos_hosei2();
    Bg_Family_Set();
}



/* 2i 060A60FA, 3s-near: sf3 src/bg120.c:46 bg1101 (2i: five steps) */
void bg1101(void) {
    void (*bg1101_jmp[5])() = { bg1101_init00, bg1101_next4, bg1101_next3, bg110_demo, bg_move_common };
    bg1101_jmp[bgw_ptr->r_no_0]();
}



/* 2i 060A612E, 3s-near: sf3 src/bg120.c:53 bg1101_init00 */
void bg1101_init00(void) {
    bgw_ptr->r_no_1 = 0;
    bgw_ptr->zuubun = 0;
    bgw_ptr->old_pos_x = bgw_ptr->xy[0].disp.pos = bgw_ptr->pos_x_work = 0x200;
    bgw_ptr->wxy[0].cal = bgw_ptr->xy[0].cal;
    bgw_ptr->hos_xy[0].disp.pos = bgw_ptr->wxy[0].disp.pos - bg_w.pos_offset;
    bgw_ptr->hos_xy[0].disp.low = 0;
    if (bg110_appear_check()) {
        bgw_ptr->r_no_0 = 1;
    } else {
        bgw_ptr->r_no_0 = 2;
        if (bg_w.area == 0) {
            bgw_ptr->free = 74;
            bgw_ptr->xy[1].cal = bgw_ptr->wxy[1].cal = 0x960000;
        }
    }
}



/* provisional name */
/* 2i 060A61B2 */
void bg1101_next4(void) {
    bgw_ptr->r_no_0 = 4;
}



/* provisional name */
/* 2i 060A61BC */
void bg1101_next3(void) {
    bgw_ptr->r_no_0 = 3;
}



/* 2i 060A61C6, 3s-exact: sf3 src/bg000.c:1628 bg_move_common (2i: a copy per stage file) */
static void bg_move_common(void) {
    bg_x_move_check();
    bg_y_move_check();
}



/* provisional name */
/* 2i 060A620C */
void bg1102(void) {
    void (*bg1102_jmp[5])() = { bg1102_init00, bg1102_color4, bg1102_color3, bg110_demo, bg_base_move_common };
    bg1102_jmp[bgw_ptr->r_no_0]();
}



/* provisional name */
/* 2i 060A6240: also the stage graphics and effects */
void bg1102_init00(void) {
    bgw_ptr->r_no_1 = 0;
    bgw_ptr->zuubun = 0;
    bgw_ptr->old_pos_x = bgw_ptr->xy[0].disp.pos = bgw_ptr->pos_x_work = 0x200;
    bgw_ptr->wxy[0].cal = bgw_ptr->xy[0].cal;
    bgw_ptr->hos_xy[0].disp.pos = bgw_ptr->wxy[0].disp.pos - bg_w.pos_offset;
    bgw_ptr->hos_xy[0].disp.low = 0;
    if (bg110_appear_check()) {
        bgw_ptr->r_no_0 = 1;
    } else {
        bgw_ptr->r_no_0 = 2;
        if (bg_w.area == 0) {
            bgw_ptr->free = 74;
            bgw_ptr->xy[1].cal = bgw_ptr->wxy[1].cal = 0x960000;
        }
    }
    load_char_gfx(0x7FC0, 1);
    load_char_gfx(0x8160, 1);
    load_char_gfx(0x82D0, 1);
    effect_05_init();
    effect_06_init();
    effect_12_init(8);
    effect_25_init(0);
    effect_25_init(1);
    effect_25_init(2);
    effect_29_init();
    effect_44_init(7);
}



/* provisional name */
/* 2i 060A6302 */
void bg1102_color4(void) {
    u8 lv;
    bgw_ptr->r_no_0 = 4;
    lv = bg_fade_level_tbl[bg_w.bg_index];
    if (Check_Shin_Gouki_Next()) {
        load_any_color_fade(107, lv, lv, lv);
    } else {
        load_any_color(107);
    }
}



/* provisional name */
/* 2i 060A6398 */
void bg1102_color3(void) {
    u8 lv;
    bgw_ptr->r_no_0 = 3;
    lv = bg_fade_level_tbl[bg_w.bg_index];
    if (Check_Shin_Gouki_Next()) {
        load_any_color_fade(107, lv, lv, lv);
    } else {
        load_any_color(107);
    }
}



/* 2i 060A63DC, 3s-near: sf3 src/bg000.c:1612 bg_base_move_common (2i: a copy per stage file) */
static void bg_base_move_common(void) {
    bg_base_x_move_check();
    bg_base_y_move_check();
    bg_chase_move();
}



/* provisional name */
/* 2i 060A63F0: as bgst030 bg030_demo */
void bg110_demo(void) {
    if (EXE_flag || Game_pause) {
        return;
    }
    switch (bgw_ptr->r_no_1) {
    case 0:
        bgw_ptr->free--;
        if (bgw_ptr->free < 0) {
            bgw_ptr->r_no_1++;
        }
        break;
    case 1:
        bgw_ptr->xy[1].cal -= 0xA8000;
        bgw_ptr->wxy[1].cal -= 0xA8000;
        if (bgw_ptr->xy[1].disp.pos <= 0) {
            bgw_ptr->r_no_1++;
            bgw_ptr->xy[1].cal = 0;
            bgw_ptr->wxy[1].cal = 0;
        }
        break;
    case 2:
        if (Appear_end != 2) {
            break;
        }
        bgw_ptr->r_no_0++;
        bgw_ptr->r_no_1 = 0;
        break;
    }
}



/* provisional name */
/* 2i 060A6474: as bgst030 bg030_appear_check, keyed on character 10 */
s32 bg110_appear_check(void) {
    s16 p1;
    s16 p2;
    if (bg_w.area >= 1) {
        return 1;
    }
    p1 = plw[0].player_number;
    p2 = plw[1].player_number;
    if (p1 != 10 && p2 != 10) {
        return 1;
    }
    if (p1 == 3 && p2 == 10) {
        return 2;
    }
    if (p1 == 10 && p2 == 3) {
        return 2;
    }
    return 0;
}
