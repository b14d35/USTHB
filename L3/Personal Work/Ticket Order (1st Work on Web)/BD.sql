create table `client` (
	idC int(11) primary key AUTO_INCREMENT,
	nomC VARCHAR(20) NOT NULL,
	prenomC VARCHAR(20) NOT NULL,
	adr VARCHAR(20) NOT NULL,
	nccp int(11),
	typeOp VARCHAR(12)
);

create table `encours` (
	ng int(1) primary key,
	nt int(5) NOT NULL
);
INSERT INTO `encours` (`ng`, `nt`) VALUES
 ('1', '0'), ('2', '0'),('3', '0'), ('4', '0'),
 ('5', '0');

create table `guichetier` (
	idG int(11) primary key AUTO_INCREMENT,
	nompreG VARCHAR(40) NOT NULL
);
INSERT INTO `guichetier` (`idG`, `nompreG`) 
VALUES ('1', 'HAMINOUMNA AMINA'),('2', 'HAMINOUMNA'),
('3', 'AMINA'),('4', 'HAMI'),
('5', 'MINA'),('6', 'MINAHAMI');

create table `receveur` (
	idR int(11) primary key,
	nompreR VARCHAR(40) NOT NULL,
	pass VARCHAR(20) NOT NULL
);
INSERT INTO `receveur` (`idR`, `nompreR`, `pass`) VALUES
 ('1', 'test1', 'test1'), ('2', 'test2', 'test2'),
 ('3', 'test3', 'test"'), ('4', 'test4', 'test4'),
 ('5', 'test5', 'test5'), ('6', 'test6', 'test6');

create table `ticket` (
	idT int(5) ,
	dateT date ,
	idC int(11),
    constraint primary key (idT,dateT)
);

create table `travail` (
	idG int(11),
	ng int(1),
	dateF date,
	idC int(10),
	constraint primary key (idG,idC)
);