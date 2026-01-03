#include "lis.h"
#include "Organizm.h"
#include "Swiat.h"
#include "cstdlib"

enum KIERUNKI {
	POLNOC = 0,
	POLUDNIE = 1,
	WSCHOD = 2,
	ZACHOD = 3
};

#define BOARD_WIDTH swiat->getM()
#define BOARD_HEIGHT swiat->getN()

lis::lis(short x, short y, Swiat* swiat, short wiek) {
	this->wiek = wiek;
	this->nazwa = "Lis";
	this->inicjatywa = 7;
	this->sila = 3;
	this->znak = 'l';
	this->polozenie[OX] = x;
	this->polozenie[OY] = y;
	this->swiat = swiat;
	swiat->setJesliWolnePole(x, y, znak);
}

lis::lis(short x, short y, Swiat* swiat, short wiek, short sila, short xp, short yp, short cp) {
	this->wiek = wiek;
	this->nazwa = "Lis";
	this->inicjatywa = 7;
	this->sila = sila;
	this->znak = 'l';
	this->polozenie[OX] = x;
	this->polozenie[OY] = y;
	this->swiat = swiat;
	this->poprzednie_polozenie[OX] = xp;
	this->poprzednie_polozenie[OY] = yp;
	this->cooldown_porodowy = cp;
}


void lis::wykonanie_porodu(short x, short y) {
	swiat->addOrganizm(new lis(x, y, swiat, swiat->get_and_incrementKtoryUrodzony()));
}

void lis::wykonanie_akcji(short direction) {
	switch (direction)
	{
	case POLUDNIE:
		if (polozenie[OY] + 1 >= BOARD_WIDTH)
			polozenie[OY] = 0;
		else
			polozenie[OY] += 1;
		break;
	case POLNOC:
		if (polozenie[OY] - 1 < 0)
			polozenie[OY] = BOARD_WIDTH - 1;
		else
			polozenie[OY] -= 1;
		break;
	case WSCHOD:
		if (polozenie[OX] + 1 >= BOARD_HEIGHT)
			polozenie[OX] = 0;
		else
			polozenie[OX] += 1;
		break;
	case ZACHOD:
		if (polozenie[OX] - 1 < 0)
			polozenie[OX] = BOARD_HEIGHT - 1;
		else
			polozenie[OX] -= 1;
		break;
	}
	Organizm* diff_org = swiat->findOrganizm(polozenie[OX], polozenie[OY], this);
	if (diff_org != nullptr && diff_org->GetSila()>this->sila) {
		polozenie[OX] = poprzednie_polozenie[OX];
		polozenie[OY] = poprzednie_polozenie[OY];
		wykonanie_akcji((direction + 1) % 3);
	}
}