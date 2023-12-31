#include "map.h"
char *maps[1] = {"../saves/level1.map"};
int nbMaps = 1;

int getMap(Context* context)
{
    if(context->map != NULL)
    {
        for (int i = 0; i < ROWS; i++)
        {
            free(context->map[i]);
        }
        free(context->map);
    }
    context->map = malloc(sizeof(char *)*ROWS);
    if(context->map == NULL)
    {
        printf("ALED\n");
        return 1;
    }
    FILE * f= fopen(context->nameMap, "r");
    if(f == NULL)
    {
        perror("ALED FICHIER\n");
        return 1;
    }
    for (int i = 0;i < ROWS; i++)
    {
        context->map[i] = malloc(COLUMNS);
        for (int j = 0;j < COLUMNS; j++)
        {
            context->map[i][j] = fgetc(f);
        }
        fgetc(f);
    }
    fscanf(f, "%d %d", &context->x, &context->y);
    fclose(f);
    return 0;
}

void saveMap(Context *context){
    FILE * f= fopen(context->nameMap, "w");
    if(f == NULL)
    {
        return;
    }
    for (int i = 0;i < ROWS; i++)
    {
        for (int j = 0;j < COLUMNS; j++)
        {
            fputc(context->map[i][j],f);
        }
        fputc('\n',f);
    }
    fprintf(f, "%d %d", context->x, context->y);
    fclose(f);
}

void restartMap(Context *context){
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLUMNS; j++)
        {
            if(context->map[i][j] == 'F'){
                context->map[i][j] = 'M';
            }else if(context->map[i][j] == 'P'){
                context->map[i][j] = 'B';
            }else if(context->map[i][j] == 'D'){
                context->x = j;
                context->y = i;
            }
        }
        
    }
    saveMap(context);
}

void restartMaps(Context *context){
    for (int i = 0; i < nbMaps; i++)
    {
        Context *ctx = malloc(sizeof(Context));
        ctx->nameMap = maps[i];
        getMap(ctx);
        restartMap(ctx);
        free(ctx);
    }
    context->nameMap = malloc(sizeof(char)*100);
    strcpy(context->nameMap, "../saves/level1.map");
}

void getCurrentMap(Context *context){
    FILE * f= fopen("../saves/currentMap", "r");
    if(f == NULL)
    {
        return;
    }
    context->nameMap = malloc(sizeof(char)*100);
    fscanf(f, "%s", context->nameMap);
    fclose(f);
}

void setCurrentMap(Context *context){
    FILE * f= fopen("../saves/currentMap", "w");
    if(f == NULL)
    {
        return;
    }
    fprintf(f, "%s", context->nameMap);
    fclose(f);
}

void nextMap(Context *context, Player *player){
    for (int i = 0; i < nbMaps; i++)
    {
        if(strcmp(context->nameMap, maps[i]) == 0){
            if(i+1 < nbMaps){
                player->difficulty ++;
                context->nameMap = maps[i+1];
                getMap(context);
                setCurrentMap(context);
                return;
            }
        }
        else {
            endGame(context, player, 1);
        }
    }
    
}

void showMap(Context* context, Player * player)
{
    printf("Quitter : Q(Maj)            Menu : p            Move : zqsd\n");
    // display some info player
    printf("\nPlayer : %s\n", player->name);
    printf("HP : %.2f/%.2f\n", player->health, player->max_health);
    printf("EXP : %d/%d\n", player->exp, player->exp_next);
    for (int i = 0; i < ROWS; i++)
    {
        for(int k = 0; k < 3; k++)
        {
            for (int j = 0;j < COLUMNS; j++)
            {
                for (int l = 0; l < 4; l++)
                {
                    if(i==context->y && j==context->x && ((k==0 && l==0 )|| (k==2 && l==3)))
                    {
                        printf("/");
                    }else if(i==context->y && j==context->x && ((k==0 && l==3 )|| (k==2 && l==0)))
                    {
                        printf("\\");
                    }else if(i==context->y && j==context->x && (k==0 || k==2))
                    {
                        printf("-");
                    }else if(i==context->y && j==context->x && (l==0 || l==3))
                    {
                        printf("|");
                    }else if (context->map[i][j] == 'N')
                    {
                        printf(" ");
                    }else if (context->map[i][j] == 'M')
                    {
                        printf("\033[1;31m%c", context->map[i][j]);
                    }else if (context->map[i][j] == 'O')
                    {
                        printf("X");
                    }else if (context->map[i][j] == 'F' || context->map[i][j] == 'P')
                    {
                        printf("\033[1;32mO");
                    }else if (context->map[i][j] == 'D')
                    {
                        printf("\033[1;32mO");
                    }else if (context->map[i][j] == 'B')
                    {
                        printf("\033[1;33mB");
                    } else if (context->map[i][j] == 'S')
                        printf("\033[1;33mS");
                    printf("\033[0m");
                    
                }
            }
            printf("\n");
        }
        
    }
    if (context->map == NULL)
    {
        printf("ALED NO MAP\n");
        return;
    }
    
}