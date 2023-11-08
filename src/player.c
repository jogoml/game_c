#include "player.h"
#include "monster.h"

Player *init_player(const char *name)
{
    Player *ply = malloc(sizeof(Player));
    ply->name = malloc(sizeof(char) * strlen(name) + 1);
    ply->weapons = init_list_weapon(7);
    ply->armors = init_list_armor(7);
    ply->spell = init_list_spell(7);
    ply->nb_arme = 0;
    ply->nb_armure = 0;
    ply->current_attack = 0;
    ply->health = 100;
    ply->money = 100;
    ply->mana = 50;
    ply->exp = 0;
    ply->nb_spell = 0;
    ply->level = 1;
    strcpy(ply->name, name);

    Weapon *weapon = create_weapon("épée en bois",5, 2, 1, 1, 0);
    ply->weapons = add_weapon(ply->weapons, weapon, ply->nb_arme);
    ply->nb_arme++;
    equip_weapon(weapon, ply);

    Armor *armor = create_armor("Robe d'Apprenti", 0, 1, 0);
    ply->armors = add_armor(ply->armors, armor, ply->nb_armure);
    ply->nb_armure++;
    equip_armor(armor, ply);

    return ply;
}


Player *reinit_player_info(Player *ply)
{
    for (int i = 0; i < ply->nb_arme; i++) {
        if (ply->weapons[i]->equiped)
            ply->nb_attack = ply->weapons[i]->attaquesParTour;
    }

    for (int j = 0; j < ply->nb_armure; j++) {
        if (ply->armors[j]->equiped)
            ply->def = ply->armors[j]->protection;
    }
    return ply;
}

void save_player(Player *player)
{
    FILE *file = fopen("../saves/player.txt", "w");
    if (file != NULL) {
        fprintf(file, "Nom : %s\n", player->name);
        fprintf(file, "Niveau : %d\n", player->level);
        fprintf(file, "Expérience : %d\n", player->exp);
        fprintf(file, "Santé : %f\n", player->health);
        fprintf(file, "Mana : %d\n", player->mana);
        fprintf(file, "Argent : %f\n", player->money);
        fprintf(file, "Attaque : %d\n", player->current_attack);
        fprintf(file, "Défense : %d\n", player->def);
        fprintf(file, "Attaque Min : %d\n", player->attack_min);
        fprintf(file, "Attaque Max : %d\n", player->attack_max);
        fprintf(file, "Nb attaque : %d\n", player->nb_attack);
        fprintf(file, "Nb arme : %d\n", player->nb_arme);
        fprintf(file, "Nb armure : %d\n", player->nb_armure);
        fprintf(file, "Nb sort : %d\n", player->nb_spell);
        fclose(file);
    }
}

void createPlayer(Player *player) {
    char name[50] = "";
    while (strlen(name) == 0 || name == "\n") {
        printf("Entrez le nom du personnage : ");
        scanf("%s", name);
    }
    player = init_player(name);
    FILE *file = fopen("../saves/player.txt", "w");
    if (file != NULL) {
        fprintf(file, "Nom : %s\n", player->name);
        fprintf(file, "Niveau : %d\n", player->level);
        fprintf(file, "Expérience : %d\n", player->exp);
        fprintf(file, "Santé : %f\n", player->health);
        fprintf(file, "Mana : %d\n", player->mana);
        fprintf(file, "Argent : %f\n", player->money);
        fprintf(file, "Attaque : %d\n", player->current_attack);
        fprintf(file, "Défense : %d\n", player->def);
        fprintf(file, "Attaque Min : %d\n", player->attack_min);
        fprintf(file, "Attaque Max : %d\n", player->attack_max);
        fprintf(file, "Nb attaque : %d\n", player->nb_attack);
        fprintf(file, "Nb arme : %d\n", player->nb_arme);
        fprintf(file, "Nb armure : %d\n", player->nb_armure);
        fprintf(file, "Nb sort : %d\n", player->nb_spell);
        fclose(file);
    } else {
        printf("Impossible d'enregistrer le personnage dans le fichier.\n");
    }
}

