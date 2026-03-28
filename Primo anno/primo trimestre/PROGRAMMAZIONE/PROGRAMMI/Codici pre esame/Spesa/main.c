/*****************************************************************************

Supermercato

*******************************************************************************/
#include <stdio.h>
#include <string.h>
#define STRINGA 50
#define MAX_SUP 20

//definire struttura
typedef struct{
    char cognome[STRINGA];
    char nome[STRINGA];
    char citta[STRINGA];
    int num_dip;
    float fattura;
} supermercato_t; //_t per evitare di scrivere ogni volta la struct 

//dichiarazione funzioni
int caricamento(supermercato_t sup[]);
void stampa_supermercato(supermercato_t sup[], int num_sup);
void ricerca_responsabile(supermercato_t sup[], int num_sup);
void conta_supermercati(supermercato_t sup[], int num_sup);
void massimo_dipendenti(supermercato_t sup[], int num_sup);

//main
int main()
{
    supermercato_t super[MAX_SUP];
    int dim_super;
    
    dim_super=caricamento(super);
    printf("\n");
    stampa_supermercato(super,dim_super);
    printf("\n");
    ricerca_responsabile(super, dim_super);
    printf("\n");
    conta_supermercati(super, dim_super);
    printf("\n");
    massimo_dipendenti(super, dim_super);
    
    return 0;
}

//funzione P1
int caricamento(supermercato_t sup[]){
    int num_sup;
    do{
        printf("Inserire numero dei supermercati: ");
        scanf("%d", &num_sup);
    }while(num_sup<0 || num_sup>MAX_SUP || num_sup==0);
    
    for(int i=0; i<num_sup; i++){
        printf("\nInserire dati ");
        printf("\ncognome del responsabile: ");
        scanf("%s", sup[i].cognome);
        printf("\nNome del responsabile: ");
        scanf("%s", sup[i].nome);
        printf("\nLa città: ");
        scanf("%s", sup[i].citta);
        printf("\nNumero dipendenti: ");
        scanf("%d", &sup[i].num_dip);
        printf("\nFatturato: ");
        scanf("%f", &sup[i].fattura);
    }
    return (num_sup);
}

//funzione di stampataggio
void stampa_supermercato(supermercato_t sup[], int num_sup){
    for(int i=0; i<num_sup; i++){
        printf("\n I dati: ");
        printf("\ncognome e nome del responsabile: %s %s", sup[i].cognome, sup[i].nome);
        printf("\nLa città: %s", sup[i].citta);
        printf("\nNumero dipendenti: %d", sup[i].num_dip);
        printf("\nFatturato: %.2f", sup[i].fattura);
    }
}

//funzione di P2
void ricerca_responsabile(supermercato_t sup[], int num_sup){
    char nome_resp_ric[STRINGA];
    char cognome_ric[STRINGA];
    short flag=0;
    printf("\n cognome e nome del responsabile da ricercare: ");
    scanf("%s %s", cognome_ric, nome_resp_ric);
    
    for(int i=0;(i<num_sup && flag==0);i++){
        if((strcmp(sup[i].cognome, cognome_ric)==0) && (strcmp(sup[i].nome, nome_resp_ric)==0)){
             printf("\n I dati: ");
            printf("\ncognome e nome del responsabile: %s %s", sup[i].cognome, sup[i].nome);
            printf("\nLa città: %s", sup[i].citta);
            printf("\nNumero dipendenti: %d", sup[i].num_dip);
            printf("\nFatturato: %.2f", sup[i].fattura);
            flag=1;
        }
    }
    if(flag==0){
        printf("\n Non esiste un supermercato con questo titolare");
    }
}

//funzione di P3
void conta_supermercati(supermercato_t sup[], int num_sup){
    char citta_ricerca[STRINGA];
    int totale_supermercati=0;
    printf("\nInserire la città da cercare: ");
    scanf("%s", citta_ricerca);
    
    for(int i=0;i<num_sup;i++){
        if(strcmp(sup[i].citta, citta_ricerca)==0) totale_supermercati++;
    }
    if(totale_supermercati==0) printf("\nNon ci sono i supermercati in qesta città ");
    else printf("\nIl numero dei supermercati in quella città sono: %d", totale_supermercati);
}

//funzione di P4
void massimo_dipendenti(supermercato_t sup[], int num_sup){
    int massimo_idx=0;
    for(int i=1; i<num_sup;i++){
        if(sup[i].num_dip>sup[massimo_idx].num_dip) massimo_idx= i;
    }
    
    for(int i=0; i<num_sup; i++){
        printf("\n I dati: ");
        printf("\ncognome e nome del responsabile: %s %s", sup[massimo_idx].cognome, sup[massimo_idx].nome);
        printf("\nLa città: %s", sup[massimo_idx].citta);
        printf("\nNumero dipendenti: %d", sup[massimo_idx].num_dip);
        printf("\nFatturato: %.2f", sup[massimo_idx].fattura);
    }
}