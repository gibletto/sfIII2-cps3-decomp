#ifndef EFFF0_H
#define EFFF0_H

#include "structs.h"

s32 effect_F0_init(WORK* wk);
void effect_F0_move(WORK_Other* ewk);
void effF0_scroll_reset(WORK_Other* ewk);
void effF0_scroll_set(WORK_Other* ewk);

#endif
