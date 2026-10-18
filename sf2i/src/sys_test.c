/*
 * SYS_TEST.C  System library: scroll registers, test mode pages, CD/SCSI, coin chutes
 *
 * Scroll control: Bg_On_W / Bg_Off_W and the layer masks, Scrn_Move_Set and Scrn_Pos_Init set plane
 * positions, Irl_Family and scroll_layers_finalize_frame write the scroll and family registers each
 * frame, and the sprite slot setters point planes at their tilemaps. Operator test menu pages: input
 * and output tests, sound test, colour bars, screen cross hatch, backup RAM (game data) display and
 * clear, and the memory test with its RAM, SIMM and SRAM checks. The boot self-test routines test
 * cell, work, video, palette and sprite RAM and check the CD drive and disc ID; the rewrite menu
 * handles the CD-ROM setup screen. SCSI commands (test unit ready, mode sense, read capacity,
 * request sense, start/stop unit, medium lock, read(10)) drive the CD drive. The last part runs the
 * coin chutes, the service coin and the lockout coils each frame (the chute, credit and switch
 * routines they call are in coin_sw.c).
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "meta_col.h"
#include "meta_col_mem.h"
#include "meta_col_strcpy.h"
#include "meta_col_lib.h"
#include "meta_col_bcd.h"
#include "eeprom.h"
#include "sys_config_2.h"
#include "sys_config_3.h"
#include "textsound.h"
#include "textsound_2.h"
#include "textsound_3.h"
#include "sys_test.h"
#include "cps3.h"

extern volatile s16 flip_crt_ofs_x;
extern volatile s16 flip_crt_ofs_y;

SCRLPOS scrn_pos[5];  /* 0206A104 */
SCROLL_CTRL scrn_reg_w[4];  /* 0206A154 */
SPRPTR scrn_map_ptr[4];  /* 0206A17C */
u16 scrn_line_prm[4][2];  /* 0206A1BC */
SCRN_MODE scrn_mode_prm[4];  /* 0206A1CC */
u16 Screen_Switch;  /* 0206A1DC */
u16 Screen_Switch_Buffer;  /* 0206A1DE */
u8 Screen_Switch_Req;  /* 0206A1E0 */


/* provisional name: unreferenced; toggles a scroll layer's flip bits and applies them */
/* 2i 060EE408, 3s-reloc: sf3 src/sys_test.c:48 scrn_flip_set */
void scrn_flip_set(u16 n, u16 flip) {
    s32 r;
    switch (flip) {
    case 0:
        scrn_mode_prm[n].set ^= 0x800;
        scrn_mode_prm[n].cur = scrn_mode_prm[n].set;
        break;
    case 1:
        scrn_mode_prm[n].set ^= 0x400;
        scrn_mode_prm[n].cur = scrn_mode_prm[n].set;
        break;
    case 2:
        scrn_mode_prm[n].set ^= 0xC00;
        scrn_mode_prm[n].cur = scrn_mode_prm[n].set;
    }
}



/* provisional name: unreferenced; toggles a scroll layer's flip bits */
/* 2i 060EE4C0, 3s-exact: sf3 src/sys_test.c:68 scrn_flip_toggle */
void scrn_flip_toggle(u16 n, u16 flip) {
    s32 r;
    switch (flip) {
    case 0:
        scrn_mode_prm[n].set ^= 0x800;
        break;
    case 1:
        scrn_mode_prm[n].set ^= 0x400;
        break;
    case 2:
        scrn_mode_prm[n].set ^= 0xC00;
    }
}



/* provisional name */
/* 2i 060EE526, 3s-reloc: sf3 src/sys_test.c:85 clear_scroll_layer_state_and_mask */
void clear_scroll_layer_state_and_mask(void) {
    s32 i;
    Bg_Off_R(0xFFF);
    for (i = 0; i < 4; i++) {
        scrn_reg_w[i].pos_x = 0;
        scrn_reg_w[i].pos_y = 0;
        scrn_reg_w[i].attr = 0;
        scrn_reg_w[i].ctrl = 0;
        scrn_reg_w[i].map_adrs = 0;
        scrn_mode_prm[i].set = 0;
        scrn_mode_prm[i].cur = 0;
    }
}



