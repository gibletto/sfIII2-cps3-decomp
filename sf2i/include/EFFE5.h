#ifndef EFFE5_H
#define EFFE5_H

#include "structs.h"

void get_attdata_of_illusion(WORK_Other* ewk);
s32 effect_E5_init(PLW* wk);
void effect_E5_move(WORK_Other* ewk);
void setup_illusion_data(WORK_Other* ewk, PLW* mwk);
s32 check_new_after_image(WORK_Other* ewk, PLW* mwk);
void effect_e7_e8_init_union(WORK_Other* nwk, WORK_Other* ek, PLW* mk);
void erase_after_images(PLW* wk, u8 who);
void setup_after_images(PLW* wk, u8 ix);
void effect_E4_move(void);

#endif
