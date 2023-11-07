#ifndef _DISPLAY_MONSTER_H_INCLUDED
#define _DISPLAY_MONSTER_H_INCLUDED

#include <string.h>
#include "monster.h"
#include <time.h>

#define SCREEN_WIDTH 195
#define SCREEN_HEIGHT 15
#define SPACE 10
#define MONSTER_WIDTH 35



typedef struct Fight {
    int nbMonsters;
    int target;
    Monster *monsters;
} Fight;

void displayMonster(Fight *fight);

void attributSpriteToMonster(Monster *monster);

#endif