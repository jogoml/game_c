#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct Arme {
    char *name;        // Nom de l'arme
    int attaqueMin;      // Attaque minimale
    int attaqueMax;      // Attaque maximale
    int attaquesParTour; // Nombre d'attaques par tour
    float price;
    int equiped;
} Arme;

Arme *init_arme();
Arme **init_list_arme(int size);
Arme **add_arme(Arme **spell, Arme *new_spell, int pos);
Arme *create_arme(char *name, float price, int attaqueMax, int attaqueMin, int attaqueParTour, int equiped);
Arme **inventory_arme();
