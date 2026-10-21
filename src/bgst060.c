/*
 * BGST060.C  Stage 06 background
 *
 * BG060 runs stage 06's two layers (1 and 0). In the first area both rise from below
 * (bg060_demo); layer 1 also runs bg060_anime, which plays a 16-frame cell animation on
 * layer 1 (bg060_cell_tbl) once and then raises bg060_end.
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
#include "EFF63.h"

/* declarations the headers do not give */
void zoom_ud_check(void);
void bg_x_move_check(void);
void bg_y_move_check(void);
void bg_base_y_move_check(void);
s32 Check_Shin_Gouki_Next(void);
void load_any_color();
extern const u8 bg_fade_level_tbl[];
extern const u32 eff23_scrn_data[];
extern s8 bg060_cnt;
extern s8 bg060_timer;
extern s8 bg060_end;
extern s8 bg060_mode;
s32 effect_12_init();
s32 effect_18_init();
s32 effect_44_init();
s32 effect_87_init();
void bg060_layer0(void);
void bg060_layer1(void);
void bg060_layer0_init(void);
void bg060_layer0_color(void);
void bg060_layer1_init(void);
void bg060_layer1_wait(void);
void bg060_demo(void);
void bg060_anime(void);
static void bg_move_common(void);
static void bg_base_move_common(void);
#pragma inline(bg060_layer0)


/* provisional name */
/* provisional name */
/* the four cells of each animation frame */
const s32 bg060_cell_tbl[16][4] = {
    { 0x0A, 0x0B, 0x0E, 0x0F },
    { 0x10, 0x11, 0x13, 0x14 },
    { 0x15, 0x16, 0x17, 0x18 },
    { 0x19, 0x1A, 0x1B, 0x1C },
    { 0x1D, 0x1E, 0x1F, 0x20 },
    { 0x21, 0x22, 0x23, 0x24 },
    { 0x25, 0x26, 0x27, 0x28 },
    { 0x29, 0x2A, 0x2B, 0x2C },
    { 0x2D, 0x2E, 0x2F, 0x30 },
    { 0x31, 0x32, 0x33, 0x34 },
    { 0x35, 0x36, 0x37, 0x38 },
    { 0x39, 0x3A, 0x3B, 0x3C },
    { 0x3D, 0x3E, 0x3F, 0x40 },
    { 0x41, 0x42, 0x43, 0x44 },
    { 0x45, 0x46, 0x47, 0x48 },
    { 0x49, 0x4A, 0x4B, 0x4C },
};


void BG060(void) {
    bgw_ptr = &bg_w.bgw[1];
    bg060_layer1();
    bgw_ptr = &bg_w.bgw[0];
    bg060_layer0();
    zoom_ud_check();
    bg_pos_hosei2();
    Bg_Family_Set();
}



/* provisional name */
void bg060_layer0(void) {
    void (*bg0601_jmp[4])() = { bg060_layer0_init, bg060_layer0_color, bg060_demo, bg_move_common };
    bg0601_jmp[bgw_ptr->r_no_0]();
}



/* provisional name */
void bg060_layer0_init(void) {
    u8 lv;
    bgw_ptr->r_no_0++;
    bgw_ptr->old_pos_x = bgw_ptr->xy[0].disp.pos = bgw_ptr->pos_x_work = 0x200;
    bgw_ptr->hos_xy[0].cal = bgw_ptr->wxy[0].cal = bgw_ptr->xy[0].cal;
    bgw_ptr->zuubun = 0;
    if (bg_w.area == 0) {
        bg_app = 1;
        bg060_end = 0;
        bg060_mode = 0;
        bgw_ptr->xy[1].cal = bgw_ptr->speed_y * 240;
        bgw_ptr->hos_xy[1].disp.pos = bgw_ptr->wxy[1].cal = bgw_ptr->xy[1].cal;
    } else {
        bg_app = 0;
        bgw_ptr->r_no_0 = 3;
        lv = bg_fade_level_tbl[bg_w.bg_index];
        if (Check_Shin_Gouki_Next()) {
            load_any_color_fade(96, lv, lv, lv);
        } else {
            load_any_color(96);
        }
    }
    load_char_gfx(0x85E0, 1);
    effect_05_init();
    effect_06_init();
    effect_63_init();
    effect_18_init(3);
    effect_12_init(3);
    effect_44_init(4);
    effect_87_init(3);
}



