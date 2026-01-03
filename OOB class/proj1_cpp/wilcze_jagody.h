#pragma once
#include "Roslina.h"
class wilcze_jagody : public Roslina{
public:
	wilcze_jagody(short x, short y, Swiat* swiat, short wiek);
	void zasiej(short x, short y) override;
	int kolizja(Organizm* napotkany_org);
};

