#ifndef _PLAYER_OBJECT_H_
#define _PLAYER_OBJECT_H_

#include "enum_manager.h"
#include <stdbool.h>

typedef struct tag_struct_player_object
{
	enum_move_type player_move_type;
	int spotX, spotY;
	int posnX, posnY;
	int drawX, drawY;
	int collX, collY;
	int prevX, prevY;
	int commX, commY;
	int velX, velY;
	signed char deltaX, deltaY;
	signed char player_idxX;
	signed char player_idxY;
	signed char player_grav;
	int depthX, depthY;
	bool isOnGround;
	bool isJumping;
	bool wasJumping;
	unsigned char jumpFrame;
	signed char coll_horz, coll_vert;
	signed char coll_left, coll_rght, coll_topX, coll_botX;
	int previousBottom;
	unsigned char anim_index, anim_start, anim_maxim;
	signed char anim_frame, anim_count;
	signed char kill_idx;

} struct_player_object;

#endif//_PLAYER_OBJECT_H_