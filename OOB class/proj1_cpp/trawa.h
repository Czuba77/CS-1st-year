#pragma once
#include "Roslina.h"
class trawa : public Roslina{
public:
	trawa(short x, short y, Swiat* swiat, short wiek);
	void zasiej(short x, short y) override;
};


