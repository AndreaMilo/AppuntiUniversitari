Per gestire la **conoscenza** bisogna saper:
- **Raccogliere** la conoscenza
- Organizzarla
- Distribuirla
- Renderla **accessibile** a chi necessita di quel tipo di informazione e nel momento e luogo in cui la richiede

Queste prassi vengono eseguite al fine di **risparmiare tempo**, riducendo i tempi di accesso all'informazione e **migliorando** la qualità dei servizi che la distribuiscono.
## Dati / Informazione / Conoscenza
La **conoscenza** è un capitale difficile da gestire, poiché è:
- volatile
- intangibile
- difficile da conservare

Per questo la maggior parte dei DB nel mondo possiede i dati in forma **non strutturata**.

L'obiettivo dell'**AKM** (Automatic Knowledge Management) è quello di costruire sistemi in grado di processare documenti in formato di **linguaggio naturale**.
## Acquisizione
L'**acquisizione** è il ritrovamento di conoscenza partendo da DB in forma testuale.
Lo slogan più noto per l'acquisizione di conoscenza è proprio: "**From Text to Knowledge**"; per passare infatti dal testo grezzo alla conoscenza formale, detta **Ontology Construction**, si utilizzano diverse tecniche, come:
- *Document Classification*
- *Information Extraction*
- *Text Mining*
### Paradigma Search vs Discover
![[Pasted image 20261001190826.png]]

Per comprendere dove collocare le varie tecnologie di recupero e analisi della conoscenza, vengono posti due **assi principali**:
- **La struttura del dato** (righe): ovvero se sono dati **strutturati** o **testuali**.
- **L'intento dell'utente** (colonne): ovvero se sono specifici ad un obiettivo (**Search**) o orientati alla scoperta di altre correlazioni (**Discover**).

Dall'incrocio di questi due assi, nascono quattro paradigmi:
- **Data Retrieval**:
  Questo paradigma si concentra sul trovare una corrispondenza di dati per risolvere un unico **obiettivo** mirato. Per questo il DB è **strutturato** e l'utente troverà questa informazione tramite un **linguaggio formale** (SQL ad esempio).
  Un esempio di questo paradigma è la ricerca di un ristorante a Boston, dove sarà effettuata la sua query di ricerca.
  L'entità manipolata è il **Record**.
  
- **Information Retrieval**:
  In questo caso l'utente deve cercare **documenti** in un DB **non strutturato**, essendo quindi privo di schema relazionale, l'SQL classico non funziona.
  Seguendo l'esempio precedente, si ottiene la medesima informazione tramite **navigazione per categorie** (`Boston -> Restaurant -> Japanese`), ad albero o per **parole chiave**.
  L'entità manipolata è il **Documento**.
  
- **Data Mining**:
  Nel Data Mining cambiano le carte in tavola. Non cerchiamo più un dato noto, ma si vuole scoprire in un DB **strutturato**, nuova **conoscenza** analizzando moli di dati strutturati.
  L'entità manipolata sono i valori **numerici**.
  
- **Text Mining**:
  Nel Text Mining andremo ad eseguire la stessa ricerca effettuata nel Data Mining, solo che la conoscenza nuova da scoprire **non è nota a priori** (come il Data Mining) ma non cerca su pattern numerici ma puramente **linguistici**, analizzando direttamente **testi liberi** e non valori **numerici**.
  L'entità manipolata è il **Concetto linguistico**.
### Processo di KDD
Il **Data Mining** in realtà è un sottoprocesso del grande processo di ricerca dai Databases, chiamato KDD (**Knowledge Discovery from Databases**).

>[!NOTES] Definizione di Fayyad et al., 1996
> Il KDD è il processo non banale di identificare pattern validi, nuovi, potenzialmente utili e comprensibili all'interno dei dati.

Le fasi del ciclo del processo KDD sono 5:
1. **Selezione**: raccolta dei dati di partenza e isolamento del sottoinsieme su cui opera.
2. **Pre-processing**: pulizia del dato eliminando file corrotti o sporchi.
3. **Trasformazione**: riduzione delle dimensioni dei dati e conversione in formati adatti all'algoritmo.
4. **Data Mining**: applicazione di **algoritmi per estrarre** e scoprire i pattern nascosti nei dati.
5. **Valutazione**: analisi critica dei pattern estratti dall'essere umano per tradurli in conoscenza utilizzabile, veritiera e concreta.

![[Pasted image 20261001192708.png]]

Come si evince da questo esempio non c'è mai una garanzia del 100% ma da piccole conoscenze già presenti possiamo notare dei pattern tra diversi dati, creando correlazioni utili per l'azienda.

