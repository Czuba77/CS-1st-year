<!DOCTYPE html>
<html>
	<head>
		<title>Przesyłanie zdjęć</title>
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
			<h1>Przesyłanie zdjęć</h1>
		</header>
		<div id="container">
			<?php include '../views/sub_views/nav.php'?>
			<article>
				<?php
					echo $zdjecie['wiad'] . "<br>";
					if(isset($zdjecie['w1'])){
						echo $zdjecie['w1'] . "<br>";
					}
					if(isset($zdjecie['w2'])){
						echo $zdjecie['w2'] . "<br>";
					}
				?>
			</article>
		</div>
	</body>
</html>


