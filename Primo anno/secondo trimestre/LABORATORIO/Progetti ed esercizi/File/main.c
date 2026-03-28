#include <stdio.h>
#include <stdlib.h>
#include "studentiFile.h"

int main(){
    short scelta=0;
    short x=1;
    int posizione=0;
    studenti_t stud={0};

    do{
        printf("Scegli le seguenti opzioni\n 1-Se vuoi creare un nuovo file\n2-Se vuoi modificare un file esistente\n3-Se vuoi ricercare uno studente per codice\n4-Per visualizzare gli studenti con la media maggiore");
        printf("\nQualsiasi altra opzione ti fara' uscire dal programma! -> ");
        
        scanf("%hd", &scelta);
        switch (scelta){
            case 1:
                scrivere("studentibinari.dat",stud);
                break;
            case 2:
                printf("\nInserire la posizione dello studente da modificare il file ");
                scanf("%d", &posizione);
                aggiornare("studentibinari.dat",posizione, stud);  //DA RIVEDERE LA MODIFICA
                break;
            case 3:
                ricerca("studentibinari.dat",stud);
                break;
            case 4:
                mediaMaggiore("studentibinari.dat",stud);
                break;
            default:
                x=0;
                printf("\nUscita dal programma...\n");
                break;
        }
        if(x==1 || x==2 || x==3 || x==4){ 
            printf("\nVuoi continuare? (SI-1, NO-0): ");
            scanf("%hd", &x);
        }
    }while(x==1 || x==2 || x==3 || x==4);

    return 0;
}