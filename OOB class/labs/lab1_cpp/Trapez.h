#pragma once
#include "FiguraPlaska.h"
class Trapez : public FiguraPlaska {
private:
	double a, b, h;
protected:
	void Wypisz(std::ostream& out) const override;
public:
	Trapez(double a, double b, double h);
	double GetA() const;
	void SetA(double a);
	double GetB() const;
	void SetB(double b);
	double GetH() const;
	void SetH(double h);
	double Obwod() override;
	double Pole() override ;

	~Trapez() override;
};


