#include "utils.h"
#include "map.h"

int main(int argc, char** argv){
    Context* context = malloc(sizeof(Context));
    context->x = 3;
    context->y = 3;
    context->nameMap = malloc(sizeof(char)*20);
    context->nameMap = "../saves/level1.map";
    if(getMap(context)!=0){
        printf("ERROR GET MAP\n");
        return 1;
    }
    showMap(context);
    
}