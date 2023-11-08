#ifndef SPELL_H
#define SPELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef enum spell_type {
    OFFENSIVE,
    DEFENSE,
    CARE
}spell_type;

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


Spell *init_spell();
Spell **init_list_spell(int size);

Spell **add_spell(Spell **spell, Spell *new_spell, int pos);
Spell *create_spell(char *name, spell_type type, int damage, int def, int mana_cost, float price, int level, float care);
Spell **inventory_spell();

#endif