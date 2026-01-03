#include <vector>
#include <fcntl.h>
#include <io.h>
#include "Swiat.h"
#include "Organizm.h"
#include "Zwierze.h"
#include "czlowiek.h"
#include "owca.h"
#include "wilk.h"
#include "antylopa.h"
#include "zolw.h"
#include "lis.h"
#include "trawa.h"
#include "mlecz.h"
#include "guarana.h"
#include "wilcze_jagody.h"
#include "barszcz_sosnowskiego.h"
#include <windows.h>
#include <string>
#include <iostream>
#include <fstream>


#define first 1
#define second 2
#define equal 3

short Swiat::getM() {
	return M;
}

short Swiat::getN() {
	return N;
}


void Swiat::wczytajGre() {
	dziennik_zdarzen = "";
	std::fstream zapis;
	zapis.open("zapis.txt", std::ios::in);

	zapis >> N;
	zapis >> M;

	plansza = new char* [N];
	for (int i = 0; i < N; ++i) {
		plansza[i] = new char[M];
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			plansza[i][j] = '.';
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			zapis >> plansza[i][j];
		}
	}
	zapis >> iterator;
	zapis >> ktory_urodzony;
	std::string tmp;
	zapis >> tmp;
	while (tmp != "_") {
		dziennik_zdarzen += tmp + " ";
		if (tmp.back() == '.')
			dziennik_zdarzen += "\n";
		zapis >> tmp;
	}

	char ctmp;
	int sila,silaflat,ox,oy,oxp,oyp,cp,cu,wiek;
	czlowiek* czlowiek1;
	zapis >> ctmp;
	while(ctmp != '_') {
		switch (ctmp)
		{
		case 'a':
			zapis >> ox;
			zapis >> oy;
			zapis >> sila;
			zapis >> wiek;
			zapis >> oxp;
			zapis >> oyp;
			zapis >> cp;
			addOrganizm(new antylopa(ox,oy,this,wiek,sila,oxp,oyp,cp));
			break;
		case 'c':
			zapis >> ox;
			zapis >> oy;
			zapis >> sila;
			zapis >> wiek;
			zapis >> oxp;
			zapis >> oyp;
			zapis >> cp;
			zapis >> silaflat;
			zapis >> cu;
			czlowiek1 = new czlowiek(ox, oy, this, wiek, sila, oxp, oyp, cp,silaflat,cu);
			setCzlowiek(czlowiek1);
			addOrganizm(czlowiek1);
			break;
		case 'l':
			zapis >> ox;
			zapis >> oy;
			zapis >> sila;
			zapis >> wiek;
			zapis >> oxp;
			zapis >> oyp;
			zapis >> cp;
			addOrganizm(new lis(ox, oy, this, wiek, sila, oxp, oyp, cp));
			break;
		case 'o':
			zapis >> ox;
			zapis >> oy;
			zapis >> sila;
			zapis >> wiek;
			zapis >> oxp;
			zapis >> oyp;
			zapis >> cp;
			addOrganizm(new owca(ox, oy, this, wiek, sila, oxp, oyp, cp));
			break;
		case 'w':
			zapis >> ox;
			zapis >> oy;
			zapis >> sila;
			zapis >> wiek;
			zapis >> oxp;
			zapis >> oyp;
			zapis >> cp;
			addOrganizm(new wilk(ox, oy, this, wiek, sila, oxp, oyp, cp));
			break;
		case 'z':
			zapis >> ox;
			zapis >> oy;
			zapis >> sila;
			zapis >> wiek;
			zapis >> oxp;
			zapis >> oyp;
			zapis >> cp;
			addOrganizm(new zolw(ox, oy, this, wiek, sila, oxp, oyp, cp));
			break;
		case 'B':
			zapis >> ox;
			zapis >> oy;
			zapis >> wiek;
			addOrganizm(new barszcz_sosnowskiego(ox, oy, this,wiek));
			break;
		case 'G':
			zapis >> ox;
			zapis >> oy;
			zapis >> wiek;
			addOrganizm(new guarana(ox, oy, this, wiek));
			break;
		case 'M':
			zapis >> ox;
			zapis >> oy;
			zapis >> wiek;
			addOrganizm(new mlecz(ox, oy, this, wiek));
			break;
		case 'T':
			zapis >> ox;
			zapis >> oy;
			zapis >> wiek;
			addOrganizm(new trawa(ox, oy, this, wiek));
			break;
		case 'W':
			zapis >> ox;
			zapis >> oy;
			zapis >> wiek;
			addOrganizm(new wilcze_jagody(ox, oy, this, wiek));
			break;
		}
		zapis >> ctmp;
	}
	zapis.close();
}

