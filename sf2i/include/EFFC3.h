#ifndef EFFC3_H
#define EFFC3_H

#include "structs.h"

void bs2_display_C3(WORK* wk);
void clear_parts_hit_data(WORK* wk);
void effC3_main_process(WORK_Other* ewk);
s32 effect_C3_init();
void effect_C3_move(WORK_Other* ewk);
s32 get_efffC3_nsc();
void set_display_car_parts(WORK_Other* wk);

#endif
