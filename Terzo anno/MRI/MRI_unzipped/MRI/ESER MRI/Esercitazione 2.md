![[Pasted image 20261030153041.png]]

L'esercizio presenta una query $q$ con 5 documenti rilevanti totali presenti nella collezione. L'algoritmo di ricerca ha restituito un ranking $R_q$ di 6 documenti: `D3, D1, D5, D7, D9, D8`. Di questi documenti recuperati, sappiamo che `D3, D9, e D8` sono rilevanti per la query.


L'esercizio è diviso in due parti:
- **Punto a):** Calcolare Precision, Recall, e Average Precision, fornendo una descrizione formale per ciascuna metrica, basandosi su un concetto di rilevanza binaria (rilevante/non rilevante).
- **Punto b):** Calcolare il DCG (Discounted Cumulative Gain) assumendo giudizi di rilevanza graduata (non-binaria) in cui `D3` e `D8` valgono 3, `D9` vale 2, e gli altri valgono 0, fornendo anche qui una breve descrizione della metrica.


**a): Rilevanza Binaria (Precision, Recall, AP)**
Innanzitutto, costruiamo la tabella di analisi del ranking con rilevanza binaria (D3, D9, D8 sono Rilevanti, gli altri Non Rilevanti).

|**Posizione (k)**|**Documento**|**Rilevanza**|**Rilevanti trovati**|**Precisione (P@k)**|
|---|---|---|---|---|
|1|D3|Rilevante|1|$1/1 = 1.0$|
|2|D1|Non Rilevante|1|$1/2 = 0.5$|
|3|D5|Non Rilevante|1|$1/3 \approx 0.33$|
|4|D7|Non Rilevante|1|$1/4 = 0.25$|
|5|D9|Rilevante|2|$2/5 = 0.4$|
|6|D8|Rilevante|3|$3/6 = 0.5$|

**Precision (Precisione):** 
Indica la frazione di documenti recuperati che sono effettivamente rilevanti.
- _Calcolo:_ Il sistema ha restituito 6 documenti totali, di cui 3 (D3, D9, D8) sono rilevanti.
- $Precision = \frac{3}{6} = 0.5$

**Recall (Richiamo):**
Indica la frazione di documenti rilevanti totali presenti nella collezione che l'algoritmo è riuscito a recuperare.      
- _Calcolo:_ La traccia specifica che la collezione contiene in tutto 5 documenti rilevanti per $q$. Il sistema ne ha trovati 3.
- $Recall = \frac{3}{5} = 0.6$

**Average Precision (AP):**
Rappresenta la media delle precisioni calcolate esclusivamente ai rank in cui viene trovato un documento rilevante. Se un documento rilevante della collezione non viene trovato, contribuisce con 0.
- _Calcolo:_ I documenti rilevanti sono apparsi alle posizioni 1, 5, e 6. Le relative precisioni sono $\frac{1}{1}$, $\frac{2}{5}$, e $\frac{3}{6}$. Ci sono 5 documenti rilevanti totali da trovare, quindi mancano all'appello 2 documenti non recuperati (due "+0").
- $AP = \frac{1 + \frac{2}{5} + \frac{3}{6} + 0 + 0}{5} = \frac{1 + 0.4 + 0.5}{5} = \frac{1.9}{5} = 0.38$


**b): Rilevanza Graduata (DCG)**
**Descrizione metrica DCG (Discounted Cumulative Gain):**
È una metrica che valuta l'utilità di un ranking basandosi su livelli multipli di rilevanza (Graded Relevance). Accumula il guadagno offerto da ciascun documento scendendo nella lista, ma penalizza i documenti utili trovati in basso applicando uno sconto posizionale logaritmico, premiando i sistemi che posizionano le risposte migliori ai primi posti.


**1. Definizione del Vettore di Guadagno ($G$)** Assegniamo ai documenti recuperati il loro grado di rilevanza come indicato dalla traccia (D3=3, D1=0, D5=0, D7=0, D9=2, D8=3).
$$G = (3, 0, 0, 0, 2, 3)$$
**2. Calcolo progressivo del DCG** Applichiamo la formula ricorsiva del DCG che sconta e cumula i punteggi:
$$DCG[i] = \begin{cases} G[i] & \text{se } i = 1 \\ \frac{G[i]}{\log_2 i} + DCG[i-1] & \text{se } i > 1 \end{cases}$$

Passaggi posizione per posizione, riflettendo esattamente quanto scritto negli appunti del professore:
- **Pos 1 (D3, punteggio 3):** $3$
- **Pos 2 (D1, punteggio 0):** $0 + 3 = 3$
- **Pos 3 (D5, punteggio 0):** $0 + 3 = 3$
- **Pos 4 (D7, punteggio 0):** $0 + 3 = 3$
- **Pos 5 (D9, punteggio 2):** Scontiamo il valore e sommiamo il cumulato precedente: 
	$\frac{2}{\log_2 5} + 3$
- **Pos 6 (D8, punteggio 3):** Scontiamo il valore e aggiungiamo il totale cumulato precedente: $\frac{3}{\log_2 6} + \frac{2}{\log_2 5} + 3$

Il vettore DCG finale è:
$$DCG = \left( 3, \quad 3, \quad 3, \quad 3, \quad \frac{2}{\log_2 5} + 3, \quad \frac{3}{\log_2 6} + \frac{2}{\log_2 5} + 3 \right)$$

ESER fatto da Pasquale:
![[Pasted image 20261030155242.png]]