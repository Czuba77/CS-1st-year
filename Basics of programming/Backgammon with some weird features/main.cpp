#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include<stdio.h>
#include <time.h>
#include <stdlib.h>
#include"conio2.h"



#define SZER_CAL 69
#define WYS_CAL 22
#define L_KOSTEK 4
#define L_GRACZY 2
#define Oy 1
#define Ox 1
#define WCIECIE 4
#define L_poj 26
#define Ox_KOS1 80
#define Oy_KOS1 7
#define Ox_KOS2 80
#define Oy_KOS2 8
#define Ox_KOS3 80
#define Oy_KOS3 9
#define Ox_KOS4 80
#define Oy_KOS4 10
#define Ox_PKT_B 80
#define Oy_PKT_B 4
#define Ox_PKT_CZ 80
#define Oy_PKT_CZ 5
#define Ox_TURA 80
#define Oy_TURA 2
#define Ox_RUCHY 80
#define Oy_RUCHY 12
#define Ox_BICIA 80
#define Oy_BICIA 13
#define Ox_WPISZ_R 80
#define Oy_WPISZ_R 14
#define Ox_BANDA 35
#define Oy_BANDA_CZ 16
#define Oy_BANDA_BI 7
#define DLUG_T_AVA 16
#define PRZES_KUR 6
#define MR_KOS 1
#define MR_RUCH 0
#define RUCH_NR1 0
#define RUCH_NR2 1
#define RUCH_NR3 2
#define RUCH_NR4 3
#define RUCH_NR1_Z 49
#define RUCH_NR2_Z 50
#define RUCH_NR3_Z 51
#define RUCH_NR4_Z 52
#define BANDA_BI 0
#define BANDA_CZ 25
#define Ox_INST 4
#define Oy_INST 25
#define Ox_CZ_DWOR 72
#define Oy_CZ_DWOR 14
#define Ox_B_DWOR 72
#define Oy_B_DWOR 8


#define Ox_P_M 42
#define Oy_P_M 3
#define SZER_M 68
#define WYS_M 15
#define Ox_MENUT 45
#define Oy_MENUT 5
#define Ox_MENUN 45
#define Oy_MENUN 9
#define Ox_MENUC 45
#define Oy_MENUC 11
#define Ox_MENUQ 45
#define Oy_MENUQ 13


#define pozioma_kraw 205
#define pionowa_kraw 186
#define lewy_g_rog 201
#define prawy_g_rog 187
#define lewy_d_rog 200
#define prawy_d_rog 188
#define pojemnik1l 123
#define pojemnik1p 125
#define pojemnik2l 40
#define pojemnik2p 41
#define bar 179
#define pionek_b 43
#define pionek_cz 42
#define kursor_p 62
#define kursor_s 45
#define kursor_l 60
#define lewo 110
#define prawo 109
#define ruch_z 98
#define lewo1 78
#define prawo1 77
#define ruch_z1 66
#define zapis_z 115
#define wyjdz_z 113


enum kolor_e {
	CZARNY = 1,
	BIALY = 0,
	BRAK = 3
};

enum typ_pojemnika_e {
	DOM_CZ,
	DOM_B,
	ZEW,
	BANDA,
};

enum menu_e {
	NOWA_G,
	WCZYTAJ,
	HALL,
	EX,
};

enum dublet_e {
	TAK=1,
	NIE=0
};

enum dublet_drugi_wym_e {
	WARTOSC_KOS = 1,
	CZY_JEST=0
};

enum ktory_napis_e {
	BRAK_RUCHOW=1,
	BIALY_PIERWSZY=2,
	CZARNY_PIERWSZY=3,
	BRAK_K=4,
	WYGRANA = 6
};

struct pojemnik_s
{
	int liczba_pion;
	int kolor_pion;
	int typ_poj;
	int wspol[1][2]; //0 x 1 y
	int moz_ruchy[4][2]; //drugi wymiar po uzyta kostke
};



struct gracz_s {
	int pkt;
	int kolor_pion;
	int czy_pion_w_domu;
	int kostki[4];
	int dublet[2];
	int pierwszenstwo;
	int dwor;
};

struct gra_s {
	pojemnik_s pojemniki[L_poj];
	gracz_s gracze[L_GRACZY];
	int tura;
};




void zapisywanie_gry(gra_s* gra);
void usun_kursor(const int ox, const int oy, const int strona);
void komunikat(int ktorynapis);
void wyœ_bande(pojemnik_s pojemniki[L_poj]);
void wyœwietl_ture(int tura);
void kursor(pojemnik_s pojemnik[L_poj], gracz_s gracze[L_GRACZY], int tura, gra_s* gra);
void wyswietl_kostki(gracz_s gracze[L_poj], int kolor);
void przesun_kursor(int* ox, int* oy, int* strona, pojemnik_s pojemniki[L_poj], gracz_s gracze[L_GRACZY], int tura, gra_s* gra);
int zerowaniekos_dub(gracz_s gracze[L_GRACZY], int liczba_kostek, int kolor);
int czy_pionki_dwor(pojemnik_s pojemnik[L_poj], int kolor);
int r_pos_dub(pojemnik_s pojemnik[L_poj], gracz_s gracz[L_GRACZY], int tura, int ile_r_pos, int poj_start);
int menu();

void k_plk_z() {
	char a = 'b', t, c;
	FILE* odczyt;
	odczyt = fopen("ruchy.txt", "r");
	FILE* zapis;
	zapis = fopen("zapruchy.txt", "w");
	while (a != '\0') {
		c = a;
		t=fscanf(odczyt, "%c", &a);
		if (a == c)
			break;
		fprintf(zapis, "%c", a);
	}
	fclose(zapis);
	fclose(odczyt);
}

void k_plk_w() {
	char a='b',t,c;
	FILE* odczyt;
	odczyt = fopen("zapruchy.txt", "r");
	FILE* zapis;
	zapis = fopen("ruchy.txt", "w");
	while (a != '\0') {
		c = a;
		t = fscanf(odczyt, "%c", &a);
		if (a == c)
			break;
		fprintf(zapis, "%c", a);
	}
	fclose(zapis);
	fclose(odczyt);
}

void cz_plk() {
	FILE* buf;
	buf = fopen("ruchy.txt", "w");
	fclose(buf);
}

void z_r_d_p(int kolor, int p_r, int p_s) { //zapis ruchu do pliku
	char kz = 'W';
	if (kolor == CZARNY)
		kz = 'B';
	FILE* ruchy;
	ruchy = fopen("ruchy.txt", "a");
	if (p_s == 0 || p_s == 25)
		fprintf(ruchy, "%c BAR -> %d \n", kz, p_r);
	else if (p_r == 0 || p_r == 25)
		fprintf(ruchy, "%c %d -> HOME \n", kz, p_s);
	else
		fprintf(ruchy, "%c %d -> %d \n", kz, p_s, p_r);
	fclose(ruchy);
}

void wypisz_napis(int ox, int oy, const char napis[], int dlugosc) {
	for (int i = 0; i < dlugosc; i++) {
		if (napis[i] == '\0')
			break;
		gotoxy(ox + i, oy);
		putch(napis[i]);
	}
}

void czysc_napis(int ox, int oy) {
	char T[] = "                                         ";
	wypisz_napis(ox, oy, T, sizeof(T) / sizeof(char));
}

void wyp_cyf_krop(int liczba,int ox,int oy) {
	gotoxy(ox, oy);
	putch(liczba + '0');
	gotoxy(ox+1, oy);
	putch('.');
}


void t_rys_plan2() {
	char instrukcjaT[] = "Keys:";
	char instrukcjaT2[] = "M - move cursor to right N - move cursor to left B - check possible moves for choosen field";
	wypisz_napis(Ox_INST, Oy_INST, instrukcjaT, sizeof(instrukcjaT) / sizeof(char));
	wypisz_napis(Ox_INST, Oy_INST + 1, instrukcjaT2, sizeof(instrukcjaT2) / sizeof(char));

}

void t_rys_plan3() {
	char instrukcjaT3[] = "S - save your game Q - quit to menu";
	char instrukcjaT4[] = "1 - move number one 2 - move number two 3 - move number three 4 - move number four ";
	char instrukcjaT5[] = "Any Key - go back to move cursor function";
	wypisz_napis(Ox_INST, Oy_INST + 2, instrukcjaT3, sizeof(instrukcjaT3) / sizeof(char));
	wypisz_napis(Ox_INST, Oy_INST + 3, instrukcjaT4, sizeof(instrukcjaT4) / sizeof(char));
	wypisz_napis(Ox_INST, Oy_INST + 4, instrukcjaT5, sizeof(instrukcjaT5) / sizeof(char));
}

void t_rys_plan1() {
	char punkty1T[] = "White score:";
	char punkty2T[] = "Black score:";
	wypisz_napis(Ox_PKT_B, Oy_PKT_B, punkty1T, sizeof(punkty1T) / sizeof(char));
	wypisz_napis(Ox_PKT_CZ, Oy_PKT_CZ, punkty2T, sizeof(punkty2T) / sizeof(char));
	char turaT[] = "Turn: ";
	wypisz_napis(Ox_TURA, Oy_TURA, turaT, sizeof(turaT) / sizeof(char));
	t_rys_plan2();
	t_rys_plan3();
}

void rys_plan_gen12(int i, int j, pojemnik_s pojemniki[L_poj]) {
	gotoxy(j - 1, i);
	putch(bar);
	gotoxy(j + 1, i);
	putch(bar);
	if (i == 7) {
		gotoxy(j, i);
		putch('W');
	}
	if (i == 16) {
		gotoxy(j, i);
		putch('B');
	}
	if (i == 10) {
		gotoxy(j, i);
		putch('B');
	}
	if (i == 11) {
		pojemniki[0].wspol[0][0] = j;
		pojemniki[0].wspol[0][1] = i;
		gotoxy(j, i);
		putch('A');
		gotoxy(j + 36, i);
		putch('H');
		gotoxy(j + 37, i);
		putch('O');
		gotoxy(j + 38, i);
		putch('M');
		gotoxy(j + 39, i);
		putch('E');
	}
	if (i == 12) {
		gotoxy(j, i);
		putch('R');
	}
}

