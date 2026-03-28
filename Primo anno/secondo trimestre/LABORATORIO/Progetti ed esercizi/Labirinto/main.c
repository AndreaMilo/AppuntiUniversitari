#include <stdio.h>
#include <ctype.h>
#include "labirinto.h"

int main(){
    int flag=0;
    char c;

    Griglia();
    VisualizzaGriglia();
    
    do{
        printf("\nScegli un movimento (W,A, S, D) ");
        c=getchar();
        while(getchar()!='\n');
        flag=Muovi(c);
        
        printf("\nVediamo dove sei!");
        VisualizzaGriglia();
    }while(flag!=1);

    return 0;
}