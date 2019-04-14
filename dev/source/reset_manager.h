#ifndef _RESET_MANAGER_H_
#define _RESET_MANAGER_H_

#include "reset_object.h"

// Global variable.
extern struct_reset_object global_reset_object;

// Methods.
void engine_reset_manager_load( unsigned char frame );
void engine_reset_manager_reset();
unsigned char engine_reset_manager_update();

#endif//__RESET_MANAGER_H_
