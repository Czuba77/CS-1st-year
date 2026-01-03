<!DOCTYPE html>
<html>
	<head>
		<title>Dodaj zdjęcie</title>
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
			<h1>Dodaj zdjęcie</h1>
		</header>
		<div id="container">
			<?php include '../views/sub_views/nav.php'?>
			<form action="/przesylanie_zdjec" method="post" enctype="multipart/form-data"/>
				Wybierz zdjęcie do wysłania: <br/>
				<input type="file" name="fileToUpload" id="fileToUpload" required />
				<br/> Podaj znak wodny: <br/>
				<input type="text" name="znakWodny" required />
				<br/> Podaj tytuł: <br/>
				<input type="text" name="tytul"/>
				<br/> Podaj autora: <br/>
				<input type="text" name="autor"/>
				<br/>
				<input type="submit" value="Prześlij zdjęcie" name="formularz_view"/>
			</form>
		</div>
	</body>
</html>