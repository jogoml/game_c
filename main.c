#include <stdio.h>
#include <stdlib.h>
#include "player.h"

#define MAX_PLAYERS 10

int main() {
    int choice;
    Player joueurs[MAX_PLAYERS];
    int nbJoueurs = 0;

    printf("Bienvenue dans le jeu!\n");

    do {
        printf("Menu :\n");
        printf("1 - Créer un personnage\n");
        printf("2 - Afficher les caractéristiques d'un joueur\n");
        printf("3 - Afficher la liste des joueurs\n");
        printf("0 - Quitter le jeu\n");
        printf("Choice : ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
            
                if (nbJoueurs < MAX_PLAYERS) {
                    createPlayer(&joueurs[nbJoueurs]);
                    nbJoueurs++;
                } else {
                    printf("Nombre maximal de joueurs atteint !\n");
                }
                break;
            case 2:
                if (nbJoueurs > 0) {
                    int numJoueur;
                    printf("Entrez le numéro du joueur : ");
                    scanf("%d", &numJoueur);
                    if (numJoueur >= 1 && numJoueur <= nbJoueurs) {
                        printf("Caractéristiques du joueur %d :\n", numJoueur);
                        displayPlayer(&joueurs[numJoueur - 1]);
                    } else {
                        printf("Numéro de joueur invalide.\n");
                    }
                } else {
                    printf("Aucun joueur n'a été créé.\n");
                }
                break;
            case 3:
                if (nbJoueurs > 0) {
                    printf("Liste des joueurs :\n");
                    for (int i = 0; i < nbJoueurs; i++) {
                        printf("%d - %s\n", i + 1, joueurs[i].name);
                    }
                } else {
                    printf("Aucun joueur n'a été créé.\n");
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
