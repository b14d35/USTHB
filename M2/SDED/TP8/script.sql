-- Question 1 --
SELECT COUNT(*) AS NbrAgence FROM DAgence 
    WHERE NomBanque='Delta';

-- Question 2 --
CREATE INDEX MyIndex1
    ON DAgence(NomBanque)
    TABLESPACE system;

-- Question 3 --
ALTER SYSTEM FLUSH SHARED_POOL;
ALTER SYSTEM FLUSH BUFFER_CACHE;
SELECT COUNT(*) AS NbrAgence FROM DAgence 
    WHERE NomBanque='Delta';
-- Examiner le temps et le plan d'exec

-- Question 4 --
DROP INDEX MyIndex1;
CREATE BITMAP INDEX MyIndex1
    ON DAgence(NomBanque)
    TABLESPACE system;

-- Question 5 --
ALTER SYSTEM FLUSH SHARED_POOL;
ALTER SYSTEM FLUSH BUFFER_CACHE;
SELECT COUNT(*) AS NbrAgence FROM DAgence 
    WHERE NomBanque='Delta';
-- Comparez les trois executions

-- Question 6 --
SELECT SUM(MontantV) FROM FOperation, DTypeCompte
    WHERE CodeType = CodeTypeCompte AND LibType='Epargne';

-- Question 7 --
CREATE BITMAP INDEX MyIndex2
    ON FOperation(DTypeCompte.LibType)
    FROM FOperation, DTypeCompte
    WHERE DTypeCompte.CodeType = FOperation.CodeTypeCompte;

-- Question 8 --
ALTER SYSTEM FLUSH SHARED_POOL;
ALTER SYSTEM FLUSH BUFFER_CACHE;
SELECT /*+ index(FOperation MyIndex2) */  SUM(MontantV)
    FROM FOperation, DTypeCompte
    WHERE CodeType = CodeTypeCompte AND LibType='Epargne';
-- Comparez les 2 executions

-- Question 9 --
SELECT SUM(MontantV) FROM FOperation f, DAgence d
    WHERE f.NumAgence = d.NumAgence AND d.NomWilaya = 'Alger';

-- Question 10 --
CREATE BITMAP INDEX MyIndex3
    ON FOperation(DAgence.NomWilaya)
    FROM FOperation, DAgence
    WHERE FOperation.NumAgence = DAgence.NumAgence;

-- Question 11 --
ALTER SYSTEM FLUSH SHARED_POOL;
ALTER SYSTEM FLUSH BUFFER_CACHE;
SELECT /*+ index(FOperation MyIndex3) */ SUM(MontantV)
    FROM FOperation f, DAgence d
    WHERE f.NumAgence = d.NumAgence AND d.NomWilaya = 'Alger';
-- Comparez les deux executions

-- Question 12 --
CREATE TABLE FOperation2(
    NumClient NUMBER(10), NumAgence NUMBER(10),
    CodeTypeCompte NUMBER(2), CodeTemps NUMBER(6),
    NbOperationsR NUMBER(6), NbOperationsV NUMBER(6),
    MontantR NUMBER, MontantV NUMBER,
    CONSTRAINT pk_Operation1 PRIMARY KEY (NumClient, NumAgence, CodeTypeCompte, CodeTemps),
    CONSTRAINT fk_Client1 FOREIGN KEY (NumClient) REFERENCES DClient(NumClient),
    CONSTRAINT fk_Agence1 FOREIGN KEY (NumAgence) REFERENCES DAgence(NumAgence),
    CONSTRAINT fk_Type1 FOREIGN KEY (CodeTypeCompte) REFERENCES DTypeCompte(CodeType),
    CONSTRAINT fk_Temps1 FOREIGN KEY (CodeTemps) REFERENCES DTemps(CodeTemps)
)
PARTITION BY RANGE(NumAgence)(
    PARTITION P1 VALUES LESS THAN (4000),
    PARTITION P2 VALUES LESS THAN (7000),
    PARTITION P3 VALUES LESS THAN (10000),
    PARTITION P4 VALUES LESS THAN (MAXVALUE)
);

-- Question 13 --
INSERT INTO FOperation2 SELECT * FROM FOperation;

-- Question 14 --
SELECT SUM(MontantV) FROM FOperation
    WHERE NumAgence = 12014;

-- Question 15 --
ALTER SYSTEM FLUSH SHARED_POOL;
ALTER SYSTEM FLUSH BUFFER_CACHE;
SELECT SUM(MontantV) FROM FOperation2
    WHERE NumAgence = 12014;
-- Comparez les deux executions
