#include "magasin.h"

void display_inventory_weapon(Weapon **wp, Player *ply)
{
    clearScreen();
    printf("Quelle arme voulez-vous acheter?\n");
    printf("Argent restant: %.2f\n", ply->money);
    printf("0. Retour\n");
    int a = 0;
    for (int i = 0; i < 7; i++) {
        a = 0;
        for (int j = 0; j < ply->nb_arme; j++) {
            if (strcmp(ply->weapons[j]->name, wp[i]->name) == 0)
                a = 1;
        }
        if (a == 0)
            printf("%d. Arme: %s\tAttaque Min: %d\tAttaque Max: %d\tNombre d'attaques par tour: %d\tPrix: %.2f\n",
            i+1, wp[i]->name, wp[i]->attaqueMin, wp[i]->attaqueMax, wp[i]->attaquesParTour, wp[i]->price);
    } 

}

void display_inventory_armor(Armor **armor, Player *ply)
{
    clearScreen();

    printf("Argent restant: %.2f\n", ply->money);
    printf("Quelle armure voulez-vous acheter?\n");
    printf("0. Retour\n");
    int a = 0;
    for (int i = 0; i < 7; i++) {
        a = 0;
        for (int j = 0; j < ply->nb_armure; j++) {
            if (strcmp(ply->armors[j]->name, armor[i]->name) == 0)
                a = 1;
        }
        if (a == 0)
            printf("%d. Armure: %s\tProtection: %d\tPrix: %.2f\n",
            i + 1, armor[i]->name, armor[i]->protection, armor[i]->price);

    }
}

void display_inventory_spell(Spell **spell, Player *ply)
{
    clearScreen();
    printf("Argent restant: %.2f\n", ply->money);
    printf("Quel sort voulez-vous acheter?\n");
    printf("0. Retour\n");
    int a = 0;
    for (int i = 0; i < 9; i++) {
        a = 0;
        for (int j = 0; j < ply->nb_spell; j++) {
            if (strcmp(ply->spell[j]->name, spell[i]->name) == 0)
                a = 1;
        }
        if (a == 0) {
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
}

void magasin(Player *ply)
{
    char c = '-';
    char choice = '-';
    printf("Argent restant: %.2f\n", ply->money);
    while (choice != '1' && choice != '2' && choice  != '3' && choice != '0') {
        printf("Que voulez-vous acheter?\n1- Une arme\n2- Une armure\n3- Un sort\n0- Continuer\n");
        system ("/bin/stty raw");
        choice = fgetc(stdin);
        system ("/bin/stty cooked");
    }
    if (choice == '1') {
        Weapon **wp = inventory_weapon();
        display_inventory_weapon(wp, ply);
        do {
            system ("/bin/stty raw");
            c = fgetc(stdin);
            system ("/bin/stty cooked");
        }
        while (c -48 > 7 || 0 > c -48);
        if (c == '0')
            return;
        if (ply->money >= wp[(c -48) -1]->price) {
            ply->money -= wp[(c -48) -1]->price;
            ply->weapons = add_weapon(ply->weapons, wp[(c -48) - 1], ply->nb_arme);
            ply->nb_arme++;
            printf("%s achetée !\n", wp[(c -48) - 1]->name);
            save_weapon(ply);
            magasin(ply);
        } else
            printf("Vous n'avez pas assez d'argent pour acheter cette arme!\n");
    } else if (choice == '2') {
        Armor **armor = inventory_armor();
        display_inventory_armor(armor, ply);
        do {
            system ("/bin/stty raw");
            c = fgetc(stdin);
            system ("/bin/stty cooked");
        }
        while (c -48 > 7 || 0 > c -48);
        if (c == '0') {
            return;
        }
        if (ply->money >= armor[(c -48) -1]->price) {
            ply->money -= armor[(c -48) -1]->price;
            ply->armors = add_armor(ply->armors, armor[(c -48) - 1], ply->nb_armure);
            ply->nb_armure++;
            printf("%s achetée !\n", armor[(c -48) - 1]->name);
            save_armor(ply);
            magasin(ply);
        } else
            printf("Vous n'avez pas assez d'argent pour acheter cette armure !\n");
    } else if (choice == '3') {
        Spell **spell = inventory_spell();
        display_inventory_spell(spell, ply);
        do {
            system ("/bin/stty raw");
            c = fgetc(stdin);
            system ("/bin/stty cooked");
        }
        while (c -48 > 7 || 0 > c -48);
        if (c == '0')
            return;
        if (ply->money >= spell[(c -48) -1]->price) {
            ply->money -= spell[(c -48) -1]->price;
            ply->spell = add_spell(ply->spell, spell[(c -48) - 1], ply->nb_spell);
            ply->nb_spell++;
            printf("Potion %s acheté !\n", spell[(c -48) - 1]->name);
            save_spell(ply);
            magasin(ply);
        } else
            printf("Vous n'avez pas assez d'argent pour acheter cette potion !\n");
    } else if (choice == '0') {
        save_armor(ply);
        save_weapon(ply);
        save_player(ply);
        save_spell(ply);
        return;
    }
}