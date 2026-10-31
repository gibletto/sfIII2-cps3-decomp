/*
 * sc_trans.c  Text (fix) layer character transfer and put routines
 *
 * Low-level routines for the fix layer used by the HUD, menus and result screens.
 * Character data from sc_chr_data is copied into the fix-layer character RAM a row at a time
 * (sc_chr_trans, sc_chr_block_trans, sc_chr_sheet_trans, sc_chr_list_trans, sc_chr_slot_trans),
 * or into a RAM buffer and later to video RAM (sc_chr_to_ram, sc_ram_to_vram); sc_chr_save /
 * sc_chr_load / sc_chr_backup preserve the name-entry letters while the whole font is reloaded
 * (Ranking_00_6th), and ToneDown loads the screen tone-down characters.
 * The put routines write cells to the text tilemap: square and line blocks (scfont_sqput,
 * scfont_lnput and reversed forms), fills and rectangles, single cells and attributes, cell
 * lists and pictures. HUD transfers built on them draw the player names, timer and count
 * digits, super art numbers, stock and max marks, and the round win marks.
 * SF3_logo clears a block of the text layer character area and then puts the "SF3" logo as a
 * 16 x 6 cell block with scfont_sqput, at the column taken from the DE_X table and the row
 * passed in (called by effect 59). break_into_banner_trans is called from the effect A2 main
 * routine while the new challenger banner is shown: kind 0 clears the banner characters and
 * redraws the text layer; any other kind copies the kind-th three-cell column of the banner
 * graphics from sc_chr_data into character RAM.
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "Grade.h"
#include "sys_config.h"
#include "sys_config_2.h"
#include "sys_config_3.h"
#include "sc_trans.h"
#include "cps3.h"
#include "fighter.h"
#include "sc_logo.h"
#include "EffA2.h"
#include "cmb_win.h"



u16 * sc_trans_dst;  /* 02023C20 */
u8 * sc_bak_ptr;  /* 02023C24 */
const u8 * sc_trans_src;  /* 02023C28 */
u8 sc_trans_src_tail[6];  /* after sc_trans_src; nothing refers to it by name or address */
u16 sc_trans_word;  /* 02023C32 */
u8 sc_chr_bak_1p[320];  /* 02023C34 */
u8 sc_chr_bak_2p[324];  /* 02023D74 */



/* provisional name */
s32 sc_chr_trans(rows)
u16 rows;
{
    u16* dst = sc_trans_dst;
    const u8* src = sc_trans_src;
    s32 i;
    for (i = 0; i < rows * 32; i++) {
        *dst = *src;
        dst++;
        src++;
    }
}



/* provisional name */
void sc_chr_save(u16 rows) {
    s32 i;
    for (i = 0; i < rows * 32; i++) {
        *sc_bak_ptr = *sc_trans_dst;
        sc_bak_ptr++;
        sc_trans_dst++;
    }
}



/* provisional name */
void sc_chr_load(u16 rows) {
    s32 i;
    for (i = 0; i < rows * 32; i++) {
        *sc_trans_dst = *sc_bak_ptr;
        sc_bak_ptr++;
        sc_trans_dst++;
    }
}



/* Copies w * h font characters, stored one after another from character chr, into a w x h block of the text
   character RAM at pos. */
/* provisional name */
void sc_chr_block_trans(chr, pos, w, h)
u16 chr;
u16 pos;
u16 w;
u16 h;
{
    s32 i, j, k;
    u16* dst;
    sc_trans_src = (u8*)&sc_chr_data[chr * 32 / 2];
    sc_trans_dst = (u16*)(pos * 64 + (SS_RAM + 0x8000));
    dst = sc_trans_dst;
    i = 0;
    for (; (u16)i < h; i++) {
        for (j = 0; (u16)j < w; j++) {
            k = 0;
            do {
                k += 2;
                {
                    u16 v = *sc_trans_src;
                    *sc_trans_dst = v;
                }
                sc_trans_dst++;
                sc_trans_src++;
                {
                    u16 v = *sc_trans_src;
                    *sc_trans_dst = v;
                }
                sc_trans_dst++;
                sc_trans_src++;
            } while ((u16)k < 32);
        }
        dst += 0x200;
        sc_trans_dst = dst;
    }
}



/* Copies a w x h block of font characters from character chr into a w x h block of the text character RAM at
   pos; the font and the character RAM are both 16 characters to the row. */
