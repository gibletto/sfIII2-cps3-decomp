/*
 * BGST000.C  Stage 00 background (2nd Impact only)
 *
 * BG000 runs stage 00's four layers: layer 1 (bg0001_ctrl, the chasing base layer: stage graphics,
 * effects 05 and I4), layer 0 (bg0000) and two synced layers (2 and 6, bg000_layer with the family number;
 * speed_x from bg_sync_speed_tbl), then the zoom check, position correction and family set. In the first
 * area every layer starts raised and bg0000_demo brings it down: a countdown (faster while a shot button
 * is held) starts effect 11 at 50, then the layers fall into place.
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

/* trial declarations */
/* provisional name */
extern s8 bg_demo_cnt;
void zoom_ud_check(void);
void bg_x_move_check(void);
void bg_y_move_check(void);
void bg_base_y_move_check(void);
s32 effect_I4_init(void);
void bg0001_ctrl(void);
void bg0000(void);
void bg0001_init00(void);
void bg0000_init00(void);
void bg0000_demo(void);
static void bg_base_move_common(void);
static void bg_move_common(void);
void bg000_layer(s16 n);
#pragma inline(bg0001_ctrl, bg0000)


/* (2nd Impact: two synced layers added) */
void BG000(void) {
    bgw_ptr = &bg_w.bgw[1];
    bg0001_ctrl();
    bgw_ptr = &bg_w.bgw[0];
    bg0000();
    bgw_ptr = &bg_w.bgw[2];
    bg000_layer(2);
    bgw_ptr = &bg_w.bgw[6];
    bg000_layer(6);
    zoom_ud_check();
    bg_pos_hosei2();
    Bg_Family_Set();
}



void bg0001_ctrl(void) {
    void (*bg0001_jmp[3])() = { bg0001_init00, bg0000_demo, bg_base_move_common };
    bg0001_jmp[bgw_ptr->r_no_0]();
}



void bg0001_init00(void) {
    bgw_ptr->r_no_0++;
    bgw_ptr->zuubun = 0;
    bgw_ptr->old_pos_x = bgw_ptr->xy[0].disp.pos = bgw_ptr->pos_x_work = 0x200;
    if (bg_w.area == 0) {
        bg_app = 1;
        bg_demo_cnt = 80;
        bgw_ptr->xy[1].cal = bgw_ptr->speed_y * 0xC0;
        if (Game_setting.mode) {
            bgw_ptr->xy[0].cal += bgw_ptr->speed_x * 0x88;
        } else {
            bgw_ptr->xy[0].cal += bgw_ptr->speed_x * 0xC0;
        }
        bgw_ptr->hos_xy[1].disp.pos = bgw_ptr->wxy[1].cal = bgw_ptr->xy[1].cal;
    } else {
        bgw_ptr->r_no_0++;
    }
    bgw_ptr->hos_xy[0].cal = bgw_ptr->wxy[0].cal = bgw_ptr->xy[0].cal;
    load_char_gfx(0x9B90, 1);
    effect_05_init();
    effect_I4_init();
}



/* (2nd Impact: a copy per stage file) */
static void bg_base_move_common(void) {
    bg_base_x_move_check();
    bg_base_y_move_check();
    bg_chase_move();
}



void bg0000(void) {
    void (*bg0000_jmp[3])() = { bg0000_init00, bg0000_demo, bg_move_common };
    bg0000_jmp[bgw_ptr->r_no_0]();
}



void bg0000_init00(void) {
    bgw_ptr->r_no_0++;
    bgw_ptr->zuubun = 0;
    bgw_ptr->old_pos_x = bgw_ptr->xy[0].disp.pos = bgw_ptr->pos_x_work = 0x200;
    if (bg_w.area == 0) {
        if (Game_setting.mode) {
            bgw_ptr->xy[0].cal += bgw_ptr->speed_x * 0x88;
        } else {
            bgw_ptr->xy[0].cal += bgw_ptr->speed_x * 0xC0;
        }
        bgw_ptr->xy[1].cal = bgw_ptr->speed_y * 0xC0;
        bgw_ptr->hos_xy[1].disp.pos = bgw_ptr->wxy[1].cal = bgw_ptr->xy[1].cal;
    } else {
        bgw_ptr->r_no_0++;
    }
    bgw_ptr->hos_xy[0].cal = bgw_ptr->wxy[0].cal = bgw_ptr->xy[0].cal;
}



/* (2nd Impact: a copy per stage file) */
static void bg_move_common(void) {
    bg_x_move_check();
    bg_y_move_check();
}