void rys_plan_gen13(int i, int j, int* zamienna) {
	if (*zamienna % 2 == 0) {

		gotoxy(j - 1, i);
		putch(pojemnik1l);
		gotoxy(j + 1, i);
		putch(pojemnik1p);
		*zamienna += 1;

	}
	else {
		gotoxy(j - 1, i);
		putch(pojemnik2l);
		gotoxy(j + 1, i);
		putch(pojemnik2p);
		*zamienna += 1;
	}
}

void rys_plan_gen1(int i, int* zamienna, pojemnik_s pojemniki[L_poj]) {
	int num_poj_g = 13;
	int num_poj_d = 12;
	for (int j = Ox; j <= SZER_CAL; j++) {
		if (j == Ox || j == SZER_CAL) {
			gotoxy(j, i);
			putch(pionowa_kraw);
		}
		if (j >= 5 && j % 5 == 0) {
			if (j == 35) {
				rys_plan_gen12(i, j, pojemniki);
			}
			else if (i < 8 || i>15) {
				if (i == 3) {
					pojemniki[num_poj_g].wspol[0][0] = j;
					pojemniki[num_poj_g].wspol[0][1] = i;
					num_poj_g++;
				}
				if (i == 20) {
					pojemniki[num_poj_d].wspol[0][0] = j;
					pojemniki[num_poj_d].wspol[0][1] = i;
					num_poj_d--;
				}
				rys_plan_gen13(i, j, zamienna);
			}
			if (i == 10) {
				*zamienna += 1;
			}

		}
		}
}

void rys_plan_gen2(int i) {
	for (int j = Ox; j <= SZER_CAL; j++) {
		if (j == Ox && i == 2) {
			gotoxy(j, i);
			putch(lewy_g_rog);
		}
		else if (j == Ox && i == 21) {
			gotoxy(j, i);
			putch(lewy_d_rog);
		}
		else if (j == SZER_CAL && i == 2) {
			gotoxy(j, i);
			putch(prawy_g_rog);
		}
		else if (j == SZER_CAL && i == 21) {
			gotoxy(j, i);
			putch(prawy_d_rog);
		}
		else {
			gotoxy(j, i);
			putch(pozioma_kraw);
		}
		}
}


void rys_plan_gen3(int i) {
	int liczba = 13, a=1, b=13;
	if (i == 22) {
		liczba = 12;
		a = -1;
		b = 12;
	}
	for (int j = Ox;( liczba < 25 && b == 13) || (liczba > 0 && b == 12); j = j + 5) {
		if (liczba == 19 || liczba == 6) {
			j = j + 5;
		}
		int liczbaJ = liczba % 10;
		int liczbaD = liczba / 10;
		gotoxy(WCIECIE + j, i);
		putch(liczbaD + '0');
		gotoxy(WCIECIE + j + 1, i);
		putch(liczbaJ + '0');
		liczba+=a;
		}
}

void rysuj_plansze(pojemnik_s pojemniki[L_poj]) {
#ifndef __cplusplus
	Conio2_Init();
#endif
	clrscr();
	int zamienna = 0;
	for (int i = Oy; i <= WYS_CAL; i++) {

		if (i == 1) {
			rys_plan_gen3(i);
		}
		else if (i == 2 || i == 21) {
			rys_plan_gen2(i);
		}
		else if (i > 2 && i < 21) 
			rys_plan_gen1(i,  &zamienna, pojemniki);	
		if (i == 22)
			rys_plan_gen3(i);
	}
	t_rys_plan1();
}





void sprawdz_dlugosc_liczby(int liczba, int* dlugosc) {
	if (liczba > 0) {
		*dlugosc = *dlugosc + 1;
		sprawdz_dlugosc_liczby(liczba / 10, dlugosc);
	}
}

int mnozenie_10(int ile_razy) {
	int a = 1;
	for (int i = 0; i < ile_razy - 1; i++) {
		a = a * 10;
	}
	return a;
}

void pod_wyœwietl_ture(int tura, int ox, int oy) {
	if (tura > 0) {
		int dlugosc = 0;
		sprawdz_dlugosc_liczby(tura, &dlugosc);
		gotoxy(ox, oy);
		int cyfra = ((tura - (tura % (mnozenie_10(dlugosc)))) / (mnozenie_10(dlugosc)));
		putch(cyfra + '0');
		cyfra = tura - cyfra * (mnozenie_10(dlugosc));
		ox = ox + 1;
		if (tura < 100 && tura % 10 == 0) {
			gotoxy(ox, oy);
			putch('0');
		}
		pod_wyœwietl_ture(cyfra, ox, oy);
	}
}


void inic_poj2(pojemnik_s pojemniki[L_poj]) {
	pojemniki[1].liczba_pion = 2;
	pojemniki[1].kolor_pion = BIALY;

	pojemniki[12].liczba_pion = 5;
	pojemniki[12].kolor_pion = BIALY;

	pojemniki[17].liczba_pion = 3;
	pojemniki[17].kolor_pion = BIALY;

	pojemniki[19].liczba_pion = 5;
	pojemniki[19].kolor_pion = BIALY;

	pojemniki[24].liczba_pion = 2;
	pojemniki[24].kolor_pion = CZARNY;

	pojemniki[13].liczba_pion = 5;
	pojemniki[13].kolor_pion = CZARNY;

	pojemniki[8].liczba_pion = 3;
	pojemniki[8].kolor_pion = CZARNY;

	pojemniki[6].liczba_pion = 5;
	pojemniki[6].kolor_pion = CZARNY;
}

void inic_poj1(pojemnik_s pojemniki[L_poj], int i) {
	if (i > 6 && i < 19) {
		pojemniki[i].liczba_pion = 0;
		pojemniki[i].kolor_pion = BRAK;
		pojemniki[i].typ_poj = ZEW;
	}
	else if (i > 18 && i < 25) {
		pojemniki[i].liczba_pion = 0;
		pojemniki[i].kolor_pion = BRAK;
		pojemniki[i].typ_poj = DOM_B;
	}
	else if (i == 25) {
		pojemniki[i].liczba_pion = 0;
		pojemniki[i].kolor_pion = CZARNY;
		pojemniki[i].typ_poj = BANDA;
	}
}

void inic_pojemnikow(pojemnik_s pojemniki[L_poj]) {
	for (int i = 0; i < L_poj; i++) {
		if (i == 0) {
			pojemniki[i].liczba_pion = 0;
			pojemniki[i].kolor_pion = BIALY;
			pojemniki[i].typ_poj = BANDA;
		}
		else if (i > 0 && i<7) {
			pojemniki[i].liczba_pion = 0;
			pojemniki[i].kolor_pion = BRAK;
			pojemniki[i].typ_poj = DOM_CZ;
		}
		inic_poj1(pojemniki, i);
	}	
	inic_poj2(pojemniki);
};

void czysc_pojemniki(pojemnik_s pojemniki[L_poj]) {
	for (int i=1;i<L_poj-1;i++){
		if (i < 13) {
			for (int j = 0; j < 6; j++) {
				gotoxy(pojemniki[i].wspol[0][0], pojemniki[i].wspol[0][1] - j);
				putch(' ');
				if (j == 5) {
					gotoxy(pojemniki[i].wspol[0][0]- 1, pojemniki[i].wspol[0][1] - j);
					putch(' ');
				}
			}
		}
		else {
			for (int j = 0; j < 7; j++) {
				gotoxy(pojemniki[i].wspol[0][0], pojemniki[i].wspol[0][1] + j);
				putch(' ');
				if (j == 5) {
					gotoxy(pojemniki[i].wspol[0][0] - 1, pojemniki[i].wspol[0][1] + j);
					putch(' ');
				}
			}
		}
	}
}



void rys_poj1(pojemnik_s pojemniki[L_poj], int i, int j) {
	int a = 1;
	if (i < 13)
		a = -1;
	int x = j * a;
	if (pojemniki[i].liczba_pion < 10) {
		gotoxy(pojemniki[i].wspol[0][0], pojemniki[i].wspol[0][1] + x);
		putch(pojemniki[i].liczba_pion + '0');
	}
	else {
		gotoxy(pojemniki[i].wspol[0][0], pojemniki[i].wspol[0][1] + x);
		putch(pojemniki[i].liczba_pion / 10 + '0');
		gotoxy(pojemniki[i].wspol[0][0] + 1, pojemniki[i].wspol[0][1] + x);
		putch((pojemniki[i].liczba_pion % 10) + '0');
	}
}

void rys_poj2(pojemnik_s pojemniki[L_poj], int i, int j) {
	int a = 1;
	if (i < 13)
		a = -1;
	int x = j * a;
	gotoxy(pojemniki[i].wspol[0][0], pojemniki[i].wspol[0][1] + x);
	if (pojemniki[i].kolor_pion == CZARNY)
		putch(pionek_cz);

	else if (pojemniki[i].kolor_pion == BIALY)
		putch(pionek_b);
}


void rys_pojemniki(pojemnik_s pojemniki[L_poj]) {
	czysc_pojemniki(pojemniki);
	for (int i = 1; i < L_poj-1; i++) {
		for (int j = 0; j < pojemniki[i].liczba_pion; j++) {
			if (j == 5) {
				rys_poj1(pojemniki, i, j);
				break;
			}
			rys_poj2(pojemniki, i, j);
		}
	}
}

void inic_graczy(gracz_s gracze[L_GRACZY]) {
	gracze[BIALY].czy_pion_w_domu = 0;
	gracze[BIALY].kolor_pion = BIALY;
	gracze[BIALY].pkt = 0;

	gracze[CZARNY].czy_pion_w_domu = 0;
	gracze[CZARNY].kolor_pion = CZARNY;
	gracze[CZARNY].pkt = 0;
}


