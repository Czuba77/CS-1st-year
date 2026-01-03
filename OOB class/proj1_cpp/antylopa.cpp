#include "antylopa.h"

enum KIERUNKI {
	POLNOC = 0,
	POLUDNIE = 1,
	WSCHOD = 2,
	ZACHOD = 3
};

void antylopa::wykonanie_porodu(short x, short y) {
	swiat->addOrganizm(new antylopa(x, y, swiat, swiat->get_and_incrementKtoryUrodzony()));
}

antylopa::antylopa(short x, short y, Swiat* swiat, short wiek) {
	this->wiek = wiek;
	this->nazwa = "Antylopa";
	this->inicjatywa = 4;
	this->sila = 4;
	this->znak = 'a';
	this->polozenie[OX] = x;
	this->polozenie[OY] = y;
	this->swiat = swiat;
	swiat->setJesliWolnePole(x, y, znak);
}

antylopa::antylopa(short x, short y, Swiat* swiat, short wiek, short sila, short xp, short yp, short cp) {
	this->wiek = wiek;
	this->nazwa = "Antylopa";
	this->inicjatywa = 4;
	this->sila = sila;
	this->znak = 'a';
	this->polozenie[OX] = x;
	this->polozenie[OY] = y;
	this->swiat = swiat;
	this->poprzednie_polozenie[OX] = xp;
	this->poprzednie_polozenie[OY] = yp;
	this->cooldown_porodowy = cp;
}



int antylopa::kolizja(Organizm* napotkany_org) {
	short if_flew = genRand(0,1);
	if (if_flew) {
		if (znajdz_wolny(polozenie[OX], polozenie[OY])) {
			napotkany_org->GetWorld()->zmienZnakNaPolu(napotkany_org->GetOx(), napotkany_org->GetOy(), napotkany_org->GetZnak());
			std::string zdarzenie = "Na polu (" + std::to_string(polozenie[OX]) + "," + std::to_string(polozenie[OY]) + "), doszlo do kolizji " +
				this->nazwa + " uciekla przed " + napotkany_org->GetNazwa() + ".\n";
			swiat->dodajZdarzenie(zdarzenie);
			return SPECIAL_CASE;
		}
		else
			return WIN;
	}
	else if (this->sila <= napotkany_org->GetSila())
		return WIN;
	else
		return LOOSE;
}


void antylopa::wykonanie_akcji(short kierunek) {
	switch (kierunek)
	{
	case POLUDNIE:
		if (polozenie[OY] + 2 >= BOARD_WIDTH)
			polozenie[OY] = 0;
		else
			polozenie[OY] += 2;
		break;
	case POLNOC:
		if (polozenie[OY] - 2 < 0)
			polozenie[OY] = BOARD_WIDTH - 2;
		else
			polozenie[OY] -= 2;
		break;
	case WSCHOD:
		if (polozenie[OX] + 2 >= BOARD_HEIGHT)
			polozenie[OX] = 0;
		else
			polozenie[OX] += 2;
		break;
	case ZACHOD:
		if (polozenie[OX] - 2 < 0)
			polozenie[OX] = BOARD_HEIGHT - 2;
		else
			polozenie[OX] -= 2;
		break;
	}
}

bool antylopa::znajdz_wolny(short x, short y) {
	if (y + 1 >= BOARD_WIDTH) {
		if (swiat->setJesliWolnePole(x, 0, znak)) {
			polozenie[OX] = x;
			polozenie[OY] = 0;
			return true;
		}
	}
	else
		if (swiat->setJesliWolnePole(x, y, znak)) {
			polozenie[OX] = x;
			polozenie[OY] = y;
			return true;
		}

	if (y - 1 < 0) {
		if (swiat->setJesliWolnePole(x, BOARD_WIDTH - 1,znak)) {
			polozenie[OX] = x;
			polozenie[OY] = BOARD_WIDTH - 1;
			return true;
		}
	}
	else
		if (swiat->setJesliWolnePole(x, y, znak)) {
			polozenie[OX] = x;
			polozenie[OY] = y;
			return true;
		}

	if (x + 1 >= BOARD_HEIGHT) {
		if (swiat->setJesliWolnePole(0, y, znak)) {
			polozenie[OX] = 0;
			polozenie[OY] = y;
			return true;
		}
	}
	else
		if (swiat->setJesliWolnePole(x, y, znak)) {
			polozenie[OX] = x;
			polozenie[OY] = y;
			return true;
		}
	
	if (x - 1 < 0) {
		if (swiat->setJesliWolnePole(BOARD_HEIGHT - 1, y, znak)) {
			polozenie[OX] = BOARD_HEIGHT - 1;
			polozenie[OY] = y;
			return true;
		}
	}
	else
		if (swiat->setJesliWolnePole(x, y, znak)) {
			polozenie[OX] = x;
			polozenie[OY] = y;
			return true;
		}

	return false;
}