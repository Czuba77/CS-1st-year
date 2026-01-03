package symulator.zwierzeta;

import symulator.Organizm;
import symulator.Swiat;
import symulator.Zwierze;

public class antylopa extends Zwierze {

    public antylopa(Swiat swiat, int ox, int oy, int wiek, int BOARD_WIDTH, int BOARD_HEIGHT) {
        super(swiat, ox, oy,ox, oy, wiek, BOARD_WIDTH, BOARD_HEIGHT);

        this.nazwa = "Antylopa";
        this.inicjatywa = 4;
        this.sila = 4;
        this.znak = 'a';
        swiat.setJesliWolnePole(ox, oy, znak);
    }

    @Override
    protected void wykonanie_porodu(int x, int y) {
        swiat.addOrganizm(new antylopa( swiat,x, y, swiat.get_and_incrementKtoryUrodzony(),this.BOARD_WIDTH,this.BOARD_HEIGHT));
    }



    public antylopa(Swiat swiat,int x, int y,  int wiek, int sila, int xp, int yp, int cp, int BOARD_WIDTH, int BOARD_HEIGHT) {
        super(swiat, x, y,xp,yp, wiek, BOARD_WIDTH, BOARD_HEIGHT);
        this.nazwa = "Antylopa";
        this.inicjatywa = 4;
        this.sila = sila;
        this.znak = 'a';
        this.cooldown_porodowy = cp;
    }



    @Override
    public int kolizja(Organizm napotkany_org) {
        int if_flew = genRand(0,1);
        if (if_flew==1) {
            if (znajdz_wolny(polozenie[OX], polozenie[OY])) {
                napotkany_org.GetWorld().zmienZnakNaPolu(napotkany_org.GetOx(), napotkany_org.GetOy(), napotkany_org.GetZnak());
                String zdarzenie = "Na polu (" + polozenie[OX] + "," + polozenie[OY] + "), doszlo do kolizji " +
                        this.nazwa + " uciekla przed " + napotkany_org.GetNazwa() + ".\n";
                swiat.dodajZdarzenie(zdarzenie);
                return SPECIAL_CASE;
            }
            else
                return WIN;
        }
        else if (this.sila <= napotkany_org.GetSila())
        return WIN;
	else
        return LOOSE;
    }

    @Override
    public void wykonanie_akcji(int kierunek) {
        if(swiat.getCzyHex()){
            switch (kierunek) {
                case LEWOD:
                    if (polozenie[OY] + 2 >= BOARD_WIDTH)
                        polozenie[OY] = 0;
                    else
                        polozenie[OY] += 2;
                    break;
                case PRAWOG:
                    if (polozenie[OY] - 2 < 0)
                        polozenie[OY] = BOARD_WIDTH - 2;
                    else
                        polozenie[OY] -= 2;
                    break;
                case PRAWOD:
                    if (polozenie[OX] + 2 >= BOARD_HEIGHT)
                        polozenie[OX] = 0;
                    else
                        polozenie[OX] += 2;
                    break;
                case LEWOG:
                    if (polozenie[OX] - 2 < 0)
                        polozenie[OX] = BOARD_HEIGHT - 2;
                    else
                        polozenie[OX] -= 2;
                    break;
                case LEWO:
                    if (polozenie[OX] + 2 >= BOARD_HEIGHT)
                        polozenie[OX] = 0;
                    else
                        polozenie[OX] += 2;
                    if (polozenie[OY] + 2 >= BOARD_WIDTH)
                        polozenie[OY] = 0;
                    else
                        polozenie[OY] += 2;
                    break;
                case PRAWO:
                    if (polozenie[OX] - 2 < 0) {
                        polozenie[OX] = BOARD_HEIGHT - 2;
                    } else
                        polozenie[OX] -= 2;
                    if (polozenie[OY] - 2 < 0)
                        polozenie[OY] = BOARD_WIDTH - 2;
                    else
                        polozenie[OY] -= 2;
                    break;
                default:
                    break;
            }
        }
        else {
            switch (kierunek) {
                case POLUDNIE:
                    if (polozenie[OY] + 2 >= BOARD_WIDTH)
                        polozenie[OY] = 0;
                    else
                        polozenie[OY] += 2;
                    break;
                case POLNOC:
                    if (polozenie[OY] - 2 < 0)
                        polozenie[OY] = BOARD_WIDTH - 2;
                    else
                        polozenie[OY] -= 2;
                    break;
                case WSCHOD:
                    if (polozenie[OX] + 2 >= BOARD_HEIGHT)
                        polozenie[OX] = 0;
                    else
                        polozenie[OX] += 2;
                    break;
                case ZACHOD:
                    if (polozenie[OX] - 2 < 0)
                        polozenie[OX] = BOARD_HEIGHT - 2;
                    else
                        polozenie[OX] -= 2;
                    break;
                default:
                    break;
            }
        }
    }

