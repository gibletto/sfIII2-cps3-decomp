/*
 * CD_VOLUME.C  the CD-ROM's volume identifier (sections CDVOL, 067FFFE0, and CDVOL2, 06FFFFE0)
 *
 * The self test reads the CD's primary volume descriptor and compares its volume identifier with the
 * first 11 characters of the copy at 067FFFE0. The program holds the identifier twice, at the end of
 * each 8 MB half of the program ROM; the bytes after it hold FF. The last halfword differs between the
 * two copies; nothing in the program reads it.
 */

#include "types.h"

#pragma section CDVOL

const s8 game_volume_id[12] = "CAP-3GA-1   ";
/* provisional name */
const u8 game_volume_fill[18] = {
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF,
};
const u16 game_volume_word = 0x2CD4;

#pragma section CDVOL2

/* provisional name */
const s8 game_volume_id_2[12] = "CAP-3GA-1   ";
/* provisional name */
const u8 game_volume_fill_2[18] = {
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF,
};
/* provisional name */
const u16 game_volume_word_2 = 0x8448;
