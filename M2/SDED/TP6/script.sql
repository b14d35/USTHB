-- Question 1 --
UPDATE DAgence SET NomWilaya='Alger' WHERE CodeWilaya=16;
SELECT SUM(NbOperationsR+NbOperationsV) AS Somme FROM FOperation o, DAgence a
    WHERE o.NumAgence = a.NumAgence AND a.NomWilaya='Alger';

-- Question 2 --
CREATE MATERIALIZED VIEW VMWilaya BUILD IMMEDIATE
    REFRESH COMPLETE ON DEMAND ENABLE QUERY REWRITE
    AS SELECT a.CodeWilaya, a.NomWilaya, SUM(o.NbOperationsR+o.NbOperationsV) AS Somme FROM FOperation o, DAgence a WHERE o.NumAgence = a.NumAgence
    GROUP BY (a.CodeWilaya, a.NomWilaya);

-- Question 3 --
ALTER SYSTEM FLUSH SHARED_POOL;
ALTER SYSTEM FLUSH BUFFER_CACHE;
SELECT SUM(NbOperationsR+NbOperationsV) AS Somme FROM FOperation o, DAgence a
    WHERE o.NumAgence = a.NumAgence AND a.NomWilaya='Alger';
-- Comparer le temps d'execution --

-- Question 4 --
CREATE MATERIALIZED VIEW VMMontant BUILD IMMEDIATE
    REFRESH COMPLETE ON DEMAND ENABLE QUERY REWRITE
    AS SELECT t.Mois, SUM(o.MontantV) AS MontantV FROM FOperation o, DTemps t
    WHERE o.CodeTemps = t.CodeTemps GROUP BY t.Mois;

-- Question 5 --
ALTER SYSTEM FLUSH SHARED_POOL;
ALTER SYSTEM FLUSH BUFFER_CACHE;
SELECT t.Annee, SUM(o.MontantV) AS MontantV FROM FOperation o, DTemps t
    WHERE o.CodeTemps = t.CodeTemps GROUP BY t.Annee;
-- Exploite t-il la VM? PK?

-- QUestion 6 --
-- Méta données Dim_Client
CREATE DIMENSION Dim_Client
    LEVEL NumClient IS (DClient.NumClient)
    ATTRIBUTE NumClient DETERMINES (DClient.NomClient, DClient.DNClient);

-- Méta données Dim_Agence
CREATE DIMENSION Dim_Agence
    LEVEL CodeBanque IS (DAgence.CodeBanque)
    LEVEL NumAgence IS (DAgence.NumAgence)
    LEVEL CodeVille IS (DAgence.CodeVille)
    LEVEL CodeWilaya IS (DAgence.CodeWilaya)
    HIERARCHY h_agence (CodeBanque CHILD OF NumAgence)
    HIERARCHY h_place (NumAgence CHILD OF CodeVille CHILD OF CodeWilaya)
    ATTRIBUTE CodeBanque DETERMINES (DAgence.NomBanque)
    ATTRIBUTE NumAgence DETERMINES (DAgence.NomAgence)
    ATTRIBUTE CodeVille DETERMINES (DAgence.NomVille)
    ATTRIBUTE CodeWilaya DETERMINES (DAgence.NomWilaya);

-- Méta données Dim_TypeCompte
CREATE DIMENSION Dim_TypeCompte
    LEVEL CodeType IS (DTypeCompte.CodeType)
    ATTRIBUTE CodeType DETERMINES (DTypeCompte.LibType);

-- Méta données Dim_Temps
CREATE DIMENSION Dim_Temps
    LEVEL CodeTemps IS (DTemps.CodeTemps)
    LEVEL Mois IS (DTemps.Mois)
    LEVEL Annee IS (DTemps.Annee)
    HIERARCHY h_temps (CodeTemps CHILD OF Mois CHILD OF Annee)
    ATTRIBUTE CodeTemps DETERMINES (DTemps.Jour, DTemps.LibJour)
    ATTRIBUTE Mois DETERMINES (DTemps.LibMois);

-- Question 7 --
ALTER SESSION SET QUERY_REWRITE_INTEGRITY=TRUSTED;

-- Question 8 --
ALTER SYSTEM FLUSH SHARED_POOL;
ALTER SYSTEM FLUSH BUFFER_CACHE;
SELECT t.Annee, SUM(o.MontantV) AS MontantV FROM FOperation o, DTemps t
    WHERE o.CodeTemps = t.CodeTemps GROUP BY t.Annee;

-- Question 9 --
CREATE MATERIALIZED VIEW VMMontantVVille BUILD IMMEDIATE
    REFRESH COMPLETE ON DEMAND ENABLE QUERY REWRITE
    AS SELECT a.CodeVille, a.NomVille, SUM(o.MontantV) AS MontantV 
    FROM FOperation o, DAgence a WHERE o.NumAgence = a.NumAgence
    GROUP BY (a.CodeVille, a.NomVille);

-- Question 10 --
ALTER SYSTEM FLUSH SHARED_POOL;
ALTER SYSTEM FLUSH BUFFER_CACHE;
SELECT a.CodeWilaya, a.NomWilaya, SUM(o.MontantV) AS MontantV
    FROM FOperation o, DAgence a WHERE o.NumAgence = a.NumAgence
    GROUP BY (a.CodeWilaya, a.NomWilaya);

-- Question 11 --
-- Analyser le temps de réponse --

-- Question 12 --
DROP DIMENSION Dim_Agence;
ALTER SYSTEM FLUSH SHARED_POOL;
ALTER SYSTEM FLUSH BUFFER_CACHE;
SELECT a.CodeWilaya, a.NomWilaya, SUM(o.MontantV) AS MontantV
    FROM FOperation o, DAgence a WHERE o.NumAgence = a.NumAgence
    GROUP BY (a.CodeWilaya, a.NomWilaya);

-- Question 13 --
-- C'est quoi la conclusion? --

-- Question 14 --
-- C'est quoi l'interet de la commande: --
-- alter session set query_rewrite_integrity=trusted --
