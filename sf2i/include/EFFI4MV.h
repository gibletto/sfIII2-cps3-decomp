#ifndef EFFI4MV_H
#define EFFI4MV_H

#include "structs.h"

s32 effect_I4_init(void);
void effect_I4_move(WORK_Other* ewk);
void effect_i4_hit_sub(WORK_Other* ewk);
void effi4_down_to_up(WORK_Other* ewk);
void effi4_up_to_down(WORK_Other* ewk);

#endif
