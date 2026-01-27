#include <stdio.h>
#include <ctype.h>
// Returns string length.
void str_toupper(char *cad){
    while(*cad){
        *cad=toupper(*cad);
        cad++;

    }

}

int main()
{
    char cad[] = "Hola mundo";
    str_toupper(cad);
    printf("%s\n",cad); // En pantalla debe mostrarse "HOLA MUNDO"
}

