#ifndef EFF16_H
#define EFF16_H

#include "structs.h"

void eff16_trans(WORK* ewk);
s32 effect_16_init();
void effect_16_move(WORK_Other* ewk);
s32 score_bunkai_eff16(WORK_Other_CONN* ewk, u32 tsc);

#endif
