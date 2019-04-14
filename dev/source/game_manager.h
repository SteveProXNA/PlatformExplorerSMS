#ifndef _GAME_MANAGER_H_
#define _GAME_MANAGER_H_

#include "game_object.h"

// Global variable.
extern struct_game_object global_game_object;

void engine_game_manager_init();
void engine_game_manager_draw();

#endif//_GAME_MANAGER_H_