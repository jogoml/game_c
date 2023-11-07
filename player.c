#include "player.h"
#include <stdio.h>
#include <string.h>

void initPlayer(Player *player, const char *name) {
    player->lvl = 1;
    player->exp = 0;
    player->health = 100;
    player->mana = 100;
    player->money = 0;
    player->attack = 15;
    player->def = 20;
    strcpy(player->name, name);
}

void createPlayer(Player *player) {
    printf("Entrez le nom du joueur : ");
    scanf("%s", player->name);

    FILE *file = fopen("joueur.txt", "w");
    if (file != NULL) {
        initPlayer(player, player->name);

        fprintf(file, "Nom : %s\n", player->name);
        fprintf(file, "Niveau : %d\n", player->lvl);
        fprintf(file, "Expérience : %d\n", player->exp);
        fprintf(file, "Santé : %d\n", player->health);
        fprintf(file, "Mana : %d\n", player->mana);
        fprintf(file, "Argent : %d\n", player->money);
        fprintf(file, "Attaque : %d\n", player->attack);
        fprintf(file, "Défense : %d\n", player->def);

        fclose(file);

        printf("Joueur créé avec succès et enregistré dans le fichier 'joueur.txt' !\n");
    } else {
        printf("Impossible d'enregistrer le joueur dans le fichier.\n");
    }
}

void displayPlayer(const Player *player) {
    printf("Nom : %s\n", player->name);
    printf("Niveau : %d\n", player->lvl);
    printf("Expérience : %d\n", player->exp);
    printf("Santé : %d\n", player->health);
    printf("Mana : %d\n", player->mana);
    printf("Argent : %d\n", player->money);
    printf("Attaque : %d\n", player->attack);
    printf("Défense : %d\n", player->def);
}

int search_player(Player *joueur) {
    FILE *file = fopen("joueur.txt", "r");
    if (file != NULL) {
        char line[100];
        if (fgets(line, sizeof(line), file) != NULL) {

            sscanf(line, "Nom : %s", joueur->name);
            fscanf(file, "Niveau : %d\n", &joueur->lvl);
            fscanf(file, "Expérience : %d\n", &joueur->exp);
            fscanf(file, "Santé : %d\n", &joueur->health);
            fscanf(file, "Mana : %d\n", &joueur->mana);
            fscanf(file, "Argent : %d\n", &joueur->money);
            fscanf(file, "Attaque : %d\n", &joueur->attack);
            fscanf(file, "Défense : %d\n", &joueur->def);
            
            fclose(file);
            return 1;
        }
        fclose(file);
    }
    return 0;
}
