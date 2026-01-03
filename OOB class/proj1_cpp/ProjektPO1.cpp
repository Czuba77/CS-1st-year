#include <iostream>
#include "Swiat.h"
#include "Organizm.h"
#include "Zwierze.h"
#include "owca.h"
#include "wilk.h"
#include "antylopa.h"
#include "zolw.h"
#include "lis.h"
#include "czlowiek.h"

int main()
{
    int N, M;
    std::cout << "Podaj rozmiary planszy.\n";
    std::cin >> N;
    std::cin >> M;
    Swiat* swiat = new Swiat(N,M);

    swiat->rysujSwiat();
    while (!swiat->getZakonczGre()) {
        swiat->wykonajTure();
        if (swiat->getWczytajGre()) {
            delete(swiat);
            swiat = new Swiat();
        }
    }
    if (swiat->getCzlowiek() == nullptr) {
        swiat->rysujSwiat();
        swiat->wypisz_dziennik();
    }
    return 0;
}

