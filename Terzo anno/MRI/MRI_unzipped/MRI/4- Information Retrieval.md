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

>[!NOTES] Alternativa alle classi d'equivalenza: Espansione della Query
>Anziché fondere le varianti di un termine in un'unica classe d'equivalenza in fase di indicizzazione, un'alternativa consiste nel **mantenere nel dizionario posting list separate** per ciascuna variante ed **espandere la query** al momento della ricerca (cercando tutte le varianti contemporaneamente). Questo approccio risulta potenzialmente **più accurato**, ma è **meno efficiente** dal punto di vista computazionale durante l'interrogazione.
![[image 3.png]]

---
## Modello a Spazio Vettoriale (*Vector Space Model*)
Uno dei limiti principali del **Modello Booleano** è la totale perdita dell'ordine dei termini e del **numero di occorrenze** all'interno dei documenti, unita a un matching puramente binario (`true` o `false`). Questo lo rende poco adatto alla maggior parte degli utenti (come nelle ricerche sul Web), i quali preferiscono formulare interrogazioni a testo libero (*free text queries*) anziché espressioni booleane complesse.

Piuttosto che restituire in blocco l'intero insieme non ordinato di documenti che soddisfano una condizione logica (rischiando di restituire zero risultati con `AND` o migliaia di risultati con `OR`), l'obiettivo del **Ranked Retrieval** è ordinare i documenti restituendo quelli che hanno la **maggior probabilità di essere utili** per chi effettua la ricerca. Anche qualora il risultato complessivo comprendesse moltissimi documenti pertinenti, l'ordinamento risolve il problema alla radice poiché permette di **limitare la visualizzazione ai primi $k$ documenti migliori** (*top-$k$*).

Per ottenere questo ordinamento, il sistema assegna a ciascun documento un **punteggio numerico di rilevanza** (*score*), ad esempio nell'intervallo $[0, 1]$, misurando quanto il documento aderisce alla query.
Considerando il caso più semplice di una **query composta da una sola parola**, un primo criterio immediato consiste nell'assegnare il punteggio in base alla **frequenza** con cui quel termine compare nel documento stesso, attribuendo $0$ ai documenti in cui la parola è assente.
### Il Coefficiente di Jaccard
Prima di introdurre modelli basati sulla frequenza, un metodo classico per misurare la sovrapposizione tra due insiemi $A$ e $B$ (utilizzabile quindi anche con una vista insiemistica/booleana di query e documento) è il **Coefficiente di Jaccard**, definito come il rapporto tra la cardinalità dell'intersezione e la cardinalità dell'unione dei due insiemi:

$$\text{Jaccard}(A, B) = \frac{\vert{}A \cap B\vert{}}{\vert{}A \cup B\vert{}}$$

![[image 5.png]]
![[image 6.png]]

Il coefficiente gode delle seguenti proprietà:
- $\text{Jaccard}(A, A) = 1$ (massima sovrapposizione);
- $\text{Jaccard}(A, B) = 0$ se e solo se $A \cap B = \emptyset$ (nessun termine in comune);
- Gli insiemi $A$ e $B$ non devono necessariamente avere la stessa cardinalità.

Tuttavia, utilizzare il Coefficiente di Jaccard come funzione di scoring presenta **tre gravi problemi**:
- **Ignora la frequenza dei termini**: non tiene conto di quante volte una parola compare all'interno di un documento.
- **Ignora la rarità dei termini**: non considera che i termini rari all'interno della collezione possiedono un **contenuto informativo maggiore** (sono molto più discriminanti) rispetto alle parole comuni.
- **Normalizzazione superficiale della lunghezza**: dividere semplicemente per $\vert{}A \cup B\vert{}$ è un modo troppo grezzo per pesare la lunghezza di un documento (sarebbe più efficace una normalizzazione sublineare come $\sqrt{\vert{}A \cup B\vert{}}$).
### Dalla Matrice di Incidenza alla Term Frequency ($tf$)
Riconsiderando la **Matrice di Incidenza Termine-Documento** vista nel modello booleano:
![[image 7.png]]

Possiamo evolvere questa rappresentazione memorizzando in ogni cella non più la semplice presenza/assenza binaria ($0/1$), bensì il **numero di occorrenze** del termine nel documento (*Matrice delle Frequenze* o *Term-Document Count Matrix*):
![[image 8.png]]

