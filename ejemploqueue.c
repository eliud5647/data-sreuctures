
#include <stdio.h>
#include <string.h>
#include "queue.h"
#include "datatypes.h"

#define NAMELEN 40
int main()
{
    int i;
    type_t *n;
    queue_t cola = QUEUEINITIALIZER;
    FILE *fp = fopen("nombres.txt","r");
    char name[NAMELEN];
    char *x;

    if(fp==NULL)
    {
        perror("Error en la apertura del archivo\n");
        exit(1);
    }

    while(fgets(name,NAMELEN,fp)!=NULL) 
    {
        name[strcspn(name, "\n\r")] = '\0';
        if(queue_offer(&cola,string_new(name))==-1)
        {
            perror("Error al crear un nodo nuevo en la cola\n");
            exit(1);
        }
    }

    while(!queue_empty(&cola))
    {
        x = (int )queue_poll_first(&cola);
        printf("%s\n",x);
    }

    queue_clean(&cola);
}