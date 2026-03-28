/******************************************************************************

Agenzia viaggi 

*******************************************************************************/
#include <stdio.h>
#include <string.h>

#define ANNOATT 2025
#define CABINEMAX 10
#define STRINGA 80

//strutture
typedef struct{
    int g;
    int mese;
    int anno;
}data_t;

typedef struct{
    char nome[STRINGA];
    int ncabine;
    data_t d;
}cliente_t;

typedef struct{
    char skipper[STRINGA];
    int numcab;
    char nbarca[STRINGA];
}barca_t;

//dichiarazione funzioni
int caricamento_barca(barca_t barca[]);
void visualizzabarca(barca_t barca[], int numbarche);
void prenotazione(cliente_t cliente[], int numbarche, barca_t barca[]);
void datibarca(barca_t barca[], int numbarche, char* ric_skipper);

int main()
{
    barca_t b[10];
    int numero_barche=0;
    char rskipper[STRINGA];
    
    numero_barche=caricamento_barca(b);
    cliente_t c[10];
    prenotazione(c,numero_barche,b);
    
    printf("\nInserire skipper da cercare per vedere i dati della barca: ");
    scanf("%s", rskipper);
    datibarca(b,numero_barche,rskipper);
    return 0;
}

//funzione P1
int caricamento_barca(barca_t barca[]){
    int numbarche=0;
    printf("Inserire il numero delle barche presenti al porto: ");
    scanf("%d", &numbarche);
    for(short i=0;i<numbarche;i++){
        printf("\n Inserire il nome della barca numero %hd: ", i+1);
        scanf("%s", barca[i].nbarca);
        printf("\n Inserire lo skipper della barca numero %hd: ", i+1);
        scanf("%s", barca[i].skipper);
        do{
            printf("\n Inserire il numero di cabine presenti nella barca numero %hd: ", i+1);
            scanf("%d", &barca[i].numcab);
        }while(barca[i].numcab<0 || barca[i].numcab > CABINEMAX);    
    }
}

//prova di visualizzazione barche
/*
void visualizzabarca(barca_t barca[], int numbarche){
    for(short i=0;i<numbarche;i++){
        printf("\n I dati della barca numero %hd sono: ", i+1);
        printf("\n %s %s %d", barca[i].nbarca, barca[i].skipper, barca[i].numcab);
    }
}*/

//funzione P2
void prenotazione(cliente_t cliente[], int numbarche, barca_t barca[]){
    short i=0, j=0, flag=0,x=0;
    do{
        printf("\nPer eseguire la prenotazione della sua barca procedere ad inserire il vostro nome: ");
        scanf("%s", cliente[i].nome);
        printf("\nPer continuare con la prenotazione procedere ad inserire la data di partenza, \nASSICURAZRSI DI INSERIRLA CORRETTAMENTE");
        do{
            printf("\nInserire il giorno: ");
            scanf("%d", &cliente[i].d.g);
        }while(cliente[i].d.g<1 || cliente[i].d.g>31); // in maniera tale da non accettare lo 0
        
        do{
            printf("\nInserire il mese: ");
            scanf("%d", &cliente[i].d.mese);
        }while(cliente[i].d.mese<1 || cliente[i].d.mese>12);
        
        do{
            printf("\nInserire l'anno: ");
            scanf("%d", &cliente[i].d.anno);
        }while(cliente[i].d.anno<ANNOATT);
        
        printf("\nFornire numero cabine da prenotare: ");
        scanf("%d", &cliente[i].ncabine);
        for(j=0;j<numbarche;j++){
            if(cliente[i].ncabine>barca[j].numcab) flag=1; // così potremmo uscire direttamente dal programma
            else flag=0;
        }
        if(flag==1){
            printf("\nCabine non disponibili, bye bye");
            x=1; //In modo tale che esca dal ciclo
        }
        
        //controllo sulla data per vedere se coincide con le altre presenti nel codice
        j=0;
        for(j;j<i;j++){
            if((cliente[i].d.g==cliente[j].d.g)||(cliente[i].d.mese==cliente[j].d.mese)||(cliente[i].d.anno==cliente[j].d.anno)){
                printf("\nPrenotazione non disponibile in questa data");
                x=1;
            }
        }
        if(x!=1) printf("\nPrenotazione riuscita con successo");
        
        if(x==0){
            printf("\nSe si vuole continuare a prenotare un altro cliente premere '0' altrimenti qualunque valore ");
            scanf("%hd", &x);
            if(x==0) i++;
        }
    }while(x==0);
}

//Funzione P3
void datibarca(barca_t barca[], int numbarche, char* ric_skipper){
    short stampato=0;
    for(short i=0;i<numbarche;i++){
        if(strncmp(barca[i].skipper, ric_skipper, STRINGA)==0){
            printf("\n I dati della barca guidati dallo skipper %s sono: ", ric_skipper);
            printf("\n %s %s %d", barca[i].nbarca, barca[i].skipper, barca[i].numcab);
            stampato=1;
        }
    }
    if(!stampato) printf("Skipper non presente");
}