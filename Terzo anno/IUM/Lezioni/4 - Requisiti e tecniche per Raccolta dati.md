# Requisiti e Tecniche per la Raccolta dei Dati nell'Interaction Design

## 1. Dai bisogni ai requisiti

> [!info] Definizione di Requisiti di prodotto
> Dal latino *requisitus* («richiesto»), i **requisiti di prodotto** (*product requirements*) sono le proprietà richieste al prodotto.
> Si raccolgono mediante analisi condotte con varie tecniche e si riportano per iscritto in un **documento strutturato**, che rende esplicito ciò che il prodotto deve offrire e costituisce l'input che guida le successive attività di progettazione.

### Requisiti funzionali vs Requisiti non funzionali
- **Requisiti funzionali:** descrivono le *funzioni* che il sistema deve realizzare (compresi i vincoli di capacità e i contenuti).
- **Requisiti non funzionali:** descrivono le *proprietà qualitative e prestazionali* che il prodotto dovrà possedere.

> [!example] Esempio di requisiti per un sito di e-commerce
> | **Tipo** | **Proprietà richiesta** |
> |---|---|
> | **Funzionale** | Il sito deve permettere di inserire nel carrello i prodotti di cui si sta valutando l'acquisto. |
> | **Funzionale** | Il carrello deve contenere almeno 15 prodotti contemporaneamente *(Vincolo di capacità)*. |
> | **Funzionale** | Ogni scheda deve includere fotografia a colori, nome del prodotto, produttore, prezzo e descrizione sintetica ma completa di al massimo 5 righe *(Contenuto del catalogo)*. |
> | **Non funzionale** | L'intero processo di acquisto dovrebbe richiedere al massimo 5 minuti. |

### Ambiti di analisi e la distinzione tra Requisiti e Progettazione
La definizione dei requisiti si articola in **5 ambiti principali di analisi**:
1. **Analisi dell'utente:** *A quali utenti è destinato il prodotto?* (categorie prioritarie e secondarie; differenze per sesso, età, cultura, esperienza, abilità/disabilità, interessi, valori e obiettivi pertinenti).
2. **Analisi dei bisogni:** *Quali necessità hanno tali utenti?* (necessità espresse e inespresse; bisogni prioritari rispetto al prodotto).
3. **Analisi del contesto:** *Quale sarà il contesto d'uso?* (dove e in quali condizioni si userà il prodotto; contesti prevalenti o occasionali).
4. **Analisi dei casi d'uso:** *Come interagiranno i diversi utenti con il prodotto?*
5. **Analisi della concorrenza:** *Quali punti di forza e di debolezza emergono rispetto ai prodotti concorrenti?*

> [!warning] Una distinzione decisiva: Specificare i requisiti $\neq$ Progettare
> - **Specificare i requisiti ("Che cosa e perché"):** il documento dei requisiti indica *che cosa* si deve realizzare e *perché*, ponendo dei vincoli all'attività di progettazione.
> - **Progettare ("Come"):** la progettazione decide *come* realizzare il prodotto entro quei vincoli.
> - *Esempio:* «Consentire di modificare una prenotazione» è un **requisito**; scegliere il layout grafico della schermata è una **decisione progettuale**.

### Il processo di definizione dei requisiti e i rischi dell'esplorazione
Il passaggio dal campo al documento finale avviene in **3 fasi**:
1. **01 – Esplorazione (*Elicitation*):** fa emergere bisogni, contesto e aspettative degli stakeholder.
2. **02 – Organizzazione:** le evidenze raccolte vengono organizzate nella stesura formale dei requisiti.
3. **03 – Revisione e approvazione:** si verificano chiarezza, coerenza e accordo sul documento; una volta approvato, il documento alimenta le attività di progettazione e sviluppo.

Durante la fase di **esplorazione** bisogna fronteggiare **4 problemi tipici**:
- **Ambito:** i "contorni" del sistema sono poco definiti (esplorare troppo amplia eccessivamente il campo; esplorare troppo poco esclude aspetti importanti).
- **Comprensione:** gli utenti conoscono solo parte dei propri bisogni reali, mentre il ricercatore può conoscere poco il dominio applicativo e usare un linguaggio diverso.
- **Conflitto:** stakeholder diversi hanno punti di vista differenti, che vanno esplicitati e risolti nel documento finale.
- **Volatilità:** i requisiti evolvono nel tempo; occorre conservarne motivazioni e cambiamenti.

> [!info] Importanza dello studio degli utenti
> Sono gli utenti a decidere se utilizzare o meno un prodotto: preferenze, abitudini, istruzione, formazione professionale, conoscenze ed esperienze precedenti entrano in ogni interazione e influenzano il modo in cui le persone apprendono e usano i sistemi. Non supportare le loro necessità causa **perdita di produttività per l'azienda** e **frustrazione per l'utente**.

---
## 2. Cosa sono i dati e perché si raccolgono

> [!info] Definizione di Dati (Sharp, Rogers e Preece)
> I **dati** possono assumere qualsiasi forma utile per comprendere un design, i bisogni o il comportamento degli utenti: numeri, parole, misurazioni, descrizioni, commenti, fotografie, schizzi, film o video. Si dividono in due grandi categorie:
> - **Dati quantitativi:** esprimono quantità numeriche misurabili. *Esempio:* il tempo impiegato per trovare un'informazione su una pagina web o il numero di clic effettuati per arrivarci.
> - **Dati qualitativi:** descrivono qualità, opinioni, esperienze e significati. *Esempio:* ciò che l'utente dice o commenta a proposito di quella stessa pagina web e delle difficoltà incontrate.

Nell'Interaction Design i dati si raccolgono principalmente in due fasi (e non richiedono quasi mai competenze tecniche o di programmazione):
1. **Scoperta dei requisiti:** per avere informazioni sufficienti, accurate e pertinenti prima di iniziare a progettare.
2. **Valutazione:** per raccogliere le reazioni degli utenti e misurare le loro prestazioni mentre usano un sistema o un prototipo.

