#include <stdio.h>
#include <stdlib.h>


int main()
{
    FILE *fp_in = fopen("salida.bin","rb");
    int n, contador=0;
    // int leidos;


    if(fp_in==NULL)
    {
        perror("Error al abrir archivo\n");
        exit(1);
    }



    while(fread(&n,sizeof(int),1,fp_in)>0){
        printf("%d\t",n);
        contador++;

        if(contador % 3 ==0){
            printf("\n");
        }
    }


    fclose(fp_in);
}
