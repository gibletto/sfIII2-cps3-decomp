#ifndef EFF95_H
#define EFF95_H

#include "structs.h"

void effect_95_move(WORK_Other* ewk);
s32 effect_95_init(s16 kind, s16 pl);
s32 eff95_set_obj();
s8 eff95_rl_check(s16 pl);
s32 effect_95_rank_init();
void eff95_set_position(WORK_Other* ewk, s16 pl);
void eff95_set_speed();

#endif
