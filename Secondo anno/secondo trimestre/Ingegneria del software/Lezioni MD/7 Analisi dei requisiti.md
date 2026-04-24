# Modello di dominio
Il modello di dominio è utile per avere una base solida della **business logic** e per rappresentarlo si utilizza un **diagramma delle classi con prospettiva concettuale**, esso rappresenta in modo visivo i concetti caratteristici del dominio che stiamo studiando.
Inoltre questo modello è **indipendente dal software** ed è chiamato anche **modello concettuale** (già visto e usato nei concetti di Basi di Dati).
## Classe come concetto
Una classe rappresenta un concetto ben definito che permette l'astrazione di istanze simili.
![[Pasted image 20260424095750.png]]
Le proprietà della classe sono gli **attributi** e le **associazioni**.
### Attributi e Associazioni
Un **attributo** è una proprietà rilevante di un concetto (o classe) che contiene un valore per ogni oggetto.
![[Pasted image 20260424095913.png]]

Un'**associazione** è una relazione rivelante tra due concetti (o classi) ed è etichettata, come ad esempio `classe1 verbo classe2` quindi *Persona **lavora per** Dipartimento*.
Le associazioni sono generalmente bidirezionali, anche se generalmente vengono lette da sinistra a destra o dall'altro al basso.
Inoltre le associazioni possono essere anche **ricorsive**, come una classe di nome *"cartella"* che *contiene* altre classi cartella.
#### Legami delle associazioni
Un'associazione può rappresentare in modo più preciso anche un **gruppo di legami** tra gli oggetti delle classi associate:
![[Pasted image 20260424100339.png]]
![[Pasted image 20260424100354.png]]
### Classi associative e attributi di legame
Le classi nate dalle associazioni sono utilizzate per modellare proprietà intrinseche nella relazione delle due classi coinvolte. Un attributo di una classe associativa contiene un **valore per ogni legame** e per definizione di Basi di Dati si ricorda che nascono molto spesso dalle relazioni di tipo **molti-a-molti**.
![[Pasted image 20260424101220.png]]
## Ruoli
Un'alternativa grafica per non inserire l'etichetta nell'associazione è quella di definire dei **ruoli**. I ruoli rappresentano il nome della proprietà e sono posti alla fine della linea di congiunzione.
I ruoli hanno gran efficacia nelle associazioni tra oggetti della stessa classe, come l'esempio precedente:![[Pasted image 20260424101505.png]]
L'aggregazione del contenuto e del contenitore viene rappresentato anch'esso graficamente tramite il **daimo**, il quale può essere **vuoto** o **pieno**:
![[Pasted image 20260424101826.png]]
La **composizione** è una forma definita **forte** dell'aggregazione, poiché stiamo definendo che:
- la parte componente non può esistere senza il contenitore
- la parte componente può appartenere solo ad un unico oggetto contenitore
La composizione è una forma definita **debole** invece quando l'oggetto può esistere anche senza un altra classe.

In lettura queste due parti si leggono con ***è parte di*** o al contrario ***è composto da***.
## Generalizzazione
L'associazione tra classi viene definita sotto il concetto di ***è un tipo di*** o al contrario come ***può essere un***. 
Questo concetto è utilizzato per definire le **tassonomie** di classi, così possiamo dividere le classi in **superclasse** e le loro rispettive **sottoclassi**.
![[Pasted image 20260424102403.png]]
Ad esempio *Docente* è una classe specializzata di *Persona* che è una classe generale.
Per definizione, ogni oggetto di una sottoclasse è anche un oggetto della sua superclasse.

>[!WARNING] Attenzione
>Non tutti gli attributi sono generali per tutte le sottoclassi di una superclasse.

Per rappresentare graficamente una bozza degli studi di dominio si usa una **lavagna condivisa in scrittura** così da condividere questi dettagli. Questa lavagna virtuale è integrata sulle piattaforme di meeting (come quella su teams).
