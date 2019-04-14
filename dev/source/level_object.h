#ifndef _LEVEL_OBJECT_H_
#define _LEVEL_OBJECT_H_

#include "global_manager.h"

typedef struct tag_struct_level_object
{
	unsigned char collision_array[ MAX_ROWS * MAX_COLS ];
	unsigned char drawtiles_array[ MAX_ROWS * MAX_COLS ];
	unsigned int load_cols;
	unsigned int draw_cols;
	signed char exit_spotX, exit_spotY;		// Compatible with collX, collY
	unsigned char gem_level;
	unsigned int player_spot;
	unsigned int enemys_spotX[ MAX_ENEMIES ];
	unsigned int enemys_spotY[ MAX_ENEMIES ];
	unsigned char enemys_type[ MAX_ENEMIES ];
	unsigned char enemys_minX[ MAX_ENEMIES ];
	unsigned char enemys_maxX[ MAX_ENEMIES ];
	unsigned char enemys_action[ MAX_ENEMIES ];
	unsigned char enemyCount;

} struct_level_object;

extern const unsigned char *tutorialdata[];
extern const unsigned char tutorialsize[];
extern const unsigned char tutorialbank[];

extern const unsigned char *levelAAdata[];
extern const unsigned char levelAAsize[];
extern const unsigned char levelAAbank[];

extern const unsigned char *levelBBdata[];
extern const unsigned char levelBBsize[];
extern const unsigned char levelBBbank[];

#endif//_LEVEL_OBJECT_H_