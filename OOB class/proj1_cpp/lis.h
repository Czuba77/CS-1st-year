#pragma once
#include "Zwierze.h"
#include "Organizm.h"
#include "Swiat.h"
#include "cstdlib"

class lis : public Zwierze
{
public:
	lis(short x, short y, Swiat* swiat, short wiek);
	lis(short x, short y, Swiat* swiat, short wiek, short sila, short xp, short yp, short cp);
	void wykonanie_porodu(short x, short y) override;
	void wykonanie_akcji(short direction) override;
};


