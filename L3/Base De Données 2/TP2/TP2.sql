---------------1-----------------
create view ListeBateau as (select nbat,nombat from Bateau);
select * from ListeBateau;
---------------2-----------------
insert into Bateau values(106,'SIRTA','CEVITAL');
select * from ListeBateau;
---------------3-----------------
create view ListeNomsBateau as (select nombat from Bateau);
select * from ListeNomsBateau;
---------------4-----------------
create view CompBateau(Ncomp,NbBat) as
	(select Ncomp, count(Nbat) from Courses
	group by Ncomp);
select * from CompBateau;
--------------5------------------
insert into Courses values(102,220,3);
insert into Courses values(102,265,2);
select * from CompBateau;
--------------6------------------
select NomComp from Competetion x, CompBateau y 
	where x.Ncomp=y.Ncomp and y.NbBat = (select min(Nbbat)
	from CompBateau);
--------------7------------------
select Ncomp from CompBateau where NbBat = (
	select count(*) from Bateau);
--------------8------------------
insert into ListeBateau values(107,'TOUAREG');
select * from ListeBateau;
select * from Bateau;
--------------9------------------
update ListeBateau set NomBat='TOUAR' where NBat=107;
select * from ListeBateau;
delete from ListeBateau where NBat=107;
select * from ListeBateau;
--------------10-----------------
insert into ListeNomsBateau values('ILLUSION');
--------------11-----------------
create table Courses2(Nbat NUMBER(3), 
Ncomp NUMBER(3),Score NUMBER(1),
constraint FKK foreign key (Nbat) references Bateau(Nbat),
constraint FKK2 foreign key (Ncomp) references Competetion(Ncomp)
);
--------------12-----------------
insert into Courses2 select * from Courses;
--------------13-----------------
create view VBateau as select Nbat from
	Courses2 group by nbat;
select * from VBateau;
--------------14-----------------
insert into VBateau values(103);
insert into VBateau values(109);
select * from VBateau;
--------------15-----------------
create or replace view VBateau as select nbat,
	count(*) from courses2 group by nbat;
create or replace view VBateau(nbat , nbr) as select
	nbat , count(*) from COURSES2 group by nbat;
select * from VBateau;
--------------16-----------------
insert into VBateau values(108,3);
--------------17-----------------
insert into CompBateau values(103,2);
--------------18-----------------
create view jointure as select c.Nbat,NomBat
	from Courses c, Bateau b where c.NBat=b.NBat;
select * from jointure;
insert into jointure(NomBat,Nbat) values(101,"Test");
--------------19-----------------
create NO FORCE view VNoForce as select Nbat,NomP
	from Bateau x, Proprietaire y where x.NBat=y.NBat;
--------------20-----------------
create FORCE view VForce as select  Nbat,nomP from
	Bateau x, Proprietaire y where x.NBat=y.NBat;
--------------21-----------------
create or replace view ListeBateau(Nbat,NomBat) as
	select Nbat,NomBat from Bateau with read only;
--------------22-----------------
insert into ListeBateau values (108,'Touareg2');
--------------23-----------------
create view Comp_Apres2006(Ncomp,Nomcomp,Datcomp) as
	select Ncomp,NomComp,DateComp from Competetion x
	where x.DateComp> '31-12-2006';
select * from Comp_Apres2006;
--------------24-----------------
insert into Comp_Apres2006 values
	(211,'Le Grand Tour','20-03-2003');
select * from Comp_Apres2006;
select * from Competetion;
--------------25-----------------
create or replace view Comp_Apres2006(Ncomp,Nomcomp,Datcomp) as
	select Ncomp,NomComp,DateComp from Competetion x
	where x.DateComp> '31-12-2006' with check option;
select * from Comp_Apres2006;
--------------26-----------------
insert into Comp_Apres2006 values
	(212,'Le Grand Tour','20-03-2004');
select * from Comp_Apres2006;
select * from Competetion;