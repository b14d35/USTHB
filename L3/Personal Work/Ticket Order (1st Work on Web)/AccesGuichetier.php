<?php
    session_start();
?>
<!DOCTYPE html >
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=utf-8">
<title>Acces Guichetier</title>
</head>

 
 
</body>
<?php include('index.php');?>


<div id='contenue'><h3> <b> Accès Guichet </b> </h3>
	<?php 
	$count=0;
	if(isset($_POST['valid']) && !empty($_POST["nomprenC"]) && isset($_POST['numg'])){
		$np = mysqli_real_escape_string($GLOBALS['$bd'],$_POST['nomprenC']);
		$result=mysqli_query($GLOBALS['$bd'],"SELECT idG from guichetier where nompreG='$np'");
		$count=mysqli_num_rows($result);
		$row=mysqli_fetch_row($result);
		$_SESSION['guichet']=substr($_POST['numg'],11);
		$_SESSION['idG']=$row[0];
	}
	if( (isset($_GET['nvclient'])) || $count==1){ 
		$cl='--';
		if(isset($_GET['nvclient'])){
			if(nextClient()<=numGlobal()){
				$cl=nextClient();
				$nc=numClient($cl);
				ajoutTravail($_SESSION['idG'],$_SESSION['guichet'],$nc);
			}
			maintenant($_SESSION['guichet'],numClient($cl));
		}
?>

 <form method="get" name="guichet" action="AccesGuichetier.php">
 <p><label> N° Guichet:</label> <input type="text" disabled value="<?php echo $_SESSION['guichet']?>" >   <br/>
    <label> Numéro de ticket en appel (chez le guichet) :</label> <br/><input type="text" disabled value="<?php echo $cl ?>" ><br/><br/>
    <label> Numéro Global actuel:</label> <input type="text" disabled value="<?php echo numGlobal() ?>"><br/>
 </br><input type="submit" id='bt3' name="nvclient" value="Appeler un nouveau client"/>    </p>

</form>
<?php 
	}else{
	?>
 <p> Tapez les informations ci-dessous pour vous identifier :
  </br>
 <form method="post" name="guichet" action="AccesGuichetier.php">
 <p><label> N Guichet:</label>   <SELECT name="numg" size="1">
<OPTION selected="selected">Guichet N°1
<OPTION>Guichet N°2
<OPTION>Guichet N°3
<OPTION>Guichet N°4
<OPTION>Guichet N°5
</SELECT> * </br>
    <label> Nom et Prénom :</label> <input type="text" name="nomprenC">*</br>
 </br><input type="submit" id='bt1' name="valid" value="Valider"/> <input id ='bt2'  type="reset" value="Annuler"/>   </p>

</form> <?php } ?> </div>


<style>

	label
{
	display: block;
	width:200px;
	float: left;
	
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
#bt3{
	width:250px; 
		position : absolute ;
	 	top : 97% ;
	  	margin-left : 15% ;
}
</style>
</body>
</html>