In questa formulazione, indicato con $\vert{}V\vert{}$ il numero di termini del vocabolario, **ogni documento è rappresentato come un vettore di conteggi** appartenente allo spazio vettoriale $\mathbb{N}^{\vert{}V\vert{}}$ (una componente per ciascun termine del vocabolario).

>[!NOTES] Modello Bag of Words
>Rappresentare un documento come un vettore di frequenze corrisponde ad adottare il modello **Bag of Words**. In questo schema **non viene considerato l'ordine delle parole** all'interno del testo: due frasi semanticamente diverse ma composte dagli stessi termini con le medesime frequenze (ad esempio *"John is quicker than Mary"* e *"Mary is quicker than John"*) producono esattamente lo stesso vettore.

Si introduce così formalmente la **Term Frequency ($tf_{t,d}$)**, definita come il numero di volte in cui il termine $t$ compare all'interno del documento $d$.
## Rarità dei termini e pesatura tf-idf
Nelle ricerche testuali è opportuno attribuire un peso maggiore alle **parole più rare** nella collezione: essendo meno ripetute, esse risultano molto più selettive e permettono ricerche più efficaci rispetto ai termini ad alta frequenza.

Per quantificare quanto un termine sia comune o raro nell'intero corpus, si utilizza la **Document Frequency ($df_t$)**, ovvero il **numero di documenti della collezione che contengono il termine $t$**.
Sulla base di $df_t$ e del numero totale $N$ di documenti nella collezione, si definisce l'**Inverse Document Frequency ($idf_t$)** del termine $t$:

$$idf_t = \log_{10}\left(\frac{N}{df_t}\right)$$

>[!NOTES] Proprietà fondamentale dell'$idf_t$
>L'$idf_t$ è un valore che **dipende esclusivamente dal termine $t$** (e dalla collezione nel suo complesso), **non dal singolo documento**:
>- Per **parole molto rare**, $df_t$ è basso e quindi $idf_t$ assume un valore elevato (fino a $\log_{10}(N)$ quando $df_t = 1$).
>- Per **parole molto comuni**, $df_t$ è prossimo a $N$ e quindi $idf_t$ tende a $0$.
>
>Inoltre, l'$idf$ **non ha alcun effetto sul ranking per query composte da una sola parola**, poiché per un singolo termine $t$ il fattore $idf_t$ è una costante identica per tutti i documenti; diventa invece determinante nelle **query composte da almeno due parole**, in quanto bilancia l'importanza relativa dei diversi termini.

Oltre alla *Document Frequency*, è possibile definire anche la **Collection Frequency ($cf_t$)**, data dalla **somma totale delle occorrenze** del termine $t$ nell'intera collezione di documenti.
![[lez12_image.png]]

Come mostra la tabella, due termini possono avere una *Collection Frequency* quasi identica (es. *try* e *insurance*), ma una distribuzione molto diversa: *try* compare in moltissimi documenti ($df$ alto, poco discriminante), mentre *insurance* è concentrato in molti meno documenti ($df$ più basso, molto più informativo). Per questo motivo per il calcolo dell'$idf$ si preferisce sempre $df_t$ rispetto a $cf_t$.
### Lo schema di pesatura tf-idf
Combinando la frequenza locale nel documento ($tf_{t,d}$) e la rarità globale nella collezione ($idf_t$), si ottiene lo schema di pesatura **tf-idf**, che assegna a ciascun termine $t$ in un documento $d$ il peso:

$$w_{t,d} = \text{tf-idf}_{t,d} = tf_{t,d} \times \log\left(\frac{N}{df_t}\right)$$

![[lez12_image 1.png]]

Questo valore gode di due proprietà chiave:
- **Incrementa** all'aumentare del numero di occorrenze del termine all'interno del singolo documento ($tf_{t,d}$).
- **Incrementa** all'aumentare della rarità del termine nell'intera collezione ($idf_t$).

Di conseguenza, il punteggio di **ranking (Score)** di un documento $d$ rispetto a una query $q$ viene calcolato sommando i pesi $\text{tf-idf}$ di tutti i termini della query presenti nel documento:

