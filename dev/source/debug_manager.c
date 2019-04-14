#include "debug_manager.h"
#include "enum_manager.h"
#include "tile_manager.h"

void engine_debug_manager_draw_grid()
{
	unsigned char x, y;
	for( y = 0; y < 24; y += 2 )
	{
		for( x = 0; x < 32; x += 2 )
		{
			engine_tile_manager_draw_tile( tile_type_gridline, x, y );
		}
	}
}