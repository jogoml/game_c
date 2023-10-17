#ifndef PLAYER_H
#define PLAYER_H

typedef struct {
    char name[50];
    int lvl;
    int exp;
    int health;
    int mana;
    int money;
    int attack;
    int def;
} Player;

void initPlayer(Player *player);
void createPlayer(Player *player);
void displayPlayer(const Player *player);

#endif
