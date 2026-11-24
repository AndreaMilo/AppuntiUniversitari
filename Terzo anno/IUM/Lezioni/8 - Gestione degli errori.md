Nell'interazione con un sistema informatico, anche l'utente più esperto commette inevitabilmente degli errori. Il progettista non deve colpevolizzare l'utente né pretenderne la perfezione: se l'utente sbaglia, è spesso perché il sistema gli consente di sbagliare. Occorre quindi progettare interfacce che riducano al minimo la probabilità di errore e ne limitino le conseguenze.

>[!NOTE] Sistema *error-tolerant* (Standard ISO 9241-110)
>Un sistema (o dialogo) che permette all'utente di raggiungere gli obiettivi desiderati nonostante gli errori compiuti — senza azioni correttive o con un intervento minimo — è definito **error-tolerant** (tollerante verso gli errori).

Per comprendere la natura dell'errore umano dal punto di vista psicologico e operativo, si fa riferimento agli studi di **James Reason** (*Human Error*, 1990):

>[!NOTE] Definizione di Errore (James Reason)
>Termine generico per comprendere tutti i casi in cui una sequenza pianificata di attività fisiche o mentali fallisce il suo scopo, e quando questo fallimento non possa essere attribuito all'intervento di qualche agente casuale.

## Classificazione dell'errore umano (Reason)
Secondo James Reason, un'azione è corretta quando soddisfa tre condizioni: c'era l'intenzione di agire, l'azione è proceduta come pianificato e l'azione ha ottenuto lo scopo desiderato. Quando manca una di queste condizioni, si individuano quattro categorie:

![[Pasted image 20261124135404.png]]

