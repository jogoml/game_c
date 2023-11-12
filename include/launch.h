#ifndef LAUNCH_H
#define LAUNCH_H

#include "player.h"
#include "cli.h"
#include "loop.h"
#include "map.h"

void launch_game(Player *player, Context *context);

void menu(Player *player, Context *context);

int in_game_menu(Player * player);

#endif
