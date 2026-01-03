#include "zolw.h"

zolw::zolw(short x, short y, Swiat* swiat, short wiek) {
	this->wiek = wiek;
	this->nazwa = "Zolw";
	this->inicjatywa = 1;
	this->sila = 2;
	this->znak = 'z';
	this->polozenie[OX] = x;
	this->polozenie[OY] = y;
	this->swiat = swiat;
	swiat->setJesliWolnePole(x, y, znak);
}

zolw::zolw(short x, short y, Swiat* swiat, short wiek, short sila, short xp, short yp, short cp) {
	this->wiek = wiek;
	this->nazwa = "Zolw";
	this->inicjatywa = 1;
	this->sila = sila;
	this->znak = 'z';
	this->polozenie[OX] = x;
	this->polozenie[OY] = y;
	this->swiat = swiat;
	this->poprzednie_polozenie[OX] = xp;
	this->poprzednie_polozenie[OY] = yp;
	this->cooldown_porodowy = cp;
}


void zolw::akcja(){
	if (cooldown_porodowy)
		cooldown_porodowy--;
	swiat->zwolnijPole(polozenie[OX], polozenie[OY]);
	int direction = genRand(0, 15);
	poprzednie_polozenie[OX] = polozenie[OX];
	poprzednie_polozenie[OY] = polozenie[OY];
	wykonanie_akcji(direction);
	std::string zdarzenie;
	if (direction < 4) {
		/*
		zdarzenie = nazwa + "(" + std::to_string(poprzednie_polozenie[OX]) + "," + std::to_string(poprzednie_polozenie[OY]) + ") idzie na pole ("
			+ std::to_string(polozenie[OX]) + "," + std::to_string(polozenie[OY]) + ").\n";
			*/
	}
	else {
		zdarzenie = nazwa + "(" + std::to_string(polozenie[OX]) + "," + std::to_string(polozenie[OY]) + ") nie ruszyl sie.\n";
	}
	swiat->dodajZdarzenie(zdarzenie);
}

int zolw::kolizja(Organizm* napotkany_org) {
	if (napotkany_org->GetSila() < 5) {
		napotkany_org->SetOx(napotkany_org->GetOx_poprz());
		napotkany_org->SetOy(napotkany_org->GetOy_poprz());
		napotkany_org->GetWorld()->setJesliWolnePole(napotkany_org->GetOx(), napotkany_org->GetOy(), napotkany_org->GetZnak());
		std::string zdarzenie = "Na polu (" + std::to_string(polozenie[OX]) + "," + std::to_string(polozenie[OY]) + "), doszlo do kolizji " +
			this->nazwa + " odbil atak " + napotkany_org->GetNazwa() + ".\n";
		swiat->dodajZdarzenie(zdarzenie);
		return SPECIAL_CASE;
	}
	else if (this->sila <= napotkany_org->GetSila())
		return WIN;
	else
		return LOOSE;
}


void zolw::wykonanie_porodu(short x, short y) {
	swiat->addOrganizm(new zolw(x, y, swiat, swiat->get_and_incrementKtoryUrodzony()));
}