/* provisional name */
void bg060_layer0_color(void) {
    u8 lv;
    bgw_ptr->r_no_0++;
    lv = bg_fade_level_tbl[bg_w.bg_index];
    if (Check_Shin_Gouki_Next()) {
        load_any_color_fade(96, lv, lv, lv);
    } else {
        load_any_color(96);
    }
}



/* each stage file has its own copy */
static void bg_move_common(void) {
    bg_x_move_check();
    bg_y_move_check();
}



/* provisional name */
/* provisional name */
/* nothing reads it */
const u8 bg060_unused[4] = {
    0, 1, 2, 0,
};


/* provisional name */
void bg060_layer1(void) {
    void (*bg0602_jmp[4])() = { bg060_layer1_init, bg060_layer1_wait, bg060_demo, bg_base_move_common };
    bg0602_jmp[bgw_ptr->r_no_0]();
    bg060_anime();
}



/* provisional name */
void bg060_layer1_init(void) {
    bgw_ptr->r_no_0++;
    bgw_ptr->old_pos_x = bgw_ptr->xy[0].disp.pos = bgw_ptr->pos_x_work = 0x200;
    bgw_ptr->hos_xy[0].cal = bgw_ptr->wxy[0].cal = bgw_ptr->xy[0].cal;
    bgw_ptr->zuubun = 0;
    if (!bg_w.area) {
        bgw_ptr->xy[1].cal = bgw_ptr->speed_y * 240;
        bgw_ptr->hos_xy[1].disp.pos = bgw_ptr->wxy[1].cal = bgw_ptr->xy[1].cal;
    } else {
        bgw_ptr->r_no_0 = 3;
    }
}



/* provisional name */
void bg060_layer1_wait(void) {
    bgw_ptr->r_no_0++;
}



/* each stage file has its own copy */
static void bg_base_move_common(void) {
    bg_base_x_move_check();
    bg_base_y_move_check();
    bg_chase_move();
}



/* provisional name */
void bg060_demo(void) {
    if (EXE_flag || Game_pause) {
        return;
    }
    if (Cut_Cut_Cut()) {
        bgw_ptr->xy[1].cal -= bgw_ptr->speed_y * 4;
    } else {
        bgw_ptr->xy[1].cal -= bgw_ptr->speed_y * 2;
    }
    if (bgw_ptr->xy[1].cal < bgw_ptr->pos_y_work) {
        bgw_ptr->xy[1].cal = bgw_ptr->pos_y_work;
        bgw_ptr->r_no_0++;
        bg_app = 0;
    }
}



/* provisional name */
void bg060_anime(void) {
    const s32* p;
    if (EXE_flag || Game_pause) {
        return;
    }
    switch (bg060_mode) {
    case 0:
        bg060_mode++;
        bg060_timer = 10;
        bg060_cnt = 0;
        break;
    case 1:
        bg060_timer--;
        if (bg060_timer < 0) {
            bg060_timer = 10;
            bg060_cnt++;
            if (bg060_cnt > 15) {
                bg060_mode++;
            } else {
                p = bg060_cell_tbl[bg060_cnt];
                bg_cell_write(1, 0x2040, *p, (u32)eff23_scrn_data, 0, 0x240);
                p++;
                bg_cell_write(1, 0x2080, *p, (u32)eff23_scrn_data, 0, 0x240);
                p++;
                bg_cell_write(1, 0x3040, *p, (u32)eff23_scrn_data, 0, 0x240);
                p++;
                bg_cell_write(1, 0x3080, *p, (u32)eff23_scrn_data, 0, 0x240);
            }
        }
        break;
    case 2:
        bg060_end = 1;
        break;
    }
}
