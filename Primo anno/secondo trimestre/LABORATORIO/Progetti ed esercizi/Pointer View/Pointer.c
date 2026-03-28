#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define ADDRESS 10
// Prototipi delle funzioni
void AritmeticaPuntatori(int *ptr, int size);
void navigate_and_modify(int *ptr, int size);
void Visualizza(int *ptr, int size);
void reverse_with_pointers(int *array[], int size);
void copy(int *array, int *dest, int size);

int main(){
    int array[ADDRESS];
    int *pointer_first = array;
    int s=sizeof(int);
    s=ADDRESS;
    AritmeticaPuntatori(pointer_first,s);
    printf("\n");

    navigate_and_modify(pointer_first,s);
    Visualizza(pointer_first,s);
    printf("\n");
    
    int* point_array[ADDRESS];
    for (int i = 0; i < ADDRESS; i++) {
        point_array[i] = &array[i];
    }
    reverse_with_pointers(point_array,s);
    Visualizza(pointer_first,s);
    printf("\n");

    int destinazione[ADDRESS];
    int *dest = destinazione;
    copy(pointer_first, dest, s);

    return 0;
}

//Funzioni
/*Funzione che acquisisca 10 valori interi in un array casualmente
 *Allocare l'array ed inizializzare un puntatore *ptr all'inizio dell'array
 *Attraverso l'aritmetica dei puntatori inserire i valori randomici da 0 a 100
 *Con la stessa aritmetica stampare i valori dell'array
*/
void AritmeticaPuntatori(int *ptr, int size){
    srand(time(NULL));
    for(int i=0; i<size; i++){
        *(ptr+i)=rand()%101;
        printf("\n%d valore e': %d ", i+1, *(ptr+i));
    }
}

/*Implementa una funzione void navigate_and_modify(int *start, int size) che:
• Riceve il puntatore all’inizio dell’array e la dimensione
• Si "muove" nell’array con l’aritmetica dei puntatori
• Ogni volta che accede a un elemento pari, lo moltiplica per 2
• Ogni volta che accede a un elemento dispari, lo rende negativo */

void navigate_and_modify(int *ptr, int size){
    for(short i=0;i<size;i++){
        if(*(ptr+i)%2==0) *(ptr+i)=*(ptr+i)*2;
        else *(ptr+i)=*(ptr+i)*-1;
    }
}

//funzione per visualizzare di volta in volta i cambiamenti dell'array
void Visualizza(int *ptr, int size){
    for(short i=0;i<size;i++){
        printf("\n%d valore e': %d ", i+1, *(ptr+i));
    }
}

/*Implementa una funzione void reverse_with_pointers(int *start, int size) che:
 *inverte gli elementi nell’array utilizzando solo puntatori senza la notazione indice */
void reverse_with_pointers(int *array[], int size){                    
    for(short i=0; i<size/2; i++){
        int t=0;
        t = *array[i];
        *array[i] = *array[size - 1 - i];
        *array[size - 1 - i] = t;
    }
}

/*Implementa una funzione copy(int *src, int *dest, int size) che:
 *copia l'array di interi src nell'array di interi dest
 *Utilizza i puntatori e l'aritmetica dei puntatori per effettuare la copia */
void copy(int *array, int *dest, int size) {
    for (int i = 0; i < size; i++) {
        *(dest + i) = *(src + i);
    }
}