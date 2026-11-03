Per avviare un progetto è necessario partire da un'idea chiara e ben consolidata, così da individuare le soluzioni progettuali migliori per la sua implementazione.
Le fasi principali per trasformare l'idea in un sistema concreto sono:
- **Comprendere il contesto d'uso**, gli utenti e i loro compiti, analizzando i casi d'uso e i sistemi già esistenti
- **Sfruttare la conoscenza esistente**, applicando standard e linee guida di progettazione (come la norma **ISO 9241**)
- **Realizzare i prototipi** per progettare le soluzioni
- **Valutare i prototipi** insieme agli utenti

Ma cos'è un prototipo?
Secondo lo standard **ISO 9241-210**, il prototipo è la rappresentazione di tutto o di una parte di un sistema o prodotto che, sebbene limitata in qualche modo, può essere utilizzata a scopo di analisi, progettazione e valutazione.

Rappresenta quindi la base concreta su cui validare l'idea progettuale prima di procedere con lo sviluppo vero e proprio.
![[Pasted image 20261103143806.png]]

### Perché usiamo i prototipi
Secondo lo standard ISO 9241-210, l'uso dei prototipi è fondamentale perché permette di raccogliere feedback già nelle fasi iniziali del progetto, rende più esplicite le decisioni progettuali, migliora la qualità e la completezza delle specifiche e consente di esplorare diverse alternative di design.

### Classificazione dei prototipi
I prototipi possono essere classificati in base a cinque dimensioni:
- Scopo
- Modalità d'uso
- Fedeltà
- Completezza funzionale
- Durata

#### Scopo
In base a ciò che si vuole indagare (modello di Houde & Hill), lo scopo si divide in:
- **Ruolo**: valuta la funzione e l'utilità del prodotto nel contesto di vita dell'utente
- **Interfaccia (Look & Feel)**: esplora l'aspetto visivo e le modalità di interazione sensoriale tra utente e prodotto
- **Implementazione**: verifica la fattibilità tecnica e il funzionamento reale del sistema
![[Pasted image 20261103144146.png]]

#### Modalità d'uso
La modalità di fruizione del prototipo può essere:
- **Statica**: rappresentazioni fisse consultabili in sequenza, come sketch, storyboard (simili a quelli cinematografici) o diagrammi
- **Dinamica**: rappresentazioni che mostrano l'evoluzione nel tempo senza intervento diretto dell'utente, come animazioni o video dimostrativi
- **Interattiva**: sistemi che permettono all'utente di interagire direttamente con il prototipo simulando l'uso reale

#### Fedeltà
La fedeltà indica quanto il prototipo assomigli al prodotto finale e si divide in **bassa e alta**:
- **Bassa fedeltà (Low-Fi)**: il prototipo è distante dall'aspetto grafico definitivo; viene realizzato in modo rapido ed economico (spesso su carta) per testare i concetti di base
- **Alta fedeltà (High-Fi)**: il prototipo offre una rappresentazione visiva e interattiva molto vicina al prodotto finale

#### Completezza funzionale
Indica quante funzionalità sono effettivamente implementate rispetto al sistema finale:
- **Prototipo orizzontale**: riproduce l'intera superficie dell'interfaccia (es. tutti i menu e le schermate principali), ma senza implementare in profondità le singole funzioni
- **Prototipo verticale**: implementa in modo approfondito e completo solo un numero ristretto di funzionalità specifiche
- **Scenario**: simula un percorso d'uso specifico e predefinito, seguendo un'unica sequenza di azioni per uno specifico task
![[Pasted image 20261103144512.png]]

#### Durata
In base al ciclo di vita nel processo di sviluppo, i prototipi si dividono in:
- **Usa e getta (Throwaway)**: come gli schizzi su carta o i primi wireframe su Figma; servono solo a chiarire i requisiti o testare un'idea iniziale e vengono poi scartati prima della scrittura del codice finale.
![[Pasted image 20261103144704.png]]

- **Evolutivi**: come le app pilota o i prototipi sviluppati su framework software definitivi; il prototipo non viene buttato, ma viene conservato, raffinato e integrato progressivamente fino a diventare il prodotto finale.
![[Pasted image 20261103144715.png]]

### Il processo di prototipazione
La prototipazione accompagna le diverse fasi del ciclo di progettazione attraverso livelli crescenti di dettaglio:
- **Prototipi iniziali**: schizzi su carta o wireframe per esplorare idee e struttura generale
- **Prototipi intermedi**: introduzione dei primi aspetti grafici, del layout e dei flussi di navigazione principali
- **Prototipi finali**: sistema ad alta fedeltà, quasi completo nei dettagli visivi e funzionali

## Paper prototyping
*Domanda: Non sarebbe utile capire cosa vogliono gli utenti prima ancora di iniziare a scrivere codice?*
- Realizzare prototipi su carta permette proprio questo, anche se può sembrare controintuitivo testare un'interfaccia utente senza usare un computer
- Con i prototipi su carta si **massimizza il feedback minimizzando lo sforzo** e i costi di realizzazione
- Bastano pochi test di usabilità su carta per raccogliere informazioni sufficienti a capire se la direzione progettuale intrapresa è quella corretta

### In cosa consiste?
Il **Paper prototyping** è un metodo di test di usabilità applicato alle interfacce software che si articola in diverse fasi:
1. Si definiscono i task (compiti) che l'utente dovrà svolgere durante il test
2. Si disegnano su carta le schermate e tutti gli elementi dell'interfaccia necessari per completare i task (finestre, menu, finestre di dialogo, pulsanti, ecc.)
3. Si simula l'interazione: un membro del team svolge il ruolo del "computer", spostando e sostituendo i fogli di carta in risposta alle azioni dell'utente per simulare il comportamento del sistema
4. Si chiede agli utenti di svolgere compiti realistici interagendo direttamente con i modelli cartacei (usando il dito come cursore e scrivendo su post-it o nastri rimovibili)

