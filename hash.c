#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>


#define M 20
#define STRLEN 40


typedef struct node_t {
    char key[STRLEN];
    struct node_t *next;
} node_t;


typedef struct {
    node_t *first;
    node_t *last;
    int size;
} linkedlist_t;


linkedlist_t arr[M];
void initarr(linkedlist_t *a,int m);
void linkedlist_add(linkedlist_t *l,char key[STRLEN]);
void linkedlist_print(linkedlist_t *l);
node_t *hash_search(linkedlist_t *a, char key[STRLEN]);


uint64_t hash(char *s);


int main()
{
    FILE *fp = fopen("entrada.txt","r");
    char entrada[STRLEN];
    char serch[STRLEN];
    int i;
    node_t *temp;


    if(fp==NULL)
    {
        perror("Error en la apertura del archivo\n");
        exit(1);
    }


    initarr(arr,M);


    while(fscanf(fp,"%s",entrada)!=-1)
    {
        printf("Hash code: %lu, entrada en la tabla: %d, Key: %s\n",hash(entrada),(int)(hash(entrada) % M), entrada);
        linkedlist_add(&arr[(int)(hash(entrada) % M)],entrada);
    }
    fclose(fp);


    for(i=0;i<M;i++)
    {
        printf("%d :",i);
        linkedlist_print(&arr[i]);

    }

    for (int i=0;i<3;i++){
        printf("\nIngresa el correo a buscar: ");
        scanf("%s",serch);
        temp=hash_search(arr,serch);
        if(temp==NULL)
        printf("El correo: %s no esta en la tabla\n",serch);
        
        else
        printf("El correo:  %s si esta en la tabla\n",serch);

    }
    
}


uint64_t hash(char *s)
{
    uint64_t x = 0;


    while(*s)
    {
        x = x << 2;
        x = x | *s & 0x3;
        s++;
    }


    return x;
}


void initarr(linkedlist_t *a,int m)
{
    int i;


    for(i=0;i<m;i++)
    {
        a->first = NULL;
        a->last = NULL;
        a->size = 0;
    }
}


void linkedlist_add(linkedlist_t *l,char key[STRLEN])
{
    node_t *new = malloc(sizeof(node_t));


    strcpy(new->key,key);
    new->next = NULL;


    if(l->first == NULL)
        l->first = new;
    else
        l->last->next = new;


    l->last = new;
}


void linkedlist_print(linkedlist_t *l)
{
    node_t *ptr = l->first;


    while(ptr!=NULL)
    {
        printf("%s,",ptr->key);
        ptr = ptr->next;
    }
    printf("\b \n");
}

node_t *hash_search(linkedlist_t *a, char key[STRLEN])
{
    int index = hash(key) % M;

    node_t *ptr = a[index].first;

    while(ptr != NULL)
    {
        if(strcmp(ptr->key,key) == 0)
            return ptr;   

        ptr = ptr->next;
    }

    return NULL;   
}