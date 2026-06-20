#include<stdlib.h>
#include "rectangle.h"

RECTANGLE *rectangle_create(float base, float height)
{
    RECTANGLE *temp=malloc(sizeof(RECTANGLE));
    temp->altura=height;
    temp->base=base;
    return temp;
    
}

float rectangle_base(RECTANGLE r)
{
    return r.base;
}

float rectangle_height(RECTANGLE r)
{
    return r.altura;
}

float rectangle_area(RECTANGLE r)
{
    return r.altura*r.base;
}

float rectangle_perimeter( RECTANGLE r)
{
    return 2*r.altura+2*r.base;
}

void rectangle_set_base(RECTANGLE *r,float base)
{
    r->base=base;
}
void rectangle_set_height(RECTANGLE *r, float height)
{
    r->altura=height;
}