-- es 1
CREATE DATABASE Management;
USE Management;

CREATE TABLE Impiegato(
    Matricola INT PRIMARY KEY,
    Nome varchar(50) NOT NULL,
    Cognome varchar(50) NOT NULL,
    LuogoNascita varchar(50) NOT NULL,
    DataNascita DATE NOT NULL,
    Stipendio FLOAT
);

CREATE TABLE Progetto(
    CodProgetto INT PRIMARY KEY,
    Titolo varchar(30) NOT NULL,
    DataInizio DATE NOT NULL,
    DataFine DATE,
    Budget FLOAT NOT NULL,
    Responsabile INT NOT NULL,

    FOREIGN KEY (Responsabile) REFERENCES Impiegato(Matricola)
);

CREATE TABLE Assegnazione(
    CodProgetto INT NOT NULL,
    CodImpiegato INT NOT NULL,

    FOREIGN KEY (CodProgetto) REFERENCES Progetto(CodProgetto),
    FOREIGN KEY (CodImpiegato) REFERENCES Impiegato(Matricola)
);

-- es 2
INSERT INTO Impiegato(Matricola,Nome,Cognome,LuogoNascita,DataNascita,Stipendio) VALUES
    (0001,'Luca','Giallo','Bari','1990-10-20',NULL),
    (0002,'Luigi','Bianchi','Milano','1999-10-20',1200),
    (0003,'Piero','Rossi','Roma','1980-11-20',1300.50),
    (0004,'Moro','Michele','Bari','1990-08-20',1500);

INSERT INTO Progetto(CodProgetto,Titolo,DataInizio,DataFine,Budget,Responsabile) VALUES
    (1000,'Ponti','2024-10-11',NULL,32000,0004),
    (1001,'Scuola','2022-10-11','204-01-02',45000,0002),
    (1002,'Ospedale','2025-10-10',NULL,42000,0003),
    (1003,'Piazza','2023-10-11','2024-02-02',32600,0004);

INSERT INTO Assegnazione(CodProgetto,CodImpiegato) VALUES
    (1000,0001),
    (1001,0002),
    (1002,0002),
    (1003,0004);

-- es 3.1
SELECT I.Nome,I.Cognome,I.Matricola,I.Stipendio
FROM Impiegato I
WHERE I.Matricola NOT IN(
    SELECT A.CodImpiegato
    FROM Assegnazione A JOIN Progetto P ON P.CodProgetto=A.CodProgetto
);

-- es 3.2
SELECT I.Nome,I.Cognome,I.Stipendio
FROM Impiegato I LEFT JOIN Assegnazione A ON I.Matricola=A.CodImpiegato JOIN Progetto P ON A.CodProgetto=P.CodProgetto
WHERE P.Budget>70000 AND I.Matricola NOT IN(
    SELECT A.CodImpiegato
    FROM Impiegato I JOIN Assegnazione A ON I.Matricola=A.CodImpiegato INNER JOIN Progetto P ON A.CodProgetto=P.CodProgetto
    WHERE P.Budget<70000
);

-- es 3.3
INSERT INTO Impiegato(Matricola,Nome,Cognome,LuogoNascita,DataNascita,Stipendio) VALUES
    (100,'Susino','Sussanna','Foggia','1990-08-20',2500);
INSERT INTO Progetto(CodProgetto,Titolo,DataInizio,DataFine,Budget,Responsabile) VALUES
    (4000,'Ponti','2024-10-11',NULL,32000,100);
SELECT I.Matricola,I.Nome,I.Cognome
FROM Impiegato I JOIN Assegnazione A ON I.Matricola=A.CodImpiegato JOIN Progetto P ON A.CodProgetto=P.CodProgetto
WHERE P.Responsabile=100
ORDER BY P.Titolo;

-- es 4.1
mysql> SELECT * FROM Assegnazione WHERE CodImpiegato=2;
+-------------+--------------+
| CodProgetto | CodImpiegato |
+-------------+--------------+
|        1001 |            2 |
|        1002 |            2 |
+-------------+--------------+
2 rows in set (0,01 sec)
-- ci sono già delle doppietà quindi prima di inserire l'unicità bisogna togliere l'ambiguità
DELETE FROM Assegnazione WHERE CodImpiegato=2 AND CodProgetto=1001;
ALTER TABLE Assegnazione MODIFY COLUMN CodImpiegato INT NOT NULL UNIQUE;

-- es 4.2
CREATE TABLE ConsulenteEsterno(
    Responsabile INT PRIMARY KEY,
    Nome varchar(50) NOT NULL,
    Compenso FLOAT
);

SHOW CREATE TABLE Progetto;
ALTER TABLE Progetto DROP FOREIGN KEY Progetto_ibfk_1; -- eliminare il vincolo esistente per creare il nuovo vincolo

-- ma prima di crearlo bisogna far combaciare ciò che sta già in Progetto nella nuova tabella
INSERT INTO ConsulenteEsterno(Responsabile,Nome,Compenso)
SELECT DISTINCT Responsabile,'Mario',1000
FROM Progetto P;

ALTER TABLE Progetto ADD CONSTRAINT FOREIGN KEY (Responsabile) REFERENCES ConsulenteEsterno(Responsabile);
