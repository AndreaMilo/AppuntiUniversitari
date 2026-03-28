#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "studentiFile.h"

//Funzioni
//Funzione per scrivere sul file binario nuovo
void scrivere(char *nomeFile,studenti_t stud){
    short flag=1; //è stato scritto correttamente
    int numeroStudenti=0;
    FILE* file=fopen(nomeFile, "wb");
    if(file!=NULL){
        printf("\nInserire quanti studenti vuoi inserire: ");
        do{
            printf("\nNumero studenti: ");
            scanf("%d", &numeroStudenti);
            if(numeroStudenti<=0) printf("\nNumero non valido, reinserire: ");
        }while(numeroStudenti<=0);

        //ciclo per l'inserimento dei dati
        for(short i=0;i<numeroStudenti;i++){
                printf("\nInserire i valori da inserire nel file");
                do{
                    printf("\nCodice: ");
                    scanf("%d", &stud.codice);
                    if(stud.codice>1000) printf("\nCodice non valido reinserire: ");
                }while(stud.codice>1000);
                printf("\nNome: ");
                scanf("%s", stud.nome);

                printf("\nCognome: ");
                scanf("%s", stud.cognome);
            
                printf("\nMatricola: ");
                scanf("%s", stud.matricola);
            
                do{
                    printf("\nVoto medio: ");
                    scanf("%f", &stud.votom);
                    if(stud.votom<0 || stud.votom>31) printf("\nValore non valido, rinserire.");
                }while(stud.votom<0 || stud.votom>31);

                if(fwrite(&stud,sizeof(studenti_t),1,file)!=1) flag=0;
                if(!flag) printf("\nErrore durante la scrittura");
                else printf("\nSCRITTO");
            }
            fclose(file);
        }
    else printf("ERROR\n");
}

//funzione per aggiornare il file binario
void aggiornare(char *nomeFile, int pos, studenti_t stud){
    short scelta=0;
    FILE *file=fopen(nomeFile,"rb+");

    if(file!=NULL){
        if(pos<0) printf("\nPosizione non valida, rinserire: ");
        while(pos<0){
            scanf("%d",&pos);
            while (getchar() != '\n'); // pulisci il buffer
            if(pos<0) printf("\nPosizione non valida, rinserire: ");
        }

        //controllo se il file è stato aperto correttamente e verificare che campo modificare
        printf("\nChe campo vuoi modificare?");
        printf("\n1. Codice");
        printf("\n2. Nome");
        printf("\n3. Cognome");
        printf("\n4. Matricola");
        printf("\n5. Voto medio");

        do{
            printf("\nScelta: ");
            scanf("%hd",&scelta);
            while (getchar() != '\n'); // pulisci il buffer
            if(scelta>5 || scelta<1){
                printf("\nScelta errata rinserirla: ");
                //printf("\nTrappola");
            }
            //printf("\nTrappolaB");
        }while(scelta>5 || scelta<1);
    
        //modifica campo selezionato
        switch (scelta){
            case 1:
                /* codice */
                printf("\nInserire il nuovo codice: ");
                scanf("%d",&stud.codice);
                break;
            case 2:
                /* nome */
                printf("\nInserire il nuovo nome: ");
                scanf("%84s",stud.nome);
                break;
            case 3:
                /* cognome */
                printf("\nInserire il nuovo cognome: ");
                scanf("%665s",stud.cognome);
                break;
            case 4:
                /* matricola */
                printf("\nInserire il nuovo codice di matricola: ");
                scanf("%5s",stud.matricola);
                break;
            case 5:
                /* voto medio */
                printf("\nInserire il nuovo voto medio: ");
                scanf("%f",&stud.votom);
                break;

            default:
                printf("Questa è una trappola");
                break;
        }

            //aggiornamento con fseek
            fseek(file,pos*sizeof(studenti_t),SEEK_SET);
            if(fwrite(&stud,sizeof(studenti_t),1,file)!=1) printf("\nErrore nella scrittura del record");
            else printf("\nMODIFICATO");

            fclose(file);
    }
    else printf("\nERROR");
}

//funzione per la ricerca di uno studente
void ricerca(char *nomeFile, studenti_t stud){
    int cod_paragone=0;
    short trova_studente=0; //variabile per verificare se lo studente è stato trovato
    FILE* file=fopen(nomeFile, "rb");
    if(file!=NULL){
        printf("\nInserire il codice dello studente da ricercare: ");
        do{
            printf("\nCodice: ");
            scanf("%d", &cod_paragone);
            if(cod_paragone>1000) printf("\nCodice non valido reinserire: ");
        }while(cod_paragone>1000);
        
        //ciclo per la ricerca dello studente
        while(fread(&stud,sizeof(studenti_t),1,file)==1){
            //controllo se il codice dello studente è uguale a quello inserito
            if(stud.codice==cod_paragone){ 
                trova_studente=1; //se lo studente è stato trovato
                printf("\nCodice: %d", stud.codice);
                printf("\nNome: %s", stud.nome);
                printf("\nCognome: %s", stud.cognome);
                printf("\nMatricola: %s", stud.matricola);
                printf("\nVoto medio: %.2f", stud.votom);
            }
        }
        if(trova_studente==0) printf("\nStudente non trovato");

        fclose(file);
    }
    else printf("ERROR\n");    
}

//funzione per la visualizzazione degli studenti con media maggiore di 18
void mediaMaggiore(char *nomeFile, studenti_t stud){
    float media_max=0;
    FILE *file=fopen(nomeFile, "rb");
    if(file!=NULL){
        //ciclo per la ricerca dello studente
        while(fread(&stud,sizeof(studenti_t),1,file)==1){
            //impostazione della media massima
            if(stud.votom>media_max) media_max=stud.votom;
        }    

        //riposizionare il puntatore all'inizio del file
        fseek(file,0,SEEK_SET);

        //controllo degli studenti con la media massima
        printf("\nGli studenti con la media maggiore sono: ");
        while(fread(&stud,sizeof(studenti_t),1,file)==1){
            if(stud.votom==media_max){
                printf("\nCodice: %d", stud.codice);
                printf("\nNome: %s", stud.nome);
                printf("\nCognome: %s", stud.cognome);
                printf("\nMatricola: %s", stud.matricola);
                printf("\nVoto medio: %f", stud.votom);
            }
        }
        if(media_max<18) printf("\nNessuno studente ha la media maggiore di 18");
        fclose(file);
    }
    else printf("ERROR\n");    
}
    
