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
