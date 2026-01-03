#include "mlecz.h"
#include "Swiat.h"

mlecz::mlecz(short x, short y, Swiat* swiat, short wiek) {
	this->wiek = wiek;
	this->nazwa = "Mlecz";
	this->inicjatywa = 0;
	this->sila = 0;
	this->znak = 'M';
	this->polozenie[OX] = x;
	this->polozenie[OY] = y;
	this->swiat = swiat;
	swiat->setJesliWolnePole(x, y, znak);
}

void mlecz::zasiej(short x, short y) {
	swiat->addOrganizm(new mlecz(x, y, this->swiat, swiat->get_and_incrementKtoryUrodzony()));
}

void mlecz::akcja() {
	short chance;
	swiat->zwolnijPole(polozenie[OX], polozenie[OY]);
	for (int i = 0; i < 3; i++) {
		chance = genRand(1, EXPAND_CHANCE);
		if (chance == 1) {
			short direction = genRand(0, 3);
			wykonanie_akcji(direction);
		}
	}
};