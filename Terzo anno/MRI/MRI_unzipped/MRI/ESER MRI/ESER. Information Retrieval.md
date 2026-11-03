
![[Pasted image 20261030114601.png]]
Sia $q$ una query che ha 4 documenti rilevanti nella collezione. Supponiamo che un algoritmo di ritrovamento riporti il ranking $R_q$ (R indica che il documento è rilevante; N indica che il documento è non rilevante; il risultato più a sinistra è il top della lista): 

$R_q$: N N R R R N

a) Fornire la descrizione di: _Reciprocal Rank, Average Precision, R-precision, Precision_ 
b) Calcolare _Reciprocal Rank, Average Precision, R-precision e Precision_ per la query $q$


L'esercizio richiede due operazioni:
1. Fornire le definizioni teoriche di quattro metriche di valutazione dei sistemi di Information Retrieval.
2. Calcolare i valori numerici di queste metriche applicandole alla stringa di risultati $R_q$ fornita (N N R R R N), sapendo in anticipo che i documenti rilevanti totali per questa query nell'intera collezione sono 4.

**Analisi del ranking (Tabella delle posizioni)** Per facilitare i calcoli, tracciamo l'andamento del ranking analizzando l'esito e calcolando la precisione per ogni singola posizione raggiunta:

| Posizione | Esito | Rilevanti trovati | Precisione         |
| --------- | ----- | ----------------- | ------------------ |
| 1         | N     | 0                 | $0/1 = 0$          |
| 2         | N     | 0                 | $0/2 = 0$          |
| 3         | R     | 1                 | $1/3 \approx 0.33$ |
| 4         | R     | 2                 | $2/4 = 0.50$       |
| 5         | R     | 3                 | $3/5 = 0.60$       |
| 6         | N     | 3                 | $3/6 = 0.50$       |

## a) - Descrizione delle metriche
 **Reciprocal Rank (RR):** È il reciproco della posizione (rank) in cui compare il primo documento rilevante restituito dal sistema.
 
 **Average Precision (AP):** È la media aritmetica dei valori di precisione calcolati esclusivamente nelle posizioni in cui viene recuperato un documento rilevante. Se un documento rilevante presente nella collezione non viene restituito, contribuisce alla somma con una precisione pari a 0. Il totale viene diviso per il numero complessivo di documenti rilevanti attesi dalla query.

**R-precision:** È la precisione calcolata esattamente alla posizione $R$ del ranking, dove $R$ equivale al numero totale di documenti rilevanti presenti nell'intera collezione per quella query.  

**Precision:** (Precisione complessiva) È il rapporto tra il numero di documenti rilevanti recuperati e il numero totale di documenti restituiti dal sistema per quella query.

## b) - Calcoli*
- Documenti rilevanti totali attesi nella collezione ($m$ o $R$): 4.
- Documenti totali restituiti dalla query: 6 (stringa di 6 lettere).

**Reciprocal Rank (RR):**
Scorrendo la stringa (N, N, R...), il primo documento rilevante (R) si trova alla posizione 3. 
$RR = \frac{1}{3} \approx 0.33$    

**Average Precision (AP):** 
I documenti rilevanti recuperati si trovano alle posizioni 3, 4 e 5.
Le relative precisioni in questi punti sono:
$$\frac{1}{3},\frac{2}{4},\frac{3}{5}$$

I documenti rilevanti attesi totali sono 4, ma il sistema ne restituisce solo 3; 

il quarto documento mancante contribuisce con $+0$ al numeratore. 
$$AP = \frac{\frac{1}{3} + \frac{2}{4} + \frac{3}{5} + 0}{4} = \frac{0.333 + 0.5 + 0.6}{4} = \frac{1.433}{4} \approx 0.358$$

 **R-precision:** 
 Poiché i documenti rilevanti totali nella collezione sono $R = 4$, dobbiamo valutare la precisione tagliando il ranking alla posizione 4. 
 Tra i primi 4 risultati (N, N, R, R), il sistema ha restituito 2 documenti rilevanti.
$$R\text{-}precision = P@4 = \frac{2}{4} = 0.5$$

**Precision:**
Analizzando l'intera lista dei 6 documenti restituiti (N, N, R, R, R, N), troviamo un totale di 3 documenti rilevanti. 
$$Precision = \frac{3}{6} = 0.5$$

