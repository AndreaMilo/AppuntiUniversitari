## Obiettivi della grafica e comunicazione visiva
![[Pasted image 20261124134719.png]]

Chiarire gli obiettivi della grafica e i loro possibili conflitti è fondamentale per definire l'aspetto visivo ed estetico del progetto, perché non sempre queste decisioni vanno nella stessa direzione. Come mostra il diagramma, la grafica può puntare su cinque attributi largamente indipendenti — **comprensibilità**, **usabilità** (che rientra nella comprensibilità), **gradevolezza**, **originalità** ed **emozione** — che spesso richiedono scelte in contrasto tra loro. Se il progettista spinge molto sull'originalità, difficilmente riuscirà a garantire allo stesso tempo la massima usabilità e una comprensione immediata; al contrario, una grafica orientata solo alla massima essenzialità può risultare poco espressiva. Bisogna quindi chiarire fin dall'inizio su quali obiettivi si vuole puntare per capire fin dove è opportuno spingersi.

![[Pasted image 20261124162738.png]]

Questa schermata (storica home page di Fanta) mostra una grafica promozionale molto accesa, dominata dall'arancione, dal movimento e da personaggi in pose dinamiche e ironiche. Qui l'obiettivo principale non è guidare un'operazione tecnica o una consultazione complessa, bensì trasmettere energia, freschezza, gioco e identità di marca. Inoltre, le voci di menu sono nascoste e compaiono una alla volta solo passando con il mouse sulle aree tratteggiate di mani e piedi: l'utente non ha mai una visione d'insieme dei contenuti. È un esempio utile per capire come un linguaggio visivo espressivo ed emotivo funzioni quando lo scopo è catturare l'attenzione e costruire un'immagine di brand, ma diventi problematico se applicato senza filtri a contesti in cui l'utente deve orientarsi in fretta tra molte informazioni.

### Differenza tra campagna promozionale e negozio online
![[Pasted image 20261124162858.png]]

Nel negozio online l'utente vuole trovare un prodotto, capirne il formato e il prezzo, aggiungerlo al carrello e controllare il totale: servono quindi categorie chiare, schede ordinate, prezzi leggibili e pulsanti d'azione evidenti (_Aggiungi_, _Carrello_). Ciò che funziona per emozionare non è detto che funzioni per acquistare senza attriti.

## La grafica per l'utilità
>[!NOTE] Presentation of information (ISO 9241-12)
>La presentazione dell'informazione visiva dovrebbe abilitare l'utente a eseguire i compiti percettivi (per esempio, la ricerca di informazioni sullo schermo) in modo efficace, efficiente e con soddisfazione.

La grafica non è un semplice "abbellimento" applicato alla fine del lavoro: è parte integrante della prestazione dell'utente. Se le informazioni visive sono confuse, poco contrastate o mal disposte, la ricerca visiva richiede più tempo, comporta maggiore fatica cognitiva e genera più errori.

I principi generali dello standard **ISO 9241-112** nell'ambito della **presentazione** dell'informazione nel campo visivo, uditivo e tattile sono:
- **Rilevabilità e distinguibilità**: ogni elemento deve essere facilmente individuabile e distinguibile dagli altri.
- **Compattezza**: mostrare solo ciò che serve al compito, evitando ridondanze.
- **Assenza di distrazioni**: non inserire elementi che deviano dal compito principale.
- **Coerenza**: uniformità di layout, colori e tipografia in tutta l'interfaccia.

