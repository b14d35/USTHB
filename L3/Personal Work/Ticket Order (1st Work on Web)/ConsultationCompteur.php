<!DOCTYPE html>
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=utf-8">
	<title>Consulter le compteur globale</title>
</head>
<body>
<?php 
include("index.php");
$temp = array('--','--','--','--','--');
$temp=calculerCompteur($temp);
$var = array(array("Guichet N°1",$temp[0]),array("Guichet N°2",$temp[1]),array("Guichet N°3",$temp[2]),array("Guichet N°4",$temp[3]),array("Guichet N°5",$temp[4]));

?>

<div id="contenue">

	<p> Numéro Compteur global: <input type="text"  name="numcompteur" disabled  value = <?php echo numGlobal();?>/>
  	</p> <br/>
	<table   
         cellspacing=\"0\" cellpadding=\"3\">
		 <tr>
		 <th scope=\"col\">Numéro Guichet </th>
		 <th scope=\"col\">Numéro ticket en appel</th>  
         </tr>

         <?php
         	for($i=0;$i<5;$i++){
         		echo"<tr> <td scope=\"col\">".$var[$i][0] ."</td>  <td scope=\"col\">   ".$var[$i][1] ."</td>  </tr>";
         	}  ?>      		
    </table>
 	<input type="submit" id="refresh" value="refraichir" onclick= 'window.location.reload(false)'/>

</div>


<style>

	table {
		border: medium solid #6495ed;
		border-collapse: collapse;
		width: 50%;
		}

	th {
		font-family: monospace;
		border: thin solid #6495ed;
		width: 50%;
		padding: 5px;
		background-color: #D0E3FA;
		}

	td {
		font-family: sans-serif;
		border: thin solid #6495ed;
		width: 50%;
		padding: 5px;
		text-align: center;
		background-color: #ffffff;
		}
	caption {
		font-family: sans-serif;
	}

	th{
		width:300px; height:50px;
	    }

	#refresh {
		width:100px; 
		position : absolute ;
	 	top : 105% ;
	  	margin-left : 17% ;
		}

</style>

</body>
</html>