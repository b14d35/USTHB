<?php
    $bd= mysqli_connect("localhost","root","usbw","projet");
	if(! $bd) die("echec de la connexion ");
    $GLOBALS['$bd']=$bd;
?>