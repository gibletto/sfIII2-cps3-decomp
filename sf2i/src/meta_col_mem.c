/*
 * meta_col_mem.c  memset and strcat
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "textsound.h"
#include "textsound_2.h"
#include "textsound_3.h"
#include "meta_col_mem.h"
#include "cps3.h"



/* 2i 060ED6C0, 3s-exact: sf3 src/meta_col_mem.c:17 memset */
u8 *memset(dst, c, n)
u8 *dst;
u8 c;
u32 n;
{
    u32 i;
    u8 *p;

    p = dst;
    for (i = 0; i < n; i++) {
        *p++ = c;
    }
    return dst;
}



/* 2i 060ED6D8, 3s-reloc: sf3 src/meta_col_mem.c:34 strcat */
char* strcat(char* dst, const char* src) {
    u8* p = (u8*)dst;
    const u8* s = (const u8*)src;
    for (; *p != 0; p++) {
    }
    while ((*p++ = *s++) != 0) {
    }
    return dst;
}
