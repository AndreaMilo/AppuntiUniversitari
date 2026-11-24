Per capire bene cosa si intende per errore, ovvero il **disagio** percepito dall'utente, la classificazione ISO ha creato una classificazione dell'**errore umano**.
Gli errori possono essere:
- Azione **Intenzionale**
- Azione **Spontanea**
- Azione **non intenzionale** (dato dal **Lapsus**): Il lapsus è dato da un errore involontario dato dalla sostituzione di azioni o comportamenti al posto di farne altre.
  Il lapsus è un errore non intenzionale e per questo è **prevenibile**, un buon progettista dev'essere in grado di pensare a più lapsus che l'utente possa eseguire, così da prevenirli, ma prevenirli tutti è quasi impossibile.
- **Mistake**
![[Pasted image 20261124135404.png]]

>[!NOTE] Secondo lo standard ISO 9241-110
>I sistemi che permettono all'utente di raggiungere gli obiettivi desiderati nonostante gli errori compiuti, viene definito **Sistema error-tolerant**

James Reason sullo studio degli errori definisce la descrizione dell'errore:

>[!NOTE] Definizione Errore
>Termine generico per comprendere tutti quei casi in cui una sequenza pianificata di attività fisiche o mentali fallisce il suo scopo, e quando questo fallimento non possa essere attribuito all'intervallo di qualche agente causale
## Strategie per limitare gli errori
![[Pasted image 20261124140150.png]]
Le strategie per prevenire gli errori si dividono in 8 punti:
- Diversificare le azioni dell'utente
- Evitare comportamenti modali
- Usare funzioni obbliganti
- Imporre input vincolati
- Non sovraccaricare la memoria a breve termine dell'utente
- Richiedere conferme
- Usare default inoffensivi
- Fornire alternative sicure
### Diversificare le azioni dell'utente
Riuscire a dividere le task dell'utente per agevolarlo nel suo lavoro e così facendo preveniamo anche i possibili lapsus. Ad esempio dividere le mail per categorie, così agevoliamo gli spazi di dove andar ad adoperare e preveniamo il lapsus possibilmente dato dal cercare email sparse in molte righe.
### Comportamenti modali
Quando il sistema, a fronte di una stessa azione dell'utente, si comporta diversamente a seconda dello stato (o modalità) in cui si trova, e questo stato non è facilmente riconoscibile dall'utente.

>[!WARNING] Esempio
>Funzione di riconoscimento della password (minuscole considerate diverse dalle maiuscole)

Se l'utente non conosce lo stato, non può prevedere come il sistema risponderà alle sue azioni, per questo sarebbe preferibile far vedere un possibile Caps Lock attivo o dare altre informazioni se la password è errata.

Un altro sistema che non gestisce gli errori modali è il Power Point:
![[Pasted image 20261124141200.png]]
Un ottima soluzione sarebbe modificare il cursore con la figura della forma da seguire.
### Funzioni obbliganti
>[!NOTE] Definizione di Norman:
>Le funzioni obbliganti sono situazioni in cui le azioni sono vincolate in modo tale che la mancata esecuzione di un passaggio impedisca il successivo

Un esempio per comprendere le funzioni obbliganti è il seguente:
Selezionare l'oggetto desiderato disabilita tutte le voci del menù che corrispondo ad azioni che non hanno senso sull'oggetto selezionato.
### Input vincolati
Permettere all'utente di effettuare solo **azioni lecite** nel contesto corrente. Generalizza la nozione di funzione obbligante.
![[Pasted image 20261124142652.png]]
Vedendo l'esempio mostrato in figura, si comprende benissimo che l'opzione migliore è la n.3 poiché mostra una divisione visiva netta e spiega in modo ottimale il formato atteso (gg,mm,aaaa).
### Richiedere conferme
Chiedere sempre conferma prima di effettuare azioni **irreversibili** o pericolose. Spiegando con chiarezza quali sono le alternative possibili, e le loro conseguenze.
![[Pasted image 20261124142910.png]]
Si comprende alla perfezione che i due pop up in basso sono molto confusionari e non fanno intendere all'istante cosa si vuole. Ottimo invece è la figura in alto che ci fa capire benissimo cause e conseguenze di ciò che sta per accadere.
