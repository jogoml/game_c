#include "player.h"
#include "monster.h"


char *m1[] = {
    "        .-.                        ",
    "       (o o) boo!                  ",
    "       | O |                       ",
    "       |   |                       ",
    "       `~~~'                       "};

char *m2[] = {
    "           .-.                     ",
    "          (o.o)                    ",
    "           |=|                     ",
    "          __|__                    ",
    "        //.=|=.0                   "};
//######################################################
//                       EXEMPLE                      

    // Fight *fight = malloc(sizeof(Fight));
    // fight->nbMonsters = 5;
    // fight->target = 1;
    // fight->monsters = malloc(sizeof(Monster) * fight->nbMonsters);

    // fight->monsters[0].health = 20;
    // fight->monsters[0].height = 5;
    // fight->monsters[0].type = 1;
    // attributSpriteToMonster(&(fight->monsters[0]));

    // fight->monsters[1].health = 100;
    // fight->monsters[1].height = 5;
    // fight->monsters[1].type = 2;
    // attributSpriteToMonster(&(fight->monsters[1]));

    // fight->monsters[2].health = 100;
    // fight->monsters[2].height = 5;
    // fight->monsters[2].type = 1;
    // attributSpriteToMonster(&(fight->monsters[2]));

    // fight->monsters[3].health = 100;
    // fight->monsters[3].height = 5;
    // fight->monsters[3].type = 2;
    // attributSpriteToMonster(&(fight->monsters[3]));

    // fight->monsters[4].health = 100;
    // fight->monsters[4].height = 5;
    // fight->monsters[4].type = 1;
    // attributSpriteToMonster(&(fight->monsters[4]));

    // displayMonster(fight);

//######################################################
void attributSpriteToMonster(Monster * monster){
    monster->sprite = malloc(sizeof(char *) * monster->height);
    if (monster->type == 1) {
        for (int i = 0; i < monster->height; i++) {
            monster->sprite[i] = malloc(sizeof(char) * (MONSTER_WIDTH + 1)); // +1 for the null terminator
            strcpy(monster->sprite[i], m1[i]);
        }
    }
    else {
        for (int i = 0; i < monster->height; i++) {
            monster->sprite[i] = malloc(sizeof(char) * (MONSTER_WIDTH + 1)); // +1 for the null terminator
            strcpy(monster->sprite[i], m2[i]);
        }
    }
}

void displayMonster(Fight *fight) {
    clearScreen();
    char display[SCREEN_HEIGHT][SCREEN_WIDTH];

    for (int i = 0; i < SCREEN_HEIGHT; i++) {
        for (int j = 0; j < SCREEN_WIDTH; j++) {
            display[i][j] = ' ';
        }
    }
    int targeted;
    for (int i = 0; i < fight->nbMonsters; i++) {
        if(fight->monsters[i].health <= 0){
            continue;
        }
        if (i == fight->target) {
            targeted = 2;
            for (int k = 0; k < MONSTER_WIDTH; k++) {
                display[1][SPACE + i * MONSTER_WIDTH + k] = '#';
                display[SCREEN_HEIGHT-1][SPACE + i * MONSTER_WIDTH + k] = '#';
            }
        }
        else {
            targeted = 0;
        }
        for (int j = 0; j < fight->monsters[i].height; j++) {
            for (int k = 0; k < MONSTER_WIDTH; k++) {
                display[targeted + j][SPACE + i * MONSTER_WIDTH + k] = fight->monsters[i].sprite[j][k];
            }
        }
    }
    if (fight->target >= 0 && fight->monsters[fight->target].health > 0){
        display[0][fight->target * MONSTER_WIDTH + MONSTER_WIDTH / 2 + SPACE] = 'v';
    }

    for (int i = 0; i < SCREEN_HEIGHT; i++) {
        for (int j = 0; j < SCREEN_WIDTH; j++) {
            printf("%c", display[i][j]);
        }
        printf("\n");
    }
}


void monster_attack(Monster *monster)
{
    if (monster->health > 0) {
        srand((unsigned int)time(NULL));
        monster->current_attack = rand() % (monster->attack_max - monster->attack_min + 1) + monster->attack_min;
    }
}

void monster_defense(Monster *monster, Player *ply)
{
    if (monster->health > 0) {
        if (monster->def <= ply->current_attack)
            monster->health = (monster->health >= ply->current_attack ? monster->health - ply->current_attack + monster->def : 0); 
    }
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

void monster_death(Monster *monster, Player *ply)
{
    srand((unsigned int)time(NULL));
    int reward = get_reward_type();
    if (monster->health == 0) {
        int exp = (monster->type * 2) + 5;
        ply->exp += exp;
        printf("Vous avez obtenue %d exp en plus !\n", exp);
        printf("reward %d", reward);
        if (reward == 0) {
            float money = (monster->type * 10) + 10;
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
            int mana = (monster->type * 3) + 5;
            ply->mana += mana;
            printf("Vous avez obtenue %d mana en plus !\n", mana);
        }
    }
}