/* 2i 060EE5C8, 3s-reloc: sf3 src/sys_test.c:101 Bg_On_R */
void Bg_On_R(u16 mask) {
    Screen_Switch |= mask;
    Screen_Switch_Buffer = Screen_Switch &= 0xFFF;
    Scrn_Renew();
}



/* 2i 060EE61C, 3s-exact: sf3 src/sys_test.c:109 Bg_On_W */
void Bg_On_W(u16 mask) {
    Screen_Switch |= mask;
    Screen_Switch &= 0xFFF;
    Screen_Switch_Req = 1;
    Scrn_Renew();
}



/* 2i 060EE64C, 3s-reloc: sf3 src/sys_test.c:118 Bg_Off_R */
void Bg_Off_R(mask)
u16 mask;
{
    mask = ~mask;
    Screen_Switch &= mask;
    Screen_Switch_Buffer = Screen_Switch &= 0xFFF;
    Scrn_Renew();
}



/* 2i 060EE68C, 3s-exact: sf3 src/sys_test.c:129 Bg_Off_W */
void Bg_Off_W(mask)
u16 mask;
{
    mask = ~mask;
    Screen_Switch &= mask;
    Screen_Switch &= 0xFFF;
    Screen_Switch_Req = 1;
    Scrn_Renew();
}



/* 2i 060EE6C0, 3s-reloc: sf3 src/sys_test.c:141 Scrn_Renew */
void Scrn_Renew(void) {
    s32 j;
    s32 i;
    u16 bit;
    u16 m;
    for (i = 0; i < 3; i++) {
        bit = scroll_enable_bit_tbl[i][0];
        for (j = 0; j < 4; j++) {
            m = Screen_Switch_Buffer;
            m &= bit;
            if (m == bit) {
                scrn_reg_w[j].ctrl |= scroll_enable_bit_tbl[i][1];
            } else {
                scrn_reg_w[j].ctrl &= ~scroll_enable_bit_tbl[i][1];
            }
            bit <<= 1;
        }
    }
    Screen_Switch_Buffer = Screen_Switch;
}



/* provisional name: unreferenced */
/* 2i 060EE780, 3s-reloc: sf3 src/sys_test.c:165 scrn_line_set_now */
void scrn_line_set_now(n, v)
u16 n;
s16 v;
{
    scrn_line_prm[n][0] = v & 0x3FF;
    scrn_line_prm[n][1] = v & 0x3FF;
}



/* provisional name: unreferenced */
/* 2i 060EE7CC, 3s-exact: sf3 src/sys_test.c:176 scrn_line_set */
void scrn_line_set(u16 n, s16 v) {
    scrn_line_prm[n][0] = v & 0x3FF;
}



/* provisional name */
u32 simmram_large_page_addr(void) {
    u32 addr;
    u16 slot;
    slot = simmram_big_page_alloc_40(1);
    if (slot == 0) {
        return 0;
    }
    return simmram_slot_addr(slot);
}



/* provisional name */
/* 2i 060EE838, 3s-exact: sf3 src/sys_test.c:196 simmram_small_page_addr */
u32 simmram_small_page_addr(void) {
    u32 addr;
    u16 slot;
    slot = simmram_small_page_alloc_40(1);
    if (slot == 0) {
        return 0;
    }
    return simmram_slot_addr(slot);
}



/* provisional name */
/* 2i 060EE872, 3s-reloc: sf3 src/sys_test.c:209 scrn_map_set_now */
void scrn_map_set_now(u16 n, u32 p) {
    scrn_map_ptr[n].ptr0 = (void*)p;
    scrn_map_ptr[n].ptr2 = (void*)p;
}



/* provisional name */
/* 2i 060EE8B4, 3s-exact: sf3 src/sys_test.c:217 scrn_map_set */
void scrn_map_set(u16 n, u32 p) {
    scrn_map_ptr[n].ptr0 = (void*)p;
}



