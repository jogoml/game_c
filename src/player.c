#include "player.h"
#include "monster.h"

Player *init_player(char *name)
{
    Player *ply = malloc(sizeof(Player));
    ply->name = malloc(sizeof(char) * strlen(name) + 1);
    ply->weapons = init_list_weapon(7);
    ply->armors = init_list_armor(7);
    ply->spell = init_list_spell(9);
    ply->nb_arme = 0;
    ply->nb_armure = 0;
    ply->current_attack = 0;
    ply->money = 100;
    ply->mana = 50;
    ply->level = 1;
    ply->exp = 0;
    ply->exp_next = 100;
    ply->health = 100;
    ply->max_health = 100;
    ply->def = 0;
    ply->attack_min = 0;
    ply->attack_max = 0;
    ply->nb_attack = 0;
    ply->nb_spell = 0;
    strcpy(ply->name, name);
    save_player(ply);

    Weapon *weapon = create_weapon("épée en bois",15, 5, 1, 2, 0);
    ply->weapons = add_weapon(ply->weapons, weapon, ply->nb_arme);
    ply->nb_arme++;
    get_player_current_weapon(ply);
    equip_weapon(weapon, ply);

    Armor *armor = create_armor("Robe d'Apprenti", 0, 2, 0);
    ply->armors = add_armor(ply->armors, armor, ply->nb_armure);
    ply->nb_armure++;
    get_player_current_armor(ply);
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
        fprintf(file, "Exp next : %d\n", player->exp_next);
        fprintf(file, "Santé : %.1f\n", player->health);
        fprintf(file, "Santer max : %.1f\n", player->max_health);
        fprintf(file, "Mana : %d\n", player->mana);
        fprintf(file, "Argent : %.2f\n", player->money);
        fprintf(file, "Attaque : %d\n", player->current_attack);
        fprintf(file, "Défense : %d\n", player->def);
        fprintf(file, "Attaque Min : %d\n", player->attack_min);
        fprintf(file, "Attaque Max : %d\n", player->attack_max);
        fprintf(file, "Nb attaque : %d\n", player->nb_attack);
        fprintf(file, "Nb arme : %d\n", player->nb_arme);
        fprintf(file, "Nb armure : %d\n", player->nb_armure);
        fprintf(file, "Nb sort : %d\n", player->nb_spell);
    }
    fclose(file);
}

