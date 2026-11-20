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

