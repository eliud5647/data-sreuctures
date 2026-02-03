#include<stdio.h>
#include<string.h>



void sortnames(char *n, int STRLEN){
    char tmp[STRLEN];
    int i,j;

    for(i=0; i<STRLEN-1; i++){ 
        for(j=0; j<STRLEN-i-1; j++){
            if(strcmp(n+j*STRLEN, n+(j+1)*STRLEN)>0){ //si el elemento que está en j es mayor que el siguiente
            //n+j*STRLEN apunta al inicio de la cadena j y n+(j+1)*STRLEN apunta al siguiente elemento
                strcpy(tmp, n+j*STRLEN); //guarda el valor de la cadena j en tmp
                strcpy(n+j*STRLEN, n+(j+1)*STRLEN);
                strcpy(n+(j+1)*STRLEN, tmp);
            }
        }
    }

}

void printnames(char *n, int size){
    int i;
    for(i=0; i<size; i++){
        printf("%s\n", n+i*size);
    }
}

int main(){
    char nombres[10][10]={"Juán","José","Gaby","María","Karla","Luis","Antonio","Cecilia","Roberto","Francisco"};
    sortnames((char *)nombres,10);

// Mostrar en pantalla la lista de nombres ordenada
    printnames((char *)nombres,10);
}