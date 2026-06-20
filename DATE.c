#include "DATE.h"

DATE *date_create(uint32_t dia, uint32_t mes, uint32_t año)
{   
    DATE *temp=malloc(sizeof(DATE));
    DATE *temp2=malloc(sizeof(DATE));
    temp2->año=1970;
    temp2->mes=1;
    temp2->dia=1;
    temp->año=año;
    if(1<=mes && mes<=12){
        temp->mes=mes;
        
    }else{
        perror("mes invalido");
        return temp2;

    }

    if(mes>=0 && mes<=7)
    {   
        if(mes%2)
        {
            if(1<=dia && dia <=31)
            {   temp->dia=dia;
                
            }else{
                perror("dia invalido");
                return temp2;
            }
        }else if(mes==2)
        {
            if(!(año%4))
            {   if(!(año%100))
                {   if(!(año%400))
                    {
                        if(dia>=1 && dia<=29)
                        {   temp->dia=dia;

                        }else{
                            perror("dia incorrecto");
                            return temp2;
                        }
                    }else{
                        if(dia>=1 && dia<=28)
                        {   temp->dia=dia;

                        }else{
                            perror("dia incorrecto");
                            return temp2;
                        }
                    }
                }else
                {   if(dia>=1 && dia<=29)
                        {   temp->dia=dia;
                        }else{
                            perror("dia incorrecto");
                            return temp2;
                        }
                }

            }else{
                if(dia>=1 && dia<=28){
                    temp->dia=dia;
                }else{
                    perror("dia invalido");
                    return temp2;
                }

            }

        }else{
            if(1<=dia && dia <=30)
            {   temp->dia=dia;
                
            }else{
                perror("dia invalido");
                return temp2;
            }

        }
        
    }else{
        if(mes%2 && mes!=2){
            if(1<=dia && dia <=30)
            {   temp->dia=dia;
                
            }else{
                perror("dia invalido");
                return temp2;
            }
        }else{
            if(1<=dia && dia <=31)
            {   temp->dia=dia;
                
            }else{
                perror("dia invalido");
                return temp2;
            }
        }
    }
    return temp;
}

void date_print(DATE date){

    printf("{"
           "\"Dia\":%u,"
           "\"Mes\":%u,"
           "\"Año\":%u"
           "}",date.dia,date.mes,date.año);
}

void date_destroy(DATE *date)
{   
    free(date);
}