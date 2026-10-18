/*
 * SPR_POOL_2.C  SIMM RAM slot address helpers
 *
 * Conversions from a SIMM RAM slot number to its page offset, address and character code, and the
 * X shift of a sprite list.
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "sys_config.h"
#include "sys_config_2.h"
#include "sys_config_3.h"
#include "cps3.h"

/* provisional name */
/* 2i 060F7F28, 3s-exact: sf3 src/spr_pool_2.c:18 simmram_slot_to_page_offset */
u32 simmram_slot_to_page_offset(s16 slot) {
    return (slot - 1) << 8;
}


/* provisional name */
/* 2i 060F7F42, 3s-exact: sf3 src/spr_pool_2.c:24 simmram_slot_addr */
u32 simmram_slot_addr(s16 slot) {
    return ((slot - 1) << 8) + (SPRITE_RAM + 0x2000);
}



/* provisional name */
/* 2i 060F7F60, 3s-reloc: sf3 src/spr_pool_2.c:31 simmram_slot_to_code */
u16 simmram_slot_to_code(s16 n) {
    return (u16)(n - 1) * 0x10 + 0x200;
}



/* provisional name */
/* 2i 060F7F8E, 3s-reloc: sf3 src/spr_pool_2.c:38 sprite_list_shift_x */
void sprite_list_shift_x(SPR16* dst, SPR16* src, s16 dx, s32 n) {
    do {
        *dst = *src;
        dst->x += dx;
        src++;
        dst++;
    } while (--n);
}
