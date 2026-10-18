# 2nd Impact struct layouts

`sf2i/include/structs.h` is 3rd Strike's `structs.h` with the struct definitions changed to 2nd Impact's layout.
Every change rests on code: the near routines' 3s listing (our SHC, source lines kept) aligned with their 2i
instructions, registers simulated as base + offset, and each paired memory access attributed to the fields the
3s source line names (`scratch/si2hdr/pairs.py`, round 2). A field keeps its 3s name when 2i's code uses the same
offset role; fields only 2i has get provisional names (marked `/* provisional name */` in the header, listed
below). Offsets are hexadecimal, 2i's.

## Sizes

| Struct | 3s | 2i |
|---|---|---|
| WORK | 3B8 | 350 |
| PLW | 498 | 40C |
| WORK_Other | 3F0 | 388 |
| WORK_Other_CONN | 7A0 | 738 |
| WORK_Other_JUDGE | 53C | 4A4 |
| WORK_B6 | 608 | 5A0 |
| HAND_BOX, ATTACK_BOX | 20 | 10 |
| CharGfxEntry | 8 | C |

PLW's size is seen directly: `plw[1]` fields sit at 40C + their offset (bg_sub_2 scr_10_21, PLCNT2 plcnt_b_move,
PLCNTDAT setup_base_and_other_data, ...).

## WORK

| Change | 2i offsets | Evidence |
|---|---|---|
| 4 of the 5 CHAR_CMDs after cmb3 gone (cmhs, cmr0-cmr3; the census has no cmhs routine in 2i) | cmr0 142 | cmwk at 14A, not 16A (CHARMOVE command routines) |
| cmwk is s16[16] (3s [32]; no 3s index exceeds 15) | cmwk 14A, my_bright_type 16A | char_table 16C, se_random_table .. old_cgnum all at 3s - 40 (CHARID set_char_base_data, CHARMOVE, ...) |
| done_flip, done_rl before spr; cg_ofs_x inside spr after a halfword; sprite_flip a halfword; floor gone | done_flip 1F6, done_rl 1F7, spr 1F8: spr_free0 +0, cg_ofs_x +2, cg_ofs_y +4, sprite_flip +6 | aboutspr trans_char_cells, make_char_cells_x/y, sort_push_request2/3, EFFE7/EFFE8/EFFJ0 (sprite_flip read as a word) |
| HIT_IX, box sizes: see below | hit_ix_table 248, cg_ja 24C, body_adrs .. att_ix_table 25C..298 (3s - 40) | CHARMOVE set_jugde_area |
| jump_att_flag, shell_vs_refrect gone | renew_attack 2C4 | dm_* fields at 3s - 42 (HITCHECK same_dm_stop, PLMAIN check_hit_stop, ...); every 3s user of jump_att_flag is census-absent |
| K5_init_flag, K5_exec_ok gone | kow 326 | CHARMOVE char_move_wca_init, char_move_index_set store nothing there |
| tail: 41 bytes after kow (3s: swallow_no_effect, E3/E4_work_index, kezurare_flag, wrd_free, wrd_free2) | wrd_free 327 | size 350 (PLW.cp at 350, WORK_Other.my_master at 350); no paired access in 327-34F |

## PLW

Everything up to auto_guard keeps 3s order at 3s - 68, except:

| Change | 2i offset | Evidence |
|---|---|---|
| permited_koa is a byte where 3s has tc_1st_flag | 3C1 | PLS03ATT check_nm_attack, check_chouhatsu, check_lever_up_attack, check_renda_cancel, Com_Sub Provoke, ... (byte or, byte loads) |
| tc_1st_flag and all of hsjp_ok .. pad5 gone; 24 bytes after auto_guard | pt_free 3F4 | size 40C; the 2i versions of clear_tk_flags (att_plus/def_plus), nm_17000 (high_jump_flag), Normal_16000/18000 (extra_jump, bs2, air_jump_ok_time), Player_move (metamor_over), setup_any_data (gill_ccch_go), add_sp_arts_gauge_init (metamorphose), check_meoshi_cancel (tc_1st_flag), effect_E5_move (kind_of_blocking) drop the accesses |

## Hit boxes and attack records

| Struct | 2i layout | Evidence |
|---|---|---|
| HIT_IX (16 bytes) | boix +0, haix +2, ix2_free +4, caix +6, cuix +8, atix +A, eaix +C, hoix +E; 3s bhix and mf gone | set_jugde_area: h_bod = body_adrs + boix*32, h_han = hand_adrs + [+2]*16, h_cat = catch_adrs + [+6]*8, h_cau = caught_adrs + [+8]*8, h_att = attack_adrs + [+A]*16, h_eat = attack_adrs + [+C]*16, h_hos = hosei_adrs + [+E]*8; PLCNTDAT check_combo_end (cuix), EFF13 check_tengu_attack (atix) |
| HAND_BOX | s16 hand_dm[2][4] (16 bytes) | h_han stride 16 |
| ATTACK_BOX | s16 att_box[2][4] (16 bytes) | h_att, h_eat stride 16; si2data: 2 boxes per row |
| CATCH_BOX, CAUGHT_BOX, HOSEI_BOX, BODY_BOX | unchanged | strides 8, 8, 8, 32 |
| ATTACK_ATTR (16 bytes) | u16 reaction +0, mkh_ix +2, dipsw +3, at_free4 +4, dir +5, u16 guard +6, pow +8, impact +9, piyo +A, ng_type +B, hs_me +C, hs_you +D, hit_mark +E, dmg_mark +F; 3s level, but_ix, free gone | HITCHECK setup_dm_rl, set_caught_status (reaction read as an unsigned halfword), cal_hit_mark_pos (mkh_ix), same_dm_stop (dipsw & 1, hs_me), PLS02 cal_attdir (dir), EFFE5 get_attdata_of_illusion (guard stored as a halfword, pow, piyo, hs_you); si2data: the level sits in the reaction halfword's high nibble |

