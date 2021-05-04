#include <stdio.h>
#include <stdlib.h>
#include "logicalPart.h"
#include "fileReadStore.h"
int NextState(const int *pwidth, const int *plength, int **istate)
{
    if((pwidth==NULL)||(plength==NULL)||(istate==NULL)){
        //printf("wrong input\n");
        return -1;
    }
    int **newstate;
    newstate = createArray(plength, pwidth);
    int count = 0;
    for (int i = 0; i < (*pwidth); i++)
    {
        for (int j = 0; j < (*plength); j++)
        {
            if ((j - 1) >= 0)
            {
                if (istate[i][j - 1] == 1)
                {
                    count++;
                }
            }
            if ((j + 1) < (*plength))
            {
                if (istate[i][j + 1] == 1)
                {
                    count++;
                }
            }
            if ((i - 1) >= 0)
            {
                if (istate[i - 1][j] == 1)
                {
                    count++;
                }
            }
            if ((i + 1) < (*pwidth))
            {
                if (istate[i + 1][j] == 1)
                {
                    count++;
                }
            }
            if (((j - 1) >= 0) && ((i - 1) >= 0))
            {
                if (istate[i - 1][j - 1] == 1)
                {
                    count++;
                }
            }
            if (((j - 1) >= 0) && ((i + 1) < (*pwidth)))
            {
                if (istate[i + 1][j - 1] == 1)
                {
                    count++;
                }
            }
            if (((j + 1) < (*plength)) && ((i - 1) >= 0))
            {
                if (istate[i - 1][j + 1] == 1)
                {
                    count++;
                }
            }
            if (((j + 1) < (*plength)) && ((i + 1) < (*pwidth)))
            {
                if (istate[i + 1][j + 1] == 1)
                {
                    count++;
                }
            }
            if (istate[i][j] == 0)
            {
                if (count == 3)
                {
                    newstate[i][j] = 1;
                }
            }
            else
            {
                if ((count == 2) || (count == 3))
                {
                    newstate[i][j] = 1;
                }
            }
            count = 0;
        }
    }
    for (int i = 0; i < (*pwidth); i++)
    {
        for (int j = 0; j < (*plength); j++)
        {
            istate[i][j] = newstate[i][j];
        }
    }
    for (int i = 0; i < (*pwidth); i++)
    {
        free(newstate[i]);
    }
    free(newstate);
    return 0;
}
// int main(void)
// {
//     int length;
//     int width;
//     int **istate;
//     FILE *file = fopen("initial.txt", "r");
//     if (file == NULL)
//     {
//         return -1;
//     }
//     else
//     {
//         findSize(file, &length, &width);
//         fclose(file);
//         file = fopen("initial.txt", "r");
//         istate = createArray(&length, &width);
//         readArray(file, istate, &length, &width);
//         fclose(file);
//     }
//     for (int i = 0; i < (width); i++)
//     {
//         for (int j = 0; j < (length); j++)
//         {
//             printf("%d", istate[i][j]);
//         }
//         printf("\n");
//     }
//     printf("******************\n");
//     NextState(&width, &length, istate);
//     for (int i = 0; i < (width); i++)
//     {
//         for (int j = 0; j < (length); j++)
//         {
//             printf("%d", istate[i][j]);
//         }
//         printf("\n");
//     }
//     file = fopen("initial.txt", "w");
//     storeArray(file, istate, &length, &width);
//     fclose(file);
//     for (int i = 0; i < width; i++)
//     {
//         free(istate[i]);
//     }
//     free(istate);

//     return 0;
// }