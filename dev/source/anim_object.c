#include "anim_object.h"

#include "..\banks\bank2.h"

// Player.
const unsigned char *player_anim_data[] =
{
	player_idle__tiles__psgcompr,
	player_run_left_01__tiles__psgcompr,
	player_run_left_02__tiles__psgcompr,
	player_run_left_03__tiles__psgcompr,
	player_run_left_04__tiles__psgcompr,
	player_run_left_05__tiles__psgcompr,
	player_run_rght_01__tiles__psgcompr,
	player_run_rght_02__tiles__psgcompr,
	player_run_rght_03__tiles__psgcompr,
	player_run_rght_04__tiles__psgcompr,
	player_run_rght_05__tiles__psgcompr,
};
const unsigned char player_anim_bank[] =
{
	player_idle__tiles__psgcompr_bank,
	player_run_left_01__tiles__psgcompr_bank,
	player_run_left_02__tiles__psgcompr_bank,
	player_run_left_03__tiles__psgcompr_bank,
	player_run_left_04__tiles__psgcompr_bank,
	player_run_rght_01__tiles__psgcompr_bank,
	player_run_rght_02__tiles__psgcompr_bank,
	player_run_rght_03__tiles__psgcompr_bank,
	player_run_rght_04__tiles__psgcompr_bank,
	player_run_rght_05__tiles__psgcompr_bank,
};

// EnemyA.
const unsigned char *enemyA_anim_data[] =
{
	enemyA_idle__tiles__psgcompr,
};
const unsigned char enemyA_anim_bank[] =
{
	enemyA_idle__tiles__psgcompr_bank,
};

// EnemyB.
const unsigned char *enemyB_anim_data[] =
{
	enemyB_idle__tiles__psgcompr,
};
const unsigned char enemyB_anim_bank[] =
{
	enemyB_idle__tiles__psgcompr_bank,
};

// EnemyC.
const unsigned char *enemyC_anim_data[] =
{
	enemyC_idle__tiles__psgcompr,
};
const unsigned char enemyC_anim_bank[] =
{
	enemyC_idle__tiles__psgcompr_bank,
};

// EnemyD.
const unsigned char *enemyD_anim_data[] =
{
	enemyD_idle__tiles__psgcompr,
};
const unsigned char enemyD_anim_bank[] =
{
	enemyD_idle__tiles__psgcompr_bank,
};