Le **tre tecniche principali di raccolta** (flessibili e utilizzabili sia per dati qualitativi sia quantitativi, meglio se **combinate tra loro** per confrontare le evidenze e ridurre le distorsioni intrinseche di ogni singolo metodo) sono:
- **Interviste:** conversazioni sincrone (in presenza, al telefono o da remoto via Skype/Zoom) con domande a una o più persone e diverso grado di struttura.
- **Questionari:** serie di domande predisposte su carta o online a cui l'utente risponde in modo asincrono, cioè senza la presenza del ricercatore, raggiungendo molti partecipanti.
- **Osservazione:** può essere **diretta** (osservare le persone durante lo svolgimento delle attività) o **indiretta** (registrare l'attività dell'utente per studiarla successivamente).

---
## 3. I cinque aspetti fondamentali della Raccolta Dati
Per preparare e condurre con successo qualsiasi studio di raccolta dati, bisogna curare **cinque aspetti chiave**:

### 1. Definizione degli obiettivi
Prima di iniziare, bisogna fissare obiettivi specifici, chiari e concisi (nell'Interaction Design di solito si esprimono in modo informale). Gli obiettivi incidono sulla natura delle sessioni, sulle tecniche da utilizzare e sull'analisi da condurre.
- *Esempi di obiettivi:* capire come la tecnologia entra nella vita di una famiglia; confrontare due icone per il comando «invia il messaggio»; verificare che il redesign di un sistema o di un contatore portatile garantisca la piena accessibilità digitale per utenti con diverse abilità.

### 2. Identificazione dei partecipanti (Campionamento)
Il campione deriva direttamente dagli obiettivi dello studio, che indicano il profilo delle persone da coinvolgere (**popolazione dello studio**; es. per studiare il primo acquisto online occorre reclutare persone che non abbiano già completato quel processo sul sito, non soltanto clienti esperti).
Quando è possibile raggiungere tutti i membri della popolazione target si parla di **campionamento di saturazione**, ma è un caso rarissimo. Quasi sempre bisogna scegliere un sottoinsieme di persone (**campionamento**) attraverso due approcci:
- **Campionamento probabilistico:** permette di applicare test statistici (se il numero di partecipanti è abbastanza alto) e di generalizzare i risultati all'intera popolazione. Include:
  - *Casuale:* si scelgono le persone con un generatore di numeri casuali o selezionando una persona ogni $n$ da un elenco.
  - *Stratificato:* si divide prima la popolazione in gruppi (es. le diverse classi di una scuola superiore) e poi si applica la scelta casuale dentro ogni gruppo.
- **Campionamento non probabilistico:** si basa sulla disponibilità delle persone a collaborare; non permette generalizzazioni statistiche robuste. Include:
  - *Di comodo (o di convenienza / gruppi di volontari):* si coinvolgono le persone che sono semplicemente disponibili in quel momento.
  - *A valanga:* i partecipanti attuali trovano altri partecipanti, che a loro volta ne portano altri, facendo crescere il gruppo proprio come una valanga di neve.

> [!info] Quanti partecipanti servono? (Dimensione del campione)
> Non c'è una risposta unica: contano obiettivi, metodo e vincoli. In generale, più sono i partecipanti e meglio è (così le interpretazioni dei risultati possono essere formulate con maggiore fiducia e non dipendono dal caso). Esistono **4 criteri formali** per decidere il numero:
> 1. **Saturazione:** si prosegue finché non emergono più nuove informazioni rilevanti.
> 2. **Costi e fattibilità:** si valuta in base al budget e al tempo disponibile (molto comune nei progetti industriali).
> 3. **Linee guida empiriche:** secondo uno studio (Caine, 2016) sulle ricerche presentate alla conferenza CHI, il numero più comune ed empiricamente accettato per studi sperimentali di Interaction Design è **12 partecipanti** (regola empirica comune, non soglia universale).
> 4. **Analisi di potenza prospettica:** metodo statistico rigoroso basato su dati quantitativi preesistenti (spesso inapplicabile per tecnologie del tutto nuove).

### 3. Relazione con i partecipanti, Consenso Informato, GDPR e Incentivi
Il rapporto tra ricercatore e partecipante deve essere chiaro, trasparente e professionale:
- **Modulo di consenso informato:** protegge gli interessi sia di chi raccoglie sia di chi fornisce i dati (in ambito accademico regolato dal *Comitato Etico della Ricerca – CER*). Spiega l'obiettivo della raccolta e l'uso dei dati, descrive la riservatezza, l'anonimato e la conservazione sicura, assicura al ricercatore di poter pubblicare i risultati e chiarisce che l'utente può ritirarsi in qualsiasi momento (distinguendo inoltre il consenso alla partecipazione dal permesso specifico di registrare audio/video). È fondamentale con persone vulnerabili, disabili o **minori** (in questo caso firmano i genitori). *Esempio pratico:* nel progetto *CampusNet* dell'Università del Maryland, il modulo chiedeva agli studenti il permesso specifico per caricare online le foto scattate nel campus, rendere visibili i commenti agli altri utenti ed essere videoregistrati.
- **Quando il consenso non serve:** se un consulente viene assunto da un'azienda per studiare un nuovo sistema interno di compilazione dei fogli presenza, non serve far firmare il consenso ai dipendenti perché esiste già un contratto lavorativo e commerciale che regola l'attività.
- **GDPR e Protezione dei Dati:** applicabile nell'Unione Europea dal maggio 2018, il *Regolamento generale sulla protezione dei dati* impone a chi raccoglie dati personali di proteggerli da accessi non autorizzati, chiarire finalità, base giuridica, accessi e tempi di conservazione, e **raccogliere solo ciò che serve** (*Esempio:* usare codici identificativi dei partecipanti nelle trascrizioni e conservare separatamente i recapiti).
- **Incentivi:** se i partecipanti non hanno un vantaggio diretto (es. testare un'app per bambini in età scolare), può servire offrire un incentivo. Se invece il vantaggio è diretto (es. i responsabili vendite devono valutare una nuova app aziendale che useranno ogni giorno per lavorare), saranno già motivati a collaborare senza incentivi extra.

### 4. Triangolazione
> [!info] Definizione e 4 tipi di Triangolazione
> **Triangolare** significa studiare un fenomeno da almeno due prospettive diverse per verificare i risultati, ridurre le distorsioni intrinseche di un singolo metodo o verificare la **"verità di base" (*ground truth*)** (es. nei grandi studi in crowdsourcing o nei sistemi per auto a guida autonoma). Esistono **4 tipi di triangolazione**:
> 1. **Triangolazione dei dati:** raccogliere dati da fonti differenti per persone, luoghi o momenti diversi.
> 2. **Triangolazione dei ricercatori:** far partecipare diversi osservatori o intervistatori alla raccolta e all'interpretazione dei dati.
> 3. **Triangolazione delle teorie:** usare quadri teorici (*framework*) differenti per esaminare i dati (difficile, perché le teorie devono avere basi filosofiche compatibili).
> 4. **Triangolazione metodologica:** è la forma più comune e consiste nell'usare tecniche diverse di raccolta dati in combinazione (es. intervistare gli utenti sugli ostacoli all'acquisto, osservarli durante il compito e approfondire con un questionario).

### 5. Studi pilota
Uno **studio pilota** è uno studio preliminare su scala ridotta condotto con pochi partecipanti prima dello studio principale per verificare la percorribilità del metodo. Serve a:
- Controllare apparecchiature e istruzioni;
- Verificare la chiarezza delle domande (es. se nel pilota un termine risulta ambiguo, lo si riscrive prima di distribuire 500 questionari);
- Provare la procedura e anticipare problemi organizzativi (se mancano partecipanti, si può svolgere anche con amici o colleghi).

> [!warning] Regola fondamentale sullo studio pilota
> **I partecipanti allo studio pilota NON vanno mai coinvolti nello studio principale:** la conoscenza già acquisita sul sistema e sulla procedura distorcerebbe i risultati.

---
## 4. Differenza tra Dati Grezzi, Informazioni e Conclusioni
Non bisogna mai confondere l'evidenza raccolta con ciò che se ne deduce:
1. **Dati (Dati grezzi):** sono il materiale puro raccolto (tempi, commenti, letture biometriche, registrazioni video).
2. **Informazioni:** sono i risultati che emergono dall'analisi e dall'interpretazione dei dati grezzi.
3. **Conclusioni:** sono le decisioni e le azioni pratiche da intraprendere sulla base delle informazioni ottenute.

> [!example] Esempi pratici (E-commerce e Centro Sportivo)
> - **Caso 1 (Acquisto online):**
>   - *Dato grezzo:* l'utente torna più volte alla pagina precedente.
>   - *Informazione:* il percorso di navigazione non rende chiaro dove trovare i costi di spedizione.
>   - *Conclusione:* rendere i costi visibili prima della schermata di conferma.
> - **Caso 2 (Prenotazione lezione di nuoto in un centro sportivo):**
>   - *Dati grezzi:* i secondi impiegati per prenotare, i commenti degli utenti sulla grafica e la misurazione del battito cardiaco.
>   - *Informazioni:* chi frequenta la piscina da oltre 5 anni trova il nuovo layout frustrante e impiega più tempo, mentre gli iscritti da meno di 2 anni lo trovano utile e veloce.
>   - *Conclusione:* introdurre un sistema di guida pensato per abituare gradualmente al cambiamento i clienti storici.

---
## 5. Metodi di Registrazione dei Dati
Mentre questionari, diari o file di log si "auto-documentano", per le interviste e le osservazioni occorre scegliere un metodo di registrazione affinché le evidenze possano essere analizzate e condivise:

| **Metodo** | **Che cosa conserva e Vantaggi** | **Svantaggi, Limiti e Accorgimenti** |
|---|---|---|
| **Appunti scritti e Fotografie** | A mano o a tastiera: poco tecnici, molto flessibili, non richiedono attrezzature speciali. Gli appunti a mano sono meno intrusivi della tastiera, consentono schizzi al volo e aiutano a focalizzare ciò che conta. Le **fotografie** catturano oggetti, eventi e ambiente completando gli appunti. | Scrivere e ascoltare insieme è stancante: si rischia di perdere punti salienti o concentrazione; velocità limitata e calligrafia difficile da decifrare. **Lavorare in coppia** riduce il carico e aggiunge una seconda prospettiva. |
| **Registrazione Audio (e Fotografie)** | Conserva parole e suoni con minore intrusività rispetto al video. L'osservatore si concentra sull'attività e l'intervistatore sulla persona. Non occorre trascrivere tutto: l'audio aiuta anche a rievocare persone e luoghi. | Richiede buona qualità acustica (connessioni instabili compromettono le interviste remote; conviene registrare un breve test prima della sessione). Difficile sincronizzare l'audio con azioni visive. |
| **Registrazione Video** | Cattura dettagli complessi delle attività, dell'ambiente, delle espressioni facciali e dei commenti verbali in contemporanea. | Molto intrusiva (può alterare il comportamento dei partecipanti). Richiede tre decisioni: **1) Videocamera fissa o mobile?** (uno smartphone basta per brevi video in movimento), **2) Quale inquadratura scegliere?**, **3) Come incide sui partecipanti?** Conviene trascorrere prima un breve periodo sul campo per familiarizzare con l'ambiente. |

> [!example] Scelta del metodo: Realtà Aumentata per progettisti di giardini
> Seguendo dei paesaggisti mentre camminano nei giardini dei clienti usando un prototipo, facendo schizzi e parlando: gli *appunti a mano* sono scomodi camminando e temono la pioggia (ma le *fotografie* sono essenziali per la natura visiva del giardinaggio); l'*audio* non permette di capire a quale schizzo o pianta si riferisca una frase; la soluzione ottimale combina **fotografie e brevi video girati con lo smartphone**.

---
## 6. Le Interviste
Le interviste sono **«conversazioni con uno scopo»**. Quanto assomiglino a una conversazione ordinaria dipende dal tipo di intervista e dal grado di controllo esercitato dall'intervistatore:

1. **Interviste non strutturate (o aperte):**
   Conversazioni esplorative e profonde su un tema, con **domande aperte** (es. *«Mi racconta l'ultima volta che ha cercato un albergo?»* o *«Quali sono i pro e i contro dell'avere un dispositivo indossabile?»*). Le risposte non hanno un formato atteso ed entrambe le persone possono orientare il percorso, pur seguendo un programma dei temi principali e usando tecniche di **probing** ("sondare").
   - *Ricchezza vs Costo:* forniscono dati ricchi, complessi e aspetti imprevisti, ma generano una grande mole di dati non strutturati e disomogenei, lunghi da analizzare.
2. **Interviste strutturate:**
   Domande prestabilite, brevi, chiare e spesso **chiuse** (scelte tra alternative predefinite, es. *«Ha acquistato su questo sito nell'ultimo mese? Sì / No»* o *«Quale sito visita più spesso: Amazon, Google o MSN?»*), poste a ogni partecipante **nello stesso modo e nello stesso ordine**, proprio come un questionario. Si usano quando gli obiettivi sono già chiari e le alternative sono note.
3. **Interviste semi-strutturate:**
   Uniscono domande chiuse e aperte: l'intervistatore segue un copione di base uguale per tutti, inizia con domande predefinite e poi sonda le risposte in modo flessibile fino a esaurire le informazioni pertinenti, facendo attenzione a **approfondire senza suggerire**.
4. **Focus Group (Interviste di gruppo):**
   Coinvolgono normalmente da **3 a 10 persone** rappresentative dei profili d'interesse, guidate da un **facilitatore esperto** che segue un programma, stimola i timidi e lascia spazio a tutte le voci evitando che figure dominanti monopolizzino la discussione.
   - *Cosa fanno emergere:* storie diverse, temi condivisi, argomenti delicati, aree di consenso o di conflitto tra stakeholder e differenze nelle aspettative o nella terminologia (es. 3 focus group separati con studenti, docenti e amministrativi per valutare un portale universitario).

### Le 4 Fasi delle Tecniche di Probing (Approfondire le risposte)
Per approfondire le risposte dell'intervistato senza influenzarlo, il *probing* si articola in **4 fasi progressive**:

1. **FASE 1 – Mantenimento del flusso (Probing a bassa intensità):**
   - **Probing silenzioso:** silenzio intenzionale di 3–5 secondi (mantenendo il contatto visivo senza intervenire) per spingere l'intervistato ad aggiungere dettagli.
   - **Incoraggiamento minimo:** rinforzi verbali neutri per confermare l'ascolto (*«Mmh... Capisco. Certo, vai avanti»*).
2. **FASE 2 – Elaborazione concettuale (Probing di espansione):**
   - **Echo Probing:** ripetizione "a specchio" dell'ultima parola chiave espressa dall'utente (*«Disorientato...?»*).
   - **Tell-Me-More Probing:** richiesta ampia, neutra e non vincolante di approfondimento (*«Vuole dirmi qualche altra cosa?»* o *«Potresti dirmi qualcosa di più su come gestisci le notifiche?»*; evitare invece frasi come *«Sembra che le piaccia questo uso del colore…»* che introducono un'interpretazione).
3. **FASE 3 – Ancoraggio fattuale (Ricostruzione contestuale):**
   - **Mini-Tour Probing:** ricostruzione cronologica passo-dopo-passo dei passaggi operativi (*«Mi descriveresti passo dopo passo cosa succede da quando accendi il dispositivo?»*).
   - **Casi devianti:** esplorazione di eccezioni, *workaround* o fallimenti (*«Ti è mai capitato che la procedura non funzionasse? Cosa è successo in quell'occasione?»*).
4. **FASE 4 – Dissoluzione delle ambiguità (Probing di chiarimento):**
   - **Sostituzione del "Perché":** indagine indiretta sui fattori causali che evita il tono inquisitorio del "perché" (*«Quali elementi della schermata ti hanno portato a ignorare il suggerimento?»*).
   - **Probing Naïve:** richiesta di un esempio concreto vissuta dal punto di vista del principiante (*«Potresti farmi un esempio concreto dell'ultima volta che l'interazione ti è sembrata macchinosa?»*).

### Lavorare con utenti diversi (Inclusione nella ricerca)
Età, istruzione, vita quotidiana, cultura e abilità fisiche o cognitive influenzano la raccolta dati:
- **Bambini:** usare immagini e conversazioni al posto di istruzioni scritte; per i più piccoli si usa lo **"smiley-metro"** (scala di faccine da *"Orribile"* a *"Brillante"* per esprimere sentimenti).
- **Culture diverse:** adottare metodi e tecniche visuali appropriati per comprendere significati condivisi (es. presso la comunità Mbeere del Kenya il focus group è stato adattato nel tradizionale *talking circle* degli anziani, dove interrompere o mettere fretta sarebbe una grave scortesia).
- **Persone con disabilità intellettive:** coinvolgere i *caregiver* che conoscono la persona per tradurre concetti astratti in esempi concreti e comprensibili (es. *"Così non devi telefonare alla mamma per dirle 'Mamma, mi sono perso'"*).
- **Animali (*Animal-Computer Interaction*):** osservazioni e sistemi di tracciamento (es. registrare quando il cane gira la testa davanti alla TV) interpretati con esperti di comportamento animale.

### Linee guida per formulare le domande, Pianificazione e Conduzione
Quando si formulano le domande di un'intervista occorre rispettare **3 regole d'oro**:
1. **Una cosa alla volta (evitare domande lunghe o composte):** invece di *«Le piace questa app rispetto a quelle usate in precedenza?»*, chiedere separatamente: 1) se piace l'app, 2) se sono state usate altre app in passato, 3) che cosa se ne pensa.
2. **Linguaggio semplice (evitare il gergo tecnico):** chi non capisce un termine tecnico può vergognarsi di ammetterlo.
3. **Neutralità (non suggerire la risposta attesa):** chiedere *«Che cosa pensa di questa interazione?»* invece di *«Perché le piace questa interazione?»*.

**Pianificazione di un'intervista (5 passi prima dell'incontro):**
1. **01 – Definizione delle domande:** preparare domande aperte o chiuse chiare e concise in base agli obiettivi.
2. **02 – Documentazione:** raccogliere moduli di consenso informato, trattamento dei dati e descrizioni del progetto.
3. **03 – Apparecchiature:** verificare il funzionamento di registratori audio, videocamere o fotocamere.
4. **04 – Strutturazione:** organizzare la sequenza logica delle domande.
5. **05 – Logistica:** organizzare momento e sede opportuni per l'incontro.

**Conduzione dell'intervista (sequenza tipica in 5 fasi):**
1. **Introduzione:** l'intervistatore si presenta, spiega lo scopo dell'intervista, rassicura sugli aspetti etici/privacy e chiede il permesso di registrare (**deve essere identica per ogni intervistato**).
2. **Riscaldamento:** domande facili che non incutono timore (es. informazioni demografiche di base).
3. **Parte principale:** domande presentate in sequenza logica, lasciando quelle più approfondite e complesse alla fine (l'ordine può variare nelle semi-strutturate).
4. **Raffreddamento:** poche domande semplici per dissipare ogni eventuale tensione creatasi.
5. **Conclusione:** ringraziare l'intervistato e **spegnere visibilmente il registratore** (o chiudere il taccuino), segnalando che l'intervista è conclusa.

**Interviste da remoto e arricchimento del contesto:**
- **Interviste da remoto (Skype, WebEx, Zoom, telefono):**
  - *Vantaggi:* nessuno spostamento, ambiente familiare e rilassato, minore preoccupazione per l'abbigliamento, raggiungimento di persone lontane e maggiore anonimato su temi delicati.
  - *Svantaggi:* connessione e acustica scadenti, distrazioni domestiche, visione parziale del linguaggio del corpo e facilità di abbandono della sessione.
- **Arricchire l'esperienza dell'intervista:** poiché una stanza d'intervista neutra crea un contesto artificiale, conviene usare strumenti di appoggio per rendere più concrete le risposte: **prototipi di Persona** (es. poster con i profili di "Leonard" e "Monica"), **oggetti legati al lavoro**, **scenari** (descrizioni di attività comuni) e **prototipi fisici o digitali**.

---
## 7. I Questionari
I questionari utilizzano domande predisposte per ottenere risposte confrontabili, raccogliendo dati demografici e opinioni in modo efficiente. Le loro **4 caratteristiche principali** sono: **Scalabilità** (raggiungono molti partecipanti senza replicare sessioni singole), **Accessibilità** (coinvolgono persone lontane o non disponibili a orari fissi), **Asincronia** (si risponde senza il ricercatore) e **Standardizzazione** (stesse domande e formato per tutti).

### Quando usare Questionari vs Interviste strutturate
| **Questionari** | **Interviste strutturate** |
|---|---|
| I partecipanti hanno **motivazione sufficiente** per completare autonomamente il modulo. | Serve **incoraggiare la partecipazione** (senza pressioni) perché le persone hanno fretta e non si fermano a compilare da sole (es. in stazione). |
| Molte persone geograficamente disperse; domande specifiche con risposte predefinite; verifica su un gruppo ampio delle conclusioni emerse da uno piccolo. | Occorre chiarire eventuali ambiguità, il contesto fisico è rilevante o si vuole osservare il linguaggio del corpo. |

### Struttura e consigli di progettazione di un questionario
Un questionario ben progettato è organizzato in **3 sezioni**:
1. **01 – Informazioni demografiche:** genere, età, luogo di nascita (**solo se pertinenti all'obiettivo!** Chiedere l'altezza è inutile per un sito web, ma essenziale per dispositivi indossabili).
2. **02 – Esperienze pertinenti:** es. ore quotidiane dedicate a Internet o conoscenza pregressa del dominio (es. prima l'esperienza di acquisto online, poi le difficoltà nel pagamento).
3. **03 – Domande principali:** contribuiscono direttamente alla ricerca (nei questionari lunghi si raggruppano per tema).

**Consigli di progettazione:**
- **L'ordine conta:** una domanda può influenzare quelle successive;
- Valutare versioni diverse per popolazioni diverse, mantenendo comparabili gli aspetti comuni;
- Fornire istruzioni chiare, compresa la possibilità di saltare domande o inserire opzioni come *"nessuna opinione"*;
- Limitare la lunghezza, eliminare domande non pertinenti e prevedere possibilità di salvataggio/interruzione se il percorso è lungo;
- Curare l'**impaginazione** equilibrando spazi bianchi, compattezza e ritmo visivo.

### Formati di risposta e Scale di valutazione
1. **Scelte multiple e Caselle di spunta:** per alternative finite e predefinite (specificando sempre se si può scegliere una sola risposta o più risposte).
2. **Intervalli:** usati per l'età o altre misure continue.
   - **Errore grave da evitare:** non sovrapporre mai gli intervalli! Scrivere `15–20` e `20–25` (o `1–3 ore` e `3–5 ore`) rende ambiguo dove collocare il valore di confine `20` (o `3`). Gli intervalli corretti sono **`15–19` e `20–24`**.
3. **Scale Likert:** misurano opinioni, atteggiamenti, convinzioni e soddisfazione chiedendo il grado di accordo con un'affermazione (es. *«L'uso del colore è eccellente»*) su una scala di numeri o parole:
   `1 (Molto d'accordo)` – `2 (D'accordo)` – `3 (OK / Né l'uno né l'altro)` – `4 (In disaccordo)` – `5 (Molto in disaccordo)`.
   Occorre definire chiaramente il significato del punto centrale e mantenere l'ordine della scala (`1–5` oppure `5–1`) **coerente in tutto il questionario**.
4. **Scale del Differenziale Semantico:** esplorano atteggiamenti bipolari tramite coppie di aggettivi opposti posti agli estremi di una scala (es. da 1 a 7: *Attraente — Sgradevole*, *Chiaro — Confuso*, *Piatto — Colorato*, *Entusiasmante — Noioso*). I poli positivi e negativi vengono **mescolati** tra destra e sinistra proprio per individuare gli utenti che compilano il questionario senza prestare attenzione.

> [!info] Quanti punti deve avere una scala? (Granularità del giudizio)
> - Un **numero dispari** (3, 5, 7, 9) offre un punto neutro centrale; un **numero pari** costringe l'utente a sbilanciarsi.
> - **3 punti:** per alternative limitate (*Sì / Non so / No*).
> - **5 punti:** ideale per giudizi di accordo o preferenza (*mi piace / non mi piace*, *d'accordo / in disaccordo*).
> - **7 – 9 punti:** per giudizi più fini e sfumati (es. valutare il "grado di fascino" di un personaggio in un videogioco).

### Questionari Online vs Cartacei e Preparazione
- **Online:** raccolta e trasferimento automatico in database, analisi automatizzata, caselle e menu interattivi, validazione immediata dei dati e **salto automatico** delle domande non pertinenti (es. saltare la sezione bagagli se il passeggero ha viaggiato solo col bagaglio a mano). Gli studi mostrano inoltre che online le persone sono più schiette su abitudini private e scrivono risposte aperte più lunghe e dettagliate.
- **Cartacei:** utili quando manca l'accesso a Internet, la connessione è costosa o il contesto fisico lo richiede (es. eventi e luoghi pubblici).
- **Limite del campione:** il canale va scelto in base ai partecipanti, non solo alla comodità del ricercatore; il campionamento casuale è difficile e quello di convenienza limita la generalizzabilità.

**I 5 passi per preparare un questionario online:**
1. **Pianificazione della tempistica:** se c'è una scadenza, procedere a ritroso programmando le attività su base settimanale.
2. **Design offline:** creare prima un documento di puro testo facilmente copiabile nello strumento online.
3. **Programmazione online:** implementare percorsi di navigazione e funzionalità interattive.
4. **Test e Studio Pilota:** verificare che lo strumento si comporti come previsto e raccogliere feedback da esperti e potenziali partecipanti.
5. **Reclutamento:** creare inviti stuzzicanti, semplici, amichevoli, rispettosi, motivanti, informativi e brevi.

**Somministrazione e tasso di risposta:**
- **40%:** tasso di ritorno generalmente considerato accettabile nelle grandi indagini (spesso è inferiore).
- **~100% (<20 utenti):** nei piccoli campioni con meno di 20 utenti (dimensione spesso usata dagli interaction designer) si ottiene quasi sempre il completamento totale.

---
## 8. L'Osservazione
L'osservazione è utile in qualsiasi fase dello sviluppo per comprendere contesti, attività e obiettivi degli utenti, guardando **come un'attività si svolge realmente**. Si classifica lungo **due dimensioni indipendenti**:
1. **Accesso all'attività:**
   - **Diretta:** il ricercatore osserva gli utenti mentre agiscono in tempo reale.
   - **Indiretta:** l'attività viene registrata (es. in video o tramite log) e studiata successivamente.
2. **Ambiente:**
   - **Sul campo:** si osservano le attività quotidiane nel contesto naturale.
   - **Controllato (in laboratorio):** si osservano attività e compiti specifici assegnati in un ambiente controllato.
   *(Nota: un video raccolto sul campo combina ambiente naturale e analisi indiretta).*

### Confronto: Osservazione sul Campo vs In Laboratorio
| **Aspetto** | **Sul campo (Contesto naturale)** | **In laboratorio (Ambiente controllato)** |
|---|---|---|
| **Vantaggi** | Fa emergere problemi reali, il vero contesto d'uso, soddisfazione e frustrazione autentiche e l'integrazione tra dispositivo e comportamento (es. testare un navigatore da polso girando per Stoccolma con i turisti). | Garantisce **replicabilità**, permette di isolare problemi specifici di usabilità, ottenere prestazioni confrontabili, calcolare medie e statistiche precise e mantenere un maggiore distacco dell'osservatore. |
| **Limiti** | Difficile restare obiettivi dall'interno del gruppo; dati qualitativi difficili da generalizzare; condizioni esatte non replicabili. | Situazione artificiale; manca il contesto naturale e non descrive da solo l'uso reale. |
| **Quando sceglierlo** | Per comprendere l'attività nella vita quotidiana. | Per confrontare compiti specifici e condizioni controllate. |

### Framework di riferimento per l'Osservazione
Per strutturare la raccolta sul campo e non perdersi tra i troppi eventi simultanei, si utilizzano dei **quadri di riferimento (*framework*)**:
- **Quadro semplice ("Chi, dove, che cosa"):**
  1. *La persona (Chi):* chi usa la tecnologia?
  2. *Il luogo (Dove):* dove la usa?
  3. *La cosa (Che cosa):* che cosa fa?
- **Quadro dettagliato di Robson e McCartan (9 elementi):**
  1. **Spazio:** *Come è configurato l'ambiente fisico?*
  2. **Attori:** *Chi è coinvolto?*
  3. **Attività:** *Che cosa fanno e perché?*
  4. **Oggetti:** *Che cosa è presente oltre alla tecnologia studiata?*
  5. **Atti:** *Quali sono le singole azioni specifiche?*
  6. **Eventi:** *È un'occasione speciale?*
  7. **Tempo:** *Qual è la successione temporale?*
  8. **Obiettivi:** *Che cosa cercano di realizzare gli attori?*
  9. **Stati d'animo:** *Qual è l'umore del gruppo e dei singoli?*

### Il Grado di Partecipazione dell'Osservatore
Il coinvolgimento del ricercatore varia lungo uno spettro che va dall'**esterno** all'**interno** del gruppo:
1. **Osservatore passivo (Esterno):** non prende alcuna parte nell'ambiente; è più appropriato in laboratorio, mentre sul campo è difficile da mantenere.
2. **Partecipazione moderata:** mantiene un'interazione limitata e un distacco professionale.
3. **Osservatore partecipante (Interno):** diventa membro del gruppo studiato, ma deve mantenere ben separati i due ruoli (partecipare richiede coinvolgimento, osservare richiede distacco).
   - **Le 4 sfide dell'osservatore partecipante:** 1) competenze insufficienti per svolgere l'attività del gruppo; 2) gruppo poco disposto ad accettare un estraneo; 3) tempo limitato per acquisire familiarità; 4) accesso delicato a luoghi privati come le abitazioni *(es. nello studio di Cycil et al., 2013 sulle conversazioni in auto tra genitori e figli, i ricercatori hanno viaggiato con le famiglie la prima settimana per farsi conoscere, lasciando poi che fossero i familiari stessi a videoregistrare gli episodi successivi)*.

### Pianificazione, Lavoro in Team, Conduzione e Criteri di arresto
**I 5 passi per pianificare l'osservazione sul campo (prima di entrare sul campo):**
1. Scegliere un *framework* per focalizzare e organizzare la raccolta;
2. Definire il livello di partecipazione (da passivo ad attivo);
3. Decidere come registrare i dati (appunti, audio, video, fotografie o combinazioni);
4. Pianificare l'accettazione nel gruppo e l'accesso agli spazi privati;
5. Includere prospettive diverse su persone, attività e mansioni, valutando il **lavoro in team**.

**I 4 vantaggi del lavoro in team nell'osservazione:**
- **Copertura più ampia:** ogni osservatore si concentra su persone o parti diverse del contesto;
- **Osservazione e riflessione:** si intrecciano più facilmente quando gli osservatori sono più di uno;
- **Maggiore affidabilità:** le osservazioni possono essere confrontate e discusse;
- **Prospettive multiple:** i risultati riflettono letture diverse che arricchiscono la comprensione del fenomeno.

**Conduzione dell'osservazione (durante e dopo ogni sessione):**
- Prestare uguale attenzione a tutti i partecipanti, anche quando alcune relazioni sono più facili;
- Rifocalizzare progressivamente lo studio in base a ciò che si apprende;
- **Rivedere appunti e registrazioni alla fine di ogni singola giornata**, tenendo un diario o blog privato;
- **Separare nettamente le opinioni personali dalle osservazioni oggettive** ed evidenziare ciò che richiede ulteriori indagini;
- Verificare osservazioni e interpretazioni con informatori o membri del gruppo (**member checking** / interviste retrospettive).

**Quando smettere di osservare? (5 indicatori di arresto):**
1. È stata raggiunta la scadenza prevista dal calendario;
2. Non emerge più nulla di nuovo (**saturazione**);
3. Si ripetono schemi di comportamento simili;
4. Sono stati osservati tutti i principali gruppi di stakeholder;
5. Le loro prospettive sono ormai comprese adeguatamente.

---
## 9. Il Dilemma "Dire vs Fare", Protocollo di Lavoro ed Errori Comuni

> [!warning] Il dilemma dell'autodescrizione: "Dire vs Fare"
> Ciò che gli utenti dicono di fare non coincide sempre con ciò che fanno realmente (es. nello studio di *Rogers et al., 2010*, i lavoratori sostenevano nelle interviste di non aver cambiato abitudini dopo l'installazione di luci nel pavimento, mentre i sensori dimostravano che prendevano le scale molto più spesso; oppure un utente afferma di confrontare sempre i prezzi online, ma durante l'osservazione sceglie il primo prodotto disponibile).
> - **Perché accade:** desiderabilità sociale (volersi mettere in buona luce), dimenticanze e tentativo di compiacere l'intervistatore (ancora più difficile da verificare nelle interviste remote).
> - **Come affrontarlo:** essere consapevoli del limite, scegliere con cura le domande, ampliare il campione quando opportuno e **triangolare più tecniche** (affiancando l'osservazione alle interviste).

### Protocollo di lavoro: Buone pratiche nella Raccolta Dati
1. **01 – Preparazione:** definire obiettivi chiari, scegliere tecniche appropriate, preparare materiali e apparecchiature, condurre lo studio pilota e predisporre il consenso informato.
2. **02 – Raccolta:** mantenere flessibilità e focus, registrare accuratamente, conservare obiettività e prestare uguale attenzione a tutti i partecipanti.
3. **03 – Revisione e analisi:** effettuare una revisione quotidiana, separare opinioni e osservazioni, verificare con i partecipanti (*member checking*), proteggere i dati (GDPR), distinguere dati grezzi, informazioni e conclusioni, usare prospettive multiple e documentare il processo.

### I 6 Errori Comuni da Evitare
- **Domande ambigue:** evitare domande troppo lunghe, domande composte e gergo tecnico.
- **Domande orientate (tendenziose):** non suggerire mai la risposta desiderata.
- **Intervalli sovrapposti:** usare `15–19` e `20–24`, mai `15–20` e `20–25`.
- **Nessuno studio pilota:** provare sempre il metodo prima del lancio definitivo.
- **Contesto ignorato:** ricordare che le condizioni d'uso guidano l'interpretazione dei dati.
- **Una sola tecnica:** triangolare più metodi quando possibile.

---
## 10. Altre Fonti di Requisiti, Analisi della Concorrenza e Sintesi Finale

Oltre a interviste, questionari e osservazione, esistono altre due fonti preziose per raccogliere requisiti:

### 1. Suggerimenti spontanei degli utenti
I forum di discussione, le recensioni e le segnalazioni all'assistenza fanno emergere difficoltà e proposte di miglioramento non sollecitate dal ricercatore.
- *Esempio:* in un forum un utente segnala di dover reinserire l'indirizzo di spedizione a ogni acquisto.
- *Attenzione:* il suggerimento spontaneo ha bassi costi di raccolta ma carattere episodico; indica un **bisogno da approfondire** (conservando il contesto della segnalazione e verificando quanti altri utenti lo condividono), non ancora un requisito approvato.

### 2. Analisi della concorrenza e delle Best Practices
L'analisi dei prodotti concorrenti persegue **3 obiettivi principali**:
1. **Pratiche migliori (*Best practices*):** individuare le soluzioni migliori adottate nel settore per evitare di *"reinventare la ruota"*.
2. **Forze e debolezze:** comprendere dove i prodotti concorrenti funzionano bene e dove mostrano limiti.
3. **Valore distintivo:** caratterizzare il nostro prodotto chiedendosi cosa lo contraddistingue e cosa gli conferisce valore competitivo.
*(Nota: confrontare soluzioni serve a orientare le scelte trasformando le differenze in criteri espliciti di analisi, non a copiarle acriticamente senza verificare i bisogni degli utenti).*

> [!example] Esempio di tabella di Analisi della Concorrenza (Confronto di 5 siti web)
> | **Caratteristica / Funzione** | **Sito 1** | **Sito 2** | **Sito 3** | **Sito 4** | **Sito 5** |
> |---|---|---|---|---|---|
> | **Registrazione utenti** | SÌ | SÌ | SÌ | SÌ | SÌ |
> | **Acquisto online** | SÌ | NO | Solo registrati | Solo registrati | NO |
> | **Newsletter** | NO | NO | SÌ | NO | NO |
> | **Forum** | SÌ | NO | NO | SÌ | NO |
> | **Invio commenti** | NO | NO | SÌ | SÌ | SÌ |
> | **Ricerca interna** | SÌ | SÌ | SÌ | SÌ | SÌ |
> | **Navigazione** | Barre globali e locali orizzontali | Menu verticale a due livelli | Barre globali e locali orizzontali a schede | Barre globali e locali orizzontali | Menu a tendina |

### Tabella riepilogativa delle 6 Tecniche per la Raccolta dei Requisiti

| **Tecnica** | **Serve per** | **Vantaggi** | **Svantaggi** |
|---|---|---|---|
| **Questionari** | Rispondere a domande specifiche. | Si possono raggiungere molte persone con poco sforzo. | Vanno progettati con grande accuratezza, altrimenti le risposte risultano poco informative; il tasso di risposta può essere basso. |
| **Interviste individuali** | Esplorare determinati aspetti del problema e specifici punti di vista. | L'intervistatore può controllare il corso dell'intervista, orientandola verso i temi su cui l'intervistato fornisce i contributi più utili. | Richiedono molto tempo; gli intervistati potrebbero evitare di esprimersi con franchezza su aspetti delicati. |
| **Focus group** | Mettere a fuoco un argomento su cui possono esserci diversi punti di vista. | Fanno emergere aree di consenso e di conflitto; possono far emergere soluzioni condivise dal gruppo. | La conduzione richiede esperienza; possono emergere figure dominanti che monopolizzano la discussione. |
| **Osservazioni sul campo** | Comprendere il contesto reale delle attività dell'utente. | Permettono di ottenere una consapevolezza sull'uso reale del prodotto che le altre tecniche non danno. | Possono essere difficili da effettuare e richiedere molto tempo e risorse. |
| **Suggerimenti spontanei dell'utente** | Individuare specifiche necessità di miglioramento di un prodotto. | Hanno bassi costi di raccolta. | Hanno normalmente carattere episodico e possono essere molto specifici. |
| **Analisi della concorrenza e best practices** | Individuare le soluzioni migliori adottate nel settore di interesse. | Evitano di "reinventare la ruota" e permettono di ottenere un vantaggio competitivo. | L'analisi approfondita è di solito costosa in termini di tempo e risorse. |

### Dalle evidenze alla progettazione: 3 difficoltà da evitare
Nel passaggio dalla raccolta dei requisiti alla progettazione vera e propria, i progettisti devono evitare **tre trappole comuni**:
1. **Solo l'oggetto:** concentrarsi esclusivamente sul prodotto tecnologico trascurando il contesto d'uso reale.
2. **Progettare per noi stessi:** considerarsi "utenti tipici" e dare per scontato che le proprie abilità e necessità siano quelle di tutti gli utenti.
3. **Ruoli senza persone:** immaginare gli utenti come semplici ruoli astratti (es. *"l'amministratore"*, *"il cliente"*), facendo perdere concretezza al progetto. Per superare questo limite si utilizzano i profili **Persona** e gli **scenari d'uso**, che permettono di tenere insieme persone reali, motivazioni e situazioni concrete.