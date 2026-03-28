#define STUDENTI_H
#define STUDENTI 2
#define ESAMI 20
#define STRING_LENGHT 40
#include <time.h>
#include <stdlib.h>

//strutture
typedef struct
{
    int giorno;
    int mese;
    int anno;
} data;

typedef struct
{
    char nome[STRING_LENGHT];
    char cognome[STRING_LENGHT];
    data nascita;
    int matricola;
    int libretto[ESAMI];
} studente;

//funzioni
studente Studenti(studente student){
    studente classe[STUDENTI] = {"", "", {0, 0, 0}, 0, {0}};
    int seed = time(NULL);
    static int giorni_validi[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    srand(seed);
    for (unsigned int i = 0; i < STUDENTI; i++)
    {
        printf("Inserire nome studente %d: ", i + 1);
        scanf("%s", classe[i].nome);
        printf("Inserire cognome studente %d: ", i + 1);
        scanf("%s", classe[i].cognome);
        do
        {
            printf("Inserire matricola studente %d: ", i + 1);
            scanf("%d", &classe[i].matricola);
            if (classe[i].matricola <= 0)
            {
                printf("\nLa matricola non è valida, deve essre maggiore di 0!\n");
            }
        } while (classe[i].matricola <= 0);
        do
        {
            printf("Inserire mese di nascita studente %d: ", i + 1);
            scanf("%d", &classe[i].nascita.mese);
            if (classe[i].nascita.mese < 1 || classe[i].nascita.mese > 12)
            {
                printf("\nIl mese di nascita non è valido, deve essre compreso tra 1 e 12!\n");
            }
        } while (classe[i].nascita.mese < 1 || classe[i].nascita.mese > 12);
        do
        {
            printf("Inserire giorno di nascita studente %d: ", i + 1);
            scanf("%d", &classe[i].nascita.giorno);
            if (classe[i].nascita.giorno < 1 || classe[i].nascita.giorno > giorni_validi[classe[i].nascita.mese - 1])
            {
                printf("\nIl giorno di nascita non è valido per il mese selezionato, deve essre compreso tra 1 e %d!\n", giorni_validi[classe[i].nascita.mese - 1]);
            }
        } while (classe[i].nascita.giorno < 1 || classe[i].nascita.giorno > giorni_validi[classe[i].nascita.mese - 1]);
        do
        {
            printf("Inserire anno di nascita studente %d: ", i + 1);
            scanf("%d", &classe[i].nascita.anno);
            if (classe[i].nascita.anno < 1800)
            {
                printf("\nL'anno di nascita non è valido, deve essre maggiore di 1799!\n");
            }
        } while (classe[i].nascita.anno < 1800);
        for (unsigned int j = 0; j < ESAMI; j++)
        {
            classe[i].libretto[j] = rand() % (31 - 18 + 1) + 18;
        }
    }
}
