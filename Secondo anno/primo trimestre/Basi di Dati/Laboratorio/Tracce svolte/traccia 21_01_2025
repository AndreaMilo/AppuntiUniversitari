Traccia 21/01/2025
CREATE DATABASE MUSEO;
USE MUSEO;
--es 1
CREATE TABLE Dipinto(
    CodDipinto INT PRIMARY KEY,
    TitoloDipinto varchar(50) NOT NULL,
    AnnoRealizzazione YEAR NOT NULL,
    Autore INT(50) NOT NULL,
    NomeSala varchar(1) NOT NULL,
    Corrente varchar(30) NOT NULL,

    FOREIGN KEY (Autore) REFERENCES Artista(CodArtista),
    CHECK(NomeSala IN ('A', 'B', 'C', 'D', 'E', 'F', 'G', 'H')),
    CHECK (Corrente IN ('Cubismo','Impressionismo','Strattismo','PorArt'))
);

CREATE TABLE Artista(
        CodArtista INT PRIMARY KEY,
        Nome varchar(50) NOT NULL,
        Cognome varchar(50) NOT NULL
);

CREATE TABLE Scatto(
    Cod INT PRIMARY KEY,
    Titolo varchar(50) NOT NULL,
    Anno YEAR NOT NULL,
    NomeSala varchar(1) NOT NULL,
    Genere varchar(100) NOT NULL,
    Autore INT NOT NULL,

    FOREIGN KEY (Autore) REFERENCES Artista(CodArtista),
    CHECK(NomeSala IN ('A', 'B', 'C', 'D', 'E', 'F', 'G', 'H')),
    CHECK(Genere IN ('foto di strada', 'foto di viaggio', 'foto di ritratto'))
);

-- es numero 2
INSERT INTO Artista (CodArtista, Nome, Cognome) VALUES
    (1,'Claude', 'Monet'),
    (2,'Pablo','Picasso'),
    (3,'Wassily','Kandisky'),
    (4,'Andy','Warhol');

INSERT INTO Dipinto (CodDipinto,TitoloDipinto,AnnoRealizzazione,Autore,NomeSala,Corrente) VALUES
    (001, 'Levar del sole', 1901, 1,'A','Impressionismo'),
    (002,'Ninfee blu', 1916, 1, 'A', 'Impressionismo'),
    (003,'Primo acquerello astratto',1910, 3, 'C','Strattismo'),
    (004,'Guernica',1937, 2,'B','Cubismo');

INSERT INTO Scatto (Cod,Titolo,Anno,NomeSala,Genere,Autore) VALUES
    (101,'A',2000,'A','foto di strada',4),
    (102,'B',1905,'B','foto di viaggio',3),
    (103,'C',2010,'G','foto di ritratto',2),
    (104,'D',2001,'D','foto di strada',4);

-- es numero 3
SELECT Titolo,Nome,Cognome, Anno
FROM Scatto INNER JOIN Artista ON Artista.CodArtista=Scatto.Autore
WHERE (NomeSala IN ('F', 'G', 'H')) AND (Genere='foto di strada' OR Genere='foto di viaggio');

SELECT Nome,Cognome,TitoloDipinto
FROM Artista INNER JOIN Dipinto ON Artista.CodArtista=Dipinto.Autore INNER JOIN Scatto ON Artista.CodArtista=Scatto.Autore
WHERE Corrente='Impressionismo' AND Genere='foto di ritratto'
ORDER BY Nome,Cognome, TitoloDipinto;

SELECT Nome,Cognome
FROM Artista INNER JOIN Dipinto ON Artista.CodArtista=Dipinto.Autore
 -- se metto INNER JOIN Scatto ON Artista.CodArtista=Scatto.Autore conto di cercare in scatto, quando io scatto non lo devo vedere
WHERE NOT EXISTS(
    SELECT *
    FROM Scatto -- 2. La query interna "legge" Artista da fuori, grazie ai vincoli di scope
    WHERE Scatto.Autore=Artista.CodArtista
);

-- es numero 4
CREATE TABLE Museo(
    MuseoID INT PRIMARY KEY,
    Nome varchar(100) NOT NULL,
);

ALTER TABLE Dipinto
ADD COLUMN MuseoEspositorio INT,
ADD FOREIGN KEY (MuseoEspositorio) REFERENCES Museo(MuseoID);

INSERT INTO Museo VALUES (1,'Uffizzi','Firenze');

UPDATE Dipinto
SET MuseoEspositorio=1
WHERE MuseoEspositorio IS NULL;

ALTER TABLE Dipinto MODIFY MuseoEspositorio INT NOT NULL;

-- esempio spostamento nel museo
UPDATE Dipinto
SET MuseoEspositorio = 2    -- Qui metti l'ID del NUOVO museo
WHERE TitoloDipinto = 'Ninfee blu';

SELECT * FROM Dipinto;
+------------+---------------------------+-------------------+--------+----------+----------------+------------------+
| CodDipinto | TitoloDipinto             | AnnoRealizzazione | Autore | NomeSala | Corrente       | MuseoEspositorio |
+------------+---------------------------+-------------------+--------+----------+----------------+------------------+
|          1 | Levar del sole            |              1901 |      1 | A        | Impressionismo |                1 |
|          2 | Ninfee blu                |              1916 |      1 | A        | Impressionismo |                2 |
|          3 | Primo acquerello astratto |              1910 |      3 | C        | Strattismo     |                1 |
|          4 | Guernica                  |              1937 |      2 | B        | Cubismo        |                1 |
|          5 | Manicaretto               |              2024 |      5 | F        | PorArt         |                1 |
+------------+---------------------------+-------------------+--------+----------+----------------+------------------+
5 rows in set (0,00 sec)