- **Azione non intenzionale (*Lapsus* o *Slip*)**: l'utente aveva l'intenzione di agire e ha pianificato l'azione corretta, ma nell'esecuzione sostituisce involontariamente un'azione o un comportamento con un altro (es. premere per sbaglio il pulsante adiacente a quello desiderato). I lapsus si verificano spesso quando due azioni si assomigliano o condividono una sequenza iniziale (i cosiddetti *errori di cattura* di Norman). Proprio perché non intenzionali, sono in larga misura **prevenibili** attraverso una buona progettazione, anche se evitarli tutti è pressoché impossibile.
- **Azione intenzionale ma errata (*Mistake* / Sbaglio)**: l'utente agisce con intenzione e l'azione si svolge esattamente come pianificato, ma non raggiunge lo scopo prefissato perché la scelta di partenza era sbagliata (es. premere un interruttore credendo che accenda la luce desiderata, quando in realtà comanda un'altra stanza).
- **Azione spontanea**: non c'era una precedente intenzione di agire, ma l'azione viene compiuta intenzionalmente sul momento come riflesso o reazione immediata (es. proteggersi con le mani quando qualcuno lancia una palla di neve). È classificata come errore solo quando produce effetti indesiderati.
- **Azione involontaria (non intenzionale)**: manca sia l'intenzione precedente di agire sia l'intenzione nell'azione stessa (es. urtare involontariamente il tavolo e rovesciare un bicchiere).

## Strategie per progettare per l'errore
Come illustrato nello schema seguente, progettare per l'errore si articola in due grandi momenti: **prevenire** l'errore prima che accada e **gestirlo** (diagnosticandolo e correggendolo) quando si verifica.

![[Pasted image 20261124140150.png]]

---

## 1. Prevenire l'errore
La prevenzione (*error prevention*) consiste nel progettare il sistema in modo che la possibilità di errore sia minima e che nessuna azione dell'utente possa causare un blocco o uno stato indefinito. Le principali strategie di prevenzione sono 8 (7 classiche del testo di riferimento, integrate con la disponibilità di alternative sicure):

1. Diversificare le azioni dell'utente
2. Evitare comportamenti modali
3. Usare funzioni obbliganti
4. Imporre input vincolati
5. Non sovraccaricare la memoria a breve termine dell'utente
6. Richiedere conferme
7. Usare default inoffensivi
8. Fornire alternative sicure

### Diversificare le azioni dell'utente
Consiste nel rendere ben distinte e separate le azioni necessarie per compiti diversi, soprattutto distanziando i comandi di uso frequente da quelli pericolosi o irreversibili, così da prevenire i *lapsus*.
- **Esempio**: nei client di posta elettronica (come Microsoft Outlook), nel menu *Edit* i comandi frequenti *Mark as Read* e *Mark as Unread* sono spesso vicini al comando critico *Mark All as Read* (che segna tutte le email come già lette e non è annullabile). Questo genera un conflitto tra il raggruppamento di comandi semanticamente affini e la prevenzione dell'errore: lo si risolve allontanando il comando pericoloso oppure mantenendolo vicino ma richiedendo una conferma prima dell'esecuzione. Analogamente, separare in modo chiaro le sezioni e le categorie delle email aiuta a mantenere ordinati gli spazi di lavoro e a ridurre il rischio di selezioni errate tra molte righe.

### Evitare comportamenti modali
Un sistema presenta un comportamento **modale** quando, a fronte di una stessa azione dell'utente, risponde in modo diverso a seconda dello stato (o modalità) in cui si trova, e questo stato non è facilmente riconoscibile dall'utente. Se l'utente non conosce lo stato corrente, non può prevedere il comportamento del sistema ed è facilmente indotto in errore.

>[!WARNING] Esempio: riconoscimento della password
>Nel campo di inserimento della password, le lettere minuscole sono considerate diverse dalle maiuscole. Se l'utente non sa che il tasto *Caps Lock* è attivo, continuerà a digitare credendo di aver commesso un errore di battitura. È quindi preferibile rendere visibile lo stato direttamente vicino al campo di input (dove si concentra l'attenzione dell'utente), segnalando il *Caps Lock* attivo o fornendo indicazioni chiare quando la password viene rifiutata.

Un altro classico esempio di comportamento modale si osserva in **PowerPoint** durante l'inserimento delle forme:

![[Pasted image 20261124141200.png]]

Dopo aver selezionato una figura dal menu a tendina (che si richiude subito), il cursore assume la forma generica di una croce (`+`) e non mostra all'utente quale forma sta per disegnare. Un'ottima soluzione (adottata ad esempio già in *MacPaint* nel 1984) consiste nel modificare l'aspetto del cursore con l'icona dello strumento o con la sagoma della forma da disegnare, rendendo lo stato immediatamente visibile proprio dove l'utente sta guardando.

### Usare funzioni obbliganti
>[!NOTE] Definizione di Donald Norman
>Le **funzioni obbliganti** (*forcing functions*) sono situazioni in cui le azioni sono vincolate in modo tale che la mancata esecuzione di un passaggio impedisca il passaggio successivo.

In questo modo l'utente è guidato a compiere le operazioni nell'ordine corretto. Nei sistemi software moderni (secondo il modello **oggetto-azione**, introdotto da Xerox Star e Apple Macintosh), l'utente seleziona prima l'oggetto su cui vuole operare e poi il comando da eseguire: selezionare l'oggetto desiderato (o non selezionarne alcuno) porta il sistema a **disabilitare automaticamente** tutte le voci di menu che corrispondono ad azioni prive di senso su quell'oggetto.

### Imporre input vincolati
Questa tecnica generalizza la nozione di funzione obbligante e consiste nel permettere all'utente di fornire esclusivamente **valori di input leciti e validi** nel contesto corrente.

![[Pasted image 20261124142652.png]]

Osservando gli esempi di inserimento della data mostrati in figura:
- Le opzioni **1** e **2** risultano inadeguate: la **1** separa i tre campi ma non esplicita il formato atteso, mentre la **2** indica il formato `(gg/mm/aaaa)` ma lascia un unico campo di testo non strutturato.
- L'opzione **3** è nettamente migliore delle prime due, perché abbina la divisione visiva netta dei tre riquadri a un'indicazione esplicita del formato atteso `(gg/mm/aaaa)`. Lascia tuttavia all'utente la libertà di digitare date formalmente non valide (es. `31/02`).
- L'opzione **4** utilizza menu a tendina con valori preimpostati, impedendo l'immissione di date illecite, ma introduce il rischio opposto: in elenchi molto lunghi (come 31 giorni o decine di anni) il puntatore può facilmente scivolare su una voce adiacente provocando un *lapsus*. Pertanto, per stabilire quale sia la soluzione migliore tra la **3** e la **4**, occorre effettuare delle **prove d'uso reali con gli utenti**.

### Non sovraccaricare la memoria a breve termine dell'utente
La memoria a breve termine umana ha una capacità limitata e trattiene le informazioni per poco tempo. Interfacce e dialoghi che obbligano l'utente a tenere a mente troppe opzioni o passaggi aumentano lo sforzo cognitivo e la probabilità di errore (come accade, ad esempio, nei messaggi vocali preregistrati dei call-center che elencano troppe alternative prima di permettere la scelta).

### Richiedere conferme
Il sistema deve sempre avvisare l'utente e richiedere conferma prima di eseguire azioni **irreversibili** o potenzialmente pericolose, spiegando con chiarezza quali sono le alternative possibili e le relative conseguenze.

![[Pasted image 20261124142910.png]]

Dal confronto tra le finestre di dialogo in figura emerge chiaramente la differenza tra una buona e una cattiva progettazione:
- La finestra **in alto** è un ottimo esempio: identifica il problema (`"Prova" esiste già. Vuoi sostituirlo?`), chiarisce le conseguenze (`i contenuti attuali verranno sovrascritti`) e propone due pulsanti espliciti e inequivocabili (`Annulla` e `Sostituisci`).
- I due pop-up **in basso** risultano invece ambigui e poco immediati: quello a sinistra (`Ok to not save game?`) usa una negazione che rende poco intuitivo l'effetto dei pulsanti `OK` e `Cancel`; quello a destra (Microsoft Access) impiega una dicitura fuorviante (`Solution`) e pulsanti generici (`Yes` / `No`) invece di verbi d'azione chiari (es. *Elimina* / *Annulla*).

>[!TIP] Quando evitare le conferme
>Le richieste di conferma vanno limitate alle sole operazioni non annullabili o molto onerose da ripristinare: chiederle per azioni facilmente reversibili intralcia il flusso di lavoro e porta l'utente a confermare meccanicamente senza leggere. Vanno inoltre evitate conferme inutilmente vessatorie (come obbligare a digitare manualmente `YES`).

### Usare default inoffensivi
Il sistema non dovrebbe mai impostare come valore predefinito (*default*) l'azione più pericolosa, costosa o distruttiva tra quelle possibili (ad esempio, impostare per default la stampa di *Tutte* le pagine in documenti molto lunghi anziché della sola pagina corrente, senza avviso). Progettare in modo **a prova di errore** (*foolproof*) significa assumere che qualsiasi utente — dal meno esperto al più esperto in un momento di distrazione — possa commettere un errore, scegliendo quindi valori predefiniti sicuri e non distruttivi.

### Fornire alternative sicure
Oltre a prevenire il passo falso, l'interfaccia dovrebbe offrire percorsi alternativi e vie d'uscita sicure (come l'annullamento rapido, il salvataggio temporaneo o la modifica di una scelta prima della conferma definitiva), evitando di mettere l'utente in situazioni senza ritorno.

---

## 2. Gestire l'errore: Diagnosi e messaggi di errore
Anche applicando le migliori tecniche di prevenzione, l'utente può comunque commettere un errore. In questo caso il sistema deve rilevarlo e comunicarlo efficacemente. Un buon messaggio di errore svolge **tre funzioni fondamentali**:
1. **Allertare**: segnalare all'utente che qualcosa non va (anche tramite icone e colori coerenti: ad esempio giallo per problemi recuperabili, rosso per errori gravi).
2. **Identificare**: spiegare con precisione *cosa* non va e *perché*.
3. **Dirigere**: indicare chiaramente all'utente cosa deve fare per risolvere il problema e ripristinare una situazione corretta.

La stesura dei messaggi di errore segue linee guida precise:
- Usare un **linguaggio umano, chiaro e vicino a quello dell'utente**, evitando codici tecnici comprensibili solo agli sviluppatori.
- Mantenere un tono **educato, preciso ed esaustivo**, senza mai rimproverare o colpevolizzare l'utente (molte applicazioni moderne adottano anzi un tono cortese o autoironico, i cosiddetti *self-deprecating error messages*).
- Orientare il contenuto alla **risoluzione concreta del problema** (eventualmente offrendo un messaggio sintetico affiancato da un collegamento a spiegazioni più dettagliate).

### Linee guida per i messaggi di errore sul web
- **Visibilità e linguaggio comprensibile**: i messaggi devono essere immediatamente visibili ed espressi in modo semplice e accessibile a tutti.
- **Associazione chiara ai campi (granularità)**: nella compilazione di form con errori multipli, ogni messaggio va collocato **direttamente vicino o sopra al campo errato** (ad esempio in rosso vivo), evitando finestre che coprano il modulo o lunghi elenchi che sovraccarichino la memoria a breve termine.
- **Preservare il lavoro svolto**: non cancellare i dati già inseriti correttamente dall'utente negli altri campi.
- **Ridurre al minimo lo sforzo di correzione**: il sistema dovrebbe agire automaticamente dove non serve l'intervento umano (es. posizionando il cursore sul campo da correggere), così da non stressare l'utente e rendere il recupero rapido.

---

## 3. Gestire l'errore: Correzione (*Recovery*)
Dopo aver diagnosticato l'errore, il sistema e l'utente devono poter riportare l'interazione in uno stato valido. Il processo di correzione (*recovery*) avviene secondo due strategie principali:

- **Backward recovery (Ripristino all'indietro)**: si annullano gli effetti dell'errore per tornare allo **stato iniziale**, da cui l'utente può ripetere correttamente l'azione (es. svuotare il campo errato, oppure usare le funzioni di **`Undo`** e **`Redo`** a più livelli nei programmi di grafica e scrittura). Non è sempre facile da realizzare, perché richiede memoria per gli stati precedenti o interventi complessi su dati già salvati.
- **Forward recovery (Ripristino in avanti)**: invece di tornare indietro, si cerca di raggiungere lo **stato finale desiderato direttamente dallo stato di errore**. Può essere eseguita automaticamente dal sistema (es. il motore di ricerca che corregge un errore di battitura mostrando *"Forse cercavi..."*) oppure manualmente dall'utente (es. ridimensionare un rettangolo disegnato per sbaglio fino a trasformarlo in un quadrato, anziché cancellarlo e ricominciare). I sistemi che applicano sistematicamente questa strategia sono detti *error-tolerant*. Talvolta la *forward recovery* produce un **ripristino imperfetto**, ovvero uno stato finale approssimato rispetto a quello ideale.

In entrambe le strategie (secondo lo standard **ISO 9241-110**), valgono tre raccomandazioni chiave:
- **Minimo sforzo di correzione**: ridurre e automatizzare il più possibile i passaggi richiesti all'utente.
- **Correzione differibile**: permettere all'utente di rimandare la correzione di un dato non immediatamente indispensabile per proseguire (es. un CAP da verificare in un secondo momento).
- **Correzione automatica modificabile**: quando il sistema corregge automaticamente un errore (es. correttore ortografico), deve avvisare l'utente e consentirgli di modificare o annullare la correzione.
