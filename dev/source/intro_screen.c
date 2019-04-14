#include "intro_screen.h"
#include "intro_object.h"
#include "_sms_manager.h"
#include "global_manager.h"
#include "locale_manager.h"
#include "content_manager.h"
#include "enum_manager.h"
#include "font_manager.h"
#include "text_manager.h"
#include "delay_manager.h"
#include "sprite_manager.h"
#include "tile_manager.h"
#include "input_manager.h"
#include "anim_manager.h"
#include "audio_manager.h"
#include "..\engine\asm_manager.h"
#include <stdlib.h>

#define INTRO_SCREEN_DELAY		3600
#define INTRO_WRITER_TIMER		50
#define INTRO_LEFT				7
#define INTRO_HIGH				17
#define PAUSE_COUNT				10
#define STAGE_COUNT				7

static void draw_sprite( unsigned char x, unsigned char y, unsigned frame );
static void update_text();

static unsigned char count;
static unsigned char first;
static unsigned char stage;
static unsigned char pause;

void screen_intro_screen_load()
{
	unsigned char x, tile;

	engine_delay_manager_load( INTRO_SCREEN_DELAY );

	// Unload VRAM each begin to remove any unwanted graphics glitches...!
	devkit_SMS_displayOff();
	engine_asm_manager_clear_VRAM();
	engine_text_manager_clear_all();

	engine_content_manager_load_back_tiles();
	engine_content_manager_load_sprites();
	engine_content_manager_load_title();
	engine_anim_manager_tester_load_anim();

	for( x = 2; x < SCREEN_TILE_WIDE; x += 2 )
	{
		tile = rand() % MAX_BLOCK_TILES + 1;
		engine_tile_manager_draw_tile( tile, x, 0 );
		tile = rand() % MAX_BLOCK_TILES + 1;
		engine_tile_manager_draw_tile( tile, x, 22 );
	}

	engine_font_manager_draw_text( LOCALE_BUILD_VERSION, 28, 21 );
	engine_tile_manager_draw_tile( tile_type_exitgame, 26, 20 );

	devkit_SMS_displayOn();

	first = 0;
	count = 0;
	stage = 0;
	pause = 0;
}

void screen_intro_screen_update( unsigned char *screen_type )
{
	unsigned char delay;
	unsigned char input;
	unsigned char x, y, frame;

	x = 28;
	y = 144;
	frame = 0;
	draw_sprite( x, y, frame );

	count++;
	if( count > INTRO_WRITER_TIMER )
	{
		count = 0;
		update_text();
	}

	delay = engine_delay_manager_update();
	input = engine_input_manager_hold_fire1();

	if( delay || input )
	{
		engine_audio_manager_music_stop();
		*screen_type = screen_type_begin;
		return;
	}

	*screen_type = screen_type_intro;
}

static void draw_sprite( unsigned char x, unsigned char y, unsigned frame )
{
	unsigned int tile = TESTER_SPRITE_TILE + frame * SPRITE_TILES_NUMBER;
	engine_sprite_manager_draw_player( x, y, tile );
}

static void update_text()
{
	if( 0 == first )
	{
		first = 1;
		engine_audio_manager_music_title();
		engine_font_manager_draw_text( "WELCOME HERO!", INTRO_LEFT, INTRO_HIGH );
	}
	else if( 1 == first )
	{
		first = 2;
		engine_font_manager_draw_text( LOCALE_BLANK_SIZE18, INTRO_LEFT, INTRO_HIGH + 2 );
		engine_font_manager_draw_text( LOCALE_BLANK_SIZE18, INTRO_LEFT, INTRO_HIGH + 3 );
	}
	else if (2 == first )
	{
		if( 0 == stage )
		{
			engine_font_manager_draw_text( intro_textTop[ pause ], INTRO_LEFT, INTRO_HIGH + 2 );
			engine_font_manager_draw_text( intro_textBot[ pause ], INTRO_LEFT, INTRO_HIGH + 3 );

			pause++;
			if( pause >= PAUSE_COUNT )
			{
				pause = 0;
			}
		}

		stage++;
		if( stage >= STAGE_COUNT )
		{
			stage = 0;
		}
	}
}