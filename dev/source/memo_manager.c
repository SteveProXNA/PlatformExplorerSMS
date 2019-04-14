#include "memo_manager.h"
#include "global_manager.h"
#include "locale_manager.h"
#include "enum_manager.h"
#include "font_manager.h"
#include "content_manager.h"
#include "tile_manager.h"
#include <stdlib.h>

#define MEMO_Y			9
#define MEMO_HIGH		4

static unsigned char small_tiles[ MAX_SMALL_TILES ] =
{
	tile_type_blockA,
	tile_type_blockB,
	tile_type_blockC,
};

static unsigned char border;
static unsigned char index;
static unsigned char get_tile();
static void draw_tile( unsigned char left, unsigned char topY, unsigned char wide );
static void draw_memo( unsigned char *blank, unsigned char *text1, unsigned char *text2, unsigned char x, unsigned char y, unsigned char wide );

void engine_memo_manager_init()
{
	border = 1;
	index = 0;
}

void engine_memo_manager_draw_title()
{
	engine_font_manager_draw_text( LOCALE_TITLE_MESSAGE1, 13, 0 );
	engine_font_manager_draw_text( LOCALE_TITLE_MESSAGE2, 13, 1 );

}

void engine_memo_manager_draw_level( const unsigned char tutorial,  const unsigned char world, const unsigned char round )
{
	unsigned char x = 12;
	unsigned char y = 20;
	unsigned char wide = 12;
	draw_memo( LOCALE_BLANK_SIZE10, LOCALE_SELECT_WORLD, LOCALE_SELECT_ROUND, x, y, wide );

	if( tutorial )
	{
		engine_font_manager_draw_text( LOCALE_TUTORIAL_NO, x + 7, y + 1 );
	}
	else
	{
		engine_font_manager_draw_text( count_text[ world ], x + 7, y + 1 );
	}

	engine_font_manager_draw_text( count_text[ round ], x + 7, y + 2 );
}

void engine_memo_manager_draw_reset()
{
	unsigned char x = 12;
	unsigned char y = 20;
	unsigned char wide = 12;
	draw_memo( LOCALE_BLANK_SIZE10, LOCALE_RESET_MESSAGE1, LOCALE_RESET_MESSAGE2, x, y, wide );
}
void engine_memo_manager_draw_pass( unsigned char perfect )
{
	unsigned char x = 12;
	unsigned char y = 20;
	unsigned char wide = 12;

	if( perfect )
	{
		draw_memo( LOCALE_BLANK_SIZE10, LOCALE_PASS_MESSAGE1, LOCALE_PASS_MESSAGE3, x, y, wide );
	}
	else
	{
		draw_memo( LOCALE_BLANK_SIZE10, LOCALE_PASS_MESSAGE1, LOCALE_PASS_MESSAGE2, x, y, wide );
	}
	
}
void engine_memo_manager_draw_gems()
{
	unsigned char x = 12;
	unsigned char y = 20;
	unsigned char wide = 12;

	draw_memo( LOCALE_BLANK_SIZE10, LOCALE_BLANK_SIZE10, LOCALE_BLANK_SIZE10, x, y, wide );
	engine_font_manager_draw_text( LOCALE_GEMS_TEXT, 17, y + 1 );
}

void engine_memo_manager_draw_dead()
{
	unsigned char x = 12;
	unsigned char y = 20;
	unsigned char wide = 12;
	draw_memo( LOCALE_BLANK_SIZE10, LOCALE_DEAD_MESSAGE1, LOCALE_DEAD_MESSAGE2, x, y, wide );
}

void engine_memo_manager_draw_cont()
{
	unsigned char x = 12;
	unsigned char y = 20;
	unsigned char wide = 12;

	draw_memo( LOCALE_BLANK_SIZE10, LOCALE_CONT_MESSAGE, LOCALE_CONT_YESORNO, x, y, wide );
}

void engine_memo_manager_draw_over()
{
	unsigned char x = 12;
	unsigned char y = 20;
	unsigned char wide = 12;

	draw_memo( LOCALE_BLANK_SIZE10, LOCALE_GAME_MESSAGE1, LOCALE_GAME_MESSAGE2, x, y, wide );
}

void engine_memo_manager_draw_beat()
{
	unsigned char x = 9;
	unsigned char y = 20;
	unsigned char wide = 19;
	draw_memo( LOCALE_BLANK_SIZE17, LOCALE_BEAT_MESSAGE1, LOCALE_BEAT_MESSAGE2, x, y, wide );
}

static unsigned char get_tile()
{
	index++;
	if( index >= 3 )
	{
		index = 0;
	}

	return small_tiles[ index ];
}
static void draw_tile( unsigned char left, unsigned char topY, unsigned char wide )
{
	unsigned char max, x, y;
	max = MEMO_HIGH - 1;

	for( x = 0; x < wide; x++ )
	{
		engine_tile_manager_draw_small( left + x, topY + 0, get_tile() );
		engine_tile_manager_draw_small( left + x, topY + max, get_tile() );
	}

	for( y = 1; y < max; y++ )
	{
		engine_tile_manager_draw_small( left + 0, topY + y, get_tile() );
		engine_tile_manager_draw_small( left + wide - 1, topY + y, get_tile() );
	}
}
static void draw_memo( unsigned char *blank, unsigned char *text1, unsigned char *text2, unsigned char x, unsigned char y, unsigned char wide )
{
	unsigned char left = x - 1;
	unsigned char topY = y + 0;
	index = 0;

	engine_font_manager_draw_text( blank, x, y + 1 );
	engine_font_manager_draw_text( text1, x, y + 1 );
	engine_font_manager_draw_text( text2, x, y + 2 );

	if( !border )
	{
		return;
	}

	draw_tile( left, topY, wide );
}