/* provisional name */
void sc_chr_sheet_trans(chr, pos, w, h)
u16 chr;
u16 pos;
u16 w;
u16 h;
{
    s32 i, j, k;
    const u8* src;
    u16* dst;
    sc_trans_src = (u8*)&sc_chr_data[chr * 32 / 2];
    sc_trans_dst = (u16*)(pos * 64 + (SS_RAM + 0x8000));
    dst = sc_trans_dst;
    src = sc_trans_src;
    i = 0;
    for (; (u16)i < h; i++) {
        for (j = 0; (u16)j < w; j++) {
            k = 0;
            do {
                k += 2;
                {
                    u16 v = *sc_trans_src;
                    *sc_trans_dst = v;
                }
                sc_trans_dst++;
                sc_trans_src++;
                {
                    u16 v = *sc_trans_src;
                    *sc_trans_dst = v;
                }
                sc_trans_dst++;
                sc_trans_src++;
            } while ((u16)k < 32);
        }
        src += 0x200;
        sc_trans_src = src;
        dst = sc_trans_dst = dst + 0x200;
    }
}



/* Puts a w x h block of cells from the 16-wide font sheet, starting at code, on the text layer at x, y. */
void scfont_sqput(s16 x, s16 y, u16 w, u16 h, u16 attr, s16 code) {
    u16 row;
    u16 col;

    for (row = 0; row < h; row++) {
        for (col = 0; col < w; col++) {
            tilemap_put_cell(x + col, y + row, attr, code + row * 16 + col);
        }
    }
}



/* As scfont_sqput, mirrored: the columns run right to left and the attribute gets 0x80. */
/* provisional name */
void scfont_sqput_rev(s16 x, s16 y, u16 w, u16 h, s16 attr, s16 code) {
    u16 i;
    u16 j;
    for (j = 0; j < h; j++) {
        for (i = 0; i < w; i++) {
            tilemap_put_cell(x + w - 1 - i, y + j, attr + 0x80, code + j * 16 + i);
        }
    }
}



/* Puts w x h cells on the text layer at x, y, numbered on one after another from code. */
/* provisional name */
void scfont_lnput(s16 x, s16 y, u16 w, u16 h, s16 attr, s16 code) {
    u16 row;
    u16 col;
    s16 n;

    n = 0;
    for (row = 0; row < h; row++) {
        for (col = 0; col < w; col++) {
            tilemap_put_cell(x + col, (s16)(y + row), attr, code + n);
            n++;
        }
    }
}



/* As scfont_lnput, mirrored: the columns run right to left and the attribute gets 0x80. */
/* provisional name */
void scfont_lnput_rev(s16 x, s16 y, u16 w, u16 h, s16 attr, s16 code) {
    u16 row;
    u16 col;
    s16 n;

    n = 0;
    for (row = 0; row < h; row++) {
        for (col = 0; col < w; col++) {
            tilemap_put_cell(x + w - 1 - col, y + row, attr + 0x80, code + n);
            n++;
        }
    }
}



/* provisional name */
void scfont_fill(s16 x, s16 y, u16 w, u16 h, s16 attr, s16 code) {
    u16 i;
    u16 j;
    for (j = 0; j < h; j++) {
        for (i = 0; i < w; i++) {
            tilemap_put_cell(x + i, y + j, attr, code);
        }
    }
}



void sq_paint_chenge(s16 x, s16 y, u16 w, u16 h, s16 attr) {
    u16 i;
    u16 j;
    for (j = 0; j < h; j++) {
        for (i = 0; i < w; i++) {
            sc_attr_put(x + i, y + j, attr);
        }
    }
}



/* Fills n characters of the text character RAM, from character pos, with the blank character. */
/* provisional name */
void sc_chr_clear(pos, n)
u16 pos;
u16 n;
{
    u16 i;
    u16 k;
    const u8* blank;
    sc_trans_src = sc_blank_chr;
    blank = sc_trans_src;
    sc_trans_dst = (u16*)((SS_RAM + 0x8000) + pos * 64);
    for (i = 0; i < n; i++) {
        for (k = 0; k < 16; k++) {
            *sc_trans_dst = *sc_trans_src;
            sc_trans_dst++;
            sc_trans_src++;
            *sc_trans_dst = *sc_trans_src;
            sc_trans_dst++;
            sc_trans_src++;
        }
        sc_trans_src = blank;
    }
}



/* provisional name */
void sc_chr_to_ram(u16 n) {
    s32 i;
    for (i = 0; i < n; i++) {
        *sc_bak_ptr = *sc_trans_src;
        sc_bak_ptr++;
        sc_trans_src++;
    }
}



/* provisional name */
void sc_chr_sheet_to_ram(u16 chr, u16 pos, u16 w, u16 h) {
    u16 i, j, k;
    u16 d;
    const u8* src;
    sc_trans_src = (u8*)&sc_chr_data[chr * 32 / 2];
    sc_bak_ptr = &sc_chr_ram[pos * 32];
    src = sc_trans_src;
    for (i = 0; i < h; i++) {
        for (j = 0; j < w; j++) {
            for (k = 0; k < 32; k++) {
                d = *sc_trans_src;
                *sc_bak_ptr = d;
                sc_bak_ptr++;
                sc_trans_src++;
            }
        }
        sc_trans_src = src + 0x200;
        src = sc_trans_src;
        sc_bak_ptr += 0x200;
    }
}



