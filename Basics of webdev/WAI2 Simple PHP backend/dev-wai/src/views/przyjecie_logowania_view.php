<!DOCTYPE html>
<html>
	<head>
		<head>
		<title>Logowanie</title>
		<link rel="stylesheet" href="static/css/styles.css"/>
		<meta charset="UTF-8">
		<style>
			@font-face {
				font-family: "Ubuntu";
				src: url("static/czcionki/Ubuntu-Regular.ttf") format("truetype");
			}
		</style>
	</head>
	</head>
	<body>
		<header>
			<h1>Logowanie</h1>
		</header>
		<div id="container">
			<?php include '../views/sub_views/nav.php'?>
			<?php
				echo $przyjecie_logowania['msg'];
				if($przyjecie_logowania['czyudane']==false){?>
					<a href="/logowanie" >Spróbuj się zalogować ponownie</a> 
				<?php
				}
			?>
		</div>
	</body>
</html>
