#include "audio_object.h"

#include "..\banks\bank6.h"
#include "..\banks\bank7.h"
#include "..\banks\bank8.h"
#include "..\banks\bank9.h"

// Game.
const unsigned char *game_audio_data[] = 
{
	mus_game01_psg,
	mus_game02_psg,
	mus_game03_psg,
};
const unsigned char game_audio_bank[] =
{
	mus_game01_psg_bank,
	mus_game02_psg_bank,
	mus_game03_psg_bank,
};

// Title.
const unsigned char *title_audio_data[] =
{
	mus_title_psg,
};
const unsigned char title_audio_bank[] =
{
	mus_title_psg_bank,
};

// Beat.
const unsigned char *beat_audio_data[] = 
{
	mus_beat_psg,
};
const unsigned char beat_audio_bank[] =
{
	mus_beat_psg_bank,
};

// Over.
const unsigned char *over_audio_data[] =
{
	mus_over_psg,
};
const unsigned char over_audio_bank[] =
{
	mus_over_psg_bank,
};