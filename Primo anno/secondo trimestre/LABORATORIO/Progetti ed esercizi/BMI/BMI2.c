#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Prototipi funzioni
float CalcoloMedia(float vector[]);
float CalcoloBMI(float vector[], float h, float p);
float CalcoloMax(float vector[]);
void Acquisizione(float vector[], float *h, float *p);
void OutputVector(float vector[]);
void MostraDati(float vector[],float massimo, float medium);

//main
int main(){
    float bmi[5];
    float altezza=0;
    float peso=0;
    float media=0, max=0;

    Acquisizione(bmi, &altezza, &peso);
    OutputVector(bmi);

    media=CalcoloMedia(bmi);
    max=CalcoloMax(bmi);
    
    MostraDati(bmi,max,media);
    return 0;
}

//Implementazione
void Acquisizione(float vector[], float *h, float *p){
    short i=0;
    srand(time(NULL));
    do{
        *p=rand()%(120-60+1)+60;
        do{
            *h=(rand()%(200-160+1)+160)/100;
        }while(*h==0);
        vector[i]=CalcoloBMI(vector,*h,*p);
        i++;
    }while(i!=5);
}

float CalcoloBMI(float vector[], float h, float p){
    return p/(h*h);
}

void OutputVector(float vector[]){
    for(short int i=0; i<5;i++){
        printf("\n Il BMI del individuo %hd e' di: %.2f ",i+1, vector[i]);
    }
}

float CalcoloMedia(float vector[]){
    float sum=0;
    for(short int i=0; i<5; i++){
        sum+=vector[i];
    }
    return sum/5;
}

float CalcoloMax(float vector[]){
    float biggest = vector[0];
    for(short i=0; i<5; i++){
        if(biggest<vector[i]) biggest=vector[i];
    }
    return biggest;
}

void MostraDati(float vector[], float massimo, float medium){
    for(short i=0; i<5; i++){
        if(vector[i]<18.5) printf("\nL'individuo %hd e' in sottopeso", i+1);
        else if(vector[i]>18.5 && vector[i]<=25) printf("\nL'individuo %hd e' in normopeso", i+1);
        else printf("\nL'individuo %hd e' in sovrappeso", i+1);
    }
    printf("\nIl BMI massimo e' di: %.2f", massimo);
    printf("\nLa media dei BMI e' di: %.2f", medium);
}