int sprawdz_czy_pusty(pojemnik_s pojemnik[L_poj], int wybrany_poj) {
	if (pojemnik[wybrany_poj].liczba_pion==0)
		return 1;
	else
		return 0;
}

int sprawdz_ktora_druz(pojemnik_s pojemnik[L_poj], int wybrany_poj,int kolor) {
	if (kolor == BIALY) {
		if (pojemnik[wybrany_poj].kolor_pion == BIALY)
			return 1;
		else
			return 0;
	}
	else if (kolor == CZARNY) {
		if (pojemnik[wybrany_poj].kolor_pion == CZARNY)
			return 1;
		else
			return 0;
	}
}

int pod_sprawdz_czy_bicie(pojemnik_s pojemnik[L_poj], int wybrany_poj, int kolor) {
	if (kolor == BIALY) {
		if (pojemnik[wybrany_poj].liczba_pion == 1 && pojemnik[wybrany_poj].kolor_pion == CZARNY)
			return 1;
		else
			return 0;
	}
	else if (kolor == CZARNY) {
		if (pojemnik[wybrany_poj].liczba_pion == 1 && pojemnik[wybrany_poj].kolor_pion == BIALY)
			return 1;
		else
			return 0;
	}
	else
		return 0;
}

//sprawdza czy ruch do wskazanego pojemnika jest mozliwy
int ruch(pojemnik_s pojemnik[L_poj], gracz_s gracze[L_GRACZY], int wybrany_poj, int tura) {
	int limit1=24,limit2=1,kolor=tura%2;
	if (wybrany_poj > limit1 || wybrany_poj < limit2) {
		return 0;
	}
	else {
		if (sprawdz_czy_pusty(pojemnik, wybrany_poj)) {
			return 1;
		}
		else {
			if (sprawdz_ktora_druz(pojemnik, wybrany_poj, kolor))
				return 1;
			else
				if (pod_sprawdz_czy_bicie(pojemnik, wybrany_poj, kolor))
					return 1;
			else
				return 0;
			}
		
	}
}


void pod_tekst_wb(int pojemnik_ruch, int pojemnik_start, int dlgt2) {
	if (pojemnik_start != 0 && pojemnik_start != 25)
		pod_wyœwietl_ture(pojemnik_start, Ox_BICIA + dlgt2 + 4, Oy_BICIA + 1);
	else
		wypisz_napis(Ox_BICIA + dlgt2 + 3, Oy_BICIA + 1, "BAR", 3);
	wypisz_napis(Ox_BICIA + dlgt2 + 7, Oy_BICIA + 1, "->", 2);
	pod_wyœwietl_ture(pojemnik_ruch, Ox_BICIA + dlgt2 + 11, Oy_BICIA + 1);
}

void tekst_wyk_bic(int pojemnik_ruch, int pojemnik_start) {
	char bicieT[] = "Possibility of capturing opponent's";
	wypisz_napis(Ox_BICIA, Oy_BICIA, bicieT, sizeof(bicieT) / sizeof(char));
	char bicieT2[] = "pawn";
	wypisz_napis(Ox_BICIA, Oy_BICIA + 1, bicieT2, sizeof(bicieT2) / sizeof(char));
	wyp_cyf_krop(1, Ox_BICIA + sizeof(bicieT2) / sizeof(char), Oy_BICIA + 1);
	pod_tekst_wb(pojemnik_ruch, pojemnik_start, 4);
}


void pp_wyk_bic(gracz_s gracze[L_GRACZY], pojemnik_s pojemniki[L_poj], int kolor,int poj_s, int poj_r) {
	pojemniki[poj_s].liczba_pion--;
	pojemniki[poj_r].kolor_pion = kolor;
	if (kolor == BIALY)
		pojemniki[BANDA_CZ].liczba_pion++;
	else
		pojemniki[BANDA_BI].liczba_pion++;
	czysc_napis(Ox_BICIA, Oy_BICIA);
	czysc_napis(Ox_BICIA, Oy_BICIA + 1);
	rys_pojemniki(pojemniki); //rysuje ponowanie pojemniki
	wyswietl_kostki(gracze, kolor); //wyswietla kostki na nowo
	wyœ_bande(pojemniki);
}

void pod_wyk_bic(gracz_s gracze[L_GRACZY], pojemnik_s pojemniki[L_poj],int kolor,int ilosc_kos,int ktora_kos, int poj_s,int poj_r,int d ) {
	if (ilosc_kos == L_KOSTEK) {
		for (int i = 0; i < L_KOSTEK; i++) {  //gdy wykorzystywane sa 4 kostki
			gracze[kolor].kostki[i] = 0;
		}
	}
	else if (ilosc_kos == 3) {	//gdy wykorzystywane sa 3 kostki
		zerowaniekos_dub(gracze, 3, kolor);
	}
	else if (ilosc_kos == 2 && d == TAK) { //gdy wykorzystywane sa 2  kostki ale to dublet wiec bierze dwie ostatnie
		zerowaniekos_dub(gracze, 2, kolor);
	}
	else if (ilosc_kos == 2 && d == NIE) { //gdy wykorzystywane sa 2  kostki
		for (int i = 0; i < 2; i++) {
			gracze[kolor].kostki[i] = 0;
		}
	}
	else if (d == TAK) { //gdy wykorzystywana jest 1 kostka ale to dublet wiec bierze ostatnia dostepna 
		zerowaniekos_dub(gracze, 1, kolor);
	}
	else {
		gracze[kolor].kostki[ktora_kos] = 0; //gdy jedna kostka
	}
	z_r_d_p(kolor, poj_r, poj_s);
	pp_wyk_bic(gracze, pojemniki, kolor, poj_s, poj_r);
}

void w() {
	czysc_napis(Ox_BICIA, Oy_BICIA);
	czysc_napis(Ox_BICIA, Oy_BICIA + 1);
	menu();
}

// pokazuje czy jest bicie dla jakiegos pojemnika
int wykonanie_dostepnego_bicia(gracz_s gracze[L_GRACZY], pojemnik_s pojemniki[L_poj], int kolor, int p_r, int p_s, int ilosc_kos, int ktora_kos, gra_s* gra) {
	tekst_wyk_bic(p_r, p_s);
	char znak;
	std::cin >> znak;
	switch (znak) {
	case RUCH_NR1_Z:
		pod_wyk_bic(gracze, pojemniki, kolor, ilosc_kos, ktora_kos, p_s, p_r, gracze[kolor].dublet[CZY_JEST]);
		return 1;
	case zapis_z:
		zapisywanie_gry(gra);
		break;
	case wyjdz_z:
		w();
	default:
		wykonanie_dostepnego_bicia(gracze, pojemniki, kolor, p_r, p_s, ilosc_kos, ktora_kos, gra);
	}
}


int czy_kostki_istnieja_dub(gracz_s gracze[L_GRACZY], int liczba_kostek, int kolor) {
	int licznik = 0;
	if (liczba_kostek == 4) {
		for (int i = 0; i < L_KOSTEK; i++) {
			if (gracze[kolor].kostki[i] == 0)
				return 0;
		}
		return 1;
	}
	else if (liczba_kostek == 3) {
		for (int i = 0; i < L_KOSTEK; i++) {
			if (gracze[kolor].kostki[i] > 0)
				licznik++;
			if (licznik == 3)
				return 1;
		}

	}
	else if (liczba_kostek == 2) {
		for (int i = 0; i < L_KOSTEK; i++) {
			if (gracze[kolor].kostki[i] > 0)
				licznik++;
			if (licznik == 2)
				return 1;
		}

	}
	else{
		for (int i = 0; i < L_KOSTEK; i++) {
			if (gracze[kolor].kostki[i] > 0)
				licznik++;
			if (licznik == 1)
				return 1;
		}

	}
	return 0;
}

int zerowaniekos_dub(gracz_s gracze[L_GRACZY], int liczba_kostek, int kolor) {
	int licznik = 0;
	if (liczba_kostek == 3) {
		for (int i = 3; i > -1; i--) {
			if (gracze[kolor].kostki[i] > 0) {
				gracze[kolor].kostki[i] = 0;
				licznik++;
			}
			if (licznik == 3)
				return 1;
		}
	}
	else if (liczba_kostek == 2) {
		for (int i = 3; i > -1; i--) {
			if (gracze[kolor].kostki[i] > 0) {
				gracze[kolor].kostki[i] = 0;
				licznik++;
			}
			if (licznik == 2)
				return 1;
		}
	}
	else {
		for (int i = 3; i > -1; i--) {
			if (gracze[kolor].kostki[i] > 0) {
				gracze[kolor].kostki[i] = 0;
				licznik++;
			}
			if (licznik == 1)
				return 1;
		}
	}
}

int warun_dub_bic(pojemnik_s pojemnik[L_poj], gracz_s gracze[L_GRACZY], int kolor, int ile_kos, int w_dublet, int zmienna_znak, int tura, int poj_start ) {
	if (czy_kostki_istnieja_dub(gracze, ile_kos, kolor) && ruch(pojemnik, gracze, poj_start + ((w_dublet * ile_kos) * zmienna_znak), tura) && pod_sprawdz_czy_bicie(pojemnik, poj_start + (w_dublet * ile_kos * zmienna_znak), kolor) && pojemnik[poj_start].liczba_pion > 0)
		return 1;
	else
		return 0;
}

int warun_dwie_bic(pojemnik_s pojemnik[L_poj], gracz_s gracze[L_GRACZY], int kolor, int zmienna_znak, int tura, int poj_start, int k0, int k1) {
	if (ruch(pojemnik, gracze, poj_start + ((k0 + k1) * zmienna_znak), tura) && pod_sprawdz_czy_bicie(pojemnik, poj_start + ((k0 + k1) * zmienna_znak), kolor) && k0 > 0 && k1 > 0 && pojemnik[poj_start].liczba_pion>0)
		return 1;
	else
		return 0;
}

