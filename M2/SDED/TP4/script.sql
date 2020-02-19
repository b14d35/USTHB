-- Question 1 --
CONNECT sys AS sysdba
@?\sqlplus\admin\plustrce.sql
GRANT PLUSTRACE TO Master;

SET AUTOTRACE ON;
SET TIMING ON;

-- Question 2 --
UPDATE Wilaya SET NomWilaya='Oran' WHERE CodeWilaya=31;

SELECT c.NumClient, c.NomClient FROM Client c, Compte p,
    Agence a, Ville v, Wilaya w WHERE c.NumClient = p.NumClient 
    AND p.NumAgence = a.NumAgence AND a.CodeVille = v.CodeVille
    AND v.CodeWilaya = w.CodeWilaya AND w.NomWilaya='Oran';

-- Question 4 --
CREATE MATERIALIZED VIEW VM5 BUILD IMMEDIATE 
    REFRESH COMPLETE ON DEMAND ENABLE QUERY REWRITE
    AS SELECT c.NumClient, c.NomClient FROM Client c, Compte p,
    Agence a, Ville v, Wilaya w WHERE c.NumClient = p.NumClient 
    AND p.NumAgence = a.NumAgence AND a.CodeVille = v.CodeVille
    AND v.CodeWilaya = w.CodeWilaya;

-- Question 5 --
ALTER SYSTEM FLUSH SHARED_POOL;
ALTER SYSTEM FLUSH BUFFER_CACHE;
SELECT c.NumClient, c.NomClient FROM Client c, Compte p,
    Agence a, Ville v, Wilaya w WHERE c.NumClient = p.NumClient 
    AND p.NumAgence = a.NumAgence AND a.CodeVille = v.CodeVille
    AND v.CodeWilaya = w.CodeWilaya AND w.NomWilaya='Oran';

-- Question 6 --
CREATE MATERIALIZED VIEW VM6 BUILD IMMEDIATE 
    REFRESH COMPLETE ON DEMAND ENABLE QUERY REWRITE
    AS SELECT c.NumClient, c.NomClient FROM Client c, Compte p,
    Agence a, Ville v, Wilaya w WHERE c.NumClient = p.NumClient 
    AND p.NumAgence = a.NumAgence AND a.CodeVille = v.CodeVille
    AND v.CodeWilaya = w.CodeWilaya AND w.NomWilaya='Oran';

-- Question 7 --
ALTER SYSTEM FLUSH SHARED_POOL;
ALTER SYSTEM FLUSH BUFFER_CACHE;
SELECT c.NumClient, c.NomClient FROM Client c, Compte p,
    Agence a, Ville v, Wilaya w WHERE c.NumClient = p.NumClient 
    AND p.NumAgence = a.NumAgence AND a.CodeVille = v.CodeVille
    AND v.CodeWilaya = w.CodeWilaya AND w.NomWilaya='Oran';

-- Question 8 --
SELECT b.CodeBanque, b.NomBanque, COUNT(*) AS NbOperations FROM
    Operation o, Compte c, Agence a, Banque b WHERE (
        o.NumCompteVersement = c.NumCompte OR o.NumCompteRetrait = c.NumCompte
    ) AND c.NumAgence = a.NumAgence AND a.CodeBanque = b.CodeBanque
    GROUP BY (b.CodeBanque, b.NomBanque);

-- Question 10 --
CREATE MATERIALIZED VIEW VM7 BUILD IMMEDIATE
    REFRESH COMPLETE ON DEMAND ENABLE QUERY REWRITE
    AS SELECT b.CodeBanque, b.NomBanque, COUNT(*) AS NbOperations FROM
    Operation o, Compte c, Agence a, Banque b WHERE (
        o.NumCompteVersement = c.NumCompte OR o.NumCompteRetrait = c.NumCompte
    ) AND c.NumAgence = a.NumAgence AND a.CodeBanque = b.CodeBanque
    GROUP BY (b.CodeBanque, b.NomBanque);

-- Question 11 --
ALTER SYSTEM FLUSH SHARED_POOL;
ALTER SYSTEM FLUSH BUFFER_CACHE;
SELECT b.CodeBanque, b.NomBanque, COUNT(*) AS NbOperations FROM
    Operation o, Compte c, Agence a, Banque b WHERE (
        o.NumCompteVersement = c.NumCompte OR o.NumCompteRetrait = c.NumCompte
    ) AND c.NumAgence = a.NumAgence AND a.CodeBanque = b.CodeBanque
    GROUP BY (b.CodeBanque, b.NomBanque);

-- Question 12 --
DROP MATERIALIZED VIEW VM7;
-- Ajout des tuples jusqu'à 800000
DECLARE
d DATE;
Heure NUMBER;
typeof CHAR(1);
montant NUMBER;
cpt NUMBER;
i NUMBER;
BEGIN
    FOR i IN 610315..800000 LOOP
        SELECT TO_DATE(TRUNC(DBMS_RANDOM.VALUE(TO_CHAR(DATE'2015-01-01','J'),TO_CHAR(DATE'2018-12-31','J'))),'J') INTO d FROM DUAL;
        SELECT TRUNC(DBMS_RANDOM.VALUE(5000, 100000), 2) INTO montant FROM dual;
        SELECT FLOOR(DBMS_RANDOM.VALUE(0, 23.99)) INTO Heure FROM dual;
        SELECT FLOOR(DBMS_RANDOM.VALUE(1, 2.99)) INTO typeof FROM dual;
        SELECT FLOOR(DBMS_RANDOM.VALUE(1, 200000.99)) INTO cpt FROM dual;
        INSERT INTO Operation VALUES(i, d, Heure, typeof, montant, DECODE(typeof, 1, cpt, null), DECODE(typeof, 2, cpt, null));
    END LOOP;
    COMMIT;
