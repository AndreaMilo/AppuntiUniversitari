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
[Continuare da slide 40 fino alla 50]
[Dalla 50 alla 61]
