#include"priorityqueue.h"


#define left(n) (2*n+1)
#define right(n) (2*n+2)
#define parent(n) ((n-1)/2)

int heap_init(heap_t *heap);
int heap_offer(heap_t *heap,type_t *e);
bool heap_empty(heap_t *heap);
type_t *heap_poll(heap_t *heap);
int heap_size(heap_t *heap);
int compare_string(type_t *a,type_t *b);
void string_print(type_t *a);

int main()
{
    FILE *fp = fopen("nombres.txt","r");
    char nom[100];
    char *nom2;
    heap_t h;
    int i;
    
    

    if(heap_init(&h)==-1) // Inicializamos el heap
    {
        perror("Error en la inicialización del heap");
        exit(1);
    }

    if(fp==NULL)
    {
        perror("Error en la apertura del archivo");
        exit(1);
    }

    while(fscanf(fp,"%s",nom)!=-1)
    {
        heap_offer(&h,string_new(nom));
    }
        fclose(fp);

    printf("Nombres cargados, tamaño del heap = %d\n",heap_size(&h));
    /*
    for(i=0;i<10;i++)
        printf("%d\t",h.arr[i]);
    */

    while(!heap_empty(&h))
    {
        nom2 = string_value(heap_poll(&h));
        printf("%s\n",nom2);
        free(nom2);
    }

}

