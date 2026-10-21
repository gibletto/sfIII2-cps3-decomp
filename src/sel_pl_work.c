/*
 * SEL_PL_WORK.C  character select work
 *
 * Cleared work RAM (section B). A <name>_tail table holds the bytes between <name> and the next
 * named variable.
 */

#include "types.h"
#include "structs.h"

s16 SEL_PL_X;  /* 020159E4 */
s16 Sel_Arts_Pos[2];  /* 020159E6 */
u16* Demo_Ptr[2];  /* 020159EC */
u8 Demo_Ptr_tail[8];  /* after Demo_Ptr; nothing refers to it by name or address */
s8 Sel_Char_Shot[2];  /* 020159FC */
u16 Sel_Command_Sw;  /* 020159FE */
