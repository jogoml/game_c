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
        printf("Vous avez perdu !\n");
    }
    // Create real ends

    free_player(player);
    if(context->map != NULL)
    {
        for (int i = 0; i < ROWS; i++)
        {
            free(context->map[i]);
        }
        free(context->map);
    }
    free(context);
    return;
}