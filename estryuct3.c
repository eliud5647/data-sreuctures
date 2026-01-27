#include<stdio.h>
void strcopy(char *dst, char *cad1){
    while(*cad1){
        *dst=*cad1;
        *dst++;
        *cad1++;

    }
    *dst='\0';

}
int main()
{

    char cad1[] = "Hola mundo";
    char dst[20];
    strcopy(dst,cad1);
    printf("%s\n",dst); // En pantalla debe mostrarse "Hola mundo"
}