$$\text{Score}(q, d) = \sum_{t \in q \cap d} \text{tf-idf}_{t,d}$$

![[lez12_image 2.png]]

Per evitare di dover ricalcolare tutti i pesi statici nell'indice ogni volta che la collezione subisce modifiche (variazioni di $N$ o $df_t$), i valori di $idf_t$ non vengono ricalcolati sull'intero indice ad ogni aggiornamento, ma vengono **calcolati dinamicamente a runtime** al momento dell'esecuzione della query.
## Calcolo della Similarità nello Spazio Vettoriale
Adottando la pesatura $\text{tf-idf}$, ciascun documento è rappresentato come un **vettore reale in uno spazio vettoriale $\vert{}V\vert{}$-dimensionale** ($\mathbb{R}^{\vert{}V\vert{}}$), il che implica milioni di dimensioni quando il modello viene applicato su scala Web.
Per gestire ed effettuare ricerche in spazi così grandi, il **Modello a Spazio Vettoriale** si fonda su due principi:
- Rappresentare anche le **query come vettori** nello stesso spazio $\vert{}V\vert{}$-dimensionale dei documenti.
- Ordinare (*rankare*) i documenti in base alla loro **prossimità geometrica** rispetto al vettore della query all'interno di tale spazio.
### Distanza Euclidea vs Angolo tra vettori
Per valutare la vicinanza tra il vettore della query $\vec{q}$ e il vettore del documento $\vec{d}$, una prima idea intuitiva potrebbe essere quella di calcolare la **distanza euclidea**, ossia la distanza geometrica tra le due estremità dei vettori.
Sorge però un grave problema: **la distanza euclidea dipende fortemente dalla lunghezza (modulo) dei vettori**.
![[lez12_image 3.png]]

Consideriamo ad esempio un documento $d$ e costruiamo un nuovo documento $d'$ ottenuto concatenando $d$ a se stesso due volte: sebbene $d$ e $d'$ abbiano **esattamente lo stesso contenuto semantico** e la stessa proporzione di termini, il vettore $\vec{d}'$ avrà lunghezza doppia rispetto a $\vec{d}$ e la distanza euclidea tra i due (o rispetto alla query) risulterà molto grande.

Per ovviare a questo problema, anziché misurare la distanza tra le punte dei vettori, si valuta **l'angolo $\theta$ compreso tra il vettore della query e il vettore del documento** (nell'esempio precedente, $\vec{d}$ e $\vec{d}'$ hanno la stessa direzione e quindi angolo $0^\circ$).
In questo modo i documenti vengono ordinati:
- **Al decrescere dell'angolo** $\theta(\vec{q}, \vec{d})$ tra query e documento;
- Equivalente a ordinarli **all'aumentare del coseno dell'angolo** $\cos(\vec{q}, \vec{d})$, poiché il coseno è massimo (pari a $1$) quando l'angolo è $0^\circ$ e decresce monotonicamente fino a $0$ per vettori ortogonali ($90^\circ$).
### Normalizzazione della lunghezza e Cosine Similarity
Per eliminare la distorsione dovuta al fatto che i documenti hanno lunghezze diverse (che porterebbe a preferire documenti più lunghi con frequenze assolute maggiori), si applica la **normalizzazione della lunghezza** (*length normalization*).
Un vettore $\vec{x}$ viene normalizzato dividendone ciascuna componente per la sua **lunghezza euclidea (norma $L_2$)**:

$$\Vert{}\vec{x}\Vert{}_2 = \sqrt{\sum_{i} x_i^2}$$

![[lez12_image 4.png]]

Dividendo un vettore per la sua norma $\Vert{}\vec{x}\Vert{}_2$, lo si trasforma in un **versore** (*unit vector*), ovvero un vettore di **lunghezza unitaria pari a $1$**, facilitando così il calcolo del coseno dell'angolo e rendendo un documento $d$ e il suo duplicato $d'$ identici dopo la normalizzazione.

Per calcolare la pertinenza (**Cosine Similarity**) di un documento $\vec{d}$ rispetto a una query $\vec{q}$ si effettua quindi il seguente calcolo:

