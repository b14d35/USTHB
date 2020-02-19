CREATE USER Master2 IDENTIFIED BY pwd DEFAULT TABLESPACE system QUOTA UNLIMITED ON system;
GRANT ALL PRIVILEGES TO Master2;

-- Création des tables --
CREATE TABLE DClient(
    NumClient NUMBER(10),
    NomClient VARCHAR2(10),
    DNClient DATE,
    CONSTRAINT pk_Client PRIMARY KEY (NumClient)
)

CREATE TABLE DAgence(
    NumAgence NUMBER(10),
    NomAgence VARCHAR2(10),
    CodeBanque NUMBER(10),
    NomBanque VARCHAR2(10),
    CodeVille NUMBER(10),
    NomVille VARCHAR2(10),
    CodeWilaya NUMBER(2),
    NomWilaya VARCHAR2(10),
    CONSTRAINT pk_Agence PRIMARY KEY (NumAgence)
);

CREATE TABLE DTypeCompte(
    CodeType NUMBER(2),
    LibType VARCHAR2(10),
    CONSTRAINT pk_Type PRIMARY KEY (CodeType)
);

CREATE TABLE DTemps(
    CodeTemps NUMBER(6),
    Jour VARCHAR2(10),
    LibJour VARCHAR2(10),
    Mois VARCHAR2(10),
    LibMois VARCHAR2(10),
    Annee VARCHAR2(10),
    CONSTRAINT pk_Temps PRIMARY KEY (CodeTemps)
);

CREATE TABLE FOperation(
    NumClient NUMBER(10),
    NumAgence NUMBER(10),
    CodeTypeCompte NUMBER(2),
    CodeTemps NUMBER(6),
    NbOperationsR NUMBER(6),
    NbOperationsV NUMBER(6),
    MontantR NUMBER,
    MontantV NUMBER,
    CONSTRAINT pk_Operation PRIMARY KEY (NumClient, NumAgence, CodeTypeCompte, CodeTemps),
    CONSTRAINT fk_Client FOREIGN KEY (NumClient) REFERENCES DClient(NumClient),
    CONSTRAINT fk_Agence FOREIGN KEY (NumAgence) REFERENCES DAgence(NumAgence),
    CONSTRAINT fk_Type FOREIGN KEY (CodeTypeCompte) REFERENCES DTypeCompte(CodeType),
    CONSTRAINT fk_Temps FOREIGN KEY (CodeTemps) REFERENCES DTemps(CodeTemps)
);

-- Insertion dans les tables --
BEGIN
    FOR i IN (SELECT NumClient, NomClient, DNClient FROM Master.Client) LOOP
        INSERT INTO DCLIENT VALUES(i.NumClient, i.NomClient, i.DNClient);
    END LOOP;
    COMMIT;
END;
/

BEGIN
    FOR i IN (
        SELECT a.NumAgence, a.NomAgence, b.CodeBanque, b.NomBanque, 
        v.CodeVille, v.NomVille, w.CodeWilaya, w.NomWilaya FROM 
        Master.Agence a, Master.Banque b, Master.Ville v, Master.Wilaya w 
        WHERE a.CodeBanque = b.CodeBanque AND a.CodeVille = v.CodeVille AND v.CodeWilaya = w.CodeWilaya
        ) LOOP
        INSERT INTO DAgence VALUES(
            i.NumAgence, i.NomAgence, i.CodeBanque, i.NomBanque, 
            i.CodeVille, i.NomVille, i.CodeWilaya, i.NomWilaya
        );
    END LOOP;
    COMMIT;
END;
/

BEGIN
    FOR i IN (SELECT CodeType, LibType FROM Master.Type_Compte) LOOP
        INSERT INTO DTypeCompte VALUES(i.CodeType, i.LibType);
    END LOOP;
    COMMIT;
END;
/

-- Crétation de la séquence --
CREATE SEQUENCE seq 
    MINVALUE 1 MAXVALUE 100000
    START WITH 1 INCREMENT BY 1;

BEGIN
    FOR i IN (SELECT DISTINCT(DateOp) FROM Master.Operation) LOOP
        INSERT INTO DTemps VALUES(
            seq.NEXTVAL, TO_CHAR(i.DateOp, 'DD/MM/YYYY'), 
            TO_CHAR(i.DateOp, 'DAY'), TO_CHAR(i.DateOp, 'MM/YYYY'), 
            TO_CHAR(i.DateOp, 'MONTH'), TO_CHAR(i.DateOp, 'YYYY')
        );
    END LOOP;
    COMMIT;
END;
/

BEGIN
    FOR i IN (
        SELECT c.NumClient, c.NumAgence, c.CodeType, t.CodeTemps, 
            SUM(DECODE(o.TypeOp, 2, 1, 0)) as NbOperationsR, 
            SUM(DECODE(o.TypeOp, 1, 1, 0)) as NbOperationsV, 
            SUM(DECODE(o.TypeOp, 2, o.Montant, 0)) as MontantR, 
            SUM(DECODE(o.TypeOp, 1, o.Montant, 0)) as MontantV 
            FROM Master.Compte c, Master.Operation o, DTemps t 
            WHERE t.jour = TO_CHAR(o.DateOp, 'DD/MM/YYYY') AND
            (o.NumCompteRetrait = c.NumCompte 
                OR o.NumCompteVersement = c.NumCompte)
            GROUP BY (c.NumClient, c.NumAgence, c.CodeType, t.CodeTemps)
    ) LOOP
        INSERT INTO FOperation VALUES(i.NumClient, i.NumAgence,
            i.CodeType, i.CodeTemps, i.NbOperationsR, 
            i.NbOperationsV, i.MontantR, i.MontantV
        );
    END LOOP;
    COMMIT;
END;
/
