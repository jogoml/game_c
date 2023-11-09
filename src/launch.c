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
    playerExists = search_player(player);
    clearScreen();
    do
    {
        printf("Bienvenue dans le jeu!\n");
        printf("\nMenu :\n");
        printf("1 - Commencer une nouvelle partie\n");
        if (playerExists) {
            printf("2 - Afficher les caractéristiques du personnage\n");
            printf("3 - Continuer la partie\n");
        }
        printf("0 - Quitter le jeu\n");
        printf(" : ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                playerExists = search_player(player);
                if (playerExists) {
                    char confirm;
                    printf("Un personnage existe déjà. Voulez-vous le supprimer et commencer une nouvelle partie ? (O/N) : ");
                    scanf(" %c", &confirm);
                    if (confirm != 'O' && confirm != 'o') {
                        break;
                    } 
                }
                restartMap(context);
                createPlayer(player);
                playerExists = 1;
                context->nameMap = "../saves/level1.map";
                getMap(context);
                launch_game(player, context);
                break;
            case 2:
                playerExists = search_player(player);
                if (playerExists) {
                    clearScreen();
                    printf("\nCaractéristiques du personnage :\n");
                    displayPlayer(player);
                }
                break;
            case 3:
                eventLoop(player, context);
            case 0:
                break;
            default:
            clearScreen();
                printf("Option invalide. Réessayez.\n");
        }
        clearScreen();
    } while (choice != 0);
}