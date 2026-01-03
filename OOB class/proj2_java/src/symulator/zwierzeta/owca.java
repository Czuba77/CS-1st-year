package symulator.zwierzeta;

import symulator.Swiat;
import symulator.Zwierze;

public class owca extends Zwierze {

    public owca(Swiat swiat, int ox, int oy, int wiek, int BOARD_WIDTH, int BOARD_HEIGHT) {
        super(swiat, ox, oy,ox, oy, wiek, BOARD_WIDTH, BOARD_HEIGHT);
        this.nazwa = "Owca";
        this.inicjatywa = 4;
        this.sila = 3;
        this.znak = 'o';
        swiat.setJesliWolnePole(ox, oy, znak);
    }

    @Override
    protected void wykonanie_porodu(int x, int y) {
        swiat.addOrganizm(new owca( swiat,x, y, swiat.get_and_incrementKtoryUrodzony(),this.BOARD_WIDTH,this.BOARD_HEIGHT));
    }



    public owca(Swiat swiat, int x, int y,  int wiek, int sila, int xp, int yp, int cp, int BOARD_WIDTH, int BOARD_HEIGHT) {
        super(swiat, x, y,xp,yp, wiek, BOARD_WIDTH, BOARD_HEIGHT);

        this.nazwa = "Owca";
        this.inicjatywa = 4;
        this.sila = sila;
        this.znak = 'o';
        this.cooldown_porodowy = cp;
    }

}
