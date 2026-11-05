***DOMANDE TEORICHE***:
1. Qual è la differenza semantica tra l'uso delle parentesi `<...>` e delle parentesi `{...}` nelle POST condizioni, e quando si sceglie il simbolo `<>`?
2. Come si definisce formalmente in logica (da copiare in una POST condizione) che un array o una lista generica _A_ lunga _n_ è ordinata in modo crescente?
3. Confronta i costi temporali della "Ricerca Lineare" e della "Ricerca Binaria" su array/liste. Qual è il loro caso pessimo, e quale condizione strutturale deve avere una sequenza per poter usare la ricerca binaria?
*****


***APPELLO II 2025-02-07 Esercizio Guidato per capire come farlo**:
**Richiesta:** L'operatore restituisce la somma degli ultimi $k$ (terzo argomento) pagamenti ricevuti dal dipendente.

Fase del **DOMINIO**:
Definisco i parametri di ingresso e il valore restituito, assegnando a loro valori brevi:
- `totaleUltimiKpagamenti (storico, dipendente, intero)->float`
- `totaleUlimtikPagamenti(s,d,k)->somma`

Fase delle **PRE-CONDIZIONI**:
Bisogna chiedersi qual è il requisito minimo pur che abbia funzionamento quest'operazione.
Ovviamente il dipendente di cui vogliamo attuare la somma degli ultimi k pagamenti deve esistere.
- **PRE**: `APPARTIENE(d,s)`

Fase delle **POST-CONDIZIONI**:
Qui dobbiamo usare le funzioni della Lista per arrivare al risultato atteso dalla traccia.
