## Astrazioni funzionale
Un algoritmo produce nuovi tipi di **operazioni** sui dati, poiché trasforma in determinati modi, dei dati di input in risultati.
L'**astrazione funzionale** è la tecnica che permette di creare in un programma nuovi operatori. Questi sono definiti tramite sotto-programmi in cui si fa uso di operatori di base già noti, l'interno di questi sotto-programmi definiscono le regole di comportamento mentre il loro nome allude l'argomento di cui si occupa l'operatore.

I linguaggi di programmazione di alto livello permettono l'uso dell'astrazione funzionale, cioè si crea un **unità di programma** con un suo nome e delle istruzioni che deve eseguire, permettendo di essere messa in comunicazione tra il programma principale e se stessa. 
Al momento della sua chiamata il programma generale (chiamante) si blocca per far spazio all'unità chiamata, la quale in maniera indipendente svolgerà le sue funzioni e al suo termine riprenderà il normale flusso da dove si era fermato.

I costrutti linguistici per la creazione di un astrazione funzionale permettono la distinzione tra la definizione di:
- **specifica**, ovvero il *cosa* ci si aspetta dalla funzione, quindi la relazione che intercorre i dati di ingresso e i loro risultati. Per esempio nel caso del fattoriale la specifica dirà che:
  L'intestazione è *int Fatt(int k);* l'ingresso *k* (argomento) è una variabile di tipo intero; il risultato è ancora di tipo intero
- **realizzazione**, ovvero il *come* il risultato viene ottenuto, ovvero come è stata implementata la funzione
## Astrazione di dati
Il concetto di astrazione di dati estende il concetto precedente di astrazione funzionale.
Per comprendere, se l'astrazione funzionale definiva nuove operazioni, l'astrazione di dati **amplia i tipi di dati disponibili**, attraverso nuovi tipi di dati e nuovi tipi di operatori.
L'astrazione di dati sollecita ad individuare le **organizzazioni dei dati più adatte** alla soluzione del problema.

L'astrazione di dati in particolare permette di estendere l'algebra dei dati disponibile di un dato linguaggio.
**L'algebra** è un sistema matematico costituito da un dominio, il quale contiene dei valori dove sui quali è possibile eseguire determinate funzioni. Gli elementi principali di un algebra sono il tipo, il numero e le proprietà delle funzioni.

Non tutti i linguaggi di programmazione sono in grado di astrarre sui dati però, poiché poter eseguire astrazioni funzionali non permette automaticamente di poter astrarre sui dati; per coloro che ne sono in grado, il linguaggio di programmazione fornisce mezzi in grado di definire nuovi tipi di dati.
Un tipo di dato si dice **astratto** se le **operazioni applicabili sugli oggetti** che li rappresentano sono **isolate** dai **dettagli** usati per realizzare il tipo.
Bisogna avere un linguaggio fortemente tipizzato per avere una buona possibilità di astrarre sui dati, come pascal. Avendo un linguaggio che definisce differenti tipi, si possono:
- **utilizzare dati** che definiamo complessi a prescindere della loro effettiva complessità computazionale.
- creare procedure per i nostri dati dove solo i nostri dati possano accedervi in modo **esclusivo**.
Queste caratteristiche sono alla base della necessità per l'astrazione di dati, anche noti come **requisiti per l'astrazione di dati**.

### Requisiti dell'astrazione di dati
I requisiti si dividono in:
- **Requisito di astrazione**, esso è verificando quando la creazione di programmi che usano astrazione possono essere scritti **senza dipendenze di scelte di realizzazione**, per esempio (come detto precedentemente) nel Pascal, modificando l'implementazione di un programma che non ha dipendenze di relazione con un altro, può essere modificata a proprio piacimento, seppur questa porti sempre ai medesimi risultati.
  La mancanza del requisito di astrazione si manifesta con l'impossibilità di dichiarare variabili con il nuovo tipo creato.
- **Requisito di protezione**, esso è verificato se sui nuovi dati creati è possibile lavorare con gli operatori già definiti al momento in cui il tipo di dato è stato progettato e specificato, senza aggiungerne altri nuovi per farlo funzionare.
  La mancanza di questo requisito porta alla possibilità di lavorare su qualsiasi tipo di dato che sia simile, andato ad intaccare altri tipi di dati che non hanno legami.

