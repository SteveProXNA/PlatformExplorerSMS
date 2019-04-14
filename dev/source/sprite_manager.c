#include "sprite_manager.h"
#include "_sms_manager.h"

void engine_sprite_manager_draw_player( unsigned char x, unsigned char y, unsigned int tile )
{
	devkit_SMS_addSprite_bulk12( x, y, tile );
}

void engine_sprite_manager_draw_enemyX( unsigned char x, unsigned char y, unsigned int tile )
{
	devkit_SMS_addSprite_bulk8( x, y, tile );
}