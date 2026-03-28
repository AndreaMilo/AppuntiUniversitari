**Qui informazioni maggiori per chiarire alcuni concetti riportati da internet o dalle IA**:
## [Terza forma normale PAG 51- 57](obsidian://open?vault=UNI&file=Backup%20(fisso%20Onedrive)%2FSecondo%20anno%2Fprimo%20trimestre%2FBasi%20di%20Dati%2FPDF%2F5%20-%20Progettazione%20di%20Basi%20di%20Dati.pdf) 
Ecco una spiegazione dettagliata e "tradotta" in linguaggio semplice della sezione sulla **Terza Forma Normale (3NF)** (pagine 51-57 del file _5 - Progettazione di Basi di Dati_), con riferimento specifico all'esempio discusso nel testo a pagina 57.

---

### 1. Il Concetto Base: La "Dipendenza Transitiva" (Pag. 51-53)

Per capire la Terza Forma Normale, devi immaginare una catena di informazioni.

Il problema che la 3NF vuole risolvere è la **Dipendenza Transitiva**.

**Cosa dice il testo (concettualmente):**

Una tabella è "sporca" (non normalizzata) se contiene informazioni che non dipendono direttamente dalla chiave primaria, ma dipendono da un altro attributo che sta in mezzo.

**L'Esempio logico (per capire la teoria):**

Immagina una tabella `STUDENTE` con questi campi:

- `Matricola` (Chiave)
    
- `Comune_Residenza`
    
- `Provincia_Residenza`
    

Qui c'è un problema:

1. La `Matricola` determina il `Comune` (Se so chi sei, so dove vivi).
    
2. Il `Comune` determina la `Provincia` (Se so che vivi a "Milano", so che la provincia è "MI").
    

Quindi: `Matricola` $\to$ `Comune` $\to$ `Provincia`.

La Provincia dipende dalla Matricola non direttamente, ma **transitivamente** (attraverso il Comune).

La 3NF ti dice: **"Spezza questa catena! Ogni attributo deve dipendere SOLO dalla chiave, nient'altro."**

---

### 2. La Definizione Formale (Pag. 54-55)

Nelle pagine centrali, il testo introduce la regola matematica per verificare se sei in 3NF.

Una relazione è in 3NF se, per ogni dipendenza funzionale $X \to Y$ (non banale), vale **almeno una** di queste due condizioni:

1. **X è una Superchiave:** Cioè chi "comanda" (chi sta a sinistra della freccia) è la chiave della tabella. (Questa è la situazione ideale).
    
2. **Y è un attributo primo:** Cioè l'attributo che viene determinato fa parte di una chiave candidata (è un'eccezione tecnica che serve in casi rari).
    

Se trovi una dipendenza dove **X NON è una chiave** e sta determinando un altro attributo che non c'entra con la chiave, allora **violi la 3NF**.

**La Soluzione (Decomposizione):**

Se trovi questo difetto, devi **decomporre** (spezzare) la tabella in due:

1. Una tabella con la dipendenza "colpevole" (es. `COMUNI(Comune, Provincia)`).
    
2. La tabella originale senza l'attributo dipendente (es. `STUDENTI(Matricola, Comune)`).
    

---

### 3. L'Esempio Complesso: L'Associazione "TESI" (Pag. 57)

A pagina 57, il testo fa un esempio molto interessante perché mostra un caso "limite" dove la teoria matematica incontra la logica del buon senso.

#### Lo Scenario (Immagine a metà pag. 57)

Abbiamo un'associazione ternaria (un rombo che collega tre entità) chiamata **TESI**.

Collega:

- `STUDENTE`
    
- `PROFESSORE`
    
- `CORSO DI LAUREA`
    
#### Le Dipendenze Funzionali

Il testo elenca queste regole (dipendenze):

1. `STUDENTE` $\to$ `PROFESSORE` (Uno studente ha un solo relatore per la tesi).
    
2. `STUDENTE` $\to$ `CORSO DI LAUREA` (Uno studente è iscritto a un solo corso di laurea).
    
#### Perché è tecnicamente in 3NF?

Il testo dice: _"L'associazione TESI è in terza forma normale"_.

Perché?

- La chiave di questa relazione è **STUDENTE** (perché ogni studente fa una sola tesi, quindi basta la matricola per identificare la riga).
    
- Le dipendenze hanno `STUDENTE` a sinistra della freccia ($X$).
    
- Essendo `STUDENTE` la chiave, la condizione "X è una superchiave" è rispettata.
    
- **Conclusione Matematica:** La tabella è in 3NF. Nessuna regola formale è violata.
    
#### Il Problema "Nascosto" (Analisi critica)

Nonostante sia in 3NF, il testo dice che c'è comunque qualcosa che non va:

> _"tuttavia le proprietà descritte dalle due dipendenze sono fra loro indipendenti"_.

Cosa significa?

Significa che stiamo mescolando due concetti che non c'entrano nulla l'uno con l'altro:

1. Il fatto che lo studente sia iscritto a un Corso di Laurea (succede appena ti iscrivi).
    
2. Il fatto che lo studente abbia un Professore per la tesi (succede solo alla fine).
    

Se teniamo tutto in un'unica tabella `TESI`:

- Non potremmo inserire uno studente appena iscritto (che ha il Corso di Laurea) perché non ha ancora il Professore (valore NULL).
    
- Se lo studente cambia relatore, sembra che stiamo toccando anche i dati del suo corso di laurea.
    
#### La Soluzione Finale (Decomposizione a pag. 57)

