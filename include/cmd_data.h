/*
 * CMD_DATA.H  Command records: the format of the pl_cmd_list tables
 *
 * Each fighter has 56 command slots (pl_cmd_list).  A slot's record is an array of s16:
 *
 *   header (CMD_HEAD_WORDS words, copied into WORK_CP by cmd_data_set)
 *     reset         frames a completed command stays set in waza_flag, waiting for its move to
 *                   start (command_ok_move counts it down); CMD_RESET for most records, 10 for
 *                   the parries, 8 for the dashes
 *     dead, dead2   input words (sw_new: the lever and buttons held this frame) which abandon
 *                   the command, while it is entered and while it waits (dead_lvr_check);
 *                   0: none.  CMD_LV_UP: holding up (a jump) drops a special move
 *     rno[4]        routine_no[2] of the move started by each strength (hissatsu_setup_union)
 *     btix          button word and flags, CMD_BT_*
 *     exdt[4]       button required for each strength, CMD_EX_*; the fourth is the EX version
 *
 *   steps (4 words each; check_init and check_next load them into the slot's WAZA_WORK)
 *     ck            the check routine, CK_*: an index into chk_move_jp
 *     time          w_int: frames allowed (counted down before each test)
 *     prm           free1 and free2: a count or time, as each check routine reads it
 *     sw            w_lvr: the lever or button word the step waits for
 *
 *   CMD_END after the last step.
 *
 * Lever words are relative to the facing direction (pl_lvr_set swaps left and right).
 * CMD_LV_EXACT asks for exactly the low four lever bits; without it a step accepts any of the
 * given bits (CK_LEVER: on a new lever press), and 0 asks for neutral.  An exact diagonal is a
 * valid request.
 */

#ifndef CMD_DATA_H
#define CMD_DATA_H

#define CMD_SLOTS       56          /* command slots per fighter */
#define CMD_SA_GROUND   20          /* first slot of the ground super arts */
#define CMD_SP_GROUND   28          /* first slot of the ground special moves */
#define CMD_SA_AIR      38          /* first slot of the air super arts */
#define CMD_SP_AIR      46          /* first slot of the air special moves */
#define CMD_HEAD_WORDS  12
#define CMD_RESET       12          /* reset: the usual wait for the move to start */

/* lever bits of the command input words */
#define CMD_LV_NEUTRAL  0x0000
#define CMD_LV_UP       0x0001
#define CMD_LV_DOWN     0x0002
#define CMD_LV_FORWARD  0x0004
#define CMD_LV_BACK     0x0008
#define CMD_LV_MASK     0xF
#define CMD_LV_EXACT    0x8000      /* step word: the lever must be exactly the low four bits */

/* button bits of the command input words (SHOT1-SHOT6) */
#define CMD_SW_LP       0x0010
#define CMD_SW_MP       0x0020
#define CMD_SW_HP       0x0040
#define CMD_SW_PP       0x0080      /* two or three punches pressed or let go together */
#define CMD_SW_LK       0x0100
#define CMD_SW_MK       0x0200
#define CMD_SW_HK       0x0400
#define CMD_SW_KK       0x0800      /* the same for the kicks */
#define CMD_SW_PUNCH    0x70
#define CMD_SW_KICK     0x700
#define CMD_SW_SHOT     0x770       /* all six buttons */
#define CMD_LVSW_ALL    0x77F   /* the lever and all six buttons */

