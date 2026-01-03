package symulator.rosliny;

import symulator.Organizm;
import symulator.Roslina;
import symulator.Swiat;

public class barszcz_sosnowskiego extends Roslina {


    public barszcz_sosnowskiego(Swiat swiat, int ox, int oy,  int wiek, int BOARD_WIDTH, int BOARD_HEIGHT) {
        super(swiat, ox, oy, wiek, BOARD_WIDTH, BOARD_HEIGHT);
        this.nazwa = "Barszcz sosnowskiego";
        this.inicjatywa = 0;
        this.sila = 10;
        this.znak = 'B';
        swiat.setJesliWolnePole(ox, oy, znak);
    }


    public void zasiej(int x, int y) {
        swiat.addOrganizm(new barszcz_sosnowskiego(swiat,x, y, swiat.get_and_incrementKtoryUrodzony(),BOARD_WIDTH,BOARD_HEIGHT));
    }

    @Override
    public int kolizja(Organizm napotkany_org) {
        return POISON;
    }

    @Override
    public void akcja() {
        swiat.zwolnijPole(polozenie[OX], polozenie[OY]);
        zabij_wszystkie_zwierzeta();
        int chance = genRand(1, EXPAND_CHANCE);
        if (chance == 1) {
            int direction = genRand(0, 3);
            wykonanie_akcji(direction);
        }
    }

    private void zabij_wszystkie_zwierzeta() {
        Organizm pobliski_organizm;
        if (polozenie[OY] != BOARD_WIDTH - 1) {
            pobliski_organizm = swiat.findOrganizm(polozenie[OX], polozenie[OY] + 1, this);
            zabij_zwierze(pobliski_organizm);
        }
        else {
            pobliski_organizm = swiat.findOrganizm(polozenie[OX], 0, this);
            zabij_zwierze(pobliski_organizm);
        }

        if (polozenie[OY] != 0) {
            pobliski_organizm = swiat.findOrganizm(polozenie[OX], polozenie[OY] - 1, this);
            zabij_zwierze(pobliski_organizm);
        }
        else {
            pobliski_organizm = swiat.findOrganizm(polozenie[OX], BOARD_WIDTH - 1, this);
            zabij_zwierze(pobliski_organizm);
        }

        if (polozenie[OX] != BOARD_HEIGHT - 1) {
            pobliski_organizm = swiat.findOrganizm(polozenie[OX] + 1, polozenie[OY], this);
            zabij_zwierze(pobliski_organizm);
        }
        else {
            pobliski_organizm = swiat.findOrganizm(0, polozenie[OY], this);
            zabij_zwierze(pobliski_organizm);
        }

        if (polozenie[OX] != 0) {
            pobliski_organizm = swiat.findOrganizm(polozenie[OX] - 1, polozenie[OY], this);
            zabij_zwierze(pobliski_organizm);
        }
        else {
            pobliski_organizm = swiat.findOrganizm(BOARD_HEIGHT - 1, polozenie[OY], this);
            zabij_zwierze(pobliski_organizm);
        }

        if (polozenie[OX] != BOARD_HEIGHT - 1 && polozenie[OY] != 0) {
            pobliski_organizm = swiat.findOrganizm(polozenie[OX] + 1, polozenie[OY] - 1, this);
            zabij_zwierze(pobliski_organizm);
        }
        else if (polozenie[OX] != BOARD_HEIGHT - 1) {
            pobliski_organizm = swiat.findOrganizm(polozenie[OX] + 1, BOARD_WIDTH - 1, this);
            zabij_zwierze(pobliski_organizm);
        }
        else if (polozenie[OY] != 0) {
            pobliski_organizm = swiat.findOrganizm(0, polozenie[OY] - 1, this);
            zabij_zwierze(pobliski_organizm);
        }
        else {
            pobliski_organizm = swiat.findOrganizm(0, BOARD_WIDTH - 1, this);
            zabij_zwierze(pobliski_organizm);
        }

        if (polozenie[OX] != 0 && polozenie[OY] != BOARD_WIDTH - 1) {
            pobliski_organizm = swiat.findOrganizm(polozenie[OX] - 1, polozenie[OY] + 1, this);
            zabij_zwierze(pobliski_organizm);
        }
        else if (polozenie[OX] != 0) {
            pobliski_organizm = swiat.findOrganizm(polozenie[OX] - 1, 0, this);
            zabij_zwierze(pobliski_organizm);
        }
        else if (polozenie[OY] != BOARD_WIDTH - 1) {
            pobliski_organizm = swiat.findOrganizm(BOARD_HEIGHT - 1, polozenie[OY] + 1, this);
            zabij_zwierze(pobliski_organizm);
        }
        else {
            pobliski_organizm = swiat.findOrganizm(BOARD_HEIGHT - 1, 0, this);
            zabij_zwierze(pobliski_organizm);
        }


        if(!swiat.getCzyHex()) {
            if (polozenie[OX] != BOARD_HEIGHT - 1 && polozenie[OY] != BOARD_WIDTH - 1) {
                pobliski_organizm = swiat.findOrganizm(polozenie[OX] + 1, polozenie[OY] + 1, this);
                zabij_zwierze(pobliski_organizm);
            } else if (polozenie[OX] != BOARD_HEIGHT - 1) {
                pobliski_organizm = swiat.findOrganizm(0, polozenie[OY] + 1, this);
                zabij_zwierze(pobliski_organizm);
            } else if (polozenie[OY] != BOARD_WIDTH - 1) {
                pobliski_organizm = swiat.findOrganizm(polozenie[OX] + 1, 0, this);
                zabij_zwierze(pobliski_organizm);
            } else {
                pobliski_organizm = swiat.findOrganizm(0, 0, this);
                zabij_zwierze(pobliski_organizm);
            }
            if (polozenie[OX] != 0 && polozenie[OY] != 0) {
                pobliski_organizm = swiat.findOrganizm(polozenie[OX] - 1, polozenie[OY] - 1, this);
                zabij_zwierze(pobliski_organizm);
            } else if (polozenie[OX] != 0) {
                pobliski_organizm = swiat.findOrganizm(polozenie[OX] - 1, BOARD_WIDTH - 1, this);
                zabij_zwierze(pobliski_organizm);
            } else if (polozenie[OY] != 0) {
                pobliski_organizm = swiat.findOrganizm(BOARD_HEIGHT - 1, polozenie[OY] - 1, this);
                zabij_zwierze(pobliski_organizm);
            } else {
                pobliski_organizm = swiat.findOrganizm(BOARD_HEIGHT - 1, BOARD_WIDTH - 1, this);
                zabij_zwierze(pobliski_organizm);
            }
        }

    }

    private void  zabij_zwierze(Organizm pobliski_organizm) {
        String zdarzenie;
        if (pobliski_organizm != null && pobliski_organizm.GetZnak() >= 'a') {
            zdarzenie = nazwa + "(" + polozenie[OX] + "," + polozenie[OY] + ") zabija " + pobliski_organizm.GetNazwa() + "("
                    + pobliski_organizm.GetOx() + "," + pobliski_organizm.GetOy() + ").\n";
            swiat.dodajZdarzenie(zdarzenie);
            swiat.zwolnijPole(pobliski_organizm.GetOx(), pobliski_organizm.GetOy());
            swiat.zmienIteratorUsuwanie(this, pobliski_organizm);
            if(pobliski_organizm.GetZnak()=='c')
                swiat.setJesliWolnePole(polozenie[OX], polozenie[OY], znak);
            pobliski_organizm.delOrganizm();
        }
    }


}

