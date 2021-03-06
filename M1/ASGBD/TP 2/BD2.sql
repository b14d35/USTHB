---- Question 1 ----
CREATE USER AdminHopital IDENTIFIED BY password DEFAULT TABLESPACE HOSPITAL_TBS TEMPORARY TABLESPACE HOSPITAL_tEMPTBS;

---- Question 2 ----
Connect AdminHopital /password
-- L'utilisateur n'a pas le droit de créer une session --

---- Question 3 ----
GRANT CREATE SESSION TO AdminHopital;

---- Question 4 ----
ALTER USER AdminHopital QUOTA UNLIMITED ON HOSPITAL_TBS;

GRANT CREATE TABLE TO AdminHopital;
CREATE TABLE x (x NUMBER);
DESC x;
DROP TABLE x;

GRANT CREATE USER TO AdminHopital;
CREATE USER x IDENTIFIED BY x;
-- Can't Drop the User --

---- Question 5 ----
SELECT * FROM DBAHOPITAL.EMPLOYE;
-- Inexistant !!!--

---- Question 6 ----
GRANT SELECT ON DBAHOPITAL.EMPLOYE TO AdminHopital;
SELECT * FROM DBAHOPITAL.EMPLOYE;

---- Question 7 ----
SELECT * FROM DBAHOPITAL.EMPLOYE WHERE NOM_EMP LIKE 'ABDELMOUMEN' AND PRENOM_EMP LIKE 'Nassima';
-- Il faut changer l'adresse --
UPDATE DBAHOPITAL.EMPLOYE SET ADRESSE_EMP='152, rue Hassiba Ben Bouali 2eme etage -Hamma- Alger' WHERE NOM_EMP LIKE 'ABDELMOUMEN' AND PRENOM_EMP LIKE 'Nassima';
-- Privileges insuffisant --

---- Question 8 ----
GRANT UPDATE ON DBAHOPITAL.EMPLOYE TO AdminHopital;
UPDATE DBAHOPITAL.EMPLOYE SET ADRESSE_EMP='152, rue Hassiba Ben Bouali 2eme etage -Hamma- Alger' WHERE NOM_EMP LIKE 'ABDELMOUMEN' AND PRENOM_EMP LIKE 'Nassima';

---- Question 9 ----
CREATE INDEX EMPLOYENOM_IX ON DBAHOPITAL.EMPLOYE (NOM_EMP);
-- Privileges insuffisant --

---- Question 10 ----
GRANT INDEX ON DBAHOPITAL.EMPLOYE TO AdminHopital;
CREATE INDEX EMPLOYENOM_IX ON DBAHOPITAL.EMPLOYE (NOM_EMP);
-- L'index se crée normalement --

---- Question 11 ----
REVOKE ALL PRIVILEGES ON DBAHOPITAL.EMPLOYE FROM AdminHopital;

---- Question 12 ----
-- Les requetes d'avant ne marchent plus --

---- Question 13 ----
CREATE PROFILE Admin_Profil LIMIT
	SESSIONS_PER_USER 4 
	CPU_PER_CALL 4000 
	CONNECT_TIME 50
	LOGICAL_READS_PER_CALL 1500
	PRIVATE_SGA 20K
	IDLE_TIME 30
	FAILED_LOGIN_ATTEMPTS 3
	PASSWORD_LIFE_TIME 60
	PASSWORD_REUSE_TIME 40
	PASSWORD_LOCK_TIME 1
	PASSWORD_GRACE_TIME 5;
	
---- Question 14 ----
ALTER USER AdminHopital PROFILE Admin_Profil;

---- Question 15 ----
CREATE ROLE GestionnairePatient;
GRANT SELECT ON DBAHOPITAL.PATIENT TO GestionnairePatient;
GRANT SELECT ON DBAHOPITAL.HOSPITALISATION TO GestionnairePatient;
GRANT SELECT ON DBAHOPITAL.SOIGNE TO GestionnairePatient;
GRANT UPDATE ON DBAHOPITAL.HOSPITALISATION TO GestionnairePatient;

---- Question 16 ----
GRANT GestionnairePatient TO AdminHopital;
SELECT * FROM DBAHOPITAL.PATIENT;
SELECT * FROM DBAHOPITAL.HOSPITALISATION;
SELECT * FROM DBAHOPITAL.SOIGNE;
UPDATE DBAHOPITAL.HOSPITALISATION SET LIT=2 WHERE CODE_SERVICE LIKE 'REA' AND NUM_PATIENT=1;
UPDATE DBAHOPITAL.HOSPITALISATION SET LIT=1 WHERE CODE_SERVICE LIKE 'REA' AND NUM_PATIENT=1;