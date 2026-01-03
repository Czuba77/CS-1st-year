#pragma once
#include "Zwierze.h"
class antylopa : public Zwierze
{
public:
	antylopa(short x, short y, Swiat* swiat, short wiek);
	antylopa(short x, short y, Swiat* swiat, short wiek, short sila, short xp, short yp, short cp);
	void wykonanie_porodu(short x, short y) override;
	void wykonanie_akcji(short kierunek) override;
	int kolizja(Organizm* napotkany_org) override;
	bool znajdz_wolny(short x, short y);
};
