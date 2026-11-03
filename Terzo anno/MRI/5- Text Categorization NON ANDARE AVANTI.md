# Introduzione
## Il ritrovamento dell'informazione: ricerca basata su Query
Lo studio dei sistemi di **Information Retrieval (IR)** si concentra tipicamente sulla risoluzione di un problema fondamentale: data una *query* (che rappresenta il bisogno informativo dell'utente) e una vasta *collezione di documenti*, come restituire i risultati più pertinenti nel miglior ordine possibile.

Per analizzare e misurare rigorosamente l'efficacia di tali sistemi, si ricorre a concetti e strumenti analitici specifici:
- Lo studio dell'utilità e della rilevanza (in forma binaria e graduata).
- Le metriche di valutazione assolute (Precision, Recall, F-measure).
- Le metriche avanzate per la valutazione dei risultati ordinati (Precision@k, AP, MAP, MRR, nDCG).
- I metodi per confrontare matematicamente le variazioni tra due classifiche (Coefficienti di correlazione di Rank: Spearman e Kendall Tau).

In questo scenario classico, la rilevanza è intrinsecamente dinamica, poiché dipende strettamente dall'interrogazione che l'utente formula di volta in volta.

Oltre alla normale ricerca di informazioni, nasce spesso il bisogno di ordinare e dividere automaticamente enormi quantità di documenti all'interno di categorie o argomenti decisi in partenza.

Questo scenario introduce formalmente il dominio della **Text Categorization** (Classificazione del Testo) e del **Machine Learning** (Apprendimento Automatico). 
Mentre nell'IR tradizionale il motore di ricerca restituisce documenti in risposta a un'interrogazione mirata, nella Text Categorization il sistema (definito *classificatore*) analizza il contenuto di un testo per determinare in autonomia a quale **categoria fissa** debba essere assegnato (ad esempio, stabilire se un'email sia "Spam" o "Non Spam", oppure se un articolo giornalistico tratti di "Sport" o "Politica").

Tale transizione segna l'adozione di un nuovo approccio metodologico: il sistema non si limita più a "cercare" l'informazione, ma deduce pattern e regole a partire da dati storici etichettati (fase di *training*) al fine di prevedere con accuratezza l'assegnazione corretta per i dati futuri.
  

# Text Categorization (Categorizzazione dei Testi)

## Outline del problema
Il processo di classificazione e categorizzazione dei testi (Text Categorization - TC) coinvolge diverse fasi e concetti fondamentali:
1. **Definizione del problema:** Cos'è la categorizzazione e come viene impostata.
2. **Machine Learning (ML) e Text Categorization:** L'uso di algoritmi di apprendimento automatico per automatizzare il processo.
3. **Indexing (Indicizzazione):** La rappresentazione formale e la preparazione dei documenti di testo.
4. **Costruzione di un classificatore (Building a Classifier):** L'addestramento del modello.
5. **Valutazione (Evaluation):** Misurazione dell'efficacia del modello creato.
6. **Applicazioni pratiche:** Dove vengono utilizzati il Machine Learning, il Text Categorization e l'Information Retrieval.

## Il Task della Classificazione
Il compito principale della classificazione richiede due input fondamentali per definire formalmente il problema:
- **Dati:** Viene fornita la descrizione di un'istanza generica, indicata con $x \in X$, dove $X$ rappresenta l'intero **spazio delle istanze** (ovvero l'insieme di tutti i possibili oggetti che vogliamo classificare).
- **Categorie:** Esiste un insieme finito e predefinito di categorie, indicato con $C = \{c_1, c_2, ... c_n\}$.

L'**obiettivo** (o task) è determinare a quale categoria appartiene l'istanza $x$. Matematicamente, questo significa trovare una funzione $c(x) \in C$. La funzione $c(x)$ è detta **funzione di classificazione**: prende in input un elemento dal dominio $X$ (lo spazio delle istanze) e restituisce un valore appartenente al codominio $C$ (l'insieme delle categorie).

## Machine Learning for Categorization (Apprendimento Automatico per la Categorizzazione)

Nel Machine Learning, un algoritmo impara a classificare partendo da **esempi di training (addestramento)**. Un singolo esempio di training è composto da un'istanza $x \in X$ accoppiata alla sua corretta categoria di appartenenza preassegnata $c(x)$. L'esempio assume quindi la forma della tupla $<x, c(x)>$. In questa fase, la vera funzione di classificazione $c$ non è nota al sistema.

Dato un intero insieme di esempi di training $D$, l'obiettivo dell'algoritmo di Machine Learning è:

- **Trovare un'ipotesi di funzione di classificazione**, chiamata $h(x)$, che simuli la funzione vera.

**Condizione di Consistenza:** Un'ipotesi $h(x)$ si definisce _consistente_ rispetto all'insieme di addestramento se, per ogni singolo esempio di training fornito, la categoria prevista dall'ipotesi corrisponde esattamente a quella vera. In termini formali:
$$
\forall <x, c(x)> \in D : h(x) = c(x)
$$

  

## Esempio sample category learning problem
Consideriamo un problema in cui lo **spazio delle istanze** è descritto da tre attributi: `<size, color, shape>` (dimensione, colore, forma).

- I valori possibili sono: 
	- `size` $\in$ {small, medium, large}
	- `color` $\in$ {red, blue, green}
	- `shape` $\in$ {square, circle, triangle}
- Le categorie possibili sono due: $C = \{\text{positive, negative}\}$.

Il nostro dataset di training $D$ è formato dai seguenti esempi:

|**Example**|**Size**|**Color**|**Shape**|**Category**|
|---|---|---|---|---|
|1|small|red|circle|positive|
|2|large|red|circle|positive|
|3|small|red|triangle|negative|
|4|large|blue|circle|negative|

Il sistema dovrà imparare da questa tabella le "regole" che determinano se un oggetto è positivo o negativo.

## Generalizzazione vs Memorizzazione
L'obiettivo reale dell'apprendimento non è semplicemente imparare a memoria il set di addestramento, ma **generalizzare** le osservazioni.
- Memorizzare gli esempi assicura la _consistenza_ su quei dati specifici, ma fallisce quando si presenta una nuova istanza mai vista prima.
- Il processo di apprendimento (learning) mira invece a costruire un **modello generale di classificazione**, capace di estrapolare le regole sottostanti per classificare correttamente nuove istanze non presenti nel training set.

## Text categorization (Definizione e Applicazioni)
Il termine **Text Categorization** (o classificazione del testo) si riferisce al processo automatico che assegna una o più etichette di categoria a testi scritti in linguaggio naturale.

Le principali **applicazioni** di questa tecnologia includono:
- **Pagine Web:** Sistemi di raccomandazione (Recommending) e organizzazione delle pagine in directory (come il vecchio sistema di classificazione di Yahoo).
- **Messaggi Newsgroup:** Filtraggio dello spam (spam filtering) e suggerimento di gruppi di interesse (recommending).
- **Articoli di Notizie:** Creazione di giornali personalizzati in base agli interessi dell'utente (Personalized newspaper).
- **Email:** Suddivisione automatica delle email in cartelle (Folderizing) e blocco della posta indesiderata (spam filtering).

## Definizione Formale del Problema

Formalmente, il problema della Text Categorization (TC) consiste nell'approssimare una funzione obiettivo (target):
- **Funzione target ($\Phi'$):** $\Phi' : D \times C \rightarrow \{T, F\}$   
- **Funzione approssimante ($\Phi$):** $\Phi : D \times C \rightarrow \{T, F\}$
 

Dove:

  

- $D$ è l'insieme totale dei documenti.
    
      
    
- $C$ è l'insieme predefinito delle categorie.
    
      
    
- $\{T, F\}$ sono i valori booleani True e False.
    
      
    

La funzione approssimante $\Phi$ prende il nome di **classificatore** e il suo scopo è risultare il più fedele e aderente possibile alla vera (ma incognita) funzione target $\Phi'$.

  

### Single-label vs Multi-label

L'assegnazione delle categorie può avvenire secondo due approcci principali:

  

1. **Single-label (Assegnazione singola):** Viene assegnata una e una sola classe ad ogni documento (classificazione binaria).
    
      
    
2. **Multi-label (Assegnazione multipla):** È possibile assegnare una o più classi contemporaneamente allo stesso documento.
    
      
    

L'approccio _single-label_ è applicabile solo assumendo che vi sia un'indipendenza tra le categorie (ipotesi solitamente vera nella pratica).

  

**Il caso Single-label Binario:** Se si utilizza il single-label binario per classificare un documento in un insieme di categorie $C$, il problema viene scomposto. Risolvere questa classificazione vuol dire risolvere esattamente $\vert{}C\vert{}$ (cardinalità di $C$) problemi di categorizzazione single-label binari indipendenti (es. "Il documento appartiene a $C_1$? Sì/No", "Appartiene a $C_2$? Sì/No", ecc.). Questo caso specifico è:

  

- Il più generale.
    
      
    
- Utilizzato molto frequentemente nella pratica.
    
      
    
- Il più studiato e dettagliato in letteratura.
    
      
    

## Tipologie di Algoritmi per la Classificazione del Testo

Gli algoritmi di Machine Learning per la classificazione si dividono in tre grandi famiglie in base all'uso dei dati di addestramento:

  

1. **Supervised learning (Apprendimento Supervisionato):**
    
      
    - I dati di training vengono forniti in input al sistema.
        
          
        
    - Ogni documento di training ha la propria classe di appartenenza (etichetta) già esplicitata.
        
          
        
2. **Unsupervised learning (Apprendimento Non Supervisionato):**
    
      
    - Non viene fornito alcun dato di training etichettato. Il sistema deve dedurre autonomamente la struttura o i raggruppamenti dei dati.
        
          
        
3. **Semi-supervised learning (Apprendimento Semi-supervisionato):**
    
      
    - Fornisce all'algoritmo una piccola quantità di dati di training etichettati, combinata con una mole molto più grande di dati non etichettati per addestrare il modello.
        
          
        

### Tassonomia degli Algoritmi Non Supervisionati (Unsupervised)

Gli algoritmi che operano senza dati di training si dividono in due rami principali:

  

- **Clustering (Raggruppamento):**
    
      
    - _Partitional Clustering:_ es. K-means, Bisecting K-means.
        
          
        
    - _Agglomerative (Hierarchical) Clustering:_ es. Single Link, Complete Link, Average Link.
        
          
        
- **Naive Text Classification:**
    
      
    - _Text Classification by Direct Match:_ es. Vector Model.
        
          
        

### Tassonomia degli Algoritmi Supervisionati (Supervised)

Gli algoritmi che sfruttano set di addestramento (Training Set) includono diverse tipologie di approcci:

  

- **Decision Trees (Alberi di Decisione):** Algoritmi basati su DT.
    
      
    
- **Nearest Neighbors (K-NN):** Metodi basati sulla vicinanza (kNN standard, Weighted kNN).
    
      
    
- **Relevance Feedback:** Adattamento di tecniche di IR, come il classificatore di _Rocchio_ o Rocchio in a Query Zone.
    
      
    
- **Naive Bayes (Probabilistici):** Binary Independence Naive Bayes, Multinomial Naive Bayes.
    
      
    
- **Support Vector Machines (SVM):** Metodi matematici avanzati (SVM classici, SVM Multi-classe, SVM Multi-kernel).
    
      
    
- **Ensemble:** Modelli che combinano più classificatori insieme, come lo Stacking-based Ensemble o il Boosting-based Ensemble.