#include "datatypes.h"

int *int_new(int i)
{
    int *new = malloc(sizeof(int));
    *new = i;
    return new;
}

float *float_new(float f)
{
    float *new = malloc(sizeof(float));
    *new = f;
    return new;
}

double *double_new(double d)
{
    double *new = malloc(sizeof(double));
    *new = d;
    return new;
}

char *string_new(char *s)
{
    int size = 0;
    int i;
    char *new;

    while(*(s+size)!='\0')
        size++;              // Medir el tamaño de la cadena

    new = malloc(size+1);

    for(i=0;i<size+1;i++)
        *(new+i) = *(s+i);  // Hacer una copia de la cadena en el nuevo nodo
    
    return new;
}
