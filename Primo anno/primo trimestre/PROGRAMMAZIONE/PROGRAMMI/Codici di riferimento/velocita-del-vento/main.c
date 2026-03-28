/******************************************************************************

    NOME: ANDREA MILO
    Esercizio vento in km/h

*******************************************************************************/
#include <stdio.h>

int main()
{
    //definizione variabili
    float vw=0;
    printf("Inserire il valore della velocita' del vento \n");
    
    //Inserimento valori
    scanf("%f", &vw);
    
    //Controllo forza del vento
    if(vw<=0){
        printf("Vento inesistente");
    }
    else if(vw>0 && vw<25){
        printf("Vento debole e la sua velocita' e' di: %.2f ",vw);

    }
    else if(vw>25 && vw<38){
        printf("Vento forte e la sua velocita' e' di: %.2f ",vw);

    }
    else if(vw>=39 && vw<54){
        printf("Tempesta e la sua velocita' e' di: %.2f ",vw);

    }
    else if(vw>= 55 && vw<72){
        printf("Forte Tempesta e la sua velocita' e' di: %.2f ",vw);
    }
    else if(vw>72){
        printf("Uragano e la sua velocita' e' di: %.2f ",vw);
    }

    return 0;
}