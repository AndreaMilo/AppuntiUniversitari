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
Per ottenere sistemi realmente usabili è necessario seguire tre direttrici fondamentali (formalizzate dallo standard **ISO 9241-210**, *Human-centred design process for interactive systems*):
- **Progetto centrato sull'utente:** comprendere gli utenti, i loro compiti e il contesto d'uso.
- **Sviluppo iterativo:** articolato in 4 step di sviluppo ciclici per ottenere e raffinare un prototipo.
- **Valutazione dei prototipi:** possibilmente condotta con gli utenti finali (o, in alternativa, tramite ispettori ed esperti di usabilità).

![[IUM_Pasted image 20261013162008.png]]

- **Ingegneria del software:** è la disciplina che si occupa dei problemi tecnici e di gestione per sviluppare sistemi software di qualità e senza sprechi, studiando i vari modelli dei processi di progettazione e sviluppo.
- **Ingegneria dell'usabilità:** studia tecniche, metodi e processi per progettare e sviluppare sistemi **usabili** in modo pratico ed economico, iniziando fin dalla primissima raccolta e analisi dei requisiti. Questo approccio dimostra che l'usabilità non è un semplice ritocco estetico finale, ma un processo olistico che guida e struttura l'intero ciclo di vita del prodotto.

Secondo **Jakob Nielsen** (1994), l'ingegneria non consiste nel creare un sistema perfetto con risorse infinite, ma nel costruire in modo economico un sistema funzionante che soddisfi una necessità. Per farlo, l'approccio cardine dell'ingegneria dell'usabilità è la **misurabilità**: prima ancora di costruire il prodotto, impone di **specificare quantitativamente e in anticipo** quali caratteristiche e requisiti di usabilità dovrà avere il prodotto finale e in quale misura. Questa definizione preventiva permette di verificare e dimostrare oggettivamente che esso soddisfi le necessità per cui è stato progettato: senza metriche specifiche e misurabili non è possibile fare vera ingegneria dell'usabilità.

### I 3 principi cardine dell'Ingegneria dell'Usabilità
1. **Centralità dell'utente (Focalizzazione sull'utente):** mantenere una costante focalizzazione sull'utente, dall'inizio e per tutta la durata della progettazione, è fondamentale per evitare l'errore comune di sviluppare soluzioni tecniche eccellenti ma inutilizzabili o distaccate dalle reali necessità del pubblico di riferimento.
2. **Sviluppo iterativo:** adottare un modello di progettazione e sviluppo iterativo basato su prototipi successivi garantisce grande flessibilità, poiché permette di testare idee, individuare difetti precocemente a basso costo e affinare progressivamente l'interfaccia fino a raggiungere la soluzione ottimale.
3. **Testing continuo e basato sui dati (Prove con l'utente):** condurre test continui lungo tutto il processo, combinando **analisi qualitative** (opinioni, comportamenti) e **misure quantitative** (tempi di esecuzione, numero di errori), permette di validare le scelte di design basandosi su feedback reali e dati oggettivi, eliminando le supposizioni.

## I modelli di sviluppo: dal modello "a Cascata" a quello "Iterativo"

### Il Modello Tradizionale "a Cascata" (Waterfall)
![[IUM_Pasted image 20261013163746.png]]

Il **modello tradizionale** di sviluppo (noto come *modello a cascata*) si basa su un approccio rigidamente lineare e sequenziale: *Requisiti $\rightarrow$ Analisi e progettazione $\rightarrow$ Realizzazione $\rightarrow$ Test $\rightarrow$ Rilascio*.
- **Pro:** Si distingue per avere fasi logiche ben definite, in cui ogni step si conclude fornendo direttamente gli input necessari alla fase successiva. Questa struttura a blocchi consente di inserire chiari punti di controllo (*check-point*) di verifica tra un passaggio e l'altro, rendendo l'intero processo *apparentemente* molto ben controllabile da un punto di vista gestionale.
- **Contro:** La natura sequenziale impone una grave inflessibilità: una volta presa una decisione (ad esempio sui requisiti o sul design), è **estremamente costoso tornare indietro** in termini di tempo e budget per correggere o modificare il lavoro fatto in fasi avanzate. Procedendo senza iterazioni, il committente e l'utente vedono il sistema solo alla fine del lunghissimo ciclo di sviluppo, con l'altissimo rischio di trovarsi di fronte a un risultato finale insoddisfacente o che non risponde più ai bisogni iniziali. Per la progettazione di sistemi interattivi è un modello **concettualmente sbagliato e di fatto non funziona**.

> [!question] Domanda d'esame: Differenza tra modello iterativo e modello a cascata

### Perché il modello a cascata fallisce? Il "Ciclo Compito-Artefatto"
![[IUM_Pasted image 20261013164844.png]]

Il motivo per cui non si può fissare tutto all'inizio è spiegato dal **ciclo compito-artefatto**, che illustra la dinamica di continua evoluzione tra le necessità umane e le soluzioni tecnologiche:
1. I **bisogni dell'utente** fanno nascere un nuovo **strumento** (o artefatto), concepito appositamente per risolvere un problema o facilitare un determinato compito.
2. Tuttavia, il processo non si esaurisce con la creazione della soluzione: l'introduzione e l'utilizzo dello **strumento** modifica inevitabilmente l'ambiente, le abitudini e il modo in cui l'utente lavora e vive, trasformando nel tempo i bisogni stessi dell'utente, facendo nascere **nuovi bisogni** e cambiando i compiti.

Questa continua interazione evidenzia come la progettazione non sia mai un processo statico con un traguardo definitivo: risolvere un problema odierno introducendo una nuova tecnologia altera lo scenario di partenza, generando nuove sfide, aspettative e necessità che danno inizio a un nuovo ciclo di sviluppo. Di conseguenza, **anche i requisiti evolvono durante il processo!**

### Il Modello Corretto: Sviluppo Iterativo
![[IUM_Pasted image 20261013164853.png]]

Il **modello iterativo** rappresenta l'approccio corretto ed efficace per la progettazione di sistemi interattivi, basandosi su uno **sviluppo per prototipi successivi**. Dopo aver raccolto i *Requisiti iniziali* (che segnano l'inizio del processo), si entra in un ciclo continuo e dinamico composto da quattro fasi: **Requisiti $\rightarrow$ Progettazione $\rightarrow$ Prototipazione $\rightarrow$ Test & Rilascio**, tornando indietro per correggere e affinare.

