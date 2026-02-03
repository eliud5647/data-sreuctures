#include<stdio.h>
#include<string.h>


void switcharray(char arr[][10],int N, char **a){
    char *temp=(char *)arr;
    for(int i=0;i<N;i++){
        *a=temp;
        a++;
        temp+=10;
    }


}

void printnames(char **n, int size){
    int i;
    for(i=0; i<size; i++){
        
        printf("%s\n", *(n+i));
    }
}


int main(){
    char arr[][10]={"Uno","Dos","Tres","Cuatro","Cinco","Seis","Siete","Ocho","Nueve","Diez","Once","Doce"};
    char *a[12];
    switcharray(arr,12,a);
    printnames(a,12);
    

}