Nell'interazione con un sistema informatico, anche l'utente più esperto finisce inevitabilmente per sbagliare. Per capire bene cosa si intende per errore e come affrontarlo, lo standard **ISO 9241-110** definisce **error-tolerant** quei sistemi che permettono all'utente di raggiungere gli obiettivi desiderati nonostante gli errori compiuti, con il minimo sforzo correttivo (o addirittura senza dover intervenire).

Per classificare l'errore umano dal punto di vista psicologico e operativo, invece, si fa riferimento allo psicologo **James Reason** (*Human Error*, 1990), che dà questa definizione di errore:

>[!NOTE] Definizione di Errore (James Reason)
>Termine generico per comprendere tutti i casi in cui una sequenza pianificata di attività fisiche o mentali fallisce il suo scopo, e quando questo fallimento non possa essere attribuito all'intervento di qualche agente casuale.

Secondo lo schema di Reason, un'azione è corretta solo quando c'era l'intenzione di agire, l'azione si è svolta come pianificato e ha ottenuto lo scopo desiderato. Quando manca una di queste condizioni, si possono avere quattro situazioni diverse:

![[Pasted image 20261124135404.png]]

- **Azione non intenzionale (*Lapsus* o *Slip*)**: l'utente aveva l'intenzione giusta e ha specificato l'azione corretta, ma nell'eseguirla sostituisce involontariamente un'azione o un comportamento al posto di un altro (ad esempio premendo il pulsante vicino per distrazione). Capita spesso quando due azioni si assomigliano o condividono l'inizio di una sequenza abituale (i cosiddetti *errori di cattura* di Norman). Proprio perché non è intenzionale, il lapsus è **prevenibile**: un buon progettista dovrebbe prevedere quanti più lapsus possibili per evitarli, anche se prevenirli tutti è quasi impossibile.
- **Azione intenzionale ma errata (*Mistake* / Sbaglio)**: l'utente agisce con intenzione e l'azione si svolge esattamente come aveva pianificato, ma non raggiunge lo scopo prefissato perché era sbagliata l'idea di partenza (ad esempio premere un interruttore convinti che accenda una certa luce, quando in realtà ne comanda un'altra).
- **Azione spontanea**: non c'era una reale intenzione precedente di agire, ma sul momento si compie un'azione intenzionale quasi di riflesso (come proteggersi con le mani se qualcuno ci lancia una palla di neve). Diventa un errore solo se produce effetti indesiderati.
- **Azione involontaria**: non c'era né l'intenzione di agire prima, né intenzione durante l'azione stessa (per esempio urtare il tavolo e rovesciare un bicchiere).
## Strategie per limitare gli errori
![[Pasted image 20261124140150.png]]

Come si vede dallo schema, per progettare tenendo conto dell'errore si lavora su due fronti: prima si cerca di **prevenire l'errore**, poi — quando l'utente sbaglia comunque — bisogna saperlo **gestire**, diagnosticandolo con messaggi chiari e aiutando l'utente a **correggerlo** (*recovery*).

