#include "func_screen.h"
#include "hack_manager.h"
#include "enum_manager.h"
#include "font_manager.h"
#include "input_manager.h"
#include "player_manager.h"

void screen_func_screen_load()
{
	engine_font_manager_draw_text("TEST PLAYER MANAGER", 3, 0);
}

void screen_func_screen_update( unsigned char *screen_type )
{
	*screen_type = screen_type_func;
}