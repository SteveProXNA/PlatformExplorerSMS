#ifndef _ENUM_MANAGER_H_
#define _ENUM_MANAGER_H_

typedef enum tag_enum_screen_type
{
	screen_type_none = 0,
	screen_type_splash = 1,
	screen_type_intro = 2,
	screen_type_begin = 3,
	screen_type_title = 4,
	screen_type_entry = 5,
	screen_type_diff = 6,
	screen_type_pace = 7,
	screen_type_level = 8,
	screen_type_view = 9,
	screen_type_init = 10,
	screen_type_ready = 11,
	screen_type_load = 12,
	screen_type_play = 13,
	screen_type_reset = 14,
	screen_type_pass = 15,
	screen_type_gems = 16,
	screen_type_dead = 17,
	screen_type_cont = 18,
	screen_type_over = 19,
	screen_type_beat = 20,
	screen_type_test = 21,
	screen_type_func = 22,

} enum_screen_type;

typedef enum tag_enum_diff_type
{
	diff_type_easy = 0,
	diff_type_hard = 1,

} enum_diff_type;

typedef enum tag_enum_pace_type
{
	pace_type_slow = 0,
	pace_type_fast = 1,

} enum_pace_type;

typedef enum tag_enum_tile_type
{
	tile_type_blankGap = 0,
	tile_type_blockerA = 1,
	tile_type_blockerB = 2,
	tile_type_blockerC = 3,
	tile_type_blockerD = 4,
	tile_type_blockerE = 5,
	tile_type_blockerF = 6,
	tile_type_blockerG = 7,
	tile_type_blockerH = 8,
	tile_type_blockerI = 9,
	tile_type_platform = 10,
	tile_type_exitgame = 11,
	tile_type_gemscore = 12,
	tile_type_gempower = 13,
	tile_type_emptyspc = 14,
	tile_type_gridline = 15,

} enum_tile_type;

typedef enum tag_enum_tiny_type
{
	tile_type_blockA = 108,
	tile_type_blockB = 109,
	tile_type_blockC = 124,
	tile_type_heart = 125,

} enum_tiny_type;

typedef enum tag_enum_coll_type
{
	coll_type_passable = 0,
	coll_type_impassable = 1,
	coll_type_platform = 2,

} enum_coll_type;

typedef enum tag_enum_sprite_type
{
	sprite_type_enemyA = 0,
	sprite_type_enemyB = 1,
	sprite_type_enemyC = 2,
	sprite_type_enemyD = 3,
	sprite_type_player = 4,
	sprite_type_unknown = 5,

} enum_sprite_type;

typedef enum tag_enum_side_type
{
	side_type_left = 0,
	side_type_rght = 1,

} enum_side_type;

typedef enum tag_enum_move_type
{
	move_type_left = 0,
	move_type_idle = 1,
	move_type_rght = 2,

} enum_move_type;

typedef enum tag_enum_action_type
{
	action_type_chase = 0,
	action_type_guard = 1,
	action_type_empty = 2,
	action_type_unknown = 3,

} enum_action_type;

typedef enum tag_enum_event_type
{
	event_type_none = 0,
	event_type_exit = 1,
	event_type_gemscorehi = 2,
	event_type_gempowerhi = 3,
	event_type_gemscorelo = 4,
	event_type_gempowerlo = 5,

} enum_event_type;

typedef enum tag_enum_stage_type
{
	event_stage_start = 0,
	event_stage_pause = 1,

} enum_stage_type;

#endif//_ENUM_MANAGER_H_