/* (2nd Impact: the stage rises into view at the start (faster while a shot button is held), then settles) */
void bg0000_demo(void) {
    if (EXE_flag || Game_pause) {
        return;
    }
    switch (bgw_ptr->r_no_1) {
    case 0:
        if (bgw_ptr->fam_no == 1) {
            if (pl_shot_trg_check()) {
                bg_demo_cnt -= 10;
            } else {
                bg_demo_cnt -= 1;
            }
        }
        if (bg_demo_cnt >= 50) {
            return;
        }
        bgw_ptr->r_no_1++;
        effect_11_init();
        break;
    case 1:
        if (bgw_ptr->fam_no == 1) {
            if (pl_shot_trg_check()) {
                bg_demo_cnt -= 10;
            } else {
                bg_demo_cnt -= 1;
            }
        }
        if (bg_demo_cnt > 0) {
            return;
        }
        bgw_ptr->r_no_1++;
        break;
    case 2:
        if (Cut_Cut_Cut()) {
            bgw_ptr->xy[1].cal -= bgw_ptr->speed_y * 4;
            if (bgw_ptr->wxy[0].disp.pos > bgw_ptr->pos_x_work) {
                bgw_ptr->wxy[0].cal -= bgw_ptr->speed_x * 4;
                if (bgw_ptr->wxy[0].disp.pos <= bgw_ptr->pos_x_work) {
                    bgw_ptr->wxy[0].disp.pos = bgw_ptr->pos_x_work;
                }
            }
        } else {
            bgw_ptr->xy[1].cal -= bgw_ptr->speed_y * 2;
            if (bgw_ptr->wxy[0].disp.pos > bgw_ptr->pos_x_work) {
                bgw_ptr->wxy[0].cal -= bgw_ptr->speed_x * 2;
                if (bgw_ptr->wxy[0].disp.pos <= bgw_ptr->pos_x_work) {
                    bgw_ptr->wxy[0].disp.pos = bgw_ptr->pos_x_work;
                }
            }
        }
        if (bgw_ptr->xy[1].disp.pos < bgw_ptr->pos_y_work) {
            bgw_ptr->r_no_0++;
            bgw_ptr->r_no_1 = 0;
            bg_app = 0;
            bgw_ptr->xy[1].disp.pos = bgw_ptr->pos_y_work;
            bgw_ptr->xy[0].disp.pos = bgw_ptr->wxy[0].disp.pos = 0x200;
            bgw_ptr->xy[1].disp.low = 0;
            bgw_ptr->xy[0].disp.low = 0;
            bgw_ptr->wxy[0].disp.low = 0;
        }
        break;
    }
}



/* provisional name */
/* the synced layers' speed_x by family number (end_bg000_sync reads it too) */
const s32 bg_sync_speed_tbl[7] = {
    0xE000, 0xE000, 0xE000, 0xE000, 0xE000, 0xC000, 0xA000,
};


/* provisional name */
void bg000_layer(s16 n) {
    switch (bgw_ptr->r_no_0) {
    case 0:
        bgw_ptr->r_no_0++;
        bgw_ptr->old_pos_x = bgw_ptr->xy[0].disp.pos = bgw_ptr->pos_x_work = 0x200;
        bgw_ptr->xy[1].cal = 0;
        bgw_ptr->xy[0].disp.low = 0;
        bgw_ptr->pos_y_work = 0;
        bgw_ptr->zuubun = 0;
        bgw_ptr->fam_no = n;
        bgw_ptr->y_limit = bgw_ptr->y_limit2 = 216;
        bgw_ptr->speed_x = bg_sync_speed_tbl[n];
        bgw_ptr->speed_y = 0xE000;
        if (bg_w.area == 0) {
            if (Game_setting.mode) {
                bgw_ptr->xy[0].cal += bgw_ptr->speed_x * 0x88;
            } else {
                bgw_ptr->xy[0].cal += bgw_ptr->speed_x * 0xC0;
            }
            bgw_ptr->xy[1].cal = bgw_ptr->speed_y * 0xC0;
        } else {
            bgw_ptr->xy[1].cal = 0;
            bgw_ptr->r_no_0++;
        }
        bgw_ptr->hos_xy[0].cal = bgw_ptr->wxy[0].cal = bgw_ptr->xy[0].cal;
        bgw_ptr->hos_xy[1].disp.pos = bgw_ptr->wxy[1].cal = bgw_ptr->xy[1].cal;
        bgw_ptr->r_no_1 = 0;
        sync_fam_set3(n);
        break;
    case 1:
        bg0000_demo();
        sync_fam_set3(n);
        break;
    case 2:
        bg_x_move_check();
        bg_y_move_check();
        sync_fam_set3(n);
        return;
    }
}
