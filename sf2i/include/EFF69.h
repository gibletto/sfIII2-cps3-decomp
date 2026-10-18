#ifndef EFF69_H
#define EFF69_H

#include "structs.h"

void EFF69_SLIDE_IN(WORK_Other* ewk);
void Setup_Clear_OBJ(WORK_Other* ewk);
void EFF69_SLIDE_OUT(WORK_Other* ewk);
void EFF69_SUDDENLY(WORK_Other* ewk);
void EFF69_KILL(WORK_Other* ewk);
s32 effect_69_init(s16 dir_old);
void effect_69_move(WORK_Other* ewk);
void EFF69_WAIT(WORK_Other* ewk);

#endif