int warun_1_kos(pojemnik_s pojemnik[L_poj], gracz_s gracze[L_GRACZY], int kolor, int zmienna_znak, int tura, int poj_start, int kostka) {
	if (ruch(pojemnik, gracze, poj_start + (kostka * zmienna_znak), tura) && pod_sprawdz_czy_bicie(pojemnik, poj_start + (kostka * zmienna_znak), kolor) && pojemnik[poj_start].liczba_pion>0)
		return 1;
	else
		return 0;
}



int b11(pojemnik_s pojemnik[L_poj], gracz_s gracze[L_GRACZY], gra_s* gra, int kolor, int tura, int zmienna_znak, int i, int w_dublet,int ilekos) {
	if (warun_dub_bic(pojemnik, gracze, kolor, ilekos, w_dublet, zmienna_znak, tura, i))
		if (r_pos_dub(pojemnik, gracze, kolor, ilekos-1, i)) {
			wykonanie_dostepnego_bicia(gracze, pojemnik, kolor, i + ((w_dublet * ilekos) * zmienna_znak), i, ilekos, NULL, gra);
			return 1;
		}
}

int b1(pojemnik_s pojemnik[L_poj], gracz_s gracze[L_GRACZY], gra_s* gra, int kolor, int tura, int z, int i,int d) {
	if (gracze[kolor].dublet[CZY_JEST] == TAK) {
		if (b11(pojemnik, gracze, gra, kolor, tura, z, i, d, 4))
			return 1;
		if (b11(pojemnik, gracze, gra, kolor, tura, z, i, d, 3))
			return 1;
		if (b11(pojemnik, gracze, gra, kolor, tura, z, i, d, 2))
			return 1;
		if (warun_dub_bic(pojemnik, gracze, kolor, 1, d, z, tura, i)) {
			wykonanie_dostepnego_bicia(gracze, pojemnik, kolor, i + (d * z), i, 1, NULL, gra);
			return 1;
		}
	}
	return 0;
}

int b21(pojemnik_s pojemnik[L_poj], gracz_s gracze[L_GRACZY], gra_s* gra, int kolor, int tura, int zmienna_znak, int i, int k0, int k1) {
	if (ruch(pojemnik, gracze, i + (k0 * zmienna_znak), tura)) {
		if (pod_sprawdz_czy_bicie(pojemnik, i + (k0 * zmienna_znak), kolor)) {
			pojemnik[i + (k0 * zmienna_znak)].liczba_pion--;
			if (kolor == BIALY)
				pojemnik[BANDA_CZ].liczba_pion++;
			else
				pojemnik[BANDA_BI].kolor_pion++;
		}
		wykonanie_dostepnego_bicia(gracze, pojemnik, kolor, i + ((k0 + k1) * zmienna_znak), i, 2, NULL, gra);
		return 1;
	}
}

int b22(pojemnik_s pojemnik[L_poj], gracz_s gracze[L_GRACZY], gra_s* gra, int kolor, int tura, int zmienna_znak, int i, int k0, int k1) {
	if (pod_sprawdz_czy_bicie(pojemnik, i + (k1 * zmienna_znak), kolor)) {
		pojemnik[i + (k1 * zmienna_znak)].liczba_pion--;
		if (kolor == BIALY)
			pojemnik[BANDA_CZ].liczba_pion++;
		else
			pojemnik[BANDA_BI].kolor_pion++;
	}
	wykonanie_dostepnego_bicia(gracze, pojemnik, kolor, i + ((k0 + k1) * zmienna_znak), i, 2, NULL, gra);
	return 1;
}

int b2(pojemnik_s pojemnik[L_poj], gracz_s gracze[L_GRACZY], gra_s* gra, int kolor, int tura, int zmienna_znak, int i, int k0, int k1) {
	if (warun_dwie_bic(pojemnik, gracze, kolor, zmienna_znak, tura, i, k0, k1)) {
		if (b21(pojemnik, gracze, gra, kolor, tura, zmienna_znak, i, k0, k1))
			return 1;
		else if (b22(pojemnik, gracze, gra, kolor, tura, zmienna_znak, i, k0, k1))
			return 1;
	}
}



int b31(pojemnik_s pojemnik[L_poj], gracz_s gracze[L_GRACZY], gra_s* gra, int kolor, int tura, int zmienna_znak, int poj_start, int k0, int k1) {
	if (warun_1_kos(pojemnik, gracze, kolor, zmienna_znak, tura, poj_start, k0)) {
		wykonanie_dostepnego_bicia(gracze, pojemnik, kolor, poj_start + (k0 * zmienna_znak), poj_start, 1, 0, gra);
		return 1;
	}
	if (warun_1_kos(pojemnik, gracze, kolor, zmienna_znak, tura, poj_start, k1)) {
		wykonanie_dostepnego_bicia(gracze, pojemnik, kolor, poj_start + (k1 * zmienna_znak), poj_start, 1, 1, gra);
		return 1;
	}
}

int b32(pojemnik_s pojemnik[L_poj], gracz_s gracze[L_GRACZY], gra_s* gra, int kolor, int tura, int zmienna_znak, int poj_start, int k0, int k1) {
	if (warun_1_kos(pojemnik, gracze, kolor, zmienna_znak, tura, poj_start, k1)) {
		wykonanie_dostepnego_bicia(gracze, pojemnik, kolor, poj_start + (k1 * zmienna_znak), poj_start, 1, 1, gra);
		return 1;
	}
	if (warun_1_kos(pojemnik, gracze, kolor, zmienna_znak, tura, poj_start, k0)) {
		wykonanie_dostepnego_bicia(gracze, pojemnik, kolor, poj_start + (k0 * zmienna_znak), poj_start, 1, 0, gra);
		return 1;
	}
}

int bicie_z_bandy(pojemnik_s pojemnik[L_poj], gracz_s gracze[L_GRACZY], gra_s* gra, int kolor, int tura, int zmienna_znak, int poj_start) {
	int k0 = gracze[kolor].kostki[0];
	int k1 = gracze[kolor].kostki[1];
	if (k0 > k1) {
		if (b31(pojemnik, gracze, gra, kolor, tura, zmienna_znak, poj_start, k0, k1))
			return 1;
	}
	else {
		if (b32(pojemnik, gracze, gra, kolor, tura, zmienna_znak, poj_start, k0, k1))
			return 1;
	}
}

int czy_dostepne_bicie(pojemnik_s pojemnik[L_poj], gracz_s gracze[L_GRACZY], int tura, gra_s* gra) {
	int k = tura % 2;
	int z;
	int o;
	int za;
	int d = gracze[k].dublet[WARTOSC_KOS];
	int k0 = gracze[k].kostki[0];
	int k1 = gracze[k].kostki[1];
	if (k == BIALY) {
		z = 1;
		o = 23;
		za = 0;
	}
	else {
		z = -1;
		o = 2;
		za = 25;
	}
	for (int i = o;((za==25 && i<za) || (za == 0 && i > za)); i = i - z) {
		if (pojemnik[i].kolor_pion == k) {
			//sprawdza dla dubletu najpierw czy jest bicie dla 4, potem 3 kostek potem czy jest mozliwy ruch posredni
			if (b1(pojemnik, gracze, gra, k, tura, z, i, d))
				return 1;
			else {
				//sprawdza sume dwóch kostek i czy jest mozliwy posredni ruch dla najpierw mniejszej a potem wiekszej lub na odwrot
				if (b2(pojemnik, gracze, gra, k, tura, z, i, k0, k1))
					return 1;
				// sprawdza ktora jest wieksza i dla tej najpierw sprawdza czy jest bicie

				if (bicie_z_bandy(pojemnik, gracze, gra, k, tura, z, i))
					return 1;
			}
		}
	}
	return 0;
}




void d11(pojemnik_s p[L_poj], gracz_s g[L_GRACZY], int tura, int wp, int* sd, int* dw, int* l, int i) { //wp wybrany poj sd suma dlug  dw do wypisywania l licznik i nr kos
	int  z = -1, k=tura%2;
	if (tura % 2==0) z = 1;
	if (ruch(p, g, wp + (g[k].kostki[i]*z), tura) && g[k].kostki[i] > 0) {  //sprawdza czy ruch dla danej kostki jest dostepny
		*sd = *sd + 6;
		wyp_cyf_krop(*dw, Ox_RUCHY + (*sd) + DLUG_T_AVA, Oy_RUCHY);
		*dw = *dw + 1;
		pod_wyœwietl_ture(wp + (g[k].kostki[i]*z), Ox_RUCHY + (*sd) + DLUG_T_AVA + 2, Oy_RUCHY);  //wypisywanie
		p[wp].moz_ruchy[*l][MR_RUCH] = wp + (g[k].kostki[i]*z); //przypisuje ruch do mozliwych ruchow
		p[wp].moz_ruchy[*l][MR_KOS] = i; // przypisuje kostke do mozliwego ruchu 
		*l = *l + 1;
	}
}

int d12(pojemnik_s p[L_poj], gracz_s g[L_GRACZY], int tura, int wp, int* sd, int* dw, int* l, int i) {
	int  z = -1, k = tura % 2;
	if (tura % 2==0) z = 1;
	if (ruch(p, g, wp + (g[k].kostki[i]*z), tura) && g[k].kostki[i] > 0) {
		wyp_cyf_krop(*dw, Ox_RUCHY + DLUG_T_AVA + 1, Oy_RUCHY);
		*dw = *dw + 1;
		pod_wyœwietl_ture(wp + (g[k].kostki[i]*z), Ox_RUCHY + 3 + DLUG_T_AVA, Oy_RUCHY);
		p[wp].moz_ruchy[RUCH_NR1][MR_RUCH] = (wp + g[k].kostki[i]*z);
		p[wp].moz_ruchy[RUCH_NR1][MR_KOS] = i;
		return 1;
	}
	else
		return 0;
}

void drT() {
	czysc_napis(Ox_RUCHY, Oy_RUCHY);
	char ruchyT[] = "Available moves: ";
	wypisz_napis(Ox_RUCHY, Oy_RUCHY, ruchyT, sizeof(ruchyT) / sizeof(char));
}