/* provisional name */
void sc_chr_backup(s8 restore) {
    sc_trans_dst = (u16*)(SS_RAM + 0x9E80);
    sc_bak_ptr = sc_chr_bak_1p;
    if (restore) {
        sc_chr_load(4);
    } else {
        sc_chr_save(4);
    }
    sc_trans_dst = (u16*)(SS_RAM + 0xCE80);
    sc_bak_ptr = sc_chr_bak_2p;
    if (restore) {
        sc_chr_load(4);
    } else {
        sc_chr_save(4);
    }
}



void Ranking_00_6th(s8 flag) {
    s32 n;
    if (flag) {
        sc_chr_backup(0);
    }
    sc_trans_src = (u8*)sc_chr_data;
    sc_trans_dst = (u16*)(SS_RAM + 0x8000);
    for (n = 0; n < 0x2800; n++) {
        sc_trans_word = 0;
        sc_trans_word = *sc_trans_src;
        *sc_trans_dst = sc_trans_word;
        sc_trans_dst++;
        sc_trans_src++;
    }
    if (flag) {
        sc_chr_backup(1);
    }
}



s32 ToneDown(s8 tone) {
    const TONE_ENTRY* e = &tone_down_tbl[tone];
    sc_trans_src = (u8*)sc_chr_data + e->chr * 32;
    sc_trans_dst = (u16*)((SS_RAM + 0x8000) + e->pos * 64);
    return sc_chr_trans(e->n);
}



/* provisional name */
void sc_chr_list_trans(s8 ix) {
    const u16** tbl;
    const u16* slot;
    const u16* src;
    u16 n;
    u16 i;
    tbl = (const u16**)&sc_chr_list_tbl[ix];
    slot = *tbl;
    tbl++;
    src = *tbl;
    n = *slot++;
    for (i = 0; i < n; i++) {
        sc_trans_dst = (u16*)((SS_RAM + 0x8000) + *slot++ * 64);
        sc_trans_src = (u8*)((u32)sc_chr_data + *src++ * 32);
        sc_trans_src = (u8*)sc_chr_data + (*src++ * 32 / 2) * 2;
        *sc_trans_dst = *sc_trans_src;
    }
}



/* provisional name */
void sc_chr_slot_trans(s8 ix, u16 code, s8 to_ram) {
    const u16* const* list = &sc_chr_slot_tbl[ix];
    const u16* p = *list;
    u16 n;
    u16 i;
    u16 k;
    sc_trans_src = (u8*)&sc_chr_data[code * 32 / 2];
    n = *p++;
    if (to_ram == 0) {
        for (i = 0; i < n; i++) {
            sc_trans_dst = (u16*)((SS_RAM + 0x8000) + *p++ * 64);
            for (k = 0; k < 32; k++) {
                *sc_trans_dst = *sc_trans_src;
                sc_trans_dst++;
                sc_trans_src++;
            }
        }
    } else {
        for (i = 0; i < n; i++) {
            sc_bak_ptr = sc_chr_ram + *p++ * 32;
            for (k = 0; k < 32; k++) {
                *sc_bak_ptr = *sc_trans_src;
                sc_bak_ptr++;
                sc_trans_src++;
            }
        }
    }
}



void sc_ram_to_vram(char ix, char dx, char dy) {
    const u16 **tbl;
    const u16 *pos;
    const u16 *code;
    const u16 *attr;
    u16 *cell;
    u16 n;
    u16 i;

    tbl = (const u16 **)&sc_ram_vram_tbl[ix];
    pos = *tbl;
    tbl++;
    code = *tbl;
    tbl++;
    attr = *tbl;
    n = *code++;
    if (dx == 0 && dy == 0) {
        for (i = 0; i < n; i++) {
            cell = (u16 *)(SS_RAM + *pos++);
            cell[0] = *code;
            cell[1] = ((*code++ & 0x100) >> 8) | *attr++;
        }
    } else {
        for (i = 0; i < n; i++) {
            cell = (u16 *)(SS_RAM + *pos++ + (dx << 2) + (dy << 8));
            cell[0] = *code;
            cell[1] = ((*code++ & 0x100) >> 8) | *attr++;
        }
    }
}



void sc_ram_to_vram_opc(s8 ix, s8 dx, s8 dy, u16 attr) {
    const u16** tbl;
    const u16* pos;
    const u16* code;
    u16* cell;
    u16 n;
    u16 i;

    tbl = (const u16**)&sc_ram_vram_tbl[ix];
    pos = *tbl;
    tbl++;
    code = *tbl;
    n = *code++;
    if (dx == 0 && dy == 0) {
        for (i = 0; i < n; i++) {
            cell = (u16*)(SS_RAM + *pos++);
            cell[0] = *code;
            cell[1] = ((*code++ & 0x100) >> 8) | attr;
        }
    } else {
        for (i = 0; i < n; i++) {
            cell = (u16*)(SS_RAM + *pos++ + (dx << 2) + (dy << 8));
            cell[0] = *code;
            cell[1] = ((*code++ & 0x100) >> 8) | attr;
        }
    }
}



