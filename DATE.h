#include<stdint.h>
#include<stdio.h>
#include<stdlib.h>
#ifndef _DATE_H_
    #define _DATE_H
    typedef struct{   
        uint32_t dia;
        uint32_t mes;
        uint32_t año;
    } DATE;
    DATE *date_create(uint32_t dia,uint32_t mes, uint32_t año);
    void date_print(DATE date);
    void date_destroy(DATE *date);

#endif