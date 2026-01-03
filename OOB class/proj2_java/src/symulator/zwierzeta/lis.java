package symulator.zwierzeta;

import symulator.Organizm;
import symulator.Swiat;
import symulator.Zwierze;

public class lis extends Zwierze {


    public lis(Swiat swiat, int ox, int oy, int wiek, int BOARD_WIDTH, int BOARD_HEIGHT) {
        super(swiat, ox, oy,ox, oy, wiek, BOARD_WIDTH, BOARD_HEIGHT);
        this.nazwa = "Lis";
        this.inicjatywa = 7;
        this.sila = 3;
        this.znak = 'l';
        swiat.setJesliWolnePole(ox, oy, znak);
    }

    @Override
    protected void wykonanie_porodu(int x, int y) {
        swiat.addOrganizm(new lis( swiat,x, y, swiat.get_and_incrementKtoryUrodzony(),this.BOARD_WIDTH,this.BOARD_HEIGHT));
    }



    public lis(Swiat swiat, int x, int y,  int wiek, int sila, int xp, int yp, int cp, int BOARD_WIDTH, int BOARD_HEIGHT) {
        super(swiat, x, y,xp,yp, wiek, BOARD_WIDTH, BOARD_HEIGHT);

        this.nazwa = "Lis";
        this.inicjatywa = 7;
        this.sila = sila;
        this.znak = 'a';
        this.cooldown_porodowy = cp;
    }


    @Override
    protected void wykonanie_akcji(int direction) {
        super.wykonanie_akcji(direction);
        Organizm diff_org = swiat.findOrganizm(polozenie[OX], polozenie[OY], this);
        if (diff_org != null && diff_org.GetSila()>this.sila) {
            polozenie[OX] = poprzednie_polozenie[OX];
            polozenie[OY] = poprzednie_polozenie[OY];
            wykonanie_akcji((direction + 1) % 3);
        }
    }

}
