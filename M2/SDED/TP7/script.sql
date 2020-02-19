-- Question 1 --
SELECT t.Annee, a.CodeWilaya, tc.LibType, SUM(o.MontantV) AS Total 
    FROM DAgence a, DTemps t, DTypeCompte tc, FOperation o 
    WHERE tc.CodeType = o.CodeTypeCompte AND o.CodeTemps = t.CodeTemps 
    AND o.NumAgence = a.NumAgence GROUP BY (t.Annee, a.CodeWilaya, tc.LibType) 
    ORDER BY t.Annee, a.CodeWilaya, tc.LibType;

-- Question 2 --
SELECT t.Annee, a.CodeWilaya, tc.LibType, SUM(o.MontantV) AS Total 
    FROM DAgence a, DTemps t, DTypeCompte tc, FOperation o 
    WHERE tc.CodeType = o.CodeTypeCompte AND o.CodeTemps = t.CodeTemps 
    AND o.NumAgence = a.NumAgence GROUP BY ROLLUP(t.Annee, a.CodeWilaya, tc.LibType);

-- Question 3 --
SELECT t.Annee, a.CodeWilaya, tc.LibType, SUM(o.MontantV) AS Total 
    FROM DAgence a, DTemps t, DTypeCompte tc, FOperation o 
    WHERE tc.CodeType = o.CodeTypeCompte AND o.CodeTemps = t.CodeTemps 
    AND o.NumAgence = a.NumAgence GROUP BY CUBE(t.Annee, a.CodeWilaya, tc.LibType);

-- Question 4 --
SELECT t.Annee, a.CodeWilaya, tc.LibType, SUM(o.MontantV) AS Total,
    GROUPING(t.Annee) AS tAnnee,
    GROUPING(a.CodeWilaya) AS aCodeWilaya,
    GROUPING(tc.LibType) AS tcLibType
    FROM DAgence a, DTemps t, DTypeCompte tc, FOperation o 
    WHERE tc.CodeType = o.CodeTypeCompte AND o.CodeTemps = t.CodeTemps 
    AND o.NumAgence = a.NumAgence GROUP BY ROLLUP(t.Annee, a.CodeWilaya, tc.LibType);

-- Question 5 --
SELECT t.Annee, a.CodeWilaya, tc.LibType, SUM(o.MontantV) AS Total,
    GROUPING_ID(t.Annee, a.CodeWilaya, tc.LibType) AS groupId
    FROM DAgence a, DTemps t, DTypeCompte tc, FOperation o 
    WHERE tc.CodeType = o.CodeTypeCompte AND o.CodeTemps = t.CodeTemps 
    AND o.NumAgence = a.NumAgence GROUP BY ROLLUP(t.Annee, a.CodeWilaya, tc.LibType);

-- Question 6 --
SELECT t.Annee, a.CodeWilaya, tc.LibType, SUM(o.MontantV) AS Total,
    DECODE(GROUPING(t.Annee), 1, 'Total Annee', t.Annee) AS tAnnee,
    DECODE(GROUPING(a.CodeWilaya), 1, 'Total Wilaya', a.CodeWilaya) AS aCodeWilaya,
    DECODE(GROUPING(tc.LibType), 1, 'Total Type', tc.LibType) AS tcLibType
    FROM DAgence a, DTemps t, DTypeCompte tc, FOperation o 
    WHERE tc.CodeType = o.CodeTypeCompte AND o.CodeTemps = t.CodeTemps 
    AND o.NumAgence = a.NumAgence GROUP BY ROLLUP(t.Annee, a.CodeWilaya, tc.LibType);

-- Question 7 --
SELECT a.CodeBanque, a.CodeWilaya, SUM(o.MontantV) AS Total,
    RANK() OVER (ORDER BY SUM(o.MontantV) DESC) AS Classement,
    DENSE_RANK() OVER (ORDER BY SUM(o.MontantV) DESC) AS Classement_Dense
    FROM DAgence a, FOperation o WHERE a.NumAgence = o.NumAgence
    GROUP BY (a.CodeBanque, a.CodeWilaya);

-- Question 8 --
SELECT t.Annee, a.CodeBanque, SUM(o.NbOperationsR+o.NbOperationsV) AS NbrOp,
    CUME_DIST() OVER (PARTITION BY t.Annee ORDER BY t.Annee, a.CodeBanque)
    AS TotalCumul FROM FOperation o, DAgence a, DTemps t 
    WHERE a.NumAgence = o.NumAgence AND t.CodeTemps = o.CodeTemps
    GROUP BY (t.Annee, a.CodeBanque);

-- Question 9 --
SELECT t.Mois, SUM(o.NbOperationsR+o.NbOperationsV) AS NbrOp,
    NTILE(4) OVER(ORDER BY SUM(o.NbOperationsR+o.NbOperationsV)) AS Ntile
    FROM DTemps t, FOperation o WHERE t.CodeTemps = o.CodeTemps 
    GROUP BY t.Mois ORDER BY t.Mois;

-- Question 10 --
SELECT a.CodeBanque, t.Annee, SUM(o.MontantV) AS MontantV,
    RATIO_TO_REPORT(SUM(o.MontantV)) OVER (PARTITION BY a.CodeBanque) AS Ratio
    FROM DAgence a, DTemps t, FOperation o
    WHERE t.CodeTemps = o.CodeTemps AND a.NumAgence = o.NumAgence
    GROUP BY (a.CodeBanque, t.Annee) ORDER BY a.CodeBanque, t.Annee;

-- Question 11 --
SELECT CodeB, NumA, MaxOp FROM (
    SELECT a.CodeBanque AS CodeB, a.NumAgence AS NumA, SUM(o.NbOperationsR+o.NbOperationsV) AS NbOpr,
    MAX(SUM(o.NbOperationsR+o.NbOperationsV)) OVER (PARTITION BY a.CodeBanque) AS MaxOp
    FROM DAgence a, FOperation o WHERE a.NumAgence = o.NumAgence
    GROUP BY a.CodeBanque, a.NumAgence
) WHERE MaxOp = NbOpr;
