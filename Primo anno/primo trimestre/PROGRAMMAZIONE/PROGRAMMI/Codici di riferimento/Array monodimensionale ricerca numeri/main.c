/******************************************************************************

Array monodimensionale
Ricerca valore intero
üRealizzare un algoritmo e un programma che dato in input un
array di N valori interi ricerchi il valore dato in input dall’utente e la
sua posizione. Nel caso il valore esista più volte restituire solo
l’ultima posizione in cui esso si trova
    Autor: Andrea Milo

*******************************************************************************/
#include <stdio.h>
#define N 5
int main()
{
    short n=0, v[N]={0}, presente=0;
    printf("Inserire i 5 numeri da posizione nell'array: ");
    for(short i=0;i<N;i++){
        scanf("%hd", &v[i]);
    }
    
    printf("\nInserisci un valore che tu credi possa esistere nell'array ");
    scanf("%hd", &n);
    for(short i=0;i<N;i++){
        if(v[i]==n){
            presente=i+1;
        }
    }
    if(presente!=0) printf("\n %hd e' presente nella posizione %hd ", n, presente);
    else printf("\n%hd non e' presente nell'array", n);
    
    return 0;
}