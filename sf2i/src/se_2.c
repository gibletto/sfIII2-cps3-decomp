/*
 * SE_2.C  Screen wipe patterns and sound request routines (part 2)
 *
 * Routines: wipe_pattern_and_low, wipe_and_row, wipe_and_dot, wipe_mask_set_cols,
 * wipe_mask_and_cols.
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "textsound.h"
#include "textsound_2.h"
#include "textsound_3.h"
#include "bg_sub.h"
#include "bg_sub_2.h"
#include "bg_sub_3.h"
#include "bg_sub_4.h"
#include "bg_sub_5.h"
#include "se_3.h"
#include "se_2.h"
#include "cps3.h"


/* provisional name */
/* 2i 060825BC, 3s-exact: sf3 src/se_2.c:26 mix_put_step */
void mix_put_step(void) {
    *wipe_dst_ptr = *wipe_back_ptr | *wipe_pat_ptr;
    wipe_dst_ptr++;
    wipe_pat_ptr++;
    wipe_back_ptr++;
}

/* provisional name */
/* 2i 060825E8, 3s-exact: sf3 src/se_2.c:34 wipe_pattern_and_low */
void wipe_pattern_and_low(s16 kind, s16 row) {
    s16 x;
    s16 y;
    wipe_pat_top = wipe_clear_pattern_tbl[kind].adr;
    wipe_pat_top += row * 32;
    wipe_dst_ptr = (u16*)(SS_RAM + 0xD000);
    for (y = 0; y < 144; y++) {
        wipe_pat_ptr = wipe_pat_top;
        for (x = 0; x < 32; x++) {
            *wipe_dst_ptr = *wipe_pat_ptr & *wipe_dst_ptr;
            wipe_dst_ptr++;
            wipe_pat_ptr++;
        }
    }
}



/* provisional name */
/* 2i 0608266E, 3s-exact: sf3 src/se_2.c:53 wipe_and_row */
void wipe_and_row(void) {
    s32 j;
    wipe_pat_ptr = wipe_pat_top;
    for (j = 0; j < 32; j++) {
        *wipe_dst_ptr = *wipe_pat_ptr & *wipe_dst_ptr;
        wipe_dst_ptr++;
        wipe_pat_ptr++;
    }
}



/* provisional name */
/* 2i 060826BA, 3s-reloc: sf3 src/se_2.c:66 wipe_and_dot */
void wipe_and_dot(void) {
    *wipe_dst_ptr = *wipe_pat_ptr & *wipe_dst_ptr;
    wipe_dst_ptr++;
    wipe_pat_ptr++;
}



/* provisional name */
/* 2i 060826F8, 3s-exact: sf3 src/se_2.c:75 wipe_mask_set_cols */
void wipe_mask_set_cols(s16 kind, s16 row) {
    s16 x;
    s16 y;
    s16 i;
    u8* src;
    u8* map;
    u32 dst;
    u8* mask;
    src = wipe_column_tbl[kind].adr;
    src += wipe_column_tbl[kind].w * row;
    map = wipe_set_pattern_tbl[kind].adr;
    map += row * 32;
    dst = (SS_RAM + 0xE000);
    mask = wipe_mask_chr;
    for (i = 0; i < 6; i++) {
        for (y = 0; y < 16; y++) {
            for (x = 0; x < wipe_column_tbl[kind].w; x++) {
                *(u16*)(dst + src[x] * 2U) = (mask[src[x]] & map[src[x]]);
            }
            dst += 64;
            mask += 32;
        }
    }
}



/* provisional name */
/* 2i 0608279A, 3s-reloc: sf3 src/se_2.c:103 wipe_mask_and_cols */
void wipe_mask_and_cols(s16 kind, s16 row) {
    s16 x;
    s16 y;
    s16 i;
    u8* src;
    u8* map;
    u16* dst;
    src = wipe_column_tbl[kind].adr;
    src += wipe_column_tbl[kind].w * row;
    map = wipe_clear_pattern_tbl[kind].adr;
    map += row * 32;
    dst = (u16*)(SS_RAM + 0xE000);
    for (i = 0; i < 6; i++) {
        for (y = 0; y < 16; y++) {
            for (x = 0; x < wipe_column_tbl[kind].w; x++) {
                dst[src[x]] &= map[src[x]];
            }
            dst += 32;
        }
    }
}