### Dal Data Mining al Text Mining
Il **Text Mining** utilizza i principi del KDD sul testo a **linguaggio naturale**.
L'obiettivo è quello di scavare tra mille testi diversi fino alla ricerca di pattern, trend e associazioni nascoste, così da costruire nuova conoscenza.

>[!NOTES] Definizione Feldman e Dagan 1995
>Il *Text Data Mining* è l'estrazione non banale di informazioni implicite, precedentemente sconosciute e potenzialmente utili a partire da grandi quantità di dati testuali.

Espressa tramite la formula concettuale: $$\text{Text Mining}=\text{Data Mining (applicato al testo)}+\text{Linguistica di base}$$
#### Processo di Text Mining
![[Pasted image 20261001193541.png]]

Lo schema riportato sopra mostra l'**architettura** tipica di un sistema Text Mining, come si evince è basato su una **pipeline sequenziale**.
Partendo dal **Testo Grezzo** si va all'**Analisi sintattica**, per poi andare nella fase di **Feature Generation** dove vengono create le *Bag of Words*.
Dopo di che si eseguono i **filtri statistici** e in questa fase centrale vengono estratti i pattern, la loro estrazione avviene tramite tecniche di **classificazione** o di **clustering**, dopo di che vengono eseguiti i controlli dei pattern e per concludere, come abbiamo già visto, vengono poi **valutati i risultati**.
### Text Mining nell'Impresa
In ambito aziendale è diventata una delle pratiche più importanti, poiché permette di comprendere opinioni, reclami, feedback, ecc... dei clienti in una società dove i clienti espongono le loro preferenze tramite **fonti testuali eterogenee** (email, ticket, siti web, social, comunicati stampa, ecc...).
Un altro ostacolo è la **velocità** con cui i clienti cambiano opinione, rendendo impossibile gestire questo tipo di conoscenza manualmente.

L'obiettivo chiave quindi del Text Mining aziendale è quello di poter analizzare documenti testuali in modo **rapido**, **raggruppandoli automaticamente** in base al loro contenuto, così da permette l'estrazione (come cercare le criticità maggiormente segnalate).
#### Aree di ricerca correlate al Text Mining
Il Text Mining non è una disciplina isolata mirata solamente alla ricerca di dati da formati di testo generici, ma unisce diverse branche dell'informatica e dell'IA, come:
- **Information Retrieval (IR)**: per indicizzare collezioni di testi.
  
- **Text Categorization**: per l'assegnazione automatica di documenti a determinate classi tematiche.
  
- **Information Extraction (IE)**: per identificare entità e relazioni.
  
- **Natural Language Processing (NLP)**: per comprendere la sintassi, la grammatica e il significato del linguaggio naturale umano per introdurlo alla macchina.
  
- **Data Mining**: per la scoperta di ulteriori pattern.
## IR System 
![[Pasted image 20261002162345.png]]
Nei modelli classici di Information Retrieval, il processo di ricerca funziona esattamente come mostrato nello schema: l'utente invia una stringa di testo (la **query**), il sistema consulta la propria collezione di documenti e, calcolando un punteggio di pertinenza, restituisce una lista ordinata di documenti (**ranking**) dal più utile al meno utile.

