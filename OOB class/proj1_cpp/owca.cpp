#include "owca.h"
owca::owca(short x, short y, Swiat* swiat, short wiek) {
	this->wiek = wiek;
	this->nazwa = "Owca";
	this->inicjatywa = 4;
	this->sila = 4;
	this->znak = 'o';
	this->polozenie[OX] = x;
	this->polozenie[OY] = y;
	this->swiat = swiat;
	swiat->setJesliWolnePole(x, y, znak);
}

owca::owca(short x, short y, Swiat* swiat, short wiek, short sila, short xp, short yp, short cp) {
	this->wiek = wiek;
	this->nazwa = "Owca";
	this->inicjatywa = 4;
	this->sila = sila;
	this->znak = 'o';
	this->polozenie[OX] = x;
	this->polozenie[OY] = y;
	this->swiat = swiat;
	this->poprzednie_polozenie[OX] = xp;
	this->poprzednie_polozenie[OY] = yp;
	this->cooldown_porodowy = cp;
}

void owca::wykonanie_porodu(short x, short y) {
	swiat->addOrganizm(new owca(x, y, swiat, swiat->get_and_incrementKtoryUrodzony()));
}
