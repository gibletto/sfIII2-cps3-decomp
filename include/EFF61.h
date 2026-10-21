#ifndef EFF61_H
#define EFF61_H

#include "structs.h"

s32 effect_60_init(s16 type);
void effect_60_move(WORK_Other* ewk);
void effect_61_move(WORK_Other_CONN* ewk);
s32 effect_61_init(WORK_Other* oya);   /* 3rd Strike keeps an empty effect_61_dummy */

#endif