void displayPlayer(const Player *player) {
    printf("Nom : %s\n", player->name);
    printf("Niveau : %d\n", player->level);
    printf("Expérience : %d\n", player->exp);
    printf("Santé : %f\n", player->health);
    printf("Mana : %d\n", player->mana);
    printf("Argent : %f\n", player->money);
    printf("Attaque : %d\n", player->current_attack);
    printf("Défense : %d\n", player->def);
    printf("Nb attaque : %d\n", player->nb_attack);
    printf("Nb arme : %d\n", player->nb_arme);
    printf("Nb armure : %d\n", player->nb_armure);
    printf("Nb sort : %d\n", player->nb_spell);
}

int search_player(Player *player) {
    FILE *file = fopen("../saves/player.txt", "r");
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
            fscanf(file, "Niveau : %d\n", &player->level);
            fscanf(file, "Expérience : %d\n", &player->exp);
            fscanf(file, "Santé : %f\n", &player->health);
            fscanf(file, "Mana : %d\n", &player->mana);
            fscanf(file, "Argent : %f\n", &player->money);
            fscanf(file, "Attaque : %d\n", &player->current_attack);
            fscanf(file, "Défense : %d\n", &player->def);
            fscanf(file, "Attaque Min : %d\n", &player->attack_min);
            fscanf(file, "Attaque Max : %d\n", &player->attack_max);
            fscanf(file, "Nb attaque : %d\n", &player->nb_attack);
            fscanf(file, "Nb arme : %d\n", &player->nb_arme);
            fscanf(file, "Nb armure : %d\n", &player->nb_armure);
            fscanf(file, "Nb sort : %d\n", &player->nb_spell);
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

Player *equip_weapon(Weapon *weapon, Player *ply)
{
    for (int i = 0; i < ply->nb_arme; i++) {
        if (ply->weapons[i]->name == weapon->name) {
            ply->weapons[i]->equiped = 1;
            ply->attack_max = weapon->attaqueMax;
            ply->attack_min = weapon->attaqueMin;
            ply->nb_attack = weapon->attaquesParTour;
        } else
            ply->weapons[i]->equiped = 0;
    }
    return ply;
}

Player *equip_armor(Armor *armor, Player *ply)
{
    for (int i = 0; i < ply->nb_armure; i++) {
        if (ply->armors[i]->name == armor->name) {
            ply->armors[i]->equiped = 1;
            ply->def = armor->protection;
        } else
            ply->armors[i]->equiped = 0;
    }
    return ply;
}

Weapon *get_player_current_weapon(Player *ply)
{
    for (int i = 0; i < ply->nb_arme; i++) {
        if (ply->weapons[i]->equiped) {
            return ply->weapons[i];
        }
    }
    return NULL;
}

Armor *get_player_current_armor(Player *ply)
{
    for (int i = 0; i < ply->nb_armure; i++) {
        if (ply->armors[i]->equiped) {
            return ply->armors[i];
        }
    }
    return NULL;
}

int display_player_weapon(Player *ply)
{
    if (ply->nb_arme == 0) {
        printf("Vous ne possédez aucune arme !\n");
        return 0;
    }
    printf("Quelle arme voulez-vous utiliser ?\n");
    for (int i = 0; i < ply->nb_arme; i++) {
        printf("%d. Arme: %s\nAttaque Min: %d\nAttaque Max: %d\nNombre d'attaques par tour: %d\n",
        i+1, ply->weapons[i]->name, ply->weapons[i]->attaqueMin, ply->weapons[i]->attaqueMax, ply->weapons[i]->attaquesParTour);
    }
    return 1;
}

int display_player_armor(Player *ply)
{
    if (ply->nb_arme == 0) {
        printf("Vous ne possédez aucune armure !\n");
        return 0;
    }
    printf("Quelle armure voulez-vous utiliser ?\n");
    for (int i = 0; i < ply->nb_arme; i++) {
        printf("%d. Armure: %s\nProtection: %d\n",
        i + 1, ply->armors[i]->name, ply->armors[i]->protection);
    }
    return 1;
}

int display_player_spell(Player *ply)
{
    if (ply->nb_spell == 0) {
        printf("Vous ne possédez aucun sort !\n");
        return 0;
    }
    printf("Quel sort voulez-vous utiliser ?\n");
    for (int i = 0; i < ply->nb_spell; i++) {
        if (ply->spell[i]->type == OFFENSIVE)
            printf("%d. Sort: %s\nType: Offense\nMana: %d\nDégat: %d\n", i + 1, ply->spell[i]->name,
            ply->spell[i]->mana_cost, ply->spell[i]->damage);
        if (ply->spell[i]->type == DEFENSE)
            printf("%d. Sort: %s\nType: Défense\nMana: %d\nDéfense: %d\n", i + 1, ply->spell[i]->name,
            ply->spell[i]->mana_cost, ply->spell[i]->def);
        if (ply->spell[i]->type == CARE)
            printf("%d. Sort: %s\nType: Soin\nMana: %d\nSoin: %d\n", i + 1, ply->spell[i]->name,
            ply->spell[i]->mana_cost, ply->spell[i]->care);
    }
    return 1;
}

Player *use_spell(Player *ply, int key, Fight *fight)
{
    ply->mana -= ply->spell[(key -48)-1]->mana_cost;
    if (ply->spell[(key -48)-1]->type == OFFENSIVE) {
        ply->current_attack = ply->spell[(key -48)-1]->damage;
        for(int i = 0; i < fight->nbMonsters; i++)
            monster_defense(&fight->monsters[i], ply);
        ply->nb_attack--;
    } else if (ply->spell[(key -48)-1]->type == DEFENSE) {
        ply->def += ply->spell[(key -48)-1]->def;
    } else if (ply->spell[(key -48)-1]->type == CARE) {
        if (ply->spell[(key -48)-1]->care + ply->health >= 100)
            ply->health = 100;
        else
            ply->health += ply->spell[(key -48)-1]->care;
    }
    return ply;
}

Player *player_defense(Player *ply, Fight *fight)
{
    for (int i = 0; i < fight->nbMonsters; i++) {
        monster_attack(&fight->monsters[i]);
        if (ply->health > 0) {
            if (ply->def <= fight->monsters[i].current_attack)
                ply->health = (ply->health >= fight->monsters[i].current_attack ? ply->health - fight->monsters[i].current_attack + ply->def : 0); 
        } else 
            return NULL;
    }
    return ply;
}

Player *player_attack(Player *ply, Fight *fight, char key)
{
    int o = 0, i = 0;
    Weapon *ply_weapon = get_player_current_weapon(ply);
    Armor *ply_armor = get_player_current_armor(ply);
    printf("Il vous reste encore %d attaques à effectuer\nQuelle action voulez-vous effectuer ? Souhaitez-vous:\n", ply->nb_attack);
    printf("1- Attaquer avec votre arme %s ?\n2- Utiliser un sort?\n3- Changer votre arme?\n4- Changer d'armure?\n", ply_armor->name);
    if (key == '1') {
        printf("Quel monstre voulez-vous attaquer? ");
        for(i = 0; i < fight->nbMonsters -1; i++)
            printf("%d, ", i+1);
        printf("ou %d?\n", i+1);
        o = 1;
        int id = getchar();
        while (id < 48 || id - 48 > fight->nbMonsters) {
            id = getchar();
        }
        fight->target = (id-48)-1;
        srand((unsigned int)time(NULL));
        ply->current_attack = rand() % (ply->attack_max - ply->attack_min + 1) + ply->attack_min;
        printf("attaque: %d\n", ply->current_attack);
        monster_defense(&fight->monsters[fight->target], ply);
        printf("santé monstre: %f\n", fight->monsters[fight->target].health);
        ply->nb_attack--;
    }
    if (key == '2') {
        if (display_player_spell(ply)) {
            int id_spell = getchar();
            while (id_spell < 48 || id_spell - 48 > ply->nb_spell) {
                id_spell = getchar();
            }
            use_spell(ply, id_spell, fight);
        }
    }
    if (key == '3') {
        if (display_player_weapon(ply)) {
            int id_arme = getchar();
            while (id_arme < 48 || id_arme - 48 > ply->nb_arme) {
                id_arme = getchar();
            }
            equip_weapon(ply->weapons[(id_arme - 48) -1], ply);
        }
    }
    if (key == '4') {
        if (display_player_armor(ply)) {
            int id_armure = getchar();
            while (id_armure < 48 || id_armure - 48 > ply->nb_armure) {
                id_armure = getchar();
            }
            equip_armor(ply->armors[(id_armure - 48) -1], ply);
        }
    }
    return ply;
   
}