#include <stdio.h>
#include <stdlib.h>

#define R 3
#define C 3

int max(int mat[R][C], int row, int col){
    int i,j,max;

    int *ptr=(int *)mat;
    for (i = 0; i < row; i++)
    {
        for (j = 0; j < col; j++)
        {
            if ((*(*(mat+i)+j)) > max){
                max = (*(*(mat+i)+j));
            }
        }
    }
    return max;
}

int main(){
    
int mat[R][C] = { { 1, 2, 3}, { -1, -2, 0 }, {2, 4, -3 }};
int m = max(mat,R,C); // max = 4

printf("%d\n",m);
}