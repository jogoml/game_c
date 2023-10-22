#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure pour représenter une armure
typedef struct Armure {
    char *name;        // Nom de l'armure
    int protection;      // Valeur de protection
    float price;
    int equiped;
} Armure;

Armure *init_armure();
Armure **init_list_armure(int size);
Armure **add_armure(Armure **spell, Armure *new_spell, int pos);
Armure *create_armure(char *name, float price, int protection, int equiped);
Armure **inventory_armure();