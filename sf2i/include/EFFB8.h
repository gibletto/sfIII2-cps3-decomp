#ifndef EFFB8_H
#define EFFB8_H

#include "structs.h"

s32 effect_B8_init(s8 WIN_PL_NO, s16 timer);
void effect_B8_move(WORK_Other_CONN* ewk);
s32 effB8_mes_change_init(s16 pl, s16 mes_no);
void wk_set(WORK_Other_CONN* ewk);

#endif
