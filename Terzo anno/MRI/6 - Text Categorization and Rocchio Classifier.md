# Text Categorization: Dimensionality Reduction e Classificatore di Rocchio

### Text Categorization

Il classificatore di testi, data la descrizione di una istanza $x \in X$, dove $X$ è lo spazio delle istanze, si occupa di associare ad x categoria $c(x) \in C$, dove $c(x)$ è detta funzione di classificazione il cui dominio è $X$ e il range è $C$, ovvero un insieme finito di categorie.

Un esempio di classificatori di testo è il filtro delle mail, che categorizza le mail in spam o importanti.

Approfondiremo l’argomento tramite machine learning, ovvero istruire una macchina tramite dati già suddivisi in categorie. Un esempio di training è un’istanza $x \in X$
associata alla categoria di appartenenza $c(x)$: $<x,c(x)>$ dove c è una funzione di
classificazione **non nota.**

La macchina dovrà quindi ipotizzare, sulla base degli esempi forniti, una funzione di classificazione che classifichi i documenti come la funzione non nota.

Formalmente: dato un esempio di training *D*, deve trovare una ipotesi di classificazione *h(x)* tale che:

$\forall < x,c(x)> \in D: h(x) = c(x)$

Un buon training è caratterizzato a una buona generalizzazione dei casi di test, così da poter classificare anche qualcosa non appartenente al training set, definendo così un modello generale di classificazione.

Il termine Text Categorization designa l’assegnazione
automatica di una o più categorie a testi scritti in linguaggio naturale.

Formalmente, un problema di TC (Text Categorization) si occupa di approssimare una funzione target $\phi': DxC\to\{T,F\}$, ovvero la funzione di classificazione ignota, con una funzione  $\phi: DxC\to\{T,F\}$ che deve approssimare la prima nel modo più fedele possibile. (*D* è l’insieme dei documenti, *C* è l’insieme delle categorie).

Esistono due tipi di problemi di classificazione:

- **Single Label** → ogni documento può essere associato ad una sola classe.
    - Rientrano i tipi binari, ovvero che ti dicono se un documento rientra o meno in una categoria
- **Multi Label** → ogni documento è categorizzabile da più etichette.

E’ possibile ricondurre ogni problemi multi label ad una serie di problemi single label binari.

Ci sono diversi modi per addestrare i sistemi:

- **Apprendimento supervisionato** → tutto il training set è categorizzato
- **Apprendimento non supervisionato** → il training set non è categorizzato
- **Apprendimento semi-supervisionato** → il training set categorizzato è affiancato da una più vasta mole di dati non categorizzati

Considerando l’insieme dei documenti $D$, possiamo fare una suddivisione in 2 sottoinsiemi:

- *Training Set (Tr)*
- *Test Set (Te)*

→ $D = Tr \cup Te$

>[!WARNING] ATTENZIONE: 
>Tr e Te devono essere insiemi disgiunti (non ci devono quindi essere documenti in comuni), altrimenti l’addestramento sarà detto viziato.

Come detto è necessario che il training set sia di qualità; perciò meglio un training set molto ampio o ridotto?
Avendo un training set ridotto si correrebbe il rischio di avere un training set poco generale, tuttavia anche un training set molto ampio non porterebbe molti benefici, anzi. Infatti si corre il rischio di **overfitting**, ovvero il sistema di classificazione sarebbe troppo legato agli esempi, e quindi incapace di ipotizzare una vera funzione di classificazione. Per valutare un **classifier** è quindi necessario l’uso del Test Set (*te*) ovvero un insieme di oggetti non presenti nel Training Set (*tr*) con il quale valutare la correttezza dell’approssimazione.

Ai fini di poter operare sul test set è necessario, ricordando che gli elaboratori non comprendono le parole, fornire una sua codifica, pertanto anche qui verrà effettuata l’indicizzazione. Ogni documento verrà quindi rappresentato come un insieme di pesi che indicano la presenza o la frequenza di parole tratte da un insieme di frasi o dalle parole stesse (tipicamente si usa il bag of words, ma in alternativa vengono usate frasi denotate sintatticamente, ovvero frasi vere e proprie, o statisticamente, insiemi di parole che vengono spesso usati assieme (come pesce fa derivare salmone, o sushi si va a pensare al nigiri)). Tali pesi avranno valori nell’intervallo $[0,1]$ oppure binari ($0$ o $1$).

