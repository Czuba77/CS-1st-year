<!DOCTYPE html>
<html>
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
	<body>
		<header>
			<h1>Logowanie</h1>
		</header>
		<div id="container">
			<?php include '../views/sub_views/nav.php'?>
			<form action="/p_log" method="post">
				Podaj login <br/>
				<input type="text" name="login"/>
				<br/>
				Podaj hasło <br/>
				<input type="password" name="pass"/>
				<br/>
				<input type="submit" value="Zaloguj"/>
				<br/>
			</form>
		</div>
	</body>
</html>