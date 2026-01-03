package symulator.rosliny;

import symulator.Roslina;
import symulator.Swiat;

public class mlecz extends Roslina {
    public mlecz(Swiat swiat, int ox, int oy,  int wiek, int BOARD_WIDTH, int BOARD_HEIGHT) {
        super(swiat, ox, oy, wiek, BOARD_WIDTH, BOARD_HEIGHT);

        this.nazwa = "Mlecz";
        this.inicjatywa = 0;
        this.sila = 0;
        this.znak = 'M';
        swiat.setJesliWolnePole(ox, oy, znak);
    }

    @Override
    public void zasiej(int x, int y) {
        swiat.addOrganizm(new mlecz(swiat,x, y, swiat.get_and_incrementKtoryUrodzony(),BOARD_WIDTH,BOARD_HEIGHT));
    }

    @Override
    public void akcja() {
        int chance;
        swiat.zwolnijPole(polozenie[OX], polozenie[OY]);
        for (int i = 0; i < 3; i++) {
            chance = genRand(1, EXPAND_CHANCE);
            if (chance == 1) {
                int direction = genRand(0, 3);
                wykonanie_akcji(direction);
            }
        }
    }

}
