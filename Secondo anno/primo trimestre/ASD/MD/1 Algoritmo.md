L'algoritmo è il **procedimento di calcolo**.
==Un algoritmo è una sequenza di azioni che un esecutore deve svolgere per giungere alla soluzione di un qualsiasi problema computazionale.==
Un algoritmo si comporta come una scatola, prende al suo ingresso dei dati trasformandoli in dati di output.
Tra gli **algoritmi** e i **dati** esiste un forte legame di unione; ponendo un esempio possiamo dire che l'algoritmo è la ricetta e i dati di ingresso sono gli ingredienti, il piatto terminato è il dato di output.
### Algoritmi e problemi
Il problema computazionale non è l'algoritmo:
- Il **problema computazionale** specifica il risultato che si vuole ottenere ovvero specifica la relazione che lega i dati di input a quelli di output.
- L'**algoritmo** definisce la serie di passi da eseguire per risolvere un problema.
### Descrizione di algoritmi
La **descrizione** di un algoritmo è composta da azioni elementari. L'effetto di un'azione su un dato è certo, unico e ripetibile non deve dipendere da fattori casuali con azioni comprensibili.
### Valutazione di algoritmi
Per valutare un algoritmo si studia la **correttezza** ed **efficienza**: 
- Lo scopo della **correttezza** sta nel dimostrare che l'algoritmo produca il risultato atteso. La correttezza richiede una dimostrazione matematica tramite **induzione** (passo base e passo induttivo).
- L'**efficienza** è l'analisi della nostra soluzione in termini di **spazio** e **tempo** (*occupazione di memoria e velocità*); per comprendere ciò si analizzano le operazioni dominanti, cioè quelle eseguite con maggior numero di volte ed esaminare quante volte vengono riutilizzate.
Correttezza ed efficienza non sono gli unici metodi di valutazione di un algoritmo, anche se sono i più solidi, esistono anche la robustezza, semplicità, la modularità, la possibilità di espandere e migliorarlo e la sicurezza.
## Progettare un algoritmo
Un ottima progettazione di un algoritmo sta nel classificare il problema e capire che soluzioni già presenti siano adatte per la determinata classe di problema.
Inoltre bisogna centrare gli **obiettivi** chiave, ovvero l'esecuzione di un ottima programmazione modulare ed essere in grado SEMPRE di applicare una metodologia di progetto alternativa attraverso una tecnica formale basata sull'astrazione di dati.
### Ciclo di Sviluppo del Software
Per lo sviluppo di un software si eseguono determinate fasi:
- **Studio di fattibilità**: valutare i costi e benefici del sistema da costruire, analizzare le risorse necessarie, i tempi e i modi di attuazione.
- **Raccolta e analisi dei requisiti**: 
	- Scopi: definire il tipo di problema e specificare l'ambiente di sviluppo che sia SW o HW (software e hardware).
	- Risultato: è un documento informativo che specifica l'ambiente di sviluppo adottato, le tecniche utilizzate e i dati sui cui si deve adoperare.

Il nostro studio è collocato nella fase di **Progettazione**.
Le qualità che deve possedere un programma sono di due tipi, **interne** ed **esterne**.
#### Qualità Esterne
Sono quelle utili all'utente e si dividono in:
- Correttezza: capacità di eseguire precisamente i compiti individuati durante l'analisi dei requisiti
- Efficienza: usare in modo razionale ed economico le risorse di calcolo
- Robustezza: funzionare anche in condizioni anomale e limitanti
- Usabilità: la capacità di consentire un interazione semplice e naturale con un utente finale.
Molto spesso la correttezza e l'efficienza vanno in **conflitto** tra loro, la soluzione migliore non è sempre la più buona in termini di efficienza. Per questo sta allo sviluppatore trovare il giusto compromesso.
#### Qualità Interne
Sono qualità percepibili non esternamente ma da chi scrive/riprende il codice e legge dalla sua progettazione e sono:
- Riusabilità
- Modularità
- Estensibilità
- Portabilità e Compatibilità
- Leggibilità
- Documentazione
## Principi di progettazione
Il principio fondamentale nella progettazione è il concetto di **Astrazione dei dati** (nei sistemi software). L'astrazione si basa sul:
==Focalizzarsi sul livello di dettaglio necessario in cui soffermarsi senza addentrarsi ulteriormente nei dettagli, altrimenti si rischia di perdersi e di giungere ad informazioni superflue, difficili e inutili. Bisogna astrarre fino all'informazione principale ed utile.==
Per capire qual è il livello di dettaglio ottimale a cui fermarsi — senza perdere informazioni rilevanti (se ci si ferma troppo presto) o sovraccaricare il sistema (se ci si ferma troppo tardi) — è necessaria molta esperienza.  
L’astrazione fornisce infatti un metodo efficace per controllare la complessità e mantenere la coerenza nei sistemi software complessi.