/* provisional name */
s32 tilemap_put_cell(u16 x, u16 y, u16 attr, u16 code) {
    u16* cell = (u16*)(SS_RAM + x * 4 + y * 0x100);
    cell[0] = code;
    cell[1] = ((code & 0x100) >> 8) | attr;
}



void score8x16_put(u16 x, u16 y, u16 attr, u16 code) {
    code += 0x60;
    tilemap_put_cell(x, y, attr, code);
    tilemap_put_cell(x, y + 1, attr, code + 0x10);
}



void score16x24_put(u16 x, u16 y, u16 attr, s32 n) {
    s32 code = n * 6 + 0x140;
    tilemap_put_cell(x, y, attr, code);
    tilemap_put_cell(x + 1, y, attr, code + 1);
    tilemap_put_cell(x, y + 1, attr, code + 2);
    tilemap_put_cell(x + 1, y + 1, attr, code + 3);
    tilemap_put_cell(x, y + 2, attr, code + 4);
    tilemap_put_cell(x + 1, y + 2, attr, code + 5);
}



/* provisional name */
void sc_celllist_put(u8 ix) {
    const CELL_ENTRY* const* tbl = sc_celllist_tbl + ix;
    const CELL_ENTRY* p = *tbl;
    u16 x;
    for (x = p->x; x != 100; x = p->x) {
        tilemap_put_cell(p->x, p->y, p->attr, p->code);
        p++;
    }
}



/* provisional name */
void sc_celllist_put_scr(u8 ix) {
    const CELL_ENTRY* const* tbl = sc_celllist_tbl + ix;
    s8 k = sc_celllist_scr_tbl[ix];
    const CELL_ENTRY* p = *tbl;
    u16 x;
    for (x = p->x; x != 100; x = p->x) {
        tilemap_put_cell(DE_X[k] + p->x, p->y, p->attr, p->code);
        p++;
    }
}



/* provisional name */
void sc_celllist_put_pos(u8 kind, u8 dx, u8 dy) {
    const CELL_ENTRY* const* tbl = sc_celllist_tbl + kind;
    s8 k = sc_celllist_scr_tbl[kind];
    const CELL_ENTRY* p = *tbl;
    u16 x;
    for (x = p->x; x != 100; x = p->x) {
        tilemap_put_cell(DE_X[k] + p->x + dx, p->y + dy, p->attr, p->code);
        p++;
    }
}



/* provisional name */
void sc_attr_put(u16 x, u16 y, u16 attr) {
    u16* cell = (u16*)(SS_RAM + x * 4 + y * 0x100);
    cell[1] = (cell[1] & 1) | attr;
}



/* provisional name */
void player_name_trans(void) {
    u16 i;
    sc_trans_dst = (u16*)(SS_RAM + 0x8D40);
    if (Game_setting.Screen_Mode == 0) {
        if (Country == 1) {
            for (i = 0; i < 2; i++) {
                sc_trans_src = (u8*)((u32)sc_chr_data + ((My_char[i] & 0x7F) * 4 + i * 68 + 0x408) * 32);
                sc_chr_trans(4);
                sc_trans_dst = (u16*)(SS_RAM + 0x8E80);
            }
            return;
        }
        for (i = 0; i < 2; i++) {
            if ((My_char[i] & 0x7F) == PL_GOUKI1 || (My_char[i] & 0x7F) == PL_GOUKI2) {
                sc_trans_src = (u8*)((u32)sc_chr_data + (16 * 4 + i * 68 + 0x408) * 32);
            } else {
                sc_trans_src = (u8*)&sc_chr_data[((My_char[i] & 0x7F) * 4 + i * 68 + 0x408) * 16];
            }
            sc_chr_trans(4);
            sc_trans_dst = (u16*)(SS_RAM + 0x8E80);
        }
        return;
    }
    if (Country == 1) {
        for (i = 0; i < 2; i++) {
            sc_trans_src = (u8*)((u32)sc_chr_data + ((My_char[i] & 0x7F) * 5 + i * 85 + 0x500) * 32);
            sc_chr_trans(5);
            sc_trans_dst = (u16*)(SS_RAM + 0x8E80);
        }
        return;
    }
    for (i = 0; i < 2; i++) {
        if ((My_char[i] & 0x7F) == PL_GOUKI1 || (My_char[i] & 0x7F) == PL_GOUKI2) {
            sc_trans_src = (u8*)((u32)sc_chr_data + (16 * 5 + i * 85 + 0x500) * 32);
        } else {
            sc_trans_src = (u8*)((u32)sc_chr_data + ((My_char[i] & 0x7F) * 5 + i * 85 + 0x500) * 32);
        }
        sc_chr_trans(5);
        sc_trans_dst = (u16*)(SS_RAM + 0x8E80);
    }
}



