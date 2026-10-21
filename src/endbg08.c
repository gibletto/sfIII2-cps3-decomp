/*
 * ENDBG08.C  Ending background 08 (2nd Impact only)
 *
 * end_BG080 (entry 8) runs layer 1 (clears bg_land_flag, no move step), layer 0 (palette and graphics;
 * end_bg080_layer0_color is unreferenced) and a synced layer 2, then the zoom check, position correction
 * and Bg_Family_Set_2.
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

/* trial declarations */
void zoom_ud_check(void);
void bg_x_move_check(void);
void bg_y_move_check(void);
void Bg_Family_Set_2(void);

void end_bg080_layer0(void);
void end_bg080_layer0_init00(void);
void end_bg080_layer0_move(void);
void end_bg080_layer1(void);
void end_bg080_layer1_init00(void);
void end_bg080_none(void);
void end_bg080_layer0_color(void);
void end_bg080_sync(void);
#pragma inline(end_bg080_layer1, end_bg080_layer0)


/* provisional name */
void end_BG080(void) {
    bgw_ptr = &bg_w.bgw[1];
    end_bg080_layer1();
    bgw_ptr = &bg_w.bgw[0];
    end_bg080_layer0();
    bgw_ptr = &bg_w.bgw[2];
    end_bg080_sync();
    zoom_ud_check();
    bg_pos_hosei2();
    Bg_Family_Set_2();
}



/* provisional name */
void end_bg080_layer0(void) {
    void (*end_bg0800_jmp[2])() = { end_bg080_layer0_init00, end_bg080_layer0_move };
    end_bg0800_jmp[bgw_ptr->r_no_0]();
}



/* provisional name */
void end_bg080_layer0_init00(void) {
    bgw_ptr->r_no_0++;
    load_any_color_fade(98, 15, 15, 15);
    bgw_ptr->old_pos_x = bgw_ptr->xy[0].disp.pos = bgw_ptr->pos_x_work = 0x200;
    bgw_ptr->hos_xy[0].cal = bgw_ptr->wxy[0].cal = bgw_ptr->xy[0].cal;
    bgw_ptr->zuubun = 0;
    load_char_gfx(0x8760, 1);
}



/* provisional name */
void end_bg080_layer0_color(void) {
    bgw_ptr->r_no_0++;
    load_any_color_fade(98, 15, 15, 15);
}



/* provisional name */
void end_bg080_layer0_move(void) {
    bg_x_move_check();
    bg_y_move_check();
}



/* provisional name */
void end_bg080_layer1(void) {
    void (*end_bg0801_jmp[2])() = { end_bg080_layer1_init00, end_bg080_none };
    end_bg0801_jmp[bgw_ptr->r_no_0]();
}



/* provisional name */
void end_bg080_layer1_init00(void) {
    bgw_ptr->r_no_0++;
    bg_land_flag = 0;
    bgw_ptr->old_pos_x = bgw_ptr->xy[0].disp.pos = bgw_ptr->pos_x_work = 0x200;
    bgw_ptr->hos_xy[0].cal = bgw_ptr->wxy[0].cal = bgw_ptr->xy[0].cal;
    bgw_ptr->zuubun = 0;
}



/* provisional name */
void end_bg080_none(void) {
}



/* provisional name */
void end_bg080_sync(void) {
    switch (bgw_ptr->r_no_0) {
    case 0:
        bgw_ptr->r_no_0++;
        bgw_ptr->old_pos_x = bgw_ptr->xy[0].disp.pos = bgw_ptr->pos_x_work = 0x200;
        bgw_ptr->hos_xy[0].cal = bgw_ptr->wxy[0].cal = bgw_ptr->xy[0].cal;
        bgw_ptr->zuubun = 0;
        bgw_ptr->fam_no = 2;
        bgw_ptr->xy[1].disp.pos = bgw_ptr->pos_y_work = 0;
        bgw_ptr->y_limit = bgw_ptr->y_limit2 = 96;
        bgw_ptr->speed_x = 0xC000;
        bgw_ptr->speed_y = 0xC000;
        sync_fam_set3(2);
        break;
    default:
        bg_x_move_check();
        bg_y_move_check();
        sync_fam_set3(2);
        break;
    }
}
