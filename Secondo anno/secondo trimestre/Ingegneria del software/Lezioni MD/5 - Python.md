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
Prima dei `:` prendiamo dall'inizio all'elemento segnato, dopo l'elemento invece va da quell'elemento in poi, altrimenti senza vincoli prende tutto.
Due alternative per una **vera copia** sono:
``` Python
l = [2, 3, 10, 50] 
m = l[:] oppure n = l.copy()
```
Infine la seguente notazione `l[::-1]` andremo a contare da $-1$ fino a salire indietro tutti gli elementi.
I `::` si leggono come **passo** e servono a fare un salto di elementi quanti richiesti dal numero indicato, come nel seguente esercizio:
```Python
//Crea una lista di 100 elementi ed esegui un passo di 3
i=0
l=[]

while(i<100):
  l.append(i)
  i+=1
else:
  print(l[::3])
```

## Sequenze
Abbiamo dato uno sguardo alle liste e ai loro metodi. In Python le liste fanno parte di una grande famiglia di tipi di dati detti **sequenze**.
Di questa famiglia fanno parte anche le **stringhe**.

La **tupla()** è un'ulteriore tipologia di sequenza i cui elementi sono **immutabili**.
`t=("a",2,"c")`, come possiamo notare le tuple a differenza delle liste contengono **elementi disomogenei**.
### Operazione nelle sequenze
`x in s, x not in s`, ci dicono se è vero che l’elemento $x$ **c’è (o non c’è)** nella sequenza $s$.
`s + r` concatena due sequenze $s$ e $r$ 
`s * n` replica la sequenza $s$ per $n$ volte, se $n$ è un numero intero; ad esempio:
```Python
s=3
r="2"

p=s*r

print(p) //ci darà 222
```
Questa operazione è eseguibile anche sulle liste per inserire lo stesso elemento $n$ volte all'interno di una grande lista.

Un ultima operazione sulle sequenze in Python è il **sequence unpacking**, una delle operazioni più importanti. Questa operazione ci permette di trasformare gli elementi di una lista in variabili singole apposite, in maniera tale da procurarci solo quella che ci serve:
```Python
l=(4,6,8,10)

a,b,_,c=l

print(a) // 3
print(c) //10
```
Come si può notare, associamo alla lista le seguenti variabili escludendo quella presente in posizione `_` così salterà automaticamente quella posizione (non prenderà il valore $8$). 
Si dice che: **La lista viene ribaltata in variabili mutabili**.

## Variabili mutabili avanzate
Introduciamo ancora un altro tipo di dato mutabile in Python, il **set {}**, una collezione **non ordinata e non indicizzabile** di oggetti di qualunque tipo.
```
s={4,2,4,1}
print(s)
```
Sul tipo di dato **set** è possibile utilizzare le operazioni viste precedentemente.

>[!NOTE] Quando è meglio usarlo?
>Meglio i set per collezioni di tantissimi elementi senza duplicati e su cui facciamo "ricerche"

### Dizionari
Python ci offre lo strumento del **dizionario {}**. È una collezione **non ordinata e mutabile** di elementi, ognuno avente una **chiave e un valore**, proprio come in un vocabolario.

Accedere ad un elemento di un dizionario è semplice: basta conoscere la sua chiave.
```Python
d={'Uniba': 'Universita del Sud Italia', 7: 'Numero intero'}
print(d['Uniba']) //Avremo->'Universita del Sud Italia'
print(d.get(7)) //Preleviamo quell'elemento
```
Per inserire elementi nel dizionario utilizziamo la clausola **dict**: `d = dict(Uniba='…', Gatto='…')`, questo è eseguibile però solo se **le chiavi sono identificatori validi**.
Per quanto riguarda **l'inserimento di valori in un dizionario già esistente**, basterà assegnare alla chiave il valore nuovo da voler inserire: `d['Bari']='Bellissima città'`.

Per copiare un dizionario in una nuova variabile dizionario si utilizzerà la sua funzione **copy()**:
`c=d.copy()`
Se utilizzassimo la sintassi normale `c=d` andremo a fare una sovrascrittura dei dati del dizionario, come nella seguente foto:
![[Pasted image 20260422090739.png]]
Questo è dato dal fatto che i dizionari sono oggetti mutabili.
## Input in Python
Differentemente dal **cin>>** o dalla **scanf** per far digitare in input un dato dall'utente si utilizza in python proprio la funzione **input()** stessa:
```Python
nome=input("Insert name")
print(nome+ "string")
```
A terminale avremo uno spazio di inserimento, con la label *Insert name*, e **registrerà sempre e solamente come stringa** ciò che andremo ad inserire all'interno della label.
Per inserire in input un intero quindi bisognerà fare sempre il **casting del valore**, poiché ogni input sarà sempre stringa: 
```Python
nome=input("Inserisci valore: ")
print(int(nome)+2) //così da eseguire le operazioni anche
```
## Il ciclo For e gli Iterabili
In Python, il costrutto detto ciclo `for` ci permette di eseguire delle istruzioni ripetute per ciascuno degli elementi all'interno di una sequenza. La sintassi base è la seguente:
```
for i in seq:
    # <istruzioni>
else:
    # <istruzioni finali>
```

Ma cos'è esattamente `seq`? In Python, questo oggetto è definito come un "iterabile", ovvero un oggetto che è in grado di restituire un suo elemento alla volta. Una qualsiasi sequenza (come una lista, una tupla, un range o una stringa di testo), un set o un dizionario sono considerati iterabili.

### Strumenti utili per l'iterazione: zip, enumerate e range

Quando ci troviamo a iterare, Python offre diverse funzioni built-in per semplificarci il lavoro:

