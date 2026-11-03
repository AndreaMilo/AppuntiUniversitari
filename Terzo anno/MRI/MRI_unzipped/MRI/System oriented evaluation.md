Un modo per ovviare al problema dell’utente che non sempre da feedback diretti, oltre i feedback impliciti, un altro modo per captare più informazioni è lo **pseudo-relevance** feedback, che assume che i primi $k$ risultati di una query siano rilevanti e i restanti no. 

Nel processo di relevance feedback c’è un altro processo, ovvero quello di **query expansion**. Nella relevance feedback, le informazioni in più erano dati ai risultati ottenuti da una query esplorativa, nella query expansion, le informazioni aggiuntive vengono inserite nelle query, ad esempio con l’uso di parole più specifiche. Un esempio sono i query assistance dei browser, che generalmente sono ottenuti da query passate proprie o di altri utenti, a cui viene applicato un ulteriore sistema di ranking (proprio come per i documenti) per mostrarle all’utente.

 Le sorgenti di query expansion sono:

- Dizionari
- Analisi globale di tutti i documenti all’interno della collezione (effettuando una moltiplicazione tra la matrice dei termini $T$ e quella dei documenti $D$, ottenendo una matrice $M$; effettuando la trasposta di $M$, e moltiplicandola per $M$ iniziale si otterrebbe la matrice termini termini, che, detto in breve, mette in corrispondenza parole simili).
- Analisi dei documenti ottenuti come risultato

Un altro esempio di query expansion è quello Thesaurus-based, che aggiunge parole relative a quelle inserite nella query iniziale. Usata in ambiti scientifiche, potrebbe tuttavia aumentare l’imprecisione in caso di parole ambigue, oltre che avere alti costi di produzione e modifica.

## Valutazione dei Sistemi di Ritrovamento
C’è la necessità di capire quali sono i sistemi di ritrovamento migliori in base alle necessità che si hanno (quali operazioni di preprocessing fare, sistemi di ranking più adatti, schema di pesatura migliore, ecc..).

L’efficacia di un sistema è legato alla rilevanza, il quale è però un parametro sfumato, difficile da valutare in modo empirico.

Storicamente, la valutazione dei sistemi per il ritrovamento delle informazioni nasce grazie agli studi di Cyril Cleverdon, un bibliotecario presso il Cranfield College of Aeronautics. Nel 1952, Cleverdon usando **Uniterm**, un sistema di indicizzazione, e con l’aiuto di Bob Thorne, condusse un esperimento sulla valutazione dei sistemi di indicizzazione, che gli permisero grazie ad una sovvenzione del Nation Science Foundation, di poi condurre altri test per compararne diversi, che culminarono con la moderna misurazione della **Precisione**, la percentuale di documenti rilevanti tra quelli restituiti, e il **Richiamo**, ovvero la percentuale dei documenti restituiti tra quelli rilevanti. 

>[!WARNING] OSSERVAZIONE: 
>si noti che:
>- nella maggior parte delle ricerche un alto richiamo non è fondamentale;
> - la maggior parte degli utenti necessita di un set limitato di risultati, tra cui sceglierà quelli con un ranking maggiore.

Il primo modo di valutare l’efficienza è il **Cranfield Paradigm**, che valuta la rilevanza intesa come rilevanza dal punto di vista dell’argomento, ovvero considera i documenti che contengono informazioni sullo stesso argomento della query. Quando viene implementato un motore di ricerca, si associano a delle query un set di documenti che sappiamo essere pertinenti, cosicchè per query future il sistema sappia quale documenti associare. Gli step adottati per calcolare l’efficienza di questo sistema è:

![lez21_image.png](lez21_image.png)

Un altro metodo è quello del **Test Collection**: partendo da un corpus di documenti, si selezionano delle informazioni da ottenere, le quali saranno ottenute da un umano che manualmente dovrà assegnare delle etichette ai documenti rilevanti ciascuna informazioni necessaria (richiede troppo effort).

**Principali Collezioni di Test**
• **TREC:** Iniziativa del NIST attiva dal 1992 che fornisce un vasto ambiente di test con circa 1 milione di documenti tramite workshop annuali.   
• **Origini:** L'idea di una collezione "ideale" fu proposta da Karen Sparck Jones negli anni '70 e implementata nel progetto TREC seguendo il paradigma di Cranfield.   
• **ClueWeb09:** Dataset massiccio per il Web track contenente oltre 1 miliardo di pagine web in 10 lingue.   
• **Archivi Storici:** Includono benchmark precedenti come ISILT, UKCIS e MEDLARS. (I pokemon dei laghi per ricordare i nomi)

**Metodologia e Giudizio Umano**
• **Task Specifici:** Benchmark come la collezione Reuters definiscono precisi "compiti di recupero", spesso sotto forma di query predefinite.   
• **Etichettatura Manuale:** Gli esperti umani valutano i risultati contrassegnando esplicitamente ogni documento come "Rilevante" o "Non rilevante" per la query associata.   
• **Tecnica del Pooling:** Per gestire enormi moli di dati, l'etichettatura viene effettuata solo su un sottoinsieme di documenti (pool) effettivamente recuperati dai vari sistemi analizzati.   

### Precision and Recall
Si consideri una collezione di documenti. Si suddividano poi le collezione test di documenti rilevanti e la collezione dei documenti ritrovati da una query (sottoinsiemi della collezione di partenza).

![image.png](lez21_image%201.png)

Se fossero disgiunti, il motore di ricerca avrebbe fallito. Al contrario se fossero sovrapposti, sarebbe perfetto. Tipicamente questi stati sono irraggiungibili, la situazione più comune è infatti quella riportata, ovvero insiemi intersecati.

Uno scenario del genere ci mette a quattro situazioni possibili:

- Documenti irrilevanti e non restituiti (**True Negative** - TN)
- Documenti irrilevanti e restituiti (**False Positive** - FP) (rumore, errore)
- Documenti rilevanti e non restituiti (**False Negative** - FN) (effetto silenzio, anch’esso considerabile come errore)
- Documenti rilevanti e restituiti (**True Positive** - TP)

In base al numero di questi documenti si possono calcolare:

$precision = \frac{numero\ documenti\ rilevanti\ restituiti}{numero\ totale\ di\ documenti\ restituiti}$

ovvero l’abilità del restituire i documenti più rilevanti restituiti. Equivale alla probabilità condizionata $P(rilevanti | restituiti)$. 

$recall = \frac{numero\ documenti\ rilevanti\ restituiti}{numero\ totale \ di \ documenti \ rilevanti}$

l’abilità del trovare tra tutti i documenti, tutti quelli rilevanti, che corrisponde alla probabilità condizionata $P(restituiti | rilevanti)$.

Queste due metriche non sono sensibili al ranking.

Un esempio di sistema ad alta precisione è uno che restituisce pochi risultati, al 100% rilevanti. Uno di un sistema con alto richiamo è uno che tra 200 risultati ne ha 10 non utili.

OSSERVAZIONE: il richiamo è una funzione non decrescente rispetto al numero i documenti ritrovati, il che vuol dire che se aumento il numero di documenti nella collezione, al massimo il recall rimane costante o aumenta; per quanto riguarda la precisione, invece, questa diminuirà all’aumentare del recall o all’aumentare dei documenti restituiti.

ATTENZIONE: l’osservazione precedente non è un teorema ma una osservazione empirica!

La precisione è tendenzialmente facile da calcolare a differenza del recall, a causa della difficoltà di stimare in grandi collezioni di documenti quanti siano i documenti rilevanti.

Idealmente i documenti si comportano così:

![image.png](lez21_image%202.png)

Precision e recall sono due misure in tensione tra loro: un sistema può eccellere nella precision (restituisce pochi documenti, quasi tutti rilevanti, ma ne lascia fuori molti) oppure nel recall (restituisce quasi tutti i documenti rilevanti, ma insieme a molto rumore). Il caso ideale è quello in cui entrambe sono alte, ma nella pratica un sistema si colloca in una via di mezzo: le prestazioni non sono mai "totalmente buone" o "totalmente pessime", ma hanno diverse sfumature tra i due estremi.

Per assegnare al sistema un **unico valore** che tenga conto sia della precision che del recall serve una media. La media aritmetica però non è adatta: un sistema con recall al 50% e precision al 50% avrebbe media 50%, esattamente come un sistema con recall al 10% e precision al 90%. Con la media aritmetica i due sistemi risulterebbero equivalenti, mentre in realtà non lo sono affatto.

Si usa quindi la **media armonica**, che è alta solo se entrambi i valori sono alti. Nell'esempio precedente, con recall al 10% e precision al 90%, la media armonica vale $\frac{2 \cdot 0.1 \cdot 0.9}{0.1 + 0.9} = 0.18$, contro lo 0.5 del primo sistema. Si esprime come segue:

$F_1 = \frac{2PR}{P+R} = \frac{2}{\frac{1}{R}+\frac{1}{P}}$

Questa metrica è chiamata $F_1$ ed è un caso particolare della misura $F_\beta$, dove $\beta$ è un parametro che permette di dare più peso al recall oppure alla precision:

