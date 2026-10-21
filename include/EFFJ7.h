#ifndef EFFJ7_H
#define EFFJ7_H

#include "structs.h"

s32 effect_J7_init(PLW* wk);
void effect_J7_move(WORK_Other* ewk);
void get_new_color_data(WORK* wk, ColorCode* trom, s16* tram);
void check_new_color_data(WORK* wk);

#endif
