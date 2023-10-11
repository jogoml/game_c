#include "spell.h"

Arme *init_arme()
{
    Arme *arme = malloc(sizeof(Arme));
    arme->name = malloc(sizeof(char) * 100);
    arme->attaqueMax = 0;
    arme->attaqueMin = 0;
    arme->attaquesParTour = 0;
    arme->price = 0;
    arme->equiped = 0;

    return arme;
}

Armure *init_armure()
{
    Armure *armure = malloc(sizeof(Armure));
    armure->name = malloc(sizeof(char) * 100);
    armure->protection = 0;
    armure->price = 0;
    armure->equiped = 0;

    return armure;
}

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

Armure **init_list_armure(int size)
{
    Armure **armure = malloc(sizeof(Armure *) * size);
    for (int i = 0; i < size; i++)
        armure[i] = init_armure();
    return armure;
}

Arme **init_list_arme(int size)
{
    Arme **arme = malloc(sizeof(Arme *) * size);
    for (int i = 0; i < size; i++)
        arme[i] = init_arme();
    return arme;
}
