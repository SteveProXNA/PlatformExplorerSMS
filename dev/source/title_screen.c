#include "title_screen.h"
#include "_sms_manager.h"
#include "global_manager.h"
#include "locale_manager.h"
#include "hack_manager.h"
#include "enum_manager.h"
#include "font_manager.h"
#include "text_manager.h"
#include "delay_manager.h"
#include "tile_manager.h"
#include "input_manager.h"
#include "audio_manager.h"
#include "game_manager.h"
#include <stdlib.h>

#define TITLE_FLASH_DELAY	50
#define TEXT_X				12
#define TEXT_Y				18

static unsigned char flash;
static unsigned char cheat_count;

void screen_title_screen_load()
{
	struct_hack_object *ho = &global_hack_object;
	struct_game_object *go = &global_game_object;
	engine_delay_manager_load( TITLE_FLASH_DELAY );

	engine_text_manager_clear_three();
	engine_text_manager_cheat_blank();
	engine_font_manager_draw_text( LOCALE_PRESS_START, TEXT_X, TEXT_Y );

	cheat_count = 0;
	go->localcheat = 0;
	if( ho->hack_invincible )
	{
		engine_text_manager_cheat_write();
	}
}

void screen_title_screen_update( unsigned char *screen_type )
{
	struct_hack_object *ho = &global_hack_object;
	struct_game_object *go = &global_game_object;
	unsigned char delay;
	unsigned char input;

	if( ho->hack_delayspeed )
	{
		delay = engine_delay_manager_update();
		if( delay )
		{
			flash = 1 - flash;
			if( flash )
			{
				engine_font_manager_draw_text( LOCALE_BLANK_WIDTH, 0, TEXT_Y );
			}
			else
			{
				engine_font_manager_draw_text( LOCALE_PRESS_START, TEXT_X, TEXT_Y );
			}
		}
	}

	input = engine_input_manager_hold_fire1();
	if( input )
	{
		engine_audio_manager_sound_accept();
		*screen_type = screen_type_entry;
		return;
	}

	input = engine_input_manager_hold_fire2();
	if( input )
	{
		if( !ho->hack_invincible && !go->localcheat )
		{
			cheat_count++;
			if( cheat_count >= LOCAL_CHEAT_TOTAL )
			{
				engine_text_manager_cheat_write();
				engine_audio_manager_sound_power();
				go->localcheat = 1;
			}
		}
	}

	rand();
	*screen_type = screen_type_title;
}