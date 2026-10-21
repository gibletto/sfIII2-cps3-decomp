/*
 * SE_DATA.C  what each sound request number does
 *
 * A script frame's sound field or CM_SSE names a number s (bit 0x800: a pick from the character's
 * se_random table); sound_effect_request[s] is the routine that plays it (se_3.c), called with s. Each
 * plays only while sound is on (Demo_Sound, Demo_Flag) and the combo demonstration has not muted it:
 *   Call_Se        sound code s: a sound every character shares
 *   Se_Myself      the character's own sound: s + its side * 0x200 (player 2's copy), panned to its position;
 *                  from 0x140 Check_Voice_SE swaps in the alternate voice set when Voice_Type is set
 *                  (Voice_SE_Data)
 *   Se_Myself_Die  the same without the voice swap, unless the character is already knocked out
 *   Se_Let         the same as Se_Myself, for the character or the effect it owns
 *   Se_Let_SP      the same without the voice swap; on a KO 0x14B and 0x13A play 0x158 and 0x15A
 *   Se_Shock       a hit: the same without the voice swap, plus 0x27 (its KO version) when the hit knocks
 *                  the opponent out and s is not one of SE_Shock_Data
 *   Se_Term        the same as Se_Myself, unless the character is falling at a height of 64 or less
 *   Se_Dummy       nothing
 */

#include "types.h"
#include "structs.h"

#pragma section TBL

extern void Call_Se();
extern void Se_Dummy();
extern void Se_Let();
extern void Se_Let_SP();
extern void Se_Myself();
extern void Se_Myself_Die();
extern void Se_Shock();
extern void Se_Term();

