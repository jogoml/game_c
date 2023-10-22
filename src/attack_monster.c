#include "monster.h"

Monster *monster_attack(Monster *monster)
{
    if (monster->health > 0) {
        srand((unsigned int)time(NULL));
        monster->current_attack = rand() % (monster->attack_max - monster->attack_min + 1) + monster->attack_min;
    }
    return monster;
}

Monster *monster_defense(Monster *monster, Player *ply)
{
    if (monster->health > 0) {
        monster->health = (monster->health > ply->current_attack ? monster->health - ply->current_attack + monster->def : 0); 
    }
    return monster;
}

int get_reward()
{
    srand((unsigned int)time(NULL));
    int ra = rand() % (1 + 1) + 0;
    return ra;
}

int get_reward_type()
{
   // if (get_reward) {
    srand((unsigned int)time(NULL));
    int type = rand() % (3) + 0;
    return type;
    //}
}

Monster *monster_death(Monster *monster, Player *ply)
{
    srand((unsigned int)time(NULL));
    int reward = get_reward_type();
    if (monster->health == 0) {
        ply->exp += (monster->type * 2) + 5;
        if (reward == 0) {
            ply->money += (monster->type * 10) + 10;
        }
    } else if (reward == 1) {
        if (2 > ply->level) {
            int id_arme = rand() % (3) + 0;
           // add_arme(ply->armement, inventory_arme[id_arme], nb_arme+1);
        } else {
            int id_arme = rand() % (8) + 3;
           // add_arme(ply->armement, inventory_arme[id_arme], nb_arme+1);
        }
    } else if (reward == 2) {
        if (2 > ply->level) {
            int id_arme = rand() % (3) + 0;
           // add_arme(ply->armement, inventory_arme[id_arme], nb_arme+1);
        } else {
            int id_arme = rand() % (8) + 3;
           // add_arme(ply->armement, inventory_arme[id_arme], nb_arme+1);
        }
    }
}
