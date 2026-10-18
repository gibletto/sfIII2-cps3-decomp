#ifndef EFFJ4_H
#define EFFJ4_H

#include "structs.h"

s32 effect_J4_init2(s16 ix);
s32 effect_J3_init(WORK* wk, u8 type);
s32 effect_J4_init(u8 unused, u8 data);
void effect_J3_move(WORK_Other* ewk);
void effect_J4_move(WORK_Other* ewk);
s32 effJ4_piece_set();
s32 effJ4_piece_set_stay();

#endif
