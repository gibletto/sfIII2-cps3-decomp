#ifndef BG_SUB_2_H
#define BG_SUB_2_H

#include "structs.h"

void Bg_mv_tw(s32 value_x, s32 value_y);
void bg_base_x_move_check(void);
void scr_10_21(void);
void scr_11_20(void);
void scr_11_22(void);
void scr_12_21(void);
void scr_12_22(void);
void scr_11_22_2(void);
void scr_12_21_2(void);
void bg_base_x_move_sub(void);
void scr_10_22(void);
void scr_11_21(void);
void scr_12_20(void);
void Bg_mv_tw_appoint();
void x_left_check(s16 d0);
void scr_x_dummy(void);
void scr_10_20(void);
void x_right_check(s16 d1);
s32 remake_mvstep();
void bg_chase_move(void);
void chase_start_check(void);
s32 chase_xy_move(void);
void check_cg_zoom(void);

#endif
