<!DOCTYPE html>
<html>
	<head>
			<title>Usuwanie</title>
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
				<h1>Usuwanie</h1>
		</header>
		<div id="container">
			<?php include '../views/sub_views/nav.php'?>
			<form method="post">
				Czy usunąć zdjecie <?= $zdjecie['tytul'] ?>?

				<input type="hidden" name="id" value="<?= $zdjecie['_id'] ?>"/>

				<div>
					<a href="galeria" class="cancel">Anuluj</a>
					<input type="submit" value="Potwierdź"/>
				</div>
			</form>
		</div>
	</body>
</html>
