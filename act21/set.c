
#include"set.h"
#include<string.h>



void to_roman(char *ret,int num){
    
    char *tempchar=ret;
    int tempint,res;

    tempint=num/1000;
    res=num-tempint*1000;
    if(0<tempint && tempint<4){
        for(int i=0;i<tempint;i++){
            *tempchar='M';
            tempchar++;
        }
    }
    if(res>=400){
        if(res>=900 && res<1000){
            *tempchar='C';
            tempchar++;
            *tempchar='M';
            tempchar++;
            res-=900;
        }else if(res>=400 && res<500){
            *tempchar='C';
            tempchar++;
            *tempchar='D';
            tempchar++;
            res-=400;

        }else{
        *tempchar='D';
        tempchar++;
        res-=500;
        }
    }
    tempint=res/100;
    res=res-tempint*100;
    if(0<tempint && tempint<4){
        for(int i=0;i<tempint;i++){
            *tempchar='C';
            tempchar++;
        }
    }

    if(res>=40){
        if(res>=90 && res<100){
            *tempchar='X';
            tempchar++;
            *tempchar='C';
            tempchar++;
            res-=90;
        }else if(res>=40 && res<50){
            *tempchar='X';
            tempchar++;
            *tempchar='L';
            tempchar++;
            res-=40;

        }else {
        *tempchar='L';
        tempchar++;   
        res-=50;
        }
    }

    tempint=res/10;
    res=res-tempint*10;
    if(0<tempint && tempint<4){
        for(int i=0;i<tempint;i++){
            *tempchar='X';
            tempchar++;
        }
    }

    if(res>=4){
        if(res==9){
            *tempchar='I';
            tempchar++;
            *tempchar='X';
            tempchar++;
            res-=9;}
        else if(res==4){
            *tempchar='I';
            tempchar++;
            *tempchar='V';
            tempchar++;
            res-=4;


        }else{
            *tempchar='V';
            tempchar++;
            res-=5;

        }

        
    }

    if(0<res && res<4){
        for(int i=0;i<res;i++){
            *tempchar='I';
            tempchar++;
        }
    }
    *tempchar='\0';

}

tree_node_t *tree_add(tree_node_t *root,int num,bool *res)
{   
    char roman[20];
    to_roman(roman,num);
    
    *res = false;
    if(root==NULL)
    {
        root = malloc(sizeof(tree_node_t));
        root->arabico= num;
        strcpy(root->romano,roman);
        root->left = NULL;
        root->right = NULL;
        *res = true;
        
    }
    else if(num<root->arabico) //if(n < root->n)
        root->left = tree_add(root->left,num,res);
    else if(num>root->arabico) // if(n > root->n)
        root->right = tree_add(root->right,num,res);

    return root;
}



void tree_inorder(tree_node_t *root)
{
    if(root->left != NULL)
        tree_inorder(root->left);
    printf("%s\n",root->romano);
    if(root->right != NULL)
        tree_inorder(root->right);
}


bool tree_search(tree_node_t *root,int num)
{


    if(root == NULL)
        return false;


    else if(num == root->arabico) //if(n == root->n)
        return true;


    else if(root->arabico < num) // if(n < root->n)
        return tree_search(root->left,num);


    else if(root->arabico > num) //if(n > root->n)
        return tree_search(root->right,num);
}
