/*
 * BGST150.C  Stage 15 background (2nd Impact only)
 *
 * BG150 runs stage 15's two layers: layer 1 (the chasing base layer, effect 14 x3) and layer 0. In the
 * first area both start raised (speed_y << 8) and, once bg1403_wait has run out, come down to pos_y_work
 * (bg1403, unreferenced in 3rd Strike); then the zoom check, position correction and family set.
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
extern s16 bg1403_wait;

void bg150_layer1(void);
void bg150_layer1_init00(void);
void bg150_layer0(void);
void bg150_layer0_init00(void);
void bg1403(void);
static void bg_base_move_common(void);
static void bg_move_common(void);
#pragma inline(bg150_layer1, bg150_layer0)


/* provisional name */
void BG150(void) {
    bgw_ptr = &bg_w.bgw[1];
    bg150_layer1();
    bgw_ptr = &bg_w.bgw[0];
    bg150_layer0();
    zoom_ud_check();
    bg_pos_hosei2();
    Bg_Family_Set();
}



/* provisional name */
void bg150_layer1(void) {
    void (*bg1501_jmp[3])() = { bg150_layer1_init00, bg1403, bg_base_move_common };
    bg1501_jmp[bgw_ptr->r_no_0]();
}



/* provisional name */
void bg150_layer1_init00(void) {
    bgw_ptr->r_no_0++;
    bgw_ptr->old_pos_x = bgw_ptr->xy[0].disp.pos = bgw_ptr->pos_x_work = 0x200;
    bgw_ptr->hos_xy[0].cal = bgw_ptr->wxy[0].cal = bgw_ptr->xy[0].cal;
    bgw_ptr->zuubun = 0;
    bg_app = 0;
    if (bg_w.area == 0) {
        bg1403_wait = 60;
        bgw_ptr->xy[1].cal = bgw_ptr->speed_y << 8;
        bgw_ptr->hos_xy[1].disp.pos = bgw_ptr->wxy[1].cal = bgw_ptr->xy[1].cal;
        bg_app = 1;
    } else {
        bgw_ptr->r_no_0++;
    }
    effect_14_init(8);
    effect_14_init(9);
    effect_14_init(10);
}



/* (2nd Impact: a copy per stage file) */
static void bg_base_move_common(void) {
    bg_base_x_move_check();
    bg_base_y_move_check();
    bg_chase_move();
}



/* provisional name */
void bg150_layer0(void) {
    void (*bg1500_jmp[3])() = { bg150_layer0_init00, bg1403, bg_move_common };
    bg1500_jmp[bgw_ptr->r_no_0]();
}



/* provisional name */
void bg150_layer0_init00(void) {
    bgw_ptr->r_no_0++;
    bgw_ptr->old_pos_x = bgw_ptr->xy[0].disp.pos = bgw_ptr->pos_x_work = 0x200;
    bgw_ptr->hos_xy[0].cal = bgw_ptr->wxy[0].cal = bgw_ptr->xy[0].cal;
    bgw_ptr->zuubun = 0;
    if (bg_w.area == 0) {
        bgw_ptr->xy[1].cal = bgw_ptr->speed_y << 8;
        bgw_ptr->hos_xy[1].disp.pos = bgw_ptr->wxy[1].cal = bgw_ptr->xy[1].cal;
    } else {
        bgw_ptr->r_no_0++;
    }
}



/* (2nd Impact: a copy per stage file) */
static void bg_move_common(void) {
    bg_x_move_check();
    bg_y_move_check();
}



void bg1403(void) {
    if (EXE_flag || Game_pause) {
        return;
    }
    switch (bgw_ptr->r_no_1) {
    case 0:
        if (bgw_ptr->fam_no == 0) {
            bg1403_wait--;
        }
        if (bg1403_wait < 0) {
            bgw_ptr->r_no_1++;
        }
        break;
    case 1:
        bgw_ptr->xy[1].cal -= bgw_ptr->speed_y << 2;
        if (bgw_ptr->xy[1].cal < bgw_ptr->pos_y_work) {
            bgw_ptr->xy[1].cal = bgw_ptr->pos_y_work;
            bgw_ptr->r_no_0++;
            bg_app = 0;
        }
        break;
    }
}
