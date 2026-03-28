/*
    Libreria che gestirà le operazioni per definire i dati degli
    studenti e delle loro classi, la gestione randomica di approvigionamento
    reale dei voti degli studenti, il calcolo della media degli esami per ogni studente
    e la stampa dei risultati, con corrispettivi dati degli studenti e delle loro classi
    
    void Studenti(*studente)
    float MediaStudente(float, *studente)
    void StampaStudente(float, *studente)
    float MediaMassima(float, *studente)
    void StampaStudMassimo(float, *studente)

    
    Author: Andrea Milo
    Date: 31/03/2025
    Number of versions: 1
    Version: 1.0

    non inlcude altre librerie al momento
*/
#include "studenti.c"

#ifndef STUDENTI_H

#define STUDENTI_H
studente Studenti();

float MediaStudente(float, *studente);

void StampaStudente(float, *studente);

float MediaMassima(float, *studente);

void StampaStudMassimo(float, *studente);

#endif //STUDENTI_H