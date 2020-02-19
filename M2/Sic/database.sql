create table offre_prof (
	id number primary key,
	resume varchar2(200),
	sujet varchar2(1000),
	propose varchar2(12),
	constraint fk_prof foreign key (propose) references prof(id_prof)
);

create table offre_externe (
	id number primary key,
	resume varchar2(200),
	sujet varchar2(1000),
	propose varchar2(12),
	constraint fk_externe foreign key (propose) references externe(id_ext)
);

create table offre_etudiant (
	id number primary key,
	resume varchar2(200),
	sujet varchar2(1000),
	propose varchar2(12),
	constraint fk_etudiant foreign key (propose) references student(matricule)
);

create table fiche(
	-- Les informations ?
);

create table prof(
	id_prof varchar2(12) primary key,
	nom varchar2(30),
	prenom varchar2(30),
	grade varchar2(20)
);

create table student(
	matricule varchar2(12) primary key,
	nom varchar2(30),
	prenom varchar2(30),
	spec varchar2(3),
	niveau varchar2(2)
);

create table externe(
	id_ext varchar2(12) primary key,
	nom varchar2(30),
	prenom varchar2(30),
	entreprise varchar2(50)
);