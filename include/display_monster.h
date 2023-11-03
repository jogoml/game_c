#ifndef _DISPLAY_MONSTER_H_INCLUDED
#define _DISPLAY_MONSTER_H_INCLUDED

#include "monster.h"

#define SCREEN_WIDTH 50
#define SCREEN_HEIGHT 30
#define SPACE 5
#define MONSTER_WIDTH 10

typedef struct Fight {
    int nbMonsters;
    int target;
    Monster *monsters;
} Fight;

void displayMonster(Fight *fight);


#endif