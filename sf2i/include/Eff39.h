#ifndef EFF39_H
#define EFF39_H

#include "structs.h"

void EFF39_MOVE(WORK_Other* ewk);
void EFF39_SLIDE_IN(WORK_Other* ewk);
void EFF39_SLIDE_OUT(WORK_Other* ewk);
void EFF39_SUDDENLY(WORK_Other* ewk);
void EFF39_KILL(WORK_Other* ewk);
s32 effect_39_init(s16 PL_id, s16 dir_old, s16 Your_Char, s16 Target_BG, s16 Option);
s32 Get_Pos39();
void EFF39_WAIT(WORK_Other* ewk);
void effect_39_move(WORK_Other* ewk);

#endif
