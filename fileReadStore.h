#include<stdio.h>


int findSize(FILE*file,int *plength,int *pwidth);
int **createArray(const int *plength,const int *pwidth);
int readArray(FILE*file,int **istate,const int *plength,const int *pwidth);
int storeArray(FILE*file,int **istate,const int *plength,const int *pwidth);