void player_name(void) {
    u16 i;
    u16 x1;
    s16 y1;
    u16 x2;
    s16 y2;
    player_name_trans();
    if (Game_setting.Screen_Mode == 0) {
        x1 = 8;
        y1 = 3;
        x2 = 36;
        y2 = 3;
    } else {
        x1 = 10;
        y1 = 3;
        x2 = 47;
        y2 = 3;
    }
    for (i = 0; i < Game_setting.Screen_Mode + 4; i++) {
        tilemap_put_cell(x1 + i, y1, 2, i + 53);
    }
    for (i = 0; i < Game_setting.Screen_Mode + 4; i++) {
        tilemap_put_cell(x2 + i, y2, 2, i + 58);
    }
}



/* provisional name */
void sa_number_trans(void) {
    sc_trans_dst = (u16*)(SS_RAM + 0xCB80);
    sc_trans_src = (u8*)&sc_chr_data[(Super_Arts[0] * 2 + 0x900) * 16];
    sc_chr_trans(2);
    sc_trans_dst = (u16*)(SS_RAM + 0xCF80);
    sc_trans_src = (u8*)&sc_chr_data[(Super_Arts[1] * 2 + 0x900) * 16];
    sc_chr_trans(2);
}



/* provisional name */
void stun_mark_put(s8 pl) {
    u16 i;
    const s16* pos = &smark_pos_tbl[My_char[pl] & 0x7F][pl][Game_setting.Screen_Mode];
    s16 code = smark_kind_tbl[My_char[pl] & 0x7F] * 4;
    for (i = 0; i < smark_kind_tbl[My_char[pl] & 0x7F] + 4; i++) {
        tilemap_put_cell(*pos + i, 3, 18, code + i + 33);
    }
}



/* Puts count cells of a player's max mark on text row 26 beside the player's super art gauge; mark picks the
   six-cell set. */
void max_mark_write(char side, s16 left, u16 count, s32 x, char mark) {
    u16 i;

    for (i = 0; i < count; i++) {
        if (side == 0) {
            tilemap_put_cell(x + i + 5, 26, 20, mark * 6 + i + 42);
        } else {
            tilemap_put_cell(DE_X[18] - left + x + i + 43, 26, 20, mark * 6 + i + 42);
            if (0) {
            }
        }
    }
}



/* Copies the six font characters of max mark n into player pl's area of the text character RAM. */
/* provisional name */
void max_mark_chr_trans(pl, n)
s8 pl;
s16 n;
{
    sc_trans_dst = (u16*)((SS_RAM + 0xB400) + pl * 0x400);
    sc_trans_src = (u8*)sc_chr_data + ((n * 6 + 0x680) << 5);
    sc_chr_trans(6);
}



/* Clears the text-layer cells from x0, y0 to x1, y1 inclusive to blanks with attribute 0. */
/* provisional name */
void tilemap_clear_rect(x0, y0, x1, y1)
u32 x0;
u32 y0;
u32 x1;
u32 y1;
{
    u16 *line;
    u16 row;
    u16 col;

    line = (u16 *)(SS_RAM + (u16)x0 * 4 + (u16)y0 * 0x100);
    for (row = 0; row < (u16)y1 - (u16)y0 + 1; row++) {
        for (col = 0; col < (u16)x1 - (u16)x0 + 1; col++) {
            line[col * 2] = 0x20;
            line[col * 2 + 1] = 0;
        }
        line += 0x80;
    }
}



/* Clears text rows 25 to 27, the super art frame rows. */
void Sa_frame_Clear(void) {
    tilemap_clear_rect(0, 0x19, 0x37, 0x1B);
}



/* provisional name */
void sc_picture_put(u8 ix, s8 dx, s8 dy) {
    sc_trans_dst = (u16*)(SS_RAM + 0xE000);
    sc_trans_src = (u8*)sc_chr_data + picture_chr_tbl[ix] * 32;
    sc_chr_trans(128);
    sc_ram_to_vram_opc(picture_set_tbl[ix], dx + Game_setting.Screen_Mode * 7, dy, picture_attr_tbl[ix]);
}



/* provisional name */
void bcount_digit_trans(u8 mode, u16 top, u16 bottom) {
    sc_trans_src = (u8*)(sc_chr_data + top * 64 + 0xA000);
    switch (mode) {
    case 0:
        sc_trans_dst = (u16*)(SS_RAM + 0xBC00);
        sc_chr_trans(4);
        break;
    case 1:
        sc_bak_ptr = &sc_chr_ram[0x1E00];
        sc_chr_to_ram(128);
        break;
    }
    sc_trans_src = (u8*)(sc_chr_data + bottom * 64 + 0xA280);
    switch (mode) {
    case 0:
        sc_trans_dst = (u16*)(SS_RAM + 0xBD00);
        sc_chr_trans(4);
        break;
    case 1:
        sc_bak_ptr = &sc_chr_ram[0x1E80];
        sc_chr_to_ram(128);
        break;
    }
}