Durante la sessione:
- Un **facilitatore** (tipicamente un esperto di usabilità) conduce il test, mentre gli altri membri del team osservano in silenzio e prendono appunti
- Chi interpreta "il computer" non deve parlare né dare spiegazioni sull'interfaccia, ma limitarsi a reagire meccanicamente agli input dell'utente cambiando le schermate cartacee
- In caso di problemi evidenti di comprensione, il prototipo su carta può essere modificato rapidamente "al volo" tra una sessione e l'altra per correggere subito i difetti più semplici

### Accuratezza
Un buon prototipo su carta deve puntare sulla **chiarezza dei contenuti e delle etichette**, non sull'estetica. L'obiettivo è verificare se la logica dell'interfaccia e il flusso di navigazione funzionano; i dettagli puramente visivi verranno curati nelle fasi successive.
![[Pasted image 20261103145204.png]]

Più velocemente si realizza il prototipo cartaceo, prima emergono eventuali lacune progettuali. Non serve che le icone, le immagini o i loghi siano definitivi: basta abbozzarne l'ingombro con uno schizzo e un'etichetta descrittiva per far capire cosa ci sarà in quel punto, concentrandosi esclusivamente sul funzionamento di base.
## Paper prototyping: analisi
I **pro** del paper prototyping sono:
- Verificare se i concetti sono chiari all'utente
- Verificare se i passi presentati sono quelli che si aspettano gli utenti e se manca qualche informazione che l'utente ci aveva richiesto
- Verificare se le informazioni sono poche o ci sono informazioni inutili

I **contro** del paper prototyping sono:
- Si possono creare prototipi che non possono essere implementati: per evitarlo deve esserci almeno una persona in grado di capire i vincoli tecnici presenti in una soluzione
- Attendere i tempi di risposta dell'utente
- L'uso dello scrolling, in particolare per le pagine web, è da evitare, così anche per i prototipi su carta e così l'utente non potrà capire se quella sezione di pagina sarà visibile o meno dallo scrolling
- Con i prototipi su carta è difficile comprendere come l'interfaccia finale sarà mostrata su schermo. È una buona idea coinvolgere un designer nel prototipo cartaceo, perché potrebbe fare osservazioni che influenzano il progetto
### Quanto devono essere fedeli i prototipi?
Uno studio di **Virzi et al. (CHI '96)** ha confrontato sperimentalmente prototipi a bassa e ad alta fedeltà, dimostrando che **i problemi di usabilità individuati sono gli stessi** lungo tutto il ciclo di vita del software. Di conseguenza, risulta molto più vantaggioso ed economico utilizzare prototipi a **bassa fedeltà**.
## Altre tecniche di prototipazione iniziale
### Wireframe
I **wireframe** (termine derivato dalla grafica computerizzata) sono prototipi a **bassa fedeltà** e di tipo **usa e getta** che rappresentano lo scheletro strutturale dell'interfaccia (es. prototipi di navigazione per testare i link e confrontare il layout responsive tra desktop e mobile).
### Prototipi ipertestuali
Sono costituiti da una sequenza di schermate statiche (**snapshot**), dove ogni schermata corrisponde a una slide o a un frame (es. in Figma) su cui vengono definite **aree cliccabili** (pulsanti, campi) collegate ad altri frame per simulare la navigazione:
- **Limiti e soglia di gestibilità**: consentono solo interazioni semplici di tipo *point & click*. Per sistemi complessi, al fine di non superare la soglia di gestibilità, si realizzano **prototipi separati**, ciascuno dedicato a uno specifico aspetto del sistema (es. un prototipo per le chiamate, uno per la rubrica, uno per la chat e uno per le notifiche).
- **Combinazione Carta + Digitale**: il flusso ottimale prevede di costruire e testare prima un prototipo su carta a bassa fedeltà; una volta consolidata la soluzione, la si trasforma in un prototipo digitale navigabile ad alta fedeltà (es. in Figma, aiutandosi con **design stencil e librerie preconfezionate** come i kit ufficiali iOS/macOS o Material Design) per condurre nuovi test con gli utenti.

### Mago di Oz (Wizard of Oz)
È una tecnica di prototipazione interattiva in cui **l'utente crede di interagire con un sistema informatico autonomo, ma in realtà interagisce con un essere umano** nascosto (il "Mago") che simula le risposte del software in tempo reale. È particolarmente utile per testare sistemi complessi prima di svilupparli, come un assistente conversazionale basato su IA in cui un ricercatore digita manualmente le risposte in tempo reale.
## Prototipi intermedi e finali
### Prototipi intermedi
Permettono di testare **aspetti specifici** del prodotto, ma non ancora le sue funzioni complessive (che saranno verificabili solo alla fine). Una volta definito il *design concept*, vengono sviluppati utilizzando direttamente le **tecnologie finali**: in questo modo il sistema cresce in modo evolutivo per **ampliamenti successivi** e modesti rifacimenti a partire da una **base di codice iniziale**.
### Prototipi finali
Rappresentano il **sistema sostanzialmente completo**. Se il processo di progettazione è stato condotto correttamente nelle fasi precedenti, i test sui prototipi finali non dovrebbero riservare sorprese, ma restano fondamentali perché solo a questo stadio è possibile effettuare **prove complete su compiti reali (e non simulati)**.
- **Esempio (sito di e-commerce)**: il prototipo finale corrisponde al sito completo con contenuti definitivi, funzionalità collaudate e una **base di dati reale** (o significativa), su cui eseguire test sofisticati in scenari d'uso completi e ad alta complessità.