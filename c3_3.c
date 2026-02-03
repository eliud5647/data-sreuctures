#include<stdio.h>
#include<string.h>


void switcharray(char *arr,int N, char **a){
    char *temp=(char *)arr;
    for(int i=0;i<N;i++){
        *a=temp;
        a++;
        temp+=10;
    }


}

void printnames(char **n, int size){
    int i;
    char **n2=n;
    for(i=0; i<size; i++){
        
        printf("%s\n", *(n2+i));
    }
}


int main(){
    char arr[][10]={"Uno","Dos","Tres","Cuatro","Cinco","Seis","Siete","Ocho","Nueve","Diez","Once","Doce"};
    char *a[12];
    switcharray((char *)arr,12,a);
    printnames(a,12);
    

}