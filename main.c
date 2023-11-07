#include <stdio.h>
#include <stdlib.h>
#include "player.h"
#include "launch_game.h"

int main() {
    int choice;
    Player joueur;
    int playerExists = 0;

    playerExists = search_player(&joueur);

    printf("Bienvenue dans le jeu!\n");

    do {
        printf("\nMenu :\n");
        printf("1 - Commencer une nouvelle partie\n");
        if (playerExists) {
            printf("2 - Afficher les caractéristiques du joueur\n");
        }
        printf("0 - Quitter le jeu\n");
        printf(" : ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (playerExists) {
                    char confirm;
                    printf("Un joueur existe déjà. Voulez-vous le supprimer et commencer une nouvelle partie ? (O/N) : ");
                    scanf(" %c", &confirm);
                    if (confirm == 'O' || confirm == 'o') {
                        playerExists = 0;
                        createPlayer(&joueur);
                    }else{
                    	continue;
                    }
                } else {
                    createPlayer(&joueur);
                }
                launch_game();
               
                playerExists = search_player(&joueur);
                break;
            case 2:
                if (playerExists) {
                    printf("\nCaractéristiques du joueur :\n");
                    displayPlayer(&joueur);
                }
                break;
            case 0:
                printf("Au revoir !\n");
                break;
            default:
                printf("Option invalide. Réessayez.\n");
        }
    } while (choice != 0);

    return 0;
}