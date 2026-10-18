#ifndef SOUND_VOICE_2_H
#define SOUND_VOICE_2_H

#include "structs.h"

s32 sound_note_to_pitch(s32 note);
void sound_reg_write_verify(s16 *reg, u16 value);
u16 sound_voice_volume_compute(u16 level, u32 pan_scale, s8 pan, SNDVOICE* v);
void voice_process_secondary(SNDVOICE* voice, u8 voice_index, u8 is_bgm);
s32 midi_vlq_decode_leading();
s32 midi_vlq_decode_while();

#endif
