#include "display_monster.h"

char *m1[] = {
    "        .-.                        ",
    "       (o o) boo!                  ",
    "       | O |                       ",
    "       |   |                       ",
    "       `~~~'                       "};

char *m2[] = {
    "           .-.                     ",
    "          (o.o)                    ",
    "           |=|                     ",
    "          __|__                    ",
    "        //.=|=.0                   ",
    "       // .=|=.                    ",
    "       || .=|=.                    ",
    "       || (_=_)                    ",
    "         (:| |:)                   ",
    "          || ||                    ",
    "          () ()                    ",
    "          || ||                    ",
    "          || ||                    ",
    "         ==' '==                   "};


void attributSpriteToMonster(Monster * monster){
    monster->sprite = malloc(sizeof(char *) * monster->height);
    srand(time(NULL));
    int r = rand() % 2;
    if (r == 0) {
        for (int i = 0; i < monster->height; i++) {
            monster->sprite[i] = malloc(sizeof(char) * (MONSTER_WIDTH + 1)); // +1 for the null terminator
            strcpy(monster->sprite[i], m1[i]);
        }
    }
    else {
        for (int i = 0; i < monster->height; i++) {
            monster->sprite[i] = malloc(sizeof(char) * (MONSTER_WIDTH + 1)); // +1 for the null terminator
            strcpy(monster->sprite[i], m2[i]);
        }
    }
}

void displayMonster(Fight *fight) {
    char display[SCREEN_HEIGHT][SCREEN_WIDTH];

    for (int i = 0; i < SCREEN_HEIGHT; i++) {
        for (int j = 0; j < SCREEN_WIDTH; j++) {
            display[i][j] = ' ';
        }
    }
    int targeted;
    for (int i = 0; i < fight->nbMonsters; i++) {
        if (i == fight->target) {
            targeted = 2;
            for (int k = 0; k < MONSTER_WIDTH; k++) {
                display[1][SPACE + i * MONSTER_WIDTH + k] = '#';
                display[SCREEN_HEIGHT-1][SPACE + i * MONSTER_WIDTH + k] = '#';
            }
        }
        else {
            targeted = 0;
        }
        for (int j = 0; j < fight->monsters[i].height; j++) {
            for (int k = 0; k < MONSTER_WIDTH; k++) {
                display[targeted + j][SPACE + i * MONSTER_WIDTH + k] = fight->monsters[i].sprite[j][k];
            }
        }
    }
    if (fight->target >= 0){
        display[0][fight->target * MONSTER_WIDTH + MONSTER_WIDTH / 2 + SPACE] = 'v';
    }

    for (int i = 0; i < SCREEN_HEIGHT; i++) {
        for (int j = 0; j < SCREEN_WIDTH; j++) {
            printf("%c", display[i][j]);
        }
        printf("\n");
    }
}
