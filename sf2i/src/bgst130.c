/*
 * BGST130.C  Stage 13 background (2i)
 *
 * BG130 runs stage 13's two layers with 3s bg120.c's bg1202 / bg1201 routines (named bg130_layer1 /
 * bg130_layer0 here, as the census holds bg1202 elsewhere): layer 1 (the chasing base layer: stage
 * graphics, effects 05, 06, 18 and 44) and layer 0, then the zoom check, position correction and family set.
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

/* trial declarations */
void zoom_ud_check(void);
void bg_x_move_check(void);
void bg_y_move_check(void);
void bg_base_x_move_check(void);
void bg_base_y_move_check(void);
s32 effect_18_init();
s32 effect_44_init();
void bg130_layer1(void);
void bg130_layer1_init00(void);
void bg130_layer0(void);
void bg130_layer0_init00(void);
static void bg_base_move_common(void);
static void bg_move_common(void);
#pragma inline(bg130_layer1, bg130_layer0)


/* 2i 060A86F0, 3s-near: sf3 src/bg120.c:93 BG120 (2i: layers 1 and 0 only) */
void BG130(void) {
    bgw_ptr = &bg_w.bgw[1];
    bg130_layer1();
    bgw_ptr = &bg_w.bgw[0];
    bg130_layer0();
    zoom_ud_check();
    bg_pos_hosei2();
    Bg_Family_Set();
}



/* provisional name */
/* 2i 060A874E, 3s-near: sf3 src/bg120.c:127 bg1202 */
void bg130_layer1(void) {
    void (*bg130_layer1_jmp[2])() = { bg130_layer1_init00, bg_base_move_common };
    bg130_layer1_jmp[bgw_ptr->r_no_0]();
}



/* provisional name */
/* 2i 060A8776, 3s-near: sf3 src/bg120.c:134 bg1202_init00 */
void bg130_layer1_init00(void) {
    bgw_ptr->r_no_0++;
    bgw_ptr->old_pos_x = bgw_ptr->xy[0].disp.pos = bgw_ptr->pos_x_work = 0x200;
    bgw_ptr->hos_xy[0].cal = bgw_ptr->wxy[0].cal = bgw_ptr->xy[0].cal;
    bgw_ptr->zuubun = 0;
    load_char_gfx(0x9060, 1);
    effect_05_init();
    effect_06_init();
    effect_18_init(7);
    effect_44_init(8);
}



/* 2i 060A87D2, 3s-near: sf3 src/bg000.c:1612 bg_base_move_common (2i: a copy per stage file) */
static void bg_base_move_common(void) {
    bg_base_x_move_check();
    bg_base_y_move_check();
    bg_chase_move();
}



/* provisional name */
/* 2i 060A87E6, 3s-near: sf3 src/bg120.c:111 bg1201 */
void bg130_layer0(void) {
    void (*bg130_layer0_jmp[2])() = { bg130_layer0_init00, bg_move_common };
    bg130_layer0_jmp[bgw_ptr->r_no_0]();
}



/* provisional name */
/* 2i 060A880E, 3s-near: sf3 src/bg120.c:118 bg1201_init00 */
void bg130_layer0_init00(void) {
    bgw_ptr->r_no_0++;
    bgw_ptr->old_pos_x = bgw_ptr->xy[0].disp.pos = bgw_ptr->pos_x_work = 0x200;
    bgw_ptr->hos_xy[0].cal = bgw_ptr->wxy[0].cal = bgw_ptr->xy[0].cal;
    bgw_ptr->zuubun = 0;
}



/* 2i 060A8844, 3s-exact: sf3 src/bg000.c:1628 bg_move_common (2i: a copy per stage file) */
static void bg_move_common(void) {
    bg_x_move_check();
    bg_y_move_check();
}
