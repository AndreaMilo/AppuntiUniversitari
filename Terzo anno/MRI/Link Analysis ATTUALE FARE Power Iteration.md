# Introduzione

## Dal contenuto testuale alla struttura dei collegamenti (Link Analysis)

Nello studio classico dei sistemi di **Information Retrieval (IR)** e di **Text Categorization**, l'attenzione si concentra sull'analisi del contenuto testuale interno ai singoli documenti. Attraverso tecniche di pre-processing, indicizzazione tramite _Inverted Index_ e modelli come il **Modello Booleano** o il **Modello a Spazio Vettoriale (VSM)** basato su pesatura _tf-idf_ e _Cosine Similarity_, un motore di ricerca tradizionale valuta quanto le parole di un documento corrispondano alla _query_ dell'utente, oppure classifica il testo in categorie predefinite tramite algoritmi di _Machine Learning_.

Anche quando il sistema viene potenziato con strumenti semantici (come **WordNet** per la disambiguazione dei termini), meccanismi iterativi di **Relevance Feedback** (come l'algoritmo di Rocchio) e metriche rigorose di valutazione (_Precision_, _Recall_, _MAP_, _MRR_, _NDCG_), ogni documento viene comunque trattato come un'unità isolata e indipendente dalle altre.

Questo approccio funziona in modo eccellente su collezioni tradizionali, controllate e affidabili (come archivi di brevetti, articoli scientifici o testate giornalistiche), ma entra in crisi quando viene applicato al **World Wide Web**. Sul Web, infatti, i documenti non sono entità isolate, ma sono interconnessi tra loro attraverso i **collegamenti ipertestuali (hyperlink)**. Come già anticipato nella tassonomia generale dei modelli di IR (dove le proprietà del documento si dividono in _Text_, _Links_ e _Multimedia_), per effettuare ricerche efficaci sul Web è indispensabile affiancare all'analisi del testo lo studio delle relazioni tra le pagine.
  
Nasce così la **Link Analysis** (analisi dei collegamenti), che modella il Web come un enorme **grafo orientato** e sfrutta la rete dei link per misurare l'**importanza**, l'**affidabilità** e l'**autorevolezza** di ciascuna pagina, ponendo le basi per algoritmi fondamentali come **PageRank** e **HITS (Hubs and Authorities)**.


## Analisi di Grandi Grafi: Link Analysis e PageRank
Lo studio della **Link Analysis** e dell'algoritmo **PageRank** si inserisce nell'ambito della **Analysis of Large Graphs** (analisi di grafi di grandi dimensioni). 

L'idea di partenza è che moltissimi sistemi complessi del mondo reale, caratterizzati da enormi volumi di dati, non possono essere compresi guardando i singoli elementi separatamente, ma devono essere rappresentati e studiati sotto forma di **grafi** (insiemi di nodi collegati tra loro da archi).

## I Dati a Grafo: esempi di reti reali
Prima di analizzare il Web, è utile osservare come i dati strutturati a grafo (_Graph Data_) siano presenti in numerosi domini applicativi, divisibili in tre grandi categorie principali:

![[Pasted image 20261031152342.png]]
Un primo esempio emblematico di grafo di enormi dimensioni è rappresentato dalle **reti sociali**, come il **grafo sociale di Facebook** (_Facebook social graph_):
- **Nodi:** rappresentano i singoli utenti iscritti alla piattaforma in tutto il mondo.    
- **Archi:** rappresentano le relazioni di amicizia o collegamento sociale tra due persone.

Studiando la struttura globale del grafo di Facebook (ricerca di _Backstrom, Boldi, Rosa, Ugander e Vigna, 2011_), si è scoperto che la rete presenta una distanza media di appena **4 gradi di separazione** (_4-degrees of separation_). Ciò significa che, nonostante il grafo contenga miliardi di persone sparse su tutti i continenti, qualunque coppia di utenti nel mondo è collegata in media da una catena di sole quattro conoscenze intermedie.

![[Pasted image 20261031152517.png]]
Una seconda famiglia fondamentale è costituita dalle **reti di informazione**, illustrate attraverso le **reti di citazioni scientifiche e le mappe della scienza**:
- **Nodi:** rappresentano gli articoli scientifici o gli specifici ambiti disciplinari.
- **Archi:** rappresentano le citazioni bibliografiche con cui una pubblicazione o una disciplina fa riferimento a un'altra.

![[Pasted image 20261031152931.png]]
Le **reti di comunicazione**, il cui caso più concreto è la struttura fisica e logica di **Internet**:
- **Nodi:** sono costituiti dai dispositivi terminali (come i singoli computer o laptop degli utenti) e dai dispositivi di instradamento del traffico (**router**).
- **Archi:** rappresentano le connessioni fisiche o wireless (linee tratteggiate) attraverso cui viaggiano i pacchetti di dati.

L'infrastruttura è organizzata gerarchicamente in **domini** (_domain1_, _domain2_, _domain3_): all'interno di ciascun dominio i router sono interconnessi tra loro e servono i computer locali, mentre specifici collegamenti dorsali uniscono i router di domini differenti permettendo la comunicazione su scala globale.

## Il Web come Grafo Orientato
Passando dall'infrastruttura fisica dei cavi e dei router (Internet) al livello dei contenuti informativi (il **World Wide Web**), possiamo modellare matematicamente l'intero Web come un **grafo orientato** (_directed graph_):
- **Nodi (_Nodes_):** sono le singole **pagine Web** (_Webpages_).
- **Archi (_Edges_):** sono i **collegamenti ipertestuali** (_Hyperlinks_), ovvero i link cliccabili che portano l'utente da una pagina sorgente a una pagina di destinazione.

**Perché il grafo si definisce "orientato"?** Il grafo è orientato (o diretto) perché ogni link possiede un verso ben preciso, rappresentato graficamente da una **freccia**: se la pagina $A$ contiene un link che punta alla pagina $B$ ($A \rightarrow B$), è possibile navigare da $A$ verso $B$, ma questo non implica che nella pagina $B$ esista un link per tornare indietro verso $A$.

### Esempio di costruzione degli archi tramite Hyperlink
  
![[Pasted image 20261031161423.png]]
**Stato iniziale:** immaginiamo quattro pagine web distinte, ciascuna con il proprio testo:
- Pagina 1: _"I teach a class on Data Mining."_ (Insegno un corso su Data Mining).
- Pagina 2: _"Classes are in the Gates building"_ (Le lezioni si tengono nell'edificio Gates).- Pagina 3: _"Computer Science Department at Stanford"_ (Dipartimento di Informatica a Stanford).
- Pagina 4: _"Stanford University"_ (Università di Stanford).

![[Pasted image 20261031161451.png]]
**Inserimento dei link**: nel momento in cui gli autori delle pagine inseriscono dei link ipertestuali su specifiche parole chiave (dette _anchor text_, sottolineate in blu), si creano gli archi orientati del grafo:
 - Nella Pagina 1, le parole _"Data Mining"_ diventano un link che punta alla Pagina 2 (_"Classes are in the Gates building"_).
 - Nella Pagina 2, la parola _"Gates"_ diventa un link che punta alla Pagina 3 (_"Computer Science Department at Stanford"_).
  - Nella Pagina 3, la parola _"Stanford"_ diventa un link che punta alla Pagina 4 (_"Stanford University"_).

### Esempio di rete complessa di pagine Web
![[Pasted image 20261031161748.png]]
Osservando questo grafo si intuisce già visivamente un aspetto cruciale: mentre nodi periferici come _"My song lyrics"_ ricevono un solo link da una pagina poco nota e non puntano a nulla, nodi centrali come _"Univ. of X"_ o _"USNews College Rankings"_ ricevono link da molteplici percorsi indipendenti e autorevoli.

## Come organizzare il Web?
Con l'esplosione del World Wide Web è nata una domanda fondamentale: **come possiamo organizzare il Web** per permettere agli utenti di orientarsi e trovare le informazioni desiderate? Storicamente sono stati compiuti due grandi tentativi:

### Primo tentativo: le Web Directory curate da umani
Il primo approccio storico è consistito nell'affidare a redattori umani il compito di catalogare manualmente i siti web all'interno di grandi elenchi ragionati e organizzati ad albero per categorie tematiche:
- Gli esempi più celebri di questo modello sono stati **Yahoo!** (nella sua versione storica degli anni '90 mostrata nella slide), **DMOZ** e **LookSmart**.
![[Pasted image 20261031161943.png]]
- Come si vede nella schermata storica di Yahoo!, l'utente navigava sfogliando macro-categorie catalogate a mano (come _Arts_, _Business and Economy_, _Computers and Internet_, _Education_, _Entertainment_, _Government_, _Health_, _News_, _Recreation_, _Reference_, _Regional_, _Science_, _Social Science_, _Society and Culture_).
- Questo approccio non poteva reggere la crescita esponenziale del Web, poiché l'intervento umano manuale è lento, costoso e incapace di tenere il passo con miliardi di nuove pagine create o modificate ogni giorno.

### Ricerca Web (_Web Search_)
Per superare i limiti delle directory manuali si è passati ai motori di ricerca automatici basati sull'**Information Retrieval (IR)**. Tuttavia, è emerso subito un contrasto profondo tra gli ambienti per cui l'IR classico era stato progettato e la realtà del Web:
- **L'Information Retrieval tradizionale** studia come trovare documenti rilevanti all'interno di una **collezione piccola e fidata** (_a small and trusted set_), come ad esempio raccolte di **articoli di giornale** (_Newspaper articles_), **brevetti** (_Patents_) o archivi bibliotecari, dove tutti i testi sono controllati alla fonte e scritti in buona fede.
- **La realtà del Web:** al contrario, il Web è **immenso** (_huge_), ed è pieno di **documenti non affidabili** (_untrusted documents_), **contenuti casuali** (_random things_) e soprattutto di **web spam** (pagine spazzatura create appositamente per manipolare gli algoritmi testuali ripetendo parole chiave nascoste o ingannevoli per comparire ai primi posti).

## Web Search: 2 Challenges
Proprio a causa della natura caotica, eterogenea e non controllata del Web, un motore di ricerca deve affrontare e risolvere **due grandi sfide** (_2 challenges of web search_), superando entrambe grazie a un'intuizione basata sui link:

1. **Prima sfida: Di chi "fidarsi"? (_Who to "trust"?_)**
    - **Il problema:** il Web contiene innumerevoli fonti di informazione in contraddizione tra loro, incluse pagine false, amatoriali o di spam; guardando solo le parole contenute nel testo non è possibile stabilire se una pagina sia autorevole o meno.
    - **Il trucco (_Trick_):** _le pagine affidabili tendono a puntare le une alle altre!_ (_Trustworthy pages may point to each other!_). Un sito universitario o istituzionale inserirà link verso altre fonti serie e verificate, mentre difficilmente inserirà un link verso una pagina di spam.
    
2. **Seconda sfida: Qual è la risposta "migliore" a una query generica come _"newspaper"_?**
    - **Il problema:** se un utente cerca una parola molto ampia come _"newspaper"_ (quotidiano), **non esiste un'unica risposta giusta** (_no single right answer_), e milioni di pagine sul Web contengono la parola _"newspaper"_ nel proprio testo (spesso anche più volte rispetto alla home page di un vero quotidiano).
    - **Il trucco (_Trick_):** _le pagine che conoscono davvero i quotidiani punteranno probabilmente verso molti quotidiani diversi_ (_Pages that actually know about newspapers might all be pointing to many newspapers_). Se molte pagine di rassegne stampa o elenchi di media puntano contemporaneamente a determinati siti, quei siti saranno con altissima probabilità le testate giornalistiche più importanti.

## Classificare i nodi sul grafo
Dalle considerazioni precedenti emerge un principio cardine per i motori di ricerca Web: **non tutte le pagine web sono ugualmente "importanti"** (_All web pages are not equally "important"_).
La slide propone un confronto immediato tra due indirizzi web:
- `www.joe-schmoe.it` (il sito personale di uno sconosciuto qualsiasi).
- `www.stanford.edu` (il portale ufficiale dell'Università di Stanford).

Anche se entrambe le pagine parlassero dello stesso argomento (ad esempio di un corso di informatica) e avessero la stessa frequenza di parole chiave, qualsiasi utente si aspetta di trovare `www.stanford.edu` in cima ai risultati e non la pagina amatoriale.
![[Pasted image 20261031163141.png]]
Osservando il grafo disegnato, si nota che **esiste un'enorme diversità nella connettività dei nodi del grafo del Web** (_There is large diversity in the web-graph node connectivity_):
- Alcuni nodi periferici (come il pallino rosso in alto a destra o i puntini isolati ai margini) hanno pochissimi collegamenti.
- Altri nodi centrali (come il grande nodo blu in basso a sinistra, verso cui convergono decine e decine di archi a raggiera) fungono da veri e propri poli di attrazione della rete.

La soluzione consiste quindi nel **classificare (fare il ranking) delle pagine in base alla struttura dei link** (_Let's rank the pages by the link structure!_), assegnando a ogni nodo del grafo un punteggio numerico che ne misuri l'importanza strutturale.

## Algoritmi di Link Analysis 
Per calcolare matematicamente l'importanza dei nodi all'interno di un grafo orientato sfruttando la struttura dei link, vengono utilizzati gli algoritmi di **Link Analysis**. I due approcci fondamentali studiati nel corso sono:

- **PageRank:** l'algoritmo reso celebre dai fondatori di Google (Larry Page e Sergey Brin), che valuta l'importanza globale di ogni pagina web interpretando i link in ingresso come "voti" pesati in base all'importanza della pagina che li emette (risolvendo in particolare la prima sfida sulla fiducia e sull'autorevolezza dei nodi).
- **Hubs and Authorities (HITS):** l'algoritmo che assegna a ciascuna pagina due punteggi distinti, distinguendo tra le pagine **Authorities** (fonti autorevoli che forniscono la risposta migliore su un argomento) e le pagine **Hubs** (pagine "collettori" che conoscono bene l'argomento e puntano verso molte buone Authorities).

# PageRank: La Formulazione "Flow"  

## Links as Votes
La prima formulazione matematica dell'algoritmo **PageRank** prende il nome di **Formulazione a Flusso** (_The "Flow" Formulation_).
L'idea intuitiva alla base di questo modello consiste nel considerare i collegamenti ipertestuali (link) come dei veri e propri **voti** (_Links as votes_) espressi da una pagina nei confronti di un'altra.

Partendo dal principio che una pagina è tanto più importante quanto maggiore è il numero di link che possiede, occorre innanzitutto chiedersi se vadano conteggiati i **link in ingresso** (_In-coming links_) oppure i **link in uscita** (_Out-going links_):
La scelta ricade sui **link in ingresso (_in-links_)**, i quali vengono interpretati come voti di fiducia ricevuti dalle altre pagine del Web (mentre i link in uscita sarebbero troppo facili da manipolare, poiché chiunque potrebbe creare una pagina inserendovi migliaia di link verso l'esterno).
- **Esempio:** il portale ufficiale dell'Università di Stanford (`www.stanford.edu`) riceve ben $23.400$ _in-links_, mentre un sito amatoriale sconosciuto (`[www.joe-schmoe.com](https://www.joe-schmoe.com)`) riceve appena $1$ _in-link_.


Tuttavia, contare semplicemente il numero di link in ingresso non basta e porta a una domanda cruciale: **tutti gli _in-links_ hanno lo stesso valore?**
- La risposta è **no**: i link provenienti da pagine **importanti** contano molto di più (_Links from important pages count more_) rispetto ai link provenienti da pagine marginali o sconosciute.
- **Natura ricorsiva del problema:** questa regola trasforma il calcolo dell'importanza in una **questione ricorsiva** (_Recursive question!_), poiché per sapere quanto è importante una pagina bisogna già conoscere l'importanza delle pagine che la puntano, la quale a sua volta dipende da chi punta loro.

## Esempio visivo dei punteggi di PageRank

![[Pasted image 20261031164814.png]]
Questo grafo mostra visivamente come funziona questa distribuzione ricorsiva dell'importanza su un piccolo grafo orientato, in cui la dimensione di ciascun nodo è proporzionale al suo punteggio di PageRank:
- **Nodo B (punteggio 38.4):** È il più importante della rete perché raccoglie numerosi link in ingresso da quasi tutti i nodi del grafo.
- **Nodo C (punteggio 34.3):** Dimostra la forza del PageRank rispetto al semplice conteggio dei link: pur ricevendo _un solo_ collegamento in ingresso, ottiene un punteggio altissimo perché proviene interamente da B, la pagina più autorevole.
- **Nodo E (punteggio 8.1):** Pur ricevendo ben quattro link, si ferma a un valore intermedio e ridistribuisce il suo punteggio verso altri nodi.
- **Nodi D ed F (punteggio 3.9):** Ricevono link da E e da nodi periferici, spartendo la propria importanza tra gli elementi collegati.
- **Nodo A (punteggio 3.3):** Ottiene un punteggio basso perché riceve un solo link da una pagina marginale e condivisa (D).
- **Nodi periferici in basso (punteggio 1.6):** Sono nodi senza ingressi che possiedono il valore minimo e trasferiscono la loro importanza verso i nodi superiori.
## Formulazione Ricorsiva Semplice
Per tradurre in formule questo meccanismo di voto pesato, si stabiliscono tre regole:
1. **Proporzionalità del voto:** il voto espresso da ciascun link è direttamente proporzionale all'importanza della sua pagina sorgente (_source page_).
2. **Ripartizione equa tra i link uscenti:** se una pagina $j$ possiede un'importanza pari a $r_j$ e ha $n$ link in uscita (_out-links_), l'importanza viene divisa equamente e ciascun link uscente riceve esattamente $\frac{r_j}{n}$ voti.
3. **Somma dei voti in ingresso:** l'importanza complessiva $r_j$ della pagina $j$ è data dalla somma di tutti i voti trasportati dai suoi link in ingresso (_in-links_).

![[Pasted image 20261031171207.png]]

Osservando lo schema per il calcolo dell'importanza del nodo centrale $j$:
- Il nodo $i$ ha un'importanza $r_i$ e possiede **$3$ link uscenti**: il link che entra in $j$ trasporta quindi un voto pari a $\frac{r_i}{3}$.
- Il nodo $k$ ha un'importanza $r_k$ e possiede **$4$ link uscenti**: il link che entra in $j$ trasporta quindi un voto pari a $\frac{r_k}{4}$.
- Sommando i contributi ricevuti in ingresso, il punteggio di importanza del nodo $j$ è:
$$
r_j = \frac{r_i}{3} + \frac{r_k}{4}
$$
- A sua volta, poiché il nodo $j$ possiede **$3$ link uscenti** verso i tre nodi azzurri, esso cederà a ciascuno di loro un terzo della propria importanza, ovvero $\frac{r_j}{3}$.

# Il Modello a Flusso (The "Flow" Model)
Generalizzando la regola appena vista all'intero grafo del Web, otteniamo il **Modello a Flusso** (_Flow Model_), basato sul principio secondo cui un "voto" proveniente da una pagina importante vale di più e, di conseguenza, una pagina è importante se viene puntata da altre pagine importanti.

> [!NOTES] Definizione Formale del Rank $r_j$ (Equazione di Flusso) Indicando con $d_i$ il **grado uscente** (_out-degree_, ovvero il numero di link in uscita) del nodo $i$, il punteggio di importanza (**rank**) $r_j$ della pagina $j$ è definito come la somma dei punteggi $r_i$ di tutte le pagine $i$ che puntano a $j$ ($i \rightarrow j$), ciascuno diviso per il rispettivo grado uscente $d_i$:
> 
>   
> 
> $$r_j = \sum_{i \rightarrow j} \frac{r_i}{d_i}$$

## Esempio
![[Pasted image 20261031171734.png]]
The web in 1839 è un grafo composto da soli $3$ nodi:
- **Nodo $y$:** ha $2$ archi uscenti ($d_y = 2$), uno che punta a se stesso e uno che punta ad $a$; ciascuno trasporta metà dell'importanza di $y$, cioè $\frac{y}{2}$.
- **Nodo $a$:** ha $2$ archi uscenti ($d_a = 2$), uno che punta a $y$ e uno che punta a $m$; ciascuno trasporta metà dell'importanza di $a$, cioè $\frac{a}{2}$.
- **Nodo $m$:** ha $1$ solo arco uscente ($d_m = 1$) che punta direttamente ad $a$, trasportando tutta l'importanza di $m$.

Applicando la formula generale $r_j = \sum_{i \rightarrow j} \frac{r_i}{d_i}$ a ciascuno dei tre nodi (guardando quali frecce **entrano** in ogni nodo), si ottiene il seguente sistema di **equazioni di flusso** (_Flow equations_):

$$\begin{cases} r_y = \frac{r_y}{2} + \frac{r_a}{2} \\ r_a = \frac{r_y}{2} + r_m \\ r_m = \frac{r_a}{2} \end{cases}$$

Analizzando il sistema lineare ottenuto per i tre nodi ($r_y$, $r_a$, $r_m$), ci troviamo di fronte a **3 equazioni in 3 incognite, ma prive di termini noti costanti**.
Dal punto di vista algebrico, un sistema omogeneo di questo tipo comporta due conseguenze:
- **Nessuna soluzione unica (_No unique solution_):** esistono infinite soluzioni possibili.
- **Equivalenza a meno di un fattore di scala:** tutte le soluzioni sono equivalenti tra loro a meno di una costante moltiplicativa (_modulo the scale factor_), poiché se una terna di valori risolve il sistema, anche il suo doppio o il suo triplo lo risolve.

Per forzare l'esistenza di **una sola soluzione unica**, si introduce un **vincolo aggiuntivo di normalizzazione**, imponendo che la somma totale dei punteggi di PageRank di tutte le pagine del grafo sia esattamente uguale a $1$ (così da poter interpretare i punteggi come una distribuzione di probabilità):
$$r_y + r_a + r_m = 1$$

Risolvendo il sistema delle equazioni di flusso insieme a questo vincolo:
1. Dalla prima equazione $r_y = \frac{r_y}{2} + \frac{r_a}{2}$ si ricava subito che $\frac{r_y}{2} = \frac{r_a}{2}$, ovvero $r_y = r_a$.
    
2. Sapendo che $r_m = \frac{r_a}{2}$, possiamo sostituire tutto nel vincolo di somma pari a $1$:
$$
r_a + r_a + \frac{r_a}{2} = 1 \implies \frac{5}{2} r_a = 1 \implies r_a = \frac{2}{5}
$$    
3. Si ottiene così l'**unica soluzione esatta** del sistema:
$$r_y = \frac{2}{5}, \quad r_a = \frac{2}{5}, \quad r_m = \frac{1}{5}$$

> [!WARNING] Limite computazionale su scala Web Il metodo classico di risoluzione algebrica (come il **metodo di eliminazione di Gauss**, _Gaussian elimination_) funziona benissimo per piccoli esempi didattici da 3 o 4 nodi, ma è **totalmente inutilizzabile per grafi delle dimensioni del Web** (miliardi di pagine), poiché ha una complessità cubica rispetto al numero di nodi. Abbiamo quindi bisogno di una **nuova formulazione** più efficiente!
> 
>   

**Domanda: Illustrare il principio alla base del PageRank basandosi sulla formulazione di flusso. (Fatta da Lops)**
Il principio alla base del PageRank si fonda sulla modellazione dei documenti ipertestuali come un grafo orientato, in cui le singole pagine rappresentano i nodi e i link costituiscono gli archi. L'algoritmo determina l'importanza di una pagina web analizzando rigorosamente la topologia della rete e interpretando ogni collegamento come un "voto" di fiducia.

Secondo questo modello, l'autorevolezza di un nodo non dipende unicamente dalla quantità dei link in ingresso, ma possiede una natura intrinsecamente ricorsiva: una pagina accresce significativamente il proprio punteggio se viene puntata a sua volta da nodi altamente autorevoli. Questa dinamica viene tradotta nelle **equazioni di flusso**, le quali descrivono come l'importanza si propaghi e si distribuisca all'interno della rete, generando un sistema di equazioni lineari.

Tuttavia, risolvere analiticamente un simile sistema (ad esempio tramite metodi classici come l'eliminazione gaussiana) risulta computazionalmente impraticabile su scala reale. La presenza di un vastissimo quantitativo di documenti (milioni o miliardi di pagine) genererebbe un sistema di equazioni di dimensioni insostenibili, rendendo necessario il passaggio a una formulazione matriciale risolvibile tramite metodi iterativi più efficienti.


## Formulazione Matriciale
Per poter calcolare il PageRank su grafi con miliardi di pagine senza usare l'eliminazione di Gauss, si riscrive il modello a flusso ricorrendo all'algebra lineare e introducendo la **matrice di adiacenza stocastica $M$** (_Stochastic adjacency matrix $M$_).

Dato un grafo in cui la pagina $i$ possiede $d_i$ link in uscita (_out-links_), la matrice $M$ (di dimensione $N \times N$, dove $N$ è il numero di pagine) viene costruita secondo la seguente regola:

$$
M_{ji} = \begin{cases} \frac{1}{d_i} & \text{se } i \rightarrow j \text{ (esiste un link da } i \text{ verso } j\text{)} \\ 0 & \text{altrimenti} \end{cases}
$$

**Attenzione agli indici della matrice ($M_{ji}$):**
- Le **colonne ($i$)** rappresentano i nodi di **partenza** (le pagine che emettono i link).
- Le **righe ($j$)** rappresentano i nodi di **arrivo** (le pagine che ricevono i link).
- Poiché ogni pagina $i$ divide la propria importanza in $d_i$ parti uguali pari a $\frac{1}{d_i}$ lungo la propria colonna $i$, **la matrice $M$ è una matrice stocastica per colonne** (_column stochastic matrix_), il che significa che la somma degli elementi di ciascuna colonna è sempre uguale a $1$.

![[Pasted image 20261031175106.png]]
Riprendendo l'esempio a tre nodi ($y, a, m$), la matrice stocastica $M$ associata alle equazioni di flusso si costruisce colonna per colonna:
- **Colonna $y$ ($d_y = 2$):** $y$ punta a $y$ e ad $a$, quindi vale $\frac{1}{2}$ sulle righe $y$ e $a$, e $0$ sulla riga $m$.
- **Colonna $a$ ($d_a = 2$):** $a$ punta a $y$ e a $m$, quindi vale $\frac{1}{2}$ sulle righe $y$ e $m$, e $0$ sulla riga $a$.
- **Colonna $m$ ($d_m = 1$):** $m$ punta solo ad $a$, quindi vale $1$ sulla riga $a$, e $0$ sulle righe $y$ e $m$.
  
Se definiamo ora il **vettore di rank $r$** (_Rank vector $r$_) come un vettore colonna che contiene una componente per ciascuna pagina, dove $r_i$ è il punteggio di importanza della pagina $i$ e la somma di tutte le componenti vale $$\sum_i r_i = 1$$, l'intero sistema delle equazioni di flusso $$r_j = \sum_{i \rightarrow j} \frac{r_i}{d_i}$$ si riassume nella compatta **equazione matriciale**:
$$r = M \cdot r$$

## Spiegazione dell'esempio svolto: dal sistema di equazioni a         $r = M \cdot r$ 
![[Pasted image 20261031181756.png]]
Osservando il grafo di esempio composto dai tre nodi $y$, $a$ ed $m$, la tabella della matrice stocastica $M$ e il relativo sistema di equazioni di flusso:

$$\begin{cases} r_y = r_y / 2 + r_a / 2 \\ r_a = r_y / 2 + r_m \\ r_m = r_a / 2 \end{cases}$$

Per capire come si passa algebricamente da questo sistema di equazioni alla forma compatta matriciale, definiamo il **vettore di rank $r$** (_Rank vector $r$_) come un vettore colonna che possiede un'entrata per ciascuna pagina del grafo, dove $r_i$ rappresenta il punteggio di importanza della pagina $i$ e la somma di tutte le componenti è pari a $1$ ($\sum_i r_i = 1$):

$$M = \begin{pmatrix} 1/2 & 1/2 & 0 \\ 1/2 & 0 & 1 \\ 0 & 1/2 & 0 \end{pmatrix}, \quad r = \begin{pmatrix} r_y \\ r_a \\ r_m \end{pmatrix}$$

Proviamo ora a eseguire il prodotto riga per colonna tra la matrice $M$ e il vettore colonna $r$:
- **Controllo delle dimensioni:** la matrice $M$ ha dimensione $3 \times 3$ (3 righe per 3 colonne), mentre il vettore colonna $r$ ha dimensione $3 \times 1$ (3 righe per 1 colonna). Poiché i due indici interni coincidono ($3 = 3$), la moltiplicazione è ben definita e restituisce come risultato un nuovo vettore colonna di dimensione $3 \times 1$ (data dagli indici esterni).
- **Calcolo del prodotto riga per colonna ($M \cdot r$):** moltiplicando ciascuna riga di $M$ per l'unica colonna di $r$ si ottiene:
    - **Prima riga:** $\left(\frac{1}{2} \cdot r_y\right) + \left(\frac{1}{2} \cdot r_a\right) + \left(0 \cdot r_m\right) = \frac{1}{2}r_y + \frac{1}{2}r_a$
    - **Seconda riga:** $\left(\frac{1}{2} \cdot r_y\right) + \left(0 \cdot r_a\right) + \left(1 \cdot r_m\right) = \frac{1}{2}r_y + r_m$
    - **Terza riga:** $\left(0 \cdot r_y\right) + \left(\frac{1}{2} \cdot r_a\right) + \left(0 \cdot r_m\right) = \frac{1}{2}r_a$

Scrivendo per esteso l'uguaglianza ottenuta:
$$\underbrace{\begin{pmatrix} 1/2 & 1/2 & 0 \\ 1/2 & 0 & 1 \\ 0 & 1/2 & 0 \end{pmatrix}}_{M \ (3 \times 3)} \underbrace{\begin{pmatrix} r_y \\ r_a \\ r_m \end{pmatrix}}_{r \ (3 \times 1)} = \underbrace{\begin{pmatrix} \frac{1}{2}r_y + \frac{1}{2}r_a \\ \frac{1}{2}r_y + r_m \\ \frac{1}{2}r_a \end{pmatrix}}_{(3 \times 1)}$$

Come si nota confrontando il vettore appena calcolato con il sistema di partenza, **la moltiplicazione di $M$ per $r$ ci ha dato esattamente la parte destra del sistema di equazioni** di flusso. 
Poiché nel sistema di equazioni di flusso questa parte destra è uguale ai singoli punteggi di rank posti a sinistra dell'uguale ($r_y, r_a, r_m$), ovvero al vettore $r$ stesso, possiamo uguagliare il tutto:
$$\begin{pmatrix} r_y \\ r_a \\ r_m \end{pmatrix} = M \cdot r = \begin{pmatrix} r_y/2 + r_a/2 \\ r_y/2 + r_m \\ r_a/2 \end{pmatrix}$$

Si dimostra così che l'intero sistema delle equazioni di flusso $r_j = \sum_{i \rightarrow j} \frac{r_i}{d_i}$ può essere scritto nella forma matriciale compatta:
$$r = M \cdot r$$

---

## Interpretazione grafica del prodotto $M \cdot r = r$
![[Pasted image 20261031182327.png]]
Qui viene illustrato visivamente cosa accade a una singola pagina $i$ e a una pagina $j$ quando si esegue il prodotto matriciale $M \cdot r = r$ (che corrisponde all'equazione di flusso $r_j = \sum_{i \rightarrow j} \frac{r_i}{d_i}$):
- Supponiamo che la pagina $i$ abbia $3$ link uscenti ($d_i = 3$) che puntano a $3$ pagine diverse, inclusa la pagina $j$. 
- All'interno della matrice $M$, nella **colonna $i$** (che rappresenta le uscite dal nodo $i$) tutti gli elementi varranno $0$ tranne esattamente $3$ caselle (corrispondenti alle $3$ pagine puntate da $i$, tra cui la **riga $j$**), ciascuna delle quali conterrà il valore $\frac{1}{3}$.
- Quando moltiplichiamo la **riga $j$** della matrice $M$ per il vettore colonna $r$, il valore $\frac{1}{3}$ che si trova all'incrocio tra la riga $j$ e la colonna $i$ andrà a moltiplicare esattamente la componente $r_i$ del vettore $r$, sommando il contributo $\frac{1}{3} r_i$ dentro il risultato finale $r_j$.

---

## Formulazione agli Autovettori
Riprendiamo l'equazione matriciale a cui siamo giunti:
$$r = M \cdot r$$

![[Pasted image 20261031182629.png]]
Questo risultato ci ricorda un concetto fondamentale dell'algebra lineare:
Se avessimo un'equazione della forma $\lambda r = M r$ (o equivalentemente $A x = \lambda x$), in cui **uno scalare ($\lambda$) moltiplicato per un vettore ($r$) è uguale al risultato della moltiplicazione di una matrice ($M$) per quello stesso vettore ($r$)**, allora lo scalare $\lambda$ si chiama **autovalore** (_eigenvalue_) e il vettore $r$ si chiama **autovettore** (_eigenvector_).

Nel nostro caso specifico, poiché davanti al vettore $r$ a sinistra dell'uguale è sottinteso il coefficiente $1$, è possibile scrivere l'equazione come:
$$1 \cdot r = M \cdot r$$

Confrontando $1 \cdot r = M \cdot r$ con la definizione generale $\lambda r = M r$ (dove $\lambda = 1$), è possibile affermare che **il vettore $r$ (il vettore dei rank) è l'autovettore della matrice stocastica $M$ — che è la matrice di adiacenza che codifica il grafo — con autovalore $\lambda = 1$**.

> [!NOTES] Eleganza della formulazione algebrica e Autovettore Principale Facendo questo passaggio algebrico otteniamo una formulazione del PageRank molto più elegante: **il PageRank non è altro che l'autovettore della matrice stocastica $M$ che codifica il grafo, associato all'autovalore $1$**.
> 
>   
> 
> Più precisamente, $r$ è il **primo autovettore** o **autovettore principale** (_first or principal eigenvector_) della matrice $M$, ovvero quello corrispondente al suo autovalore più grande, che vale esattamente $1$:
> 
>   
> 
> - **Perché il più grande autovalore di $M$ vale $1$?** Perché la matrice $M$ è **stocastica per colonne** (_column stochastic_): sapendo che il vettore $r$ ha lunghezza unitaria (la somma dei suoi elementi è $1$) e che ciascuna colonna di $M$ somma a $1$, il prodotto $M r$ non può mai superare $1$ ($M r \le 1$).
>     
>       
>     

![[Pasted image 20261031183329.png]]
Riepilogando questa formulazione sull'esempio dei tre nodi ($y, a, m$), mostriamo come il sistema di equazioni di flusso si traduca direttamente nell'equazione agli autovettori $r = M \cdot r$:

$$\begin{bmatrix} y \\ a \\ m \end{bmatrix} = \begin{bmatrix} 1/2 & 1/2 & 0 \\ 1/2 & 0 & 1 \\ 0 & 1/2 & 0 \end{bmatrix} \begin{bmatrix} y \\ a \\ m \end{bmatrix}$$

Grazie a questa proprietà, non abbiamo più bisogno di risolvere il sistema con l'eliminazione di Gauss, ma possiamo calcolare in modo estremamente efficiente il vettore $r$ tramite un metodo numerico iterativo chiamato **Power Iteration** (metodo delle potenze).

## Il Metodo Power Iteration
Dato un grafo del Web con $N$ nodi (dove i nodi sono le pagine web e gli archi sono gli hyperlink), il metodo **Power Iteration** consiste in un semplice schema iterativo per trovare l'autovettore principale $r$.  

Supponendo che ci siano $N$ pagine web totali, l'algoritmo si articola in tre passi:
1. **Inizializzazione (_Initialize_):** al passo iniziale $t = 0$, non sapendo ancora quali pagine siano più importanti, si assegna a tutte le $N$ pagine esattamente la stessa importanza uguale a $\frac{1}{N}$, costruendo il vettore iniziale:
 $$r^{(0)} = \left[\frac{1}{N}, \dots, \frac{1}{N}\right]^T$$
    
2. **Iterazione (_Iterate_):** a ogni passo successivo $t + 1$, si calcola la nuova stima del vettore dei rank moltiplicando la matrice $M$ per il vettore $r^{(t)}$ ottenuto al passo precedente:
$$r^{(t+1)} = M \cdot r^{(t)}$$

    In termini dei singoli nodi, questo equivale a ricalcolare l'equazione di flusso usando i punteggi del passo $t$:
$$r_j^{(t+1)} = \sum_{i \rightarrow j} \frac{r_i^{(t)}}{d_i}$$
    dove $d_i$ è sempre il grado uscente (_out-degree_) del nodo $i$.
    
3. **Condizione di arresto (_Stop_):** si ripete il ciclo finché la differenza tra il vettore nuovo $r^{(t+1)}$ e il vettore precedente $r^{(t)}$ diventa più piccola di una soglia di tolleranza $\epsilon$ fissata (cioè quando i valori si stabilizzano e convergono):
    $$
    \left\vert{}r^{(t+1)} - r^{(t)}\right\vert{}_1 < \epsilon
    $$
    
> [!NOTES] Norma $L_1$ per il calcolo della distanza tra due iterazioni Nella condizione di arresto si utilizza la **norma $L_1$** (_$L_1$ norm_), definita come la somma dei valori assoluti delle componenti del vettore:
> 
>   
> 
> $$\vert{}x\vert{}_1 = \sum_{1 \le i \le N} \vert{}x_i\vert{}$$
> 
> In pratica, per verificare se l'algoritmo è arrivato a convergenza, si calcola per ogni pagina la differenza in valore assoluto $\left\vert{}r_i^{(t+1)} - r_i^{(t)}\right\vert{}$ tra il punteggio nuovo e quello vecchio, si sommano tutti gli scarti e si controlla che la somma sia inferiore a $\epsilon$. Al posto della norma $L_1$ è comunque possibile utilizzare qualsiasi altra norma vettoriale, come ad esempio la **distanza Euclidea** (norma $L_2$).
> 
>   

### Esempio: 

![[Pasted image 20261102143237.png]]
Per vedere concretamente come funziona il metodo delle potenze (**Power Iteration**), l'esempio mostra l'esecuzione passo dopo passo dell'algoritmo applicato al nostro grafo di esempio a $3$ nodi ($y, a, m$).

Lo schema operativo dell'algoritmo è il seguente:
- **Inizializzazione:** si imposta il valore iniziale di ciascun nodo a $r_j = \frac{1}{N}$ (dove $N$ è il numero totale di nodi del grafo).
- **Passo 1 (Calcolo del nuovo rank):** si calcola il nuovo punteggio $r'_j = \sum_{i \rightarrow j} \frac{r_i}{d_i}$ per ogni pagina $j$ (che in forma matriciale equivale a calcolare $r' = M \cdot r$).
- **Passo 2 (Aggiornamento):** si aggiorna il vettore dei rank sostituendo i vecchi valori con quelli appena calcolati ($r = r'$).
- **Controllo di convergenza:** se i valori non sono ancora arrivati a convergenza (_If not converged_), si torna al **Passo 1** e si ripete il ciclo.

Riprendiamo il grafo con i $3$ nodi ($y, a, m$), la sua matrice di adiacenza stocastica $M$ e le relative equazioni di flusso:

$$M = \begin{pmatrix} 1/2 & 1/2 & 0 \\ 1/2 & 0 & 1 \\ 0 & 1/2 & 0 \end{pmatrix}, \quad \begin{cases} r_y = r_y / 2 + r_a / 2 \\ r_a = r_y / 2 + r_m \\ r_m = r_a / 2 \end{cases}$$

#### Iterazione 0: Inizializzazione
Avendo $N = 3$ nodi nel grafo, all'inizio (Iterazione 0) impostiamo tutte le componenti del vettore $r^{(0)}$ a $\frac{1}{3}$:
$$
r^{(0)} = \begin{pmatrix} r_y \\ r_a \\ r_m \end{pmatrix} = \begin{pmatrix} 1/3 \\ 1/3 \\ 1/3 \end{pmatrix}
$$

In questa fase iniziale è come se tutti e $3$ i nodi avessero esattamente lo stesso _PageRank score_ ($\frac{1}{3}$). Si nota inoltre che la somma dei tre valori iniziali fa esattamente $1$ ($\frac{1}{3} + \frac{1}{3} + \frac{1}{3} = 1$), rispettando fin dal principio la condizione di unicità che avevamo imposto nelle equazioni di flusso.

#### Iterazione 1: Primo passo di calcolo
Eseguiamo ora la prima iterazione moltiplicando la matrice $M$ per il vettore iniziale 
$r^{(0)}$ ($r^{(1)} = M \cdot r^{(0)}$):

$$
r^{(1)} = \begin{pmatrix} 1/2 & 1/2 & 0 \\ 1/2 & 0 & 1 \\ 0 & 1/2 & 0 \end{pmatrix} \begin{pmatrix} 1/3 \\ 1/3 \\ 1/3 \end{pmatrix} = \begin{pmatrix} \left(\frac{1}{2} \cdot \frac{1}{3}\right) + \left(\frac{1}{2} \cdot \frac{1}{3}\right) + \left(0 \cdot \frac{1}{3}\right) \\ \left(\frac{1}{2} \cdot \frac{1}{3}\right) + \left(0 \cdot \frac{1}{3}\right) + \left(1 \cdot \frac{1}{3}\right) \\ \left(0 \cdot \frac{1}{3}\right) + \left(\frac{1}{2} \cdot \frac{1}{3}\right) + \left(0 \cdot \frac{1}{3}\right) \end{pmatrix} = \begin{pmatrix} \frac{1}{6} + \frac{1}{6} + 0 \\ \frac{1}{6} + 0 + \frac{1}{3} \\ 0 + \frac{1}{6} + 0 \end{pmatrix} = \begin{pmatrix} 1/3 \\ 3/6 \\ 1/6 \end{pmatrix}
$$

**Osservazione sull'Iterazione 1:** Confrontando il nuovo vettore $r^{(1)}$ con lo score iniziale (che era uguale a $\frac{1}{3}$ per tutti i nodi), notiamo subito come la struttura dei link inizi a modificare i pesi:
- Lo score del primo nodo ($y$) è rimasto **uguale** ($\frac{2}{6} = \frac{1}{3}$).
- Lo score del secondo nodo ($a$) è **aumentato**, passando da $\frac{1}{3}$ a $\frac{3}{6}$ (ovvero $\frac{1}{2}$).
- Lo score del terzo nodo ($m$) è **diminuito**, scendendo da $\frac{1}{3}$ a $\frac{1}{6}$.

#### Iterazione 2
Poiché il vettore è cambiato rispetto al passo precedente, non siamo ancora a convergenza. Nella seconda iterazione moltiplichiamo la matrice $M$ per il nuovo vettore appena ottenuto $r^{(1)}$, ricavando il vettore $r^{(2)}$ ($r^{(2)} = M \cdot r^{(1)}$):

$$
r^{(2)} = \begin{pmatrix} 1/2 & 1/2 & 0 \\ 1/2 & 0 & 1 \\ 0 & 1/2 & 0 \end{pmatrix} \begin{pmatrix} 1/3 \\ 3/6 \\ 1/6 \end{pmatrix} = \begin{pmatrix} \left(\frac{1}{2} \cdot \frac{1}{3}\right) + \left(\frac{1}{2} \cdot \frac{3}{6}\right) + \left(0 \cdot \frac{1}{6}\right) \\ \left(\frac{1}{2} \cdot \frac{1}{3}\right) + \left(0 \cdot \frac{3}{6}\right) + \left(1 \cdot \frac{1}{6}\right) \\ \left(0 \cdot \frac{1}{3}\right) + \left(\frac{1}{2} \cdot \frac{3}{6}\right) + \left(0 \cdot \frac{1}{6}\right) \end{pmatrix} = \begin{pmatrix} \frac{1}{6} + \frac{3}{12} \\ \frac{1}{6} + \frac{1}{6} \\ \frac{3}{12} \end{pmatrix} = \begin{pmatrix} 5/12 \\ 1/3 \\ 3/12 \end{pmatrix}
$$

#### Iterazione 3:
Eseguiamo una terza iterata moltiplicando nuovamente $M$ per il vettore $r^{(2)}$ appena trovato ($r^{(3)} = M \cdot r^{(2)}$):
$$
r^{(3)} = \begin{pmatrix} 1/2 & 1/2 & 0 \\ 1/2 & 0 & 1 \\ 0 & 1/2 & 0 \end{pmatrix} \begin{pmatrix} 5/12 \\ 1/3 \\ 3/12 \end{pmatrix} = \begin{pmatrix} \left(\frac{1}{2} \cdot \frac{5}{12}\right) + \left(\frac{1}{2} \cdot \frac{1}{3}\right) + \left(0 \cdot \frac{3}{12}\right) \\ \left(\frac{1}{2} \cdot \frac{5}{12}\right) + \left(0 \cdot \frac{1}{3}\right) + \left(1 \cdot \frac{3}{12}\right) \\ \left(0 \cdot \frac{5}{12}\right) + \left(\frac{1}{2} \cdot \frac{1}{3}\right) + \left(0 \cdot \frac{3}{12}\right) \end{pmatrix} = \begin{pmatrix} \frac{5}{24} + \frac{4}{24} \\ \frac{5}{24} + \frac{6}{24} \\ \frac{1}{6} \end{pmatrix} = \begin{pmatrix} 9/24 \\ 11/24 \\ 1/6 \end{pmatrix}
$$

#### Convergenza e stabilizzazione del PageRank 
Continuando a iterare questo procedimento per un numero sufficiente di passi, la sequenza dei vettori si assesta sui valori finali mostrati nella Slide 29:

$$
\begin{equation*}
\begin{pmatrix} r_y \\ r_a \\ r_m \end{pmatrix} = 
\underbrace{\begin{matrix} \mathbf{1/3} \\ \mathbf{1/3} \\ \mathbf{1/3} \end{matrix}}_{\text{Iter. 0}} \quad
\underbrace{\begin{matrix} 1/3 \\ \mathbf{3/6} \\ 1/6 \end{matrix}}_{\text{Iter. 1}} \quad
\underbrace{\begin{matrix} 5/12 \\ \mathbf{1/3} \\ \mathbf{3/12} \end{matrix}}_{\text{Iter. 2}} \quad
\underbrace{\begin{matrix} 9/24 \\ 11/24 \\ 1/6 \end{matrix}}_{\text{Iter. 3}} \quad
\dots \quad
\underbrace{\begin{matrix} \mathbf{6/15} \\ \mathbf{6/15} \\ \mathbf{3/15} \end{matrix}}_{\text{Convergenza}}
\end{equation*}
$$

Se semplifichiamo le frazioni del vettore finale dividendo numeratore e denominatore per $3$, otteniamo esattamente:

$$r = \begin{pmatrix} 6/15 \\ 6/15 \\ 3/15 \end{pmatrix} = \begin{pmatrix} \mathbf{2/5} \\ \mathbf{2/5} \\ \mathbf{1/5} \end{pmatrix}$$

Questi sono **esattamente gli stessi valori** ($r_y = \frac{2}{5}, r_a = \frac{2}{5}, r_m = \frac{1}{5}$) che avevamo trovato in precedenza risolvendo a mano il sistema delle equazioni di flusso.

> [!NOTES] Equivalenza dei metodi e Stabilizzazione del vettore
> 
>   
> 
> 1. **Stesso risultato con due metodi diversi:** notiamo che sia risolvendo algebricamente le **equazioni di flusso**, sia calcolando l'**autovettore principale** attraverso il meccanismo iterativo dell'algoritmo **Power Iteration** (metodo delle potenze), otteniamo esattamente lo stesso risultato. La differenza fondamentale è che la _Power Iteration_ richiede solo prodotti matrice-vettore ed è quindi applicabile su scala Web.
>     
>       
>     
> 2. **Cosa succede dopo la convergenza?** Una volta che il risultato si è stabilizzato su $\left[\frac{2}{5}, \frac{2}{5}, \frac{1}{5}\right]^T$, se proviamo a moltiplicare nuovamente la matrice $M$ per questo vettore, **il risultato non cambierà più**:
>     
>       
>     
>     $$\begin{pmatrix} 1/2 & 1/2 & 0 \\ 1/2 & 0 & 1 \\ 0 & 1/2 & 0 \end{pmatrix} \begin{pmatrix} 2/5 \\ 2/5 \\ 1/5 \end{pmatrix} = \begin{pmatrix} \frac{1}{5} + \frac{1}{5} \\ \frac{1}{5} + \frac{1}{5} \\ \frac{1}{5} \end{pmatrix} = \begin{pmatrix} 2/5 \\ 2/5 \\ 1/5 \end{pmatrix}$$
>     
>     In questo momento il PageRank ha raggiunto il punto fisso ($r = M \cdot r$), si è stabilizzato e assume valori costanti che non variano più nelle iterazioni successive.
>     
>       
>     

### Significato operativo di $M \cdot r$: simulare un passo di visita del grafo
Che cosa significa, da un punto di vista pratico e operativo, moltiplicare a ogni iterazione la matrice $M$ per il vettore $r$?

![[Pasted image 20261102144639.png]]
Poiché la matrice stocastica $M$ è la codifica matematica delle connessioni del grafo, **ogni moltiplicazione $M \cdot r$ simula esattamente un passo di visita all'interno del grafo**:
- **Se mi trovo nel nodo $y$** (prima colonna di $M$: $\left[\frac{1}{2}, \frac{1}{2}, 0\right]^T$): siccome dal nodo $y$ partono due link uscenti, facendo un passo di navigazione ho metà probabilità ($\frac{1}{2}$) di restare in $y$ (attraverso il _self-loop_) e metà probabilità ($\frac{1}{2}$) di spostarmi verso il nodo $a$, mentre non posso andare direttamente in $m$ ($0$).
- **Se mi trovo nel nodo $a$** (seconda colonna di $M$: $\left[\frac{1}{2}, 0, \frac{1}{2}\right]^T$): attraverso il meccanismo della moltiplicazione sto dicendo che dal nodo $a$, avendo due link uscenti verso $y$ ed $m$, posso spostarmi per metà ($\frac{1}{2}$) verso il nodo $y$ e per metà ($\frac{1}{2}$) verso il nodo $m$.
- **Se mi trovo nel nodo $m$** (terza colonna di $M$: $\left[0, 1, 0\right]^T$): avendo un unico link uscente che punta ad $a$, dal nodo $m$ sono obbligato a spostarmi al 100% ($1$) verso il nodo $a$.

#### Perché il nodo $m$ ha la metà del PageRank rispetto a $y$ e $a$?
Guardando la topologia del grafoe i risultati finali ($r_y = \frac{2}{5}$, $r_a = \frac{2}{5}$, $r_m = \frac{1}{5}$), possiamo trarre una conclusione molto intuitiva:
- Il nodo **$m$** possiede **un solo link in entrata** (quello che proviene da $a$, il quale per giunta divide il suo flusso a metà tra $y$ ed $m$), mentre sia $y$ che $a$ ricevono due link in entrata ciascuno.
- Di conseguenza, essendo un nodo meno connesso in ingresso, **$m$ ottiene un PageRank pari a $\frac{1}{5}$, ovvero esattamente la metà rispetto agli altri due nodi** ($\frac{2}{5}$ ciascuno).
- Seguendo il meccanismo probabilistico dei link durante la visita del grafo, **è molto più probabile arrivare (e trovarsi) sul nodo $y$ o sul nodo $a$ rispetto che sul nodo $m$**.

## Random Walk
Oltre alla vista algebrica basata sulle equazioni di flusso e sugli autovettori, il funzionamento del PageRank può essere compreso in modo estremamente intuitivo attraverso un'interpretazione probabilistica chiamata **Random Walk**.

Un processo di _Random Walk_ consiste letteralmente nell'**andare a caso per la rete viaggiando attraverso i link**. Per modellare questo processo, immaginiamo il comportamento di un **navigatore casuale del Web** (_random web surfer_) che si muove nel grafo secondo queste regole:
- **Al tempo $t$:** il navigatore si trova su una certa pagina $i$ del grafo.
- **Al tempo $t+1$:** il navigatore sceglie e segue **un link uscente (_out-link_) dalla pagina $i$ in modo totalmente casuale e con probabilità uniforme** (_uniformly at random_). Se la pagina $i$ ha grado uscente $d_{\text{out}}(i)$, ogni link uscente ha la stessa probabilità $\frac{1}{d_{\text{out}}(i)}$ di essere cliccato.
- **Arrivo:** il navigatore finisce così su una pagina $j$ puntata da $i$ ($i \rightarrow j$).
- **Ripetizione:** questo processo di navigazione casuale si ripete all'infinito (_repeats indefinitely_).

$$r_j = \sum_{i \rightarrow j} \frac{r_i}{d_{\text{out}}(i)}$$

Per descrivere matematicamente la posizione del navigatore durante il suo percorso, definiamo il vettore **$p(t)$**:
- **$p(t)$** è un vettore la cui $i$-esima coordinata rappresenta la **probabilità che il navigatore casuale si trovi esattamente sulla pagina $i$ all'istante di tempo $t$**.
- Di conseguenza, il vettore $p(t)$ costituisce a tutti gli effetti una **distribuzione di probabilità sulle pagine** del Web (_probability distribution over pages_, in cui tutti i valori sono compresi tra $0$ e $1$ e la loro somma totale fa $1$).

> [!NOTES] Significato pratico del Random Walk: il legame tra visite, connettività e PageRank Immaginiamo concretamente questo navigatore casuale che, partendo da una pagina web qualsiasi e seguendo il meccanismo dei link, continua a muoversi nella rete:
> 
>   
> 
>Supponiamo ad esempio di aver fatto **un milione di visite** muovendoci con il meccanismo dei link e chiediamoci: _quante volte abbiamo visitato ogni singola pagina?_ Contando quante volte siamo passati su ciascuna pagina rispetto al totale dei passi effettuati, otteniamo la frequenza relativa di visita.
>     
>       
>     
>Il vettore delle probabilità $p(t)$ ci dice qual è la **probabilità di fermarci (o trovarci) su una certa pagina**, il che corrisponde esattamente a quante volte abbiamo visitato quella pagina nel nostro lungo processo di navigazione.
>     
>       
>     
>Seguendo il meccanismo dei link otteniamo la probabilità di visita (ovvero il **PageRank**) per ogni singola pagina. Se una pagina è **molto connessa**, cioè possiede molti link entranti (come il nodo $j$, che riceve archi dai nodi $i_1, i_2, i_3$) oppure riceve link da pagine a loro volta molto frequentate, chiaramente durante la navigazione casuale **entreremo in quella pagina molto più spesso** rispetto a una pagina isolata o periferica; di conseguenza, la sua probabilità di visita (e quindi il suo PageRank) sarà molto alta.
>     ![[Pasted image 20261102221653.png]]
>       
>     

## La Distribuzione Stazionaria (_The Stationary Distribution_)
Chiediamoci ora: se conosciamo la distribuzione di probabilità $p(t)$ al tempo $t$, **dove si troverà il navigatore casuale all'istante successivo $t+1$?**

Poiché a ogni passo il navigatore sceglie un link uscente in modo uniforme e casuale (secondo le probabilità di transizione codificate nella matrice stocastica $M$), la distribuzione di probabilità $p(t+1)$ al passo $t+1$ si ottiene semplicemente moltiplicando la matrice $M$ per il vettore $p(t)$:

$$
p(t+1) = M \cdot p(t)
$$
Supponiamo che, passo dopo passo, la passeggiata casuale raggiunga uno stato di equilibrio in cui applicare un ulteriore passo di navigazione non modifica più le probabilità:

$$
p(t+1) = M \cdot p(t) = p(t)
$$

Quando si verifica questa condizione di punto fisso, il vettore $p(t)$ prende il nome di **distribuzione stazionaria** (_stationary distribution_) della passeggiata casuale.

### Il PageRank come Distribuzione Stazionaria

Confrontando questa equazione con la formulazione matriciale del PageRank, notiamo un'identità fondamentale:
- Il nostro vettore originale dei rank **$r$** soddisfa esattamente l'equazione **$r = M \cdot r$**.
- Pertanto, **il vettore di PageRank $r$ non è altro che la distribuzione stazionaria della passeggiata casuale (_random walk_) sul grafo del Web**! Il punteggio di PageRank $r_i$ di una pagina $i$ misura esattamente la probabilità a lungo termine che un navigatore casuale, cliccando link all'infinito, si trovi su quella pagina in un dato istante.


### Esistenza e Unicità della soluzione (_Existence and Uniqueness_)

Dal punto di vista matematico, un risultato centrale della teoria delle passeggiate casuali note in calcolo delle probabilità anche come **processi di Markov** o **catene di Markov**. garantisce una proprietà fondamentale per il funzionamento dell'algoritmo:
> [!NOTES] Teorema di Esistenza e Unicità (Processi di Markov) Per i grafi che soddisfano determinate condizioni strutturali, **la distribuzione stazionaria $r$ è unica** e **verrà inevitabilmente raggiunta** (tramite le iterazioni di $p(t+1) = M \cdot p(t)$) **indipendentemente da quale sia la distribuzione di probabilità iniziale scelta al tempo $t = 0$**.
> 
>   

Questo risultato teorico spiega perché nel metodo _Power Iteration_ possiamo partire da un vettore iniziale $r^{(0)} = \left[\frac{1}{N}, \dots, \frac{1}{N}\right]^T$ qualsiasi: se il grafo rispetta le condizioni richieste dai processi di Markov, siamo certi che l'algoritmo convergerà sempre verso l'unico vero vettore di PageRank.


---


# PageRank: La Formulazione di Google

## Le Tre Domande Fondamentali sul PageRank 

Fino a questo punto abbiamo definito il calcolo del PageRank attraverso il metodo iterativo delle potenze (*Power Iteration*) basato sull'equazione di flusso:

$$r_j^{(t+1)} = \sum_{i \rightarrow j} \frac{r_i^{(t)}}{d_i}$$

oppure, in maniera del tutto equivalente, nella forma matriciale compatta:

$$r = M r$$

Prima di poter applicare questa formula al Web reale (da cui nasce la **Formulazione di Google**, *The Google Formulation*), dobbiamo però porci **tre domande fondamentali** sul comportamento di questo processo iterativo:
1. **Converge sempre? (*Does this converge?*)** Siamo sicuri che, continuando a moltiplicare $M$ per $r$, i numeri si stabilizzino sempre su un valore fisso senza oscillare all'infinito?
2. **Converge a ciò che vogliamo? (*Does it converge to what we want?*)** Anche ammesso che i valori si fermino e convergano, il vettore finale che otteniamo ha senso o rischia di annullarsi?
3. **I risultati ottenuti sono ragionevoli? (*Are results reasonable?*)** I punteggi finali rispecchiano davvero la reale importanza delle pagine sul Web?

Come vedremo subito con degli esempi pratici, applicando la formula base $r = M r$ a grafi generici la risposta a queste domande è **negativa**, a causa di due gravi problemi strutturali del Web: le **Spider Traps** e i **Dead Ends**.

## 1° Problema: Converge sempre? Il caso delle "Spider Trap"
Analizziamo la prima domanda (*Does this converge?*) considerando un grafo semplicissimo composto da soli due nodi $a$ e $b$ che puntano esclusivamente l'uno verso l'altro ($a \rightarrow b$ e $b \rightarrow a$), configurando il problema della **"Spider trap"** (trappola per ragni/crawler) o comportamento periodico:
* Il nodo $a$ ha un solo link uscente che va in $b$ ($d_a = 1$), quindi cede tutto il suo punteggio a $b$ ($r_b^{(t+1)} = r_a^{(t)}$).
* Il nodo $b$ ha un solo link uscente che va in $a$ ($d_b = 1$), quindi cede tutto il suo punteggio ad $a$ ($r_a^{(t+1)} = r_b^{(t)}$).

Supponiamo di far partire l'algoritmo all'Iterazione 0 assegnando tutta l'importanza iniziale al nodo $a$ ($r_a = 1$) e zero al nodo $b$ ($r_b = 0$):
* **Iterazione 0:** $r^{(0)} = \begin{bmatrix} 1 \\ 0 \end{bmatrix}$.
* **Iterazione 1:** il flusso di $a$ passa interamente a $b$, quindi $r^{(1)} = \begin{bmatrix} 0 \\ 1 \end{bmatrix}$.
* **Iterazione 2:** il flusso di $b$ torna interamente ad $a$, quindi $r^{(2)} = \begin{bmatrix} 1 \\ 0 \end{bmatrix}$.
* **Iterazione 3:** il flusso ripassa a $b$, quindi $r^{(3)} = \begin{bmatrix} 0 \\ 1 \end{bmatrix}$.

$$\begin{bmatrix} r_a \\ r_b \end{bmatrix} = \underbrace{\begin{matrix} 1 \\ 0 \end{matrix}}_{\text{Iter. } 0} \quad \underbrace{\begin{matrix} 0 \\ 1 \end{matrix}}_{\text{Iter. } 1} \quad \underbrace{\begin{matrix} 1 \\ 0 \end{matrix}}_{\text{Iter. } 2} \quad \underbrace{\begin{matrix} 0 \\ 1 \end{matrix}}_{\text{Iter. } 3} \quad \dots$$
![[Pasted image 20261103125104.png]]

**Conclusione:** In una situazione ciclica di questo tipo, i punteggi rimbalzano all'infinito tra $a$ e $b$ alternando $[1, 0]^T$ e $[0, 1]^T$: **l'algoritmo oscilla per sempre e non converge mai**!

## 2° Problema: Converge a ciò che vogliamo? Il caso dei "Dead End" 
Analizziamo ora la seconda domanda (*Does it converge to what we want?*) osservando cosa accade quando nel grafo è presente un **"Dead end"** (vicolo cieco), ovvero un nodo che riceve link in ingresso ma **non ha alcun link in uscita**:
* Consideriamo due nodi $a$ e $b$ in cui $a$ punta a $b$ ($a \rightarrow b$), ma **$b$ non punta a nulla** ($d_b = 0$).
* Di conseguenza, le equazioni di flusso dicono che $r_b^{(t+1)} = r_a^{(t)}$ (perché $b$ riceve da $a$), mentre $r_a^{(t+1)} = 0$ (perché nessun nodo punta ad $a$).

Partendo anche qui dal vettore iniziale $r^{(0)} = \begin{bmatrix} 1 \\ 0 \end{bmatrix}$:

* **Iterazione 0:** $r^{(0)} = \begin{bmatrix} 1 \\ 0 \end{bmatrix}$.

* **Iterazione 1:** l'importanza di $a$ passa a $b$, mentre $a$ non riceve nulla e scende a $0$, ottenendo $r^{(1)} = \begin{bmatrix} 0 \\ 1 \end{bmatrix}$.

* **Iterazione 2:** poiché $b$ non ha archi uscenti, la sua importanza pari a $1$ non può andare da nessuna parte e sparisce nel nulla; sia $a$ che $b$ si ritrovano con $0$, ottenendo $r^{(2)} = \begin{bmatrix} 0 \\ 0 \end{bmatrix}$.

* **Iterazioni successive:** da questo momento in poi il vettore rimane bloccato su $\begin{bmatrix} 0 \\ 0 \end{bmatrix}$ per sempre.



$$\begin{bmatrix} r_a \\ r_b \end{bmatrix} = \underbrace{\begin{matrix} 1 \\ 0 \end{matrix}}_{\text{Iter. } 0} \quad \underbrace{\begin{matrix} 0 \\ 1 \end{matrix}}_{\text{Iter. } 1} \quad \underbrace{\begin{matrix} 0 \\ 0 \end{matrix}}_{\text{Iter. } 2} \quad \underbrace{\begin{matrix} 0 \\ 0 \end{matrix}}_{\text{Iter. } 3} \quad \dots$$

**Conclusione:** In questo caso l'algoritmo converge (si ferma su $[0, 0]^T$), ma **non converge affatto a ciò che vogliamo**, perché tutta l'importanza del grafo è andata perduta azzerando il PageRank di tutte le pagine!

## La Struttura del Web ("Bow-Tie") e i 2 Problemi del PageRank
![[Pasted image 20261103125007.png]]
Nella realtà il grafo del Web non è un blocco unico perfettamente connesso, ma presenta una celebre struttura a "farfallino" o papillon (*bow-tie structure*), illustrata nello schema:
* **SCC (*Strongly Connected Core*):** è il cuore centrale fortemente connesso del Web, in cui ogni pagina può raggiungere qualunque altra pagina seguendo i link.
* **IN:** è la parte sinistra del grafo composta da pagine che possono raggiungere il nucleo centrale *SCC* tramite link uscenti, ma non possono essere raggiunte partendo dall'*SCC*.
* **OUT:** è la parte destra composta da pagine che vengono raggiunte partendo dal nucleo *SCC*, ma che non possiedono link per tornare indietro dentro l'*SCC*.
* **TENDRILS (Tentacoli), TUBES (Tubi) e Disconnected components:** sono diramazioni periferiche che partono da *IN* o entrano in *OUT* senza passare dal centro (*Tendrils*), passaggi diretti che collegano *IN* a *OUT* saltando il nucleo (*Tubes*), oppure isole di pagine completamente scollegate dal resto del Web (*Disconnected components*).



A causa di questa topologia complessa, il calcolo del PageRank deve fare i conti con **2 problemi strutturali fondamentali**:

1. **Dead ends (Vicoli ciechi):** alcune pagine non hanno alcun link in uscita (*have no out-links*); queste pagine funzionano come degli scarichi che **fanno "fuoriuscire" e disperdere l'importanza** fuori dal grafo (*cause importance to "leak out"*) fino ad azzerare i punteggi.


2. **Spider traps (Trappole per spider):** sono gruppi di una o più pagine i cui **link in uscita puntano tutti esclusivamente all'interno del gruppo stesso** (*all out-links are within the group*), senza alcun link che permetta di uscire verso il resto del Web; a lungo andare, **le spider traps assorbono tutta l'importanza del grafo** (*eventually spider traps absorb all importance*), lasciando a zero tutte le altre pagine.



## Analisi dettagliata del problema 1: Spider Traps e Soluzione

### Esempio numerico di una Spider Trap sul grafo a 3 nodi
![[Pasted image 20261103125207.png]]

Riprendiamo il nostro grafo a 3 nodi ($y, a, m$), ma modifichiamo il link uscente del nodo $m$: invece di tornare verso $a$, supponiamo che **il nodo $m$ punti solo a se stesso** ($m \rightarrow m$, formando un *self-loop* chiuso da cui non si può più uscire). Il nodo $m$ è diventato una **Spider Trap**!

La nuova matrice stocastica $M$ (dove la colonna $m$ ha ora $1$ sulla riga $m$) e le nuove equazioni di flusso diventano:

$$M = \begin{pmatrix} 1/2 & 1/2 & 0 \\ 1/2 & 0 & 0 \\ 0 & 1/2 & 1 \end{pmatrix}, \quad \begin{cases} r_y = r_y / 2 + r_a / 2 \\ r_a = r_y / 2 \\ r_m = r_a / 2 + r_m \end{cases}$$

Applichiamo il metodo **Power Iteration** partendo come sempre dalla distribuzione uniforme $r^{(0)} = \left[\frac{1}{3}, \frac{1}{3}, \frac{1}{3}\right]^T$ (la cui somma totale dei rank vale $\sum r_j = 1$):

* **Iterazione 0:** $r^{(0)} = \begin{bmatrix} 1/3 \\ 1/3 \\ 1/3 \end{bmatrix}$.


* **Iterazione 1 ($M \cdot r^{(0)}$):**
* $r_y^{(1)} = \frac{1}{2}\left(\frac{1}{3}\right) + \frac{1}{2}\left(\frac{1}{3}\right) = \frac{2}{6}$

* $r_a^{(1)} = \frac{1}{2}\left(\frac{1}{3}\right) = \frac{1}{6}$

* $r_m^{(1)} = \frac{1}{2}\left(\frac{1}{3}\right) + 1\left(\frac{1}{3}\right) = \frac{1}{6} + \frac{2}{6} = \frac{3}{6}$


* **Iterazione 2 ($M \cdot r^{(1)}$):**
* $r_y^{(2)} = \frac{1}{2}\left(\frac{2}{6}\right) + \frac{1}{2}\left(\frac{1}{6}\right) = \frac{3}{12}$

* $r_a^{(2)} = \frac{1}{2}\left(\frac{2}{6}\right) = \frac{2}{12}$

* $r_m^{(2)} = \frac{1}{2}\left(\frac{1}{6}\right) + 1\left(\frac{3}{6}\right) = \frac{1}{12} + \frac{6}{12} = \frac{7}{12}$


* **Iterazione 3 ($M \cdot r^{(2)}$):**
* $r_y^{(3)} = \frac{1}{2}\left(\frac{3}{12}\right) + \frac{1}{2}\left(\frac{2}{12}\right) = \frac{5}{24}$

* $r_a^{(3)} = \frac{1}{2}\left(\frac{3}{12}\right) = \frac{3}{24}$

* $r_m^{(3)} = \frac{1}{2}\left(\frac{2}{12}\right) + 1\left(\frac{7}{12}\right) = \frac{2}{24} + \frac{14}{24} = \frac{16}{24}$

$$\begin{bmatrix} r_y \\ r_a \\ r_m \end{bmatrix} = \underbrace{\begin{matrix} 1/3 \\ 1/3 \\ 1/3 \end{matrix}}_{\text{Iter. } 0} \quad \underbrace{\begin{matrix} 2/6 \\ 1/6 \\ 3/6 \end{matrix}}_{\text{Iter. } 1} \quad \underbrace{\begin{matrix} 3/12 \\ 2/12 \\ 7/12 \end{matrix}}_{\text{Iter. } 2} \quad \underbrace{\begin{matrix} 5/24 \\ 3/24 \\ 16/24 \end{matrix}}_{\text{Iter. } 3} \quad \dots \quad \underbrace{\begin{matrix} \mathbf{0} \\ \mathbf{0} \\ \mathbf{1} \end{matrix}}_{\text{Convergenza}}$$

**Cosa è successo?** A ogni passo $m$ riceve metà del punteggio di $a$ e si tiene stretto tutto il proprio punteggio senza restituire mai nulla indietro; all'infinito, **$m$ assorbe il 100% dell'importanza ($r_m = 1$), mentre $y$ e $a$ si svuotano completamente scendendo a $0$** ($r_y = 0, r_a = 0$)!

### La Soluzione di Google per le Spider Traps: Random Teleports
Per impedire che il navigatore casuale (*random surfer*) rimanga intrappolato per sempre dentro una *spider trap*, Google ha introdotto il meccanismo dei **Random Teleports** (teletrasporti casuali).
Ad ogni singolo passo temporale (*time step*), il navigatore casuale ha a disposizione **due opzioni** governate da una probabilità $\beta$ (detta anche *damping factor* o fattore di smorzamento):
* **Con probabilità $\beta$:** il navigatore si comporta normalmente e **segue a caso uno dei link uscenti** dalla pagina in cui si trova.
* **Con probabilità $1 - \beta$:** il navigatore ignora i link della pagina corrente e **salta (si "teletrasporta") su una pagina qualsiasi dell'intero Web scelta a caso** con probabilità uniforme (frecce verdi tratteggiate nello schema della slide 39).
* **Valori tipici di $\beta$:** nella pratica, i valori comunemente usati per $\beta$ sono compresi nell'intervallo tra **$0.8$ e $0.9$** (ad esempio $\beta = 0.85$, il che significa che nell'85% dei casi il navigatore clicca un link della pagina e nel restante 15% dei casi digita un nuovo indirizzo casuale nella barra del browser teletrasportandosi altrove).

Grazie a questo stratagemma, anche se il navigatore finisce dentro una *spider trap* come il nodo $m$, **nel giro di pochi passi temporali si teletrasporterà fuori dalla trappola** (*Surfer will teleport out of spider trap within a few time steps*) rimettendo in circolo l'importanza in tutto il grafo.

## Analisi dettagliata del problema 2: Dead Ends e Soluzione
### Esempio numerico di un Dead End sul grafo a 3 nodi (Slide 40)
Vediamo ora cosa accade sullo stesso grafo a 3 nodi ($y, a, m$) se rimuoviamo anche il cappio su $m$, facendo in modo che **il nodo $m$ non abbia nessun link uscente** ($d_m = 0$). Il nodo $m$ diventa così un **Dead End** (vicolo cieco).
Guardando la matrice $M$ e le equazioni di flusso nella slide 40, notiamo un fatto gravissimo: **la colonna relativa a $m$ è composta interamente da zeri** ($\left[0, 0, 0\right]^T$), quindi la somma della colonna $m$ fa $0$ anziché $1$ e **la matrice $M$ non è più stocastica per colonne**!

$$M = \begin{pmatrix} 1/2 & 1/2 & 0 \\ 1/2 & 0 & 0 \\ 0 & 1/2 & 0 \end{pmatrix}, \quad \begin{cases} r_y = r_y / 2 + r_a / 2 \\ r_a = r_y / 2 \\ r_m = r_a / 2 \end{cases}$$

Eseguendo le iterazioni della **Power Iteration** a partire da $r^{(0)} = \left[\frac{1}{3}, \frac{1}{3}, \frac{1}{3}\right]^T$:

* **Iterazione 0:** $r^{(0)} = \begin{bmatrix} 1/3 \\ 1/3 \\ 1/3 \end{bmatrix}$ (somma $= 1$).


* **Iterazione 1 ($M \cdot r^{(0)}$):** $r_y^{(1)} = \frac{1}{6} + \frac{1}{6} = \frac{2}{6}$, $r_a^{(1)} = \frac{1}{6}$, $r_m^{(1)} = \frac{1}{6}$ (la somma totale è già scesa a $\frac{4}{6}$, perché il $\frac{1}{3}$ che stava in $m$ è sparito!).


* **Iterazione 2 ($M \cdot r^{(1)}$):** $r_y^{(2)} = \frac{2}{12} + \frac{1}{12} = \frac{3}{12}$, $r_a^{(2)} = \frac{2}{12}$, $r_m^{(2)} = \frac{1}{12}$ (somma scesa a $\frac{6}{12} = \frac{1}{2}$).


* **Iterazione 3 ($M \cdot r^{(2)}$):** $r_y^{(3)} = \frac{3}{24} + \frac{2}{24} = \frac{5}{24}$, $r_a^{(3)} = \frac{3}{24}$, $r_m^{(3)} = \frac{2}{24}$ (somma scesa a $\frac{10}{24}$).



$$\begin{bmatrix} r_y \\ r_a \\ r_m \end{bmatrix} = \underbrace{\begin{matrix} 1/3 \\ 1/3 \\ 1/3 \end{matrix}}_{\text{Iter. } 0} \quad \underbrace{\begin{matrix} 2/6 \\ 1/6 \\ 1/6 \end{matrix}}_{\text{Iter. } 1} \quad \underbrace{\begin{matrix} 3/12 \\ 2/12 \\ 1/12 \end{matrix}}_{\text{Iter. } 2} \quad \underbrace{\begin{matrix} 5/24 \\ 3/24 \\ 2/24 \end{matrix}}_{\text{Iter. } 3} \quad \dots \quad \underbrace{\begin{matrix} \mathbf{0} \\ \mathbf{0} \\ \mathbf{0} \end{matrix}}_{\text{Convergenza}}$$

**Cosa è successo?** Ad ogni iterazione, la quota di PageRank che entra nel nodo $m$ non può più uscire e "gocciola fuori" dal sistema; procedendo con le iterazioni, **tutti i punteggi convergono a $[0, 0, 0]^T$**!

### La Soluzione per i Dead Ends: Teletrasportarsi Sempre
Come si comporta un navigatore quando finisce su una pagina *dead-end* che non ha nessun link su cui cliccare? L'unica cosa che può fare è **teletrasportarsi sempre con probabilità $1.0$ (100%)** verso una pagina qualsiasi del grafo scelta a caso (*Follow random teleport links with probability 1.0 from dead-ends*).

Matematicamente, questo significa **modificare la matrice $M$** sostituendo ogni colonna di soli zeri (corrispondente a un *dead-end*) con una colonna in cui tutte le entrate valgono $\frac{1}{N}$ (nel nostro caso con $3$ nodi, $\frac{1}{3}$ per ciascuna riga):

$$M_{\text{originale}} = \begin{pmatrix} 1/2 & 1/2 & \mathbf{0} \\ 1/2 & 0 & \mathbf{0} \\ 0 & 1/2 & \mathbf{0} \end{pmatrix} \quad \Longrightarrow \quad M_{\text{corretta}} = \begin{pmatrix} 1/2 & 1/2 & \mathbf{1/3} \\ 1/2 & 0 & \mathbf{1/3} \\ 0 & 1/2 & \mathbf{1/3} \end{pmatrix}$$

Dal punto di vista del grafo, questa modifica equivale ad aggiungere dal nodo *dead-end* $m$ dei link virtuali (frecce verdi) verso tutti i nodi del grafo (incluso $m$ stesso), ciascuno con probabilità $\frac{1}{3}$, rendendo nuovamente la matrice **stocastica per colonne** (ora anche la colonna $m$ somma a $\frac{1}{3} + \frac{1}{3} + \frac{1}{3} = 1$)!

## Perché i Teletrasporti Risolvono il Problema? Teoria delle Catene di Markov 
Per capire il motivo profondo per cui l'introduzione dei teletrasporti risolve contemporaneamente tutti i problemi di convergenza, le slide dalla 42 alla 46 richiamano la **Teoria delle Catene di Markov** (*Markov chains*).
Una catena di Markov è definita da:
* Un insieme finito di stati **$X$** (che nel nostro caso sono le pagine Web).
* Una **matrice di transizione $P$** in cui l'elemento $P_{ij} = P(X_t = i \mid X_{t-1} = j)$ indica la probabilità di trovarsi nello stato $i$ al passo $t$ sapendo che al passo precedente $t-1$ ci si trovava nello stato $j$ (esattamente come la nostra matrice $M$).
* Un vettore **$\pi$** che specifica la **probabilità stazionaria** (*stationary probability*) di trovarsi in ciascuno stato $x \in X$, tale da soddisfare l'equazione di punto fisso $\pi = P \pi$ (esattamente come $r = M r$).

> [!NOTES] Teorema fondamentale delle Catene di Markov (Slide 43)
> La teoria delle catene di Markov dimostra un fatto cruciale: **per qualunque vettore di partenza**, il metodo delle potenze (*power method*) applicato a una matrice di transizione di Markov $P$ **convergerà sempre a un unico vettore stazionario strettamente positivo**, a patto che la matrice $P$ goda di **tre proprietà fondamentali**:
> 
> 
> 1. **Stocastica (*Stochastic*)**.
> 
> 
> 2. **Aperiodica (*Aperiodic*)**.
> 
> 
> 3. **Irriducibile (*Irreducible*)**.
> 
> 
> 
> 

Vediamo nel dettaglio cosa significano queste tre proprietà e come i collegamenti di teletrasporto (indicati nelle slide come **link verdi**, *green links*) garantiscano ciascuna di esse:

### 1. Rendere $M$ Stocastica
* **Definizione:** una matrice si dice **stocastica** se **ogni sua colonna somma esattamente a $1$** (*Every column sums to 1*), il che garantisce che nessuna frazione di probabilità o importanza vada persa durante il passaggio da uno stato all'altro.
* **Problema:** i nodi *dead-end* (che hanno grado uscente $0$) producono colonne di soli zeri che sommano a $0$.
* **Soluzione:** si aggiungono i link verdi di teletrasporto dai *dead-end* verso tutti gli $n$ nodi del grafo con peso $\frac{1}{n}$. Formalmente, definendo un vettore indicatore $a$ tale che $a_i = 1$ se il nodo $i$ ha grado uscente $0$ (è un *dead-end*) e $a_i = 0$ altrimenti, e indicando con $e$ il vettore colonna formato da tutti $1$, la matrice stocastica corretta si ottiene sommando a $M$ le colonne $\frac{1}{n}$ in corrispondenza dei *dead-end* (nella notazione della slide $A = M + a^T \left(\frac{1}{n} e\right)$). Nell'esempio a 3 nodi dove $m$ era un *dead-end*, la colonna di $m$ diventa $\left[\frac{1}{3}, \frac{1}{3}, \frac{1}{3}\right]^T$ e le nuove equazioni diventano $r_y = \frac{r_y}{2} + \frac{r_a}{2} + \frac{r_m}{3}$, $r_a = \frac{r_y}{2} + \frac{r_m}{3}$, $r_m = \frac{r_a}{2} + \frac{r_m}{3}$.

### 2. Rendere $M$ Aperiodica 

* **Definizione:** una catena di Markov si dice **periodica** se esiste un intero $k > 1$ tale che l'intervallo di passi necessario per tornare a visitare uno stesso stato $s$ è sempre un multiplo esatto di $k$ (come nel ciclo $a \leftrightarrow b$ visto alla slide 35 con $k = 2$, o nel ciclo triangolare $y \rightarrow a \rightarrow m \rightarrow y$ in cui si torna su $y$ solo ogni $3, 6, 9\dots$ passi). Una catena è **aperiodica** se non presenta questo vincolo rigido.


* **Soluzione:** aggiungendo i link verdi di teletrasporto (in particolare i **cappi/self-loop verdi** che permettono a ogni nodo di saltare su se stesso al passo successivo con una probabilità maggiore di zero), si rompe qualsiasi periodicità, poiché da ogni nodo è possibile ritornare sul nodo stesso anche dopo un solo passo ($k = 1$).



### 3. Rendere $M$ Irriducibile

* **Definizione:** una catena di Markov si dice **irriducibile** se, partendo da qualunque stato, **esiste sempre una probabilità diversa da zero di andare da qualsiasi stato a qualsiasi altro stato** del grafo (*From any state, there is a non-zero probability of going from any one state to any another*).


* **Soluzione:** aggiungendo i link verdi di teletrasporto che collegano ogni nodo a tutti gli altri nodi del grafo, tutto il grafo diventa fortemente connesso: non esistono più isole irraggiungibili o trappole senza uscita, perché da ogni pagina c'è sempre una probabilità $> 0$ di saltare su qualunque altra pagina.



## L'Equazione del PageRank di Brin e Page e La Matrice di Google

Combinando il normale flusso dei link con il teletrasporto casuale (*Random Jumps*), otteniamo **la soluzione completa di Google che risolve tutti i problemi contemporaneamente** (*Google's solution that does it all*), rendendo la matrice di transizione **stocastica, aperiodica e irriducibile**:

* Ad ogni passo, con probabilità **$\beta$** il navigatore segue un link uscente scelto a caso.


* Con probabilità **$1 - \beta$** il navigatore salta (si teletrasporta) su una pagina scelta a caso tra tutte le $n$ pagine del grafo (ciascuna pagina ha quindi probabilità $\frac{1}{n}$ di essere la destinazione del salto).



> [!NOTES] Equazione del PageRank [Brin-Page, 1998] (Slide 47)
> Il punteggio di PageRank $r_j$ di una pagina $j$ nella formulazione ufficiale di Sergey Brin e Larry Page (1998) è dato da:
> 
> 
> $$r_j = \sum_{i \rightarrow j} \beta \frac{r_i}{d_i} + (1 - \beta) \frac{1}{n}$$
> 
> 
> dove:
> * **$\sum_{i \rightarrow j} \beta \frac{r_i}{d_i}$**: è la quota di importanza che arriva alla pagina $j$ attraverso i link normali provenienti dalle pagine $i$ (con grado uscente $d_i$), pesata per la probabilità $\beta$ di seguire i link.
> 
> 
> * **$(1 - \beta) \frac{1}{n}$**: è la quota di importanza che arriva alla pagina $j$ grazie ai salti casuali (teletrasporti) da parte di qualunque pagina del grafo (su un totale di $n$ pagine), pesata per la probabilità $1 - \beta$ di teletrasportarsi.
> 
> 
> 
> 
> *Nota sui Dead Ends:* L'equazione scritta sopra assume che la matrice $M$ di partenza **non abbia dead-ends** (cioè che sia già stocastica). Se nel grafo ci sono dei *dead-ends*, possiamo pre-processare la matrice $M$ sostituendo le colonne nulle con $\frac{1}{n}$ (come visto alla slide 41) oppure imporre esplicitamente nell'algoritmo di teletrasportarsi con probabilità $1.0$ ogni volta che ci si trova su un *dead-end*.
> 
> 

### La Matrice di Google $A$

Traducendo l'equazione di Brin e Page in forma matriciale, si definisce la celebre **Matrice di Google $A$** (*The Google Matrix $A$*):

$$A = \beta M + (1 - \beta) \frac{1}{n} e \cdot e^T$$

dove:

* **$M$**: è la matrice di adiacenza stocastica del grafo (di dimensione $n \times n$).


* **$e$**: è un vettore colonna di lunghezza $n$ composto interamente da $1$ (*vector of all 1s*); di conseguenza, il prodotto esterno $e \cdot e^T$ genera una matrice quadrata $n \times n$ piena di $1$, e moltiplicandola per $\frac{1}{n}$ si ottiene una matrice di teletrasporto in cui **ogni singola casella vale esattamente $\frac{1}{n}$**.


* **$\beta$**: nella pratica si imposta a $\beta = 0.8$ oppure $\beta = 0.9$, il che corrisponde intuitivamente a un navigatore che segue in media $5$ link consecutivi ($\frac{1}{1 - 0.8} = 5$ passi) prima di effettuare un salto casuale.



Poiché la Matrice di Google $A$ è **stocastica, aperiodica e irriducibile**, il metodo delle potenze applicato ad $A$ converge sempre a un unico vettore di PageRank valido:

$$r^{(t+1)} = A \cdot r^{(t)}$$

## Esempio completo svolto: Random Teleports con $\beta = 0.8$

La slide 49 conclude il blocco mostrando il calcolo completo passo dopo passo della Matrice di Google $A$ e delle iterazioni del PageRank sul grafo a $3$ nodi ($y, a, m$) che conteneva la **Spider Trap** sul nodo $m$ (visto alla slide 38, dove senza teletrasporto $y$ e $a$ finivano a $0$ e $m$ assorbiva tutto arrivando a $1$).

### 1. Costruzione della Matrice di Google $A$

Fissiamo il parametro **$\beta = 0.8$** (quindi la probabilità di teletrasporto è $1 - \beta = 0.2$) su un grafo di $n = 3$ nodi:

* La matrice del grafo con la *spider trap* in $m$ è $M = \begin{pmatrix} 1/2 & 1/2 & 0 \\ 1/2 & 0 & 0 \\ 0 & 1/2 & 1 \end{pmatrix}$.


* La matrice di teletrasporto uniforme $\frac{1}{n} \mathbf{1} \cdot \mathbf{1}^T$ (con $n = 3$) ha tutte le caselle pari a $\frac{1}{3}$: $\begin{pmatrix} 1/3 & 1/3 & 1/3 \\ 1/3 & 1/3 & 1/3 \\ 1/3 & 1/3 & 1/3 \end{pmatrix}$.



Calcoliamo $A = 0.8 M + 0.2 \left(\frac{1}{3} \mathbf{1} \cdot \mathbf{1}^T\right)$ sommando termine a termine (ricordando che $0.8 = \frac{4}{5}$ e $0.2 = \frac{1}{5}$):

* **Dove in $M$ c'è $\frac{1}{2}$:** il nuovo valore in $A$ diventa $0.8 \cdot \frac{1}{2} + 0.2 \cdot \frac{1}{3} = \frac{4}{10} + \frac{1}{15} = \frac{2}{5} + \frac{1}{15} = \frac{6 + 1}{15} = \mathbf{\frac{7}{15}}$.


* **Dove in $M$ c'è $0$:** il nuovo valore in $A$ diventa $0.8 \cdot 0 + 0.2 \cdot \frac{1}{3} = 0 + \frac{1}{5} \cdot \frac{1}{3} = \mathbf{\frac{1}{15}}$.


* **Dove in $M$ c'è $1$ (il cappio su $m$):** il nuovo valore in $A$ diventa $0.8 \cdot 1 + 0.2 \cdot \frac{1}{3} = \frac{4}{5} + \frac{1}{15} = \frac{12 + 1}{15} = \mathbf{\frac{13}{15}}$.



Otteniamo così la **Matrice di Google $A$** (si noti che tutte le entrate sono strettamente positive e ogni colonna somma perfettamente a $\frac{15}{15} = 1$):

$$A = 0.8 \begin{pmatrix} 1/2 & 1/2 & 0 \\ 1/2 & 0 & 0 \\ 0 & 1/2 & 1 \end{pmatrix} + 0.2 \begin{pmatrix} 1/3 & 1/3 & 1/3 \\ 1/3 & 1/3 & 1/3 \\ 1/3 & 1/3 & 1/3 \end{pmatrix} = \begin{pmatrix} \mathbf{7/15} & \mathbf{7/15} & \mathbf{1/15} \\ \mathbf{7/15} & \mathbf{1/15} & \mathbf{1/15} \\ \mathbf{1/15} & \mathbf{7/15} & \mathbf{13/15} \end{pmatrix}$$

### 2. Esecuzione della Power Iteration con la matrice $A$

Partendo dal vettore iniziale uniforme $r^{(0)} = \left[\frac{1}{3}, \frac{1}{3}, \frac{1}{3}\right]^T$ e moltiplicando ad ogni passo per la matrice $A$ ($r^{(t+1)} = A \cdot r^{(t)}$), otteniamo la seguente sequenza che converge rapidamente:

* **Iterazione 0:** $r^{(0)} = \begin{bmatrix} 1/3 \\ 1/3 \\ 1/3 \end{bmatrix} \approx \begin{bmatrix} 0.33 \\ 0.33 \\ 0.33 \end{bmatrix}$.


* **Iterazione 1 ($A \cdot r^{(0)}$):**
* $r_y^{(1)} = \frac{7}{15}\left(\frac{1}{3}\right) + \frac{7}{15}\left(\frac{1}{3}\right) + \frac{1}{15}\left(\frac{1}{3}\right) = \frac{15}{45} = \frac{1}{3} \approx \mathbf{0.33}$


* $r_a^{(1)} = \frac{7}{15}\left(\frac{1}{3}\right) + \frac{1}{15}\left(\frac{1}{3}\right) + \frac{1}{15}\left(\frac{1}{3}\right) = \frac{9}{45} = \frac{1}{5} = \mathbf{0.20}$


* $r_m^{(1)} = \frac{1}{15}\left(\frac{1}{3}\right) + \frac{7}{15}\left(\frac{1}{3}\right) + \frac{13}{15}\left(\frac{1}{3}\right) = \frac{21}{45} = \frac{7}{15} \approx \mathbf{0.46}$




* **Iterazioni successive e Convergenza finale:**

$$\begin{matrix} \mathbf{y} \\ \mathbf{a} \\ \mathbf{m} \end{matrix} = \underbrace{\begin{matrix} 1/3 \\ 1/3 \\ 1/3 \end{matrix}}_{\text{Iter. } 0} \quad \underbrace{\begin{matrix} 0.33 \\ 0.20 \\ 0.46 \end{matrix}}_{\text{Iter. } 1} \quad \underbrace{\begin{matrix} 0.24 \\ 0.20 \\ 0.52 \end{matrix}}_{\text{Iter. } 2} \quad \underbrace{\begin{matrix} 0.26 \\ 0.18 \\ 0.56 \end{matrix}}_{\text{Iter. } 3} \quad \dots \quad \underbrace{\begin{matrix} \mathbf{7/33} \\ \mathbf{5/33} \\ \mathbf{21/33} \end{matrix}}_{\text{Convergenza}}$$

**Interpretazione del risultato finale:**
Confrontando il risultato finale $\left[\frac{7}{33}, \frac{5}{33}, \frac{21}{33}\right]^T$ con quello che avevamo ottenuto senza teletrasporto ($\left[0, 0, 1\right]^T$ alla slide 38), vediamo chiaramente l'efficacia della soluzione di Google:

* Il nodo **$m$** mantiene comunque il punteggio più alto ($\frac{21}{33} \approx 0.636$) perché riceve link da $a$ e punta a se stesso trattenendo l'80% della propria importanza a ogni passo.


* Tuttavia, grazie a quel 20% ($1 - \beta = 0.2$) di probabilità di teletrasporto che fa "uscire" il navigatore dalla trappola $m$ ridistribuendolo su tutto il grafo, **i nodi $y$ e $a$ non si azzerano più**, ma conservano un PageRank significativo pari rispettivamente a **$r_y = \frac{7}{33}$** ($\approx 0.212$) e **$r_a = \frac{5}{33}$** ($\approx 0.151$), con la somma totale che resta perfettamente uguale a $\frac{7 + 5 + 21}{33} = \frac{33}{33} = 1$.