#pragma once
#include <string>
#define OX 0
#define OY 1
#define WIN 1
#define LOOSE 2
#define SPECIAL_CASE 3
#define POISON 4

class Swiat;
 class Organizm
{
protected:
	std::string nazwa;
	short wiek;
	short sila;
	short inicjatywa;
	short polozenie[2];
	char znak;
	Swiat* swiat;

	virtual void wykonanie_akcji(short kierunek) = 0;
	virtual int rozmnazanie(Organizm* napotkany_org) = 0;

	virtual int kolizja(Organizm* napotkany_org);
public:
	virtual void zapiszOrganizm(std::fstream& zapis);
	virtual void akcja() = 0;
	void rysowanie();
	static short genRand(short min, short max);
	virtual void setCooldownPorodowy() = 0;
	virtual short const GetOy_poprz() = 0;
	virtual short const GetOx_poprz() = 0;
	virtual short const  GetCooldownPorodowy() = 0;
	Swiat* const GetWorld();
	short const GetSila();
	short const GetOy();
	short const GetOx();
	short const GetWiek();
	short const GetInicjatywa();
	std::string const GetNazwa();
	char const GetZnak();

	virtual void zwiekszSile(short sila);
	void SetOy(short polozeniex);
	void SetOx(short polozeniex);

	virtual ~Organizm();
};

