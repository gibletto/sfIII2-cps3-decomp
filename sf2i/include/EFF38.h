#ifndef EFF38_H
#define EFF38_H

#include "structs.h"

void EFF38_MOVE(WORK_Other* ewk);
void EFF38_SHIFT(WORK_Other* ewk);
void EFF38_SLIDE_IN(WORK_Other* ewk);
void EFF38_SLIDE_OUT(WORK_Other* ewk);
void EFF38_SUDDENLY(WORK_Other* ewk);
void Exit_Slide_in_38(WORK_Other* ewk);
void EFF38_KILL(WORK_Other* ewk);
s32 Move_X_Sub_38(WORK_Other* ewk);
s32 Move_Y_Sub_38(WORK_Other* ewk, s16 Target_Y);
s32 Shift_38(WORK_Other* ewk);
void EFF38_WAIT(WORK_Other* ewk);
s32 effect_38_init(s16 PL_id, s16 dir_old, s16 Your_Char, s16 Play_Status, s16 Target_BG);
void effect_38_move(WORK_Other* ewk);

#endif
