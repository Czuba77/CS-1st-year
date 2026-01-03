#pragma once
#include "Organizm.h"
#include "Zwierze.h"
#define BOARD_WIDTH swiat->getM()
#define BOARD_HEIGHT swiat->getN()
#define EXPAND_CHANCE 14
class Roslina : public Organizm
{
public:
	virtual void akcja() override;
	void wykonanie_akcji(short direction) override;
	virtual void zasiej(short x, short y) = 0;
	short const GetOy_poprz() override;
	short const GetOx_poprz() override;


	//martwe funkcje
	int rozmnazanie(Organizm* drugi_organizm) override;
	void setCooldownPorodowy() override;
	short const  GetCooldownPorodowy() override;
};

