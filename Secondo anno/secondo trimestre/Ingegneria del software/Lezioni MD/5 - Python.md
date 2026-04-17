## Cosa fare prima di creare un progetto Python
Quando creiamo un nuovo progetto in Python, che può contenere tanti file e pacchetti esterni, ricordiamoci di creare un nuovo ambiente virtuale in cui eseguirlo. **L’ambiente virtuale** di Python ci permette di avere un’installazione leggera e isolata di Python per il nostro progetto. Ogni progetto potrà usare pacchetti esterni di versioni diverse e potremo "sporcare" questo ambiente senza fare danni all’ambiente Python globale.
### Recap dei concetti base
Una **variabile** è una locazione di memoria riservata per memorizzare diversi tipi di dati, anche complessi.
Ad una variabile è associato un **identificatore** (il nome), il quale ci permette di accedere poi alla sua cella di memoria, $a=2$.
Gli identificatori in Python possono contenere anche caratteri **alfanumerici** ma devono iniziare con una lettera maiuscola o minuscola o underscore.
Le **parole riservate** non possono essere identificatori e per convenzione gli identificatori delle variabili iniziano con la lettera **minuscola**.

In caso avessimo: $x=3 \cap y=x \cap x=4$:
L’assegnazione $y = x$ indica a Python di collegare $y$ alla locazione di memoria di $x$. Tuttavia, con l’assegnazione $x = 4$, l’identificatore $x$ punta ora a una nuova locazione.

Anche in Python si usa 
