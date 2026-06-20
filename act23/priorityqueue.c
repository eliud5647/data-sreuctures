#include "priorityqueue.h"
int heap_offer(heap_t *heap,type_t *e)
{
    int i = heap->size;
    int p;
    type_t *tmp;

    if(heap->blocks_assigned==0)
    {
        heap->blocks_assigned=1;
        heap->arr = malloc(BLOCKSIZE * sizeof(type_t*));
    }

    if(heap->size / BLOCKSIZE >= heap->blocks_assigned)
    {
        heap->blocks_assigned++;
        // printf("\t\t\tIncrementando, tamaño = %d, bloques asignados = %d\n",heap->size + 1,heap->blocks_assigned);

        heap->arr = realloc(heap->arr, heap->blocks_assigned * BLOCKSIZE * sizeof(type_t*));

        if(heap->arr == NULL)
            return -1;
    }

    heap->arr[i]=e;

    while(i!=0)
    {
        p = parent(i);
        // Checar si el elemento tiene mayor prioridad que el padre
        if(heap->compare_func(heap->arr[i], heap->arr[p])==-1)
        {
            // Intercambiamos
            tmp = heap->arr[i];
            heap->arr[i] = heap->arr[p];
            heap->arr[p] = tmp;
        }

        i = p;
    }

    heap->size++;

    return 0;       // Todo ok
}

type_t *heap_poll(heap_t *heap)
{
    int last = heap->size - 1;
    type_t *ret_value = heap->arr[0];   // Siempre retiramos el elemento que está hasta arriba en el heap
    type_t *tmp;
    int pos,hijom;

    if(heap->size == 0)
        return NULL;

    heap->arr[0] = heap->arr[last]; // Poner el elemento del final hasta arriba

    pos = 0;

    /*
    El último elemento que movimos al prinicipio, ahora hay que reacomodarlo, siempre
    vamos a ir checando los hijos si tienen mayor prioridad.
    */
    // Checar si tiene hijo izquierdo, si no tiene hijos ya terminó
    while(left(pos) < heap->size)
    {
        hijom = left(pos);  // El número de hijo que tiene menor valor

        // Checar si tiene hijo derecho y ver si el hijo derecho es menor al izquierdo
        if(right(pos) < heap->size && (heap->compare_func(heap->arr[right(pos)] , heap->arr[left(pos)])==-1))
            hijom = right(pos);

        if(heap->compare_func(heap->arr[hijom] , heap->arr[pos])==-1)
        {
            tmp = heap->arr[hijom];
            heap->arr[hijom] = heap->arr[pos];
            heap->arr[pos] = tmp;
        }
        pos = hijom;
    }

    heap->size--;
    if(heap->size / BLOCKSIZE < heap->blocks_assigned - 1)
    {
        heap->blocks_assigned--;    // Un bloque menos
        // printf("\t\t\tReduciendo, tamaño = %d, bloques asignados = %d\n",heap->size+1,heap->blocks_assigned);

        heap->arr = realloc(heap->arr,heap->blocks_assigned * BLOCKSIZE * sizeof(type_t*));
        if(heap->arr==NULL)
            return NULL;
    }
    if(heap->size == 0)
    {
        heap->blocks_assigned = 0;
        free(heap->arr);
        // printf("\t\t\tMontículo vacío, se liberó la memoria\n");
    }

    return ret_value;
}

bool heap_empty(heap_t *heap)
{
    return heap->size==0;
}

int heap_init(heap_t *heap)
{
    // Asignar un bloque de memoria al arreglo
    heap->arr = malloc(sizeof(type_t*)*BLOCKSIZE);
    comparator_t strcomp= compare_string;
    printfunc_t prtn = string_print;
    if(heap->arr==NULL)
        return -1;

    heap->size = 0;
    heap->blocks_assigned = 1;
    heap->compare_func=strcomp;
    heap->print_func=prtn;
    // printf("\t\t\tInicializando, tamaño = %d, bloques asignados = %d\n",heap->size,heap->blocks_assigned);
    return 0;
}

int heap_size(heap_t *heap)
{
    return heap->size;
}

int compare_string(type_t *a,type_t *b)
{
    if(strcmp(string_value(a),string_value(b))<0)
    {
        return -1;
    }else{
        return  1;
    }
}

void string_print(type_t *a)
{
    printf("%s\n",string_value(a));
}