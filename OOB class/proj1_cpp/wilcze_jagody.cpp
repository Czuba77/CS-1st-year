#include "wilcze_jagody.h"
#include "Swiat.h"

wilcze_jagody::wilcze_jagody(short x, short y, Swiat* swiat, short wiek) {
	this->wiek = wiek;
	this->nazwa = "Wilcze Jagody";
	this->inicjatywa = 0;
	this->sila = 99;
	this->znak = 'W';
	this->polozenie[OX] = x;
	this->polozenie[OY] = y;
	this->swiat = swiat;
	swiat->setJesliWolnePole(x, y, znak);
}


void wilcze_jagody::zasiej(short x, short y) {
	swiat->addOrganizm(new wilcze_jagody(x, y, this->swiat, swiat->get_and_incrementKtoryUrodzony()));
}

int wilcze_jagody::kolizja(Organizm* napotkany_org) {
	return POISON;
}
