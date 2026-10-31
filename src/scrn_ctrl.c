/*
 * SCRN_CTRL.C  Screen mode, window and zoom registers
 *
 * set_screen_mode and screen_flip_offsets_set choose normal or wide screen; screen_window_regs_update
 * and zoom_regs_update write the window and zoom registers in vblank; Zoomf_Init_X/Y, Frame_Up/Down
 * and Frame_Adgjust handle screen zoom.
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "Com_Sub.h"
#include "ACTIVE00.h"
#include "active01.h"
#include "active02.h"
#include "active03.h"
#include "active04.h"
#include "active05.h"
#include "active06.h"
#include "active07.h"
#include "active08.h"
#include "active09.h"
#include "active10.h"
#include "active11.h"
#include "active12.h"
#include "active13.h"
#include "active14.h"
#include "active15.h"
#include "active16.h"
#include "active17.h"
#include "active18.h"
#include "active19.h"
#include "active20.h"
#include "FOLLOW01.h"
#include "FOLLOW02.h"
#include "fifo.h"
#include "sys_test.h"
#include "sys_test_2.h"
#include "sys_test_2b.h"
#include "sys_test_2c.h"
#include "sys_test_3.h"
#include "sys_test_4.h"
#include "sys_test_5.h"
#include "textsound.h"
#include "textsound_2.h"
#include "textsound_3.h"
#include "pass00.h"
#include "PASS01.h"
#include "PASS02.h"
#include "PASS03.h"
#include "PASS04.h"
#include "PASS05.h"
#include "PASS06.h"
#include "PASS07.h"
#include "PASS08.h"
#include "PASS09.h"
#include "pass10.h"
#include "PASS11.h"
#include "PASS12.h"
#include "pass13.h"
#include "pass14.h"
#include "pass15.h"
#include "pass16.h"
#include "pass17.h"
#include "pass18.h"
#include "pass19.h"
#include "Passive20.h"
#include "SHELL00.h"
#include "SHELL01.h"
#include "SHELL03.h"
#include "SHELL04.h"
#include "SHELL05.h"
#include "SHELL07.h"
#include "SHELL11.h"
#include "SHELL12.h"
#include "SHELL13.h"
#include "SHELL14.h"
#include "Entry.h"
#include "entry_2.h"
#include "CMD_MAIN.h"
#include "cmd_main_2.h"
#include "sys_config.h"
#include "sys_config_2.h"
#include "sys_config_3.h"
#include "PLS02.h"
#include "SE.h"
#include "se_2.h"
#include "se_3.h"
#include "EFFECT.h"
#include "effect_2.h"
#include "aboutspr.h"
#include "end_sub.h"
#include "end_sub_2.h"
#include "end_sub_3.h"
#include "end_sub_4.h"
#include "end_sub_5.h"
#include "end_sub_6.h"
#include "end_sub_7.h"
#include "color3rd.h"
#include "end_sub_8.h"
#include "sc_trans.h"
#include "Manage.h"
#include "manage_2.h"
#include "bg0001.h"
#include "Com_Pl.h"
#include "cps3.h"
#include "fighter.h"
#include "RANKING.h"

extern s16 flip_crt_ofs_x;
extern s16 flip_crt_ofs_y;



s8 Monitor_Flip_Old = 0;  /* 020084D4 */


/* provisional name */
void screen_flip_offsets_set(void) {
    zoom_req_flag = 1;
    if (Monitor_Flip) {
        flip_obj_ofs_x = screen_flip_ofs_tbl[screen_mode][0];
        flip_obj_ofs_y = screen_flip_ofs_tbl[screen_mode][1];
        flip_crt_ofs_x = screen_flip_ofs_tbl[screen_mode][2];
        flip_crt_ofs_y = screen_flip_ofs_tbl[screen_mode][3];
        flip_scr_ofs_x = screen_flip_ofs_tbl[screen_mode][4];
        flip_scr_ofs_y = screen_flip_ofs_tbl[screen_mode][5];
        flip_zoom_ofs_x = screen_flip_ofs_tbl[screen_mode][6];
        flip_zoom_ofs_y = screen_flip_ofs_tbl[screen_mode][7];
    } else {
        flip_obj_ofs_x = 0;
        flip_obj_ofs_y = 0;
        flip_crt_ofs_x = 0;
        flip_crt_ofs_y = 0;
        flip_scr_ofs_x = 0;
        flip_scr_ofs_y = 0;
        flip_zoom_ofs_x = 0;
        flip_zoom_ofs_y = 0;
    }
}



