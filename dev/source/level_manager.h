#ifndef _LEVEL_MANAGER_H_
#define _LEVEL_MANAGER_H__

#include "level_object.h"

// Global variable.
extern struct_level_object global_level_object;

void engine_level_manager_init_level();
void engine_level_manager_load_level( const unsigned char tutorial, const unsigned char world, const unsigned char round, unsigned char invincible, unsigned char difficulty );
void engine_level_manager_draw_level();
void engine_level_manager_draw_section();
void engine_level_manager_draw_level_column( unsigned char column );
void engine_level_manager_draw_level_column_side( unsigned side_type, unsigned char column );
void engine_level_manager_draw_blank( unsigned char x, unsigned char y );
void engine_level_manager_get_collision( unsigned char *coll_type, unsigned char x, unsigned char y );

#endif//_LEVEL_MANAGER_H_