#include "loop.h"
char dieu[] = "DIEU";
int count = 0;
int eventLoop(Player * player, Context * context)
{
    while(1) 
    {
        clearScreen();
        showMap(context, player);

        system ("/bin/stty raw");
        char input = fgetc(stdin);
        system ("/bin/stty cooked");
        if(processUserInput(input,context, player) == 0) {
            return 0;
        }
        clearScreen();
        showMap(context, player);
    }
}

int processUserInput(char userInput, Context* context, Player * player) 
{
    if (context->map == NULL)
    {
        printf("Aucune carte chargée\n");
        return 1;
    }
    if(userInput == dieu[count]){
        count++;
        if(count == 4){
            player->mana = 999999;
            player->max_health = 999999;
            player->level = 999999;
            player->exp = 999999;
            player->exp_next = 999999;
            player->money = 999999;
            player->health = player->max_health;
            count = 0;
        }
    }else{
        count = 0;
    }
    
    switch(userInput) {
        case 'z':
            if(!(context->y-1<0 || context->map[context->y-1][context->x]=='O' || context->map[context->y-1][context->x]=='N')){
                if(context->map[context->y-1][context->x]=='M' || context->map[context->y-1][context->x]=='B'){
                    int is_boss = 0;
                    if(context->map[context->y-1][context->x]=='B'){
                        is_boss = 1;
                    }
                    Fight *fight1 = init_fight(player, is_boss);
                    int res = fights(fight1, player);
                    if( res == 0) {
                        endGame(context, player, 0);
                        return 0;
                    }else if(res == 2){
                        return 0;
                    }
                    free_fight(fight1);
                    player->count++;
                    if(player->count%3==0){
                        player->difficulty++;
                        player->count=0;
                    }
                    player->exp += 10;
                    verify_exp(player);
                    player->health = player->max_health>player->health+10?player->health+10:player->max_health;
                    player->mana += 10;
                    if (is_boss ==1){
                        nextMap(context,player);
                    }
                }
                context->y-=1;
                if(context->map[context->y][context->x]=='M'){
                    context->map[context->y][context->x]='F';
                }else if(context->map[context->y][context->x]=='B'){
                    context->map[context->y][context->x]='P';
                } else if (context->map[context->y][context->x]=='S')
                    magasin(player);

                saveMap(context);
            }
            break;
        case 'd':
            if(!(context->x+1>=ROWS || context->map[context->y][context->x+1]=='O' || context->map[context->y][context->x+1]=='N')){
                if(context->map[context->y][context->x+1]=='M' || context->map[context->y][context->x+1]=='B'){
                    int is_boss = 0;
                    if(context->map[context->y][context->x+1]=='B'){
                        is_boss = 1;
                    }
                    Fight *fight1 = init_fight(player, is_boss);
                    if(fight1 == NULL) {
                        printf("Erreur lors de l'initialisation du combat\n");
                        return 0;
                    }
                    int res = fights(fight1, player);
                    if( res == 0) {
                        endGame(context, player, 0);
                        return 0;
                    }else if(res == 2){
                        return 0;
                    }
                    free_fight(fight1);
                    player->count++;
                    if(player->count%3==0){
                        player->difficulty++;
                        player->count=0;
                    }
                    player->exp += 10;
                    verify_exp(player);
                    player->health = player->max_health>player->health+10?player->health+10:player->max_health;
                    player->mana += 10;
                    if (is_boss ==1){
                        nextMap(context,player);
                    }
                }
                context->x+=1;
                if(context->map[context->y][context->x]=='M'){
                    context->map[context->y][context->x]='F';
                }else if(context->map[context->y][context->x]=='B'){
                    context->map[context->y][context->x]='P';
                }else if (context->map[context->y][context->x]=='S')
                    magasin(player);
                
                saveMap(context);
            }
            break;
        case 's':
            if(!(context->y+1>=COLUMNS || context->map[context->y+1][context->x]=='O' || context->map[context->y+1][context->x]=='N')){
                if(context->map[context->y+1][context->x]=='M' || context->map[context->y+1][context->x]=='B'){
                    int is_boss = 0;
                    if(context->map[context->y+1][context->x]=='B'){
                        is_boss = 1;
                    }
                    Fight *fight1 = init_fight(player, is_boss);
                    if(fight1 == NULL) {
                        printf("Erreur lors de l'initialisation du combat\n");
                        return 0;
                    }
                    int res = fights(fight1, player);
                    if( res == 0) {
                        endGame(context, player, 0);
                        return 0;
                    }else if(res == 2){
                        return 0;
                    }
                    free_fight(fight1);
                    player->count++;
                    if(player->count%3==0){
                        player->difficulty++;
                        player->count=0;
                    }
                    player->exp += 10;
                    verify_exp(player);
                    player->health = player->max_health>player->health+10?player->health+10:player->max_health;
                    player->mana += 10;
                    if (is_boss ==1){
                        nextMap(context,player);
                    }
                }
                context->y+=1;
                if(context->map[context->y][context->x]=='M'){
                    context->map[context->y][context->x]='F';
                }else if(context->map[context->y][context->x]=='B'){
                    context->map[context->y][context->x]='P';
                }else if (context->map[context->y][context->x]=='S')
                    magasin(player);
                
                saveMap(context);

            }
            break;
        case 'q':
            if(!(context->x-1<0 || context->map[context->y][context->x-1]=='O' || context->map[context->y][context->x-1]=='N')){
                if(context->map[context->y][context->x-1]=='M' || context->map[context->y][context->x-1]=='B'){
                    int is_boss = 0;
                    if(context->map[context->y][context->x-1]=='B'){
                        is_boss = 1;
                    }
                    Fight *fight1 = init_fight(player, is_boss);
                    if(fight1 == NULL) {
                        printf("Erreur lors de l'initialisation du combat\n");
                        return 0;
                    }
                    int res = fights(fight1, player);
                    if( res == 0) {
                        endGame(context, player, 0);
                        return 0;
                    }else if(res == 2){
                        return 0;
                    }
                    free_fight(fight1);
                    player->count++;
                    if(player->count%3==0){
                        player->difficulty++;
                        player->count=0;
                    }
                    player->exp += 10;
                    verify_exp(player);
                    player->health = player->max_health>player->health+10?player->health+10:player->max_health;
                    player->mana += 10;
                    if (is_boss ==1){
                        nextMap(context,player);
                    }

                    saveMap(context);
                }
                context->x-=1;
                if(context->map[context->y][context->x]=='M'){
                    context->map[context->y][context->x]='F';
                }else if(context->map[context->y][context->x]=='B'){
                    context->map[context->y][context->x]='P';
                }
                else if (context->map[context->y][context->x]=='S')
                    magasin(player);

                saveMap(context);
            }
            
            break;
        case 'p':
            // menu pause
            if(in_game_menu(player) == 0){

                return 0;
            }
            break;
        case 'i':
            displayPlayer(player);
            break;
        case 'Q':
            return 0;
    }

    save_player(player);
    save_armor(player);
    save_weapon(player);
    save_spell(player);

    return 1;

}