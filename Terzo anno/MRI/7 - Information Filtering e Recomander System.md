![[Pasted image 20261127164602.png]]
L'obiettivo del filtraggio dell'informazione è trovare le informazioni interessanti andando però a filtrare (ovvero **togliere**) tutto ciò che non è importante.
I vari motori di ricerca sono dinamici, ovvero cambiano il loro bisogno informativo ad ogni diversa apertura.
Invece nel information filtering il bisogno diventa stabile e statico, ed è la sorgente che è dinamica, ovvero varia e possono essere molteplici.

Questo concetto è alla base di TikTok ad esempio, ovvero un algoritmo privo di ricerca dispone già dei contenuti che in base alle sue ricerche e filtraggio di informazioni mostra contenuti che possono essere appaganti.
![[Pasted image 20261127164953.png]]

La sorgente informativa è dinamica perché il set di contenuti varia costantemente (amazon, tiktok, spotify, ecc...).
Il bisogno informativo non viene esposto tramite query, ma è l'utente stesso in base alle sue esperienze che sa cosa cerca e la piattaforma sa cosa scartare e cosa lasciare per la conoscenza di ciò che guarda l'utente.
## Information Retrival vs Information Filtering
![[Pasted image 20261127165302.png]]
### Sono ancora valide queste differenze?
![[Pasted image 20261127165552.png]]
Anche le pagine web ora sono dinamiche, infatti sono in cambiamento costante. Quindi sono entrambi dinamici.

Possiamo definire l'IR e l'IF due facce della stessa moneta. Così l'ha definito **N. Belkin**
![[Pasted image 20261127165716.png]]
Entrambi mirano allo stesso obiettivo, ovvero ottimizzare la ricerca sui dati.

I dati su cui vengono costruite le regole per l'IR (così capire cosa mostrare di più all'utente), si base sugli stereotipi. Se ci sono donne, con determinati status l'algoritmo capisce di filtrare informazioni mostrando ciò che è possibile che possa interessarti.
Viceversa per tutte le altre scremature. Questi stereotipi hanno trovato inizio già in uno studio del 1979 da Grundy, su questa base di studi si creano i primi dati modificati e mirati all'utente.
![[Pasted image 20261127170052.png]]

Questo sistema di filtraggio delle informazioni è anche alla base degli **algoritmi anti-spam**. Anche l'ordine con cui saranno mostrate le News su google news, o i contenuti da vedere sui social.
Anche la **raccomendations**, ovvero la raccomandazione degli oggetti da comprare, film da comprare o video da vedere nei consigliati.

Tutti questi esempi usano algoritmi basati sul Information Filtering,
![[Pasted image 20261127170723.png]]
La maggior parte dei video, prodotti e film guardati o comprati sono dati dai consigliati e non dai ricercati.

>[!NOTE] Definizione di Recomander System di Burke 2002
>I Recomander System guidano l'utente in modo **personalizzato** in uno spazio dove ci sono **tante possibili opzioni**.
## Problemi
![[Pasted image 20261127173104.png]]
[Spiegare queste slide e queste foto]
![[Pasted image 20261127173128.png]]![[Pasted image 20261127173134.png]]
### Quanto questo è buono al business
![[Pasted image 20261127175048.png]]
[Spiegare slide]
### Come funzionano questo tipo di piattaforme
Ci sono tre attori importanti per il funzionamento di queste piattaforme:
- L'**utente** dove è importante segnare le informazioni di quest'ultimo, come cosa compra, il profilo, quanto tempo rimane attivo sulla piattaforma, che tipo di contenuto guarda, ecc...
- Informazioni sugli **oggetti**, ovvero se il film o prodotto o canzone è di tendenza, quanto viene visualizzato, acquistato, streammato e che impatto ha nell'ultimo periodo

Mettendo insieme le preferenze utente e le informazioni degli oggetti, in modo diverso per ogni algoritmo, avviene l'operazione di Recomander System, dove viene appreso l'analisi delle preferenze utente, il raking degli oggetti e selezionare i top-N reccomandetions, analyzes item charaterictis.

Con i top-N recommanded items possiamo stilare poi una lista dei prodotti personalizzati da mostrare all'utente.
## Tassonomia dei Recommender Systems
![[Pasted image 20261127175710.png]]
Le strategie non pesonalizzate vengono utilizzate per mostrare qualcosa di sicuro e che funzionerebbe di certo perché sono di tendenza.
Personalizzati invece sono degli adv basati sul video cliccato o generalmente su ciò che guardiamo sui social.
![[Pasted image 20261127180047.png]]
- Content-Based: ...
- Collaborative Filtering: ...
- Hybrid & Knowledge-Aware: ...