#ifndef EFFJ9_H
#define EFFJ9_H

#include "structs.h"

void effJ9_trans(WORK* wk);
s32 effect_J9_init(WORK_Other* wk, u8 data);
void effect_J9_move(WORK_Other* ewk);
s16 get_c2_quake(WORK* c2wk);

#endif
