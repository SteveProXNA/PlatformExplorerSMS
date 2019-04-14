#include "delay_manager.h"
#include "hack_manager.h"

// Global variable.
struct_delay_object global_delay_object;

void engine_delay_manager_load( unsigned int delay )
{
	struct_delay_object *dObj = &global_delay_object;
	struct_hack_object *ho = &global_hack_object;
	dObj->delay_delay = delay;
	dObj->delay_timer = 0;

	// Used for testing so no wait.
	if( 0 == ho->hack_delayspeed )
	{
		dObj->delay_delay = 0;
	}
}

unsigned char engine_delay_manager_update()
{
	struct_delay_object *dObj = &global_delay_object;
	unsigned char test;

	dObj->delay_timer++;
	test = dObj->delay_timer >= dObj->delay_delay;
	if( test )
	{
		dObj->delay_timer = 0;
	}

	return test;
}