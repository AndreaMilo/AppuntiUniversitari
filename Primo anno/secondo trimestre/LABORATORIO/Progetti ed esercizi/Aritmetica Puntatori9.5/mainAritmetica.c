#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

//Prototipi delle funzioni
void Inserimento(int *array, int element);
void Visualizza(int *arrat, int element);
void SommaMedia(int *array, int element);
void DivideMoltipla(int *array, int element);


int main(){
    int element=0;
    int *ptr;
    printf("Quanti elementi vuoi inserire dentro all'array?\n");
    scanf("%d", &element);
    ptr = (int *) calloc(element, sizeof(int)); //dinamicamente allocando memoria per un array di element interi
    Inserimento(ptr, element);
    Visualizza(ptr, element);
    
    printf("\n");
    SommaMedia(ptr, element);

    printf("\n");
    DivideMoltipla(ptr, element);
    printf("I numeri dopo la moltiplicazione sono: ");
    Visualizza(ptr, element);
    return 0;
}

//Funzioni
/*Inserimento dell'utente degli elementi dell'array*/
void Inserimento(int *array, int element){
    for(int i=0; i<element; i++){
        printf("Inserisci il numero %d: ", i+1);
        scanf("%d", &*(array+i));
    }
}

/*Visualizzazione dell'array*/
void Visualizza(int *array, int element){
    printf("I numeri inseriti sono: ");
    for(int i=0; i<element; i++){
        printf("%d ", *(array+i));
    }
    printf("\n");
}

/*Somma e media degli elementi dell'array*/
void SommaMedia(int *array, int element){
    int somma=0;
    for(int i=0; i<element; i++){
        somma=somma+*(array+i);
    }
    printf("La somma degli elementi e': %d\n", somma);
    printf("La media degli elementi e': %d\n", somma/element);
}

/*Moltiplicazione degli elementi divisibili per tre*/
void DivideMoltipla(int *array, int element){
    for(int i=0; i<element; i++){
        if(*(array+i)%3==0){
            *(array+i)=10*(*(array+i));
        }
    }
}