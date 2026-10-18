#ifndef BG000_H
#define BG000_H

#include "structs.h"

void BG020(void);
void bg_rect_attr_preset(void);
void bg_rect_attr_add();
void scroll_cell_write(s16 i, u32 ofs, u32 cell, u32 tbl);
void bg_extra_color_trans(void);
void bg_color_trans(void);
void BG000(void);
void bg0001_ctrl(void);
void BG010(void);
void bg0101(void);
void bg0101_init00(void);
void bg0102(void);
void bg0103(void);
void bg0201(void);
void bg0202(void);
void bg020_sync_common(void);
void BG030(void);
void bg0300(void);
void bg0000(void);
void bg0000_demo(void);
void bg0000_init00(void);
void bg020_sync_init(void);
void bg0300_init00(void);
void bg0202_init00(void);
s16 capcom_logo_anim(void);
s16 capcom_logo_color_step(void);
void bg0001_init00(void);
void bg_base_move_common(void);
void bg_move_common(void);
void bg0102_init00(void);
void bg0201_init00(void);
void bg020_sync_move(void);
void bg_initialize(void);
void oh_opening_demo();
void reset_all_char_display_with_backup(void);
void akebono_initialize(void);
void bg_etc_write(s16 x);

#endif
