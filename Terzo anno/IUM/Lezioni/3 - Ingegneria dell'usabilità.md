# Ingegneria dell'Usabilità e Human-Centred Design (HCD)

## Progettare vs realizzare
> [!info] Definizione di Progettare e Realizzare
> Prima di costruire qualsiasi sistema informatico, è fondamentale distinguere due concetti base:
> - **Progettare** (dal latino *proicere*, gettare avanti; in inglese *to design*): significa *"immaginare, ideare qualcosa che ancora non c'è e studiare il modo per attuarla"*. La progettazione è il ponte che unisce **ciò che esiste** (la conoscenza della situazione attuale) a **ciò che vogliamo che esista** (la descrizione della situazione desiderata, *"ciò che potrebbe essere"*), passando attraverso i **bisogni e i desideri** delle persone.
> - **Realizzare** (dal latino *res*, realtà): significa *"rendere reale e concreto ciò che è stato ideato, attuandolo praticamente"*.

### L'approccio tradizionale contro il nuovo approccio
- **Approccio tradizionale (orientato al sistema):** ci si chiede semplicemente quali funzioni tecniche il sistema debba fornire al suo utente, dopodiché le si progetta e le si realizza.
- **Nuovo approccio (orientato all'utente):** ci si chiede prima quali siano i **"casi d'uso"** dell'utente rispetto al sistema, ovvero come e perché la persona userà quello strumento, e si progetta l'interazione di conseguenza.

Per applicare questo nuovo approccio in modo pratico, prima ancora di progettare le funzioni del sistema, bisogna svolgere **quattro analisi fondamentali** (spesso complesse):
1. **Analisi dell'utente:** studiare le sue caratteristiche psico-fisiche e socio-culturali.
2. **Analisi dei bisogni:** capire i suoi bisogni e le sue aspettative in relazione al sistema.
3. **Analisi del contesto:** studiare il contesto specifico in cui verrà usato il sistema.
4. **Analisi dei "casi d'uso":** definire le situazioni concrete di utilizzo.

## Livelli di maturità della progettazione e il "Prodotto Invisibile"
La qualità della progettazione di un prodotto attraversa **4 livelli di maturità**:
1. **Primo livello:** il prodotto funziona (non si blocca, esegue il codice).
2. **Secondo livello (*System-Centered Design*):** il prodotto fornisce le funzioni richieste.
3. **Terzo livello (*Human-Centred Design*):** il prodotto è facile da imparare e da usare.
4. **Quarto livello:** il prodotto diventa **"invisibile"** durante l'uso (permette all'utente di concentrarsi sul compito e non sullo strumento).

> [!info] Cosa significa "Prodotto Invisibile"?
> Un prodotto è **invisibile** quando permette all'utente di pensare e concentrarsi esclusivamente sul **compito** che sta svolgendo e non sullo strumento che sta usando. Lo strumento torna a essere "visibile" (cioè ci accorgiamo della sua presenza e ci pensiamo) solo quando c'è qualcosa che non va o si rompe.

---
## Ingegneria del Software vs Ingegneria dell'Usabilità
Per ottenere sistemi realmente usabili è necessario seguire tre direttrici fondamentali (formalizzate dallo standard **ISO 9241-210**, ex ISO 13407, *Human-Centred Design Process for Interactive Systems*):
- **Progetto centrato sull'utente:** comprendere gli utenti, i loro compiti e il contesto d'uso;
- **Sviluppo iterativo:** articolato in 4 step di sviluppo ciclici per ottenere e raffinare un prototipo;
- **Valutazione dei prototipi:** possibilmente condotta con gli utenti finali (o, in alternativa, tramite ispettori ed esperti di usabilità).

![[IUM_Pasted image 20261013162008.png]]

> [!info] Definizioni di Ingegneria del Software e Ingegneria dell'Usabilità
> - **Ingegneria del software:** è la disciplina che si occupa dei problemi tecnici e di gestione dello sviluppo dei sistemi software di qualità e senza sprechi; studia, tra l'altro, i vari modelli dei processi di progettazione e sviluppo dei sistemi software.
> - **Ingegneria dell'usabilità:** è la disciplina che studia le tecniche, i metodi e i processi che possono essere utilizzati per progettare e sviluppare sistemi **usabili**. Nella sua accezione più ampia, comprende la totalità delle pratiche utilizzate nel processo di progettazione e sviluppo dei sistemi interattivi, a partire dalla raccolta e analisi iniziale dei requisiti. Questo approccio dimostra che l'usabilità non è un semplice ritocco estetico finale, ma un processo olistico che guida e struttura l'intero ciclo di vita del prodotto.

