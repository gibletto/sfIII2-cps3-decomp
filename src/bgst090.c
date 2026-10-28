/*
 * BGST090.C  Stage 09 background
 *
 * BG090 runs stage 09's three layers: layer 1 (bg090_layer1, the chasing base layer; in area 1 it starts
 * effect C3 and draws its own map into eff_bg_adrs[0], then waits for bg_land_flag to switch back to its
 * map with a quake and Sound_SE(119)), layer 0 (gfx, effects 14/05/12, then the stage palette, faded when
 * Shin Gouki is next) and layer 2 (bg0603, a synced layer), then the zoom check, position correction and
 * Bg_Family_Set_2.
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
#include "color3rd.h"
#include "se_3.h"
#include "sys_config.h"
#include "end_main.h"
#include "bg000.h"
#include "eff05.h"
#include "eff14.h"

/* bgw r_no_0 of a layer that follows the camera */
#define SYNC_INIT       0       /* set up the layer */
#define SYNC_MOVE       1       /* follow the camera (bg_x_move_check, bg_y_move_check) */

/* declarations the headers do not give */
void zoom_ud_check(void);
void bg_x_move_check(void);
void bg_y_move_check(void);
void bg_base_x_move_check(void);
void bg_base_y_move_check(void);
void Bg_Family_Set_2(void);
s32 Check_Shin_Gouki_Next(void);
void load_any_color();
s32 effect_12_init();
s32 effect_C3_init();

void bg090_layer0(void);
void bg1502_init00(void);
void bg090_layer0_color(void);
void bg090_layer1(void);
void bg090_layer1_init(void);
void bg0603(void);
static void bg_move_common(void);
static void bg_base_move_common(void);
#pragma inline(bg090_layer0, bg090_layer1)


void BG090(void) {
    bgw_ptr = &bg_w.bgw[1];
    bg090_layer1();
    bgw_ptr = &bg_w.bgw[0];
    bg090_layer0();
    bgw_ptr = &bg_w.bgw[2];
    bg0603();
    zoom_ud_check();
    bg_pos_hosei2();
    Bg_Family_Set_2();
}



/* provisional name */
void bg090_layer0(void) {
    void (*bg0901_jmp[3])() = { bg1502_init00, bg090_layer0_color, bg_move_common };
    bg0901_jmp[bgw_ptr->r_no_0]();
}



/* layer 0: clears r_no_1, starts effects 14, 05 and 12 */
void bg1502_init00(void) {
    bgw_ptr->r_no_0++;
    bgw_ptr->r_no_1 = 0;
    bgw_ptr->old_pos_x = bgw_ptr->xy[0].disp.pos = bgw_ptr->pos_x_work = 0x200;
    bgw_ptr->hos_xy[0].cal = bgw_ptr->wxy[0].cal = bgw_ptr->xy[0].cal;
    bgw_ptr->zuubun = 0;
    load_char_gfx(0x88B0, 1);
    effect_14_init(0);
    effect_05_init();
    effect_12_init(6);
}



/* provisional name */
void bg090_layer0_color(void) {
    u8 lv;
    bgw_ptr->r_no_0++;
    lv = bg_fade_level_tbl[bg_w.bg_index];
    if (Check_Shin_Gouki_Next()) {
        load_any_color_fade(99, lv, lv, lv);
    } else {
        load_any_color(99);
    }
}



/* each stage file has its own copy */
static void bg_move_common(void) {
    bg_x_move_check();
    bg_y_move_check();
}



/* provisional name */
void bg090_layer1(void) {
    void (*bg0902_jmp[2])() = { bg090_layer1_init, bg_base_move_common };
    bg0902_jmp[bgw_ptr->r_no_0]();
}



/* provisional name */
void bg090_layer1_init(void) {
    switch (bgw_ptr->r_no_1) {
    case 0:
        bgw_ptr->r_no_1++;
        bg_land_flag = 0;
        bgw_ptr->old_pos_x = bgw_ptr->xy[0].disp.pos = bgw_ptr->pos_x_work = 0x200;
        bgw_ptr->hos_xy[0].cal = bgw_ptr->wxy[0].cal = bgw_ptr->xy[0].cal;
        bgw_ptr->position_y = bgw_ptr->wxy[1].disp.pos = bgw_ptr->xy[1].disp.pos = 0;
        bgw_ptr->zuubun = 0;
        if (bg_w.area != 1) {
            bgw_ptr->r_no_0++;
            break;
        }
        effect_C3_init(1);
        eff_bg_adrs[0].no = simmram_big_page_alloc_40(1);
        eff_bg_adrs[0].adrs = simmram_slot_addr(eff_bg_adrs[0].no);
        scroll_cell_write(0, 0x2000, 9, (u32)eff08_scrn_data);
        scroll_cell_write(0, 0x2040, 10, (u32)eff08_scrn_data);
        scroll_cell_write(0, 0x2080, 11, (u32)eff08_scrn_data);
        scroll_cell_write(0, 0x20C0, 12, (u32)eff08_scrn_data);
        scroll_cell_write(0, 0x3000, 17, (u32)eff08_scrn_data);
        scroll_cell_write(0, 0x3040, 18, (u32)eff08_scrn_data);
        scroll_cell_write(0, 0x3080, 19, (u32)eff08_scrn_data);
        scroll_cell_write(0, 0x30C0, 20, (u32)eff08_scrn_data);
        scrn_map_set_now(1, eff_bg_adrs[0].adrs);
        break;
    case 1:
        if (bg_land_flag) {
            bgw_ptr->r_no_1++;
            scrn_map_set_now(1, (u32)bg_w.bgw[1].bg_address);
            bg_w.quake_y_index = 32;
            Sound_SE(119);
        }
        break;
    case 2:
        if (bg_w.quake_y_index == 0) {
            bgw_ptr->r_no_0++;
        }
        break;
    }
}



/* each stage file has its own copy */
static void bg_base_move_common(void) {
    bg_base_x_move_check();
    bg_base_y_move_check();
    bg_chase_move();
}



void bg0603(void) {
    switch (bgw_ptr->r_no_0) {
    case SYNC_INIT:
        bgw_ptr->r_no_0++;
        bgw_ptr->old_pos_x = bgw_ptr->xy[0].disp.pos = bgw_ptr->pos_x_work = 0x200;
        bgw_ptr->hos_xy[0].cal = bgw_ptr->wxy[0].cal = bgw_ptr->xy[0].cal;
        bgw_ptr->zuubun = 0;
        bgw_ptr->fam_no = 2;
        bgw_ptr->xy[1].disp.pos = bgw_ptr->pos_y_work = 0;
        bgw_ptr->speed_x = 0xC000;
        bgw_ptr->speed_y = 0xC000;
        bgw_ptr->y_limit = bgw_ptr->y_limit2 = 0xF0;
        sync_fam_set3(2);
        break;
    case SYNC_MOVE:
        bg_x_move_check();
        bg_y_move_check();
        sync_fam_set3(2);
        break;
    }
}
