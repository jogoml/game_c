#include "spell.h"

Spell *init_spell()
{
    Spell *spell = malloc(sizeof(Spell));
    spell->name = malloc(sizeof(char) * 100);
    spell->type = 0;
    spell->damage = 0;
    spell->def = 0;
	spell->mana_cost = 0;
	spell->price = 0;
    spell->level = 0;

    return spell;
}

Spell **init_list_spell(int size)
{
    Spell **spell = malloc(sizeof(Spell *) * size);
    for (int i = 0; i < size; i++)
        spell[i] = init_spell();
    return spell;
}


Spell *create_spell(char *name, spell_type type, int damage, int def, int mana_cost, float price, int level)
{
    Spell *spell = init_spell();
    strcpy(spell->name, name);
    spell->type = type;
    spell->damage = damage;
    spell->def = def;
	spell->mana_cost = mana_cost;
	spell->price = price;
    spell->level = level;
    return spell;
}

Spell **add_spell(Spell **spell, Spell *new_spell, int pos)
{
    strcpy(spell[pos]->name, new_spell->name);
    spell[pos]->price = new_spell->price;
    spell[pos]->type = new_spell->type;
    spell[pos]->damage = new_spell->damage;
    spell[pos]->def = new_spell->def;
    spell[pos]->mana_cost = new_spell->mana_cost;
    spell[pos]->level = new_spell->level;

    return spell;
}

Spell **inventory_spell()
{
    char *name = malloc(sizeof(char) *50);
    char *type = malloc(sizeof(char) *50);
    int level,degat,mana_cost,def,care;
    float price;
    Spell **spell = init_list_spell(10);
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
        fscanf(f,"\n%[^;];%[^;];%f;%d;%d;%d;%d;%d", name, type, &price, &level,&degat, &mana_cost, &def, &care);
        if (strcmp("DEFENSE", type) == 0) {
            spell[i] = create_spell(name, DEFENSE, degat, def, mana_cost, price, level);
            spell = add_spell(spell, spell[i], i);
        } else if (strcmp("OFFENSIVE", type) == 0) {
            spell[i] = create_spell(name, OFFENSIVE, degat, def, mana_cost, price, level);
            spell = add_spell(spell, spell[i], i);
        }else if (strcmp("CARE", type) == 0) {
            spell[i] = create_spell(name, CARE, degat, def, mana_cost, price, level);
            spell = add_spell(spell, spell[i], i);
        }
    }
    free(name);
    free(type);
    fclose(f);
    return spell;
}
