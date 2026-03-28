#include "BMI.h"
#include <stdio.h>
#include <stdlib.h>

float CalcoloBMI(float peso, float altezza) {
    if (altezza <= 0) {
        printf("Errore: altezza non valida.\n");
        return -1;
    }

    return peso / (altezza * altezza);
}

float CalcoloMedia(int a, int b) {
    float media = (a + b) / 2.0;
    printf("La media tra %d e %d è: %.2f\n", a, b, media);
    return media;
}

int Esamesuperato(int voto) {
    int esito;
    if (voto >= 18) {
        printf("Esame superato con voto: %d\n", voto);
        esito=1;
    } else {
        printf("Esame non superato con voto: %d\n", voto);
        esito=0;
    }
    return esito;
}