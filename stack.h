
#ifndef _STACK_H
    #define STACK_H

typedef struct {
    int num;
    stack_node * next;
}stack_node;

typedef struct 
{
    stack_node top;
    int numE;
}stack_p;

#endif