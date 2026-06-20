#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "datatypes.h"
#include<string.h>

#ifndef _PRIORITY_QUEUE_H
    
    
    typedef struct {
        type_t **arr;
        int size;
        int blocks_assigned;
        comparator_t compare_func;
        printfunc_t print_func;
    } heap_t;

    #define SIZE 100
    #define BLOCKSIZE 8
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

#endif