#ifndef EFF45_H
#define EFF45_H

#include "structs.h"

void effect_45_move(WORK_Other* ewk);
s32 effect_45_init(void);

extern const s16 eff45_pos_x_tbl[];       /* provisional names (06179360, 061793A0, 061793C0) */
extern const s16 eff45_pos_y_tbl[16];
extern const s16 eff45_pos_y_tbl2[16];
extern const u32 eff45_char_table[];      /* provisional name */

#endif
