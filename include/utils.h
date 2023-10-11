#ifndef UTILS_H
#define UTILS_H

#include <stdio.h>
#include <stdlib.h>
#define ROWS 5
#define COLUMNS 5


typedef struct {
    int x;
    int y;
    char* nameMap;
    char** map;
} Context;

#endif