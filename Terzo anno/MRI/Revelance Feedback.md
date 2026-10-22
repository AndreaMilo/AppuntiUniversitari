Una parte importante nello studio della rilevanza è il **relevance feedback**, ovvero la possibilità che l’utente segnali come rilevante o meno un set di risultati cosicché il sistema possa rielaborare una query includendone il feedback. Il relevance feedback può passare attraverso una o più iterazioni: poiché è difficile formulare subito una buona query se non si conosce bene la collezione, si procede in modo iterativo.

Il processo di modifica della query è detto:

- **relevance feedback** quando l’utente dà informazioni sulla rilevanza dei documenti
- **query expansion** quando delle informazioni legate alla query ne espandono il risultato.

Entrambe verranno dette **metodi di feedback**.

I metodi di feedback possono essere:

- **impliciti** → le informazioni sono derivate dal sistema
- **espliciti** → l’utente fornisce direttamente informazioni

Dato un insieme di documenti, il **centroide** è il documento medio (centro di massa). Essendo i documenti rappresentati come punti (o vettori) all'interno di uno spazio vettoriale multidimensionale, il centroide si otterrà:

![lez19_image.png](lez19_image.png)

Ovvero la somma delle dimensioni diviso il numero di documenti, in pratica la **media**.
### Algoritmo di Rocchio
Si presenta un algoritmo che permette di discriminare i documenti non rilevanti da quelli rilevanti.

Tale algoritmo permette, tramite l’uso del modello a spazio vettoriale, la formulazione di una query che divide i documenti non rilevanti da quelli rilevanti, tramite la formula:

![image.png](lez19_image%201.png)

ove:

- $D_r$ è il set di documenti rilevanti tra i documenti recuperati
- $N_r$ è il numero di documenti nel set $D_r$
- $D_n$ è il set di documenti non rilevanti tra i documenti recuperati
- $N_n$ è il numero di documenti nel set $D_n$
- $C_r$ è il set di documenti rilevanti all’interno di tutta la collezione
- $N$ è il numero di documenti dell’intera collezione
- $\alpha, \beta, \gamma$ sono costanti di tuning

In pratica calcola la differenza tra il centroide dei documenti rilevanti e il centroide dei documenti non rilevanti.

Il problema è che realisticamente, all’interno di un sistema di Information Retrieval (o motore di ricerca), non sappiamo a priori qual è il set di documenti rilevanti dell'intera collezione ($C_r$). Per ovviare a questo problema si potrebbe formulare una query iniziale e pian piano incrementare il vettore query.

![image.png](lez19_image%202.png)

Si giunge quindi a questa formula, ovvero l’algoritmo del 1971 di Rocchio (sistema SMART), la quale aggiungerà dei pesi ai documenti ritenuti rilevanti o meno, non più alla collezione totale, ma alla collezione dei documenti ottenuti tramite una query esplorativa iniziale ($q_0$) per ottenere il vettore della query modificata ($q_m$):

![image.png](lez19_image%203.png)

L’uso dei pesi porta alcune accortezze:

- trade-off tra $\alpha$ rispetto a $\beta$ e $\gamma$: in base al numero di documenti giudicati, se ne abbiamo molti si deve cercare di dare un peso maggiore a $\beta$ e $\gamma$
- alcuni pesi nel vettore della query possono diventare negativi: i pesi negativi dei termini vengono ignorati (impostati a 0)
- i feedback positivi (di rilevanza) hanno un effetto maggiore rispetto a quelli negativi (quindi si imposta $\gamma < \beta$, ad esempio $\gamma = 0.25$ e $\beta = 0.75$); molti sistemi consentono solo feedback positivo impostando $\gamma = 0$
- il relevance feedback può migliorare sia la recall che la precision

E anche alcuni problemi:

- query complesse (lunghe) sono inefficienti per un tipico motore di IR
    - tempi di risposta lunghi e costi computazionali elevati
    - SOLUZIONE → si ripesano solo alcuni termini prominenti (ad esempio i primi 20 per frequenza del termine)
- gli utenti spesso sono riluttanti a fornire feedback esplicito
- dopo aver applicato il relevance feedback, è spesso più difficile capire perché un particolare documento sia stato recuperato
- le esigenze informative (information needs) dell'utente possono cambiare durante l'interazione

Vedere esercizio.[AL momento uniba è in down non posso vederlo]
