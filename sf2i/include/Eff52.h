#ifndef EFF52_H
#define EFF52_H

#include "structs.h"

void EFF52_SLIDE_IN(WORK_Other* ewk);
void EFF52_SLIDE_OUT(WORK_Other* ewk);
void EFF52_SUDDENLY(WORK_Other* ewk);
void EFF52_KILL(WORK_Other* ewk);
s32 effect_52_init(s16 PL_id, s16 dir_old);
void Setup_Char_52(WORK_Other* ewk);
void Setup_Pos_52(WORK_Other* ewk);
void effect_52_move(WORK_Other* ewk);
void EFF52_WAIT(WORK_Other* ewk);

#endif
