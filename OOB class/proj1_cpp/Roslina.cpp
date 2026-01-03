#include "Roslina.h"
#include "Swiat.h"
#include "Zwierze.h"
#include <iostream>
#include <random>



enum KIERUNKI {
	POLNOC = 0,
	POLUDNIE = 1,
	WSCHOD = 2,
	ZACHOD = 3
};

 void Roslina::akcja(){
	 swiat->zwolnijPole(polozenie[OX], polozenie[OY]);
	 short chance = genRand(1, EXPAND_CHANCE);
	 if (chance == 1) {
		 short direction = genRand(0, 3);
		 wykonanie_akcji(direction);
	 }
};

 int Roslina::rozmnazanie(Organizm* drugi_organizm) {
	 int a;
	 std::cout << "niemozliwa sytuacja";
	 std::cin >> a;
	 return 0;
 }

 void Roslina::setCooldownPorodowy() {

 }
 short const  Roslina::GetCooldownPorodowy() {
	 return 0;
 }

 void Roslina::wykonanie_akcji(short direction) {
	 short polozenietmp[2] = { polozenie[OX] , polozenie[OY] };
	 switch (direction)
	 {
	 case POLUDNIE:
		 if (polozenie[OY] + 1 >= BOARD_WIDTH)
			 polozenietmp[OY] = 0;
		 else
			 polozenietmp[OY] += 1;
		 break;
	 case POLNOC:
		 if (polozenie[OY] - 1 < 0)
			 polozenietmp[OY] = BOARD_WIDTH - 1;
		 else
			 polozenietmp[OY] -= 1;
		 break;
	 case WSCHOD:
		 if (polozenie[OX] + 1 >= BOARD_HEIGHT)
			 polozenietmp[OX] = 0;
		 else
			 polozenietmp[OX] += 1;
		 break;
	 case ZACHOD:
		 if (polozenie[OX] - 1 < 0)
			 polozenietmp[OX] = BOARD_HEIGHT - 1;
		 else
			 polozenietmp[OX] -= 1;
		 break;
	 }
	 if (swiat->findOrganizm(polozenietmp[OX], polozenietmp[OY], this) == nullptr ) {
		 zasiej(polozenietmp[OX], polozenietmp[OY]);
	 }
 }


 short const  Roslina::GetOy_poprz() {
	 return polozenie[OY];
 }

 short const  Roslina::GetOx_poprz() {
	 return polozenie[OX];
 }