set_caught_status tests 3s dipsw's bits (0x40, 0x20) on 2i's +4 with other masks (0x80, 0x40), so dipsw/at_free4
is the one assignment with code on both sides; same_dm_stop's `dipsw & 1` decides it.

## Others

| Struct | Change | Evidence |
|---|---|---|
| SA_WORK | exsa_g_ix +2, nmsa_g_ix +3, exsa_a_ix +4, nmsa_a_ix +5; exs2_g_ix, exs2_a_ix gone; everything from gauge_type to gauge_len at 3s - 2 (gauge at 18 again); size 2C | PLS03 check_super_arts_attack (nmsa_*), check_full_gauge_attack (exsa_*), PLCNTDAT set_super_arts_status, clear_super_arts_point, PLMAIN sag_normal, demo_set_sa_full, spgauge, Com_Sub (ok at 8) |
| CharGfxEntry (CG directory) | 12 bytes: x, y, cge_free +4, set +8 | aboutspr get_cg_slot_no, load_char_gfx, purge_char_gfx, trans_char_cells, ... (index * 12, set at +8); si2data: 12-byte entries |
| WORK_Other_JUDGE | ja[54][2], jx[13][4] (13 boxes, 3s 15: 2 hand and 2 attack boxes fewer) | aboutspr set_judge_area_sprite reads fade_cja at 4A0 (3s - 98 after WORK's - 68) |
| BG, BGW, SETTINGS, MVXY, WORK_Other, WORK_Other_CONN, WORK_B6 | unchanged apart from the embedded WORK | paired accesses agree at the same offsets |

## Provisional names

| Struct | Field | 2i offset | Note |
|---|---|---|---|
| WORK | cmr0 | 142 | one CHAR_CMD where 3s has five; no paired access |
| WORK | wrd_free | 327 | 41 bytes after kow; no paired access |
| PLW | pt_free | 3F4 | 24 bytes after auto_guard; no paired access |
| CHAR_SPR_WORK | spr_free0 | +0 (WORK 1F8) | a halfword before cg_ofs_x; no paired access |
| HIT_IX | ix2_free | +4 | no reader; si2data: always 0 in the fighter tables |
| HIT_IX | eaix | +C | h_eat's attack-box index (set_jugde_area); si2data: 0 in the tables |
| ATTACK_ATTR | at_free4 | +4 | set_caught_status tests bits 0x80, 0x40 of it |
| CharGfxEntry | cge_free | +4 | a word before the set pointer; no paired access |

## Proving them

`tools/hdr2i.py fit` builds every 3s module with a header set at each function's 2i address mod 4 (the
SHC_ALIGN_FILE pads re-fitted to the build until every placed function has 2i's parity) and `levels` compares
each near, changed and exact/reloc routine with 2i (tools/near2i.py): level 2 = exact or reloc in place, level 1
= the same instructions and pool values with the pool placed elsewhere (a module-layout difference), level 0
neither. 3s source that names a member 2i lacks is compiled through measurement-only aliases and sed edits (round
2 scratch); those routines need source changes anyway. `pairs` gives the offset votes the changes come from.

With the 3s headers -> with these (`levels`): near, near-moved and changed routines (2,591) at level 2 265 -> 581,
at level 1 or 2 466 -> 889; si2cc's const-class near routines (724 of near.tsv's 741 are single census routines)
37 -> 305 at level 2, 44 -> 401 at level 1 or 2; exact/reloc routines at level 2 3,912 -> 3,940, none lost.

Ablation (the final set minus one change, against the final set): routines that drop a level without the change,
and routines that gain one.

| Change | Unlocked | Broken |
|---|---|---|
| WORK: CHAR_CMDs, cmwk[16] | 445 | 0 |
| WORK: jump_att_flag, shell_vs_refrect | 44 | 0 |
| WORK: K5 flags and tail | 281 | 0 |
| HIT_IX | 1 | 0 |
| HAND_BOX, ATTACK_BOX 16 bytes | 0 | 0 |
| PLW | 73 | 0 |
| ATTACK_ATTR | 3 | 0 |
| sprite region | 4 | 0 |
| SA_WORK | 13 | 0 |
| CharGfxEntry | 3 | 0 |
| WORK_Other_JUDGE | 0 | 0 |

The box sizes stand on set_jugde_area's strides (a routine that needs source changes); the judge-box count stands
on one access (fade_cja), the weakest change here.
