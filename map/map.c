#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <ctype.h>


#define M 20
#define STRLEN 40
#define LINELEN 2*STRLEN


// Cada nodo de las listas del mapa contiene llave y valor
typedef struct node_t {
    char key[STRLEN];
    char value[STRLEN];
    struct node_t *next;
} node_t;


// Definimos la lista
typedef struct {
    node_t *first;
    node_t *last;
    int size;
} linkedlist_t;


// Definimos el TDA map
typedef struct {
    linkedlist_t arr[M];    // Arreglo de M listas
    int size;
} map_t;


void map_init(map_t *m);    
void map_print(map_t *m);
void map_put(map_t *m,char *key,char *value);
char *map_get(map_t *m,char *key);


uint64_t hash(char *s);


int main()
{
    map_t m;
    FILE *fp = fopen("entrada.txt","r");
    char linea[LINELEN];
    char *key;
    char *value;
    char serch[LINELEN];
    char *val;
    int i;


    if(fp==NULL)
    {
        perror("Error en la apertura del archivo\n");
        exit(1);
    }


    map_init(&m);   // Inicializar el mapa


    while(fgets(linea,LINELEN,fp)!=NULL)    // Leer línea por línea del archivo 
    {
        // De cada línea separamos la parte que corresponde a key y value
        key = strtok(linea,":");
        value = strtok(NULL,"\n");
        // printf("Hash code: %lu, entrada en la tabla: %d, Key: %s\n",hash(key),(int)(hash(key) % M), key);
    
        // Agregar el par key,value al mapa
        map_put(&m,key,value);
    }
    fclose(fp);




    map_print(&m);

    while(1){
        printf("Llave:");
        scanf("%s",serch);
        if(strcmp("fin",serch)==0){
            break;
        }else{
            val=map_get(&m,serch);
            if(val==NULL){
                printf("no existeb la llave\n");
            }else{
                printf("Valor:%s\n",val);
            }
            
        }
        


    }
}


uint64_t hash(char *s)
{
    uint64_t x = 0;


    while(*s)
    {
        x = x << 2;
        x = x | tolower(*s) & 0x3;
        s++;
    }


    return x;
}


/* Inicializar el mapa, para esto es necesario inicializar cada una de las listas
   Las listas inicialmente están vacías 
*/
void map_init(map_t *m)
{
    int i;


    for(i=0;i<M;i++)
    {
        m->arr[i].first = NULL;
        m->arr[i].last = NULL;
        m->arr[i].size = 0;
    }
    m->size = 0;
}


void map_print(map_t *m)
{
    int i;
    node_t *ptr;


    // Por cada una de las listas que tiene el mapa
    for(i=0;i<M;i++)
    {
        ptr = m->arr[i].first;


        printf("%d:",i);
        while(ptr!=NULL)    // Recorrer todos los nodos de la lista
        {
            printf("\t<\"key\":\"%s\",\"value\":\"%s\">\n",ptr->key,ptr->value);
            ptr = ptr->next;
        }
        printf("\n");
    }
}


void map_put(map_t *m,char *key,char *value)
{


    int list_idx = (int)(hash(key) % M);    // Determina en qué lista debe ir el par key,value
    linkedlist_t *l = &m->arr[list_idx];    // l apunta a la lista que le toca al par key,value
    node_t *temp=l->first;

    while(temp!=NULL){
        if(strcmp(key,temp->key)==0){
            strcpy(temp->value,value);
            return;
        }
        temp=temp->next;
    }
    /*
    Debe verificar si la llave ya existe en el mapa
    Si ya existe, solo debe reemplazar el valor (value) en el nodo y no agregar uno nuevo
    Si no existe, entonces debe crear el nodo y agregar a la lista correspondiente
    */


    // Crear nodo y poner los valores en el nodo
    node_t *new = malloc(sizeof(node_t));
    strcpy(new->key,key);
    strcpy(new->value,value);
    new->next = NULL;


    // Agregar el nodo a la lista
    if(l->first == NULL)
        l->first = new;
    else
        l->last->next = new;


    l->last = new;
}


char *map_get(map_t *m,char *key)
{   
    int list_idx = (int)(hash(key) % M);    // Determina en qué lista debe ir el par key,value
    linkedlist_t *l = &m->arr[list_idx];    // l apunta a la lista que le toca al par key,value
    node_t *temp=l->first;

    while(temp!=NULL){
        if(strcmp(temp->key,key)==0){
            return temp->value;
        }
        temp=temp->next;
    }
    return NULL;
}
