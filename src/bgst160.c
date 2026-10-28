/*
 * BGST160.C  Stage 16 background
 *
 * BG160 runs stage 16's two still layers (no move step): layer 1 and layer 0, which loads the palettes
 * and graphics and starts the stage effects with bg_w.compel_flag 2 and bg_w.area set to 2 for them;
 * then the zoom check, position correction and family set.
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
#include "aboutspr.h"
#include "eff05.h"
#include "eff06.h"
#include "EFF63.h"
#include "color3rd.h"
#include "eff12.h"
#include "EFF44.h"

/* declarations the headers do not give */
void zoom_ud_check(void);
void bg_x_move_check(void);
void bg_y_move_check(void);
void bg_base_x_move_check(void);
void bg_base_y_move_check(void);
s32 effect_35_init();

void bg160_layer0(void);
void bg160_layer0_init00(void);
void bg160_none(void);
void bg160_layer1(void);
void bg160_layer1_init00(void);
#pragma inline(bg160_layer1, bg160_layer0)


/* provisional name */
void BG160(void) {
    bgw_ptr = &bg_w.bgw[1];
    bg160_layer1();
    bgw_ptr = &bg_w.bgw[0];
    bg160_layer0();
    zoom_ud_check();
    bg_pos_hosei2();
    Bg_Family_Set();
}



/* provisional name */
void bg160_layer0(void) {
    void (*bg1600_jmp[2])() = { bg160_layer0_init00, bg160_none };
    bg1600_jmp[bgw_ptr->r_no_0]();
}



/* provisional name */
void bg160_layer0_init00(void) {
    s8 area;
    bgw_ptr->r_no_0++;
    bgw_ptr->old_pos_x = bgw_ptr->xy[0].disp.pos = bgw_ptr->pos_x_work = 0x200;
    bgw_ptr->hos_xy[0].cal = bgw_ptr->wxy[0].cal = bgw_ptr->xy[0].cal;
    bgw_ptr->zuubun = 0;
    bg_app = 0;
    load_any_color(96);
    load_char_gfx(0x85E0, 1);
    load_any_color(170);
    bg_w.compel_flag = 2;
    area = bg_w.area;
    bg_w.area = 2;
    effect_05_init();
    effect_06_init();
    effect_63_init();
    effect_12_init(5);
    effect_44_init(5);
    effect_35_init(0, 2);
    bg_w.area = area;
}



/* provisional name */
void bg160_none(void) {
}



/* provisional name */
void bg160_layer1(void) {
    void (*bg1601_jmp[2])() = { bg160_layer1_init00, bg160_none };
    bg1601_jmp[bgw_ptr->r_no_0]();
}



/* provisional name */
void bg160_layer1_init00(void) {
    bgw_ptr->r_no_0++;
    bgw_ptr->old_pos_x = bgw_ptr->xy[0].disp.pos = bgw_ptr->pos_x_work = 0x200;
    bgw_ptr->hos_xy[0].cal = bgw_ptr->wxy[0].cal = bgw_ptr->xy[0].cal;
    bgw_ptr->zuubun = 0;
}
