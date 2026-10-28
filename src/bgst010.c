/*
 * BGST010.C  Stage 01 background
 *
 * BG010 runs stage 01's three scroll layers: layer 1 (bg0102, the base layer that chases the
 * players), layer 0 (bg0101) and layer 2 (bg0103, a synced layer), then the zoom check, position
 * correction and family set. The file has its own copies of bg_move_common and bg_base_move_common.
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
#include "eff66.h"

/* bgw r_no_0 of a layer that follows the camera */
#define SYNC_INIT       0       /* set up the layer */
#define SYNC_MOVE       1       /* follow the camera (bg_x_move_check, bg_y_move_check) */

void bg0101(void);
void bg0102(void);
void bg0103(void);
void bg0101_init00(void);
void bg0102_init00(void);
static void bg_base_move_common(void);
static void bg_move_common(void);
#pragma inline(bg0101, bg0102)


void BG010(void) {
    bgw_ptr = &bg_w.bgw[1];
    bg0102();
    bgw_ptr = &bg_w.bgw[0];
    bg0101();
    bgw_ptr = &bg_w.bgw[2];
    bg0103();
    zoom_ud_check();
    bg_pos_hosei2();
    Bg_Family_Set();
}



void bg0101(void) {
    void (*bg1601_jmp[2])() = { bg0101_init00, bg_move_common };
    bg1601_jmp[bgw_ptr->r_no_0]();
}



/* starts effects 05 and 66 */
void bg0101_init00(void) {
    bgw_ptr->r_no_0++;
    bgw_ptr->old_pos_x = bgw_ptr->xy[0].disp.pos = bgw_ptr->pos_x_work = 0x200;
    bgw_ptr->hos_xy[0].disp.pos = bgw_ptr->wxy[0].cal = bgw_ptr->xy[0].cal;
    bgw_ptr->zuubun = 0;
    effect_05_init();
    effect_66_init(2);
}



/* each stage file has its own copy */
static void bg_move_common(void) {
    bg_x_move_check();
    bg_y_move_check();
}



void bg0102(void) {
    void (*bg0602_jmp[2])() = { bg0102_init00, bg_base_move_common };
    bg0602_jmp[bgw_ptr->r_no_0]();
}



/* loads the stage graphics */
void bg0102_init00(void) {
    bgw_ptr->r_no_0++;
    bgw_ptr->old_pos_x = bgw_ptr->xy[0].disp.pos = bgw_ptr->pos_x_work = 0x200;
    bgw_ptr->hos_xy[0].cal = bgw_ptr->wxy[0].cal = bgw_ptr->xy[0].cal;
    bgw_ptr->zuubun = 0;
    load_char_gfx(0x8E20, 1);
}



/* each stage file has its own copy: the base layer moves and chases */
static void bg_base_move_common(void) {
    bg_base_x_move_check();
    bg_base_y_move_check();
    bg_chase_move();
}



void bg0103(void) {
    switch (bgw_ptr->r_no_0) {
    case SYNC_INIT:
        bgw_ptr->r_no_0++;
        bgw_ptr->old_pos_x = bgw_ptr->xy[0].disp.pos = bgw_ptr->pos_x_work = 0x200;
        bgw_ptr->hos_xy[0].cal = bgw_ptr->wxy[0].cal = bgw_ptr->xy[0].cal;
        bgw_ptr->xy[1].disp.pos = bgw_ptr->pos_y_work = 0;
        bgw_ptr->fam_no = 2;
        bgw_ptr->xy[0].disp.low = bgw_ptr->xy[1].disp.low = 0;
        bgw_ptr->y_limit = bgw_ptr->y_limit2 = 0xF0;
        bgw_ptr->speed_x = 0xD000;
        bgw_ptr->speed_y = 0xE000;
        sync_fam_set3(2);
        break;
    case SYNC_MOVE:
        bg_x_move_check();
        bg_y_move_check();
        sync_fam_set3(2);
        break;
    }
}
