<!DOCTYPE html>
<html>
	<head>
		<title>Zdjęcie</title>
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
			<h1>Zdjęcie</h1>
		</header>
		<div id="container">
			<?php include '../views/sub_views/nav.php'?>
			<img src = "<?php echo  '/images/zw/zw_' . $zdjecie['nazwa'] ?>"></img>
			<article>
				<h1>Tytuł: <?= $zdjecie['tytul'] ?></h1>
				<div>Autor: <?= $zdjecie['autor'] ?></div>
			</article>
		</div>
	</body>
</html>
