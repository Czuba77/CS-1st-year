#include "guarana.h"
#include "Swiat.h"

guarana::guarana(short x, short y, Swiat* swiat, short wiek) {
	this->wiek = wiek;
	this->nazwa = "Guarana";
	this->inicjatywa = 0;
	this->sila = 0;
	this->znak = 'G';
	this->polozenie[OX] = x;
	this->polozenie[OY] = y;
	this->swiat = swiat;
	swiat->setJesliWolnePole(x, y, znak);
}

void guarana::zasiej(short x, short y) {
	swiat->addOrganizm(new guarana(x, y, this->swiat, swiat->get_and_incrementKtoryUrodzony()));
}

int guarana::kolizja(Organizm* napotkany_org) {
	napotkany_org->zwiekszSile(3);
	return WIN;
}
