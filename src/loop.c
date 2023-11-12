#include "loop.h"

int eventLoop(Player * player, Context * context)
{
    int exitMenu = 0;
    while(1) 
    {
        clearScreen();
        showMap(context);
        system ("/bin/stty raw");
        char input = fgetc(stdin);
        system ("/bin/stty cooked");
        if(processUserInput(input,context, player, &exitMenu) == 0) {
            if (exitMenu == 0) {
                return 0;
            }else if (exitMenu == 2) {
                menu(player, context);
                break;
            }
        }
        clearScreen();
        showMap(context);
    }
}

int processUserInput(char userInput, Context* context, Player * player, int *exitMenu) 
{
    if (context->map == NULL)
    {
        printf("Aucune carte chargée\n");
        return 1;
    }
    
    switch(userInput) {
        case 'z':
            if(!(context->y-1<0 || context->map[context->y-1][context->x]=='O' || context->map[context->y-1][context->x]=='N')){
                if(fight(player) == 0) {
                    endGame(context, player, 0);
                    return 0;
                }
                player->exp += 10;
                verify_exp(player);
                context->y-=1;
                if(context->map[context->y][context->x]=='M'){
                    context->map[context->y][context->x]='F';
                }else if(context->map[context->y][context->x]=='B'){
                    context->map[context->y][context->x]='P';
                }

                saveMap(context);
            }
            break;
        case 'd':
            if(!(context->x+1>ROWS || context->map[context->y][context->x+1]=='O' || context->map[context->y][context->x+1]=='N')){
                if(fight(player) == 0) {
                    endGame(context, player, 0);
                    return 0;
                }
                player->exp += 10;
                verify_exp(player);
                context->x+=1;
                if(context->map[context->y][context->x]=='M'){
                    context->map[context->y][context->x]='F';
                }else if(context->map[context->y][context->x]=='B'){
                    context->map[context->y][context->x]='P';
                }
                
                saveMap(context);
            }
            break;
        case 's':
            if(!(context->y+1>COLUMNS || context->map[context->y+1][context->x]=='O' || context->map[context->y+1][context->x]=='N')){
                if(fight(player) == 0) {
                    endGame(context, player, 0);
                    return 0;
                }
                player->exp += 10;
                verify_exp(player);
                context->y+=1;
                if(context->map[context->y][context->x]=='M'){
                    context->map[context->y][context->x]='F';
                }else if(context->map[context->y][context->x]=='B'){
                    context->map[context->y][context->x]='P';
                }
                
                saveMap(context);

            }
            break;
        case 'q':
            if(!(context->x-1<0 || context->map[context->y][context->x-1]=='O' || context->map[context->y][context->x-1]=='N')){
                if(fight(player) == 0) {
                    endGame(context, player, 0);
                    return 0;
                }
                player->exp += 10;
                verify_exp(player);
                context->x-=1;
                if(context->map[context->y][context->x]=='M'){
                    context->map[context->y][context->x]='F';
                }else if(context->map[context->y][context->x]=='B'){
                    context->map[context->y][context->x]='P';
                }

                saveMap(context);
            }
            
            break;
        case 'p':
            // menu pause
            *exitMenu = in_game_menu(player, context);
            if (*exitMenu == 1) {
                getCurrentMap(context);
                getMap(context);
                return 1;
            } else if (*exitMenu == 2) {
                return 2;
            } else {
                return 0;
            }
            break;
        case 'i':
            displayPlayer(player);
            break;
        case 'Q':
            *exitMenu = 0;
            return 0;
    }
    save_player(player);
    save_armor(player);
    save_weapon(player);

    return 1;

}