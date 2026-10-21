#ifndef EFF99_H
#define EFF99_H

#include "structs.h"

s32 effect_99_init(s16 index, s16 timer, s16 ip);
void effect_99_move(WORK_Other* ewk);
void EFF98_KILL(WORK_Other* ewk);
s32 effect_98_init(s16 PL_id, s16 dir_old, s16 master_player, s16 Target_BG);

#endif
