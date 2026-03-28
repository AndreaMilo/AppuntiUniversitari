/*
    Libreria che gestirà le operazioni per il gioco del labirinto, definendo le funzioni
    per le gestione del giocatore e della creazione del labirinto 8x8, posizionando il tesoro
    in una posizione casuale, stampare il labirinto senza la posizione del tesoro
    e implementare un algoritmo per il movimento del giocatore.
    Quest'ultimo si basa sul movimento dei comandi: WASD per le varie direzioni,
    controllo del giocatore per rimanere nei limiti dell'8x8, infine verificare la vittoria del giocatore
    e stampare un messaggio di vittoria

    char Griglia()
    void StampaGriglia()
    char Comandi(char array);

    
    Author: Andrea Milo
    Date: 31/03/2025
    Number of versions: 1
    Version: 2.0

*/
#include "labirinto.c"
#ifndef LABIRINTO_H

#define LABIRINTO_H

void Griglia();

int Muovi(char comando);

void VisualizzaGriglia();

#endif