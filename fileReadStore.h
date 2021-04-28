#include<stdio.h>


int findSize(FILE*file,int *plength,int *pwidth);
int **createArray(int *plength,int *pwidth);
int readArray(FILE*file,int **istate,int *plength,int *pwidth);
int storeArray(FILE*file,int **istate,int *plength,int *pwidth);