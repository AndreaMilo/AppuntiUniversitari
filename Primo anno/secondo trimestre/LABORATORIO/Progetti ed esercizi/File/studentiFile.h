/*
    Libreria che gestisce la struct per lo studente e gestisce le funzioni
    che andranno a modificare il file binario attraverso la scelta dell'utente, il quale può:
    - aggiornare
    - scrivere
    - ricercare uno studente per codice
    - visualizzare studente/i con media maggiore
    
    void scrivere(char *nomeFile);
    void aggiornare(char *nomeFile, int pos);
    void ricerca(char *nomeFile, studenti_t stud);
    void mediaMaggiore(char *nomeFile, studenti_t stud);

    
    Author: Andrea Milo
    Date: 27/04/2025
    Number of versions: 1
    Version: 1.0
*/

#ifndef STUFILE
#define STUFILE

//Struttura dello studente
typedef struct{
    int codice;
    char nome[85]; //nome più lungo al mondo
    char cognome[666]; //cognome più lungo al mondo
    char matricola[6];
    float votom;
}studenti_t;


void scrivere(char *nomeFile, studenti_t);
void aggiornare(char *nomeFile, int, studenti_t);
void ricerca(char *nomeFile, studenti_t);
void mediaMaggiore(char *nomeFile, studenti_t);

#endif