/* provisional name */
void sa_stock_chr_trans(s8 pl, s16 n) {
    sc_trans_dst = (u16*)((SS_RAM + 0xB500) + pl * 0x400);
    sc_trans_src = (u8*)(sc_chr_data + n * 64 + pl * 768 + 0x9100);
    sc_chr_trans(4);
}



/* provisional name */
void sa_max_level_trans(row, col)
s8 row;
s16 col;
{
    sc_trans_dst = (u16*)((SS_RAM + 0xB400) + row * 0x400);
    sc_trans_src = (u8*)(sc_chr_data + col * 64 + row * 768 + 0x9700);
    sc_chr_trans(4);
}



void sa_stock_trans(s16 n, s16 ix, s8 pl) {
    s16 x;
    if (pl == 0) {
        sa_stock_chr_trans(0, n);
        if (Game_setting.Screen_Mode == 0) {
            x = 1;
        } else {
            x = 1;
        }
        tilemap_put_cell(x, 25, sa_color_data_tbl[ix], 0xD4);
        tilemap_put_cell(x + 1, 25, sa_color_data_tbl[ix], 0xD5);
        tilemap_put_cell(x, 26, sa_color_data_tbl[ix], 0xD6);
        tilemap_put_cell(x + 1, 26, sa_color_data_tbl[ix], 0xD7);
    } else {
        sa_stock_chr_trans(1, n);
        if (Game_setting.Screen_Mode == 0) {
            x = 43;
        } else {
            x = 57;
        }
        tilemap_put_cell(x, 25, sa_color_data_tbl[ix], 0xE4);
        tilemap_put_cell(x + 1, 25, sa_color_data_tbl[ix], 0xE5);
        tilemap_put_cell(x, 26, sa_color_data_tbl[ix], 0xE6);
        tilemap_put_cell(x + 1, 26, sa_color_data_tbl[ix], 0xE7);
    }
}



void sa_fullstock_trans(s8 side, s16 ix) {
    s16 x;
    if (side == 0) {
        if (Game_setting.Screen_Mode == 0) {
            x = 3;
        } else {
            x = 3;
        }
        tilemap_put_cell(x, 25, sa_color_data_tbl[ix], 0xD0);
        tilemap_put_cell(x + 1, 25, sa_color_data_tbl[ix], 0xD1);
        tilemap_put_cell(x, 26, sa_color_data_tbl[ix], 0xD2);
        tilemap_put_cell(x + 1, 26, sa_color_data_tbl[ix], 0xD3);
    } else {
        if (Game_setting.Screen_Mode == 0) {
            x = 45;
        } else {
            x = 59;
        }
        tilemap_put_cell(x, 25, sa_color_data_tbl[ix], 0xE0);
        tilemap_put_cell(x + 1, 25, sa_color_data_tbl[ix], 0xE1);
        tilemap_put_cell(x, 26, sa_color_data_tbl[ix], 0xE2);
        tilemap_put_cell(x + 1, 26, sa_color_data_tbl[ix], 0xE3);
    }
}



/* provisional name */
void win_mark_put(s16 pl, u16 n, s16 attr) {
    const s16* e;
    sc_trans_src = (u8*)&sc_chr_data[n * 32] + 0xBDC0;
    sc_trans_dst = (u16*)((SS_RAM + 0x8400) + pl * 128);
    sc_chr_trans(2);
    e = &vmark_tbl[pl * 6];
    tilemap_put_cell(e[0] + DE_X[3], e[1], attr, e[2]);
    tilemap_put_cell(e[3] + DE_X[3], e[4], attr, e[5]);
}



/* provisional name */
void win_mark_ram_clear(void) {
    u16 i;
    u8* dst;
    for (i = 0, dst = &sc_chr_ram[0x200]; i < 8; i++) {
        u32 src;
        src = (u32)sc_chr_data, sc_trans_src = (u8*)(src + 0xBDC0);
        sc_bak_ptr = dst;
        sc_chr_to_ram(64);
        dst += 64;
    }
}



/* provisional name */
void win_mark_find_put(s16 x, s16 y, s16 pl) {
    s16 round = win_mark_find(pl);
    const s16* mark;
    if (round == -1) {
        cpu_hang_forever();
    }
    mark = &vmark_tbl[pl * 24 + round * 6];
    tilemap_put_cell(x, y, 14, mark[2]);
    tilemap_put_cell(x + 1, y, 14, mark[5]);
}



/* provisional name */
s32 win_mark_find(s16 pl) {
    s16 i;
    for (i = 0; i < Game_setting.Battle_Number + 1; i++) {
        if (win_type[pl][i] == WIN_MARK_PERFECT) {
            return i;
        }
    }
    return -1;
}



