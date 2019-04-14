#include "reset_manager.h"
#include "font_manager.h"

// Global variable.
struct_reset_object global_reset_object;

// Methods.
void engine_reset_manager_load( unsigned char frame )
{
	struct_reset_object *ro = &global_reset_object;
	ro->reset_frame = frame;
	engine_reset_manager_reset();
}

void engine_reset_manager_reset()
{
	struct_reset_object *ro = &global_reset_object;
	ro->reset_timer = 0;
}

unsigned char engine_reset_manager_update()
{
	struct_reset_object *ro = &global_reset_object;
	unsigned char test;

	ro->reset_timer++;
	test = ro->reset_timer >= ro->reset_frame;
	if( test )
	{
		ro->reset_timer = 0;
	}

	return test;
}