//wyswietla dostepne ruchy dla danego pojemnika
int dostepne_ruchy(pojemnik_s p[L_poj], gracz_s g[L_GRACZY], int tura, int wp) {
	if (((p[wp].kolor_pion == BIALY && tura % 2 == 0) || (p[wp].kolor_pion == CZARNY && tura % 2 == 1)) && p[wp].liczba_pion > 0) {
		drT(); //wypisywanie tekstu
		int sd = -5; //SUMA DLUG
		int l = 0; //LICZNIK DO SPRADZANIA CZY JEST DOSTEPNY RUCH DLA JAKIEJS KOSTKI
		int dw = 1; //DO WYPISYWANIA GRAFICZNEGO
		int k = tura % 2; //KOLOR

		if (g[k].dublet[CZY_JEST] == NIE) { //sprawdza czy dublet
			for (int i = 0; i < 2; i++) {
				d11(p, g, tura, wp, &sd, &dw, &l, i);
			}
			if (l > 0) 
				return 1;
			else {
				komunikat(1); //BRAK_RUCHOW
				return 0;
			}
		}
		else {
			for (int i = 0; i < 4; i++) {
				if (d12(p, g, tura, wp, &sd, &dw, &l, i))
					return 1;
			}
			komunikat(1);
			return 0;
		}
		
	}
	else
		return 0;
}




int rysuj_kursor(const int ox,const int oy,const int strona) {
	if (strona<13) {
		gotoxy(ox, oy - PRZES_KUR);
		putchar(kursor_s);
		gotoxy(ox - 1, oy - PRZES_KUR);
		putchar(kursor_l);
		gotoxy(ox + 1, oy - PRZES_KUR);
		putchar(kursor_p );
		return ox, oy, strona;
	}
	else{
		gotoxy(ox, oy + PRZES_KUR);
		putchar(kursor_s);
		gotoxy(ox - 1, oy + PRZES_KUR);
		putchar(kursor_l);
		gotoxy(ox + 1, oy + PRZES_KUR);
		putchar(kursor_p);
		return ox, oy, strona;
	}
}

void usun_kursory(pojemnik_s pojemnik[L_poj]) {
	for (int i = 1; i < 25; i++) {
		usun_kursor(pojemnik[i].wspol[0][0], pojemnik[i].wspol[0][1], i);
	}
}

void usun_kursor(const int ox,const int oy,const int strona) {
	if (strona < 13) {
		gotoxy(ox, oy - PRZES_KUR);
		putchar(' ');
		gotoxy(ox - 1, oy - PRZES_KUR);
		putchar(' ');
		gotoxy(ox + 1, oy - PRZES_KUR);
		putchar(' ');
	}
	else {
		gotoxy(ox, oy + PRZES_KUR);
		putchar(' ');
		gotoxy(ox - 1, oy + PRZES_KUR);
		putchar(' ');
		gotoxy(ox + 1, oy + PRZES_KUR);
		putchar(' ');
	}
}


void ppwr(pojemnik_s p[L_poj], gracz_s g[L_GRACZY], int k) {
	czysc_napis(Ox_WPISZ_R, Oy_WPISZ_R); //usuwa napis wybierania ruchow
	czysc_napis(Ox_WPISZ_R, Oy_WPISZ_R - 2); //usuwa napis mozliwych ruchow
	rys_pojemniki(p); //rysuje ponowanie pojemniki
	wyswietl_kostki(g, k); //wyswietla kostki na nowo
	wyœ_bande(p);
}

void pwr(pojemnik_s p[L_poj], gracz_s g[L_GRACZY], int w_p, int t, int nr) { // pod wykonanie ruchu
	int p_r = p[w_p].moz_ruchy[nr][MR_RUCH];
	int k_r= p[w_p].moz_ruchy[nr][MR_KOS];
	int k;
	if (t % 2 == 0) {
		k = 0;  //bialy
	}
	else{
		k = 1; //czarny
	}
	if (pod_sprawdz_czy_bicie( p, p_r, k)) { //sprawdza bicie
		p[p_r].kolor_pion = k; //dodac bande
		if (k == 0) {
			p[BANDA_CZ].liczba_pion++;
		}
		else {
			p[BANDA_BI].liczba_pion++;
		}
	}
	else if (sprawdz_czy_pusty(p,p_r)) { //sprawdza czy pole jest puste
		p[p_r].liczba_pion++;
		p[p_r].kolor_pion = k;
	}
	else {
		p[p_r].liczba_pion++; //zachodzi gyd pole jest tej samej druzyny co pionek
	}

	p[w_p].liczba_pion--;
	g[k].kostki[k_r] = 0;
	z_r_d_p(t % 2, p_r, w_p);
	for (int i = 0; i < L_KOSTEK; i++) {
		p[w_p].moz_ruchy[i][MR_KOS] = 0; //zerowanie mozliwych ruchow i kostek bo beda generowane na nowo
		p[w_p].moz_ruchy[i][MR_RUCH] = 0;
	}
	ppwr(p, g, k);
}

void wrT() {
	char wykon_ruchT[] = "Choose your move";
	wypisz_napis(Ox_WPISZ_R, Oy_WPISZ_R, wykon_ruchT, sizeof(wykon_ruchT) / sizeof(char));
}

void wykonanie_ruchu(pojemnik_s p[L_poj], gracz_s g[L_GRACZY], int* wp, int t, int* ox, int* oy, gra_s* gra) {
	wrT();
	char r; //znak ruchu
	std::cin >> r; 
	switch (tolower(r)) {
	case 49: //1
		if (p[*wp].moz_ruchy[0][0] > 0) //p=pojemniki wp wybrany pojemnik  pierwsze 0 to numer ruchu a drugie 0 to wybranie miedzy ruchem a kostka- ruch
			pwr(p, g, *wp, t, 0); //g=gracze t=tura
		break;
	case 50: //2
		if(p[*wp].moz_ruchy[1][0]>0)
			pwr(p, g, *wp, t, 1);
		break;
	case 51: //3
		if (p[*wp].moz_ruchy[2][0] > 0)
			pwr(p, g, *wp, t, 2);
		break;
	case 52: //4
		if (p[*wp].moz_ruchy[3][0] > 0)
			pwr(p, g, *wp, t, 3);
		break;
	case 115: //s
		zapisywanie_gry(gra);
		break;
	case 113: //q
		menu();
	default:
		if (ox != NULL && oy != NULL)
			przesun_kursor(ox, oy, wp, p, g, t, gra);
		else
			wykonanie_ruchu(p, g, wp, t, ox, oy, gra); //gdy z bandy
		break;
	}
}


void z_r(int* ox, int* oy, int* strona, pojemnik_s pojemniki[L_poj], gracz_s gracze[L_GRACZY], int tura, gra_s* gra) {
	czysc_napis(Ox_RUCHY, Oy_RUCHY);
	if (dostepne_ruchy(pojemniki, gracze, tura, *strona)) {
		wykonanie_ruchu(pojemniki, gracze, strona, tura, ox, oy, gra);
		czysc_napis(Ox_WPISZ_R, Oy_WPISZ_R);
	}
}

void pp_k1(int* ox, int* oy, int* s, pojemnik_s p[L_poj]) {
	usun_kursor(*ox, *oy, *s);  //s= strona p=pojemniki g=gracze t=tura z=znak
	*s = 1;
	*ox = p[*s].wspol[0][0];
	*oy = p[*s].wspol[0][1];
	rysuj_kursor(*ox, *oy, *s);
}

void pp2_k1(int* ox, int* oy, int* s, pojemnik_s p[L_poj]) {
	usun_kursor(*ox, *oy, *s);  //s= strona p=pojemniki g=gracze t=tura z=znak
	*s = *s + 1;
	*ox = p[*s].wspol[0][0];
	*oy = p[*s].wspol[0][1];
	rysuj_kursor(*ox, *oy, *s);
}

void p_k1(int* ox, int* oy, int* s, pojemnik_s p[L_poj], gracz_s g[L_GRACZY], int t, gra_s* gra, char z) {
	switch (tolower(z)) {
	case lewo:
		czysc_napis(Ox_RUCHY, Oy_RUCHY);
		usun_kursor(*ox, *oy, *s);  //s= strona p=pojemniki g=gracze t=tura z=znak
		*s = *s - 1;
		*ox = p[*s].wspol[0][0];
		*oy = p[*s].wspol[0][1];
		rysuj_kursor(*ox, *oy, *s);
		break;
	case prawo:
		czysc_napis(Ox_RUCHY, Oy_RUCHY);
		if (*s + 1 == 25) {
			pp_k1(ox, oy, s, p);
			break;
		}
		else {
			pp2_k1(ox, oy, s, p);
			break;
		}
	case ruch_z:
		z_r(ox, oy, s, p, g, t, gra);
		break;
	case zapis_z:
		zapisywanie_gry(gra);
		break;
	case wyjdz_z:
		menu();
	}
}

void pp_k2(int* ox, int* oy, int* s, pojemnik_s p[L_poj]) {
	usun_kursor(*ox, *oy, *s);  //s= strona p=pojemniki g=gracze t=tura z=znak
	*s = 24;
	*ox = p[*s].wspol[0][0];
	*oy = p[*s].wspol[0][1];
	rysuj_kursor(*ox, *oy, *s);
}

void pp2_k2(int* ox, int* oy, int* s, pojemnik_s p[L_poj]) {
	usun_kursor(*ox, *oy, *s);  //s= strona p=pojemniki g=gracze t=tura z=znak
	*s = *s - 1;
	*ox = p[*s].wspol[0][0];
	*oy = p[*s].wspol[0][1];
	rysuj_kursor(*ox, *oy, *s);
}