- `zip()`: Questa funzione ci permette di iterare contemporaneamente su tuple costruite prendendo gli elementi di indice corrispondente da due o più iterabili.
    
- `enumerate()`: Se all'interno del ciclo ci serve avere a disposizione sia l'elemento di un iterabile sia il suo indice, possiamo usare `enumerate()`, che fornisce a ogni iterazione una tupla contenente proprio l'indice e l'elemento.
    
- `range(start, end, step)`: È il modo migliore in assoluto per creare un contatore che "guidi" un ciclo for.
    

Se all'interno del ciclo le istruzioni non dipendono dall'elemento restituito dall'iterabile, possiamo per convenzione usare l'underscore `_` al posto della variabile (es. `for _ in range(0, 100):`).

### Iterare su un Dizionario

Esistono approcci diversi per iterare sugli elementi di un dizionario. Se eseguiamo le iterazioni direttamente sul dizionario `d` oppure su `d.keys()`, il ciclo ci restituirà tutte le chiavi del dizionario. Utilizzando invece il metodo `d.items()`, Python restituisce una lista di tuple contenenti la combinazione `(chiave, valore)`. Accoppiando questo metodo con un uso intelligente del _sequence unpacking_ visto in precedenza, possiamo scorrere il dizionario in modo molto elegante:
```
d = {1: "Bruno", 2: "Giulio", 3: "Luigi"}
for key, val in d.items():
    print("chiave {} valore {}".format(key, val))
```
## List Comprehension e Generatori
Avendo qualche strumento in più e conoscendo il ciclo for, possiamo scrivere codice più compatto con la tecnica della **list comprehension**. Questa è un'ottima tecnica per filtrare o rimuovere elementi dalle liste, creandone una nuova in una sola riga. La sintassi è la seguente: `[expression for name in seq]`. È possibile anche aggiungere condizioni come `if` al suo interno o persino annidare loop interni ed esterni.

> [!NOTE] Less (than less) is more 
> Se non vogliamo davvero creare e salvare una nuova lista in memoria, ma ci serve solo utilizzare "al volo" gli elementi generati all'interno di una funzione, possiamo omettere le parentesi quadrate utilizzando un'**espressione generator**. Possiamo ottenere un tipo di dato da un altro semplicemente mettendo il generatore dentro funzioni come `sum(...)` o `set(...)`.
## Le Funzioni
Possiamo scrivere dei blocchi di codice che siano riusabili in più punti del nostro algoritmo introducendo il concetto di **funzione**. Una funzione si definisce con la keyword `def`:
```
def power(n, exp=2):
    s = n ** exp
    return s
```
Non siamo obbligati a restituire valori e la parola chiave `return` non è obbligatoria. Quando vogliamo fornire dei parametri opzionali, possiamo definire per loro dei valori di default. **Se una funzione restituisce più oggetti contemporaneamente, essi vengono automaticamente inseriti in una tupla**.
### Funzioni anonime, map e filter
Possiamo dichiarare piccole funzioni formate da singole espressioni "al volo" definendole come **funzioni lambda** (es. `lambda n, exp: n**exp`). Queste sono molto utili nella programmazione funzionale, specialmente se combinate con:
- `filter()`: Genera gli elementi di un iterabile per i quali la funzione lambda restituisce il booleano `True`.
- `map()`: Genera il mapping degli elementi dell'iterabile applicando loro la funzione specificata.

Per gestire progetti grandi, qualsiasi funzione definita in un file esterno può essere importata con `import nome_file`, con un alias `import nome_file as alias`, o estraendo solo ciò che ci serve con la sintassi `from nome_file import funzione`.
## Programmazione Orientata agli Oggetti (OOP)
Se vogliamo inserire nel progetto oggetti complessi che si rifacciano tutti a uno stesso modello e offrano funzionalità, creiamo una **classe**. Il modello rappresenta la classe, ciascun individuo è un'**istanza** della classe, le caratteristiche si chiamano **variabili** e le funzionalità sono dette **metodi**.
```
class Studente:
    def __init__(self, nome, cognome):
        self.nome = nome
        self.cognome = cognome
```
All'interno della classe, la parola chiave `self` ci permette di accedere a variabili e metodi appartenenti a quello specifico individuo (istanza).
### Ereditarietà e Metodi Dunder
Le classi possono comportarsi come "**padri e figli**": una classe può ereditare attributi da un'altra (**ereditarietà**) richiamando il costruttore del padre tramite la funzione `super().__init__()`. Quando andiamo a riscrivere un metodo ereditato per modificarlo o estenderlo, effettuiamo un'operazione nota come **overriding**.
![[Pasted image 20260422092140.png]]
![[Pasted image 20260422092155.png]]

Python utilizza metodi "predefiniti" detti **dunder** (double underscore), come `__add__`, `__len__` o `__str__`, che possiamo riscrivere per dare un comportamento polimorfico a funzioni generiche a seconda della classe in cui ci troviamo. Riscrivere `__str__`, ad esempio, dice a Python come l'oggetto deve essere trasformato in testo se inserito in una `print()`.
#### Sicurezza e Incapsulamento
A differenza di altri linguaggi, in Python otteniamo i livelli di "protezione" degli attributi di una classe usando la convenzione degli underscore:
- **Singolo underscore** (`self._b`): Crea un attributo _protetto_, che resta di fatto accessibile dall'esterno ed ereditabile.
- **Doppio underscore** (`self.__c`): Crea un attributo _privato_, che in principio non è né accessibile dall'esterno né utilizzabile da eventuali classi ereditate.

[FInire con la parte di docker e Ruff]
