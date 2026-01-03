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
			<form action="/p_rej" method="post">
				Podaj login <br/>
				<input type="text" name="login" required />
				<br/>
				Podaj e-mail <br/>
				<input type="text" name="email" required />
				<br/>
				Podaj hasło <br/>
				<input type="password" name="pass" required />
				<br/>
				Powtórz hasło <br/>		
				<input type="password" name="repeat_pass" required />
				<br/>
				<br/>
				<input type="submit" value="Dołącz do kinomaniaków"/>
			</form>
		</div>
	</body>
</html>