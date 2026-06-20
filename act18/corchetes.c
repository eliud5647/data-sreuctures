#include<stdio.h>
#include<stdlib.h>

typedef struct pila_node
{
    char data;
    struct pila_node *prev;
}pila_node;

typedef struct pila_t
{
    pila_node *top;
    int pilla_size;
}pila_t;

void pila_pop(pila_t *pila);
void pila_push(pila_t *pila,char c);


void val(char *c,pila_t *pila){
    char *temp=c;
    while(*temp!='\0'){
        if(*temp=='\n'){
            temp++;
            continue;
        }
        if(*temp=='{' || *temp=='[' || *temp=='('){
            pila_push(pila,*temp);
        }else if(*temp=='}'  &&  pila->top->data=='{'){
            pila_pop(pila);
        }else if(*temp==']'  &&  pila->top->data=='['){
            pila_pop(pila);
        }else if(*temp==')'  &&  pila->top->data=='('){
            pila_pop(pila);
        }else{
            printf("Invalido\n");
            return;
        }
        temp++;
        
    }

    if(pila->pilla_size==0){
        printf("Valido\n");
        return;
    }else{
        printf("Invalido\n");
        return;
    }
}


int main(){

FILE *fp=fopen("fuente.txt","r");
char buff[100];
pila_t *pila;
while(fgets(buff,sizeof(buff),fp)){
    pila->top=NULL;
    pila->pilla_size=0;
    printf("%s\n",buff);
    val(buff,pila);
    
}
fclose(fp);

}

void pila_pop(pila_t *pila){
    if(pila->top==NULL){
        perror("lista vacia");
    }else{
        pila_node *temp=pila->top;
        pila->top=pila->top->prev;
        pila->pilla_size--;
        free(temp);
    }
}

void pila_push(pila_t *pila,char c){
    if(pila->top==NULL){
        pila_node *temp=malloc(sizeof(pila_node));
        temp->data=c;
        temp->prev=NULL;
        pila->top=temp;
        pila->pilla_size++;
    }else{
        pila_node *temp=malloc(sizeof(pila_node));
        temp->data=c;
        temp->prev=pila->top;
        pila->top=temp;
        pila->pilla_size++;
    }
}

void pila_clear(pila_t *pila){
    pila_node *temp= pila->top;
    while(pila->top!=NULL){
        temp=pila->top->prev;
        free(pila->top);
        pila->top=temp;
    }

}