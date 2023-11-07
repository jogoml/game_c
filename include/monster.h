#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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

typedef struct Player {
    float health;
    int def;
    int attack_min;
    int attack_max;
    int current_attack;
    float money;
    int exp;
    int nb_arme;
    int nb_armure;
    int level;
} Player;

Monster *monster_attack(Monster *monster);
Monster *monster_defense(Monster *monster, Player *ply);
int get_reward();
int get_reward_type();
Monster *monster_death(Monster *monster, Player *ply);