/* check routines (chk_move_jp) */
#define CK_INIT          0  /* check_init: reload the first step */
#define CK_LEVER         1  /* check_0: the lever word within time */
#define CK_CHARGE        2  /* check_1: hold the lever prm frames, then let go */
#define CK_HOLD          3  /* check_2: hold all the buttons prm frames, then let go */
#define CK_SHOT_HOLD     4  /* check_3: let go of sw buttons, each held time frames */
#define CK_RENDA         5  /* check_4: one punch (sw = CMD_SW_LP) or kick five times */
#define CK_PRESS         6  /* check_5: press exactly sw */
#define CK_TURN          7  /* check_6: up, down, forward and back, each within 14 frames */
#define CK_SHOT_P        8  /* check_7 for the punches */
#define CK_SHOT_K        9  /* check_7 for the kicks */
#define CK_LEVER_CHANGE 10  /* check_9: the next lever change must be sw */
#define CK_PARRY        11  /* check_10: tap the lever to sw (parry) */
#define CK_BACK_DOWN    12  /* check_11: back, then down */
#define CK_AIR_PARRY    13  /* check_12: tap the lever to sw in the air */
#define CK_UKEMI        14  /* check_13: recovery (ukemi) input; command_ok keeps it active */
#define CK_RENDA3       15  /* check_14: three punch (sw = CMD_SW_LP) or kick presses in time */
#define CK_LEVER_COUNT  16  /* check_15: the lever word on prm frames within time */
#define CK_PRESS_P      17  /* check_16 for the punches: sw of them pressed */
#define CK_PRESS_K      18  /* check_16 for the kicks */
#define CK_LEVER_REPEAT 19  /* check_18: set the command each time the lever is moved to sw */
#define CK_LEVER_SET    20  /* check_19: set the command and go on to the next step */
#define CK_NONE         21  /* check_20: never completes */
#define CK_LEVER_PRESS  22  /* check_21: the lever moved to sw within time */
#define CK_ROTATE       23  /* check_22: all eight directions within time */
#define CK_PARRY_STRICT 24  /* check_23: parry tap which a wrong direction abandons */
#define CK_LEVER_NEW    25  /* check_24: newly pressed lever bits within time */
#define CK_LEVER_HELD   26  /* check_25: the lever word within time, no new press needed */
#define CK_LEVER_OFF    27  /* check_26: move the lever to sw and away again */
#define CMD_END         28

/* btix: low byte, the WORK_CP switch word (as a u16 index) tested for the button */
#define CMD_BT_OLD      2           /* sw_old */
#define CMD_BT_NOW      3           /* sw_now */
#define CMD_BT_CHG      5           /* sw_chg */
#define CMD_BT_NONE     0x80        /* no button (an air special starts strength 0) */
#define CMD_BT_INDEX    0xFF
/* btix flags */
#define CMD_BT_ALWAYS   0x100       /* also taken by check_full_gauge_attack's always pass */
#define CMD_BT_FOURTH   0x200       /* the fourth strength may be used */
#define CMD_BT_EX       0x400       /* the fourth strength is an EX move and uses the EX gauge */
#define CMD_BT_STRENGTH4 0x600      /* either */
#define CMD_BT_SHELL    0x800       /* not while the fighter's projectile is alive */

/* exdt: the button for each strength, an index into cmdshot_conv_tbl */
#define CMD_EX_LP       0
#define CMD_EX_MP       1
#define CMD_EX_HP       2
#define CMD_EX_PP       3
#define CMD_EX_LK       4
#define CMD_EX_MK       5
#define CMD_EX_HK       6
#define CMD_EX_KK       7
#define CMD_EX_BUTTON   0xF         /* the button, without CMD_EX_ALONE */
#define CMD_EX_ALONE    16          /* and no other button (PP, KK: none of the other group) */

#define CMD_EX_ONLY(ex)         (CMD_EX_ALONE | (ex))

/* the usual strength sets: S, M, L and the two-button EX version */
#define CMD_EX_PUNCHES  CMD_EX_LP, CMD_EX_MP, CMD_EX_HP, CMD_EX_ONLY(CMD_EX_PP)
#define CMD_EX_KICKS    CMD_EX_LK, CMD_EX_MK, CMD_EX_HK, CMD_EX_ONLY(CMD_EX_KK)

/* rno[4] when every strength starts the same routine (each fighter's routine names are in cmd_data.c) */
#define CMD_WAZA(rno)           (rno), (rno), (rno), (rno)
#define CMD_WAZA_EX(rno, ex)    (rno), (rno), (rno), (ex)   /* the EX version has its own routine */

#define CMD_EXACT(lv)           (s16)(CMD_LV_EXACT | (lv))
#define CMD_STEP(ck, time, prm, sw)     (ck), (time), (prm), (sw)
#define CMD_LEVER(time, lv)     CK_LEVER, (time), 0, CMD_EXACT(lv)
#define CMD_LEVER_ANY(time, lv) CK_LEVER, (time), 0, (lv)

#endif
