#ifndef EFFD7_H
#define EFFD7_H

#include "structs.h"

void ball_init_position_effD7(WORK_Other* ewk, PLW* mwk);
void cal_speeds_to_em(WORK_Other* ewk, PLW* twk);
void cal_speeds_to_me(WORK_Other* ewk, PLW* mwk);
void effD7_main_process(WORK_Other* ewk);
s32 effect_D7_init(PLW* wk);
void effect_D7_move(WORK_Other* ewk);
s32 my_ball_live_check(PLW* wk);
s32 screen_range_check_effD7(WORK* wk);
void cal_speeds_effD7();

#endif