void p_k2(int* ox, int* oy, int* s, pojemnik_s p[L_poj], gracz_s g[L_GRACZY], int t, gra_s* gra, char z) {
	switch (tolower(z)) {
	case prawo:
		czysc_napis(Ox_RUCHY, Oy_RUCHY);
		if (*s - 1 == 0) {
			pp_k2(ox, oy, s, p);  //s= strona p=pojemniki g=gracze t=tura z=znak
			break;
		}
		else {
			pp2_k2(ox, oy, s, p);
			break;
		}
	case lewo:
		czysc_napis(Ox_RUCHY, Oy_RUCHY);
		usun_kursor(*ox, *oy, *s);
		*s = *s + 1;
		*ox = p[*s].wspol[0][0];
		*oy = p[*s].wspol[0][1];
		rysuj_kursor(*ox, *oy, *s);
		break;
	case ruch_z:
		z_r(ox, oy, s, p, g, t, gra);
		break;
	case zapis_z:
		zapisywanie_gry(gra);
		break;
	case wyjdz_z:
		menu();
	}
}

void przesun_kursor(int* ox, int* oy, int* strona,pojemnik_s pojemniki[L_poj], gracz_s gracze[L_GRACZY], int tura, gra_s *gra) {
	char znak;
	std::cin>>znak;
	if (*strona > 12) {
		p_k1(ox, oy, strona, pojemniki, gracze, tura, gra, znak);
	}
	else{
		p_k2(ox, oy, strona, pojemniki, gracze, tura, gra, znak);
	}
}



void pod_wyœwietl_wyniki(gracz_s gracze[L_poj], int kolor,int ox, int oy) {
	if (gracze[kolor].pkt > 9) {
		gotoxy(ox + 13, oy);
		putch(gracze[kolor].pkt / 10 + '0');
		gotoxy(ox + 14, oy);
		putch(gracze[kolor].pkt % 10 + '0');
	}
	else {
		gotoxy(ox + 14, oy);
		putch(gracze[kolor].pkt + '0');
	}
}

void wyœwietl_wyniki(gracz_s gracze[L_poj]) {
	pod_wyœwietl_wyniki(gracze, BIALY, Ox_PKT_B, Oy_PKT_B);
	pod_wyœwietl_wyniki(gracze, CZARNY, Ox_PKT_CZ, Oy_PKT_CZ);
}

int czy_wwykorzystane_wszytskie_kostki(gracz_s gracze[L_GRACZY], int tura) {
	for (int i = 0; i < L_KOSTEK;i++) {
		if (gracze[tura % 2].kostki[i] > 0) {
			return 0;
		}
	}
	komunikat(BRAK_K);
	return 1;
}

void kursor(pojemnik_s pojemnik[L_poj], gracz_s gracze[L_GRACZY],int* tura, gra_s* gra) {
	int ox = pojemnik[13].wspol[0][0], oy = pojemnik[13].wspol[0][1];
	int strona = 13;
	while(1){
		przesun_kursor(&ox, &oy, &strona, pojemnik, gracze, *tura, gra);
		if (czy_wwykorzystane_wszytskie_kostki(gracze, *tura)==1) {
			break;
		}
	}
}

void inic_kostki(gracz_s gracze[L_poj], int kolor) {
	gracze[kolor].kostki[0] = rand() % 6 + 1;
	gracze[kolor].kostki[1] = rand() % 6 + 1;
	if (gracze[kolor].kostki[0] == gracze[kolor].kostki[1]) {
		gracze[kolor].kostki[2]= gracze[kolor].kostki[0];
		gracze[kolor].kostki[3]= gracze[kolor].kostki[0];
		gracze[kolor].dublet[CZY_JEST] = TAK;
		gracze[kolor].dublet[WARTOSC_KOS] = gracze[kolor].kostki[0];
	}
	else {
		gracze[kolor].kostki[2] = 0;
		gracze[kolor].kostki[3] = 0;
		gracze[kolor].dublet[CZY_JEST] = NIE;
		gracze[kolor].dublet[WARTOSC_KOS] = 0;
	}
}

void pod_wyswietl_kostki(gracz_s gracze[L_GRACZY], int kolor, int nr_kostki, int ox,int oy, char kostkaT[], int rozmiar) {
	if (gracze[kolor].kostki[nr_kostki] > 0) {
		wypisz_napis(ox, oy, kostkaT, rozmiar);
		gotoxy(ox + 22, oy);
		putch(gracze[kolor].kostki[nr_kostki] + '0');
	}
	else {
		czysc_napis(ox, oy);
	}
}

void wyswietl_kostki(gracz_s gracze[L_poj], int kolor) {
	char kostka1T[] = "Value of dice one:";
	pod_wyswietl_kostki(gracze, kolor, 0, Ox_KOS1, Oy_KOS1, kostka1T, sizeof(kostka1T) / sizeof(char));
	char kostka2T[] = "Value of dice two:";
	pod_wyswietl_kostki(gracze, kolor, 1, Ox_KOS2, Oy_KOS2, kostka2T,sizeof(kostka2T) / sizeof(char));
	char kostka3T[] = "Value of dice three:";
	pod_wyswietl_kostki(gracze, kolor, 2, Ox_KOS3, Oy_KOS3, kostka3T, sizeof(kostka3T) / sizeof(char));
	char kostka4T[] = "Value of dice four:";
	pod_wyswietl_kostki(gracze, kolor, 3, Ox_KOS4, Oy_KOS4, kostka4T, sizeof(kostka4T) / sizeof(char));
}



void wyœwietl_ture(gracz_s gracze[L_GRACZY], int tura) {
	if (tura % 2 == 0) {
		char turaT[] = "WHITE";
		wypisz_napis(Ox_TURA+7, Oy_TURA, turaT, sizeof(turaT) / sizeof(char));
	}
	else {
		char tura2T[] = "BLACK";
		wypisz_napis(Ox_TURA+7, Oy_TURA, tura2T, sizeof(tura2T) / sizeof(char));
	}
	
	if (gracze[BIALY].pierwszenstwo == TAK)
		tura = tura / 2+1;
	else {
		tura = tura + 1;
		tura = tura / 2;
	}

	if (tura == 0) {
		gotoxy(Ox_TURA + 14, Oy_TURA);
		putch(tura + '0');
	}
	else
		pod_wyœwietl_ture(tura,Ox_TURA+14,Oy_TURA);
}

void wyœ_bande(pojemnik_s pojemniki[L_poj]) {
	gotoxy(Ox_BANDA, Oy_BANDA_BI + 1);
	putch(pojemniki[BANDA_BI].liczba_pion + '0');
	gotoxy(Ox_BANDA, Oy_BANDA_CZ - 1);
	putch(pojemniki[BANDA_CZ].liczba_pion + '0');
}

int czy_pion_na_bandzie(pojemnik_s pojemniki[L_poj], int tura) {
	if (tura % 2 == 0) {
		if (pojemniki[BANDA_BI].liczba_pion > 0)
			return 1;
		else
			return 0;
	}
	else {
		if (pojemniki[BANDA_CZ].liczba_pion > 0)
			return 1;
		else
			return 0;
	}
}




int wychodzenie_z_bandy(pojemnik_s pojemniki[L_poj], gracz_s gracze[L_GRACZY], int kolor, int tura, gra_s* gra) {
	int zmie = -1, bffnrbnd=BANDA_CZ;
	if (kolor == BIALY) {
		zmie = 1;
		bffnrbnd = BANDA_BI;
	}
	if (bicie_z_bandy(pojemniki, gracze, gra, kolor, tura, zmie, bffnrbnd))
		return 1;
	if (dostepne_ruchy(pojemniki, gracze, tura, bffnrbnd)) {
		wykonanie_ruchu(pojemniki, gracze, &bffnrbnd, tura, NULL, NULL, gra);
		return 1;
	}
	else
		return 0;
}

void inic_dwor(gracz_s gracze[L_GRACZY]) {
	for (int i = 0; i < 2; i++) {
		gracze[i].dwor = 0;
	}
}

void rysuj_dwor(gracz_s gracze[L_GRACZY]) {
	if (gracze[BIALY].dwor != 0) {
		pod_wyœwietl_ture(gracze[BIALY].dwor, Ox_B_DWOR, Oy_B_DWOR);
	}
	else {
		gotoxy(Ox_B_DWOR, Oy_B_DWOR);
		putch('0');
	}
	if (gracze[CZARNY].dwor != 0)
		pod_wyœwietl_ture(gracze[CZARNY].dwor, Ox_CZ_DWOR, Oy_CZ_DWOR);
	else {
		gotoxy(Ox_CZ_DWOR, Oy_CZ_DWOR);
		putch('0');
	}
}

void czysc_dwor() {
	wypisz_napis(Ox_B_DWOR, Oy_B_DWOR, "   ", sizeof("   ") / sizeof(char));
	wypisz_napis(Ox_CZ_DWOR, Oy_CZ_DWOR, "   ", sizeof("   ") / sizeof(char));
}

int czy_pionki_dwor(pojemnik_s pojemnik[L_poj], int kolor) {
	int dom;
	if (kolor == BIALY)
		dom = DOM_B;
	else
		dom = DOM_CZ;
	for (int i = 0; i < 26; i++) {
		if (pojemnik[i].typ_poj != dom && pojemnik[i].kolor_pion==kolor && pojemnik[i].liczba_pion>0) {
			return 0;
		}
	}
	return 1;
}


void w_dT(int poj_srt) {
	char T[] = "Possibility of removing pawn from the";
	wypisz_napis(Ox_BICIA, Oy_BICIA, T, sizeof(T) / sizeof(char));
	char T2[] = "board";
	int d = sizeof(T2) / sizeof(char);
	wypisz_napis(Ox_BICIA, Oy_BICIA + 1, T2, d);
	wyp_cyf_krop(1, Ox_BICIA + d, Oy_BICIA + 1);
	pod_wyœwietl_ture(poj_srt, Ox_BICIA + d + 3, Oy_BICIA + 1);
	wypisz_napis(Ox_BICIA + d + 7, Oy_BICIA + 1, "->", sizeof("->") / sizeof(char));
	wypisz_napis(Ox_BICIA + d + 11, Oy_BICIA + 1, "HOME", sizeof("HOME") / sizeof(char));
}