$F_\beta = \frac{(1+\beta^2)PR}{\beta^2 P + R} = \frac{(1+\beta^2)}{\frac{\beta^2}{R}+\frac{1}{P}}$

Il valore di $\beta$ controlla il compromesso tra le due misure:

- se $\beta = 1$ c'è equità tra precision e recall ($F_\beta = F_1$);
- se $\beta > 1$ si dà più peso al recall;
- se $\beta < 1$ si dà più peso alla precision;
- se $\beta = 0$ si ha $F_\beta = P$.

Esiste anche la **misura E**, definita come $E = 1 - F_\beta$, che misura l'errore anziché la bontà del sistema (quindi più è bassa, meglio è).

Nella pratica si usa quasi sempre $F_1$, poiché è la versione più semplice e basilare.
### Evaluating ranked results
Finora precision e recall sono state calcolate su un insieme di documenti restituiti, senza considerare l'ordine con cui compaiono. In un sistema con ranking, invece, l'utente può scorrere la lista dei risultati fermandosi dove vuole: il sistema può quindi restituire un numero qualsiasi di documenti. Prendendo i primi $k$ documenti per valori diversi di $k$ (ovvero diversi livelli di recall), si ottiene una coppia (recall, precision) per ciascun $k$. Riportando queste coppie su un grafico si ottiene la **curva precision-recall**.

![[Pasted image 20261022163941.png]]
![[Pasted image 20261022163946.png]]

Dalla curva si nota un andamento a "dente di sega": quando il documento successivo è non rilevante, la precision cala mentre il recall rimane invariato (la curva scende in verticale); quando invece è rilevante, aumentano sia il recall sia (di norma) la precision, e la curva risale. Nell'esempio della figura il denominatore del recall (1000) è il numero totale di documenti rilevanti per la query.

Il grafico di una singola query non è molto significativo: bisogna **mediare** le prestazioni su un insieme di query. Per l'$F_1$ è semplice: si calcola un valore per ogni query e il valore finale del sistema è la media aritmetica di tutti quei valori. Per le curve precision-recall c'è invece un problema tecnico: ogni query produce punti a livelli di recall diversi (che dipendono dal numero di documenti rilevanti di quella query), quindi le curve non si possono mediare direttamente.

La soluzione è confrontare le query attraverso dei **livelli di recall standard**, che sono 11 valori fissi compresi tra 0.0 e 1.0 con passo 0.1, indicati con $r_j$:

$r_j \in \{0.0, 0.1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.7, 0.8, 0.9, 1.0\}$

È come avere il grafico di una funzione di cui si conoscono solo alcuni valori e si vuole approssimare la funzione nei punti intermedi: si esegue quindi l'**interpolazione**.

Vediamo prima come calcolare precision e recall in corrispondenza di ogni documento rilevante restituito. Non si calcolano i valori in tutte le posizioni, ma solo dove compare un nuovo documento rilevante (cioè dove il recall aumenta).

![[Pasted image 20261022164856.png]]

![[Pasted image 20261022171118.png]]

Nell'esempio, il numero totale di documenti rilevanti è 6, e i documenti rilevanti compaiono nelle posizioni 1, 2, 4, 6 e 13. Come si vede in figura, nelle prime due posizioni ci azzecchiamo subito, poi ci spostiamo in posizione 4, poi in 6 e infine in 13:

- posizione 1: $R = 1/6 = 0.167$; $P = 1/1 = 1$
- posizione 2: $R = 2/6 = 0.333$; $P = 2/2 = 1$
- posizione 4: $R = 3/6 = 0.5$; $P = 3/4 = 0.75$
- posizione 6: $R = 4/6 = 0.667$; $P = 4/6 = 0.667$
- posizione 13: $R = 5/6 = 0.833$; $P = 5/13 = 0.38$

In posizione 13 c'è stato un po' di errore: per trovare il quinto documento rilevante abbiamo dovuto scorrere molti documenti non rilevanti, quindi la precision è crollata. Il sesto documento rilevante, inoltre, non viene mai restituito: il recall non raggiunge mai il 100%. Tuttavia, i primi documenti rilevanti sono posizionati molto in alto, quindi la precision resta alta ai primi livelli di recall e otteniamo comunque una buona media di informazione.

Questi dati possiamo inserirli in un grafico e studiarli. Da un punto di vista numerico, applichiamo ora a questo esempio la procedura di interpolazione, così da ricavare, a partire dai valori noti, la precision ai livelli di recall standard.

>[!NOTE] Regola
>La precision interpolata al $j$-esimo livello di recall standard è la **massima precision nota** tra tutti i livelli di recall maggiori o uguali a $r_j$:
>
>$P(r_j) = \max_{r \ge r_j} P(r)$

In pratica, per ogni $r_j$ si guardano tutti i punti misurati con recall almeno pari a $r_j$ e si prende la precision più alta. Se non esiste nessun punto con recall maggiore o uguale a $r_j$, la precision interpolata vale 0. Questa regola elimina il "dente di sega" e produce una curva non crescente.

Applicandola all'esempio appena visto (esempio 1), e a un secondo esempio in cui sono recuperati tutti e 6 i documenti rilevanti (nelle posizioni 1, 3, 5, 8, 9 e 14, per cui il recall arriva a 1.0 con $P = 6/14 = 0.429$), si ottiene:

| $r_j$ | Esempio 1 | Esempio 2 |
| ----- | --------- | --------- |
| 0.0   | 1         | 1         |
| 0.1   | 1         | 1         |
| 0.2   | 1         | 0.667     |
| 0.3   | 1         | 0.667     |
| 0.4   | 0.75      | 0.6       |
| 0.5   | 0.75      | 0.6       |
| 0.6   | 0.667     | 0.556     |
| 0.7   | 0.38      | 0.556     |
| 0.8   | 0.38      | 0.556     |
| 0.9   | 0         | 0.429     |
| 1.0   | 0         | 0.429     |

![[Pasted image 20261022165600.png]]

Così vediamo visivamente la precision confrontata con i livelli di recall standard. Il procedimento verrà approfondito in seguito.

![[Pasted image 20261022171005.png]]

Come mostrato in figura, è in questo modo che vengono paragonate e confrontate due query (o due sistemi): si sovrappongono le curve interpolate, e **la curva più vicina all'angolo in alto a destra indica le prestazioni migliori**. Nell'esempio della slide, la curva del sistema con stemming sta sopra quella del sistema senza stemming, quindi lo stemming migliora le prestazioni.
### Precision@k

I grafici sono utili, ma spesso si preferisce avere una misura riassuntiva. La **Precision@k** è la precision calcolata a un livello di retrieval fisso: è la precision dei primi $k$ risultati (valori comunemente usati sono $k = 10$ e $k = 20$).

**Pregi**:

- è adatta alla maggior parte delle ricerche web, dove all'utente interessano buoni risultati nella prima o nelle prime due pagine;
- è utile per stimare un valore di soglia (*cutoff*) $k$.

**Difetti**:

- si media male e dipende da un parametro $k$ arbitrario;
- è una misura *set-based*: non distingue tra diversi ordinamenti dello stesso numero di documenti rilevanti nei primi $k$;
- la scelta di $k$ può essere fuorviante: se $k = 10$ e la query ha solo 5 documenti rilevanti, P@10 non potrà mai raggiungere 1, nemmeno per un sistema perfetto.
### Unranked vs Ranked Misurazione
Vogliamo capire quale sia il migliore tra IRS1 e IRS2. Consideriamo due sistemi che restituiscono 10 documenti, di cui 5 sono i documenti rilevanti totali presenti nella collezione, e supponiamo che entrambi ne recuperino 3 nei primi 10 risultati, ma in posizioni diverse. Le misure senza ranking danno lo stesso valore a entrambi:

$recall = \frac{\text{documenti recuperati e rilevanti}}{\text{totale documenti rilevanti}}$, quindi $recall(IRS_1) = \frac{3}{5} = recall(IRS_2)$

$precision = \frac{\text{documenti recuperati e rilevanti}}{\text{totale documenti recuperati}}$, quindi $precision(IRS_1) = \frac{3}{10} = precision(IRS_2)$

![[Pasted image 20261022171234.png]]

Queste misure non dipendono dalla posizione dei documenti, quindi non possono distinguere i due sistemi. Servono misure che tengano conto del ranking: la **precision a una data posizione $p$**, che si calcola impostando $p$ al numero di documenti considerati, cioè i primi $p$ della lista.

![[Pasted image 20261022171423.png]]

Nell'esempio entrambi i sistemi hanno 5 documenti rilevanti nei primi 10 risultati, ma IRS1 li mette più in alto (posizioni 1, 3, 4, 6 e 8, contro 2, 3, 4, 7 e 10 di IRS2): per esempio in posizione 1 IRS1 ha $P = 1$ e $R = 0.2$, mentre IRS2 ha $P = 0$ e $R = 0$. In generale, se a una posizione $p$ la precision di IRS1 è maggiore di quella di IRS2, allora anche il recall di IRS1 è maggiore di quello di IRS2. Il motivo è che, alla stessa posizione $p$, i due sistemi hanno restituito lo stesso numero di documenti, e il numero totale di rilevanti è lo stesso: precision e recall sono entrambi proporzionali al numero di documenti rilevanti restituiti, quindi se aumenta uno aumenta anche l'altro.

