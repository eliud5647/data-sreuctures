#include<stdio.h>
#include<time.h>
#include <stdlib.h>
 
typedef struct casilla
{  
    char row;
    char column;
    char edge;
    char ocuppied;
    char caracter;
}casilla;
 
typedef struct fichas
{
    casilla *ficha;
    char check;
}fichas;
 
typedef fichas jugador[12];
 
 
int random_number(int n){
    return rand() % n;
}
 

void imprimir_tablero(casilla *tablero){ 
    int i,j,b=1;
    for(i=0;i<8;i++)
    {
        printf("|");
        for(j=0;j<4;j++)
        {
            if(b){
                
                printf("%c|%c|",219,(tablero+j+4*i)->caracter);
            }else if(!b){
                
                printf("%c|%c|",(tablero+j+4*i)->caracter,219);
            }
        }
        printf("\n");
      
        b=b*(-1)+1;
    }
}
void iniciar_juego(void *tablero,void *X, void *O){
    int i,j,b=1;
    casilla *temp=tablero,*temp2=tablero;
    fichas *tempX=X,*tempO=O;
    for(i=0;i<3;i++)
    {  
        for(j=0;j<4;j++)
        {
            temp->caracter='X';
            temp->row=i;
            if (b)
            {
                temp->column=j*2+1;
               
            }else{
                temp->column=j*2;
               
            }
           
            temp->ocuppied=1;
            temp->edge=0;
            tempX->ficha=temp;
            tempX++;
            temp++;
               
        }
        b=b*-1+1;
    }
     for(i=3;i<5;i++)
    {  
        for(j=0;j<4;j++)
        {
            temp->caracter=32;
            temp->row=i;
            if (b)
            {
                temp->column=j*2+1;
               
            }else{
                temp->column=j*2;
               
            }
            temp->ocuppied=0;
            temp->edge=0;
            temp++;
           
        }
        b=b*-1+1;
    }
    for(i=5;i<8;i++)
    {  
        for(j=0;j<4;j++)
        {
            temp->caracter='O';
            temp->row=i;
            if (b)
            {
                temp->column=j*2+1;
               
            }else{
                temp->column=j*2;
               
            }
            temp->ocuppied=1;
            temp->edge=0;
            tempO->ficha=temp;
            tempO++;
            temp++;
           
        }
        b=b*-1+1;
    }
 
    for(i=0;i<4;i++){
        (temp2+(3+i*8))->edge=1;
        (temp2+(4+i*8))->edge=1;
    }
}
void movimiento(fichas *viejo, casilla *nuevo){
    printf("\nSelecciona ficha %d,%d\n",viejo->ficha->row,viejo->ficha->column);
    printf("Movimiento realizado a %d,%d\n",nuevo->row,nuevo->column);
    nuevo->caracter=viejo->ficha->caracter;
    nuevo->ocuppied=1;
    viejo->ficha->ocuppied=0;
    viejo->ficha->caracter=32;
    viejo->ficha=nuevo;
   
 
 
 
}
void turno(void *J){
    fichas *temp=J,*current;
    int n1,n2,n3,n4,i,checks=0;
    for(n1=0;n1<12;n1++){
        (temp+n1)->check=0;
    }
   
    do{
        printf(".");
        n1=random_number(12);
        current=temp+n1;
        if(!(current->check))
        {
            if ((current->ficha->row<7 && current->ficha->caracter=='X')||(current->ficha->row>0 && current->ficha->caracter=='O')){
               
                switch (current->ficha->caracter)
                {
                    case 'O':
                        n3=-1;
                        if(current->ficha->row%2){
                            n4=0;
                        }else{
                            n4=1;
                        }
                    break;
                    case 'X':
                        n3=1;
                        if(current->ficha->row%2){
                            n4=1;
                        }else{
                            n4=0;
                        }
                    break;
                   
                    default:
                        break;
                }
 
                if (!(current->ficha->edge))
                {  
                   
                    n2=random_number(2);
                    switch (n2)
                    {
                        case 0:
                            if(!((current->ficha+n3*(4-n4))->ocuppied))
                            {
                               
                                movimiento(current,(current->ficha+n3*(4-n4)));
                                return;
                               
                            }else if (!((current->ficha+n3*(5-n4))->ocuppied))
                            {
                               
                                movimiento(current,(current->ficha+n3*(5-n4)));
                                return;
                               
                            }else{
                                current->check=1;
                            }
                           
                            break;
                        case 1:
                            if (!((current->ficha+n3*(5-n4))->ocuppied))
                            {
                               
                                movimiento(current,(current->ficha+n3*(5-n4)));
                                return;
                               
                            }else if(!((current->ficha+n3*(4-n4))->ocuppied))
                            {
                               
                                movimiento(current,(current->ficha+n3*(4-n4)));
                                return;
                               
                            }else{
                                current->check=1;
                            }
                            break;
                       
                        default:
                            printf("error");
                            break;
                    }
                }else{
                    if(!((current->ficha+(4*n3))->ocuppied))
                        {
                            printf("ESQUINA");
                            movimiento(current,(current->ficha+(4*n3)));
                            return;
                               
                        }else{
                            current->check=1;
                        }
 
 
                }
                current->check=1;
            }
        }
        checks=0;
        for(i=0;i<12;i++){
            checks=checks+(temp+i)->check;
        }
 
    }while (checks<12);
 
    printf("\nsin movimientos, se pasa turno\n");
   
   
     
}
 
int main(){
    casilla tablero[32];
    jugador X;
    jugador O;
    int i;

    srand((unsigned)time(NULL));
    iniciar_juego(tablero,X,O);
    printf("Tablero inicial:\n");
    imprimir_tablero(tablero);
   
   
    for(i=1;i<11;i++){
        printf("Presiona una tecla para jugada de X...\n\n");
        getchar();
        printf("Turno %d:\n",i);
        turno(X);
        imprimir_tablero(tablero);
        printf("Presiona una tecla para jugada de O...\n\n");
        getchar();
        turno(O);
        imprimir_tablero(tablero);
    }
   
   return 0;
}