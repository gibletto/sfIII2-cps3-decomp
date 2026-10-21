/*
 * EFFA6_WORK.C  effect work
 *
 * Cleared work RAM (section B) of effects A6 and B0.
 */

#include "types.h"
#include "structs.h"

static u8 effa6_spare[8];  /* nothing in the program refers to it */
s16 mmes_already;  /* 0206449C */
u8 mmes_already_tail[2];  /* after mmes_already; nothing refers to it by name or address */
s16 END_OF_B0;  /* 020644A0 */
