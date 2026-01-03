package symulator.zwierzeta;

import symulator.Swiat;
import symulator.Zwierze;

public class wilk extends Zwierze {

    public wilk(Swiat swiat, int ox, int oy, int wiek, int BOARD_WIDTH, int BOARD_HEIGHT) {
        super(swiat, ox, oy,ox, oy, wiek, BOARD_WIDTH, BOARD_HEIGHT);

        this.nazwa = "Wilk";
        this.inicjatywa = 5;
        this.sila = 9;
        this.znak = 'w';
        swiat.setJesliWolnePole(ox, oy, znak);
    }

    @Override
    protected void wykonanie_porodu(int x, int y) {
        swiat.addOrganizm(new wilk( swiat,x, y, swiat.get_and_incrementKtoryUrodzony(),this.BOARD_WIDTH,this.BOARD_HEIGHT));
    }



    public wilk(Swiat swiat, int x, int y,  int wiek, int sila, int xp, int yp, int cp, int BOARD_WIDTH, int BOARD_HEIGHT) {
        super(swiat, x, y,xp,yp, wiek, BOARD_WIDTH, BOARD_HEIGHT);
        this.nazwa = "Wilk";
        this.inicjatywa = 5;
        this.sila = sila;
        this.znak = 'w';
        this.cooldown_porodowy = cp;
    }
}
