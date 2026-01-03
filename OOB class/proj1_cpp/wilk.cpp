#include "wilk.h"

wilk::wilk(short x, short y, Swiat* swiat, short wiek) {
	this->wiek = wiek;
	this->nazwa = "Wilk";
	this->inicjatywa = 5;
	this->sila = 9;
	this->znak = 'w';
	this->polozenie[OX] = x;
	this->polozenie[OY] = y;
	this->swiat = swiat;
	swiat->setJesliWolnePole(x, y, znak);
}

wilk::wilk(short x, short y, Swiat* swiat, short wiek, short sila, short xp, short yp, short cp) {
	this->wiek = wiek;
	this->nazwa = "Wilk";
	this->inicjatywa = 5;
	this->sila = sila;
	this->znak = 'w';
	this->polozenie[OX] = x;
	this->polozenie[OY] = y;
	this->swiat = swiat;
	this->poprzednie_polozenie[OX] = xp;
	this->poprzednie_polozenie[OY] = yp;
	this->cooldown_porodowy = cp;
}


void wilk::wykonanie_porodu(short x, short y) {
	swiat->addOrganizm(new wilk(x, y, swiat, swiat->get_and_incrementKtoryUrodzony()));
}
