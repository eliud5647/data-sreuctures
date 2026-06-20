#include<stdio.h>
#include<stdlib.h>

typedef struct listf
{
    int data;
    struct listf *next;

}listf;

void clear(listf *list){
    listf *temp=list;

    while(list!=NULL){
        temp=list->next;
        free(list);
        list=temp;
    }
}

void add_e(listf **head,int n){
    if(*head==NULL)
    {
        listf *temp=malloc(sizeof(listf));
        temp->data=n;
        temp->next=NULL;
        *head=temp;
        return;
    }else if((*head)->next==NULL){
        listf *temp=malloc(sizeof(listf));
        temp->data=n;
        temp->next=NULL;
        (*head)->next=temp;
        return;
    }else{
        add_e(&((*head)->next),n);
    }
    return;
}

void print_e(listf *head){
    if(head==NULL)
    {
        perror("lista vacia");
    }else if(head->next!=NULL){
        print_e(head->next);
    }
    printf("%d\n",head->data);
    free(head);
    return;
}


int main(){
    listf *head=NULL;
    int nums[]={10,9,8,7,6,5,4,3,2,1,0};
    int i=0;

    while(i<11){
        add_e(&head,nums[i]);
        i++;
    }
    print_e(head);
    clear(head);

}