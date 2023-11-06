#include "armure.h"

Armor *init_armor()
{
    Armor *armor = malloc(sizeof(Armor));
    armor->name = malloc(sizeof(char) * 100);
    armor->protection = 0;
    armor->price = 0;
    armor->equiped = 0;

    return armor;
}

Armor **init_list_armor(int size)
{
    Armor **armor = malloc(sizeof(Armor *) * size);
    for (int i = 0; i < size; i++)
        armor[i] = init_armor();
    return armor;
}

Armor **add_armor(Armor **armor, Armor *new_armor, int pos)
{
    armor[pos]->name = new_armor->name;
    armor[pos]->price = new_armor->price;
    armor[pos]->protection = new_armor->protection;
    armor[pos]->equiped = new_armor->equiped;
    return armor;
}

Armor *create_armor(char *name, float price, int protection, int equiped)
{
    Armor *armor = init_armor();
    strcpy(armor->name, name);
    armor->protection = protection;
    armor->price = price;
    armor->equiped = equiped;
    return armor;
}

Armor **inventory_armor()
{
    Armor **armor = init_list_armor(8);
    char *name = malloc(sizeof(char) *50);
    int protection;
    float price;
    FILE *f = fopen("../files/Armure.csv", "r");
    char c = fgetc(f);
    int line = 1;
    while(c != EOF) {
        c = fgetc(f);
        if(c == '\n') {
            line++;
        }
    }
    fclose(f);
    f = fopen("../files/Armure.csv", "r");
    fgets(malloc(sizeof (char) * 100), 100, f);
    for(int i = 0; i < line-1; i++) {
        fscanf(f,"\n%[^;];%d;%f", name, &protection, &price);
        armor[i] = create_armor(name, price, protection, 0);
        armor = add_armor(armor, armor[i], i);
    }
    free(name);
    fclose(f);
    return armor;
}
