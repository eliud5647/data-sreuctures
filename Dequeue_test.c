#include <stdio.h>
#include <string.h>
#include "queue.h"
#include "datatypes.h"

int main(){
    queue_t cola=QUEUEINITIALIZER;
    int i,j=0,k=1;
    for(i=1;i<21;i++){
        if(j)
        {
            queue_offer_first(&cola,int_new(i));
            j=j*-1+1;
        }else
        {
            queue_offer_last(&cola,int_new(i));
            j=j*-1+1;
        }

    }
    while (!queue_empty(&cola))
    {
        k=int_value(queue_poll_last(&cola));
        printf("%d\n",k);
    }
    
    queue_clean(&cola);
    

}