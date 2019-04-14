#include "reset_screen.h"
#include "delay_manager.h"
#include "reset_manager.h"
#include "enum_manager.h"
#include "memo_manager.h"
#include "player_manager.h"
#include "enemy_manager.h"
#include "audio_manager.h"
#include "game_manager.h"

#define RESET_SCREEN_DELAY		75
#define RESET_SCREEN_PAUSE		25

static unsigned char stage;

void screen_reset_screen_load()
{
	engine_audio_manager_music_stop();
	engine_audio_manager_sound_reset();
	engine_delay_manager_load( RESET_SCREEN_DELAY );
	engine_memo_manager_draw_reset();
	stage = event_stage_start;
}

void screen_reset_screen_update( unsigned char *screen_type )
{
	struct_reset_object *ro = &global_reset_object;
	struct_game_object *go = &global_game_object;
	unsigned char delay;

	engine_enemyX_manager_draw_enemys();
	if( event_stage_pause == stage )
	{
		delay = engine_delay_manager_update();
		if( delay )
		{
			if( screen_type_begin ==  ro->reset_screen )
			{
				if( go->tutorial )
				{
					go->tutorial = 0;
				}
			}

			*screen_type = ro->reset_screen;
			return;
		}
		else
		{
			*screen_type = screen_type_reset;
			return;
		}
	}

	delay = engine_delay_manager_update();
	if( delay )
	{
		stage = event_stage_pause;
		engine_delay_manager_load( RESET_SCREEN_PAUSE );
		return;
	}

	// Draw enemies first!
	if( screen_type_begin == ro->reset_screen )
	{
		engine_enemyX_manager_draw_enemys();
	}
	else
	{
		engine_player_manager_draw();
	}

	*screen_type = screen_type_reset;
}