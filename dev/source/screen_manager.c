#include "screen_manager.h"
#include "global_manager.h"
#include "enum_manager.h"

// Screens
#include "none_screen.h"
#include "splash_screen.h"
#include "intro_screen.h"
#include "begin_screen.h"
#include "title_screen.h"
#include "entry_screen.h"
#include "diff_screen.h"
#include "pace_screen.h"
#include "level_screen.h"
#include "view_screen.h"
#include "init_screen.h"
#include "load_screen.h"
#include "ready_screen.h"
#include "play_screen.h"
#include "reset_screen.h"
#include "pass_screen.h"
#include "gems_screen.h"
#include "dead_screen.h"
#include "cont_screen.h"
#include "over_screen.h"
#include "beat_screen.h"
#include "test_screen.h"
#include "func_screen.h"

static void( *load_method[ MAX_SCREEENS ] )( );
static void( *update_method[ MAX_SCREEENS ] )( unsigned char *screen_type );

static unsigned char curr_screen_type;
static unsigned char next_screen_type;

void engine_screen_manager_init( unsigned char open_screen_type )
{
	next_screen_type = open_screen_type;
	curr_screen_type = screen_type_none;

	// Set load methods.
	load_method[ screen_type_none ] = screen_none_screen_load;
	load_method[ screen_type_splash ] = screen_splash_screen_load;
	load_method[ screen_type_intro ] = screen_intro_screen_load;
	load_method[ screen_type_begin ] = screen_begin_screen_load;
	load_method[ screen_type_title ] = screen_title_screen_load;
	load_method[ screen_type_entry ] = screen_entry_screen_load;
	load_method[ screen_type_diff ] = screen_diff_screen_load;
	load_method[ screen_type_pace ] = screen_pace_screen_load;
	load_method[ screen_type_level ] = screen_level_screen_load;
	load_method[ screen_type_view ] = screen_view_screen_load;
	load_method[ screen_type_init ] = screen_init_screen_load;
	load_method[ screen_type_load ] = screen_load_screen_load;
	load_method[ screen_type_ready ] = screen_ready_screen_load;
	load_method[ screen_type_play ] = screen_play_screen_load;
	load_method[ screen_type_reset ] = screen_reset_screen_load;
	load_method[ screen_type_pass ] = screen_pass_screen_load;
	load_method[ screen_type_gems ] = screen_gems_screen_load;
	load_method[ screen_type_dead ] = screen_dead_screen_load;
	load_method[ screen_type_cont ] = screen_cont_screen_load;
	load_method[ screen_type_over ] = screen_over_screen_load;
	load_method[ screen_type_beat ] = screen_beat_screen_load;
	load_method[ screen_type_test ] = screen_test_screen_load;
	load_method[ screen_type_func ] = screen_func_screen_load;

	// Set update methods.
	update_method[ screen_type_none ] = screen_none_screen_update;
	update_method[ screen_type_splash ] = screen_splash_screen_update;
	update_method[ screen_type_intro ] = screen_intro_screen_update;
	update_method[ screen_type_begin ] = screen_begin_screen_update;
	update_method[ screen_type_title ] = screen_title_screen_update;
	update_method[ screen_type_entry ] = screen_entry_screen_update;
	update_method[ screen_type_diff ] = screen_diff_screen_update;
	update_method[ screen_type_pace ] = screen_pace_screen_update;
	update_method[ screen_type_level ] = screen_level_screen_update;
	update_method[ screen_type_view ] = screen_view_screen_update;
	update_method[ screen_type_init ] = screen_init_screen_update;
	update_method[ screen_type_load ] = screen_load_screen_update;
	update_method[ screen_type_ready ] = screen_ready_screen_update;
	update_method[ screen_type_play ] = screen_play_screen_update;
	update_method[ screen_type_reset ] = screen_reset_screen_update;
	update_method[ screen_type_pass ] = screen_pass_screen_update;
	update_method[ screen_type_gems ] = screen_gems_screen_update;
	update_method[ screen_type_dead ] = screen_dead_screen_update;
	update_method[ screen_type_cont ] = screen_cont_screen_update;
	update_method[ screen_type_over ] = screen_over_screen_update;
	update_method[ screen_type_beat ] = screen_beat_screen_update;
	update_method[ screen_type_test ] = screen_test_screen_update;
	update_method[ screen_type_func ] = screen_func_screen_update;

	// Initialize screens.
	screen_level_screen_init();
}

void engine_screen_manager_update()
{
	if( curr_screen_type != next_screen_type )
	{
		curr_screen_type = next_screen_type;
		load_method[ curr_screen_type ]();
	}

	update_method[ curr_screen_type ]( &next_screen_type );
}