Il System design è l'**identificazione** dei principali componenti e le relazioni tra i componenti stessi per quanto riguarda **l'architettura software**.
Quest'ultima è definita per gli stili di **progettazione ad alto livello**. Di fatto, differisce sostanzialmente dall' **OO design** che è incentrata per la **progettazione di dettaglio**.
La progettazione di dettaglio dipende dal paradigma di programmazione usato (per questo il nome OO) e si occupa di **specificare** i meccanismi interni ai componenti maggiori.
## Architettura software
>[!NOTE] Definizione
>L'architettura software definisce un modello di come il sistema è strutturato e di come i sottosistemi presenti comunicano tra di loro.

Generalmente un sottosistema sono le classi, operazioni interne e altri aspetti del sistema che sono strettamente correlati tra i vari sottosistemi.

L'architettura **evidenzia le decisioni** che avranno impatto significativo sui lavori successivi.
### Rappresentazioni
L'architettura è rappresentabile sotto diversi stili dell'UML, come ad esempio il **diagramma dei package**:
![[Pasted image 20260502161735.png]]
Ricordiamo che un **package** può essere un'unità binaria di rilascio, come un file `.jar`, mentre una **dipendenza** è una relazione tra package, per esempio nell'immagine presente possiamo notare come elementi di un package (*Persistence* presente in *Service*) richiedono elementi di un altro package (*Core* presente in *Domain*).
Un cambiamento in *Services* potrebbe causare un cambiamento di *Domain*.

Altrimenti, è rappresentabile tramite **diagramma dei componenti**:
![[Pasted image 20260502162224.png]]
Il diagramma dei componenti ci permette di comprendere la modellazione del sistema in termini di **componenti** e **dipendenze tra componenti**.
Un componente generalmente è un'**interfaccia** pubblica, come un **API**; una dipendenza è un connettore tra il **componente cliente** e il **componente fornitore**.

Nel diagramma illustrato si comprende a pieno lo stile di rappresentazione delle obbligazioni e dei collegamenti tra componenti tramite le dipendenze.

Un ulteriore rappresentazione è tramite **diagramma di deployment**:
![[Pasted image 20260502162621.png]]
Il quale ci permette di avere una rappresentazione grafica della distribuzione dei sottosistemi tra i **nodi** (i componenti hardware).
### Rappresentazione non-UML dell'architettura
L'architettura in fenomeni aziendali concreti richiedono rappresentazioni che non sono riconosciute dall'UML, come:
- **Architettura a 3 livelli**, la quale ci permette di comprendere come lavora il progetto reale nei tre strati logici e fisici, partendo dall'*Interfaccia web*, *Logica di business* e *Database Tier*.![[Pasted image 20260502163502.png]]
- **Slurm**, è una metodologia di rappresentazione di una reale architettura con i vari server a lavoro. Generalmente è usata per comprendere le come le diverse tecnologie usate (come HTML, Python, JSON) comunicano tra loro![[Pasted image 20260502163657.png]]
- Rappresentazione tramite **Whiteboard**. Quest'ultima è una delle più usate nelle aziende per creare una bozza iniziale dell'architettura quando il lavoro sta per nascere o c'è bisogno di ricrearlo per capire come aggiustarlo o migliorarlo.
  ![[Pasted image 20260502163841.png]]
  Come si può notare è molto confuso, infatti questo scaturisce il dibattito su come renderlo comprensibile, utilizzando la **checklist dei diagrammi**.
### Checklist per la revisione di diagrammi di architettura software
La checklist per la revisione dei diagrammi è una **tabella** divisa in tre campi con delle domande al suo interno. Un diagramma per essere corretto e adatto alla comprensione **deve rispondere in maniera affermativa** a (quasi) tutte le domande proposte al suo interno.
I campi presenti nella tabella sono:
- **General**:
- **Elements**:
- **Relationships**: