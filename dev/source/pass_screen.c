#include "pass_screen.h"
#include "_snd_manager.h"
#include "hack_manager.h"
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
#include "game_manager.h"

#define PASS_SCREEN_DELAY	250

static unsigned char gem_level;
static void increase_lives();

void screen_pass_screen_load()
{
	struct_hack_object *ho = &global_hack_object;
	struct_level_object *lo = &global_level_object;
	struct_score_object *so = &global_score_object;
	struct_game_object *go = &global_game_object;
	unsigned char perfect = 0;
	unsigned char invincible;

	engine_audio_manager_music_stop();
	if( ho->hack_delayspeed )
	{
		engine_audio_manager_sound_level();
	}

	// Check if player collected all available gems.
	gem_level = so->gem_level;
	if( 0 != lo->gem_level )
	{
		if( gem_level == lo->gem_level )
		{
			perfect = 1;
		}
	}

	engine_delay_manager_load( PASS_SCREEN_DELAY );
	engine_memo_manager_draw_pass( perfect );

	if( perfect )
	{
		invincible = go->invincible || go->localcheat;
		if( !invincible )
		{
			engine_score_manager_bonus_gems();
			engine_score_manager_draw_score();

			if( so->gem_count >= MAX_GEMS_FREEMAN )
			{
				so->gem_count -= MAX_GEMS_FREEMAN;
				increase_lives();
			}
		}
	}
}

void screen_pass_screen_update( unsigned char *screen_type )
{
	struct_player_object *po = &global_player_object;
	struct_score_object *so = &global_score_object;
	struct_game_object *go = &global_game_object;

	unsigned char delay;

	// Draw enemies first!
	engine_enemyX_manager_draw_enemys();
	engine_player_manager_hide();

	delay = engine_delay_manager_update();
	if( delay )
	{
		go->round_no++;
		if( go->round_no >= MAX_ROUNDS )
		{
			go->round_no = 0;
			if( go->tutorial )
			{
				go->tutorial = 0;
				go->world_no = 0;
				*screen_type = screen_type_begin;
				return;
			}

			go->world_no++;
			if( go->world_no >= MAX_WORLDS )
			{
				go->world_no = 0;
				*screen_type = screen_type_beat;
				return;
			}
		}

		*screen_type = screen_type_gems;
		return;
	}

	*screen_type = screen_type_pass;
}

static void increase_lives()
{
	struct_score_object *so = &global_score_object;
	if( so->num_lives < MAMNUM_LIVES )
	{
		// Don't play sound effect as overrides music!
		//engine_audio_manager_sound_power();

		engine_score_manager_update_lives( 1 );
		engine_score_manager_draw_lives();
	}
}