/* provisional name */
/* 2i 060EE8D2, 3s-reloc: sf3 src/sys_test.c:224 scrn_linescroll_set_now */
void scrn_linescroll_set_now(u16 n, void* p) {
    scrn_map_ptr[n].ptr1 = p;
    scrn_map_ptr[n].ptr3 = p;
}



/* provisional name: unreferenced */
/* 2i 060EE90C, 3s-exact: sf3 src/sys_test.c:232 scrn_linescroll_set */
void scrn_linescroll_set(n, p)
u16 n;
void* p;
{
    scrn_map_ptr[n].ptr1 = p;
}



/* provisional name */
/* 2i 060EE92A, 3s-exact: sf3 src/sys_test.c:242 scrn_attr_set */
void scrn_attr_set(s16 n, u16 attr, u16 bits) {
    scrn_reg_w[n].attr = attr << 6;
    scrn_reg_w[n].attr |= bits;
}



/* 2i 060EE978, 3s-reloc: sf3 src/sys_test.c:249 Scrn_Pos_Init */
void Scrn_Pos_Init(void) {
    s32 i;
    for (i = 0; i < 5; i++) {
        scrn_pos[i].set_x.cal = 0;
        scrn_pos[i].cur_x.cal = 0;
        scrn_pos[i].set_y.cal = 0;
        scrn_pos[i].cur_y.cal = 0;
    }
}



/* provisional name */
/* 2i 060EE9D0, 3s-reloc: sf3 src/sys_test.c:262 Scrn_Move_Set_R */
void Scrn_Move_Set_R(s32 n, s16 x, s16 y) {
    scrn_pos[n].set_x.disp.pos = x;
    scrn_pos[n].cur_x.disp.pos = x;
    scrn_pos[n].set_y.disp.pos = y;
    scrn_pos[n].cur_y.disp.pos = y;
}



/* provisional name: unreferenced */
/* 2i 060EEA28, 3s-exact: sf3 src/sys_test.c:272 Scrn_X_Set_R */
void Scrn_X_Set_R(ix, x)
    s32 ix;
    s16 x;
{
    scrn_pos[ix].set_x.disp.pos = x;
    scrn_pos[ix].cur_x.disp.pos = x;
}

/* provisional name */
/* 2i 060EEA54, 3s-reloc: sf3 src/sys_test.c:281 Scrn_Y_Set_R */
void Scrn_Y_Set_R(ix, y)
    s32 ix;
    s16 y;
{
    scrn_pos[ix].set_y.disp.pos = y;
    scrn_pos[ix].cur_y.disp.pos = y;
}



/* 2i 060EEA90, 3s-exact: sf3 src/sys_test.c:291 Scrn_Move_Set */
void Scrn_Move_Set(s32 n, s16 x, s16 y) {
    scrn_pos[n].set_x.disp.pos = x;
    scrn_pos[n].set_y.disp.pos = y;
}



/* provisional name: unreferenced */
/* 2i 060EEABC, 3s-reloc: sf3 src/sys_test.c:299 Scrn_X_Set_W */
void Scrn_X_Set_W(s32 ix, s16 x)
{
    scrn_pos[ix].set_x.disp.pos = x;
}

/* provisional name */
/* 2i 060EEAE4, 3s-exact: sf3 src/sys_test.c:305 Scrn_Y_Set_W */
void Scrn_Y_Set_W(ix, y)
s32 ix;
s16 y;
{
    scrn_pos[ix].set_y.disp.pos = y;
}



/* provisional name: unreferenced */
/* 2i 060EEB02, 3s-reloc: sf3 src/sys_test.c:315 Scrn_Move_Add */
void Scrn_Move_Add(s32 n, s32 dx, s32 dy) {
    scrn_pos[n].set_x.cal += dx;
    scrn_pos[n].set_y.cal += dy;
    if (n == 4) {
        scrn_pos[n].set_x.disp.pos &= 0x1FF;
        scrn_pos[n].set_y.disp.pos &= 0x1FF;
    } else {
        scrn_pos[n].set_x.disp.pos &= 0x3FF;
        scrn_pos[n].set_y.disp.pos &= 0x3FF;
    }
}



