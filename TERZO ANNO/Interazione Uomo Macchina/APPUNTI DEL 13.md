Ottenere sistemi usabili: 
- progetto centrato sull'utente, capire gli utenti i loro compiti il contesto d'uso. 
- sviluppo iterattivo (4 step di sviluppo per ottenere un prototipo).
- valutare i prototipi (possibilimente con utenti, è possibile anche in alternative usare degli ispettori sull'usabilità)
ISO 9241-210: Human centred design process for interactive system. 
![[Pasted image 20261013162008.png]]

la disciplina si occupa dei problemi tecnici e di gestione dello sviluppo dei sistei software di qualità, tra l'altro studia i vari modelli dei processi di progettazione e svilupo dei sistemi software. 

L'**ingegneria dell'usabilità** è la disciplina che definisce metodi e processi per sviluppare sistemi usabili in modo pratico ed economico, allontanandosi dall'idea irrealistica di creare un sistema perfetto con risorse illimitate. 
L'approccio è la **misurabilità**: prima ancora di costruire il prodotto, è necessario stabilire in anticipo e in modo quantitativo quali caratteristiche e requisiti di usabilità dovrà possedere. Questa definizione preventiva permette, di verificare e dimostrare oggettivamente che esso soddisfi le necessità per cui è stato progettato. Senza metriche specifiche e misurabili, infatti, non è possibile fare vera ingegneria dell'usabilità.

## Ingegneria dell'usabilità
L'ingegneria dell'usabilità, racchiude l'insieme delle pratiche per la progettazione e lo sviluppo di sistemi interattivi, iniziando fin dalla primissima raccolta e analisi dei requisiti. 
Questo approccio dimostra che l'usabilità non è un semplice ritocco estetico finale, ma un processo olistico che guida e struttura l'intero ciclo di vita del prodotto.
Per garantire che il sistema finale sia davvero a misura di persona, la disciplina si fonda su tre principi cardine:
- **Centralità dell'utente:** Mantenere una costante focalizzazione sull'utente, dall'inizio e per tutta la durata della progettazione, è fondamentale per evitare l'errore comune di sviluppare soluzioni tecniche eccellenti ma inutilizzabili o distaccate dalle reali necessità del pubblico di riferimento.
- **Testing continuo e basato sui dati:** Condurre prove con gli utenti durante l'intero processo, combinando analisi qualitative e misure quantitative, permette di validare le scelte di design basandosi su feedback reali e dati oggettivi, eliminando le supposizioni.
- **Sviluppo iterativo:** Adottare un modello di progettazione e sviluppo iterativo basato su prototipi successivi è una strategia vincente perché garantisce grande flessibilità: permette di testare idee, individuare difetti precocemente a basso costo e affinare progressivamente l'interfaccia fino a raggiungere la soluzione ottimale.

![[Pasted image 20261013163746.png]]
Il **modello tradizionale** di sviluppo (spesso noto come modello a cascata) si basa su un approccio rigidamente lineare che offre alcuni vantaggi organizzativi.

Tra i **pro**, questo metodo si distingue per avere fasi logiche ben definite, in cui ogni step si conclude fornendo direttamente gli input necessari alla fase successiva. Questa struttura a blocchi consente di inserire chiari check-point di verifica tra un passaggio e l'altro, rendendo l'intero processo _apparentemente_ molto ben controllabile da un punto di vista gestionale. Tuttavia, questa natura sequenziale impone una forte limitazione: nel modello a cascata, una volta che viene presa una decisione (ad esempio sui requisiti o sul design), è consigliabile procedere con essa, poiché tornare indietro per correggere o modificare il lavoro fatto in fasi avanzate risulta estremamente costoso in termini di tempo e budget.

Questa grave inflessibilità spiega i pesanti **contro** che caratterizzano l'approccio. Procedendo senza iterazioni, il committente e l'utente possono vedere il sistema prodotto solo alla fine del lunghissimo ciclo di sviluppo, con l'altissimo rischio di trovarsi di fronte a un risultato finale che non è soddisfacente o che non risponde più ai bisogni iniziali. Proprio per questa sua incapacità strutturale di adattarsi, validare le idee in corso d'opera e accogliere i cambiamenti, il modello tradizionale viene considerato concettualmente sbagliato e, di fatto, non funziona per la progettazione efficace di sistemi interattivi.

DOMANDA: DIFFERENZA MODELLO ITERATIVO E CASCATA

## Il ciclo compito-artefatto 

![[Pasted image 20261013164844.png]]

Il **ciclo compito-artefatto** illustra la dinamica di continua evoluzione tra le necessità umane e le soluzioni tecnologiche. Questo modello circolare descrive come, da un lato, siano proprio i **bisogni dell'utente** che fanno nascere uno **strumento** (o artefatto), concepito appositamente per risolvere un problema o facilitare un determinato compito. Tuttavia, il processo non si esaurisce con la creazione della soluzione: l'introduzione e l'utilizzo di questo nuovo strumento modifica inevitabilmente l'ambiente, le abitudini e le modalità di lavoro, andando a trasformare nel tempo i bisogni stessi dell'utente.

Questa continua interazione è un concetto fondamentale nell'interazione uomo-macchina, poiché evidenzia come la progettazione non sia mai un processo statico con un traguardo definitivo. Risolvere un problema odierno introducendo una nuova tecnologia altera lo scenario di partenza, generando nuove sfide, aspettative e necessità che daranno inevitabilmente inizio a un nuovo ciclo di sviluppo, richiedendo la progettazione di strumenti sempre nuovi o aggiornati.

![[Pasted image 20261013164853.png]]
Il **modello iterativo** rappresenta l'approccio corretto ed efficace per la progettazione di sistemi interattivi, basandosi su uno **sviluppo per prototipi successivi**. A differenza degli  approcci sequenziali, questo metodo si articola in un ciclo continuo e dinamico composto da quattro fasi: si parte dall'analisi dei **requisiti** (che segna l'inizio del processo), si passa alla **progettazione** vera e propria, si realizza la **prototipazione** e infine si sottopone il prodotto alla fase di **test & rilascio**.

I vantaggi sono l'strema flessibilità e capacità di adattamento. Un principio fondamentale da tenere sempre a mente, infatti, è che **anche i requisiti evolvono durante il processo**. Man mano che si sviluppano e si testano i prototipi con gli utenti, emergono nuove informazioni e si comprendono meglio i bisogni reali; l'approccio iterativo permette di accogliere questi cambiamenti in corso d'opera, ridefinendo continuamente le specifiche iniziali a ogni nuovo ciclo per garantire che il sistema finale sia davvero utile, utilizzabile e soddisfacente.


![[Pasted image 20261013165338.png]]
Nel contesto di un processo di sviluppo iterativo, come quello delineato nello "Unified Software Development Process" (di Jacobson, Booch e Rumbaugh), è fondamentale comprendere che **le diverse attività hanno pesi diversi** a seconda della fase temporale in cui ci si trova.

Il grafico illustra molto bene questa dinamica, mostrando che le attività (Requisiti, Progettazione, Prototipazione, Test e Rilascio) non sono fasi isolate che si chiudono per far iniziare la successiva, ma scorrono in parallelo lungo le diverse iterazioni assorbendo una quantità di **risorse** variabile nel **tempo**. Nelle prime iterazioni, la curva dei "Requisiti" raggiunge il suo picco massimo assorbendo gran parte dello sforzo, per poi assottigliarsi man mano che il progetto avanza. Al contrario, le attività di "Progettazione", "Prototipazione" e "Test" si gonfiano progressivamente nelle iterazioni centrali, mentre il "Rilascio" domina la parte finale del ciclo di vita.

Questo modello visivo ci offre un commento molto pratico sulla natura dello sviluppo moderno: in qualsiasi momento (o iterazione) il team sta lavorando un po' su tutto. Mantenere le curve "aperte" lungo tutto il grafico significa che, anche a progetto avanzato, è sempre possibile dedicare una frazione di risorse per rivedere un requisito o sistemare un aspetto del design. È proprio questa flessibilità nell'allocazione delle energie che permette al prodotto di evolvere organicamente, correggendo il tiro senza i costi enormi che imporrebbe un modello tradizionale a cascata.

![[Pasted image 20261013170233.png]]
Il diagramma illustra un tentativo pratico di integrare l'usabilità all'interno di un tradizionale ciclo di sviluppo software "a cascata". Per ovviare alla ben nota rigidità di questo approccio sequenziale, vengono "innestate" delle specifiche attività centrate sull'utente che forniscono input vitali alle fasi classiche del processo. Ad esempio, l'analisi diretta degli utenti (attraverso interviste e visite sul posto) va ad alimentare le specifiche dei requisiti e il progetto dell'architettura. Parallelamente, la definizione degli scenari e delle specifiche dell'interfaccia guida la progettazione, sfociando nell'aggiunta di una fase intermedia interamente dedicata alla realizzazione di prototipi e test prima di passare alla codifica e all'integrazione del codice.

Questo adattamento rappresenta certamente un passo avanti rispetto al modello tradizionale "cieco", tuttavia si configura nei fatti come un compromesso strutturale: si cerca di forzare pratiche esplorative (come i test e l'analisi degli utenti) all'interno di uno schema che rimane fondamentalmente monodirezionale. Il limite pratico di questa soluzione mista è che, se i test sui prototipi (fase 4) dovessero evidenziare la necessità di stravolgere del tutto le idee di partenza, la natura "a cascata" del processo renderebbe comunque faticoso e costoso tornare indietro a riscrivere le specifiche iniziali, confermando che l'integrazione di pratiche iterative in un modello lineare non può eguagliare la fluidità di un vero approccio iterativo nativo.

![[Pasted image 20261013170324.png]]
Il **ciclo di vita a stella** (teorizzato da Hix e Hartson) rappresenta un approccio radicalmente diverso e altamente flessibile alla creazione di sistemi interattivi. La caratteristica rivoluzionaria di questo modello è che **non esiste alcun ordine prestabilito** tra le fasi di lavoro: a differenza dei metodi tradizionali, qui non si è obbligati a seguire un percorso rigidamente sequenziale dall'inizio alla fine.

Il cuore nevralgico dell'intero processo è la **Valutazione**, posizionata fisicamente e concettualmente al centro del sistema. Tutte le altre attività operative – ovvero l'analisi dei compiti, la definizione dei requisiti, la progettazione, la prototipazione e l'implementazione – sono disposte a raggiera e collegate direttamente a questo nucleo centrale in modo bidirezionale.

A livello pratico, questo schema ci offre un commento molto forte su come dovrebbe essere gestito un progetto agile: il team può passare liberamente da un'attività all'altra in base alle necessità del momento, ma deve sempre transitare per il centro. In altre parole, ogni volta che si completa un piccolo passo (che sia la stesura di un requisito o la creazione di un prototipo), questo deve essere immediatamente sottoposto a valutazione prima di decidere quale sarà la mossa successiva. Questa continua e pervasiva validazione garantisce che l'usabilità non sia un test finale, ma un filtro costante che permette di scovare errori sul nascere e adattare il progetto in tempo reale, abbattendo drasticamente i rischi di fallimento.

![[Pasted image 20261013170829.png]]
Lo standard **ISO 9241-210** definisce formalmente il processo di _Human-Centered Design_ (progettazione centrata sull'essere umano) per lo sviluppo di sistemi interattivi, istituzionalizzando a livello internazionale l'approccio iterativo.

Il modello si apre con una fase preliminare in cui si pianifica il processo di progettazione, per poi immettersi in un ciclo continuo composto da quattro step fondamentali: la comprensione e specificazione del contesto d'uso (1), la definizione dei requisiti sia dell'utente che di business (2), la produzione delle soluzioni di design (3) e infine la valutazione del progetto misurandolo sui requisiti iniziali (4).

L'aspetto più importante e il vero commento metodologico di questo schema risiedono proprio nella gestione della **Valutazione**. Se il test evidenzia criticità (esito "NON SODDISFA"), il modello prevede percorsi di feedback mirati: il team non deve ricominciare tutto da zero, ma può tornare agilmente indietro per produrre nuove soluzioni (fase 3), ridefinire i requisiti (fase 2) o rianalizzare il contesto d'uso (fase 1). Questo ciclo si ripete finché il progetto non ottiene un esito positivo ("SODDISFA"), traguardo che decreta il raggiungimento di una soluzione progettuale capace di rispettare tutti i requisiti. In sintesi, lo standard ISO dimostra che l'errore, la revisione e il perfezionamento ciclico non sono imprevisti da evitare, ma strumenti strutturali e necessari per ingegnerizzare un sistema realmente usabile.


Domanda IUMAN CENTER DESIGN


Le primissime fasi della progettazione centrata sull'utente richiedono di gettare fondamenta solide prima di ipotizzare qualsiasi soluzione.
Il passo iniziale consiste nel **comprendere e specificare il contesto d'uso**. Questa indagine si articola in tre direzioni fondamentali: definire accuratamente le caratteristiche degli utenti (chi userà il sistema), identificare i compiti che essi dovranno eseguire (cosa faranno) e specificare l'ambiente fisico nel quale il sistema verrà utilizzato (dove opereranno). Questa fase evidenzia come un software non esista mai in uno spazio vuoto: la sua reale utilità dipende intimamente dal mondo fisico, sociale e cognitivo che lo circonda.

Una volta chiarito il contesto, si procede a **specificare i requisiti utente e organizzativi**. Questa lunga e complessa fase di analisi ci offre un commento cruciale sulla natura dell'usabilità: essa non riguarda solo la grafica di uno schermo, ma impatta sull'intera organizzazione aziendale e sul benessere delle persone. I requisiti da mappare includono:
- **Obiettivi e conformità:** Le prestazioni che il nuovo sistema deve garantire per soddisfare gli obiettivi operativi ed economici, insieme al rigoroso rispetto dei requisiti normativi e legislativi, compresi quelli per la salute e la sicurezza.
- **Dinamiche umane e di sistema:** La gestione della comunicazione e della cooperazione tra tutti gli attori coinvolti, le attività specifiche degli utenti e la delicata ripartizione dei compiti tra esseri umani e sistemi tecnologici, tutelando il benessere e la motivazione del personale.
- **Operatività organizzativa:** La definizione delle prestazioni dei vari compiti, la progettazione concreta delle procedure di lavoro e dell'organizzazione, la gestione del cambiamento (che include l'addestramento di chi vi partecipa), fino ad arrivare alla fattibilità della manutenzione, al design dei posti di lavoro e alla realizzazione dell'interfaccia uomo-computer.

Questo approccio olistico assicura che il prodotto finale sia uno strumento che si adatta all'ecosistema lavorativo, sostenendo gli utenti anziché ostacolarli.

