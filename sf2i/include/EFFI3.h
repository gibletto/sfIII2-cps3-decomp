#ifndef EFFI3_H
#define EFFI3_H

#include "structs.h"

s32 effI0_piece_set();
void effect_I0_init(WORK* wk, u8 num);
s32 effect_I2_init(void);
void effect_I2_move(WORK_Other* ewk);
s32 effect_I3_init(WORK* wk, u8 tix);
void effect_I3_move(WORK_Other* ewk);
void effect_I1_move(void);

#endif
