#pragma once
#include "Zwierze.h"
#include "Organizm.h"

class czlowiek : public Zwierze
{
	short sila_flat, cooldown_ult;
public:
	czlowiek(short x, short y, Swiat* swiat, short wiek);
	czlowiek(short x, short y, Swiat* swiat, short wiek, short sila, short xp, short yp, short cp, short sila_flat, short cooldown_ult);
	void wykonanie_porodu(short x, short y) override;
	void czlowiek_status();
	void akcja() override;
	void zwiekszSile(short oIle) override;
	void zapiszOrganizm(std::fstream& zapis) override;
	~czlowiek() override;
};

