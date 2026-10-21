#include "EM_Cand.h"

/*
 * EM_CAND.C  Combo demo setup and CPU opponent candidate lists
 *
 * Combo_Demo_Init prepares a combo-demo round (allows the battle, clears player-control steps and
 * Suicide, points both demo input streams at the current demo's data) and Setup_Combo_Demo_PL
 * (called from PLCNTAPP) loads both players' character, super art and colour from the combo demo
 * table.
 * Initialize_EM_Candidate (from sel_pl) builds a player's candidate buffer and fills the two CPU
 * opponent candidate lists for stages 1-8, sets the rival for stage 9 and clears stage 10.
 * Check_EM_Buff and Check_Same_CPU are the helpers that avoid repeated or duplicate opponents.
 * All_Clear_Suicide clears the eight Suicide (effect kill) flags; it is used when screens and
 * fights start (Manage, next_cpu, sel_pl, Win). clear_chainex_check clears a player's
 * chain-combo check table.
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"

/* file-local view: sel_pl.c reads the same table as s8 */
extern const u8 EM_Candidate_Data[16][4][8];
#include "extern.h"
#include "VITAL.h"
#include "count.h"
#include "PLCNTDAT.h"
#include "plcntdat_2.h"
#include "HITCHECK.h"
#include "PLS02.h"


/* provisional name */
/* 2i 060849C4, 3s-reloc: sf3 src/EM_Cand.c:32 Combo_Demo_Init */
void Combo_Demo_Init(void) {
    Demo_Lever_Play = 255;
    Allow_a_battle_f = 1;
    Game_pause = 0;
    Suicide = 0;
    round_timer.size.full = 1;
    pcon_rno[0] = 0;
    pcon_rno[1] = 0;
    pcon_rno[2] = 0;
    pcon_rno[3] = 0;
    appear_type = 0;
    Demo_Ptr[0] = Combo_Demo_Lever_Data[(u8)Get_Demo_Index][0];
    Demo_Ptr[1] = Combo_Demo_Lever_Data[(u8)Get_Demo_Index][1];
    clear_hit_queue();
    vital_cont_init();
    set_kizetsu_status(0);
    set_kizetsu_status(1);
}


/* provisional name */
/* 2i 06084A3A, 3s-reloc: sf3 src/EM_Cand.c:54 Setup_Combo_Demo_PL */
void Setup_Combo_Demo_PL(void) {
    s8* p = combo_demo_pl_tbl[Get_Demo_Index];
    My_char[0] = *p++;
    Super_Arts[0] = *p++;
    Player_Color[0] = *p++;
    My_char[1] = *p++;
    Super_Arts[1] = *p++;
    Player_Color[1] = *p;
}


/* provisional name */
/* 2i 06084A6C, 3s-reloc: sf3 src/EM_Cand.c:67 stage_index_get */
s32 stage_index_get(void) {
    s32 stage = bg_w.stage;
    s32 next = stage + 1;
    if (stage == 8) {
        if (bg_w.area != 0) {
            return next;
        } else {
            return stage;
        }
    }
    if (stage < 8) {
        return stage;
    }
    return next;
}


/* 2i 06084A98, inferred: sf3 src/EM_Cand.c:85 Initialize_EM_Candidate */
void Initialize_EM_Candidate(s16 PL_id, s16 set) {
    s16 ix;
    for (ix = 0; ix < 8; ix++) {
        EM_Candidate[PL_id][ix] = EM_Candidate_Data[My_char[PL_id]][set][ix];
    }
}


