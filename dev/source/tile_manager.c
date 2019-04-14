#include "tile_manager.h"
#include "_sms_manager.h"
#include "global_manager.h"
#include "enum_manager.h"
#include "..\gfx.h"
#include "..\banks\bank3.h"
#include <stdlib.h>

#define BASE_TILE_OFFSET	64

static const unsigned char *guard_tiles[ MAX_ENEMIES ] =
{
	guardA_idle__tilemap__bin,
	guardB_idle__tilemap__bin,
	guardC_idle__tilemap__bin,
	guardD_idle__tilemap__bin,
};

void engine_tile_manager_draw_tile( unsigned char index, unsigned char x, unsigned char y )
{
	const unsigned char *pnt = back_tiles__tilemap__bin;
	index = BASE_TILE_OFFSET + ( index / 8 ) * 16 + index * 2;

	devkit_SMS_setNextTileatXY( x + 0, y + 0 );	devkit_SMS_setTile( *pnt + index + 0 );
	devkit_SMS_setNextTileatXY( x + 1, y + 0 );	devkit_SMS_setTile( *pnt + index + 1 );
	devkit_SMS_setNextTileatXY( x + 0, y + 1 );	devkit_SMS_setTile( *pnt + index + 16 );
	devkit_SMS_setNextTileatXY( x + 1, y + 1 );	devkit_SMS_setTile( *pnt + index + 17 );
}

void engine_tile_manager_draw_guard( unsigned char x, unsigned char y, unsigned char type )
{
	const unsigned char *pnt = guard_tiles[ type ];
	devkit_SMS_mapROMBank( guardA_idle__tilemap__bin_bank );

	devkit_SMS_setNextTileatXY( x + 0, y + 0 );		devkit_SMS_setTile( *pnt + 0 );
	devkit_SMS_setNextTileatXY( x + 1, y + 0 );		devkit_SMS_setTile( *pnt + 1 );
	devkit_SMS_setNextTileatXY( x + 0, y + 1 );		devkit_SMS_setTile( *pnt + 2 );
	devkit_SMS_setNextTileatXY( x + 1, y + 1 );		devkit_SMS_setTile( *pnt + 3 );
	devkit_SMS_setNextTileatXY( x + 0, y + 2 );		devkit_SMS_setTile( *pnt + 4 );
	devkit_SMS_setNextTileatXY( x + 1, y + 2 );		devkit_SMS_setTile( *pnt + 5 );
	devkit_SMS_setNextTileatXY( x + 0, y + 3 );		devkit_SMS_setTile( *pnt + 6 );
	devkit_SMS_setNextTileatXY( x + 1, y + 3 );		devkit_SMS_setTile( *pnt + 7 );
}

void engine_tile_manager_draw_small( unsigned char x, unsigned char y, unsigned char tile )
{
	const unsigned char *pnt = back_tiles__tilemap__bin;
	devkit_SMS_setNextTileatXY( x + 0, y + 0 );
	devkit_SMS_setTile( *pnt + tile );
}

void engine_tile_manager_draw_tile_side( unsigned char side_type, unsigned char index, unsigned char x, unsigned char y )
{
	const unsigned char *pnt = back_tiles__tilemap__bin;
	index = BASE_TILE_OFFSET + ( index / 8 ) * 16 + index * 2;

	if( side_type_left == side_type )
	{
		devkit_SMS_setNextTileatXY( x + 0, y + 0 );	devkit_SMS_setTile( *pnt + index + 0 );
		devkit_SMS_setNextTileatXY( x + 0, y + 1 );	devkit_SMS_setTile( *pnt + index + 16 );
	}
	else if( side_type_rght == side_type )
	{
		devkit_SMS_setNextTileatXY( x + 1, y + 0 );	devkit_SMS_setTile( *pnt + index + 1 );
		devkit_SMS_setNextTileatXY( x + 1, y + 1 );	devkit_SMS_setTile( *pnt + index + 17 );
	}
}

void engine_tile_manager_get_tile( enum_tile_type *tile_type, unsigned char tile, unsigned char difficulty )
{
	if( '#' == tile )
	{
		*tile_type = rand() % MAX_BLOCK_TILES + 1;
		return;
	}
	if( '@' == tile || '-' == tile )
	{
		*tile_type = tile_type_platform;
		return;
	}
	if( '$' == tile )
	{
		// $ Optional platform:
		if( diff_type_hard == difficulty )
		{
			*tile_type = tile_type_blankGap;
			return;
		}

		*tile_type = tile_type_platform;
		return;
	}
	if( 'X' == tile )
	{
		*tile_type = tile_type_exitgame;
		return;
	}
	if( 'G' == tile )
	{
		*tile_type = tile_type_gemscore;
		return;
	}
	if( 'P' == tile )
	{
		*tile_type = tile_type_gempower;
		return;
	}

	*tile_type = tile_type_blankGap;
}

void engine_tile_manager_get_collision( enum_coll_type *coll_type, unsigned char tile, unsigned char difficulty )
{
	if( '#' == tile )
	{
		*coll_type = coll_type_impassable;
		return;
	}
	if( '@' == tile || '-' == tile )
	{
		*coll_type = coll_type_platform;
		return;
	}
	if( '$' == tile )
	{
		// $ diff=Easy visible otherwise diff=Hard hidden.
		if( diff_type_hard == difficulty )
		{
			*coll_type = coll_type_passable;
			return;
		}

		*coll_type = coll_type_platform;
		return;
	}

	*coll_type = coll_type_passable;
}

void engine_tile_manager_get_sprite( enum_sprite_type *sprite_type, unsigned char tile )
{
	if( '1' == tile )
	{
		*sprite_type = sprite_type_player;
		return;
	}
	if( 'A' == tile || 'a' == tile )
	{
		*sprite_type = sprite_type_enemyA;
		return;
	}
	if( 'B' == tile || 'b' == tile )
	{
		*sprite_type = sprite_type_enemyB;
		return;
	}
	if( 'C' == tile || 'c' == tile )
	{
		*sprite_type = sprite_type_enemyC;
		return;
	}
	if( 'D' == tile || 'd' == tile )
	{
		*sprite_type = sprite_type_enemyD;
		return;
	}

	*sprite_type = sprite_type_unknown;
}