#include "trawa.h"
#include "Swiat.h"

trawa::trawa(short x, short y, Swiat* swiat, short wiek) {
	this->wiek = wiek;
	this->nazwa = "Trawa";
	this->inicjatywa = 0;
	this->sila = 0;
	this->znak = 'T';
	this->polozenie[OX] = x;
	this->polozenie[OY] = y;
	this->swiat = swiat;
	swiat->setJesliWolnePole(x, y, znak);
}


void trawa::zasiej(short x, short y) {
	swiat->addOrganizm(new trawa(x, y, this->swiat, swiat->get_and_incrementKtoryUrodzony()));
}