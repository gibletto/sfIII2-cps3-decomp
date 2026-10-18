#ifndef EFFK4_H
#define EFFK4_H

#include "structs.h"

s32 effect_K4_init(WORK_Other* wk, WORK* dad);
void effect_K4_move(WORK_Other* ewk);
void get_init_position_effK4(WORK* wk);
void get_init_speed_and_timer_effK4(WORK* wk);
void setup_effK4();

#endif
