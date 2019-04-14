#include "score_manager.h"
#include "global_manager.h"
#include "locale_manager.h"
#include "font_manager.h"
#include "tile_manager.h"

// Global variable.
struct_score_object global_score_object;

void engine_score_manager_init( unsigned char difficulty )
{
	struct_score_object *so = &global_score_object;
	so->tot_lives = NUMBER_LIVES - difficulty;
	so->gem_count = 0;
	so->gem_total = 0;

	engine_score_manager_reset_gems();
	engine_score_manager_reset_lives();
}

void engine_score_manager_reset_gems()
{
	struct_score_object *so = &global_score_object;
	so->gem_level = 0;
}

void engine_score_manager_reset_lives()
{
	struct_score_object *so = &global_score_object;
	so->num_lives = so->tot_lives;
}

void engine_score_manager_update_gems()
{
	struct_score_object *so = &global_score_object;
	so->gem_count++;
	so->gem_level++;
	so->gem_total++;

	if( so->gem_total > MAX_GEMS_COLLECT )
	{
		so->gem_total = MAX_GEMS_COLLECT;
	}
}

void engine_score_manager_bonus_gems()
{
	struct_score_object *so = &global_score_object;
	so->gem_count += MAX_GEMS_BONUSES;
	so->gem_total += MAX_GEMS_BONUSES;

	if( so->gem_total > MAX_GEMS_COLLECT )
	{
		so->gem_total = MAX_GEMS_COLLECT;
	}
}

void engine_score_manager_update_lives( signed char delta )
{
	struct_score_object *so = &global_score_object;
	if( so->num_lives > 0 && so->num_lives <= MAMNUM_LIVES )
	{
		so->num_lives += delta;
		engine_score_manager_draw_lives();
	}
}

void engine_score_manager_draw_lives()
{
	struct_score_object *so = &global_score_object;
	unsigned char index = so->num_lives;

	engine_tile_manager_draw_tile( tile_type_gempower, 30, GAME_DATA_TOP );
	engine_font_manager_draw_text( lives_text[ index ], 31, GAME_DATA_BOT );
}

void engine_score_manager_draw_score()
{
	engine_score_manager_draw_score_at( 31, 2 );
}
void engine_score_manager_draw_score_at( unsigned char x, unsigned char y )
{
	struct_score_object *so = &global_score_object;
	engine_font_manager_draw_data( so->gem_total, x, y );
}