> [!info] La misurabilità secondo Jakob Nielsen (*Usability Engineering*, 1994)
> *"L'ingegneria dell'usabilità è un processo, basato sull'ingegneria classica, che consiste nello specificare, quantitativamente e in anticipo, quali caratteristiche e in qual misura il prodotto finale da ingegnerizzare dovrà possedere. Questo processo è seguito dall'effettiva realizzazione del prodotto, e dalla dimostrazione che esso effettivamente possiede le caratteristiche pianificate.*
> *L'ingegneria non è il processo di costruire un sistema perfetto con risorse infinite. Piuttosto, l'ingegneria è il processo di costruire economicamente un sistema funzionante che soddisfa una necessità. In assenza di specifiche misurabili di usabilità, non c'è alcun modo di determinare le esigenze di usabilità di un prodotto, o di misurare se il prodotto soddisfi o meno tali esigenze. Se non possiamo misurare l'usabilità, non possiamo avere un'ingegneria dell'usabilità."*

### I 3 principi cardine dell'Ingegneria dell'Usabilità
1. **Centralità dell'utente (Focalizzazione sull'utente):** mantenere una costante focalizzazione sull'utente, dall'inizio e per tutta la durata della progettazione, è fondamentale per evitare l'errore comune di sviluppare soluzioni tecniche eccellenti ma inutilizzabili o distaccate dalle reali necessità del pubblico di riferimento.
2. **Testing continuo e basato sui dati (Prove con l'utente):** condurre test continui lungo tutto il processo, combinando **analisi qualitative** (opinioni, comportamenti) e **misure quantitative** (tempi di esecuzione, numero di errori), permette di validare le scelte di design basandosi su feedback reali e dati oggettivi, eliminando le supposizioni.
3. **Sviluppo iterativo:** adottare un modello di progettazione e sviluppo iterativo basato su prototipi successivi garantisce grande flessibilità, poiché permette di testare idee, individuare difetti precocemente a basso costo e affinare progressivamente l'interfaccia fino a raggiungere la soluzione ottimale.

---
## I modelli di sviluppo: dal modello "a Cascata" a quello "Iterativo"

### Il Modello Tradizionale "a Cascata" (Waterfall)
> [!example] Schema del modello a cascata
> ![[IUM_Pasted image 20261013163746.png]]

Il **modello tradizionale** di sviluppo (noto come *modello a cascata*) si basa su un approccio rigidamente lineare e sequenziale: *Requisiti $\rightarrow$ Analisi e progettazione $\rightarrow$ Realizzazione $\rightarrow$ Test $\rightarrow$ Rilascio*.
- **Pro:** Si distingue per avere fasi logiche ben definite, in cui ogni step si conclude fornendo direttamente gli input necessari alla fase successiva. Questa struttura a blocchi consente di inserire chiari punti di controllo (*check-point*) di verifica tra un passaggio e l'altro, rendendo l'intero processo *apparentemente* molto ben controllabile da un punto di vista gestionale.
- **Contro:** La natura sequenziale impone una grave inflessibilità: una volta presa una decisione (ad esempio sui requisiti o sul design), è **estremamente costoso tornare indietro** in termini di tempo e budget per correggere o modificare il lavoro fatto in fasi avanzate. Procedendo senza iterazioni, il committente e l'utente vedono il sistema solo alla fine del lunghissimo ciclo di sviluppo, con l'altissimo rischio di trovarsi di fronte a un risultato finale insoddisfacente o che non risponde più ai bisogni iniziali. Per la progettazione di sistemi interattivi è un modello **concettualmente sbagliato e di fatto non funziona**.

> [!question] Domanda d'esame: Differenza tra modello iterativo e modello a cascata

### Perché il modello a cascata fallisce? Il "Ciclo Compito-Artefatto"
> [!example] Schema del ciclo compito-artefatto
> ![[IUM_Pasted image 20261013164844.png]]

Il motivo per cui non si può fissare tutto all'inizio è spiegato dal **ciclo compito-artefatto**, che illustra la dinamica di continua evoluzione tra le necessità umane e le soluzioni tecnologiche:
1. I **bisogni dell'utente** fanno nascere un nuovo **strumento** (o artefatto), concepito appositamente per risolvere un problema o facilitare un determinato compito.
2. Tuttavia, il processo non si esaurisce con la creazione della soluzione: l'introduzione e l'utilizzo dello **strumento** modifica inevitabilmente l'ambiente, le abitudini e il modo in cui l'utente lavora e vive, trasformando nel tempo i bisogni stessi dell'utente, facendo nascere **nuovi bisogni** e cambiando i compiti.

Questa continua interazione evidenzia come la progettazione non sia mai un processo statico con un traguardo definitivo: risolvere un problema odierno introducendo una nuova tecnologia altera lo scenario di partenza, generando nuove sfide, aspettative e necessità che danno inizio a un nuovo ciclo di sviluppo. Di conseguenza, **anche i requisiti evolvono durante il processo!**

### Il Modello Corretto: Sviluppo Iterativo
> [!example] Schema del modello iterativo per prototipi successivi
> ![[IUM_Pasted image 20261013164853.png]]

Il **modello iterativo** rappresenta l'approccio corretto ed efficace per la progettazione di sistemi interattivi, basandosi su uno **sviluppo per prototipi successivi**. Dopo aver raccolto i *Requisiti iniziali* (che segnano l'inizio del processo), si entra in un ciclo continuo e dinamico composto da quattro fasi: **Requisiti (1) $\rightarrow$ Progettazione (2) $\rightarrow$ Prototipazione (3) $\rightarrow$ Test & Rilascio (4)**, tornando indietro per correggere e affinare.

