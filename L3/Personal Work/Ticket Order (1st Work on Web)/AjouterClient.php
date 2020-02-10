<!DOCTYPE html >
<html >
<head>
<meta http-equiv="Content-Type" content="text/html; charset=utf-8">
<title>Demande Ticket</title>
</head>
<body>
	<?php  include("index.php");?>


		<div id="contenue">
			 <div ><h3> <b> Ticket Client </b> </h3>
  					</br>

					<?php 
					
  if ( isset($_POST['valid']) && !empty($_POST["nomC"]) && !empty($_POST["prenC"]) && !empty($_POST["add"]))
   { 
	ajoutClient($_POST["nomC"],$_POST["prenC"],$_POST["add"],$_POST["nccp"],$_POST["op"]);
	$tic=numGlobal()+1;
	if($tic==1) resetencours();
	ajoutTicket($tic);
	$avant=last();

?>
  
 <form method="post" name="client" action="index.php">
 <p>      <label>Date du ticket:</label>  <input type="text" name="dt" disabled value="<?php echo todayDate() ?>"></br>
    	  <label>Votre numéro de ticket : </label> <input type="text" disabled value="<?php echo $tic ?>" name="numT"></br>
	      <label>Le numéro actuel: </label>   <input type="text" name="num" disabled value="<?php echo $avant ?>"></br>
	      <label>Nombre du client avant votre tour:</label> <input type="text" name="numtour" disabled value="<?php echo (int)$tic-$avant-1 ?>"> </br>
          <label>Temps estimé pour avoir votre tour: </label><input type="text" name="tps" disabled value=" <?php echo ((int)$tic-$avant-1)*3 ?>"> min </br>
	     <input type="submit" id='bt2'   value="OK">
	    </form> </div>
  <?php }else{
 

?>
 <p> Tapez les informations ci-dessous pour vous identifier :
  <br/>
 <form name="client" method="post" action="AjouterClient.php">
 <p>   <label>   Nom: </label><input type="text" name="nomC">*
    <label>  Prénom : </label> <input type="text" name="prenC">*</br>
	<label>  Adresse: </label> <input type="text" name="add">*</br>
	 <label> N° CCP : </label> <input type="password" name="nccp"></br>
	 <label> Type d'opération à demander :</label> <SELECT name="op" size="1">
<OPTION>Demande d'avoir
<OPTION>Retrait
<OPTION selected>Versement
<OPTION>Relevé des opérations
</SELECT></p> 
 </br><input type="submit" name='valid' id="bt1" value="Valider"> <input type="reset" id="bt2" value="Annuler"> 
</form> </div>
<?php }   ?>

<style >
	label
{
	display: block;
	width:55%;
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
	



</style>
</body>
</html>
