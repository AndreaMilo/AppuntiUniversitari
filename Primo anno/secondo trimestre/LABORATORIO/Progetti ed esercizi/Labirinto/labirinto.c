#include <stdlib.h>
#include <time.h>
//#include <ctype.h>
#include <stdio.h>

#ifndef LABIRINTO_H
#define LABIRINTO_H

#define K 8
#define VUOTA 0

typedef struct{
    int mappa[K][K];
    int xG; // riga giocatore
    int yG; //colonna giocatore
    int xT; //tesoro riga
    int yT; //tesoro colonna
}labirinto_t;

labirinto_t labirinto={{VUOTA, VUOTA}, -1,-1,-1,-1};

void Griglia(){
    int seed=time(NULL);
    srand(seed);
    labirinto.xG=rand()%K;
    labirinto.yG=rand()%K;
    while (labirinto.xT!=labirinto.xG && labirinto.yT!= labirinto.yG){
        labirinto.xT=rand()%K;
        labirinto.yT=rand()%K;
    }
}

int Muovi(char comando){
    comando=tolower(comando); //Conversione automatica in minuscolo

    switch(comando){
        case 'w':
            if(labirinto.yG>0 && labirinto.mappa[labirinto.yG-1][labirinto.xG]==VUOTA) labirinto.yG--;
            else printf("\nNon ho spazio per andare in alto");
            break;
        case 's':
            if(labirinto.yG<K-1) labirinto.yG++;
            else printf("\nNon ho spazio per andare in basso");
            break;
        case 'a':
            if(labirinto.xG>0) labirinto.xG--;
            else printf("\nNon ho spazio per andare a sinistra");
            break;
        case 'd':
            if(labirinto.xG<K-1) labirinto.xG++;
            else printf("\nNon ho spazio per andare a destra");
            break;
        default:
            printf("\nNon ci siamo");
    }

    if(labirinto.xG==labirinto.xT && labirinto.yG==labirinto.yT){
        printf("\nHai trovato il tesoro!");
        return 1;
    }
    else return 0;
}

void VisualizzaGriglia(){
    short posizione=0;
    for(short int r = 0; r < K; r++){
        printf("\n");
        for(short int c = 0; c < K; c++){
            if(r == labirinto.yG && c == labirinto.xG){
                printf("  G  "); // Giocatore
            } else {
                posizione= r*K+c+1;
                printf("%5d", posizione); //posizioni numeriche
            }
        }
    }
    printf("\n");
}

#endif