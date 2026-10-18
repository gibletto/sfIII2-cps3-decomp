#ifndef EFF42_H
#define EFF42_H

#include "structs.h"

void EFF42_MOVE(WORK_Other* ewk);
void EFF42_SLIDE_IN(WORK_Other* ewk);
void EFF42_SLIDE_OUT(WORK_Other* ewk);
void EFF42_SUDDENLY(WORK_Other* ewk);
void EFF42_KILL(WORK_Other* ewk);
void Setup_Char_Index(WORK_Other* ewk);
s32 effect_41_init(PLW* wk, u8 data);
s32 effect_42_init(s16 Type);
void effect_42_move(WORK_Other* ewk);

s32 zoom_x_step_check();

#endif
