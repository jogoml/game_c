#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum spell_type {
    OFFENSIVE,
    DEFENSE,
    CARE
}spell_type;

typedef struct Arme {
    char *name;        // Nom de l'arme
    int attaqueMin;      // Attaque minimale
    int attaqueMax;      // Attaque maximale
    int attaquesParTour; // Nombre d'attaques par tour
    float price;
    int equiped;
} Arme;

// Structure pour représenter une armure
typedef struct Armure {
    char *name;        // Nom de l'armure
    int protection;      // Valeur de protection
    float price;
    int equiped;
} Armure;

typedef struct Spell {
	char *name;
    spell_type type;
	int damage;
    int def;
    int care;
	int mana_cost;
	float price;
    int level;
} Spell;

Arme *init_arme();
Armure *init_armure();
Spell *init_spell();
Spell **init_list_spell(int size);
Arme **init_list_arme(int size);
Armure **init_list_armure(int size);
Spell **add_spell(Spell **spell, Spell *new_spell, int pos);
Arme **add_arme(Arme **spell, Arme *new_spell, int pos);
Armure **add_armure(Armure **spell, Armure *new_spell, int pos);
Spell **inventory_spell(Spell **spell);
Arme **inventory_arme(Arme **arme);
Armure **inventory_armure(Armure **armure);