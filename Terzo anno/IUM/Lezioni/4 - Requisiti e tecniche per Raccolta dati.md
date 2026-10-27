# Appunti: La Raccolta dei Dati nell'Interaction Design

## 1. Cosa sono i dati e perché si raccolgono

I dati possono assumere qualsiasi forma utile per comprendere un progetto, i bisogni o il comportamento degli utenti: numeri, parole, misurazioni, descrizioni, commenti, foto, schizzi o video. Si dividono in due grandi categorie:
- **Dati quantitativi:** esprimono quantità numeriche. _Esempio:_ il tempo impiegato per trovare un'informazione su una pagina web o il numero di clic effettuati per arrivarci.
- **Dati qualitativi:** esprimono qualità, opinioni e descrizioni. _Esempio:_ ciò che l'utente dice o commenta a proposito di quella stessa pagina web.

Nell'Interaction Design i dati si raccolgono principalmente in due fasi (e non richiedono quasi mai competenze tecniche o di programmazione):
1. **Scoperta dei requisiti:** per avere informazioni sufficienti, accurate e pertinenti prima di iniziare a progettare.
2. **Valutazione:** per raccogliere le reazioni degli utenti e misurare le loro prestazioni mentre usano un sistema o un prototipo.

Le tre tecniche principali di raccolta sono (utilizzabili sia per dati qualitativi che quantitativi, meglio se combinate tra loro per evitare le distorsioni tipiche di ogni singolo metodo):
- **Interviste:** conversazioni sincrone (di persona, al telefono o via Skype/Zoom) con domande più o meno strutturate.
- **Questionari:** serie di domande su carta o online a cui l'utente risponde in modo asincrono, cioè senza la presenza del ricercatore.
- **Osservazione:** può essere **diretta** (passare del tempo con le persone guardando cosa fanno mentre lo fanno) o **indiretta** (registrare l'attività dell'utente per studiarla in seguito).

## 2. I cinque aspetti fondamentali della Raccolta Dati
Per avere successo in qualsiasi sessione di raccolta dati, bisogna curare cinque aspetti chiave:

