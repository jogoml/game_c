#include "main.h"

int main(int argc, char **argv)
{
    Context *context = malloc(sizeof(Context));
    Player *player = NULL;

    menu(player, context);

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
    
    return 0;
}