#include "level_manager.h"
#include "_sms_manager.h"
#include "global_manager.h"
#include "enum_manager.h"
#include "font_manager.h"
#include "tile_manager.h"
#include <stdlib.h>

// Global variable.
struct_level_object global_level_object;

#define CRlf	2				// char
#define CR		'\r'			// 0x0d
#define LF		'\n'			// 0x0a

// Private helper methods.
static void load_level( const unsigned char *data, const unsigned char bank, const unsigned char size, unsigned char invincible, unsigned char difficulty );
static void draw_tiles( unsigned char x, unsigned char y );
static void setup_player( unsigned char index );
static void setup_enemyX( enum_sprite_type sprite_type, unsigned char enemy, unsigned char tile, unsigned char row, unsigned char col );

void engine_level_manager_init_level()
{
	struct_level_object *lo = &global_level_object;
	unsigned char idx, row, col;

	for( row = 0; row < MAX_ROWS; row++ )
	{
		for( col = 0; col < MAX_COLS; col++ )
		{
			idx = row * MAX_COLS + col;
			lo->collision_array[ idx ] = 0;
			lo->drawtiles_array[ idx ] = 0;
		}
	}

	for( idx = 0; idx < MAX_ENEMIES; idx++ )
	{
		lo->enemys_spotX[ idx ] = 0;
		lo->enemys_spotY[ idx ] = 0;
		lo->enemys_type[ idx ] = sprite_type_unknown;
		lo->enemys_minX[ idx ] = 0;
		lo->enemys_maxX[ idx ] = 0;
		lo->enemys_action[ idx ] = action_type_unknown;
	}
}

void load_level( const unsigned char *data, const unsigned char bank, const unsigned char size, unsigned char invincible, unsigned char difficulty )
{
	struct_level_object *lo = &global_level_object;

	const unsigned char *o = data;
	unsigned char row, col, cnt;
	unsigned char minX, maxX, tmpX;
	unsigned char tile;
	unsigned char enemyCount;
	
	unsigned int idx;
	enum_tile_type tile_type;
	enum_coll_type coll_type;
	enum_sprite_type sprite_type;
	enemyCount = 0;

	lo->load_cols = size / MAX_ROWS;
	lo->draw_cols = lo->load_cols - CRlf;
	lo->gem_level = 0;

	devkit_SMS_mapROMBank( bank );
	for( row = 0; row < MAX_ROWS; row++ )
	{
		for( col = 0; col < lo->load_cols; col++ )
		{
			tile = *o;
			if( !( tile == CR || tile == LF ) )
			{
				idx = row * MAX_COLS + col;

				engine_tile_manager_get_tile( &tile_type, tile, difficulty );
				lo->drawtiles_array[ idx ] = tile_type;
				if( tile_type_exitgame == tile_type )
				{
					lo->exit_spotX = col;
					lo->exit_spotY = row;
				}
				if( tile_type_gemscore == tile_type )
				{
					lo->gem_level++;
				}
				if( tile_type_gempower == tile_type )
				{
					if( invincible )
					{
						lo->drawtiles_array[ idx ] = tile_type_blankGap;
					}
				}

				engine_tile_manager_get_collision( &coll_type, tile, difficulty );

				engine_tile_manager_get_sprite( &sprite_type, tile );
				if( sprite_type_unknown != sprite_type )
				{
					if( sprite_type_player == sprite_type )
					{
						setup_player( idx );
					}
					else
					{
						setup_enemyX( sprite_type, enemyCount++, tile, row, col );
					}
				}

				lo->collision_array[ idx ] = coll_type;
			}

			o++;
		}
	}

	// Hardcode 2x bottom game data steps as passable.
	row = MAX_ROWS - 1;
	col = 1;
	idx = row * lo->draw_cols + col;
	lo->drawtiles_array[ idx ] = tile_type_blankGap;
	lo->collision_array[ idx ] = coll_type_passable;

	col = 15;
	idx = row * lo->draw_cols + col;
	lo->drawtiles_array[ idx ] = tile_type_blankGap;
	lo->collision_array[ idx ] = coll_type_passable;


	// Calculate the min + max X co-ordinates per enemy.
	lo->enemyCount = enemyCount;
	for( cnt = 0; cnt < enemyCount; cnt++ )
	{
		if( action_type_guard == lo->enemys_action[ cnt ] )
		{
			continue;
		}

		// Get the row under the enemy.
		col = lo->enemys_spotX[ cnt ];
		minX = maxX = col;

		tmpX = col;				// MinX
		if( tmpX > 1 )
		{
			while( 1 )
			{
				tmpX--;
				if( tmpX < 1 )
				{
					break;
				}
				// Algorithm: check this row.
				row = lo->enemys_spotY[ cnt ];
				idx = row * MAX_COLS + tmpX;
				coll_type = lo->collision_array[ idx ];
				if( coll_type_impassable == coll_type )
				{
					break;
				}
				// Algorithm: check next row.
				row = lo->enemys_spotY[ cnt ] + 1;
				idx = row * MAX_COLS + tmpX;
				coll_type = lo->collision_array[ idx ];
				if( coll_type_passable == coll_type )
				{
					break;
				}

				minX = tmpX;
			}
		}

		tmpX = col;				// MaxX
		if( tmpX < lo->draw_cols - 1 )
		{
			while( 1 )
			{
				tmpX++;
				if( tmpX > lo->draw_cols - 1 )
				{
					break;
				}
				// Algorithm: check this row.
				row = lo->enemys_spotY[ cnt ];
				idx = row * MAX_COLS + tmpX;
				coll_type = lo->collision_array[ idx ];
				if( coll_type_impassable == coll_type )
				{
					break;
				}
				// Algorithm: check next row.
				row = lo->enemys_spotY[ cnt ] + 1;
				idx = row * MAX_COLS + tmpX;
				coll_type = lo->collision_array[ idx ];
				if( coll_type_passable == coll_type )
				{
					break;
				}

				maxX = tmpX;
			}
		}

		lo->enemys_minX[ cnt ] = minX;
		lo->enemys_maxX[ cnt ] = maxX;
	}

	// If player is invincible then "replace" any pits.
	if( invincible )
	{
		row = MAX_ROWS - 1;
		for( col = 1; col < lo->draw_cols; col++ )
		{
			idx = row * MAX_COLS + col;

			tile_type = lo->drawtiles_array[ idx ];
			coll_type = lo->collision_array[ idx ];

			if( tile_type_blankGap == tile_type )
			{
				//lo->drawtiles_array[ idx ] = tile_type_gridline;
			}
			if( coll_type_passable == coll_type )
			{
				lo->collision_array[ idx ] = coll_type_impassable;
			}
		}
	}
}

