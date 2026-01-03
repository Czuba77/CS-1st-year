#include <iostream>
#include "FiguraPlaska.h"
#include "Prostokat.h"
#include "Trojkat.h"
#include "Kolo.h"
#include "Trapez.h"

void wypisywaniefigur(FiguraPlaska*  f1 ) {
    std::cout << *f1;
    std::cout <<"p=" << f1->Pole() << std::endl;
    std::cout << "ob=" << f1->Obwod() << std::endl << std::endl;
}

int main() {

    FiguraPlaska* f1;
    
    FiguraPlaska* tab[5];
    tab[0] = new Prostokat(2,4);
    tab[1] = new Trojkat(2, 4,5);
    tab[2] = new Trojkat(2, 3);
    tab[3] = new Kolo(3);
    tab[4] = new Trapez(2, 4,3);

    for (int i = 0; i < 5; i++) {
        wypisywaniefigur(tab[i]);
    }

    delete tab[0];


    /*
    double p,ob;
    Prostokat p1(2,4);
    f1 = &p1;
    p = f1->Pole(); //moge uzyc wskaznika f1 za pomoca polimorfii na klasie prostokat jak i na klasie kolo
    ob = f1->Obwod(); //co swiadczy ze jest to metoda dziedziczona z abstrakcyjnej klasy FiguraPlaska wiec jest tez wirtualna pokazuje to tez overreading metod
    std::cout << p << std::endl;
    std::cout << ob << std::endl << std::endl;

    //overloading
    Trojkat* t1 = new Trojkat(3, 4, 5);
    Trojkat* t2 = new Trojkat(2, 3);
    p = t1->Pole();
    ob = t1->Obwod();
    std::cout << p << std::endl;
    std::cout << ob << std::endl;
    std::cout << "t1 " << t1->GetC() << std::endl;
    std::cout << "t2 " << t2->GetC() << std::endl << std::endl;

    Kolo k1(3);
    f1 = &k1;
    p = f1->Pole();
    ob = f1->Obwod();
    std::cout << p << std::endl;
    std::cout << ob << std::endl;
    k1.Setr(2);
    std::cout << "zmiana danych" << std::endl;
    p = f1->Pole();
    ob = f1->Obwod();
    std::cout << p << std::endl;
    std::cout << ob << std::endl << std::endl;
    
    Trapez tr1(2, 4, 3);
    f1 = &tr1;
    p = f1->Pole();
    ob = f1->Obwod();
    std::cout << p << std::endl;
    std::cout << ob << std::endl << std::endl;
    */

    return 0;
}