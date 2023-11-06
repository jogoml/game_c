#include "monster.h"

Monster monster_attack(Monster monster)
{
    if (monster.health > 0) {
        srand((unsigned int)time(NULL));
        monster.current_attack = rand() % (monster.attack_max - monster.attack_min + 1) + monster.attack_min;
    }
    return monster;
}

Monster monster_defense(Monster monster, Player *ply)
{
    if (monster.health > 0) {
        if (monster.def <= ply->current_attack)
            monster.health = (monster.health > ply->current_attack ? monster.health - ply->current_attack + monster.def : 0); 
    }
    return monster;
}

int get_reward()
{
    srand((unsigned int)time(NULL));
    int ra = rand() % (2);
    return ra;
}

int get_reward_type()
{
   // if (get_reward) {
    srand((unsigned int)time(NULL));
    int type = rand() % (4);
    return type;
    //}
}

int exist_armor(Player *ply, int id)
{
    for (int i = 0; i < ply->nb_armure; i++) {
        if (ply->armors[i]->name == ply->armors[id]->name)
            return 1;
    }
    return 0;
}

int exist_weapon(Player *ply, int id)
{
    for (int i = 0; i < ply->nb_arme; i++) {
        if (ply->weapons[i]->name == ply->weapons[id]->name)
            return 1;
    }
    return 0;
}

Monster monster_death(Monster monster, Player *ply)
{
    srand((unsigned int)time(NULL));
    int reward = get_reward_type();
    if (monster.health == 0) {
        int exp = (monster.type * 2) + 5;
        ply->exp += exp;
        printf("Vous avez obtenue %d exp en plus !\n", exp);
        if (reward == 0) {
            float money = (monster.type * 10) + 10;
            ply->money += money;
            printf("Vous avez obtenue %f pièces !\n", money);
        }
        else if (reward == 1) {
            if (2 > ply->level) {
                int id_weapon = rand() % (3);
                if (!exist_weapon(ply, id_weapon)) {
                    ply->weapons = add_weapon(ply->weapons, inventory_weapon()[id_weapon], ply->nb_arme);
                    ply->nb_arme++;
                    printf("Vous avez obtenue l'arme %s !\n", inventory_weapon()[id_weapon]->name);
                }
            } else {
                int id_weapon = rand() % (8) + 3;
                if (!exist_weapon(ply, id_weapon)) {
                    ply->weapons = add_weapon(ply->weapons, inventory_weapon()[id_weapon], ply->nb_arme);
                    ply->nb_arme++;
                    printf("Vous avez obtenue l'arme %s !\n", inventory_weapon()[id_weapon]->name);
                }
            }
        } else if (reward == 2) {
            if (2 >= ply->level) {
                int id_armor = rand() % (3);
                if (!exist_armor(ply, id_armor)) {
                    ply->armors = add_armor(ply->armors, inventory_armor()[id_armor], ply->nb_armure);
                    ply->nb_armure++;
                    printf("Vous avez obtenue l'arme %s !\n", inventory_armor()[id_armor]->name);
                }
            } else {
                int id_armor = rand() % (8) + 3;
                if (!exist_armor(ply, id_armor)) {
                    ply->armors = add_armor(ply->armors, inventory_armor()[id_armor], ply->nb_armure+1);
                    ply->nb_armure++;
                    printf("Vous avez obtenue l'arme %s !\n", inventory_armor()[id_armor]->name);
                }
            }
        } else if (reward == 3) {
            int mana = (monster.type * 3) + 5;
            ply->mana += mana;
            printf("Vous avez obtenue %d mana en plus !\n", mana);
        }
    }
    return monster;
}
