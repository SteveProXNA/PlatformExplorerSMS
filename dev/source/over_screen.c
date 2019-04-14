#include "over_screen.h"
#include "global_manager.h"
#include "locale_manager.h"
#include "enum_manager.h"
#include "font_manager.h"
#include "sprite_manager.h"
#include "tile_manager.h"
#include "memo_manager.h"
#include "delay_manager.h"
#include "input_manager.h"
#include "level_manager.h"
#include "player_manager.h"
#include "enemy_manager.h"
#include "audio_manager.h"
#include "game_manager.h"

#define OVER_SCREEN_DELAY		250

void screen_over_screen_load()
{
	struct_game_object *go = &global_game_object;

	// Reset tutorial unconditionally.
	go->tutorial = 0;

	engine_audio_manager_music_over();
	engine_delay_manager_load( OVER_SCREEN_DELAY );
	engine_memo_manager_draw_over();
}

void screen_over_screen_update( unsigned char *screen_type )
{
	unsigned char delay;

	// Draw enemies first!
	engine_enemyX_manager_draw_enemys();
	engine_player_manager_draw();

	delay = engine_delay_manager_update();
	if( delay )
	{
		engine_audio_manager_music_stop();
		*screen_type = screen_type_begin;
		return;
	}

	*screen_type = screen_type_over;
}