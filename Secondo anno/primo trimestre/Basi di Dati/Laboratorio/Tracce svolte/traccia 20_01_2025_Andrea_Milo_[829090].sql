-- es 1
CREATE DATABASE Marketing;
USE Marketing;

CREATE TABLE Cliente(
  CodFiscale varchar(16) PRIMARY KEY,
  Nome varchar(50) NOT NULL,
  Cognome varchar(50) NOT NULL,
  NumeroTelefono varchar(13) NOT NULL,
  CittaResidenza varchar(50) NOT NULL
);

CREATE TABLE ClienteInteressi(
    CFCliente varchar(16) NOT NULL,
    Interesse varchar(40) NOT NULL,

    FOREIGN KEY (CFCliente) REFERENCES Cliente(CodFiscale),
    CHECK (Interesse IN ('Giardinaggio','Sport','Abbigliamento','Calzature','Accessori'))
);

CREATE TABLE Prodotto(
    Cod INT PRIMARY KEY,
    Nome varchar(50) NOT NULL,
    Descrizione varchar(150) NOT NULL,
    CategoriaInteresse varchar(40) NOT NULL,
    Prezzo FLOAT NOT NULL,
    PrezzoScontato FLOAT,
    PercentualeSconto INT,

    CHECK (CategoriaInteresse IN ('Giardinaggio','Sport','Abbigliamento','Calzature','Accessori'))
    -- dato che la relazione è NxN non ci si può riferie ad ClienteInteressi.Interesse poiché non è ne PK né può esserlo se no non si potrebbe ribetere, si joina con prodotto cartesiano le due tabelle riportando i medesimi campi ripetuti.
);

-- il join con prodotto cartesiano grazie alla clausola check avviene con: SELECT C.Nome, P.Nome
FROM Cliente C
JOIN ClienteInteressi CI ON C.CodFiscale = CI.CFCliente
JOIN Prodotto P ON CI.Interesse = P.CategoriaInteresse; -- Funziona perfettamente

-- es 2
INSERT INTO Cliente(CodFiscale,Nome,Cognome,NumeroTelefono,CittaResidenza) VALUES
    ('FGSBKS63B01L869H','Federico','Della Fede','+393331234567','Roma'),
    ('BWNNIO91R91Y201D','Michele','Demichele','+513389876543','Milano'),
    ('YGHGTD44B38P595F','Andrea','DellaGiusta','+393391122334','Venezia'),
    ('WLGECC44R79P133N','Luigina','Walter','+613315566778','Bari');

INSERT INTO ClienteInteressi(CFCliente,Interesse) VALUES
    ('FGSBKS63B01L869H','Giardinaggio'),
    ('BWNNIO91R91Y201D','Sport'),
    ('YGHGTD44B38P595F','Accessori'),
    ('BWNNIO91R91Y201D','Accessori');

INSERT INTO Prodotto(Cod,Nome,Descrizione,CategoriaInteresse,Prezzo,PrezzoScontato,PercentualeSconto) VALUES
    (001,'Bagnoschiuma','Bagnoschiuma antiforfora','Accessori',3.50,2.80,20),
    (002,'Mazza da golf','NuovaGen ultra preciso','Sport',50,NULL,NULL),
    (003,'Tosaerba','Il prato sarà lucido come barba tagliata','Giardinaggio',200,150.99,24),
    (004,'Maglia termica','Stai al calduccio','Abbigliamento',10,NULL,NULL);

-- es 3.1
SELECT Cod, Prodotto.Nome, PrezzoScontato
FROM Prodotto
WHERE CategoriaInteresse='Giardinaggio' AND PercentualeSconto>20
GROUP BY Cod, Prodotto.Nome
ORDER BY PrezzoScontato ASC;

-- es 3.2
SELECT Nome,Cognome,NumeroTelefono,CittaResidenza
FROM Cliente JOIN ClienteInteressi ON Cliente.CodFiscale=ClienteInteressi.CFCliente
WHERE Interesse='Accessori' AND CFCliente IN (
    SELECT CFCliente
    FROM ClienteInteressi
    WHERE Interesse='Sport'
)
ORDER BY CittaResidenza;

-- es 3.3
SELECT C.Nome,C.Cognome,C.NumeroTelefono, P.Nome,P.Descrizione,P.Prezzo
FROM Cliente C JOIN ClienteInteressi CI ON C.CodFiscale=CI.CFCliente JOIN Prodotto P ON CI.Interesse=P.CategoriaInteresse
WHERE (P.PrezzoScontato IS NULL) AND (P.CategoriaInteresse='Abbigliamento') AND (P.Prezzo<=300);

-- es 4
CREATE TABLE Categoria(
    CodCategoria INT PRIMARY KEY AUTO_INCREMENT,
    NomeCategoria varchar(40) NOT NULL,

    CHECK (NomeCategoria IN ('Giardinaggio','Sport','Abbigliamento','Calzature','Accessori'))
);

INSERT INTO Categoria (NomeCategoria)
    SELECT DISTINCT CategoriaInteresse
    FROM Prodotto;

ALTER TABLE Prodotto ADD COLUMN Categoria INT NOT NULL;

UPDATE Prodotto
JOIN Categoria ON Categoria.NomeCategoria=Prodotto.CategoriaInteresse
SET Categoria=CodCategoria;

ALTER TABLE Prodotto DROP COLUMN CategoriaInteresse;
ALTER TABLE Prodotto ADD CONSTRAINT Categoria FOREIGN KEY (Categoria) REFERENCES Categoria(CodCategoria);

CREATE TABLE CategorieProdotti(
    Categoria INT NOT NULL,
    Prodotto INT NOT NULL,

    FOREIGN KEY (Categoria) REFERENCES Categoria(CodCategoria),
    FOREIGN KEY (Prodotto) REFERENCES Prodotto(Cod)
);

INSERT INTO CategorieProdotti(Categoria,Prodotto)
SELECT Categoria, Cod
FROM Prodotto;

ALTER TABLE Prodotto DROP FOREIGN KEY Categoria;
ALTER TABLE Prodotto DROP COLUMN Categoria;

SHOW TABLES;
+---------------------+
| Tables_in_Marketing |
+---------------------+
| Categoria           |
| CategorieProdotti   |
| Cliente             |
| ClienteInteressi    |
| Prodotto            |
+---------------------+
5 rows in set (0,00 sec)

ALTER TABLE Cliente ADD COLUMN CategoriaCliente INT NOT NULL;
-- Per creare il vincolo non può essere NULL (ci sono gli zeri ora) UPDATE Cliente SET CategoriaCliente=1;
ALTER TABLE Cliente ADD CONSTRAINT CategoriaCliente FOREIGN KEY (CategoriaCliente) REFERENCES Categoria(CodCategoria);

UPDATE Cliente C
JOIN ClienteInteressi CI ON C.CodFiscale=CI.CFCliente JOIN Categoria Ca ON Ca.NomeCategoria=CI.Interesse
SET C.CategoriaCliente=Ca.CodCategoria;
