/*
 * ENDBG07.C  Ending background 07 (2nd Impact only)
 *
 * end_BG070 (entry 7) runs layer 1 (no move step), layers 0 and 2 and the synced layer 4 (as stage 07's
 * bg180_sync_*), then the zoom check, position correction and family set.
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

void end_bg070_layer0(void);
void end_bg070_layer0_init00(void);
void end_bg070_layer0_move(void);
void end_bg070_layer1(void);
void end_bg070_layer1_init00(void);
void end_bg070_none(void);
void end_bg070_layer2(void);
void end_bg070_layer2_init00(void);
void end_bg070_layer2_move(void);
void end_bg070_layer4(void);
void end_bg070_layer4_init00(void);
void end_bg070_layer4_move(void);
#pragma inline(end_bg070_layer1, end_bg070_layer0, end_bg070_layer2, end_bg070_layer4)


/* provisional name */
void end_BG070(void) {
    bgw_ptr = &bg_w.bgw[1];
    end_bg070_layer1();
    bgw_ptr = &bg_w.bgw[0];
    end_bg070_layer0();
    bgw_ptr = &bg_w.bgw[2];
    end_bg070_layer2();
    bgw_ptr = &bg_w.bgw[4];
    end_bg070_layer4();
    zoom_ud_check();
    bg_pos_hosei2();
    Bg_Family_Set();
}



/* provisional name */
void end_bg070_layer0(void) {
    void (*end_bg0700_jmp[2])() = { end_bg070_layer0_init00, end_bg070_layer0_move };
    end_bg0700_jmp[bgw_ptr->r_no_0]();
}



/* provisional name */
void end_bg070_layer0_init00(void) {
    bgw_ptr->r_no_0++;
    bgw_ptr->old_pos_x = bgw_ptr->xy[0].disp.pos = bgw_ptr->pos_x_work = 0x200;
    bgw_ptr->hos_xy[0].cal = bgw_ptr->wxy[0].cal = bgw_ptr->xy[0].cal;
    bgw_ptr->zuubun = 0;
}



/* provisional name */
void end_bg070_layer0_move(void) {
    bg_x_move_check();
    bg_y_move_check();
}



/* provisional name */
void end_bg070_layer1(void) {
    void (*end_bg0701_jmp[2])() = { end_bg070_layer1_init00, end_bg070_none };
    end_bg0701_jmp[bgw_ptr->r_no_0]();
}



/* provisional name */
void end_bg070_layer1_init00(void) {
    bgw_ptr->r_no_0++;
    bgw_ptr->old_pos_x = bgw_ptr->xy[0].disp.pos = bgw_ptr->pos_x_work = 0x200;
    bgw_ptr->hos_xy[0].cal = bgw_ptr->wxy[0].cal = bgw_ptr->xy[0].cal;
    bgw_ptr->zuubun = 0;
}



/* provisional name */
void end_bg070_none(void) {
}



/* provisional name */
void end_bg070_layer2(void) {
    void (*end_bg0702_jmp[2])() = { end_bg070_layer2_init00, end_bg070_layer2_move };
    end_bg0702_jmp[bgw_ptr->r_no_0]();
}



/* provisional name */
void end_bg070_layer2_init00(void) {
    bgw_ptr->r_no_0++;
    bgw_ptr->old_pos_x = bgw_ptr->xy[0].disp.pos = bgw_ptr->pos_x_work = 0x200;
    bgw_ptr->hos_xy[0].cal = bgw_ptr->wxy[0].cal = bgw_ptr->xy[0].cal;
    bgw_ptr->zuubun = 0;
}



/* provisional name */
void end_bg070_layer2_move(void) {
    bg_x_move_check();
    bg_y_move_check();
}



/* provisional name */
void end_bg070_layer4(void) {
    void (*end_bg0704_jmp[2])() = { end_bg070_layer4_init00, end_bg070_layer4_move };
    end_bg0704_jmp[bgw_ptr->r_no_0]();
}



/* provisional name */
void end_bg070_layer4_init00(void) {
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



/* provisional name */
void end_bg070_layer4_move(void) {
    bg_x_move_check();
    bg_y_move_check();
    sync_fam_set3(4);
}
