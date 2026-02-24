#include<stdio.h>
#include<string.h>

void printchar(void *p, char *cad){
    char *temp=p;
    int i; 
        for(i=0;i<11;i++){
            printf(cad,*temp);
            temp++;
            printf("\n");
        }
        
        printf("\n");
    
    

}
int main(){
    char arr[]={'A','B',100,20,0x4E,50,60,'M','D',0x25,040};
    printchar(arr,"%c"); // Mostrará en consola el caracter 'A'
    printchar(arr,"%d"); // Mostrará en consola el valor 65


}