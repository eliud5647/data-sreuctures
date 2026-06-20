#include <time.h>
#include <stdlib.h>
#include "linkedlist.h"

#define LIMIT 20

int main()
{
    LINKEDLIST l;
    int i,n;

     srand(time(NULL));
     linkedlist_init(&l);

     for(i=0;i<LIMIT;i++)
     {
         n = rand() % LIMIT;
         if(!linkedlist_found(l,n))
         linkedlist_add(&l,n);
     }
     linkedlist_display(l);
     linkedlist_clean(&l);
}