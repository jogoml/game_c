#include "player.h"
#include <stdio.h>
#include <string.h>

// Initialisation d'un joueur avec des valeurs par défaut
void initPlayer(Player *player) {
    player->lvl = 1;
    player->exp = 0;
    player->health = 100;
    player->mana = 100;
    player->money = 0;
    player->attack = 15;
    player->def = 20;
    strcpy(player->name, "Joueur");
}

void createPlayer(Player *player) {
    printf("Entrez le nom du joueur : ");
    scanf("%s", player->name);
    
    initPlayer(player);

    printf("Joueur créé avec succès !\n");
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