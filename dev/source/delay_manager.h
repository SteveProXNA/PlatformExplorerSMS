#ifndef _DELAY_MANAGER_H_
#define _DELAY_MANAGER_H__

#include "delay_object.h"

// Global variable.
extern struct_delay_object global_delay_object;

// Methods.
void engine_delay_manager_load( unsigned int delay );
unsigned char engine_delay_manager_update();

#endif//_DELAY_MANAGER_H_