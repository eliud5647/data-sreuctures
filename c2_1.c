#include <stdio.h>

//funcion cambio
void swap(char *last, char *first){
    char temp=*last;
    *last=*first;
    *first=temp;
}
//funcion reverse
void reverse(char *string1){
    if(!(*string1))return;
    char *first=string1;
    while(*string1){//dirije al ultimo elemento
        string1++;
        
    }
    string1--;
    char *last=string1;
    while(last>first){//cambia mietras el ultimo siga adelante
    
        swap(last,first);
        last--;
        first++;

    }

}

int main()
{
    char string1[] = "Guadalajara";
    reverse(string1);
    printf("%s\n", string1);  // Imprime arajaladauG
}