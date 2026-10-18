#ifndef EFFJ8_H
#define EFFJ8_H

#include "structs.h"

void dragonfly_l_move_1(WORK_Other* ewk);
void dragonfly_r_move_1(WORK_Other* ewk);
void dragonfly_l_move(WORK_Other* ewk);
void dragonfly_l_move_0(WORK_Other* ewk);
s16 dragonfly_l_move_2(WORK_Other* ewk);
s16 dragonfly_l_move_3(WORK_Other* ewk);
s16 dragonfly_l_move_4(WORK_Other* ewk);
void dragonfly_line_set(WORK_Other* ewk, s16 dir_type);
void dragonfly_move(WORK_Other* ewk);
void dragonfly_move_0000(WORK_Other* ewk);
void dragonfly_move_0001(WORK_Other* ewk);
void dragonfly_move_0004(WORK_Other* ewk);
void dragonfly_move_0005(WORK_Other* ewk);
void dragonfly_move_next(WORK_Other* ewk);
void dragonfly_r_move(WORK_Other* ewk);
void dragonfly_r_move_0(WORK_Other* ewk);
s16 dragonfly_r_move_2(WORK_Other* ewk);
s16 dragonfly_r_move_3(WORK_Other* ewk);
s16 dragonfly_r_move_4(WORK_Other* ewk);
void dragonfly_stop_timer(WORK_Other* ewk);
s32 effect_J8_init(void);
void effect_J8_move(WORK_Other* ewk);

#endif
