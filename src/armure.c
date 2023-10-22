#include "armure.h"

Armure *init_armure()
{
    Armure *armure = malloc(sizeof(Armure));
    armure->name = malloc(sizeof(char) * 100);
    armure->protection = 0;
    armure->price = 0;
    armure->equiped = 0;

    return armure;
}

Armure **init_list_armure(int size)
{
    Armure **armure = malloc(sizeof(Armure *) * size);
    for (int i = 0; i < size; i++)
        armure[i] = init_armure();
    return armure;
}

Armure **add_armure(Armure **armure, Armure *new_armure, int pos)
{
    armure[pos]->name = new_armure->name;
    armure[pos]->price = new_armure->price;
    armure[pos]->protection = new_armure->protection;
    armure[pos]->equiped = new_armure->equiped;
    return armure;
}

Armure *create_armure(char *name, float price, int protection, int equiped)
{
    Armure *armure = init_armure();
    strcpy(armure->name, name);
    armure->protection = protection;
    armure->price = price;
    armure->equiped = equiped;
    return armure;
}

Armure **inventory_armure()
{
    Armure **armure = init_list_armure(8);
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
        armure[i] = create_armure(name, price, protection, 0);
        armure = add_armure(armure, armure[i], i);
    }
    free(name);
    fclose(f);
    return armure;
}
