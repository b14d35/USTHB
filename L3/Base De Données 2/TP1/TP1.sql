create user b14d35 identified by system;
grant all privileges to b14d35;
connect b14d35
	/* enter password 'system'*/
create table Competetion(Ncomp NUMBER(3) primary key,
	NomComp varchar2(40), DateComp date, PrixComp NUMBER(7)
);
create table Bateau(Nbat NUMBER(3) primary key,
	NomBat varchar2(40), Sponsor varchar2(20)
);
create table Courses(Nbat NUMBER(3), Ncomp NUMBER(3), Score NUMBER(1),
	constraint PK2 primary key (Nbat,Ncomp),
	constraint FK foreign key (Nbat) references Bateau(Nbat),
	constraint FK2 foreign key (Ncomp) references Competetion(Ncomp)
);
create table Participants(
	NPart NUMBER(3) primary key, NomPart varchar2(10), Nbat NUMBER(3),
	constraint FK3 foreign key (Nbat) references Bateau(Nbat)
);
insert into Competetion values(200,'Le grand tour','21-03-2000',1000000);
insert into Competetion values(210,'course de la liberté','05-05-2004',1000000);
insert into Competetion values(215,'Le grand tour','20-03-2005',1000000);
insert into Competetion values(220,'Trophée barberousse','01-08-2005',1500000);
insert into Competetion values(240,'Course de la liberté','10-05-2007',1500000);
insert into Competetion values(260,'Trophée barberousse','01-08-2009',2000000);
insert into Competetion values(265,'Le grand tour','21-03-2010',2000000);
insert into Competetion values(270,'Course de la liberté','08-05-2010',1800000);
insert into Bateau values(102,'Tassili','Djezzy');
insert into Bateau values(103,'El bahdja','BNA');
insert into Bateau values(104,'La colombe','Condor');
insert into Bateau values(105,'Hoggar','BNA');
insert into Courses values(102,210,2);
insert into Courses values(102,240,1);
insert into Courses values(102,270,4);
insert into Courses values(103,210,4);
insert into Courses values(103,215,3);
insert into Courses values(104,210,1);
insert into Courses values(104,215,2);
insert into Courses values(104,220,4);
insert into Courses values(104,240,3);
insert into Courses values(104,260,5);
insert into Courses values(104,265,1);
insert into Courses values(104,270,3);
insert into Courses values(105,210,3);
insert into Courses values(105,215,1);
insert into Participants values(320,'Mohammed',104);
insert into Participants values(470,'Ali',103);
insert into Participants values(601,'Omar',102);
insert into Participants values(720,'Mustafa',105);

delete from Bateau where NomBat='Tassili';
delete from Participants where Nbat =
(Select Nbat from Bateau where NomBat='Tassili');
delete from courses where Nbat =
(Select Nbat from Bateau where NomBat='Tassili');
delete from Bateau where NomBat='Tassili';

alter table Bateau add (nbr NUMBER(3));

update Bateau x set nbr=
(select count(*) from Courses y where x.Nbat=y.Nbat);
	
create unique index x1 on Bateau(Nbat);
create index x2 on Bateau(NomBat);

drop table Bateau;
alter table Courses drop constraint FK;
alter table Participants drop constraint FK3;
drop table Bateau;

create table Bateau(Nbat NUMBER(3) primary key,
	NomBat varchar2(40), Sponsor varchar2(20)
);
insert into Bateau values(102,'Tassili','Djezzy');
insert into Bateau values(103,'El bahdja','BNA');
insert into Bateau values(104,'La colombe','Condor');
insert into Bateau values(105,'Hoggar','BNA');

alter table Courses add (constraint FK foreign key
(Nbat) references Bateau(Nbat));
alter table Participants add (constraint FK3 foreign key
 (Nbat) references Bateau(Nbat));

desc user_tables;
desc user_tab_columns;
desc user_constraints;
desc user_indexes;