![[Pasted image 20261022171518.png]]

Riportando i punti nel grafico recall-precision, la curva di IRS1 sta sopra quella di IRS2: più alta è la curva, migliore è il ranking, quindi IRS1 è il sistema migliore.

Per riassumere il confronto in un solo numero si usa l'**Average Precision (AP)**, ovvero la media dei valori di precision calcolati nelle posizioni in cui viene restituito un documento rilevante:

$AP = \frac{1}{m}\sum_{k=1}^{m} Precision(p_k)$

dove $m$ è il numero di documenti rilevanti per la query e $p_k$ è la posizione in cui compare il $k$-esimo documento rilevante. Il valore ottenuto è compreso tra 0 e 1, ed è tanto più alto quanto più i documenti rilevanti sono posizionati in alto. Un documento rilevante che non viene mai restituito contribuisce con precision pari a 0.

Calcoliamo l'Average Precision dei due sistemi dell'esempio, usando le precision nelle posizioni dei documenti rilevanti:

- $AP(IRS_1) = \frac{1 + 0.67 + 0.75 + 0.67 + 0.63}{5} = 0.74$
- $AP(IRS_2) = \frac{0.5 + 0.67 + 0.75 + 0.57 + 0.5}{5} = 0.6$

L'AP di IRS1 è maggiore, a conferma che il suo ranking è migliore.
[Continuare da slide 40 fino alla 50 dalle slide]
[Dalla 50 alla 61 ma da ciò che dice nell'audio]

---

# MAP (Mean Average Precision)
L'Average Precision (AP) ci permette di valutare di singola quesry, na per valutare le prestazioni complessive di un sistema su un intero set di query si utilizza la Mean Average Precision (MAP). 
Essa è calcolata come la media aritmetica fei valori di AP ottenuti per ciascuna query: 

$$
MAP = \frac{1}{n}\sum_{1}^{n}\frac{1}{m_{j}}\sum_{k=1}^{m_{j}}PRECISION(p=k)
$$
dove $n$ è il numero di query e $m_{j}$ è il numero di documenti rilevanti per la $j$-esima query.

Trattandosi di una media aritmetica basata su somme, le differenze di prestazioni sulle singole query possono compensarsi. Due sistemi differenti possono ottenere lo stesso valore complessivo di MAP (ad esempio 0.225) pur avendo comportamenti del tutto opposti sulle singole query.

**Gestione dei documenti non recuperati (+0):**
Se un documento rilevante per la query non viene mai restituito dal sistema, esso contribuisce comunque al calcolo con un valore di precisione pari a $0$. Questo $+0$ viene sommato al numeratore dell'AP lasciando inalterato il denominatore $m_j$ (il totale dei documenti rilevanti attesi), penalizzando direttamente l'AP del sistema per la mancata restituzione dell'informazione utile.

![[Pasted image 20261028142956.png]]

## GMAP (Geometric Mean Average Precision)
Per ovviare al problema del MAP, si utilizza la **GMAP**, che calcola la media geometrica (usando il prodotto anziché la somma).

$$
GMAP = \sqrt[n]{\prod_{n}AP_{n}}
$$

Con il prodotto, gli incrementi sui valori piccoli hanno un impatto molto più forte sul risultato finale. È una metrica ideale per testare i sistemi su query "difficili", in cui il sistema recupera pochi documenti rilevanti, poiché riflette in modo molto più fedele le differenze di efficacia.

![[Pasted image 20261028143250.png]]

### Esempio di MAP 
![[Pasted image 20261028144008.png]]

**Calcolo per la Query 1 (Q1)**
- Il sistema individua documenti rilevanti (indicati in verde) alle posizioni 1, 3 e 7 del ranking.
- I valori di precisione in queste specifiche posizioni sono rispettivamente 1/1, 2/3 e 3/7.
- L'Average Precision si ottiene sommando questi valori e dividendoli per il numero totale di documenti rilevanti per quella query (in questo caso 3): (1 + 2/3 + 3/7) / 3 = 0.69.

**Calcolo per la Query (Q2)**
- I documenti rilevanti vengono recuperati alle posizioni 1, 2, 6 e 7.
- La precisione calcolata in questi punti equivale a 1/1, 2/2, 3/6 e 4/7.
- Essendo 4 i documenti rilevanti da trovare in totale per questa query, l'Average Precision è: (1 + 1 + 3/6 + 4/7) / 4 = 0.76.

**Mean Average Precision (MAP)**
- Il MAP è la media aritmetica dei punteggi AP calcolati per tutte le singole query analizzate.
- Utilizzando i dati di Q1 e Q2, il risultato finale del sistema è: (0.69 + 0.76) / 2 = 0.72.

**Documenti rilevanti non recuperati**
Nel calcolo dell'Average Precision, la valutazione finale si basa sul numero totale dei documenti che sono effettivamente pertinenti per una determinata ricerca. La formula matematica richiede di sommare i valori di precisione ogni volta che si incontra un risultato corretto, per poi dividere questa somma per la quantità totale dei documenti rilevanti attesi. 

Se il motore di ricerca non riesce a recuperare uno o più di questi documenti utili, la formula impone che i documenti mancanti partecipino comunque alla media.

Poiché il sistema non li ha trovati, il loro contributo alla precisione è nullo: per questo si aggiunge un "+0" al numeratore, mantenendo inalterato il divisore, penalizzando così il punteggio finale per aver omesso informazioni utili. 
Il "+0", quindi, non rappresenta i documenti irrilevanti della collezione, ma simboleggia specificamente un documento **rilevante** che il sistema ha mancato di restituire.

## R-Precision
La **R-Precision** misura la precisione del sistema calcolata esattamente alla posizione $R$-esima della lista ordinata dei risultati, dove $R$ rappresenta il numero totale di documenti rilevanti presenti nella collezione per quella specifica query:

- Se per una query esistono in totale $R = 6$ documenti rilevanti e nelle prime 6 posizioni ne compaiono 4, la R-Precision sarà pari a $4/6 = 0.67$.
- Un sistema ideale raggiunge un punteggio massimo di $1.0$ (coseno).
- È una metrica utile per analizzare e confrontare il comportamento dell'algoritmo sulle singole query, ed è mediabile su tutto il set di query.

# Mean Reciprocal Rank (MRR)
## Limite delle metriche tradizionali (Precision@k)
Le metriche tradizionali come la Precision@k non sono sufficientemente sensibili all'esatta posizione dei risultati. 

![[Pasted image 20261028150826.png]]
Ad esempio, se due sistemi ($IR_1$ e $IR_2$) restituiscono entrambi 2 documenti rilevanti nei primi 5 risultati, la $Precision@5$ per entrambi sarà pari a $2/5 = 0.4$. 
Tuttavia, se $IR_2$ posiziona il primo documento rilevante al rank 1, mentre $IR_1$ lo posiziona al rank 4, è evidente che $IR_2$ offre un'esperienza utente migliore, pur ottenendo lo stesso valore di Precision@5.

## Definizione di Reciprocal Rank (RR) e MRR
Per premiare i sistemi che restituiscono la prima risposta utile nelle primissime posizioni, si definiscono:
- **Reciprocal Rank (RR):** Il reciproco del rank (posizione) a cui viene recuperato il **primo** documento rilevante per una specifica query.
$$RR = \frac{1}{rank_i}$$    
- **Mean Reciprocal Rank (MRR):** La media aritmetica dei Reciprocal Rank calcolata su un insieme di $\vert{}Q\vert{}$ query:
$$
MRR = \frac{1}{\vert{}Q\vert{}}\sum_{i=1}^{\vert{}Q\vert{}}\frac{1}{rank_{i}}
$$

### Esempio: Perché $IR_2$ è migliore di $IR_1$?
![[Schermata_20261028_153242.png]]

**Il limite della Precision@5**
Se consideriamo solo i primi 5 risultati (quelli al di sopra della linea rossa):
- **$IR_1$** restituisce **2 documenti rilevanti** (alle posizioni 4 e 5).
- **$IR_2$** restituisce **2 documenti rilevanti** (alle posizioni 1 e 2).

Calcolando la Precision@5 per entrambi i sistemi:
$$\text{Precision@5}(IR_1) = \frac{2}{5} = 0.4$$
$$\text{Precision@5}(IR_2) = \frac{2}{5} = 0.4$$
La _Precision@5_ assegna a entrambi lo stesso punteggio ($0.4$), trattandoli come **equivalenti**. Tuttavia, dal punto di vista dell'utente, **$IR_2$ è nettamente migliore** perché soddisfa il bisogno informativo già al 1° risultato.

#### La soluzione tramite Reciprocal Rank (RR)
Il **Reciprocal Rank** valuta l'esatta posizione del **primo documento rilevante** restituito dal sistema:
- **Per $IR_1$**: Il primo documento rilevante si trova alla posizione 4.
$$RR(q, IR_1) = \frac{1}{4} = 0.25$$    
- **Per $IR_2$**: Il primo documento rilevante si trova alla posizione 1.
$$RR(q, IR_2) = \frac{1}{1} = 1.0$$
Il Reciprocal Rank dimostra che **$IR_2$ è migliore di $IR_1$** ($1.0 > 0.25$), premiando il sistema che posiziona la prima risposta utile in cima al ranking.

### Esempio di calcolo del MRR
Considerando tre query di test con le rispettive posizioni del primo risultato corretto:

| **Query** | **Risultati restituiti** | **Risposta corretta** | **Posizione (Rank)** | **Reciprocal Rank (RR)** |
| --------- | ------------------------ | --------------------- | -------------------- | ------------------------ |
| **cat**   | catten, cati, cats       | cats                  | 3                    | $1/3$                    |
| **torus** | torii, tori, toruses     | tori                  | 2                    | $1/2$                    |
| **virus** | viruses, virii, viri     | viruses               | 1                    | $1/1 = 1$                |

Il valore di MRR del sistema è:
$$MRR = \frac{\frac{1}{3} + \frac{1}{2} + 1}{3} = \frac{11}{18} \approx 0.61$$
## Ambiti di applicazione del MRR
Il MRR è la metrica ideale negli scenari di ricerca in cui all'utente interessa esclusivamente **il primo risultato corretto**:
- **Sistemi di Question-Answering (QA):** Dove l'utente cerca l'unica risposta esatta a una domanda.
- **Ricerca Navigazionale:** Query mirate a raggiungere un sito specifico (es. ricerca di URL, home-page o pagine specifiche).

# Graded Relevance (Rilevanza Non Binaria)
## Limiti della rilevanza binaria
Fino a questo punto, metriche come Precision e Recall si basano su una valutazione della rilevanza strettamente binaria (un documento è o completamente rilevante o completamente non rilevante).

Nella realtà pratica:
- I documenti raramente sono bianchi o neri, ma presentano gradi sfumati di pertinenza rispetto alla query dell'utente.
- La rilevanza binaria non permette di distinguere tra un documento _altamente rilevante_ e uno solo _marginalmente o parzialmente rilevante_.

## Rilevanza Graduata (Graded / Non-Binary Relevance)

### Limiti della Rilevanza Binaria
Le metriche tradizionali come _Precision_ e _Recall_ si basano su una valutazione binaria della rilevanza (un documento è considerato o completamente rilevante o completamente non rilevante). 
Nella realtà:
- I documenti sono raramente del tutto pertinenti o del tutto irrilevanti rispetto a una query.    
- La rilevanza binaria non permette di distinguere i documenti _altamente rilevanti_ da quelli solo _marginalmente o parzialmente rilevanti_.

#### Introduzione alle Metriche Graduate
Per superare questi limiti si adottano metriche basate sulla **rilevanza graduata** (_graded relevance_):
- I giudizi di rilevanza vengono espressi su una scala a più livelli (ad esempio una scala Likert a 5 punti).
- Le risposte vengono suddivise in più categorie, come _altamente rilevante_, _parzialmente rilevante_ o _non rilevante_.

### Discounted Cumulative Gain (DCG)
La metrica **Discounted Cumulative Gain (DCG)** (Järvelin e Kekäläinen, 2002) combina in modo efficace i giudizi di rilevanza graduata. 
Si basa su due osservazioni fondamentali sull'esperienza utente:
1. **Valore dell'informazione:** I documenti fortemente rilevanti sono molto più utili di quelli solo marginalmente rilevanti.
2. **Effetto della posizione (Rank Bias):** Più un documento rilevante si trova in basso nella classifica (ovvero a un rank peggiore), meno è utile per l'utente, poiché diminuisce drasticamente la probabilità che venga esaminato.

#### Esempio di Valutazione Graduata (Scala 0-3)
Supponiamo che i risultati delle query vengano valutati su una scala da 0 a 3:
- **0:** Non rilevante
- **1:** Lievemente rilevante
- **2:** Moderatamente rilevante
- **3:** Fortemente rilevante

Considerando due query di prova $q_1$ e $q_2$, i giudizi di rilevanza associati ai documenti pertinenti sono:
- $R_{q1} = \{[d_3, 3], [d_5, 3], [d_9, 3], [d_{25}, 2], [d_{39}, 2], [d_{44}, 2], [d_{56}, 1], [d_{71}, 1], [d_{89}, 1], [d_{123}, 1]\}$
- $R_{q2} = \{[d_3, 3], [d_{56}, 2], [d_{129}, 1]\}$

_Nota:_ Lo stesso documento può avere un grado di rilevanza differente in base alla query; ad esempio, il documento $d_3$ è altamente rilevante per $q_1$, mentre il documento $d_{56}$ è solo lievemente rilevante per $q_1$ e moderatamente rilevante per $q_2$.

### Vettore di Guadagno (Gain Vector - G)
Quando un nuovo algoritmo di ranking genera una lista di risultati, gli esperti associati alla valutazione assegnano un punteggio graduato ai primi $N$ documenti (es. i primi 10-20 risultati).

La sequenza ordinata di questi punteggi di rilevanza prende il nome di **Vettore di Guadagno (Gain Vector - $G$)**.

Considerando i primi 15 documenti restituiti dal ranking per le query $q_1$ e $q_2$, i rispettivi vettori di guadagno sono:
- $G_1 = (1, 0, 1, 0, 0, 3, 0, 0, 0, 0, 2, 0, 0, 0, 0)$
- $G_2 = (0, 0, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0)$
### Guadagno Cumulato (Cumulated Gain - CG)
Il **Guadagno Cumulato (Cumulated Gain - CG)** (Järvelin e Kekäläinen, 2000) misura il guadagno totale ottenuto sommo progressivamente i punteggi di rilevanza graduata fino a una specifica posizione nel ranking.

Per la query $q_1$, la somma cumulativa viene calcolata posizione per posizione:
- Posizione 1: $1$
- Posizione 2: $1 + 0 = 1$
- Posizione 3: $1 + 1 = 2$
- e così via.

I vettori del guadagno cumulato per $q_1$ e $q_2$ risultano essere:
- $CG_1 = (1, 1, 2, 2, 2, 5, 5, 5, 5, 7, 7, 7, 7, 7, 7, 10)$
- $CG_2 = (0, 0, 2, 2, 2, 2, 2, 2, 3, 3, 3, 3, 3, 3, 3, 3, 3, 6)$

Ad esempio, il guadagno cumulato alla posizione 8 del ranking per la query $q_1$ ($CG_1[8]$) è pari a 5.

### Definizione Formale di Guadagno Cumulato (CG)
Dato il vettore di guadagno $G_j$ associato a una query di test $q_j$, il **Guadagno Cumulato ($CG_j$)** alla posizione $i$-esima del ranking è definito in modo ricorsivo:

$$CG_j[i] = \begin{cases} G_j[1] & \text{se } i = 1 \\ G_j[i] + CG_j[i-1] & \text{altrimenti} \end{cases}$$
dove $CG_j[i]$ indica il valore di guadagno cumulato ottenuto sommando i punteggi di rilevanza fino alla posizione $i$.

## Il Fattore di Sconto (Discount Factor - D)
Il solo $CG$ ha il limite di non penalizzare i documenti rilevanti posizionati in fondo al ranking. Per ovviare a ciò, viene introdotto un **fattore di sconto ($D$)** che riduce l'impatto del guadagno man mano che si scende nella classifica dei risultati (posizioni con rank più alto/peggiore):
- **Funzione di sconto:** Un fattore di sconto semplice e comunemente utilizzato è il logaritmo della posizione di ranking.
- **Logaritmi in base 2:** Considerando la base 2, il fattore di sconto vale $\log_2 2$ per la posizione 2, $\log_2 3$ per la posizione 3, e così via.
- Dividendo il guadagno graduato di ciascun documento per il relativo fattore di sconto si ottiene il **Discounted Cumulated Gain (DCG)**.

### Definizione Formale di DCG
Dato il vettore di guadagno $G_j$ per la query di test $q_j$, il vettore $DCG_j$ ad esso associato è definito formalmente come:
$$DCG_j[i] = \begin{cases} G_j[1] & \text{se } i = 1 \\ \frac{G_j[i]}{\log_2 i} + DCG_j[i-1] & \text{altrimenti} \end{cases}$$

dove $DCG_j[i]$ rappresenta il guadagno cumulato scontato calcolato alla $i$-esima posizione del ranking per la query $q_j$.

## Vettori DCG ed Effetti dello Sconto
Applicando la formula del DCG ai vettori di guadagno definiti per le query dell'esempio ($q_1$ e $q_2$), si ottengono i seguenti vettori:
- $DCG_1 = (1.0, 1.0, 1.6, 1.6, 1.6, 2.8, 2.8, 2.8, 2.8, 3.4, 3.4, 3.4, 3.4, 3.4, 4.0, 4.2)$
- $DCG_2 = (0.0, 0.0, 1.3, 1.3, 1.3, 1.3, 1.3, 1.6, 1.6, 1.6, 1.6, 1.6, 1.6, 1.6, 2.4)$

**Proprietà fondamentali del DCG:**
- I guadagni cumulati scontati risentono molto meno dei documenti rilevanti trovati nelle fasi avanzate (in fondo) al ranking.
- Scegliendo logaritmi con basi più basse, il fattore di sconto risulta ancora più accentuato (penalizzando con maggior forza le posizioni basse).

### Definizione formale di guadagno cumulato (CG)
Dato il vettore di guadagno $G_j$ associato a una query di test $q_j$, il **Guadagno Cumulato ($CG_j$)** alla posizione $i$-esima del ranking è definito in modo ricorsivo:

$$
CG_j[i] = \begin{cases} G_j[1] & \text{se } i = 1 \\ G_j[i] + CG_j[i-1] & \text{altrimenti} \end{cases}
$$

dove $CG_j[i]$ indica il valore di guadagno cumulato ottenuto sommando i punteggi di rilevanza fino alla posizione $i$.

### Il Fattore di Sconto (Discount Factor - D)
Il solo $CG$ ha il limite di non penalizzare i documenti rilevanti posizionati in fondo al ranking. Per ovviare a ciò, viene introdotto un **fattore di sconto ($D$)** che riduce l'impatto del guadagno man mano che si scende nella classifica dei risultati (posizioni con rank più alto/peggiore):
- **Funzione di sconto:** Un fattore di sconto semplice e comunemente utilizzato è il logaritmo della posizione di ranking.
- **Logaritmi in base 2:** Considerando la base 2, il fattore di sconto vale $\log_2 2$ per la posizione 2, $\log_2 3$ per la posizione 3, e così via.
- Dividendo il guadagno graduato di ciascun documento per il relativo fattore di sconto si ottiene il **Discounted Cumulated Gain (DCG)**.

### Definizione Formale di DCG
Dato il vettore di guadagno $G_j$ per la query di test $q_j$, il vettore $DCG_j$ ad esso associato è definito formalmente come:
$$
DCG_j[i] = \begin{cases} G_j[1] & \text{se } i = 1 \\ \frac{G_j[i]}{\log_2 i} + DCG_j[i-1] & \text{altrimenti} \end{cases}
$$

dove $DCG_j[i]$ rappresenta il guadagno cumulato scontato calcolato alla $i$-esima posizione del ranking per la query $q_j$.

  
### Vettori DCG ed Effetti dello Sconto
Applicando la formula del DCG ai vettori di guadagno definiti per le query dell'esempio ($q_1$ e $q_2$), si ottengono i seguenti vettori:
- $DCG_1 = (1.0, 1.0, 1.6, 1.6, 1.6, 2.8, 2.8, 2.8, 2.8, 3.4, 3.4, 3.4, 3.4, 3.4, 4.0, 4.2)$
- $DCG_2 = (0.0, 0.0, 1.3, 1.3, 1.3, 1.3, 1.3, 1.6, 1.6, 1.6, 1.6, 1.6, 1.6, 1.6, 2.4)$

**Proprietà fondamentali del DCG:**
- I guadagni cumulati scontati risentono molto meno dei documenti rilevanti trovati nelle fasi avanzate (in fondo) al ranking.
- Scegliendo logaritmi con basi più basse, il fattore di sconto risulta ancora più accentuato (penalizzando con maggior forza le posizioni basse).

### Curve medie di CG e DCG
#### Averaging over queries
Per tracciare le curve complessive di Guadagno Cumulato ($CG$) e Guadagno Cumulato Scontato ($DCG$) su un intero set sperimentale, è necessario calcolare la media dei valori ottenuti per ciascuna posizione di ranking su tutte le query di test.

Data una collezione di $N_q$ query, i valori medi $\overline{CG}[i]$ e $\overline{DCG}[i]$ alla posizione $i$-esima si calcolano come:

$$
\overline{CG}[i] = \sum_{j=1}^{N_q} \frac{CG_j[i]}{N_q}, \quad \overline{DCG}[i] = \sum_{j=1}^{N_q} \frac{DCG_j[i]}{N_q}
$$


#### Esempio di calcolo medio
Riprendendo i vettori $CG$ e $DCG$ calcolati in precedenza per le due query di test ($q_1$ e $q_2$), la media posizione per posizione produce i seguenti vettori medi:
- $\overline{CG} = (0.5, 0.5, 2.0, 2.0, 2.0, 3.5, 3.5, 4.0, 4.0, 5.0, 5.0, 5.0, 5.0, 5.0, 5.0, 8.0)$
- $\overline{DCG} = (0.5, 0.5, 1.5, 1.5, 1.5, 2.1, 2.1, 2.2, 2.2, 2.5, 2.5, 2.5, 2.5, 2.5, 3.3)$

#### Rappresentazione grafica delle curve
Fissando una soglia massima per il rank (ad esempio considerando i primi 15 risultati), è possibile tracciare l'andamento delle curve medie variando le posizioni da 1 a 15.

![[Pasted image 20261028164855.png]]
Dal grafico si nota chiaramente la differenza tra le due metriche:
- La curva $\overline{CG}$ cresce più rapidamente poiché si limita a sommare i punteggi di rilevanza.
- La curva $\overline{DCG}$ rimane molto più schiacciata verso il basso a causa dello sconto logaritmico applicato alle posizioni più avanzate del ranking.

### Metriche Ideali: ICG e IDCG
#### Limite di CG e DCG (Assenza di una Baseline)
A differenza di metriche come _Precision_ e _Recall_, i cui valori sono confrontabili rispetto a un livello di prestazione ideale assoluto (es. 100% di precisione a tutti i livelli di recall), i punteggi di $CG$ e $DCG$ non sono calcolati rispetto a una baseline standard di riferimento.

Di conseguenza:
- Risulta fuorviante e poco pratico confrontare direttamente i valori di $DCG$ grezzi ottenuti da due algoritmi di ranking differenti.
- Si rende necessario definire una baseline di riferimento ottimale per la normalizzazione: le **metriche ideali ICG e IDCG**.

#### Definizione del Vettore di Guadagno Ideale (IG)
Per una data query di test $q$, gli esperti e i valutatori umani determinano la presenza di:
- $n_3$ documenti con rilevanza 3 (altamente rilevanti)
- $n_2$ documenti con rilevanza 2 (moderatamente rilevanti)
- $n_1$ documenti con rilevanza 1 (lievemente rilevanti)
- $n_0$ documenti con rilevanza 0 (non rilevanti)

Il **Vettore di Guadagno Ideale ($IG$)** rappresenta il miglior ordinamento teoricamente possibile per quella query, ottenuto disponendo tutti i punteggi di rilevanza disponibili in ordine strettamente decrescente:
$$IG = (3, \dots, 3, 2, \dots, 2, 1, \dots, 1, 0, \dots, 0)$$

#### Esempio di Vettori Ideali ($IG$)
Ordinando in modo decrescente tutti i giudizi di rilevanza noti per le query dell'esempio precedente, si ottengono i seguenti vettori ideali:
- $IG_1 = (3, 3, 3, 2, 2, 2, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0)$
- $IG_2 = (3, 2, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)$

### Calcolo delle metriche ideali (ICG e IDCG)
Analogamente a quanto visto per $CG$ e $DCG$, è possibile calcolare i vettori per il **Guadagno Cumulato Ideale ($ICG$)** e il **Guadagno Cumulato Scontato Ideale ($IDCG$)** partendo dal vettore di guadagno ideale $IG$.

Per le due query di esempio ($q_1$ e $q_2$), i vettori ideali risultano:
- $ICG_1 = (3, 6, 9, 11, 13, 15, 16, 17, 18, 19, 19, 19, 19, 19, 19, 19)$
- $ICG_2 = (3, 5, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6)$
- $IDCG_1 = (3.0, 6.0, 7.9, 8.9, 9.8, 10.5, 10.9, 11.2, 11.5, 11.8, 11.8, 11.8, 11.8, 11.8, 11.8)$
- $IDCG_2 = (3.0, 5.0, 5.6, 5.6, 5.6, 5.6, 5.6, 5.6, 5.6, 5.6, 5.6, 5.6, 5.6, 5.6, 5.6, 5.6)$

#### Media delle metriche ideali
Calcolando la media aritmetica posizione per posizione su un set di $N_q$ query, si ricavano i vettori medi ideali $\overline{ICG}$ e $\overline{IDCG}$:
$$
\overline{ICG}[i] = \sum_{j=1}^{N_q} \frac{ICG_j[i]}{N_q}, \quad \overline{IDCG}[i] = \sum_{j=1}^{N_q} \frac{IDCG_j[i]}{N_q}
$$

Per l'esempio analizzato si ottiene:
- $\overline{ICG} = (3.0, 5.5, 7.5, 8.5, 9.5, 10.5, 11.0, 11.5, 12.0, 12.5, 12.5, 12.5, 12.5, 12.5, 12.5)$
- $\overline{IDCG} = (3.0, 5.5, 6.8, 7.3, 7.7, 8.1, 8.3, 8.4, 8.6, 8.7, 8.7, 8.7, 8.7, 8.7, 8.7)$

**Utilità del confronto:** Sovrapponendo le curve medie reali ($\overline{CG}, \overline{DCG}$) alle rispettive curve ideali ($\overline{ICG}, \overline{IDCG}$), si quantifica con precisione il margine di miglioramento teorico ancora a disposizione per l'algoritmo.

#### Differenze chiave tra ICG e IDCG

La differenza fondamentale tra **ICG** e **IDCG** risiede nell'applicazione dello **sconto posizionale logaritmico**:
- **ICG (Ideal Cumulated Gain):** Somma pura dei punteggi di rilevanza del vettore ideale $IG$, senza applicare alcuna penalizzazione sulla posizione del documento. Rappresenta la massima quantità teorica di rilevanza accumulabile ed è il denominatore usato per calcolare l'**NCG**.
- **IDCG (Ideal Discounted Cumulated Gain):** Somma dei punteggi del vettore ideale $IG$ a cui viene applicato uno sconto logaritmico ($\log_2 i$) in base al rank. Incorpora il principio per cui un documento perde valore se posizionato in basso ed è il denominatore usato per calcolare l'**NDCG**.

### DCG Normalizzato (NDCG)

#### Necessità della Normalizzazione
Mentre i valori di _Precision_ e _Recall_ sono misurati rispetto a un valore massimo teorico (100%), i punteggi grezzi di $DCG$ non sono rapportati a una scala assoluta. Ciò rende difficoltoso il confronto diretto tra due algoritmi di ranking differenti analizzati su query distinte.

Per correggere questo limite, si definiscono le metriche normalizzate **NCG** e **NDCG** dividendo i valori medi reali per i rispettivi valori medi ideali alla posizione $i$:

  $$NCG[i] = \frac{\overline{CG}[i]}{\overline{ICG}[i]}, \quad NDCG[i] = \frac{\overline{DCG}[i]}{\overline{IDCG}[i]}$$

#### Esempio e Interpretazione
Per il set di query di esempio si hanno i seguenti valori:
- $NCG = (0.17, 0.09, 0.27, 0.24, 0.21, 0.33, 0.32, 0.35, 0.33, 0.40, 0.40, 0.40, 0.40, 0.40, 0.64)$
- $NDCG = (0.17, 0.09, 0.21, 0.20, 0.19, 0.25, 0.25, 0.26, 0.26, 0.29, 0.29, 0.29, 0.29, 0.29, 0.38)$

**Proprietà:** L'area sottesa dalla curva di NDCG rappresenta l'efficacia globale del sistema. Più l'area è elevata (valori vicini a 1.0), migliore è la qualità dell'algoritmo di ranking, rendendo i punteggi normalizzati perfetti per confrontare sistemi diversi.

### Discussione sulle Metmetriche DCG
#### Svantaggi
L'ostacolo principale nell'adozione delle metriche di tipo CG/DCG risiede nel costo di valutazione: definire giudizi di rilevanza graduata su più livelli richiede un impegno umano notevolmente maggiore e più complesso rispetto alla semplice classificazione binaria.
#### Vantaggi principali
Nonostante la complessità iniziale, le metriche DCG offrono notevoli vantaggi:
1. Permettono di combinare in modo sistematico l'ordinamento (rank) e i livelli di rilevanza.
2. Il guadagno cumulato fornisce una metrica sintetica delle prestazioni a qualsiasi profondità del ranking.
3. L'accumulo progressivo evidenzia il contributo dei documenti rilevanti rendendo la metrica più resistente ad eventuali valori anomali (_outliers_).
4. Lo sconto logaritmico penalizza in maniera controllata i documenti utili posizionati troppo in fondo nella lista dei risultati.

### Metrice di Correlazione di Rank (Rank Correlation Metrics)
#### Motivazione
In diverse situazioni sperimentali:
- Non è possibile misurare direttamente la rilevanza assoluta dei documenti.
- L'obiettivo principale è misurare quanto un nuovo algoritmo di ordinamento vari rispetto a una funzione di ranking di riferimento di cui si conoscono già le proprietà.
In questi casi non si misura la rilevanza, ma si confronta l'ordinamento relativo prodotto da due classifiche mediante le **metriche di correlazione di rank**.

#### Proprietà del Coefficiente di Correlazione $C(R_1, R_2)$
Considerate due classifiche $R_1$ e $R_2$, la funzione di correlazione restituisce un coefficiente $C(R_1, R_2)$ compreso nell'intervallo $[-1, +1]$ con le seguenti proprietà:
- $C(R_1, R_2) = 1$: **Accordo perfetto** (le due classifiche producono lo stesso identico ordinamento).
- $C(R_1, R_2) = -1$: **Disaccordo perfetto** (un ordinamento è l'esatto inverso dell'altro).
- $C(R_1, R_2) = 0$: **Indipendenza totale** tra i due ordinamenti.
- Valori crescenti di $C(R_1, R_2)$ indicano un livello di accordo via via maggiore tra i due sistemi di ranking.

# Il Coefficiente di Spearman
Il coefficiente di Spearman è probabilmente la metrica di rank più utilizzata. Esso valuta l'accordo tra due classifiche $\mathcal{R}_1$ e $\mathcal{R}_2$ basandosi sulle differenze tra le posizioni occupate dallo stesso documento nei due ordinamenti.

Siano $s_{1,j}$ la posizione del documento $d_j$ nel ranking $\mathcal{R}_1$ e $s_{2,j}$ la posizione dello stesso documento nel ranking $\mathcal{R}_2$.

## Calcolo delle differenze di posizione

Considerando un insieme di $K = 10$ documenti, si calcola il quadrato della differenza di posizione $(s_{1,j} - s_{2,j})^2$ per ciascun elemento:

| **Documento** | Posizione $s_{1,J}​$ | Posizione $s_{2,J}$ | Differenza $s_{1,J}-s_{2,j}$ | Differenza al quadrato $(s_{1,j}-s_{2,j})^2$ |
| ------------- | -------------------- | ------------------- | ---------------------------- | -------------------------------------------- |
| $d_{123}$     | 1                    | 2                   | -1                           | 1                                            |
| $d_{84}$      | 2                    | 3                   | -1                           | 1                                            |
| $d_{56}$      | 3                    | 1                   | +2                           | 4                                            |
| $d_{6}$       | 4                    | 5                   | -1                           | 1                                            |
| $d_{8}$       | 5                    | 4                   | +1                           | 1                                            |
| $d_{9}$       | 6                    | 7                   | -1                           | 1                                            |
| $d_{511}$     | 7                    | 8                   | -1                           | 1                                            |
| $d_{129}$     | 8                    | 10                  | -2                           | 4                                            |
| $d_{187}$     | 9                    | 6                   | +3                           | 9                                            |
| $d_{25}$      | 10                   | 9                   | +1                           | 1                                            |
| **Somma**     |                      |                     |                              | **24**                                       |

Tracciando questi punti su un piano cartesiano (dove l'asse X rappresenta il ranking $\mathcal{R}_1$ e l'asse Y il ranking $\mathcal{R}_2$), la disposizione quasi lineare dei punti evidenzia visivamente una forte correlazione tra i due sistemi.
![[Pasted image 20261029172725.png]]
  
Per ottenere un indice quantitativo di questa correlazione, si analizzano i casi limite teorici per la somma delle differenze al quadrato su $K$ elementi:
1. **Massimo disaccordo teorico:** La somma massima possibile delle differenze al quadrato (quando un ranking è l'esatto opposto dell'altro) è data da:
$$\frac{K \times (K^2 - 1)}{3}$$
Nel nostro esempio con $K = 10$, il valore di massimo disaccordo è $\frac{10 \times (10^2 - 1)}{3} = 330$.

2. **Accordo perfetto:** Se i due ordinamenti coincidono perfettamente, le differenze sono nulle e la somma vale $0$.

Mettendo a rapporto la somma reale delle differenze al quadrato con il suo valore massimo possibile:

$$\frac{\sum_{j=1}^{K}(s_{1,j}-s_{2,j})^2}{\frac{K \times (K^2 - 1)}{3}}$$
- Il risultato è $0$ in caso di **accordo perfetto**.
- Il risultato è $+1$ in caso di **disaccordo perfetto**.

Moltiplicando questo rapporto per 2 e sottraendo l'intero blocco da 1, la scala dei valori viene traslata matematicamente per rientrare nell'intervallo desiderato tra $[-1, +1]$.

### Definizione Formale del Coefficiente di Spearman
Da questi passaggi deriva la formula ufficiale del **coefficiente di correlazione di Spearman** $S(\mathcal{R}_1, \mathcal{R}_2)$:

$$S(\mathcal{R}_1, \mathcal{R}_2) = 1 - \frac{6 \times \sum_{j=1}^{K}(s_{1,j} - s_{2,j})^2}{K \times (K^2 - 1)}$$

Sostituendo i valori dell'esempio (somma = $24$ e $K = 10$):

$$S(\mathcal{R}_1, \mathcal{R}_2) = 1 - \frac{6 \times 24}{10 \times (10^2 - 1)} = 1 - \frac{144}{990} = 0.854$$

Il risultato di $0.854$, essendo molto vicino a $+1$, conferma in modo quantitativo l'elevato livello di accordo tra le due classifiche.

#### Esempio di spearman
![[Pasted image 20261030161827.png]]
L'algoritmo vuole confrontare due ranking restituiti per lo stesso set di $K = 6$ documenti (da D1 a D6).
- **$R_1$:** D1, D2, D3, D4, D5, D6 (L'ordinamento originale/ideale)
- **$R_2$:** D3, D2, D6, D1, D4, D5 (Il nuovo ordinamento da valutare)

Per ciascun documento, si cerca la sua posizione nel primo ranking ($s_1$) e la si confronta con la sua posizione nel secondo ranking ($s_2$). Il professore calcola l'errore o differenza (indicato come $ERR = s_1 - s_2$):

- **D1:** In $R_1$ è in pos. 1, in $R_2$ è in pos. 4 $\rightarrow 1 - 4 = -3$
- **D2:** In $R_1$ è in pos. 2, in $R_2$ è in pos. 2 $\rightarrow 2 - 2 = 0$
- **D3:** In $R_1$ è in pos. 3, in $R_2$ è in pos. 1 $\rightarrow 3 - 1 = +2$
- **D4:** In $R_1$ è in pos. 4, in $R_2$ è in pos. 5 $\rightarrow 4 - 5 = -1$
- **D5:** In $R_1$ è in pos. 5, in $R_2$ è in pos. 6 $\rightarrow 5 - 6 = -1$
- **D6:** In $R_1$ è in pos. 6, in $R_2$ è in pos. 3 $\rightarrow 6 - 3 = +3$

$ERR^2$
Le differenze vengono elevate al quadrato per eliminare i segni negativi ed enfatizzare gli scostamenti maggiori, ottenendo la colonna $ERR^2$:
- $(-3)^2 = 9$
- $0^2 = 0$
- $2^2 = 4$
- $(-1)^2 = 1$
- $(-1)^2 = 1$
- $3^2 = 9$

Si procede alla somma totale di questi quadrati: $9 + 0 + 4 + 1 + 1 + 9 = \mathbf{24}$.

**Calcolo del coefficiente di Spearman ($S$)**
La formula ufficiale del coefficiente di Spearman è:

$$S(R_1, R_2) = 1 - \frac{6 \times \sum(s_1 - s_2)^2}{K \times (K^2 - 1)}$$

Sostituiamo i valori ricavati nell'esercizio, sapendo che la somma dei quadrati è $24$ e il numero totale dei documenti $K$ è $6$:

$$S(R_1, R_2) = 1 - \frac{6 \times 24}{6 \times (6^2 - 1)}$$

 Eseguendo la divisione, il valore finale del coefficiente è:

$$S(R_1, R_2) \approx \mathbf{0.31}$$

Il risultato positivo di 0.31 indica che tra le due classifiche c'è una debole ma presente concordanza (i due ranking non sono indipendenti, ma nemmeno perfettamente identici).


# Il Coefficiente Tau Kendall ($\tau$)

Il **coefficiente Tau di Kendall** ($\tau$) offre un'interpretazione più naturale ed intuitiva rispetto a Spearman, basandosi su come due ordinamenti tendono a variare in modi simili. 
Invece di misurare la distanza grezza di posizione del singolo documento, il Kendall Tau analizza l'ordinamento relativo di **coppie di documenti**.


Consideriamo due documenti $d_j$ e $d_k$ e le loro rispettive posizioni all'interno dei due ranking $\mathcal{R}_1$ e $\mathcal{R}_2$.
Si calcolano le differenze di posizione tra i due documenti in ciascun ranking:
- Differenza in $\mathcal{R}_1$: $s_{1,k} - s_{1,j}$
- Differenza in $\mathcal{R}_2$: $s_{2,k} - s_{2,j}$

Confrontando il segno di queste differenze, la coppia $[d_k, d_j]$ viene classificata come:
- **Coppia Concordante (C):** Se le due differenze hanno lo **stesso segno**. L'ordine relativo dei due documenti è conservato in entrambe le classifiche.
- **Coppia Discordante (D):** Se le due differenze hanno **segno opposto**. L'ordine relativo dei due documenti è invertito tra i due ranking.

## Esempio 
Considerando i primi $K = 5$ documenti estratti da due ranking $\mathcal{R}_1$ e $\mathcal{R}_2$:

| Documento | Posizione $s_{1,j}$ | Posizione $s_{2,j}$ | Differenza $(s_{1,j} - s_{2,j})$ |
| :-------- | :-----------------: | :-----------------: | :------------------------------: |
| $d_{123}$ |          1          |          2          |                -1                |
| $d_{84}$  |          2          |          3          |                -1                |
| $d_{56}$  |          3          |          1          |                +2                |
| $d_{6}$   |          4          |          5          |                -1                |
| $d_{8}$   |          5          |          4          |                +1                |

Il numero di coppie uniche per singolo ranking è $\frac{1}{2} \times K \times (K - 1) = \frac{1}{2} \times 5 \times 4 = 10$ coppie.

1. **Coppie ordinate in $\mathcal{R}_1$:**  
   $[d_{123}, d_{84}]$, $[d_{123}, d_{56}]$, $[d_{123}, d_{6}]$, $[d_{123}, d_{8}]$, $[d_{84}, d_{56}]$, $[d_{84}, d_{6}]$, $[d_{84}, d_{8}]$, $[d_{56}, d_{6}]$, $[d_{56}, d_{8}]$, $[d_{6}, d_{8}]$

2. **Coppie ordinate in $\mathcal{R}_2$:**  
   $[d_{56}, d_{123}]$, $[d_{56}, d_{84}]$, $[d_{56}, d_{8}]$, $[d_{56}, d_{6}]$, $[d_{123}, d_{84}]$, $[d_{123}, d_{8}]$, $[d_{123}, d_{6}]$, $[d_{84}, d_{8}]$, $[d_{84}, d_{6}]$, $[d_{8}, d_{6}]$

Considerando i due ranking insieme, vengono prodotte in totale $K(K - 1) = 5 \times 4 = 20$ coppie ordinate congiunte.

Confrontando l'ordine di ciascuna coppia:
- **Coppie Concordanti (C):** 14
- **Coppie Discordanti (D):** 6

Il coefficiente Tau di Kendall è definito come la differenza tra la probabilità che una coppia sia concordante e la probabilità che sia discordante:

$$\tau(\mathcal{R}_1, \mathcal{R}_2) = P(\mathcal{R}_1 = \mathcal{R}_2) - P(\mathcal{R}_1 \neq \mathcal{R}_2)$$

Sostituendo i valori dell'esempio:
$$\tau(\mathcal{R}_1, \mathcal{R}_2) = \frac{14}{20} - \frac{6}{20} = \frac{8}{20} = 0.4$$

#### Formalizzazione matematica
Sia $\Delta(\mathcal{R}_1, \mathcal{R}_2)$ il numero totale di coppie discordanti tra i due ranking:
- Numero di coppie concordanti = $K(K-1) - \Delta(\mathcal{R}_1, \mathcal{R}_2)$
- Probabilità di accordo:
  $$P(\mathcal{R}_1 = \mathcal{R}_2) = \frac{K(K-1) - \Delta(\mathcal{R}_1, \mathcal{R}_2)}{K(K-1)}$$
- Probabilità di disaccordo:
  $$P(\mathcal{R}_1 \neq \mathcal{R}_2) = \frac{\Delta(\mathcal{R}_1, \mathcal{R}_2)}{K(K-1)}$$

Sostituendo queste probabilità nella definizione generale si ricava la **formula sintetica del Kendall Tau**:

$$\tau(\mathcal{R}_1, \mathcal{R}_2) = 1 - \frac{2 \times \Delta(\mathcal{R}_1, \mathcal{R}_2)}{K(K-1)}$$

#### Verifica numerica 
Nel nostro esempio con $K = 5$ e $\Delta(\mathcal{R}_1, \mathcal{R}_2) = 6$ coppie discordanti:

$$\tau(\mathcal{R}_1, \mathcal{R}_2) = 1 - \frac{2 \times 6}{5(5-1)} = 1 - \frac{12}{20} = 1 - 0.6 = 0.4$$

**Proprietà fondamentali del Kendall Tau:**
- Il coefficiente è definito esclusivamente per ranking che valutano lo **stesso insieme di elementi**.
- Presenta una struttura algebrica più semplice e un'interpretazione probabilistica più diretta rispetto al coefficiente di Spearman.


Analizzando congiuntamente i due ranking, vengono prodotte in totale $K(K - 1)$ coppie ordinate. 
Nell'esempio con $K=5$, si ottengono $5 \times 4 = 20$ coppie totali.
Confrontando i set di coppie tra i due ranking, classifichiamo ogni coppia come Concordante (C) o Discordante (D). 

Contrassegnando con **C** le coppie risultate concordanti e con **D** quelle discordanti, si ottiene la classificazione completa dell'intero set di elementi per i due ranking:
- **Risultato per $\mathcal{R}_1$:** 
C, D, C, C,
D, C, C,
C, C,
D

- **Risultato per $\mathcal{R}_2$:** 
D, D, C, C, 
C, C, C, 
C, C,
D

Dal conteggio dell'esempio risultano:
- **Coppie Concordanti:** 14
- **Coppie Discordanti:** 6

Il coefficiente Tau di Kendall è definito concettualmente come la differenza tra la probabilità che una coppia sia concordante e la probabilità che sia discordante:
$$\tau(\mathcal{R}_1, \mathcal{R}_2) = P(\mathcal{R}_1 = \mathcal{R}_2) - P(\mathcal{R}_1 \neq \mathcal{R}_2)$$
Applicando i dati numerici dell'esempio:
$$\tau(\mathcal{R}_1, \mathcal{R}_2) = \frac{14}{20} - \frac{6}{20} = 0.4$$

Per generalizzare la formula, definiamo $\Delta(\mathcal{R}_1, \mathcal{R}_2)$ come il numero totale di coppie discordanti tra i due ranking. Di conseguenza:

- Il numero di coppie concordanti equivale a $K(K-1) - \Delta(\mathcal{R}_1, \mathcal{R}_2)$.    
- La probabilità di accordo è $P(\mathcal{R}_1 = \mathcal{R}_2) = \frac{K(K-1) - \Delta(\mathcal{R}_1, \mathcal{R}_2)}{K(K-1)}$.
- La probabilità di disaccordo è $P(\mathcal{R}_1 \neq \mathcal{R}_2) = \frac{\Delta(\mathcal{R}_1, \mathcal{R}_2)}{K(K-1)}$.

Sostituendo queste probabilità nella definizione generale, si ottiene la **formula sintetica del coefficiente Tau di Kendall**:
$$\tau(\mathcal{R}_1, \mathcal{R}_2) = 1 - \frac{2 \times \Delta(\mathcal{R}_1, \mathcal{R}_2)}{K(K-1)}$$

Applicando quest'ultima formula all'esempio in cui $K = 5$ e $\Delta(\mathcal{R}_1, \mathcal{R}_2) = 6$, il calcolo conferma il risultato precedente:

$$\tau(\mathcal{R}_1, \mathcal{R}_2) = 1 - \frac{2 \times 6}{5(5-1)} = 0.4$$

**Proprietà fondamentali del Kendall Tau:**
- Il coefficiente è definito esclusivamente per confrontare classifiche che valutano esattamente lo **stesso insieme di elementi**.
- La sua importanza risiede nell'avere una struttura algebrica molto più semplice e un'interpretazione più intuitiva rispetto al coefficiente di Spearman.

#### Esempio di Kendal 

![[Pasted image 20261030164450.png]]
![[Pasted image 20261030162856.png]]

L'esercizio richiede di calcolare il **Coefficiente Tau di Kendall ($\tau$)**.
I ranking di partenza per $K=6$:
- **$R_1$:** D1, D2, D3, D4, D5, D6
- **$R_2$:** D3, D2, D6, D1, D4, D5

Il numero totale di coppie uniche che si possono formare con 6 documenti in un singolo ranking è dato dalla formula $\frac{1}{2} \times K \times (K - 1) = \frac{1}{2} \times 6 \times 5 = 15$ coppie.
Il vengono elencate le 15 combinazioni per $R_1$ e, parallelamente, le 15 combinazioni per $R_2$, mantenendo l'ordine in cui appaiono:

- **Coppie di $R_1$:** (D1 D2) (D1 D3) (D1 D4) (D1 D5) (D1 D6) ...fino a (D5 D6).    
- **Coppie di $R_2$:** (D3 D2) (D3 D6) (D3 D1) (D3 D4) (D3 D5) ...fino a (D4 D5).


**Classificazione delle coppie (Concordanti vs Discordanti)**
Confrontando le due liste, dobbiamo determinare se l'ordine relativo tra due documenti si è mantenuto o si è invertito passando da $R_1$ a $R_2$. 

Ricordiamo l'ordine esatto dei due ranking:
- **$R_1$:** D1, D2, D3, D4, D5, D6
- **$R_2$:** D3, D2, D6, D1, D4, D5

La regola fondamentale è osservare l'ordine di lettura (da sinistra verso destra). Poiché tutte le coppie estratte da $R_1$ hanno il primo documento che precede il secondo in $R_1$, bisogna solo verificare se in $R_2$ quello stesso ordine viene mantenuto (**Concordante - C**) o viene invertito (**Discordante - D**).

Per tutte le 15 coppie generate da $R_1$:

**Gruppo 1 (Coppie con D1)**
- **(D1 D2):** In $R_1$ D1 precede D2. In $R_2$ troviamo D2 prima di D1 $\rightarrow$ Invertito: **Discordante (D)**.
- **(D1 D3):** In $R_1$ D1 precede D3. In $R_2$ troviamo D3 prima di D1 $\rightarrow$ Invertito: **Discordante (D)**.
- **(D1 D4):** In $R_1$ D1 precede D4. In $R_2$ D1 è ancora prima di D4 $\rightarrow$ Confermato: **Concordante (C)**.
- **(D1 D5):** In $R_1$ D1 precede D5. In $R_2$ D1 è ancora prima di D5 $\rightarrow$ Confermato: **Concordante (C)**.
- **(D1 D6):** In $R_1$ D1 precede D6. In $R_2$ troviamo D6 prima di D1 $\rightarrow$ Invertito: **Discordante (D)**.

**Gruppo 2 (Coppie con D2)**
- **(D2 D3):** In $R_1$ D2 precede D3. In $R_2$ troviamo D3 prima di D2 $\rightarrow$ Invertito: **Discordante (D)**.
- **(D2 D4):** In $R_1$ D2 precede D4. In $R_2$ D2 è ancora prima di D4 $\rightarrow$ Confermato: **Concordante (C)**.
- **(D2 D5):** In $R_1$ D2 precede D5. In $R_2$ D2 è ancora prima di D5 $\rightarrow$ Confermato: **Concordante (C)**.
- **(D2 D6):** In $R_1$ D2 precede D6. In $R_2$ D2 è ancora prima di D6 $\rightarrow$ Confermato: **Concordante (C)**.

**Gruppo 3 (Coppie con D3)**
- **(D3 D4):** In $R_1$ D3 precede D4. In $R_2$ D3 è ancora prima di D4 $\rightarrow$ Confermato: **Concordante (C)**.
- **(D3 D5):** In $R_1$ D3 precede D5. In $R_2$ D3 è ancora prima di D5 $\rightarrow$ Confermato: **Concordante (C)**.
- **(D3 D6):** In $R_1$ D3 precede D6. In $R_2$ D3 è ancora prima di D6 $\rightarrow$ Confermato: **Concordante (C)**.

**Gruppo 4 (Coppie con D4)**
- **(D4 D5):** In $R_1$ D4 precede D5. In $R_2$ D4 è ancora prima di D5 $\rightarrow$ Confermato: **Concordante (C)**.
- **(D4 D6):** In $R_1$ D4 precede D6. In $R_2$ troviamo D6 prima di D4 $\rightarrow$ Invertito: **Discordante (D)**.

**Gruppo 5 (Coppia con D5)**
- **(D5 D6):** In $R_1$ D5 precede D6. In $R_2$ troviamo D6 prima di D5 $\rightarrow$ Invertito: **Discordante (D)**.

Eseguendo il confronto per tutte le 15 coppie di $R_1$, ottenendo il seguente schema: 
D, D, C, C, D D, C, C, C C, C, C C, D D

Dal set di 15 coppie del primo ranking ($R_1$) risultano:
- **Coppie Discordanti (D):** 6
- **Coppie Concordanti (C):** 9


Come verifica, ripetendo l'operazione prendendo come base $R_2$ e cercando in $R_1$, i risultati si specchiano perfettamente, fornendo altre 6 D e 9 C. 
Unendo le due analisi congiunte, otteniamo in totale $K(K-1) = 6 \times 5 = 30$ coppie ordinate complessive (2 volte 15). Su 30 coppie totali avremo:

- Totale Discordanti = $6 + 6 = 12$    
- Totale Concordanti = $9 + 9 = 18$

**Kendall Tau** $\tau$ 
Il coefficiente Tau ($\tau$) è definito come la probabilità che le due classifiche concordino meno la probabilità che discordino:

  $$\tau(R_1, R_2) = P(R_1 = R_2) - P(R_1 \neq R_2)$$
Sostituiamo con le frazioni calcolate sul totale delle 30 coppie:
$$\tau(R_1, R_2) = \frac{18}{30} - \frac{12}{30}$$
Eseguendo la sottrazione:
$$\tau(R_1, R_2) = \frac{6}{30} = 0.2$$

  Il risultato di 0.2 indica una concordanza debole (ma positiva) tra i due ranking. 
  Si nota che per lo stesso set di documenti, Spearman aveva restituito 0.31, mentre Kendall restituisce un valore più conservativo di 0.2, pur confermando lo stesso andamento generale positivo.