Il testo suggerisce di **decomporre ulteriormente** anche se siamo già in 3NF, per pulizia logica.

Si spezza l'associazione `TESI` in due associazioni separate (vedi figura in basso a pag. 57):

1. **AFFERENZA:** Collega `PROFESSORE` e `DIPARTIMENTO` (o Studente e Professore).
    
2. **ISCRIZIONE:** Collega `STUDENTE` e `CORSO DI LAUREA`.
    
**Morale della sezione:**
La Terza Forma Normale è un ottimo strumento matematico per pulire i dati dalle dipendenze a catena, ma il progettista deve sempre usare la testa: se due informazioni sono concettualmente indipendenti (come iscriversi all'università vs. chiedere la tesi), conviene separarle in due tabelle diverse.

## [BCNF normale Pag 45 - 47 ](obsidian://open?vault=UNI&file=Backup%20(fisso%20Onedrive)%2FSecondo%20anno%2Fprimo%20trimestre%2FBasi%20di%20Dati%2FPDF%2F5%20-%20Progettazione%20di%20Basi%20di%20Dati.pdf)
Ecco la "traduzione" passo-passo di quei concetti e formule:
### 1. Dipendenze Funzionali (La Formalizzazione)

La formula che vedi spesso è scritta come:

$$X \to Y$$

Si legge: _"X determina funzionalmente Y"_.

**Cosa significa in pratica?**

Significa che se conosci il valore di **X**, conosci automaticamente e con certezza il valore di **Y**. Non c'è ambiguità.

- _Esempio:_ `CodiceFiscale` $\to$ `Cognome`.
    
    Se io ho il tuo Codice Fiscale, c'è un solo Cognome possibile associato. Quindi il CF _determina_ il Cognome.
    
- _Contro-esempio:_ `Cognome` $\to$ `Nome`.
    
    Se so che ti chiami "Rossi", non so con certezza se ti chiami Mario o Luca. Quindi questa **non** è una dipendenza funzionale valida.
    

**Le "Osservazioni"** (spesso proprietà come la _riflessività_ o l'_aumento_) dicono banalità logiche, tipo: "Se conosco Tutto ($X,Y$), allora conosco una parte ($X$)" (Dipendenza Banale).

---

### 2. BCNF (Forma Normale di Boyce-Codd)

Questa è la regola d'oro per dire se una tabella è "fatta bene" o se creerà problemi.

**La definizione matematica:**

Una relazione $r$ è in BCNF se, per ogni dipendenza funzionale (non banale) $X \to Y$, **X è una superchiave**.

**Cosa significa in pratica?**

Vuol dire che **chi comanda (chi sta a sinistra della freccia) deve essere un "capo" (una Chiave)**.

In una tabella ben fatta, gli unici attributi che possono determinare il valore degli altri sono le Chiavi Primarie (o candidate).

Se un attributo "semplice" (non chiave) si mette a comandare e a determinare altri attributi, **la tabella non è in BCNF** e va sistemata.

- _Esempio di Errore (Non BCNF):_
    
    Immagina una tabella `ESAME(Matricola, CodiceCorso, Docente)`.
    
    - La chiave è la coppia `Matricola + CodiceCorso`.
        
    - Però scopri che c'è una regola: `Docente` $\to$ `CodiceCorso` (Ogni docente insegna una sola materia).
        
    - Qui `Docente` **non è chiave** (la chiave include la matricola!), ma sta determinando `CodiceCorso`.
        
    - **Verdetto:** Violazione della BCNF. Il `Docente` sta "comandando" senza essere un capo.
        

---

### 3. Decomposizione in BCNF (Come si risolve)

Quando trovi una violazione (come quella del Docente sopra), devi "decomporre", cioè spezzare la tabella in due.

**La procedura logica:**

1. Prendi la dipendenza "cattiva" che viola la regola: $X \to Y$ (dove X non è chiave).
    
2. Crei una **Nuova Tabella** con dentro solo loro due ($X$ e $Y$). Qui $X$ diventa la chiave.
    
3. Nella **Tabella Originale**, togli la colonna $Y$ (la parte destra della dipendenza), ma lasci $X$ come "collegamento".
    

**Esempio pratico (Decomposizione):**

Riprendiamo `ESAME(Matricola, CodiceCorso, Docente)` con la dipendenza cattiva `Docente` $\to$ `CodiceCorso`.

1. Isolo il problema: Creo la tabella `CORSI(Docente, CodiceCorso)`. Qui `Docente` è chiave.
    
2. Pulisco l'originale: Dalla tabella `ESAME` tolgo `CodiceCorso`. Rimane `ESAME(Matricola, Docente)`.
    
Ora hai due tabelle pulite e in BCNF. Non hai perso informazioni (puoi sempre risalire al corso tramite il docente) e hai eliminato la ridondanza.

**In sintesi per andare avanti:**

Ogni volta che vedi quelle formule, chiediti solo: _"Chi sta a sinistra della freccia è una Chiave?"_
- Se **SÌ** $\to$ Tutto ok, vai avanti.
- Se **NO** $\to$ C'è un problema, devi spezzare la tabella mettendo quella dipendenza in una tabella tutta sua.

## Architettura e metodologia delle basi di dati Mappa concettuale
![[NotebookLM Mind Map (1).png]]
A seguito il link per visualizzare meglio e in maniera originale la [mappa memonica](https://notebooklm.google.com/notebook/9a84ae8f-40ef-402b-98c2-0bc379808559) / [Sito generale](https://notebooklm.google.com/notebook/9a84ae8f-40ef-402b-98c2-0bc379808559)

## Diagnosi della normalizzazione
Prima di tutto, una precisazione importante basata sui tuoi documenti: **La normalizzazione si applica alle Tabelle (Schema Logico), non direttamente al disegno E-R.** Tuttavia, se hai disegnato bene l'E-R (usando la metodologia corretta), le tue tabelle saranno quasi sempre già normalizzate.

La verifica serve a trovare "errori" sfuggiti. Ecco la guida pratica per capire a colpo d'occhio in che forma sei e quale usare.

---

### Quale forma usare? (Il "Gold Standard")

L'obiettivo all'esame e nella realtà è arrivare alla **BCNF (Forma Normale di Boyce-Codd)**.

Se non è possibile raggiungere la BCNF (casi rari), ci si accontenta della **3NF**.

- **1NF e 2NF** sono considerate "di passaggio": se ti fermi lì, il database è fatto male.
    

---

### Come capire in che forma sei (La Checklist)

Devi procedere a gradini. Non puoi essere in 3NF se non sei prima in 2NF.

#### 1. Prima Forma Normale (1NF) - "Niente Liste"

**Come notarlo:**

Guarda una singola cella della tua tabella. C'è scritta più di una cosa? C'è una lista separata da virgole?

- _Esempio:_ Nella colonna `Telefono` c'è scritto "333123456, 06123456".
    
- _Diagnosi:_ **NON è in 1NF**.
    
- _Soluzione:_ Devi avere un solo valore per cella (valori atomici). Nel modello E-R, questo errore nasce se hai lasciato un **attributo multivalore** (doppio cerchio) senza trasformarlo in una nuova tabella.
    

#### 2. Seconda Forma Normale (2NF) - "Tutta la Chiave"

**Quando controllarla:** Solo se la tua tabella ha una **Chiave Primaria Composta** (fatta da 2 o più colonne). Se la chiave è una sola colonna (es. `Matricola`), sei **automaticamente** in 2NF.

**Come notarlo:**

Chiediti: _"C'è qualche colonna che dipende solo da UNA PARTE della chiave e non da tutta?"_

- _Esempio:_ Tabella `VOTI_ESAME(Matricola, CodiceMateria, Voto, NomeMateria)`.
    
    - Chiave: `Matricola` + `CodiceMateria`.
        
    - `Voto` dipende da entrambi (mi serve sapere chi e in che materia).
        
    - `NomeMateria` dipende **solo** da `CodiceMateria`. Non gli interessa la `Matricola`.
        
- _Diagnosi:_ Violazione della 2NF (Dipendenza Parziale).
    
- _Soluzione:_ Sposta `NomeMateria` in una tabella `MATERIE` separata.
    

#### 3. Terza Forma Normale (3NF) - "Niente Passaparola"

**Quando controllarla:** Sempre. È l'errore più comune.

**Come notarlo:** Cerca una "catena" di dipendenze (Dipendenza Transitiva). Un attributo non chiave determina un altro attributo non chiave.

- _Esempio:_ Tabella `STUDENTE(Matricola, Comune, Provincia)`.
    
    - `Matricola` (Chiave) $\to$ `Comune`.
        
    - `Comune` (Non Chiave) $\to$ `Provincia`.
        
    - La Provincia dipende dalla Matricola solo "perché passa" dal Comune.
        
- _Diagnosi:_ Violazione della 3NF.
    
- _Soluzione:_ Crea una tabella `COMUNI(Comune, Provincia)`e togli la Y da `STUDENTI`.
    

#### 4. BCNF (Boyce-Codd) - "Il Capo è solo la Chiave"

Questa è la versione più severa della 3NF.

**Come notarlo:** La regola è semplice: **"Chiunque stia a sinistra di una freccia ($\to$) DEVE essere una Chiave (o Superchiave)"**. Se trovi una dipendenza funzionale $X \to Y$ dove $X$ **NON è una chiave**, hai violato la BCNF.

- _Esempio Tricky:_ `LEZIONI(Studente, Corso, Docente)`.
    
    - Regola: Un docente insegna una sola materia (`Docente` $\to$ `Corso`).
        
    - Chiave della tabella: `Studente` + `Corso` (perché uno studente segue tanti corsi).
        
    - **L'Errore:** C'è la regola `Docente` $\to$ `Corso`. Ma `Docente` non è chiave! Sta comandando il `Corso` senza avere i gradi per farlo.
        
- _Diagnosi:_ È in 3NF (sottigliezza tecnica), ma **NON è in BCNF**.
    
- _Soluzione:_ Decomporre.
    

---

### Riassunto per l'Esame

Quando guardi le tue tabelle finali:

1. **Vedi liste nelle celle?** $\to$ Correggi subito (1NF).
    
2. **Hai chiavi composte?** $\to$ Controlla se gli altri campi dipendono da _tutta_ la chiave o solo un pezzo (2NF).
    
3. **Vedi dati ripetuti che dipendono l'uno dall'altro?** (es. Indirizzo dipende da Fornitore, che dipende da Prodotto) $\to$ Spezza la catena (3NF).
    
4. **Verifica BCNF:** Scrivi tutte le dipendenze funzionali ($X \to Y$). Se c'è una $X$ che non è chiave primaria, devi spezzare la tabella

### Capire le dipendenze funzionali
Scrivere le dipendenze funzionali è un esercizio di **logica** e di **lettura attenta della traccia**, non di calcoli matematici. Devi tradurre le "regole del business" (i requisiti) in formule del tipo $X \to Y$.

Ecco il metodo pratico in **3 passaggi** per trovarle e scriverle tutte, basato sulla teoria della progettazione.

---

#### 1. La Domanda Magica ("Il Test dell'Unicità")

Per ogni coppia di attributi (A e B) della tua tabella, fatti questa domanda:

> _"Se conosco il valore di A, esiste **UN SOLO** valore possibile per B?"_

- Se la risposta è **SÌ** $\to$ Scrivi **$A \to B$**.
    
- Se la risposta è **NO** (ce ne possono essere vari) $\to$ Non c'è dipendenza.
    

**Esempio:**

- _Conosco il Codice Fiscale. C'è un solo Cognome associato?_ **SÌ.** ($\text{CF} \to \text{Cognome}$)
    
- _Conosco il Cognome (es. Rossi). C'è un solo CF associato?_ **NO** (ci sono tanti Rossi). (Nessuna dipendenza).
    

---

#### 2. Procedura Passo-Passo per l'Esame

Prendi la tua tabella (o lo schema E-R) e segui questo ordine per non dimenticarne nessuna:

##### A. Scrivi le Dipendenze dalla Chiave (Quelle "Ovvie")

La Chiave Primaria (PK), per definizione, determina **tutti** gli altri attributi della tabella. Queste sono le prime da scrivere.

- _Tabella:_ `STUDENTE(Matricola, Nome, Cognome, DataNascita, Indirizzo)`
    
- _Dipendenza 1:_ $\text{Matricola} \to \text{Nome, Cognome, DataNascita, Indirizzo}$
    
    _(Nota: Puoi scriverle tutte insieme a destra)._
    

##### B. Cerca le Dipendenze "Nascoste" (Quelle "Cattive" per la 3NF)

Ora guarda gli attributi che **NON sono chiave**. Chiediti: _"Tra questi campi semplici, c'è qualcuno che comanda su un altro?"_

Cerca nel testo della traccia frasi come "ogni X ha un solo Y" o "Y dipende da X".

- _Esempio:_ Nella tabella c'è anche `CAP` e `Città`.
    
- _Analisi:_ Se conosco il `CAP` (es. 00100), conosco la `Città` (Roma)? Sì.
    
- _Dipendenza 2:_ $\text{CAP} \to \text{Città}$
    
    _(Questa è quella pericolosa che viola la 3NF perché il CAP non è la matricola!)_.
    

##### C. Cerca le Chiavi Candidate (Alternative)

A volte ci sono attributi univoci che non hai scelto come chiave primaria, ma che lo sono di fatto (es. Codice Fiscale, Partita IVA, Matricola Aziendale).

- _Dipendenza 3:_ $\text{CodiceFiscale} \to \text{Nome, Cognome, ...}$
    
    _(Anche il CF determina tutto, proprio come la Matricola)._
    

---

#### 3. Esempio Completo (Tratto dalla teoria)

Immaginiamo la tabella **VOTI_ESAME**:

`VOTI(Matricola, CodiceMateria, Voto, NomeMateria, CreditiMateria)`

**Passo 1: La Chiave**

La chiave è la coppia `Matricola + CodiceMateria`.

- **DF1:** $\text{Matricola, CodiceMateria} \to \text{Voto}$
    
    _(Se so chi sei e che esame hai fatto, so che voto hai preso)._
    

**Passo 2: Le Dipendenze Interne (Analisi del testo)**

Guardo `NomeMateria` e `CreditiMateria`. Dipendono dalla Matricola dello studente? No. Dipendono solo dal `CodiceMateria`? Sì.

- **DF2:** $\text{CodiceMateria} \to \text{NomeMateria, CreditiMateria}$
    
    _(Ogni codice materia corrisponde a un solo nome e a un numero fisso di crediti)._
    

**Risultato Finale (Lista delle Dipendenze):**

1. $\{\text{Matricola, CodiceMateria}\} \to \text{Voto}$
    
2. $\text{CodiceMateria} \to \{\text{NomeMateria, CreditiMateria}\}$
    
##### Come capire se hai finito?

Hai finito quando hai controllato che:

1. La chiave determina tutto il resto.
    
2. Non ci sono attributi "annidati" che dipendono l'uno dall'altro (es. Città dipende da CAP).
    
3. Non ci sono vincoli di unicità (es. "Ogni docente ha una sola stanza") che non hai scritto.
    
Se trovi la dipendenza del tipo **2** (dove chi sta a sinistra NON è la chiave intera), allora sai già che quella tabella **NON è normalizzata** e va spezzata.

## Tavola dei volumi calcoli
### 1. Per le Entità (I rettangoli)

Qui devi **inventare** dei numeri realistici, mantenendo le proporzioni logiche.

La domanda che devi farti è: _"In uno scenario reale, quante righe avrebbe questa tabella?"_

- **Esempio dal PDF:**
    
    - **Sede:** Hanno messo **10**. (Ha senso: un ente non ha 1000 sedi, ne ha poche).
        
    - **Foto:** Hanno messo **20.000**. (Un archivio storico ha tante foto).
        
    - **Soggetto:** Hanno messo **6.000**. (Ci sono meno soggetti catalogati rispetto al numero totale delle foto, perché lo stesso soggetto può apparire in più foto).
        

**Regola d'oro:** Non serve indovinare il numero "vero", serve che i numeri siano **proporzionati**. Se metti 1.000.000 di Sedi e 10 Foto, il progetto è sbagliato logicamente.

---

### 2. Per le Relazioni (I rombi)

Qui invece **NON devi inventare**. Il volume delle relazioni dipende strettamente dalle **Cardinalità** che hai disegnato nello schema E-R.

Devi guardare le linee che entrano nel rombo:

- **Caso A: Relazioni Uno-a-Molti (1:N)**
    
    - _Regola:_ Il volume della relazione è uguale al volume dell'entità che ha la cardinalità **(1,1)** o **(0,1)** (cioè il lato "molti" della relazione, paradossalmente).
        
    - Esempio dal PDF: Guarda la relazione **Ospita** tra _Sede_ e _Foto_.
        
        - Una Foto sta in **1** Sede.
            
        - Una Sede ospita **N** Foto.
            
        - Quindi: Ci sono tante "ospitalità" quante sono le foto.
            
        - Volume Foto = 20.000 $\rightarrow$ **Volume Ospita = 20.000**.
            
- **Caso B: Relazioni Molti-a-Molti (N:N)**
    
    - _Regola:_ Qui il numero cresce. Di solito si stima un fattore di moltiplicazione medio.
        
    - _Esempio (ipotetico):_ Se avessi `Studenti` (100) ed `Esami` (N:N).
        
        Se ipotizzi che ogni studente fa in media 5 esami:
        
        Volume Relazione = $100 \times 5 = 500$.
        

---

### 3. Per le Gerarchie (Padre-Figlio)

Qui i numeri devono "tornare" matematicamente. La somma dei volumi delle entità figlie deve essere uguale (o quasi, se parziale) al volume del padre.

- Esempio dal PDF:
    
    - Entità Padre **Soggetto**: Volume **6.000**.
        
    - Entità Figlie:
        
        - **Personaggio**: 1.500
            
        - **Luogo**: 2.000
            
        - **Oggetto**: 2.500
            
    - **Controllo:** $1.500 + 2.000 + 2.500 = 6.000$. I conti tornano perfettamente.


## Leggenda della tavola degli accessi
Prima però analizziamo il tuo calcolo (**10.001**), perché nasconde un'ipotesi estrema.
### 1. Analisi del tuo calcolo (10.001)

Hai calcolato: $1 (\text{Veterinario}) + 5.000 (\text{Cura}) + 5.000 (\text{Animali}) = 10.001$.

**È giusto?**

Matematicamente è corretto **SOLO SE** quel _singolo specifico veterinario_ cura **TUTTI** i 5.000 animali presenti nel database (cioè se c'è un solo veterinario in tutto il sistema o se hai preso il "caso pessimo" estremo).

**È realistico?**

Di solito no. In un database con 5.000 animali e (ipotizziamo) 10 veterinari, la "media" sarebbe che ogni veterinario ne cura 500.

In quel caso il calcolo corretto sarebbe:

$$1 + 500 (\text{relazioni sue}) + 500 (\text{suoi animali}) = 1.001$$

Tuttavia, all'esame, se vuoi essere prudente e non hai il numero dei veterinari, puoi giustificare il tuo 10.001 scrivendo nelle note: _"Ipotizzo il caso pessimo in cui il veterinario abbia in carico l'intero allevamento"_.

---

### 2. Guida Definitiva: Come calcolare gli Accessi (Per i tuoi appunti)

Ecco lo schema pratico da copiare. Quando devi riempire la colonna **Accessi**, cerca in quale di questi casi ricade la tua operazione.

#### LEGENDA

- **Volume(X):** Numero totale di righe nella tabella X.
    
- **Fan-out:** Numero medio di "figli" per ogni "padre" (es. quanti animali ha in media un veterinario). Si calcola: $\frac{\text{Volume(Figli)}}{\text{Volume(Padri)}}$.
    

---

#### CASO A: INSERIMENTO DATI (Insert)

_L'operazione è: "Inserisci un nuovo Cliente e il suo Ordine"._

Non leggi nulla, scrivi solo in coda.

- **Regola:** Contano solo le tabelle dove aggiungi righe.
    
- **Formula:** **1** per ogni tabella toccata.
    
- **Tipo:** **S** (Scrittura).
    
- _Esempio:_ Inserisco Animale (1) e Proprietario (1). Totale = 2 Accessi (S).
    

---

#### CASO B: RICERCA PUNTUALE (Select by ID)

_L'operazione è: "Dammi i dati del Cliente con Codice 123"._

Entri diretto con la chiave primaria.

- **Regola:** Accesso diretto.
    
- **Formula:** **1**.
    
- **Tipo:** **L** (Lettura).
    

---

#### CASO C: RICERCA PER FILTRO (Scan)

_L'operazione è: "Dammi tutti i clienti di Roma" (e non ho un indice su Città)._

Devi scorrere tutta la tabella per trovare quelli giusti.

- **Regola:** Devi leggere tutto per filtrare.
    
- **Formula:** **Volume(Tabella)**.
    
- **Tipo:** **L**.
    
- _Nota:_ Se l'operazione dice "Tutti i clienti", scrivi il Volume. Se dice "I clienti di Roma", scrivi comunque il Volume (perché devi controllarli tutti) oppure una frazione se ipotizzi un indice (es. Volume / 10). _Consiglio: usa il Volume intero per sicurezza._
    

---

#### CASO D: NAVIGAZIONE 1:N (Padre $\to$ Figli)

_L'operazione è: "Dato il Veterinario X (Padre), trova i suoi Animali (Figli)"._

È il caso del tuo esercizio.

1. **Accesso al Padre:** **1** (lo trovi per ID).
    
2. **Accesso ai Figli (Relazione):** Devi trovare tutti i collegamenti.
    
    - **Formula:** **Fan-out** (oppure Volume(Figli) se è il caso pessimo).
        
3. **Accesso ai Figli (Entità):** Devi leggere i dati di ogni figlio trovato.
    
    - **Formula:** **Fan-out** (uguale al numero sopra).
        

- _Totale:_ $1 + 2 \times \text{Fan-out}$.
    

---

#### CASO E: NAVIGAZIONE N:1 (Figlio $\to$ Padre)

_L'operazione è: "Dato l'Animale Fido, dammi il suo Proprietario"._

Qui è facile: un figlio ha _un solo_ padre.

1. **Accesso al Figlio:** **1** (trovi Fido).
    
2. **Accesso al Padre:** Leggi la chiave esterna e vai al padre.
    
    - **Formula:** **1**.
        

- _Totale:_ 2 Accessi.
    

---

#### CASO F: MODIFICA O CANCELLAZIONE (Update/Delete)

_L'operazione è: "Modifica l'indirizzo del Cliente X"._

Prima lo devi trovare, poi lo modifichi.

1. **Ricerca:** **1 L** (Lettura per trovarlo).
    
2. **Modifica:** **1 S** (Scrittura per salvarlo).
    

- _Totale:_ 2 Accessi (1L + 1S).

---

---
# Guida Completa Unificata: Teoria e Pratica di Basi di Dati
## Organizzazione Fisica e Gestione delle Interrogazioni

_(Riferimento: File 6)_
### 1. Architettura e Gestione del Buffer

Il DBMS non accede direttamente al disco per ogni singola richiesta, ma utilizza una gerarchia di moduli per l'efficienza. L'interazione chiave avviene tra la memoria secondaria (Lenta, persistente) e la memoria principale (Veloce, volatile) attraverso il **Gestore del Buffer**.

> **Per capire:** Immagina il Buffer come una scrivania (RAM) e il Disco come un archivio in cantina. Non scendi in cantina per ogni foglio; porti una cartella (Pagina) sulla scrivania, ci lavori sopra, e la riporti giù solo quando serve o quando la scrivania è piena.

- **Pagine e Blocchi:** Il buffer è diviso in **pagine**, che corrispondono esattamente alle dimensioni dei blocchi fisici del disco.
    
- **Variabili di Stato:** Per ogni pagina, il gestore deve sapere:
    
    - _Contatore (Pin Count):_ Quanti programmi stanno usando quella pagina ora.
        
    - _Bit "Sporco" (Dirty Bit):_ Se la pagina è stata modificata rispetto al disco. Se è "sporca", va salvata prima di essere rimossa.
        

**Le Primitive del Buffer:**

1. **fix:** Richiede una pagina. Se non c'è, la carica dal disco. Incrementa il contatore d'uso.
    
2. **unfix:** Indica che ho finito di usare la pagina. Decrementa il contatore.
    
3. **setDirty:** Comunica che la pagina è stata modificata.
    
4. **force:** Obbliga la scrittura immediata su disco (sincrona), fondamentale per garantire l'affidabilità (es. dopo un COMMIT).
    
### 2. Strutture per l'Organizzazione dei File

Come vengono salvate le righe (tuple) fisicamente?

- **Sequenziali (Heap):** Le tuple sono messe una dopo l'altra nell'ordine di arrivo. È un "mucchio" disordinato.
    
- **Hash:** La posizione fisica dipende da una formula matematica sulla chiave.
    
    - _Pro:_ Velocissimo per accessi puntuali (es. "Dammi cliente ID 50").
        
    - _Contro:_ Inutile per ricerche su intervalli (es. "Clienti dal 50 al 100") o ordinamenti.
        
- **Ad Albero (Indici):** Strutture gerarchiche che permettono accessi veloci (logaritmici) sia puntuali che per intervalli.
    

### 3. Gli Indici (Primari vs Secondari)

Un indice è un file separato che contiene coppie `<Valore Chiave, Indirizzo Fisico>`.

- **Indice Primario (Sparso):** Si usa quando il file dei dati è **già ordinato fisicamente** in base alla chiave.
    
    > **Esempio:** Pensa all'indice dei capitoli di un libro. Non ti dice ogni singola pagina. Ti dice "Capitolo 1 inizia a pag. 10", "Capitolo 2 inizia a pag. 50". Se cerchi la pag. 35, sai automaticamente che è nel blocco del Capitolo 1.
    
    - Essendo "Sparso", l'indice non deve puntare a ogni riga, ma solo al primo record di ogni blocco. Occupa pochissimo spazio.
        
- **Indice Secondario (Denso):** Si usa quando cerchi per un campo che **non** determina l'ordine fisico del file (es. cerchi per "Cognome" ma il file è ordinato per "Matricola").
    
    > **Esempio:** Pensa all'indice analitico in fondo al libro. Le parole sono in ordine alfabetico (A-Z), ma i concetti nel libro sono sparsi ovunque. Per questo, l'indice deve elencare _ogni singola occorrenza_ della parola.
    
    - Deve essere "Denso": contiene un puntatore per ogni singola tupla.
        

**B-Tree e B+-Tree (Alberi Dinamici)** Sono gli alberi usati nei DB reali. Sono **bilanciati**: tutte le foglie sono alla stessa distanza dalla radice, garantendo tempi di accesso costanti.

- **Split:** Se inserisco un dato e la pagina (nodo) è piena, il nodo si spacca in due e la modifica risale verso l'alto.
    
- **Merge:** Se cancello dati e il nodo si svuota troppo, si fonde con il vicino.
    
- **B+-Tree:** A differenza del B-Tree classico, nelle foglie ci sono puntatori che collegano una foglia alla successiva.
    
    > **Utilità:** Questo crea una "catena" orizzontale. È perfetto per le query tipo `WHERE Età BETWEEN 20 AND 30`. Trovi il 20 e poi scorri la catena fino al 30 senza risalire l'albero.
    

### 4. Ottimizzazione delle Query

Il DBMS trasforma la tua query SQL in un piano di esecuzione efficiente.

1. **Ottimizzazione Algebrica:** Cambia l'ordine delle operazioni logiche.
    
    > **Esempio:** Se devi fare `JOIN` tra due tabelle enormi e poi filtrare `WHERE Città = 'Roma'`, l'ottimizzatore sposta il filtro _prima_ del JOIN. È sempre meglio lavorare su pochi dati filtrati che unire tutto e filtrare dopo.
    
2. **Ottimizzazione basata sui Costi:** Sceglie l'algoritmo fisico migliore basandosi sui **Profili delle Relazioni** (statistiche salvate nel dizionario: quante righe ci sono? quanto sono grandi?).
    

**Algoritmi di Join (Strategie):**

- **Nested-loop:** Cicli annidati (Per ogni riga di A, scorro tutta B). Lento se le tabelle sono grandi.
    
- **Merge-scan:** Richiede che i dati siano ordinati. Molto veloce se lo sono.
    
- **Hash-join:** Usa funzioni hash per accoppiare le righe. Efficiente per grandi moli di dati non ordinati.
    

---

## Sviluppo di Applicazioni per Basi di Dati

_(Riferimento: File 7)_

### 1. SQL Embedded e il Conflitto di Impedenza

Quando usi SQL dentro un programma (C, Java), nasce un problema chiamato **Conflitto di Impedenza**.

- I linguaggi di programmazione lavorano "record per record" (variabili scalari).
    
- SQL lavora "insieme per insieme" (restutisce tabelle intere).
    

> **Metafora:** È come cercare di travasare un secchio d'acqua (la tabella SQL) in una bottiglia dal collo stretto (la variabile del programma) tutto in una volta. L'acqua uscirebbe fuori.

**Soluzione: I Cursori** Il cursore è un meccanismo che permette di prendere le righe della tabella **una alla volta**.

1. `DECLARE`: Definisci la query.
    
2. `OPEN`: Esegui la query (riempi il secchio).
    
3. `FETCH`: Prendi la riga successiva e mettila nelle variabili del programma (il "mestolo" che travasa goccia a goccia).
    
4. `CLOSE`: Chiudi tutto.
    

### 2. SQL Dinamico vs Statico

- **SQL Statico:** La query è scritta fissa nel codice (`SELECT * FROM Clienti`). Il DBMS la ottimizza una volta sola (alla compilazione). Massima velocità.
    
- **SQL Dinamico:** La query viene costruita come stringa mentre il programma gira (Run-time).
    
    > **Esempio:** Un motore di ricerca dove l'utente può scegliere se filtrare per nome, data, o prezzo. Non puoi sapere prima quale `WHERE` scrivere.
    
    - Richiede due fasi: `PREPARE` (il DBMS analizza la stringa SQL) e `EXECUTE` (la lancia).
        

### 3. Transazioni e Livelli di Isolamento

Una transazione è un blocco di operazioni che deve essere **Atomico** (tutto o niente). Per garantire velocità, a volte si accetta di abbassare il livello di isolamento, rischiando però delle anomalie.

Ecco i 4 livelli, dal più veloce (e pericoloso) al più sicuro (e lento):

1. **Read Uncommitted (Livello 0):**
    
    - Non usa blocchi in lettura.
        
    - **Rischio:** _Dirty Read_. Leggi un dato che un'altra transazione sta modificando ma non ha ancora confermato (potrebbe annullarlo dopo!).
        
2. **Read Committed (Livello 1):**
    
    - Blocca il dato solo nell'istante in cui lo legge.
        
    - **Rischio:** _Non-repeatable Read_. Leggi il saldo (100€). Un attimo dopo qualcun altro lo cambia e committa. Se rileggi lo stesso dato nella stessa transazione, trovi un valore diverso (es. 80€).
        
3. **Repeatable Read (Livello 2):**
    
    - Mantiene i blocchi su ciò che legge fino alla fine.
        
    - **Rischio:** _Phantom Read_ (Fantasmi). Se fai `SELECT count(*) FROM Clienti` e ottieni 10. Qualcuno _inserisce_ un nuovo cliente. Se rifai la conta, ne trovi 11. Il dato è apparso dal nulla.
        
4. **Serializable (Livello 4):**
    
    - Simula l'esecuzione seriale. Nessuna anomalia, ma prestazioni minori.
        

---

## Basi di Dati Semantiche

_(Riferimento: File 8)_

### 1. Differenza con i DB Relazionali

Nei DB Relazionali, lo schema (tabelle) viene prima dei dati. Nel Web Semantico, i dati sono flessibili e il significato (semantica) è descritto tramite metadati. L'obiettivo è creare **Linked Open Data** (dati aperti e connessi tra loro sul web).

### 2. RDF (Resource Description Framework)

È il modello base. Tutto è descritto come una **Tripla**:

`<Soggetto, Predicato, Oggetto>`.

> **Esempio:** `<Verdi> <HaComposto> <Traviata>`.
> 
> È un modo universale per descrivere qualsiasi relazione.

- **IRI:** Identificatori univoci (simili a URL) per le risorse.
    
- **Blank Nodes:** Nodi anonimi, usati quando non serve dare un nome globale a una risorsa.
    

### 3. RDFS (Schema e Inferenza)

RDFS permette di creare vocabolari (ontologie) per dare senso ai dati. Introduce concetti potenti come l'**Ereditarietà**:

- Definisco: `Compositore` è _sottoclasse_ di `Artista`.
    
- Definisco: `Artista` è _sottoclasse_ di `Persona`.
    
- **Inferenza (Entailment):** Se dico che "Verdi è un Compositore", il sistema capisce _automaticamente_ che Verdi è anche una Persona, senza che io debba scriverlo esplicitamente.
    

### 4. SPARQL (Interrogare il Web Semantico)

È l'equivalente di SQL per i grafi RDF.

- Usa i **Triple Pattern**: Nella clausola `WHERE`, inserisci delle triple con delle variabili (indicate con `?`).
    
    > **Esempio:** `SELECT ?nome WHERE { ?x <HaComposto> <Traviata> . ?x <HaNome> ?nome }`.
    > 
    > Cerca la X che ha composto la Traviata e dammi il suo nome.
    
- **SPARQL 1.1** ha introdotto gli **Entailment Regimes**: La query non cerca solo i dati scritti nel DB, ma anche quelli che può _dedurre_ logicamente grazie all'RDFS.


## PARTE 4: Guida Completa a MySQL

_(Riferimento: File 4.1 - Intro to MySQL)_

### 1. Introduzione

MySQL è un RDBMS open source, client/server, noto per velocità e scalabilità. Supporta lo standard SQL e architetture embedded. La sua architettura modulare include:

- **Connection Pool:** Gestione autenticazione e thread.
    
- **Optimizer:** Analisi e ottimizzazione query.
    
- **Pluggable Storage Engines:** Moduli intercambiabili per la gestione fisica (es. **InnoDB** per transazioni, **MyISAM** per velocità).
    

### 2. Guida all'Installazione e Configurazione

_(Dettagli operativi basati sui riferimenti alla documentazione ufficiale Cap. 2)_

#### **A. Windows**

Si raccomanda l'uso del **MySQL Installer** che include Server, Workbench e Shell.

1. Scaricare il **MySQL Installer** (versione `mysql-installer-community`) dal sito ufficiale [dev.mysql.com](https://dev.mysql.com/downloads/installer/).
    
2. Avviare l'eseguibile. Scegliere il setup **"Developer Default"** (installa tutto) o **"Server only"**.
    
3. **Configurazione:**
    
    - Scegliere "Standalone MySQL Server".
        
    - Lasciare la porta default **3306**.
        
    - **Importante:** Impostare una password robusta per l'utente **root** e annotarla.
        
4. Completare il wizard assicurandosi che il servizio MySQL si avvii con Windows.
    
#### **B. macOS**

1. Scaricare il pacchetto **DMG Archive** dal sito ufficiale (versione per Intel o Apple Silicon).
    
2. Eseguire il pacchetto `.pkg`.
    
3. Al termine, apparirà una notifica con una **password temporanea per root**. **SALVARLA SUBITO!**
    
4. Avviare il server da _Preferenze di Sistema > MySQL_.
    
5. Da terminale, loggarsi (`/usr/local/mysql/bin/mysql -u root -p`) usando la password temporanea e cambiarla subito:
    ```
    ALTER USER 'root'@'localhost' IDENTIFIED BY 'nuova_password';
    ```
    
#### **C. Linux (Ubuntu/Debian)**

1. `sudo apt-get update` e `sudo apt-get install mysql-server`.
    
2. Eseguire lo script di sicurezza (fondamentale):
    ```
    sudo mysql_secure_installation
    ```
    
    Seguire le istruzioni per impostare la password di root e rimuovere accessi insicuri.
    
### 3. Connessione e Comandi Base

- **Connessione Shell:** `mysql -u utente -p`.
    
- **Comandi:**
    
    - `SHOW DATABASES;`
        
    - `USE nome_db;`
        
    - `SHOW TABLES;`
        
    - `DESCRIBE tabella;` (Struttura campi)
        
    - `QUIT` o `\q` (Uscita)
        
### 4. DDL e DML (Esempi Pratici)

- **Creazione Tabella:**
    ```
    CREATE TABLE pet (
      name VARCHAR(20),
      owner VARCHAR(20),
      birth DATE
    );
    ```
    
- **Inserimento:** `INSERT INTO pet VALUES ('Fluffy', 'Harold', '1993-02-04');`
    
- **Caricamento da File:** `LOAD DATA LOCAL INFILE "pet.txt" INTO TABLE pet;`
    
- **Aggiornamento:** `UPDATE pet SET birth='1989-08-31' WHERE name='Bowser';`
    
- **Cancellazione:** `DELETE FROM pet WHERE name='Bowser';`
    
### 5. Interrogazioni (SELECT)

- **Selezione:** `SELECT * FROM pet WHERE species = 'dog' AND sex = 'f';`
    
- **NULL:** Usare `IS NULL` o `IS NOT NULL` (mai `= NULL`).
    
- **Pattern Matching:**
    
    - `LIKE 'b%'`: Inizia per 'b'.
        
    - `REGEXP '^b'`: Inizia per 'b' (espressione regolare).
        
- **Aggregazione:**
    ```
    SELECT owner, COUNT(*) FROM pet GROUP BY owner;
    ```
    (Conta animali per proprietario) .
### 6. Workbench

Strumento visuale incluso per:

- Progettazione diagrammi E-R.
    
- **Forward Engineering:** Dal diagramma al codice SQL.
    
- **Reverse Engineering:** Dal database esistente al diagramma.