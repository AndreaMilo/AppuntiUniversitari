-- es 1
CREATE DATABASE MagistraleInformatica;
USE MagistraleInformatica;

CREATE TABLE CdL(
    codCdL INT PRIMARY KEY,
    NomeCdL varchar(80) NOT NULL,
    Sede varchar(50) NOT NULL,
    AnnoIstituzione YEAR NOT NULL,

    CHECK (NomeCdL IN ('ComputerScience','DataScience','SicurezzaInformatica')),
    CHECK (Sede IN ('Bari','Taranto'))
);

CREATE TABLE Studente(
    Matr INT(8) NOT NULL,
    CF varchar(18) NOT NULL,
    Nome varchar(50) NOT NULL,
    Cognome varchar(50) NOT NULL,
    DataNascita DATE NOT NULL,
    AnnoImmatricolazione YEAR NOT NULL,
    CdL INT NOT NULL,

    FOREIGN KEY (CdL) REFERENCES CdL(codCdL),
    PRIMARY KEY(Matr,CF)
);

CREATE TABLE Insegnamento(
    Cod INT PRIMARY KEY,
    Nome varchar(50) NOT NULL,
    Descrizione varchar(150),
    Semestre char(3) NOT NULL,
    Anno char(3) NOT NULL,
    CdL INT NOT NULL,

    FOREIGN KEY (CdL) REFERENCES CdL(codCdL),
    CHECK (Semestre IN ('I','II')),
    CHECK (Anno IN ('I','II'))
);

CREATE TABLE Docente(
    MatrDocente INT PRIMARY KEY,
    Nome varchar(50) NOT NULL,
    Cognome varchar(50) NOT NULL,
    CFDocente varchar(18) NOT NULL,
    DataNascitaDocente DATE NOT NULL
);

CREATE TABLE DocenteInsegnamento(
    CodInsegnamento INT NOT NULL,
    MatrDocente INT NOT NULL,

    FOREIGN KEY (CodInsegnamento) REFERENCES Insegnamento(Cod),
    FOREIGN KEY (MatrDocente) REFERENCES Docente(MatrDocente)
);

-- es 2
INSERT INTO CdL(codCdL,NomeCdL,Sede,AnnoIstituzione) VALUES
    (1,'ComputerScience','Bari',1990),
    (2,'DataScience','Taranto',1999),
    (3,'SicurezzaInformatica','Bari',2000),
    (4,'SicurezzaInformatica','Taranto',2010),
    (5,'ComputerScience','Taranto',2000);

INSERT INTO Studente(Matr,Nome,Cognome,CF,DataNascita,AnnoImmatricolazione,CdL) VALUES
    (1000,'Andrea','Milo','BRNSFN80A01H501Z','2005-10-20',2024,2),
    (1001,'Francesco','Sblendorio','VRDGLI92M55F205Q','2005-05-02',2024,1),
    (1002,'Giuseppe','Sifanno','RSSMRA75T10L219A','2005-12-30',2024,3),
    (1003,'Davide','Santoruvo','RSSMRA75T10L318A','2000-04-12',2000,4),
    (1004,'Emanuenzi','Santoruvo','FRRLCU99R15D612K','2005-12-04',1995,3);

INSERT INTO Insegnamento(Cod,Nome,Descrizione,Semestre,Anno,CdL) VALUES
    (0001,'Programmazione',NULL,'I','I',1),
    (0002,'BaseDati',NULL,'I','II',2),
    (0003,'SistemiReti',NULL,'II','II',3),
    (0004,'Telecomunicazioni',NULL,'II','I',3),
    (0005,'Linguaggi',NULL,'I','II',5);

INSERT INTO Docente(MatrDocente,Nome,Cognome,CFDocente,DataNascitaDocente) VALUES
    (2000,'Veronica','Rossano','BNCLGU65A01H501X','1960-10-11'),
    (2001,'Pasquale','Lops','SPSMRA78M50F839K','1970-09-10'),
    (2002,'Signora','Azzali','RCCGNN82R15A944J','1890-09-10'),
    (2003,'Gennaro Giuseppe','Bevilacqua','RMNNAA70D62L219Y','1980-09-10');

INSERT INTO DocenteInsegnamento(CodInsegnamento,MatrDocente) VALUES
    (0001,2000),
    (0003,2003),
    (0005,2001),
    (0004,2002),
    (0002,2002);

-- es 3.1
SELECT D.Nome,D.Cognome,D.MatrDocente
FROM Docente D
WHERE D.MatrDocente
IN(
    SELECT Di.MatrDocente
    FROM DocenteInsegnamento Di JOIN Insegnamento I ON Di.CodInsegnamento=I.Cod JOIN CdL C ON I.CdL=C.codCdL
    WHERE C.Sede='Bari'
)
AND D.MatrDocente
IN(
    SELECT Di.MatrDocente
    FROM DocenteInsegnamento Di JOIN Insegnamento I ON Di.CodInsegnamento=I.Cod JOIN CdL C ON I.CdL=C.codCdL
    WHERE C.Sede='Taranto'
)
AND D.MatrDocente
IN(
    SELECT Di.MatrDocente
    FROM DocenteInsegnamento Di
    GROUP BY Di.MatrDocente
    HAVING COUNT(Di.MatrDocente)>1
);

-- es 3.2
SELECT I.Cod,I.Nome,D.Nome,D.MatrDocente
FROM Insegnamento I JOIN DocenteInsegnamento Di ON I.Cod=Di.CodInsegnamento JOIN Docente D ON D.MatrDocente=Di.MatrDocente JOIN CdL C ON I.CdL=C.codCdL
WHERE C.NomeCdL='DataScience'
ORDER BY Semestre, Anno;

-- es 3.3
SELECT D.Nome,D.Cognome,D.MatrDocente
FROM Docente D LEFT JOIN DocenteInsegnamento Di ON D.MatrDocente=Di.MatrDocente
WHERE Di.CodInsegnamento IS NULL; -- con il LEFT JOIN nell'unione mi rimangono i valori NULL di docente diversamente dal join che toglie i NULL, così vedo quali non hanno docenza

-- es 4.1
ALTER TABLE CdL DROP CHECK CdL_chk_1; -- Con SHOW CREATE TABLE CdL vedo il nome del vincolo
ALTER TABLE CdL MODIFY COLUMN NomeCdL varchar(80) NOT NULL CHECK (NomeCdL IN ('ComputerScience','DataScience','SicurezzaInformatica','ICD','ITPS','Informatica'));
-- es 4.2
ALTER TABLE DocenteInsegnamento ADD CONSTRAINT UNIQUE (CodInsegnamento);
