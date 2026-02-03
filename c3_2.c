#include<stdio.h>
#include<string.h>



void sortnames(char **n, int STRLEN){
    char *  tmp;
    char **first=n,**second;

    int i,j;

    for(i=0; i<STRLEN-1; i++){ 
        second=first;
        for(j=0; j<STRLEN-i-1; j++){
            second++;
            
            if(strcmp(*first, *second)>0){ //si el elemento que está en j es mayor que el siguiente
            //n+j*STRLEN apunta al inicio de la cadena j y n+(j+1)*STRLEN apunta al siguiente elemento
                
                tmp=*first;
                *first=*second;
                *second=tmp;
            
               
            }
        }
        first++;   
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
    char *nombres[]={"Juan","Jose","Gaby","Maria","Karla","Luis","Antonio","Cecilia","Roberto","Francisco"};
   
    sortnames(nombres,10);

    // Mostrar en pantalla la lista de nombres ordenada
     printnames(nombres,10);
}