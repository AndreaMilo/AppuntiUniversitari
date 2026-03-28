/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>

int main()
{
    //Dichiarazione dati
    short N=0,M=0,r=0,c=0;
    int mediap=0, medias=0;
    printf("Inserire (N) quanti studenti hanno partecipato alla prova: ");
    scanf("%hd", &N);
    printf("\nInserire (M) quante prove sono state effettuate: ");
    scanf("%hd", &M);
    int voti[N][M];
    
    //Inserimento nel ciclo e media studenti
    for(r=0;r<N;r++){
        for(c=0;c<M;c++){
            printf("\nInserire il voto dello studente %hd nella prova n. %hd : ", r+1, c+1);
            scanf("%d", &voti[r][c]);
            while(voti[r][c]<0 || voti[r][c]>31){
                printf("\nInserire valori che superino lo 0 e arrivino a 31, reinserire\n");
                scanf("%d", &voti[r][c]);
            }
            medias+=voti[r][c];
        }
        printf("\nLa media dei voti dello studente %hd e' pari a: %d", r+1,(medias/=N));
        medias=0;
    }
    
    //media prove
    for(c=0;c<M;c++){
        for(r=0;r<N;r++){
            mediap+=voti[r][c];
        }
        printf("\nLa media dei voti della prova %hd e' pari a: %d", c+1,(mediap/=M));
        mediap=0;
    }

    return 0;
}