In alcuni ambiti, questo tipo di astrazione viene definito **modellazione analitica**. Essa parte dall’osservazione di un fenomeno o di un sistema, a cui segue la formulazione di ipotesi e assiomi che lo descrivono. Tali assiomi permettono di definire i dati e le funzioni da utilizzare per costruire un modello capace di formulare previsioni.

Si tende a definire una gerarchia di **livelli di modelli** per comprendere quale livello sia più adatto a uno specifico scopo: i livelli inferiori offrono una descrizione più dettagliata, mentre quelli superiori forniscono una visione più astratta e sintetica.  
A questo punto entra in gioco la natura delle astrazioni nel software: esse tendono a mettere in evidenza gli **aspetti funzionali**, separando il **“come arrivo”** dal **“cosa voglio ottenere”**.

Generalizzare un metodo risolutivo ideato per un problema specifico richiede di cogliere l’essenza del **principio algoritmico sottostante**, ossia la logica generale che può essere riapplicata a contesti diversi, indipendentemente dai dettagli particolari dell’implementazione
### Astrarre su dati e funzioni
Per estrarre dobbiamo dividere a due tipi questa pratica:
- **Astrazione sui dati**: definire nuovi dati e strutture dati senza preoccuparci di ciò che avviene alle spalle, ovvero nella memoria e nei vettori. Esternamente sembrerà avere un funzionamento totalmente diverso dai costrutti basilari, facendo trasparire all'esterno un altro tipo di dato. 
- **Astrazione sulle funzioni**: ci si concentra sul cosa da la funzione e non sul come lo fa.
La **struct** utilizzata nel C è l'esempio più basilare della creazione del nuovo dato, ma essa presenta vantaggi ma molte limitazioni, essendo proprio un caso base.
Uno dei problemi principali è che i controlli sui campi sono eseguiti durante l'inserimento dei dati fuori dalla struttura e non al suo interno. Ma i controlli di dati che provengono dall'esterno come un DB saranno by-passati senza poter attuare un controllo su di essi.
## Tecniche di Programmazione
Esistono delle Tecniche che favoriscono aiuti e/o svantaggi durante la progettazione.
- **Tecniche di specifica**: ovvero dimostrare l'idea e il concetto mediante grafi
- **I linguaggi**: riguardano i metodi per la stesura dei programmi a partire dal concetto.
- **Modularizzazione**: razionalizza il software attraverso l'uso di programmi indipendenti e interagenti tra loro.
- **Tecniche di progettazione di algoritmi e strutture dati**
- **Tecniche di progettazione per specifiche classe di applicazioni** come le applicazioni distribuite, concorrenti, ecc...

## Classificazione dei linguaggi di programmazione
- Linguaggi **imperativi**
- Linguaggi di programmazione **Funzionale**
- Linguaggi di programmazione **Logica**
- Linguaggio di programmazione **Object Oriented**
## Ottima modularizzazione
La qualità della modularizzazione aumenta all'aumentare della:
- **Coesione** -> incapsula informazioni omogenee, indipendenti da altri moduli 
- **Information Hiding** -> i dettagli interni del modulo non devono avere ruoli nell'uso del modulo da parte di moduli esterni.
al diminuire del:
- **Accoppiamento** tra moduli -> quindi non si utilizzano dipendenze volute, come variabili globali che sono visibili ed utilizzabili da più moduli
È all'uso di:
- **Interfacciamento esplicito** -> rappresentare tutti i dati che vengono scambiati tra due sottoprogrammi mediante parametri.