void (*const sound_effect_request[784])() = {
    Call_Se,       Call_Se,       Call_Se,       Call_Se,       Call_Se,       Call_Se,       Call_Se,       Call_Se,  /* 0x000 */
    Call_Se,       Call_Se,       Call_Se,       Call_Se,       Call_Se,       Call_Se,       Call_Se,       Call_Se,  /* 0x008 */
    Call_Se,       Call_Se,       Call_Se,       Call_Se,       Call_Se,       Call_Se,       Call_Se,       Call_Se,  /* 0x010 */
    Call_Se,       Call_Se,       Call_Se,       Call_Se,       Call_Se,       Call_Se,       Call_Se,       Call_Se,  /* 0x018 */
    Call_Se,       Call_Se,       Call_Se,       Call_Se,       Call_Se,       Call_Se,       Call_Se,       Call_Se,  /* 0x020 */
    Call_Se,       Call_Se,       Call_Se,       Call_Se,       Call_Se,       Call_Se,       Call_Se,       Call_Se,  /* 0x028 */
    Call_Se,       Call_Se,       Call_Se,       Call_Se,       Call_Se,       Call_Se,       Call_Se,       Call_Se,  /* 0x030 */
    Call_Se,       Call_Se,       Call_Se,       Call_Se,       Call_Se,       Call_Se,       Call_Se,       Call_Se,  /* 0x038 */
    Call_Se,       Call_Se,       Call_Se,       Call_Se,       Call_Se,       Call_Se,       Call_Se,       Call_Se,  /* 0x040 */
    Call_Se,       Call_Se,       Call_Se,       Call_Se,       Call_Se,       Call_Se,       Call_Se,       Call_Se,  /* 0x048 */
    Call_Se,       Call_Se,       Call_Se,       Call_Se,       Call_Se,       Call_Se,       Call_Se,       Call_Se,  /* 0x050 */
    Call_Se,       Call_Se,       Call_Se,       Call_Se,       Call_Se,       Call_Se,       Call_Se,       Call_Se,  /* 0x058 */
    Call_Se,       Call_Se,       Call_Se,       Call_Se,       Call_Se,       Call_Se,       Call_Se,       Call_Se,  /* 0x060 */
    Call_Se,       Call_Se,       Call_Se,       Call_Se,       Call_Se,       Call_Se,       Call_Se,       Call_Se,  /* 0x068 */
    Call_Se,       Call_Se,       Call_Se,       Call_Se,       Call_Se,       Call_Se,       Call_Se,       Call_Se,  /* 0x070 */
    Call_Se,       Call_Se,       Call_Se,       Call_Se,       Call_Se,       Call_Se,       Call_Se,       Call_Se,  /* 0x078 */
    Call_Se,       Call_Se,       Call_Se,       Call_Se,       Call_Se,       Call_Se,       Call_Se,       Call_Se,  /* 0x080 */
    Call_Se,       Call_Se,       Call_Se,       Call_Se,       Call_Se,       Call_Se,       Call_Se,       Call_Se,  /* 0x088 */
    Call_Se,       Call_Se,       Call_Se,       Call_Se,       Call_Se,       Call_Se,       Call_Se,       Call_Se,  /* 0x090 */
    Call_Se,       Call_Se,       Call_Se,       Call_Se,       Call_Se,       Call_Se,       Call_Se,       Call_Se,  /* 0x098 */
    Call_Se,       Call_Se,       Call_Se,       Call_Se,       Call_Se,       Call_Se,       Call_Se,       Call_Se,  /* 0x0A0 */
    Se_Let,        Se_Let,        Call_Se,       Call_Se,       Call_Se,       Call_Se,       Call_Se,       Call_Se,  /* 0x0A8 */
    Call_Se,       Call_Se,       Call_Se,       Call_Se,       Call_Se,       Call_Se,       Call_Se,       Call_Se,  /* 0x0B0 */
    Call_Se,       Call_Se,       Call_Se,       Call_Se,       Call_Se,       Call_Se,       Call_Se,       Call_Se,  /* 0x0B8 */
    Call_Se,       Call_Se,       Call_Se,       Call_Se,       Call_Se,       Call_Se,       Call_Se,       Call_Se,  /* 0x0C0 */
    Call_Se,       Call_Se,       Call_Se,       Call_Se,       Call_Se,       Call_Se,       Call_Se,       Call_Se,  /* 0x0C8 */
    Call_Se,       Call_Se,       Call_Se,       Call_Se,       Call_Se,       Call_Se,       Call_Se,       Call_Se,  /* 0x0D0 */
    Call_Se,       Call_Se,       Call_Se,       Call_Se,       Call_Se,       Call_Se,       Call_Se,       Call_Se,  /* 0x0D8 */
    Call_Se,       Call_Se,       Call_Se,       Call_Se,       Call_Se,       Call_Se,       Call_Se,       Call_Se,  /* 0x0E0 */
    Call_Se,       Call_Se,       Call_Se,       Call_Se,       Call_Se,       Call_Se,       Call_Se,       Call_Se,  /* 0x0E8 */
    Call_Se,       Call_Se,       Call_Se,       Call_Se,       Call_Se,       Call_Se,       Call_Se,       Call_Se,  /* 0x0F0 */
    Call_Se,       Call_Se,       Call_Se,       Call_Se,       Call_Se,       Call_Se,       Call_Se,       Call_Se,  /* 0x0F8 */
    Se_Shock,      Se_Shock,      Se_Shock,      Se_Shock,      Se_Shock,      Se_Shock,      Se_Shock,      Se_Shock,  /* 0x100 */
    Se_Let,        Se_Let,        Se_Let,        Se_Let,        Se_Let,        Se_Myself,     Se_Myself,     Se_Shock,  /* 0x108 */
    Se_Let,        Se_Let,        Se_Myself,     Se_Let,        Se_Let,        Se_Myself,     Se_Myself,     Se_Myself,  /* 0x110 */
    Se_Myself,     Se_Myself,     Se_Myself,     Se_Let,        Se_Myself,     Se_Shock,      Se_Shock,      Se_Shock,  /* 0x118 */
    Se_Shock,      Se_Shock,      Se_Let,        Se_Let,        Se_Let,        Se_Let,        Se_Let,        Se_Dummy,  /* 0x120 */
    Se_Dummy,      Se_Dummy,      Se_Dummy,      Se_Dummy,      Se_Dummy,      Se_Dummy,      Se_Dummy,      Se_Let,  /* 0x128 */
    Se_Let,        Se_Let,        Se_Let,        Se_Let,        Se_Let,        Se_Let,        Se_Let,        Se_Let,  /* 0x130 */
    Se_Let,        Se_Let,        Se_Let,        Se_Let,        Se_Let,        Se_Let,        Se_Let,        Se_Let,  /* 0x138 */
    Se_Myself,     Se_Myself,     Se_Let,        Se_Let,        Se_Myself,     Se_Myself,     Se_Myself,     Se_Myself,  /* 0x140 */
    Se_Myself,     Se_Myself,     Se_Myself,     Se_Let_SP,     Se_Myself,     Se_Myself,     Se_Myself,     Se_Let,  /* 0x148 */
    Se_Myself,     Se_Myself,     Se_Myself,     Se_Let,        Se_Let,        Se_Let,        Se_Myself,     Se_Let,  /* 0x150 */
    Se_Myself,     Se_Myself,     Se_Myself,     Se_Myself,     Se_Myself,     Se_Let,        Se_Myself,     Se_Let,  /* 0x158 */
    Se_Myself,     Se_Myself,     Se_Myself_Die, Se_Myself_Die, Se_Myself,     Se_Myself,     Se_Myself,     Se_Myself,  /* 0x160 */
    Se_Myself,     Se_Myself,     Se_Myself,     Se_Myself,     Se_Myself,     Se_Myself,     Se_Myself_Die, Se_Myself_Die,  /* 0x168 */
    Se_Myself,     Se_Myself,     Se_Myself,     Se_Myself,     Se_Myself,     Se_Myself,     Se_Myself,     Se_Myself,  /* 0x170 */
    Se_Myself,     Se_Myself_Die, Se_Myself_Die, Se_Myself,     Se_Myself,     Se_Myself,     Se_Myself,     Se_Myself,  /* 0x178 */
    Se_Myself,     Se_Term,       Se_Myself,     Se_Myself,     Se_Myself,     Se_Myself_Die, Se_Myself_Die, Se_Myself,  /* 0x180 */
    Se_Myself,     Se_Myself,     Se_Myself,     Se_Myself,     Se_Term,       Se_Myself,     Se_Myself,     Se_Myself,  /* 0x188 */
    Se_Myself,     Se_Myself,     Se_Myself_Die, Se_Myself_Die, Se_Myself,     Se_Myself,     Se_Myself,     Se_Myself,  /* 0x190 */
    Se_Myself,     Se_Myself,     Se_Myself,     Se_Myself,     Se_Myself,     Se_Myself,     Se_Myself_Die, Se_Myself_Die,  /* 0x198 */
    Se_Myself,     Se_Myself,     Se_Myself,     Se_Myself,     Se_Myself,     Se_Myself,     Se_Myself,     Se_Myself,  /* 0x1A0 */
    Se_Myself,     Se_Myself,     Se_Myself_Die, Se_Myself_Die, Se_Myself,     Se_Myself,     Se_Myself,     Se_Myself,  /* 0x1A8 */
    Se_Myself,     Se_Myself,     Se_Myself,     Se_Myself,     Se_Myself,     Se_Myself,     Se_Myself_Die, Se_Myself_Die,  /* 0x1B0 */
    Se_Myself,     Se_Myself,     Se_Myself,     Se_Myself,     Se_Myself,     Se_Myself,     Se_Myself,     Se_Myself,  /* 0x1B8 */
    Se_Myself,     Se_Myself,     Se_Myself_Die, Se_Myself_Die, Se_Myself,     Se_Myself,     Se_Myself,     Se_Myself,  /* 0x1C0 */
    Se_Myself,     Se_Myself,     Se_Myself,     Se_Myself,     Se_Myself,     Se_Myself,     Se_Myself,     Se_Myself,  /* 0x1C8 */
    Se_Myself_Die, Se_Myself_Die, Se_Myself,     Se_Myself,     Se_Myself,     Se_Myself,     Se_Myself,     Se_Myself,  /* 0x1D0 */
    Se_Myself,     Se_Myself,     Se_Myself,     Se_Myself,     Se_Myself,     Se_Myself,     Se_Myself,     Se_Myself,  /* 0x1D8 */
    Se_Myself,     Se_Myself_Die, Se_Myself_Die, Se_Myself,     Se_Myself,     Se_Myself,     Se_Let,        Se_Let,  /* 0x1E0 */
    Se_Myself,     Se_Myself,     Se_Myself,     Se_Myself,     Se_Myself,     Se_Myself,     Se_Myself_Die, Se_Myself_Die,  /* 0x1E8 */
    Se_Myself,     Se_Myself,     Se_Myself,     Se_Myself,     Se_Myself,     Se_Myself,     Se_Myself,     Se_Myself,  /* 0x1F0 */
    Se_Myself,     Se_Myself,     Se_Myself,     Se_Myself,     Se_Myself,     Se_Myself,     Se_Myself,     Se_Myself,  /* 0x1F8 */
    Se_Myself,     Se_Myself,     Se_Myself,     Se_Myself,     Se_Myself,     Se_Myself,     Se_Myself,     Se_Myself,  /* 0x200 */
    Se_Myself,     Se_Myself,     Se_Myself,     Se_Myself,     Se_Myself,     Se_Myself,     Se_Myself,     Se_Myself,  /* 0x208 */
    Se_Myself,     Se_Myself,     Se_Myself,     Se_Myself,     Se_Myself,     Se_Myself,     Se_Myself,     Se_Myself,  /* 0x210 */
    Se_Myself,     Se_Myself,     Se_Myself,     Se_Myself,     Se_Myself,     Se_Myself,     Se_Myself,     Se_Myself,  /* 0x218 */
    Se_Myself,     Se_Myself,     Se_Myself,     Se_Myself,     Se_Myself,     Se_Myself,     Se_Myself,     Se_Myself,  /* 0x220 */
    Se_Myself,     Se_Myself,     Se_Myself,     Se_Myself,     Se_Myself,     Se_Myself,     Se_Myself,     Se_Myself,  /* 0x228 */
    Se_Myself,     Se_Myself,     Se_Myself,     Se_Myself,     Se_Myself,     Se_Myself,     Se_Myself,     Se_Myself,  /* 0x230 */
    Se_Myself,     Se_Myself,     Se_Myself,     Se_Myself,     Se_Myself,     Se_Myself,     Se_Myself,     Se_Myself,  /* 0x238 */
    Se_Myself,     Se_Myself,     Se_Myself,     Se_Myself,     Se_Myself,     Se_Myself,     Se_Myself,     Se_Myself,  /* 0x240 */
    Se_Myself,     Se_Myself,     Se_Myself,     Se_Myself,     Se_Myself,     Se_Myself,     Se_Myself,     Se_Myself,  /* 0x248 */
    Se_Myself,     Se_Myself,     Se_Myself,     Se_Myself,     Se_Myself,     Se_Myself,     Se_Myself,     Se_Myself,  /* 0x250 */
    Se_Let,        Se_Let,        Se_Let,        Se_Let,        Se_Let,        Se_Let,        Se_Let,        Se_Let,  /* 0x258 */
    Se_Myself,     Se_Myself,     Se_Myself,     Se_Myself,     Se_Myself,     Se_Myself,     Se_Myself,     Se_Myself,  /* 0x260 */
    Se_Myself,     Se_Myself,     Se_Myself,     Se_Myself,     Se_Myself,     Se_Myself,     Se_Myself,     Se_Myself,  /* 0x268 */
    Se_Myself,     Se_Myself,     Se_Myself,     Se_Myself,     Se_Myself,     Se_Myself,     Se_Myself,     Se_Myself,  /* 0x270 */
    Se_Myself,     Se_Myself,     Se_Myself,     Se_Myself,     Se_Myself,     Se_Myself,     Se_Myself,     Se_Myself,  /* 0x278 */
    Se_Myself,     Se_Myself,     Se_Myself,     Se_Myself,     Se_Myself,     Se_Myself,     Se_Myself,     Se_Myself,  /* 0x280 */
    Se_Myself,     Se_Myself,     Se_Myself,     Se_Myself,     Se_Myself,     Se_Myself,     Se_Myself,     Se_Myself,  /* 0x288 */
    Se_Myself,     Se_Myself,     Se_Myself,     Se_Myself,     Se_Myself,     Se_Myself,     Se_Myself,     Se_Myself,  /* 0x290 */
    Se_Myself,     Se_Myself,     Se_Myself,     Se_Myself,     Se_Myself,     Se_Myself,     Se_Myself,     Se_Myself,  /* 0x298 */
    Se_Myself,     Se_Myself,     Se_Myself,     Se_Myself,     Se_Myself,     Se_Myself,     Se_Myself,     Se_Myself,  /* 0x2A0 */
    Se_Myself,     Se_Myself,     Se_Myself,     Se_Myself,     Se_Myself,     Se_Myself,     Se_Myself,     Se_Myself,  /* 0x2A8 */
    Se_Myself,     Se_Myself,     Se_Myself,     Se_Myself,     Se_Myself,     Se_Myself,     Se_Myself,     Se_Myself,  /* 0x2B0 */
    Se_Myself,     Se_Myself,     Se_Myself,     Se_Myself,     Se_Myself,     Se_Myself,     Se_Myself,     Se_Myself,  /* 0x2B8 */
    Se_Myself,     Se_Myself,     Se_Myself,     Se_Myself,     Se_Myself,     Se_Myself,     Se_Myself,     Se_Myself,  /* 0x2C0 */
    Se_Myself,     Se_Myself,     Se_Myself,     Se_Myself,     Se_Myself,     Se_Myself,     Se_Myself,     Se_Myself,  /* 0x2C8 */
    Se_Myself,     Se_Myself,     Se_Myself,     Se_Myself,     Se_Myself,     Se_Myself,     Se_Myself,     Se_Myself,  /* 0x2D0 */
    Se_Myself,     Se_Myself,     Se_Myself,     Se_Myself,     Se_Myself,     Se_Myself,     Se_Myself,     Se_Myself,  /* 0x2D8 */
    Se_Myself,     Se_Myself,     Se_Myself,     Se_Myself,     Se_Myself,     Se_Myself,     Se_Myself,     Se_Myself,  /* 0x2E0 */
    Se_Myself,     Se_Myself,     Se_Myself,     Se_Myself,     Se_Myself,     Se_Myself,     Se_Myself,     Se_Myself,  /* 0x2E8 */
    Se_Myself,     Se_Myself,     Se_Myself,     Se_Myself,     Se_Myself,     Se_Myself,     Se_Myself,     Se_Myself,  /* 0x2F0 */
    Se_Myself,     Se_Let,        Se_Myself,     Se_Myself,     Se_Myself,     Se_Myself,     Se_Myself,     Se_Myself,  /* 0x2F8 */
    Se_Myself,     Se_Myself,     Se_Myself,     Se_Myself,     Se_Myself,     Se_Myself,     Se_Myself,     Se_Myself,  /* 0x300 */
    Se_Myself,     Se_Myself,     Se_Myself,     Se_Myself,     Se_Myself,     Se_Myself,     Se_Myself,     Se_Let,  /* 0x308 */
};
