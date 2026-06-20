#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define msize 3


void mmul(int **A,int **B,int **C);
void llenarM(int **A,int **B);
void writedoc(int **C);



int main(){
    int **A=malloc(msize * sizeof(int *));
    int **B=malloc(msize * sizeof(int *));
    int **C=malloc(msize * sizeof(int *));
    llenarM(A,B);
    mmul(A,B,C);
    writedoc(C);
    free(A);
    free(B);
    free(C);
    return 0;
}

void llenarM(int **A,int **B){
    int i,j;
    FILE *fp;
    fp=fopen("entrada.bin","rb");
    if (!fp)
    {
        perror("archivo no encontrado");
    }
    
    for(i=0;i<msize;i++){
        A[i]=malloc(msize*sizeof(int));
        for (j=0;j<msize;j++){
            fread(&A[i][j],sizeof(int),1,fp);
            
        }
    }
    for(i=0;i<msize;i++){
        B[i]=malloc(msize*sizeof(int));
        for (j=0;j<msize;j++){
            fread(&B[i][j],sizeof(int),1,fp);
            
        }
    }
    fclose(fp);

}



void mmul(int **A,int **B,int **C){
    int i,j,k,temp;

    for(i=0;i<msize;i++)
    {   C[i]=malloc(msize*sizeof(int()));
        for(j=0;j<msize;j++)  
        {   temp=0;
            for(k=0;k<msize;k++)
            {   temp=temp+A[i][k]*B[k][j];

            }
            C[i][j]=temp;
        }
    }
    
}


void writedoc(int **C){
    int i,j;
    FILE *fp=fopen("salida.bin","wb");
    for(i=0;i<msize;i++){
        for(j=0;j<msize;j++){
            fwrite(&C[i][j],sizeof(int),1,fp);
            
        }
    }
    fclose(fp);
    
}   