#include "anim_manager.h"
#include "anim_object.h"
#include "_sms_manager.h"
#include "global_manager.h"
#include "enum_manager.h"

#define PLAYER_TILE_IDLE		PLAYER_SPRITE_TILE
#define PLAYER_TILE_LEFT		PLAYER_SPRITE_TILE + 1 * SPRITE_TILES_NUMBER
#define PLAYER_TILE_RGHT		PLAYER_SPRITE_TILE + 6 * SPRITE_TILES_NUMBER
#define TESTER_TILE_IDLE		TESTER_SPRITE_TILE
#define TESTER_TILE_RGHT		TESTER_SPRITE_TILE + 1 * SPRITE_TILES_NUMBER
#define ENEMYX_TILE_IDLE		ENEMYX_SPRITE_TILE

// Private helper methods.
static void player_load( unsigned char index, unsigned int tile );
static void enemyA_load( unsigned char index, unsigned int tile );
static void enemyB_load( unsigned char index, unsigned int tile );
static void enemyC_load( unsigned char index, unsigned int tile );
static void enemyD_load( unsigned char index, unsigned int tile );

void engine_anim_manager_player_load_idle()
{
	player_load( 0, PLAYER_TILE_IDLE );
}

void engine_anim_manager_player_load_move()
{
	unsigned char index, loop;
	unsigned int tile;

	for( loop = 0; loop < ANIMATE_MOVE_MAX; loop++ )
	{
		index = ANIMATE_IDX_LEFT + loop;
		tile = PLAYER_TILE_LEFT + loop * SPRITE_TILES_NUMBER;
		player_load( index, tile );

		index = ANIMATE_IDX_RGHT + loop;
		tile = PLAYER_TILE_RGHT + loop * SPRITE_TILES_NUMBER;
		player_load( index, tile );
	}
}

void engine_anim_manager_tester_load_anim()
{
	unsigned char index, loop;
	unsigned int tile;
	player_load( 0, TESTER_TILE_IDLE );

	for( loop = 0; loop < ANIMATE_MOVE_MAX; loop++ )
	{
		index = ANIMATE_IDX_RGHT + loop;
		tile = TESTER_TILE_RGHT + loop * SPRITE_TILES_NUMBER;
		player_load( index, tile );
	}
}

void engine_anim_manager_enemyX_load_idle()
{
	enemyA_load( 0, ENEMYX_TILE_IDLE + 0 * GUARDS_TILES_NUMBER );
	enemyB_load( 0, ENEMYX_TILE_IDLE + 1 * GUARDS_TILES_NUMBER );
	enemyC_load( 0, ENEMYX_TILE_IDLE + 2 * GUARDS_TILES_NUMBER );
	enemyD_load( 0, ENEMYX_TILE_IDLE + 3 * GUARDS_TILES_NUMBER );
}


// Private helper methods.
static void player_load( unsigned char index, unsigned int tile )
{
	const unsigned char *data = ( const unsigned char * ) player_anim_data[ index ];
	const unsigned char bank = ( const unsigned char ) player_anim_bank[ index ];

	devkit_SMS_mapROMBank( bank );
	devkit_SMS_loadPSGaidencompressedTiles( data, tile );
}

static void enemyA_load( unsigned char index, unsigned int tile )
{
	const unsigned char *data = ( const unsigned char * ) enemyA_anim_data[ index ];
	const unsigned char bank = ( const unsigned char ) enemyA_anim_bank[ index ];

	devkit_SMS_mapROMBank( bank );
	devkit_SMS_loadPSGaidencompressedTiles( data, tile );
}

static void enemyB_load( unsigned char index, unsigned int tile )
{
	const unsigned char *data = ( const unsigned char * ) enemyB_anim_data[ index ];
	const unsigned char bank = ( const unsigned char ) enemyB_anim_bank[ index ];

	devkit_SMS_mapROMBank( bank );
	devkit_SMS_loadPSGaidencompressedTiles( data, tile );
}

static void enemyC_load( unsigned char index, unsigned int tile )
{
	const unsigned char *data = ( const unsigned char * ) enemyC_anim_data[ index ];
	const unsigned char bank = ( const unsigned char ) enemyC_anim_bank[ index ];

	devkit_SMS_mapROMBank( bank );
	devkit_SMS_loadPSGaidencompressedTiles( data, tile );
}

static void enemyD_load( unsigned char index, unsigned int tile )
{
	const unsigned char *data = ( const unsigned char * ) enemyD_anim_data[ index ];
	const unsigned char bank = ( const unsigned char ) enemyD_anim_bank[ index ];

	devkit_SMS_mapROMBank( bank );
	devkit_SMS_loadPSGaidencompressedTiles( data, tile );
}