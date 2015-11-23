#pragma once
//attributs
extern int code_direction;
extern int nb_right;
extern int nb_wrong;
extern int score;
extern int life;
extern bool locked;
extern bool started;
const enum Mode { CLASSIC, TIME_LIMITED };
const enum Difficulty { NORMAL, NIGHTMARE, HELL };
const int boundsClassic = 20;
const int boundsTimeLimited = 100;
const int maxlife = 5;
extern enum Mode GameMode;
extern enum Difficulty GameDifficulty;
extern Platform::String^ picPaths[8];
extern Platform::String^ normalPaths[8];
extern Platform::String^ nightmarePaths[8];
extern Platform::String^ hellPaths[8];

//methods
extern void gamepage_var_clear();
extern void initPaths(Difficulty diff);