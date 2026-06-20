#include<stdio.h>
#include<stdlib.h>
#include"datatypes.h"
#include"set.h"

int main(){
    FILE *fp=fopen("nums.txt","r");
    set_t s = SETINITIALIZER;
    char nums[100];
    int num;
    bool res=false;

    while(fgets(nums,sizeof(nums),fp)!=NULL){
        num=atoi(nums);
        printf("%d",num);
        s.tree_root=tree_add(s.tree_root,num,&res);
        if(res){
            s.size++;
            printf("agregado\n");
            res=false;
        }else{
            printf("no agregado\n");
        }
    }
    fclose(fp);
    tree_inorder(s.tree_root);
}