#ifndef _HACK_MANAGER_H_
#define _HACK_MANAGER_H_

#include "hack_object.h"

void engine_hack_manager_init();
void engine_hack_manager_invert();

// Global variable.
extern struct_hack_object global_hack_object;

#endif//_HACK_MANAGER_H_