#ifndef _GLOBAL_MANAGER_H_
#define _GLOBAL_MANAGER_H_

#define MAX_SCREEENS			23
#define MAX_ENEMIES				4
#define MAX_BLOCK_TILES			9
#define MAX_SMALL_TILES			3

#define SPRITE_TILES_NUMBER		12
#define GUARDS_TILES_NUMBER		8

#define PLAYER_ANIMS_COUNT		5
#define PLAYER_SPRITE_TILE		256
#define TESTER_SPRITE_TILE		352
#define ENEMYX_SPRITE_TILE		388
#define INVALID_INDEX			-1

#define TOT_WORLDS				8
#define MAX_WORLDS				4		//8 - capacity
#define MAX_ROUNDS				10

#define MAX_ROWS				12
#define MAX_COLS				16

#define TILE_WIDE				16
#define TILE_HIGH				16

#define SCREEN_SIZE_WIDE		256
#define SCREEN_SIZE_HIGH		192

#define SCREEN_TILE_WIDE		32
#define SCREEN_TILE_HIGH		24
#define SCREEN_TILE_LEFT		2

// Easy:4 and Hard:3
#define NUMBER_LIVES			4
#define MAMNUM_LIVES			9
#define MAMNUM_TUNES			3

#define ENEMYS_COLL_EASY		8
#define ENEMYS_COLL_HARD		12

#define MIN_POSITION_X			24
#define MAX_POSITION_X			248
#define MAX_POSITION_Y			SCREEN_SIZE_HIGH + 2 * TILE_HIGH

#define MAX_GEMS_COLLECT		9999
#define MAX_GEMS_FREEMAN		20
#define MAX_GEMS_BONUSES		5
#define MEMO_SPRITE_TOP			32
#define MEMO_SPRITE_BOT			128

#define GAME_DATA_TOP			22
#define GAME_DATA_BOT			23

#define LOCAL_CHEAT_TOTAL		5
#define LOCAL_SELECT_TOTAL		3

#define ANIMATE_MOVE_MAX		5
#define ANIMATE_IDX_LEFT		1
#define ANIMATE_IDX_RGHT		6

// Global values.
extern unsigned char *count_text[];
extern unsigned char *lives_text[];

#endif//_GLOBAL_MANAGER_H_