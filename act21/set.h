
#ifndef _SET_H_
    #define _SET_H_

    #include <stdio.h>
    #include <stdlib.h>
    #include <stdbool.h>


    #define SETINITIALIZER {NULL,0}

    typedef struct tree_node_t {
        int arabico;
        char romano[20];
        struct tree_node_t *left;
        struct tree_node_t *right;
    } tree_node_t;

    typedef struct {
        tree_node_t *tree_root;
        int size;
    } set_t;

    tree_node_t *tree_add(tree_node_t *root,int num,bool *res);
    void to_roman(char *ret,int num);
    void tree_inorder(tree_node_t *root);
    bool tree_search(tree_node_t *root,int num);
#endif