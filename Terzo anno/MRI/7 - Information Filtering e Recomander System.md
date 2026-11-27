# Information Filtering e Recommender Systems

![[Pasted image 20261127164602.png]]
L'obiettivo del filtraggio dell'informazione (**Information Filtering**) è individuare le informazioni interessanti andando a filtrare (ovvero **togliere**) tutto ciò che non è rilevante per l'utente.
Nei classici motori di ricerca (**Information Retrieval**) il bisogno informativo è dinamico, ovvero cambia a ogni diversa ricerca, mentre la sorgente informativa è relativamente statica.
Invece, nell'**Information Filtering** il bisogno informativo diventa stabile, ed è la sorgente a essere dinamica, ovvero varia continuamente nel tempo e può provenire da molteplici fonti.

Questo concetto è alla base di piattaforme come TikTok: un algoritmo privo di ricerca esplicita dispone già dei contenuti e, in base alle interazioni dell'utente e al filtraggio delle informazioni, mostra ciò che può risultare più appagante.
![[Pasted image 20261127164953.png]]

La sorgente informativa è dinamica perché il set di contenuti varia costantemente (Amazon, TikTok, Spotify, ecc.).
Il bisogno informativo non viene esposto tramite una *query*, ma attraverso il **profilo utente** (*user model*): la piattaforma, in base alle esperienze e a ciò che l'utente guarda o con cui interagisce, sa cosa scartare e cosa mostrargli.

## Information Retrieval vs Information Filtering
![[Pasted image 20261127165302.png]]
### Sono ancora valide queste differenze?
![[Pasted image 20261127165552.png]]
Oggi molte di queste differenze si sono attenuate: anche le pagine web sono dinamiche e in cambiamento costante, e nei moderni motori di ricerca gli utenti sono ormai profilati e utilizzano il sistema in modo ripetitivo nel lungo periodo. Quindi entrambi gli ambiti operano in contesti dinamici.

Possiamo definire l'IR e l'IF **due facce della stessa moneta**, come li hanno descritti **N. Belkin e W. Croft** (1992).
![[Pasted image 20261127165716.png]]
Entrambi mirano allo stesso obiettivo, ovvero ottimizzare e facilitare l'accesso a sorgenti di dati (non strutturate).

Le prime regole per modellare l'utente e capire cosa mostrargli si basavano spesso sugli **stereotipi**: ad esempio, associando un utente a determinate caratteristiche o status, l'algoritmo filtra le informazioni mostrando ciò che è più probabile possa interessargli (e scartando il resto). Questi stereotipi hanno avuto origine già in uno studio del 1979 di **Elaine Rich**, in cui venne presentato il sistema **Grundy**, che costruiva modelli utente tramite stereotipi (ad esempio per suggerire romanzi); su questa base si sono sviluppati i primi sistemi di filtraggio mirati all'utente.
![[Pasted image 20261127170052.png]]

Questo sistema di filtraggio delle informazioni è anche alla base degli **algoritmi anti-spam**, dell'ordine con cui vengono mostrate le notizie su Google News o dei contenuti proposti sui social.
Alla stessa logica appartengono le **recommendations**, ovvero la raccomandazione di oggetti da acquistare, film da vedere o video tra i consigliati.

Tutti questi esempi usano algoritmi basati sull'Information Filtering.
![[Pasted image 20261127170723.png]]
Gran parte dei video, prodotti e film guardati o acquistati deriva infatti dai contenuti consigliati e non da una ricerca diretta (come mostrano i dati nell'immagine: l'80% dei contenuti consumati su Netflix, il 60% dei click nella homepage di YouTube e il 35% dei ricavi di Amazon provengono dai sistemi di raccomandazione).

>[!NOTE] Definizione di Recommender System di Burke (2002)
>I **Recommender Systems** guidano l'utente in modo **personalizzato** verso oggetti interessanti o utili all'interno di uno spazio in cui ci sono **tante possibili opzioni**.

## Il Problema
![[Pasted image 20261127173104.png]]
Nella sua formulazione più comune, il problema della raccomandazione si riduce alla **stima dei rating** (valutazioni) per gli oggetti (*item*) che non sono ancora stati visti o valutati dall'utente. Nella matrice utente-item mostrata sopra, le celle azzurre rappresentano i rating osservati, mentre quelle viola con `?` indicano le valutazioni mancanti da predire (ad esempio $r_{A,3}, r_{A,4}, r_{B,2}, \dots$).

