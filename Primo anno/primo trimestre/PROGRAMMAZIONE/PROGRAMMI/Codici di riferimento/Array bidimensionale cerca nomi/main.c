/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define N 5
int main()
{
    short presente=0;
    int M=0;
    printf("Inserisci la grandezza massima dei nomi che vuoi inserire: ");
    scanf("%d", &M);
    char nome[M], nomi[N][M];
    
    //Inserire nomi nella lista
    printf("Inserisci i nomi della tua lista: ");
    for (int i = 0; i <= N; i++) {
        fgets(nomi[i], M, stdin);
        nomi[i][strcspn(nomi[i], "\n")] = '\0'; // Rimuove il newline
    }
    
    //Inserire nome da cercare
    printf("\nInserisci il nome che tu credi stia nella lista: ");
    fgets(nome,sizeof(nome), stdin);
    nome[strcspn(nome,"\n")]='\0';
    
    //Cercarlo nella lista
    for(short i=0;i<=N;i++){
        if(strcmp(nomi[i],nome)==0){
            //printf("Weli wela");
            presente=i;
        }
    }
    
    //Output
    if(presente!=0) printf("%s presente in posizione %hd", nome, presente);
    else printf("\nNon esiste questo nome nella lista");
    
    return 0;
}
