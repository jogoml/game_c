#include "main.h"

int main(int argc, char **argv)
{
    Context *context = malloc(sizeof(Context));
    Player *player = NULL;
    
    menu(player, context);

    free(player);
    free(context);
    
    return 0;
}