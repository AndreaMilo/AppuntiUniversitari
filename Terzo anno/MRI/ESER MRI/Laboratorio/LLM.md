[Aggiungere la parte precedente alla lezione del 25/11]
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