void p_w_dom(pojemnik_s pojemnik[L_poj], gracz_s gracze[L_GRACZY], int kolor, gra_s* gra) {
	czysc_napis(Ox_BICIA, Oy_BICIA);
	czysc_napis(Ox_BICIA, Oy_BICIA + 1);
	rys_pojemniki(pojemnik); //rysuje ponowanie pojemniki
	wyswietl_kostki(gracze, kolor); //wyswietla kostki na nowo
	rysuj_dwor(gracze);
}

void wykonanie_dom(pojemnik_s pojemnik[L_poj], gracz_s gracze[L_GRACZY], int kolor, int poj_srt, int wyb_kos, gra_s* gra) {
	w_dT(poj_srt);
	int pr = 25;
	if (kolor) pr = 0;
	char znak;
	std::cin >> znak;
	switch (znak) {
	case RUCH_NR1_Z:
		gracze[kolor].dwor++;
		pojemnik[poj_srt].liczba_pion--;
		z_r_d_p(kolor, pr, poj_srt);
		if (wyb_kos >= 0)
			gracze[kolor].kostki[wyb_kos] = 0;
		else if (wyb_kos == -1)
			zerowaniekos_dub(gracze, 1, kolor);
		else if(wyb_kos==-2) 
			zerowaniekos_dub(gracze, 2, kolor);
		else if (wyb_kos == -3) 
			zerowaniekos_dub(gracze, 3, kolor);
		else if (wyb_kos == -4) 
			zerowaniekos_dub(gracze, 4, kolor);
	case zapis_z:
		zapisywanie_gry(gra);
		break;
	case wyjdz_z:
		menu();
	}
	p_w_dom(pojemnik, gracze, kolor, gra);
}


int cdwm_kos(pojemnik_s pojemnik[L_poj], gracz_s gracze[L_GRACZY], int kolor, int kos, gra_s* gra) { //sprawdza dostepnosc ruchu dana kostka do domu
	int iter, odliczanie, zakres;
	if (kolor == BIALY) {
		iter = 1;
		odliczanie = 19;
		zakres = 25;
	}
	else {
		iter = -1;
		odliczanie = 6;
		zakres = 0;
	}
	for (int i = odliczanie; ((zakres == 25 && i < zakres) || (zakres == 0 && i > zakres)); i=i+iter) {
		if (((gracze[kolor].kostki[kos] + i >= zakres && zakres==25) || ((gracze[kolor].kostki[kos] * iter) + i <= zakres && zakres==0)) && sprawdz_czy_pusty(pojemnik, i) == 0 && sprawdz_ktora_druz(pojemnik, i, kolor)) {
			wykonanie_dom(pojemnik, gracze, kolor, i, kos, gra);
			return 1;
		}
	}
	return 0;
}

int cdwm_kos2(pojemnik_s p[L_poj], gracz_s g[L_GRACZY], int kolor, int k1, int k2, gra_s* gra) { //wariant dla dwoch kostek
		int iter, o, z, s= g[kolor].kostki[k1] + g[kolor].kostki[k2];
	if (kolor == BIALY) {
		iter = 1;
		o = 19; //odliczanie od ktorego momentu
		z = 25; // zakres do ktorego momentu
	}
	else {
		iter = -1;
		o = 6;
		z = 0;
	}
	for (int i = o; ((z == 25 && i < z) || (z == 0 && i > z)); i = i + iter) {
		if (((s + i >= z && z == 25) || ((s * iter) + i <= z && z == 0)) && sprawdz_czy_pusty(p, i) == 0 && sprawdz_ktora_druz(p, i, kolor) && (ruch(p, g, i + (g[kolor].kostki[k1] * iter), kolor) || ruch(p, g, i + (g[kolor].kostki[k2] * iter), kolor))){
			wykonanie_dom(p, g, kolor, i, -2, gra);
			return 1;
		}
	}
	return 0;
}

int cdwm_kosdub(pojemnik_s pojemnik[L_poj], gracz_s gracze[L_GRACZY], int kolor, int ilosc_kos, gra_s* gra) { //wariant dla dwoch kostek dub
	int iter, odliczanie, zakres, sumakos = (gracze[kolor].dublet[WARTOSC_KOS]*ilosc_kos);
	if (kolor == BIALY) {
		iter = 1;
		odliczanie = 19;
		zakres = 25;
	}
	else {
		iter = -1;
		odliczanie = 6;
		zakres = 0;
	}
	for (int i = odliczanie; ((zakres == 25 && i < zakres) || (zakres == 0 && i > zakres)); i = i + iter) {
		if (((sumakos + i >= zakres && zakres == 25) || ((sumakos * iter) + i <= zakres && zakres == 0)) && sprawdz_czy_pusty(pojemnik, i) == 0 && sprawdz_ktora_druz(pojemnik, i, kolor) && r_pos_dub(pojemnik,gracze,kolor,(ilosc_kos-1),i) ) {
			wykonanie_dom(pojemnik, gracze, kolor, i, -ilosc_kos, gra);
			return 1;
		}
	}
	return 0;
}




int czy_dostepne_w_dom(pojemnik_s p[L_poj], gracz_s g[L_GRACZY], int k, gra_s* gr) {
	if (g[k].dublet[CZY_JEST] == NIE) {
		if (g[k].kostki[0] > g[k].kostki[1]) { //gdy 1 kostka wieksza
			if (cdwm_kos(p, g, k, 0, gr))
				return 1;
			else if (cdwm_kos(p, g, k, 1, gr))
				return 1;
		}
		else { //gdy 2 kostka wieksza
			if (cdwm_kos(p, g, k, 1, gr))
				return 1;
			else if (cdwm_kos(p, g, k, 0, gr))
				return 1;
		}
		if (cdwm_kos2(p, g, k, 0, 1, gr))
			return 1;
		else
			return 0;
	}
	else {
		if (czy_kostki_istnieja_dub(g, 1, k) && cdwm_kosdub(p, g, k, 1, gr))
			return 1;
		if (czy_kostki_istnieja_dub(g, 2, k) && cdwm_kosdub(p, g, k, 2, gr))
			return 1;
		if (czy_kostki_istnieja_dub(g, 3, k) && cdwm_kosdub(p, g, k, 3, gr))
			return 1;
		if (czy_kostki_istnieja_dub(g, 4, k) && cdwm_kosdub(p, g, k, 4, gr))
			return 1;
		else
			return 0;
	}
}

int r_pos_dub(pojemnik_s pojemnik[L_poj], gracz_s gracz[L_GRACZY], int tura, int ile_r_pos, int poj_start) {
	int zmienna = 1;
	if (tura % 2 == CZARNY)
		zmienna = -1;

	for (int i = 1; i <= ile_r_pos; i++) {
		if (ruch(pojemnik, gracz, poj_start + ((i * gracz[tura % 2].dublet[WARTOSC_KOS]) * zmienna), tura) == 0)
			return 0;
	}
	for (int i = 1; i <= ile_r_pos; i++) {
		if (pod_sprawdz_czy_bicie(pojemnik, poj_start + ((i * gracz[tura % 2].dublet[WARTOSC_KOS]) * zmienna), tura) == 1) {
			pojemnik[poj_start + (i * gracz[tura % 2].dublet[WARTOSC_KOS] * zmienna)].liczba_pion--;
			if (tura % 2 == BIALY)
				pojemnik[BANDA_CZ].liczba_pion++;
			else
				pojemnik[BANDA_BI].liczba_pion++;
		}
	}
	return 1;
} //sprawdza czy ruchy posrednie sa wykonalne i jesli sa dokonjuje bic

void p_ko() {
	czysc_napis(Ox_RUCHY, Oy_RUCHY);
	czysc_napis(Ox_RUCHY, Oy_RUCHY + 1);
}

void komunikat(int n) { //n ktory napis
	char T1[] = "No available moves";
	char T2[] = "Black starts";
	char T3[] = "White starts";
	char T4[] = "No more dices to use";
	char T5[] = "Click anything to continue";
	char T6[] = "White wins";
	char T7[] = "Black wins";
	if (n == 1) //BRAK_RUCHOW
		wypisz_napis(80, 12, T1, 19); //80 ox_ruchy 12 oy ruchy
	else if (n == 3) //CZARNY PIERWSZY
		wypisz_napis(80, 12, T2, 13);
	else if (n == 2) //BIALY PIERWSZY
		wypisz_napis(80, 12, T3, 13);
	else if (n == 6) //WYGRANA
		wypisz_napis(80, 12, T6, 11);
	else if (n == 6+1) // WYGRANA DLA DRUGIEGO KOLORU
		wypisz_napis(80, 12, T7, 11);
	else
		wypisz_napis(80, 12, T4, 21);

	wypisz_napis(80, 12 + 1, T5, 27);

	char z;
	std::cin >> z;
	switch (z) {
	default:
		p_ko();
		break;
	}
}

void ktoPierwszy(gracz_s gracze[L_GRACZY], int* tura) {
	inic_kostki(gracze, *tura % 2);
	*tura = *tura + 1;
	inic_kostki(gracze, *tura % 2);
	int sumakostekB = 0, sumakostekCZ = 0;
	for (int i = 0; i < L_KOSTEK; i++) {
		sumakostekB += gracze[BIALY].kostki[i];
		sumakostekCZ += gracze[CZARNY].kostki[i];
	}

	if (sumakostekB == sumakostekCZ) {
		ktoPierwszy(gracze, tura);
	}
	else if (sumakostekB > sumakostekCZ) {
		komunikat(BIALY_PIERWSZY);
		*tura = 0;
		gracze[BIALY].pierwszenstwo = TAK;
		gracze[CZARNY].pierwszenstwo = NIE;
	}
	else {
		komunikat(CZARNY_PIERWSZY);
		*tura = 1;
		gracze[BIALY].pierwszenstwo = NIE;
		gracze[CZARNY].pierwszenstwo = TAK;
	}
}

