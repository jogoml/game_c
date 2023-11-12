#include "magasin.h"

void display_inventory_weapon(Weapon **wp, Player *ply)
{
    printf("Quelle arme voulez-vous acheter?\n");
    for (int i = 0; i < 7; i++) {
        if (ply->weapons[i] && strcmp(ply->weapons[i]->name,wp[i]->name) == 0)
            continue;
        printf("%d. Arme: %s\tAttaque Min: %d\tAttaque Max: %d\tNombre d'attaques par tour: %d\tPrix: %.2f\n",
        i+1, wp[i]->name, wp[i]->attaqueMin, wp[i]->attaqueMax, wp[i]->attaquesParTour, wp[i]->price);
    }
}

void display_inventory_armor(Armor **armor, Player *ply)
{
    printf("Quelle armure voulez-vous acheter?\n");
    for (int i = 0; i < 7; i++) {
        if (ply->armors[i] && strcmp(ply->armors[i]->name, armor[i]->name) == 0)
            continue;
        printf("%d. Armure: %s\tProtection: %d\tPrix: %.2f\n",
        i + 1, armor[i]->name, armor[i]->protection, armor[i]->price);
    }
}

void display_inventory_spell(Spell **spell, Player *ply)
{
    printf("Quel sort voulez-vous acheter?\n");
    for (int i = 0; i < 9; i++) {
        if (ply->spell[i] && strcmp(ply->spell[i]->name, spell[i]->name) == 0)
            continue;
        if (ply->level >= spell[i]->level) {
            if (spell[i]->type == OFFENSIVE)
                printf("%d. Sort: %s\tType: Offense\tMana: %d\tDégat: %d\tPrix: %.2f\n", i + 1, spell[i]->name,
                spell[i]->mana_cost, spell[i]->damage, spell[i]->price);
            if (spell[i]->type == DEFENSE)
                printf("%d. Sort: %s\tType: Défense\tMana: %d\tDéfense: %d\tPrix: %.2f\n", i + 1, spell[i]->name,
                spell[i]->mana_cost, spell[i]->def, spell[i]->price);
            if (spell[i]->type == CARE)
                printf("%d. Sort: %s\tType: Soin\tMana: %d\tSoin: %d\tPrix: %.2f\n", i + 1, spell[i]->name,
                spell[i]->mana_cost, spell[i]->care, spell[i]->price);
        }
    }
}

void magasin(Player *ply)
{
        printf("Que voulez-vous acheter?\n1- Une arme\n2- Une armure\n3- Un sort\n");
        int choice;
        scanf("%d", &choice);
        while (choice  != 1 && choice != 2 && choice  != 3) {
            printf("Que voulez-vous acheter?\n1- Une arme\n2- Une armure\n3-Un sort\n");
            scanf("%d", &choice);
        }
        if (choice == 1) {
            Weapon **wp = inventory_weapon();
            display_inventory_weapon(wp, ply);
            scanf("%d", &choice);
            while (choice > 7 || 0 >= choice)
                scanf("%d", &choice);
            ply->money -= wp[(choice) -1]->price;
            ply->weapons = add_weapon(ply->weapons, wp[(choice) - 1], ply->nb_arme);
            ply->nb_arme++;
        } else if (choice == 2) {
            Armor **armor = inventory_armor();
            display_inventory_armor(armor, ply);
            scanf("%d", &choice);
            while (choice > 7 || 0 >= choice)
                scanf("%d", &choice);;
            ply->money -= armor[(choice) -1]->price;
            ply->armors = add_armor(ply->armors, armor[(choice) - 1], ply->nb_armure);
            ply->nb_armure++;
        } else if (choice == 3) {
            Spell **spell = inventory_spell();
            display_inventory_spell(spell, ply);
            scanf("%d", &choice);
            while (choice > 7 || 0 >= choice)
                scanf("%d", &choice);
            ply->money -= spell[(choice) -1]->price;
            ply->spell = add_spell(ply->spell, spell[(choice) - 1], ply->nb_spell);
            ply->nb_spell++;
        }
}