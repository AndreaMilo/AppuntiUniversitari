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
        const int DIMENSIONE=30;
        struct cella{tipoelem elemento;
            int posizione_succ;
        };
        cella elementi[DIMENSIONE];
        posizione lista_inizio; // elemento della lista momentaneo
        posizione lista_vuota; // elemento della lista vuoto
};