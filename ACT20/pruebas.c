#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include<time.h>


typedef struct tree_node_t {
    int n;
    struct tree_node_t *left;
    struct tree_node_t *right;
} tree_node_t;




tree_node_t *tree_add(tree_node_t *root,int n)
{
    if(root==NULL)
    {
        root = malloc(sizeof(tree_node_t));
        root->n = n;
        root->left = NULL;
        root->right = NULL;
    }
    else if(n < root->n)
        root->left = tree_add(root->left,n);
    else if(n > root->n)
        root->right = tree_add(root->right,n);


    return root;
}


void tree_inorder(tree_node_t *root)
{
    if(root->left != NULL)
        tree_inorder(root->left);


    printf("%d\n",root->n);


    if(root->right != NULL)
        tree_inorder(root->right);
}


bool tree_search(tree_node_t *root,int n)
{


    if(root == NULL)
        return false;


    else if(n == root->n)
        return true;


    else if(n < root->n)
        return tree_search(root->left,n);


    else if(n > root->n)
        return tree_search(root->right,n);
}


tree_node_t *tree_destroy(tree_node_t *root)
{
    if(root->left!=NULL)
        root->left = tree_destroy(root->left);


    if(root->right!=NULL)
        root->right = tree_destroy(root->right);


    // printf("Eliminando elemento %d del árbol\n",root->n);
    free(root);
    return NULL;
}


int main()
{
    srand(time(NULL));
    int n[20],i,j;
    for(i=0;i<20;i++){

        n[i]=(rand()%101)+1;
    }
    tree_node_t *root = NULL;
     for(i=0;i<20;i++){
        root=tree_add(root,n[i]);
    }
    tree_inorder(root);
    
    for(i=0;i<3;i++){
        printf("que numero deceas buscar...\n");
        scanf("%d",&j);
        if(tree_search(root,j)){
            printf("si esta el numero %d",j);
        }else{
            printf("no esta el numero %d",j);
        }
        
    }
    tree_destroy(root);
}
