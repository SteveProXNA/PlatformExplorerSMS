#include "entry_screen.h"
#include "global_manager.h"
#include "locale_manager.h"
#include "enum_manager.h"
#include "font_manager.h"
#include "text_manager.h"
#include "tile_manager.h"
#include "delay_manager.h"
#include "input_manager.h"
#include "stats_manager.h"
#include "audio_manager.h"
#include "game_manager.h"

#define TEXT_X				9
#define TEXT_Y				18
#define OPT1_X				TEXT_X + 3
#define OPT1_Y				TEXT_Y + 1
#define OPT2_Y				TEXT_Y + 2

static unsigned char select_count;
static unsigned char cursorY[ 2 ] = { OPT1_Y, OPT2_Y };
static void display_cursor();

void screen_entry_screen_load()
{
	engine_text_manager_clear_three();
	engine_font_manager_draw_text( LOCALE_SELECT_ENTRY, TEXT_X, TEXT_Y + 0 );
	engine_font_manager_draw_text( LOCALE_ENTRY_OPT1, TEXT_X + 5, TEXT_Y + 1 );
	engine_font_manager_draw_text( LOCALE_ENTRY_OPT2, TEXT_X + 5, TEXT_Y + 2 );

	display_cursor();
	select_count = 0;
}

void screen_entry_screen_update( unsigned char *screen_type )
{
	struct_game_object *go = &global_game_object;
	unsigned char test[ 5 ] = { 0, 0, 0, 0, 0 };

	test[ 0 ] = engine_input_manager_hold_up();
	test[ 1 ] = engine_input_manager_hold_down();
	if( test[ 0 ] || test[ 1 ] )
	{
		go->tutorial = 1 - go->tutorial;
		display_cursor();
	}

	test[ 2 ] = engine_input_manager_hold_fire1();
	if( test[ 2 ] )
	{
		engine_audio_manager_sound_accept();
		*screen_type = screen_type_diff;
		return;
	}

	test[ 2 ] = engine_input_manager_hold_fire1();
	if( test[ 2 ] )
	{
		engine_audio_manager_sound_accept();
		*screen_type = screen_type_diff;
		return;
	}

	test[ 3 ] = engine_input_manager_move_down();
	if( test[ 3 ] )
	{
		/*test[ 4 ] = engine_input_manager_hold_fire2();
		if( test[ 4 ] )
		{
			select_count++;
			if( select_count >= LOCAL_SELECT_TOTAL )
			{
				*screen_type = screen_type_view;
				return;
			}
		}*/

		return;
	}

	test[ 4 ] = engine_input_manager_hold_fire2();
	if( test[ 4 ] )
	{
		*screen_type = screen_type_title;
		return;
	}

	*screen_type = screen_type_entry;
}

static void display_cursor()
{
	struct_game_object *go = &global_game_object;
	engine_font_manager_draw_text( LOCALE_SELECT_BLANK, OPT1_X, OPT1_Y );
	engine_font_manager_draw_text( LOCALE_SELECT_BLANK, OPT1_X, OPT2_Y );
	engine_font_manager_draw_text( LOCALE_SELECT_ARROW, OPT1_X, cursorY[ 1 - go->tutorial ] );
}