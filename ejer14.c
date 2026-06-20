#include <stdio.h>
#include <stdlib.h>
#include <math.h>


typedef struct node_t {
    int n;
    struct node_t *next;
} node_t;

typedef struct {
    node_t *first;
    node_t *last;
} linkedlist_t;

int val(linkedlist_t *list,int i,int lim);
int list_insert(linkedlist_t *listp, int n);
void list_display(linkedlist_t list);
void list_destroy(linkedlist_t *listp);

int main()
{
	int i,lim;
    linkedlist_t list = {NULL,NULL};
    for(i=2;i<1000;i++)
    {
		// Buscar si i es divisible entre algun numero que ya esta en la lista
		// Si no es divisible, hay que insertarloo
		lim=sqrt(i);
        if(val(&list,i,lim)){
            if(list_insert(&list,i)==-1)
            {
                perror("Error al asignar memoria\n");
                exit(1);
            }
        }
        
    }
    list_display(list);
    list_destroy(&list);    // Libera los nodos de la lista

}


int list_insert(linkedlist_t *listp, int n)
{
    node_t *new = malloc(sizeof(node_t));   // Crear el nuevo nodo
    if(new==NULL)       // Checar que no haya error al crear el nuevo nodo
        return -1;
    new->n=n;    // Poner los valores en el nuevo nodo
    new->next = NULL;           
    if(listp->first==NULL)
        listp->first = new;
    else
        listp->last->next = new;
    listp->last = new;
    return 0;
}


void list_display(linkedlist_t list)
{
    node_t *ptr = list.first;
    while(ptr)
    {
        printf("%d\n",ptr->n);
        ptr = ptr->next;
    }
}


void list_destroy(linkedlist_t *listp)
{
    node_t *ptr = listp->first;
    node_t *before = listp->first;
    while(ptr!=NULL)
    {
        ptr = ptr->next;
        free(before);
        before = ptr;
    }
    listp->first = NULL;
    listp->last = NULL;
}

int val(linkedlist_t *list,int i,int lim){
    node_t *temp=list->first;
    while(temp && (temp->n<=lim)){
        if((i%temp->n==0)){
            return 0;
        }
        temp=temp->next;
    }
    return 1;
}