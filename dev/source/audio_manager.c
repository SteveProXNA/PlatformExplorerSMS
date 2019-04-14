#include "audio_manager.h"
#include "audio_object.h"
#include "_sms_manager.h"
#include "_snd_manager.h"
#include "hack_manager.h"
#include "..\psg.h"

// IMPORTANT disable compiler warning 110
#ifdef _CONSOLE
#else
#pragma disable_warning 196
#endif

#define sfx_accept_psg			sfx_accept_psg
#define sfx_death_psg			sfx_death_psg
#define sfx_gem_psg				sfx_gem_psg
#define sfx_level_psg			sfx_level_psg
#define sfx_power_psg			sfx_power_psg
#define sfx_reset_psg			sfx_reset_psg

// Private helper functions.
static void play_music( unsigned char *mus, unsigned char bank );
static void play_music_norepeat( unsigned char *mus, unsigned char bank );
static void play_sound( unsigned char *sfx );

void engine_audio_manager_music_game( unsigned char index )
{
	play_music( ( unsigned char* ) game_audio_data[ index ], game_audio_bank[ index ] );
}
void engine_audio_manager_music_title()
{
	play_music_norepeat( ( unsigned char* ) title_audio_data[ 0 ], title_audio_bank[ 0 ] );
}
void engine_audio_manager_music_over()
{
	play_music_norepeat( ( unsigned char* ) over_audio_data[ 0 ], over_audio_bank[ 0 ] );
}
void engine_audio_manager_music_beat()
{
	play_music_norepeat( ( unsigned char* ) beat_audio_data[ 0 ], beat_audio_bank[ 0 ] );
}

void engine_audio_manager_music_resume()
{
	devkit_PSGResume();
}
void engine_audio_manager_music_stop()
{
	devkit_PSGStop();
}

void engine_audio_manager_sound_accept()
{
	play_sound( ( unsigned char* ) sfx_accept_psg );
}
void engine_audio_manager_sound_death()
{
	play_sound( ( unsigned char* ) sfx_death_psg );
}
void engine_audio_manager_sound_gem()
{
	play_sound( ( unsigned char* ) sfx_gem_psg );
}
void engine_audio_manager_sound_level()
{
	play_sound( ( unsigned char* ) sfx_level_psg );
}
void engine_audio_manager_sound_power()
{
	play_sound( ( unsigned char* ) sfx_power_psg );
}
void engine_audio_manager_sound_reset()
{
	play_sound( ( unsigned char* ) sfx_reset_psg );
}

static void play_music( unsigned char *mus, unsigned char bank )
{
	struct_hack_object *ho = &global_hack_object;
	if( !ho->hack_music )
	{
		return;
	}

	devkit_SMS_mapROMBank( bank );
	devkit_PSGPlay( mus );
}
static void play_music_norepeat( unsigned char *mus, unsigned char bank )
{
	struct_hack_object *ho = &global_hack_object;
	if( !ho->hack_music )
	{
		return;
	}

	devkit_SMS_mapROMBank( bank );
	devkit_PSGPlayNoRepeat( mus );
}
static void play_sound( unsigned char *sfx )
{
	struct_hack_object *ho = &global_hack_object;
	if( !ho->hack_sound )
	{
		return;
	}

	devkit_PSGSFXPlay( sfx, devkit_SFX_CHANNEL2() );
}