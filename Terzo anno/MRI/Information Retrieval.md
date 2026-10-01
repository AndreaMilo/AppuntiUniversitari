Per gestire la **conoscenza** bisogna saper:
- **Raccogliere** la conoscenza
- Organizzarla
- Distribuirla
- Renderla **accessibile** a chi necessita di quel tipo di informazione e nel momento e luogo in cui la richiede

Queste prassi vengono eseguite al fine di **risparmiare tempo**, riducendo i tempi di accesso all'informazione e **migliorando** la qualità dei servizi che la distribuiscono.

## Dati / Informazione / Conoscenza
La **conoscenza** è un capitale difficile da gestire, poiché è:
- volatile
- intangibile
- difficile da conservare

Per questo la maggior parte dei DB nel mondo possiede i dati in forma **non strutturata**.

L'obiettivo dell'**AKM** (Automatic Knowledge Management) è quello di costruire sistemi in grado di processare documenti in formato di **linguaggio naturale**.
## Acquisizione
L'**acquisizione** è il ritrovamento di conoscenza partendo da DB in forma testuale.
La sigla più famosa per l'acquisizione di conoscenza è proprio: "**From Text to Knowledge**"; per passare infatti dal testo grezzo alla conoscenza formale, detta **Ontology Construction**, si utilizzano diverse tecniche, come:
- *Document Classification*
- *Information Extraction*
- *Text Mining*
### Paradigma Search vs Discover
![[Pasted image 20261001190826.png]]

Per comprendere dove collocare le varie tecnologie di recupero e analisi della conoscenza, vengono posti due **assi principali**:
- **La struttura del dato** (righe): ovvero se sono dati **strutturati** o **testuali**.
- **L'intento dell'utente** (colonne): ovvero se sono specifici ad un obiettivo (**Search**) o orientati alla scoperta di altre correlazioni (**Discover**).

Dall'incrocio di questi due assi, nascono quattro paradigmi:
- **Data Retrieval**:
  Questo paradigma si concentra sul trovare una corrispondenza di dati per risolvere un unico **obiettivo** mirato. Per questo il DB è **strutturato** e l'utente troverà questa informazione tramite un **linguaggio formale** (SQL ad esempio).
  Un esempio di questo paradigma è la ricerca di un ristorante a Boston, dove sarà effettuata la sua query di ricerca.
  
- **Information Retrieval**:
  In questo caso l'utente deve cercare **documenti** in un DB **non strutturato**, essendo quindi privo di schema razionale, l'SQL classico non funziona.
  Seguendo l'esempio precedente, si ottiene la medesima informazione tramite **navigazione per categorie** (`Boston -> Resturant -> Japanese`).
  
- **Data Mining**:
  Nel Data Mining cambiano le carte in tavola. Non cerchiamo più un dato noto, ma si vuole scoprire in un DB **strutturato**, nuova **conoscenza** analizzando moli di dati strutturati.
  
- **Text Mining**:
  Nel Text Mining andremo ad eseguire la stessa ricerca effettuata nel Data Mining, solo che la conoscenza nuova da scoprire **non è nota a priori** e si analizzano direttamente **testi liberi** e non valori numerici.
### Processo di KDD
Il **Data Mining** in realtà è un sottoprocesso del grande processo di ricerca dai Databases, chiamato KDD (**Knowledge Discovery from Databases**).

>[!NOTES] Definizione di Fayyad et 1996
> Il KDD è il processo non banale di identificare pattern validi, nuovi, potenzialmente utili e comprensibili all'interno dei dati.

Le fasi del ciclo del processo KDD sono 5:
1. **Selezione**: raccolta dei dati di partenza e isolamento del sottoinsieme su cui opera.
2. **Pre-processing**: pulizia del dato eliminando file corrotti o sporchi.
3. **Trasformazione**: ridimensionamento delle dimensioni dei dati e conversione in formati adatti all'algoritmo.
4. **Data Mining**: utilizzo dei **patterns** trovati per scoprire la nuova conoscenza che ci porterà ad ulteriore conoscenza.
5. **Valutazione**: analisi critica dei pattern estratti dall'essere umano per tradurli in conoscenza utilizzabile, veritiera e concreta.

![[Pasted image 20261001192708.png]]

Come si evince da questo esempio non c'è mai una garanzia del 100% ma da piccole conoscenze già presenti possiamo notare dei pattern tra diversi dati, creando correlamenti utili per l'azienda.

### Dal Data Mining al Text Mining
Il **Text Mining** utilizza i principi del KDD sul testo a **linguaggio naturale**.
L'obiettivo è quello di scavare tra mille testi diversi fino alla ricerca di pattern, trend e associazioni nascoste, così da costruire nuova conoscenza.

>[!NOTES] Definizione Feldman e Dagan 1995
>Il *Text Data Mining*' è l'estrazione non banale di informazioni implicite, precedentemente sconosciute e potenzialmente utili a partire da grandi quantità di dati testuali.

Espressa tramite la formula concettuale: $$\text{Text Mining}=\text{Data Mining (applicata al testo)}+\text{Linguistica di base}$$
#### Processo di Text Mining
![[Pasted image 20261001193541.png]]
