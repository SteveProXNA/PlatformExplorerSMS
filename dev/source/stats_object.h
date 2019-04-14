#ifndef _STATS_OBJECT_H_
#define _STATS_OBJECT_H_

#include "global_manager.h"
#include "enum_manager.h"

typedef struct tag_struct_stats_object
{
	// 2x difficulty types: Easy + Hard.
	unsigned char collision_offsets[ 2 ];

	unsigned char enemys_velX[ MAX_ENEMIES ][ TOT_WORLDS ];
	unsigned char enemys_wait[ MAX_ENEMIES ][ TOT_WORLDS ];
	unsigned char enemys_walk[ MAX_ENEMIES ][ TOT_WORLDS ];

} struct_stats_object;

#endif//_STATS_OBJECT_H_