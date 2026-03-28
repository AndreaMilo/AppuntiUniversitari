Scrum è un **framework** agile per la gestione del ciclo di sviluppo del software, iterativo ed incrementale, concepito per gestire progetti e prodotti e progetti software per lo sviluppo.
Il **framework** è definito in tre parti:
1. Ruoli
2. Eventi
3. Artifact
![[Pasted image 20260313103414.png]]
## Sprint
I progetti **Scrum** fanno progressi in una serie di iterazioni dette **sprint**, che è sinonimo stesso di iterazione. In ogni sprint si svolgono le varie attività tecniche, quindi i requisiti sono analizzati, progettati e realizzati (testati) tramite la durata dello sprint.
Gli sprint **non sono interrompibili e non modificabili**, la durata dello sprint viene definita a monte dal **timeboxing**, che ha durata solitamente dalle 2 alle 4 settimane.
## Artifact
### Product Backlog
Il **product backlog** è una lista di requisiti funzionali richiesti per il progetto.
Diversamente da un processo a cascata, dove la lista viene definita a monte in modo rigido, il product backlog si adatta in modo dinamico nei cambiamenti, definendo delle priorità da eseguire.
Queste priorità vengono stabilite dal **Product Owner**, aggiornate ad inizio di ogni sprint, molto spesso questo ruolo coincide con quello dell'**analista**.
Il team di sviluppo definisce la **stima** di durata di ogni iterazione (funzionalità) da eseguire. 

Queste funzionalità vengono definite come **user story** da coloro che ci lavorano sopra.
#### Descrizione User-Story
![[Pasted image 20260313100407.png]]
Nel product backlog sono presenti anche i **bugs** e gli **issues** che definiscono gli errori generici o i problemi riscontrati e presenti.

Anche se non si crea la lista dei requisiti immediati, si crea comunque nella user story una **lista abbozzata** di ciò che deve essere eseguito. Per scrivere queste bozze si usano i **template**. 
>[!example] Ne sussegue il seguente esempio:
>![[Pasted image 20260313100748.png]]
>
>Il risultato finale di un product backlog con user-story, risulta tale:
>![[Pasted image 20260313100937.png]]

L'**unità di misura** di Scrum per il Product Backlog si chiama **story-point**, che non si base sulle *ore-uomo*.
Questa unità di misura è idealistica e si basa sui valori interni che il team definisce come corretto. A livello idealistico una user-story molto semplice (operazione facilmente realizzabile dal team) corrisponde ad uno **story-point**
### Sprint backlog
Lo **sprint backlog** si basa sugli obiettivi posti nel **product backlog** ma a differenza di quest'ultimo che è gestito dal Product Owner, in questo caso le **user-story** sono gestite dai **Team autogestiti**, ovvero team privi da leader.
Questo crea delle conseguenze positive e negative, non essendoci una persona a capo del team.
In questo caso la stima del lavoro rimanente è aggiornata nel **daily meeting**.
![[Pasted image 20260313102028.png]]

La rappresentazione di uno Sprint backlog si può eseguire su:
- **lavagne fisiche**: queste grandi lavagne vengono utilizzate proprio nella maniera dell'esempio presente nell'immagine superiormente inserita.
- **lavagne virtuali**: adottate specialmente post covid e per i team che lavorano a distanza, usando software che simulano queste lavagne con i relativi post-it come **JIRA**. Altrimenti si può usare come tool gratuito, come quelli presenti in **GitHub**.

È importante ricordare che Scrum non impone le User Story né gli Story Point: sono ottime pratiche adottate da quasi tutti i team Scrum, ma il framework di base non le richiede obbligatoriamente.

## Eventi
Gli eventi in Scrum sono **incontri** gestiti sia in presenza che a distanza.
Gli eventi si dividono in 4 gruppi tutti basati su dei meeting, eseguiti molto spesso settimanalmente e *circa* nel seguente ordine:
- sprint planning
- daily scrum
- sprint review
- sprint retrospective
### Meeting sprint planning
In questa fase si seleziona dal Product Backlog lo **sprint da usare in quel momento**.
Si selezionano quindi anche gli item da completare nello Sprint in modo tale da stimare lo **story point**.
Successivamente si svolge anche un attività di **analisi preliminare** definendo le task e le ore da eseguire per ciascuna task, creando infine lo **Sprint Backlog con autogestione del team**.

### Daily scrum meeting
In questo meeting si cerca di tenere **aggiornati giornalmente i membri del team** sui progressi dell'attività, è un meeting breve di 15min e si svolge in maniera **stand-up** (in piedi), in modo tale da farlo durare veramente poco.
In questi meeting di coordinamento sono presenti tutti i membri del team ma principalmente il diritto alla parola è basato sulle azioni dello **Scrum Master** e del **Product Owner**.
In questo meeting si danno risposte a tre domande di coordinazione:
- Cosa è stato fatto ieri
- Cosa verrà eseguito domani
- Che problemi ci sono
### Sprint review meeting
Nello sprint review meeting partecipano sia membri del team che utenti esterni, in modo tale da far mostrare, ai dipendenti e non, la demo attuale del progetto, così da poter **raccogliere feedback**.
In questo modo si può raffinare o rivedere il product backlog, scrivendo e definendo anche le issues incontrate.

### Sprint retrospective meeting
Anche a questo meeting partecipano dipendenti e utenti come quello di tipo review, al **termine di ogni sprint** viene eseguita questa meeting con durata dai 15 ai 30min e si annotano dei feedback sul progetto, segnando i miglioramenti che si vorrebbero apportare e discussi in seguito assieme al team per come integrarli nel progetto.
In questa riunione si danno risposte alle seguenti domande:
- Cosa introduce
- Cosa evitare
- Cosa continuare sicuramente

## Ruoli
Il team di sviluppo si basa, per essere definito tale, da 3 a 8 persone e come già specificato prima è autogestito ed è fondamentale che ogni membro si dedichi a **tempo pieno** al lavoor del progetto per non perdere tempo prezioso.
I vari ruoli presenti nel team sono:
- **Product Owner**:
  È responsabile del valore del prodotto. Ha la responsabilità esclusiva di gestione del Product Backlog e definisce le caratteristiche funzionali e non funzionali (**feature**) del prodotto.
  **Assegna le priorità alle feature** in base al valore di mercato, per ogni iterazione. Infine  accetta o rifiuta i risultati del lavoro del Team di Sviluppo.
  Inoltre definisce concretamente i **done**, ovvero le conferme di task completate, verbalizzandoli.
- **Scrum Master**:
  Si fa carico di **rimuovere gli ostacoli e protegge dalle interferenze esterne il team**, inoltre è colui che si interfaccia direttamente con il management.
  Molto spesso può essere una figura anche alternante, in cui ad ogni sprint viene cambiata, così da far ricadere un po' a tutto il team queste grandi responsabilità e non solo su una persona.
  Lo scrum master è una guida al servizio del Team di Sviluppo e del Product Owner, in modo da poter fare esporre tutti i membri del team a parlare, anche ai più timidi, avendo priorità di far fermare il dialogo di alcune persone in favore di altre.
![[Pasted image 20260313114147.png]]
## Scrum of Scrums
Sono simili ai daily meeting, solo che questi ultimi si svolgono due volte ogni settimana.
Lo scopo di questi meeting è **coordinare più team**, quando sono tanti, tra di loro. Ogni team sceglie il proprio membro da mandare alle Scrum of Scrums per identificarli.

  