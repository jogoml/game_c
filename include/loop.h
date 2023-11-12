#ifndef LOOP_H
#define LOOP_H

#include "utils.h"
#include "map.h"
#include "cli.h"
#include "player.h"
#include "exp.h"
#include "magasin.h"
#include "launch.h"
#include "monster.h"

int eventLoop(Player *player, Context *context);

int processUserInput(char userInput, Context* context, Player * player);

#endif