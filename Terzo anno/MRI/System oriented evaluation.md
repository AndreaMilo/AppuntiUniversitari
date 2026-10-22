Un modo per ovviare al problema dell’utente che non sempre da feedback diretti, oltre i feedback impliciti, un altro modo per captare più informazioni è lo **pseudo-relevance** feedback, che assume che i primi k risultati di una query siano rilevanti e i restanti no. 

Nel processo di relevance feedback c’è un altro processo, ovvero quello di **query expansion**. Nella relevance feedback, le informazioni in più erano dati ai risultati ottenuti da una query esplorativa, nella query expansion, le informazioni aggiuntive vengono inserite nelle query, ad esempio con l’uso di parole più specifiche. Un esempio sono i query assistance dei browser, che generalmente sono ottenuti da query passate proprie o di altri utenti, a cui viene applicato un ulteriore sistema di ranking (proprio come per i documenti) per mostrarle all’utente.

 Le sorgenti di query expansion sono:

- dizionari
- analisi globale di tutti i documenti all’interno della collezione (effettuando una moltiplicazione tra la matrice dei termini T e quella dei documenti D, ottenendo una matrice M; effettuando la trasposta di M, e moltiplicandola per M iniziale si otterrebbe la matrice termini termini, che, detto in breve, mette in corrispondenza parole simili).
- analisi dei documenti ottenuti come risultato

Un altro esempio di query expansion è quello Thesaurus-based, che aggiunge parole relative a quelle inserite nella query iniziale. Usata in ambiti scientifiche, potrebbe tuttavia aumentare l’imprecisione in caso di parole ambigue, oltre che avere alti costi di produzione e modifica.

## Valutazione dei Sistemi di Ritrovamento

C’è la necessità di capire quali sono i sistemi di ritrovamento migliori in base alle necessità che si hanno (quali operazioni di preprocessing fare, sistemi di ranking più adatti, schema di pesatura migliore, ecc..).

L’efficacia di un sistema è legato alla rilevanza, il quale è però un parametro sfumato, difficile da valutare in modo empirico.

Storicamente, la valutazione dei sistemi per il ritrovamento delle informazioni nasce grazie agli studi di Cyril Cleverdon, un bibliotecario presso il Cranfield College of Aeronautics. Nel 1952, Cleverdon usando Uniterm, un sistema di indicizzazione, e con l’aiuto di Bob Thorne, condusse un esperimento sulla valutazione dei sistemi di indicizzazione, che gli permisero grazie ad una sovvenzione del Nation Science Foundation, di poi condurre altri test per compararne diversi, che culminarono con la moderna misurazione della **Precisione**, la percentuale di documenti rilevanti tra quelli restituiti, e il **Richiamo**, ovvero la percentuale dei documenti restituiti tra quelli rilevanti. 

OSSERVAZIONE: si noti che:

- nella maggior parte delle ricerche un alto richiamo non è fondamentale;
- la maggior parte degli utenti necessita di un set limitato di risultati, tra cui sceglierà quelli con un ranking maggiore.

Il primo modo di valutare l’efficienza è il Cranfield Paradigm, che valuta la rilevanza intesa come rilevanza dal punto di vista dell’argomento, ovvero considera i documenti che contengono informazioni sullo stesso argomento della query. Quando viene implementato un motore di ricerca, si associano a delle query un set di documenti che sappiamo essere pertinenti, cosicchè per query future il sistema sappia quale documenti associare. Gli step adottati per calcolare l’efficienza di questo sistema è:

![lez21_image.png](lez21_image.png)

Un altro metodo è quello del Test Collection: partendo da un corpus di documenti, si selezionano delle informazioni da ottenere, le quali saranno ottenute da un umano che manualmente dovrà assegnare delle etichette ai documenti rilevanti ciascuna informazioni necessaria (richiede troppo effort).

**Principali Collezioni di Test**
• **TREC:** Iniziativa del NIST attiva dal 1992 che fornisce un vasto ambiente di test con circa 1 milione di documenti tramite workshop annuali.   
• **Origini:** L'idea di una collezione "ideale" fu proposta da Karen Sparck Jones negli anni '70 e implementata nel progetto TREC seguendo il paradigma di Cranfield.   
• **ClueWeb09:** Dataset massiccio per il Web track contenente oltre 1 miliardo di pagine web in 10 lingue.   
• **Archivi Storici:** Includono benchmark precedenti come ISILT, UKCIS e MEDLARS. 

**Metodologia e Giudizio Umano**
• **Task Specifici:** Benchmark come la collezione Reuters definiscono precisi "compiti di recupero", spesso sotto forma di query predefinite.   
• **Etichettatura Manuale:** Gli esperti umani valutano i risultati contrassegnando esplicitamente ogni documento come "Rilevante" o "Non rilevante" per la query associata.   
• **Tecnica del Pooling:** Per gestire enormi moli di dati, l'etichettatura viene effettuata solo su un sottoinsieme di documenti (pool) effettivamente recuperati dai vari sistemi analizzati.   

