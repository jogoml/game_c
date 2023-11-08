#include "player.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

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
    printf("Entrez le nom du personnage : ");
    char name[50];
    scanf("%s", name);

    if (player->name != NULL) {
        char *temp = (char *)realloc(player->name, strlen(name) + 1);
        if (temp != NULL) {
            player->name = temp;
        } else {
            printf("erreur lors de la création d'un nouveau personnage");
        }
        free(temp);
    } else {
        player->name = (char *)malloc(strlen(name) + 1);
    }
    strcpy(player->name, name);

    FILE *file = fopen("player.txt", "w");
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
    } else {
        printf("Impossible d'enregistrer le personnage dans le fichier.\n");
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

int search_player(Player *player) {
    FILE *file = fopen("player.txt", "r");
    if (file != NULL) {
        char line[100];
        char name[100];
        if (fgets(line, sizeof(line), file) != NULL) {
            if (sscanf(line, "Nom : %99s", name) == 1) {
                player->name = (char *)malloc(strlen(name) + 1);
                if (player->name != NULL) {
                    strcpy(player->name, name);
                } else {
                    printf("erreur lors de la recuperation de la sauvegarde\n");
                    return 0;
                }
            }
            fscanf(file, "Niveau : %d\n", &player->lvl);
            fscanf(file, "Expérience : %d\n", &player->exp);
            fscanf(file, "Santé : %d\n", &player->health);
            fscanf(file, "Mana : %d\n", &player->mana);
            fscanf(file, "Argent : %d\n", &player->money);
            fscanf(file, "Attaque : %d\n", &player->attack);
            fscanf(file, "Défense : %d\n", &player->def);

            fclose(file);
            return 1;
        }
        fclose(file);
    }
    return 0;
}



void free_player(Player *player) {
    if (player->name != NULL) {
        free(player->name);
    }
    free(player);
}
    
    
    
    