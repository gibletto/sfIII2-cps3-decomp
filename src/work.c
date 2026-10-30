/*
 * WORK.C  system settings work
 *
 * The free-running timer tick, the system and game settings that start the game with a value, and the
 * register names of the exception display. The boot code copies the image of every object's
 * initialised work RAM from ROM to work RAM 02000000-0200873B (section D); this object links first, so
 * its variables start that area. A <name>_tail table holds the initial values of the bytes between
 * <name> and the next named variable.
 */

#include "types.h"
#include "structs.h"

extern const char str_R0[];
extern const char str_R10[];
extern const char str_R11[];
extern const char str_R12[];
extern const char str_R13[];
extern const char str_R14[];
extern const char str_R1[];
extern const char str_R2[];
extern const char str_R3[];
extern const char str_R4[];
extern const char str_R5[];
extern const char str_R6[];
extern const char str_R7[];
extern const char str_R8[];
extern const char str_R9[];
extern const char str_SP[];

/* provisional name */
u32 frt_tick_count = 0;  /* 02000000 */
s8 Coin_Mode = 0;  /* 02000004 */
s8 Monitor_Flip = 0;  /* 02000005 */
s8 Continue_Flag = 0;  /* 02000006 */
s8 Chute_Mode = 0;  /* 02000007 */
s8 Sound_Mode = 0;  /* 02000008 */
s8 Demo_Sound = 0;  /* 02000009 */
/* 0200000A */
/* Stored after Demo_Sound. Nothing in the program refers to it by name or address. */
u8 Demo_Sound_tail[1] = {
    0,
};

s8 Language = 0;  /* 0200000B */
s8 Free_Play = 0;  /* 0200000C */
u8 Card_Dispenser = 0;  /* 0200000D */
s8 Win_Point_Com = 0;  /* 0200000E */
s8 Win_Point_Human = 0;  /* 0200000F */
s8 Voice_Type = 0;  /* 02000010 */
s8 Win_Point_Com_Max = 8;  /* 02000011 */
s8 Win_Point_Human_Max = 30;  /* 02000012 */
s8 Win_Point_Com_Min = 2;  /* 02000013 */
s8 Win_Point_Human_Min = 2;  /* 02000014 */
s8 Win_Point_Split = 0;  /* 02000015 */
s8 Cabinet_Type = 0;  /* 02000016 */
s8 Area_Type = 0;  /* 02000017 */
s8 Area_Alt_Flag = 0;  /* 02000018 */
s8 Two_Coin_Start = 0;  /* 02000019 */
s8 Free_Play_Enable = 0;  /* 0200001A */
/* 0200001B */
/* Stored after Free_Play_Enable. Nothing in the program refers to it by name or address. */
u8 Free_Play_Enable_tail[2] = {
    0, 0,
};

s8 Cd_Error_Flag = 0;  /* 0200001D */
s16 Config_No_0 = 0;  /* 0200001E */
s16 Config_No_1 = 0;  /* 02000020 */
s16 Config_No_2 = 0;  /* 02000022 */
/* 02000024 */
const char* reg_name_tbl[16] = {
    str_R0, str_R1, str_R2, str_R3, str_R4, str_R5, str_R6, str_R7,
    str_R8, str_R9, str_R10, str_R11, str_R12, str_R13, str_R14, str_SP,
};
