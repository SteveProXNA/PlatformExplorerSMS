#include "play_screen.h"
#include "global_manager.h"
#include "hack_manager.h"
#include "enum_manager.h"
#include "font_manager.h"
#include "reset_manager.h"
#include "tile_manager.h"
#include "level_manager.h"
#include "anim_manager.h"
#include "player_manager.h"
#include "enemy_manager.h"
#include "input_manager.h"
#include "state_manager.h"
#include "stats_manager.h"
#include "score_manager.h"
#include "audio_manager.h"
#include "game_manager.h"

#define PLAY_SCREEN_DELAY		75
#define LOOP_SPEED_FORCE		1

// Cache values for entire class.
static unsigned char invincible;
static unsigned char game_speed;
static unsigned char loop_speed;
static unsigned char collision;

// Private helper methods.
static void increase_lives();
static unsigned char ground_collision();

void screen_play_screen_load()
{
	struct_game_object *go = &global_game_object;
	struct_stats_object *so = &global_stats_object;
	enum_diff_type difficulty;

	invincible = go->invincible || go->localcheat;
	difficulty = go->difficulty;
	game_speed = go->game_speed;
	loop_speed = LOOP_SPEED_FORCE;
	collision = so->collision_offsets[ difficulty ];

	engine_reset_manager_load( PLAY_SCREEN_DELAY );
}

void screen_play_screen_update( unsigned char *screen_type )
{
	struct_reset_object *ro = &global_reset_object;
	struct_level_object *lo = &global_level_object;
	struct_score_object *so = &global_score_object;
	
	struct_player_object *po = &global_player_object;
	struct_enemy_master *em = &global_enemy_master;
	struct_enemy_object *eo;
	unsigned char input;
	unsigned char check;
	unsigned char idx;
	unsigned char evt;
	int coll_diff;

	// If player slow then can override on-the-fly.
	input = engine_input_manager_move_up();
	if( input )
	{
		loop_speed = LOOP_SPEED_FORCE;
	}

	if( loop_speed )
	{
		// Player movement.
		engine_player_manager_get_input();
		engine_player_manager_apply_physics();
		engine_player_manager_handle_collisions();
		engine_player_manager_cleanup();

		// Enemy(s) movement.
		engine_enemyX_manager_update();
	}

	if( pace_type_slow == game_speed )
	{
		loop_speed = 1 - loop_speed;
	}

	// Draw enemies first!
	engine_enemyX_manager_draw_enemys();
	engine_player_manager_draw();


	// Check reset next.
	input = engine_input_manager_move_fire2();
	if( input )
	{
		check = engine_reset_manager_update();
		if( check )
		{
			engine_audio_manager_music_stop();
			input = engine_input_manager_move_down();
			if( input )
			{
				ro->reset_screen = screen_type_begin;
			}
			else
			{
				ro->reset_screen = screen_type_ready;
			}

			*screen_type = screen_type_reset;
			return;
		}
	}
	else
	{
		engine_reset_manager_reset();
	}


	// Collision detection while player on ground.
	if( po->isOnGround )
	{
		if( po->coll_left == po->coll_rght )
		{
			// Gems + power up.
			evt = ground_collision();
			if( event_type_none != evt )
			{
				if( event_type_exit == evt )
				{
					*screen_type = screen_type_pass;
					return;
				}
				else if( event_type_gemscorehi == evt || event_type_gemscorelo == evt )
				{
					engine_score_manager_update_gems();
					engine_score_manager_draw_score();

					if( 0 == so->gem_total % MAX_GEMS_FREEMAN )
					{
						so->gem_count = 0;
						increase_lives();
					}
					//else
					//{
					//	Disabled for now as gems can be close together and "mash" sound FX.
					//	engine_audio_manager_sound_gem();
					//}
				}
				else if( event_type_gempowerhi == evt || event_type_gempowerlo == evt )
				{
					increase_lives();
				}
			}
		}
	}

	// If invincible then ignore collisions and pits.
	if( invincible )
	{
		*screen_type = screen_type_play;
		return;
	}

	// If jump above "ceiling" then cannot collide with anything
	if( po->posnY < 0 )
	{
		*screen_type = screen_type_play;
		return;
	}

	// Check if fell into pit.
	if( po->posnY >= MAX_POSITION_Y )
	{
		*screen_type = screen_type_dead;
		return;
	}

	// Enemy + guard collisions.
	for( idx = 0; idx < em->max_enemies; idx++ )
	{
		eo = &global_enemy_objects[ idx ];
		if( ( signed char ) eo->spotY >= po->coll_topX && ( signed char ) eo->spotY <= po->coll_botX )
		{
			// Test for collision with player.
			coll_diff = 0;
			if( po->posnX > eo->posnX )
			{
				coll_diff = po->posnX - eo->posnX;
			}
			else
			{
				coll_diff = eo->posnX - po->posnX;
			}

			if( coll_diff <= collision )
			{
				po->kill_idx = idx;
				*screen_type = screen_type_dead;
				return;
			}
		}
	}

	*screen_type = screen_type_play;
}

static void increase_lives()
{
	struct_score_object *so = &global_score_object;

	if( invincible )
	{
		return;
	}

	if( so->num_lives < MAMNUM_LIVES )
	{
		engine_audio_manager_sound_power();
		engine_score_manager_update_lives( 1 );
		engine_score_manager_draw_lives();
	}
}

static unsigned char ground_collision()
{
	struct_level_object *lo = &global_level_object;
	struct_player_object *po = &global_player_object;
	unsigned char evt;
	unsigned char tile;
	unsigned int cell_top, cell_bot;

	evt = event_type_none;
	cell_top = lo->draw_cols *  ( po->coll_topX + 0 ) + po->coll_left;
	cell_bot = lo->draw_cols *  ( po->coll_topX + 1 ) + po->coll_left;

	// Exit sign.
	if( po->coll_left == lo->exit_spotX && po->coll_topX + 1 == lo->exit_spotY )
	{
		return event_type_exit;
	}

	// Check top section.
	tile = lo->drawtiles_array[ cell_top ];
	if( tile_type_blankGap != tile )
	{
		if( tile_type_gemscore == tile || tile_type_gempower == tile )
		{
			lo->drawtiles_array[ cell_top ] = tile_type_blankGap;
			engine_level_manager_draw_blank( po->coll_left, po->coll_topX );
		}
		if( tile_type_gemscore == tile )
		{
			return event_type_gemscorehi;
		}
		else if( tile_type_gempower == tile )
		{
			return event_type_gempowerhi;
		}
	}

	// Check bot section.
	tile = lo->drawtiles_array[ cell_bot ];
	if( tile_type_blankGap != tile )
	{
		if( tile_type_gemscore == tile || tile_type_gempower == tile )
		{
			lo->drawtiles_array[ cell_bot ] = tile_type_blankGap;
			engine_level_manager_draw_blank( po->coll_left, po->coll_topX + 1 );
		}
		if( tile_type_gemscore == tile )
		{
			return event_type_gemscorelo;
		}
		else if( tile_type_gempower == tile )
		{
			return event_type_gempowerlo;
		}
	}

	return evt;
}