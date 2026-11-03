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

Vedere esercizio. [Al momento Uniba è in down, non posso vederlo]

Per verificare se effettivamente il Relevance Feedback abbia avuto successo, non basta riprovare il processo di ricerca sull'intera collezione. Il risultato atteso sarebbe migliore ma fittizio poiché, usando la query modificata $q_{m}$ per calcolare il grafico di precision e recall, è normale che il sistema restituisca ai primi posti i risultati appena scelti dall'utente. Per verificare l'effettiva riuscita dobbiamo valutare la capacità di trovare *nuovi* documenti rilevanti che l'utente non abbia mai visto.

Si usa quindi il metodo della **collezione residuale**, ovvero eliminare dalla collezione i documenti precedentemente giudicati e valutare $q_{m}$ su ciò che resta. I numeri assoluti scenderanno (perché abbiamo tolto dalla collezione i documenti rilevanti più "facili" da trovare), ma è un metodo equo per confrontare diverse strategie di feedback tra loro. Infine, nella pratica, fare una sola iterazione di feedback dà ottimi risultati, mentre continuare con una seconda iterazione porta benefici minimi.

Il metodo più onesto, per non incorrere nel risultato fittizio precedentemente descritto, consiste nel dividere a metà la collezione in modo casuale, avendo:
- $q_{0}$ e il feedback dell'utente eseguiti sulla prima metà
- $q_{m}$ eseguita e valutata sulla seconda metà
### Caveat
Matematicamente abbiamo appurato che il relevance feedback funziona, ma attraverso degli studi si è notato che non tutti gli utenti preferiscono inviare il feedback e spuntare le caselle di rilevanza a ogni ricerca eseguita. In termini di fatica e tempo dell'utente, **riscrivere la query modificandola leggermente** a mano risulta un metodo molto più rapido e utilizzato.
### Relevance feedback nel Web
Sul web alcuni motori di ricerca offrono la funzionalità delle *pagine correlate/simili*, ma non tutti la prediligono poiché è complesso farne capire il funzionamento all'utente medio. Un esempio tipico è **Excite**, il quale inizialmente integrava un vero relevance feedback che è stato però eliminato per mancato utilizzo.
Quando un utente clicca su "Pagine simili" accanto a un singolo risultato web, sta dicendo al sistema _"voglio altri documenti uguali a questo"_. Rispetto alla formula di Rocchio, non c'è feedback negativo ($\gamma = 0$), la vecchia query conta pochissimo o nulla ($\alpha = 0$), e tutto il peso è concentrato sull'unico documento selezionato ($\beta = 1$).
### Pseudo relevance feedback
Lo **pseudo relevance feedback** automatizza la parte manuale del relevance feedback. L'algoritmo recupera la lista ordinata (*ranked list*) dei risultati della query dell'utente, dà per scontato che i primi $k$ documenti siano rilevanti ed esegue successivamente su di essi l'algoritmo di Rocchio.

