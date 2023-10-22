#include "arme.h"

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


Arme **init_list_arme(int size)
{
    Arme **arme = malloc(sizeof(Arme *) * size);
    for (int i = 0; i < size; i++)
        arme[i] = init_arme();
    return arme;
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

Arme *create_arme(char *name, float price, int attaqueMax, int attaqueMin, int attaqueParTour, int equiped)
{
    Arme *arme = init_arme();
    strcpy(arme->name, name);
    arme->attaqueMax = attaqueMax;
    arme->attaqueMin = attaqueMin;
    arme->attaquesParTour = attaqueParTour;
    arme->price = price;
    arme->equiped = equiped;

    return arme;
}

Arme **inventory_arme()
{
    Arme **arme = init_list_arme(7);
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
        arme[i] = create_arme(name, price, attaque_max, attaque_min, nb_tour, 0);
        arme = add_arme(arme, arme[i], i);
    }
    free(name);
    fclose(f);
    return arme;
}

