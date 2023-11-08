#include "weapon.h"

Weapon *init_weapon()
{
    Weapon *weapon = malloc(sizeof(Weapon));
    weapon->name = malloc(sizeof(char) * 100);
    weapon->attaqueMax = 0;
    weapon->attaqueMin = 0;
    weapon->attaquesParTour = 0;
    weapon->price = 0;
    weapon->equiped = 0;

    return weapon;
}


Weapon **init_list_weapon(int size)
{
    Weapon **weapon = malloc(sizeof(Weapon *) * size);
    for (int i = 0; i < size; i++)
        weapon[i] = init_weapon();
    return weapon;
}

Weapon **add_weapon(Weapon **weapon, Weapon *new_weapon, int pos)
{
    weapon[pos]->name = new_weapon->name;
    weapon[pos]->price = new_weapon->price;
    weapon[pos]->attaqueMax = new_weapon->attaqueMax;
    weapon[pos]->attaqueMin = new_weapon->attaqueMin;
    weapon[pos]->attaquesParTour = new_weapon->attaquesParTour;
    weapon[pos]->equiped = new_weapon->equiped;

    return weapon;
}

Weapon *create_weapon(char *name, float price, int attaqueMax, int attaqueMin, int attaqueParTour, int equiped)
{
    Weapon *weapon = init_weapon();
    strcpy(weapon->name, name);
    weapon->attaqueMax = attaqueMax;
    weapon->attaqueMin = attaqueMin;
    weapon->attaquesParTour = attaqueParTour;
    weapon->price = price;
    weapon->equiped = equiped;

    return weapon;
}

Weapon **inventory_weapon()
{
    Weapon **weapon = init_list_weapon(7);
    char *name = malloc(sizeof(char) *50);
    int attaque_min,attaque_max, nb_tour;
    float price;
    FILE *f = fopen("../files/Arme.csv", "r");
    char c = fgetc(f);
    int line = 1;
    while(c != EOF) {
        c = fgetc(f);
        if(c == '\n') {
            line++;
        }
    }
    fclose(f);
    f = fopen("../files/Arme.csv", "r");
    fgets(malloc(sizeof (char) * 100), 100, f);
    for(int i = 0; i < line-1; i++) {
        fscanf(f,"\n%[^;];%d;%d;%d;%f", name, &attaque_min, &attaque_max, &nb_tour, &price);
        weapon[i] = create_weapon(name, price, attaque_max, attaque_min, nb_tour, 0);
        weapon = add_weapon(weapon, weapon[i], i);
    }
    free(name);
    fclose(f);
    return weapon;
}

