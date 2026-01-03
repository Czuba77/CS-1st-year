#include "czlowiek.h"
#include "Zwierze.h"
#include "Organizm.h"
#include <conio.h>
#include <fstream>


#define KB_UP 75
#define KB_DOWN 77
#define KB_LEFT 72
#define KB_RIGHT 80
#define KB_ESCAPE 27

enum KIERUNKI {
	POLNOC = 0,
	POLUDNIE = 1,
	WSCHOD = 2,
	ZACHOD = 3,
	SPECIAL = 4
};

czlowiek::czlowiek(short x, short y, Swiat* swiat, short wiek) {
	this->wiek = wiek;
	this->nazwa = "Czlowiek";
	this->inicjatywa = 4;
	this->sila = 5;
	this->sila_flat = 5;
	this->cooldown_ult = 0;
	this->znak = 'c';
	this->polozenie[OX] = x;
	this->polozenie[OY] = y;
	this->swiat = swiat;
	swiat->setJesliWolnePole(x, y, znak);
}

czlowiek::czlowiek(short x, short y, Swiat* swiat, short wiek, short sila, short xp, short yp, short cp, short sila_flat, short cooldown_ult){
	this->wiek = wiek;
	this->nazwa = "Czlowiek";
	this->inicjatywa = 4;
	this->sila = sila;
	this->sila_flat = sila_flat;
	this->cooldown_ult = cooldown_ult;
	this->znak = 'c';
	this->polozenie[OX] = x;
	this->polozenie[OY] = y;
	this->poprzednie_polozenie[OX] = xp;
	this->poprzednie_polozenie[OY] = yp;
	this->cooldown_porodowy = cp;
	this->swiat = swiat;
	swiat->setJesliWolnePole(x, y, znak);
}

void czlowiek::wykonanie_porodu(short x, short y) {
	swiat->addOrganizm(new czlowiek(x, y, swiat, swiat->get_and_incrementKtoryUrodzony()));
}

void czlowiek::akcja() {
	if (cooldown_porodowy)
		cooldown_porodowy--;
	swiat->rysujSwiat();
	swiat->wypisz_dziennik();

	if (sila > sila_flat) {
		sila--;
		if (sila == sila_flat)
			cooldown_ult = 5;
	}
	else if (cooldown_ult > 0)
		cooldown_ult--;
	swiat->zwolnijPole(polozenie[OX], polozenie[OY]);
	int direction=5, tmp;
	while (direction > 3) {
		tmp = _getch();
		switch (tmp)
		{
		case KB_LEFT:
			direction = ZACHOD;
			break;

		case KB_RIGHT:
			direction = WSCHOD;
			break;

		case KB_UP:
			direction = POLNOC;
			break;

		case KB_DOWN:
			direction = POLUDNIE;
			break;
		case 's':
			if (sila == sila_flat && cooldown_ult == 0) {
				sila += 5;
				swiat->rysujSwiat();
				swiat->wypisz_dziennik();
			}
			break;
		case 'z':
			swiat->zapiszGre();
			break;
		case 'w':
			swiat->wczytajGreFun();
			direction = POLNOC;
			break;
		case KB_ESCAPE:
			swiat->zakonczGreFun();
			direction = POLNOC;
			break;
		}
	}
	swiat->czysc_dziennik();
	poprzednie_polozenie[OX] = polozenie[OX];
	poprzednie_polozenie[OY] = polozenie[OY];
	wykonanie_akcji(direction);
}

void czlowiek::czlowiek_status() {
	if(cooldown_ult==0 && sila>sila_flat)
		printf("%c  Sila - %d   Umiejetnosc specjalna aktywna\n", 186, sila);
	else if(sila==sila_flat && cooldown_ult!=0)
		printf("%c  Sila - %d   Umiejetnosc specjalna dostepna za %d\n", 186, sila,cooldown_ult);
	else
		printf("%c  Sila - %d   Umiejetnosc specjalna gotowa do uzycia\n", 186, sila, cooldown_ult);
}

void czlowiek::zwiekszSile(short oIle) {
	this->sila += oIle;
	this->sila_flat += oIle;
}

czlowiek::~czlowiek() {
	swiat->zakonczGreFun();
	swiat->setCzlowiek(nullptr);
}

void czlowiek::zapiszOrganizm(std::fstream& zapis) {
	zapis << znak;
	zapis << " ";
	zapis << polozenie[OX];
	zapis << " ";
	zapis << polozenie[OY];
	zapis << " ";
	zapis << sila;
	zapis << " ";
	zapis << wiek;
	zapis << " ";
	zapis << poprzednie_polozenie[OX];
	zapis << " ";
	zapis << poprzednie_polozenie[OY];
	zapis << " ";
	zapis << cooldown_porodowy;
	zapis << " ";
	zapis << sila_flat;
	zapis << " ";
	zapis << cooldown_ult;
	zapis << " ";
}