#include "cli.h"


void clearScreen()
{
    printf("\e[1;1H\e[2J");
}

void endGame(Context *context, Player *player, int win)
{
    clearScreen();
    if(win)
    {
        printf("Vous avez gagné !\n");
    }
    else
    {
        remove("../saves/armors.csv");
        remove("../saves/player.txt");
        remove("../saves/weapons.csv");
        remove("../saves/spells.csv");


        printf("Vous avez perdu !\n");
        sleep(3);
    }
    return;
}