### 1. Definizione degli obiettivi
Prima di iniziare, bisogna fissare obiettivi chiari, concisi e specifici (nell'Interaction Design di solito si esprimono in modo informale). Gli obiettivi determinano quale tecnica usare e come analizzare i dati.
- _Esempi di obiettivi:_ capire come la tecnologia entra nella vita di una famiglia; stabilire quale tra due icone per il comando "invia messaggio" sia più facile da usare; capire se il redesign di un contatore portatile va nella direzione giusta.
### 2. Identificazione dei partecipanti (Campionamento)
Gli obiettivi indicano il profilo delle persone da coinvolgere, che formano la **popolazione dello studio**. Quando è possibile raggiungere tutti i membri della popolazione target si parla di **campionamento di saturazione**, ma è un caso rarissimo. Quasi sempre bisogna scegliere un sottoinsieme di persone (**campionamento**) attraverso due approcci:
- **Campionamento probabilistico:** permette di applicare test statistici (se il numero di partecipanti è abbastanza alto) e di generalizzare i risultati all'intera popolazione. Include:  
    - _Casuale:_ si scelgono le persone con un generatore di numeri casuali o selezionando una persona ogni $n$ da un elenco.
    - _Stratificato:_ si divide prima la popolazione in gruppi (es. le diverse classi di una scuola superiore) e poi si applica la scelta casuale dentro ogni gruppo.
- **Campionamento non probabilistico:** si basa sulla disponibilità delle persone a collaborare; non permette generalizzazioni statistiche robuste. Include:  
    - _Di comodo (o gruppi di volontari):_ si coinvolgono le persone che sono semplicemente disponibili in quel momento.
    - _A valanga:_ i partecipanti attuali trovano altri partecipanti, che a loro volta ne portano altri, facendo crescere il gruppo proprio come una valanga di neve.

**Quanti partecipanti servono?** In generale, più sono e meglio è (così le differenze trovate dipendono da effetti reali e non dal caso). Esistono 4 modi formali per decidere il numero:
1. _Saturazione:_ si raccolgono dati finché non emergono più informazioni nuove.
2. _Costi e fattibilità:_ si decide in base al budget e al tempo (molto comune nei progetti industriali, raro nell'accademia).
3. _Linee guida / Standard locali:_ secondo uno studio (Caine, 2016) sulle ricerche presentate alla conferenza CHI, il numero più comune ed empiricamente accettato nell'Interaction Design è **12 partecipanti**.
4. _Analisi di potenza prospettica:_ metodo statistico rigoroso basato su dati quantitativi preesistenti (spesso inapplicabile nell'Interaction Design perché per le nuove tecnologie non esistono dati precedenti).

### 3. Relazione con i partecipanti, Consenso e Incentivi
Il rapporto tra ricercatore e partecipante deve essere chiaro e professionale.
- **Modulo di consenso informato:** usato in molti paesi (es. USA e Regno Unito) per tutelare entrambe le parti. Spiega gli obiettivi, garantisce l'anonimato e la sicurezza dei dati, assicura al ricercatore di poter pubblicare i risultati e garantisce all'utente di potersi ritirare in qualsiasi momento. È fondamentale con persone disabili o **minori** (in questo caso firmano i genitori per assicurarsi che non vengano mostrate immagini violente o fatte domande imbarazzanti). _Esempio pratico:_ Nel progetto _CampusNet_ dell'Università del Maryland, il modulo chiedeva agli studenti il permesso specifico per caricare online le foto scattate nel campus, rendere visibili i commenti agli altri utenti ed essere videoregistrati.
- **Quando il consenso non serve:** se un consulente viene assunto da un'azienda per studiare un nuovo sistema di compilazione dei fogli presenza, non serve far firmare il consenso ai dipendenti perché esiste già un contratto lavorativo e commerciale che regola l'attività (fermo restando il rispetto di leggi come il **GDPR** europeo per la protezione dei dati personali).
- **Incentivi:** se i partecipanti non hanno un vantaggio diretto (es. testare un'app per bambini in età scolare), può servire offrire un incentivo per convincerli a partecipare. Se invece il vantaggio è ovvio (es. i responsabili vendite devono compilare un questionario su una nuova app aziendale che useranno ogni giorno per lavorare), saranno già motivati a collaborare senza incentivi extra.

### 4. Triangolazione
Significa studiare un fenomeno da almeno due prospettive diverse per convalidare i risultati, compensare i limiti di un metodo o verificare la **"verità di base" (_ground truth_)** nei grandi studi in crowdsourcing o nei sistemi per auto a guida autonoma. Esistono 4 tipi di triangolazione:
1. **Triangolazione dei dati:** raccogliere dati da fonti, luoghi, momenti o persone diverse.
2. **Triangolazione dei ricercatori:** usare diversi osservatori o intervistatori per raccogliere e interpretare i dati.
3. **Triangolazione delle teorie:** analizzare i dati usando quadri teorici differenti (difficile, perché le teorie dovrebbero avere basi filosofiche compatibili).
4. **Triangolazione metodologica:** è la più comune e consiste nell'usare tecniche di raccolta diverse (es. affiancare un questionario a delle interviste).

### 5. Studi pilota
Uno **studio pilota** è un test preliminare fatto su un piccolo gruppo prima di avviare lo studio vero e proprio. Serve a testare le apparecchiature, verificare la procedura e controllare che le domande siano chiare (distribuire 500 questionari per poi scoprire che due domande erano incomprensibili è un errore costosissimo). Se mancano partecipanti, si può fare con amici o colleghi.
> **Regola fondamentale:** Chi partecipa allo studio pilota **non può partecipare allo studio principale**, perché conoscendo già lo studio falserebbe i risultati.

## 3. Differenza tra Dati Grezzi, Informazioni e Conclusioni
Non bisogna mai confondere ciò che si raccoglie con ciò che se ne deduce:
- **Dati grezzi:** sono gli elementi puri raccolti.
- **Informazioni:** emergono quando si analizzano e si interpretano i dati grezzi.
- **Conclusioni:** sono le decisioni e le azioni pratiche da intraprendere in base alle informazioni ottenute.

_Esempio del centro sportivo:_ Si vuole capire se il nuovo layout delle schermate migliora la prenotazione di una lezione di nuoto.
- _Dati grezzi:_ i secondi impiegati per prenotare, i commenti degli utenti sulla grafica e la misurazione del loro battito cardiaco durante l'operazione.
- _Informazioni:_ dall'analisi emerge che chi frequenta la piscina da oltre 5 anni trova il layout frustrante e ci mette più tempo, mentre i clienti iscritti da meno di 2 anni lo trovano utile e prenotano velocemente.
- _Conclusione:_ bisogna introdurre un sistema di guida più efficace pensato per abituare al cambiamento i clienti storici.

## 4. Metodi di Registrazione dei Dati
Mentre questionari, diari o file di log si "auto-documentano", per le interviste e le osservazioni bisogna scegliere come registrare i dati:

|**Metodo**|**Vantaggi**|**Svantaggi e Limiti**|
|---|---|---|
|**Appunti manoscritti e Fotografie**|Poco tecnici, molto flessibili e meno intrusivi di una tastiera. Permettono di fare schizzi e diagrammi al volo. Scrivere a mano aiuta a concentrarsi su ciò che è importante.|Stancante scrivere mentre si ascolta/osserva; velocità limitata; calligrafia difficile da rileggere; facile perdere la concentrazione o introdurre distorsioni (lavorare in coppia aiuta a evitarlo).|
|**Registrazione Audio e Fotografie**|Meno intrusiva del video; permette di concentrarsi totalmente sull'utente o sull'attività senza dover scrivere ogni parola. Ottima per rievocare luoghi e citazioni (non serve trascrivere tutto).|Richiede un'ottima qualità acustica (spesso rovinata nelle chiamate Skype/remoto con connessioni instabili). Difficile sincronizzare l'audio con azioni visive o documenti.|
|**Registrazione Video**|Cattura tutto nel dettaglio: ambiente, azioni, espressioni facciali e commenti verbali in contemporanea.|Molto intrusivo (può alterare il comportamento delle persone, che magari guardano in camera). Richiede pianificazione: bisogna scegliere tra **telecamera fissa o mobile** (es. nei giochi in movimento serve mobile o uno smartphone) e fare sopralluoghi prima per capire **dove puntarla**.|

_Esempio di scelta del metodo (Strumento in Realtà Aumentata per progettisti di giardini):_ Se dobbiamo seguire dei paesaggisti mentre camminano nei giardini dei clienti usando un prototipo, fare schizzi e parlare:
- Gli _appunti a mano_ sono scomodi mentre si cammina e se piove la carta si bagna (però fare _fotografie_ è fondamentale perché il giardinaggio è un'attività visiva ed estetica).
- L'_audio_ è comodo, ma poi è difficilissimo capire a quale schizzo o pianta si riferiva una frase registrata.
- Il _video_ cattura tutto (sguardo, schizzi, parole), ma è intrusivo e teme la pioggia; la soluzione migliore sono brevi video girati con lo smartphone.

## 5. Le Interviste
Le interviste sono "conversazioni con uno scopo". Si dividono in 4 tipologie in base al livello di controllo esercitato dall'intervistatore:
1. **Interviste non strutturate (o aperte):** L'intervistatore ha un controllo minimo; sono conversazioni esplorative che scendono in profondità usando **domande aperte** (es. _"Quali sono i pro e i contro di avere un dispositivo indossabile?"_). L'intervistatore usa comunque una scaletta di temi da toccare e utilizza tecniche di **probing** (domande sonda come _"Può dirmi di più a proposito di..."_).
    - _Pro e Contro:_ Fanno emergere idee a cui il ricercatore non aveva mai pensato, ma generano una mole enorme di dati disomogenei lunghi e complessi da analizzare.
2. **Interviste strutturate:** L'intervistatore segue domande chiuse e predefinite, poste **nello stesso identico ordine e modo** a tutti i partecipanti (es. _"Quale sito visita più spesso tra Amazon, Google o MSN?"_). Utili solo quando gli obiettivi sono già chiarissimi e le risposte possibili sono note (es. feedback sul layout grafico di un browser).
3. **Interviste semi-strutturate:** Combinano domande chiuse e aperte. Si parte da un copione base uguale per tutti, ma poi si approfondisce con domande sonda neutre finché non emergono più informazioni nuove. _Esempio:_ Si chiede quali siti musicali si visitano $\rightarrow$ l'utente risponde _hottestmusic.com_ $\rightarrow$ si chiede _"Perché?"_ $\rightarrow$ risponde _"Per il layout"_ $\rightarrow$ si sonda con _"Mi dica di più sul layout"_ e poi _"C'è altro che le piace?"_.
4. **Focus Group (Interviste di gruppo):** Coinvolgono da **3 a 10 persone** rappresentative della popolazione target, guidate da un facilitatore che stimola i timidi e frena chi monopolizza la parola. Ottimi per indagare temi condivisi o far emergere conflitti tra diversi gruppi. _Esempio:_ per valutare un sito universitario si possono fare 3 focus group separati (studenti, docenti, amministrativi) perché ognuno usa il sito per scopi diversi.

### Adattarsi a utenti diversi ("Non esiste una taglia unica")
Le tecniche vanno adattate alle capacità cognitive, fisiche e culturali dei partecipanti:
- **Bambini:** non reagiscono come gli adulti e i più piccoli non sanno leggere. Al posto dei questionari scritti si usano immagini, chiacchierate o lo **"smiley-metro"** (una scala di faccine che vanno da "Orribile" a "Brillante" su cui il bambino indica come si sente).
- **Culture diverse:** in Namibia o presso la comunità Mbeere del Kenya (per uno studio sulla gestione dell'acqua), i ricercatori hanno dovuto adattare il focus group trasformandolo nel tradizionale _talking circle_ kenyota: gli anziani siedono in cerchio e parlano a turno per tutto il tempo che vogliono, poiché interromperli o mettergli fretta sarebbe una grave scortesia culturale.
- **Persone con disabilità intellettive:** è fondamentale affiancare i _caregiver_ (chi si prende cura di loro) per tradurre concetti astratti in esempi concreti e familiari. _Esempio:_ per spiegare a cosa serve un'app con gli orari degli autobus, la caregiver ha detto al partecipante: _"Così non devi telefonare alla mamma per dirle 'Mamma, mi sono perso'"_.
- **Animali (Animal-Computer Interaction):** per studiare quanta attenzione prestano i cani alla TV, si usano osservazioni e sistemi di tracciamento che registrano quando il cane gira la testa, interpretando i dati con esperti di comportamento animale.

### Il dilemma: "Quello che dicono vs Quello che fanno"
Le persone spesso non fanno ciò che dicono: dimenticano i fatti, vogliono mettersi in buona luce o cercano di compiacere l'intervistatore.
- _Esempio dello studio sulle scale (Rogers et al., 2010):_ In un edificio di uffici sono state installate luci lampeggianti nel pavimento per invogliare le persone a prendere le scale invece dell'ascensore. Nelle interviste i lavoratori giuravano di non aver cambiato abitudini, ma i dati oggettivi dimostravano che prendevano le scale molto più spesso! Per evitare questa distorsione bisogna formulare bene le domande, intervistare tante persone o combinare più tecniche (es. affiancare l'osservazione).

### Regole per formulare le domande e condurre l'intervista
Quando si scrivono le domande bisogna evitare tre errori classici:
1. **Evitare domande lunghe o composte:** _"Le piace questa app rispetto a quelle usate in precedenza?"_ confonde l'utente. Va divisa in tre: 1) _"Le piace questa app?"_, 2) _"Ha usato altre app simili in passato?"_, 3) _"Le sono piaciute?"_.
2. **Evitare il gergo tecnico:** usare un linguaggio semplice per non mettere in imbarazzo l'utente.
3. **Evitare domande o atteggiamenti tendenziosi (non neutri):** chiedere _"Perché le piace questo uso del colore?"_ (o sorridere/accigliarsi) dà per scontato che all'utente piaccia e lo spinge ad assecondare l'intervistatore.

**Le 5 fasi per condurre un'intervista:**
1. **Introduzione:** presentarsi, spiegare lo scopo, rassicurare sull'etica/privacy e chiedere il permesso di registrare (deve essere identica per tutti).
2. **Riscaldamento:** domande facili e demografiche (es. _"In che zona vive?"_) per sciogliere la tensione.
3. **Parte principale:** domande disposte in sequenza logica, lasciando quelle più complesse e profonde alla fine.
4. **Raffreddamento:** poche domande semplici per eliminare ogni eventuale tensione accumulata.
5. **Conclusione:** ringraziare, **spegnere visibilmente il registratore** o chiudere il blocco appunti per segnalare che l'intervista è finita.

**Varianti e arricchimenti:**
- **Interviste da remoto (Skype, Zoom, telefono):** l'utente è a casa sua, è più rilassato, non deve viaggiare o vestirsi bene, può restare anonimo su temi delicati e può chiudere la chiamata quando vuole. Di contro, è facile che si distragga facendo altro e l'intervistatore non vede il linguaggio del corpo.
- **Interviste retrospettive (_member checking_):** fatte subito dopo un'osservazione per verificare col partecipante di aver capito bene cosa è successo.
- **Arricchire l'intervista:** poiché le stanze d'intervista sono ambienti neutri e artificiali, conviene portare oggetti reali, prototipi, scenari o appendere al muro dei profili **Persona** (es. i poster dei profili di "Leonard" e "Monica") per stimolare la discussione su basi concrete. Un altro metodo (Mancini et al., 2009) consiste nell'inviare un mini-questionario sullo smartphone nel momento esatto in cui avviene un evento, per poi fare un'intervista basata su quelle risposte.

## 6. I Questionari

I questionari permettono di raccogliere dati demografici e opinioni da un numero enorme di persone, anche distanti, senza che il ricercatore sia presente.
- **Quando usare un questionario vs un'intervista strutturata?** Le domande sono molto simili, ma cambia la **motivazione**. Se l'utente è molto motivato a rispondere da solo, va bene il questionario; se invece ha fretta (es. pendolari in una stazione ferroviaria o manager tra una riunione e l'altra) e serve un po' di persuasione, è meglio fermarli con un'intervista strutturata veloce.
### Struttura e progettazione di un questionario

Poiché non c'è nessuno a chiarire i dubbi, le domande devono essere chiarissime, specifiche e possibilmente chiuse (includendo sempre opzioni come _"nessuna opinione"_ o _"nessuna di queste"_). Bisogna fare attenzione alle formulazioni negative che confondono, anche se a volte si alternano domande positive e negative di proposito per verificare che l'utente stia leggendo con attenzione.
- Si inizia con **domande demografiche e di esperienza** (età, ore passate su Internet), ma **solo se pertinenti** per contestualizzare le risposte: chiedere l'altezza di una persona è inutile per uno studio sui siti web, ma diventa fondamentale se si progettano dispositivi indossabili!
- Bisogna curare l'ordine delle domande, l'impaginazione (equilibrio tra spazi bianchi e compattezza) e permettere agli utenti di salvare o abbandonare i questionari lunghi a metà (meglio avere risposte parziali a qualche sezione che perdere tutto).

### Formati di risposta e Scale di valutazione
1. **Caselle di spunta e Intervalli:** usati per dati prevedibili come l'età (molti non amano dire l'età esatta). Gli intervalli non devono per forza essere tutti della stessa ampiezza (per un sito di assicurazioni sulla vita bastano 3 fasce: _<21, 21-65, >65_; per uno studio sulle idee politiche tra generazioni servono fasce di 10 anni: _21-30, 31-40_, ecc.)
    - **Errore grave da evitare:** non sovrapporre mai gli intervalli! Scrivere `1-3 ore` e `3-5 ore` manda in crisi chi passa esattamente 3 ore online. Gli intervalli corretti sono `15-19` e `20-24`.
    - (Altri errori classici nei questionari mal progettati: chiedere l'età precisa con un quadratino minuscolo, non specificare quante caselle si possono barrare in un elenco e lasciare uno spazio minuscolo di due righe per una domanda aperta).
2. **Scale Likert:** misurano opinioni e soddisfazione chiedendo quanto si è d'accordo con un'affermazione (es. _"L'uso del colore è eccellente"_) tramite parole (_Molto d'accordo / D'accordo / OK / In disaccordo / Molto in disaccordo_) o numeri (da 1 a 5). Non importa se il numero 1 indica il massimo (come il 1° classificato in gara) o il minimo, l'importante è mantenerlo coerente in tutto il questionario. Sono le più usate perché è facile scrivere affermazioni chiare per tutti.
3. **Scale del differenziale semantico:** usano coppie di aggettivi opposti (bipolari) posti agli estremi di una linea (es. _Attraente — Sgradevole_, _Chiaro — Confuso_, _Utile — Inutile_), spesso mescolando i lati positivi e negativi. L'utente segna un punto nello spazio tra i due poli.

**Quanti punti deve avere una scala?**
- Se il compito di valutazione è difficile, le persone tendono a non sbilanciarsi scegliendo i valori centrali. Usare un **numero dispari** (3, 5, 7) offre un punto neutro centrale ("OK" o "Non so"), mentre un **numero pari** costringe l'utente a schierarsi.
- **3 punti:** per scelte limitate (_Sì / Non so / No_).
- **5 punti:** ideale per giudizi del tipo _mi piace/non mi piace_ o _d'accordo/in disaccordo_.
- **7 o 9 punti:** per giudizi molto sfumati, come valutare il "grado di fascino" del personaggio di un videogioco (_molto attraente ... ok ... scostante_).

### Questionari Online vs Cartacei
Nei grandi sondaggi, ottenere un tasso di ritorno del **40%** è già considerato un buon risultato (mentre con piccoli gruppi sotto i 20 utenti si arriva quasi al 100%).
- **Vantaggi dell'Online:** costo-efficacia 10 volte migliore rispetto alla carta; validazione immediata dei dati (impedisce di inserire numeri fuori range); caricamento automatico in database; possibilità di **segmentazione e salto automatico** (es. nel questionario di una compagnia aerea, se dichiari di non aver imbarcato bagagli o non aver usato la sala d'aspetto, il sistema salta automaticamente quelle sezioni senza irritarti).
- **Differenze nelle risposte tra Carta e Web:** gli studi dimostrano che al computer le persone sono più schiette e sincere su abitudini private (cibo, alcol, sport) e gli studenti giudicano più severamente i professori. Inoltre, nei questionari online ci sono meno domande lasciate in bianco e nelle domande aperte le persone scrivono risposte più dettagliate e più lunghe (in media 63 caratteri in più rispetto alla carta!). Anche i componenti grafici cambiano le risposte: i menu a discesa e i cursori continui aumentano il tasso di risposta e la precisione rispetto agli spazi vuoti su carta.
- **I 5 passi per creare un questionario online:** 1) Pianificare le tempistiche a ritroso dalla scadenza; 2) Progettarlo prima offline in puro testo; 3) Programmarlo online (con le logiche di navigazione); 4) Fare un **test / studio pilota** con esperti e utenti; 5) Reclutare i partecipanti con inviti brevi, amichevoli e stuzzicanti.

