<!DOCTYPE html>
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=utf-8">
<title>Statistiques</title>
</head>

<body>
<?php include ('index.php');
	$login=0;
	if(isset($_POST['valid2'] ) && !empty($_POST["nomprenom"]) && !empty($_POST["pw"])){

		$npt = mysqli_real_escape_string($GLOBALS['$bd'],$_POST['nomprenom']);
		$ppt = mysqli_real_escape_string($GLOBALS['$bd'],$_POST['pw']);
		$result=mysqli_query($GLOBALS['$bd'],"SELECT idR from receveur where nompreR='$npt' AND pass='$ppt'");
		$login=mysqli_num_rows($result);
	}
    if (isset($_GET['ref']) || $login==1)
    { 
	

?> 
   <div id='contenue'><h3> <b> Statistiques</b> </h3>
   <form method='get' action="Stats.php" >
 <input type="submit" id='btref' name='ref' value="Rafraichir">
</form>
    <table  border="4" cellpadding="2" cellspacing="4"> 
   <tr> <td> N° Guichet </td>
        <td> Type opération </td>
		<td> Nombre de tickets traités </td>  
      </tr>	
		<?php
			$arr=stats();
			for ($i=0;$i<=4;$i++){
				$j=$i+1;
				echo '<tr><td rowspan="4"> Guichet N°'.$j.' </td>';
				echo '<td><input disabled type="text" value="Demande d\'avoir" name="numt"/>  </td> <td> <input disabled value=" '.$arr[$i][0].'"type="text" name="numt"/></td>	</tr> ';
				echo  '<tr> <td><input disabled value="Retrait"  type="text" name="numt"/> </td> <td> <input disabled value="'.$arr[$i][1].'" type="text" name="numt"/></td>	</tr> ';
				echo  '<tr> <td><input disabled value="Versement"  type="text" name="numt"/> </td> <td> <input disabled value="'.$arr[$i][2].'" type="text" name="numt"/></td>	</tr> ';
				echo  '<tr> <td><input disabled value="Relevé des opérations"  type="text" name="numt"/> </td> <td> <input disabled value="'.$arr[$i][3].'" type="text" name="numt"/></td>	</tr> ';
			}
				echo '</table>';
?>
 
		   
   
<?php 
}else{

  ?>	
  <div id='contenue'><h3> <b> Accès Receveur des PTT</b> </h3>
  <p> Tapez les informations ci-dessous pour vous identifier :
  </br>
 <form method="post" name="receveur" action="Stats.php">
 <p> <label>Nom & Prénom: </label>  <input type="text" name="nomprenom">*</br>
  <label>Mot de passe: </label>  <input type="password" name="pw">* </br></p>
   <input type="submit" name="valid2" id='bt1' value="Valider"> <input id='bt2' type="reset" value="Annuler"/> 
</form> 
	<?php	}
		?>
   </div> 
  <style >

  label{
	display: block;
	width:40%;
	float: left;
  }
  	table{
width:100px; 
		position : absolute ;
	 	top : 97% ;
	  	margin-left : -200% ;


  	}

#btref{
	width:100px; 
		position : absolute ;
	 	top : -50% ;
	  	margin-left: -30%;
}

#bt1{
	width:100px; 
		position : absolute ;
	 	top : 97% ;
	  	margin-left : 12% ;
}
#bt2{
	width:100px; 
		position : absolute ;
	 	top : 97% ;
	  	margin-left : 57% ;
}

  </style>
</body>
</html>