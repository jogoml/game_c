#ifndef LOOP_H
#define LOOP_H

#include "utils.h"
#include "map.h"
#include "cli.h"

int eventLoop(Context *context);

int processUserInput(char userInput, Context* context);

#endif