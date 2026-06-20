#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void imprimirres(int **A,int **B, int **C,int msize);
void mmul(int **A,int **B,int **C,int msize);
void imprimirm(int **M,char m,int msize);
void llenarM(int **M,char m,int msize, char *txt);
void writedoc(int **C,int msize);



int main(){
    int msize=3;
    srand((unsigned)time(NULL));
    int **A=malloc(msize * sizeof(int *));
    int **B=malloc(msize * sizeof(int *));
    int **C=malloc(msize * sizeof(int *));
    llenarM(A,'A',msize,"a.txt");
    llenarM(B,'B',msize,"b.txt");
    mmul(A,B,C,msize);
    imprimirres(A,B,C,msize);
    writedoc(C,msize);
    free(A);
    free(B);
    free(C);
    return 0;
}

void llenarM(int **M, char m,int msize,char txt[]){
    int i,j;
    FILE *fp;
    fp=fopen(txt,"r");
    if (!fp)
    {
        perror("archivo no encontrado");
    }
    
    for(i=0;i<msize;i++){
        M[i]=malloc(msize*sizeof(int));
        for (j=0;j<msize;j++){
            fscanf(fp,"%d",&M[i][j]);
            
        }
    }
    fclose(fp);
    imprimirm(M,m,msize);

}

void imprimirm(int **M,char m,int msize){
    
    int i,j;
    printf("%c:\n",m);
    for(i=0;i<msize;i++){
        for (j=0;j<msize;j++){
            
            printf("%4d ",M[i][j]);

        }
        printf("\n\n");
    }
}

void mmul(int **A,int **B,int **C,int msize){
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

void imprimirres(int **A,int **B, int **C,int msize){
    int i,j,k;
    printf("A= %*sB=%*s C=\n",msize*4,"",msize*4,"");
    for(i=0;i<msize;i++){
        for (j=0;j<3;j++){
            
            for(k=0;k<msize;k++)
            {
                switch (j)
                {
                case 0:
                    printf("%4d",A[i][k]);
                    break;
                case 1:
                    printf("%4d",B[i][k]);
                    break;
                case 2:
                    printf("%4d",C[i][k]);
                    break;
                
                default:
                    break;
                }
                
            }
            if(i==msize/2 && j==1){
                  printf(" = ");
            }else if(i==msize/2 && j==0)
            {printf("  *");
            }else{printf("   ");}

           
            

        }
        printf("\n\n");
    }
    
}

void writedoc(int **C,int msize){
    int i,j;
    FILE *fp=fopen("c.txt","w");
    for(i=0;i<msize;i++){
        for(j=0;j<msize;j++){
            fprintf(fp,"%d ",C[i][j]);
        }
        fprintf(fp,"\n");
    }
    fclose(fp);
    
}