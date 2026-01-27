#include<stdio.h>
int lenght(char *cad){
    int len=0;
    while (*cad)
    {
        len++;
        cad++;
    }
    

    return len;
}
int main()
{
    char cad[] = "Hola mundo";
    printf("La longitud de cad es %d\n",lenght(cad));
}

