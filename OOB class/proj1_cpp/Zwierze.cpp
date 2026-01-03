#include "Zwierze.h"
#include "Organizm.h"
#include "Swiat.h"
#include <cstdlib>
#include <fstream>

enum KIERUNKI {
	POLNOC = 0,
	POLUDNIE = 1,
	WSCHOD = 2,
	ZACHOD = 3
};

#define BOARD_WIDTH swiat->getM()
#define BOARD_HEIGHT swiat->getN()

void Zwierze::setCooldownPorodowy() {
	this->cooldown_porodowy = 3;
}

short const  Zwierze::GetCooldownPorodowy() {
	return cooldown_porodowy;
}

int Zwierze::rozmnazanie(Organizm* napotkany_org) {
	napotkany_org->SetOx(napotkany_org->GetOx_poprz());
	napotkany_org->SetOy(napotkany_org->GetOy_poprz());
	napotkany_org->GetWorld()->setJesliWolnePole(napotkany_org->GetOx(), napotkany_org->GetOy(), napotkany_org->GetZnak());
	if (this->cooldown_porodowy > 0 || napotkany_org->GetCooldownPorodowy()>0) {
		std::string zdarzenie= nazwa + "(" + std::to_string(polozenie[OX]) + "," + std::to_string(polozenie[OY]) + ") probowala urodzic, niestety nie byla wstanie\n";
		swiat->dodajZdarzenie(zdarzenie);
		return 0;
	}
	Organizm* pobliskie_pole;
	if (polozenie[OY] != BOARD_WIDTH - 1) {
		pobliskie_pole = swiat->findOrganizm(polozenie[OX], polozenie[OY] + 1, this);
		if(urodz(pobliskie_pole, napotkany_org, polozenie[OX], polozenie[OY] + 1)) return 1;
	}
	else {
		pobliskie_pole = swiat->findOrganizm(polozenie[OX], 0, this);
		if(urodz(pobliskie_pole, napotkany_org, polozenie[OX], 0)) return 1;;
	}

	if (polozenie[OY] != 0) {
		pobliskie_pole = swiat->findOrganizm(polozenie[OX], polozenie[OY] - 1, this);
		if(urodz(pobliskie_pole, napotkany_org, polozenie[OX], polozenie[OY] - 1)) return 1;
	}
	else {
		pobliskie_pole = swiat->findOrganizm(polozenie[OX], BOARD_WIDTH - 1, this);
		if(urodz(pobliskie_pole, napotkany_org, polozenie[OX], BOARD_WIDTH - 1)) return 1;
	}

	if (polozenie[OX] != BOARD_HEIGHT - 1) {
		pobliskie_pole = swiat->findOrganizm(polozenie[OX] + 1, polozenie[OY], this);
		if(urodz(pobliskie_pole, napotkany_org, polozenie[OX] + 1, polozenie[OY])) return 1;
	}
	else {
		pobliskie_pole = swiat->findOrganizm(0, polozenie[OY], this);
		if(urodz(pobliskie_pole, napotkany_org, 0, polozenie[OY])) return 1;
	}

	if (polozenie[OX] != 0) {
		pobliskie_pole = swiat->findOrganizm(polozenie[OX] - 1, polozenie[OY], this);
		if(urodz(pobliskie_pole, napotkany_org, polozenie[OX] - 1, polozenie[OY])) return 1;
	}
	else {
		pobliskie_pole = swiat->findOrganizm(BOARD_HEIGHT - 1, polozenie[OY], this);
		if(urodz(pobliskie_pole, napotkany_org, BOARD_HEIGHT - 1, polozenie[OY])) return 1;
	}

	if (polozenie[OX] != BOARD_HEIGHT - 1 && polozenie[OY] != BOARD_WIDTH - 1) {
		pobliskie_pole = swiat->findOrganizm(polozenie[OX] + 1, polozenie[OY] + 1, this);
		if(urodz(pobliskie_pole, napotkany_org, polozenie[OX] + 1, polozenie[OY] + 1)) return 1;
	}
	else if (polozenie[OX] != BOARD_HEIGHT - 1) {
		pobliskie_pole = swiat->findOrganizm(polozenie[OX] + 1, 0, this);
		if (urodz(pobliskie_pole, napotkany_org, polozenie[OX] + 1, 0)) return 1;
	}
	else if (polozenie[OY] != BOARD_WIDTH - 1) {
		pobliskie_pole = swiat->findOrganizm(0, polozenie[OY] + 1, this);
		if(urodz(pobliskie_pole, napotkany_org, 0, polozenie[OY] + 1)) return 1;
	}
	else {
		pobliskie_pole = swiat->findOrganizm(0, 0, this);
		if(urodz(pobliskie_pole, napotkany_org, 0, 0)) return 1;
	}

	if (polozenie[OX] != BOARD_HEIGHT - 1 && polozenie[OY] != 0) {
		pobliskie_pole = swiat->findOrganizm(polozenie[OX] + 1, polozenie[OY] - 1, this);
		if(urodz(pobliskie_pole, napotkany_org, polozenie[OX] + 1, polozenie[OY] - 1)) return 1;
	}
	else if (polozenie[OY] != 0) {
		pobliskie_pole = swiat->findOrganizm(0, polozenie[OY] - 1, this);
		if (urodz(pobliskie_pole, napotkany_org, 0, polozenie[OY] - 1)) return 1;
	}
	else if (polozenie[OX] != BOARD_HEIGHT - 1) {
		pobliskie_pole = swiat->findOrganizm(polozenie[OX] + 1, BOARD_WIDTH - 1, this);
		if(urodz(pobliskie_pole, napotkany_org, polozenie[OX] + 1, BOARD_WIDTH - 1)) return 1;
	}
	else {
		pobliskie_pole = swiat->findOrganizm(0, BOARD_WIDTH - 1, this);
		if(urodz(pobliskie_pole, napotkany_org, 0, BOARD_WIDTH - 1)) return 1;
	}

	if (polozenie[OX] != 0 && polozenie[OY] != BOARD_WIDTH - 1) {
		pobliskie_pole = swiat->findOrganizm(polozenie[OX] - 1, polozenie[OY] + 1, this);
		if(urodz(pobliskie_pole, napotkany_org, polozenie[OX] - 1, polozenie[OY] + 1)) return 1;
	}
	else if (polozenie[OY] != BOARD_WIDTH - 1) {
		pobliskie_pole = swiat->findOrganizm(BOARD_HEIGHT - 1, polozenie[OY] + 1, this);
		if (urodz(pobliskie_pole, napotkany_org, BOARD_HEIGHT - 1, polozenie[OY] + 1)) return 1;
	}
	else if (polozenie[OX] != 0) {
		pobliskie_pole = swiat->findOrganizm(polozenie[OX] - 1, 0, this);
		if(urodz(pobliskie_pole, napotkany_org, polozenie[OX] - 1, 0)) return 1;
	}
	else {
		pobliskie_pole = swiat->findOrganizm(BOARD_HEIGHT - 1, 0, this);
		if(urodz(pobliskie_pole, napotkany_org, BOARD_HEIGHT - 1, 0)) return 1;
	}

	if (polozenie[OX] != 0 && polozenie[OY] != 0) {
		pobliskie_pole = swiat->findOrganizm(polozenie[OX] - 1, polozenie[OY] - 1, this);
		if(urodz(pobliskie_pole, napotkany_org, polozenie[OX] - 1, polozenie[OY] - 1)) return 1;
	}
	else if (polozenie[OY] != 0) {
		pobliskie_pole = swiat->findOrganizm(BOARD_HEIGHT - 1, polozenie[OY] - 1, this);
		if (urodz(pobliskie_pole, napotkany_org, BOARD_HEIGHT - 1, polozenie[OY] - 1)) return 1;
	}
	else if (polozenie[OX] != 0) {
		pobliskie_pole = swiat->findOrganizm(polozenie[OX] - 1, BOARD_WIDTH - 1, this);
		if(urodz(pobliskie_pole, napotkany_org, polozenie[OX] - 1, BOARD_WIDTH - 1)) return 1;
	}
	else {
		pobliskie_pole = swiat->findOrganizm(BOARD_HEIGHT - 1, BOARD_WIDTH - 1, this);
		if(urodz(pobliskie_pole, napotkany_org, BOARD_HEIGHT - 1, BOARD_WIDTH - 1)) return 1;
	}
	return 0;
}

