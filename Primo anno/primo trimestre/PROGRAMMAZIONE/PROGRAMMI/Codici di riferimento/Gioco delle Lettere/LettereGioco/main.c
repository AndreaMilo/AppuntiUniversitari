/*
 * main.c
 *
 *  Created on: 14 nov 2024
 *      Author: Andrea Milo
 */
#include <stdio.h>

int main(){
	//Dichiarazioni
	char PAROLA[8]= {'s', 't', 'e', 'l', 'l', 'a','t','o'};
	char lettera=0;
	short giu=0;

	//ciclo
	for(short i=0;i<=7;i++){
		printf("Inserisci la lettera che credi ci sia nella parola ");
		scanf(" %c", &lettera);
		if(lettera==PAROLA[i]){
			PAROLA[i]='0';
			giu++;
		}
	}

	//controlli dell'esito
	if(giu>7){
		printf("VITTORIA \n");
	}
	else if(giu>=4 && giu<=7){
		printf("CONGRATULAZIONI \n");
	}
	else if(giu>=1 && giu<4){
		printf("PUOI FARCELA \n");
	}
	else printf("Riprova \n");

	printf("Torna a giocare, il tuo contatore attuale e' di: %hd \n", giu);
	return 0;
}

