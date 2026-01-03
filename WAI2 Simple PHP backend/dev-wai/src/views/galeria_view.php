<!DOCTYPE html>
<html>
	<head>
		<title>Galeria</title>
		<link rel="stylesheet" href="static/css/styles.css"/>
		<style>
			@font-face {
				font-family: "Ubuntu";
				src: url("static/czcionki/Ubuntu-Regular.ttf") format("truetype");
			}
		</style>
	</head>
	<body>
		<header>
			<h1>Galeria Filmowa</h1>
		</header>
		<div id="container">
			<?php include '../views/sub_views/nav.php'?>
			<article>
				<?php if (count($galeria)): ?>
					<?php foreach ($galeria as $zdjecie): ?>
						<div class="zdjecie">
							<div class="img">
								<a href="/zdjecie?id=<?= $zdjecie['_id'] ?>" >
									<img src = "<?php echo  '/images/min/min_' . $zdjecie['nazwa'] ?>"></img>
								</a>
							</div>
							<div>
								Tytuł: <?= $zdjecie['tytul'] ?>
							</div>
							<div>
								Autor: <?= $zdjecie['autor'] ?>
							</div>
							<div>
								<a href="usun?id=<?= $zdjecie['_id'] ?>">Usuń</a>
							</div>
						</div>
					<?php endforeach ?>
				<?php else: ?>
					<div id="Brakzdj">
						<div>Brak zdjec</div>
					</div>
				<?php endif ?>
			</article>
			<div id="buff"></div>
			<footer>
				<a href="/galeria?strona=<?php echo $strona-1 ?>">poprzednia strona </a>
				&emsp;
				<a>Strona <?php echo $strona ?></a>
				&emsp;
				<a href="/galeria?strona=<?php echo $strona+1 ?>">następna strona </a>
			</footer>
		</div>
	</body>
</html>