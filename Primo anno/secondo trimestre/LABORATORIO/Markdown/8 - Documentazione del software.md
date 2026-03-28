## Documentare un prodotto
Un prodotto viene documentato tramite due manuali solitamente:
- **Manuale Tecnico**: descrive **come è fatto** un prodotto
- **Manuale d'uso**: descrive **cosa fa** un prodotto

Un prodotto quindi non è altro che un insieme di <u>attributi</u> tangibili e intangibili di un bene o un <u>servizio</u> volti a procurare un beneficio a un <u>utilizzatore</u>, ottenuto tipicamente attraverso un processo di <u>produzione</u>

Alcune delle parole evidenziate possono essere associate al software, che anche lui è un **prodotto**:
- **Attributi** = Funzionalità del software
- **Servizio** = Scopo del software
- **Utilizzatore** = Utente del software
- **Produzione** = Sviluppo del software

Ogni prodotto che si rispetti ha un **interfaccia** e un **implementazione**:
- L'interfaccia è come il prodotto viene mostrato al pubblico
- L'implementazione invece è la struttura interna

La documentazione dell'interfaccia spiega come può il software (o la libreria) essere **utilizzata da un utente finale**, mentre la documentazione sull'implementazione fornisce dettagli **sul processo alla realizzazione del prodotto** 
### Documentazione di una libreria
Anche una **libreria** è un modulo di software più grande e può essere vista come un prodotto:
- **Attributi** = Cosa implementa (funzioni, procedure, tipi di dati, costanti...)
- **Servizio** = Scopo della libreria
- **Utilizzatore** = Sviluppatore che usa la libreria
- **Produzione** = Programmazione della libreria

L'interfaccia viene rappresentata dalle **funzioni implementate in una libreria**, mentre l'implementazione è **il codice sorgente che le realizza**, e tutte e due possono essere documentate in modo generativo.

L'interfaccia di una libreria software rappresenta **la descrizione degli attributi pubblici**, cioè le funzionalità utilizzabili dall'utilizzatore, in questo caso per le librerie in C si definisce con un file header di un modulo.
Fornire comunque il codice dell'interfaccia non è **sufficiente a rendere utilizzabile una libreria**, ma è necessaria una **documentazione aggiuntiva**.

Cosa deve offrire questa documentazione aggiuntiva?:
- Descrivere il **significato dei tipi** e delle **costanti pubbliche**
- Descrivere **cosa fanno le funzioni e le procedure**
- **Non deve descrivere come le funzioni e le procedure svolgono il loro compito** (concetto di information hiding)
Documentare il codice equivale a scrivere un **manuale d'uso**, in questo caso l'interfaccia di una libreria
### Documentazione vs commento
C'è un importante differenza tra la documentazione di un prodotto sorgente e il commento del codice sorgente:
- La **documentazione** spiega il significato di una funzione **all'utilizzatore**
- Il **commento** spiega i punti più critici al **programmatore** della funzione
### Documentazione di una funzione
Quando si documenta una funzione cosa bisogna inserire?
1. **Cosa fa la funzione**:
   - Scenari tipici (comportamento normale della funzione)
   - Scenari eccezionali (cosa fa la funzione in caso di situazioni anomale)
2. **Significato e dominio dei parametri**
3. **Esempi d'uso** 
4. **Pre-condizioni**
5. **Post-condizioni**
6. Eventuali riferimenti (altre funzioni, link, test, standard...)
7. Eventuali note (funzioni deprecate, portabilità...)
#### Documentazione pre-condizione
La pre-condizione è **una condizione che deve essere vera prima della chiamata di una funzione**, solitamente è una condizione sui paramenti.
Se una pre-condizione è falsa, **il funzionamento non è garantito**.
*ES*. la funzione per il calcolo del BMI ha come pre-condizione che peso e altezza siano maggiori di 0 ed eventualmente minuri di una certa soglia.

Il chiamante di una procedura ha la responsabilità di garantire la verifica di tutte le condizioni (una pre-condizione falsa è sintomo di bug)

**IMPORTANTE:** la definizione delle pre-condizioni non implica il mancato uso della programmazione difensiva, infatti è bene specificare le precondizioni ma anche rendere il codice solido in modo tale da restituire risultati anche quando le pre-condizioni non sono verificate
Sapere a priori quali errori possono verificarsi è diverso dallo scrivere codice in grado di gestirli!
#### Documentazione post-condizione
La post-condizione è **una condizione che deve essere vera dopo l'esecuzione di una funzione**, solitamente è sui parametri di output.
La falsificazione di una post-condizione (se le pre-condizioni sono verificato) è un chiaro sintomo della presenza di un bug nella funzione. 
*ES*. riprendendo il BMI, se non corrisponde a quello corretto evidentemente c'è un problema nell'implementazione
## Documentazione in linea
Oltre a documentare le funzioni nel modo convenzionale, si può documentare una libreria nel **codice sorgente stesso**, ma è necessario che tale documentazione sia poi accessibile all'utilizzatore della libreria

La documentazione in linea è scritta mediante **commenti speciali** (doc-comments) che seguono una convenzione particolare
### Generazione automatica di documentazione
Esistono tool particolari che esaminano il codice sorgente alla ricerca di doc-comment, poi vengono formattati in documenti in formato pdf, html, etc.
Questi strumenti si chiamano **tool di generazione automatica della documentazione**

Noi andremo ad usare [Doxygen](https://www.doxygen.nl/)
### Doxygen
#### Formattazione commenti
I commenti in Doxygen hanno una struttura leggermente differente,serve a farli distinguere dai commenti base di C
![[Pasted image 20250509183300.png]]
#### Header file
Una caratteristica di Doxygen è l’utilizzo di particolari annotazioni (tag) che servono a indicare porzioni particolari del codice sorgente, `@file` ad esempio indica il nome del file, `@version` la versione. L’uso dei tag serve a dare un significato ai commenti
![[Pasted image 20250509183450.png]]
#### \#Define e tipi di dato
Nei commenti inseriamo informazioni sul significato della `#define`  e sulle caratteristiche del tipo di dato
![[Pasted image 20250509183610.png]]
#### Enumerazione
![[Pasted image 20250509183651.png]]
#### Variabili globali
Nel caso delle variabili globali, si usa il tag `@warning` per fornire eventuali informazioni legate all’utilizzo
![[Pasted image 20250509184054.png]]
#### Funzioni
Utilizziamo `@param` per indicare quali parametri utilizza la funzione e `@return` per spiegare che valore restituisce. Prima di questi tag inseriamo anche una descrizione generale
![[Pasted image 20250509184256.png]]
#### Separare i commenti
A volte può essere utile distinguere i commenti, inserendo una parte di essi nel .h e una parte nel .c
Nel .h si inseriscono informazioni su parametri, tipi di ritorno e sullo scopo generale della funzione
Nel .c (dedicato all'implementazione) si dettagliano meglio le pre/post condizioni
![[Pasted image 20250509184353.png]]![[Pasted image 20250509184405.png]]
#### Manuale e configuration file
Il manuale è disponibile a questo [link](http://www.doxygen.nl/manual/commands.html)
\---
Oggi progetto deve avere un Doxygen configuration file che contiene informazioni utili per la generazione della documentazione dell'intero progetto
Anche per la generazione della documentazione di un singolo file sorgente è necessario un Doxygen configuration file.
Un template di file sorgente può essere generato con il seguente comando:`doxygen -g <config-file>` (dove config-file è il nome del file di configurazione)
Il template andrà customizzato in base all'esigenze del progetto, possono essere utilizzati dei tool grafici per modificare facilmente il template: doxywizard