### Precision and Recall

Si consideri una collezione di documenti. Si suddividano poi le collezione test di documenti rilevanti e la collezione dei documenti ritrovati da una query (sottoinsiemi della collezione di partenza).

![image.png](lez21_image%201.png)

Se fossero disgiunti, il motore di ricerca avrebbe fallito. Al contrario se fossero sovrapposti, sarebbe perfetto. Tipicamente questi stati sono irraggiungibili, la situazione più comune è infatti quella riportata, ovvero insiemi intersecati.

Uno scenario del genere ci mette a quattro situazioni possibili:

- documenti irrilevanti e non restituiti (True Negative - TN)
- documenti irrilevanti e restituiti (False Positive - FP) (rumore, errore)
- documenti rilevanti e non restituiti (False Negative - FN) (effetto silenzio, anch’esso considerabile come errore)
- documenti rilevanti e restituiti (True Positive - TP)

In base al numero di questi documenti si possono calcolare:

$precision = \frac{numero\ documenti\ rilevanti\ restituiti}{numero\ totale\ di\ documenti\ restituiti}$

ovvero l’abilità del restituire i documenti più rilevanti rilevanti. Equivale alla probabilità condizionata P(rilevanti | restituiti). E:

$recall = \frac{numero\ documenti\ rilevanti\ restituiti}{numero\ totale \ di \ documenti \ rilevanti}$

l’abilità del trovare tra tutti i documenti, tutti quelli rilevanti, che corrisponde alla probabilità condizionata P(restituiti | rilevanti).

Queste due metriche non sono sensibili al ranking.

Un esempio di sistema ad alta precisione è uno che restituisce pochi risultati, al 100% rilevanti. Uno di un sistema con alto richiamo è uno che tra 200 risultati ne ha 10 non utili.

OSSERVAZIONE: il richiamo è una funzione non decrescente rispetto al numero i documenti ritrovati, il che vuol dire che se aumento il numero di documenti nella collezione, al massimo il recall rimane costante o aumenta; per quanto riguarda la precisione, invece, questa diminuirà all’aumentare del recall o all’aumentare dei documenti restituiti.

ATTENZIONE: l’osservazione precedente non è un teorema ma una osservazione empirica!

La precisione è tendenzialmente facile da calcolare a differenza del recall, a causa della difficoltà di stimare in grandi collezioni di documenti quanti siano i documenti rilevanti.

Idealmente i documenti si comportano così:

![image.png](lez21_image%202.png)

[DA QUI]
Di questa metrica abbiamo due misure, o eccellere nella precision o eccellere nella recall.
Un vincolo da superare è quello che le metriche non possono essere solo totalmente positive o totalmente negative, ma avere più scale di grigi

Per mettere un unico valore al sistema che divide tra precision e recall, facciamo la media matematica
Usare la media aritimetica però è errato e non utilizzabile perché avere 50 di recall e 50 di precision ci da una media del 50 pari ad una media in cui il recall è 10 e 90 la percision. Così statistiamente entrambi saranno messi al pari quando armonicamente non è così

Usiamo quindi la media armonica, la media armonica è alta solo se entrambi gli elementi sono alti, e si esprime come segue:
![[Pasted image 20261022162648.png]]

Questa metrica è chiamata $F_{1}$ ed è una generalizzazione della $F_{BETA}$ dove BETA è un parametro che da +- precisione al richiamo e alla precisione, e la formula segue come tale:
![[Pasted image 20261022162924.png]]
ma ormai si usa F1 poiché più basilare.
- Se beta è = 1 c'è un equità tra i due campi
- Se beta è >1 abbiamo più recall
- Se beta <1 abbiamo più precisione
- Se beta = 0 F_beta = P
E misura = 1-F_beta
### Evaluating ranked results
Possiamo insirire i dati dei documenti rilevanti su un grafico per una query eseguita tante volte e dal grafico poi possiamo evincerne la curva dell'andarmento tra l'incremento del recall.
![[Pasted image 20261022163941.png]]
![[Pasted image 20261022163946.png]]

Se volessimo calcolarlo su tante query e non più su una sola avremo mille valori di F1 e per decidere la performance di quel sistema, basta fare la media artimetica.
Per cofrontare la performance del motore di ricerca su tutte le query l'utile sarebbe avere tanti grafici diversi e gestirlo tramite riferimenti che vanno coi valori standard di recall che vanno da 0 a 11.
E' come avere il grafico di una funzione dove si conoscono alcuni valori della funzione ma non tutta la funzione e si vuole approssimare la funzione così da approfondirla negli altri punti, quindi si esegue l'**interpolazione**.

