[Aggiungere la parte precedente alla lezione del 25/11]
[Da qui]
## Tre vettori per ogni token
Da ogni token il modello ricava tre vettori, con trasformazioni apprese dai dati:
- **Query** (Q): ciò che il token cerca negli altri token
- **Key** (K): ciò che il token espone al confronto come le query
- **Value** (V): ciò che il token restituisce a chi lo seleziona

Questi tre vettori funzionano come una **ricerca**: la query è la domanda, la key è la ricerca e il value e il risultato ovvero i documenti.
### Calcolo dell'attention
L'attention si calcola tramite tre step:
- Confronto: prodotto scalare tra query e key di goni token, ogni token ottiene un punteggio
- Pesi: i punteggi vengono trasformati in pesi che sommano ad 1
- Somma: il nuovo vettore di porta è la somma dei value, ognuno moltiplicato per il suo peso

La somma dei velue, pesata coi pesi del **prodotto scalare** (confronto) restituisce l'attention.
Un motore di ricerca restituirà i risultati migliori di questo calcolo.

$$Attention(Q,K,V)=softmax( \frac{Q \times K^T} {{\sqrt{d_{k}}}})$$
## Multi-head attention
Il **Trasformer** non esegue queste operazioni una singola volta, ma più volte in parallelo. QUesto si chiama **Multi-Head Attention**.
Ogni calcolo in parallelo viene chiamata **testa**. Le teste stanno nello stesso strato e i loro risultati si uniscono in un selo vettore per token.
Di solito sono 8 nel paper.

### Rete feed forward
La rete feed forward lavora sul vettore di un token per volta dopo aver calcolato l'attention.
L'attention sposta informazioni tra i token. La rete feed-forward aggiunge ai vettori di un token [Continuare]

# N blocchi in sequenza
Ogni blocco aggiunge un **qualcosa**. Ogni blocco prende dei pattern che il blocco precedente ha perso durante la tokenizzazione. Per interpretare cosa fanno i blocchi bisogna guardare i blocchi più in alto, perché sono più precisi, mentre quelli più in basso (non sempre) esegue controlli più astratti, come la sintassi o la grammatica.
Per questo è importante avere un sistema di blocchi impilato che lavorano sulla stessa ricerca ma con operazioni di controllo differenti.
## Risultati e limiti. Guardare dentro un modello
Un modello reale è nota la struttura esterna ma non quella interna, Per esempio nei modelli di entropic sono molto più complessi di quelli descritti precedentemtne e sono ancora in caso di studio attuale.
### Dal vettore finale alle probabilità sul vocabolario
Si prende il vettore finale (in uscita dal modello) dell'ultimo token d'ingresso e si calcola il punteggio (**logit**) per ogni riga del nostro vocaoblario.
eusti punteggi diventano probabilità tramite la softmax.

Il token da scrivere non ha ancora un vettore, la prevsione si legge dall'ultimo token letto.

Il vocabolario di un LLM è fatto di token, quindi tramite l'ultimo token riusciamo a ipotizzare dei punteggi per i token all'interno del vocabolario.

Come si procede da questo punto in poi?
Ad ogni passo entra tutto il testo scritto finora ad esce solo un token. Oniti token può guarrdare **solo quelli scritti prima di lui**.
La generazione è **autoregressiva**, ovvero il modello prevede il prossimo elemento di una sequenza a partire da quelli che ha già prodotto. La scelta avviene nel modo della parte 6.
Il token scelto si aggiunge in fondo all'igresso e diventa l'ultimo, ripetendo col nuovo ultimo l'operazione e così via.
