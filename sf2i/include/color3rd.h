#ifndef COLOR3RD_H
#define COLOR3RD_H

#include "structs.h"

void debug_play12_init(void);
void debug_play13_init(void);
void init_color_trans_req(void);
void load_bg_color_fade();
void load_any_color_fade();
void load_any_color_attr(u16 col_no, u8 r, u8 g, u8 b);
void debug_play12(void);
void debug_play13(void);
void debug_play13_move(void);
void debug_play12_move(void);
void metamor_color_restore(u16 wkid);
void color_trans_dummy(void);
void load_bg_color();
void load_any_color_req();
void load_player_color();

#endif
