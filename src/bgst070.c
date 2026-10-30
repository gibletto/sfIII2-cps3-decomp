/*
 * BGST070.C  Stage 07 background
 *
 * BG070 runs stage 07's four layers: layer 1 (bg1802, the base layer that chases the players),
 * layer 0 (bg1801), layer 2 (bg1803) and layer 4 (bg180_sync_common, a synced layer), then the
 * zoom check, position correction and family set. Layer 2 is a plain scroll.
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
#include "Com_Pl.h"
#include "eff14.h"

/* declarations the headers do not give */
void zoom_ud_check(void);
void bg_x_move_check(void);
void bg_y_move_check(void);
void bg_base_x_move_check(void);
void bg_base_y_move_check(void);

void bg1801(void);
void bg1801_init00(void);
void bg1801_move(void);
void bg1802(void);
void bg1802_init00(void);
void bg1802_move(void);
void bg1803(void);
void bg1803_init00(void);
void bg1803_move(void);
void bg180_sync_common(void);
void bg180_sync_init(void);
void bg180_sync_move(void);
#pragma inline(bg1801, bg1802, bg1803, bg180_sync_common)


void BG070(void) {
    bgw_ptr = &bg_w.bgw[1];
    bg1802();
    bgw_ptr = &bg_w.bgw[0];
    bg1801();
    bgw_ptr = &bg_w.bgw[2];
    bg1803();
    bgw_ptr = &bg_w.bgw[4];
    bg180_sync_common();
    zoom_ud_check();
    bg_pos_hosei2();
    Bg_Family_Set();
}



void bg1801(void) {
    void (*bg0801_jmp[2])() = { bg1801_init00, bg1801_move };
    bg0801_jmp[bgw_ptr->r_no_0]();
}



void bg1801_init00(void) {
    bgw_ptr->r_no_0++;
    bgw_ptr->old_pos_x = bgw_ptr->xy[0].disp.pos = bgw_ptr->pos_x_work = 0x200;
    bgw_ptr->hos_xy[0].cal = bgw_ptr->wxy[0].cal = bgw_ptr->xy[0].cal;
    bgw_ptr->zuubun = 0;
}



void bg1801_move(void) {
    bg_x_move_check();
    bg_y_move_check();
}



void bg1802(void) {
    void (*bg1601_jmp[2])() = { bg1802_init00, bg1802_move };
    bg1601_jmp[bgw_ptr->r_no_0]();
}



/* starts effect 14 three times */
void bg1802_init00(void) {
    bgw_ptr->r_no_0++;
    bgw_ptr->old_pos_x = bgw_ptr->xy[0].disp.pos = bgw_ptr->pos_x_work = 0x200;
    bgw_ptr->hos_xy[0].cal = bgw_ptr->wxy[0].cal = bgw_ptr->xy[0].cal;
    bgw_ptr->zuubun = 0;
    effect_14_init(4);
    effect_14_init(5);
    effect_14_init(11);
}



/* provisional name */
/* nothing calls it (an unused bg1802 step: zooms the frame in to bg_f_x 64, then Zoomf_Init) */
void bg1802_zoom_in(void) {
    if (C_No1 > 3 || Allow_a_battle_f) {
        if (Game_setting.Screen_Mode == 0) {
            bg_w.bg_f_x--;
            bg_w.bg_f_y--;
            if (bg_w.bg_f_x > 64) {
                Frame_Up(192, 224, 1, 1);
            } else {
                bgw_ptr->r_no_0++;
                Zoomf_Init();
                bg_w.bg_f_x = bg_w.bg_f_y = 64;
            }
        } else {
            bgw_ptr->r_no_0++;
        }
    }
}



void bg1802_move(void) {
    bg_base_x_move_check();
    bg_base_y_move_check();
    bg_chase_move();
}



/* provisional name */
void bg1803(void) {
    void (*bg1803_jmp[2])() = { bg1803_init00, bg1803_move };
    bg1803_jmp[bgw_ptr->r_no_0]();
}



/* provisional name */
void bg1803_init00(void) {
    bgw_ptr->r_no_0++;
    bgw_ptr->old_pos_x = bgw_ptr->xy[0].disp.pos = bgw_ptr->pos_x_work = 0x200;
    bgw_ptr->hos_xy[0].cal = bgw_ptr->wxy[0].cal = bgw_ptr->xy[0].cal;
    bgw_ptr->zuubun = 0;
}



/* provisional name */
void bg1803_move(void) {
    bg_x_move_check();
    bg_y_move_check();
}



/* runs layer 4 */
void bg180_sync_common(void) {
    void (*bg080_sync_jmp[2])() = { bg180_sync_init, bg180_sync_move };
    bg080_sync_jmp[bgw_ptr->r_no_0]();
}



void bg180_sync_init(void) {
    bgw_ptr->r_no_0++;
    bgw_ptr->old_pos_x = bgw_ptr->xy[0].disp.pos = bgw_ptr->pos_x_work = 0x200;
    bgw_ptr->hos_xy[0].cal = bgw_ptr->wxy[0].cal = bgw_ptr->xy[0].cal;
    bgw_ptr->zuubun = 0;
    bgw_ptr->fam_no = 4;
    bgw_ptr->y_limit = bgw_ptr->y_limit2 = 160;
    bgw_ptr->pos_y_work = 0;
    bgw_ptr->xy[1].disp.pos = 0;
    bgw_ptr->speed_x = 0xE000;
    bgw_ptr->speed_y = 0x10000;
    sync_fam_set3(4);
}



void bg180_sync_move(void) {
    bg_x_move_check();
    bg_y_move_check();
    sync_fam_set3(4);
}