- **Pro del modello iterativo:** Estrema flessibilità e capacità di adattamento. Il prodotto si vede fin da subito (anche se parziale) e si perfeziona per aggiustamenti successivi; le scelte effettuate possono essere sperimentate anticipatamente scartando subito quelle sbagliate. Man mano che si sviluppano e si testano i prototipi con gli utenti, emergono nuove informazioni e si comprendono meglio i bisogni reali: l'approccio iterativo permette di accogliere questi cambiamenti in corso d'opera, ridefinendo continuamente le specifiche iniziali a ogni nuovo ciclo per garantire che il sistema finale sia davvero utile, utilizzabile e soddisfacente. È il modello concettualmente corretto per la realizzazione di sistemi complessi.
- **Contro del modello iterativo:** Difficoltà di stima dei costi in anticipo (a preventivo); si rischia di far divergere il processo (non finire mai) per troppe richieste di modifiche; la fluidità delle specifiche rende più difficile la comunicazione fra le persone coinvolte (team di progetto e committente).

### Altre varianti di modelli di sviluppo

#### 1. Unified Software Development Process (Jacobson, Booch, Rumbaugh)
> [!example] Distribuzione delle risorse nelle iterazioni dello Unified Process
> ![[IUM_Pasted image 20261013165338.png]]

Nel contesto di un processo di sviluppo iterativo, come quello delineato nello *Unified Software Development Process*, è fondamentale comprendere che **le diverse attività hanno pesi diversi** a seconda della fase temporale in cui ci si trova.
Il grafico mostra che le attività (*Requisiti, Progettazione, Prototipazione, Test e Rilascio*) non sono fasi isolate che si chiudono per far iniziare la successiva, ma scorrono in parallelo lungo le diverse iterazioni assorbendo una quantità di **risorse** variabile nel **tempo**:
- Nelle prime iterazioni, la curva dei **Requisiti** raggiunge il suo picco massimo assorbendo gran parte dello sforzo, per poi assottigliarsi man mano che il progetto avanza.
- Le attività di **Progettazione**, **Prototipazione** e **Test** si gonfiano progressivamente nelle iterazioni centrali.
- Il **Rilascio** domina la parte finale del ciclo di vita.

In qualsiasi momento (o iterazione) il team sta lavorando un po' su tutto: mantenere le curve "aperte" lungo tutto il grafico significa che, anche a progetto avanzato, è sempre possibile dedicare una frazione di risorse per rivedere un requisito o sistemare un aspetto del design, correggendo il tiro senza i costi enormi del modello a cascata.