bool Zwierze::urodz(Organizm* pobliskie_pole, Organizm* napotkany_organizm, short x, short y) {
	std::string zdarzenie;
	if (pobliskie_pole == nullptr) {
		this->setCooldownPorodowy();
		napotkany_organizm->setCooldownPorodowy();
		zdarzenie = nazwa + "(" + std::to_string(polozenie[OX]) + "," + std::to_string(polozenie[OY]) + ") urodzil/la na polu ("
			+ std::to_string(x) + "," + std::to_string(y) + ").\n";
		swiat->dodajZdarzenie(zdarzenie);
		this->wykonanie_porodu(x, y);
		return true;
	}
	return false;
}

void Zwierze::akcja() {
	if (cooldown_porodowy)
		cooldown_porodowy--;
	swiat->zwolnijPole(polozenie[OX], polozenie[OY]);
	int direction  =genRand(0,3);
	poprzednie_polozenie[OX] = polozenie[OX];
	poprzednie_polozenie[OY] = polozenie[OY];
	wykonanie_akcji(direction);
	/*
	std::string zdarzenie = nazwa + "(" + std::to_string(poprzednie_polozenie[OX]) + "," + std::to_string(poprzednie_polozenie[OY]) + ") idzie na pole (" 
		+ std::to_string(polozenie[OX]) + "," + std::to_string(polozenie[OY]) + ").\n";
	swiat->dodajZdarzenie(zdarzenie);
	*/
}

void Zwierze::wykonanie_akcji(short kierunek) {
	switch (kierunek)
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
	default:
		break;
	}
}


short const Zwierze::GetOy_poprz(){
	return poprzednie_polozenie[OY];
}

short const Zwierze::GetOx_poprz() {
	return poprzednie_polozenie[OX];
}

void Zwierze::zapiszOrganizm(std::fstream& zapis) {
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
}