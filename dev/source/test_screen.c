#include "test_screen.h"
#include "_snd_manager.h"
#include "global_manager.h"
#include "locale_manager.h"
#include "enum_manager.h"
#include "font_manager.h"
#include "memo_manager.h"
#include "input_manager.h"
#include "audio_manager.h"

void screen_test_screen_load()
{
	unsigned char status;
	status = 2;

	engine_font_manager_draw_text( "TEST SCREEN", 10, 0 );

//	status = PSGGetStatus();
	engine_font_manager_draw_text( "STATUS", 10, 5 );
	engine_font_manager_draw_data( status, 10, 6 );

	status = !status;
	engine_font_manager_draw_text( "STATUS", 10, 8 );
	engine_font_manager_draw_data( status, 10, 9 );
}

void screen_test_screen_update( unsigned char *screen_type )
{
	unsigned char test[ 4 ] = { 0, 0, 0, 0 };
	unsigned char status;

	test[ 0 ] = engine_input_manager_hold_left();
	if( test[ 0 ] )
	{
		engine_font_manager_draw_text( "PRESS START", 10, 1 );
		//engine_audio_manager_music_game( 0 );
		engine_audio_manager_music_beat();
	}
	test[ 1 ] = engine_input_manager_hold_right();
	if( test[ 1 ] )
	{
		engine_font_manager_draw_text( "PRESS PAUSE", 10, 2 );
		devkit_PSGStop();
	}
	test[ 2 ] = engine_input_manager_hold_down();
	if( test[ 2 ] )
	{
		engine_font_manager_draw_text( "PRESS RESUME...!", 10, 3 );
		devkit_PSGResume();
	}

	test[ 3 ] = engine_input_manager_hold_up();
	if( test[ 3 ] )
	{
		status = PSGGetStatus();
		engine_font_manager_draw_text( "STATUS", 10, 5 );
		engine_font_manager_draw_data( status, 10, 7 );
	}

	*screen_type = screen_type_test;
}