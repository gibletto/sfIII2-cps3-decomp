/*
 * meta_col_bcd.c  BCD helpers used for scores and counters: hex_to_bcd (binary to BCD), abcd and sbcd (BCD add and
 * subtract)
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "textsound.h"
#include "textsound_2.h"
#include "textsound_3.h"
#include "meta_col_bcd.h"
#include "cps3.h"



s16 bcdext;  /* 020644E0 */


/* provisional name */
u32 hex_to_bcd(u32 dat) {
    u32 sum = 0;
    u8* bcd = (u8*)&sum;
    const u8* p = bcd_weight_end;
    u32 mask;
    p--;
    for (mask = 0x8000; mask > 0; mask = mask >> 1) {
        if (dat & mask) {
            bcdext = 0;
            bcd[3] = abcd(bcd[3], *p);
            p--;
            bcd[2] = abcd(bcd[2], *p);
            p--;
            bcd[1] = abcd(bcd[1], *p);
            p--;
            bcd[0] = abcd(bcd[0], *p);
            p--;
        } else {
            p -= 4;
        }
    }
    return sum;
}



/* provisional name */
u8 abcd(u8 a, u8 b) {
    u16 d;
    if ((d = (bcdext & 1) + (a & 0xF) + (b & 0xF)) > 9) {
        d -= 10;
        d |= 0x10;
    }
    if ((d += (a & 0xF0) + (b & 0xF0)) > 0x99) {
        d -= 0xA0;
        d &= 0xFF;
        bcdext = 1;
    } else {
        bcdext = 0;
    }
    return d;
}


u8 sbcd(u8 a, u8 b) {
    s16 c, d;
    if ((d = (b & 0xF) - (a & 0xF) - (bcdext & 1)) < 0) {
        d += 10;
        d |= 0x10;
    }
    c = (b & 0xF0) - (a & 0xF0) - (d & 0xF0);
    d &= 0xF;
    if ((d |= c) < 0) {
        d += 160;
        bcdext = 1;
    } else {
        bcdext = 0;
    }
    return d;
}

/* provisional name */
u8 nbcd(u8 a) {
    s8 c, d;
    if ((d = 0 - (bcdext & 1) - (a & 0xF)) < 0) {
        d += 2;
        d |= 0x10;
    }
    c = 0 - (a & 0xF0) - (d & 0xF0);
    d |= c;
    if ((d & 0xF0) > 0) {
        d += 48;
        bcdext = 1;
    } else {
        bcdext = 0;
    }
    return d;
}
