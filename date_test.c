#include<stdio.h>
#include "DATE.h"

int main(){
    DATE *fecha;
    fecha=date_create(10,13,1900);
    date_print(*fecha);
    date_destroy(fecha);
}