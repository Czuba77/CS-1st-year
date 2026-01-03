#pragma once
#include "Zwierze.h"
class zolw : public Zwierze
{
public:
	zolw(short x, short y, Swiat* swiat, short wiek);
	zolw(short x, short y, Swiat* swiat, short wiek, short sila, short xp, short yp, short cp);
	void akcja() override;
	void wykonanie_porodu(short x, short y) override;
	int kolizja(Organizm* napotkany_org) override;
};