#### 2. Ciclo a cascata integrato con l'usabilità
> [!example] Integrazione delle attività di usabilità nel ciclo a cascata
> ![[IUM_Pasted image 20261013170233.png]]

Questo diagramma illustra un tentativo pratico di integrare l'usabilità all'interno di un tradizionale ciclo di sviluppo software "a cascata". Per ovviare alla rigidità dell'approccio sequenziale, vengono "innestate" specifiche attività centrate sull'utente come input vitali per le fasi classiche del processo:
- L'analisi diretta degli utenti (attraverso interviste e visite sul posto) alimenta le specifiche dei requisiti e il progetto dell'architettura.
- La definizione degli scenari e delle specifiche dell'interfaccia guida la progettazione, sfociando nell'aggiunta di una fase intermedia interamente dedicata alla realizzazione di prototipi e test (fase 4) prima di passare alla codifica e all'integrazione del codice.

Pur rappresentando un passo avanti rispetto al modello tradizionale "cieco", si configura come un **compromesso strutturale**: cerca di forzare pratiche esplorative all'interno di uno schema fondamentalmente monodirezionale. Se i test sui prototipi dovessero evidenziare la necessità di stravolgere le idee di partenza, la natura "a cascata" renderebbe comunque faticoso e costoso tornare indietro a riscrivere le specifiche iniziali.

#### 3. Ciclo di vita "a Stella" (Hix & Hartson, 1993)
> [!example] Schema del ciclo di vita a stella
> ![[IUM_Pasted image 20261013170324.png]]

Il **ciclo di vita a stella** rappresenta un approccio radicalmente diverso e altamente flessibile: la sua caratteristica rivoluzionaria è che **non esiste alcun ordine prestabilito** tra le fasi di lavoro, né un percorso rigidamente sequenziale dall'inizio alla fine.
- Il cuore nevralgico dell'intero processo è la **Valutazione**, posizionata fisicamente e concettualmente al centro del sistema.
- Tutte le altre attività operative (*analisi dei compiti / funzionale, specifica dei requisiti, progettazione concettuale / specifica formale, prototipazione e implementazione*) sono disposte a raggiera e collegate direttamente a questo nucleo centrale in modo bidirezionale.

Il team può passare liberamente da un'attività all'altra in base alle necessità del momento, ma **deve sempre transitare per il centro**: ogni volta che si completa un piccolo passo (che sia la stesura di un requisito o la creazione di un prototipo), questo deve essere immediatamente sottoposto a valutazione prima di decidere quale sarà la mossa successiva. Questa validazione continua garantisce che l'usabilità non sia un test finale, ma un filtro costante che permette di scovare errori sul nascere e adattare il progetto in tempo reale.

---
## Lo Standard ISO 9241-210: Human-Centred Design (HCD)
> [!question] Domanda d'esame: Human-Centered Design (ISO 9241-210)

> [!info] Definizione formale di HCD secondo ISO 9241-210 (ex ISO 13407)
> *"La progettazione centrata sull'essere umano (human-centred design, spesso chiamata anche **User-Centred Design – UCD**) è un approccio allo sviluppo dei sistemi interattivi specificamente orientato alla creazione di sistemi usabili.*
> *È un'attività multi-disciplinare che incorpora la conoscenza e le tecniche dei fattori umani e dell'ergonomia. L'applicazione dei fattori umani e dell'ergonomia alla progettazione dei sistemi interattivi ne potenzia l'efficacia e l'efficienza, migliora le condizioni del lavoro umano e contrasta i possibili effetti avversi dell'uso sulla salute, sulla sicurezza e sulle prestazioni.*
> *Applicare l'ergonomia alla progettazione dei sistemi richiede che si tenga conto delle capacità, delle abilità, delle limitazioni e delle necessità umane. I sistemi human-centred supportano gli utenti e li motivano a imparare. I benefici possono includere una maggiore produttività, una migliore qualità del lavoro, riduzione dei costi di supporto e di addestramento e una migliore soddisfazione dell'utente."*

> [!example] Il ciclo di progettazione centrata sull'uomo (ISO 9241-210)
> ![[IUM_Pasted image 20261013170829.png]]

### Le 4 fasi cicliche dello standard ISO 9241-210

