#include <stdio.h>
#include <stdlib.h>
#include "player.h"
#include "launch_game.h"

int main() {
    int choice;
    Player *player = (Player *)malloc(sizeof(Player));
    int playerExists = 0;

    playerExists = search_player(player);

    printf("Bienvenue dans le jeu!\n");

    do {
        printf("\nMenu :\n");
        printf("1 - Commencer une nouvelle partie\n");
        if (playerExists) {
            printf("2 - Afficher les caractéristiques du personnage\n");
        }
        printf("0 - Quitter le jeu\n");
        printf(" : ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (playerExists) {
                    char confirm;
                    printf("Un personnage existe déjà. Voulez-vous le supprimer et commencer une nouvelle partie ? (O/N) : ");
                    scanf(" %c", &confirm);
                    if (confirm == 'O' || confirm == 'o') {
                        createPlayer(player);
                    } else {
                        continue;
                    }
                } else {
                    player = (Player *)malloc(sizeof(Player));
                    createPlayer(player);
                    playerExists = 1;
                }
                launch_game();
                playerExists = search_player(player);
                break;
            case 2:
                if (playerExists) {
                    printf("\nCaractéristiques du personnage :\n");
                    displayPlayer(player);
                }
                break;
            case 0:
                printf("Au revoir !\n");
                break;
            default:
                printf("Option invalide. Réessayez.\n");
        }
    } while (choice != 0);

    if (player != NULL) {
        free_player(player);
    }

    return 0;
}
