#include "state_manager.h"
#include "hack_manager.h"
#include "memo_manager.h"
#include "level_manager.h"
#include "player_manager.h"
#include "enemy_manager.h"
#include "stats_manager.h"
#include "game_manager.h"
#include <stdlib.h>

void engine_state_manager_init()
{
	struct_hack_object *ho = &global_hack_object;
	struct_game_object *go = &global_game_object;

	// Initialize hack manager.
	engine_hack_manager_init();
	engine_hack_manager_invert();

	// Initialize other managers.
	engine_memo_manager_init();
	engine_player_manager_init();
	engine_stats_manager_init();
	engine_game_manager_init();


	// Setup hacked variables.
	go->invincible = ho->hack_invincible;
	go->difficulty = ho->hack_difficulty;
	go->game_speed = ho->hack_game_speed;
	go->world_no = ho->hack_world;
	go->round_no = ho->hack_round;
}

void engine_state_manager_load()
{
	struct_hack_object *ho = &global_hack_object;
	struct_game_object *go = &global_game_object;
	struct_level_object *lo = &global_level_object;
	struct_player_object *po = &global_player_object;
	struct_stats_object *so = &global_stats_object;

	struct_enemy_master *em = &global_enemy_master;
	struct_enemy_object *eo;

	unsigned char idx;
	unsigned char num;

	// This should never happen!
	if( 0 == lo->draw_cols )
	{
		return;
	}

	// Player setup.
	po->spotY = lo->player_spot / lo->draw_cols;
	po->spotX = lo->player_spot % lo->draw_cols;
	po->anim_count = PLAYER_ANIMS_COUNT;

	// EnemyX setup.
	em->max_enemies = lo->enemyCount;
	for( idx = 0; idx < em->max_enemies; idx++ )
	{
		eo = &global_enemy_objects[ idx ];

		eo->sprite_type = lo->enemys_type[ idx ];
		eo->action_type = lo->enemys_action[ idx ];
		eo->spotY = lo->enemys_spotY[ idx ];
		eo->spotX = lo->enemys_spotX[ idx ];

		// Don't set movement data for guards.
		if( action_type_guard == eo->action_type )
		{
			continue;
		}

		eo->minX = lo->enemys_minX[ idx ];
		eo->maxX = lo->enemys_maxX[ idx ];

		// Cheat to disable enemy movement.
		if( ho->hack_enemy )
		{
			eo->velX = so->enemys_velX[ eo->sprite_type ][ go->world_no ];
		}

		if( eo->velX > MAX_ENEMY_VELX )
		{
			eo->velX = MAX_ENEMY_VELX;
		}

		eo->wait = so->enemys_wait[ eo->sprite_type ][ go->world_no ];
		if( eo->wait < MIN_ENEMY_WAIT )
		{
			eo->wait = MIN_ENEMY_WAIT;
		}
		if( eo->wait > MAX_ENEMY_WAIT )
		{
			eo->wait = MAX_ENEMY_WAIT;
		}
		// Difficulty Hard waits 25x frames less!
		if( diff_type_hard == go->difficulty )
		{
			eo->wait -= MIN_ENEMY_WAIT;
		}


		// If walk count zero then always walk i.e. enemy does not stutter.
		eo->walkCount = so->enemys_walk[ eo->sprite_type ][ go->world_no ];
		if( eo->walkCount > MAX_ENEMY_WALK )
		{
			eo->walkCount = MAX_ENEMY_WALK;
		}
		if( 0 == eo->walkCount )
		{
			eo->walkFlag = 1;
		}

		// Finally if EnemyB or EnemyD and difficulty Hard then *maybe* double velocity...
		if( ho->hack_enemy )
		{
			if( sprite_type_enemyB == eo->sprite_type || sprite_type_enemyD == eo->sprite_type )
			{
				if( diff_type_hard == go->difficulty )
				{
					num = rand() % 2;
					if( 0 == num )
					{
						eo->velX += go->difficulty;
					}
				}
			}
		}

	}

}
