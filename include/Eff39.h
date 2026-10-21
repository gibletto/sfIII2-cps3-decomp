#ifndef EFF39_H
#define EFF39_H

#include "structs.h"

void effect_39_move(WORK_Other* ewk);
s32 eff39_arts_flag(WORK_Other* ewk);
s16 eff39_pattern(WORK_Other* ewk);
void eff39_slide_in_end(WORK_Other* ewk);
s32 effect_39_init(s16 PL_id, s16 Wait, s16 Kind, s16 Face_Set, s16 Your_Char);

#endif