## 7. L'Osservazione
Alle persone riesce difficile spiegare a parole tutti i dettagli di ciò che fanno: l'osservazione permette di vedere come si comportano davvero. Può avvenire in due ambienti:
1. **Osservazione sul campo (contesto naturale):** si osservano le persone nella loro vita quotidiana.
2. **Osservazione in ambiente controllato (es. laboratorio di usabilità):** si osservano le persone mentre eseguono compiti specifici assegnati dal ricercatore.

_Esempio di confronto (Test di un navigatore da polso per turisti):_
- _Scenario 1 (Sul campo a Stoccolma):_ Il consulente gira per Stoccolma insieme ai turisti mentre usano l'orologio per cercare e prenotare un ristorante nel raggio di 2 km. **Pro:** si vede l'uso reale in movimento e si coglie l'entusiasmo finale del gruppo nel trovare un buon ristorante. **Contro:** l'osservatore fa parte del gruppo e si diverte, quindi perde obiettività; inoltre le condizioni esatte di quella giornata non sono replicabili.
- _Scenario 2 (In laboratorio):_ Gli utenti devono usare l'orologio in una stanza per trovare il numero del ristorante "Matisse". **Pro:** l'osservatore è esterno e obiettivo; l'esperimento è replicabile; si calcolano medie precise su tempi ed errori diagnosticando subito i difetti dei pulsanti e dell'audio. **Contro:** è una situazione finta e artificiale (trovare un numero in laboratorio non dà la stessa gratificazione di una vera cena!).