/* provisional name */
void set_screen_mode(mode)
s32 mode;
{
    s16 unused;

    window_req_flag = 1;
    screen_mode = mode;
    screen_base_x = screen_origin_tbl[mode][0];
    screen_base_y = screen_origin_tbl[mode][1];
    if (screen_mode == 7 && Monitor_Flip) {
        screen_window[0].l = screen_window_flip_tbl[0];
        screen_window[0].t = screen_window_flip_tbl[1];
        screen_window[0].r = screen_window_flip_tbl[2];
        screen_window[0].b = screen_window_flip_tbl[3];
        screen_window[1].l = screen_window_flip_tbl[4];
        screen_window[1].t = screen_window_flip_tbl[5];
        screen_window[1].r = screen_window_flip_tbl[6];
        screen_window[1].b = screen_window_flip_tbl[7];
        screen_disp_ctrl = screen_window_flip_tbl[8];
    } else {
        screen_window[0].l = screen_window_tbl[mode][0];
        screen_window[0].t = screen_window_tbl[mode][1];
        screen_window[0].r = screen_window_tbl[mode][2];
        screen_window[0].b = screen_window_tbl[mode][3];
        screen_window[1].l = screen_window_tbl[mode][4];
        screen_window[1].t = screen_window_tbl[mode][5];
        screen_window[1].r = screen_window_tbl[mode][6];
        screen_window[1].b = screen_window_tbl[mode][7];
        screen_disp_ctrl = screen_window_tbl[mode][8];
    }
}



/* provisional name */
void screen_window_regs_update(void) {
    u16 t;
    if (Monitor_Flip != Monitor_Flip_Old) {
        Monitor_Flip_Old = Monitor_Flip;
        screen_flip_offsets_set();
        goto set;
    }
    if (window_req_flag == 0) {
        goto end;
    } else {
        window_req_flag = 0;
    }
set:
    *(u16*)(VIDEO_REG + 0x60) = screen_window[0].l;
    *(u16*)(VIDEO_REG + 0x62) = screen_window[0].t;
    *(u16*)(VIDEO_REG + 0x64) = screen_window[0].r;
    *(u16*)(VIDEO_REG + 0x66) = screen_window[0].b;
    *(u16*)(VIDEO_REG + 0x70) = screen_window[1].l;
    *(u16*)(VIDEO_REG + 0x72) = screen_window[1].t;
    *(u16*)(VIDEO_REG + 0x74) = screen_window[1].r;
    *(u16*)(VIDEO_REG + 0x76) = screen_window[1].b;
    if (Monitor_Flip) {
        t = screen_disp_ctrl;
        t |= 24;
        *(u16*)(VIDEO_REG + 0x80) = t;
    } else {
        *(u16*)(VIDEO_REG + 0x80) = screen_disp_ctrl;
    }
    t = screen_window[0].l;
    *(u16*)SS_REG = t;
    *(u16*)(SS_REG + 0x2) = screen_disp_reg_tbl[screen_mode][0];
    *(u16*)(SS_REG + 0x4) = screen_disp_reg_tbl[screen_mode][1];
    *(u16*)(SS_REG + 0x6) = screen_disp_reg_tbl[screen_mode][2];
    *(u16*)(SS_REG + 0x8) = screen_disp_reg_tbl[screen_mode][3];
    t = screen_window[0].b;
    *(u16*)(SS_REG + 0xA) = t;
    t >>= 8;
    *(u16*)(SS_REG + 0xC) = t;
    t = screen_window[1].l;
    *(u16*)(SS_REG + 0x12) = t;
    t = screen_window[1].t;
    *(u16*)(SS_REG + 0x14) = t;
    t >>= 8;
    *(u16*)(SS_REG + 0x16) = t;
    t = screen_window[1].r;
    t += 2;
    *(u16*)(SS_REG + 0x18) = t;
    t >>= 8;
    *(u16*)(SS_REG + 0x1A) = t;
    t = screen_window[1].b;
    *(u16*)(SS_REG + 0x1C) = t;
    t >>= 8;
    *(u16*)(SS_REG + 0x1E) = t;
    t = screen_disp_ctrl & 7;
    *(u16*)(SS_REG + 0x26) = t;
    if (Monitor_Flip) {
        *(u16*)(SS_REG + 0x28) = 3;
    } else {
        *(u16*)(SS_REG + 0x28) = 0;
    }
end:;
}



void Zoomf_Init(void) {
    zoom_frame[0].pos = 0;
    zoom_frame[0].size = 0;
    zoom_frame[0].mask = 1023;
    zoom_frame[0].zoom = 64;
    zoom_frame[1].pos = 0;
    zoom_frame[1].size = 0;
    zoom_frame[1].mask = 1023;
    zoom_frame[1].zoom = 64;
    zoom_adj_x = 0;
    zoom_adj_y = 0;
    zoom_req_flag = 1;
    if (Monitor_Flip) {
        screen_flip_offsets_set();
    }
}