Anche qui si usa il *tfidf* per il calcolo dei pesi:

![[imLez16.png]]

Come detto però, abbiamo bisogno che i valori ricadano nel range $[0,1]$ e quindi usiamo la normalizzazione del coseno (dato che può avere solo valori da $0$ a $1$):

![[imLez16_1.png]]

- T → insieme dei termini che compaiono almeno una volta nel Tr

Trattandosi sempre di indicizzazione anche qui vengono prima rimossi articoli, stopwords e parole non inerenti rispetto ai topic in esame. Tuttavia risulta controverso l’uso dello **stemming** che ricordiamo accomunare ad una stessa radice, parole totalmente slegate.

Come detto, un ampio training set può portare all’overfitting, quindi uno spazio dei termini troppo elevato va ridimensionato (**dimensionality reduction**). Per fare ciò abbiamo bisogno di algoritmi di riduzione, che possono essere:

- **locali** → per ogni categoria verrà indicato un insieme di termini
- **globali** → il set di termini selezionato è valido per ogni categoria

Inoltre la riduzione può avvenire per:

- **selezione**
- **estrazione**

Alcuni algoritmi per la dimensionality reduction per selezione sono:

>[!NOTE] Selezionato
>selezionato = lascia come training set finale da comprendere

- **TSR** (Term Space Reduction) → viene selezionato un sotto-insieme
dell’insieme dei termini che massimizzi la effectiveness al momento della indicizzazione.
- **Wrapper** → partendo da un insieme di termini applica l’algoritmo di learning a sotto-insiemi di termini ottenuti eliminando un termine per volta, fino ad ottenere la effectiveness massima.
- **Filtering** → seleziona un sotto-insieme dei termini in accordo ai valori forniti da una funzione che misura ***l'importanza*** dei termini nel processo di categorizzazione (applicato prima della fase di learning)

Alcune funzioni usate per la selezione sono:

![[imLez16_2.png]]

### Metodi di Costruzione

E’ possibile usare le nozioni di Relevance Feedback anche per il text categorization: i documenti vengono valutati come vettori di pesi tfidf, normalizzati tramite frequenza massima dei termini, per ogni categoria si calcola un vettore prototipo, ad ogni vettore prototipo si assegnano dei documenti di testing in base alla misura della similarità.

Un esempio di categorizzatore che fa uso del relevance feedback è il classificatore di **Rocchio**, come già visto nel Relevance Feedback. Ricordando che il relevance feedback di Rocchio modifica la query producendone una nuova che meglio approssima l’interesse dell’utente, il classificatore di Rocchio interpreta il training set come feedback information, le parole che appartengono ai documenti facenti parte del training set categorizzati in una certa classe $c_p$ hanno feedback positivo; parole che appartengono ai documenti facenti parte del training set non categorizzati in una certa classe $c_p$ hanno feedback negativo. Tutti i feedback vengono poi sintetizzati tramite un **vettore centroide** (vettore delle medie).

Ogni documento viene interpretato come un vettore di pesi:

![[imLez16_3.png]]

- $w_{i,j}$ → peso della parola $k_i$ nel documento $d_j$
- $t$ → dimensione del vocabolario

Per ogni classe viene quindi poi calcolato un centroide ottenuto così:

![[imLez16_4.png]]

dove:

- $n_p$ → numero dei documenti nella classe $c_p$
- $N_t$ → numero totale di documenti nel training set
- $\beta \text{ e } \gamma$ → parametri per valutare l’importanza

La formula, spiegata a parole, calcola il centroide dei documenti appartenenti alla classe (feedback positivi) ed il centroide dei documenti non appartenenti alla classe (feedback negativi), e li sottrae. 

Per classificare i documenti, infine, si associano ad essi (ricordando che sono interpretati come vettori di pesi) i centroidi delle classi (vettori prototipo) con più alta misura di similarità (come quella del coseno, vedere Laboratorio).

E’ possibile calcolare il vettore prototipo anche solo usando documenti del training set appartenenti alla classe interessata.

**Osservazioni sull’algoritmo di Rocchio:**
- non garantisce un’ipotesi consistente
- il vettore prototipo è una semplice generalizzazione di una classe
- la classificazione si basa sulla similarità tra i documenti e il vettore prototipo
- non necessita di normalizzazioni perché la similarità del coseno non è influenzata dalla lunghezza