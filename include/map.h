#ifndef MAP_H
#define MAP_H

#include "utils.h"
#include <string.h>

int getMap(Context* context);

void saveMap(Context *context);

void restartMap(Context *context);

void restartMaps(Context *context);

void getCurrentMap(Context *context);

void setCurrentMap(Context *context);

void showMap(Context* context);

#endif