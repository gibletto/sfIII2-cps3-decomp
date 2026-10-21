/*
 * BGST030.C  Stage 03 background (2i)
 *
 * BG030 runs stage 03's three layers (1, 0, 2). Unless bg030_appear_check says the stage starts in
 * place (a later area, or neither player is character 3), each layer first drops in from above
 * (bg030_demo: wait, slide down, then wait for Appear_end) before it scrolls normally.
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
#include "EFF23.h"

s32 Check_Shin_Gouki_Next(void);
void load_any_color();
extern const u8 bg_fade_level_tbl[];
extern s16 Appear_end;
s32 effect_12_init();
s32 effect_18_init();
s32 effect_44_init();
s32 effect_87_init();
void bg030_layer0(void);
void bg030_layer1(void);
void bg030_layer2(void);
void bg030_layer0_init(void);
void bg030_layer1_init(void);
void bg030_layer2_init(void);
void bg030_layer2_move(void);
void bg030_demo(void);
s32 bg030_appear_check(void);
static void bg_move_common(void);
static void bg_base_move_common(void);
#pragma inline(bg030_layer0, bg030_layer1, bg030_layer2)


/* 2i 060A5BA0, 3s-near: sf3 src/bg040.c:69 BG030 (2i: layers 1, 0, 2, each with the drop-in step) */
void BG030(void) {
    bgw_ptr = &bg_w.bgw[1];
    bg030_layer1();
    bgw_ptr = &bg_w.bgw[0];
    bg030_layer0();
    bgw_ptr = &bg_w.bgw[2];
    bg030_layer2();
    zoom_ud_check();
    bg_pos_hosei2();
    Bg_Family_Set();
}



/* provisional name */
/* 2i 060A5C3C */
void bg030_layer0(void) {
    void (*bg0301_jmp[3])() = { bg030_layer0_init, bg030_demo, bg_move_common };
    bg0301_jmp[bgw_ptr->r_no_0]();
}



/* provisional name */
/* 2i 060A5C68 */
void bg030_layer0_init(void) {
    bgw_ptr->r_no_1 = 0;
    bgw_ptr->zuubun = 0;
    bgw_ptr->old_pos_x = bgw_ptr->xy[0].disp.pos = bgw_ptr->pos_x_work = 0x200;
    bgw_ptr->wxy[0].cal = bgw_ptr->xy[0].cal;
    bgw_ptr->hos_xy[0].disp.pos = bgw_ptr->wxy[0].disp.pos - bg_w.pos_offset;
    bgw_ptr->hos_xy[0].disp.low = 0;
    if (bg030_appear_check()) {
        bgw_ptr->r_no_0 = 2;
    } else {
        bgw_ptr->r_no_0++;
        if (bg_w.area == 0) {
            bgw_ptr->free = 52;
            bgw_ptr->xy[1].cal = bgw_ptr->wxy[1].cal = 0xC40000;
        }
    }
}



/* 2i 060A5CEE, 3s-exact: sf3 src/bg000.c:1628 bg_move_common (2i: a copy per stage file) */
static void bg_move_common(void) {
    bg_x_move_check();
    bg_y_move_check();
}



/* provisional name */
/* 2i 060A5D38 */
void bg030_layer1(void) {
    void (*bg0302_jmp[3])() = { bg030_layer1_init, bg030_demo, bg_base_move_common };
    bg0302_jmp[bgw_ptr->r_no_0]();
}



/* provisional name */
/* 2i 060A5D64: also the stage palette, graphics and effects */
void bg030_layer1_init(void) {
    u8 lv;
    bgw_ptr->r_no_1 = 0;
    bgw_ptr->zuubun = 0;
    bgw_ptr->old_pos_x = bgw_ptr->xy[0].disp.pos = bgw_ptr->pos_x_work = 0x200;
    bgw_ptr->wxy[0].cal = bgw_ptr->xy[0].cal;
    bgw_ptr->hos_xy[0].disp.pos = bgw_ptr->wxy[0].disp.pos - bg_w.pos_offset;
    bgw_ptr->hos_xy[0].disp.low = 0;
    if (bg030_appear_check()) {
        bgw_ptr->r_no_0 = 2;
    } else {
        bgw_ptr->r_no_0++;
        if (bg_w.area == 0) {
            bgw_ptr->free = 52;
            bgw_ptr->xy[1].cal = bgw_ptr->wxy[1].cal = 0xC40000;
        }
    }
    lv = bg_fade_level_tbl[bg_w.bg_index];
    if (Check_Shin_Gouki_Next()) {
        load_any_color_fade(106, lv, lv, lv);
    } else {
        load_any_color(106);
    }
    load_char_gfx(0x7D40, 1);
    effect_05_init();
    effect_06_init();
    effect_12_init(1);
    effect_44_init(1);
    effect_18_init(2);
    effect_87_init(2);
    effect_23_init();
}



/* 2i 060A5E4E, 3s-near: sf3 src/bg000.c:1612 bg_base_move_common (2i: a copy per stage file) */
static void bg_base_move_common(void) {
    bg_base_x_move_check();
    bg_base_y_move_check();
    bg_chase_move();
}



/* provisional name */
/* 2i 060A5EB4 */
void bg030_layer2(void) {
    void (*bg0303_jmp[3])() = { bg030_layer2_init, bg030_demo, bg030_layer2_move };
    bg0303_jmp[bgw_ptr->r_no_0]();
}



/* provisional name */
/* 2i 060A5EE0 */
void bg030_layer2_init(void) {
    bgw_ptr->r_no_1 = 0;
    bgw_ptr->zuubun = 0;
    bgw_ptr->old_pos_x = bgw_ptr->xy[0].disp.pos = bgw_ptr->pos_x_work = 0x200;
    bgw_ptr->wxy[0].cal = bgw_ptr->xy[0].cal;
    bgw_ptr->hos_xy[0].disp.pos = bgw_ptr->wxy[0].disp.pos - bg_w.pos_offset;
    bgw_ptr->hos_xy[0].disp.low = 0;
    if (bg030_appear_check()) {
        bgw_ptr->r_no_0 = 2;
    } else {
        bgw_ptr->r_no_0++;
        if (bg_w.area == 0) {
            bgw_ptr->free = 52;
            bgw_ptr->xy[1].cal = bgw_ptr->wxy[1].cal = 0xC40000;
        }
    }
}



/* provisional name */
/* 2i 060A5F66 */
void bg030_layer2_move(void) {
    bg_x_move_check();
    bg_y_move_check();
}



/* provisional name */
/* 2i 060A5F74: the drop-in: free counts down, then the layer slides down to 0, then waits for Appear_end == 2 */
void bg030_demo(void) {
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
/* 2i 060A601E: 1 = start in place, 2 = character 3 against character 10 */
s32 bg030_appear_check(void) {
    s16 p1;
    s16 p2;
    if (bg_w.area >= 1) {
        return 1;
    }
    p1 = plw[0].player_number;
    p2 = plw[1].player_number;
    if (p1 != 3 && p2 != 3) {
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
