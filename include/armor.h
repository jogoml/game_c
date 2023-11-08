#ifndef ARMOR_H
#define ARMOR_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// Structure pour représenter une armure
typedef struct Armor {
    char *name;        // Nom de l'armure
    int protection;      // Valeur de protection
    float price;
    int equiped;
} Armor;

Armor *init_armor();
Armor **init_list_armor(int size);
Armor **add_armor(Armor **spell, Armor *new_spell, int pos);
Armor *create_armor(char *name, float price, int protection, int equiped);
Armor **inventory_armor();

#endif