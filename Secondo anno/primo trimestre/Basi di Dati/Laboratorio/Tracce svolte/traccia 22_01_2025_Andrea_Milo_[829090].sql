-- es 1
CREATE DATABASE Ricerca;
USE Ricerca;
CREATE TABLE Autore(
    Cod INT PRIMARY KEY,
    Nome varchar(50) NOT NULL,
    Cognome varchar(50) NOT NULL,
    Affiliazione varchar(150) NOT NULL
);

CREATE TABLE Rivista(
    CodRivista INT PRIMARY KEY,
    NomeRivista varchar(50) NOT NULL,
    CasaEditrice varchar(70) NOT NULL,
    Ambito varchar(100) NOT NULL
);

CREATE TABLE Articolo(
    CodArticolo INT PRIMARY KEY,
    Titolo varchar(30) NOT NULL,
    Autore INT NOT NULL,
    Rivista INT NOT NULL,
    AnnoPublicazione YEAR NOT NULL,
    ParolaChiave varchar(80) NOT NULL,

    FOREIGN KEY (Autore) REFERENCES Autore(Cod),
    FOREIGN KEY (Rivista) REFERENCES Rivista(CodRivista)
);

-- es 2
INSERT INTO Autore(Cod,Nome,Cognome,Affiliazione) VALUES
    (1,'Andrea','Milo','Universita di Bari'),
    (2,'Giovanni','Sansonetti','Universita di Bari'),
    (3,'Francesco','Sblendorio','istituo ricerca Filandese'),
    (4,'Ciro','Scugnato','istituto di ricerca CNR Napoli');

INSERT INTO Rivista(CodRivista,NomeRivista,CasaEditrice,Ambito) VALUES
    (101,'Il mezzogiorno','Mondadori','AI & Law'),
    (102,'La rosa','Einaudi','Sports'),
    (103,'Cronaca nera','Feltrinelli','biomediche'),
    (104,'Il meridione','RAI','engineering');

INSERT INTO Articolo(CodArticolo,Titolo,Autore,Rivista,AnnoPublicazione,ParolaChiave) VALUES
    (001,'Rivoluzione del sud',4,104,2024,'Ontology'),
    (002,'Macchine uccidono uomo',2,103,2025,'AIProgress'),
    (003,'Bari in serie A?',1,102,2012,'SportLove'),
    (004,'Base di dati innovativa',3,101,2000,'Large Lenguage Models');

-- es 3.1
INSERT INTO Autore VALUES (5,'Maria','Luisa','Universita di Bologna');
INSERT INTO Rivista VALUES (105,'Times','EpsteinFBI','AI & Law');
INSERT INTO Articolo VALUES (005,'Lenguage',5,105,2023,'IslandScammer');

SELECT Nome,Cognome, Titolo, NomeRivista
FROM Autore INNER JOIN Articolo ON Articolo.Autore=Autore.Cod INNER JOIN Rivista ON Articolo.Rivista=Rivista.CodRivista
WHERE (Affiliazione='Universita di Bologna') AND (AnnoPublicazione=2023) AND (Ambito='AI & Law');

-- es 3.2
SELECT Titolo,AnnoPublicazione,Ambito,NomeRivista,CasaEditrice
FROM Articolo INNER JOIN Rivista ON Articolo.Rivista=Rivista.CodRivista
WHERE (AnnoPublicazione=2025 AND Ambito='biomediche'); -- non voglio scrivere machine learning di nuovo

-- es 3.3
SELECT Nome,Cognome
FROM Autore INNER JOIN Articolo ON Autore.Cod=Articolo.Autore INNER JOIN Rivista ON Articolo.Rivista=Rivista.CodRivista
WHERE (Autore.Affiliazione='Universita di Verona') AND (Rivista.Ambito='engineering') AND Autore.Cod NOT IN(
    SELECT Articolo.Autore
    FROM Articolo INNER JOIN Rivista ON Articolo.Rivista=Rivista.CodRivista
    WHERE Rivista.Ambito <> 'engineering'
);

-- es 4
ALTER TABLE Articolo RENAME COLUMN AnnoPublicazione TO AnnoEffettivaPubblicazione;
ALTER TABLE Articolo ADD COLUMN MeseEffettivaPubblicazione INT CHECK( MeseEffettivaPubblicazione BETWEEN 1 AND 12);
ALTER TABLE Articolo ADD COLUMN AnnoAccettazioneArticolo YEAR NOT NULL;
ALTER TABLE Articolo ADD COLUMN MeseAccettazioneArticolo INT CHECK( MeseAccettazioneArticolo BETWEEN 1 AND 12);
