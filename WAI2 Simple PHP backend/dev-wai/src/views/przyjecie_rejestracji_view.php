<!DOCTYPE html>
<html>
	<head>
		<title>Rejestracja</title>
		<link rel="stylesheet" href="static/css/styles.css"/>
		<meta charset="UTF-8">
		<style>
			@font-face {
				font-family: "Ubuntu";
				src: url("static/czcionki/Ubuntu-Regular.ttf") format("truetype");
			}
		</style>
	</head>
	<body>
		<header>
			<h1>Rejestracja</h1>
		</header>
		<div id="container">
			<?php include '../views/sub_views/nav.php'?>
			 <?php
				echo $przyjecie_rejestracji['wiad'];
			?>
		</div>
	</body>
</html>

