#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>

#ifndef _RECTANGLE_H_
    #define _RECTANGLE_H_
    typedef struct
    {
        float base;
        float altura;
        
    }RECTANGLE;
    RECTANGLE *rectangle_create(float base, float height);
    float rectangle_base(RECTANGLE r);
    float rectangle_height(RECTANGLE r);
    float rectangle_area(RECTANGLE r);
    float rectangle_perimeter( RECTANGLE r);
    void rectangle_set_base(RECTANGLE *r,float base);
    void rectangle_set_height(RECTANGLE *r, float height);
    

#endif