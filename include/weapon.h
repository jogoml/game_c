#ifndef WEAPON_H
#define WEAPON_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Weapon {
    char *name;        // Nom de l'arme
    int attaqueMin;      // Attaque minimale
    int attaqueMax;      // Attaque maximale
    int attaquesParTour; // Nombre d'attaques par tour
    float price;
    int equiped;
} Weapon;

Weapon *init_weapon();
Weapon **init_list_weapon(int size);
Weapon **add_weapon(Weapon **spell, Weapon *new_spell, int pos);
Weapon *create_weapon(char *name, float price, int attaqueMax, int attaqueMin, int attaqueParTour, int equiped);
Weapon **inventory_weapon();

#endif