Mediamente questo algoritmo funziona bene, ma non è ottimale per alcune query: ponendo caso che tutti i primi risultati di una query riguardino un *subtopic* specifico, avremo come rilevanza solamente quel sottotema rispetto all'informazione di interesse principale.
Se per sfortuna i primi $k$ risultati non sono rilevanti o parlano tutti di una singola accezione di un termine ambiguo (es. cerco _"Giaguaro"_ inteso come animale, ma i primi 8 risultati parlano dell'automobile _Jaguar_), l'algoritmo estrarrà termini come _"motore", "auto", "prezzo"_. Se facciamo più iterazioni, a ogni ciclo il vettore della query si sposterà sempre più verso le automobili, allontanandosi definitivamente dall'intento originale dell'utente. Questo fenomeno prende il nome di **Query Drift**.
### Feedback Implicito
Il **feedback implicito** si basa sul dare maggiore rilevanza ai link cliccati più spesso dagli utenti: così, a ogni query simile o uguale, verranno ripresentati questi documenti poiché si presume che siano i risultati desiderati e più importanti a livello di peso.

Questo tipo di feedback è usato nei moderni motori di ricerca e sfrutta i **click** per posizionare i link più visitati più in alto nel ranking rispetto all'ordine dettato inizialmente dalla sola query. Questa tecnica, chiamata **clickstream mining**, raccoglie dati a livello globale da milioni di utenti e oggi alimenta direttamente i modelli di Machine Learning che decidono l'ordine dei risultati (*machine-learned ranking*).
### Query Expansion (Espansione della query)
Nel relevance feedback, gli utenti danno un input aggiuntivo (rilevante/non rilevante) sui **documenti**, che viene usato per ripesare i termini nella query. Nella **query expansion**, gli utenti danno un input aggiuntivo (termine di ricerca buono/cattivo) direttamente su **parole o frasi**.

In sintesi, nella Query Expansion si agisce sulle parole e frasi di rilievo aggiungendo sinonimi o termini correlati alla query di partenza, mentre nel Relevance Feedback l'input riguarda i documenti su cui poi viene applicato l'algoritmo di Rocchio.
#### Esempio sulla ricerca delle immagini
Un modo visivo per capire la differenza tra Relevance Feedback e Query Expansion è osservare la ricerca immagini di Google:
![[Pasted image 20261022153313.png]]

- Sotto le fotografie delle bici c'è il tasto *Find similar images*: questo è l'equivalente di esprimere una preferenza sul documento e dare un **relevance feedback** al motore di ricerca.
- In alto invece c'è la dicitura *Related searches*: quella mostra le parole aggiuntive consigliate per migliorare e specificare i termini della ricerca, rappresentando un caso di **query expansion**.
### Query Assist
Il Query Assist non si basa su dizionari fissi ma sul **Query Log Mining**, ovvero sull'analisi delle ricerche eseguite precedentemente dagli utenti, raccomandando query recenti e frequenti che contengono la stringa parziale digitata dall'utente.
Dal punto di vista del **Ranking**, viene gestito proprio come un problema di ordinamento: ogni vecchia query salvata nei log viene trattata come se fosse un *"documento"* e, a ogni lettera inserita in una nuova ricerca, il sistema cerca le query passate che corrispondono alla stringa parziale, ordinandole per popolarità (frequenza) e freschezza (ovvero quanto è recente quella ricerca/notizia).
#### Esempio di Query Assist
L'immagine riportata di seguito mostra come avviene **l'autocompletamento** delle query nelle barre di ricerca:
![[Pasted image 20261022153650.png]]

È un esempio pratico di come i motori di ricerca aiutino l'utente a espandere e completare la query in tempo reale mentre sta ancora scrivendo, guidandolo verso formulazioni più precise.
### Come espandere la query utente
Per espandere una query utente abbiamo tre possibili scelte:
- **Tesauro Manuale:** è un dizionario di sinonimi e termini correlati scritto manualmente da esperti.
- **Analisi Globale (Statica):** si basa sull'analisi di tutti i documenti della collezione o sui log delle ricerche eseguite dagli utenti sul web. Generalmente, se due parole compaiono molto spesso insieme negli stessi documenti o nelle stesse query (*co-occorrenza*), il sistema impara che sono correlate e crea un tesauro automatico.
- **Analisi Locale (Dinamica):** invece di analizzare tutti i documenti nel DB a priori, si analizzano al volo solo i documenti restituiti dalla query appena fatta dall'utente così da estrarre i termini più frequenti in quest'ultima; si basa molto sul concetto dello Pseudo-Relevance Feedback.
### Espansione della query basata su Tesauro
Per ogni termine $t$ in una query, si espande la query con i sinonimi e le parole correlate di $t$ presenti nel tesauro (come *feline $\rightarrow$ feline cat*).

Il **vantaggio** principale del Tesauro è l'aumento della **Recall** (trovare molti più documenti rilevanti che contengono i sinonimi), avendo cura di assegnare un peso inferiore ai termini aggiunti così da non far valere i sinonimi più della parola originale scelta dall'utente.
Tuttavia presenta anche degli **svantaggi**:
- **Crollo della Precision:** il Tesauro non funziona bene con le parole polisemiche (ambigue). Ad esempio, se cerchiamo un'espressione come *"interest rate"* (tasso d'interesse), il tesauro potrebbe analizzare separatamente le parole *interest* e *rate*, espandendole con significati fuori contesto (come *fascinate* ed *evaluate*) e restituendo risultati totalmente fuori tema.
- **Costi:** creare manualmente un tesauro è molto dispendioso poiché richiede il lavoro di team di esperti; inoltre il linguaggio e le scienze sono in costante evoluzione, quindi il tesauro deve essere costantemente aggiornato.
