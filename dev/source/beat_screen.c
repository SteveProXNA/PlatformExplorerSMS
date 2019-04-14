#include "beat_screen.h"
#include "enum_manager.h"
#include "memo_manager.h"
#include "delay_manager.h"
#include "player_manager.h"
#include "enemy_manager.h"
#include "audio_manager.h"

#define BEAT_SCREEN_DELAY	900

void screen_beat_screen_load()
{
	engine_audio_manager_music_stop();
	engine_audio_manager_music_beat();
	engine_delay_manager_load( BEAT_SCREEN_DELAY );
	engine_memo_manager_draw_beat();
}

void screen_beat_screen_update( unsigned char *screen_type )
{
	unsigned char delay;

	// Draw enemies first!
	engine_enemyX_manager_draw_enemys();
	engine_player_manager_hide();

	delay = engine_delay_manager_update();
	if( delay )
	{
		engine_audio_manager_music_stop();
		*screen_type = screen_type_begin;
		return;
	}

	*screen_type = screen_type_beat;
}