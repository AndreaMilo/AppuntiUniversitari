/* Esercizio n.1 Lista:
    Realizzazione della struttura dati lista mediante cursori
*/

#include <string>
#include <iostream>

using namespace std;

// classe Lista
class Lista{
    public:
        typedef int tipoelem; //lista popolata da interi
        typedef int posizione;
        Lista(); // costruttore
        //operatori
        void creaLista();
        bool listaVuota() const;
        tipoelem leggiLista(posizione);
        void scriviLista(tipoelem,posizione);
        posizione primoLista();
        bool fineLista(posizione);
        posizione succLista(posizione);
        posizione predLista(posizione);
        void insLista(tipoelem, posizione);
        void cancLista(posizione);

    private:
        static const int DIMENSIONE=30;
        struct cella{tipoelem elemento;
            int posizione_succ;
        };
        cella elementi[DIMENSIONE];
        posizione lista_inizio; // elemento della lista momentaneo
        posizione lista_vuota; // elemento della lista vuoto
};

// Operatori
// Il costruttore richiama semplicemente creaLista
Lista::Lista() {
    creaLista();
}

void Lista::creaLista() {
    lista_inizio = -1; // -1 indica che non ci sono elementi (lista vuota)
    lista_vuota = 0;   // Lo spazio libero inizia dall'indice 0 del vettore

    // Colleghiamo tutte le celle della memoria libera tra loro
    for (int i = 0; i < DIMENSIONE - 1; i++) {
        //la posizione_succ della cella 'i' sia 'i + 1'
        elementi[i].posizione_succ=i+1;
    }
    
    // COSA SCRIVI QUI?
    // Devi fare in modo che la posizione_succ dell'ultimissima cella 
    // (quella all'indice DIMENSIONE - 1) sia -1, per indicare che la memoria è finita
    elementi[DIMENSIONE-1].posizione_succ=-1;
}