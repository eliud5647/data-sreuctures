
#ifndef _QUEUE_H_
    #define _QUEUE_H_

    #include <stdbool.h>
    #include <stdlib.h>
    #include "datatypes.h"
    
    typedef struct queue_node_t {
        type_t *data;
        struct queue_node_t *next;
        struct queue_node_t *prev;
    }  queue_node_t;

    typedef struct {
        queue_node_t *first;
        queue_node_t *last;
        int size;
    } queue_t;

    #define QUEUEINITIALIZER {NULL,NULL,0}

    int queue_offer_first(queue_t *qp,type_t *data);
    int queue_offer_last(queue_t *qp,type_t *data);
    type_t *queue_poll_first(queue_t *qp);
    type_t *queue_poll_last(queue_t *qp);
    bool queue_empty(queue_t *qp); 
    void queue_clean(queue_t *qp);
#endif
