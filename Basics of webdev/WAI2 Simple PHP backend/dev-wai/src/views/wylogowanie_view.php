<!DOCTYPE html>
<html>
	<head>
		<title>Wylogowywanie</title>
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
			<h1>Wylogowywanie</h1>
		</header>
		<div id="container">
			<?php include '../views/sub_views/nav.php'?>
			<form action="/p_wyl" method="post">
				Czy napewno chcesz aby cię wylogowano?<br/>
				<input type="submit" value="Wyloguj"/>
			</form>
		</div>
	</body>
</html>