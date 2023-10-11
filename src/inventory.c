#include "spell.h"

Armure **inventory_armure(Armure **armure)
{
    char *name = malloc(sizeof(char) *50);
    int protection,price;
    FILE *f = fopen("../files/Armure.csv", "r");
    char c = fgetc(f);
    int line = 1;
    while(c != EOF) {
        c = fgetc(f);
        if(c == '\n') {
            line++;
        }
    }
    fclose(f);
    f = fopen("../files/Armure.csv", "r");
    fgets(malloc(sizeof (char) * 100), 100, f);
    for(int i = 0; i < line-1; i++) {
        fscanf(f,"\n%[^;];%d;%d", name, &protection, &price);
        strcpy(armure[i]->name, name);
        armure[i]->price = price;
        armure[i]->protection = protection;
    }
    free(name);
    fclose(f);
    return armure;
}

Arme **inventory_arme(Arme **arme)
{
    char *name = malloc(sizeof(char) *50);
    int attaque_min,attaque_max, nb_tour,mana_cost,price;
    FILE *f = fopen("../files/Arme.csv", "r");
    char c = fgetc(f);
    int line = 1;
    while(c != EOF) {
        c = fgetc(f);
        if(c == '\n') {
            line++;
        }
    }
    fclose(f);
    f = fopen("../files/Arme.csv", "r");
    fgets(malloc(sizeof (char) * 100), 100, f);
    for(int i = 0; i < line-1; i++) {
        fscanf(f,"\n%[^;];%d;%d;%d;%d", name, &attaque_min, &attaque_max, &nb_tour, &price);
        strcpy(arme[i]->name, name);
        arme[i]->price = price;
        arme[i]->attaqueMin = attaque_min;
        arme[i]->attaqueMax = attaque_max;
        arme[i]->attaquesParTour = nb_tour;
    }
    free(name);
    fclose(f);
    return arme;
}

Spell **inventory_spell(Spell **spell)
{
    char *name = malloc(sizeof(char) *50);
    char *type = malloc(sizeof(char) *50);
    int price,level,degat,mana_cost,def,care;
    FILE *f = fopen("../files/Sort.csv", "r");
    char c = fgetc(f);
    int line = 1;
    while(c != EOF) {
        c = fgetc(f);
        if(c == '\n') {
            line++;
        }
    }
    fclose(f);
    f = fopen("../files/Sort.csv", "r");
    fgets(malloc(sizeof (char) * 100), 100, f);
    for(int i = 0; i < line-2; i++) {
        fscanf(f,"\n%[^;];%s;%d;%d;%d;%d;%d;%d", name, type, &price, &level,&degat, &mana_cost, &def, &care);
        strcpy(spell[i]->name, name);
        if (strcmp("DEFENSE", type) == 0)
            spell[i]->type = DEFENSE;
        else if (strcmp("OFFENSIVE", type) == 0)
            spell[i]->type = OFFENSIVE;
        else if (strcmp("CARE", type) == 0)
            spell[i]->type = CARE;
        spell[i]->price = price;
        spell[i]->level = level;
        spell[i]->damage = degat;
        spell[i]->mana_cost = mana_cost;
        spell[i]->def = def;
        spell[i]->care = care;
    }
    free(name);
    free(type);
    fclose(f);
    return spell;
}
