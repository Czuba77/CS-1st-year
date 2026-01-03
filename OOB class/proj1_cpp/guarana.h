#pragma once
#include "Roslina.h"
class guarana : public Roslina{
public:
	guarana(short x, short y, Swiat* swiat, short wiek);
	void zasiej(short x, short y) override;
	int kolizja(Organizm* napotkany_org) override;
};

