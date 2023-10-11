#include "spell.h"


Spell **add_spell(Spell **spell, Spell *new_spell, int pos)
{
    spell[pos]->name = new_spell->name;
    spell[pos]->price = new_spell->price;
    spell[pos]->type = new_spell->type;
    spell[pos]->damage = new_spell->damage;
    spell[pos]->def = new_spell->def;
    spell[pos]->mana_cost = new_spell->mana_cost;
    spell[pos]->level = new_spell->level;

    return spell;
}

Arme **add_arme(Arme **arme, Arme *new_arme, int pos)
{
    arme[pos]->name = new_arme->name;
    arme[pos]->price = new_arme->price;
    arme[pos]->attaqueMax = new_arme->attaqueMax;
    arme[pos]->attaqueMin = new_arme->attaqueMin;
    arme[pos]->attaquesParTour = new_arme->attaquesParTour;
    arme[pos]->equiped = new_arme->equiped;

    return arme;
}

Armure **add_armure(Armure **armure, Armure *new_armure, int pos)
{
    armure[pos]->name = new_armure->name;
    armure[pos]->price = new_armure->price;
    armure[pos]->protection = new_armure->protection;
    armure[pos]->equiped = new_armure->equiped;
    return armure;
}