![[Pasted image 20261127173128.png]]![[Pasted image 20261127173134.png]]
Formalmente, dati un insieme di utenti $U = \{u_1, \dots, u_M\}$ e un insieme di oggetti $X = \{x_1, \dots, x_N\}$, l'obiettivo è stimare una **funzione di utilità** $f: U \times X \to R$ che predica automaticamente quanto un utente apprezzerà un oggetto a lui sconosciuto.

Una volta stimati i rating mancanti (come mostrato nella seconda matrice), per ciascun utente $u \in U$ il sistema raccomanda l'oggetto con il rating stimato più alto:
$$\forall u \in U, \quad x'_u = \arg\max_{x \in X} f(u, x)$$
Nell'esempio, gli oggetti consigliati (indicati con la corona) sono l'*Item 3* per l'Utente A ($4.6$), l'*Item 5* per l'Utente B ($4.1$) e l'*Item 4* per l'Utente C ($4.7$).

### Valore per l'utente e per il business
![[Pasted image 20261127175048.png]]
Un Recommender System efficace deve mantenere un **equilibrio ottimale** (*optimal balance*) tra due prospettive diverse:
- **Prospettiva dell'utente (*User Value*):** punta a massimizzare la rilevanza, la piacevolezza (*enjoyment*) e la scoperta (*discovery*), garantendo soddisfazione, novità e diversità nei suggerimenti.
- **Prospettiva del fornitore (*Business Value*):** punta a massimizzare il profitto, il coinvolgimento (*engagement*), la fidelizzazione degli utenti (*retention*) e l'equità tra i contenuti proposti (*fairness*).

### Come funziona questo tipo di piattaforme
Ci sono tre componenti fondamentali per il funzionamento di queste piattaforme:
- L'**utente**, di cui è importante registrare le informazioni: cosa acquista, il profilo, quanto tempo rimane attivo sulla piattaforma, che tipo di contenuto guarda, ecc.
- Le informazioni sugli **oggetti** (*item*), ovvero se un film, prodotto o canzone è di tendenza, quanto viene visualizzato, acquistato o riprodotto in streaming e che impatto ha nell'ultimo periodo.
- Le **interazioni** e l'algoritmo di **Recommender System**, che mettono in relazione utenti e oggetti.

Mettendo insieme le preferenze dell'utente e le informazioni sugli oggetti (in modo diverso per ogni algoritmo), avviene l'operazione di **Recommender System**, che comprende l'analisi delle preferenze utente, l'analisi delle caratteristiche degli item, il **ranking** (ordinamento) degli oggetti e la selezione delle **top-N recommendations**.

Con i *top-N recommended items* possiamo poi stilare una lista personalizzata di prodotti o contenuti da mostrare all'utente.

## Tassonomia dei Recommender Systems
![[Pasted image 20261127175710.png]]
Le strategie **non personalizzate** vengono utilizzate per mostrare qualcosa di sicuro che funziona bene a livello generale, senza adattarsi al singolo utente: ad esempio i contenuti più popolari (*Popular*), quelli aggiunti di recente (*Novel*), quelli in crescita di popolarità (*Trending*) o selezionati casualmente (*Random*).

Le strategie **personalizzate**, invece, adattano i suggerimenti (come contenuti consigliati o annunci pubblicitari) al singolo utente in base ai video cliccati e, più in generale, a ciò che guarda e con cui interagisce sulle piattaforme.
![[Pasted image 20261127180047.png]]
- **Content-Based:** raccomanda oggetti simili a quelli apprezzati in passato dall'utente analizzandone il contenuto e le caratteristiche (tramite *Keywords / TF-IDF* o *Semantic Embeddings*).
- **Collaborative Filtering:** sfrutta le preferenze e le interazioni passate di molti utenti per individuare pattern comuni, utilizzando metodi basati su vicinato (*Neighborhood*: User-/Item-kNN), fattori latenti (*Latent Factors*: MF / BPR) o reti neurali e grafi (*Neural / Graph*: NCF / LightGCN).
- **Hybrid & Knowledge-Aware:** combina più strategie tra loro (ad esempio fondendo le feature di approcci diversi con tecniche di *Feature Fusion*) oppure integra basi di conoscenza esterne, come i **Knowledge Graphs**, per migliorare la qualità delle raccomandazioni.
[Conitnuare da slide 59 a 75]