## Specifica e Realizzazione
Riprendendo il discorso della specifica (cosa) e della realizzazione (come), si possono distinguere in ulteriori sottogruppi.
- **Specifica sintattica**, la quale fornisce i nomi dei tipi di dato utilizzati per la definizione della struttura, le costanti e le operazioni specifiche e i domini di partenza e di arrivo, ossia i tipi di dati di ingresso e i dati prodotti in uscita.
- **Specifica semantica**, accomuna i nomi creati alla specifica sintattica. Associa il nome al tipo introdotto nella specifica sintattica, il valore alla costante e la funzione all'operazione, specificandone per quest'ultima una **pre-condizione** e una **post-condizione**. La pre-condizione definisce quando l'operatore è applicabile e la post condizione stabilisce come il risultato sia vincolato agli argomenti dell'operatore.
- La **realizzazione** sfrutta nel modo più generale possibile gli aiuti offerti dall'IDE. La definizione di un formalismo riguardo la specifica sintattica non arreca gravi problematica, rispetto alla specifica semantica, poiché il loro formalismo deriva da linguaggio umano o matematico.

## Struttura di Dati
Possiamo concludere fornendo una sintesi, spiegando che il **tipo di dato** è un modello matematico composto da possibili valori, il suo dominio, sui quali vengono attuate delle operazioni precise, le funzioni.
Tuttavia una **struttura di dati** richiede più attenzione all'**organizzazione** imposta agli elementi che la compongono piuttosto che il tipo di elementi componenti.
Le strutture solitamente disponibili nei linguaggi di programmazione sono le tabelle monodimensionali (vettori, array) i cui elementi sono contenuti in memoria centrale in locazioni contigue.

Le strutture generalmente si differenziano in:
- **lineari**: i dati sono disposti in sequenza
- **non lineari**: non è presente una sequenza
- **statiche**: numero di elementi non modificabile nel tempo
- **dinamiche**: numero di elementi modificabile e variabile nel tempo
- **omogenee**: dati dello stesso tipo
- **non omogenee**: dati di tipo misti

