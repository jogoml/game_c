#ifndef MAP_H
#define MAP_H

#include "utils.h"
#include "player.h"
#include <string.h>

int getMap(Context* context);

void saveMap(Context *context);

void restartMap(Context *context);

void restartMaps(Context *context);

void getCurrentMap(Context *context);

void setCurrentMap(Context *context);

void nextMap(Context *context, Player *player);

void showMap(Context* context, Player * player);

#endif