- **Pro del modello iterativo:** Estrema flessibilità e capacità di adattamento. Il prodotto si vede fin da subito (anche se parziale) e si perfeziona; le scelte si sperimentano in anticipo scartando subito quelle sbagliate. Man mano che si sviluppano e si testano i prototipi con gli utenti, emergono nuove informazioni e si comprendono meglio i bisogni reali: l'approccio iterativo permette di accogliere questi cambiamenti in corso d'opera, ridefinendo continuamente le specifiche iniziali a ogni nuovo ciclo per garantire che il sistema finale sia davvero utile, utilizzabile e soddisfacente. È il modello giusto per sistemi complessi.
- **Contro del modello iterativo:** È difficile stimare i costi in anticipo (a preventivo); si rischia di non finire mai (divergenza del processo) per troppe richieste di modifica; i requisiti fluidi rendono più difficile la comunicazione tra team e cliente (committente).

### Altre varianti di modelli di sviluppo

#### 1. Unified Software Development Process (Jacobson, Booch, Rumbaugh)
![[IUM_Pasted image 20261013165338.png]]

Nel contesto di un processo di sviluppo iterativo, come quello delineato nello *Unified Software Development Process*, è fondamentale comprendere che **le diverse attività hanno pesi diversi** a seconda della fase temporale in cui ci si trova.
Il grafico mostra che le attività (*Requisiti, Progettazione, Prototipazione, Test e Rilascio*) non sono fasi isolate che si chiudono per far iniziare la successiva, ma scorrono in parallelo lungo le diverse iterazioni assorbendo una quantità di **risorse** variabile nel **tempo**:
- Nelle prime iterazioni, la curva dei **Requisiti** raggiunge il suo picco massimo assorbendo gran parte dello sforzo, per poi assottigliarsi man mano che il progetto avanza.
- Le attività di **Progettazione**, **Prototipazione** e **Test** si gonfiano progressivamente nelle iterazioni centrali.
- Il **Rilascio** domina la parte finale del ciclo di vita.

In qualsiasi momento (o iterazione) il team sta lavorando un po' su tutto: mantenere le curve "aperte" lungo tutto il grafico significa che, anche a progetto avanzato, è sempre possibile dedicare una frazione di risorse per rivedere un requisito o sistemare un aspetto del design, correggendo il tiro senza i costi enormi del modello a cascata.

#### 2. Ciclo a cascata integrato con l'usabilità
![[IUM_Pasted image 20261013170233.png]]

Questo diagramma illustra un tentativo pratico di integrare l'usabilità all'interno di un tradizionale ciclo di sviluppo software "a cascata". Per ovviare alla rigidità dell'approccio sequenziale, vengono "innestate" specifiche attività centrate sull'utente come input vitali per le fasi classiche del processo:
- L'analisi diretta degli utenti (attraverso interviste e visite sul posto) alimenta le specifiche dei requisiti e il progetto dell'architettura.
- La definizione degli scenari e delle specifiche dell'interfaccia guida la progettazione, sfociando nell'aggiunta di una fase intermedia interamente dedicata alla realizzazione di prototipi e test (fase 4) prima di passare alla codifica e all'integrazione del codice.

Pur rappresentando un passo avanti rispetto al modello tradizionale "cieco", si configura come un **compromesso strutturale**: cerca di forzare pratiche esplorative all'interno di uno schema fondamentalmente monodirezionale. Se i test sui prototipi dovessero evidenziare la necessità di stravolgere le idee di partenza, la natura "a cascata" renderebbe comunque faticoso e costoso tornare indietro a riscrivere le specifiche iniziali.

#### 3. Ciclo di vita "a Stella" (Hix & Hartson, 1993)
![[IUM_Pasted image 20261013170324.png]]

