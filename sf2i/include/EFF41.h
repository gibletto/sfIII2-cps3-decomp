#ifndef EFF41_H
#define EFF41_H

#include "structs.h"

s32 effect_40_init(s16 dir, s16 timer);
void eff41_process_00(WORK_Other* ewk, PLW* mwk);
void eff41_process_01(WORK_Other* ewk, PLW* mwk);
void effect_40_move(WORK_Other* ewk);
void effect_41_move(WORK_Other* ewk);
void gauge_minus(WORK_Other* ewk, PLW* mwk);

#endif