void naming_set(s8 pl, s16 place, u16 chr) {
    sc_trans_src = (u8*)&sc_chr_data[chr * 16] + 0x7000;
    if (pl == 0) {
        sc_trans_dst = (u16*)(place * 64 + (SS_RAM + 0x9E80));
    } else {
        sc_trans_dst = (u16*)(place * 64 + (SS_RAM + 0xCE80));
    }
    sc_chr_trans(1);
}



/* provisional name */
void rank_mark_set(s8 row, s8 n) {
    sc_trans_src = (u8*)&sc_chr_data[n * 32] + 0x7600;
    if (row == 0) {
        sc_trans_dst = (u16*)(SS_RAM + 0x9A80);
    } else {
        sc_trans_dst = (u16*)(SS_RAM + 0x9B00);
    }
    if (Escape_SS == 0) {
        sc_chr_trans(2);
    } else {
        sc_bak_ptr = &sc_chr_ram[row * 64] + 0xD40;
        sc_chr_to_ram(64);
    }
}



/* provisional name */
void winner_name_put(s8 ch) {
    const NAME_PLATE* p = &nwdata_tbl[ch];
    if (Country == 1) {
        sc_chr_block_trans(p->cell, 0x180, p->w, p->h);
    } else {
        if (ch == PL_GOUKI1 || ch == PL_GOUKI2) {
            p = &nwdata_tbl[16];
        }
        sc_chr_block_trans(p->cell, 0x180, p->w, p->h);
    }
    sc_chr_block_trans(0x1458, 0x1C0, 13, 4);
    scfont_sqput(DE_X[3] + p->x, p->y, p->w, p->h, 44, 0x180);
    scfont_sqput(p->x2 + DE_X[3], p->y2, 13, 4, 44, 0x1C0);
}



/* provisional name */
void player_face_char_set(pl)
s8 pl;
{
    if ((My_char[1] & 0x7F) == PL_GILL && pl == 1) {
        sc_chr_slot_trans(1, 0x350, 0);
    } else {
        sc_chr_slot_trans(pl, (My_char[pl] & 0x7F) * 21 + 0x200, 0);
    }
    if (Game_setting.Screen_Mode != 0) {
        sc_trans_dst = (u16*)((SS_RAM + 0xC900) + pl * 0x400);
        if ((My_char[1] & 0x7F) == PL_GILL && pl == 1) {
            sc_trans_src = (u8*)gill_face_wide_chr;
        } else {
            sc_trans_src = (u8*)&sc_chr_data[((My_char[pl] & 0x7F) * 6 + 0x680) * 16];
        }
        sc_chr_trans(6);
    }
}



/* provisional name */
void player_face_default_set(s8 pl) {
    col_dma_request(0x027D0AA0 + Player_Color[pl] * 32, 0x3FC00 + pl * 0x200, 32, 0, 0, 0);
    sc_chr_slot_trans(pl, 0x33B, 1);
    if (Game_setting.Screen_Mode != 0) {
        sc_trans_dst = (u16*)((SS_RAM + 0xC900) + pl * 0x400);
        sc_trans_src = (u8*)default_face_wide_chr;
        sc_chr_trans(6);
    }
}



void player_face(void) {
    player_face_char_set(0);
    player_face_char_set(1);
    col_dma_request(0x027CFD80 + (My_char[0] & 0x7F) * 0xE0 + Player_Color[0] * 32, 0x3FC00, 32, 0, 0, 0);
    col_dma_request(0x027CFD80 + (My_char[1] & 0x7F) * 0xE0 + Player_Color[1] * 32, 0x3FE00, 32, 0, 0, 0);
    if (Game_setting.Screen_Mode == 0) {
        sc_ram_to_vram(0, 0, 0);
        sc_ram_to_vram(1, 0, 0);
    } else {
        sc_ram_to_vram(14, 0, 0);
        sc_ram_to_vram(15, 0, 0);
    }
}



/* Puts the SF3 logo, a block of font cells, on the text layer below row y. */
u32 SF3_logo(s16 y) {
    sc_chr_clear(384, 128);
    scfont_sqput(DE_X[3] + 16, y + 10, 16, 6, 12, 384);
}



/* provisional name */
void break_into_banner_trans(sel, kind)
s8 sel;
s16 kind;
{
    if (sel) {
        switch (kind) {
        case 0:
            sc_chr_clear(320, 192);
            sc_ram_to_vram_opc(17, Game_setting.Screen_Mode * 7, Text_Page_Y, 56);
            break;
        default:
            sc_trans_src = (u8*)&sc_chr_data + (kind - 1) * 3 * 32 + 0x2A400;
            sc_trans_dst = (u16*)((SS_RAM + 0xD000) + (kind - 1) * 3 * 64);
            sc_chr_trans(3);
            break;
        }
    } else {
        switch (kind) {
        case 0:
            sc_chr_clear(320, 192);
            sc_ram_to_vram_opc(16, Game_setting.Screen_Mode * 7, Text_Page_Y, 58);
            break;
        default:
            sc_trans_src = (u8*)&sc_chr_data + (kind - 1) * 3 * 32 + 0x29200;
            sc_trans_dst = (u16*)((SS_RAM + 0xD000) + (kind - 1) * 3 * 64);
            sc_chr_trans(3);
            break;
        }
    }
}



