#pragma once
#include "FiguraPlaska.h"
class Kolo : public FiguraPlaska {
	double r;
protected:
	void Wypisz(std::ostream& out) const override;
public:
	Kolo(double r);
	double Getr() const;
	void Setr(double r);
	double Obwod() override;
	double Pole() override;

	~Kolo() override;
};


