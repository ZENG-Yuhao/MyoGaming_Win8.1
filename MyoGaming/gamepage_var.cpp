#include "pch.h"
#include "gamepage_var.h"

int nb_right = 0;
int nb_wrong = 0;
int score = 0;
int life = maxlife;
int code_direction = 1;
bool locked = true;
bool started = false;
enum Mode GameMode;
enum Difficulty GameDifficulty;
Platform::String^ picPaths[8];

Platform::String^ normalPaths[8] = {
	"ms-appx:Assets/arrow_blue_up.png",
	"ms-appx:Assets/arrow_blue_down.png",
	"ms-appx:Assets/arrow_blue_left.png",
	"ms-appx:Assets/arrow_blue_right.png",
	"ms-appx:Assets/arrow_red_up.png",
	"ms-appx:Assets/arrow_red_down.png",
	"ms-appx:Assets/arrow_red_left.png",
	"ms-appx:Assets/arrow_red_right.png" };

Platform::String^ nightmarePaths[8] = {
	"ms-appx:Assets/nightmare_blue_up.png",
	"ms-appx:Assets/nightmare_blue_down.png",
	"ms-appx:Assets/nightmare_blue_left.png",
	"ms-appx:Assets/nightmare_blue_right.png",
	"ms-appx:Assets/nightmare_red_up.png",
	"ms-appx:Assets/nightmare_red_down.png",
	"ms-appx:Assets/nightmare_red_left.png",
	"ms-appx:Assets/nightmare_red_right.png" };

Platform::String^ hellPaths[8] = {
	"ms-appx:Assets/hell_blue_up.png",
	"ms-appx:Assets/hell_blue_down.png",
	"ms-appx:Assets/hell_blue_left.png",
	"ms-appx:Assets/hell_blue_right.png",
	"ms-appx:Assets/hell_red_up.png",
	"ms-appx:Assets/hell_red_down.png",
	"ms-appx:Assets/hell_red_left.png",
	"ms-appx:Assets/hell_red_right.png" };

void initPaths(Difficulty diff)
{
	switch (diff)
	{
	case NORMAL:
		for (int i = 0; i < 8; i++) picPaths[i] = normalPaths[i];
		break;
	case NIGHTMARE:
		for (int i = 0; i < 8; i++) picPaths[i] = nightmarePaths[i];
		break;
	case HELL:
		for (int i = 0; i < 8; i++) picPaths[i] = hellPaths[i];
		break;
	default:
		break;
	}
}


void gamepage_var_clear()
{
	nb_right = 0;
	nb_wrong = 0;
	score = 0;
	code_direction = 1;
	locked = true;
	life = maxlife;
}
