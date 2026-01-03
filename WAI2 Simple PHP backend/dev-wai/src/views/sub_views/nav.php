<nav>
				<ol>
					<li>
						<a href="/">Galeria</a>
					</li>
					<li>
						<a href="/formularz">Dodaj zdjęcie</a>
					</li>
					<?php if( isset($_SESSION['user_id']) ):?>
					<li>
						<a href="/wylogowanie">Wyloguj się</a>
					</li>
					<?php else: ?>
					<li>
						<a href="/rejestracja">Dołącz do kinomaniaków</a>
					</li>
					<li>
						<a href="/logowanie">Zaloguj się</a>
					</li>
					<?php endif ?>
				</ol>
</nav>