Il modello si apre con una fase preliminare in cui si **pianifica il processo di progettazione centrata sull'uomo**, per poi immettersi in un ciclo continuo composto da **4 fasi** (da ripetere finché i requisiti non sono soddisfatti):

1. **Comprendere e specificare il contesto d'uso:**
   Un software non esiste mai in uno spazio vuoto: la sua reale utilità dipende intimamente dal mondo fisico, sociale e cognitivo che lo circonda. Questa indagine si articola in tre direzioni fondamentali:
   - Definire accuratamente le caratteristiche degli utenti (chi userà il sistema).
   - Identificare i compiti che essi dovranno svolgere (cosa faranno).
   - Specificare l'ambiente fisico, sociale, organizzativo e tecnologico nel quale gli utenti utilizzeranno il sistema (dove opereranno).
2. **Specificare i requisiti utente e organizzativi (di business):**
   L'usabilità non riguarda solo la grafica di uno schermo, ma impatta sull'intera organizzazione aziendale e sul benessere delle persone. I requisiti da mappare includono:
   - *Obiettivi e conformità:* le prestazioni richieste al nuovo sistema in relazione agli obiettivi operativi ed economici, insieme ai requisiti normativi e legislativi rilevanti (compresi quelli relativi alla sicurezza e alla salute).
   - *Dinamiche umane e di sistema:* la comunicazione e la cooperazione fra gli utenti e gli altri attori coinvolti, le attività degli utenti (inclusa la ripartizione dei compiti, il benessere e la motivazione degli utenti) e la ripartizione dei compiti fra esseri umani e sistemi tecnologici.
   - *Operatività organizzativa:* le prestazioni dei diversi compiti, la progettazione delle procedure di lavoro e dell'organizzazione, la gestione del cambiamento (incluse le attività di addestramento e il personale coinvolto), la fattibilità delle diverse operazioni (comprese quelle di manutenzione), la progettazione dei posti di lavoro e l'interfaccia uomo-computer.
3. **Produrre soluzioni di progetto (Design):**
   - Utilizzare le conoscenze disponibili per sviluppare proposte di progetto con un approccio multi-disciplinare.
   - Rendere le soluzioni di progetto più concrete utilizzando **simulazioni, modelli e prototipi** di vario tipo.
   - Presentare le soluzioni agli utenti, permettendo loro di eseguire i compiti che il sistema è destinato a supportare (eventualmente in modo simulato).
   - Modificare il progetto in conseguenza delle reazioni degli utenti, ripetendo il processo fino al raggiungimento degli obiettivi e gestendo l'iterazione delle soluzioni di progetto.
4. **Valutare il progetto nei confronti dei requisiti:**
   - Produrre il piano di valutazione, fornire feedback per la progettazione, verificare se gli obiettivi sono stati raggiunti, effettuare la validazione sul campo, assicurare il monitoraggio di lungo termine e documentare i risultati.
   - **Gestione del feedback:** se la valutazione evidenzia criticità (esito *"NON SODDISFA"*), il modello prevede percorsi di feedback mirati: il team non deve ricominciare tutto da zero, ma può tornare agilmente indietro per produrre nuove soluzioni (fase 3), ridefinire i requisiti (fase 2) o rianalizzare il contesto d'uso (fase 1). Il ciclo si ripete finché il progetto non ottiene un esito positivo (*"SODDISFA"*), dimostrando che l'errore, la revisione e il perfezionamento ciclico sono strumenti strutturali e necessari per ingegnerizzare un sistema realmente usabile.

---
## L'HCD nella pratica: UCD Sprint e Design Thinking
Il modello HCD dell'ISO 9241-210 è un modello teorico ("astratto"). Nella pratica lavorativa viene istanziato attraverso metodologie concrete, tra cui le più diffuse sono lo **UCD Sprint** e il **Design Thinking**.

