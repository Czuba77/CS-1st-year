#include "barszcz_sosnowskiego.h"
#include "Swiat.h"
#include "Roslina.h"

barszcz_sosnowskiego::barszcz_sosnowskiego(short x, short y, Swiat* swiat, short wiek) {
	this->wiek = wiek;
	this->nazwa = "Barszcz sosnowskiego";
	this->inicjatywa = 0;
	this->sila = 10;
	this->znak = 'B';
	this->polozenie[OX] = x;
	this->polozenie[OY] = y;
	this->swiat = swiat;
	swiat->setJesliWolnePole(x, y, znak);
}


void barszcz_sosnowskiego::zasiej(short x, short y) {
	swiat->addOrganizm(new barszcz_sosnowskiego(x, y, swiat,swiat->get_and_incrementKtoryUrodzony()));
}

int barszcz_sosnowskiego::kolizja(Organizm* napotkany_org) {
	return POISON;
}

void barszcz_sosnowskiego::akcja() {
	swiat->zwolnijPole(polozenie[OX], polozenie[OY]);
	zabij_wszystkie_zwierzeta();
	short chance = genRand(1, EXPAND_CHANCE);
	if (chance == 1) {
		short direction = genRand(0, 3);
		wykonanie_akcji(direction);
	}
};

void barszcz_sosnowskiego::zabij_wszystkie_zwierzeta() {
	Organizm* pobliski_organizm;
	if (polozenie[OY] != BOARD_WIDTH - 1) {
		pobliski_organizm = swiat->findOrganizm(polozenie[OX], polozenie[OY] + 1, this);
		zabij_zwierze(pobliski_organizm);
	}
	else {
		pobliski_organizm = swiat->findOrganizm(polozenie[OX], 0, this);
		zabij_zwierze(pobliski_organizm);
	}

	if (polozenie[OY] != 0) {
		pobliski_organizm = swiat->findOrganizm(polozenie[OX], polozenie[OY] - 1, this);
		zabij_zwierze(pobliski_organizm);
	}
	else {
		pobliski_organizm = swiat->findOrganizm(polozenie[OX], BOARD_WIDTH - 1, this);
		zabij_zwierze(pobliski_organizm);
	}

	if (polozenie[OX] != BOARD_HEIGHT - 1) {
		pobliski_organizm = swiat->findOrganizm(polozenie[OX] + 1, polozenie[OY], this);
		zabij_zwierze(pobliski_organizm);
	}
	else {
		pobliski_organizm = swiat->findOrganizm(0, polozenie[OY], this);
		zabij_zwierze(pobliski_organizm);
	}

	if (polozenie[OX] != 0) {
		pobliski_organizm = swiat->findOrganizm(polozenie[OX] - 1, polozenie[OY], this);
		zabij_zwierze(pobliski_organizm);
	}
	else {
		pobliski_organizm = swiat->findOrganizm(BOARD_HEIGHT - 1, polozenie[OY], this);
		zabij_zwierze(pobliski_organizm);
	}

	if (polozenie[OX] != BOARD_HEIGHT - 1 && polozenie[OY] != BOARD_WIDTH - 1) {
		pobliski_organizm = swiat->findOrganizm(polozenie[OX] + 1, polozenie[OY] + 1, this);
		zabij_zwierze(pobliski_organizm);
	}
	else if (polozenie[OX] != BOARD_HEIGHT - 1) {
		pobliski_organizm = swiat->findOrganizm( 0, polozenie[OY] + 1, this);
		zabij_zwierze(pobliski_organizm);
	}
	else if (polozenie[OY] != BOARD_WIDTH - 1) {
		pobliski_organizm = swiat->findOrganizm(polozenie[OX]+1, 0, this);
		zabij_zwierze(pobliski_organizm);
	}
	else {
		pobliski_organizm = swiat->findOrganizm(0, 0, this);
		zabij_zwierze(pobliski_organizm);
	}

	if (polozenie[OX] != BOARD_HEIGHT - 1 && polozenie[OY] != 0) {
		pobliski_organizm = swiat->findOrganizm(polozenie[OX] + 1, polozenie[OY] - 1, this);
		zabij_zwierze(pobliski_organizm);
	}
	else if (polozenie[OX] != BOARD_HEIGHT - 1) {
		pobliski_organizm = swiat->findOrganizm(polozenie[OX] + 1, BOARD_WIDTH - 1, this);
		zabij_zwierze(pobliski_organizm);
	}
	else if (polozenie[OY] != 0) {
		pobliski_organizm = swiat->findOrganizm(0, polozenie[OY] - 1, this);
		zabij_zwierze(pobliski_organizm);
	}
	else {
		pobliski_organizm = swiat->findOrganizm(0, BOARD_WIDTH - 1, this);
		zabij_zwierze(pobliski_organizm);
	}

	if (polozenie[OX] != 0 && polozenie[OY] != BOARD_WIDTH - 1) {
		pobliski_organizm = swiat->findOrganizm(polozenie[OX] - 1, polozenie[OY] + 1, this);
		zabij_zwierze(pobliski_organizm);
	}
	else if (polozenie[OX] != 0) {
		pobliski_organizm = swiat->findOrganizm(polozenie[OX] - 1, 0, this);
		zabij_zwierze(pobliski_organizm);
	}
	else if (polozenie[OY] != BOARD_WIDTH - 1) {
		pobliski_organizm = swiat->findOrganizm(BOARD_HEIGHT - 1, polozenie[OY] + 1, this);
		zabij_zwierze(pobliski_organizm);
	}
	else {
		pobliski_organizm = swiat->findOrganizm(BOARD_HEIGHT - 1, 0, this);
		zabij_zwierze(pobliski_organizm);
	}

	if (polozenie[OX] != 0 && polozenie[OY] != 0) {
		pobliski_organizm = swiat->findOrganizm(polozenie[OX] - 1, polozenie[OY] - 1, this);
		zabij_zwierze(pobliski_organizm);
	}
	else if (polozenie[OX] != 0) {
		pobliski_organizm = swiat->findOrganizm(polozenie[OX] - 1, BOARD_WIDTH - 1, this);
		zabij_zwierze(pobliski_organizm);
	}
	else if (polozenie[OY] != 0) {
		pobliski_organizm = swiat->findOrganizm(BOARD_HEIGHT - 1, polozenie[OY] - 1, this);
		zabij_zwierze(pobliski_organizm);
	}
	else {
		pobliski_organizm = swiat->findOrganizm(BOARD_HEIGHT - 1, BOARD_WIDTH - 1, this);
		zabij_zwierze(pobliski_organizm);
	}
		

};

void  barszcz_sosnowskiego::zabij_zwierze(Organizm* pobliski_organizm) {
	std::string zdarzenie;
	if (pobliski_organizm != nullptr && pobliski_organizm->GetZnak() >= 'a') {
		zdarzenie = nazwa + "(" + std::to_string(polozenie[OX]) + "," + std::to_string(polozenie[OY]) + ") zabija " + pobliski_organizm->GetNazwa() + "("
			+ std::to_string(pobliski_organizm->GetOx()) + "," + std::to_string(pobliski_organizm->GetOy()) + ").\n";
		swiat->dodajZdarzenie(zdarzenie);
		swiat->zwolnijPole(pobliski_organizm->GetOx(), pobliski_organizm->GetOy());
		swiat->zmienIteratorUsuwanie(this, pobliski_organizm);
		pobliski_organizm->~Organizm();
	}
}