#pragma once
#include "Organizm.h"
#include "Swiat.h"

class Zwierze : public Organizm 
{
protected:
	short poprzednie_polozenie[2];
	short cooldown_porodowy=3;

	virtual void zapiszOrganizm(std::fstream& zapis);

	virtual void akcja() override;
	virtual void wykonanie_akcji(short kierunek);

	int rozmnazanie(Organizm* drugi_organizm) override;
	bool urodz(Organizm* pobliskie_pole, Organizm* napotkany_organizm, short x, short y);
	virtual void wykonanie_porodu(short x, short y)=0;

	short const GetCooldownPorodowy();
	short const GetOy_poprz();
	short const GetOx_poprz();
	void setCooldownPorodowy();
};

