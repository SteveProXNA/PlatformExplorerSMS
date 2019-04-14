#ifndef _ENEMYK_OBJECT_H_
#define _ENEMYK_OBJECT_H_

#include "enum_manager.h"

typedef struct tag_struct_enemy_master
{
	unsigned char max_enemies;

} struct_enemy_master;

// Enemies:
// EnemyA	Dave	move: discrete
// EnemyB	Alex	move: continuous
// EnemyC	Mike	move: discrete
// EnemyD	Eddie	move: continuous

typedef struct tag_struct_enemy_object
{
	enum_sprite_type sprite_type;
	enum_action_type action_type;
	enum_move_type curr_move_type;
	enum_move_type next_move_type;
	unsigned char spotX, spotY;
	unsigned char posnX, posnY;
	unsigned char startX;
	unsigned char drawX, drawY;
	unsigned char leftX, rghtX;
	unsigned char minX, maxX;
	unsigned char velX;
	unsigned char wait, loop;
	unsigned char walkCount;
	unsigned char walkTimer;
	unsigned char walkFlag;

} struct_enemy_object;

#endif//_ENEMYK_OBJECT_H_