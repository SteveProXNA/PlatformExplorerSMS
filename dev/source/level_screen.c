#include "level_screen.h"
#include "global_manager.h"
#include "locale_manager.h"
#include "content_manager.h"
#include "enum_manager.h"
#include "font_manager.h"
#include "text_manager.h"
#include "tile_manager.h"
#include "delay_manager.h"
#include "input_manager.h"
#include "stats_manager.h"
#include "audio_manager.h"
#include "game_manager.h"

#define LEVEL_SCREEN_DELAY	50
#define TEXT_X				11
#define TEXT_Y				18
#define OPT1_X				TEXT_X + 7
#define OPT1_Y				TEXT_Y + 1
#define OPT2_Y				TEXT_Y + 2

static unsigned char stage;
static unsigned char cursor;
static unsigned char cursorY[ 2 ] = { OPT1_Y, OPT2_Y };
static void display_options();

void screen_level_screen_init()
{
	// Default select round.
	cursor = 1;
}

void screen_level_screen_load()
{
	struct_game_object *go = &global_game_object;
	engine_delay_manager_load( LEVEL_SCREEN_DELAY );

	engine_text_manager_clear_three();
	engine_font_manager_draw_text( LOCALE_SELECT_LEVEL, TEXT_X + 0, TEXT_Y + 0 );
	engine_font_manager_draw_text( LOCALE_SELECT_WORLD, TEXT_X + 0, TEXT_Y + 1 );
	engine_font_manager_draw_text( LOCALE_SELECT_ROUND, TEXT_X + 0, TEXT_Y + 2 );

	// Select round only if tutorial entry.
	if( go->tutorial )
	{
		cursor = 1;
	}

	display_options();
	stage = event_stage_start;
}

void screen_level_screen_update( unsigned char *screen_type )
{
	struct_game_object *go = &global_game_object;
	unsigned char test[ 6 ] = { 0, 0, 0, 0, 0, 0 };
	unsigned char delay;

	if( event_stage_pause == stage )
	{
		delay = engine_delay_manager_update();
		if( delay )
		{
			*screen_type = screen_type_init;
			return;
		}
		else
		{
			*screen_type = screen_type_level;
			return;
		}
	}

	test[ 0 ] = engine_input_manager_hold_left();
	if( test[ 0 ] )
	{
		if( 0 == cursor )
		{
			if( 0 == go->world_no )
			{
				go->world_no = MAX_WORLDS - 1;
			}
			else
			{
				go->world_no--;
			}
		}
		else if( 1 == cursor )
		{
			if( 0 == go->round_no )
			{
				go->round_no = MAX_ROUNDS - 1;
			}
			else
			{
				go->round_no--;
			}
		}

		display_options();
	}

	test[ 1 ] = engine_input_manager_hold_right();
	if( test[ 1 ] )
	{
		if( 0 == cursor )
		{
			if( MAX_WORLDS - 1 == go->world_no )
			{
				go->world_no = 0;
			}
			else
			{
				go->world_no++;
			}
		}
		else if( 1 == cursor )
		{
			if( MAX_ROUNDS - 1 == go->round_no )
			{
				go->round_no = 0;
			}
			else
			{
				go->round_no++;
			}
		}

		display_options();
	}

	if( !go->tutorial )
	{
		test[ 2 ] = engine_input_manager_hold_up();
		test[ 3 ] = engine_input_manager_hold_down();
		if( test[ 2 ] || test[ 3 ] )
		{
			cursor = 1 - cursor;
			display_options();
		}
	}

	test[ 4 ] = engine_input_manager_hold_fire1();
	if( test[4] )
	{
		engine_audio_manager_sound_accept();
		stage = event_stage_pause;
		return;
	}
	test[ 5 ] = engine_input_manager_hold_fire2();
	if( test[ 5 ] )
	{
		*screen_type = screen_type_pace;
		return;
	}

	*screen_type = screen_type_level;
}

static void display_options()
{
	struct_game_object *go = &global_game_object;

	engine_font_manager_draw_text( LOCALE_SELECT_BLANK, OPT1_X, OPT1_Y );
	engine_font_manager_draw_text( LOCALE_SELECT_BLANK, OPT1_X, OPT2_Y );
	engine_font_manager_draw_text( LOCALE_SELECT_ARROW, OPT1_X, cursorY[ cursor ] );

	if( go->tutorial )
	{
		engine_font_manager_draw_text( LOCALE_TUTORIAL_NO, OPT1_X + 2, OPT1_Y );
	}
	else
	{
		engine_font_manager_draw_text( count_text[ go->world_no ], OPT1_X + 2, OPT1_Y );
	}

	engine_font_manager_draw_text( count_text[ go->round_no ], OPT1_X + 2, OPT2_Y );
}