### Quadri di riferimento per osservare sul campo
Nella realtà succedono troppe cose contemporaneamente: osservare un gruppo chiedendosi genericamente _"Che cosa fanno queste persone?"_ porta solo a frustrazione e confusione. Per mantenere il focus servono dei **quadri di riferimento (framework)**:
- **Quadro semplice (3 elementi):**
    1. _La persona:_ chi usa la tecnologia in quel momento?
    2. _Il luogo:_ dove viene usata?
    3. _La cosa:_ cosa ci fanno?
- **Quadro dettagliato di Robson e McCartan (9 elementi):**
    1. _Spazio:_ com'è configurato l'ambiente fisico?
    2. _Attori:_ chi sono le persone coinvolte?
    3. _Attività:_ cosa fanno e perché?
    4. _Oggetti:_ quali altri oggetti fisici sono presenti oltre alla tecnologia studiata e che impatto hanno su di essa?
    5. _Atti:_ quali sono le singole azioni specifiche?
    6. _Eventi:_ fa parte di un evento speciale?
    7. _Tempo:_ qual è la sequenza temporale?
    8. _Obiettivi:_ cosa cercano di ottenere gli attori?
    9. _Stati d'animo:_ qual è l'umore dei singoli e del gruppo (frustrati, felici, seri)?