Il punto centrale di tutto il sistema è comprendere cosa sia la **rilevanza**. A differenza di quanto si possa pensare, la rilevanza è un concetto prettamente **soggettivo**: non esiste una pertinenza assoluta, ma dipende sempre dal bisogno specifico di chi cerca, dal contesto e dal momento temporale (spesso serve un'informazione recente e aggiornata).
A rendere la rilevanza un problema davvero complesso è la natura stessa del linguaggio naturale. Se ad esempio un utente cerca la parola *Mosca*, il motore di ricerca si trova davanti a un campo vastissimo di possibilità:
- la capitale della Russia
- l'insetto
- il cognome di una persona
Capire quale di questi risultati sia effettivamente rilevante per chi ha digitato la query è una delle sfide principali dell'IR.
### La ricerca per parole chiave e i suoi limiti
Il metodo più immediato per rappresentare i documenti e cercare al loro interno si basa sull'approccio **Bag of Words** (a "sacco di parole"). In questo modo la ricerca avviene tramite **parole chiave**: si verifica semplicemente la presenza e la frequenza delle parole della query all'interno del documento, a prescindere dal loro ordine sintattico. Questo approccio è molto comodo e permette di trovare risposte anche se l'utente formula una frase sgrammaticata, anche se per query più articolate l'ordine dei termini farebbe la differenza.

Tuttavia, affidarsi alla pura presenza delle parole chiave porta con sé due grandi problemi linguistici:
1. **La Polisemia (o ambiguità)**: accade quando una stessa parola possiede più significati diversi. È proprio il caso dell'esempio di *Mosca*, oppure della parola *Apple*, che può riferirsi all'azienda di informatica o al frutto. In questi casi il motore rischia di restituire documenti che contengono la parola giusta ma con il significato sbagliato.
2. **La Sinonimia**: accade quando termini diversi indicano lo stesso concetto (ad esempio cercare *ristorante* quando un testo parla di *café* o *trattoria*, oppure cercare *Cina* quando nel documento è scritto *Repubblica Popolare Cinese*). Se il sistema cerca solo la parola esatta digitata, finirà per ignorare documenti perfettamente pertinenti solo perché usano un sinonimo.
## IR Intelligente
Per superare questi limiti, un motore di ricerca per definirsi "intelligente" deve andare oltre la semplice corrispondenza letterale dei termini: deve iniziare a considerare il significato semantico delle parole e tenere conto del loro ordine.
Inoltre, un elemento chiave dell'IR intelligente è la capacità di adattarsi all'utente sfruttando il **Relevance Feedback** (feedback di rilevanza): il sistema raccoglie i segnali lasciati dall'utente durante le ricerche (quali link ha aperto, quali ha ignorato, su quali si è soffermato) e usa queste informazioni per correggere o arricchire la query, ricalcolando il ranking nelle ricerche successive per mettere in primo piano i risultati più graditi.
### IR System Architecture
![[Pasted image 20261002163432.png]]
Guardando lo schema dell'architettura completa, possiamo distinguere due grandi percorsi che si incontrano: da una parte la gestione dei documenti archiviati, dall'altra l'interazione con l'utente.

- **Text Operations**: prima di poter essere cercati, i testi devono essere processati (un po' come fa la fase di analisi di un compilatore sul codice sorgente). In questa fase il testo viene ripulito e ridotto ai minimi termini: si fa la **stopword removal** (eliminando parole grammaticalmente necessarie ma prive di valore informativo, come articoli e preposizioni) e lo **stemming** (riducendo le parole alla loro radice comune, rimuovendo prefissi e desinenze).
- **Indexing**: è il processo con cui si costruisce la struttura dati per le ricerche veloci, chiamata **Inverted Index** (indice invertito). Funziona in modo analogo all'indice analitico in fondo a un libro: invece di scorrere tutti i documenti da cima a fondo a ogni query (cosa impensabile per archivi enormi), l'indice associa a ogni singola parola l'elenco di tutti i documenti in cui compare. In questo modo il motore cerca direttamente dentro l'indice.
- **Searching e Ranking**: quando l'utente digita una query, il motore consulta l'indice invertito, recupera i documenti candidati che contengono quei termini e infine applica gli algoritmi di **Ranking**, assegnando un punteggio a ciascuno e ordinandoli prima di mostrarli nell'interfaccia finale.

Per rendere un sistema di Information Retrieval realmente capace di comprendere i testi e le intenzioni dell'utente, la ricerca fa affidamento su due grandi discipline dell'Intelligenza Artificiale: il **Natural Language Processing (NLP)** e il **Machine Learning (ML)**.
## Natural Language Processing (NLP)
Il **Natural Language Processing** (Elaborazione del Linguaggio Naturale) si concentra sull'analisi computazionale del testo e del discorso umano a tre livelli progressivi:
- **Sintattico**: studio della struttura grammaticale e della disposizione delle parole nella frase.
- **Semantico**: comprensione del significato letterale dei termini e delle relazioni concettuali.
- **Pragmatico**: interpretazione del significato del messaggio in relazione al contesto d'uso.

L'obiettivo fondamentale dell'integrazione dell'NLP nei motori di ricerca è superare il vecchio modello basato sulla semplice corrispondenza letterale delle parole chiave, permettendo al sistema di recuperare i documenti in base al loro reale **significato** (*meaning-based retrieval*).
### Le direzioni dell'NLP applicate all'Information Retrieval
In ambito IR, le tecniche di NLP si sviluppano principalmente lungo tre direzioni applicative:
1. **Disambiguazione del significato delle parole (*Word Sense Disambiguation - WSD*)**: algoritmi capaci di determinare il significato corretto di un termine polisemico o ambiguo analizzando il contesto della frase (ad esempio capire se *Apple* nella query si riferisce all'azienda informatica o al frutto).
2. **Estrazione dell'informazione (*Information Extraction - IE*)**: tecniche per individuare ed estrarre automaticamente fatti, relazioni ed entità specifiche dal testo non strutturato per popolare schemi strutturati.
3. **Risposta a domande (*Question Answering*)**: sistemi evoluti in grado di fornire risposte puntuali ed esaustive a domande formulate dall'utente in linguaggio naturale, estraendo la risposta direttamente dall'analisi dell'intero corpus di documenti.
## Machine Learning
Il **Machine Learning** (Apprendimento Automatico) si focalizza sullo sviluppo di sistemi computazionali capaci di **migliorare automaticamente le proprie prestazioni con l'esperienza** (cioè aumentando la quantità dei propri risultati nel tempo e imparando dai propri errori).

Nel contesto dell'Information Retrieval, il Machine Learning interviene attraverso due paradigmi fondamentali:
- **Supervised Learning**: viene impiegato per la **Classificazione automatica**. Il sistema apprende modelli concettuali a partire da un insieme di esempi pre-etichettati (*training set*, come email già marchiate come "spam" o "non spam"), imparando ad assegnare autonomamente i nuovi documenti alla classe corretta.
- **Unsupervised Learning**: viene impiegato per il **Clustering**. Il sistema analizza dati ed esempi privi di etichetta (*unlabeled*), raggruppandoli spontaneamente in cluster omogenei e scoprendo temi, affinità e correlazioni nascoste senza bisogno di una guida umana preventiva.

---
# Modelli di ritrovamento
Un **modello di Information Retrieval** è una formalizzazione teorica che stabilisce come rappresentare i documenti e le query, e come misurare la pertinenza tra di essi. Formalmente, può essere definito come una quadrupla:

$$\mathcal{M} = [D, Q, \mathcal{F}, R(q_i, d_j)]$$

dove:
- **$D$**: è un insieme di **viste logiche** (*logical views*) per i documenti della collezione (la loro rappresentazione computazionale, ad esempio come insiemi di parole chiave o vettori).
- **$Q$**: è un insieme di **viste logiche** per le interrogazioni dell'utente.
- **$\mathcal{F}$**: è il **framework concettuale e matematico** adottato per modellare documenti e interrogazioni (come la teoria degli insiemi, l'algebra lineare o la teoria delle probabilità).
- **$R(q_i, d_j)$**: è la **funzione di ranking**, che quantifica la pertinenza tra l'interrogazione $q_i$ e il documento $d_j$ associando un punteggio numerico reale.

![[Pasted image 20261005164642.png]]

Accanto ai modelli puramente testuali, esistono modelli che integrano l'analisi della struttura dei collegamenti (**link analysis**), essenziali per il Web Retrieval, in questo scenario le pagine web formano un grafo connesso da collegamenti ipertestuali e il ranking calcola l'autorevolezza e l'importanza relativa delle pagine connesse.

I modelli di reperimento differiscono per architettura e algoritmi, ma condividono tutti il medesimo ciclo di vita: una fase preliminare di elaborazione e indicizzazione della collezione, seguita dalla fase di ricerca e ranking a fronte della query dell'utente.
![[Pasted image 20261005161258.png]]
## Modello Booleano
Il **Modello Booleano** è il più classico modello formale di Information Retrieval, fondato sulla **teoria degli insiemi** e sull'**algebra booleana**. 
Prima di poter rappresentare documenti e query, i testi grezzi devono attraversare una fase preliminare di **pre-processing**.

L'obiettivo del pre-processing è ripulire il testo non strutturato e ridurlo a token normalizzati:
1. **Normalizzazione e pulizia**: eliminazione di markup superfluo (tag HTML, commenti, metadati), caratteri speciali, punteggiatura e numeri privi di valore informativo per la ricerca.
2. **Tokenizzazione (*Tokenization*)**: scomposizione del flusso di testo in unità elementari dette **token** (singole parole). È una fase delicata che deve gestire casi ambigui come parole con apostrofo (es. *l'albero*) o termini con trattino (es. *state-of-the-art*).
3. **Stopword Removal**: eliminazione dei termini grammaticali ad altissima frequenza privi di significato discriminante (articoli, preposizioni, congiunzioni).
4. **Stemming e Lemmatizzazione**: riconduzione dei termini alla loro radice comune (*stem*) o alla forma base di dizionario (*lemma*, come la forma all'infinito per i verbi o il singolare per i nomi). In questo modo forme flesse diverse dello stesso termine vengono ricondotte alla stessa unità concettuale.

>[!NOTES] Il principio dell'elaborazione Offline
>L'intero pre-processing viene eseguito **una sola volta** su tutti gli $N$ documenti della collezione durante la fase di indicizzazione. In questo modo si evita il costo computazionale insostenibile di dover riprocessare i documenti a ogni singola query dell'utente.
### Funzionamento del Modello Booleano
Nel modello booleano classico:
- I **documenti** sono rappresentati semplicemente come un **insieme di parole chiave** (presenza binaria $0/1$: un termine compare o non compare).
- La **query** è formulata dall'utente come un'**espressione booleana**, combinando i termini mediante gli operatori logici:
  - `AND` (intersezione logica)
  - `OR` (unione logica)
  - `NOT` (complemento/differenza logica)

L'output restituito dal sistema è l'insieme esatto dei documenti che soddisfano l'espressione logica.
#### Perché il Modello Booleano puro NON supporta il Ranking?
Nel modello booleano puro **non è possibile ordinare i risultati per pertinenza**:
1. **Rilevanza strettamente binaria**: per ogni documento la funzione di pertinenza $R(q, d)$ può assumere solo due valori: $1$ (pertinente, soddisfa la condizione) o $0$ (non pertinente). Non esiste una scala di pertinenza parziale o graduale.
2. **Assenza di frequenza e pesatura dei termini**: il modello considera solo la presenza o l'assenza del termine, ignorando quante volte compare all'interno del documento (*Term Frequency*) e quanto sia raro o comune nell'intera collezione (*Document Frequency*). Di conseguenza, un documento che cita una parola chiave una sola volta riceve lo stesso identico punteggio di un documento che ne parla approfonditamente.

Concettualmente, la ricerca booleana può essere visualizzata tramite una **Matrice di Incidenza Termine-Documento**.
![[Pasted image 20261005162741.png]]

In questa matrice:
- Le righe rappresentano i **termini** del vocabolario.
- Le colonne rappresentano i **documenti** (identificati da un identificatore univoco `docID`).
- Ogni cella contiene $1$ se il termine è presente nel documento, $0$ altrimenti.

**Il limite della matrice di incidenza:**  
Nelle collezioni reali di grandi dimensioni la matrice è estremamente **sparsa** (la quasi totalità delle celle ha valore $0$, poiché nessun documento contiene più di una minima frazione dell'intero vocabolario). Memorizzare tutti gli zeri comporterebbe un enorme spreco di spazio.

Per superare questo limite si impiega la struttura dati fondamentale dell'Information Retrieval: l'**Indice Invertito** (*Inverted Index*).
![[Pasted image 20261005163737.png]]

L'indice invertito memorizza **esclusivamente le presenze effettive**, associando a ciascun termine solo l'elenco dei documenti in cui esso compare.

Si compone di due elementi:
1. **Vocabolario / Dictionary**: l'elenco ordinato di tutti i termini unici estratti dalla collezione.
2. **Posting List**: per ciascun termine, la lista ordinata dei documenti identificati tramite `docID` in cui il termine compare. Ciascun elemento della lista è detto **posting**.

Le interrogazioni booleane si risolvono eseguendo operazioni insiemistiche direttamente sulle posting list.
Quando nuovi documenti vengono aggiunti o modificati, non è necessario riprocessare l'intero corpus: è sufficiente aggiornare le posting list corrispondenti ai documenti coinvolti.
Per questo nel mondo attuale si lavora solo su parti di indici e non si rielabora tutto in caso di aggiornamenti. Si eseguono i backup e si lavora sulle parte di essi, mantenendo attivi ciò che non è stato salvato nei backup più recenti.
### Costruzione dell'Indice Invertito (*Inverted Index Construction*)
La costruzione dell'indice invertito segue una procedura sequenziale in tre fasi:

I documenti vengono scansionati uno alla volta e tokenizzati. Per ciascun token viene generata una coppia formata dal termine normalizzato e dal `docID` del documento in cui si trova.
![[Pasted image 20261005170111.png]]

Successivamente, la lista globale di tutte le coppie estratte viene **ordinata alfabeticamente per termine** e, a parità di termine, in ordine crescente di `docID`.
![[Pasted image 20261005170446.png]]

I termini duplicati vengono raggruppati: per ciascun termine unico del vocabolario viene generata la corrispondente **posting list** con i relativi `docID`, memorizzando anche la **Document Frequency ($df$)**, ovvero la cardinalità della lista (il numero totale di documenti che contengono quel termine). Salvati in **Lemma**, poiché molte parole possono essere singolari-plurali / maschile-femminile.
![[Pasted image 20261005170510.png]]

![[Pasted image 20261005171346.png]]
### Vantaggi dell'ordinamento per la ricerca
- **Ricerca binaria nel vocabolario**: poiché i termini nel dizionario sono ordinati in modo **lessicografico**, la localizzazione di una parola non richiede una scansione lineare, ma può essere effettuata con una ricerca binaria o tramite alberi in tempo logaritmico.
- **Intersezione efficiente (*Posting Merge*)**: poiché le posting list sono mantenute rigorosamente ordinate per `docID` crescente, l'intersezione tra due liste per una query `AND` (aventi rispettivamente lunghezza $x$ e $y$) viene risolta tramite un algoritmo di scansione a due puntatori (*merge*) in tempo lineare, senza scorrere la collezione.

Per capire come avvengono le operazioni di **intersezione (merge)**, dobbiamo chiederci: *perché è così importante mantenere ordinate le posting list?*  
La risposta è semplice: se le liste sono ordinate in modo crescente per `docID`, possiamo confrontarle scorrendole in parallelo, rendendo la ricerca rapida ed evitando di dover confrontare a vuoto ogni singolo elemento.
#### Algoritmo di merge delle posting list
![[Pasted image 20261006162409.png|354]]

L'algoritmo confronta due liste muovendo due puntatori, $p_1$ e $p_2$:
- **Corrispondenza**: se i due puntatori puntano allo stesso `docID`, abbiamo trovato una corrispondenza. L'ID viene salvato nella lista dei risultati (`answer`) e si fanno avanzare entrambi i puntatori per passare ai documenti successivi.
- **Differenza**: se i valori non coincidono, si fa avanzare il puntatore che ha il valore minore:
  - se $\text{docID}(p_1) < \text{docID}(p_2)$, si incrementa $p_1$;
  - se $\text{docID}(p_1) > \text{docID}(p_2)$, si incrementa $p_2$.

Possiamo riprendere l'esempio delle liste di *Bruto* e *Cesare*: se per Bruto il valore iniziale è $2$ e per Cesare è $1$, si incrementa il puntatore di Cesare ($p_2$) perché è più piccolo, allineandolo così al valore successivo. 
Il ciclo continua finché uno dei due puntatori arriva alla fine della propria lista (`null`): a quel punto l'algoritmo si ferma, poiché è impossibile trovare altri documenti in comune.
### Efficienza delle query
In un motore di ricerca, le query troppo lunghe o cariche di termini **non sono efficienti**. Una ricerca con troppe parole complica le operazioni di intersezione, allunga i tempi di risposta e spesso **peggiora** la qualità del risultato finale anziché migliorarlo.

Nel modello di reperimento booleano la sequenza operativa è quindi:
1. **Processare i documenti** (pulizia e normalizzazione iniziale del testo)
2. **Creare le posting list**
3. **Costruire l'indice invertito**
4. **Lavorare ed eseguire le query direttamente sull'indice**

Il modello booleano si basa su alcune **assunzioni semplificative**: non tiene conto dell'ordine delle parole né di quante volte compaiano (approccio *Bag of Words*), ma verifica puramente se i termini sono presenti o assenti. È comunque un sistema molto preciso, perché valuta le condizioni logiche restituendo un risultato netto: **vero o falso**.
Proprio per la sua immediatezza ed efficacia nelle ricerche semplici, viene ancora utilizzato in strumenti pratici come **Spotlight** (il motore di ricerca locale di Apple), dove servono risposte istantanee che non richiedono calcoli sull'ordine o sulla frequenza delle parole.

Questa estrema semplicità comporta però diversi **limiti**:
- L'operatore **`AND`** è fin troppo **restrittivo**: basta che manchi una sola parola chiave per escludere un documento, con il rischio di restituire zero risultati.
-  L'operatore **`OR`** è fin troppo **permissivo**: allarga eccessivamente la ricerca includendo qualsiasi documento contenga anche solo uno dei termini, sommergendo l'utente di risultati poco utili.
- **Complessità per l'utente**: per ottenere buoni risultati, chi cerca deve saper formulare la richiesta impostando con cura i connettivi logici e le parentesi.
- **Assenza di Ranking**: i documenti restituiti non hanno un ordine di pertinenza. Se l'utente vuole consultare i primi 10 risultati, il sistema non può indicare quali siano i migliori, poiché tutti i documenti estratti hanno esattamente lo stesso peso.
- **Mancanza di Relevance Feedback**: il modello fatica ad adattarsi al comportamento dell'utente. Non essendoci pesi o punteggi ma solo risposte **binarie** (vero/falso), il motore non può correggere o riordinare facilmente i risultati in base a quali documenti sono stati aperti o preferiti nelle ricerche precedenti.
## Pre-processing steps
Durante la fase di **pre-processing** non esistono regole universali prefissate: spetta infatti al progettista definire strategie consapevoli in base allo scopo dell'applicazione e alla natura dei dati da trattare, gestendo con attenzione i diversi casi limite.

Una delle prime decisioni riguarda la definizione stessa dell'unità di documento (*document unit*). Nel caso emblematico di un'email con allegati, ad esempio, bisogna scegliere se indicizzare l'intero messaggio come un unico blocco oppure trattare il corpo del testo e i vari allegati come documenti distinti. 
La questione si complica ulteriormente in presenza di **collezioni multilingua**, dove il messaggio principale potrebbe essere redatto in una lingua e l'allegato in un'altra.

Per rilevare automaticamente l'**idioma** di un testo, una tecnica **euristica** diffusa consiste nell'analizzare la **frequenza degli articoli**.
Poiché ogni lingua possiede il proprio insieme caratteristico di articoli, il sistema può dedurre la lingua prevalente esaminandone la presenza. Trattandosi tuttavia di una semplice euristica, **non garantisce un'accuratezza assoluta** e può fallire facilmente in presenza di testi brevi, poco strutturati o eterogenei.
### Token
Un'analoga discrezionalità si riscontra nella fase di **tokenizzazione**, in cui il flusso di caratteri viene suddiviso in unità elementari. 
Anche in questo passaggio emergono ambiguità legate ai **separatori**, come apostrofi e trattini: davanti a forme come *l'albero* o *state-of-the-art*, è il progettista a dover stabilire se scartare i simboli come semplice punteggiatura, mantenere i termini uniti in una sola parola oppure spezzarli in token separati.

Infine, non tutti i token individuati entrano a far parte dell'indice, poiché rappresentano solo candidati provvisori.
Il primo filtro consiste nell'eliminazione delle **stopword**, ovvero le parole puramente grammaticali e di congiunzione che non apportano valore informativo utile alla ricerca. Successivamente, i token selezionati vengono ricondotti al loro **lemma**, ossia la forma base di dizionario. Questa operazione permette di non disperdere le varianti flesse di una parola tra singolari, plurali, maschili e femminili: invece di registrare fino a quattro voci distinte che occuperebbero spazio inutile nell'indice invertito, si conserva un unico token di riferimento.
In questo modo si risolvono anche i problemi di disallineamento durante l'interrogazione, consentendo al motore di recuperare i documenti rilevanti anche quando l'utente cerca un termine in una forma grammaticale diversa rispetto a quella presente nel testo originale.

Il token quindi è una **sequenza di caratteri** che possono essere analizzati nell'indice invertito che compone una parte significativa nel documento che merita considerazione.
Molti motori di ricerca permettono di sbagliare alcuni caratteri di un token, poiché grazie alla **distanza di Levenstain** (la distanza possibile tra una parola e un altra in base al cambiamento dei caratteri), cerco le **chiavi di ricerca** più simili a quella parola ,con la stessa distanza di Levenstain calcolata, memorizzate nell'indice e si trova comunque una corrispondenza e quindi viene suggerita la parola corretta.
### Numeri
Un'ulteriore criticità nella fase di pre-processing riguarda il trattamento delle stringhe contenenti entità numeriche, in particolare le **date**. 
Se il sistema tratta i numeri semplicemente come token slegati tra loro, perde del tutto il valore informativo del dato temporale. A ciò si aggiunge l'ambiguità dei formati: memorizzare una data nella forma generica `n1/n2/n3` crea disallineamenti, poiché `n1` può rappresentare il **giorno** nello standard europeo o il **mese** in quello anglosassone. 

I motori di ricerca più moderni e definiti **intelligenti**, superano questo limite interpretando il contesto circostante, riuscendo a riconoscere e normalizzare la data corretta anche quando viene formulata in formati particolari o notazioni storiche (come ad esempio *55 B.C.*).

Una problematica del tutto analoga si riscontra con i **numeri di telefono** e la gestione dei prefissi. Come ad esempio `+39 333...`, `(080) 23343` o `(080)23-323`.
Se l'algoritmo si limitasse a trattare i separatori come normale punteggiatura da eliminare o se frammentasse i numeri in elementi distinti, diventerebbe impossibile far corrispondere la query al documento corretto. Anche in questo caso è compito del progettista introdurre procedure di normalizzazione specifiche che convertano queste sequenze in un formato standard univoco prima di registrarle nell'indice.
### Tokenizzazione: problemi con la lingua
Un altro problema legato al pre-processing deriva dalle specificità intrinseche delle singole lingue:
- **Cinese e Giapponese**: non utilizzano lo spazio per separare le parole.
- **Arabo**: la scrittura e il processamento avvengono da destra verso sinistra (RTL), ad eccezione dei numeri.
- **Alfabeti multipli**: caratteristica tipica del giapponese, che complica ulteriormente la fase di suddivisione in token.
### Stop words
Come già accennato in precedenza, le **stop words** sono parole che si decide di escludere dal vocabolario dell'indice poiché prive di reale valore informativo o discriminante per le query (come articoli e preposizioni).
Mantenere queste parole nell'indice invertito comporterebbe la restituzione della quasi totalità della collezione di documenti come risultato, vanificando il lavoro di ricerca a monte.

Bisogna comunque essere pragmatici nella loro eliminazione, poiché un filtraggio indiscriminato può causare diversi problemi:
- **Annullamento di intere frasi**: query celebri o frasi composte esclusivamente da stop words (come *To be or not to be*) verrebbero completamente eliminate dal sistema.
- **Titoli falsati**: alterazione del senso nei titoli di alcune opere o testi, come ad esempio *King of Denmark*.
- **Clausole relazionali**: in ricerche come *flights to London*, l'eliminazione della preposizione *to* fa perdere la relazione concettuale tra il volo e la città di destinazione.
#### Normalizzazione dei termini (*Normalization to terms*)
L'operazione di **normalizzazione** permette di creare delle **classi di equivalenza** tra termini che presentano modalità di scrittura differenti, evitando che vengano trattati come parole distinte.
Ad esempio, varianti come *USA*, *U.S.A.* e *US* vengono raggruppate all'interno di un'unica classe $[USA]$.
Formalmente:
$$[a] = \{x \mid x \sim a\}$$

La normalizzazione è importante anche per la gestione degli accenti, dato che parole con accenti diversi possono avere significati totalmente differenti (come *résumé* e *resume*). Nella prassi, tuttavia, è spesso conveniente rimuovere i segni diacritici, poiché l'utente medio tende a non utilizzarli nelle ricerche veloci, creando classi di equivalenza come:
$$\text{Tuebingen, Tübingen, Tubingen} \in [Tubingen]$$
La medesima operazione si applica anche per uniformare i diversi formati delle **date**.

**Tokenizzazione** e **normalizzazione** dipendono strettamente dalla lingua e sono quindi collegate al rilevamento automatico della lingua (**language detection**).
Un principio cruciale è che occorre **normalizzare nella stessa identica forma sia il testo indicizzato sia i termini della query**.
Ad esempio, nella frase *Morgen will ich in MIT*, non è subito chiaro se *MIT* sia un acronimo, una parola in un'altra lingua o la preposizione tedesca *mit* scritta semplicemente in maiuscolo.
#### Case folding
Il **case folding** è l'operazione che uniforma le parole scritte in maiuscolo e minuscolo. Richiede però attenzione al contesto d'uso: ad esempio, *SAIL* e *sail* hanno significati del tutto differenti a seconda di come vengono scritti.

Nei motori di ricerca la prassi comune prevede comunque la conversione di tutti i termini in **lowercase**, poiché nella maggior parte dei casi pratici rappresenta la soluzione più efficace.
### Thesauri e Soundex
In presenza di vocaboli sinonimi, il sistema genererebbe due posting list differenti. Tramite i **thesauri** è possibile collegare termini affini (come *automobile* e *macchina*), consentendo al motore di restituire l'insieme corretto dei documenti indipendentemente dal sinonimo digitato dall'utente.

Allo stesso modo, per gestire gli errori di spelling e le variazioni fonetiche (come ad esempio *color* e *colour*), si utilizzano algoritmi come **Soundex**, che permettono di ricondurre parole dalla pronuncia simile alla stessa query e alla medesima collezione di documenti.
## Lemmatizzazione
Come accennato in precedenza, per alleggerire la cardinalità del vocabolario e aumentare la probabilità di corrispondenza nelle query, una pratica fondamentale è la **lemmatizzazione**, ovvero la trasformazione delle parole nella loro forma base di dizionario (**lemma**).
Ad esempio, le diverse forme flesse *am*, *are*, *is* vengono ricondotte direttamente a *be*.
### Stemming
Lo **stemming** consiste nel ridurre le parole alla loro radice comune (*stem*) mediante appositi algoritmi.
Ad esempio, varianti come *automate(s)*, *automatic* e *automation* vengono tutte ricondotte alla radice condivisa ***automat***.
![[Pasted image 20261007165427.png]]
Ridurre eccessivamente alla radice presenta però dei limiti: se da un lato riduce lo spazio occupato dall'indice, dall'altro può alterare il significato semantico di alcuni termini fondendoli scorrettamente, come ad esempio *police* (che può indicare sia la polizia sia le polizze di sicurezza).

Infine, è fondamentale comprendere il funzionamento dell'algoritmo di stemming scelto: **lo stesso algoritmo utilizzato per la costruzione dell'indice invertito deve essere applicato anche sui termini della query**, altrimenti il sistema non troverebbe corrispondenza.
![[Pasted image 20261007165617.png]]
