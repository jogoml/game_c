#include "main.h"

int main(int argc, char **argv)
{

    Fight *fight = malloc(sizeof(Fight));
    fight->nbMonsters = 2;
    fight->target = -1;
    fight->monsters = malloc(sizeof(Monster) * fight->nbMonsters);

    // Adding monster1 to fight->monsters[0]
    fight->monsters[0].height = 5;
    attributSpriteToMonster(&(fight->monsters[0]));

    fight->monsters[1].height = 5;
    attributSpriteToMonster(&(fight->monsters[1]));
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