#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "studenti.h"

int main()
{
    
    printf("\n === MEDIA ESAMI PER STUDENTE ===\n");
    // calcola media
    int max_pos = -1;
    float max_avg = 0;
    for (unsigned int i = 0; i < STUDENTI; i++)
    {
        float avg = 0;
        for (unsigned int j = 0; j < ESAMI; j++)
        {
            avg += classe[i].libretto[j];
        }
        avg = avg / ESAMI;
        if (avg > max_avg)
        {
            max_avg = avg;
            max_pos = i;
        }
        printf("Media esami studente %s %s: %.2f \n", classe[i].cognome, classe[i].nome, avg);
    }

    // stampa nome e cognome dello studente che ha la media più alta
    if (max_pos > -1)
    {
        printf("\nStudente con la media più alta: %s\t%s\n", classe[max_pos].nome, classe[max_pos].cognome);
    }

    int freq[14] = {0};
    for (unsigned int i = 0; i < STUDENTI; i++)
    {
        for (unsigned int j = 0; j < ESAMI; j++)
        {
            freq[classe[i].libretto[j] - 18]++;
        }
    }
    printf("\nFrequenza voti esami:\n");
    for (unsigned int i = 0; i < 14; i++)
    {
        if (i < 13)
            printf("Frequenza voto %d: %d\n", i + 18, freq[i]);
        else
            printf("Frequenza voto Trenta e Lode: %d\n", freq[i]);
    }
    printf("\n");
}