#ifndef EFF19_H
#define EFF19_H

#include "structs.h"

s32 effect_19_init(void);
void effect_19_move(WORK_Other* ewk);
void eff19_quake_sub(WORK_Other* ewk);

extern const u32 eff19_char_table[];   /* provisional name */

#endif
