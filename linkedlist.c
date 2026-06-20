#include "linkedlist.h"
#include<stdlib.h>

void linkedlist_add(LINKEDLIST *list,int num)
{
    LINKEDLIST_NODE *temp =list->last;
    LINKEDLIST_NODE *nodo= malloc(sizeof(LINKEDLIST_NODE));
    nodo->num=num;
    nodo->next=NULL;
    temp->next=nodo;
    list->last=nodo;
}

void list_display(LINKEDLIST list)
{
    LINKEDLIST_NODE *ptr = list.first;
    while(ptr)
    {
        printf("%d\n",ptr->num);
        ptr = ptr->next;
    }
}

int linkedlist_remove(LINKEDLIST *list, int num){
    
    
}