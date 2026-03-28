int somma(int a, int b){
    return a + b;
}

int prodotto(int a, int b){
    return a * b;
}

int sottrazione(int a, int b){
    return a - b;
}

float divisione(int a, int b){
    if(b!=0){
        return (float)a / b;
    } else {
        return 0.0;
    }
}

int quadrato(int a){
    return a * a;
}

int cubo(int a){
    return a * a * a;
}

int dispari(int a){
    return a % 2!=0;
}

int pari(int a){
    return a % 2==0;
}