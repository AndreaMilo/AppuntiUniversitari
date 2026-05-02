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
