#include<stdio.h>
#include<math.h>

typedef double (*Function2D)(int x);

int islinear(Function2D a){
    double res=a(20000)/a(10000);
    if (res>=1.99 && res<=2.01){
        return 1;

    }
    return 0;
    
}
int isquadratic(Function2D a){
    double res=a(20000)/a(10000);
    if (res>=3.98 && res<=4.02){
        return 1;

    }
    return 0;
    
}

double f1(int x){
    return 4*x-2;

}
double f2(int x){
    return 3*pow(x,2)-2*x+4;

}
double f3(int x){
    return 6*sqrt(x)+2;

}



int main(){
    Function2D arr[] = {f1,f2,f3,NULL};
    for(int i=0;i<3;i++){
        if (islinear(arr[i])==1){
            printf("Es lineal.");
        }else{
            printf("No es lineal.");
        }
        if (isquadratic(arr[i])==1){
            printf("Es  cuadratica.");
        }else{
            printf("No es cuadratica.");
        }
        printf("\n");
    }

}