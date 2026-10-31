/*
 * BGST040.C  Stage 04 background
 *
 * BG040 runs stage 04's two layers: layer 1 (bg0402, the chasing base layer, one frame's wait after
 * its init) and layer 0 (bg0401: the stage graphics and effects, then the stage palette, faded when
 * Shin Gouki is next).
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
#include "ta_sub.h"
#include "ta_sub2.h"
#include "aboutspr.h"
#include "eff05.h"
#include "EFF11.h"
#include "sys_config.h"
#include "sys_test.h"
#include "meta_col_mem.h"
#include "color3rd.h"
#include "eff06.h"

/* declarations the headers do not give */
s32 Check_Shin_Gouki_Next(void);
void load_any_color();
s32 effect_18_init();

#include "EFF44.h"
#include "eff66.h"
#include "EFF68.h"

void bg0401(void);
void bg0402(void);
void bg0401_init00(void);
void bg0401_color(void);
void bg0402_init00(void);
void bg0402_wait(void);
static void bg_move_common(void);
static void bg_base_move_common(void);
#pragma inline(bg0401, bg0402)


void BG040(void) {
    bgw_ptr = &bg_w.bgw[1];
    bg0402();
    bgw_ptr = &bg_w.bgw[0];
    bg0401();
    zoom_ud_check();
    bg_pos_hosei2();
    Bg_Family_Set();
}



void bg0401(void) {
    void (*bg0401_jmp[3])() = { bg0401_init00, bg0401_color, bg_move_common };
    bg0401_jmp[bgw_ptr->r_no_0]();
}



void bg0401_init00(void) {
    bgw_ptr->r_no_0++;
    bgw_ptr->old_pos_x = bgw_ptr->xy[0].disp.pos = bgw_ptr->pos_x_work = 0x200;
    bgw_ptr->hos_xy[0].cal = bgw_ptr->wxy[0].cal = bgw_ptr->xy[0].cal;
    bgw_ptr->zuubun = 0;
    load_char_gfx(0x8AD0, 1);
    effect_66_init(0);
    effect_68_init();
    effect_05_init();
    effect_06_init();
    effect_44_init(2);
    effect_18_init(6);
}



/* provisional name */
void bg0401_color(void) {
    u8 lv;
    bgw_ptr->r_no_0++;
    lv = bg_fade_level_tbl[bg_w.bg_index];
    if (Check_Shin_Gouki_Next()) {
        load_any_color_fade(101, lv, lv, lv);
    } else {
        load_any_color(101);
    }
}



/* each stage file has its own copy */
static void bg_move_common(void) {
    bg_x_move_check();
    bg_y_move_check();
}



void bg0402(void) {
    void (*bg0402_jmp[3])() = { bg0402_init00, bg0402_wait, bg_base_move_common };
    bg0402_jmp[bgw_ptr->r_no_0]();
}



void bg0402_init00(void) {
    bgw_ptr->r_no_0++;
    bgw_ptr->old_pos_x = bgw_ptr->xy[0].disp.pos = bgw_ptr->pos_x_work = 0x200;
    bgw_ptr->hos_xy[0].cal = bgw_ptr->wxy[0].cal = bgw_ptr->xy[0].cal;
    bgw_ptr->zuubun = 0;
}



/* provisional name */
void bg0402_wait(void) {
    bgw_ptr->r_no_0++;
}



/* each stage file has its own copy */
static void bg_base_move_common(void) {
    bg_base_x_move_check();
    bg_base_y_move_check();
    bg_chase_move();
}
