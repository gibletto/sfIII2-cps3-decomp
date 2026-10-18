#ifndef EFFD8_H
#define EFFD8_H

#include "structs.h"

s32 effect_D8_entry(s16 PL_id, s16 Type);
s32 Setup_Face_Offset_X();
void effect_D8_init();
void effect_D8_move(WORK_Other* ewk);

#endif
