#ifndef PLAYER_H
#define PLAYER_H


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#include "weapon.h"
#include "armor.h"
#include "spell.h"


typedef struct Player {
    char *name;
    int level;
    int exp;
    int exp_next;
    float health;
    float max_health;
    int mana;
    float money;
    int current_attack;
    int def;
    int attack_min;
    int attack_max;
    int nb_attack;
    int nb_arme;
    int nb_armure;
    int nb_spell;
    
    Weapon **weapons;
    Armor **armors;
    Spell **spell;
} Player;

#include "cli.h"

Player *init_player(char *name);
Player *reinit_player_info(Player *ply);
Player *equip_weapon(Weapon *weapon, Player *ply);
Player *equip_armor(Armor *armor, Player *ply);
Weapon *get_player_current_weapon(Player *ply);
Armor *get_player_current_armor(Player *ply);
int display_player_armor(Player *ply);
int display_player_spell(Player *ply);

int fight(Player *ply);

void createPlayer(Player *player);
void displayPlayer(Player *player);
int search_player(Player *player);
void free_player(Player *player);
void save_player(Player *player);
void save_armor(Player *ply);
void save_weapon(Player *ply);

#endif