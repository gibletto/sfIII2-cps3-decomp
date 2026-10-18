#ifndef EFFH9_H
#define EFFH9_H

#include "structs.h"

s32 effect_H7_init(WORK* wk, s16 type);
s32 effect_H8_init(WORK* wk, s16 type);
void effect_H7_move(WORK_Other* ewk);
void effect_H8_move(WORK_Other* ewk);
s32 effect_H9_init(PLW* wk);
void effect_H9_move(WORK_Other_CONN* ewk);
void effH9_trans(WORK* ewk);
void nokori_ball_effH9(WORK_Other_CONN* ewk, s16 num);

#endif
