/*
 * SOUND_WORK.C  sound driver work
 *
 * The sound driver's voices, envelopes and settings: cleared work RAM (section B), the last of
 * it.
 */

#include "types.h"
#include "structs.h"

const u16* snd_attack_ptr;  /* 020731B8 */
const u16* snd_decay_ptr;  /* 020731BC */
const u16* snd_lfo_rate_ptr;  /* 020731C0 */
const u16* snd_pitch_lfo_ptr;  /* 020731C4 */
const u16* snd_vol_lfo_ptr;  /* 020731C8 */
SNDSAMPLE* snd_sample_tbl;  /* 020731CC */
u8** snd_bank_tbl;  /* 020731D0 */
u32 snd_fade_level;  /* 020731D4 */
u32 snd_fade_speed;  /* 020731D8 */
SNDVOICE bgm_voice[16];  /* 020731DC */
SNDVOICE se_voice[16];  /* 0207391C */
SNDRAMP se_pan_ramp[16];  /* 0207405C */
/* added to every music voice's pitch (sound_reg_level_set) */
s16 bgm_pitch_offset;  /* 020740DC */
u16 snd_wave_bias;  /* 020740DE */
SOUND_CTRL snd_ctrl;  /* 020740E0 */
u16 bgm_tick_step;  /* 020740E4 */
u16 se_tick_step[16];  /* 020740E6 */
/* the music's volume offset; -128 silences it (sound_reg_level_set) */
s8 bgm_volume_offset;  /* 02074106 */
u8 bgm_master_vol;  /* 02074107 */
u8 snd_master_vol;  /* 02074108 */
u8 snd_stereo;  /* 02074109 */
