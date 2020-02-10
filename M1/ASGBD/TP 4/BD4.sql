SET SERVEROUTPUT ON;
-- Question 1 --
DECLARE
CURSOR cr IS SELECT x.CODE_SERVICE, x.NOM_SERVICE, y.NUM_CHAMBRE, y.NB_LITS FROM SERVICE x, CHAMBRE y WHERE x.CODE_SERVICE=y.CODE_SERVICE ORDER BY y.CODE_SERVICE;
c_rec cr%ROWTYPE;
CURSOR cr2 IS SELECT CODE_SERVICE, NUM_CHAMBRE, COUNT(LIT) AS Nbr FROM HOSPITALISATION GROUP BY CODE_SERVICE,NUM_CHAMBRE ORDER BY CODE_SERVICE;
c_rec2 cr2%ROWTYPE;
i BINARY_INTEGER;
BEGIN
	OPEN cr;
	LOOP
		FETCH cr INTO c_rec;
		EXIT WHEN cr%NOTFOUND;
		OPEN cr2;
		i := 0;
		LOOP
			FETCH cr2 INTO c_rec2;
			EXIT WHEN cr2%NOTFOUND;
			IF c_rec2.CODE_SERVICE=c_rec.CODE_SERVICE AND c_rec.NUM_CHAMBRE=c_rec2.NUM_CHAMBRE THEN
				i := c_rec2.Nbr;
				EXIT;
			END IF;
		END LOOP;
		CLOSE cr2;
		DBMS_OUTPUT.PUT_LINE('La chambre N° '||c_rec.NUM_CHAMBRE||' de service '||c_rec.NOM_SERVICE||' possède '||i||' lit(s) ocuupé(s) et '||(c_rec.NB_LITS-i)||' lit(s) libre(s).');
	END LOOP;
END;
/

-- Question 2 --
ALTER TABLE INFIRMIER DISABLE CONSTRAINT Salaire_10k_30k;

CREATE OR REPLACE PROCEDURE Augmenter_Salaire IS
CURSOR cr IS SELECT x.NOM_EMP,x.PRENOM_EMP,y.ROTATION,y.SALAIRE FROM EMPLOYE x, INFIRMIER y WHERE x.NUM_EMP=y.NUM_INF;
c_rec cr%ROWTYPE;
new_sal DECIMAL(8,2);
BEGIN
	FOR c_rec IN cr LOOP
		IF c_rec.ROTATION='NUIT' THEN
			new_sal := c_rec.SALAIRE*160/100;
		ELSE
			new_sal := c_rec.SALAIRE*150/100;
		END IF;
		DBMS_OUTPUT.PUT_LINE('L''infirmier '||c_rec.NOM_EMP||' '||c_rec.PRENOM_EMP||' do rotation '||c_rec.ROTATION||' son ancien salaire est: '||c_rec.SALAIRE||' DA et son nouveau salaire est '||new_sal||' DA.');
		UPDATE INFIRMIER i SET i.SALAIRE=new_sal WHERE i.NUM_INF=c_rec.NUM_INF;
	END LOOP;
END;
/

EXECUTE Augmenter_Salaire;
ALTER TABLE INFIRMIER ENABLE CONSTRAINT Salaire_10k_30k;

-- Question 3 --
CREATE OR REPLACE FUNCTION Verification(salaire DECIMAL) RETURN VARCHAR IS
chaine VARCHAR(30);
BEGIN
	IF salaire<10000 OR salaire>30000 THEN
		chaine := 'Verification Negative';
	ELSE
		chaine := 'Verification Positive';
	END IF;
	RETURN chaine;
END Verification;

SELECT NUM_INF, Verification(SALAIRE) FROM INFIRMIER;

-- Question 4 --
CREATE OR REPLACE FUNCTION Med_Spec(Spec VARCHAR) RETURN NUMBER IS
CURSOR cr IS SELECT * FROM MEDECIN;
c_rec cr%ROWTYPE;
x NUMBER;
BEGIN
	x := 0;
	FOR c_rec IN cr LOOP
		IF c_rec.SPECIALITE = Spec THEN
			x := x + 1;
		END IF;
	END LOOP;
	RETURN x;
END Med_Spec;

SELECT Med_Spec('Orthopediste') FROM DUAL;
SELECT Med_Spec('Traumatologue') FROM DUAL;