void createPlayer(Player *player) {
    clearScreen();
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
        fprintf(file, "Exp next : %d\n", player->exp_next);
        fprintf(file, "Santé : %.1f\n", player->health);
        fprintf(file, "Santer max : %.1f\n", player->max_health);
        fprintf(file, "Mana : %d\n", player->mana);
        fprintf(file, "Argent : %.2f\n", player->money);
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

void displayPlayer(Player *player) {
    clearScreen();
    printf("Nom : %s\n", player->name);
    printf("Niveau : %d\n", player->level);
    printf("Expérience : %d/%d\n", player->exp, player->exp_next);
    printf("Santé : %.1f\n", player->max_health);
    printf("Mana : %d\n", player->mana);
    printf("Argent : %.2f\n", player->money);
    printf("Attaque : %d\n", player->current_attack);
    printf("Défense : %d\n", player->def);
    printf("Nb attaque : %d\n", player->nb_attack);
    printf("Nb arme : %d\n", player->nb_arme);
    printf("Nb armure : %d\n", player->nb_armure);
    printf("Nb sort : %d\n", player->nb_spell);
    printf("Q - Quitter\n");
    while(1){
        system ("/bin/stty raw");
        char c = fgetc(stdin);
        system ("/bin/stty cooked");
        if (c == 'Q' || c == 'q')
        {
            return;
        }
        clearScreen();
        printf("Nom : %s\n", player->name);
        printf("Niveau : %d\n", player->level);
        printf("Expérience : %d/%d\n", player->exp, player->exp_next);
        printf("Santé : %.1f\n", player->max_health);
        printf("Mana : %d\n", player->mana);
        printf("Argent : %.2f\n", player->money);
        printf("Attaque : %d\n", player->current_attack);
        printf("Défense : %d\n", player->def);
        printf("Nb attaque : %d\n", player->nb_attack);
        printf("Nb arme : %d\n", player->nb_arme);
        printf("Nb armure : %d\n", player->nb_armure);
        printf("Nb sort : %d\n", player->nb_spell);
        printf("Q - Quitter\n");
        
    }
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
            fscanf(file, "Exp next : %d\n", &player->exp_next);
            fscanf(file, "Santé : %f\n", &player->health);
            fscanf(file, "Santer max : %f\n", &player->max_health);
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
        if (strcmp(ply->weapons[i]->name, weapon->name) == 0) {
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
        if (strcmp(ply->armors[i]->name, armor->name) == 0) {
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
        printf("%d. Arme: %s\tAttaque Min: %d\tAttaque Max: %d\tNombre d'attaques par tour: %d\n",
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
        printf("%d. Armure: %s\tProtection: %d\n",
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
            printf("%d. Sort: %s\tType: Offense\tMana: %d\tDégat: %d\n", i + 1, ply->spell[i]->name,
            ply->spell[i]->mana_cost, ply->spell[i]->damage);
        if (ply->spell[i]->type == DEFENSE)
            printf("%d. Sort: %s\tType: Défense\tMana: %d\tDéfense: %d\n", i + 1, ply->spell[i]->name,
            ply->spell[i]->mana_cost, ply->spell[i]->def);
        if (ply->spell[i]->type == CARE)
            printf("%d. Sort: %s\tType: Soin\tMana: %d\tSoin: %d\n", i + 1, ply->spell[i]->name,
            ply->spell[i]->mana_cost, ply->spell[i]->care);
    }
    return 1;
}

Player *use_spell(Player *ply, int key, Fight *fight)
{
    ply->mana -= ply->spell[key-1]->mana_cost;
    if (ply->spell[key -1]->type == OFFENSIVE) {
        ply->current_attack = ply->spell[key -1]->damage;
        for(int i = 0; i < fight->nbMonsters; i++)
            monster_defense(&fight->monsters[i], ply);
        ply->nb_attack--;
    } else if (ply->spell[key -1]->type == DEFENSE) {
        ply->def += ply->spell[key-1]->def;
    } else if (ply->spell[key-1]->type == CARE) {
        if (ply->spell[key -1]->care + ply->health >= 100)
            ply->health = 100;
        else
            ply->health += ply->spell[key -1]->care;
    }
    return ply;
}

Player *player_defense(Player *ply, Fight *fight)
{
    for (int i = 0; i < fight->nbMonsters; i++) {
        srand((unsigned int)time(NULL));
        monster_attack(&fight->monsters[i]);
        if (fight->monsters[i].health > 0)
            printf("Le monstre %d a lancé une attaque de %d\n", i+1, fight->monsters[i].current_attack);
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
    int i = 0;
    Weapon *ply_weapon = get_player_current_weapon(ply);
    Armor *ply_armor = get_player_current_armor(ply);
    if (key == 1) {
        printf("Quel monstre voulez-vous attaquer? ");
        for(i = 0; i < fight->nbMonsters -1; i++) {
            if (fight->monsters[i].health != 0 && fight->monsters[i].health != -1)
                printf("%d, ", i+1);
        }
        if (fight->monsters[i].health != 0 && fight->monsters[i].health != -1)
            printf("ou %d?\n", i+1);
        int id = 0;
        scanf("%d", &id);
        while (id < 1 || id > fight->nbMonsters) {
            if (fight->monsters[id-1].health == 0  && 
            fight->monsters[id-1].health == -1) {
                scanf("%d", &id);
                continue;
            }
            scanf("%d", &id);
        }
        fight->target = id-1;
        srand((unsigned int)time(NULL));
        ply->current_attack = rand() % (ply->attack_max - ply->attack_min + 1) + ply->attack_min;
        printf("Vous avez lancer une attaque de %d\n", ply->current_attack);
        monster_defense(&fight->monsters[fight->target], ply);
        ply->nb_attack--;
    }
    if (key == 2) {
        if (display_player_spell(ply)) {
            int id_spell = 0;
            scanf("%d", &id_spell);
            while (id_spell < 1 || id_spell > ply->nb_spell) {
                scanf("%d", &id_spell);
            }
            use_spell(ply, id_spell, fight);
        }
    }
    if (key == 3) {
        if (display_player_weapon(ply)) {
            int id_arme = 0;
            scanf("%d", &id_arme);
            while (id_arme < 1 || id_arme  > ply->nb_arme) {
                scanf("%d", &id_arme);
            }
            equip_weapon(ply->weapons[id_arme -1], ply);
        }
    }
    if (key == 4) {
        if (display_player_armor(ply)) {
            int id_armure = 0;
            scanf("%d", &id_armure);
            while (id_armure <  1 || id_armure > ply->nb_armure) {
                id_armure = getchar();
            }
            equip_armor(ply->armors[id_armure -1], ply);
        }
    }
    return ply;
   
}


void save_spell(Player *ply)
{
    FILE * f = fopen("../saves/spells.csv", "w");
    if (f != NULL) {
        fprintf(f,"nom_du_sort;type_sort;prix;level;degat;mana_cost;def;care\n");
        for (int i = 0; i < ply->nb_spell; i++) {
            if (ply->spell[i]->type == OFFENSIVE)
                fprintf(f, "%s;OFFENSIVE;%f;%d;%d;%d;%d;%d\n", ply->spell[i]->name,  ply->spell[i]->price,  ply->spell[i]->level,
                ply->spell[i]->damage, ply->spell[i]->mana_cost,  ply->spell[i]->def, ply->spell[i]->care);
            else if (ply->spell[i]->type == DEFENSE)
                fprintf(f, "%s;DEFENSE;%f;%d;%d;%d;%d;%d\n", ply->spell[i]->name,  ply->spell[i]->price,  ply->spell[i]->level,
                ply->spell[i]->damage, ply->spell[i]->mana_cost,  ply->spell[i]->def, ply->spell[i]->care);
            else if (ply->spell[i]->type == CARE)
                fprintf(f, "%s;CARE;%f;%d;%d;%d;%d;%d\n", ply->spell[i]->name,  ply->spell[i]->price,  ply->spell[i]->level,
                ply->spell[i]->damage, ply->spell[i]->mana_cost,  ply->spell[i]->def, ply->spell[i]->care);
        }
    }
    fclose(f);
}

void save_armor(Player *ply)
{
    FILE * f = fopen("../saves/armors.csv", "w");
    if (f != NULL) {
        fprintf(f,"name;protection;price;equiped\n");
        for (int i = 0; i < ply->nb_armure; i++) {
            fprintf(f, "%s;%d;%f;%d\n", ply->armors[i]->name, ply->armors[i]->protection, ply->armors[i]->price, ply->armors[i]->equiped);
        }
    }
    fclose(f);
}

void save_weapon(Player *ply)
{
    FILE * f = fopen("../saves/weapons.csv", "w");
    if (f != NULL) {
        fprintf(f,"name;attaqueMin;attaqueMin;attaquesParTour;price;equiped\n");
        for (int i = 0; i < ply->nb_arme; i++) {
            fprintf(f, "%s;%d;%d;%d;%f;%d\n", ply->weapons[i]->name, ply->weapons[i]->attaqueMin, ply->weapons[i]->attaqueMax, ply->weapons[i]->attaquesParTour, ply->weapons[i]->price, ply->weapons[i]->equiped);
        }
    }
    fclose(f);
}

void restor_weapons_player(Player *ply)
{
    Weapon **weapon = init_list_weapon(7);
    char *name = malloc(sizeof(char) *50);
    int attaque_min,attaque_max, nb_tour, equip;
    float price;
    FILE *f = fopen("../saves/weapons.csv", "r");
    char c = fgetc(f);
    int line = 1;
    while(c != EOF) {
        c = fgetc(f);
        if(c == '\n') {
            line++;
        }
    }
    fclose(f);
    f = fopen("../saves/weapons.csv", "r");

    if (f != NULL) {
        fgets(malloc(sizeof (char) * 100), 100, f);
        for(int i = 0; i < line-1; i++) {
            fscanf(f,"\n%[^;];%d;%d;%d;%f;%d", name, &attaque_min, &attaque_max, &nb_tour, &price, &equip);
            ply->weapons[i] = create_weapon(name, price, attaque_max, attaque_min, nb_tour, equip);
            printf("arme: %s\n",name);
            ply->weapons = add_weapon(ply->weapons, ply->weapons[i], i);
        }
    }
    free(name);
    fclose(f);
}

void restor_armors_player(Player *ply)
{
    Armor *armor = malloc(sizeof(Armor));
    char *name = malloc(sizeof(char) *50);
    int protection, equip;
    float price;
    FILE *f = fopen("../saves/armors.csv", "r");
    char c = fgetc(f);
    int line = 1;
    while(c != EOF) {
        c = fgetc(f);
        if(c == '\n') {
            line++;
        }
    }
    fclose(f);
    f = fopen("../saves/armors.csv", "r");
    if (f != NULL) {
        fgets(malloc(sizeof (char) * 100), 100, f);
        for(int i = 0; i < line; i++) {
            fscanf(f,"\n%[^;];%d;%f;%d", name, &protection, &price, &equip);
            ply->armors[i] = create_armor(name, price, protection, equip);
            ply->armors = add_armor(ply->armors, ply->armors[i], i+1);
        }
    }
    free(name);
    fclose(f);
}


void restor_spells_player(Player *ply)
{
    char *name = malloc(sizeof(char) *50);
    char *type = malloc(sizeof(char) *50);
    int level,degat,mana_cost,def,care;
    float price;
    FILE *f = fopen("../saves/spells.csv", "r");
    char c = fgetc(f);
    int line = 1;
    while(c != EOF) {
        c = fgetc(f);
        if(c == '\n') {
            line++;
        }
    }
    fclose(f);
    f = fopen("../saves/spells.csv", "r");
    fgets(malloc(sizeof (char) * 100), 100, f);
    for(int i = 0; i < line-2; i++) {
        fscanf(f,"\n%[^;];%[^;];%f;%d;%d;%d;%d;%d", name, type, &price, &level,&degat, &mana_cost, &def, &care);
        if (strcmp("DEFENSE", type) == 0) {
            ply->spell[i] = create_spell(name, DEFENSE, degat, def, mana_cost, price, level, care);
            ply->spell = add_spell(ply->spell, ply->spell[i], i);
        } else if (strcmp("OFFENSIVE", type) == 0) {
            ply->spell[i] = create_spell(name, OFFENSIVE, degat, def, mana_cost, price, level, care);
            ply->spell = add_spell(ply->spell, ply->spell[i], i);
        }else if (strcmp("CARE", type) == 0) {
            ply->spell[i] = create_spell(name, CARE, degat, def, mana_cost, price, level, care);
            ply->spell = add_spell(ply->spell, ply->spell[i], i);
        }
    }
    free(name);
    free(type);
    fclose(f);
}

int fight(Player * player){
    printf("Vous êtes attaqué par un monstre !\n");
    return 1;
}