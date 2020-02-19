SET TIMING ON;
-- Question 1 --
CREATE MATERIALIZED VIEW VM1 BUILD IMMEDIATE
    REFRESH COMPLETE ON DEMAND AS 
        SELECT CodeOP, DateOP FROM Operation
            WHERE TypeOp = 2 AND DateOp BETWEEN '01-01-2018'
                AND '31-01-2018';

-- Question 2 --
-- Création du journal log
CREATE MATERIALIZED VIEW LOG ON Operation;
CREATE MATERIALIZED VIEW VM2 BUILD IMMEDIATE
    REFRESH FAST ON DEMAND AS
        SELECT CodeOP, DateOP FROM Operation
            WHERE TypeOp = 2 AND DateOp BETWEEN '01-01-2018'
                AND '31-01-2018';

-- Question 3 --
-- Insertion
INSERT INTO Operation VALUES(610315, '24-01-2018', 12, 2, 5000, null, 432);
-- Affichage du journal log avant le rafraichaissement
SELECT * FROM MLOG$_Operation;
-- Raffraichaissement
EXECUTE DBMS_MVIEW.REFRESH('VM1');
EXECUTE DBMS_MVIEW.REFRESH('VM2');
-- Affichage du journal log après le rafraichaissement
SELECT * FROM MLOG$_Operation;

-- Question 4 --
-- Suppression
DELETE FROM Operation WHERE CodeOp = 610315;
-- Affichage du journal log avant le rafraichaissement
SELECT * FROM MLOG$_Operation;
-- Raffraichaissement
EXECUTE DBMS_MVIEW.REFRESH('VM1');
EXECUTE DBMS_MVIEW.REFRESH('VM2');
-- Affichage du journal log après le rafraichaissement
SELECT * FROM MLOG$_Operation;
-- Modification
UPDATE Operation SET Montant = 6000 WHERE CodeOp = 610314;
-- Affichage du journal log avant le rafraichaissement
SELECT * FROM MLOG$_Operation;
-- Raffraichaissement
EXECUTE DBMS_MVIEW.REFRESH('VM1');
EXECUTE DBMS_MVIEW.REFRESH('VM2');
-- Affichage du journal log après le rafraichaissement
SELECT * FROM MLOG$_Operation;

-- Question 5 --
CREATE MATERIALIZED VIEW VM3 BUILD IMMEDIATE
    REFRESH COMPLETE ON COMMIT AS 
        SELECT CodeOp, DateOp FROM Operation x, Compte y
        WHERE (NumCompteVersement = NumCompte OR NumCompteRetrait = NumCompte)
            AND NumAgence BETWEEN 1 AND 100;
-- Alimentation de la vue
EXECUTE DBMS_MVIEW.REFRESH('VM3');

-- Question 6 --
INSERT INTO Operation VALUES(610315, '24-01-2018', 12, 2, 5000, null, 137015);
SELECT * FROM VM3 WHERE CodeOp = 610315;
COMMIT;
SELECT * FROM VM3 WHERE CodeOp = 610315;

-- Question 7 --
CREATE MATERIALIZED VIEW VM4 BUILD IMMEDIATE
    REFRESH COMPLETE ON DEMAND AS
    SELECT NumAgence AS CodeAgence, COUNT(*) AS NBComptes FROM Compte
    GROUP BY NumAgence;

-- Question 8 --
CREATE MATERIALIZED VIEW LOG ON Compte;
CREATE MATERIALIZED VIEW VM5 BUILD IMMEDIATE
    REFRESH FAST ON COMMIT AS 
        SELECT CodeOp, DateOp FROM Operation x, Compte y
        WHERE (NumCompteVersement = NumCompte OR NumCompteRetrait = NumCompte)
            AND NumAgence BETWEEN 1 AND 100;

CREATE MATERIALIZED VIEW VM6 BUILD IMMEDIATE
    REFRESH FAST ON DEMAND AS
    SELECT NumAgence AS CodeAgence, COUNT(*) AS NBComptes FROM Compte
    GROUP BY NumAgence;

-- Solution pour la table VM6
DROP MATERIALIZED VIEW LOG ON Compte;
CREATE MATERIALIZED VIEW LOG ON Compte WITH SEQUENCE, ROWID (NumAgence) INCLUDING NEW VALUES;

CREATE MATERIALIZED VIEW VM6 BUILD IMMEDIATE
    REFRESH FAST ON DEMAND AS
    SELECT NumAgence AS CodeAgence, COUNT(*) AS NBComptes FROM Compte
    GROUP BY NumAgence;