void Swiat::zapiszGre() {
	std::fstream zapis;
	zapis.open("zapis.txt", std::ios::out);

	zapis << N;
	zapis << "\n";
	zapis << M;
	zapis << "\n";

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			zapis << plansza[i][j];
		}
		zapis << "\n";
	}
	zapis << iterator;
	zapis << "\n";
	zapis << ktory_urodzony;
	zapis << "\n";
	zapis << dziennik_zdarzen;
	zapis << '_';
	zapis << "\n";
	for (int i = 0; i < Organizmy.size(); i++) {
		Organizmy[i]->zapiszOrganizm(zapis);
		zapis << "\n";
	}
	zapis << '_';
	zapis.close();
}

Swiat::Swiat(int N, int M) {
	this->N = N;
	this->M = M;
	iterator = 0;
	ktory_urodzony = 0;
	dziennik_zdarzen = "";
	plansza = new char*[N];
	for (int i = 0; i < N; ++i) {
		plansza[i] = new char[M];
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			plansza[i][j] = '.';
		}
	}
	int random_numb,ox,oy;

	do {
		ox = Organizm::genRand(0, N - 1);
		oy = Organizm::genRand(0, M - 1);
	} while (getZnakNaPolu(ox, oy) != '.');
	czlowiek* czlowiek1 = new czlowiek(ox, oy, this, ktory_urodzony++);
	setCzlowiek(czlowiek1);
	addOrganizm(czlowiek1);

	for (int i = 0; i < N * M / 15; i++) {
		random_numb = Organizm::genRand(0, 14);
		do {
			ox = Organizm::genRand(0, N - 1);
			oy = Organizm::genRand(0, M - 1);
		} while (getZnakNaPolu(ox,oy)!='.');
		switch (orglist[random_numb])
		{
		case 'a':
			addOrganizm(new antylopa(ox, oy, this, ktory_urodzony++));
			break;
		case 'l':

			addOrganizm(new lis(ox, oy, this, ktory_urodzony++));
			break;
		case 'o':
			addOrganizm(new owca(ox, oy+1, this, ktory_urodzony++));
			addOrganizm(new owca(ox, oy, this, ktory_urodzony++));
			break;
		case 'w':

			addOrganizm(new wilk(ox, oy, this, ktory_urodzony++));
			break;
		case 'z':

			addOrganizm(new zolw(ox, oy, this, ktory_urodzony++));
			break;
		case 'B':

			addOrganizm(new barszcz_sosnowskiego(ox, oy, this, ktory_urodzony++));
			break;
		case 'G':

			addOrganizm(new guarana(ox, oy, this, ktory_urodzony++));
			break;
		case 'M':

			addOrganizm(new mlecz(ox, oy, this, ktory_urodzony++));
			break;
		case 'T':

			addOrganizm(new trawa(ox, oy, this, ktory_urodzony++));
			break;
		case 'W':

			addOrganizm(new wilcze_jagody(ox, oy, this, ktory_urodzony++));
			break;
		}
	}
}

Swiat::Swiat() {
	wczytajGre();
}

void Swiat::czysc_dziennik() {
	dziennik_zdarzen = "";
}

void Swiat::dodajZdarzenie(std::string zdarzenie) {
	dziennik_zdarzen += zdarzenie;
}

void  Swiat::wypisz_dziennik() {
	std::cout << dziennik_zdarzen;
}
short  Swiat::get_and_incrementKtoryUrodzony(){
	short ktory_urodzonytmp = ktory_urodzony;
	ktory_urodzony++;
	return ktory_urodzonytmp;
}

void  Swiat::rysujSwiat() {
	system("cls");
	int liczba;
	printf("   ");
	for (int i = 0; i < M; i++) {
		liczba = (i - i % 10) / 10;
		printf("%d", liczba);
	}
	printf("                        ANTONI CZUBA 201096\n   ");
	for (int i = 0; i < M; i++)
		printf("%d", i % 10);
	printf("\n  %c%",201);
	for(int i=0;i<M;i++)
		printf("%c", 205);
	printf("%c\n", 187);
	for (int i = 0; i < N; i++) {
		if(i<10)
			printf("0%d%c", i,186);
		else
			printf("%d%c", i, 186);
		for (int j = 0; j < M; j++) {
			std::cout << plansza[i][j];
		}
		if (i == 1)
			printf("%c  Strzalka w gore - ruch w gore   Strazlka w dol - ruch w dol\n", 186);
		else if (i == 2)
			printf("%c  Strzalka w lewo - ruch w lewo   Strazlka w prawo - ruch w prawo\n", 186);
		else if (i == 3)
			printf("%c  S - umiejetnosc specjalana \n", 186);
		else if (i == 4)
			printf("%c  ESC - wyjscie z gry  W - wczytywanie  Z - zapisywanie\n", 186);
		else if (i == 5 && CzlowiekSwiat == nullptr)
			printf("%c  Zostales zabity - koniec gry \n", 186);
		else if (i == 5 && CzlowiekSwiat != nullptr)
			CzlowiekSwiat->czlowiek_status();
		else 
		printf("%c\n", 186);
	}
	printf("  %c%", 200);
	for (int i = 0; i < M; i++)
		printf("%c", 205);
	printf("%c\n", 188);

}

