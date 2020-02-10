<?php
	date_default_timezone_set('UTC');

	function todayDate(){
		return date('Y-m-d');
	}

	function numGlobal(){
		$dat=todayDate();
		$result=mysqli_query($GLOBALS['$bd'],"select count(*) from ticket where dateT='$dat'");
		$row=mysqli_fetch_row($result);
		return $row[0];
	}

	function ajoutClient($nom,$prenom,$add,$ccp,$type){
		$result=mysqli_query($GLOBALS['$bd'],"INSERT INTO client VALUES (null,'$nom','$prenom','$add','$ccp','$type')");
	}

	function lastClient(){
		$result=mysqli_query($GLOBALS['$bd'],"select max(idC) from client");
		$row=mysqli_fetch_row($result);
		return $row[0];
	}

	function ajoutTicket($tic){
		$dat=todayDate();
		$id=lastClient();
		$result=mysqli_query($GLOBALS['$bd'],"INSERT INTO ticket VALUES ('$tic','$dat','$id')");
	}

	function nextClient(){
		$dat=todayDate();
		$result=mysqli_query($GLOBALS['$bd'],"SELECT idT from ticket where idC = (select max(idC) from travail where dateT='$dat')");
		$row=mysqli_fetch_row($result);
		return (int)$row[0]+1;
	}

	function numClient($nt){
		$dat=todayDate();
		$result=mysqli_query($GLOBALS['$bd'],"SELECT idC from ticket where idT='$nt' AND dateT='$dat'");
		$row=mysqli_fetch_row($result);
		return (int)$row[0];	
	}

	function ajoutTravail($idG,$ng,$nc){
		$dat=todayDate();
		$result=mysqli_query($GLOBALS['$bd'],"INSERT INTO travail VALUES ('$idG','$ng','$dat','$nc')");
	}

	function numTicket($nc){
		$dat=todayDate();
		$result=mysqli_query($GLOBALS['$bd'],"SELECT idT from ticket where idC='$nc' AND dateT='$dat'");
		$row=mysqli_fetch_row($result);
		return $row[0];	
	}

	function maintenant($ng,$nt){
		$result=mysqli_query($GLOBALS['$bd'],"UPDATE encours set nt='$nt' where ng='$ng'");
	}

	function resetencours(){
		$result=mysqli_query($GLOBALS['$bd'],"UPDATE encours set nt=0");
	}

	function calculerCompteur(){
		$arr=array('--','--','--','--','--');
		$dat=todayDate();
		for($i=0;$i<5;$i++){
			$j=$i+1;
			$result=mysqli_query($GLOBALS['$bd'],"SELECT nt from encours where ng='$j'");
			$row=mysqli_fetch_row($result);
			if($row[0]>0)$arr[$i]=(int)numTicket($row[0]);
		}
		return $arr;
	}

	function numActuel(){
		$result=mysqli_query($GLOBALS['$bd'],"SELECT max(nt) from encours");
		$row=mysqli_fetch_row($result);
		return $row[0];
	}
	function last(){
		$dat=todayDate();
		$result=mysqli_query($GLOBALS['$bd'],"SELECT count(*) from travail where dateF='$dat'");
		$row=mysqli_fetch_row($result);
		return $row[0];
	}
	function stats(){
		$arr=array(array(0,0,0,0),array(0,0,0,0),array(0,0,0,0),array(0,0,0,0),array(0,0,0,0));
		$dat=todayDate();
		for($i=0;$i<5;$i++){
			$j=$i+1;
			$result=mysqli_query($GLOBALS['$bd'],"SELECT count(*) from client c where typeOp='Demande d\'avoir' AND c.idC IN
			 (select idC from travail where ng='$j' AND dateF='$dat')");
			$row=mysqli_fetch_row($result);
			$arr[$i][0]=(int)$row[0];
			$result=mysqli_query($GLOBALS['$bd'],"SELECT count(*) from client c where typeOp='Retrait' AND c.idC IN
			 (select idC from travail where ng='$j' AND dateF='$dat')");
			$row=mysqli_fetch_row($result);
			$arr[$i][1]=(int)$row[0];
			$result=mysqli_query($GLOBALS['$bd'],"SELECT count(*) from client c where typeOp='Versement' AND c.idC IN
			 (select idC from travail where ng='$j' AND dateF='$dat')");
			$row=mysqli_fetch_row($result);
			$arr[$i][2]=(int)$row[0];
			$result=mysqli_query($GLOBALS['$bd'],"SELECT count(*) from client c where typeOp='Relevé des opérations' AND c.idC IN
			 (select idC from travail where ng='$j' AND dateF='$dat')");
			$row=mysqli_fetch_row($result);
			$arr[$i][3]=(int)$row[0];
		}
		return $arr;
	}

?>