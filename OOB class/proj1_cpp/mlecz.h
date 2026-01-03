#pragma once
#include "Roslina.h"
class mlecz : public Roslina {
public:
	mlecz(short x, short y, Swiat* swiat, short wiek);
	void zasiej(short x, short y) override;
	void akcja() override;
};
