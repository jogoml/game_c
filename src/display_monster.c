#include "display_monster.h"

void displayMonster(Fight *fight) {
    char display[SCREEN_HEIGHT][SCREEN_WIDTH];

    for (int i = 0; i < SCREEN_HEIGHT; i++) {
        for (int j = 0; j < SCREEN_WIDTH; j++) {
            display[i][j] = ' ';
        }
    }
    int targeted;
    for (int i=0; i<fight->nbMonsters;i++){
        if( i == fight->target){
            targeted = 1;
        }else{
            targeted = 0;
        }
        for (int j=0; j<fight->monsters[i].height;j++){
            for (int k=0; k<fight->monsters[i].width;k++){
                display[SPACE+targeted+j][SPACE+i*MONSTER_WIDTH+k] = fight->monsters[i].sprite[j][k];
            }
        } 
    }

    display[0][fight->target*MONSTER_WIDTH+MONSTER_WIDTH/2+SPACE] = 'v';

    for (int i = 0; i < SCREEN_HEIGHT; i++) {
        for (int j = 0; j < SCREEN_WIDTH; j++) {
            printf("%c", display[i][j]);
        }
        printf("\n");
    }
}