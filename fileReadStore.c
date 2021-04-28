#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LINE 1024
#include "fileReadStore.h"

int findSize(FILE *file, int *plength, int *pwidth)
{
    int judge = 0;
    *plength = 0;
    *pwidth = 0;
    char buf[MAX_LINE];
    memset(buf, 0, sizeof(buf));
    while (fgets(buf, MAX_LINE, file) != NULL)
    {
        (*plength) = strspn(buf, "0123456789");
        if (judge > 0)
        {
            if ((*plength) != judge)
            {
                return 1;
            }
            (*pwidth)++;
        }
        else
        {
            judge = (*plength);
            (*pwidth)++;
        }
    }
    return 0;
}
int **createArray(int *plength, int *pwidth)
{
    int **pp = (int **)malloc(sizeof(int *) * (*pwidth));
    for (int i = 0; i < (*pwidth); i++)
    {
        pp[i] = (int *)malloc(sizeof(int) * (*plength));
    }
    for (int a = 0; a < (*pwidth); a++)
    {
        for (int b = 0; b < (*plength); b++)
        {
            pp[a][b] = 0;
        }
    }

    return pp;
}
int readArray(FILE *file, int **istate, int *plength, int *pwidth)
{
    char buf[MAX_LINE];
    int row = 0;
    int col = 0;
    memset(buf, 0, sizeof(buf));
    while (fgets(buf, MAX_LINE, file) != NULL)
    {
        for (int i = 0; i < (*plength); i++)
        {
            istate[row][col] = buf[i] - '0';
            col++;
        }
        col = 0;
        row++;
    }
    return 0;
}
int storeArray(FILE *file, int **istate, int *plength, int *pwidth)
{
    char buf[MAX_LINE];
    int len;
    memset(buf, 0, sizeof(buf));
    for (int i = 0; i < (*pwidth); i++)
    {
        for (int j = 0; j < (*plength); j++)
        {
            buf[j] = istate[i][j] + '0';
        }
        if(i<((*pwidth)-1)){
            buf[(*plength)]='\n';
        }
        fputs(buf,file);
    }
    return 0;
}
