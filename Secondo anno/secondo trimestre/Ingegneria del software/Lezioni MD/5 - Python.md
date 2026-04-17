## Cosa fare prima di creare un progetto Python
Quando creiamo un nuovo progetto in Python, che può contenere tanti file e pacchetti esterni, ricordiamoci di creare un nuovo ambiente virtuale in cui eseguirlo. **L’ambiente virtuale** di Python ci permette di avere un’installazione leggera e isolata di Python per il nostro progetto. Ogni progetto potrà usare pacchetti esterni di versioni diverse e potremo "sporcare" questo ambiente senza fare danni all’ambiente Python globale.
### Recap dei concetti base
Una **variabile** è una locazione di memoria riservata per memorizzare diversi tipi di dati, anche complessi.
Ad una variabile è associato un **identificatore** (il nome), il quale ci permette di accedere poi alla sua cella di memoria, $a=2$.
Gli identificatori in Python possono contenere anche caratteri **alfanumerici** ma devono iniziare con una lettera maiuscola o minuscola o underscore.
Le **parole riservate** non possono essere identificatori e per convenzione gli identificatori delle variabili iniziano con la lettera **minuscola**.

In caso avessimo: $x=3 \cap y=x \cap x=4$:
L’assegnazione $y = x$ indica a Python di collegare $y$ alla locazione di memoria di $x$. Tuttavia, con l’assegnazione $x = 4$, l’identificatore $x$ punta ora a una nuova locazione.

Anche in Python si usa `print(a)`, le operazioni però vengono scritte senza il `;` finale.
Inoltre in Python non si specifica il tipo di una variabile.

Se vogliamo mettere a confronto due variabili dello stesso tipo, possiamo utilizzare in Python gli **operatori logici di confronto**.
Ogni volta che mettiamo a confronto due variabili, Python ci risponderà con un valore booleano **True o False**.

Python permette di utilizzare **istruzioni condizionali** (blocchi di selezione) mediante le parole chiave:
```Python
if <cond1>:
	istruzione cond1 == True
elif <cond2>:
	istruzione per cui cond1 == False e cond2=True
else:
	istruzioni per cui cond1= False e cond2=False
```

In Python, come si nota dall'esempio, siamo costretti rigorosamente nelle istruzioni a raggrupparle tramite **l'indentazione**, senza essa non potremmo comprendere a pieno i blocchi, specialmente in progetti grandi e complessi.

In Python abbiamo anche i **cicli iterativi**:
**a condizione iniziale**:
```
 while <condizione>:
	finché la condizione è vera esegui questo blocco 
 else:
	 altrimenti procedi ad eseguire qui
```
In Python non esiste di base il ciclo a post condizione, ovvero il **do-while**.
## Liste in Python
Le liste di Python ci permettono di definire una **sequenza ordinata di oggetti di qualunque tipo** (numeri, stringhe, oggetti, …), semplicemente elencandoli all’interno di una coppia di parentesi quadre e separandoli con una virgola.
`l=[4.02,"bruno",x,True]`
Bisogna prestare attenzione, poiché in Python la **lista è un oggetto** e che una lista può trovarsi dentro un'altra lista.

Per accedere agli elementi di una lista possiamo usare gli indici in qualsiasi verso si preferisce, se dovessimo fare `print(l[-1]` dell'esempio precedente otterremmo `True` poiché partiremo da $-1$ a $-5$ che sarà $4.02$. O partire da $0$ a $3$ .Mentre si otterrà `error` quando il valore è **out of range**.

La notazione `l[n]` (**indicizzazione**) ci permette di ritrovare l’elemento di indice `n` all’interno della lista `l`.

Guardiamo il seguente codice:
```Python
x = [5]
l = [4.02, "claudio", x, True] 
l.append("giulio") 
l.extend(x) 
l.insert(2, False) 
l.remove("bruno") 
e = l.pop(3) 
print("lista: {}, elemento: {}".format(l, e))
```
- Tramite la dicitura **append** possiamo inserire alla fine di una lista un altro elemento.
- Con **extend** invece andiamo a concatenare alla fine della prima lista una seconda lista.
- Con il **remove** eliminiamo un elemento, diversamente con **insert** inseriamo nell'indice specificato (nel nostro caso il due) un altro elemento, e ciò che si trovava in quella posizione sarà **traslato** assieme al resto in sequenza.
- Il **pop** inserisce l'elemento in posizione $3$ (nel nostro caso) nella variabile `e`, sfilandolo dalla lista.
- Come ultimo invece abbiamo il **formattatore**, dove i parametri passati sono la **lista** che sarà inserita nel primo placeholder di `{}` e l'**elemento** che verrà inserito nel secondo placeholder di `{}`.
Altre funzioni della lista sono le seguenti:
![[Pasted image 20260417185644.png]]

![[Pasted image 20260417190253.png]]
La lista viene proprio copiata e immagazzinata la medesima nel tempo. Le liste in Python sono **oggetti mutabili**. Il contenuto può cambiare, pur rimanendo invariata la locazione di memoria del contenitore.
### Porzione di lista
La notazione `[start:end:step]` permette di ottenere una copia della **porzione di lista** compresa fra gli indici `s` (incluso) ed `e` (escluso):
```Python
l = [2, 3, 10, 50]
c = l[1:3]
print(l[:2], l[1:], l[:]) 
l[2] = -1
print(c)
```
Prima dei `:` (**passo**) prendiamo dall'inizio all'elemento segnato, dopo l'elemento invece va da quell'elemento in poi, altrimenti senza vincoli prende tutto.
Due alternative per una **vera copia** sono:
``` Python
l = [2, 3, 10, 50] 
m = l[:] oppure n = l.copy()
```
Infine la seguente notazione `l[::-1]` andremo a contare da $-1$ fino a salire indietro tutti gli elementi.

