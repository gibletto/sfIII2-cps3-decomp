/*
 * CRAM_BANK.C  Character RAM bank switching
 *
 * The character RAM is reached through a window at CHARACTER_RAM selected by the bank register
 * at (VIDEO_REG + 0x86). cram_bank_init resets it to bank 0; cram_bank_set selects a bank and
 * remembers the previous one; cram_bank_restore swaps back to the previous bank.
 * cram_bank_addr selects the 1 MB bank holding a linear offset and returns its address in
 * the window, and cram_bank_slot_offset does the same for a 4 KB slot number.
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "cram_bank.h"
#include "cps3.h"



s16 cram_bank_old;  /* 02079C94 */
s16 cram_bank_now;  /* 02079C96 */


/* provisional name */
/* 2i 060FB230, 3s-exact: sf3 src/cram_bank.c:25 cram_bank_init */
void cram_bank_init(void) {
    *(volatile s16*)(VIDEO_REG + 0x86) = 0;
    cram_bank_old = 0;
    cram_bank_now = 0;
}



/* provisional name */
/* 2i 060FB246, 3s-reloc: sf3 src/cram_bank.c:34 cram_bank_set */
s16 cram_bank_set(s16 bank) {
    if (cram_bank_now == bank) {
        return cram_bank_now;
    }
    cram_bank_old = cram_bank_now;
    cram_bank_now = bank;
    (*(volatile u16*)(VIDEO_REG + 0x86)) = bank & 15;
    return cram_bank_old;
}



/* provisional name */
/* 2i 060FB298, 3s-exact: sf3 src/cram_bank.c:47 cram_bank_restore */
s16 cram_bank_restore(void) {
    s16 prev;
    if (cram_bank_old == cram_bank_now) {
        return cram_bank_now;
    }
    prev = cram_bank_now;
    cram_bank_now = cram_bank_old;
    (*(volatile u16*)(VIDEO_REG + 0x86)) = cram_bank_now & 15;
    cram_bank_old = prev;
    return prev;
}



/* provisional name */
/* 2i 060FB2D8, 3s-reloc: sf3 src/cram_bank.c:62 cram_bank_addr */
u32 cram_bank_addr(s32 offset) {
    s16 bank;
    bank = (offset / 0x100000) & 15;
    if (cram_bank_now != bank) {
        cram_bank_old = cram_bank_now;
        cram_bank_now = bank;
        (*(volatile u16*)(VIDEO_REG + 0x86)) = bank & 15;
    }
    return (offset & 0xFFFFF) + CHARACTER_RAM;
}



/* provisional name */
/* 2i 060FB344, 3s-exact: sf3 src/cram_bank.c:76 cram_bank_slot_offset */
u32 cram_bank_slot_offset(s16 slot) {
    s16 bank;
    bank = ((slot - 1) / 256) & 15;
    if (cram_bank_now != bank) {
        cram_bank_old = cram_bank_now;
        cram_bank_now = bank;
        (*(volatile u16*)(VIDEO_REG + 0x86)) = bank & 15;
    }
    return ((slot - 1) << 12) & 0xFFFFF;
}


/* provisional name */
/* 2i 060FB39C, 3s-reloc: sf3 src/cram_bank.c:89 cram_bank_now_get */
s16 cram_bank_now_get(void) {
    return cram_bank_now;
}


/* provisional name */
/* 2i 060FB3C0, 3s-reloc: sf3 src/cram_bank.c:95 cram_bank_old_get */
s16 cram_bank_old_get(void) {
    return cram_bank_old;
}