Il **ciclo di vita a stella** rappresenta un approccio radicalmente diverso e altamente flessibile: la sua caratteristica rivoluzionaria è che **non esiste alcun ordine prestabilito** tra le fasi di lavoro, né un percorso rigidamente sequenziale dall'inizio alla fine.
- Il cuore nevralgico dell'intero processo è la **Valutazione**, posizionata fisicamente e concettualmente al centro del sistema.
- Tutte le altre attività operative (*analisi dei compiti / funzionale, specifica dei requisiti, progettazione concettuale / specifica formale, prototipazione e implementazione*) sono disposte a raggiera e collegate direttamente a questo nucleo centrale in modo bidirezionale.

Il team può passare liberamente da un'attività all'altra in base alle necessità del momento, ma **deve sempre transitare per il centro**: ogni volta che si completa un piccolo passo (che sia la stesura di un requisito o la creazione di un prototipo), questo deve essere immediatamente sottoposto a valutazione prima di decidere quale sarà la mossa successiva. Questa validazione continua garantisce che l'usabilità non sia un test finale, ma un filtro costante che permette di scovare errori sul nascere e adattare il progetto in tempo reale.

## Lo Standard ISO 9241-210: Human-Centred Design (HCD)
> [!question] Domanda d'esame: Human-Centered Design (ISO 9241-210)

![[IUM_Pasted image 20261013170829.png]]

Lo standard internazionale **ISO 9241-210** (che ha sostituito il vecchio ISO 13407) definisce formalmente il processo di **HCD** (*Human-Centred Design*, spesso chiamato anche **UCD - User-Centred Design**) per lo sviluppo di sistemi interattivi, istituzionalizzando a livello internazionale un approccio iterativo e multidisciplinare che usa l'ergonomia e i fattori umani per creare sistemi usabili.
- **I vantaggi:** Aumenta l'efficacia e l'efficienza, migliora le condizioni di lavoro, protegge la salute e la sicurezza dell'utente, aumenta la produttività e riduce i costi di assistenza e addestramento.

### Le 4 fasi cicliche dello standard ISO 9241-210

Il modello si apre con una fase preliminare in cui si **pianifica il processo di progettazione centrata sull'uomo**, per poi immettersi in un ciclo continuo composto da **4 fasi** (da ripetere finché i requisiti non sono soddisfatti):

1. **Comprendere e specificare il contesto d'uso:**
   Un software non esiste mai in uno spazio vuoto: la sua reale utilità dipende intimamente dal mondo fisico, sociale e cognitivo che lo circonda. Questa indagine si articola in tre direzioni fondamentali:
   - Definire accuratamente le caratteristiche degli utenti (chi userà il sistema).
   - Identificare i compiti che essi dovranno svolgere (cosa faranno).
   - Specificare l'ambiente fisico, sociale, organizzativo e tecnologico nel quale il sistema verrà utilizzato (dove opereranno).
2. **Specificare i requisiti utente e organizzativi (di business):**
   L'usabilità non riguarda solo la grafica di uno schermo, ma impatta sull'intera organizzazione aziendale e sul benessere delle persone. I requisiti da mappare includono:
   - *Obiettivi e conformità:* definire le prestazioni richieste per soddisfare gli obiettivi operativi ed economici, insieme al rigoroso rispetto dei requisiti normativi e legislativi, compresi quelli per la salute e la sicurezza.
   - *Dinamiche umane e di sistema:* gestire la comunicazione e la cooperazione tra tutti gli attori coinvolti, le attività specifiche degli utenti e la delicata ripartizione dei compiti tra esseri umani e sistemi tecnologici, tutelando il benessere e la motivazione del personale.
   - *Operatività organizzativa:* definire le prestazioni dei vari compiti, la progettazione concreta delle procedure di lavoro e dell'organizzazione, la gestione del cambiamento (che include l'addestramento di chi vi partecipa), la fattibilità della manutenzione, il design dei posti di lavoro e la realizzazione dell'interfaccia uomo-computer.
3. **Produrre soluzioni di progetto (Design):**
   - Creare proposte progettuali con un team multidisciplinare.
   - Rendere concrete le idee tramite **simulazioni, modelli e prototipi**.
   - Far provare i prototipi agli utenti (anche simulando i compiti) e modificare il progetto in base alle loro reazioni.
4. **Valutare il progetto rispetto ai requisiti:**
   - Creare un piano di valutazione, raccogliere feedback, verificare se gli obiettivi sono raggiunti, fare validazione sul campo, monitorare nel lungo termine e documentare i risultati.
   - **Gestione del feedback:** se la valutazione evidenzia criticità (esito *"NON SODDISFA"*), il modello prevede percorsi di feedback mirati: il team non deve ricominciare tutto da zero, ma può tornare agilmente indietro per produrre nuove soluzioni (fase 3), ridefinire i requisiti (fase 2) o rianalizzare il contesto d'uso (fase 1). Il ciclo si ripete finché il progetto non ottiene un esito positivo (*"SODDISFA"*), dimostrando che l'errore, la revisione e il perfezionamento ciclico sono strumenti strutturali e necessari per ingegnerizzare un sistema realmente usabile.

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