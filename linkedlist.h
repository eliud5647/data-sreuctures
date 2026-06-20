#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_

typedef struct LINKEDLIST_NODE {
   int num;
   struct LINKEDLIST_NODE *next;
} LINKEDLIST_NODE;

typedef struct {
    struct LINKEDLIST_NODE *first;
    struct LINKEDLIST_NODE *last;
} LINKEDLIST;

#define LINKEDLISTINIT {NULL,NULL}
void linkedlist_init(LINKEDLIST *list);
void linkedlist_add(LINKEDLIST *list,int num);
int linkedlist_found(LINKEDLIST list,int num);

void linkedlist_display(LINKEDLIST list);
void linkedlist_clean(LINKEDLIST *list);

#endif /* LINKEDLIST_H_ */