-- Question 5 --
CREATE OR REPLACE PROCEDURE Inserer_Emp(NUM INTEGER, NOM VARCHAR, PRENOM VARCHAR, ADRESSE VARCHAR, TEL VARCHAR, CODE VARCHAR, ROT VARCHAR, SAL DECIMAL) IS
CURSOR cr1 IS SELECT COUNT(*) AS TOTAL FROM SERVICE WHERE CODE_SERVICE=CODE;
c_rec1 cr1%ROWTYPE;
CURSOR cr2 IS SELECT COUNT(*) AS TOTAL FROM EMPLOYE WHERE NUM_EMP=NUM;
c_rec2 cr2%ROWTYPE;
CURSOR cr3 IS SELECT COUNT(*) AS TOTAL FROM INFIRMIER WHERE NUM_INF=NUM;
c_rec3 cr3%ROWTYPE;
numb_ser NUMBER;
numb_emp NUMBER;
numb_inf NUMBER;
BEGIN
	numb_ser := 0;
	numb_emp := 0;
	numb_inf := 0;
	FOR c_rec1 IN cr1 LOOP
		numb_ser := c_rec1.TOTAL;
	END LOOP;
	FOR c_rec2 IN cr2 LOOP
		numb_emp := c_rec2.TOTAL;
	END LOOP;
	FOR c_rec3 IN cr3 LOOP
		numb_inf := c_rec3.TOTAL;
	END LOOP;
	IF numb_ser=1 AND numb_emp=0 AND numb_inf=0 THEN
		DBMS_OUTPUT.PUT_LINE('Insertion Avec Success');
	END IF;
	IF numb_ser=0 THEN
		DBMS_OUTPUT.PUT_LINE('Service Inexistant');
	END IF;
	IF numb_emp=1 THEN
		DBMS_OUTPUT.PUT_LINE('Employe Existe deja');
	END IF;
	IF numb_inf=1 THEN
		DBMS_OUTPUT.PUT_LINE('Infirmier Existe deja');
	END IF;
END Inserer_Emp;

Execute Inserer_Emp(195,'nom','prenom','place','055555','XXX','JOUR',10000);










/* 5  procédure qui permet d’ajouter un employé de type infirmier à partir de tous les attributs nécessaires*/
CREATE OR REPLACE PROCEDURE INSERT_EMP(num_emp in integer, nom_emp in VARCHAR, prenom_emp in VARCHAR, adresse_emp in VARCHAR,tel_emp in VARCHAR, code_service in VARCHAR,rotation in VARCHAR ,salaire in integer ) AS

BEGIN
	Erreur1:=0; Erreur2:=0; Erreur3:=1;
	FOR c_rec in cr LOOP 
		IF(c_rec.num_inf=num_emp) THEN
			Erreur1:=1;
		ELSE 
			FOR c_rec1 in cr1 LOOP
				IF(c_rec1.num_emp=num_emp)THEN
					Erreur2:=1;
				ELSE 	
					FOR c_rec2 in cr2 LOOP
						IF(c_rec2.code_service=code_service)THEN
							Erreur3:=0;
						END IF;
					END LOOP;	
				END IF;
			END LOOP;
		END IF;
	END LOOP;
	IF(Erreur1=0 AND Erreur2=0 AND Erreur3=0) THEN
			INSERT INTO employe VALUES(num_emp,nom_emp,prenom_emp,adresse_emp,tel_emp);
			INSERT INTO infirmier VALUES(num_emp,code_service,rotation,salaire);
	END IF;
	IF(Erreur1=1)THEN 
		dbms_output.put_line('l infirmier existe deja');
	END IF;
	IF(Erreur2=1)THEN
		dbms_output.put_line('l employe existe deja');
	END IF;
	IF(Erreur3=1)THEN
		dbms_output.put_line('le service n existe pas');
	END IF;
END INSERT_EMP;

EXECUTE insert_emp(0,'N','z','DELES','05468','CAR','JOUR','50000'); /* insertion sans probleme */
EXECUTE insert_emp(1,'N','z','DELES','05468','CAR','JOUR','50000'); /* l employe existe deja */
EXECUTE insert_emp(2,'N','z','DELES','05468','XXX','JOUR','50000'); /* service n'existe pas */

/* FIN */