END;
/
-- Répeter la requête
ALTER SYSTEM FLUSH SHARED_POOL;
ALTER SYSTEM FLUSH BUFFER_CACHE;
SELECT b.CodeBanque, b.NomBanque, COUNT(*) AS NbOperations FROM
    Operation o, Compte c, Agence a, Banque b WHERE (
        o.NumCompteVersement = c.NumCompte OR o.NumCompteRetrait = c.NumCompte
    ) AND c.NumAgence = a.NumAgence AND a.CodeBanque = b.CodeBanque
    GROUP BY (b.CodeBanque, b.NomBanque);
-- Recréer la vue
CREATE MATERIALIZED VIEW VM7 BUILD IMMEDIATE
    REFRESH COMPLETE ON DEMAND ENABLE QUERY REWRITE
    AS SELECT b.CodeBanque, b.NomBanque, COUNT(*) AS NbOperations FROM
    Operation o, Compte c, Agence a, Banque b WHERE (
        o.NumCompteVersement = c.NumCompte OR o.NumCompteRetrait = c.NumCompte
    ) AND c.NumAgence = a.NumAgence AND a.CodeBanque = b.CodeBanque
    GROUP BY (b.CodeBanque, b.NomBanque);

-- Répeter la requête
ALTER SYSTEM FLUSH SHARED_POOL;
ALTER SYSTEM FLUSH BUFFER_CACHE;
SELECT b.CodeBanque, b.NomBanque, COUNT(*) AS NbOperations FROM
    Operation o, Compte c, Agence a, Banque b WHERE (
        o.NumCompteVersement = c.NumCompte OR o.NumCompteRetrait = c.NumCompte
    ) AND c.NumAgence = a.NumAgence AND a.CodeBanque = b.CodeBanque
    GROUP BY (b.CodeBanque, b.NomBanque);

-- Ajout des tuples jusqu'à 1000000
DROP MATERIALIZED VIEW VM7;
DECLARE
d DATE;
Heure NUMBER;
typeof CHAR(1);
montant NUMBER;
cpt NUMBER;
i NUMBER;
BEGIN
    FOR i IN 800001..1000000 LOOP
        SELECT TO_DATE(TRUNC(DBMS_RANDOM.VALUE(TO_CHAR(DATE'2015-01-01','J'),TO_CHAR(DATE'2018-12-31','J'))),'J') INTO d FROM DUAL;
        SELECT TRUNC(DBMS_RANDOM.VALUE(5000, 100000), 2) INTO montant FROM dual;
        SELECT FLOOR(DBMS_RANDOM.VALUE(0, 23.99)) INTO Heure FROM dual;
        SELECT FLOOR(DBMS_RANDOM.VALUE(1, 2.99)) INTO typeof FROM dual;
        SELECT FLOOR(DBMS_RANDOM.VALUE(1, 200000.99)) INTO cpt FROM dual;
        INSERT INTO Operation VALUES(i, d, Heure, typeof, montant, DECODE(typeof, 1, cpt, null), DECODE(typeof, 2, cpt, null));
    END LOOP;
    COMMIT;
END;
/
-- Répeter la requête
ALTER SYSTEM FLUSH SHARED_POOL;
ALTER SYSTEM FLUSH BUFFER_CACHE;
SELECT b.CodeBanque, b.NomBanque, COUNT(*) AS NbOperations FROM
    Operation o, Compte c, Agence a, Banque b WHERE (
        o.NumCompteVersement = c.NumCompte OR o.NumCompteRetrait = c.NumCompte
    ) AND c.NumAgence = a.NumAgence AND a.CodeBanque = b.CodeBanque
    GROUP BY (b.CodeBanque, b.NomBanque);

-- Recréer la vue
CREATE MATERIALIZED VIEW VM7 BUILD IMMEDIATE
    REFRESH COMPLETE ON DEMAND ENABLE QUERY REWRITE
    AS SELECT b.CodeBanque, b.NomBanque, COUNT(*) AS NbOperations FROM
    Operation o, Compte c, Agence a, Banque b WHERE (
        o.NumCompteVersement = c.NumCompte OR o.NumCompteRetrait = c.NumCompte
    ) AND c.NumAgence = a.NumAgence AND a.CodeBanque = b.CodeBanque
    GROUP BY (b.CodeBanque, b.NomBanque);

-- Répeter la requête
ALTER SYSTEM FLUSH SHARED_POOL;
ALTER SYSTEM FLUSH BUFFER_CACHE;
SELECT b.CodeBanque, b.NomBanque, COUNT(*) AS NbOperations FROM
    Operation o, Compte c, Agence a, Banque b WHERE (
        o.NumCompteVersement = c.NumCompte OR o.NumCompteRetrait = c.NumCompte
    ) AND c.NumAgence = a.NumAgence AND a.CodeBanque = b.CodeBanque
    GROUP BY (b.CodeBanque, b.NomBanque);
