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