### Il Grado di Partecipazione dell'Osservatore
L'osservatore può posizionarsi lungo uno spettro che va da "esterno" a "interno":
- **Osservatore passivo (Esterno):** non interagisce in alcun modo con l'ambiente. È perfetto in laboratorio, ma quasi impossibile da mantenere sul campo.
- **Osservatore partecipante (Interno):** diventa un membro del gruppo che sta studiando. È un ruolo difficile perché richiede di partecipare attivamente ma, allo stesso tempo, mantenere il distacco necessario per prendere appunti oggettivi. Inoltre non è sempre possibile: se si studia l'ambiente privato di una famiglia o un lavoro altamente specializzato, un estraneo non può inserirsi facilmente.  
    - _Soluzione ibrida (Studio sulle conversazioni in auto tra genitori e figli, Cycil et al., 2013):_ I ricercatori hanno viaggiato in auto con le famiglie per la prima settimana per capire le dinamiche e farsi conoscere, dopodiché hanno lasciato che fossero i familiari stessi a videoregistrare gli episodi nei giorni successivi.

### Conduzione, Lavoro in Team e Conclusione dell'Osservazione
Per condurre bene un'osservazione sul campo è ottimo **lavorare in team**: permette di osservare persone e zone diverse contemporaneamente, confrontare gli appunti ottenendo dati più affidabili e avere prospettive diverse. Durante l'osservazione bisogna sforzarsi di prestare la stessa attenzione a tutti (non solo alle persone più simpatiche con cui si entra subito in confidenza).

**Regola di fine giornata:** L'osservazione è stancante, ma **alla fine di ogni singola giornata** è obbligatorio rivedere subito gli appunti e le registrazioni (magari tenendo un diario o un blog privato), separando nettamente le _osservazioni oggettive_ dalle _opinioni personali_. Se non lo si fa subito, gli eventi del giorno dopo cancelleranno i ricordi del giorno precedente.

**Quando smettere di osservare?** Se non c'è una scadenza fissa di calendario, ci si ferma quando non emerge più nulla di nuovo, ovvero quando si iniziano a vedere **schemi di comportamento che si ripetono** e si sono ormai compresi i punti di vista di tutti i gruppi principali.