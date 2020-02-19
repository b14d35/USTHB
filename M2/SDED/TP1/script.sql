CREATE USER Master IDENTIFIED BY pwd DEFAULT TABLESPACE system QUOTA UNLIMITED ON system;
GRANT ALL PRIVILEGES TO Master;

CREATE TABLE Banque(
    CodeBanque NUMBER(10),
    NomBanque VARCHAR2(10),
    CONSTRAINT pk_Banque PRIMARY KEY (CodeBanque)
);

CREATE TABLE Wilaya(
    CodeWilaya NUMBER(2),
    NomWilaya VARCHAR2(10),
    CONSTRAINT pk_Wilaya PRIMARY KEY (CodeWilaya)
);

CREATE TABLE Ville(
    CodeVille NUMBER(10),
    NomVille VARCHAR2(10),
    CodeWilaya NUMBER(2),
    CONSTRAINT pk_Ville PRIMARY KEY (CodeVille),
    CONSTRAINT fk_Wilaya FOREIGN KEY (CodeWilaya) REFERENCES Wilaya(CodeWilaya)
);

CREATE TABLE Agence(
    NumAgence NUMBER(10),
    NomAgence VARCHAR2(10),
    TelAgence VARCHAR2(10),
    CodeBanque NUMBER(10),
    CodeVille NUMBER(10),
    CONSTRAINT pk_Agence PRIMARY KEY (NumAgence),
    CONSTRAINT fk_Banque FOREIGN KEY (CodeBanque) REFERENCES Banque(CodeBanque),
    CONSTRAINT fk_Ville FOREIGN KEY (CodeVille) REFERENCES Ville(CodeVille)
);

CREATE TABLE Client(
    NumClient NUMBER(10),
    NomClient VARCHAR2(10),
    AdrClient VARCHAR2(10),
    TelClient VARCHAR2(10),
    DNClient DATE,
    CONSTRAINT pk_Client PRIMARY KEY (NumClient)
);

CREATE TABLE Type_Compte(
    CodeType NUMBER(2),
    LibType VARCHAR2(10),
    CONSTRAINT pk_Type PRIMARY KEY (CodeType)
);

CREATE TABLE Compte(
    NumCompte NUMBER(10),
    DateOuverture DATE,
    NumClient NUMBER(10),
    NumAgence NUMBER(10),
    CodeType NUMBER(2),
    CONSTRAINT pk_Compte PRIMARY KEY (NumCompte),
    CONSTRAINT fk_Client FOREIGN KEY (NumClient) REFERENCES Client(NumClient),
    CONSTRAINT fk_Agence FOREIGN KEY (NumAgence) REFERENCES Agence(NumAgence),
    CONSTRAINT fk_Type FOREIGN KEY (CodeType) REFERENCES Type_Compte(CodeType)
);

CREATE TABLE Operation(
    CodeOp NUMBER(10),
    DateOp Date,
    HeurOp NUMBER(2),
    TypeOp VARCHAR2(10),
    Montant NUMBER,
    NumCompteVersement NUMBER(10),
    NumCompteRetrait NUMBER(10),
    CONSTRAINT pk_Operation PRIMARY KEY (CodeOp),
    CONSTRAINT fk_CompteVersement FOREIGN KEY (NumCompteVersement) REFERENCES Compte(NumCompte),
    CONSTRAINT fk_CompteRetrait FOREIGN KEY (NumCompteRetrait) REFERENCES Compte(NumCompte)
);
