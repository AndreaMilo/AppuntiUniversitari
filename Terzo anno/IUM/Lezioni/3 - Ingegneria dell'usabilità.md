# Ingegneria dell'Usabilità e Human-Centred Design (HCD)

## Progettare vs realizzare
Prima di costruire qualsiasi sistema informatico, è fondamentale distinguere due concetti base:
- **Progettare** (dal latino _proicere_, gettare avanti; in inglese _to design_): significa immaginare, ideare qualcosa che ancora non c'è e studiare il modo per attuarla. La progettazione è il ponte che unisce **ciò che esiste** (la conoscenza della situazione attuale) a **ciò che vogliamo che esista** (la situazione desiderata), passando attraverso i bisogni e i desideri delle persone.
- **Realizzare** (dal latino _res_, realtà): significa rendere reale e concreto ciò che è stato ideato, costruendolo praticamente.

### L'approccio tradizionale contro il nuovo approccio
- **Approccio tradizionale (orientato al sistema):** Ci si chiede semplicemente quali funzioni tecniche il sistema debba offrire all'utente, dopodiché le si progetta e le si realizza.
- **Nuovo approccio (orientato all'utente):** Ci si chiede prima quali siano i **"casi d'uso"** dell'utente rispetto al sistema, ovvero come e perché la persona userà quello strumento, e si progetta l'interazione di conseguenza.
    
Per applicare questo nuovo approccio in modo pratico, prima ancora di pensare alle funzioni del software, bisogna svolgere quattro analisi fondamentali (spesso complesse):

1. **Analisi dell'utente:** studiare le sue caratteristiche psico-fisiche e socio-culturali.    
2. **Analisi dei bisogni:** capire le sue necessità e aspettative verso il sistema.
3. **Analisi del contesto:** studiare l'ambiente specifico in cui verrà usato il sistema.
4. **Analisi dei "casi d'uso":** definire le situazioni concrete di utilizzo.

## Livelli di maturità della progettazione e il "Prodotto Invisibile"
La qualità della progettazione di un prodotto attraversa 4 livelli di maturità:

1. **Primo livello:** Il prodotto funziona (non si blocca, esegue il codice).    
2. **Secondo livello (System-Centered Design):** Il prodotto fornisce le funzioni richieste.
3. **Terzo livello (Human-Centred Design):** Il prodotto è facile da imparare e da usare.
4. **Quarto livello:** Il prodotto diventa **"invisibile"** durante l'uso.

### Cosa significa "Prodotto Invisibile"?
Un prodotto è invisibile quando permette all'utente di concentrarsi esclusivamente sul **compito** che sta svolgendo e non sullo strumento che sta usando. Lo strumento torna a essere "visibile" (cioè ci accorgiamo della sua presenza e ci pensiamo) solo quando qualcosa non va o si rompe.

## Ingegneria del Software vs Ingegneria dell'Usabilità
- **Ingegneria del software:** è la disciplina che si occupa dei problemi tecnici e gestionali per sviluppare software di qualità e senza sprechi, studiando i modelli di sviluppo.
- **Ingegneria dell'usabilità:** studia tecniche, metodi e processi per progettare e sviluppare sistemi **usabili**.

Secondo **Jakob Nielsen** (1994), l'ingegneria non consiste nel creare un sistema perfetto con risorse infinite, ma nel costruire in modo economico un sistema funzionante che soddisfi una necessità. Per farlo, l'ingegneria dell'usabilità impone di **specificare quantitativamente e in anticipo** quali caratteristiche di usabilità dovrà avere il prodotto finale e in quale misura. Se non possiamo misurare l'usabilità con criteri precisi, non possiamo sapere se il prodotto soddisfa le esigenze.
### I 3 principi cardine dell'Ingegneria dell'Usabilità
1. **Focalizzazione sull'utente:** dall'inizio e per tutto il processo.
2. **Modello iterativo:** progettazione e sviluppo basati su prototipi successivi.
3. **Prove con l'utente:** test continui lungo tutto il processo, raccogliendo sia **analisi qualitative** (opinioni, comportamenti) sia **misure quantitative** (tempi di esecuzione, numero di errori).

## I modelli di sviluppo: dal modello "a Cascata" a quello "Iterativo"

### Il Modello Tradizionale "a Cascata" (Waterfall)
Prevede fasi rigide e sequenziali: _Requisiti $\rightarrow$ Analisi e progettazione $\rightarrow$ Realizzazione $\rightarrow$ Test $\rightarrow$ Rilascio_.
- **Pro:** Fasi logiche ben definite; ogni fase dà l'input alla successiva; facile inserire punti di controllo (_check-point_); processo apparentemente facile da controllare.
- **Contro:** Dopo aver preso una decisione è **molto costoso tornare indietro**. Inoltre, il prodotto si vede solo alla fine (quando potrebbe non andare bene). Per i sistemi interattivi è un modello **concettualmente sbagliato e non funziona**.

### Perché il modello a cascata fallisce? Il "Ciclo Compito-Artefatto"
Il motivo per cui non si può fissare tutto all'inizio è spiegato dal **ciclo compito-artefatto**:
1. I **bisogni dell'utente** fanno nascere un nuovo **strumento** (artefatto).
2. L'introduzione dello **strumento** modifica il modo in cui l'utente lavora e vive, facendo nascere **nuovi bisogni** e cambiando i compiti stessi. Di conseguenza, **anche i requisiti evolvono durante il processo!**

### Il Modello Corretto: Sviluppo Iterativo
Si sviluppa per prototipi successivi: dopo aver raccolto i _Requisiti iniziali_, si entra in un ciclo continuo composto da **Progettazione $\rightarrow$ Prototipazione $\rightarrow$ Test & Rilascio**, tornando indietro per correggere e affinare.

- **Pro del modello iterativo:** Il prodotto si vede fin da subito (anche se parziale) e si perfeziona; le scelte si sperimentano in anticipo scartando subito quelle sbagliate; è il modello giusto per sistemi complessi.    
- **Contro del modello iterativo:** È difficile stimare i costi in anticipo (a preventivo); si rischia di non finire mai (divergenza del processo) per troppe richieste di modifica; i requisiti fluidi rendono più difficile la comunicazione tra team e cliente (committente).

### Altre varianti di modelli di sviluppo
- **Unified Software Development Process (Jacobson, Booch, Rumbaugh):** Mostra come nelle varie iterazioni nel tempo tutte le attività (requisiti, progettazione, prototipazione, test) siano presenti contemporaneamente, ma con "pesi" (risorse impiegate) diversi: all'inizio pesano di più i requisiti, verso la fine pesano di più i test e il rilascio.
- **Ciclo a cascata integrato con l'usabilità:** Inserisce attività centrate sull'utente (analisi degli utenti, interviste, visite sul posto, scenari, prototipi) come input per le fasi classiche del modello a cascata.
- **Ciclo di vita "a Stella" (Hix & Hartson, 1993):** Non esiste alcun ordine prestabilito tra le fasi (implementazione, prototipazione, analisi dei compiti, requisiti, progettazione concettuale). Al centro della stella c'è la **Valutazione**: ogni singola attività deve passare dalla valutazione prima di passare a un'altra attività qualsiasi.

## Lo Standard ISO 9241-210: Human-Centred Design (HCD) (possibile domanda?)
Lo standard internazionale **ISO 9241-210** (che ha sostituito il vecchio ISO 13407) definisce l'**HCD** (spesso chiamato anche **UCD - User-Centred Design**) come un approccio multidisciplinare che usa l'ergonomia e i fattori umani per creare sistemi usabili.
- **I vantaggi:** Aumenta l'efficacia e l'efficienza, migliora le condizioni di lavoro, protegge la salute e la sicurezza dell'utente, aumenta la produttività e riduce i costi di assistenza e addestramento.

### Le 4 fasi cicliche dello standard ISO 9241-210

Dopo aver pianificato il processo, si entra in un ciclo composto da 4 fasi (da ripetere finché i requisiti non sono soddisfatti):
1. **Comprendere e specificare il contesto d'uso:**
    - Definire chi sono gli utenti.
    - Identificare i compiti che dovranno svolgere.
    - Specificare l'ambiente fisico, sociale e tecnologico in cui useranno il sistema.
2. **Specificare i requisiti utente e organizzativi:**
    - Definire le prestazioni richieste rispetto agli obiettivi economici e operativi.
    - Rispettare le norme di legge, salute e sicurezza.
    - Stabilire la cooperazione tra utenti, la divisione dei compiti tra uomo e macchina, le procedure di lavoro, la gestione del cambiamento (es. addestramento), la manutenzione e il design dell'interfaccia.
3. **Produrre soluzioni di progetto (Design):**
    - Creare proposte con un team multidisciplinare.
    - Rendere concrete le idee tramite **simulazioni, modelli e prototipi**.
    - Far provare i prototipi agli utenti (anche simulando i compiti) e modificare il progetto in base alle loro reazioni.
4. **Valutare il progetto rispetto ai requisiti:**
    - Creare un piano di valutazione, raccogliere feedback, verificare se gli obiettivi sono raggiunti, fare validazione sul campo, monitorare nel lungo termine e documentare i risultati. Se non soddisfa i requisiti, si torna alle fasi precedenti!

## L'HCD nella pratica: UCD Sprint e Design Thinking
Il modello HCD dell'ISO 9241-210 è un modello teorico ("astratto"). Nella pratica lavorativa viene applicato attraverso metodologie concrete (istanze), tra cui le più famose sono lo **UCD Sprint** e il **Design Thinking**.

### UCD Sprint
Deriva dal celebre _Design Sprint_ ideato da Jake Knapp in Google. È un processo guidato passo-dopo-passo progettato per aiutare i team a generare idee in modo costruttivo.
- **Caratteristiche:** Ha una struttura molto chiara e definita, perfetta anche per i **team meno esperti** o per la formazione (mentre gli esperti possono eseguirlo molto velocemente). Pur sembrando lineare, mantiene la natura ciclica dell'HCD: le fasi si possono ripetere liberamente.
- **Le 3 macro-fasi dello UCD Sprint:**
    1. **Discovery (Scoperta e Analisi degli utenti):** Comprendere l'idea generale, fare una mappatura iniziale, analizzare i gruppi di utenti, fare interviste per raccogliere informazioni, definire gli obiettivi di UX e mappare il target.
    2. **Design (Brainstorming e Schizzi):** Esplorare idee suggerite dagli utenti, definire i compiti da testare, fare schizzi iniziali (_sketching_) e brainstorming, selezionare il design migliore, disegnare il flusso delle operazioni ideali (_happy paths_) e costruire prototipi a bassa fedeltà (_low-fi_).
    3. **Reality Check (Prototipo finale, Test e Analisi):** Testare i prototipi di carta con gli utenti, fare revisioni con esperti, creare un prototipo cliccabile realistico, fare test con **5 utenti**, analizzare i risultati, documentare il tutto e decidere i passi successivi.

### Design Thinking
Secondo il _Nielsen Norman Group_, il Design Thinking è sia un'**ideologia** (risolvere i problemi partendo dall'utente porta all'innovazione, che a sua volta porta a un vantaggio competitivo sul mercato) sia un **processo pratico**.
- **Perché è fondamentale:** Come afferma Jakob Nielsen, _"un'interfaccia meravigliosa che risolve il problema sbagliato fallirà"_. Il Design Thinking evita questo fallimento perché parte da dati reali, crea un linguaggio comune nel team ed esplora tante soluzioni diverse, concentrando la creatività sul **problema giusto**.
- **Le 6 fasi del Design Thinking** (divise in 3 macro-aree: _Comprendere, Esplorare, Materializzare_):
    1. **Empatizzare (Empathize):** Fare ricerca sul campo per capire cosa gli utenti fanno, dicono, pensano e provano.
    2. **Definire (Define):** Unire tutte le ricerche per capire dove sono i veri problemi degli utenti ed evidenziare le opportunità di innovazione.
    3. **Ideare (Ideate):** Fare brainstorming generando una quantità di idee creative (anche folli) per risolvere i problemi emersi nella fase di definizione.
    4. **Prototipare (Prototype):** Costruire rappresentazioni tangibili e reali per alcune delle idee scelte, così da capire quali parti funzionano e quali no.
    5. **Testare (Test):** Tornare dagli utenti reali con i prototipi per avere feedback e chiedersi: _"Questa soluzione risolve davvero il loro problema?"_.
    6. **Implementare (Implement):** Mettere in pratica la visione finale, assicurandosi che la soluzione venga realizzata e migliori concretamente la vita degli utenti.

_(Nota: Anche il Design Thinking è **altamente iterativo**: da qualsiasi fase è possibile tornare indietro alle fasi precedenti per affinare la comprensione o i prototipi)._

## Confronto finale: Meglio UCD Sprint o Design Thinking?
I due metodi si somigliano moltissimo perché sono entrambi figli dello stesso modello (ISO 9241-210). La scelta tra l'uno e l'altro dipende dal contesto:
- **UCD Sprint** è molto più strutturato e "guidato" passo dopo passo, quindi risulta comodissimo per i progettisti novizi o meno esperti.
- **Design Thinking** è più flessibile e diffuso a livello aziendale; spesso viene scelto perché l'azienda o il gruppo di lavoro lo adotta già come standard interno.