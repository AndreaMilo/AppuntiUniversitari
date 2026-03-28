#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    //dichiarazione variabili e settaggio del random
    short i=0, eta=0; 
    float peso=0.0, altezza=0.0, bmi=0.0, maxbmi_under=0.0, maxbmi_over=0.0, maxa_under=0.0, maxp_under=0.0, maxa_over=0.0, maxp_over=0.0;
    srand(time(NULL));
    
    //esecuzione dell'algoritmo per l'inserimento dei dati
    do{
        eta = rand()%(142-1); //età massima raggiunta da una persona, con questa cifratura non potremmo avere pesi e altezze enorme per persone mai nate e viceversa per gli altri campi
        peso=rand()%(600-10); //peso massimo raggiunto da una persona
        altezza=(float) rand()/RAND_MAX*2.30; //altezza massima raggiunta da una persona
        bmi=peso/(altezza*altezza);
        printf("\nIl soggetto %hd ha un BMI pari a %.2f ", i+1, bmi);

    //controllo sulle età e memorizzazione dei massimi
        if(eta<=40){
            maxbmi_under=maxbmi_under+bmi;
            if(altezza>maxa_under) maxa_under=altezza;
            if(peso>maxp_under) maxp_under=peso;
        }
        else{
            maxbmi_over=maxbmi_over+bmi;
            if(peso>maxp_over) maxp_over=peso;
            if(altezza>maxa_over) maxa_over=altezza;
        }

        i++;
        bmi=0;
    }while(i!=10);
    
    //stampa dei risultati e verifica del sovrappeso e normopeso
    printf("\n");
    printf("\nIl BMI medio tra gli under 40 e' di: %.2f", maxbmi_under/10);
    if(maxbmi_under/10>25) printf("\nIl campione e' in sovrappeso");
    else printf("\nIl campione e' in sottopeso");

    printf("\n");
    printf("\nIl BMI medio tra gli over 40 e' di: %.2f", maxbmi_over/10);
    if(maxbmi_over/10>25) printf("\nIl campione e' in sovrappeso");
    else printf("\nIl campione e' in sottopeso");
    printf("\n");

    printf("\nL'altezza media tra gli under 40 e' di: %.2f", maxa_under);
    printf("\nIl peso medio tra gli under 40 e' di: %.2f", maxp_under);
    printf("\n");

    printf("\nL'altezza media tra gli over 40 e' di: %.2f", maxa_over);
    printf("\nIl peso medio tra gli over 40 e' di: %.2f", maxp_over);

    return 0;
}