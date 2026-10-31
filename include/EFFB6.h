#ifndef EFFB6_H
#define EFFB6_H

#include "structs.h"

s32 effect_B5_init(s16 PL_id);
void effB6_pos_data_set();
s32 effect_B6_init(WORK_Other* oya, u8 type);
void effect_B6_move(WORK_Other_CONN* ewk_conn);
void effect_B7_move(WORK_Other* ewk);
s32 effect_B7_init(s8 pl);

#endif
