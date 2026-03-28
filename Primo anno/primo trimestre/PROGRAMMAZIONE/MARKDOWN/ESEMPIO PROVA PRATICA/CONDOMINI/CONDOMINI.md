## TRACCIA
Un amministratore di condominio deve redigere il rendiconto annuale dello stabile da lui amministrato. Per ogni condomino dispone delle seguenti informazioni: nominativo, piano, interno, quota versata durante l’anno, totale delle spese ordinarie e totale delle spese straordinarie. Il programma dovrà consentire di: 
• Caricare informazioni in una tabella; 
• Visualizzare per ogni condomino il saldo precisando se a debito o a credito; 
• Inserito il nominativo di un condomino, visualizzare la quota che ha versato durante l’anno e il totale di tutte le spese che lo riguardano 
• Visualizzare i dati del condomino che ha il maggior debito Per la soluzione del problema, 

sviluppare le seguenti fasi: 
a) Analizzare il problema chiarendo le sue specifiche e formulando eventuali ipotesi necessarie per la soluzione. Individuare i dati di ingresso (dominio di definizione) e fornire un campione. Individuare i dati di uscita (dominio di definizione) e fornire il campione di output corrispondente al campione di input.
b) Progettare la strategia di soluzione del problema individuando una scomposizione in sottoproblemi e rappresentarla attraverso un albero di sviluppo. 
c) Descrivere l’algoritmo risolutore di ciascun sotto-problema attraverso un linguaggio di descrizione grafico e/o lineare.

## PUNTO A
### CHIARIFICA:
Creare un programma che riceva in input i dati di diversi condominii, registrati in un array di record, che memorizzino il nome, il piano, la misura degli interni in m^3, la quota versata annuale e il totale delle spese ordinarie e straordinarie e li memorizzi in una tabella, successivamente si visualizza il saldo per ogni condominio, quest'ultimo viene calcolato attraverso la formula: 
$Saldo= Quota versata all'anno - (totale spesa ordinarie + totale spese straordinarie)$ , se il valore finale è positivo il saldo è in credito, diversamente è di debito, salvando queste informazioni nell'array. Si prepara un altra funzione che permetta il confronto di tutti i saldi a debito dei condomini e lo memorizza in una variabile in maniera tale da mostrare i dati del condominio con debito più alto. Si ipotizza che non vi sia effettuato alcun controllo sui debiti uguali tra di loro e venga mostrato tra essi il primo considerato nel controllo. Inoltre creare una procedura che presenti in output la quota annuale, totale spesa ordinaria e straordinaria di un condominio del quale si riceva in input il nome per effettuare la ricerca.
Si ipotizza che l'utente sia a conoscenza che non esistono condomini con stesso nominativo e per cui non venga effettuato alcun controllo per esso.

### DATI:
- #### DATI INPUT:

| **Dati**                     | **Variabili**                      |
| ---------------------------- | ---------------------------------- |
| Condomini                    | condomini (array di record)        |
| - nome condominio            | condomini\[i].nomec (stringa char) |
| - piano condominio           | condomini\[i].piano > -1 e < 118   |
| - misura dell'interno        | condomini\[i].interno > 0          |
| - quota versata annualmente  | condomini\[i].quotann > 0          |
| - totale spese ordinarie     | condomini\[i].totspesa_ord         |
| - totale spese straordinarie | condomini\[i].totspesa_strao       |
| - esito saldo                | condomini\[i].esitsaldo            |
| nome da ricercare            | ric_nome (stringa char)            |
| totale appartamenti          | totapp > 0                         |

- #### DATI OUTPUT:

|**Dati**|**Variabili**|
|---|---|
|Saldo|condomini[i].esitsaldo|
|esito saldo > 0|credito|
|esito saldo < 0|debito|
|dati condominio con debito più alto|condomini[i].nomec, condomini[i].piano, condomini[i].interno, condomini[i].quotann, condomini[i].totspesa_ord, condomini[i].totspesa_strao|
|dati del condominio ricercato con nome in input|condomini[i].quotann, condomini[i].totspesa_ord, condomini[i].totspesa_strao|
|Messaggio di errore condominio non trovato|Condominio non esistente|
## PUNTO B
### SCOMPOSIZIONE IN SOTTOPROBLEMI CON ALBERO DI DECOMPOSIZIONE:
![[WhatsApp Image 2025-01-20 at 21.26.41.jpeg]]
![[WhatsApp Image 2025-01-20 at 21.26.42.jpeg]]
![[WhatsApp Image 2025-01-20 at 21.26.44.jpeg]]
## PUNTO C
### REALIZZAZIONE ATTRAVERSO LINGUAGGIO GRAFICO DELL'ALGORITMO IN FLOWCHART:
![[WhatsApp Image 2025-01-20 at 21.26.45.jpeg]]
![[WhatsApp Image 2025-01-20 at 21.26.46.jpeg]]
![[WhatsApp Image 2025-01-20 at 21.26.48.jpeg]]
![[WhatsApp Image 2025-01-20 at 21.26.49.jpeg]]
*(L'algoritmo di ricerca del maggiore non sono sicuro che sia giusto graficamente)*
## PUNTO D
### CODICE IN C:
```
/******************************************************************************

Condomini

*******************************************************************************/
#include <stdio.h>
#include <string.h>
#define STRINGA 100
#define MAXC 117

//definire il record
typedef struct{
    char nomec[STRINGA];
    int piano;
    float interno;
    float quotann;
    float totspese_ord;
    float totspese_strao;
    short esitsaldo;
}condomini_t;

//dichiarazione funzioni
int caricamento_dati(condomini_t condominio[]);
void visualizzas(condomini_t condominio[], int totapp);
void ricerca(condomini_t condominio[], int totapp);
void debitomax(condomini_t condominio[], int totapp);

//main
int main()
{
    condomini_t c[MAXC];
    int nappartamenti=0;
    nappartamenti=caricamento_dati(c);
    visualizzas(c,nappartamenti);
    printf("\n");
    ricerca(c,nappartamenti);
    printf("\n");
    debitomax(c,nappartamenti);
    
    return 0;
}

//implementazione funzioni
//Caricamento dai nell'array (P2)
int caricamento_dati(condomini_t condominio[]){
    int totapp=0;
    printf("Inserire quanti appartamenti sono presenti: ");
    do{
        scanf("%d", &totapp);
    }while(totapp<0);
    for(short i=0;i<totapp;i++){
        printf("\nInserire il nome del condominio numero %hd: ", i+1);
        scanf("%s", condominio[i].nomec);
        
        do{
            printf("\nInserire il piano del condominio numero %hd: ", i+1);
            scanf("%d", &condominio[i].piano);
        }while(condominio[i].piano<0 || condominio[i].piano>117 );
        
        do{
            printf("\nInserire la misura dell'interno in metri cubi del condominio numero %hd: ", i+1);
            scanf("%f", &condominio[i].interno);
        }while(condominio[i].interno<0);
        
        do{
            printf("\nInserire la quota annuale versata del condominio numero %hd: ", i+1);
            scanf("%f", &condominio[i].quotann);
        
            printf("\nInserire il totale delle spese ordinarie del condominio numero %hd: ", i+1);
            scanf("%f", &condominio[i].totspese_ord);
        
            printf("\nInserire il totale delle spese straordinarie del condominio numero %hd: ", i+1);
            scanf("%f", &condominio[i].totspese_strao);
        }while(condominio[i].quotann<0);
    }
}

//Visualizzazione saldo (P3)
void visualizzas(condomini_t condominio[], int totapp){
    float saldo=0;
    for(short i=0;i<totapp;i++){
        saldo=condominio[i].quotann-(condominio[i].totspese_ord+condominio[i].totspese_strao);
        if(saldo>0){
            condominio[i].esitsaldo=0;
            printf("\nIl saldo del condominio numero %hd ammonta a %f a tipo di credito", i+1, saldo);
        }
        else{
            condominio[i].esitsaldo=1;
            printf("\nIl saldo del condominio numero %hd ammonta a %f a tipo di debito", i+1, saldo);
        }
        saldo=0;
    }
}

//Ricerca nominativo (P5)
void ricerca(condomini_t condominio[], int totapp){
    char ric_nome[STRINGA];
    short flag=0;
    printf("\nInserire il nominativo per cui attuare la ricerca del condominio: ");
    scanf("%s", ric_nome);
    for(short i=0;i<totapp;i++){
        if(strcmp(condominio[i].nomec, ric_nome)==0){
            //a differenza di strncmp usiamo 2 argomenti omettendo quanti caratteri confrontare, rispetto all'esericizio precedente
            flag=1;
            printf("\nI dati monetari di questo condominio sono: ");
            printf("\nQuota annuale: %f", condominio[i].quotann);
            printf("\nTotale spese ordinarie: %f", condominio[i].totspese_ord);
            printf("\nTotale spese straordinarie: %f", condominio[i].totspese_strao);
        }
    }
    if(flag!=1) printf("\nNon esiste nessun condominio con questo nominativo");
}

//Visualizzare condominio con maggior debito (P4)
void debitomax(condomini_t condominio[], int totapp){
    float saldo=3402823466; //temporanea nel mio flowchart, impostando al valore più alto accedabile da un float
    short max=0, i=0;
    //impostare il valore del primo debito a saldo
    do{
        if(condominio[i].esitsaldo==1){
            saldo=condominio[i].quotann-(condominio[i].totspese_ord)+(condominio[i].totspese_strao);
        }
        printf("%f",saldo);
        i++;
    }while(saldo<0);
    //così che nel confronto potrà essere comparato agli altri debiti successivi e prendere il debito più pesante
    for(i=0;i<totapp;i++){
        printf("\n%hd", condominio[i].esitsaldo);
        if(condominio[i].esitsaldo==1){
            if(saldo>(condominio[i].quotann-(condominio[i].totspese_ord)+(condominio[i].totspese_strao))){
                saldo=condominio[i].quotann-(condominio[i].totspese_ord)+(condominio[i].totspese_strao);
                max=i;
            }
        }
    }
    printf("\nEcco forniti i dati del condominio che detiene il saldo a debito piu' alto: ");
    printf("\n%s", condominio[max].nomec);
    printf("\n%d", condominio[max].piano);
    printf("\n%f", condominio[max].interno);
    printf("\n%f", condominio[max].quotann);
    printf("\n%f", condominio[max].totspese_ord);
    printf("\n%f", condominio[max].totspese_strao);
}
```
