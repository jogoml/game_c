#include "launch.h"


void launch_game(Player *player, Context *context){
    char *monologue[] = {
        "Bienvenue, brave guerrier !",
        "Le monde est en danger, des monstres terrifiants ont envahi le dongeon.",
        "Votre mission est de les vaincre et de sauver notre royaume.",
        "Préparez-vous, équipez-vous de votre épée, et aventurez-vous dans le dongeon sombre.",
        "Que la chance vous accompagne dans cette quête héroïque !"
    };

    int num_texts = sizeof(monologue) / sizeof(monologue[0]);

    printf("L'aventure commence...\n");

    for (int i = 0; i < num_texts; i++) {
        printf("\n[Appuyez sur Entrée pour continuer]");
        while (getchar() != '\n');
        printf("%s\n", monologue[i]);
    }


    printf("\nQue l'aventure commence !\n");
    printf("\n[Appuyez sur Entrée pour continuer]");
    while (getchar() != '\n');
    eventLoop(player, context);
}

void menu(Player *player, Context *context)
{
    int playerExists = 0;
    int choice;
    player = (Player *)malloc(sizeof(Player));
    
    clearScreen();
    do
    {
        playerExists = search_player(player);
        printf("Bienvenue dans le jeu!\n");
        printf("\nMenu :\n");
        printf("1 - Commencer une nouvelle partie\n");
        if (playerExists) {
            printf("2 - Afficher les caractéristiques du personnage\n");
            printf("3 - Continuer la partie\n");
        }
        printf("0 - Quitter le jeu\n");
        system ("/bin/stty raw");
        char choice = fgetc(stdin);
        system ("/bin/stty cooked");
        switch (choice) {
            case '1':
                playerExists = search_player(player);
                if (playerExists) {
                    clearScreen();
                    printf("Un personnage existe déjà. Voulez-vous le supprimer et commencer une nouvelle partie ? (O/N) : ");
                    system ("/bin/stty raw");
                    char confirm = fgetc(stdin);
                    system ("/bin/stty cooked");
                    if (confirm != 'O' && confirm != 'o') {
                        getCurrentMap(context);
                        playerExists = 1;
                        getMap(context);
                        eventLoop(player, context);
                        break;
                    }
                }
                restartMaps(context);
                createPlayer(player);
                setCurrentMap(context);
                getMap(context);
                launch_game(player, context);
                break;
            case '2':
                playerExists = search_player(player);
                if (playerExists) {
                    clearScreen();
                    printf("\nCaractéristiques du personnage :\n");
                    displayPlayer(player);
                }
                break;
            case '3':
                playerExists = 1;
                getCurrentMap(context);
                getMap(context);
                eventLoop(player, context);
                break;
            case '0':
                return;
                break;
            default:
            clearScreen();
                printf("Option invalide. Réessayez.\n");
        }
        clearScreen();
    } while (choice != '0');
}

int in_game_menu(Player * player, Context * context){
    while (1)
    {
        
        clearScreen();
        
        printf("     /\\                                                                    /\\\n");
        printf("     ||---------------------------\\            /---------------------------||\n");
        printf("<====||============================|   MENU   |============================||====>\n");
        printf("     ||---------------------------/            \\---------------------------||\n");
        printf("     \\/                                                                    \\/\n");  

        printf("\n\n1 - Reprendre la partie\n");
        printf("2 - Voir les carastéristiques de mon personnage\n");
        printf("3 - Sauvegarder la partie\n");
        printf("4 - Sauvegarder et revenir au menu principal\n");

        system ("/bin/stty raw");
        char choice = fgetc(stdin);
        system ("/bin/stty cooked");

        switch (choice)
        {
        case '1':
            return 1;
        case '2':
            displayPlayer(player);
            return 1;
        case '3':
            save_player(player);
            //save_armor(player);
            //save_weapon(player);
            return 1;
        case '4':
            save_player(player);
            //save_armor(player);
            //save_weapon(player);
            return 0;

        }
    
    }
}