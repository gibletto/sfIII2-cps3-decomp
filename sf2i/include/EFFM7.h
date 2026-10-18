#ifndef EFFM7_H
#define EFFM7_H

#include "structs.h"

s32 effect_M6_init(WORK_Other* oya);
void effm7_move(WORK_Other* ewk);
void Player_control(void);
s32 effect_M7_init(PLW* oya);
s32 effect_M8_init(WORK* oya, u8 data);
void don_run_sub_m8(WORK_Other* ewk);
void effect_M7_move(WORK_Other* ewk);
void effm8_move_app(WORK_Other* ewk);
void effect_M8_move(WORK_Other* ewk);
void effm8_move_win(WORK_Other* ewk);

void plcnt_init(void);

#endif
