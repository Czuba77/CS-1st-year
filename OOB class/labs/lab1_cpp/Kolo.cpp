#include "Kolo.h"
#include <iostream>
#include <math.h>
#define M_PI       3.14159265358979323846

using namespace std;
Kolo::Kolo(double r)
	: r(r)
{
	cout << "Konstruktor Kola(" << r << ")" << endl;
}
double Kolo::Getr() const {
	return r;
}

void Kolo::Setr(double r) {
	this->r = r;
}

double Kolo::Obwod() {
	return 2* M_PI *r;
}
double Kolo::Pole() {
	return r*r* M_PI;
}
void Kolo::Wypisz(std::ostream& out) const {
	out << "Kolo" << endl;
	out << "r=" << r << endl;
}
Kolo::~Kolo() {
	this->Wypisz(cout);
}
