#ifndef MONSTER_H
#define MONSTER_H


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "weapon.h"
#include "armor.h"
#include "spell.h"
#include "cli.h"
#include "player.h"

#define SCREEN_WIDTH 195
#define SCREEN_HEIGHT 15
#define SPACE 10
#define MONSTER_WIDTH 35

typedef struct Monster {
    float health;
    float max_health;
    int def;
    int attack_min;
    int attack_max;
    int current_attack;
    int type;
    int exp_drop;
    int height;
    char **sprite;
} Monster;

typedef struct Fight {
    int nbMonsters;
    int target;
    Monster *monsters;
} Fight;

void attributSpriteToMonster(Monster * monster);
void displayMonster(Fight *fight);

void attributSpriteToMonster(Monster *monster);
void monster_attack(Monster *monster);
void monster_defense(Monster *monster, Player *ply);
int get_reward();
int get_reward_type();
void monster_death(Monster *monster, Player *ply);
int exist_armor(Player *ply, int id);
int exist_weapon(Player *ply, int id);

Player *use_spell(Player *ply, int key, Fight *fight);
Player *player_defense(Player *ply, Fight *fight);
Player *player_attack(Player *ply, Fight *fight, char key);
#endif