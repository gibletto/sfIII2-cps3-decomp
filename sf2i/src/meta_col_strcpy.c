/*
 * meta_col_strcpy.c  strcpy
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "textsound.h"
#include "textsound_2.h"
#include "textsound_3.h"
#include "meta_col_strcpy.h"
#include "cps3.h"



/* 2i 060ED6F8, 3s-reloc: sf3 src/meta_col_strcpy.c:17 strcpy */
char* strcpy(char* dst, const char* src) {
    return _builtin_strcpy(dst, src);
}
