#include <stdio.h>  
#include <stdlib.h>  

typedef struct strdate {  
   int year;  
   int month;  
   int day;  
   struct strdate *next;  
} date_t;  

void printdates(date_t *d);  
void insert(date_t **ptrinciolista,date_t *n);  

int main()  
{  
   date_t d1={1,10,2019,NULL};  
   date_t d2={2,02,2020,NULL};  
   date_t d3={3,03,2021,NULL};  
   date_t *iniciolista=NULL;  

   insert(&iniciolista,&d1);  
   insert(&iniciolista,&d2);  
   insert(&iniciolista,&d3);  

   printdates(iniciolista);  
}  

void insert(date_t **ptriniciolista,date_t *n)  
{
    if (*ptriniciolista!=NULL){
        date_t *temp=*ptriniciolista;
        while(temp->next){
            temp=temp->next;
        }
        temp->next=n;

    }else{
        *ptriniciolista=n;

    }   
   
}  

void printdates(date_t *d)  
{  
  date_t *ptr=d;  

  while(ptr!=NULL)  
  {  
      printf("%d,%d,%d\n",ptr->year,ptr->month,ptr->day);  
      ptr=ptr->next;  
  }  
}   
