**Traccia dell'Esercizio**

  
![[Pasted image 20261030143847.png]]
L'esercizio richiede di calcolare il valore della metrica **nDCG (Normalized Discounted Cumulative Gain)** per una determinata query e di fornirne una breve descrizione. 

I dati forniti sono:
- I documenti rilevanti totali presenti nella collezione sono 4.    
- L'algoritmo di ritrovamento ha restituito il seguente ranking per la query $q$: $R_q$: `1 0 1 0 1`.
    - '1' indica che il documento è rilevante (score di 1).
    - '0' indica che il documento non è rilevante (score di 0).
    - Il risultato più a sinistra è la prima posizione (top della lista).

---

**a) Descrizione della metrica nDCG** Il **nDCG (Normalized Discounted Cumulative Gain)** è una metrica di valutazione che misura l'utilità del ranking restituito da un sistema. Si fonda su tre principi:
1. **Guadagno Cumulato:** Accumula il punteggio di rilevanza dei documenti man mano che si scende nella lista.
2. **Sconto Posizionale (Discounting):** Penalizza i documenti rilevanti che appaiono troppo in basso nel ranking dividendo il loro punteggio per un logaritmo crescente (es. $\log_2 i$), simulando la minor pazienza dell'utente nello scorrere i risultati.
3. **Normalizzazione:** Divide il punteggio reale (DCG) per il punteggio teorico massimo ottenibile (IDCG), producendo un valore finale compreso tra 0 e 1, che permette di confrontare query o sistemi diversi su una scala comune.


**b) Svolgimento metodologico dell'esercizio per la query $q$**
Il vettore di guadagno rappresenta i punteggi assegnati dal sistema ai documenti restituiti. Dato il ranking della traccia $R_q$: `1 0 1 0 1`, il vettore è:
$$G = (1, 0, 1, 0, 1)$$

  

**Discounted Cumulative Gain)** 
La formula ricorsiva per calcolare il DCG applica lo sconto logaritmico e somma i valori precedenti:
$$DCG[i] = \begin{cases} G[i] & \text{se } i = 1 \\ \frac{G[i]}{\log_2 i} + DCG[i-1] & \text{se } i > 1 \end{cases}$$
Applichiamo la formula al vettore $G$, lasciando i termini indicati per mostrare il procedimento:
- Pos 1: $1$
- Pos 2 (score 0): $0 + 1 = 1$
- Pos 3 (score 1): $\frac{1}{\log_2 3} + 1$
- Pos 4 (score 0): $0 + \frac{1}{\log_2 3} + 1 = \frac{1}{\log_2 3} + 1$
- Pos 5 (score 1): $\frac{1}{\log_2 5} + \frac{1}{\log_2 3} + 1$

Il vettore DCG impostato è:
$$DCG = \left( 1, \quad 1, \quad \frac{1}{\log_2 3} + 1, \quad \frac{1}{\log_2 3} + 1, \quad \frac{1}{\log_2 5} + \frac{1}{\log_2 3} + 1 \right)$$

**Definizione del Ranking Ideale ($IG$) e calcolo dell'IDCG**
Per normalizzare la metrica, dobbiamo calcolare quale sarebbe stato il punteggio se l'algoritmo fosse stato perfetto.
Si noti che ci sono due possibili convenzioni per definire $IG$ su i primi 5 slot:

1. **Impostazione svolta a lezione (riordinando i 3 documenti rilevanti recuperati nel ranking `1 0 1 0 1`):**
   $$IG = (1, 1, 1, 0, 0)$$
   Applicando la formula ricorsiva del DCG a questo vettore ideale $IG$, otteniamo l'IDCG scritto negli appunti alla lavagna:
   - Pos 1: $1$
   - Pos 2 (score 1): $\frac{1}{\log_2 2} + 1 = 2$
   - Pos 3 (score 1): $\frac{1}{\log_2 3} + 2$
   - Pos 4 (score 0) e Pos 5 (score 0): il valore cumulato resta $\frac{1}{\log_2 3} + 2$.

   $$IDCG = \left( 1, \quad 2, \quad \frac{1}{\log_2 3} + 2, \quad \frac{1}{\log_2 3} + 2, \quad \frac{1}{\log_2 3} + 2 \right)$$

2. **Impostazione su tutta la collezione (includendo tutti e 4 i documenti rilevanti presenti nella collezione):**
   $$IG = (1, 1, 1, 1, 0)$$
   In questo caso in posizione 4 si aggiunge anche $\frac{1}{\log_2 4} = \frac{1}{2} = 0.5$, ottenendo per le posizioni 4 e 5 il valore $\frac{1}{\log_2 3} + 2.5$.

**Fase 4: Normalizzazione finale (nDCG)**
L'ultimo passaggio richiede di dividere ogni posizione del vettore reale ($DCG$) per la corrispondente posizione del vettore ideale ($IDCG$):
$$nDCG[i] = \frac{DCG[i]}{IDCG[i]}$$

Seguendo l'impostazione 1 vista a lezione, otteniamo il vettore finale:

$$nDCG = \left( \frac{1}{1}, \quad \frac{1}{2}, \quad \frac{\frac{1}{\log_2 3} + 1}{\frac{1}{\log_2 3} + 2}, \quad \frac{\frac{1}{\log_2 3} + 1}{\frac{1}{\log_2 3} + 2}, \quad \frac{\frac{1}{\log_2 5} + \frac{1}{\log_2 3} + 1}{\frac{1}{\log_2 3} + 2} \right)$$

ESER. FATTO DA PASQUALE:
![[Pasted image 20261030152854.png]]

![[Pasted image 20261030152920.png]]