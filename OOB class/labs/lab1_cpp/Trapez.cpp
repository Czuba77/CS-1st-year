#include "Trapez.h"
#include <iostream>
#include <math.h>
using namespace std;
Trapez::Trapez(double a, double b, double h)
	: a(a), b(b), h(h)
{
	cout << "Konstruktor Trapezu(" << a << "," << b << "," << h << ")" << endl;
}
double Trapez::GetA() const {
	return a;
}
double Trapez::GetB() const {
	return b;
}
double Trapez::GetH() const {
	return h;
}
void Trapez::SetA(double a) {
	this->a = a;
}
void Trapez::SetB(double b) {
	this->b = b;
}
void Trapez::SetH(double h) {
	this->h = h;
}
double Trapez::Obwod() {
	double c = (sqrt((h * h) + ((b - a) / 2)));
	return a + b + c * 2;
}
double Trapez::Pole() {
	return (a + b)*h/2;
}
void Trapez::Wypisz(std::ostream& out) const {
	out << "Trapez" << endl;
	out << "Bok a = " << a << ", b =" << b << ", h =" << h <<endl;
}
Trapez::~Trapez() {
	this->Wypisz(cout);
}
