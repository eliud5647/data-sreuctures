#include "queue.h"


int queue_offer_last(queue_t *qp,type_t *data)
{
    queue_node_t *new = malloc(sizeof(queue_node_t)); // Crear un nuevo nodo 

    if(new==NULL)       // Si no se asigna memoria dinámica para el nuevo nodo, retornar error
        return -1;

    new->data = data;   // Poner en el nuevo nodo el dato a almacenar
    new->next = NULL;
    new->prev = qp->last;   // El nuevo nodo será el nuevo último
    if(qp->last)
        qp->last->next=new;
    
    if(qp->first==NULL)         // Si la cola está vacía, el nodo new, será el primero.
        qp->first = new;
    qp->last = new;
    qp->size++;                 // Incrementamos el tamaño de la cola

    return 0;
}

int queue_offer_first(queue_t *qp,type_t *data)
{
    queue_node_t *new = malloc(sizeof(queue_node_t)); // Crear un nuevo nodo 

    if(new==NULL)       // Si no se asigna memoria dinámica para el nuevo nodo, retornar error
        return -1;

    new->data = data;   // Poner en el nuevo nodo el dato a almacenar
    new->next = qp->first;
    new->prev = NULL;   // El nuevo nodo será el nuevo último
    if((qp->first))
        qp->first->prev=new;
    if((qp->last))
        NULL;
    else
    {   qp->last=new;
    }
    qp->first=new;
    qp->size++;                 // Incrementamos el tamaño de la cola

    return 0;
}

type_t *queue_poll_first(queue_t *qp)
{
    type_t *retvalue;
    queue_node_t *to_remove = qp->first;
    if(to_remove==NULL)
        return NULL;          // Error si el stack está vacío

    retvalue = to_remove->data;
    qp->first = to_remove->next;
    qp->first->prev=NULL;
    qp->size--;
    free(to_remove);
    return(retvalue);
}

type_t *queue_poll_last(queue_t *qp)
{
    type_t *retvalue;
    queue_node_t *to_remove = qp->last;
    if(to_remove==NULL)
        return NULL;          // Error si el stack está vacío

    retvalue = to_remove->data;
    qp->last = to_remove->prev;
    qp->last->next=NULL;
    qp->size--;
    free(to_remove);
    return(retvalue);
}

bool queue_empty(queue_t *qp)
{
    return qp->first==NULL;
}

void queue_clean(queue_t *qp)
{
    while(!queue_empty(qp))
        queue_poll_first(qp);
}