Le strategie per prevenire gli errori si dividono in 8 punti (i 7 classici del libro di riferimento più l'attenzione a offrire alternative sicure):
- Diversificare le azioni dell'utente
- Evitare comportamenti modali
- Usare funzioni obbliganti
- Imporre input vincolati
- Non sovraccaricare la memoria a breve termine dell'utente
- Richiedere conferme
- Usare default inoffensivi
- Fornire alternative sicure
### Diversificare le azioni dell'utente
Per prevenire i lapsus è importante fare in modo che le azioni necessarie per compiti diversi siano ben distinte e separate, soprattutto tenendo lontani i comandi di uso frequente da quelli pericolosi o irreversibili. Un esempio tipico viene dai client di posta elettronica come Microsoft Outlook: nel menu *Edit*, comandi usati spesso come *Mark as Read* e *Mark as Unread* si trovano subito sopra a *Mark All as Read*, che invece segna tutte le email come lette senza possibilità di annullamento. Qui si crea un conflitto tra il raggruppamento di comandi simili e la prevenzione dell'errore, che si risolve allontanando il comando critico o chiedendo prima una conferma. Allo stesso modo, mantenere ben separate le aree e le categorie delle email aiuta a lavorare in spazi più ordinati e a evitare lapsus quando si cercano o si selezionano messaggi tra molte righe.
### Evitare comportamenti modali
Un sistema ha un comportamento **modale** quando, a fronte di una stessa azione dell'utente, si comporta diversamente a seconda dello stato (o modalità) in cui si trova, e questo stato non è facilmente riconoscibile.

>[!WARNING] Esempio
>Funzione di riconoscimento della password, dove le minuscole sono considerate diverse dalle maiuscole.

Se l'utente non conosce lo stato del sistema, non può prevedere come quest'ultimo risponderà alle sue azioni: per questo è preferibile segnalare un eventuale *Caps Lock* attivo proprio vicino al campo di inserimento (dove l'utente guarda), invece di limitarsi a rifiutare la password lasciandolo a fare più tentativi.

Un altro sistema che gestisce male le modalità è PowerPoint quando si disegnano le forme:
![[Pasted image 20261124141200.png]]

Dopo aver scelto una forma dal menu a tendina (che si richiude subito), il cursore resta una semplice croce e non fa capire quale figura si sta per disegnare. Un'ottima soluzione — adottata già in *MacPaint* — è modificare il cursore con la sagoma dello strumento o della forma da disegnare, rendendo lo stato visibile esattamente dove si concentra l'attenzione.
### Usare funzioni obbliganti
>[!NOTE] Definizione di Norman
>Le funzioni obbliganti sono situazioni in cui le azioni sono vincolate in modo tale che la mancata esecuzione di un passaggio impedisca il successivo.

In questo modo l'utente è portato a compiere le operazioni nell'ordine giusto senza poter saltare passaggi. Nei sistemi software questo meccanismo si realizza soprattutto con il modello **oggetto-azione**: prima si seleziona l'oggetto desiderato (per esempio un file) e solo dopo si sceglie il comando, perché così il sistema può disabilitare tutte le voci del menu che corrispondono ad azioni prive di senso sull'oggetto selezionato.
### Imporre input vincolati
Questa tecnica generalizza la nozione di funzione obbligante e consiste nel permettere all'utente di inserire solo **valori leciti** nel contesto corrente.
![[Pasted image 20261124142652.png]]

Guardando i quattro esempi in figura per inserire una data, le prime due opzioni si scartano subito: la n.1 separa i riquadri ma non spiega il formato atteso, mentre la n.2 indica `(gg/mm/aaaa)` ma lascia un unico campo libero. La n.3 è molto più chiara perché unisce una divisione visiva netta alla spiegazione esplicita del formato `(gg/mm/aaaa)`, anche se permette comunque di digitare date impossibili (come il 31 febbraio). La n.4, usando dei menu a tendina, impedisce del tutto di scegliere date non valide, ma introduce un altro problema: quando le liste sono molto lunghe (come 31 giorni o moltissimi anni) è facile far scivolare il mouse sulla voce adiacente. Per questo tra la 3 e la 4 non si può decidere solo a tavolino, ma servono delle vere prove d'uso con gli utenti.
### Non sovraccaricare la memoria a breve termine dell'utente
La memoria a breve termine ha una capacità limitata e trattiene le informazioni per pochissimo tempo. Se un'interfaccia costringe l'utente a ricordare molte opzioni o passaggi alla volta, aumentano sia la fatica sia la probabilità di sbagliare: un caso tipico sono i messaggi vocali pre-registrati dei call-center che leggono un elenco troppo lungo di scelte prima di far premere un tasto.
### Richiedere conferme
Bisogna sempre avvertire l'utente e chiedere conferma prima di effettuare azioni **irreversibili** o pericolose, spiegando con chiarezza quali sono le alternative possibili e le loro conseguenze.
![[Pasted image 20261124142910.png]]

Dall'immagine si nota subito che i due pop-up in basso sono molto confusionari: quello a sinistra (`Ok to not save game?`) usa una negazione ambigua che fa venire dubbi su cosa accada premendo *OK* o *Cancel*, mentre quello a destra usa un'etichetta fuori luogo (`Solution`) e pulsanti generici (*Yes/No*) al posto di verbi chiari. Ottima è invece la finestra di dialogo in alto, che fa capire all'istante il problema (`"Prova" esiste già`), le conseguenze (i contenuti verranno sovrascritti) e l'effetto dei due pulsanti (*Annulla* e *Sostituisci*).

Le conferme vanno però limitate ai soli casi non annullabili o molto onerosi da ripristinare: chiederle per azioni facilmente reversibili rallenta il lavoro e porta l'utente a cliccare "OK" per abitudine senza leggere, così come vanno evitate conferme inutilmente vessatorie (come obbligare a scrivere `YES` a mano).
### Usare default inoffensivi
Il sistema non dovrebbe mai intraprendere per default l'azione più pericolosa o costosa tra quelle possibili (ad esempio impostare come predefinita la stampa di *Tutte* le pagine invece della sola pagina corrente, rischiando di stampare per sbaglio centinaia di fogli senza preavviso). Tutto ciò che si progetta dev'essere a prova di errore (*foolproof*), partendo dal presupposto che qualsiasi utente — dal principiante all'esperto distratto — possa sbagliare, e scegliendo quindi valori predefiniti sicuri.
### Fornire alternative sicure
Oltre a prevenire il passo falso sul momento, è utile offrire sempre una via d'uscita sicura, come la possibilità di tornare indietro, salvare una bozza o cambiare scelta senza perdere ciò che si è già fatto.
## Un buon messaggio di errore
Quando l'errore si verifica comunque, il sistema deve rilevarlo e spiegarlo all'utente. Un buon messaggio di errore svolge tre funzioni fondamentali:
- Allertare l'utente che qualcosa non va (anche tramite icone e colori coerenti con la gravità del problema)
- Identificare l'errore, spiegando cosa non va e perché
- Dirigere l'utente, spiegandogli cosa dovrebbe fare per risolverlo

La stesura dei messaggi di errore segue linee guida ben precise: il testo deve spiegare esplicitamente qual è il problema usando un **linguaggio umano e vicino a quello dell'utente** (evitando codici tecnici incomprensibili), con un tono educato, preciso e in maniera **esaustiva**. Non bisogna mai rimproverare o colpevolizzare chi usa il sistema — molte applicazioni moderne arrivano persino a scusarsi in modo cordiale o autoironico — e tutto il contenuto deve essere orientato alla risoluzione concreta del problema.
### Linee guida per il web
Sul web, soprattutto nella compilazione dei moduli (*form*), i messaggi di errore devono essere chiaramente visibili ed espressi in un linguaggio comprensibile a tutti. Quando ci sono più campi errati, ogni avviso va mostrato direttamente vicino o sopra al campo a cui si riferisce, evitando finestre che coprano la form o lunghe liste da tenere a mente. Bisogna inoltre preservare per quanto possibile il lavoro già fatto dall'utente (non azzerando i campi compilati correttamente) e ridurre al massimo lo sforzo necessario per correggere: il sistema dovrebbe agire in automatico dove può — per esempio posizionando già il cursore sul campo da sistemare — così da non stressare troppo l'utente.
## Correggere l'errore (Recovery)
Una volta diagnosticato l'errore, bisogna permettere di risolverlo. Come si vede nello schema iniziale, la correzione (*recovery*) segue due strategie diverse:

Con la **backward recovery** (ripristino all'indietro) si annullano le conseguenze dell'errore per tornare allo stato iniziale e riprovare, ad esempio cancellando il campo errato oppure usando le funzioni di **Undo** e **Redo** a più livelli (indispensabili nei programmi di grafica, anche se più complesse da gestire quando i dati sono già stati salvati).

Con la **forward recovery** (ripristino in avanti), invece, non si torna indietro ma si cerca di raggiungere lo stato finale direttamente dallo stato di errore. Può avvenire in automatico da parte del sistema — come Google che corregge un errore di battitura mostrando *"Forse cercavi..."* — oppure per mano dell'utente, ad esempio modificando un rettangolo disegnato per sbaglio fino a trasformarlo in un quadrato invece di cancellarlo. È proprio questo approccio a rendere un sistema *error-tolerant*, anche se in alcuni casi porta a un risultato solo approssimato (*ripristino imperfetto*).

In entrambi i casi, secondo lo standard ISO 9241-110, conviene ridurre al minimo i passi richiesti per la correzione, permettere all'utente di rimandarla se non ha subito tutte le informazioni (*correzione differibile*) e, quando il sistema corregge qualcosa in automatico (come un correttore ortografico), avvisarlo sempre lasciandogli la possibilità di modificare la correzione.