/* provisional name */
void Zoomf_Init_X(void) {
    zoom_frame[0].pos = 0;
    zoom_frame[0].size = 0;
    zoom_frame[0].mask = 0x3FF;
    zoom_frame[0].zoom = 64;
    zoom_adj_x = 0;
    zoom_req_flag = 1;
    if (Monitor_Flip) {
        screen_flip_offsets_set();
    }
}



/* provisional name */
void Zoomf_Init_Y(void) {
    zoom_frame[1].pos = 0;
    zoom_frame[1].size = 0;
    zoom_frame[1].mask = 0x3FF;
    zoom_frame[1].zoom = 64;
    zoom_adj_y = 0;
    zoom_req_flag = 1;
    if (Monitor_Flip) {
        screen_flip_offsets_set();
    }
}



/* Zooms the frame in; returns the vertical offset computed by Frame_Adgjust. */
s32 Frame_Up(u16 x, u16 y, u16 add_x, u16 add_y) {
    zoom_frame[0].zoom -= add_x;
    zoom_frame[1].zoom -= add_y;
    Frame_Adgjust(x, y);
    zoom_req_flag = 1;
}



/* Zooms the frame out; returns the vertical offset computed by Frame_Adgjust. */
s32 Frame_Down(u16 x, u16 y, u16 add_x, u16 add_y) {
    zoom_frame[0].zoom += add_x;
    zoom_frame[1].zoom += add_y;
    Frame_Adgjust(x, y);
    zoom_req_flag = 1;
}



/* Recomputes the zoom frame offsets; returns the vertical offset as first computed (before -32 is nudged to -31). */
void Frame_Adgjust(u16 pos_x, u16 pos_y) {
    u16 buff;
    if (Monitor_Flip) {
        pos_y = 0xD0 - pos_y;
        if (screen_mode != 7) {
            flip_zoom_ofs_x = 0x80;
        }
    }
    if (zoom_frame[0].zoom >= 0x40) {
        buff = zoom_frame[0].zoom;
        buff -= 0x40;
        buff *= pos_x;
        buff >>= 6;
        buff &= 0x1FF;
        zoom_adj_x = -buff;
        if (Monitor_Flip && screen_mode != 7) {
            flip_zoom_ofs_x = 0x80 - buff * 2;
        }
    } else {
        buff = 0x40;
        buff -= zoom_frame[0].zoom;
        buff *= pos_x;
        buff >>= 6;
        buff &= 0x1FF;
        if (!Monitor_Flip) {
            zoom_adj_x = buff;
        } else {
            zoom_adj_x = -buff;
        }
    }
    if (zoom_frame[1].zoom >= 0x40) {
        buff = zoom_frame[1].zoom;
        buff -= 0x40;
        buff *= pos_y + 0x21;
        buff >>= 6;
        buff &= 0x1FF;
        if (Monitor_Flip == 0) {
            zoom_adj_y = -buff;
        } else {
            zoom_adj_y = buff;
        }
        if (zoom_adj_y == -0x20) {
            zoom_adj_y++;
        }
    } else {
        buff = 0x40;
        buff -= zoom_frame[1].zoom;
        buff *= pos_y + 0x21;
        buff >>= 6;
        buff &= 0x1FF;
        if (Monitor_Flip == 0) {
            zoom_adj_y = buff;
        } else {
            zoom_adj_y = -buff;
        }
        if (zoom_adj_y == -0x20) {
            zoom_adj_y++;
        }
    }
}



/* provisional name */
void zoom_regs_update(void) {
    if (zoom_req_flag) {
        zoom_req_flag = 0;
        *(s16*)(VIDEO_REG + 0x68) = (zoom_frame[0].pos + flip_zoom_ofs_x) & 0x3FF;
        *(s16*)(VIDEO_REG + 0x6A) = zoom_frame[0].size;
        *(s16*)(VIDEO_REG + 0x6C) = zoom_frame[0].mask;
        *(s16*)(VIDEO_REG + 0x6E) = zoom_frame[0].zoom;
        *(s16*)(VIDEO_REG + 0x78) = (zoom_frame[1].pos + flip_zoom_ofs_y) & 0x3FF;
        *(s16*)(VIDEO_REG + 0x7A) = zoom_frame[1].size;
        *(s16*)(VIDEO_REG + 0x7C) = zoom_frame[1].mask;
        *(s16*)(VIDEO_REG + 0x7E) = zoom_frame[1].zoom;
    }
}
