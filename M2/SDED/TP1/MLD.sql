Banque("CodeBanque", NomBanque)
Wilaya("CodeWilaya", NomWilaya)
Ville("CodeVille", NomVille, /*CodeWilaya*/)
Agence("NumAgence", NomAgence, TelAgence, /*CodeBanque*/, /*CodeVille*/)
Client("NumClient", NomClient, AdrClient, TelClient, DNClient)
Type_Compte("CodeType", LibType)
Compte("NumCompte", DateOuverture, /*NumClient*/, /*NumAgence*/, /*CodeType*/)
Operation("CodeOp", DateOp, HeurOp, TypeOp, Montant, /*NumCompteVersement*/, /*NumCompteRetrait*/)
