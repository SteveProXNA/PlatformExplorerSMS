#include "splash_screen.h"
#include "_sms_manager.h"
#include "enum_manager.h"
#include "content_manager.h"
#include "delay_manager.h"
#include "input_manager.h"

#define SPLASH_SCREEN_DELAY		150

void screen_splash_screen_load()
{
	engine_delay_manager_load( SPLASH_SCREEN_DELAY );

	devkit_SMS_displayOff();
	engine_content_manager_load_splash();
	devkit_SMS_displayOn();
}

void screen_splash_screen_update( unsigned char *screen_type )
{
	unsigned char delay;
	unsigned char input;

	delay = engine_delay_manager_update();
	input = engine_input_manager_hold_fire1();

	if( delay || input )
	{
		*screen_type = screen_type_intro;
		return;
	}

	*screen_type = screen_type_splash;
}