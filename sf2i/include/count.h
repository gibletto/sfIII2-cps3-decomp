#ifndef COUNT_H
#define COUNT_H

#include "structs.h"

void count_cont_init();
void count_cont_reset(void);
void counter_control(void);
void counter_flash(s8 type);
void bcount_cont_init(u8 pl);
void bcount_cont_reset(void);
void bcounter_control(void);
s32 bcounter_down(u8 stop);
void counter_color_clear(void);
void bcount_cont_main(void);
void count_cont_main(void);

#endif
