#include "ready_screen.h"
#include "_sms_manager.h"
#include "_snd_manager.h"
#include "enum_manager.h"
#include "font_manager.h"
#include "memo_manager.h"
#include "delay_manager.h"
#include "level_manager.h"
#include "input_manager.h"
#include "player_manager.h"
#include "enemy_manager.h"
#include "score_manager.h"
#include "audio_manager.h"

#define READY_SCREEN_DELAY		75

void screen_ready_screen_load()
{
	struct_player_object *po = &global_player_object;
	struct_enemy_master *em = &global_enemy_master;
	struct_enemy_object *eo;

	engine_delay_manager_load( READY_SCREEN_DELAY );

	// If player killed by enemy then reset enemy killer.
	if( INVALID_INDEX != po->kill_idx )
	{
		eo = &global_enemy_objects[ po->kill_idx ];
		if( action_type_chase == eo->action_type )
		{
			eo->posnX = eo->startX;
		}
	}

	// Reset player irrespective of new level or new life.
	// Reset killer index unconditionally on player load.
	engine_player_manager_load();

	engine_level_manager_draw_section();
	engine_score_manager_draw_lives();
}

void screen_ready_screen_update( unsigned char *screen_type )
{
	unsigned char test[ 2 ] = { 0, 0 };
	unsigned char delay;

	// Draw enemies first!
	engine_enemyX_manager_draw_enemys();
	engine_player_manager_draw();

	// Prompt to move to enter level quicker...
	test[ 0 ] = engine_input_manager_move_left();
	test[ 1 ] = engine_input_manager_move_right();

	delay = engine_delay_manager_update();
	if( test[ 0 ] || test[ 1 ] || delay )
	{
		engine_audio_manager_music_resume();
		*screen_type = screen_type_play;
		return;
	}

	*screen_type = screen_type_ready;
}