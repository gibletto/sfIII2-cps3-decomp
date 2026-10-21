/*
 * SCRN_WORK.C  screen and scroll control work RAM (scrn_ctrl)
 *
 * Cleared work RAM (section B).
 */

#include "types.h"
#include "structs.h"

SCREEN_WINDOW screen_window[2];  /* 020644E4 */
SCROLL_WINDOW zoom_frame[2];  /* 020644F4 */
volatile s16 screen_disp_ctrl;  /* 02064504 */
s16 screen_base_x;  /* 02064506 */
s16 screen_base_y;  /* 02064508 */
s32 screen_mode;  /* 0206450C */
u8 zoom_req_flag;  /* 02064510 */
u8 window_req_flag;  /* 02064511 */
s16 zoom_adj_x;  /* 02064512 */
s16 zoom_adj_y;  /* 02064514 */
u16 flip_obj_ofs_x;  /* 02064516 */
u16 flip_obj_ofs_y;  /* 02064518 */
s16 flip_crt_ofs_x;  /* 0206451A */
s16 flip_crt_ofs_y;  /* 0206451C */
s16 flip_scr_ofs_x;  /* 0206451E */
s16 flip_scr_ofs_y;  /* 02064520 */
s16 flip_zoom_ofs_x;  /* 02064522 */
s16 flip_zoom_ofs_y;  /* 02064524 */
