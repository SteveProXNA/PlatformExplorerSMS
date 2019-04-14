#include "view_screen.h"
#include "_sms_manager.h"
#include "locale_manager.h"
#include "content_manager.h"
#include "enum_manager.h"
#include "font_manager.h"
#include "text_manager.h"
#include "memo_manager.h"
#include "delay_manager.h"
#include "level_manager.h"
#include "input_manager.h"
#include "anim_manager.h"
#include "player_manager.h"
#include "enemy_manager.h"
#include "score_manager.h"
#include "audio_manager.h"
#include "game_manager.h"
#include "state_manager.h"

static void load_screen();

void screen_view_screen_load()
{
	struct_game_object *go = &global_game_object;

	devkit_SMS_displayOff();
	engine_text_manager_clear_all();
	engine_audio_manager_music_stop();

	// Load game content.
	engine_content_manager_load_guards();

	// Load sprite animations.
	engine_anim_manager_player_load_idle();
	engine_anim_manager_player_load_move();
	engine_anim_manager_enemyX_load_idle();
	devkit_SMS_displayOn();

	// Reset all score data.
	engine_score_manager_init( go->difficulty );
	load_screen();
}

void screen_view_screen_update( unsigned char *screen_type )
{
	struct_game_object *go = &global_game_object;
	unsigned char test[ 6 ] = { 0, 0, 0, 0, 0, 0 };

	test[ 0 ] = engine_input_manager_hold_left();
	if( test[ 0 ] )
	{
		if( 0 == go->round_no )
		{
			go->round_no = MAX_ROUNDS - 1;
		}
		else
		{
			go->round_no--;
		}
		load_screen();
	}

	test[ 1 ] = engine_input_manager_hold_right();
	if( test[ 1 ] )
	{
		if( MAX_ROUNDS - 1 == go->round_no )
		{
			go->round_no = 0;
		}
		else
		{
			go->round_no++;
		}
		load_screen();
	}

	test[ 2 ] = engine_input_manager_hold_down();
	if( test[ 2 ] )
	{
		if( 0 == go->world_no )
		{
			go->world_no = MAX_WORLDS - 1;
		}
		else
		{
			go->world_no--;
		}
		load_screen();
	}

	test[ 3 ] = engine_input_manager_hold_up();
	if( test[ 3 ] )
	{
		if( MAX_WORLDS - 1 == go->world_no )
		{
			go->world_no = 0;
		}
		else
		{
			go->world_no++;
		}
		load_screen();
	}

	test[ 4 ] = engine_input_manager_hold_fire1();
	if( test[ 4 ] )
	{
		go->difficulty = 1 - go->difficulty;
		load_screen();
	}

	test[ 5 ] = engine_input_manager_hold_fire2();
	if( test[ 5 ] )
	{
		*screen_type = screen_type_begin;
		return;
	}

	// Draw enemies first!
	engine_enemyX_manager_draw_enemys();
	engine_player_manager_draw();

	*screen_type = screen_type_view;
}

static void load_screen()
{
	struct_game_object *go = &global_game_object;
	unsigned char invincible;
	unsigned char tutorial = 0;

	engine_enemyX_manager_init();
	engine_level_manager_init_level();

	invincible = go->invincible || go->localcheat;
	engine_level_manager_load_level( tutorial, go->world_no, go->round_no, invincible, go->difficulty );
	engine_state_manager_load();
	engine_player_manager_load();
	engine_enemyX_manager_load();

	devkit_SMS_displayOff();
	engine_level_manager_draw_level();
	engine_enemyX_manager_draw_guards();
	engine_memo_manager_draw_title();
	engine_memo_manager_draw_level( tutorial, go->world_no, go->round_no );

	// Display game stats.
	engine_game_manager_draw();
	engine_text_manager_write_gems();
	engine_score_manager_draw_score();
	engine_score_manager_draw_lives();

	if( go->tutorial )
	{
		engine_text_manager_write_info( go->round_no );
	}
	engine_font_manager_draw_text( LOCALE_SELECT_TEXT, SCREEN_TILE_LEFT, 0 );
	engine_level_manager_draw_section();
	devkit_SMS_displayOn();

	// Reset gem count at each level.
	engine_score_manager_reset_gems();
}