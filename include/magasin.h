#include "armor.h"
#include "player.h"
#include "spell.h"
#include "weapon.h"

void display_inventory_weapon(Weapon **wp, Player *ply);
void display_inventory_armor(Armor **armor, Player *ply);
void display_inventory_spell(Spell **spell, Player *ply);
void magasin(Player *ply);