#include <stdio.h>
#include <math.h>

struct STRVEC {
    float x,y;
};

void toUnit(struct STRVEC *vector){
    float magnitud= sqrt(vector->x * vector->x + vector->y * vector->y);
    //Para calcular la magnitud de un vector en 2D usamos la fórmula: √(x² + y²)

    if(magnitud !=0){ //Con esto evitamos divisiones entre 0
        vector->x /= magnitud;
        vector->y /= magnitud;
    //Para volverlo unitario, dividimos cada componente entre la magnitud
    }
}
int main()
{
    struct STRVEC v1 = {3.0,4.0};
    toUnit(&v1);
    printf("{\"x\":%5.2f,\"y\":%5.2f}",v1.x,v1.y);
}