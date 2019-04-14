#include "dead_screen.h"
#include "global_manager.h"
#include "hack_manager.h"
#include "enum_manager.h"
#include "memo_manager.h"
#include "delay_manager.h"
#include "player_manager.h"
#include "enemy_manager.h"
#include "score_manager.h"
#include "audio_manager.h"

#define DEAD_SCREEN_DELAY		150
#define DEAD_DECAPITATE			20

void screen_dead_screen_load()
{
	struct_hack_object *ho = &global_hack_object;
	struct_player_object *po = &global_player_object;

	engine_audio_manager_music_stop();
	if( ho->hack_delayspeed )
	{
		engine_audio_manager_sound_death();
	}

	engine_delay_manager_load( DEAD_SCREEN_DELAY );

	// If player jumps through ceiling and dies then ouch!
	if( po->posnY < 2 * TILE_HIGH )
	{
		po->posnY = DEAD_DECAPITATE;
	}

	engine_memo_manager_draw_dead();
	engine_score_manager_update_lives( -1 );
}

void screen_dead_screen_update( unsigned char *screen_type )
{
	struct_player_object *po = &global_player_object;
	struct_score_object *so = &global_score_object;
	unsigned char delay;

	// Draw enemies first!
	engine_enemyX_manager_draw_enemys();

	// Don't draw if player in pit.
	if( po->posnY >= 0 )
	{
		engine_player_manager_draw();
	}

	delay = engine_delay_manager_update();
	if( delay )
	{
		if( so->num_lives <= 0 )
		{
			*screen_type = screen_type_cont;
			return;
		}

		*screen_type = screen_type_ready;
		return;
	}

	*screen_type = screen_type_dead;
}