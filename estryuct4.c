#include <stdio.h>
void swap(int *a, int *b){
    int temp=*a;
    *a=*b;
    *b=temp;

}
int main()
{
    int a=35,b=40;
    swap(&a,&b);
    printf("a=%d,b=%d\n",a,b); // debe mostrar "a=40, b=35"
}