$$\cos(\vec{q}, \vec{d}) = \frac{\vec{q} \cdot \vec{d}}{\Vert{}\vec{q}\Vert{} \Vert{}\vec{d}\Vert{}} = \frac{\vec{q}}{\Vert{}\vec{q}\Vert{}} \cdot \frac{\vec{d}}{\Vert{}\vec{d}\Vert{}} = \frac{\sum_{i=1}^{\vert{}V\vert{}} q_i d_i}{\sqrt{\sum_{i=1}^{\vert{}V\vert{}} q_i^2} \sqrt{\sum_{i=1}^{\vert{}V\vert{}} d_i^2}}$$

![[lez12_image 5.png]]

dove:
- **$q_i$**: è il peso $\text{tf-idf}$ del termine $i$ all'interno della query $q$;
- **$d_i$**: è il peso $\text{tf-idf}$ del termine $i$ all'interno del documento $d$.

Se i vettori sono già stati **normalizzati in lunghezza** (versori con $\Vert{}\vec{q}\Vert{} = 1$ e $\Vert{}\vec{d}\Vert{} = 1$), il denominatore si annulla a $1$ e la formula si riduce semplicemente alla **somma dei prodotti interni (prodotto scalare)**:

$$\cos(\vec{q}, \vec{d}) = \vec{q} \cdot \vec{d} = \sum_{i=1}^{\vert{}V\vert{}} q_i d_i$$

![[lez12_image 6.png]]
### Algoritmo per il calcolo del Cosine Score
L'algoritmo completo `CosineScore(q)` che calcola efficientemente i punteggi del coseno sfruttando l'indice invertito e restituisce i migliori $K$ documenti della collezione è il seguente:
![[lez12_image 7.png]]

L'algoritmo opera accumulando i punteggi un termine della query alla volta (*term-at-a-time*):
1. Inizializza a zero un array `Scores[N]` per i documenti e legge le lunghezze precalcolate nell'array `Length[N]`.
2. Per ciascun termine $t$ della query $q$, calcola il peso $w_{t,q}$ ed estrae la relativa **posting list** dall'indice invertito.
3. Per ogni coppia $(d, tf_{t,d})$ nella posting list, somma a `Scores[d]` il contributo $w_{t,d} \times w_{t,q}$.
4. Al termine delle iterazioni, normalizza ciascun punteggio dividendolo per la lunghezza del documento `Length[d]` e restituisce i **top $K$** documenti con il punteggio più alto.
### Le varianti del tf-idf
Lo schema di pesatura **tf-idf** impiegato nell'algoritmo `CosineScore` non è l'unica formulazione possibile: ne esistono infatti diverse **varianti** che si differenziano per il modo in cui viene calcolata la _term frequency_, la _document frequency_ e la normalizzazione applicata ai vettori. La differenza maggiore tra queste varianti si riscontra nelle **prestazioni** all'interno di un motore di ricerca: ad esempio, l'adozione di vettori non normalizzati richiede in genere una maggiore elaborazione, anche se non è sempre detto e dipende dal caso specifico.

![[Pasted image 20261021181526.png]]
#### Esempio: differenze nel calcolo della similarità
Per comprendere concretamente come la scelta della misura di similarità influenzi il ranking, si consideri un dizionario composto da tre termini ($t1​, t2​, t_3$), in cui la query $q$ e i due documenti $d1​$ e $d2$​ sono rappresentati (secondo la consueta rappresentazione _Bag of Words_) dai seguenti vettori di occorrenze:

| Termine / Documento | $t_1$ | $t_2$ | $t_3$ |
| :--- | :---: | :---: | :---: |
| **q** (Query) | 1 | 2 | 1 |
| **$d_1$** (Documento 1) | 5 | 1 | 2 |
| **$d_2$** (Documento 2) | 1 | 2 | 1 |

Si parta dal calcolo della similarità mediante **prodotto interno** ($sim(q,d_{i}​)$), che si ottiene sommando i prodotti delle componenti aventi le stesse coordinate:
$$sim(q,d_{1}​)=5⋅1+1⋅2+2⋅1=9$$ e $$sim(q,d_{2})=1⋅1+2⋅2+1⋅1=6$$Secondo questo ranking $d_{1}$​ sembrerebbe essere il documento più simile alla query, poiché ottiene il punteggio maggiore. Si studi ora la misura della **similarità del coseno**, che restituisce valori compresi tra 0 e 1: essa si ottiene facendo il rapporto tra il prodotto interno e il prodotto delle lunghezze dei due vettori, dove la lunghezza di un documento (e della query) si calcola sommando i quadrati delle occorrenze:

