#include "game_manager.h"
#include "global_manager.h"
#include "locale_manager.h"
#include "enum_manager.h"
#include "font_manager.h"

// Global variable.
struct_game_object global_game_object;

static unsigned char *diff_text[ 2 ] = { LOCALE_DIFF_EASY, LOCALE_DIFF_HARD };

void engine_game_manager_init()
{
	struct_game_object *go = &global_game_object;
	go->invincible = 0;
	go->tutorial = 1;
	go->world_no = 0;
	go->round_no = 0;
}

void engine_game_manager_draw()
{
	struct_game_object *go = &global_game_object;
	engine_font_manager_draw_text( diff_text[ go->difficulty ], SCREEN_TILE_LEFT, 1 );

	if( go->tutorial )
	{
		engine_font_manager_draw_text( LOCALE_TUTORIAL_NO, 2, GAME_DATA_TOP );
	}
	else
	{
		engine_font_manager_draw_text( count_text[ go->world_no ], 2, GAME_DATA_TOP );
	}

	engine_font_manager_draw_text( count_text[ go->round_no ], 2, GAME_DATA_BOT );
}