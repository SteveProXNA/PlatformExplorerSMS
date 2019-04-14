#include "hack_manager.h"
#include "global_manager.h"
#include "enum_manager.h"

#define PEEK( addr)			(* ( unsigned char *)( addr ) )
#define POKE( addr, data )	(* ( unsigned char *)( addr ) = ( data ) )

#define HACKER_START		0x0050

// Global variable.
struct_hack_object global_hack_object;

void engine_hack_manager_init()
{
	struct_hack_object *ho = &global_hack_object;

	ho->hack_delayspeed = 0;
//	ho->hack_localcheat = 0;
	ho->hack_invincible = 0;
	ho->hack_difficulty = 0;
	ho->hack_game_speed = 0;
	ho->hack_world = 0;
	ho->hack_round = 0;
	ho->hack_music = 0;
	ho->hack_sound = 0;
	ho->hack_enemy = 0;

#ifndef _CONSOLE

	ho->hack_delayspeed = PEEK( HACKER_START - 1 );		// 0x004F		// Used during dev disables screen delays.
	ho->hack_invincible = PEEK( HACKER_START + 0 );		// 0x0050		// Non-zero value enables auto invincible.
	ho->hack_difficulty = PEEK( HACKER_START + 1 );		// 0x0051		// Set value to 1=Hard otherwise use Easy.
	ho->hack_game_speed = PEEK( HACKER_START + 2 );		// 0x0052		// Set value to 1=Slow otherwise use Fast.
	ho->hack_world = PEEK( HACKER_START + 3 );			// 0x0053		// Set start world no to zero-based value.
	ho->hack_round = PEEK( HACKER_START + 4 );			// 0x0054		// Set start round no to zero-based value.
	ho->hack_music = PEEK( HACKER_START + 5 );			// 0x0055		// Set 0=music to play otherwise disabled.
	ho->hack_sound = PEEK( HACKER_START + 6 );			// 0x0056		// Set 0=sound to play otherwise disabled.
	ho->hack_enemy = PEEK( HACKER_START + 7 );			// 0x0057		// Set value non-zero to disable movement.

#endif

}

void engine_hack_manager_invert()
{
	struct_hack_object *ho = &global_hack_object;
	ho->hack_delayspeed = !ho->hack_delayspeed;

	// Difficulty.
	if( ho->hack_difficulty > diff_type_hard )
	{
		ho->hack_difficulty = diff_type_easy;
	}

	// Game Speed.
	if( ho->hack_game_speed > pace_type_fast )
	{
		ho->hack_game_speed = pace_type_slow;
	}

	// World.
	if( 0 != ho->hack_world )
	{
		if( ho->hack_world > MAX_WORLDS )
		{
			ho->hack_world = MAX_WORLDS;
		}

		// Zero-based index.
		ho->hack_world -= 1;
	}

	// Round.
	if( 0 != ho->hack_round )
	{
		if( ho->hack_round > MAX_ROUNDS )
		{
			ho->hack_round = MAX_ROUNDS;
		}

		// Zero-based index.
		ho->hack_round -= 1;
	}

	// Invert default values.
	ho->hack_game_speed = !ho->hack_game_speed;
	ho->hack_music = !ho->hack_music;
	ho->hack_sound = !ho->hack_sound;
	ho->hack_enemy = !ho->hack_enemy;
}