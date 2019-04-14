#include "cont_screen.h"
#include "global_manager.h"
#include "locale_manager.h"
#include "enum_manager.h"
#include "font_manager.h"
#include "memo_manager.h"
#include "delay_manager.h"
#include "input_manager.h"
#include "player_manager.h"
#include "enemy_manager.h"
#include "score_manager.h"
#include "audio_manager.h"

#define CONT_SCREEN_DELAY	50
#define TEXT_X				12
#define TEXT_Y				21
#define OPT1_X				TEXT_X + 0
#define OPT2_X				TEXT_X + 6

static unsigned char stage;
static unsigned char cursor;
static unsigned char cursorX[ 2 ] = { OPT1_X, OPT2_X };
static void display_cursor();

void screen_cont_screen_load()
{
	engine_audio_manager_music_stop();
	engine_delay_manager_load( CONT_SCREEN_DELAY );
	engine_memo_manager_draw_cont();
	cursor = 0;

	display_cursor();
	stage = event_stage_start;
}

void screen_cont_screen_update( unsigned char *screen_type )
{
	unsigned char test[ 4 ] = { 0, 0, 0, 0 };
	unsigned char delay;

	// Draw enemies first!
	engine_enemyX_manager_draw_enemys();
	engine_player_manager_draw();

	if( event_stage_pause == stage )
	{
		delay = engine_delay_manager_update();
		if( delay )
		{
			if( 0 == cursor )
			{
				engine_score_manager_reset_lives();
				*screen_type = screen_type_ready;
				return;
			}
			else
			{
				*screen_type = screen_type_over;
				return;
			}
		}
		else
		{
			*screen_type = screen_type_cont;
			return;
		}
	}

	test[ 0 ] = engine_input_manager_hold_left();
	test[ 1 ] = engine_input_manager_hold_right();
	if( test[ 0 ] || test[ 1 ] )
	{
		cursor = 1 - cursor;
		display_cursor();
	}

	test[ 2 ] = engine_input_manager_hold_fire1();
	if( test[ 2 ] )
	{
		engine_audio_manager_sound_accept();
		stage = event_stage_pause;
		return;
	}

	*screen_type = screen_type_cont;
}

static void display_cursor()
{
	engine_font_manager_draw_text( LOCALE_SELECT_BLANK, OPT1_X, TEXT_Y + 1 );
	engine_font_manager_draw_text( LOCALE_SELECT_BLANK, OPT2_X, TEXT_Y + 1 );
	engine_font_manager_draw_text( LOCALE_SELECT_ARROW, cursorX[ cursor ], TEXT_Y + 1 );
}