#include <stdlib.h>
#include <stdio.h>
#include "math2.h"

int main(){
    int x = 4;
    int y = 2;
    int result=0;

    float c=4.0;
    float d=2.0;
    float e=0.0;

    result=somma(x,y);
    printf("La somma di %d e %d e' %d\n", x, y, result);

    result=sottrazione(x,y);
    printf("La sottrazione di %d e %d e' %d\n", x, y, result);

    result=prodotto(x,y);
    printf("La moltiplicazione di %d e %d e' %d\n", x, y, result);

    if(d!=0){
        e=divisione(c,d);
        printf("La divisione di %f e %f e' %f\n", c, d, e);
    }
    else printf("Non è possibile");

    result=quadrato(x);
    printf("Il quadrato di %d e' %d\n", x, result);
    result=quadrato(y);
    printf("Il quadrato di %d e' %d\n", y, result);

    result=cubo(x);
    printf("Il cubo di %d e' %d\n", x, result);
    result=cubo(y);
    printf("Il cubo di %d e' %d\n", y, result);

    result=dispari(x);
    printf("Il numero %d e' %d dispari\n", x, result);

    result=pari(x);
    printf("Il numero %d e' %d pari\n", x, result);

    return 0;
}