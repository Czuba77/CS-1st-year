#include "Trojkat.h"
#include <iostream>
#include <math.h>
using namespace std;
Trojkat::Trojkat(double a, double b, double c)
	: a(a), b(b), c(c)
{
	cout << "Konstruktor Trojkata(" << a << "," << b << "," << c << ")" << endl;
}

Trojkat::Trojkat(double a, double b)
	: a(a), b(b)
{
	this->c = 1;
	cout << "Konstruktor Trojkata ze stalym c (" << a << "," << b << "," << c << ")" << endl;
}

double Trojkat::GetA() const {
	return a;
}
double Trojkat::GetB() const {
	return b;
}
double Trojkat::GetC() const {
	return c;
}
void Trojkat::SetA(double a) {
	this->a = a;
}
void Trojkat::SetB(double b) {
	this->b = b;
}
void Trojkat::SetC(double c) {
	this->c = c;
}
double Trojkat::Obwod() {
	return a + b + c;
}
double Trojkat::Pole() {
	float p = (a + b + c) / 2;
	float pole = sqrt(p * (p - a) * (p - b) * (p - c));
	return pole;
}


void Trojkat::Wypisz(std::ostream& out) const {
	out << "Trojkat" << endl;
	out << "a = " << a << " b = " << b << " c = " << c << endl;
}
Trojkat::~Trojkat() {
	this->Wypisz(cout);
}