## La grafica per l'usabilità
Se la norma precedente spiegava i principi generali della presentazione, la **ISO 9241-125** (che raccoglie l'eredità della parte visiva della ISO 9241-12) scende nel dettaglio sulla **presentazione visiva (Visual UI)**, richiamando quattro aree fondamentali:
- **Organizzazione spaziale**: definizione delle regole per la spaziatura e il raggruppamento degli elementi.
- **Uso dei colori e del contrasto**: linee guida per garantire la leggibilità, senza affidare mai un'informazione importante *solamente* al colore (perché una quota significativa di utenti soffre di daltonismo — circa 1 uomo su 12 e 1 donna su 165 — e non riuscirebbe a distinguere certi colori come rosso e verde, oltre al fatto che riflessi o schermi in bianco e nero possono annullare le differenze cromatiche).
- **Tipografia e struttura**: scelta di font leggibili, dimensioni adeguate dei caratteri e chiarezza di testi e tabelle.
- **Gestione delle finestre e del layout**: come strutturare finestre, barre di navigazione e aree funzionali in modo da minimizzare il carico cognitivo.

## Leggi della Gestalt
La psicologia della Gestalt (*Gestaltpsychologie*, dal tedesco *Gestalt*: "forma", "schema", "rappresentazione") studia la percezione intesa come unità globale. L'idea portante è che **il tutto è più della somma delle sue parti**: nel nostro campo questo si traduce nel fatto che l'occhio dell'utente non si limita a sommare singoli pixel o tratti isolati, ma organizza spontaneamente il campo visivo in gruppi.

Studiare come l'occhio raggruppa gli elementi aiuta il progettista a rendere l'interfaccia leggibile a colpo d'occhio.

![[Pasted image 20261125104556.png]]

Nell'esempio in figura (luci alternate che appaiono in movimento e i tre puntini dell'indicatore *"sta scrivendo..."* nelle chat) non c'è nulla che si sposti davvero sullo schermo, eppure la percezione coglie un movimento unitario invece di singoli punti isolati.

### Leggi della Gestalt o dell'organizzazione figurale
Nel 1923 **Max Wertheimer** formula una serie di leggi per descrivere la tendenza spontanea con cui la percezione umana raggruppa o separa gli elementi visivi (a parità di tutte le altre condizioni):
- Legge della vicinanza
- Legge della somiglianza
- Legge della chiusura
- Legge della continuità di direzione
- Legge della buona forma
- Legge dell'esperienza passata

#### Legge della vicinanza
La legge della vicinanza spiega che, a parità di altre condizioni, gli elementi del campo visivo che sono tra loro più vicini tendono a essere raccolti in unità.

![[Pasted image 20261125105039.png]]

Nell'interfaccia, questo significa che bisogna **avvicinare** gli elementi correlati tra loro per significato o funzione (ad esempio un'etichetta e il relativo campo di input) e **tenere distanziati** gli elementi che non hanno alcun legame.

#### Legge della somiglianza
La legge della somiglianza spiega che, a parità di altre condizioni, gli elementi del campo visivo tra loro simili (per forma, dimensione, orientamento, colore o movimento comune) tendono a essere raccolti in unità.

![[Pasted image 20261125145144.png]]

Anche il **colore** sfrutta bene la legge della somiglianza, perché elementi della stessa tinta vengono subito associati a funzioni o categorie affini; tuttavia questa tecnica funziona solo se non si usano troppi colori nella stessa schermata, poiché troppe tinte diverse creano confusione invece di ordinare. Allo stesso tempo, la somiglianza permette di far risaltare un elemento per **diversità o contrasto** rispetto al gruppo circostante.

#### Legge della chiusura
La legge della chiusura spiega che le linee che delimitano una superficie chiusa si percepiscono come unità più facilmente di quelle che non si chiudono.

![[Pasted image 20261125150319.png]]

Come mostra l'esempio in figura, la chiusura è una forza percettiva più forte della vicinanza: quando vicinanza spaziale e chiusura spingono in direzioni diverse, la percezione può risultare **ambigua** o venire dominata da una delle due. Per il progettista è un avvertimento importante: un layout ambiguo può far sembrare uniti elementi che non lo sono o separare elementi che dovrebbero stare insieme, aumentando la fatica di lettura. Al contrario, usare **riquadri, cornici o linee di separazione** nei menu e nei moduli permette di isolare con chiarezza i gruppi logici.

#### Legge della continuità di direzione
Chiamata anche legge della *"curva buona"*, afferma che quelle parti di una figura che formano una curva continua o che vanno nella stessa direzione si costituiscono in unità più facilmente delle altre (nell'immagine vediamo infatti due linee continue 1-2 e 3-4, evitando cambi bruschi di direzione all'incrocio).

