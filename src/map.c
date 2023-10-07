#include "map.h"

int getMap(Context* context)
{
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
    fclose(f);
    return 0;
}

void showMap(Context* context)
{
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
                    }else if (context->map[i][j] == 'F')
                    {
                        printf("\033[1;32mO");
                    }else if (context->map[i][j] == 'D')
                    {
                        printf("\033[1;32mO");
                    }else if (context->map[i][j] == 'B')
                    {
                        printf("\033[1;33mB");
                    }
                    printf("\033[0m");
                    
                }
            }
            printf("\n");
        }
        
    }
}