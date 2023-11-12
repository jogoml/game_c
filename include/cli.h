#ifndef CLI_H
#define CLI_H

#include<unistd.h>
#include "utils.h"
#include "player.h"



void clearScreen();

void endGame(Context *context, Player *player, int win);

#endif