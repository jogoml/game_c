#include "main.h"

int main(int argc, char** argv){

    Fight *fight = malloc(sizeof(Fight));
    fight->nbMonsters = 2;
    fight->target = 0;
    fight->monsters = malloc(sizeof(Monster)*fight->nbMonsters);
    fight->monsters[0].height = 3;
    fight->monsters[0].width = 3;
    fight->monsters[0].sprite = malloc(sizeof(char*)*fight->monsters[0].height);
    for (int i=0; i<fight->monsters[0].height;i++){
        fight->monsters[0].sprite[i] = malloc(sizeof(char)*fight->monsters[0].width);
        for (int j=0; j<fight->monsters[0].width;j++){
            fight->monsters[0].sprite[i][j] = '0';
        }
        
    }

    fight->monsters[1].height = 3;
    fight->monsters[1].width = 3;
    fight->monsters[1].sprite = malloc(sizeof(char*)*fight->monsters[1].height);
    for (int i=0; i<fight->monsters[1].height;i++){
        fight->monsters[1].sprite[i] = malloc(sizeof(char)*fight->monsters[1].width);
        for (int j=0; j<fight->monsters[1].width;j++){
            fight->monsters[1].sprite[i][j] = '1';
        }
        
    }
    displayMonster(fight);

    

    // Context* context = malloc(sizeof(Context));
    // context->x = 3;
    // context->y = 3;
    // context->nameMap = malloc(sizeof(char)*20);
    // context->nameMap = "../saves/level1.map";
    // if(getMap(context)!=0){
    //     printf("ERROR GET MAP\n");
    //     return 1;
    // }
    // clearScreen();
    // showMap(context);
    // if(eventLoop(context)!=0){
    //     printf("ERROR EVENT LOOP\n");
    //     return 1;
    // }
    
}