    private boolean znajdz_wolny(int x, int y) {
        if (y + 1 >= BOARD_WIDTH) {
            if (swiat.setJesliWolnePole(x, 0, znak)) {
                polozenie[OX] = x;
                polozenie[OY] = 0;
                return true;
            }
        }
        else
        if (swiat.setJesliWolnePole(x, y+ 1, znak)) {
            polozenie[OX] = x;
            polozenie[OY] = y+ 1;
            return true;
        }

        if (y - 1 < 0) {
            if (swiat.setJesliWolnePole(x, BOARD_WIDTH - 1,znak)) {
                polozenie[OX] = x;
                polozenie[OY] = BOARD_WIDTH - 1;
                return true;
            }
        }
        else
        if (swiat.setJesliWolnePole(x, y- 1, znak)) {
            polozenie[OX] = x;
            polozenie[OY] = y- 1;
            return true;
        }

        if (x + 1 >= BOARD_HEIGHT) {
            if (swiat.setJesliWolnePole(0, y, znak)) {
                polozenie[OX] = 0;
                polozenie[OY] = y;
                return true;
            }
        }
        else
        if (swiat.setJesliWolnePole(x+ 1, y, znak)) {
            polozenie[OX] = x+ 1;
            polozenie[OY] = y;
            return true;
        }

        if (x - 1 < 0) {
            if (swiat.setJesliWolnePole(BOARD_HEIGHT - 1, y, znak)) {
                polozenie[OX] = BOARD_HEIGHT - 1;
                polozenie[OY] = y;
                return true;
            }
        }
        else
        if (swiat.setJesliWolnePole(x- 1, y, znak)) {
            polozenie[OX] = x- 1;
            polozenie[OY] = y;
            return true;
        }
        if(swiat.getCzyHex()){
            if (x + 1 >= BOARD_HEIGHT && y - 1 < 0) {
                if (swiat.setJesliWolnePole(0, BOARD_WIDTH - 1, znak)) {
                    polozenie[OX] = 0;
                    polozenie[OY] = BOARD_WIDTH - 1;
                    return true;
                }
            }
            else if (x + 1 >= BOARD_HEIGHT) {
                if (swiat.setJesliWolnePole(0, y - 1, znak)) {
                    polozenie[OX] = 0;
                    polozenie[OY] = y - 1;
                    return true;
                }
            }
            else if (y - 1 < 0) {
                if (swiat.setJesliWolnePole(x + 1, BOARD_WIDTH - 1, znak)) {
                    polozenie[OX] = x + 1;
                    polozenie[OY] = BOARD_WIDTH - 1;
                    return true;
                }
            }
            else {
                if (swiat.setJesliWolnePole(x + 1, y - 1, znak)) {
                    polozenie[OX] = x + 1;
                    polozenie[OY] = y - 1;
                    return true;
                }
            }

            if (x - 1 < 0 && y + 1 >= BOARD_WIDTH) {
                if (swiat.setJesliWolnePole(BOARD_HEIGHT - 1, 0, znak)) {
                    polozenie[OX] = BOARD_HEIGHT - 1;
                    polozenie[OY] = 0;
                    return true;
                }
            }
            else if(x - 1 < 0) {
                if (swiat.setJesliWolnePole(BOARD_HEIGHT - 1, y + 1, znak)) {
                    polozenie[OX] = BOARD_HEIGHT - 1;
                    polozenie[OY] = y + 1;
                    return true;
                }
            }
            else if(y + 1 >= BOARD_WIDTH) {
                if (swiat.setJesliWolnePole(x - 1, 0, znak)) {
                    polozenie[OX] = x - 1;
                    polozenie[OY] = 0;
                    return true;
                }
            }
            else{
                if (swiat.setJesliWolnePole(x - 1, y + 1, znak)) {
                    polozenie[OX] = x - 1;
                    polozenie[OY] = y + 1;
                    return true;
                }
            }
        }
        return false;
    }


}
