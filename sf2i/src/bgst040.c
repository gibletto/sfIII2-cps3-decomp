/*
 * BGST040.C  Stage 04 background (2i)
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

/* trial declarations */
void zoom_ud_check(void);
void bg_x_move_check(void);
void bg_y_move_check(void);
void bg_base_y_move_check(void);
s32 Check_Shin_Gouki_Next(void);
void load_any_color();
extern const u8 bg_fade_level_tbl[];
s32 effect_18_init();
s32 effect_44_init();
s32 effect_66_init();
s32 effect_68_init();
void bg0401(void);
void bg0402(void);
void bg0401_init00(void);
void bg0401_color(void);
void bg0402_init00(void);
void bg0402_wait(void);
static void bg_move_common(void);
static void bg_base_move_common(void);
#pragma inline(bg0401, bg0402)


/* 2i 060A6508, 3s-near: sf3 src/bg040.c:119 BG040 (2i: layers 1 and 0) */
void BG040(void) {
    bgw_ptr = &bg_w.bgw[1];
    bg0402();
    bgw_ptr = &bg_w.bgw[0];
    bg0401();
    zoom_ud_check();
    bg_pos_hosei2();
    Bg_Family_Set();
}



/* 2i 060A656E, 3s-near: sf3 src/bg040.c:131 bg0401 (2i: three steps) */
void bg0401(void) {
    void (*bg0401_jmp[3])() = { bg0401_init00, bg0401_color, bg_move_common };
    bg0401_jmp[bgw_ptr->r_no_0]();
}



/* 2i 060A659A, 3s-near: sf3 src/bg040.c:138 bg0401_init00 */
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
/* 2i 060A6602 */
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



/* 2i 060A6648, 3s-exact: sf3 src/bg000.c:1628 bg_move_common (2i: a copy per stage file) */
static void bg_move_common(void) {
    bg_x_move_check();
    bg_y_move_check();
}



/* 2i 060A66B4, 3s-near: sf3 src/bg040.c:158 bg0402 (2i: three steps) */
void bg0402(void) {
    void (*bg0402_jmp[3])() = { bg0402_init00, bg0402_wait, bg_base_move_common };
    bg0402_jmp[bgw_ptr->r_no_0]();
}



/* 2i 060A66E0, 3s-near: sf3 src/bg040.c:165 bg0402_init00 */
void bg0402_init00(void) {
    bgw_ptr->r_no_0++;
    bgw_ptr->old_pos_x = bgw_ptr->xy[0].disp.pos = bgw_ptr->pos_x_work = 0x200;
    bgw_ptr->hos_xy[0].cal = bgw_ptr->wxy[0].cal = bgw_ptr->xy[0].cal;
    bgw_ptr->zuubun = 0;
}



/* provisional name */
/* 2i 060A6716 */
void bg0402_wait(void) {
    bgw_ptr->r_no_0++;
}



/* 2i 060A6722, 3s-near: sf3 src/bg000.c:1612 bg_base_move_common (2i: a copy per stage file) */
static void bg_base_move_common(void) {
    bg_base_x_move_check();
    bg_base_y_move_check();
    bg_chase_move();
}
