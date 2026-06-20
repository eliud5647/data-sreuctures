#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


#define SIZE 100


typedef struct {
    int arr[SIZE];
    int size;
} heap_t;


#define left(n) (2*n+1)
#define right(n) (2*n+2)
#define parent(n) ((n-1)/2)


void heap_offer(heap_t *heap,int elem);
bool heap_empty(heap_t *heap);
int heap_poll(heap_t *heap);


int main()
{
    FILE *fp = fopen("numeros.txt","r");
    int num;
    heap_t h;
    int i;


    h.size = 0;     // Establecer que el tamaño inicial del mónticulo es 0, es decir vacío


    if(fp==NULL)
    {
        perror("Error en la apertura del archivo");
        exit(1);
    }


    while(fscanf(fp,"%d",&num)!=-1)
        heap_offer(&h,num);
    fclose(fp);


    /*
    for(i=0;i<10;i++)
        printf("%d\t",h.arr[i]);
    */


    while(!heap_empty(&h))
    {
        num = heap_poll(&h);
        printf("%d\n",num);
    }


}


void heap_offer(heap_t *heap,int elem)
{
    int i = heap->size;
    int p;
    int tmp;


    heap->arr[i] = elem;


    while(i!=0)
    {
        p = parent(i);
        
        // Checar si el elemento tiene mayor prioridad que el padre
        if(heap->arr[i] < heap->arr[p])
        {
            // Intercambiamos
            tmp = heap->arr[i];
            heap->arr[i] = heap->arr[p];
            heap->arr[p] = tmp;
        }


        i = p;
    }


    heap->size++;
}


int heap_poll(heap_t *heap)
{
    if (heap->size == 0) {
        printf("Error: Montículo vacío\n");
        return -1;
    }
 
    int ret_value = heap->arr[0];      // El mínimo está en la raíz
    int last = heap->size - 1;
    heap->arr[0] = heap->arr[last];    // Movemos el último a la raíz
    heap->size--;                      // Reducimos el tamaño
 
    int pos = 0;
    int tmp;
 
    // Proceso de "Sift Down" (Hundir el elemento)
    while (left(pos) < heap->size)
    {
        int hijom = left(pos); // Empezamos asumiendo que el izquierdo es el menor
 
        // Si existe hijo derecho y es menor que el izquierdo, lo seleccionamos
        if (right(pos) < heap->size && heap->arr[right(pos)] < heap->arr[left(pos)]) {
            hijom = right(pos);
        }
 
        // Si el padre es mayor que el hijo menor, intercambiamos
        if (heap->arr[pos] > heap->arr[hijom]) {
            tmp = heap->arr[pos];
            heap->arr[pos] = heap->arr[hijom];
            heap->arr[hijom] = tmp;
            pos = hijom; // Seguimos bajando
        } 
        else {
            // ¡Propiedad restaurada! El padre ya es menor que sus hijos.
            break; 
        }
    }
 
    return ret_value;
}


bool heap_empty(heap_t *heap)
{
    return heap->size==0;
}