![[Pasted image 20261125150542.png]]

#### Legge della buona forma
Detta anche principio di **pregnanza** o della **coerenza strutturale**, stabilisce che il campo percettivo si segmenta in modo che risultino entità per quanto possibile equilibrate, armoniche, semplici e costituite secondo un medesimo principio in tutte le loro parti.

![[Pasted image 20261125150613.png]]

Nella figura, quando le due forme (a) si sovrappongono (b), il sistema visivo preferisce ricombinare i tratti in un poligono e una curva coerenti piuttosto che mantenere l'interpretazione in (c). In un'interfaccia, rispettare la "buona forma" significa evitare spigoli casuali, allineamenti approssimativi e composizioni sbilanciate che costringono l'utente a riordinare visivamente la pagina.

#### Legge dell'esperienza passata
La legge dell'esperienza passata spiega che le nostre conoscenze e abitudini pregresse influenzano il modo in cui interpretiamo e completiamo ciò che vediamo (in figura riconosciamo subito la lettera **E** in *a*, mentre in *b* è molto più difficile nonostante il numero di tratti sia identico). Se un disegno o un controllo ricorda qualcosa che abbiamo già visto e imparato, lo riconosciamo più rapidamente; se invece è troppo insolito o privo di riferimenti noti, richiede più sforzo.

![[Pasted image 20261125151228.png]]

### Elementi irregolari nella forma e nella distribuzione spaziale
Quando gli elementi nel campo visivo sono irregolari nella forma e nella distribuzione spaziale, senza contorni chiusi né simmetrie, abbiamo serie difficoltà a riconoscerne il senso. Nelle due "figure prive di Gestalt" qui sotto — il cane dalmata che annusa il terreno (*a*) e il volto barbuto (*b*) — l'assenza di linee chiuse e la somiglianza delle chiazze nere impediscono di separare subito la figura dallo sfondo.

![[Pasted image 20261125151511.png]]

Lo stesso problema accade nelle interfacce: una distribuzione irregolare di campi, testi o pulsanti fa sembrare la schermata disorganizzata e rallenta l'individuazione dei comandi, costringendo l'utente a rileggere tutto da capo ogni volta. Nell'esempio sottostante si confronta una schermata priva di regole della Gestalt con una riorganizzata secondo vicinanza, chiusura (cornici) e allineamento:

Senza Gestalt:
![[Pasted image 20261125151803.png]]

Con Gestalt:
![[Pasted image 20261125151816.png]]

Allo stesso modo, in molte applicazioni e siti web certe schermate (come le finestre di conferma o il menu di uscita) seguono ormai schemi visivi consolidati di somiglianza, chiusura e vicinanza: questo permette all'utente di riconoscere subito i gruppi di azioni disponibili senza doverli reinterpretare ogni volta.

![[Pasted image 20261125152329.png]]

### Eye vs Logic
L'ordine alfabetico non è utile perché l'utente non cerca le opzioni di stampa in ordine alfabetico, e l'occhio fatica a trovare una relazione logica tra righe disallineate in basso. Quando l'organizzazione visiva e l'allineamento in griglia non rispecchiano la **logica del compito**, l'interfaccia costringe lo sguardo a salti inutili e risulta poco intuitiva.

## Colore e contrasto
### Colore
![[Pasted image 20261125152728.png]]

La figura mostra la mappa dei mercati di **Finviz**, un ottimo esempio in cui più variabili visive e leggi della Gestalt lavorano insieme:
- **Vicinanza e chiusura**: i riquadri delle aziende dello stesso settore sono vicini e racchiusi in cornici comuni.
- **Area**: la dimensione del riquadro rappresenta la **capitalizzazione** dell'azienda.
- **Colore e somiglianza**: il colore (verde/rosso e relativa luminosità) indica la variazione percentuale giornaliera (positiva o negativa), permettendo di cogliere le tendenze generali a colpo d'occhio prima ancora di leggere i singoli numeri.