$$cosim(q,d_{1}​)=\frac{5\times 1+1\times 2+1\times 2}{\sqrt{1^2+2^2+1^2}\sqrt{5^2+1^2+2^2}}​{}≈0,67$$Ripetendo lo stesso calcolo per $d_{2}$​, con questo metodo risulta invece più simile $d_{2}$​:

$$cosim(q,d_{2}​)=\frac{1\times 1+2\times 2+1\times 1}{\sqrt{1^2+2^2+1^2}\sqrt{1^2+2^2+1^2}} = \frac{6}{\sqrt{6}\sqrt{6}}​=1$$
Il risultato è del tutto intuitivo: il vettore di $d_{2}$​ coincide esattamente con quello della query, quindi (come visto in precedenza) l'angolo tra i due è nullo e il coseno vale 1; il prodotto interno lo penalizzava invece soltanto per via della sua lunghezza minore.

Si consideri ora il caso in cui si adottino dei **vettori normalizzati**, ottenuti facendo il rapporto tra le occorrenze e la lunghezza dei documenti stessi. Andando a ricalcolare la similarità del prodotto interno tra i versori $\frac{q}{||q||}$ e $\frac{d_{1}}{||d_{1}||}$​​​, si nota che il risultato ottenuto è identico a quello che in precedenza si era ottenuto con la similarità del coseno:
$$\frac{q}{||q||}\times ​​​\frac{d_{1}}{||d_{1}||}=\frac{9}{\sqrt{6}\sqrt{30}}​≈0,67$$Un'ulteriore variante prevede invece di calcolare le lunghezze dei vettori mediante l'uso del **peso massimo**, rapportando ciascuna occorrenza alla frequenza massima presente nel documento (variante _augmented_).

> [!NOTES] Prodotto interno vs similarità del coseno
> Tutto ciò porta ad una riflessione: la misura della similarità del **prodotto interno**, in base al metodo di pesatura e normalizzazione utilizzato, conduce a risultati differenti poiché i punteggi risultano legati alla **lunghezza del vettore** (e quindi favoriscono i documenti più lunghi). La misura della similarità del **coseno**, dipendendo esclusivamente dall'angolo tra i vettori, risulta invece più **stabile**.
### Schemi di pesatura differenti tra query e documenti
Molti motori di ricerca adottano **schemi di pesatura differenti** tra query e documenti. Per una questione di semplicità le query vengono trattate come dei _documenti più piccoli_; grazie alla normalizzazione, tuttavia, query e documenti vengono ricondotti alla stessa lunghezza, permettendo così di confrontare direttamente documenti di grandi dimensioni con query contenenti poche parole. Alcuni motori di ricerca gestiscono invece le query in modo completamente differente.

Per specificare in modo compatto la tipologia di schema di pesatura utilizzata si impiega la **SMART Notation**, una notazione standard del tipo $ddd.qqq$ in cui:

- le **prime tre lettere** indicano rispettivamente lo schema di _term frequency_, di _document frequency_ e di normalizzazione usato per i **documenti**;
- le **ultime tre lettere** indicano le medesime componenti, ma relative alla **query**.

Le lettere impiegate per ciascuna posizione sono:

- **Term Frequency**: $n$ (_natural_, la $tf$ grezza), $l$ (_logarithmic_, $1 + \log tf$), $a$ (_augmented_, occorrenze riscalate rispetto al peso massimo), $b$ (_boolean_), $L$ (_log-ave_);
- **Document Frequency**: $n$ (_none_, nessun fattore), $t$ (_idf_), $p$ (_prob idf_);
- **Normalizzazione**: $n$ (_none_, nessuna), $c$ (_cosine_), $u$ (_pivoted unique_), $b$ (_byte size_).

Uno degli schemi classici è ***lnc.ltc***: i documenti pesano i termini con la term frequency logaritmica, senza fattore *idf* e con normalizzazione del coseno, mentre la query utilizza la medesima term frequency logaritmica, l'*idf* e la normalizzazione del coseno.
#### L'esempio svolto a lezione: lo schema lnc.ltc
Per fissare le idee si consideri l'esempio classico svolto a lezione, con $N=1.000.000$, query $q$= _best car insurance_ e documento $d$= _car insurance auto insurance_:

- **Lato query (ltc)**: ciascun termine riceve il peso $(1+log\ tf_{t,q}​)×idf_{t}$​, con $df_{best​}$=$50.000$, $df_{car}​=10.000$ e $df_{insurance}​=1.000$: si ottengono i pesi $1,3$ (_best_), $2$ (_car_) e $3$ (_insurance_). La lunghezza della query vale $∥q​∥=\sqrt{ 0^2+1,3^2+2^2+3^2 }​≈3,83$, da cui i pesi normalizzati:
	- $0,34$ 
	- $0,52$
	- $0,78$
- **Lato documento (lnc)**: ciascun termine riceve il peso $1+log\ tf_{t,d}​$ (senza fattore idf): si ottengono $1$ (_auto_), $1$ (_car_) e $1,3$ (_insurance_). La lunghezza del documento vale $∥d∥=\sqrt{ 1^2+0^2+1^2+1,3^2 }​≈1,92$, da cui i pesi normalizzati 
	- $0,52$
	- $0,52$
	- $0,68$

I termini _car_ e _insurance_ contribuiscono rispettivamente $0,52×0,52=0,27$ e $0,78×0,68=0,53$, mentre _auto_ (assente nella query) e _best_ (assente nel documento) contribuiscono $0$:
$$Score(q,d)=0+0+0,27+0,53≈0,8$$
![[Pasted image 20261021184423.png]]

> [!NOTES] Il ranking nello Spazio Vettoriale 
> Per effettuare il ranking in un modello a spazio vettoriale:
> 
> 1. si rappresenta la query come un vettore nello spazio $∣V∣-dimensionale$, pesato mediante il tf-idf;
> 2. si rappresentano gli $N$ documenti come vettori nello stesso spazio, pesati mediante il tf-idf;
> 3. si calcola la similarità del coseno tra il vettore della query e quello di ciascun documento;
> 4. si ordinano i documenti in base ai punteggi ottenuti;
> 5. si restituiscono all'utente i primi $k$ documenti (_top-$k$_).

---
## WordNet e la disambiguazione semantica
Come emerso nella parte introduttiva, per definirsi _intelligente_ un motore di ricerca deve andare oltre la semplice corrispondenza letterale dei termini. Si pensi infatti alla situazione in cui venga effettuata una query contenente parole **polisemiche**: si rischia di ottenere documenti inerenti ad aree semantiche non rilevanti per l'utente. In modo analogo, la **sinonimia** porterebbe all'esclusione di documenti che potrebbero invece essere utili, poiché esprimono il concetto cercato tramite un termine differente rispetto a quello digitato. Anche il modello a spazio vettoriale, pur bilanciando l'importanza relativa dei termini tramite il tf-idf, resta fondato su una rappresentazione puramente lessicale e non risolve questi problemi: è pertanto necessario ideare appositi **algoritmi di disambiguazione**, in grado di interpretare il significato dei termini nel loro contesto e di migliorare di conseguenza i risultati delle query.

Viene per questo utilizzato **WordNet**, un sistema nato con l'intento di definire un **database lessicale** per effettuare delle ricerche concettuali all'interno di un dizionario, ma largamente impiegato nel campo dell'Information Retrieval per **aggiungere semantica** al processo di ritrovamento.