/* provisional name */
/* 2i 060EEB84, 3s-reloc: sf3 src/sys_test.c:330 scroll_layers_finalize_frame */
void scroll_layers_finalize_frame(void) {
    s32 i;
    s32 unused1;
    s32 addr;
    volatile u16* reg;
    s32 unused2;
    s16 w;
    reg = ((volatile u16*)(VIDEO_REG + 0x20));
    for (i = 0; i < 4; i++) {
        scrn_reg_w[i].pos_x = zoom_adj_x + scrn_pos[i].cur_x.disp.pos + flip_scr_ofs_x;
        scrn_reg_w[i].pos_x &= 0x3FF;
        *reg = scrn_reg_w[i].pos_x;
        reg++;
        if (((u8)Monitor_Flip) == 0) {
            scrn_reg_w[i].pos_y = -scrn_pos[i].cur_y.disp.pos + zoom_adj_y + flip_scr_ofs_y + 0xFEFC;
        } else {
            scrn_reg_w[i].pos_y = -scrn_pos[i].cur_y.disp.pos + zoom_adj_y + 4;
        }
        scrn_reg_w[i].pos_y &= 0x3FF;
        *reg = scrn_reg_w[i].pos_y;
        reg++;
        *reg = scrn_reg_w[i].attr;
        reg++;
        if (Screen_Switch_Req) {
            Screen_Switch_Req = 0;
            Scrn_Renew();
        }
        w = scrn_reg_w[i].ctrl & ~0x3FF;
        w |= scrn_line_prm[i][1] & 0x3FF;
        scrn_reg_w[i].ctrl = w;
        scrn_reg_w[i].ctrl &= 0xF3FF;
        scrn_reg_w[i].ctrl |= scrn_mode_prm[i].cur & 0xC00;
        *reg = scrn_reg_w[i].ctrl;
        reg++;
        if (scrn_map_ptr[i].ptr2) {
            addr = (s32)scrn_map_ptr[i].ptr2;
            addr = (addr - SPRITE_RAM) >> 12;
            scrn_reg_w[i].map_adrs = addr;
            scrn_reg_w[i].map_adrs &= 0x7F;
        }
        if (scrn_map_ptr[i].ptr3) {
            addr = (s32)scrn_map_ptr[i].ptr3;
            addr = (addr - SPRITE_RAM) >> 4;
            w = addr;
            w &= 0x7F00;
            scrn_reg_w[i].map_adrs |= w;
        }
        *reg = scrn_reg_w[i].map_adrs;
        reg += 4;
        scrn_pos[i].cur_x.cal = scrn_pos[i].set_x.cal;
        scrn_pos[i].cur_y.cal = scrn_pos[i].set_y.cal;
        scrn_map_ptr[i].ptr2 = scrn_map_ptr[i].ptr0;
        scrn_map_ptr[i].ptr3 = scrn_map_ptr[i].ptr1;
        scrn_line_prm[i][1] = scrn_line_prm[i][0];
        scrn_mode_prm[i].cur = scrn_mode_prm[i].set;
    }
    w = scrn_pos[4].cur_x.disp.pos + screen_base_x + flip_crt_ofs_x;
    (*(volatile u16*)(SS_REG + (0x0E))) = w;
    w >>= 8;
    (*(volatile u16*)(SS_REG + (0x10))) = w;
    w = -scrn_pos[4].cur_y.disp.pos + screen_base_y + flip_crt_ofs_y;
    (*(volatile u16*)(SS_REG + (0x20))) = w;
    w >>= 8;
    (*(volatile u16*)(SS_REG + (0x22))) = w;
    scrn_pos[4].cur_x.cal = scrn_pos[4].set_x.cal;
    scrn_pos[4].cur_y.cal = scrn_pos[4].set_y.cal;
}



