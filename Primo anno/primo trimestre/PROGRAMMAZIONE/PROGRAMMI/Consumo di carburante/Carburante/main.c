/*
 * main.c
 *
 *  Created on: 12 nov 2024
 *      Author: Andrea Milo
 */
#include <stdio.h>

int main(){
	float consumo_giornaliero[31]={0.0}, tot=0, max=0, min=9999;
	short gmax=0, gmin=0, inutilizzo=0;
	for(short i=0;i<31;i++){
		printf("\n Inserire il valore del carburante del giorno numero %hd ", i+1);
		scanf("%f", &consumo_giornaliero[i]);
		if(consumo_giornaliero[i]==-1){
			break;
		}
		if(consumo_giornaliero[i]>0){
			tot=tot+consumo_giornaliero[i];
			inutilizzo=1;
			if(consumo_giornaliero[i]<min){
				gmin=i+1;
				min=consumo_giornaliero[i];
			}
			if(consumo_giornaliero[i]>max){
				gmax=i+1;
				max=consumo_giornaliero[i];
			}
		}
	}
	if(inutilizzo!=0){
		printf("\n Il totale di carburante speso e' %f ", tot);
		printf("\n Il valore minimo speso e' %f nel giorno %hd ", min, gmin);
		printf("\n Il valore massimo speso e' %f nel giorno %hd ", max, gmax);
	}else printf("Macchina non usata questo mese");
}