void combo_message_set(s8 pl, s8 kind) {
    const u16* fr = combo_mtbl[kind].v;
    s16 y = pl * 2 + 30;
    sc_chr_sheet_trans(fr[0], pl * 32 + 0x140, fr[1], fr[2]);
    scfont_sqput(combo_mpos_tbl[kind][pl], y, fr[1], fr[2], 14, pl * 32 + 0x140);
    tilemap_put_cell(combo_mclr_pos_tbl[kind][pl], y, 22, 32);
    tilemap_put_cell(combo_mclr_pos_tbl[kind][pl], y + 1, 22, 32);
}



/* provisional name */
void combo_hitnum_set(s8 pl, s8 kind, u16 hits) {
    s16 x = combo_hitpos_tbl[kind][pl];
    s16 y = pl * 2 + 30;
    u16 tens = hits / 10;
    u16 ones = hits - tens * 10;
    if (tens != 0) {
        tilemap_put_cell(x, y, 16, tens + 96);
        tilemap_put_cell(x, y + 1, 16, tens + 112);
    } else {
        tilemap_put_cell(x, y, 16, 32);
        tilemap_put_cell(x, y + 1, 16, 32);
    }
    tilemap_put_cell(x + 1, y, 16, ones + 96);
    tilemap_put_cell(x + 1, y + 1, 16, ones + 112);
    tilemap_put_cell(x + 2, y, 16, 32);
    tilemap_put_cell(x + 2, y + 1, 16, 32);
}



s16 combo_pts_set(s8 PL, u32 pts) {
    u32 number = pts;
    s16 digit[4];
    s16 i;
    s16 first;
    s32 div;
    u16 x;
    s16 y;
    s16 y2;
    s16 x2;
    div = 100000;
    first = -1;
    for (i = 3; i >= 0; i--, div = div / 10) {
        digit[i] = number / div;
        number -= digit[i] * div;
        if (first < 0) {
            if (digit[i] != 0) {
                first = i;
            }
        }
    }
    x = (15 - first) * PL;
    y = PL * 2 + 34;
    for (i = first; i >= 0; i--, x++) {
        score8x16_put(x, y, 16, digit[i]);
    }
    score8x16_put(x, y, 16, 0);
    score8x16_put(x + 1, y, 16, 0);
    tilemap_put_cell(x + 2, y, 42, 32);
    tilemap_put_cell(x + 2, y2 = y + 1, 42, 0x104);
    tilemap_put_cell(x + 3, y, 42, 32);
    tilemap_put_cell(x + 3, y2, 42, 0x105);
    if (PL == 0) {
        tilemap_put_cell(x2 = x + 4, y, 22, 32);
        tilemap_put_cell(x2, y2, 22, 32);
    } else {
        tilemap_put_cell(x2 = 14 - first, y, 22, 32);
        tilemap_put_cell(x2, y2, 22, 32);
    }
    return first + 6;
}



/* provisional name */
void combo_window_slide(s8 pl, s16 x, s16 y, s16 n) {
    u32* src = (u32*)(SS_RAM + ((y * 4 + pl * 2 + 30) << 8) + ((pl * 19) << 2));
    u32* dst = (u32*)(x * 4 + y * 0x300 + (SS_RAM + 0x700));
    s32 d;
    u16 i;
    d = (pl == 0) ? 1 : -1;
    for (i = 0; i < n + 1; i++) {
        dst[0] = src[0];
        *(u32*)((s32)dst + 0x100) = src[0x40];
        dst += d;
        src += d;
    }
}



/* provisional name */
void combo_window_erase(s8 col, s8 kind, s16 row) {
    u32* cell = (u32*)((SS_RAM + 0x700) + combo_erase_pos_tbl[Game_setting.Screen_Mode][kind][col] * 4 + row * 0x300);
    u16 i;
    for (i = 0; i < combo_erase_len_tbl[kind]; i++) {
        cell[0] = 0x200000;
        cell[0x40] = 0x200000;
        cell++;
    }
}



/* provisional name */
void combo_window_all_clear(void) {
    if (Game_setting.Screen_Mode == 0) {
        tilemap_clear_rect(0, 7, 20, 9);
        tilemap_clear_rect(0, 10, 18, 11);
        tilemap_clear_rect(27, 7, 47, 9);
        tilemap_clear_rect(29, 10, 47, 11);
    } else {
        tilemap_clear_rect(0, 7, 24, 11);
        tilemap_clear_rect(37, 7, 61, 11);
    }
}



/* provisional name */
void sc_vram_to_ram(void) {
    sc_trans_dst = (u16*)(SS_RAM + 0x8000);
    sc_bak_ptr = sc_chr_ram;
    sc_chr_save(0x200);
}
