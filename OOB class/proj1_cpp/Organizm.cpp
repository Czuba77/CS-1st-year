#include "Organizm.h"
#include "Zwierze.h"
#include "Swiat.h"
#include <random>
#include <fstream>

short const Organizm::GetOx() {
	return polozenie[OX];
}

short const Organizm::GetOy() {
	return polozenie[OY];
}

char const Organizm::GetZnak() {
	return znak;
}

std::string const Organizm::GetNazwa() {
	return nazwa;
}

short const Organizm::GetInicjatywa() {
	return inicjatywa;
}

short const Organizm::GetWiek() {
	return wiek;
}

short const Organizm::GetSila() {
	return sila;
}

Swiat* const Organizm::GetWorld() {
	return swiat;
}

void Organizm::SetOx(short polozeniex) {
	 polozenie[OX]=polozeniex;
}

void Organizm::SetOy(short polozeniey) {
	 polozenie[OY] = polozeniey;
}

void Organizm::zwiekszSile(short howmuch) {
	this->sila += howmuch;
}

short Organizm::genRand(short min, short max) {
	std::random_device rd;
	std::mt19937 generator(rd());
	std::uniform_int_distribution<int> distribution(min, max);
	int rand_num = distribution(generator);
	return rand_num;
}

void Organizm::rysowanie() {
	short warun;
	std::string zdarzenie;
	if (swiat->setJesliWolnePole(polozenie[OX], polozenie[OY], znak)==false) {
		Organizm* napotkany_org = swiat->findOrganizm(polozenie[OX], polozenie[OY], this);
		if (napotkany_org->GetNazwa() != this->GetNazwa()) {
			warun = napotkany_org->kolizja(this);
			if (warun == WIN) {
				zdarzenie = "Na polu (" + std::to_string(polozenie[OX]) + "," + std::to_string(polozenie[OY]) + "), doszlo do kolizji " +
					this->nazwa + " wygral/a z " + napotkany_org->nazwa + ".\n";
				swiat->zmienIteratorUsuwanie(this, napotkany_org);
				napotkany_org->~Organizm();
				swiat->zmienZnakNaPolu(polozenie[OX], polozenie[OY], znak);
			}
			else if (warun == LOOSE) {
				zdarzenie = "Na polu (" + std::to_string(polozenie[OX]) + "," + std::to_string(polozenie[OY]) + "), doszlo do kolizji " +
					napotkany_org->nazwa + " wygral/a z " + this->nazwa + ".\n";
				this->~Organizm();
			}
			else if (warun == POISON) {
				zdarzenie = "Na polu (" + std::to_string(polozenie[OX]) + "," + std::to_string(polozenie[OY]) + "), doszlo do kolizji " +
					this->nazwa + " zatrul/a sie jedzac " + napotkany_org->nazwa + ".\n";
				swiat->zmienIteratorUsuwanie(this, napotkany_org);
				napotkany_org->~Organizm();
				this->~Organizm();
				swiat->zwolnijPole(polozenie[OX], polozenie[OY]);
			}

			swiat->dodajZdarzenie(zdarzenie);
			//jesli nie zajdzie zaden z warunkow to wystapil special case ktory jest roziwazany w metodzie kolizja napotakanego organizmu
		}
		else
			rozmnazanie(napotkany_org);

	}
}


int Organizm::kolizja(Organizm* napotkany_org) {
	if (this->sila <= napotkany_org->sila) {
		return WIN;
	}
	else
		return LOOSE;
}

Organizm::~Organizm() {
	swiat->usunZwierze(this);
}

void Organizm::zapiszOrganizm(std::fstream& zapis) {
	zapis << znak;
	zapis << " ";
	zapis << polozenie[OX];
	zapis << " ";
	zapis << polozenie[OY];
	zapis << " ";
	zapis << wiek;
	zapis << " ";
}