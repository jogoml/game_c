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

char *m3[] = {
    "             _/|    _   | |_       ",
    "           _/_ |   _|   | _ |      ",
    "         _/_/| /  /   |  | _ _     ",
    "       _/_/  |/  /  _  |_ / | |_   ",
    "     _/_/    ||  | | | o/ ||    |  ",
    "    /_/  | | | |  |  |_V  /|  | |  ",
    "   //    ||| |  |_/    |__/ | | |  ",
    "   / __| || |    |         /  / |  ",
    "  /_/  ||||  /|        // | |  / | ",
    " //    |/  /   /         /  |/  /  ",
    "        |/    |    |    |    |/    ",
    "              /_|  | |_  |         ",
    "             / /_| |_||  |         ",
    "             | / |/||  |  |        ",
    "              /  /|||/||/ /        ",
    "                 |/ |  /           "};

char *m4[] = {
    "                        /|         ",
    "                        ||         ",
    "          ____ (((+))) _||_        ",
    "         /.--.|  .-.  /.||.|       ",
    "        /.,   |_(0.0)// || |       ",
    "       /;` ;/   ||m|//  ||  |;     ",
    "       |:    |   `:`  __||__:|     ",
    "       |:  |   __ T  (@~)(~@)|     ",
    "       |: |  _/|     |_ |/  :|     ",
    "       |:   /  |     | |_   :|     ",
    "       |'  /   |     |   |  |      ",
    "        |_/    |     |   |_/       ",
    "               |     |             ",
    "               |__|__|             ",
    "               |_____|             "};

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
    }else if (monster->type == 3) {
        for (int i = 0; i < monster->height; i++) {
            monster->sprite[i] = malloc(sizeof(char) * (MONSTER_WIDTH + 1)); // +1 for the null terminator
            strcpy(monster->sprite[i], m3[i]);
        }
    }else if (monster->type == 4) {
        for (int i = 0; i < monster->height; i++) {
            monster->sprite[i] = malloc(sizeof(char) * (MONSTER_WIDTH + 1)); // +1 for the null terminator
            strcpy(monster->sprite[i], m4[i]);
        }
    }else {
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
    srand(time(NULL));

    if (monster->health > 0) {
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

Fight *init_fight(Player *player, int is_boss){
    Fight *fight = malloc(sizeof(Fight));
    fight->target = -1;
    fight->monsters = NULL;
    createMonsters(fight, player->difficulty, is_boss);
    return fight;
}

void free_fight(Fight *fight){
    if(fight != NULL){
        if(fight->monsters != NULL){
            for(int i = 0; i < fight->nbMonsters; i++){
                if(fight->monsters[i].sprite != NULL){
                    for(int j = 0; j < fight->monsters[i].height; j++){
                        if(fight->monsters[i].sprite[j] != NULL){
                            free(fight->monsters[i].sprite[j]);
                        }
                    }
                    free(fight->monsters[i].sprite);
                }
            }
            free(fight->monsters);
        }
        free(fight);
    }
}

void createMonster(Monster * monster, int level, int is_boss){
    if(is_boss){
        monster->health = 100 * level;
        monster->max_health = 100 * level;
        monster->def = 2 * level;
        monster->attack_min = 1+level * 4;
        monster->attack_max = 15+level * 4;
        monster->current_attack = 0;
        monster->type = rand() % (2) + 3;
        monster->exp_drop = 20 + level * 12;
        monster->height = 15;
        attributSpriteToMonster(monster);
    }else{
        srand(time(NULL));
        monster->health = 10 * level;
        monster->max_health = 10 * level;
        monster->def = level;
        monster->attack_min = 1+level;
        monster->attack_max = 5+level;
        monster->current_attack = 0;
        monster->type = rand() % (2) + 1;
        monster->exp_drop = 10 + level * 2;
        monster->height = 5;
        attributSpriteToMonster(monster);
    }
}

void createMonsters(Fight *fight, int level, int is_boss){
    if(is_boss){
        fight->nbMonsters = 1;
        fight->monsters = malloc(sizeof(Monster) * fight->nbMonsters);
        createMonster(&(fight->monsters[0]), level, is_boss);
    }else{
        srand(time(NULL));
        fight->nbMonsters = rand() % (5) + 1;
        fight->monsters = malloc(sizeof(Monster) * fight->nbMonsters);
        for(int i = 0; i < fight->nbMonsters; i++){
            createMonster(&(fight->monsters[i]), level, is_boss);
        }
    }
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
        monster->health = -1;
    }
}

int nb_death_monster(Fight *fight)
{
    int nb = fight->nbMonsters;
    for (int i = 0; i < fight->nbMonsters; i++) {
        if (fight->monsters[i].health == -1) {
            nb--;
        }
    }
    if (nb == 0)
        return 1;
    return 0;
}
int fights(Fight *fight, Player *ply)
{
    int nb = fight->nbMonsters;
    while (1) {
        while (ply->nb_attack > 0) {
            if (nb_death_monster(fight) == 1)
                break;
            printf("pv %s %f, mana %d\n",ply->name, ply->health, ply->mana);
            Weapon *ply_weapon = get_player_current_weapon(ply);
            printf("Il vous reste encore %d attaques à effectuer\nQuelle action voulez-vous effectuer ? Souhaitez-vous:\n", ply->nb_attack);
            printf("1- Attaquer avec votre arme %s ?\n2- Utiliser un sort?\n3- Changer votre arme?\n4- Changer d'armure?\n", ply_weapon->name);
            int key = 0;
            scanf("%d", &key);
            while (key < 1 || key > 4) {
                scanf("%d", &key);
            }
            player_attack(ply, fight, key);
            for (int i = 0; i < fight->nbMonsters; i++) {
                if (fight->monsters[i].health == -1) {
                    continue;
                }
                monster_death(&fight->monsters[i], ply);
                printf("pv monstre %d: %f\n", i + 1, fight->monsters[i].health);                
            }
            }
            if (player_defense(ply, fight) == NULL)
                return 0;
            reinit_player_info(ply);
        }
    return 1;
}