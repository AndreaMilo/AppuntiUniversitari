# Introduzione
Nello studio teorico dei sistemi di **Information Retrieval (IR)** abbiamo analizzato l'intera architettura concettuale necessaria per indicizzare e recuperare informazioni da collezioni di testi non strutturati:
- La fase preliminare di **Text Operations** (tokenizzazione, rimozione delle _stopword_, normalizzazione e _stemming_) per trasformare il testo grezzo in token.
- La costruzione dell'**Indice Invertito (_Inverted Index_)**, composto dal dizionario dei termini e dalle rispettive _posting list_, per evitare scansioni sequenziali.
- I modelli di reperimento e pesatura, passando dal **Modello Booleano** (basato su presenza/assenza binaria) al **Modello a Spazio Vettoriale (_Vector Space Model - VSM_)**, in cui documenti e query sono vettori pesati tramite **TF-IDF** e confrontati per rilevanza producendo un ranking ordinato (_top-$k$_).

Passando dalla teoria alla progettazione software reale, costruire da zero tutte queste componenti (gestione su disco dell'indice invertito, algoritmi di parsing, strutture dati compresse e funzioni di scoring) richiederebbe uno sforzo ingegneristico enorme. Per questo motivo, nello sviluppo pratico si ricorre ad **Apache Lucene**, la libreria open-source di riferimento che traduce fedelmente ciascun blocco teorico dell'architettura di un sistema di IR in specifiche classi Java pronte all'uso, introducendo inoltre modelli di ranking evoluti come **Okapi BM25** per superare i limiti classici della pesatura TF-IDF.

  

# Accesso alle informazioni con Apache Lucene
**Apache Lucene** è un progetto open-source che fornisce gli strumenti fondamentali per l'indicizzazione e la ricerca del testo.
Per comprendere correttamente il suo ruolo architetturale, è fondamentale distinguere cosa Lucene è e cosa invece non è:
- **Che cos'è Lucene:** è una **libreria di ricerca**, ovvero un insieme di **API (_Application Programming Interface_)** per l'indicizzazione e la ricerca del testo.
- **Che cosa nn è Lucene:** **non è un motore di ricerca** pronto per l'utente finale; non include quindi moduli per fare scaricare pagine dal web, non è un server web e non possiede una interfaccia grafica utente.

Le **caratteristiche principali** sono:
- **Full-text search:** supporto completo alla ricerca testuale avanzata.
- **High performance e Scalable:** altissime prestazioni ed elevata scalabilità anche su grandi volumi di dati.
- **Cross-platform e 100%-pure Java:** è scritto interamente in linguaggio Java ed è quindi multipiattaforma.
- **Porting in altri linguaggi:** oltre alla versione nativa Java, esistono porting ufficiali e non ufficiali per i principali linguaggi di programmazione.

![[Pasted image 20261105165326.png]]

|**Componente Teorico IR**|**Classe / Componente in org.apache.lucene**|**Ruolo nel Processo**|
|---|---|---|
|**Doc** (Documento grezzo)|**`Document`**|Rappresenta il documento strutturato in campi da indicizzare.|
|**Text Operations**|**`Analyzer / Tokenizer / Filter`**|Esegue il pre-processing del testo (sia sui documenti che sulle query) generando la vista logica (_Logic view_).|
|**Indexing**|**`IndexWriter`**|Riceve i documenti analizzati e scrive/aggiorna fisicamente l'indice invertito su disco.|
|**Index** (_Inverted Index_)|**`Index`** + **`IndexReader`**|La struttura dati dell'indice invertito; viene aperta e letta tramite la classe `IndexReader`.|
|**Query Operations**|**`QueryParser`**|Riceve la stringa di ricerca ed elabora l'oggetto `Query` applicando gli stessi filtri linguistici.|
|**Searching**|**`IndexSearcher`**|Esegue materialmente la ricerca della `Query` sull'indice (tramite `IndexReader`) estraendo i documenti pertinenti.|
|**Ranking**|**`Similarity`**|Calcola lo _score_ di rilevanza dei documenti recuperati per restituire la lista ordinata (_Ranked documents_).|
![[Pasted image 20261105165520.png]]
> [!WARNING] Confini di Lucene nello schema architetturale
> 
> Si nota che i blocchi **User Interface** (l'interfaccia con cui interagisce l'utente) e **User feedback** rimangono **fuori** dal perimetro della libreria: spetta infatti allo sviluppatore costruire l'applicazione esterna che raccoglie la query dall'utente e mostra a schermo i risultati restituiti da Lucene.
> 
>   

## Document
Un `Document` non è un semplice blocco di testo indistinto, ma è modellato come una **collezione di campi (`Fields`)** che conferiscono una struttura ben precisa al documento stesso.
![[Pasted image 20261105165740.png]]
Ogni singolo **`Field`** è costituito da **tre parti fondamentali**:
1. **Name (Nome):** l'identificativo del campo (es. `"title"`, `"author"`, `"content"`).
2. **Type (Tipo):** definisce come il campo deve essere trattato, indicizzato e memorizzato dal sistema.
3. **Value (Valore):** il contenuto effettivo del campo, che può appartenere a tre tipologie di dato:
    - **text (testuale):** rappresentato da una `String`, un flusso `Reader` oppure un `TokenStream` già pre-analizzato.
    - **binary (binario):** rappresentato da un array di byte (`byte[]`).
    - **numeric (numerico):** rappresentato da un oggetto `Number` (es. interi o decimali).

Ogni campo creato deve essere aggiunto esplicitamente all'oggetto `Document`. Inoltre, per ciascun campo è possibile specificare se debba essere **memorizzato fisicamente nell'indice (`TYPE_STORED`)**, in modo che il suo valore originale possa essere restituito insieme ai risultati (_hits_) quando il documento viene recuperato da una ricerca.

## Overview of the process
![[Pasted image 20261105170837.png]]
L'indicizzazione e ricerca in Apache Lucene si riassume in **4 passi operativi**:
1. **Step 1 creazione del documento:** si crea un oggetto `Document` e si popolano i suoi campi.
2. **Step 2 indicizzazione tramite:** si passano i documenti alla classe **`IndexWriter`** invocando il metodo `addDocument()`, che provvede ad aggiungerli dentro il **Lucene Index**.
3. **Step 3 definizione della qery:** per interrogare l'indice, si definisce un oggetto **`Query`** specificando il campo e il termine cercato (ad esempio `powers:agility`).
4. **Step 4 ricerca tramite `IndexSearcher` e `TopDocs` :** si utilizza la classe **`IndexSearcher`** invocando il metodo `search()` per sottoporre la query all'indice; il metodo restituisce un oggetto **`TopDocs`** contenente i documenti migliori che soddisfano la ricerca.

## HELLO WORLD
Analizzando la classe `uniba.mri.lucene.HelloWorld.java`, la prima operazione consiste nell'aprire la cartella sul file system dove verrà salvato l'indice e nel configurare l'`IndexWriter`:
```java
// Apre una directory dal file system (cartella dell'indice)
FSDirectory fsdir = FSDirectory.open(new File("./resources/documenti_news").toPath());

// Configurazione dell'IndexWriter con lo StandardAnalyzer
IndexWriterConfig iwc = new IndexWriterConfig(new StandardAnalyzer());

// La directory dell'indice viene creata se non esiste, oppure sovrascritta
iwc.setOpenMode(IndexWriterConfig.OpenMode.CREATE);

// Creazione dell'IndexWriter
IndexWriter writer = new IndexWriter(fsdir, iwc);
```
Con il metodo `iwc.setOpenMode(...)` possiamo decidere come gestire la cartella dell'indice:
- **`CREATE`:** crea un nuovo indice da zero; se nella cartella esisteva già un indice precedente, lo **sovrascrive** cancellando i vecchi dati.
- **`APPEND` (o `CREATE_OR_APPEND`):** non cancella l'indice esistente, ma **aggiunge in coda** i nuovi documenti a quelli già presenti nella directory.

Una volta aperto l'`IndexWriter`, si istanzia il `Document`, si aggiungono i campi e si chiude il flusso di scrittura:
```java
// Creazione del documento e aggiunta dei campi (Fields)
Document doc = new Document();
doc.add(new TextField("super_name", "Spider-Man", Field.Store.NO));
doc.add(new TextField("name", "Peter Parker", Field.Store.NO));
doc.add(new TextField("category", "superhero", Field.Store.NO));
doc.add(new TextField("powers", "agility, spider-sense", Field.Store.NO));

// Aggiunge il documento all'indice
writer.addDocument(doc);

// Chiude l'IndexWriter (fondamentale per salvare le modifiche)
writer.close();

// Crea un IndexReader per leggere l'indice appena scritto
IndexReader reader = DirectoryReader.open(fsdir);

// Conta il numero di documenti attivi (non cancellati)
int numDocs = reader.numDocs();
System.out.println("Numero di documenti nell'indice: " + numDocs);
```

> [!WARNING] Differenza fondamentale tra `Field.Store.YES` e `Field.Store.NO`
> 
> Il terzo parametro passato al costruttore del campo (`Field.Store`) può assumere il valore **`YES`** oppure **`NO`** e indica se vogliamo memorizzare o meno una copia letterale del contenuto del campo dentro l'indice:
> 
>   
> 
> - Impostare **`Field.Store.NO` NON significa che non possiamo fare ricerche su quel campo!** Il campo viene comunque regolarmente analizzato e inserito nell'indice invertito (quindi le query lo troveranno perfettamente).
>     
>       
>     
> - Significa semplicemente che, una volta trovato il documento, **non possiamo più risalire al testo originale** di quel campo per stamparlo a video.
>     
>       
>     

Lucene mette a disposizione diversi costruttori specifici a seconda della natura del dato da indicizzare:
- **`TextField(String name, String value, Field.Store store)`:** crea un campo di testo libero il cui valore **viene analizzato (tokenizzato)** utilizzando l'analizzatore configurato. È la scelta corretta per titoli, corpi di testo, recensioni o descrizioni su cui fare ricerca per parole chiave (es. `new TextField("title", "Il Signore degli Anelli", Field.Store.YES)`).
- **`StringField(String name, String value, Field.Store store)`:** crea un campo di tipo stringa pura il cui valore **NON viene analizzato (non viene tokenizzato)**, ma viene indicizzato esattamente così com'è come un unico token indivisibile. È ideale per codici identificativi, URL, categorie fisse o nomi esatti (es. `new StringField("author", "J.R.R. Tolkien", Field.Store.NO)`).
- **`NumericDocValuesField(String name, long value)` / `NumericField`:** crea un campo numerico (intero, `long`, `float` o `double`) che viene indicizzato per supportare ricerche o ordinamenti numerici (es. `new NumericField("publicationYear", 1954, Field.Store.YES)`).
- **`BinaryField(String name, byte[] value, Field.Store store)`:** crea un campo binario progettato per memorizzare file o dati grezzi non testuali.
- **`Field(String name, String value, FieldType fieldType)`:** costruttore generico che permette di definire un tipo di campo completamente personalizzato tramite un oggetto `FieldType`.

### Aggiunta di documenti 
Per inserire i documenti nell'indice tramite `IndexWriter`, oltre al metodo singolo `addDocument(doc)`, esiste il metodo `addDocuments(docs)`:
- **`addDocument(Iterable<? extends IndexableField> doc)`:** aggiunge un singolo documento all'indice.
- **`addDocuments(Iterable<? extends Iterable<? extends IndexableField>> docs)`:** aggiunge in modo **atomico** un intero blocco di documenti assegnando loro dei `docID` sequenziali, garantendo che un eventuale lettore esterno (`IndexReader`) veda tutti i documenti del blocco oppure nessuno.

Come mostrato nella classe `uniba.mri.lucene.AddMultipleDocs.java`, si procede inserendo i vari oggetti `Document` dentro una `ArrayList<Document>` e passandoli in un colpo solo al writer:
```java
List<Document> docs = new ArrayList<>(); // Salviamo i documenti in un ArrayList

Document doc1 = new Document();
doc1.add(new TextField("title", "Alice in Wonderland", Field.Store.YES));
doc1.add(new TextField("content", "A girl falls into a rabbit hole.", Field.Store.YES));
docs.add(doc1);

Document doc2 = new Document();
doc2.add(new TextField("title", "Through the Looking-Glass", Field.Store.YES));
doc2.add(new TextField("content", "Alice steps through a mirror.", Field.Store.YES));
docs.add(doc2);

Document doc3 = new Document();
doc3.add(new TextField("title", "Alice in Quantumland", Field.Store.YES));
doc3.add(new TextField("content", "A journey through the quantum world.", Field.Store.YES));
docs.add(doc3);

// Aggiunge tutti i documenti in un colpo solo in modo atomico
writer.addDocuments(docs);

// Forza il commit (scrittura fisica) dei dati su disco
writer.commit();
```

## Il Modello di Ricerca di Lucene e la Funzione di Scoring Okapi BM25
### Dal Vector Space Model a Okapi BM25 
Il modulo di ricerca (_Searcher_) di Apache Lucene si fonda concettualmente sul **Modello a Spazio Vettoriale (_Vector Space Model - VSM_)**:
- Ogni documento della collezione ($D_1, D_2, D_3, \dots$) è rappresentato come un **vettore** di occorrenze dei termini nello spazio multidimensionale.
- Anche la **query ($Q$)** dell'utente viene rappresentata come un **vettore** all'interno dello stesso spazio geometrico.

|**Termine \ Vettore**|**D1**|**D2**|**D3**|**Q (Query)**|
|---|---|---|---|---|
|**Cheshire Cat**|1|0|1|0|
|**Alice**|2|2|2|1|
|**book**|1|0|0|0|
|**King**|1|1|0|0|
|**table**|0|1|1|0|
|**Queen**|0|1|1|1|
|**grin**|0|0|2|0|

Tuttavia, sorge una domanda fondamentale: **come viene calcolata esattamente la rilevanza (lo _score_) nelle versioni moderne di Lucene?**
- Nelle versioni attuali di Lucene, il calcolo della rilevanza non usa più la formula classica del TF-IDF puro, ma si basa sulla funzione di scoring **Okapi BM25** (_Best Matching 25_).
- **Perché si usa BM25?** Perché **BM25 migliora lo score di similarità classico basato su TF-IDF** introducendo **due nuovi parametri** di regolazione ($k_1$ e $b$) pensati per risolvere due noti difetti del TF-IDF tradizionale:
    1. Un parametro (**$k_1$**) per gestire il **problema della "saturazione" della Term Frequency (TF)**.
    2. Un parametro (**$b$**) per gestire in modo flessibile il **problema della lunghezza del documento (_document length_)**.

### La Formula di Okapi BM25 nel dettaglio
Dato un documento $D$ e una query $Q$ composta dai termini $q_i$, la funzione di scoring **Okapi BM25** implementata in Lucene calcola il punteggio $\text{Score}(D, Q)$ attraverso la seguente formula:
$$\text{Score}(D, Q) = \sum_{i \in Q} \underbrace{\text{IDF}(q_i)}_{\text{IDF score}} \cdot \underbrace{\frac{tf(q_i, D) \cdot (k_1 + 1)}{tf(q_i, D) + k_1 \cdot \left(1 - b + b \cdot \frac{\vert{}D\vert{}}{\text{avgdl}}\right)}}_{\text{TF score normalizzato}}$$

Analizziamo tutti gli elementi che compongono la formula:
- **$\text{IDF}(q_i)$ (_IDF score_):** misura come sempre la rarità e il potere discriminante del termine $q_i$ della query all'interno dell'intera collezione di documenti.
- **$tf(q_i, D)$:** è la frequenza grezza (_Term Frequency_), ovvero il numero di occorrenze del termine $q_i$ nel documento $D$.
- **$\vert{}D\vert{}$ e $\text{avgdl}$:** $\vert{}D\vert{}$ indica la lunghezza del documento corrente $D$ (in numero di parole/token), mentre $\text{avgdl}$ (_average document length_) è la **lunghezza media dei documenti** in tutta la collezione.
- **$k_1$ (_Saturation parameter_):** è il parametro che controlla la saturazione della frequenza del termine.
- **$b$ (_Length normalization parameter_):** è il parametro che pesa l'impatto della lunghezza del documento.

### 1. Il Parametro di Saturazione $k_1$ (_Saturation Parameter_ )
Per capire il ruolo del parametro **$k_1$**, partiamo da una riflessione intuitiva sul TF-IDF classico:
- Supponiamo che un termine compaia $5$ volte in un primo documento ($tf(x_1, D) = 5$) e $10$ volte in un secondo documento ($tf(x_2, D) = 10$).
- Se usassimo una relazione lineare, il secondo documento risulterebbe **esattamente due volte più importante** del primo. _Ma questa interpretazione è corretta? La relazione tra il numero di occorrenze e l'importanza deve davvero crescere all'infinito in modo lineare?_
- Ovviamente **no**: dopo che una parola è già comparsa 5 o 10 volte in un testo, sappiamo già che il documento parla di quell'argomento; trovarla ripetuta 50 o 100 volte non rende il documento 10 o 20 volte più pertinente.

Il **parametro di saturazione $k_1$** serve proprio a **ridurre l'importanza marginale di $tf$** imponendo un tetto massimo asintotico:
- **Valori bassi di $k_1$ = saturazione rapida (_quick saturation_):** bastano pochissime occorrenze del termine per raggiungere quasi il punteggio massimo, dopodiché ogni nuova occorrenza aggiuntiva incrementa il punteggio in modo trascurabile.
- **Valori alti di $k_1$ = saturazione lenta:** il contributo di $tf$ continua a crescere più a lungo all'aumentare delle occorrenze.

#### Analisi matematica e numerica del contributo TF al variare di $k_1$ 
Per isolare l'effetto di $k_1$, supponiamo che il documento abbia una lunghezza esattamente pari alla media della collezione ($\frac{\vert{}D\vert{}}{\text{avgdl}} = 1$, per cui tutta la parentesi legata a $b$ vale $1 - b + b \cdot 1 = 1$). In questo caso il contributo della Term Frequency si semplifica in:

$$\text{TF contribution} = \frac{tf \cdot (k_1 + 1)}{tf + k_1}$$
Si noti che, quando $tf$ cresce enormemente ($tf \to \infty$), il $+ k_1$ al denominatore diventa trascurabile e il rapporto $\frac{tf \cdot (k_1 + 1)}{tf}$ tende al **valore massimo teorico (asintoto orizzontale) pari a $k_1 + 1$**! In Apache Lucene, **il valore di default è impostato a $k_1 = 1.2$** (il che significa che il contributo massimo possibile del TF non potrà mai superare $1.2 + 1 = \mathbf{2.2}$, anche se la parola comparisse un milione di volte).

La tabella e il grafico mettono a confronto i valori numerici ottenuti per $tf = 5$ e $tf = 10$ con tre diverse scelte di $k_1$ ($0.5$, $1.2$ e $2$):  

|**Valore di k1​**|**Valore Massimo (tf→∞)**|**Calcolo per tf=5 (Num / Den)**|**Valore a tf=5**|**Calcolo per tf=10 (Num / Den)**|**Valore a tf=10**|
|---|---|---|---|---|---|
|**$0.5$**|**$1.5$**|$\frac{5 \cdot 1.5}{5 + 0.5} = \frac{7.5}{5.5}$|**$1.364$**|$\frac{10 \cdot 1.5}{10 + 0.5} = \frac{15}{10.5}$|**$1.429$**|
|**$1.2$ (Default Lucene)**|**$2.2$**|$\frac{5 \cdot 2.2}{5 + 1.2} = \frac{11}{6.2}$|**$1.774$**|$\frac{10 \cdot 2.2}{10 + 1.2} = \frac{22}{11.2}$|**$2.015$**|
|**$2.0$**|**$3.0$**|$\frac{5 \cdot 3.0}{5 + 2.0} = \frac{15}{7.0}$|**$2.143$**|$\frac{10 \cdot 3.0}{10 + 2.0} = \frac{30}{12.0}$|**$2.500$**|
![[Pasted image 20261111122244.png]]

**Osservazione sul grafico di saturazione**
Guardando le tre curve del grafico (rossa per $k_1 = 0.5$, blu per il default di Lucene $k_1 = 1.2$, verde per $k_1 = 2$), si vede chiaramente che raddoppiando le occorrenze da $tf = 5$ a $tf = 10$ il punteggio **non raddoppia affatto**:
- Con $k_1 = 0.5$ (curva rossa, saturazione rapidissima), a $tf = 5$ siamo già a $1.364$ (vicinissimi al tetto massimo di $1.5$), e raddoppiando le occorrenze a $tf = 10$ si sale appena a $1.429$.
- Con il default di Lucene $k_1 = 1.2$ (curva blu), passando da $tf = 5$ a $tf = 10$ il punteggio passa in modo bilanciato da $1.774$ a $2.015$, avvicinandosi gradualmente alla soglia massima di $2.2$.
### 2. Il Parametro di Normalizzazione della Lunghezza $b$ (_Length Normalization Parameter_ )
Il secondo parametro introdotto da BM25 è **$b$** (compreso nell'intervallo $[0, 1]$, con valore di default tipico pari a $0.75$), che pesa l'importanza della **lunghezza del documento** nel processo di recupero confrontando la lunghezza del documento $\vert{}D\vert{}$ con la lunghezza media della collezione $\text{avgdl}$ attraverso il rapporto $\frac{\vert{}D\vert{}}{\text{avgdl}}$:
$$\text{Denominatore} = tf(q_i, D) + k_1 \cdot \left(1 - b + b \cdot \frac{\vert{}D\vert{}}{\text{avgdl}}\right)$$

**Qual è l'intuizione alla base di $b$?** Se una parola chiave compare molte volte all'interno di un documento **lunghissimo** (ad esempio un intero libro di 500 pagine), quelle occorrenze sono molto meno significative rispetto a trovare quello stesso numero di occorrenze concentrato in un documento **molto breve** (ad esempio un articolo di 10 righe).

Vediamo come varia il comportamento della formula agli estremi del parametro $b$:
- **Se $b = 0$ (Nessuna normalizzazione):** il termine $b \cdot \frac{\vert{}D\vert{}}{\text{avgdl}}$ si annulla e la parentesi diventa semplicemente $(1 - 0 + 0) = 1$. La lunghezza del documento viene completamente ignorata.
- **Se $b = 1$ (Valore massimo $\rightarrow$ Massima considerazione della lunghezza):** la parentesi si riduce a $\left(1 - 1 + 1 \cdot \frac{\vert{}D\vert{}}{\text{avgdl}}\right) = \frac{\vert{}D\vert{}}{\text{avgdl}}$, dando il massimo peso possibile alla lunghezza del testo.
- **Perché questo meccanismo penalizza i documenti lunghi e premia quelli brevi?**
    - Se il documento è **più lungo della media** ($\frac{\vert{}D\vert{}}{\text{avgdl}} > 1$), il parametro $k_1$ al denominatore viene moltiplicato per un valore maggiore di $1$: **il denominatore diventa più grande e, di conseguenza, lo score finale della frazione diventa più piccolo** (il documento lungo viene penalizzato).
    - Viceversa, se il documento è **più corto della media** ($\frac{\vert{}D\vert{}}{\text{avgdl}} < 1$), il denominatore si rimpicciolisce e lo score finale aumenta (il documento breve e denso di concetti viene premiato).
        
## Interrogare l'Indice nel Codice (`SearchIndex.java`)

### 1. Ricerca su un singolo campo con `QueryParser` 
Per effettuare una ricerca su un indice Lucene (come mostrato nella classe `uniba.mri.lucene.SearchIndex`), entrano in gioco tre classi fondamentali:
1. **`IndexSearcher`:** indica l'indice fisico su cui effettuare la ricerca (ricevendo in input un `DirectoryReader` aperto sulla cartella dell'indice).
2. **`QueryParser`:** definisce le caratteristiche di interpretazione della query, specificando **su quale campo predefinito** cercare e **quale `Analyzer`** usare per processare il testo della query.
3. **`Query`:** rappresenta l'oggetto query vero e proprio contenente i termini cercati dall'utente (generato invocando il metodo `.parse(...)` del `QueryParser`).

```java
// 1. Crea l'IndexSearcher aprendo in lettura la directory dell'indice
IndexSearcher searcher = new IndexSearcher(DirectoryReader.open(fsdir));

// 2. Crea il QueryParser indicando il campo di default ("name") e l'Analyzer
QueryParser qp = new QueryParser("name", new StandardAnalyzer());

// 3. Effettua il parsing della stringa cercata ("parker") generando l'oggetto Query
Query q = qp.parse("parker");

// 4. Esegue la ricerca chiedendo i primi k = 10 risultati migliori (TopDocs)
TopDocs topdocs = searcher.search(q, 10);

// Stampa il numero totale di documenti trovati che soddisfano la query
System.out.println("Found " + topdocs.totalHits.value + " document(s).");
```

> [!NOTES] Coerenza dell'`Analyzer` tra Indicizzazione e Ricerca
> 
> Si noti che nel `QueryParser` viene passato `new StandardAnalyzer()`, ovvero lo **stesso identico analizzatore** usato nell'`IndexWriterConfig` durante l'indicizzazione: come studiato nella teoria del pre-processing, query e documenti devono subire sempre le stesse trasformazioni lessicali (es. conversione in minuscolo da `"Parker"` a `"parker"`), altrimenti i token non farebbero match nell'indice invertito.
> 
>   

### 2. Ricerca su più campi in parallelo con `MultiFieldQueryParser`
Spesso l'utente digita una parola chiave in una barra di ricerca generica senza sapere in quale campo specifico del documento si trovi quel termine (ad esempio se `"parker"` sia nel campo `"name"`, `"category"` o `"powers"`). Per interrogare **più campi in parallelo** con un'unica query, Lucene mette a disposizione la classe **`MultiFieldQueryParser`**:

```java
// 1. Inizializza l'array con i nomi di tutti i campi che vuoi interrogare
String[] fields = {"name", "category", "powers"};

// 2. Creazione del MultiFieldQueryParser passando l'array dei campi e l'analyzer
MultiFieldQueryParser parser = new MultiFieldQueryParser(fields, analyzer);

// 3. Definisci la stringa di ricerca e genera la Query
String queryString = "parker";
Query query = parser.parse(queryString);

// 4. Esegue la query sull'indice restituendo i primi 10 risultati
IndexSearcher searcher = new IndexSearcher(DirectoryReader.open(directory));
TopDocs results = searcher.search(query, 10);
```

**Cosa fa sotto il cofano `MultiFieldQueryParser`? Interrogare i tre campi `{"name", "category", "powers"}` cercando la parola `"parker"` con `MultiFieldQueryParser` equivale concettualmente a espandere e scomporre la richiesta in una **query booleana in `OR`** su tutti i campi specificati:
$$\text{name:parker} \quad \text{OR} \quad \text{category:parker} \quad \text{OR} \quad \text{powers:parker}$$

## Riepilogo dell'Architettura e Ruolo Centrale degli Analyzer
Riosservando l'architettura complessiva di `org.apache.lucene`, abbiamo visto come i documenti (`Document`) vengano scritti nell'indice invertito (`Index`) tramite `IndexWriter` e come le query vengano elaborate da `QueryParser`, cercate da `IndexSearcher` (che legge l'indice tramite `IndexReader`) e ordinate secondo la funzione di scoring BM25 implementata in `Similarity`.

![[Pasted image 20261111122526.png]]
Al centro esatto di questa architettura come ponte obbligato sia per il testo del `Document` in ingresso verso l'`IndexWriter`, sia per la `Query` dell'utente in ingresso verso il `QueryParser` — si trova il modulo **`Analyzer / Tokenizer / Filter`**, responsabile di tutte le operazioni di analisi e trasformazione linguistica del testo.



## Analisi del Testo in Lucene: `Analyzer`, `Tokenizer` e `TokenFilter`

Il modulo di **Text Analysis** in Apache Lucene si occupa di eseguire sul testo grezzo (sia dei documenti da indicizzare, sia delle query dell'utente) le tre operazioni linguistiche fondamentali studiate nella teoria dell'Information Retrieval.
- **Tokenization (Tokenizzazione):** suddivisione del testo continuo in unità elementari dette _token_.
- **Stop word elimination (Rimozione delle stopword):** eliminazione delle parole molto comuni e prive di valore informativo (come articoli, preposizioni e congiunzioni).
- **Stemming:** riduzione delle parole flesse (o derivate) alla loro radice morfologica comune (_stem_).

### Il ruolo della classe `Analyzer`
In Lucene l'intero processo di analisi testuale è incapsulato all'interno della classe astratta **`Analyzer`**:
- Riceve in ingresso il testo grezzo (**`Input Text`**) e lo tokenizza eseguendo su di esso una serie arbitraria di operazioni e trasformazioni.
- È responsabile della costruzione del **`TokenStream`** (il flusso di token elaborati in uscita), che viene poi consumato direttamente dai processi di indicizzazione (`IndexWriter`) e di ricerca (`QueryParser`).

Abbiamo già incontrato l'`Analyzer` negli esempi di codice precedenti, passandolo sia alla configurazione dell'`IndexWriter` sia al costruttore del `QueryParser`:

```java
IndexWriterConfig iwc = new IndexWriterConfig(new StandardAnalyzer());
QueryParser qp = new QueryParser("name", new StandardAnalyzer());
```

### Gli Analizzatori "Standard" forniti da Lucene
Lucene mette a disposizione diversi analizzatori predefiniti (_standard analyzers_), ciascuno dei quali combina internamente uno specifico _tokenizer_ e una serie di _filter_:
- **`KeywordAnalyzer`:** non spezza il testo, ma tratta l'intero campo come un **unico singolo token** indivisibile.
- **`WhitespaceAnalyzer`:** divide il testo in token separandolo esclusivamente in corrispondenza degli **spazi bianchi** (_whitespace_), senza modificare maiuscole/minuscole e senza rimuovere punteggiatura o stopword.
- **`SimpleAnalyzer`:** divide il testo in corrispondenza di qualsiasi **carattere non alfabetico** (eliminando quindi numeri e punteggiatura) e converte tutti i token in **minuscolo** (_lowercases_).
- **`StopAnalyzer`:** esegue le stesse operazioni del `SimpleAnalyzer` (divide sui caratteri non alfabetici e converte in minuscolo), ma in più **rimuove le stop words**.
- **`StandardAnalyzer`:** è l'analizzatore più evoluto e usato di default; tokenizza il testo basandosi su una **grammatica sofisticata** capace di riconoscere e preservare indirizzi e-mail, acronimi, URL, ecc., converte il testo in **minuscolo** e rimuove opzionalmente le **stop words**.

#### Esempio 1: Confronto su una frase in linguaggio naturale

Osserviamo come i diversi analizzatori trasformano la frase di input `"The quick brown fox jumped over the lazy dogs"`:
- **`WhitespaceAnalyzer`:** `[The] [quick] [brown] [fox] [jumped] [over] [the] [lazy] [dogs]` (separa solo sugli spazi; `"The"` resta con la maiuscola e le stopword restano presenti).
- **`SimpleAnalyzer`:** `[the] [quick] [brown] [fox] [jumped] [over] [the] [lazy] [dogs]` (tutto viene convertito in minuscolo, quindi `"The"` diventa `[the]`, ma le stopword non vengono rimosse).
- **`StopAnalyzer`:** `[quick] [brown] [fox] [jumped] [lazy] [dogs]` (converte in minuscolo ed elimina le stopword `"the"` e `"over"`).
- **`StandardAnalyzer`:** `[quick] [brown] [fox] [jumped] [over] [lazy] [dogs]` (converte in minuscolo e rimuove l'articolo `"the"` mantenendo `"over"`).

#### Esempio 2: Confronto con punteggiatura, acronimi ed e-mail 
Vediamo cosa succede su una stringa contenente caratteri speciali come `"XY&Z Corporation - xyz@example.com"`:
- **`WhitespaceAnalyzer`:** `[XY&Z] [Corporation] [-] [xyz@example.com]` (separando solo sugli spazi, conserva persino il trattino isolato `[-]` come se fosse una parola e lascia intatte le maiuscole).
- **`SimpleAnalyzer`:** `[xy] [z] [corporation] [xyz] [example] [com]` (spezzando su qualunque carattere non alfabetico come `&`, `-`, `@` e `.`, distrugge sia l'acronimo `"XY&Z"` sia l'indirizzo e-mail, dividendoli in frammenti separati).
- **`StandardAnalyzer`:** `[xy&z] [corporation] [xyz@example.com]` (grazie alla sua grammatica avanzata, elimina il trattino isolato, converte in minuscolo ma **riconosce e mantiene intatti** sia l'acronimo aziendale `[xy&z]` sia l'indirizzo e-mail `[xyz@example.com]`).

### Ispezionare i Token nel Codice (`TestAnalyzer.java`)

La classe `uniba.mri.lucene.TestAnalyzer` mostra come testare diversi analizzatori (incluso l'`EnglishAnalyzer`, specifico per la lingua inglese con stemming integrato, uno `StandardAnalyzer` a cui viene passato un file esterno di stopword `resources/en_stopword`, e un analizzatore personalizzato `MyAnalyzer`) stampando a schermo la lista dei token generati a partire dalla stringa `"the full-text indexing and search API: lucene.apache.org"`:

```java
public static void main(String[] args) throws IOException {
    String text = "the full-text indexing and search API: lucene.apache.org";
    System.out.println(getTokens(new StringReader(text), new WhitespaceAnalyzer()));
    System.out.println(getTokens(new StringReader(text), new StandardAnalyzer()));
    System.out.println(getTokens(new StringReader(text), new StandardAnalyzer(new FileReader("resources/en_stopword"))));
    System.out.println(getTokens(new StringReader(text), new EnglishAnalyzer()));
    System.out.println(getTokens(new StringReader(text), new MyAnalyzer()));
}
```

Per estrarre e visualizzare i singoli token prodotti da un `Analyzer`, si implementa il metodo statico `getTokens(Reader reader, Analyzer analyzer)`:

```java
public static List<String> getTokens(Reader reader, Analyzer analyzer) throws IOException {
    List<String> tokens = new ArrayList<>();
    
    // 1. Creiamo un flusso di token (TokenStream) a partire dall'analyzer e lo inizializziamo
    TokenStream tokenStream = analyzer.tokenStream("text", reader);
    tokenStream.reset();
    
    // 2. Istruzione per agganciare l'attributo che permette di leggere il testo del token corrente
    CharTermAttribute cattr = tokenStream.addAttribute(CharTermAttribute.class);
    
    // 3. Scorriamo il flusso un token alla volta finché ce ne sono
    while (tokenStream.incrementToken()) {
        String token = cattr.toString();
        tokens.add(token);
    }
    
    tokenStream.end();
    return tokens;
}
```

> [!NOTES] Come funziona il `TokenStream` e perché si usa `CharTermAttribute`
> 
> Analizzando il codice del metodo `getTokens()` emergono due concetti architetturali fondamentali:
> 
>   
> 
> 1. **Il ruolo dell'`Analyzer`:** la particolare tipologia di `analyzer` passata in input al metodo è direttamente responsabile di determinare come viene costruito e filtrato il flusso `tokenStream`.
>     
>       
>     
> 2. **Un token non è una semplice stringa:** in Lucene, **ogni token dentro il `TokenStream` non è una semplice `String`, ma è un insieme di attributi**! Oltre alla stringa testuale (che estraiamo agganciando l'attributo `CharTermAttribute.class`), Lucene memorizza per ciascun token anche la sua **posizione** nella frase (utile per le _phrase queries_), l'**offset** di inizio e fine carattere nel testo originale (utile per evidenziare le parole trovate nei risultati), il tipo di token, ecc..
>     
>       
>     

### Architettura interna di un `Analyzer`: `Tokenizer` + `TokenFilter`
Aprendo la "scatola nera" di un `Analyzer`, vediamo che al suo interno il processo di creazione del `TokenStream` è strutturato come una catena di montaggio (_pipeline_) composta da due elementi distinti:

$$\text{Input Text} \longrightarrow \boxed{\text{Analyzer}: \quad \text{Tokenizer} \longrightarrow \text{TokenFilter}_1 \longrightarrow \dots \longrightarrow \text{TokenFilter}_n} \longrightarrow \text{TokenStream}$$
![[Pasted image 20261111123126.png]]
1. **`Tokenizer`:**
    - È sempre il **primo passo** del processo di analisi: riceve il testo grezzo in ingresso e stabilisce **come spezzare il testo in token elementari**, producendo un primo `TokenStream`.
    - In ogni `Analyzer` può esserci **un solo `Tokenizer`**.
    - **Esempio pratico di `Tokenizers` sulla stringa `"full-text lucene.apache.org"`:**
        - `StandardTokenizer`: spezza sul trattino ma riconosce il dominio web $\rightarrow$ `"full"`, `"text"`, `"lucene.apache.org"`.
        - `WhitespaceTokenizer`: spezza solo sullo spazio bianco $\rightarrow$ `"full-text"`, `"lucene.apache.org"`.
        - `LetterTokenizer`: spezza su qualunque carattere non sia una lettera (inclusi trattino e punti) $\rightarrow$ `"full"`, `"text"`, `"lucene"`, `"apache"`, `"org"`.
2. **`TokenFilter`:**
    - Riceve in ingresso il `TokenStream` creato dal `Tokenizer` (o da un filtro precedente) ed è responsabile di **modificare, eliminare o arricchire i token**, indicando quali parole filtrare o trasformare.
    - A differenza del `Tokenizer`, dentro un `Analyzer` è possibile concatenare **più `TokenFilter` in cascata** l'uno dopo l'altro.
    - **Principali `TokenFilters` in Lucene:**
        - `LowerCaseFilter`: converte tutti i caratteri dei token in minuscolo.
        - `StopFilter`: rimuove dal flusso i token presenti in una lista di _stop words_.
        - `LengthFilter`: scarta i token troppo corti o troppo lunghi rispetto a una soglia fissata.
        - `PorterStemFilter`: applica l'algoritmo di **stemming di Porter**, riducendo le parole alla loro radice morfologica (ad esempio: `rides, ride, riding => ride`; oppure `country, countries => countri`).

### Creare un Analizzatore Personalizzato (`MyAnalyzer.java`)
Se nessuno degli analizzatori predefiniti soddisfa le esigenze del nostro dominio applicativo, Lucene permette di creare un **Custom Analyzer** estendendo la classe `Analyzer` e facendo l'_override_ del metodo `createComponents(String fieldName)`.


Nella classe `uniba.mri.lucene.MyAnalyzer`, costruiamo un analizzatore su misura che:

1. Definisce un proprio insieme personalizzato di _stop words_ (`"a", "an", "and", "are", "the", "is", "but", "by"`) salvato in un **`CharArraySet`**, una speciale struttura dati di Lucene ottimizzata per memorizzare e cercare stringhe ad altissima velocità.
2. Usa un **`LetterTokenizer`** come sorgente (`source`) per dividere il testo parola per parola (escludendo punteggiatura e numeri).
3. Applica in cascata prima un **`LowerCaseFilter`** (per convertire tutto in minuscolo) e poi uno **`StopFilter`** (per rimuovere le stopword definite in `STOP_WORDS`), restituendo l'oggetto finale `TokenStreamComponents(source, filter)`:

```java
// Creiamo una variabile statica STOP_WORDS
public static final CharArraySet STOP_WORDS;

// Inizializziamo il set di stopword personalizzato
static {
    final List<String> stopWords = Arrays.asList(
        "a", "an", "and", "are", "the", "is", "but", "by"
    );
    // CharArraySet: struttura dati ottimizzata per memorizzare stringhe in Lucene
    final CharArraySet stopSet = new CharArraySet(stopWords, false);
    STOP_WORDS = CharArraySet.unmodifiableSet(stopSet);
}

@Override
protected TokenStreamComponents createComponents(String fieldName) {
    // 1. Tokenizer: divide il testo parola per parola (solo lettere)
    Tokenizer source = new LetterTokenizer();
    
    // 2. Primo filtro: converte i token in minuscolo
    TokenStream filter = new LowerCaseFilter(source);
    
    // 3. Secondo filtro: rimuove le stop words contenute in STOP_WORDS
    filter = new StopFilter(filter, STOP_WORDS);
    
    // Restituisce la pipeline completa (Tokenizer + catena di filtri)
    return new TokenStreamComponents(source, filter);
}
```



---


## Esercizio Pratico: Indicizzare il romanzo _Alice in Wonderland_

Per realizzare un caso di studio completo in Apache Lucene, vediamo come indicizzare il celebre romanzo _Alice in Wonderland_ — il cui testo è contenuto nel file `./resources/Alice_Adv_Lewis_Carroll_utf8.text` — all'interno di un indice Lucene ricercabile.

### Requisiti e struttura del `Document`
L'obiettivo consiste nell'indicizzare ciascun capitolo (o paragrafo) del libro come un oggetto `Document` Lucene separato, strutturato attraverso quattro campi (`Fields`):
1. **The Title of the Book (`title`):** il titolo del libro, che rimane identico per tutti i capitoli e i documenti generati.
2. **The Author of the Book (`author`):** l'autore del libro, che rimane anch'esso invariato per tutti i documenti.
3. **The title of the Chapter (`chapter`):** il titolo del capitolo corrente, che varia di capitolo in capitolo.
4. **The text of the Chapter (`text`):** il contenuto testuale del capitolo o del paragrafo corrente, che cambia per ciascun documento.                        


### Svolgimento passo dopo passo
#### Passo 1 e 2: Creazione dell'indice e configurazione di `Analyzer` e `IndexWriter`
Per prima cosa si crea il nuovo indice passando come parametro il percorso della directory su file system (`./resources/alice`) tramite `FSDirectory.open(...)`. Successivamente si istanziano un nuovo `StandardAnalyzer` e il relativo `IndexWriter`, impostando nella configurazione (`IndexWriterConfig`) la modalità di apertura `CREATE_OR_APPEND`:


```java
// 1. Crea un nuovo indice indicando la directory come parametro
FSDirectory fsdir = FSDirectory.open(new File("./resources/alice").toPath());

// 2. Crea un nuovo Analyzer e un nuovo IndexWriter con le relative configurazioni
StandardAnalyzer analyzer = new StandardAnalyzer();
IndexWriterConfig config = new IndexWriterConfig(analyzer);
config.setOpenMode(IndexWriterConfig.OpenMode.CREATE_OR_APPEND);
IndexWriter writer = new IndexWriter(fsdir, config);
```

#### Passo 3: Apertura del file di testo e lettura dell'intestazione
Il passo successivo consiste nell'aprire il file di testo contenente il romanzo e predisporre una variabile per ciascuno dei quattro elementi da memorizzare (`title`, `author`, `chapter`, `text`).

Aprendo il documento sorgente in un editor di testo o stampandone il contenuto in console mentre lo si scorre in Java con `BufferedReader` e il metodo `readLine()`, si nota che le prime quattro righe del file seguono uno schema fisso prima dell'inizio dei capitoli:

- **Rigo 1:** contiene il titolo del libro, che viene letto e salvato direttamente nella variabile `title`.
- **Rigo 2:** è un rigo vuoto, che viene saltato eseguendo una chiamata a vuoto `b.readLine()`
- **Rigo 3:** contiene il nome dell'autore, che viene letto e assegnato alla variabile `author`.
- **Rigo 4:** è un altro rigo vuoto, che viene saltato con un'ulteriore chiamata `b.readLine()`, subito dopo la quale iniziano i capitoli veri e propri.

```java 
String title = b.readLine();   // Rigo 1
b.readLine();                  // Rigo 2 (vuoto)
String author = b.readLine();  // Rigo 3
b.readLine();                  // Rigo 4 (vuoto) -> poi iniziano i capitoli
```

#### Passo 4 e 5: Strategia per isolare Capitoli e Paragrafi e salvataggio dei `Document`

Scorrendo il resto del file riga per riga, occorre definire una strategia basata sul controllo delle righe vuote e di specifiche parole chiave per isolare le diverse porzioni di testo e capire esattamente quando inizia un nuovo capitolo e quando inizia un nuovo paragrafo:
- **Riconoscere l'inizio di un nuovo capitolo:** nel testo ogni capitolo inizia sempre con la parola **`CHAPTER`**. Basta quindi verificare la presenza di questa stringa nella riga appena letta per intercettare il cambio di capitolo:
    ```java
    if (readLine.contains("CHAPTER")) { ... }
    ```
- **Riconoscere l'inizio di un nuovo paragrafo e memorizzare il documento:** controllando le righe vuote, si individua che ogni nuovo paragrafo inizia alla riga successiva (`start the next line`). Una volta isolato il testo del paragrafo, lo si memorizza insieme agli altri campi (`title`, `author`, `chapter`) creando un nuovo oggetto `Document` e aggiungendolo all'indice.

## Verifica dell'Indice tramite il tool grafico Luke
Per controllare che l'indicizzazione sia andata a buon fine ed esplorare il risultato prodotto, si utilizza **Luke (_Lucene Toolbox Project_)**:
- **Che cos'è Luke:** è uno strumento dotato di interfaccia grafica (**GUI tool**) progettato per ispezionare, effettuare ricerche e analizzare gli indici di Apache Lucene, consentendo di esplorare in modo interattivo i documenti, i termini indicizzati e gli _analyzer_.
- **Come ottenerlo:** lo strumento è già incluso direttamente all'interno della release binaria di Lucene, precisamente nella cartella `./bin/`.
- **Come aprire e analizzare l'indice:** una volta avviato Luke, nella finestra _Choose index directory path_ si clicca sul pulsante _Browse_ e si seleziona **la cartella** in cui è stato salvato l'indice (è fondamentale selezionare l'intera cartella di destinazione dell'indice e non i singoli file al suo interno), potendo anche scegliere l'apertura in sola lettura (_Open in Read-only mode_) per analizzare l'indice archiviato attraverso le sezioni _Overview_, _Documents_, _Search_, _Analysis_, _Commits_ e _Logs_.

# Svolgimento Completo dell'Esercizio 1: Indicizzazione di _Alice in Wonderland_

Per implementare l'indicizzazione del romanzo _Alice in Wonderland_ (`./resources/Alice_Adv_Lewis_Carroll_utf8.text`) all'interno di un indice Apache Lucene, strutturiamo una classe Java completa che segue i 5 passi operativi definiti nella traccia: apertura della directory, configurazione dell'`IndexWriter`, lettura dell'intestazione (`title` e `author`), scansione del testo per isolare capitoli (`CHAPTER`) e paragrafi, e creazione dei singoli oggetti `Document`.

## Codice Java Completo (`AliceIndexer.java`)

```java
package uniba.mri.lucene;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;
import org.apache.lucene.analysis.standard.StandardAnalyzer;
import org.apache.lucene.document.Document;
import org.apache.lucene.document.Field;
import org.apache.lucene.document.StringField;
import org.apache.lucene.document.TextField;
import org.apache.lucene.index.DirectoryReader;
import org.apache.lucene.index.IndexReader;
import org.apache.lucene.index.IndexWriter;
import org.apache.lucene.index.IndexWriterConfig;
import org.apache.lucene.store.FSDirectory;

public class AliceIndexer {

    public static void main(String[] args) throws IOException {

        // PASSO 1: Creazione del nuovo indice indicando la directory come parametro
        FSDirectory fsdir = FSDirectory.open(new File("./resources/alice").toPath());

        // PASSO 2: Creazione dell'Analyzer e dell'IndexWriter con le relative configurazioni
        StandardAnalyzer analyzer = new StandardAnalyzer();
        IndexWriterConfig config = new IndexWriterConfig(analyzer);
        config.setOpenMode(IndexWriterConfig.OpenMode.CREATE_OR_APPEND);
        IndexWriter writer = new IndexWriter(fsdir, config);

        // PASSO 3: Apertura del file di testo e lettura delle prime 4 righe (intestazione)
        File novelFile = new File("./resources/Alice_Adv_Lewis_Carroll_utf8.text");
        BufferedReader b = new BufferedReader(new FileReader(novelFile));

        String title = b.readLine();   // Rigo 1: Titolo del libro
        b.readLine();                  // Rigo 2: Rigo vuoto
        String author = b.readLine();  // Rigo 3: Autore del libro
        b.readLine();                  // Rigo 4: Rigo vuoto (poi iniziano i capitoli)

        String chapter = "";
        StringBuilder textBuilder = new StringBuilder();
        String readLine;

        // PASSO 4 e 5: Scansione del testo per isolare capitoli e paragrafi e salvataggio dei Document
        while ((readLine = b.readLine()) != null) {

            // a) Se la riga contiene "CHAPTER", è iniziato un nuovo capitolo
            if (readLine.contains("CHAPTER")) {
                chapter = readLine.trim();
            } 
            // b) Se troviamo una riga vuota e abbiamo accumulato del testo, il paragrafo è concluso
            else if (readLine.trim().isEmpty()) {
                if (textBuilder.length() > 0) {
                    Document doc = new Document();
                    doc.add(new TextField("title", title, Field.Store.YES));
                    doc.add(new StringField("author", author, Field.Store.YES));
                    doc.add(new TextField("chapter", chapter, Field.Store.YES));
                    doc.add(new TextField("text", textBuilder.toString().trim(), Field.Store.YES));

                    writer.addDocument(doc);

                    // Svuotiamo il buffer per iniziare ad accumulare il paragrafo successivo
                    textBuilder.setLength(0);
                }
            } 
            // Altrimenti la riga fa parte del paragrafo corrente: la aggiungiamo al testo
            else {
                textBuilder.append(readLine).append(" ");
            }
        }

        // Salvataggio dell'eventuale ultimo paragrafo rimasto nel buffer a fine file
        if (textBuilder.length() > 0) {
            Document doc = new Document();
            doc.add(new TextField("title", title, Field.Store.YES));
            doc.add(new StringField("author", author, Field.Store.YES));
            doc.add(new TextField("chapter", chapter, Field.Store.YES));
            doc.add(new TextField("text", textBuilder.toString().trim(), Field.Store.YES));

            writer.addDocument(doc);
        }

        // Chiusura del file di testo e dell'IndexWriter per salvare l'indice su disco
        b.close();
        writer.close();

        // Verifica finale: conteggio dei documenti indicizzati tramite IndexReader
        IndexReader reader = DirectoryReader.open(fsdir);
        int numDocs = reader.numDocs();
        System.out.println("Indicizzazione completata! Numero di documenti nell'indice: " + numDocs);
        reader.close();
    }
}
```

## Analisi dettagliata dei blocchi di codice

### 1. Inizializzazione dell'indice e dell'`IndexWriter` (Passi 1 e 2)

- Si apre la cartella di destinazione `./resources/alice` tramite il metodo `FSDirectory.open(...)`.
- Si istanzia uno `StandardAnalyzer` e lo si passa a `IndexWriterConfig`, impostando la modalità `IndexWriterConfig.OpenMode.CREATE_OR_APPEND` affinché l'indice venga creato se non esiste ancora o aggiornato in coda se già presente.

### 2. Lettura delle variabili fisse `title` e `author` (Passo 3)
- Aprendo il file `./resources/Alice_Adv_Lewis_Carroll_utf8.text` tramite `BufferedReader`, le prime quattro chiamate a `b.readLine()` estraggono nell'ordine il titolo del romanzo al rigo 1 (`title`), saltano il rigo 2 vuoto, estraggono l'autore al rigo 3 (`author`) e saltano il rigo 4 vuoto.
- Come richiesto dalla traccia, le variabili `title` e `author` vengono lette una sola volta fuori dal ciclo `while` perché rimangono identiche per tutti i documenti che verranno generati.

### 3. Logica del ciclo `while`: intercettazione di Capitoli e Paragrafi (Passi 4 e 5)
All'interno del ciclo `while ((readLine = b.readLine()) != null)` il programma scorre il testo rimanente applicando tre controlli:
- **Cambio di capitolo (`readLine.contains("CHAPTER")`)**: poiché ogni nuovo capitolo inizia con la parola chiave `"CHAPTER"`, quando la condizione è vera aggiorniamo la variabile `chapter` con la stringa appena letta. Tutti i paragrafi letti da quel momento in poi erediteranno quel titolo di capitolo fino al prossimo `"CHAPTER"`.
- **Accumulo e fine del paragrafo (`readLine.trim().isEmpty()`)**: nel file sorgente i paragrafi sono separati da righe vuote e ogni nuovo paragrafo inizia alla riga successiva. Finché incontriamo righe piene di testo, le concateniamo dentro `textBuilder`; appena incontriamo una riga vuota (e `textBuilder` non è vuoto), significa che il paragrafo è terminato.
- **Creazione e salvataggio del `Document`**: alla chiusura di ciascun paragrafo istanziamo un nuovo oggetto `Document`, popoliamo i quattro campi (`title`, `author`, `chapter`, `text`) impostando `Field.Store.YES` per memorizzarne il contenuto nell'indice e poterlo poi visualizzare nei risultati o dentro **Luke**, e invochiamo `writer.addDocument(doc)`.


> [!NOTES] Variante: Indicizzare l'intero Capitolo come un unico `Document`
> 
> Se invece di salvare un documento per ogni singolo paragrafo si desidera salvare **un solo `Document` per ciascuno dei 12 capitoli** del libro, basta spostare la creazione del `Document` e la chiamata `writer.addDocument(doc)` direttamente dentro l'`if (readLine.contains("CHAPTER"))`: ogni volta che inizia un nuovo `"CHAPTER"` (e `textBuilder` contiene già il testo del capitolo precedente), si salva il documento del capitolo appena concluso, si svuota `textBuilder` e si aggiorna la variabile `chapter` con il titolo del nuovo capitolo.
> 
>   

## Come testare la ricerca sull'indice appena creato (`SearchAlice.java`)
Oltre ad aprire la cartella `./resources/alice` con il tool grafico **Luke**, possiamo verificare via codice che l'indice funzioni eseguendo una query di prova (ad esempio cercando la parola `"rabbit"` nel campo `"text"`) con `IndexSearcher` e `QueryParser`:

```java
package uniba.mri.lucene;

import java.io.File;
import org.apache.lucene.analysis.standard.StandardAnalyzer;
import org.apache.lucene.document.Document;
import org.apache.lucene.index.DirectoryReader;
import org.apache.lucene.queryparser.classic.QueryParser;
import org.apache.lucene.search.IndexSearcher;
import org.apache.lucene.search.Query;
import org.apache.lucene.search.ScoreDoc;
import org.apache.lucene.search.TopDocs;
import org.apache.lucene.store.FSDirectory;

public class SearchAlice {

    public static void main(String[] args) throws Exception {
        // 1. Apre in lettura la directory dell'indice di Alice
        FSDirectory fsdir = FSDirectory.open(new File("./resources/alice").toPath());
        IndexSearcher searcher = new IndexSearcher(DirectoryReader.open(fsdir));

        // 2. Configura il QueryParser sul campo "text" con lo stesso StandardAnalyzer
        QueryParser qp = new QueryParser("text", new StandardAnalyzer());
        Query q = qp.parse("rabbit");

        // 3. Esegue la ricerca restituendo i primi 10 risultati migliori
        TopDocs topdocs = searcher.search(q, 10);
        System.out.println("Trovati " + topdocs.totalHits.value + " documenti per la query 'rabbit':\n");

        // 4. Stampa i campi memorizzati (Field.Store.YES) dei documenti recuperati
        for (ScoreDoc hit : topdocs.scoreDocs) {
            Document doc = searcher.storedFields().document(hit.doc);
            System.out.println("Score: " + hit.score);
            System.out.println("Capitolo: " + doc.get("chapter"));
            System.out.println("Testo: " + doc.get("text"));
            System.out.println("--------------------------------------------------");
        }
    }
}
```
