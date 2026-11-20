Nel mondo delle usabilità le indicazioni progettuali si distinguono in due categorie:
- **Generalità**: indicazioni applicabili quasi in ogni situazione
- **Coercitività**: indicazioni seguite a discrezione del progettista e che sono obbligatorie

Dall'unione di queste due nascono quattro tipologie:
![[Pasted image 20261120152749.png]]
- **Principi**: sono basati su enunciati scientifici e su evidenze certe
- **Linee guida**: sono raccomandazioni particolari, più concreti degli standard con dimostrazioni ed esempi annesse
- **Standard**: insieme di regole da applicare nel progetto
- **Regole di progetto**: regole per un particolare sistema

Tra gli ISO principali, figurano **ISO 13407** (processi di progettazione centrata sull'uomo), **ISO 9241** (requisiti ergonomici per il lavoro d'ufficio con terminali a schermo, suddivisa in numerose parti come la _Part 11_ sull'usabilità e la _Part 110_ sui principi del dialogo) e **ISO 14915** (ergonomia del software per interfacce multimediali). La **ISO 9241-110** è rivolta ad analisti dei requisiti, progettisti di strumenti e guide di stile, sviluppatori, valutatori e acquirenti.

## I sette principi del dialogo
Secondo la norma ISO 9241-110 ci sono sette principi di raccomandazione con annesse pratiche per differenziare le **buone pratiche** e gli **errori da evitare**.

### Adeguatezza al compito
>[!NOTES] Secondo la definizione:
Un sistema è adeguato al compito quando supporta l'utente in modo efficace ed efficiente, permettendogli di concentrarsi sull'obiettivo e non sullo strumento.

Delle raccomandazioni che è importante adottare nell'adeguatezza del compito è l'**automatizzazione di tutto ciò che è possibile**, scegliere quindi un ottimo strumento, un ottimo dispositivo e formati di input adatti.

Per esempio una buona pratica sarebbe mostrare subito in un'unica vista gli orari di partenza e arrivo dei treni, con le specifiche informazioni sotto-stanti, dalle più rilevanti alle più particolari. Per un biglietto digitale, ad esempio, è fondamentale non inserire visivamente dei `Code error` poiché non spiegano nulla all'utente e soffocano lo schermo.
Infatti **troppi elementi a schermo che si sovrappongono** non aiutano l'utente ad avere una vista libera del contenuto principale, portandolo a confusione o chiudere l'app.
![[Pasted image 20261120154207.png]]
### Autodescrizione
**Un dialogo è autodescrittivo** quando l'utente riesce sempre a capire nell'applicazione dove si trova, cosa può eseguire e come muoversi. In questo modo si riduce il **golfo dell'esecuzione** e il **golfo della valutazione**.
Queste raccomandazioni racchiudono le guide all'utente, interazione e descrizioni di input e formati.
![[Pasted image 20261120155334.png]]
Un testo grigio piatto non comunica in modo chiaro quanto una forma con riempimento e contrasto evidente.

Da questo si evince che bisogna **evitare** le scritte che rendono le funzioni poco chiare che non funzionano sui dispositivi touch. 
### Conformità alle aspettative dell'utente
Il dialogo rispetta le aspettative quando è coerente con il contesto, il linguaggio familiare e le convenzioni culturali e d'uso consolidatesi nel tempo.

Nelle interfacce in lingue right-to-left (arabo o ebraico), il layout deve rispecchiare correttamente le convenzioni culturali.
Gli elementi devono essere posizionati in punti ben precisi e strategici, prendiamo ad esempio un sito di e-commerce:
- logo in alto a sinistra per tornare alla home
- ricerca in alto
- account e carrello in alto a destra
- informazioni legali e contatti nel footer

Il menù deve essere chiaro sin da subito, se le pagine si trasformano durante la navigazione o non sono alle posizioni aspettate / precedentemente cliccate le pagine potrebbero **disorientare l'utente**.
Una buona pratica con i **design system** è condividere intestazione, menu, pulsanti, card, moduli e footer tra siti della Pubblica Amministrazione (Comuni, scuole, enti) così da permettere di riutilizzare ciò che si è già appreso.

E' importante a livello grafico gestire **l'attesa dei caricamenti** così da far notare all'utente che il sito/app sta caricando per lui e non che sia ferma.
![[Pasted image 20261120162816.png]]
Sul piano temporale, risposte $\le 0{,}1\text{ s}$ appaiono immediate, tra $0{,}1\text{ s}$ e $1\text{ s}$ non spezzano la continuità del compito, fino a $10\text{ s}$ mantengono l'attenzione focalizzata, mentre oltre $10\text{ s}$ richiedono un feedback di avanzamento.

Importante è anche gestire i messaggi e la loro **posizione**, poiché collocare feedback e campi attivi vicino al punto di attenzione dell'utente evita che possano passare inosservati.
### Adeguatezza all'apprendimento

>[!NOTES] Secondo la definizione:
>Un dialogo è adeguato all'apprendimento se supporta e guida l'utente nell'apprendimento del sistema

![[Pasted image 20261120163847.png]]
Guardando l'esempio di *Wordle* notiamo come le regole essenziali sono mostrati subito a schermo. Anche la fotocamera segue questo tipo di meccanismo, mostrando in Pro le effettive funzionalità che l'utente di base non guarderebbe, per questo in primo piano mostra *Video* e *Fotocamera*.

![[Pasted image 20261120164106.png]]
I **feedback intermedi** e la **familiarizzazione alle novità** aiutano molto a capire subito come funziona il prodotto che sta usando l'utente, guidandolo ad un apprendimento facilitato.
Di fatto, l'esempio mostrato fa vedere come si sta susseguendo lo stato di ciò che l'utente deve eseguire, mostrandogli **piccoli traguardi** (questa stessa logica funziona anche con le app di tracciamento di una spedizione, mostrando i vari step dell'ordine in arrivo).
### Controllabilità
>[!NOTE] Secondo la definzione:
>Un dialogo è controllabile se l’utente è in grado di iniziare e tenere sotto controllo la
direzione e i tempi dell’interazione fino al raggiungimento dell’obbiettivo

Un esempio di quando usare questo principio è nello streaming multimediale, chiamato **Punto di ripartenza controllato**, nello streaming si riprende da dove ci si era fermati ma si può ricominciare da qualsiasi punto.
### Tolleranza verso gli errori
Permette di raggiungere il risultato desiderato nonostante errori di input, con poche o nulle azioni correttive, attraverso controllo dei danni, correzione o gestione degli errori (con raccomandazioni quali prevenzione di azioni non lecite, spiegazione, recupero, correzioni automatiche, convalida dati, minimo sforzo e richieste di conferma).
### Adeguatezza alla individualizzazione
>[!NOTE] Secondo la definzione:
>Un dialogo è adeguato alla individualizzazione se l’utente può modificare l’interazione e la presentazione dell’informazione per adattarle alle proprie necessità e capacità individuali

Susseguono vari esempi per comprenderli al meglio:
- **_Rappresentazioni alternative_:** passaggio tra vista a elenco e a griglia o tra tema chiaro e tema scuro senza alterare il contenuto.
    
- **_Vocabolario personalizzabile_**: sostituzione del testo/abbreviazioni sulla tastiera o nomi personalizzati per dispositivi smart home riconosciuti dall'assistente vocale.
    
- **_Metodo d'interazione_**: inserimento di una data tramite digitazione, calendario o dettatura vocale.
    
- **_Scorciatoie, accessibilità e centro di controllo_**: personalizzazione delle scorciatoie da tastiera con controllo conflitti e ripristino; impostazioni di sistema per l'accessibilità (dimensione e grassetto del testo, riduzione movimento, pulsante mouse per mancini, contrasto); configurazione dei comandi rapidi nel centro di controllo dello smartphone con possibilità di tornare ai valori predefiniti.
  ![[Pasted image 20261120165241.png]]
## Le 10 euristiche di Nielsen
Ogni principio di Nielsen viene accostato ai sette principi del dialogo della ISO 9241, così da notare come approcci diversi converggano sugli stessi pilastri dell'usabilità:
1. **Visibilità dello stato del sistema**: informare l'utente di ciò che sta accadendo tramite feedback.
2. **Allineamento tra il mondo del sistema e quello dell'utente**: usare parole familiari all'utente.
3. **Design estetico e minimalista**: le informazioni mostrate devono seguire un ordine naturale e logico.
4. **Coerenza e standard**: parole e azioni devono mantenere lo stesso significato.
5. **Riconoscimento rispetto alla memorizzazione**: le istruzione d'uso devono sempre esser facilmente recuperabili quando servono.
6. **Controllo da parte dell'utente e sua libertà**: shalom loro controllano tutto
7. **Flessibilità e efficienza d'uso**: l'esperienza dev'essere velocizzabile per gli utenti esperti e non basarsi sui tasti lenti di quelli medi.
8. **Aiutare l'utente nel riconoscere, diagnosticare e rimediare dagli errori**: i messaggi di errori vanno espressi in linguaggio semplice, indicando semplicemente il problema
9. **Prevenzione degli errori**: una progettazione accurata deve impedire che gli errori si verifichino in primo luogo.
10. **Aiuto e documentazione**: le informazioni di supporto devono essere facili da reperire.

Il confronto tra i due è che la **ISO 9241-110** raggruppa le qualità del dialogo in sette macro-principi normativi articolati in raccomandazioni dettagliate, e le **euristiche di Nielsen** offrono una lista sintetica e molto operativa (particolarmente usata anche per le ispezioni euristiche) che incrocia gli stessi aspetti sotto angolazioni leggermente diverse.

![[Pasted image 20261120170001.png]]
#### Altri principi
Altri **principi di usabilità** possono essere:
- Le 8 regole d'oro di Shneiderman
- Principi di design di Norman
- Principi sull'usabilità funzionale nei requisiti Euristo et al. 2007

Altre **linee guida e design system** possono essere:
- Material Design 3 di Google
- Human Interface Guidelines di Apple
- Fluent 2 di Microsoft
- Designers Italia per i servizi di Pubblica Amministrazione