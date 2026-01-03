#pragma once
#include "Zwierze.h"

class owca : public Zwierze
{
public:
	owca(short x, short y, Swiat* swiat, short wiek);
	owca(short x, short y, Swiat* swiat, short wiek, short sila, short xp, short yp, short cp);
	void wykonanie_porodu(short x, short y) override;
};

