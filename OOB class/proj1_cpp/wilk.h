#include "Zwierze.h"

#pragma once
class wilk : public Zwierze
{
public:
	wilk(short x, short y, Swiat* swiat, short wiek);
	wilk(short x, short y, Swiat* swiat, short wiek, short sila, short xp, short yp, short cp);
	void wykonanie_porodu(short x, short y) override;
};

