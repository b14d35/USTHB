<?php 
include("BD.php");
include ('myFunctions.php');
?>
<!DOCTYPE html>
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=utf-8">
<title>Page Principale</title>
</head>

<body>
	</p>
	<div id="menu">
  	  <ul id="onglets">
    	<li><a href="ConsultationCompteur.php"> <button value="Consulter" > <img id='op' src="img/consulter.png" >  </button></a>	</li>
	    <li><a href="AjouterClient.php"> 		<button value="Demande Ticket" > <img  id='op'  src="img/ajoutClient.png" >  </button></a>  </li>
	    <li><a href="AccesGuichetier.php">		<button value="Guichetier" > <img  id='op'  src="img/guichetier.jpg" >  </button></a>  </li>
    	<li><a href="Stats.php"> 		<button value="Stat" > <img id='op'  src="img/statistiques.png" > </button></a>  </li>
 	  </ul>
	</div>



<style >
	body
		{    margin:22px auto; 
    	background-image: url("img/fond.jpg");
		}

	#onglets li 
		{   float : 250px  ;
   		font : bold 12px serif;
    	list-style-type : none;
    	padding-bottom : 50px; 
    	margin-left : 0;
		}

	#contenue {
		position : absolute ;
		top : 30% ;
	    margin-left : 40% ;
		}
#op{
width:100px;
height:100px; 


}

</style>

</body>
</html> 