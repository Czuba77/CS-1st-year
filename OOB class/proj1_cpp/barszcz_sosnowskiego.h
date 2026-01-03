#pragma once
#include "Roslina.h"
class barszcz_sosnowskiego : public Roslina{
public:
	barszcz_sosnowskiego(short x, short y, Swiat* swiat, short wiek);
	void zasiej(short x, short y) override;
	int kolizja(Organizm* napotkany_org);
	void akcja() override;
	void zabij_wszystkie_zwierzeta();
	void  zabij_zwierze(Organizm* pobliski_organizm);
};