int br_r(pojemnik_s p[L_poj], gracz_s g[L_GRACZY], int k, int t) {
	int zw = 0;
	for (int i = 0; i < 26; i++) {
		if (((p[i].kolor_pion == BIALY && k==0) || (p[i].kolor_pion == CZARNY && k == 1)) && p[i].liczba_pion > 0) {
			drT(); //wypisywanie tekstu
			int sd = -5; //SUMA DLUG
			int l = 0; //LICZNIK DO SPRADZANIA CZY JEST DOSTEPNY RUCH DLA JAKIEJS KOSTKI
			int dw = 1; //DO WYPISYWANIA GRAFICZNEGO
			if (g[k].dublet[CZY_JEST] == NIE) { //sprawdza czy dublet
				for (int j = 0; j < 2; j++) {
					d11(p, g, t, i, &sd, &dw, &l, j);
				}
				if (l > 0)
					zw++;
			}
			else {
				for (int j = 0; j < 4; j++) {
					if (d12(p, g, t, i, &sd, &dw, &l, j))
						zw++;
				}
			}
		}
	}
	czysc_napis(Ox_RUCHY, Oy_RUCHY);
	if (zw > 0)
		return 1;
	else
		return 0;
}

int czy_wygrana(gracz_s gracze[L_GRACZY], int tura) {
	int kolor = CZARNY;
	if (tura % 2 == BIALY) {
		kolor = BIALY;
	}
	if (gracze[kolor].dwor == 15) {
		gracze[kolor].pkt++;
		if (gracze[(kolor + 1) % 2].dwor == 0){
			gracze[kolor].pkt++;
		}
		komunikat(WYGRANA + kolor);
		return 1;
	}
	return 0;
}

void zapisywanie_gry(gra_s* gra) {
	k_plk_z();
	FILE* zapis;
	zapis = fopen("zapis.txt","w");
	fwrite( (const void*) gra, sizeof(gra_s), 1, zapis);
	fclose(zapis);
}

void n_g4(gra_s* gra, int* p) {
	usun_kursory(gra->pojemniki);
	*p = 0;
	inic_kostki(gra->gracze, gra->tura % 2);
	wyswietl_kostki(gra->gracze, gra->tura % 2);
	wyœwietl_ture(gra->gracze, gra->tura);
}

void n_g5_ban(gra_s* gra, int* p) {
	while (czy_pion_na_bandzie(gra->pojemniki, gra->tura)) {
		if (wychodzenie_z_bandy(gra->pojemniki, gra->gracze, gra->tura % 2, gra->tura, gra) == 0) {
			*p = 1;
			gra->tura++;
			break;
		}
		wyœ_bande(gra->pojemniki);
	}
}

void n_g6_dwor(gra_s* gra, int* p) {
	while (czy_dostepne_w_dom(gra->pojemniki, gra->gracze, gra->tura % 2, gra)) {
		if (czy_wygrana(gra->gracze, gra->tura)) {
			*p = 2;
			break;
		}
		if (czy_wwykorzystane_wszytskie_kostki(gra->gracze, gra->tura) == 1) {
			gra->tura++;
			*p = 1;
			break;
		}
	}
}

void n_g7_bicie(gra_s* gra, int* p) {
	while (czy_dostepne_bicie(gra->pojemniki, gra->gracze, gra->tura, gra)) {
		if (czy_wwykorzystane_wszytskie_kostki(gra->gracze, gra->tura) == 1) {
			gra->tura++;
			*p = 1;
			break;
		}
	}
}

void n_g3(gra_s* gra, int* p) {
	while (1) {
		n_g4(gra,p);


		if (czy_pion_na_bandzie(gra->pojemniki, gra->tura)) {
			n_g5_ban(gra, p);
			if (*p == 1)
				continue;
		}
		if (czy_wwykorzystane_wszytskie_kostki(gra->gracze, gra->tura) == 1) {
			gra->tura++;
			continue;
		}



		n_g7_bicie(gra, p);
		if (*p == 1)
			continue;



		if (czy_pionki_dwor(gra->pojemniki, gra->tura % 2)) {
			n_g6_dwor(gra, p);
		}

		if (*p==2) {
			break;
		}
		if (*p == 1)
			continue;

		if (br_r(gra->pojemniki, gra->gracze, gra->tura % 2, gra->tura) == 0) {
			gra->tura++;
			komunikat(1);
			continue;
		}

		kursor(gra->pojemniki, gra->gracze, &gra->tura, gra);
		gra->tura++;
	}
}

void n_g2(gra_s* gra) {
	inic_pojemnikow(gra->pojemniki);
	rys_pojemniki(gra->pojemniki);
	inic_dwor(gra->gracze);
	czysc_dwor();
	rysuj_dwor(gra->gracze);
	wyœwietl_wyniki(gra->gracze);
	wyœ_bande(gra->pojemniki);
}

void n_g1(gra_s* gra, int *p) {
	while (1) {
		n_g2(gra);
		ktoPierwszy(gra->gracze, &gra->tura);
		n_g3(gra, p);
	}
}


int nowa_gra() {
	srand(time(0));
	cz_plk();
	gra_s gra;
	gra.tura = 0;
	int p = 0;
	rysuj_plansze(gra.pojemniki);
	inic_graczy(gra.gracze);
	n_g1(&gra, &p);
	return 0;
}

void w_g4(gra_s* gra, int* p) {
	usun_kursory(gra->pojemniki);
	*p = 0;
	wyswietl_kostki(gra->gracze, gra->tura % 2);
	wyœwietl_ture(gra->gracze, gra->tura);
}

void w_g3(gra_s* gra, int* p, int a) {
	while (1) {
		if (a == 0) {
			w_g4(gra, p);
			a++;
		}
		else
			n_g4(gra, p);


		if (czy_pion_na_bandzie(gra->pojemniki, gra->tura)) {
			n_g5_ban(gra, p);
			if (*p == 1)
				continue;
		}
		if (czy_wwykorzystane_wszytskie_kostki(gra->gracze, gra->tura) == 1) {
			gra->tura++;
			continue;
		}



		n_g7_bicie(gra, p);
		if (*p == 1)
			continue;



		if (czy_pionki_dwor(gra->pojemniki, gra->tura % 2)) {
			n_g6_dwor(gra, p);
		}

		if (*p == 2) {
			break;
		}

		if (*p == 1)
			continue;

		if (br_r(gra->pojemniki, gra->gracze, gra->tura % 2, gra->tura) == 0) {
			gra->tura++;
			komunikat(1);
			continue;
		}

		kursor(gra->pojemniki, gra->gracze, &gra->tura, gra);
		gra->tura++;
	}
}

void w_g2(gra_s* gra) {
	rys_pojemniki(gra->pojemniki);
	rysuj_dwor(gra->gracze);
	wyœwietl_wyniki(gra->gracze);
	wyœ_bande(gra->pojemniki);
}

void w_gr1(gra_s* gra, int* p, int a) {
	int b=0;
	while (1) {
		if (a == 0) {
			w_g2(gra);
			w_g3(gra, p,b);
			b++;
			a++;
		}
		else {
			n_g2(gra);
			ktoPierwszy(gra->gracze, &gra->tura);
			n_g3(gra, p);
		}
	}
}

void wczytana_gra() {
	srand(time(0));
	k_plk_w();
	FILE* zapis;
	zapis = fopen("zapis.txt", "r");
	gra_s gra;
	fread((void*)&gra, sizeof(gra_s), 1, zapis);
	int p = 0;
	int a=0;
	rysuj_plansze(gra.pojemniki);
	w_gr1(&gra, &p, a);
}

void pTm() {
	char tytulT[] = "B A C K G A M M O N";
	char nowagT[] = "1. New game";
	char kontT[] = "2. Continue";
	char wyjdzT[] = "3. Quit game";
	wypisz_napis(Ox_MENUT, Oy_MENUT, tytulT, sizeof(tytulT) / sizeof(char));
	wypisz_napis(Ox_MENUN, Oy_MENUN, nowagT, sizeof(nowagT) / sizeof(char));
	wypisz_napis(Ox_MENUC, Oy_MENUC, kontT, sizeof(kontT) / sizeof(char));
	wypisz_napis(Ox_MENUQ, Oy_MENUQ, wyjdzT, sizeof(wyjdzT) / sizeof(char));
}

void tekstmenu() {
	settitle("Antoni Czuba 201096");
	_setcursortype(_NOCURSOR);
	textbackground(BLACK);
	clrscr();
	textcolor(7);  
	for (int i = Oy_P_M; i <= WYS_M; i++) {
		for (int j = Ox_P_M; j <= SZER_M; j++) {
			if (j == Ox_P_M && i == Oy_P_M) {
				gotoxy(j, i);
				putch(201); //lewy_g_rog
			}
			else if (j == Ox_P_M && i == WYS_M) {
				gotoxy(j, i);
				putch(200); //lewy_d_rog
			}
			else if (j == SZER_M && i == Oy_P_M) {
				gotoxy(j, i);
				putch(187); //prawy_g_rog
			}
			else if (j == SZER_M && i == WYS_M) {
				gotoxy(j, i);
				putch(188); //prawy_d_rog
			}
			else if(i==Oy_P_M || i==WYS_M || (i == 7 && j != Ox_P_M && j != SZER_M)) {
				gotoxy(j, i);
				putch(205); //pozioma_kraw
			}
			else if (j == Ox_P_M || j == SZER_M) {
				gotoxy(j, i);
				putch(186); //pionowa_kraw
			}
		}
	}
	pTm();
}



int main() {
	static int a = 0;
	if (a == 0) {
		a++;
		menu();
	}
	return 0;
}

int menu() {
	tekstmenu();
	char znak;
	std::cin >> znak;
	switch (znak) {
	case RUCH_NR1_Z:
		nowa_gra();
	case RUCH_NR2_Z:
		wczytana_gra();
	case RUCH_NR3_Z:
		exit(main());
	}
}