***Per esempio*:**
Ipotizzo un array di n elementi, esso è definibile come una sequenza di oggetti in relazione d'ordine tra loro in modo lineare, l'accesso ad una singola cella di memoria avviene tramite l'indice. L'array è un vettore omogeneo, monodimensionale e statico.
Le specifiche di questo vettore sono:
1. Specifica sintattica:
	- Tipi: vettore, intero, tipo degli elementi
	- Operatori: 
		- *creavettore(n: intero) -> vettore* (Crea un vettore di dimensione $n$)
		- *leggivettore(v: vettore, i: intero) -> tipoelem* (Restituisce l'elemento del vettore $v$ presente nella posizione $i$)
		- *scrivivettore(v: vettore, i: intero, x: tipoelem) -> vettore* (L’operatore **scrivivettore** prende in ingresso un **vettore**, un **intero** (la posizione da modificare) e un **tipoelem** (il nuovo valore da scrivere), e restituisce un **nuovo vettore**)
2. Specifica semantica:
	- Tipi: int e vettore
	- Operatori:
		- ![[Pasted image 20251006190511.png]]
3. Realizzazione: 
	- Molto spesso nella maggior parte dei linguaggi il vettore è un dato primitivo.

# Introduzione alla programmazione Object Oriented e il C++
Ogni elemento presente nel mondo reale è definibile **oggetto** e ogni oggetto ha uno **stato** e un **funzionamento**.
Nel mondo software lo stato di un oggetto è un **attributo**, mentre il funzionamento è espresso attraverso i **metodi**.
## Vantaggi degli Oggetti
- **Modularità**: ogni oggetto è indipendente dagli altri e viene gestito in modo separato.
- **Information-Hiding**: proprio perché gestito in modo separato i suoi dettagli implementativi sono nascosti agli altri oggetti, rendendolo più sicuro.
- **Riutilizzo** del codice in cui è presente l'oggetto interessato. 
- **Sostituzione tra oggetti**.
## Classe
Nel mondo reale si tende a **raggruppare** oggetti che possiedono caratteristiche simili come diversi tipi di biciclette, sono pur sempre biciclette.
Quindi si dice che: 
==Una **classe** è un **modello astratto** che descrive le **caratteristiche comuni** (cioè gli attributi) e i **comportamenti** (cioè i metodi) di un insieme di oggetti simili.==
### Concetto di Ereditarietà
Alcune classi di oggetti diverse hanno caratteristiche comuni, per questo ciò che è in comune si può ereditare. L'**ereditarietà** è la caratteristiche che permette ad una classe di ereditare attributi e metodi di un **altra classe**.
Si crea un rapporto parentale in cui la classa $A$ definita padre, trasmette ai figli i metodi e/o attribuiti che possono possedere in comune **ma non vale il contrario**.
L’ereditarietà è un meccanismo potente per rappresentare una **gerarchia tra classi**.

## Programmazione Object Oriented
Nella programmazione imperativa (quella adoperata fin ora) è possibile accedere alle variabili globali da qualsiasi parte del programma, questo va a scapito dell’information-hiding, in cui nei programmi molto grandi diventa ingestibile e non si rispetta questa caratteristica e ciò comporta alla visualizzazione e modifica di tutti i moduli da parte di tutti senza poterli **incapsulare** e **controllare**.
Per risolvere queste problematiche viene in contro la **programmazione ad oggetti** / Programmazione object oriented / OOP:
==La programmazione Object Oriented è una disciplina che si basa su **oggetti** per imporre una **struttura modulare** ai programmi==.

### Oggetti e Classi
Un oggetto è una **collezione di dati**, detto stato dell'oggetto, e procedure in grado di **alterarne il comportamento** (lo stato).
La collezione di tutti gli **oggetti omogenei di un determinato tipo** che condividono gli stessi **attributi** è definita **classe**, dove ogni attributo è il **tipo** di un dato o metodo.
#### Linguaggi e programmazione Object Oriented
# Riassunto: Programmazione Orientata agli Oggetti
Un linguaggio orientato agli oggetti rappresenta i concetti di un problema come **oggetti**, entità che possiedono **attributi** (dati) e **metodi** (comportamenti).  
Questo paradigma si basa su alcuni principi fondamentali.

L’**incapsulamento** (information hiding) consiste nel nascondere i dettagli interni di un oggetto e nel rendere accessibili solo le informazioni necessarie.  
L’**astrazione dei dati** permette di descrivere un sistema complesso attraverso modelli semplificati che mostrano solo gli aspetti essenziali.  
Il **passaggio di messaggi** (message passing) descrive la comunicazione tra oggetti, e il **polimorfismo** consente a oggetti diversi di rispondere in modo differente allo stesso messaggio.
Un linguaggio object-oriented supporta anche l’**ereditarietà**, che consente di creare nuove classi a partire da altre già esistenti, riutilizzando e specializzando attributi e metodi.  
Grazie al **dynamic binding**, la scelta del metodo da eseguire avviene durante l’esecuzione del programma, rendendo possibile il polimorfismo.

Programmare con gli oggetti significa pensare al programma come a un insieme di entità che interagiscono.  
Ogni oggetto ha uno **stato** e un **comportamento** propri, può cambiare nel tempo ma mantiene la propria identità.  
Questo approccio si differenzia dalla programmazione procedurale, dove il problema è scomposto in funzioni e procedure secondo una logica top-down.  
Nella programmazione orientata agli oggetti, invece, la suddivisione avviene in termini di oggetti autonomi che cooperano fra loro.

L’uso di oggetti indipendenti rende il codice più modulare, facile da mantenere e da riutilizzare.  
L’approccio orientato agli oggetti permette di controllare meglio la complessità dei sistemi e favorisce il riuso e l’evoluzione del software nel tempo.

## I metodi
I dati presenti negli oggetti sono **privati**, quindi oggetti esterni non possono vedere questi dati, l'unico modo per visualizzarli e lavorare su di essi è tramite il **passaggio di messaggi**, ovvero un chiamata a procedura, definite in C++ **chiamata a funzioni membro**, metodo nascosto all'utente ma appartenente (non sempre) all'oggetto.
### Messaggi e metodi
Quando viene inviato un messaggio ad un oggetto, viene **selezionato** un metodo tra quelli possibili che possa rispondergli. Di per se non viene invocato il metodo di un altro oggetto, questo **non è possibile** poiché ricordiamo che un oggetto non può vedere i dati privati di un altro oggetto, ma vengono **inviati semplicemente i messaggi**.