> [!NOTES] WordNet**WordNet** organizza il lessico in **synset** 
> Ovvero insiemi di termini sinonimi che esprimono uno stesso concetto, collegati tra loro da relazioni semantiche (come ad esempio l'iperonimia: _auto_ → _veicolo_). In questo modo i termini vengono associati non più in base alla loro forma, ma al loro **significato**, costituendo la base di conoscenza su cui si fondano i sistemi di _Word Sense Disambiguation (WSD)_ citati in precedenza.
### Concetto di Parola
Nel modello lessicale di WordNet, il concetto di **parola** viene distinto in due componenti fondamentali:
- **Word Form ($F$)**: la rappresentazione fisica e lessicale della parola, ovvero la stringa di caratteri che la compone.
- **Word Meaning ($M$)**: il concetto o significato semantico che quella parola esprime.

WordNet mette in relazione le *word form* con i rispettivi *word meaning* attraverso una **matrice lessicale di corrispondenza** (*Lexical Matrix*).
![[Pasted image 20261021185932.png]]

Osservando la matrice è possibile formalizzare i due fenomeni linguistici principali:
- **Sinonimia**: si verifica quando due diverse *word form* condividono lo stesso *word meaning* (ad esempio le celle $F_1 M_1$ e $F_2 M_1$ sulla stessa riga).
- **Polisemia**: si verifica quando una stessa *word form* è associata a più *word meaning* distinti (ad esempio le celle $F_2 M_1$ e $F_2 M_2$ sulla stessa colonna).

Questo principio ricalca la struttura del **dizionario tradizionale**, il quale utilizza una **glossa** (una breve definizione testuale accompagnata da esempi d'uso) per descrivere il significato di un termine, elencarne i sinonimi e distinguere le varie accezioni delle parole polisemiche. Lo scopo principale di WordNet è proprio quello di tradurre e strutturare in formato digitale questa conoscenza linguistica, rendendola elaborabile da una macchina.

> [!NOTES] Definizione di Synset
> Il **synset** (*synonym set*) è l'**insieme delle *word form* sinonime** che possono essere utilizzate per rappresentare uno specifico *word meaning*. 
> Un synset associato a una *word form* consente di inferire la semantica del termine in esame purché si conosca il significato di almeno una delle *word form* elencate al suo interno: se ad esempio si conosce il significato di $F_1$ ma non quello di $F_2$, il fatto che appartengano allo stesso synset permette di dedurre che $F_2$ esprime il medesimo concetto di $F_1$.
### Rappresentazione dei documenti: dalla Bag of Words alla Bag of Synsets
Sfruttando la matrice lessicale di WordNet è possibile rappresentare il contenuto dei documenti in modo molto più preciso, superando i limiti storici della rappresentazione **Bag of Words** legati a sinonimia, polisemia e termini composti (*n-grammi*):
- **Gestione dei sinonimi**: termini diversi ma equivalenti vengono ricondotti a un unico concetto.
- **Gestione dei bigrammi e delle locuzioni**: espressioni composte come *Artificial Intelligence* non vengono più spezzate in due token separati e indipendenti (*artificial* e *intelligence*), ma trovano una corrispondenza diretta in un'unica voce concettuale all'interno del dizionario di WordNet.

Si passa così da una rappresentazione *Bag of Words* a una rappresentazione **Bag of Synsets**, in cui i documenti e le query sono indicizzati tramite identificatori di concetti (*synset*) anziché semplici stringhe di caratteri:
- Se una query e un documento utilizzano sinonimi diversi (ad esempio *car* e *automobile*), il motore di ricerca effettua comunque il **match**, poiché entrambi i termini vengono mappati sullo stesso synset.
- Parallelamente, parole con la stessa *word form* ma usate con accezioni diverse vengono associate a *word meaning* (e quindi synset) differenti, evitando falsi positivi nel recupero dei documenti.

Lo **svantaggio principale** dell'uso di WordNet risiede proprio nella necessità di eseguire la **disambiguazione** (*Word Sense Disambiguation*), ovvero associare il significato corretto a tutte le parole ambigue presenti nei documenti e nelle query: un'operazione onerosa sia se svolta manualmente tramite annotazione umana, sia se affidata ad algoritmi automatici.
### Similarità semantica dei synset
Per stabilire automaticamente quale synset associare a una parola ambigua, gli algoritmi di disambiguazione sfruttano la struttura di WordNet per calcolare la **similarità semantica tra synset** in base al contesto della frase.

A differenza di un dizionario tradizionale, WordNet collega i concetti (sostantivi, verbi, ecc.) tramite **relazioni semantiche**. Per i sostantivi, la relazione principale è di tipo **gerarchico** (**iperonimia/iponimia**, ovvero la relazione *is-a*), che organizza i synset in un albero tassonomico partendo dai concetti più **generali** (*iperonimi*) fino a quelli progressivamente più **specifici** (*iponimi*).
![[Pasted image 20261021192409.png]]

All'interno di questa gerarchia, concetti semanticamente affini (come *cat* e *feline*, o *cat* e *mouse* intesi come animali) si trovano **vicini nell'albero** e presentano un'elevata similarità.
Per quantificare matematicamente questa vicinanza si utilizza la misura di similarità di **Leacock-Chodorow**, che si basa sulla distanza tra i nodi dell'albero:
1. Dati due concetti, si individua il loro **sussuntore comune più specifico** (*Least Common Subsumer - LCS*), ovvero l'antenato comune più basso nella gerarchia che generalizza entrambi (nell'esempio in figura è *placental mammal*, il concetto comune più specifico che lega il ramo dei felini e quello dei roditori).
2. Si calcola la lunghezza del percorso minimo ($\text{len}$) contando i passaggi necessari per risalire dal primo concetto fino al sussuntore comune e ridiscendere lungo l'altro ramo fino al secondo concetto.
3. Si applica la formula logaritmica di **Leacock-Chodorow**, che rapporta la lunghezza del percorso al doppio della **profondità massima $D$** della tassonomia di WordNet (nella versione di WordNet mostrata in figura, la profondità massima dell'albero è pari a $D = 16$):

$$\text{Sim}_{\text{LCH}}(c_1, c_2) = -\log\left(\frac{\text{len}(c_1, c_2)}{2D}\right)$$

Più il percorso tra i due nodi è breve, più il valore restituito dalla formula sarà alto, indicando quale accezione del termine è semanticamente più plausibile nel contesto. Al contrario, confrontando *cat* (animale) con il significato di *mouse* inteso come periferica del PC, il percorso nell'albero per trovare un antenato comune sarà lunghissimo e la similarità risulterà molto bassa.
#### Esempio di disambiguazione con Leacock-Chodorow
Si consideri la frase:
> *"The white cat is hunting the mouse"*

Supponiamo di voler disambiguare i sostantivi della frase: **cat** (che può indicare il *felino* oppure la *CAT*, ovvero la TAC come esame clinico) e **mouse** (che può indicare il *roditore* oppure il *dispositivo informatico*).

1. **Pre-processing**: si eliminano le *stop words* (*the*, *is*) e si riconducono i termini alla forma base, ottenendo i token significativi:
   `white cat hunt mouse`
2. **Estrazione dei synset candidati**: poiché l'algoritmo confronta i sostantivi sulla gerarchia tassonomica, si prendono in esame **cat** e **mouse** e si estraggono da WordNet gli identificatori univoci dei rispettivi significati (synset):
![[Pasted image 20261021193449.png]]

3. **Calcolo della similarità**: si calcola la similarità di **Leacock-Chodorow** per tutte le $4$ combinazioni possibili tra i synset di *cat* e i synset di *mouse*:
![[Pasted image 20261021193527.png]]

4. **Scelta del significato (Disambiguazione)**: si osserva che il punteggio di similarità più alto si ottiene in corrispondenza della coppia **felino** per *cat* e **roditore** per *mouse*. Il sistema seleziona quindi questi due synset come significati corretti per indicizzare i concetti della frase.

Ovviamente WorldNet ora è datato, esistono versioni migliori basati su reposotory di conoscenza molto più vasti come **BubbleNet**, gli LLM hanno aiutato molto queste procedure di linguismo nella storia.
#### Relazione Parte - Tutto
Oltre alla gerarchia _iperonimia/iponimia_ (_is-a_), WordNet collega i synset anche attraverso le **relazioni parte-tutto** (_has-part_ / _part-of_), chiamate **Meronimia** (il rapporto dalla parte al tutto) e **Olonimia** (il rapporto inverso, dal tutto alla parte):

Le relazioni **parte-tutto** descrivono la composizione strutturale degli oggetti e risultano fondamentali per comprendere la struttura fisica e funzionale delle entità. In WordNet la meronimia si distingue in tre tipologie principali:

- **Part-Meronym**: identifica i componenti fisici e strutturali di un oggetto (ad esempio un componente che è parte di _"automobile"_, come il motore o la ruota).

- **Member-Meronym**: identifica i singoli membri che compongono una collezione o un gruppo (ad esempio _"albero"_ è membro di _"foresta"_).

- **Substance-Meronym**: identifica i materiali costitutivi di cui è fatta un'entità (ad esempio _"legno"_ è la sostanza di _"tavolo"_).