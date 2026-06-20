
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
    if(res>400){
        if(res>=400 && res<500){
            *tempchar='C';
            tempchar++;
            *tempchar='D';
            tempchar++;
            res-=400;

        }else if(res>=900 && res<1000){
            *tempchar='C';
            tempchar++;
            *tempchar='M';
            tempchar++;
            res-=900;
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

    if(res>40){
        if(res>=40 && res<50){
            *tempchar='X';
            tempchar++;
            *tempchar='L';
            tempchar++;
            res-=40;

        }else if(res>=90 && res<100){
            *tempchar='X';
            tempchar++;
            *tempchar='L';
            tempchar++;
            res-=90;
        }else{
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

    if(res>4){
        if(res==4){
            *tempchar='I';
            tempchar++;
            *tempchar='v';
            tempchar++;
            res-=4;

        }else if(res==9){
            *tempchar='I';
            tempchar++;
            *tempchar='X';
            tempchar++;
            res-=9;
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

tree_node_t *tree_add(tree_node_t *root,int num)
{   
    char roman[100];
    to_roman(roman,num);
    
    bool res = false;
    if(root==NULL)
    {
        root = malloc(sizeof(tree_node_t));
        root->arabico= num;
        root->left = NULL;
        root->right = NULL;
        res = true;
    }
    else if(num-root->arabico< 0) //if(n < root->n)
        root->left = tree_add(root->left,num);
    else if(num-root->arabico< 0) // if(n > root->n)
        root->left = tree_add(root->right,num);

    return root;
}