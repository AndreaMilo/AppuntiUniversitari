-- es 1
CREATE DATABASE StudentiInformatica;
USE StudentiInformatica;

CREATE TABLE Studente(
    Matr INT NOT NULL,
    Nome varchar(50) NOT NULL,
    Cognome varchar(50) NOT NULL,
    CF char(18) NOT NULL,
    DataNascita DATE NOT NULL,
    AnnoImmatricolazione YEAR NOT NULL,

    PRIMARY KEY(Matr)
);

CREATE TABLE Docente(
    MatrDocente INT PRIMARY KEY,
    Nome varchar(50) NOT NULL,
    Cognome varchar(50) NOT NULL,
    CF char(18) NOT NULL,
    DataNascita DATE NOT NULL
);

CREATE TABLE Insegnamento(
    Cod INT PRIMARY KEY,
    Nome varchar(50) NOT NULL,
    Descrizione varchar(100),
    Anno char(3) NOT NULL,
    Docente INT NOT NULL,

    FOREIGN KEY (Docente) REFERENCES Docente(MatrDocente),
    CHECK (Anno IN('I','II','III'))
);

CREATE TABLE Esame(
    CodInsegnamento INT NOT NULL,
    MatrStudente INT NOT NULL,
    Data DATE NOT NULL,
    Voto INT NOT NULL,
    Lode char(2) NOT NULL,

    CHECK (Lode IN('Si','No')),
    CHECK (Voto<=30),
    FOREIGN KEY (MatrStudente) REFERENCES Studente(Matr),
    FOREIGN KEY (CodInsegnamento) REFERENCES Insegnamento(Cod)
);

-- es 2
INSERT INTO Studente(Matr,Nome,Cognome,DataNascita,AnnoImmatricolazione,CF) VALUES
    (1000,'Andrea','Milo','2005-10-20',2014,'MLNIDR05RN04'),
    (1001,'Chiara','Aracri','2005-10-02',2024,'ARCR980JC9J3'),
    (1002,'Lara','Rossi','2000-10-20',2010,'LRARRSS9804D'),
    (1003,'Giancarlo','Ugugaga','1999-10-20',2007,'GUGGAGA7827');

INSERT INTO Docente(MatrDocente,Nome,Cognome,CF,DataNascita) VALUES
    (000,'Paolo','Zucca','DFDSIIS02ND','1995-10-20'),
    (001,'Monica','Aracri','DJASJDICDI0','1899-10-02'),
    (002,'Lello','Kavasaki','ALOCPPAJD8','1949-10-20'),
    (003,'Luisa','Gialli','AKAKHYEUCNS12','1981-10-20');

INSERT INTO Insegnamento(Cod,Nome,Descrizione,Anno,Docente) VALUES
    (1,'Matematica',NULL,'I',000),
    (2,'Italiano',NULL,'I',001),
    (3,'Storia',NULL,'II',001),
    (4,'Chimica',NULL,'III',003);

INSERT INTO Esame(CodInsegnamento,MatrStudente,Data,Voto,Lode) VALUES
    (1,1000,'2024-07-07',27,'no'),
    (1,1001,'2024-10-12',17,'no'),
    (2,1002,'2024-10-12',30,'si'),
    (3,1003,'2023-10-10',18,'no');

-- es 3.1
SELECT S.Nome,S.Cognome,S.Matr,E.CodInsegnamento,I.Nome,E.Data,E.Voto
FROM Studente S INNER JOIN Esame E ON S.Matr=E.MatrStudente JOIN Insegnamento I ON E.CodInsegnamento=I.Cod
WHERE S.Matr IN(
    SELECT E2.MatrStudente
    FROM Esame E2 JOIN Insegnamento I2 ON E2.CodInsegnamento=I2.Cod
    WHERE I2.Nome='Matematica' AND MONTH(E2.Data) BETWEEN 6 AND 7
        AND YEAR(E2.Data)=2020 AND E2.Voto>=18
)
ORDER BY E.CodInsegnamento,I.Nome,E.Data,E.Voto;

-- es 3.2
SELECT S.Nome,S.Cognome,S.Matr,COUNT(*) AS NumEsami, AVG(E.Voto) AS MediaVoti
FROM Studente S INNER JOIN Esame E ON S.Matr=E.MatrStudente
WHERE E.Voto>=18
GROUP BY S.Nome,S.Matr
HAVING COUNT(E.MatrStudente)>=6
ORDER BY NumEsami DESC, MediaVoti DESC, S.Cognome ASC;

-- es 3.3
SELECT S.Nome,S.Cognome,S.Matr,S.DataNascita,S.AnnoImmatricolazione
FROM Studente S LEFT JOIN Esame E ON S.Matr=E.MatrStudente -- col join normale toglie i NULL ANDREA RICORDALOOO
WHERE S.Matr NOT IN(
    SELECT E.MatrStudente
    FROM Esame E
)
ORDER BY S.AnnoImmatricolazione DESC;
