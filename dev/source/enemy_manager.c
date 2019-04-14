#include "enemy_manager.h"
#include "global_manager.h"
#include "hack_manager.h"
#include "enum_manager.h"
#include "font_manager.h"
#include "sprite_manager.h"
#include "tile_manager.h"
#include "stats_manager.h"
#include <stdlib.h>

// Global variables.
struct_enemy_master global_enemy_master;
struct_enemy_object global_enemy_objects[ MAX_ENEMIES ];

#define DRAW_OFFSET_X	0

static unsigned int enemy_tiles[ MAX_ENEMIES ] =
{
	ENEMYX_SPRITE_TILE + 0 * GUARDS_TILES_NUMBER,
	ENEMYX_SPRITE_TILE + 1 * GUARDS_TILES_NUMBER,
	ENEMYX_SPRITE_TILE + 2 * GUARDS_TILES_NUMBER,
	ENEMYX_SPRITE_TILE + 3 * GUARDS_TILES_NUMBER
};

static void get_enemy_draw_position( unsigned char idx );
static void get_guard_draw_position( unsigned char idx );

void engine_enemyX_manager_init()
{
	struct_enemy_object *eo;
	unsigned char idx;
	for( idx = 0; idx < MAX_ENEMIES; idx++ )
	{
		eo = &global_enemy_objects[ idx ];
		eo->sprite_type = sprite_type_unknown;
		eo->action_type = action_type_unknown;
		eo->curr_move_type = move_type_idle;
		eo->next_move_type = move_type_idle;
		eo->spotX = 0;	eo->spotY = 0;
		eo->drawX = 0;	eo->drawY = 0;
		eo->minX = 0;	eo->maxX = 0;
		eo->velX = 0;	eo->wait = 0;	eo->loop = 0;
		eo->walkCount = 0;
		eo->walkTimer = 0;
		eo->walkFlag = 0;
	}
}

void engine_enemyX_manager_load()
{
	struct_enemy_master *em = &global_enemy_master;
	struct_enemy_object *eo;
	unsigned char idx;
	unsigned char hlf;
	unsigned char num;

	// Calculate enemy starting spot based on level.
	int rectX, rectB;
	hlf = TILE_WIDE / 2;

	for( idx = 0; idx < em->max_enemies; idx++ )
	{
		eo = &global_enemy_objects[ idx ];

		// Position.
		rectX = eo->spotX * TILE_WIDE;
		rectB = eo->spotY * TILE_HIGH + TILE_HIGH;
		eo->posnX = rectX + hlf;
		eo->posnY = rectB;
		eo->startX = eo->posnX;

		// Bounds.
		rectX = eo->minX * TILE_WIDE;
		eo->leftX = rectX + hlf;

		rectX = eo->maxX * TILE_WIDE;
		eo->rghtX = rectX + hlf;

		// Randomize start direction.
		num = rand() % 2;
		eo->curr_move_type = num * 2;

		if( action_type_chase == eo->action_type )
		{
			get_enemy_draw_position( idx );
		}
		else if( action_type_guard == eo->action_type )
		{
			get_guard_draw_position( idx );
		}
	}
}

void engine_enemyX_manager_update()
{
	struct_enemy_master *em = &global_enemy_master;
	struct_enemy_object *eo;
	unsigned char idx;
	signed char deltaX;

	if( 0 == em->max_enemies )
	{
		return;
	}

	for( idx = 0; idx < em->max_enemies; idx++ )
	{
		eo = &global_enemy_objects[ idx ];

		// Guards do not move!
		if( action_type_guard == eo->action_type )
		{
			continue;
		}

		if( move_type_idle == eo->curr_move_type )
		{
			eo->loop++;
			if( eo->loop >= eo->wait )
			{
				eo->loop = 0;
				eo->curr_move_type = eo->next_move_type;
			}
		}
		else
		{
			if( 0 != eo->walkCount )
			{
				eo->walkTimer++;
				if( eo->walkTimer >= eo->walkCount )
				{
					eo->walkTimer = 0;
					eo->walkFlag = 1 - eo->walkFlag;
				}
			}

			if( eo->walkFlag )
			{
				// Wait at boundary as necessary.
				if( move_type_left == eo->curr_move_type )
				{
					if( eo->posnX <= eo->leftX )
					{
						eo->curr_move_type = move_type_idle;
						eo->next_move_type = move_type_rght;
					}
				}
				else if( move_type_rght == eo->curr_move_type )
				{
					if( eo->posnX >= eo->rghtX )
					{
						eo->curr_move_type = move_type_idle;
						eo->next_move_type = move_type_left;
					}
				}

				// Only move after above check if not idle.
				if( move_type_idle != eo->curr_move_type )
				{
					deltaX = ( eo->curr_move_type - 1 ) * eo->velX;
					eo->posnX += deltaX;
				}
				else
				{
					eo->walkTimer = 0;

					// If walk count zero then do not reset walk flag!
					if( 0 != eo->walkCount )
					{
						eo->walkFlag = 0;
					}
				}
			}
		}
	}

}

void engine_enemyX_manager_draw_enemys()
{
	struct_enemy_master *em = &global_enemy_master;
	struct_enemy_object *eo;
	unsigned char idx;
	unsigned int tile;

	for( idx = 0; idx < em->max_enemies; idx++ )
	{
		eo = &global_enemy_objects[ idx ];
		if( action_type_chase != eo->action_type )
		{
			continue;
		}

		get_enemy_draw_position( idx );
		tile = enemy_tiles[ eo->sprite_type ];
		engine_sprite_manager_draw_enemyX( eo->drawX, eo->drawY, tile );
	}
}

void engine_enemyX_manager_draw_guards()
{
	struct_enemy_master *em = &global_enemy_master;
	struct_enemy_object *eo;
	unsigned char idx;

	for( idx = 0; idx < em->max_enemies; idx++ )
	{
		eo = &global_enemy_objects[ idx ];
		if( action_type_guard != eo->action_type )
		{
			continue;
		}

		engine_tile_manager_draw_guard( eo->drawX, eo->drawY, eo->sprite_type );
	}
}

static void get_enemy_draw_position( unsigned char idx )
{
	struct_enemy_object *eo = &global_enemy_objects[ idx ];

	int halfTileSizeX = TILE_WIDE / 2;
	int twiceTileSizeY = 2 * TILE_HIGH;

	eo->drawX = eo->posnX - halfTileSizeX + DRAW_OFFSET_X;
	eo->drawY = eo->posnY - twiceTileSizeY;
}

static void get_guard_draw_position( unsigned char idx )
{
	struct_enemy_object *eo = &global_enemy_objects[ idx ];

	// Block 16x16 = 2 * 8x08.
	eo->drawX = eo->spotX * 2;
	eo->drawY = ( eo->spotY - 1 ) * 2;
}