void Swiat::setCzlowiek(czlowiek* czlowiek) {
	CzlowiekSwiat = czlowiek;
}

czlowiek* Swiat::getCzlowiek() {
	return CzlowiekSwiat;
}

void Swiat::addOrganizm(Organizm* org) {
	Organizmy.push_back(org);
}

bool Swiat::setJesliWolnePole(short x, short y, char znak) {
	if (plansza[x][y] == '.') {
		plansza[x][y] = znak;
		return true;
	}
	else
		return false;

}

void Swiat::zakonczGreFun() {
	zakonczGre = true;
}

void Swiat::wczytajGreFun() {
	wczytajGreB = true;
}

bool Swiat::getZakonczGre() {
	return zakonczGre;
}

bool Swiat::getWczytajGre() {
	return wczytajGreB;
}

void Swiat::zmienZnakNaPolu(short x, short y, char znak) {
	plansza[x][y] = znak;
}

char Swiat::getZnakNaPolu(short x, short y) {
	return plansza[x][y];
}

void Swiat::zwolnijPole(short x, short y) {
	plansza[x][y] = '.';
}

Organizm* Swiat::findOrganizm(short x, short y, Organizm* curr_org) {
	for (int i = 0; i < Organizmy.size();i++) {
		if (Organizmy[i]->GetOx() == x && Organizmy[i]->GetOy()==y && Organizmy[i] != curr_org)
			return Organizmy[i];
	}
	return nullptr;
}


void Swiat::usunZwierze(Organizm* org) {
	short i = 0;
	while (true) {
		if (Organizmy[i] == org)
			break;
		i++;
	}
	auto it = Organizmy.begin() + i;
	Organizmy.erase(it);
}

void Swiat::wykonajTure() {
	sort_q(0, Organizmy.size()-1);
	if (iterator == -1) {
		for (iterator = Organizmy.size() - 1; iterator > -1 && zakonczGre == false && wczytajGreB == false; iterator--) {
			Organizmy[iterator]->akcja();
			Organizmy[iterator]->rysowanie();
		}
	}
	else {
		for (; iterator > -1 && zakonczGre == false && wczytajGreB == false; iterator--) {
			Organizmy[iterator]->akcja();
			Organizmy[iterator]->rysowanie();
		}
	}
}

void Swiat::zmienIteratorDodawanie(Organizm* iterator_org, Organizm* other_org) {
	if (porownajOrg(iterator_org, other_org) == first) 
		iterator++;
}

void Swiat::zmienIteratorUsuwanie(Organizm* iterator_org, Organizm* other_org) {
	if (porownajOrg(iterator_org, other_org) == first)
		iterator--;
}


int Swiat::porownajOrg(Organizm* org1, Organizm* org2) {
	if (org1->GetInicjatywa() > org2->GetInicjatywa())
		return first;
	else if (org1->GetInicjatywa() < org2->GetInicjatywa())
		return second;
	else {
		if (org1->GetWiek() < org2->GetWiek())
			return first;
		else if (org1->GetWiek() > org2->GetWiek())
			return second;
		else
			return equal;
	}
}

int Swiat::part(int st, int en) {
	Organizm* pivot_val = Organizmy[(st + en) / 2];
	int i = st;
	int j = en;

	while (true) {
		while (porownajOrg(Organizmy[i], pivot_val) == second) {
			i++;
		}
		while (porownajOrg(Organizmy[j], pivot_val) == first) {
			j--;
		}

		if (i >= j) {
			return j;
		}

		if (porownajOrg(Organizmy[i], Organizmy[j]) == equal) {
			i++;
			j--;
		}
		else {
			std::swap(Organizmy[i], Organizmy[j]);
			i++;
			j--;
		}
	}
}

void Swiat::sort_q(int st, int en) {
	if (st < en) {
		int q = part(st, en);
		sort_q(st, q);
		sort_q(q + 1, en);
	}
}