### UCD Sprint
Deriva dal celebre *Design Sprint* ideato da Jake Knapp in Google ed è stato sviluppato attraverso corsi intensivi di Interaction Design da ricercatori leader nell'HCI. È un processo guidato passo-dopo-passo progettato per favorire la generazione costruttiva di idee all'interno dei team software.
- **Caratteristiche:** Presenta una struttura molto chiara con passaggi definiti per ogni parte del processo, risultando accessibile anche ai **team meno esperti** e adatta alla formazione (mentre i professionisti esperti possono applicarla più rapidamente).
- **Natura ciclica:** Sebbene la sua rappresentazione grafica appaia lineare, lo UCD Sprint resta un'istanza del modello HCD dell'ISO 9241-210: è quindi un **processo ciclico** e i progettisti possono ripetere liberamente le varie fasi in base alle necessità di progetto.
- **Le 3 parti dello UCD Sprint:**
  1. **Discovery (Analisi degli utenti):** comprendere l'idea generale, fare una mappatura iniziale, analizzare i gruppi di utenti, condurre interviste per raccogliere informazioni, definire gli obiettivi di UX e mappare il target.
  2. **Design (Sessione di brainstorming e schizzi):** esplorare idee suggerite dagli utenti, definire i compiti da testare, fare schizzi iniziali (*sketching*) e brainstorming, selezionare il design migliore, disegnare il flusso delle operazioni ideali (*happy paths*) e costruire prototipi a bassa fedeltà (*low-fi*).
  3. **Reality Check (Prototipo finale, testing e analisi dei risultati):** testare i prototipi di carta con gli utenti, effettuare revisioni con esperti, creare un prototipo cliccabile realistico, condurre test con **5 utenti**, analizzare i risultati, documentare il tutto e decidere i passi successivi.

### Design Thinking
> [!info] Definizione di Design Thinking (Nielsen Norman Group)
> Il **Design Thinking** è un'ideologia supportata da un processo correlato:
> - **L'ideologia** afferma che un approccio pratico e incentrato sull'utente alla risoluzione dei problemi può portare all'**innovazione**, e l'innovazione può portare alla differenziazione e a un **vantaggio competitivo**.
> - **Il processo** traduce questa ideologia in 6 fasi pratiche incentrate sull'utente, che partono dai dati reali dell'utente, creano artefatti di design che rispondono a esigenze reali (non immaginarie) e li testano con utenti reali.

- **Perché è fondamentale:** Sfrutta l'esperienza collettiva stabilendo un linguaggio comune e consenso nel team, ed esplora molteplici soluzioni per lo stesso problema. Come afferma Jakob Nielsen, *"un'interfaccia meravigliosa che risolve il problema sbagliato fallirà"*: il Design Thinking libera le energie creative e le concentra sul **problema giusto**.
- **Le 6 fasi del Design Thinking** (divise in 3 macro-aree: *Comprendere, Esplorare, Materializzare*):
  1. **Empatizzare (*Empathize*):** condurre ricerche sul campo per sviluppare conoscenza su ciò che gli utenti fanno, dicono, pensano e provano.
  2. **Definire (*Define*):** combinare tutte le ricerche per osservare dove esistono i problemi degli utenti ed evidenziare le opportunità di innovazione.
  3. **Ideare (*Ideate*):** fare brainstorming su una serie di idee folli e creative che rispondano alle esigenze insoddisfatte identificate nella fase di definizione.
  4. **Prototipare (*Prototype*):** costruire rappresentazioni reali e tangibili per un sottoinsieme delle idee scelte, così da capire quali componenti funzionano e quali no.
  5. **Testare (*Test*):** tornare dagli utenti reali per ricevere feedback e chiedersi: *"Questa soluzione soddisfa davvero le esigenze degli utenti?"*.
  6. **Implementare (*Implement*):** mettere in pratica la visione finale, assicurandosi che la soluzione sia materializzata e migliori concretamente la vita degli utenti finali.

*(Nota: Anche il Design Thinking è **altamente iterativo**: da qualsiasi fase è possibile tornare indietro alle fasi precedenti per affinare la comprensione o i prototipi).*

### Confronto finale: UCD Sprint vs Design Thinking
I due metodi si somigliano moltissimo perché sono entrambi istanze dello stesso modello HCD (**ISO 9241-210**). La scelta dell'uno o dell'altro dipende dalle esigenze dei progettisti e del gruppo di lavoro:
- **UCD Sprint** è molto più strutturato e "guidato" passo dopo passo, quindi risulta comodissimo per i progettisti novizi o meno esperti.
- **Design Thinking** è più flessibile e diffuso a livello aziendale; spesso viene adottato perché l'azienda o il team di lavoro lo utilizza già come processo standard interno.