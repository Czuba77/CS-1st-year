package symulator.rosliny;

import symulator.Roslina;
import symulator.Swiat;

public class trawa extends Roslina {
    public trawa(Swiat swiat, int ox, int oy,  int wiek, int BOARD_WIDTH, int BOARD_HEIGHT) {
        super(swiat, ox, oy, wiek, BOARD_WIDTH, BOARD_HEIGHT);

        this.nazwa = "Trawa";
        this.inicjatywa = 0;
        this.sila = 0;
        this.znak = 'T';
        swiat.setJesliWolnePole(ox, oy, znak);
    }

    @Override
    public void zasiej(int x, int y) {
        swiat.addOrganizm(new trawa(swiat,x, y, swiat.get_and_incrementKtoryUrodzony(),BOARD_WIDTH,BOARD_HEIGHT));
    }


}
