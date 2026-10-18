#ifndef EFF93_H
#define EFF93_H

#include "structs.h"

void Bg_Family_Set_Ex(s16 xx);
void Eff93_SLIDE_L(WORK_Other* ewk);
void Eff93_SLIDE_R(WORK_Other* ewk);
void Eff93_SLIDE_L_OUT(WORK_Other* ewk);
void Eff93_SLIDE_R_OUT(WORK_Other* ewk);
s32 effect_93_init(s8 Move_Type, s16 Time);
void effect_93_move(WORK_Other* ewk);

#endif