In generale, nella progettazione di un'interfaccia il colore va usato seguendo alcune regole pratiche:
- **Usarlo con moderazione**: troppi colori diversi rendono la pagina complessa e confusa (*troppa informazione equivale a nessuna informazione*).
- **Sfruttare sfondi calmi e insaturi**: per evidenziare elementi importanti conviene usare colori saturi e caldi su sfondi freddi e insaturi.
- **Rispettare le convenzioni culturali**: nei paesi occidentali il verde indica via libera e il rosso pericolo o stop (attenzione a non associare il colore al testo letterale — es. *NO* in rosso — invece che all'effetto reale dell'azione, come *non cancellare*).
- **Pensare al daltonismo**: non affidare mai un'informazione critica al solo colore (soprattutto la coppia rosso/verde), offrendo sempre indicatori aggiuntivi (testo, icone) o schemi alternativi (es. giallo/blu).

### Contrasto e illuminazione
Il contrasto nasce dalla differenza rispetto al contesto: un riquadro più scuro spicca tra quelli più chiari, una parola in colore diverso risalta in un testo, e anche la dimensione del carattere crea contrasto (un testo più grande spicca rispetto a uno piccolo). Il contrasto funziona proprio perché c'è una differenza netta rispetto agli elementi circostanti.

>[!NOTE] Regola d'oro sul contrasto
>I contrasti e l'enfasi visiva vanno usati con **molta moderazione**. Perché un elemento risalti serve uno sfondo relativamente **calmo**: se si evidenzia tutto con colori accesi o troppi effetti, l'enfasi si annulla e la gerarchia visiva diventa illeggibile.

Un altro modo per richiamare l'attenzione, diverso dal semplice contrasto statico, è l'**illuminazione** (o il lampeggiamento): un elemento illuminato o lampeggiante attira subito lo sguardo, ma può disturbare la lettura o **impedire di concentrarsi** se continua a lampeggiare mentre l'operatore deve leggere o decidere un'azione. Per questo, molto spesso, quando si passa sopra l'elemento con il cursore (o lo si seleziona), quest'ultimo smette di lampeggiare.

![[Pasted image 20261125154049.png|197]]

## Percorsi visivi ed esperimento di Yarbus
È diffusa l'idea che gli occhi scorrano una schermata in modo regolare dall'alto a sinistra verso il basso a destra, come nella lettura di un libro. In realtà, gli studi condotti con dispositivi di **eye tracking** dimostrano che il percorso dello sguardo (*scanpath*) è molto irregolare: alterna **fissazioni** (brevi soste in cui acquisiamo informazioni visive, circa 3-4 al secondo) e **saccadi** (movimenti rapidissimi tra un punto e l'altro durante i quali non acquisiamo informazioni).

Nel celebre esperimento del **1967**, lo psicologo russo **Alfred Yarbus** studiò i movimenti oculari sul dipinto *"Un visitatore inaspettato"* di **I.E. Repin**, osservando come lo sguardo cambiasse radicalmente percorso a seconda della consegna data all'osservatore: guardare liberamente il quadro, stimare l'età delle persone, ricordare gli abiti indossati oppure memorizzare la posizione degli oggetti nella stanza. Questo dimostra che il percorso visivo non dipende solo dall'immagine, ma soprattutto dagli **obiettivi** di chi guarda.

### Heat-map
Sommando gli *scanpath* di molti utenti si ottengono le **heat-map** (mappe di calore dell'attenzione visiva). La figura seguente mostra tre _heat-map_ tratte dagli studi di **Jakob Nielsen** e **Kara Pernice** sulle pagine web: le aree più calde (rosse e gialle) indicano dove si concentrano maggiormente gli sguardi, mentre le zone più fredde o esterne ricevono poca attenzione.

Da questi studi emerge spesso una configurazione media a **forma di F** (*F-pattern*): due bande di lettura orizzontale nella parte superiore e lungo le prime righe dei contenuti, seguite da una scansione verticale sul lato sinistro. Pur tenendo conto che i singoli percorsi variano da persona a persona, progettare tenendo presenti questi schemi aiuta a collocare le informazioni chiave dove vengono davvero notate.

![[Pasted image 20261125154612.png]]
