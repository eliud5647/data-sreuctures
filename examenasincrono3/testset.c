#include <stdio.h>
#include "set.h"

int int_comparator(type_t *d1,type_t *d2);
void int_print(type_t *d);

int main()
{
	set_t *s1 = set_new(int_comparator,int_print);

	FILE *fp = fopen("entrada.txt","r");
	int num;

	while(!feof(fp))
	{
		fscanf(fp,"%d",&num);
		set_add(s1,int32_new(num));
	}
	fclose(fp);

	fp = fopen("borrar.txt","r");

	while(!feof(fp))
	{
		set_print(s1);
		printf("\nTamaño del conjunto %d\n",set_size(s1));
		
		fscanf(fp,"%d",&num);
		printf("Presiona cualquier tecla para borrar el elemento %d\n",num);
		getchar();
		set_remove(s1,&num);
	}
	
}


int int_comparator(type_t *d1,type_t *d2)
{
	int n1 = *((int *) d1);
	int n2 = *((int *) d2);

	/*
	 * Regresa un valor positivo si n1 es mayor que n2
	 * Regresa un valor negativo si n1 es menor que n2
	 * Regresa cero si son iguales
	 */
	return n1 - n2;
}

void int_print(type_t *d)
{
	printf("%d\t",*((int *) d));
}
