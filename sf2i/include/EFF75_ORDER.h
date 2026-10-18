#ifndef EFF75_ORDER_H
#define EFF75_ORDER_H

#include "structs.h"

void EFF75_CHAR_CHANGE(WORK_Other* ewk);
void EFF75_SUDDENLY(WORK_Other* ewk);
void EFF75_DIE(WORK_Other* ewk);
void EFF75_WAIT(WORK_Other_CONN* ewk);
void EFF75_SLIDE_IN(WORK_Other* ewk);
s32 effect_75_init(s16 dir_old, s16 ID, s16 Target_BG);

void effect_75_move(WORK_Other* ewk);

#endif
