#ifndef EFF85_H
#define EFF85_H

#include "structs.h"

void eff85_1000(WORK_Other* ewk);
void eff85_5000(WORK_Other* ewk);
void eff85_8000(WORK_Other* ewk);
void eff85_0000(WORK_Other* ewk);
void eff85_0200(WORK_Other* ewk);
void eff85_9000(WORK_Other* ewk);
void eff85_0100(WORK_Other* ewk);
void eff85_3000(WORK_Other* ewk);
void eff85_7000(WORK_Other* ewk);
void eff85_common(WORK_Other* ewk);
s32 effect_85_init(void);
void effect_85_move(WORK_Other* ewk);
s32 swallow_sprize_check(WORK_Other* ewk);

#endif