void engine_level_manager_load_level( const unsigned char tutorial, const unsigned char world, const unsigned char round, unsigned char invincible, unsigned char difficulty )
{
	unsigned char halve;
	unsigned char level;
	unsigned char index;

	if( tutorial )
	{
		const unsigned char *data = tutorialdata[ round ];
		const unsigned char bank = tutorialbank[ round ];
		const unsigned char size = tutorialsize[ round ];
		load_level( data, bank, size, invincible, difficulty );
		return;
	}

	halve = TOT_WORLDS / 2 * MAX_ROUNDS;
	level = world * MAX_ROUNDS + round;
	index = 0;

	if( level >= halve )
	{
		index = level - halve;
	}
	else
	{
		index = level;
	}

	if( level < halve )
	{
		const unsigned char *data = levelAAdata[ index ];
		const unsigned char bank = levelAAbank[ index ];
		const unsigned char size = levelAAsize[ index ];
		load_level( data, bank, size, invincible, difficulty );
	}
	else
	{
		const unsigned char *data = levelBBdata[ index ];
		const unsigned char bank = levelBBbank[ index ];
		const unsigned char size = levelBBsize[ index ];
		load_level( data, bank, size, invincible, difficulty );
	}
}

void engine_level_manager_draw_level()
{
	struct_level_object *lo = &global_level_object;
	unsigned char row, col;
	for( row = 0; row < MAX_ROWS; row++ )
	{
		for( col = 0; col < lo->draw_cols; col++ )
		{
			draw_tiles( col, row );
		}
	}
}

void engine_level_manager_draw_section()
{
	struct_level_object *lo = &global_level_object;
	unsigned char row, col;
	for( row = 10; row < 12; row++ )
	{
		//for( col = 1; col < lo->draw_cols - 1; col++ )
		for( col = 5; col < 12; col++ )
		{
			draw_tiles( col, row );
		}
	}
}

void engine_level_manager_draw_level_column( unsigned char column )
{
	unsigned char x, y;

	x = column;
	for( y = 0; y < MAX_ROWS; y++ )
	{
		draw_tiles( x, y );
	}
}
void engine_level_manager_draw_level_column_side( unsigned side_type, unsigned char column )
{
	struct_level_object *lo = &global_level_object;
	unsigned char x, y, tile;
	unsigned int idx;

	x = column;
	for( y = 0; y < MAX_ROWS; y++ )
	{
		idx = y * lo->draw_cols + x;
		//tile = tiles_map[ index ];
		tile = lo->drawtiles_array[ idx ];
		//tile = tiles_mat[ y ][ x ];

		if( tile_type_blankGap != tile )
		{
			engine_tile_manager_draw_tile_side( side_type, tile, x * 2, y * 2 );
		}
	}
}

void engine_level_manager_draw_blank( unsigned char x, unsigned char y )
{
	engine_tile_manager_draw_tile( tile_type_blankGap, x * 2, y * 2 );
}

void engine_level_manager_get_collision( unsigned char *coll_type, unsigned char x, unsigned char y )
{
	struct_level_object *lo = &global_level_object;
	unsigned int idx;

	// If player greater than max rows then must have fallen in pit i.e. passable.
	if( y >= MAX_ROWS )
	{
		*coll_type = coll_type_passable;
		return;
	}

	idx = y * lo->draw_cols + x;
	*coll_type = lo->collision_array[ idx ];
}

static void draw_tiles( unsigned char x, unsigned char y )
{
	struct_level_object *lo = &global_level_object;
	unsigned char tile;
	unsigned int idx;

	idx = y * lo->draw_cols + x;
	tile = lo->drawtiles_array[ idx ];

	//if( tile_type_blankGap != tile )
	//{
		engine_tile_manager_draw_tile( tile, x * 2, y * 2 );
	//}
}
static void setup_player( unsigned char index )
{
	struct_level_object *lo = &global_level_object;
	lo->player_spot = index;
}
static void setup_enemyX( enum_sprite_type sprite_type, unsigned char enemy, unsigned char tile, unsigned char row, unsigned char col )
{
	struct_level_object *lo = &global_level_object;

	lo->enemys_type[ enemy ] = sprite_type;
	lo->enemys_spotY[ enemy ] = row;
	lo->enemys_spotX[ enemy ] = col;

	lo->enemys_action[ enemy ] = action_type_chase;
	if( 'a' == tile || 'b' == tile || 'c' == tile || 'd' == tile )
	{
		lo->enemys_action[ enemy ] = action_type_guard;
	}
}
