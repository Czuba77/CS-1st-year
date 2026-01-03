#pragma once
#include <vector>
#include <fcntl.h>
#include <io.h>
#include "Organizm.h"




#define BOARD_WIDTH swiat->getM()
#define BOARD_HEIGHT swiat->getN()
#define PUSTE '.'

class Orgaznim;
class czlowiek;
class Swiat
{
	char orglist[15] = { 'a','l','o','w','z','B','G','M','T','W','a','l','o','w','z' };
	bool zakonczGre = false;
	bool wczytajGreB = false;
	short N, M;
	short iterator=-1;
	short ktory_urodzony;
	char** plansza;

	std::string dziennik_zdarzen;
	std::vector <Organizm*> Organizmy;
	czlowiek* CzlowiekSwiat;

	void sort_q(int st, int en);
	int part(int st, int en);
	int porownajOrg(Organizm* org1, Organizm* org2);
public:
	Swiat(int N, int M);
	Swiat();

	void wczytajGre();
	void zapiszGre();
	void zakonczGreFun();
	void wczytajGreFun();

	short getN();
	short getM();
	bool getZakonczGre();
	bool getWczytajGre();
	czlowiek* getCzlowiek();

	void zwolnijPole(short x, short y);
	char getZnakNaPolu(short x, short y);
	bool setJesliWolnePole(short x, short y, char znak);
	void zmienZnakNaPolu(short x, short y, char znak);

	short get_and_incrementKtoryUrodzony();
	void zmienIteratorDodawanie(Organizm* iterator_org, Organizm* other_org);
	void zmienIteratorUsuwanie(Organizm* iterator_org, Organizm* other_org);

	Organizm* findOrganizm(short x, short y, Organizm* curr_org);
	void addOrganizm(Organizm* org);
	void wykonajTure();
	void usunZwierze(Organizm* org);
	void setCzlowiek(czlowiek* czlowiek);
	void rysujSwiat();

	void czysc_dziennik();
	void dodajZdarzenie(std::string zdarzenie);
	void wypisz_dziennik();

};

